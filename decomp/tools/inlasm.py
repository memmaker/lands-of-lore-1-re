"""inlasm.py MOD FN: rewrite function FN of src/MOD.c as BCC inline assembler (built-in BASM, no #pragma inline:
that routes the whole module through TASM, which encodes BCC's own code differently).

For functions BCC 3.1 cannot be coaxed into compiling byte-exact from C. FN must still be marked /* NONMATCHING */:
the original bytes and their symbolic fixups are read from the transplanted link OBJ run/m/MOD/MOD.OBJ (this runs
tools/mc.sh MOD first). BCC keeps generating the frame (push bp/mov bp,sp/sub sp,N, push si/di when the asm uses
them, and the epilogue); the locals are one char array `_l` (its uses make BCC allocate it), the body becomes `asm`
statements with C labels L_xxxx (offsets inside the original function) and Lret for the epilogue. Far calls, `seg`
values and DGROUP variables declared in the C use their C names; other DGROUP addresses stay numeric (ds:[XXXXh];
the data layout is fixed). 386 instructions are `db 66h` + the 16-bit form (BASM knows no 32-bit registers).
The result is compiled and compared in a loop: an instruction BASM rejects or encodes differently (e.g. BCC's
`mov r16,r16` is 8B /r, BASM's 89 /r) is emitted as raw bytes with the mnemonic in a comment.
The C body stays above the function inside #if 0 for reading and porting.
"""
import os, re, subprocess, sys, tempfile
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import objfix, omf, split

ROOT = os.path.join(os.path.dirname(os.path.abspath(__file__)), '..')


def num(v):
    if v >= 1 << 32: return '-' + num((1 << 64) - v)   # ndisasm prints sign-extended imm8 as 64 bits
    s = '%x' % v
    return ('0' + s if s[0] in 'abcdef' else s) + 'h' if v > 9 else str(v)


def conv(t):
    t = re.sub(r'\b(byte|word|dword|qword)\s+\[', r'\1 ptr [', t)
    t = re.sub(r'\[(cs|ds|es|ss):', r'\1:[', t)
    t = re.sub(r'0x([0-9a-f]+)', lambda m: num(int(m.group(1), 16)), t)
    t = re.sub(r'^(l[des]s\s+\w+,)word ptr', r'\1dword ptr', t)
    t = re.sub(r'\b(byte|word)\s+(?=[0-9-])', '', t)
    return t


def disasm(b):
    f = tempfile.NamedTemporaryFile(delete=False); f.write(b); f.close()
    out = []
    for l in subprocess.run(['ndisasm', '-b16', f.name], capture_output=True, text=True).stdout.split('\n'):
        if l: out.append((int(l[:8], 16), bytes.fromhex(l[10:28].strip()), l[28:].strip()))
    os.unlink(f.name)
    return out


DEF = re.compile(r'^(?!typedef|extern)[A-Za-z_][^;=(]*?\b([A-Za-z_]\w*)\s*\([^;]*\)\s*$')


