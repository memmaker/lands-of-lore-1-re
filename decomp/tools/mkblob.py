"""mkblob.py OUTDIR [C.OBJ ...]: blob .OBJ files (original bytes + symbolic fixups) for every module of orig/MAIN.EXE
that has no C/ASM OBJ yet, plus LINK.RSP, so TLINK relinks a byte-identical EXE while modules are rewritten.

Modules (tools/layout.py decides names and order):
  root code   one per TLINK segment-table entry (flag 1) except the RTL ones (0000 C0+CL.LIB, 1c8d OVERLAY.LIB)
  far data    one per flag-0 segment before the VROOMM tables
  overlays    one per stub segment with code (linked with /o)
  gdata/gbss  the game's part of DGROUP _DATA / _BSS
Given OBJs replace the blob of the same (lower-case) basename. Blobs publish the symbols the given OBJs import:
_fn_SSSS_OOOO (root code), _ovr_SSSS_OOOO (stub entry), _g_XXXX (DGROUP), _f_SSSS_OOOO (far data).
"""
import os, re, struct, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lolcfg, omf, ovr
from omfw import Module
import layout

e = ovr.exe()
img = e[lolcfg.HDR:lolcfg.IMG_END]
hdr = struct.unpack_from('<14H', e, 0)
relocs = [s * 16 + o for o, s in (struct.unpack_from('<HH', e, hdr[12] + 4 * i) for i in range(hdr[3]))]
st = ovr.segtable()
ovrs = ovr.overlays()
DS = lolcfg.DS

rtl = {}
# modules that share their bytes with another CL.LIB module (rtl_symbols lists both); the original linked these
PREFER = {'GETVECT', 'UNLINK', 'TOLOWER', 'TOUPPER', '_STPCPY', 'HARD', 'FNSPLIT', 'HARDERR',
          'MEMCHR', 'MEMCMP', 'MEMCPY', 'MEMICMP', 'MEMSET', 'MOVMEM', 'STRCAT', 'STRCHR', 'STRCMP', 'STRCPY',
          'STRICMP', 'STRLEN', 'STRNCPY', 'STRNICMP', 'STRRCHR', 'STRSTR', 'STRUPR'}
for l in open(os.path.join(os.path.dirname(__file__), '..', 'results', 'rtl_symbols.tsv')).read().splitlines()[1:]:
    off, n, mod = l.split('\t')[:3]
    if mod in PREFER: rtl[int(off, 16)] = n
    else: rtl.setdefault(int(off, 16), n)
rtl.update({0x4743: '_read', 0x57bf: '_write'})   # READU/WRITEU: 3-byte jmp modules, too short to fingerprint
rtl_sorted = sorted(rtl.items())
RTL_SEGS = {0x0000, 0x1c8d}
# RTL modules the game uses only through DS offsets (no relocation names them)
EXTRA_EXTS = ['__argv', '_environ']
ALIAS = {'_ovr_2db0_002a': '_main'}   # address names whose real name the RTL needs


def al(sym):
    return ALIAS.get(sym, sym)

# segment para -> module owning it (first non-empty entry wins; empty entries share the para of the next one)
seg_mod = {}
far_mod = dict((i, n) for n, i in layout.FAR)   # far segment index -> defining module
for n, v in layout.FAR_OWN.items():
    for i in v: far_mod[i] = n
for n, i in layout.ROOT + [('f%03d' % i, i) for i in layout.FAR_ALL]:
    seg, mx, fl, mn = st[i]
    if mx > mn or seg not in seg_mod: seg_mod[seg] = n   # far segments by their f### name
stub_mod = {s: n for n, s in layout.OVR}
seg_sym = {}   # module given as OBJ -> one of its code publics (stands in for __seg_<mod>)


def rtl_sym(lin):
    if lin in rtl: return rtl[lin]
    seg = 0x1c8d0 if lin >= 0x1c8d0 else 0   # base fixups only need a symbol in the same segment
    below = [n for o, n in rtl_sorted if seg <= o <= lin]
    return below[-1] if below else [n for o, n in rtl_sorted if o >= seg][0]


def target(v, off_word, ctx):
    """classify a relocated segment word v (off_word = the word before it): (loc, kind, sym)"""
    if v == lolcfg.DGROUP: return ('base', 'grp', 'DGROUP')
    if v in RTL_SEGS: return ('base', 'ext', rtl_sym(v * 16 + off_word))
    if v == 0x2c2b: return ('base', 'ext', '__OVRHOOK__')   # OVERLAY.LIB _OVRDATA_ (any public there gives the frame)
    if v in stub_mod:
        ne = len(ovrs[v]['entries'])
        if off_word >= 0x20 and (off_word - 0x20) % 5 == 0 and (off_word - 0x20) // 5 < ne:
            return ('ptr', 'ext', al('_ovr_%04x_%04x' % (v, off_word)))
        return ('base', 'ext', '_ovr_%04x_0020' % v)   # bare `seg stub` (no offset word before it)
    if v in seg_mod:
        m = seg_mod[v]
        return ('base', 'ext', '__seg_' + m if m.startswith('f') else seg_sym.get(m, '__seg_' + m))
    raise Exception('unknown target seg %04x in %s' % (v, ctx))


