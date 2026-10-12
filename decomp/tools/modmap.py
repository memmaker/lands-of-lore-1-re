"""modmap.py: one line per code segment / overlay of orig/MAIN.EXE with the facts that identify its source module.

columns: name, para, size, nfn (Ghidra functions), relocs (count and order: 'desc' = BCC, 'asc' = TASM),
prologues (count of `push bp; mov bp,sp` starts), strings (DGROUP strings loaded with mov reg,imm).
Ghidra function starts come from results/decomp_raw.c headers.
"""
import re, struct, sys, os
sys.path.insert(0, os.path.dirname(__file__))
import lolcfg

d = open(lolcfg.EXE, 'rb').read()
img = d[lolcfg.HDR:lolcfg.IMG_END]
h = struct.unpack('<14H', d[:28])
relocs = [struct.unpack_from('<HH', d, h[12] + 4 * i) for i in range(h[3])]
segs = [l.split('\t') for l in open('results/segtable.tsv').read().split('\n')[1:] if l]
segs = [(int(s[1], 16), int(s[2], 16), int(s[3])) for s in segs]

GBASE = 0x1000  # Ghidra MzLoader load segment
fns = {}
ovmap = {}
for l in open('results/decomp_raw.c'):
    m = re.match(r'//// (\S+) @ ([0-9a-f]{4}):([0-9a-f]{4})', l)
    if not m: continue
    name, s, o = m.group(1), int(m.group(2), 16), int(m.group(3), 16)
    mo = re.match(r'ovr_([0-9a-f]{4})_', name)
    if mo: ovmap[s] = int(mo.group(1), 16)
    fns.setdefault(s, []).append(o)


def strings_for(code):
    out = []
    for m in re.finditer(rb'[\xb8\xba\xbe\xbf\x68]([\x00-\xff]{2})', code, re.S):
        a = lolcfg.DS + struct.unpack('<H', m.group(1))[0]
        if a >= len(img) or img[a - 1] != 0: continue
        s = re.match(rb'[\x20-\x7e]{4,}', img[a:a + 40])
        if s: out.append(s.group(0).decode())
    return list(dict.fromkeys(out))


def order(lst):
    if len(lst) < 2: return '-'
    up = sum(1 for a, b in zip(lst, lst[1:]) if b > a)
    dn = len(lst) - 1 - up
    return 'asc' if up > dn * 3 else 'desc' if dn > up * 3 else 'mixed'


print('name\tpara\tsize\tnfn\trelocs\tprologues\tstrings')
for seg, size, flag in segs:
    if flag == 1:
        a = seg * 16
        code = img[a:a + size]
        rl = [s * 16 + o - a for o, s in relocs if a <= s * 16 + o < a + size]
        nf = len(fns.get(seg + GBASE, []))
        name = 'SEG_%04x' % seg
    elif flag == 3 and img[seg * 16:seg * 16 + 2] == b'\xcd\x3f':
        b = seg * 16
        fo, cs, rs, ne = struct.unpack_from('<IHHH', img, b + 4)
        if cs == 0: continue
        code = d[lolcfg.OVR + fo:lolcfg.OVR + fo + cs]
        rl = list(struct.unpack_from('<%dH' % (rs // 2), d, lolcfg.OVR + fo + cs))
        size = cs
        nf = sum(len(v) for k, v in fns.items() if ovmap.get(k) == seg)
        name = 'OVR_%04x' % seg
    else:
        continue
    pro = len(re.findall(rb'\x55\x8b\xec', code))
    print('\t'.join([name, '%04x' % seg, str(size), str(nf), '%d %s' % (len(rl), order(rl)), str(pro),
                     ' | '.join(strings_for(code)[:6])]))
