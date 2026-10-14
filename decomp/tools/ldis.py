#!/usr/bin/env python3
"""ldis.py EXE SEG LO HI: ndisasm a Borland EXE's load-relative segment SEG from LO to HI (hex),
labelling the TD symbols (syms.txt next to the EXE, or the file in $LDSYMS) and far calls."""
import os, re, struct, subprocess, sys, tempfile
exe, seg, lo, hi = sys.argv[1], int(sys.argv[2], 16), int(sys.argv[3], 16), int(sys.argv[4], 16)
d = open(exe, 'rb').read()
base = struct.unpack_from('<H', d, 8)[0] * 16 + seg * 16
syms = {}
for l in open(os.environ.get('LDSYMS') or os.path.join(os.path.dirname(exe), 'syms.txt')):
    a, c, n = l.split(); s, o = a.split(':'); syms.setdefault((int(s, 16), int(o, 16)), n)
with tempfile.NamedTemporaryFile(delete=False) as f:
    f.write(d[base + lo:base + hi])
out = subprocess.run(['ndisasm', '-b16', '-o', str(lo), f.name], capture_output=True, text=True).stdout
os.unlink(f.name)
for line in out.splitlines():
    a = int(line.split()[0], 16)
    if (seg, a) in syms: print(syms[(seg, a)] + ':')
    m = re.search(r'call (?:word )?(0x[0-9a-f]+):(?:word )?(0x[0-9a-f]+)', line)
    if m: line += '  ; ' + syms.get((int(m[1], 16), int(m[2], 16)), '?')
    m = re.search(r'call (?:word )?(0x[0-9a-f]+)$', line)
    if m and 'call' in line and ':' not in line.split('call')[1]: line += '  ; ' + syms.get((seg, int(m[1], 16)), '')
    print('  ' + line)
