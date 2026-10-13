"""fixorder.py OBJ HEXOFF...: reorder the fixups of each FIXUPP record of a TASM OBJ into the given order of
fixup locations (segment offsets of the fixed-up field, as in the LEDATA). Used by mc.sh for asm modules whose source
has a `; FIXUP-ORDER: ...` line: the original assembler emitted some fixups out of address order (s117: the
`mov ax,DGROUP` fixups sit at the front of their record), which shows in the EXE's relocation order, and TASM 3.1
cannot be made to reproduce it (forward references to the group move all such fixups as one block)."""
import struct, sys
sys.path.insert(0, __file__.rsplit('/', 1)[0])
from omf import records, idx
from omfw import rec

path = sys.argv[1]; order = [int(x, 16) for x in sys.argv[2:]]
buf = open(path, 'rb').read(); out = b''; last = 0
for t, d in records(buf):
    if t == 0xa0:
        _, p = idx(d, 0); last = struct.unpack_from('<H', d, p)[0]
    if t in (0x9c, 0x9d):
        p = 0; subs = []
        while p < len(d):
            q = p; b = d[p]
            assert b & 0x80, 'threads not supported'
            doff = ((b & 3) << 8) | d[p + 1]; p += 2; fd = d[p]; p += 1
            if not (fd & 0x80) and (fd >> 4) & 7 < 3: _, p = idx(d, p)
            if not fd & 8: _, p = idx(d, p)
            if not fd & 4: p += 2 + (2 if t == 0x9d else 0)
            subs.append((last + doff, d[q:p]))
        subs.sort(key=lambda s: order.index(s[0]) if s[0] in order else len(order) + s[0])
        d = b''.join(s[1] for s in subs)
    out += rec(t, d)
open(path, 'wb').write(out)
