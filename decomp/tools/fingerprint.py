"""Find Borland RTL modules inside an EXE by masked byte search.
usage: fingerprint.py EXE LIB_OR_OBJ... > results/rtl_matches.tsv
"""
import re, sys, os
sys.path.insert(0, os.path.dirname(__file__))
from omf import modules

exe = open(sys.argv[1], 'rb').read()
import struct
_h = struct.unpack("<14H", exe[:28]); HDR = _h[4] * 16; OVR = ((_h[2] - 1) * 512 + _h[1] if _h[1] else _h[2] * 512) + 16
def where(f):
    return 'root+%05x' % (f - HDR) if f < OVR - 16 else 'ovr+%05x' % (f - OVR)

print('lib\tmodule\tseg\tsize\tmasked\tmatches\tfirst\tpublics')
for path in sys.argv[2:]:
    lib = os.path.basename(path)
    for m in modules(path):
        for si, s in enumerate(m['segs']):
            if si == 0 or s['cls'] != 'CODE' or len(s['data']) < 6: continue
            if sum(1 for x in s['mask'] if x) > len(s['data']) - 6: continue
            parts, i, d, k = [], 0, s['data'], s['mask']
            while i < len(d):
                if d[i] == 0x9a and i + 5 <= len(d) and all(k[i + 1:i + 5]):
                    parts.append(b'(?:\\x9a....|\\x90\\x0e\\xe8..)'); i += 5; continue  # TLINK far->near call rewrite
                if d[i] == 0xea and i + 5 <= len(d) and all(k[i + 1:i + 5]):
                    parts.append(b'(?:\\xea....|\\x90\\x90\\xe9..)'); i += 5; continue  # TLINK far->near jmp rewrite
                parts.append(b'.' if k[i] else re.escape(bytes([d[i]]))); i += 1
            pat = b''.join(parts)
            hits = [h.start() for h in re.finditer(pat, exe, re.S)]
            pubs = ' '.join('%s@%s' % (n, where(hits[0] + o)) if hits else n for n, psi, o in m['pubs'] if psi == si)
            print('\t'.join([lib, m['name'], s['name'], str(len(s['data'])), str(sum(1 for x in s['mask'] if x)), str(len(hits)), where(hits[0]) if hits else '-', pubs]))
