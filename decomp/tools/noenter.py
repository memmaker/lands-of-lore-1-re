"""noenter.py OBJ [OUT]: rewrite BCC 3.1's `enter N,0` function prologues into `push bp; mov bp,sp; sub sp,N`.

Our BCC 3.1 (-3) opens every function that has locals with ENTER; the compiler that built MAIN.EXE never did (558
push/sub frames, no ENTER outside TASM PROCs) but otherwise generates identical code (same `leave`, `pop cx`,
3-operand imul). -Ot drops ENTER but also changes other choices, so we patch the OBJ instead:
  * ENTER sites = function starts (code PUBDEFs + every fixup target in the code segment) holding C8 lo hi 00
  * each site grows by 2 (sub sp,imm8) or 3 (sub sp,imm16) bytes; everything after it in the segment moves
  * LEDATA offsets/lengths, FIXUPP data offsets, displacements of fixups targeting the code segment (also those
    stored in the data word when the fixup has no displacement field), PUBDEF offsets and SEGDEF length follow
  * a LEDATA growing beyond 1024 bytes is split (each piece keeps its own FIXUPP)
Relative jumps never cross function starts in BCC output, so code bytes need no other change.
"""
import struct, sys, bisect


def records(buf):
    i = 0
    while i + 3 <= len(buf):
        t = buf[i]; n = struct.unpack_from('<H', buf, i + 1)[0]
        yield t, bytearray(buf[i + 3:i + 3 + n - 1])
        i += 3 + n


def rec(t, body):
    body = bytes(body)
    r = bytes([t]) + struct.pack('<H', len(body) + 1) + body
    return r + bytes([(-sum(r)) & 0xff])


def idx(d, p):
    b = d[p]
    return (b, p + 1) if b < 0x80 else (((b & 0x7f) << 8) | d[p + 1], p + 2)


def parse_fixupp(d, tthr):
    """list of subrecords: ('thread', bytes) or dict(loc, doff, pos_of_doff, target (meth, idx), disp_pos or None)"""
    out = []; p = 0
    while p < len(d):
        b = d[p]
        if b & 0x80:
            q = p
            loc = (b >> 2) & 0xf; doff = ((b & 3) << 8) | d[p + 1]; p += 2
            fd = d[p]; p += 1
            if not (fd & 0x80) and (fd >> 4) & 7 < 3: _, p = idx(d, p)
            if fd & 8: tm, ti = tthr.get(fd & 3, (None, None))
            else:
                tm = fd & 3; ti, p = idx(d, p)
            dp = None
            if not (fd & 4): dp = p; p += 2
            out.append(dict(q=q, end=p, loc=loc, doff=doff, tm=tm, ti=ti, dp=dp, m=(b >> 6) & 1))
        else:
            q = p
            meth = (b >> 2) & 7; num = b & 3; p += 1
            ti = None
            if (b & 0x40 and meth < 3) or (not b & 0x40 and meth < 4): ti, p = idx(d, p)
            if not b & 0x40: tthr[num] = (meth & 3, ti)
            out.append(dict(q=q, end=p, thread=True))
    return out


SIZE = {0: 1, 1: 2, 2: 2, 3: 4, 4: 1, 5: 2, 9: 4, 11: 6, 13: 4}


