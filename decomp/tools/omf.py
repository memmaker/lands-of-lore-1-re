"""Minimal Intel OMF reader for Borland .OBJ/.LIB (TLIB) files.
modules(path) -> list of dicts: name, segs [{name, cls, data(bytearray), mask(bytearray 1=fixup byte)}], pubs [(name, segidx, off)]
"""
import struct

def records(buf):
    i = 0
    while i + 3 <= len(buf):
        t = buf[i]; n = struct.unpack_from('<H', buf, i + 1)[0]
        yield t, buf[i + 3:i + 3 + n - 1]
        i += 3 + n

def idx(d, p):
    b = d[p]
    return (b, p + 1) if b < 0x80 else (((b & 0x7f) << 8) | d[p + 1], p + 2)

def parse_module(recs):
    m = {'name': '', 'lnames': [''], 'segs': [{}], 'pubs': [], 'exts': []}
    last = None; tthr = {}
    for t, d in recs:
        if t == 0x80:
            m['name'] = d[1:1 + d[0]].decode('latin1')
        elif t == 0x96:
            p = 0
            while p < len(d):
                n = d[p]; m['lnames'].append(d[p + 1:p + 1 + n].decode('latin1')); p += 1 + n
        elif t in (0x98, 0x99):
            a = d[0]; p = 1
            if (a >> 5) == 0: p += 3
            if t == 0x98: ln = struct.unpack_from('<H', d, p)[0]; p += 2
            else: ln = struct.unpack_from('<I', d, p)[0]; p += 4
            ni, p = idx(d, p); ci, p = idx(d, p)
            m['segs'].append({'name': m['lnames'][ni], 'cls': m['lnames'][ci], 'data': bytearray(ln), 'mask': bytearray(ln)})
        elif t == 0x8c:
            p = 0
            while p < len(d):
                n = d[p]; m['exts'].append(d[p + 1:p + 1 + n].decode('latin1')); p += 1 + n
                _, p = idx(d, p)
        elif t in (0x90, 0x91):
            p = 0; gi, p = idx(d, p); si, p = idx(d, p)
            if si == 0: p += 2
            while p < len(d):
                n = d[p]; name = d[p + 1:p + 1 + n].decode('latin1'); p += 1 + n
                off = struct.unpack_from('<H', d, p)[0]; p += 2
                _, p = idx(d, p)
                m['pubs'].append((name, si, off))
        elif t == 0xa0:
            p = 0; si, p = idx(d, p); off = struct.unpack_from('<H', d, p)[0]; p += 2
            seg = m['segs'][si]; seg['data'][off:off + len(d) - p] = d[p:]
            last = (si, off)
        elif t == 0xa2:
            p = 0; si, p = idx(d, p); off = struct.unpack_from('<H', d, p)[0]; p += 2
            out = bytearray()
            def block(p):
                rc, bc = struct.unpack_from('<HH', d, p); p += 4
                if bc == 0:
                    n = d[p]; chunk = bytes(d[p + 1:p + 1 + n]); p += 1 + n
                else:
                    chunk = b''
                    for _ in range(bc):
                        c, p = block(p); chunk += c
                return chunk * rc, p
            while p < len(d):
                c, p = block(p); out += c
            seg = m['segs'][si]; seg['data'][off:off + len(out)] = out
            last = (si, off)
        elif t in (0x9c, 0x9d) and last:
            si, base = last; seg = m['segs'][si]; p = 0
            while p < len(d):
                b = d[p]
                if b & 0x80:
                    loc = (b >> 2) & 0xf; doff = ((b & 3) << 8) | d[p + 1]; p += 2
                    fd = d[p]; p += 1
                    if not (fd & 0x80) and (fd >> 4) & 7 < 3: _, p = idx(d, p)
                    tmeth, tidx = (fd & 3), None
                    if fd & 8: tmeth, tidx = tthr.get(fd & 3, (7, None))
                    else: tidx, p = idx(d, p)
                    disp = 0
                    if not (fd & 4): disp = struct.unpack_from('<H', d, p)[0]; p += 2
                    size = {0: 1, 1: 2, 2: 2, 3: 4, 4: 1, 5: 2, 9: 4}.get(loc, 2)
                    o = base + doff
                    if loc == 1 and tmeth == 0 and tidx == si:  # offset into own segment: keep value, mark 2
                        seg['mask'][o:o + 2] = b'\2\2'
                        v = struct.unpack_from('<H', seg['data'], o)[0] + disp
                        struct.pack_into('<H', seg['data'], o, v & 0xffff)
                    else:
                        seg['mask'][o:o + size] = b'\1' * size
                        if tmeth == 2 and tidx: seg.setdefault('ext', {})[o] = m['exts'][tidx - 1]  # external target name
                        if loc == 1 and tmeth in (0, 2) and tidx:   # 16-bit offset: remember target for value checks
                            tn = m['exts'][tidx - 1] if tmeth == 2 else '#' + m['segs'][tidx]['name']
                            seg.setdefault('off', {})[o] = (tn, disp)
                else:
                    meth = (b >> 2) & 7; num = b & 3; p += 1
                    ti = None
                    if (b & 0x40 and meth < 3) or (not b & 0x40 and meth < 4): ti, p = idx(d, p)
                    if not b & 0x40: tthr[num] = (meth & 3, ti)
    return m

def modules(path):
    buf = open(path, 'rb').read()
    if buf[0] == 0xf0:
        page = struct.unpack_from('<H', buf, 1)[0] + 3
        out = []; i = page
        while i < len(buf) and buf[i] == 0x80:
            recs = []; j = i
            for t, d in records(buf[i:]):
                recs.append((t, d)); j += 3 + len(d) + 1
                if t in (0x8a, 0x8b): break
            out.append(parse_module(recs))
            i = (j + page - 1) // page * page
        return out
    return [parse_module(list(records(buf)))]

if __name__ == '__main__':
    import sys
    for m in modules(sys.argv[1]):
        print(m['name'], [(s['name'], s['cls'], len(s['data']), sum(s['mask'])) for s in m['segs'][1:]], [p[0] for p in m['pubs']][:8])