def self_entry(code, off, ents):
    """(offset word position, entry index) of the stub-entry offset paired with a `seg` at off"""
    for q in (off + 3, off + 6, off - 3, off - 6, off + 5, off - 5, off + 7, off - 7, off + 4, off - 4):
        if 0 <= q <= len(code) - 2:
            w = struct.unpack_from('<H', code, q)[0]
            if w >= 0x20 and (w - 0x20) % 5 == 0 and (w - 0x20) // 5 < len(ents): return q, (w - 0x20) // 5
    return None


def entry(i):
    seg, mx, fl, mn = st[i]
    return seg * 16 + mn, seg * 16 + mx


def far_seg(m, i, data=True):
    """add far data segment i (F###_FAR, para aligned) to module m, with its bytes and relocations if data"""
    a, b = entry(i)
    sname = 'F%03d_FAR' % i
    if not data: return m.seg(sname, 'FAR_DATA', 'para', b'')
    s = m.seg(sname, 'FAR_DATA', 'para', img[a:b])
    for r in relocs:
        if a <= r < b:
            loc, kind, sym = target(struct.unpack_from('<H', img, r)[0], struct.unpack_from('<H', img, r - 2)[0], m.modname)
            s['fixups'].append((r - a - (2 if loc == 'ptr' else 0), loc, kind, sym))
    m.pubs.append(('__seg_f%03d' % i, sname, 0))
    return s