def main():
    src = sys.argv[1]; dst = sys.argv[2] if len(sys.argv) > 2 else src
    recs = list(records(open(src, 'rb').read()))
    lnames = ['']; segs = [None]
    # pass 1: segments, code images, candidates
    for t, d in recs:
        if t == 0x96:
            p = 0
            while p < len(d):
                n = d[p]; lnames.append(d[p + 1:p + 1 + n].decode('latin1')); p += 1 + n
        elif t == 0x98:
            a = d[0]; p = 1 + (3 if (a >> 5) == 0 else 0)
            ln = struct.unpack_from('<H', d, p)[0]; p += 2
            ni, p = idx(d, p); ci, p = idx(d, p)
            segs.append(dict(cls=lnames[ci], len=ln, data=bytearray(ln)))
    code = {i for i in range(1, len(segs)) if segs[i]['cls'] == 'CODE'}
    cand = {i: set() for i in code}
    tthr = {}; last = None
    for t, d in recs:
        if t == 0xa0:
            si, p = idx(d, 0); off = struct.unpack_from('<H', d, p)[0]; p += 2
            segs[si]['data'][off:off + len(d) - p] = d[p:]; last = (si, off)
        elif t == 0x90:
            p = 0; gi, p = idx(d, p); si, p = idx(d, p)
            if si == 0: p += 2
            while p < len(d):
                n = d[p]; p += 1 + n; off = struct.unpack_from('<H', d, p)[0]; p += 2; _, p = idx(d, p)
                if si in code: cand[si].add(off)
        elif t == 0x9c and last:
            for f in parse_fixupp(d, tthr):
                if f.get('thread') or f['tm'] != 0 or f['ti'] not in code: continue
                si, base = last; o = base + f['doff']
                v = struct.unpack_from('<H', segs[si]['data'], o)[0] if f['loc'] in (1, 3, 5) else 0
                disp = struct.unpack_from('<H', d, f['dp'])[0] if f['dp'] is not None else 0
                cand[f['ti']].add((v + disp) & 0xffff)
    sites = {}
    for si in code:
        img = segs[si]['data']; s = []
        for c in sorted(cand[si]):
            if c + 4 <= len(img) and img[c] == 0xc8 and img[c + 3] == 0:
                n = struct.unpack_from('<H', img, c + 1)[0]
                s.append((c, n))
        sites[si] = s
    if not any(sites.values()):
        if dst != src: open(dst, 'wb').write(open(src, 'rb').read())
        return

    def grow(n): return 2 if n < 0x80 else 3

    starts = {si: [c for c, _ in sites[si]] for si in code}
    cum = {}
    for si in code:
        acc = [0]
        for c, n in sites[si]: acc.append(acc[-1] + grow(n))
        cum[si] = acc

    def shift(si, x):
        if si not in code: return x
        return x + cum[si][bisect.bisect_left(starts[si], x)]

    def patch_code(si, start, data):
        """new bytes for an old LEDATA chunk [start, start+len) of code segment si"""
        out = bytearray(); end = start + len(data); p = start
        for c, n in sites[si]:
            if c < start or c >= end: continue
            out += data[p - start:c - start]
            out += b'\x55\x8b\xec' + (bytes([0x83, 0xec, n]) if n < 0x80 else b'\x81\xec' + struct.pack('<H', n))
            p = c + 4
            assert p <= end, 'ENTER split across LEDATA records'
        out += data[p - start:]
        return out

    # pass 2: rewrite
    out = bytearray(); tthr = {}; pend = None   # pending (si, oldstart, ledata body) awaiting its FIXUPP

    def flush(fx):
        nonlocal out
        si, start, body = pend
        hdr_end = idx(body, 0)[1] + 2
        data = bytearray(body[hdr_end:])
        fixes = []
        tt = dict(tthr_at)
        for f in (parse_fixupp(fx, tt) if fx is not None else []):
            if f.get('thread'): fixes.append((None, fx[f['q']:f['end']])); continue
            sub = bytearray(fx[f['q']:f['end']])
            o = start + f['doff']
            # displacement/data adjust for targets in a code segment with ENTER sites
            if f['tm'] == 0 and f['ti'] in code and sites[f['ti']]:
                ti = f['ti']
                if f['dp'] is not None:
                    dpos = f['dp'] - f['q']
                    disp = struct.unpack_from('<H', sub, dpos)[0]
                    v = struct.unpack_from('<H', data, o - start)[0] if f['loc'] in (1, 3, 5) else 0
                    nd = (shift(ti, (v + disp) & 0xffff) - v) & 0xffff
                    struct.pack_into('<H', sub, dpos, nd)
                elif f['loc'] in (1, 3, 5):
                    v = struct.unpack_from('<H', data, o - start)[0]
                    struct.pack_into('<H', data, o - start, shift(ti, v) & 0xffff)
            fixes.append((o, sub))
        if si in code and sites[si]:
            nstart = shift(si, start)
            ndata = patch_code(si, start, data)
        else:
            nstart, ndata = start, data
        # new positions of fixups
        pos = []
        for o, sub in fixes:
            pos.append((None if o is None else shift(si, o) - nstart, sub))
        # split into pieces of <= 1024 bytes not cutting a fixup field
        pieces = []; a = 0
        while True:
            b = min(len(ndata), a + 1024)
            if b < len(ndata):
                for np_, sub in pos:
                    if np_ is None: continue
                    loc = (sub[0] >> 2) & 0xf; sz = SIZE.get(loc, 2)
                    if np_ < b < np_ + sz: b = np_
            pieces.append((a, b)); a = b
            if a >= len(ndata): break
        threads = [sub for np_, sub in pos if np_ is None]
        for k, (a, b) in enumerate(pieces):
            segidx = body[:idx(body, 0)[1]]
            out += rec(0xa0, segidx + struct.pack('<H', nstart + a) + ndata[a:b])
            fb = bytearray(b''.join(threads) if k == 0 else b'')
            for np_, sub in pos:
                if np_ is None or not (a <= np_ < b): continue
                sub = bytearray(sub); r = np_ - a
                assert r < 1024
                sub[0] = (sub[0] & 0xfc) | (r >> 8); sub[1] = r & 0xff
                fb += sub
            if fb: out += rec(0x9c, fb)

    tthr_at = {}
    for t, d in recs:
        if pend is not None and t != 0x9c:
            flush(None); pend = None
        if t == 0xa0:
            si, p = idx(d, 0); off = struct.unpack_from('<H', d, p)[0]
            pend = (si, off, d); tthr_at = dict(tthr)
            continue
        if t == 0x9c and pend is not None:
            flush(d); parse_fixupp(d, tthr); pend = None
            continue
        if t == 0x9c:
            parse_fixupp(d, tthr)
        if t == 0x98:
            a = d[0]; p = 1 + (3 if (a >> 5) == 0 else 0)
            # find which segment this is (count SEGDEFs)
            k = sum(1 for tt, _ in out_segdefs) + 1
            out_segdefs.append((t, None))
            if k in code and sites[k]:
                ln = struct.unpack_from('<H', d, p)[0]
                struct.pack_into('<H', d, p, ln + cum[k][-1])
        if t == 0x90:
            p = 0; gi, p = idx(d, p); si, p = idx(d, p)
            if si == 0: p += 2
            while p < len(d):
                n = d[p]; p += 1 + n
                off = struct.unpack_from('<H', d, p)[0]
                struct.pack_into('<H', d, p, shift(si, off) & 0xffff); p += 2; _, p = idx(d, p)
        out += rec(t, d)
    if pend is not None: flush(None)
    open(dst, 'wb').write(out)


out_segdefs = []
if __name__ == '__main__':
    main()
