#!/usr/bin/env python3
"""tdsfit.py EXE SYMS > FITTED: map a .TDS listing from a slightly different (larger) build onto EXE.
Functions (class 18) keep their order; each moves down by a delta that never decreases, snapped to
the next prologue (push bp; mov bp,sp or enter) at most SLACK bytes on. Prints the fitted listing
of the functions with their EXE seg:off (segment = the original's minus delta//16 paragraphs, so
offsets stay small) and, to stderr, the deltas."""
import struct, sys
SLACK = 96
d = open(sys.argv[1], 'rb').read()
hdr = struct.unpack_from('<H', d, 8)[0] * 16
syms = []
for l in open(sys.argv[2]):
    a, c, n = l.split()
    s, o = a.split(':')
    if c == '18':
        syms.append((int(s, 16) * 16 + int(o, 16), int(s, 16), n))
syms.sort()
def prologue(lin):
    b = d[hdr + lin:hdr + lin + 3]
    return b == b'\x55\x8b\xec' or b[:1] == b'\xc8'
delta = 0
for lin, seg, n in syms:
    for k in range(SLACK):
        if lin - delta - k >= 0 and prologue(lin - delta - k):
            delta += k
            break
    else:
        print(f'# {n}: no prologue near, delta {delta}', file=sys.stderr)
        continue
    e = lin - delta
    es = seg - (delta + 15) // 16
    while es * 16 > e:
        es -= 1
    print(f'{es:04x}:{e - es * 16:04x} 18 {n}')
    print(f'# {n} delta {delta}', file=sys.stderr)
