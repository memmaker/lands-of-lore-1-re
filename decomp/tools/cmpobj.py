"""cmpobj.py OBJ ORIG_EXE SEG_ROOT_OFF [SLACK]: per-function compare of OBJ's CODE segment against orig/MM3.EXE.
Functions are named fn_SSSS_OOOO (OOOO = offset in the original segment); each is compared from its own start.
Mask 1 = external fixup (ignored); mask 2 = offset into own segment (compared after adding SLACK).
Offset fixups to _g_XXXX are checked against DGROUP XXXX; with env DSBASE=hex also those into the module's own _DATA."""
import sys, struct, re; sys.path.insert(0, __file__.rsplit('/', 1)[0])
from omf import modules
NAMED = {'_main': '0003'}  # functions whose name cannot carry the orig offset
def orig_off(name):
    """orig offset of a function from its name: fn_SSSS_OOOO / loc_SSSS_OOOO -> OOOO; ovr_SSSS_OOOO -> overlay code
    offset of stub entry OOOO (tools/ovr.py); NAMED for the rest. None if unknown."""
    from names import orig as _o; name = _o(name)
    if name in NAMED: return int(NAMED[name], 16)
    mm = re.match(r'[_@](fn|loc|ovr)_([0-9a-f]{4})_([0-9a-f]{4})(\$.*)?$', name)
    if not mm: return None
    if mm.group(1) == 'ovr':
        from ovr import stub_to_code
        return stub_to_code(int(mm.group(2), 16), int(mm.group(3), 16))
    return int(mm.group(3), 16)
