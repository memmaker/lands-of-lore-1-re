"""asmgen.py NAME CODESTART [--db OFF,OFF..] [--near OFF,..]: first TASM draft of a hand-written assembler root module.

Bytes below CODESTART become `db` lines (relocated far pointers to the segment itself become `dd L_xxxx`);
code from CODESTART on is ndisasm output rewritten in TASM syntax: branch targets get labels, every
`enter` (or --near offset) starts a proc (_fn_SEG_OFF, far unless --near), relocated far calls / segment
immediates become extrn references (_fn_SEG_OFF, _f_SEG_0000 far data). Offsets given with --db are emitted
as raw bytes (TASM picks another encoding for them). Output on stdout; refine names and comments by hand.
"""
import sys, os, re, struct, subprocess, tempfile
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ovr, layout, lolcfg

name = sys.argv[1]; cstart = int(sys.argv[2], 16)
opt = dict(zip(sys.argv[3::2], sys.argv[4::2]))
dbset = {int(x, 16) for x in opt.get('--db', '').split(',') if x}
nearset = {int(x, 16) for x in opt.get('--near', '').split(',') if x}
st = ovr.segtable(); seg, size, _, minoff = st[dict(layout.ROOT)[name]]
e = ovr.exe(); hdr = struct.unpack_from('<H', e, 8)[0] * 16
img = e[hdr + seg * 16: hdr + seg * 16 + size]
nrel, relo = struct.unpack_from('<H', e, 6)[0], struct.unpack_from('<H', e, 0x18)[0]
rel = {}
for i in range(nrel):
    o, s = struct.unpack_from('<HH', e, relo + 4 * i)
    l = s * 16 + o - seg * 16
    if 0 <= l < size: rel[l] = struct.unpack_from('<H', img, l)[0]
segnames = {st[i][0]: n for n, i in layout.ROOT}
farsegs = {v[0] for k, v in enumerate(st) if k >= 150}

f = tempfile.NamedTemporaryFile(delete=False); f.write(img[cstart:]); f.close()
lines = subprocess.run(['ndisasm', '-b16', '-o%d' % cstart, f.name], capture_output=True, text=True).stdout.split('\n')
ins = []
for l in lines:
    if not l: continue
    a, hx, t = l[:8], l[10:28].strip(), l[28:].strip()
    ins.append((int(a, 16), bytes.fromhex(hx), t))

labels, procs = set(), set(nearset)
for a, b, t in ins:
    m = re.match(r'(j\w+|loop\w*|call|jcxz)\s+(?:short |near |word )?(0x[0-9a-f]+)$', t)
    if m and b[0] != 0x9a: labels.add(int(m.group(2), 16))
    if b[:1] == b'\xc8' and len(b) == 4: procs.add(a)
for a in range(0, cstart, 4):
    if a + 2 in rel and rel[a + 2] == seg: labels.add(struct.unpack_from('<H', img, a)[0])


def num(v):
    if v >= 1 << 32: return '-' + num((1 << 64) - v)
    s = '%x' % v
    return ('0' + s if s[0] in 'abcdef' else s) + 'h' if v > 9 else str(v)


def conv(t):
    t = re.sub(r'\b(byte|word|dword|qword)\s+\[', r'\1 ptr [', t)
    t = re.sub(r'\[(cs|ds|es|ss|fs|gs):', r'\1:[', t)
    t = re.sub(r'0x([0-9a-f]+)', lambda m: num(int(m.group(1), 16)), t)
    t = t.replace('o32 ', '')
    t = re.sub(r'^(cs|ds|es|ss)\s+xlatb', r'xlat\tbyte ptr \1:[bx]', t)
    t = re.sub(r'^(l[defgs]s\s+\w+,)word ptr', r'\1dword ptr', t)
    t = re.sub(r'^push\s+dword\s+(?=[0-9])', 'push\tlarge ', t)
    t = re.sub(r'\b(byte|word|dword)\s+(?=[0-9-])', '', t)
    return t


exts, out = set(), []
def emit(s): out.append(s)

