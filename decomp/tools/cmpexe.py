"""cmpexe.py NEW ORIG: compare two MZ+FBOV EXEs region by region (header, relocation table, image, overlays) and
print the first differences of each region with segment-table context. Exit 0 and "MATCH" when identical."""
import struct, sys
a, b = open(sys.argv[1], 'rb').read(), open(sys.argv[2], 'rb').read()
if a == b: print('MATCH (%d bytes)' % len(a)); sys.exit(0)
ha, hb = struct.unpack('<14H', a[:28]), struct.unpack('<14H', b[:28])
names = 'sig lastpage pages nreloc hdrpara minalloc maxalloc ss sp csum ip cs lfarlc ovno'.split()
for n, x, y in zip(names, ha, hb):
    if x != y: print('header %s: new %04x orig %04x' % (n, x, y))
ra = [struct.unpack_from('<HH', a, ha[12] + 4 * i) for i in range(ha[3])]
rb = [struct.unpack_from('<HH', b, hb[12] + 4 * i) for i in range(hb[3])]
if ra != rb:
    k = next((i for i in range(min(len(ra), len(rb))) if ra[i] != rb[i]), min(len(ra), len(rb)))
    print('relocs: %d vs %d, first diff #%d new %s orig %s' % (len(ra), len(rb), k, ra[k:k + 1], rb[k:k + 1]))
H = hb[4] * 16
end = (hb[2] - 1) * 512 + hb[1] if hb[1] else hb[2] * 512
ia, ib = a[ha[4] * 16:], b[H:]
diffs = [i for i in range(min(len(ia), len(ib))) if ia[i] != ib[i]]
print('file sizes new %d orig %d; image diffs %d' % (len(a), len(b), len(diffs)))
segs = []
exeinfo, segnum = struct.unpack_from('<II', b, end + 8)
segs = sorted(struct.unpack_from('<HHHH', b, exeinfo + i * 8) for i in range(segnum))
def where(i):
    if i + H >= end: return 'ovr+%05x' % (i + H - end - 16)
    s = [x for x in segs if x[0] * 16 <= i]
    return '%04x:%04x' % (s[-1][0], i - s[-1][0] * 16) if s else '%05x' % i
shown = 0; last = -100
for i in diffs:
    if i > last + 16 and shown < 25:
        print('  %s (img %05x): new %s orig %s' % (where(i), i, ia[i:i + 8].hex(), ib[i:i + 8].hex())); shown += 1
    last = i
sys.exit(1)
