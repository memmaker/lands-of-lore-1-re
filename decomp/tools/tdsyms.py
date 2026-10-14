#!/usr/bin/env python3
"""Print the Turbo Debugger symbols appended to a Borland EXE, or of a .TDS file: seg:off class name."""
import struct, sys
d = open(sys.argv[1], 'rb').read()
if d[:2] == b'\xfb\x52':  # a separate .TDS file
    img = 0
else:
    e = struct.unpack_from('<HHH', d, 2)
    img = (e[1] - (e[0] != 0)) * 512 + e[0]
t = d[img:]
assert t[:2] == b'\xfb\x52'
pool_size, = struct.unpack_from('<I', t, 4)
nsyms, = struct.unpack_from('<H', t, 14)
ext, = struct.unpack_from('<H', t, 0x2e)
pool = t[len(t) - pool_size:].split(b'\0')
base = 0x30 + ext
for i in range(nsyms):
    n, ty, o, sg, c = struct.unpack_from('<HHHHB', t, base + 9 * i)
    if n:
        print(f'{sg:04x}:{o:04x} {c:02x} {pool[n-1].decode()}')