def extract(mod, fn):
    m = omf.modules(os.path.join(ROOT, 'run/m/%s/%s.OBJ' % (mod, mod.upper())))[0]
    ci = [i for i, s in enumerate(m['segs']) if s and s.get('cls') == 'CODE'][0]
    seg = m['segs'][ci]
    pubs = {o: n for n, si, o in m['pubs'] if si == ci}
    # static functions have no PUBDEF: starts are also the targets of fixup-less push cs/call near; pair all starts
    # with the C definitions in source order
    d, mk = seg['data'], seg['mask']
    selfcall = {}
    starts = set(pubs)
    for q in range(len(d) - 4):
        if d[q] == 0x0e and d[q + 1] == 0xe8 and not mk[q + 2]:
            starts.add((q + 4 + int.from_bytes(d[q + 2:q + 4], 'little', signed=True)) & 0xffff)
    lines = open(os.path.join(ROOT, 'src', mod + '.c')).read().split('\n')
    defs = [DEF.match(l).group(1) for k, l in enumerate(lines[:-1]) if DEF.match(l) and lines[k + 1].startswith('{')]
    starts = sorted(o for o in starts if o < len(d))
    if len(starts) == len(defs):
        for o, n in zip(starts, defs): pubs.setdefault(o, '_' + n)
    lo = [o for o, n in pubs.items() if n == '_' + fn][0]
    hi = min([o for o in pubs if o > lo] + [len(seg['data'])])
    code = bytes(seg['data'][lo:hi])
    ext = {o - lo: n for o, n in seg.get('ext', {}).items() if lo <= o < hi}
    offs = {o - lo for o in seg.get('off', {}) if lo <= o < hi}
    # far pointers into the own segment (same-segment far calls): target = data word + fixup displacement
    raw = open(os.path.join(ROOT, 'run/m/%s/%s.OBJ' % (mod, mod.upper())), 'rb').read(); last = None
    for rt, b in objfix.records(raw):
        if rt == 0xa0:
            si, p = objfix.idx(b, 0); last = (si, int.from_bytes(b[p:p + 2], 'little'))
        elif rt == 0x9c and last and last[0] == ci:
            for f in objfix.parse_fixupp(b, *last):
                if f.loc == 3 and f.tm == 0 and f.ti == ci and lo <= f.off < hi:
                    v = int.from_bytes(d[f.off:f.off + 2], 'little')
                    if f.dpos is not None: v += int.from_bytes(f.raw[f.dpos:f.dpos + 2], 'little')
                    selfcall[f.off - lo] = (v & 0xffff) - lo
    return code, seg['mask'][lo:hi], ext, offs, {o - lo: n for o, n in pubs.items()}, lo, selfcall


# push cs/call near into the module's own segment is a C statement: BASM gives `call near ptr f` a segment-base
# fixup without target, BCC emits push cs/call near for a callee it has already seen. Arguments and `add sp`
# stay in asm. A far call (TLINK turns those into its own segment into nop/push cs/call near) to a function
# defined later is a C statement too (BASM writes offset 0 for it, BCC emits the far call for a callee not seen yet).
CALL = '    ((void (far *)(void))%s)();'


