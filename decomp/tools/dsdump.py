"""dsdump.py LO HI: words and string runs of DGROUP [LO, HI) of the original MAIN.EXE"""
import struct, sys
d = open(__file__.rsplit('/', 2)[0] + '/orig/MAIN.EXE', 'rb').read()
b = struct.unpack_from('<H', d, 8)[0] * 16 + 0x2e2d * 16
lo, hi = int(sys.argv[1], 16), int(sys.argv[2], 16)
print(' '.join('%04x:%d' % (a, struct.unpack_from('<h', d, b + a)[0]) for a in range(lo, hi, 2)))
print(repr(d[b + lo:b + hi]))