def build(n):
    m = Module(n)
    if n == 'g000':   # declares every far segment first, so they keep their order whoever defines them
        for i in layout.FAR_ALL: far_seg(m, i, i in layout.FAR_OWN[n])
    if n in dict(layout.FAR):
        far_seg(m, dict(layout.FAR)[n])
    elif n in dict(layout.ROOT):
        far = False
        i = dict(layout.FAR if far else layout.ROOT)[n]
        a, b = entry(i)
        fx = [(r - a, target(struct.unpack_from('<H', img, r)[0], struct.unpack_from('<H', img, r - 2)[0], n))
              for r in relocs if a <= r < b]
        sname = n.upper() + ('_FAR' if far else '_TEXT')
        code = bytearray(img[a:b])
        fx_self = []
        if not far:   # undo TLINK's same-segment far call rewrite (it sizes the reloc table before rewriting)
            mn = st[i][3]
            for mm in re.finditer(rb'\x90\x0e\xe8', bytes(code)):
                q = mm.start()
                tgt = (q + mn + 5 + struct.unpack_from('<h', code, q + 3)[0]) & 0xffff
                if any(q <= f - a < q + 5 for f in relocs): continue
                code[q:q + 5] = b'\x9a' + struct.pack('<H', tgt - mn) + b'\0\0'
                fx_self.append((q + 1, tgt - mn))
        s = m.seg(sname, 'FAR_DATA' if far else 'CODE', 'para' if far else 'byte' if a % 2 else 'word', bytes(code))
        for off, (loc, kind, sym) in fx:
            if loc == 'ptr': off -= 2
            s['fixups'].append((off, loc, kind, sym))
        for q, tgt in fx_self:
            s['fixups'].append((q, 'ptr', 'seg', (sname, tgt)))
        m.pubs.append(('__seg_' + n, sname, 0))
        for i in layout.FAR_OWN.get(n, []): far_seg(m, i)
    elif n in dict(layout.OVR):
        sseg = dict(layout.OVR)[n]
        o = ovrs.get(sseg, dict(file=0, size=0, relocs=[], entries=[]))
        code = bytearray(e[o['file']:o['file'] + o['size']])
        fx = []
        for r in o['relocs']:
            key = struct.unpack_from('<H', code, r)[0]
            fx.append((r, target(st[key // 8][0], struct.unpack_from('<H', code, r - 2)[0], n)))
        # TLINK rewrites far calls into the overlay's own segment to `nop; push cs; call near`; undo it so it redoes it
        fx_self = []
        for mm in re.finditer(rb'\x90\x0e\xe8', bytes(code)):
            q = mm.start()
            tgt = (q + 5 + struct.unpack_from('<h', code, q + 3)[0]) & 0xffff
            code[q:q + 5] = b'\x9a' + struct.pack('<H', tgt) + b'\0\0'
            fx_self.append((q + 1, tgt))
        m.coments += [b'\x00\xa1\x01TD']   # BCC's "new OMF extensions" mark: TLINK then gives `seg` of its own overlay the stub
        s = m.seg(n.upper() + '_TEXT', 'CODE', 'byte', bytes(code))
        for off, (loc, kind, sym) in fx:
            if loc == 'ptr': off -= 2
            if loc == 'base' and sym == '_ovr_%04x_0020' % sseg:
                # far pointer to a function of this overlay: BCC writes `seg` (T0, no displacement) and a
                # loader-resolved offset fixup to the function; TLINK turns the pair into the stub entry
                kind, sym = 'seg', (s['name'], None)
                ent = self_entry(code, off, o['entries'])
                if ent:
                    q, k = ent
                    s['fixups'].append((off, loc, kind, sym))
                    s['fixups'].append((q, 'loff', 'seg', (s['name'], o['entries'][k])))
                    continue
            s['fixups'].append((off, loc, kind, sym))
        for q, tgt in fx_self:
            s['fixups'].append((q, 'ptr', 'seg', (s['name'], tgt)))
        m.seg('_DATA', 'DATA', 'word', b''); m.seg('_BSS', 'BSS', 'word', None, 0)   # BCC module skeleton
        for k, ent in reversed(list(enumerate(o['entries']))):   # stub order = reverse PUBDEF order
            m.pubs.append((al('_ovr_%04x_%04x' % (sseg, 0x20 + 5 * k)), s['name'], ent))
    if n in layout.DATA:
        a, b = layout.DATA[n]
        s = m.seg('_DATA', 'DATA', 'word', img[DS + a:DS + b])
        for r in relocs:
            if DS + a <= r < DS + b:
                loc, kind, sym = target(struct.unpack_from('<H', img, r)[0], struct.unpack_from('<H', img, r - 2)[0], n)
                s['fixups'].append((r - DS - a - (2 if loc == 'ptr' else 0), loc, kind, sym))
        if n == 'g000':
            for x in EXTRA_EXTS: m.ext(x)
            for w, _ in layout.WWLIB: m.ext(seg_sym.get(w, '__seg_' + w))   # Westwood modules nothing calls by far ref
            m.ext('__dat_' + layout.WWHEAD)
        if n == layout.WWHEAD: m.pubs.append(('__dat_' + n, '_DATA', 0))
    if n in layout.EXITS:
        ents = layout.EXITS[n]
        s = m.seg('_EXIT_', 'EXITDATA', 'word', b''.join(bytes([1, pr]) + b'\0' * 4 for pr, _, _ in ents))
        for k, (pr, sg, off) in enumerate(ents):
            if sg in stub_mod: s['fixups'].append((6 * k + 2, 'ptr', 'ext', al('_ovr_%04x_%04x' % (sg, off))))
            else:
                own = m.segs[0]
                s['fixups'].append((6 * k + 2, 'ptr', 'seg', (own['name'], off - st[dict(layout.ROOT)[n]][3])))
    if n in layout.PIECES:
        pcs, pos = [], {}
        for sname, cut in layout.PIECES[n]:
            sg = [x for x in m.segs if x['name'] == sname][0]
            lo = pos.get(sname, 0); hi = len(sg['data']) if cut is None else cut - layout.DATA[n][0]
            pcs.append((sname, lo, hi)); pos[sname] = hi
        m.pieces = pcs
    if n in layout.BSS:
        a, b = layout.BSS[n]
        m.seg('_BSS', 'BSS', 'word', None, b - a)
    for p, sname, off in wanted.get(n, []):
        if p not in [q[0] for q in m.pubs]: m.pubs.append((p, sname, off))
    return m


wanted = {}


def build_frag(n, lo, hi, pub, part):
    """original bytes [lo, hi) of root module n's code segment as one OBJ contributing to segment N_TEXT (the rest
    of the module is C); calls into the module outside the range go through the C parts' publics"""
    m = Module(part)
    i = dict(layout.ROOT)[n]
    seg, mx, fl, mn = st[i]
    a, b = seg * 16 + lo, seg * 16 + hi
    sname = n.upper() + '_TEXT'
    code = bytearray(img[a:b])
    fx = [(r - a, target(struct.unpack_from('<H', img, r)[0], struct.unpack_from('<H', img, r - 2)[0], n))
          for r in relocs if a <= r < b]
    fx_self = []
    for mm in re.finditer(rb'\x90\x0e\xe8', bytes(code)):
        q = mm.start()
        tgt = (q + lo + 5 + struct.unpack_from('<h', code, q + 3)[0]) & 0xffff
        if any(q <= f - a < q + 5 for f in relocs): continue
        code[q:q + 5] = b'\x9a' + struct.pack('<H', tgt - lo if lo <= tgt < hi else 0) + b'\0\0'
        fx_self.append((q + 1, tgt))
    s = m.seg(sname, 'CODE', 'byte', bytes(code))
    for off, (loc, kind, sym) in fx:
        if loc == 'ptr': off -= 2
        s['fixups'].append((off, loc, kind, sym))
    for q, tgt in fx_self:
        if lo <= tgt < hi:
            s['fixups'].append((q, 'ptr', 'seg', (sname, tgt - lo)))
        else:
            s['fixups'].append((q, 'ptr', 'ext', '_fn_%04x_%04x' % (seg, tgt)))
    m.pubs.append((pub, sname, 0))
    return m


def owner(sym):
    """(module, segname, offset) of a symbol imported by a given OBJ; None for RTL names"""
    mm = re.match(r'_g_([0-9a-f]{4})$', sym)
    if mm:
        a = int(mm.group(1), 16)
        for n, (lo, hi) in layout.DATA.items():
            if lo <= a < hi: return n, '_DATA', a - lo
        for n, (lo, hi) in layout.BSS.items():
            if lo <= a < hi: return n, '_BSS', a - lo
        raise Exception('no owner for ' + sym)
    mm = re.match(r'_(fn|f)_([0-9a-f]{4})_([0-9a-f]{4})$', sym)
    if mm:
        f, o = int(mm.group(2), 16), int(mm.group(3), 16)
        n = seg_mod[f]
        if n.startswith('f'):
            i = int(n[1:])
            return far_mod[i], 'F%03d_FAR' % i, o - st[i][3]
        return n, n.upper() + '_TEXT', o - st[dict(layout.ROOT)[n]][3]
    return None


def pubsort(buf):
    """overlay OBJ: _ovr_ PUBDEFs by descending stub offset (TLINK builds the stub table in reverse PUBDEF order)"""
    recs = []; i = 0
    while i < len(buf):
        k = struct.unpack_from('<H', buf, i + 1)[0]; recs.append(buf[i:i + 3 + k]); i += 3 + k
    idx = [k for k, r in enumerate(recs) if r[0] == 0x90]
    for k, r in zip(idx, sorted((recs[k] for k in idx), key=lambda r: r[6:6 + r[5]], reverse=True)): recs[k] = r
    return b''.join(recs)


def main():
    out = sys.argv[1]
    objs, parts, frags = {}, {}, []
    for p in sys.argv[2:]:
        if os.path.basename(p) == 'PARTS':   # split module: C parts + original-byte fragments, in link order
            n = os.path.basename(os.path.dirname(os.path.dirname(p))).lower(); d = os.path.dirname(p)
            parts[n] = []
            for l in open(p).read().splitlines():
                f = l.split()
                if f[0] == 'C': parts[n].append(('C', os.path.join(d, f[1] + '.OBJ'), f[1]))
                else:
                    pn = '%s_F%d' % (n.upper(), len(parts[n]) + 1)
                    parts[n].append(('F', (int(f[1], 16), int(f[2], 16), f[3]), pn)); frags.append(f[3])
            objs[n] = None
        else:
            objs[os.path.basename(p).rsplit('.', 1)[0].lower()] = p
    defined, imported = set(frags), set()
    paths = [(n, p) for n, p in objs.items() if p] + [(n, q[1]) for n, v in parts.items() for q in v if q[0] == 'C']
    for n, p in paths:
        mod = omf.modules(p)[0]
        code = [k for k, sg in enumerate(mod['segs']) if sg.get('cls') == 'CODE']
        defined |= {q[0] for q in mod['pubs']}
        imported |= set(mod['exts'])
        cp = [q[0] for q in mod['pubs'] if q[1] in code]
        if cp and n not in seg_sym: seg_sym[n] = cp[0]
    for sym in sorted(imported - defined):
        o = owner(sym)
        if o:
            if o[0] in objs: raise Exception('%s owned by %s but not defined there' % (sym, o[0]))
            wanted.setdefault(o[0], []).append((sym,) + o[1:])
    for n in layout.order() + layout.lib_order():
        dst = os.path.join(out, n.upper() + '.OBJ')
        if n in parts:
            for kind, src, pn in parts[n]:
                d2 = os.path.join(out, pn + '.OBJ')
                if kind == 'C': open(d2, 'wb').write(open(src, 'rb').read())
                else: open(d2, 'wb').write(build_frag(n, src[0], src[1], src[2], pn).bytes())
        elif n in objs:
            b = open(objs[n], 'rb').read()
            open(dst, 'wb').write(pubsort(b) if n in dict(layout.OVR) else b)
        else:
            open(dst, 'wb').write(build(n).bytes())
    open(os.path.join(out, 'LINK.RSP'), 'w').write(layout.rsp({n: [q[2] for q in v] for n, v in parts.items()}))
    open(os.path.join(out, 'TLIB.RSP'), 'w').write(layout.tlib_rsp())


if __name__ == '__main__':
    main()
