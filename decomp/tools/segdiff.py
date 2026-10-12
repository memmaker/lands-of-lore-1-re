"""segdiff.py [EXE]: TLINK segment table (FBOV _EXEINFO_) of a relinked EXE vs orig/MAIN.EXE, first differing rows."""
import struct, sys


def table(path):
    e = open(path, 'rb').read()
    h = struct.unpack_from('<14H', e)
    end = (h[2] - 1) * 512 + h[1] if h[1] else h[2] * 512
    x, n = struct.unpack_from('<II', e, end + 8)
    return [struct.unpack_from('<HHHH', e, x + i * 8) for i in range(n)]


a, b = table('orig/MAIN.EXE'), table(sys.argv[1] if len(sys.argv) > 1 else 'run/link/MAIN.EXE')
print('rows orig %d new %d' % (len(a), len(b)))
k = 0
for i in range(max(len(a), len(b))):
    x = a[i] if i < len(a) else None
    y = b[i] if i < len(b) else None
    if x != y:
        f = lambda t: ' '.join('%04x' % v for v in t) if t else '-'
        print('#%d orig %s | new %s' % (i, f(x), f(y)))
        k += 1
        if k > 12: break