# data part
i = minoff
while i < cstart:
    if i + 2 in rel and rel[i + 2] == seg:
        emit('\tdd\tL_%04x' % struct.unpack_from('<H', img, i)[0]); i += 4; continue
    j = i
    while j < cstart and j - i < 16 and not (j + 2 in rel) and not (j in labels and j > i): j += 1
    if j == i: j = i + 1
    if i in labels: emit('L_%04x:' % i)
    run = img[i:j]
    if not any(run) and j - i > 1: emit('\tdb\t%d dup (0)' % (j - i))
    else: emit('\tdb\t' + ', '.join(num(c) for c in run))
    i = j

cur = None
for a, b, t in ins:
    if a in procs:
        if cur is not None: emit('%s\tendp\n' % cur)
        cur = '_fn_%04x_%04x' % (seg, a)
        emit('%s\tproc\t%s' % (cur, 'near' if a in nearset else 'far'))
    elif a in labels: emit('L_%04x:' % a)
    rl = [r for r in rel if a <= r < a + len(b)]
    m = re.match(r'(j\w+|loop\w*|call|jcxz)\s+(short |near |word )?(0x[0-9a-f]+)$', t)
    if a in dbset:
        emit('\tdb\t' + ', '.join(num(c) for c in b) + '\t; ' + t)
    elif rl and b[0] == 0x9a:
        v = rel[rl[0]]; o = struct.unpack_from('<H', b, 1)[0]
        sym = '_fn_%04x_%04x' % (v, o); exts.add(sym + ':far')
        emit('\tcall\tfar ptr ' + sym)
    elif rl and 0xb8 <= b[0] <= 0xbf and rel[rl[0]] == lolcfg.DGROUP:
        emit('\tmov\t%s,DGROUP' % t.split()[1].split(',')[0])
    elif rl and 0xb8 <= b[0] <= 0xbf:
        v = rel[rl[0]]
        sym = ('_f_%04x_%04x' % (v, 0)) if v in farsegs else '_fn_%04x_%04x' % (v, st[[k for k, x in enumerate(st) if x[0] == v][0]][3])
        exts.add(sym + (':byte' if v in farsegs else ':far'))
        emit('\tmov\t%s,seg %s' % (t.split()[1].split(',')[0], sym))
    elif rl:
        emit('\tdb\t' + ', '.join(num(c) for c in b) + '\t; RELOC ' + t)
    elif m and b[0] != 0x9a:
        tgt = int(m.group(3), 16); op = m.group(1)
        if op == 'call': kind = ''
        elif len(b) == 2: kind = 'short '
        else: kind = 'near ptr ' if op != 'jmp' or len(b) == 3 else ''
        emit('\t%s\t%sL_%04x' % (op, kind, tgt))
    else:
        p = conv(t).split(None, 1)
        emit('\t' + p[0] + ('\t' + p[1] if len(p) > 1 else ''))
if cur is not None: emit('%s\tendp' % cur)

U = name.upper()
print('; %s: assembler module (segment %04x, draft by tools/asmgen.py)\n' % (name, seg))
print('\t.386\n\tlocals\n%s_TEXT\tsegment byte public use16 \'CODE\'\n%s_TEXT\tends' % (U, U))
print('DGROUP\tgroup\t_DATA,_BSS\n\tassume\tcs:%s_TEXT,ds:DGROUP' % U)
print("_DATA\tsegment word public use16 'DATA'\n_DATA\tends\n_BSS\tsegment word public use16 'BSS'\n_BSS\tends\n")
for x in sorted(exts): print('\textrn\t' + x)
print('\n%s_TEXT\tsegment byte public use16 \'CODE\'' % U)
pubs = sorted(procs)
for k in range(0, len(pubs), 4): print('\tpublic\t' + ', '.join('_fn_%04x_%04x' % (seg, p) for p in pubs[k:k + 4]))
if minoff: print('\torg\t%s' % num(minoff))
print('\n'.join(out))
print('%s_TEXT\tends\n\tend' % U)
