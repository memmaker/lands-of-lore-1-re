"""Minimal Intel OMF writer for blob modules (original bytes + symbolic fixups)."""
import struct


def rec(t, body):
    body = bytes(body)
    r = bytes([t]) + struct.pack('<H', len(body) + 1) + body
    return r + bytes([(-sum(r)) & 0xff])


def name(s):
    s = s.encode('latin1')
    return bytes([len(s)]) + s


def index(i):
    return bytes([i]) if i < 0x80 else bytes([0x80 | (i >> 8), i & 0xff])


class Module:
    """segs: list of dict(name, cls, align, data(bytes or None for BSS), size, fixups[(off, loc, kind, target)]).
    loc: 'base' (16-bit segment) or 'ptr' (16:16). kind: 'grp' (target = group name), 'ext' (target = symbol) or
    'seg' (target = (segment name, displacement)).
    pubs: [(name, segname, off)]. group: DGROUP members by segment name."""

    def __init__(self, modname):
        self.modname = modname
        self.segs = []
        self.pubs = []
        self.exts = []
        self.pieces = None
        self.coments = []   # raw COMENT bodies (e.g. Borland's -Y overlay marks)

    def seg(self, name, cls, align, data=None, size=None):
        s = dict(name=name, cls=cls, align=align, data=data, size=len(data) if data is not None else size, fixups=[])
        self.segs.append(s)
        return s

    def ext(self, sym):
        if sym not in self.exts:
            self.exts.append(sym)
        return self.exts.index(sym) + 1

    def bytes(self):
        if any(f[2] == 'grp' for s in self.segs for f in s['fixups']) and \
                not any(s['cls'] in ('DATA', 'BSS') for s in self.segs):
            self.seg('_DATA', 'DATA', 'word', b'')   # DGROUP needs a member segment for TLINK to place it
        out = rec(0x80, name(self.modname))
        for c in self.coments: out += rec(0x88, c)
        lnames = ['', 'DGROUP']
        for s in self.segs:
            for n in (s['name'], s['cls']):
                if n not in lnames: lnames.append(n)
        out += rec(0x96, b''.join(name(n) for n in lnames[1:]))
        AL = {'byte': 1, 'word': 2, 'para': 3, 'page': 4}
        for s in self.segs:
            out += rec(0x98, bytes([(AL[s['align']] << 5) | (2 << 2)]) + struct.pack('<H', s['size']) +
                       index(lnames.index(s['name'])) + index(lnames.index(s['cls'])) + index(1))
        dg = [i + 1 for i, s in enumerate(self.segs) if s['cls'] in ('DATA', 'BSS', 'EXITDATA')]
        if dg:
            out += rec(0x9a, index(lnames.index('DGROUP')) + b''.join(b'\xff' + index(i) for i in dg))
        # resolve externals first so EXTDEF precedes use
        for s in self.segs:
            for f in s['fixups']:
                if f[2] == 'ext': self.ext(f[3])
        if self.exts:
            body = b''
            for e in self.exts:
                piece = name(e) + b'\0'
                if len(body) + len(piece) > 1000:
                    out += rec(0x8c, body); body = b''
                body += piece
            out += rec(0x8c, body)
        for p, sname, off in self.pubs:
            si = [s['name'] for s in self.segs].index(sname) + 1
            gi = 1 if self.segs[si - 1]['cls'] in ('DATA', 'BSS', 'EXITDATA') else 0
            out += rec(0x90, index(gi) + index(si) + name(p) + struct.pack('<H', off) + b'\0')
        datas, lefts = {}, {}
        for si, s in enumerate(self.segs, 1):
            if s['data'] is None: continue
            data = bytearray(s['data'])
            for off, loc, kind, tgt in s['fixups']:
                n = 4 if loc == 'ptr' else 2
                data[off:off + n] = b'\0' * n
            datas[si] = data
            # emitted in list order (blobs replay the original FIXUPP order); self far calls make no reloc: order-free
            lefts[si] = [f for f in s['fixups'] if not (f[2] == 'seg' and f[1] == 'ptr')]
        names = [s['name'] for s in self.segs]
        # LEDATA emission order: self.pieces = [(segname, lo, hi)] interleaves segments as a compiler does
        pieces = [(names.index(n) + 1, lo, hi) for n, lo, hi in self.pieces] if self.pieces else \
            [(si, 0, len(d)) for si, d in datas.items()]
        for si, lo, hi in pieces:
            data, fx, left = datas[si], self.segs[si - 1]['fixups'], lefts[si]
            pos = lo
            while pos < hi:
                end = min(pos + 1024, hi)
                while True:
                    # do not split a fixup location across records
                    for off, loc, kind, tgt in fx:
                        n = 4 if loc == 'ptr' else 2
                        if off < end < off + n: end = off
                    # TLINK sees fixups chunk by chunk: cut the chunk so its fixups are a prefix of the remaining order
                    inr = [i for i, f in enumerate(left) if f[0] < end]
                    j = next((i for i in range(len(left)) if left[i][0] >= end), len(left))
                    late = [left[i][0] for i in inr if i > j]
                    if not late or min(late) <= pos: break
                    end = min(late)
                lefts[si] = left = [f for f in left if f[0] >= end]
                out += rec(0xa0, index(si) + struct.pack('<H', pos) + data[pos:end])
                sub = b''
                for off, loc, kind, tgt in fx:
                    if not (pos <= off < end): continue
                    r = off - pos
                    locb = {'base': 2, 'ptr': 3, 'loff': 5}[loc]
                    sub += bytes([0x80 | 0x40 | (locb << 2) | (r >> 8), r & 0xff])
                    if kind == 'grp':
                        # frame F1 (group), target T1 (group), no displacement
                        sub += bytes([(1 << 4) | (1 << 2) | 1]) + index(1) + index(1)
                    elif kind == 'seg':
                        # frame F5 (by target), target T0 (segment) + displacement; tgt = (segname, disp)
                        ti = index([x['name'] for x in self.segs].index(tgt[0]) + 1)
                        if tgt[1] is None: sub += bytes([(5 << 4) | (1 << 2)]) + ti   # P=1: no displacement
                        else: sub += bytes([(5 << 4) | 0]) + ti + struct.pack('<H', tgt[1])
                    else:
                        # frame F5 (by target), target T2 (external), no displacement
                        sub += bytes([(5 << 4) | (1 << 2) | 2]) + index(self.ext(tgt))
                    if len(sub) > 900:
                        out += rec(0x9c, sub); sub = b''
                if sub: out += rec(0x9c, sub)
                pos = end
        out += rec(0x8a, b'\0')
        return out
