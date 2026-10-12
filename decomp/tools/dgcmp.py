"""dgcmp.py: each DGROUP contribution of run/link/LOLPMAIN.MAP (from 0x3ad6 on) with where its bytes occur in orig DGROUP."""
import re, struct
mp = open('run/link/LOLPMAIN.MAP').read()
rows = [(int(o, 16), int(l, 16), s, m) for o, l, s, m in
        re.findall(r'^ 2E2D:([0-9A-F]{4}) ([0-9A-F]{4}) C=\S+\s+S=(\S+)\s+G=DGROUP\s+M=(\S+)', mp, re.M)]


def img(p):
    e = open(p, 'rb').read(); h = struct.unpack_from('<14H', e); return e[h[4] * 16:]


n, o = img('run/link/MAIN.EXE'), img('orig/MAIN.EXE')
DS = 0x2e2d * 16
od = o[DS:DS + 0x4000]
for a, l, s, m in rows:
    if l == 0 or a < 0x3ad6: continue
    b = n[DS + a:DS + a + l]
    hits = [i for i in range(0x3a00, 0x4000) if od[i:i + l] == b] if s == '_DATA' else []
    print('%04x %3x %-8s %-9s %s' % (a, l, s, m, ' '.join('%04x' % h for h in hits[:4])))
