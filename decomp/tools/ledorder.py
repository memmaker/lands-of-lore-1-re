"""ledorder.py OBJ SEG:HEXOFF...: put the data records of a TASM OBJ in the given piece order. TASM writes each
segment's LEDATA/LIDATA in segment index order, whatever the source order; a compiler that interleaves segments
(g000: F167_FAR, _DATA ..0xcc4, F179_FAR, rest of _DATA) makes the EXE's relocation order differ. Each argument
starts a piece: every data record (with the FIXUPPs after it) of SEG at or above HEXOFF, below the next piece of
the same segment, goes to that piece. Used by mc.sh for a `; LEDATA-ORDER: ...` line in the asm source."""
import struct, sys
sys.path.insert(0, __file__.rsplit('/', 1)[0])
from omf import records, idx
from omfw import rec

path = sys.argv[1]; pieces = [(a.split(':')[0], int(a.split(':')[1], 16)) for a in sys.argv[2:]]
recs = list(records(open(path, 'rb').read()))
lnames = ['']; segs = ['']
for t, d in recs:
    if t == 0x96:
        p = 0
        while p < len(d): n = d[p]; lnames.append(d[p + 1:p + 1 + n].decode('latin1')); p += 1 + n
    elif t == 0x98:
        a = d[0]; p = 1 + (3 if (a >> 5) == 0 else 0) + 2
        segs.append(lnames[idx(d, p)[0]])
first = next(k for k, (t, _) in enumerate(recs) if t in (0xa0, 0xa2))
last = max(k for k, (t, _) in enumerate(recs) if t in (0xa0, 0xa2, 0x9c, 0x9d))
groups = []
for t, d in recs[first:last + 1]:
    if t in (0xa0, 0xa2):
        si, p = idx(d, 0); groups.append([segs[si], struct.unpack_from('<H', d, p)[0], [(t, d)]])
    else: groups[-1][2].append((t, d))
def key(g):
    cand = [k for k, (s, o) in enumerate(pieces) if s == g[0] and o <= g[1]]
    return max(cand, key=lambda k: pieces[k][1]) if cand else len(pieces)
groups.sort(key=key)   # stable: keeps record order inside a piece
out = b''.join(rec(t, d) for t, d in recs[:first])
out += b''.join(rec(t, d) for g in groups for t, d in g[2])
out += b''.join(rec(t, d) for t, d in recs[last + 1:])
open(path, 'wb').write(out)
