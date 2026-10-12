"""exeinfo.py EXE: segment map of a Borland large-model EXE with VROOMM overlays.

Segments come from the values stored at relocation targets (every far reference names its
segment). VROOMM stub segments start with `cd 3f` (int 3Fh); their header points into the FBOV
overlay data. Prints one line per segment: kind, para, image offset, size, overlay info.
"""
import struct, sys


def load(path):
    d = open(path, 'rb').read()
    h = struct.unpack('<14H', d[:28])
    hdr = h[4] * 16
    end = (h[2] - 1) * 512 + h[1] if h[1] else h[2] * 512
    relocs = [struct.unpack_from('<HH', d, h[12] + 4 * i) for i in range(h[3])]
    return d, h, hdr, end, relocs


def segments(path):
    d, h, hdr, end, relocs = load(path)
    img = d[hdr:end]
    segs = set()
    for off, seg in relocs:
        a = seg * 16 + off
        segs.add(seg)
        segs.add(struct.unpack_from('<H', img, a)[0])
    segs.add(h[11])  # CS
    segs.add(h[7])  # SS
    segs = sorted(s for s in segs if s * 16 < len(img))
    return d, h, hdr, end, img, segs


def main():
    d, h, hdr, end, img, segs = segments(sys.argv[1])
    ovr = d[end:]
    print('# header %d, image %d bytes, overlay data %d bytes, %d relocs, SS=%04x' % (hdr, len(img), len(ovr), h[3], h[7]))
    print('para\tstart\tsize\tkind\tinfo')
    for i, s in enumerate(segs):
        a = s * 16
        b = segs[i + 1] * 16 if i + 1 < len(segs) else len(img)
        kind, info = 'seg', ''
        if img[a:a + 2] == b'\xcd\x3f':
            # VROOMM stub header: int 3Fh, saveret(2), fileoff(4), codesize(2), fixupsize(2), jmpcnt(2), ...
            fo, cs, fx, jc = struct.unpack_from('<IHHH', img, a + 4)
            kind, info = 'stub', 'ovr+%05x code %d fix %d entries %d' % (fo, cs, fx, jc)
        print('%04x\t%05x\t%d\t%s\t%s' % (s, a, b - a, kind, info))


if __name__ == '__main__':
    main()
