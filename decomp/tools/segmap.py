"""segmap.py orig/MM3.EXE: list code segments (Ghidra CODE_n/OVR_ blocks) with size and the DS-relative strings they reference."""
import re, struct, sys, urllib.request
d = open(sys.argv[1], 'rb').read()
H, OVR, DS = 3584, 165568, 0x186f0
img = d[H:OVR]
def strings_for(code):
    out = []
    for m in re.finditer(rb'[\xb8\xba\xbe\xbf]([\x00-\xff]{2})', code, re.S):
        a = DS + struct.unpack('<H', m.group(1))[0]
        if a >= OVR - H or a < DS + 0x100 or img[a - 1] != 0: continue
        s = re.match(rb'[\x20-\x7e]{4,}', img[a:a + 48])
        if s: out.append(s.group(0).decode())
    return list(dict.fromkeys(out))
segs = urllib.request.urlopen('http://127.0.0.1:8091/list_segments?limit=100').read().decode().split('\n')
print('block\tstart\tsize\tstrings')
for l in segs:
    m = re.match(r'(CODE_\d+|OVR_[0-9a-f]+): ([0-9a-f]+):([0-9a-f]+) - ([0-9a-f]+):([0-9a-f]+)', l)
    if not m: continue
    name, s0, o0, s1, o1 = m.groups()
    if name.startswith('CODE'):
        a = (int(s0, 16) - 0x1000) * 16 + int(o0, 16); b = (int(s1, 16) - 0x1000) * 16 + int(o1, 16) + 1
        code = img[a:b]
    else:
        stub = (int(name[4:], 16)) * 16
        fo = struct.unpack_from('<I', img, stub + 4)[0]; cs = struct.unpack_from('<H', img, stub + 8)[0]
        code = d[OVR + fo:OVR + fo + cs]; a = fo
    print(f'{name}\t{s0}:{o0}\t{len(code)}\t' + ' | '.join(strings_for(code)[:10]))
