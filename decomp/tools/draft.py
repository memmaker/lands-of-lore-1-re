"""draft.py NAME: Ghidra's decompile (results/decomp_raw.c) of module NAME (sNNN root segment or oSSSS overlay), with
project names, into src/draft/NAME.c — a starting point for the byte-exact rewrite, not compilable as is.

Names: fn_SSSS_OOOO (root code, OOOO = segment offset; overlay-internal: code offset), ovr_SSSS_OOOO (overlay entry by
stub offset), g_XXXX (DGROUP offset), f_SSSS_OOOO (far data), RTL functions by their library name."""
import re, sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import layout, ovr

st = ovr.segtable()
ovrs = ovr.overlays()
G = 0x1000   # Ghidra load segment
DS = 0x2e2d
rtl = {}
for l in open('results/rtl_symbols.tsv').read().splitlines()[1:]:
    off, n = l.split('\t')[:2]
    rtl.setdefault(int(off, 16), n.lstrip('_') if n.startswith('_') and not n.startswith('__') else n)


def entry_name(sseg, code_off):
    ents = ovrs.get(sseg, {}).get('entries', [])
    return 'ovr_%04x_%04x' % (sseg, 0x20 + 5 * ents.index(code_off)) if code_off in ents else 'fn_%04x_%04x' % (sseg, code_off)


def ren(text):
    def fun(m):
        s, o = int(m.group(1), 16) - G, int(m.group(2), 16)
        if s == 0 and o in rtl: return rtl[o]
        if s == 0x1c8d and (0x1c8d0 + o) in rtl: return rtl[0x1c8d0 + o]
        return 'fn_%04x_%04x' % (s, o)
    text = re.sub(r'\bFUN_([0-9a-f]{4})_([0-9a-f]{4})\b', fun, text)
    text = re.sub(r'\bovr_([0-9a-f]{4})_([0-9a-f]{4})\b', lambda m: entry_name(int(m.group(1), 16), int(m.group(2), 16)), text)

    def dat(m):
        s, o = int(m.group(2), 16) - G, int(m.group(3), 16)
        lin = s * 16 + o
        if DS * 16 <= lin < DS * 16 + 0x10000: return 'g_%04x' % (lin - DS * 16)
        return 'f_%04x_%04x' % (s, o)
    text = re.sub(r'\b_?(DAT|PTR_DAT|PTR)_([0-9a-f]{4})_([0-9a-f]{4})\b', dat, text)
    return text


def main():
    n = sys.argv[1].lower()
    out = []
    for blk in open('results/decomp_raw.c').read().split('\n//// ')[1:]:
        head = blk.split('\n', 1)[0]
        m = re.match(r'(\S+) @ ([0-9a-f]{4}):([0-9a-f]{4})', head)
        name, gs, go = m.group(1), int(m.group(2), 16), int(m.group(3), 16)
        mo = re.match(r'ovr_([0-9a-f]{4})_', name)
        if n.startswith('o'):
            if not mo or 'o' + mo.group(1) != n: continue
        else:
            if mo: continue
            i = dict(layout.ROOT)[n]
            seg, mx, fl, mn = st[i]
            lin = (gs - G) * 16 + go
            if not (seg * 16 + mn <= lin < seg * 16 + mx): continue
        out.append('//// ' + ren(blk))
    os.makedirs('src/draft', exist_ok=True)
    open('src/draft/%s.c' % n, 'w').write('\n'.join(out))
    print('%d functions -> src/draft/%s.c' % (len(out), n))


main()
