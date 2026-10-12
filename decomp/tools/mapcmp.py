"""mapcmp.py [MAP]: compare TLINK's segment map (run/link/LOLPMAIN.MAP) with orig/MAIN.EXE's segment table, in order.
Prints the first rows where start or length differ (orig start = seg*16+minoff, length = maxoff-minoff)."""
import re, sys, os
sys.path.insert(0, os.path.dirname(__file__))
import ovr
mp = open(sys.argv[1] if len(sys.argv) > 1 else 'run/link/LOLPMAIN.MAP').read()
rows = [(int(a, 16), int(c, 16), n, k) for a, b, c, n, k in
        re.findall(r'^ ([0-9A-F]{5})H ([0-9A-F]{5})H ([0-9A-F]{5})H (\S+)\s+(\S+)', mp, re.M)]
st = [(s * 16 + mn, mx - mn, fl) for s, mx, fl, mn in ovr.segtable()]
print('map rows %d, segtable rows %d' % (len(rows), len(st)))
bad = 0
for i, r in enumerate(rows):
    o = st[i] if i < len(st) else None
    if o is None or o[0] != r[0] or (o[1] != r[1] and o[2] != 4):
        print('#%d map %05x len %04x %-16s %-9s | orig %s' % (i, r[0], r[1], r[2], r[3],
              '%05x len %04x fl %d' % o if o else '-'))
        bad += 1
        if bad > 12: break
