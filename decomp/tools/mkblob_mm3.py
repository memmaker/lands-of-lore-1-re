"""mkblob.py OUTDIR [C.OBJ ...]: write blob .OBJ files (original bytes + symbolic fixups) for every game module of
orig/MM3.EXE that has no C OBJ yet, so TLINK can relink a byte-identical EXE while modules are rewritten in C.
C OBJs (basename = module name) are copied into OUTDIR; overlay ones get their _ovr_ PUBDEFs sorted (see pubsort).
Blobs publish the _g_/_fn_/_ovr_ symbols the C OBJs import. Layout and module order live in tools/layout.py."""
import struct, sys, os, re
sys.path.insert(0, os.path.dirname(__file__))
import ovr
from omfw import Module
import omf
from layout import ROOT, OVR, DATA, BSS, EXTRA_EXTS, extra_pubs, DATA_MODS

e = ovr.exe()
H = 3584
img = e[H:ovr.LOAD_END]
hdr = struct.unpack_from('<14H', e, 0)
relocs = [s * 16 + o for o, s in (struct.unpack_from('<HH', e, hdr[12] + 4 * i) for i in range(hdr[3]))]   # original order within each 64K section
st = ovr.segtable()
ovrs = ovr.overlays()
DS = 0x186f0

# RTL names by root offset
rtl = {}
for l in open(os.path.join(os.path.dirname(__file__), '..', 'results', 'rtl_symbols.tsv')).read().splitlines()[1:]:
    a, off, n = l.split('\t')[:3]
    rtl.setdefault(int(off, 16), n)
rtl.update({0x2436: '_toupper', 0x3b02: '_unlink'})   # same bytes as __ftoupper/_remove; lib order says these
rtl_sorted = sorted(rtl.items())

frame_mod = {}   # root frame -> module name (game code segments)
for n, i in ROOT:
    if st[i][1] != st[i][3]: frame_mod[st[i][0]] = n
stub_mod = {s: n for n, s in OVR}


def rtl_sym(off):
    if off in rtl: return rtl[off]
    best = [n for o, n in rtl_sorted if o <= off]
    return best[-1]


def target(v, off_word, ctx):
    """classify a segment word: returns (loc, kind, sym)"""
    if v == 0x186f: return ('base', 'grp', 'DGROUP')
    if v in (0, 0x1699): return ('base', 'ext', rtl_sym(v * 16 + off_word))
    if v in stub_mod: return ('ptr', 'ext', '_ovr_%04x_%04x' % (v, off_word))
    if v in frame_mod: return ('base', 'ext', seg_sym.get(frame_mod[v], '__seg_' + frame_mod[v]))
    raise Exception('unknown target seg %04x in %s' % (v, ctx))


def code_module(n, code, fixups, seg_align='byte'):
    m = Module(n)
    s = m.seg(n.upper() + '_TEXT', 'CODE', seg_align, code)
    for off, (loc, kind, sym) in fixups:
        if loc == 'ptr': off -= 2
        s['fixups'].append((off, loc, kind, sym))
    m.pubs.append(('__seg_' + n, s['name'], 0))
    return m, s