def generate(code, mask, ext, offs, pubs, selfcall, declared, seg_name, dbset):
    ins = disasm(code)
    assert ins[0][1] == b'\x55' and ins[1][1] == b'\x8b\xec', 'no standard frame'
    k = 2; N = 0
    if ins[k][2].startswith('sub sp,'): N = int(ins[k][2].split(',')[1], 16); k += 1
    regs = []
    while ins[k][1] in (b'\x56', b'\x57'): regs.append(ins[k][1]); k += 1
    r = [i for i, x in enumerate(ins) if x[1] == b'\xcb'][0]
    e = r - 1
    if ins[e][1] in (b'\xc9', b'\x5d'): e -= 1
    while ins[e][1] in (b'\x5f', b'\x5e'): e -= 1
    e += 1
    body, eplo = ins[k:e], ins[e][0]
    tail = len(code) - ins[r + 1][0] if r + 1 < len(ins) else 0
    labels = set()
    for a, b, t in body:
        mm = re.match(r'(j\w+|loop\w*|jcxz)\s+(?:short |near )?(0x[0-9a-f]+)$', t)
        if mm: labels.add(int(mm.group(2), 16))
    cname = lambda s: s[1:] if s.startswith('_') else s
    def local(x):
        v = int(x.group(1)[:-1], 16) if x.group(1).endswith('h') else int(x.group(1))
        return ('_l+%d' % (N - v) if N - v else '_l') if v <= N else x.group(0)
    def operand(ct):
        md = re.search(r'(?<![:\w])\[([0-9a-f]+h|\d+)\]', ct)
        if md:
            v = int(md.group(1)[:-1], 16) if md.group(1).endswith('h') else int(md.group(1))
            nm = 'g_%04x' % v
            ct = ct[:md.start()] + (nm if declared(nm) else 'ds:[%s]' % num(v)) + ct[md.end():]
        if N:
            c2 = re.sub(r'\[bp-(\d+|[0-9a-f]+h)\]', local, ct)
            if c2 != ct and ' ptr ' not in ' ' + c2:   # _l is a char array: give the access its real size
                sz = 'byte' if re.search(r'\b[abcd][lh]\b', c2) else 'word'
                c2 = re.sub(r'\b_l\b', sz + ' ptr _l', c2, count=1)
            ct = c2
        return ct
    out = []   # (address or None, text)
    pushcs = {body[i][0] for i in range(len(body) - 1) if body[i][1] == b'\x0e' and body[i + 1][1][0] == 0xe8}
    for a, b, t in body:
        if a in labels: out.append((None, 'L_%04x:' % a))
        if a in pushcs: continue   # part of the C call that follows
        fx = [q for q in range(a, a + len(b)) if mask[q]]
        mm = re.match(r'(j\w+|loop\w*|jcxz)\s+(short |near )?(0x[0-9a-f]+)$', t)
        if a in dbset and not fx:
            out.append((a, '    asm db %s\t/* %s */' % (', '.join(num(c) for c in b), t))); continue
        if mm:
            tgt = int(mm.group(3), 16); lab = 'Lret' if tgt == eplo else 'L_%04x' % tgt
            out.append((a, '    asm %s %s' % (mm.group(1), lab))); continue   # BCC sizes jumps to C labels
        if b[0] == 0xe8 and not fx:   # push cs; call near: a function of this module
            tgt = a + 3 + int.from_bytes(b[1:3], 'little', signed=True)
            assert tgt in pubs, 'near call to non-public %04x at %04x' % (tgt, a)
            out.append((a, CALL % cname(pubs[tgt]))); continue
        if b[0] == 0x9a:
            q = a + 1
            if q in ext: nm = cname(ext[q])
            elif a + 3 in ext: nm = cname(ext[a + 3])
            else:
                tgt = selfcall[q]
                nm = cname(pubs[tgt]) if tgt in pubs else None
                assert nm, 'self call to unknown %04x at %04x' % (tgt, a)
                if tgt > 0:   # BASM leaves the offset of a callee defined later at 0; BCC emits that far call itself
                    out.append((a, CALL % nm)); continue
            out.append((a, '    asm call far ptr %s' % nm)); continue
        if fx:
            mm2 = re.match(r'(.*),0x0$', t) or re.match(r'(push word) 0x0$', t)
            if mm2 and fx[0] in ext:
                sym = seg_name(cname(ext[fx[0]]))
                kind = 'offset' if fx[0] in offs else 'seg'
                if t.startswith('push'):
                    out.append((a, '    asm push %s %s' % (kind, sym))); continue
                ct = operand(conv(mm2.group(1))); p = ct.split(None, 1)
                out.append((a, '    asm %s %s,%s %s' % (p[0], p[1], kind, sym))); continue
            raise Exception('unhandled fixup at %04x: %s %s' % (a, b.hex(), t))
        if b[0] == 0x66:
            d = disasm(b[1:])
            if len(d) == 1 and not d[0][2].startswith('o32'):
                ct = operand(conv(d[0][2])); p = ct.split(None, 1)
                out.append((a, '    asm db 66h\t/* %s */' % t))
                out.append((a, '    asm %s%s' % (p[0], ' ' + p[1] if len(p) > 1 else ''))); continue
            out.append((a, '    asm db %s\t/* %s */' % (', '.join(num(c) for c in b), t))); continue
        ct = operand(conv(t)); p = ct.split(None, 1)
        out.append((a, '    asm %s%s' % (p[0], ' ' + p[1] if len(p) > 1 else '')))
    out.append((None, 'Lret:'))
    out.append((None, '    ;'))
    return N, regs, body, out, tail


