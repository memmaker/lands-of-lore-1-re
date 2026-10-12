"""rtlorder.py: RTL modules in _TEXT of run/link/LOLPMAIN.MAP vs their original addresses (results/rtl_matches.tsv).
Prints a line wherever the address delta changes, so reordered/missing/extra library modules stand out."""
import re, csv
mp = open('run/link/LOLPMAIN.MAP').read()
ours = [(int(o, 16), int(l, 16), m) for o, l, m in
        re.findall(r'^ 0000:([0-9A-F]{4}) ([0-9A-F]{4}) C=CODE\s+S=_TEXT\s+G=\(none\)\s+M=(\S+)', mp, re.M)]
orig = {}
for r in csv.DictReader(open('results/rtl_matches.tsv'), delimiter='\t'):
    if r['matches'] != '0' and r['first'].startswith('root+'): orig.setdefault(r['module'], int(r['first'][5:], 16))
orig.update({'VPRINTER': 0x1759, 'SETARGV': 0x3476, 'SETENVP': 0x35bd})
prev = 0
for o, l, m in ours:
    if l == 0: continue
    oo = orig.get(m)
    d = (o - oo) if oo is not None else None
    if d != prev: print(f'{m:10s} ours {o:04x} len {l:4d} orig {"-" if oo is None else "%04x" % oo} delta {d}')
    prev = d