def build(n):
    if n in dict(ROOT):
        i = dict(ROOT)[n]
        seg, mx, fl, mn = st[i]
        a, b = seg * 16 + mn, seg * 16 + mx
        code = img[a:b]
        fx = []
        for r in relocs:
            if a <= r < b:
                fx.append((r - a, target(struct.unpack_from('<H', img, r)[0], struct.unpack_from('<H', img, r - 2)[0], n)))
        m, s = code_module(n, code, fx, 'word' if n in ('snddrv', 'empty9') else 'byte')
        if n == 'main': m.pubs.append(('_main', s['name'], 0))
    elif n in dict(OVR):
        sseg = dict(OVR)[n]
        o = ovrs[sseg]
        code = e[o['file']:o['file'] + o['size']]
        fx = []
        for r in o['relocs']:
            v = st[struct.unpack_from('<H', code, r)[0] // 8][0]
            if st[struct.unpack_from('<H', code, r)[0] // 8][2] == 3:   # stub
                v = st[struct.unpack_from('<H', code, r)[0] // 8][0]
            fx.append((r, target(v, struct.unpack_from('<H', code, r - 2)[0], n)))
        # TLINK turns `call far` into its own overlay segment into `nop; push cs; call near` but still reserves reloc
        # space for it (zero padding after the reloc table). Undo the rewrite so TLINK does it again.
        code = bytearray(code); fx_self = []
        for mm in re.finditer(rb'\x90\x0e\xe8', bytes(code)):
            q = mm.start(); tgt = (q + 5 + struct.unpack_from('<h', code, q + 3)[0]) & 0xffff
            code[q:q + 5] = b'\x9a\0\0\0\0'; fx_self.append(q + 1)
        m, s = code_module(n, bytes(code), fx)
        for q in fx_self:
            tgt = (q + 4 + struct.unpack_from('<h', e, o['file'] + q + 2)[0]) & 0xffff
            s['fixups'].append((q, 'ptr', 'seg', (s['name'], tgt)))
        m.pubs = []   # TLINK makes a stub entry for every public of an overlay segment, in PUBDEF order
        for k, ent in reversed(list(enumerate(o['entries']))):   # TLINK prepends: stub order = reverse PUBDEF order
            m.pubs.append(('_ovr_%04x_%04x' % (sseg, 0x20 + 5 * k), s['name'], ent))
    else:
        m = Module(n)
    # data pieces assigned to this module
    if n in DATA:
        a, b = DATA[n]
        s = m.seg('_DATA', 'DATA', 'word', img[DS + a:DS + b])
        for r in relocs:
            if DS + a <= r < DS + b:
                s['fixups'].append((r - DS - a,) + target(struct.unpack_from('<H', img, r)[0], struct.unpack_from('<H', img, r - 2)[0], n))
    if n in BSS:
        a, b = BSS[n]
        m.seg('_BSS', 'BSS', 'word', None, b - a)
    for x in EXTRA_EXTS.get(n, []): m.ext(x)
    for p, sname, a in extra_pubs(n):
        m.pubs.append((p, sname, a - (DATA if sname == '_DATA' else BSS)[n][0]))
    for p, sname, off in wanted.get(n, []):
        if p not in [q[0] for q in m.pubs]: m.pubs.append((p, sname, off))
    return m


seg_sym = {}   # C module -> a public of its code segment (stands in for __seg_<mod> in blob base fixups)
wanted = {}    # blob module -> [(sym, segname, off)] imported by C OBJs


def owner(sym):
    """(module, segname, offset) of a symbol a C OBJ imports from a blob, None for RTL names"""
    from names import orig; sym = orig(sym)
    mm = re.match(r'_g_([0-9a-f]{4})$', sym)
    if mm:
        a = int(mm.group(1), 16)
        for n, (lo, hi) in DATA.items():
            if lo <= a < hi: return n, '_DATA', a - lo
        for n, (lo, hi) in BSS.items():
            if lo <= a < hi: return n, '_BSS', a - lo
        raise Exception('no owner for ' + sym)
    mm = re.match(r'_fn_([0-9a-f]{4})_([0-9a-f]{4})$', sym)
    if mm:
        f, o = int(mm.group(1), 16), int(mm.group(2), 16)
        if f not in frame_mod: f -= 0x1000   # Ghidra segment form
        n = frame_mod[f]; i = dict(ROOT)[n]
        return n, n.upper() + '_TEXT', o - st[i][3]
    return None   # _ovr_ entries are published by the overlay blobs themselves; the rest is RTL


def pubsort(buf):
    """reorder an overlay OBJ's _ovr_ PUBDEF records by descending stub offset: TLINK builds the stub table in reverse
    PUBDEF order, and BCC's own (hash) order cannot be reproduced from the names"""
    recs = []; i = 0
    while i < len(buf):
        n = struct.unpack_from('<H', buf, i + 1)[0]; recs.append(buf[i:i + 3 + n]); i += 3 + n
    idx = [k for k, r in enumerate(recs) if r[0] == 0x90]
    from names import orig
    key = lambda r: orig(r[6:6 + r[5]].decode()).encode()   # address name: _ovr_SSSS_OOOO sorts by stub offset
    for k, r in zip(idx, sorted((recs[k] for k in idx), key=key, reverse=True)): recs[k] = r
    return b''.join(recs)


if __name__ == '__main__':
    out = sys.argv[1]
    cobjs = {os.path.basename(p).rsplit('.', 1)[0].lower(): p for p in sys.argv[2:]}
    defined, imported = set(), set()
    for n, p in cobjs.items():
        mod = omf.modules(p)[0]
        code = [k for k, sg in enumerate(mod['segs']) if sg.get('cls') == 'CODE']
        defined |= {q[0] for q in mod['pubs']}
        imported |= set(mod['exts'])
        cp = [q[0] for q in mod['pubs'] if q[1] in code]
        if cp: seg_sym[n] = cp[0]
    for sym in sorted(imported - defined):
        o = owner(sym)
        if o:
            if o[0] in cobjs: raise Exception('%s owned by C module %s but not defined there' % (sym, o[0]))
            wanted.setdefault(o[0], []).append((sym,) + o[1:])
    for n in [n for n, _ in ROOT] + DATA_MODS + [n for n, _ in OVR]:
        dst = os.path.join(out, n.upper() + '.OBJ')
        if n in cobjs:
            b = open(cobjs[n], 'rb').read()
            open(dst, 'wb').write(pubsort(b) if n in dict(OVR) else b)
        else:
            open(dst, 'wb').write(build(n).bytes())