def splice(src, fn, N, regs, out):
    lines = src.split('\n')
    _, _, head, s, en = [x for x in split.functions(lines) if x[0] == fn][0]
    p = s - 1
    while p >= 0 and lines[p].strip() == '': p -= 1
    if 'NONMATCHING' in lines[p]: del lines[p]; s -= 1; en -= 1
    pre = ['/* C version: BCC 3.1 does not reproduce the original code from it (tools/inlasm.py) */', '#if 0'] + \
          lines[s:en + 1] + ['#endif', head, '{'] + (['    char _l[%d];' % N] if N else []) + \
          ['    _%s;   /* saved by the original */' % r for r in regs]
    first = s + len(pre) + 1   # 1-based line number of the first body line
    lines[s:en + 1] = pre + [x for _, x in out] + ['}']
    return '\n'.join(lines), first


def main():
    mod, fn = sys.argv[1], sys.argv[2]
    path = os.path.join(ROOT, 'src', mod + '.c')
    src = open(path).read()
    subprocess.run([os.path.join(ROOT, 'tools/mc.sh'), mod], capture_output=True)
    code, mask, ext, offs, pubs, lo, selfcall = extract(mod, fn)
    hdrs = src + ''.join(open(os.path.join(ROOT, 'src', h)).read() for h in re.findall(r'#include "([^"]+)"', src)
                         if os.path.exists(os.path.join(ROOT, 'src', h)))
    declared = lambda nm: re.search(r'\b%s\b' % re.escape(nm), hdrs) is not None
    def seg_name(nm):   # `seg` of an undeclared far data/code symbol: any declared one in the same segment
        if declared(nm): return nm
        mm = re.match(r'(f|fn)_([0-9a-f]{4})_', nm)
        alt = re.search(r'\b(%s_%s_[0-9a-f]{4})\b' % (mm.group(1), mm.group(2)), hdrs) if mm else None
        assert alt, 'no C name for ' + nm
        return alt.group(1)
    dbset = set()
    for it in range(400):
        N, regs, body, out, tail = generate(code, mask, ext, offs, pubs, selfcall, declared, seg_name, dbset)
        text, first = splice(src, fn, N, [{0x56: 'SI', 0x57: 'DI'}[r[0]] for r in regs], out)
        open(path, 'w').write(text)
        res = subprocess.run([os.path.join(ROOT, 'tools/mc.sh'), mod], capture_output=True, text=True).stdout
        errs = [int(x) for x in re.findall(r'Error %s\.c (\d+):' % mod, res)]
        if errs:
            bad = {out[l - first][0] for l in errs if 0 <= l - first < len(out)} - {None}
            if not bad - dbset:
                print(res); raise SystemExit('%s: compile errors outside the asm body' % fn)
            dbset |= bad; continue
        line = [l for l in res.split('\n') if l.startswith('_%s:' % fn)]
        oc, om = extract(mod, fn)[:2]   # compare the OBJ bytes, fixup bytes excluded (cmpobj reports TLINK's
        diff = [q for q in range(min(len(oc), len(code))) if oc[q] != code[q] and not om[q] and not mask[q]]
        if not diff and len(oc) == len(code):   # far-call rewrite in overlays as a difference)
            line = ['_%s: OK' % fn]
        elif line:
            line = ['_%s: diff at +%x' % (fn, diff[0] if diff else min(len(oc), len(code)))]
        if line and ': OK' in line[0]:
            print('%s: OK after %d rounds, %d instructions, %d as raw bytes%s' % (
                fn, it + 1, len(body), len(dbset), ', %d bytes after retf' % tail if tail else '')); return
        mm = re.search(r'diff at \+([0-9a-f]+)', line[0]) if line else None
        if not mm: print(res); raise SystemExit('%s: no result' % fn)
        x = int(mm.group(1), 16)
        cand = [a for a, b, t in body if a <= x < a + len(b)]
        if not cand or cand[0] in dbset:
            print(line[0]); raise SystemExit('%s: stuck at +%x (frame/prologue or already raw)' % (fn, x))
        dbset.add(cand[0])
    raise SystemExit('%s: too many rounds' % fn)


if __name__ == '__main__':
    main()
