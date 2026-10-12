"""ovr.py [STUBSEG]: list VROOMM overlays of orig/MM3.EXE (stub seg, file/img offset, size, entry offsets).
img offset = file offset - 0xe00, usable as SEG_ROOT_OFF for cmpobj.py (slack 0: overlay code starts at offset 0).
Also importable: overlays() -> {stubseg: dict(img, size, entries)}, segtable() -> [seg,...] indexed by fixup key/8,
stub_to_code(stubseg, stuboff) -> overlay code offset of a stub entry (stub off = 0x20 + 5*k)."""
import sys, struct, os
_exe = None
def exe():
    global _exe
    if _exe is None: _exe = open(os.environ.get('LOLEXE') or os.path.join(os.path.dirname(__file__), '..', 'orig', 'MAIN.EXE'), 'rb').read()
    return _exe
H = 14336; LOAD_END = 248896
def segtable():
    e = exe(); exeinfo, segnum = struct.unpack_from('<II', e, LOAD_END + 8)
    return [struct.unpack_from('<HHHH', e, exeinfo + i * 8) for i in range(segnum)]
def overlays():
    e = exe(); out = {}
    ov_data = LOAD_END + 16
    for seg, maxoff, flags, minoff in segtable():
        if flags != 3: continue
        b = H + seg * 16
        if struct.unpack_from('<H', e, b)[0] != 0x3fcd: continue
        fo, cs, rs, ne = struct.unpack_from('<IHHH', e, b + 4)
        if not cs: continue
        ents = [struct.unpack_from('<H', e, b + 0x20 + 5 * k + 2)[0] for k in range(ne)]
        relocs = [struct.unpack_from('<H', e, ov_data + fo + cs + 2 * k)[0] for k in range(rs // 2)]
        out[seg] = dict(file=ov_data + fo, img=ov_data + fo - H, size=cs, entries=ents, relocs=relocs)
    return out
def stub_to_code(stubseg, stuboff):
    return overlays()[stubseg]['entries'][(stuboff - 0x20) // 5]
if __name__ == '__main__':
    want = int(sys.argv[1], 16) if len(sys.argv) > 1 else None
    for seg, o in overlays().items():
        if want is None or seg == want:
            print(f"OVR_{seg:04x}: file 0x{o['file']:x} img 0x{o['img']:x} size 0x{o['size']:x} relocs {len(o['relocs'])} entries " + ' '.join(f'{e:04x}' for e in o['entries']))