obj, exe, segoff = sys.argv[1], sys.argv[2], int(sys.argv[3], 16)
slack = int(sys.argv[4], 16) if len(sys.argv) > 4 else 0
import os, lolcfg
DSBASE = int(os.environ['DSBASE'], 16) if os.environ.get('DSBASE') else None   # DGROUP offset of this module's _DATA
img = open(exe, 'rb').read()[lolcfg.HDR:]
m = modules(obj)[0]
ok = total = 0
for si, s in enumerate(m['segs']):
    if si == 0 or s['cls'] != 'CODE': continue
    d, k = bytearray(s['data']), s['mask']
    pubs = sorted((o, n) for n, psi, o in m['pubs'] if psi == si)
    # own-segment offsets (jump tables): shift by the containing function's obj->orig delta
    i = 0
    while i < len(d):
        if k[i] == 2:
            f = [(po, pn) for po, pn in pubs if po <= i] or pubs[:1]   # static before the first public: its delta
            mm = orig_off(f[-1][1]) if f else None
            delta = mm - f[-1][0] if mm is not None else slack
            struct.pack_into('<H', d, i, (struct.unpack_from('<H', d, i)[0] + delta) & 0xffff); i += 2
        else: i += 1
    dump = bytearray(d)
    for (o, n), (o2, _) in zip(pubs, pubs[1:] + [(len(d), '')]):
        oo = orig_off(n)
        if oo is None: print(f'{n}: no orig offset in name'); continue
        ref = img[segoff + oo:segoff + oo + (o2 - o)]
        for j in range(o, o2):
            if k[j] == 1: dump[j] = ref[j - o]
        # offset fixups we can resolve without linking: _g_XXXX = DGROUP XXXX; own _DATA when DSBASE is given
        bad_off = set()
        for fo, (tn, disp) in s.get('off', {}).items():
            if not (o <= fo < o2): continue
            mg = re.match(r'_g_([0-9a-f]{4})$', tn)
            base = int(mg.group(1), 16) if mg else (DSBASE if tn == '#_DATA' and DSBASE is not None else None)
            if base is None: continue
            if (base + disp + struct.unpack_from('<H', s['data'], fo)[0]) & 0xffff != struct.unpack_from('<H', ref, fo - o)[0]:
                bad_off.add(fo - o)
        j = 0
        while j < o2 - o:
            if j in bad_off: break
            if k[o + j] == 1 or d[o + j] == ref[j]: j += 1; continue
            # near call (E8 rel16): accept if both resolve to the same function
            if j >= 1 and ref[j - 1] == 0xe8 and j + 1 < o2 - o:
                to = oo + j + 1 + struct.unpack_from('<h', ref, j)[0]
                tj = o + j + 1 + struct.unpack_from('<h', d, o + j)[0]
                f = [(po, pn) for po, pn in pubs if po <= tj]
                if f and orig_off(f[-1][1]) is not None and orig_off(f[-1][1]) + tj - f[-1][0] == to: j += 2; continue
            # TLINK rewrites intra-overlay far calls `9A off seg` to `0E E8 rel 90`: accept if the targets agree
            if d[o + j] == 0x9a and j + 4 < o2 - o and ref[j] == 0x0e and ref[j + 1] == 0xe8 and ref[j + 4] == 0x90:
                tgt = (oo + j + 4 + struct.unpack_from('<h', ref, j + 2)[0]) & 0xffff
                w = struct.unpack_from('<H', d, o + j + 1)[0]  # BCC backpatches same-module targets: obj offset, seg fixup only
                f = [(po, pn) for po, pn in pubs if po <= w]
                if (f and orig_off(f[-1][1]) is not None and orig_off(f[-1][1]) + w - f[-1][0] == tgt) or orig_off(s.get('ext', {}).get(o + j + 1, '')) == tgt:
                    dump[o + j:o + j + 5] = ref[j:j + 5]; j += 5; continue
            # ... or, for a plain BCC OBJ, TLINK's own `90 0E E8 rel` (nop first)
            if d[o + j] == 0x9a and j + 4 < o2 - o and ref[j] == 0x90 and ref[j + 1] == 0x0e and ref[j + 2] == 0xe8:
                tgt = (oo + j + 5 + struct.unpack_from('<h', ref, j + 3)[0]) & 0xffff
                w = struct.unpack_from('<H', d, o + j + 1)[0]
                f = [(po, pn) for po, pn in pubs if po <= w]
                if (f and orig_off(f[-1][1]) is not None and orig_off(f[-1][1]) + w - f[-1][0] == tgt) or orig_off(s.get('ext', {}).get(o + j + 1, '')) == tgt:
                    dump[o + j:o + j + 5] = ref[j:j + 5]; j += 5; continue
            break
        total += 1
        if j == o2 - o: ok += 1; print(f'{n}: OK ({o2 - o} bytes)')
        else: print(f'{n}: diff at +{j:x} (orig seg off {oo + j:04x}): obj {d[o + j]:02x} orig {ref[j]:02x}  [{o2 - o} bytes]')
    # for the asm dump: rewrite every same-module far call to TLINK's 0E E8 00 00 90 form so disassembly lengths line up
    mod = {pn.split('_')[2] for po, pn in pubs if pn.count('_') >= 3}
    for j in range(len(d) - 4):
        if d[j] != 0x9a or k[j + 3] != 1: continue
        w = struct.unpack_from('<H', d, j + 1)[0]; f = [(po, pn) for po, pn in pubs if po <= w]
        ext = s.get('ext', {}).get(j + 1, '')
        if (ext.split('_')[2] in mod) if ext.count('_') >= 3 else (not ext and f and orig_off(f[-1][1]) is not None):
            dump[j:j + 5] = b'\x0e\xe8\x00\x00\x90'
    open(obj + '.bin', 'wb').write(dump)   # per-OBJ dump for fndiff/asmdiff
print(f'{ok}/{total} functions match')
if DSBASE is not None:   # own _DATA bytes (globals + pooled strings) vs DGROUP; fixup bytes masked
    for s in m['segs'][1:]:
        if s['name'] != '_DATA' or not s['data']: continue
        ref = img[lolcfg.DS + DSBASE:lolcfg.DS + DSBASE + len(s['data'])]
        bad = [i for i in range(len(ref)) if not s['mask'][i] and s['data'][i] != ref[i]]
        print(f'_DATA {DSBASE:04x}-{DSBASE + len(ref):04x}: ' + ('OK' if not bad else f'diff at DS {DSBASE + bad[0]:04x} ({len(bad)} bytes)'))
for s in m['segs'][1:]:   # far data segments F###_FAR (data-only far modules) vs the original segment's bytes
    mf = re.match(r'F(\d{3})_FAR$', s.get('name') or '')
    if not mf or not s['data']: continue
    from ovr import segtable
    base = segtable()[int(mf.group(1))][0] * 16
    ref = img[base:base + len(s['data'])]
    bad = [i for i in range(len(ref)) if not s['mask'][i] and s['data'][i] != ref[i]]
    print(f'{s["name"]} ({len(ref)} bytes): ' + ('OK' if not bad else f'diff at +{bad[0]:x} ({len(bad)} bytes)'))
