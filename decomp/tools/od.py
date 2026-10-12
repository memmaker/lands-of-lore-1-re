# od.py SSSS: disassemble overlay with relocated segment words resolved to names
import sys, struct, subprocess, re
sys.path.insert(0, '/home/user/lands-of-lore-1-re/decomp/tools')
import os; os.chdir('/home/user/lands-of-lore-1-re/decomp')
import ovr
st = ovr.segtable(); ovs = ovr.overlays()
rtl = {}
for l in open('results/rtl_symbols.tsv').read().splitlines()[1:]:
    off, n = l.split('\t')[:2]; rtl.setdefault(int(off, 16), n)
sseg = int(sys.argv[1], 16); o = ovs[sseg]
code = bytearray(ovr.exe()[o['file']:o['file'] + o['size']])
names = {}
for r in o['relocs']:
    key = struct.unpack_from('<H', code, r)[0]; seg = st[key // 8][0]
    off = struct.unpack_from('<H', code, r - 2)[0]
    if seg == 0x2e2d: nm = 'DGROUP'
    elif seg in (0, 0x1c8d): nm = rtl.get(seg * 16 + off, 'rtl_%05x' % (seg * 16 + off))
    elif seg in ovs: nm = 'ovr_%04x_%04x' % (seg, off)
    else: nm = 'fn_%04x_%04x' % (seg, off)
    if code[r - 3] in (0x9a, 0xea): names[r - 2] = nm
    else: names[r] = "SEG:%04x" % seg
ents = {e: k for k, e in enumerate(o['entries'])}
out = subprocess.run(['ndisasm', '-b16', '-'], input=bytes(code), capture_output=True).stdout.decode()
for l in out.splitlines():
    a = int(l[:8], 16) if re.match(r'[0-9A-F]{8}', l) else None
    if a in ents: print('---- ovr_%04x_%04x' % (sseg, 0x20 + 5 * ents[a]))
    ann = ''
    if a is not None:
        n=len(l.split()[1])//2
        for q in range(a, a + n):
            if q in names: ann = '   ; ' + names[q]; break
    print(l + ann)
