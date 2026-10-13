"""objfix.py OBJ MODULE [FN ...]: post-process a BCC 3.1 OBJ of root or overlay module MODULE so it links like the original.

1. ENTER: our BCC opens functions with locals with `enter N,0`; the compiler that built MAIN.EXE wrote
   `push bp; mov bp,sp; sub sp,N` (+2 bytes, +3 for N >= 0x80). Everything else it generates is identical.
2. Transplant: each FN (a function marked /* NONMATCHING */ in the C) is replaced by the original bytes of that
   function (up to the next function), with relocations turned back into OMF fixups.
3. Re-chunk: BCC buffers code per function and writes a LEDATA whenever 1024 bytes are full, the rest of the
   function at its end, and each record's fixups in descending order. TLINK writes relocations in that order, so
   the code records are rebuilt the same way from the edited image.
Fixups targeting the code segment (own far calls, switch tables, far pointers in _DATA), PUBDEFs and the SEGDEF
length follow the edits.
"""
import bisect, os, struct, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))


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


def index(i):
    return bytes([i]) if i < 0x80 else bytes([0x80 | (i >> 8), i & 0xff])


SIZE = {0: 1, 1: 2, 2: 2, 3: 4, 4: 1, 5: 2, 9: 4, 11: 6, 13: 4}


class Fix:
    """one FIXUPP subrecord: location (segment index, offset), raw bytes after the 2 locat bytes, target info"""
    def __init__(self, seg, off, b0, raw, tm, ti, dpos):
        self.seg, self.off, self.b0, self.raw, self.tm, self.ti, self.dpos = seg, off, b0, bytearray(raw), tm, ti, dpos

    @property
    def loc(self): return (self.b0 >> 2) & 0xf

    def bytes(self, r):
        return bytes([(self.b0 & 0xfc) | (r >> 8), r & 0xff]) + bytes(self.raw)


def parse_fixupp(d, seg, base):
    out = []; p = 0
    while p < len(d):
        b = d[p]
        assert b & 0x80, 'FIXUPP threads not supported'
        doff = ((b & 3) << 8) | d[p + 1]; q = p + 2; p = q
        fd = d[p]; p += 1
        if not (fd & 0x80) and (fd >> 4) & 7 < 3: _, p = idx(d, p)
        assert not (fd & 8), 'target thread'
        tm = fd & 3; ti, p = idx(d, p)
        dpos = None
        if not (fd & 4): dpos = p - q; p += 2
        out.append(Fix(seg, base + doff, b, d[q:p], tm, ti, dpos))
    return out


FLUSH_AT_END = False   # the original compiler kept filling the 1024-byte buffer across functions (s001 reloc order)


def orig_relocs(mod):
    """the original EXE's relocation positions inside MOD's code, in table order (None if unknown)"""
    try:
        import layout, mkblob, ovr
        if mod in dict(layout.OVR):
            return list(ovr.overlays()[dict(layout.OVR)[mod]]['relocs'])
        sseg, smx, _, smn = mkblob.st[dict(layout.ROOT)[mod]]; base = sseg * 16 + smn   # module code starts at smn
        return [r - base for r in mkblob.relocs if base <= r < sseg * 16 + smx]
    except Exception:
        return None


def reloc_order_cuts(mod, chunks, code_fx, n):
    """BCC does not always fill a record to 1024 bytes (it cuts before an item that would cross), so the plain
    1024-byte cuts can put relocations in a different record than the original. TLINK emits each record's
    relocations in descending order, so the original's table order gives the record grouping of its relocations:
    move cuts back (never forward, records stay <= 1024) until every descending run is one record."""
    orl = orig_relocs(mod)
    if not orl: return chunks
    runs = [[orl[0]]]
    for r in orl[1:]:
        if r < runs[-1][-1]: runs[-1].append(r)
        else: runs.append([r])
    fxs = sorted((o, o + SIZE.get(f.loc, 2)) for o, f in code_fx)
    def fstart(r):
        for o, e in fxs:
            if o <= r < e: return o
        return r
    spans = [(fstart(min(R)), max(R)) for R in runs]   # a run's record must hold [lo, hi]
    out = []; cstart = 0
    while cstart < n:
        c = min(cstart + 1024, n)
        while c < n:
            c0 = c
            for o, e in fxs:   # never split a fixup
                if o < c < e: c = o
            for lo, hi in spans:
                if lo < c <= hi and lo > cstart: c = lo        # run straddles the cut: whole run to the next
            ins = [lo for lo, hi in spans if cstart <= lo and hi < c]
            if len(ins) > 1: c = sorted(ins)[1]                # two runs in one record: cut between them
            if c == c0: break
        if c <= cstart: c = min(cstart + 1024, n)
        out.append((cstart, c)); cstart = c
    return out


def main():
    path, mod = sys.argv[1], sys.argv[2].lower()
    transplant = sys.argv[3:]
    recs = list(records(open(path, 'rb').read()))
    lnames = ['']; segs = [None]; exts = ['']; grps = ['']
    pubs = []   # (rec index, name, seg, off)
    for k, (t, d) in enumerate(recs):
        if t == 0x96:
            p = 0
            while p < len(d):
                n = d[p]; lnames.append(d[p + 1:p + 1 + n].decode('latin1')); p += 1 + n
        elif t == 0x98:
            a = d[0]; p = 1 + (3 if (a >> 5) == 0 else 0)
            ln = struct.unpack_from('<H', d, p)[0]; p += 2
            ni, p = idx(d, p); ci, p = idx(d, p)
            segs.append(dict(name=lnames[ni], cls=lnames[ci], len=ln, data=bytearray(ln), rec=k))
        elif t == 0x9a:
            grps.append(lnames[idx(d, 0)[0]])
        elif t == 0x8c:
            p = 0
            while p < len(d):
                n = d[p]; exts.append(d[p + 1:p + 1 + n].decode('latin1')); p += 1 + n; _, p = idx(d, p)
        elif t == 0x90:
            p = 0; gi, p = idx(d, p); si, p = idx(d, p)
            if si == 0: p += 2
            while p < len(d):
                n = d[p]; nm = d[p + 1:p + 1 + n].decode('latin1'); p += 1 + n
                pubs.append((k, nm, si, struct.unpack_from('<H', d, p)[0])); p += 2; _, p = idx(d, p)
    code = [i for i in range(1, len(segs)) if segs[i]['cls'] == 'CODE']
    assert len(code) == 1, 'one code segment expected'
    cs = code[0]
    fixes = []   # all fixups, by segment
    rawcuts = []   # code LEDATA starts in the raw OBJ
    last = None
    for t, d in recs:
        if t == 0xa0:
            si, p = idx(d, 0); off = struct.unpack_from('<H', d, p)[0]; p += 2
            segs[si]['data'][off:off + len(d) - p] = d[p:]; last = (si, off)
            if si == cs: rawcuts.append(off)
        elif t == 0x9c:
            fixes += parse_fixupp(d, *last)
    img = segs[cs]['data']

    def tval(f):
        """target offset of a fixup into the code segment (data word + displacement)"""
        v = struct.unpack_from('<H', segs[f.seg]['data'], f.off)[0] if f.loc in (1, 3, 5) else 0
        disp = struct.unpack_from('<H', f.raw, f.dpos)[0] if f.dpos is not None else 0
        return (v + disp) & 0xffff

    # function starts: code publics + every fixup target in the code segment
    starts = {o for _, _, si, o in pubs if si == cs}
    for f in fixes:
        if f.tm == 0 and f.ti == cs: starts.add(tval(f))
    pubname = {o: n for _, n, si, o in pubs if si == cs}
    fx0 = {f.off for f in fixes if f.seg == cs}
    for q in range(len(img) - 4):   # static functions: targets of fixup-less `push cs; call near`
        if img[q] == 0x0e and img[q + 1] == 0xe8 and q + 2 not in fx0:
            starts.add((q + 4 + struct.unpack_from('<h', img, q + 2)[0]) & 0xffff)
    fstarts = sorted(o for o in starts if o < len(img))

    edits = []   # (old lo, old hi, new bytes, new fixups [(new rel off, b0, raw-builder)])
    # 2. transplants
    smap = {}   # OBJ static start inside a transplant -> (range start, orig offset in range)
    o2obj = {}   # orig function offset -> OBJ offset (targets of restored same-segment far calls)
    if transplant:
        import re, mkblob, layout, lolcfg, ovr
        st = mkblob.st
        ovl = mod in dict(layout.OVR)
        if ovl:
            # overlay: original bytes are the overlay's code; relocated words are segment-table keys (index * 8)
            sseg = dict(layout.OVR)[mod]; ov = ovr.overlays()[sseg]
            oimg = ovr.exe()[ov['file']:ov['file'] + ov['size']]; base = 0; seg_end = ov['size']
            orl = ov['relocs']
            segval = lambda r: st[struct.unpack_from('<H', oimg, r)[0] // 8][0]
            own = None
            import split
            cf = split.functions(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', 'src',
                                                   mod + '.c')).read().split('\n'))
            def corig(n):
                m = re.match(r'_?(fn|ovr)_([0-9a-f]{4})_([0-9a-f]{4})$', n)
                if m.group(1) == 'ovr': return ovr.stub_to_code(int(m.group(2), 16), int(m.group(3), 16))
                return int(m.group(3), 16)
            # OBJ starts: publics + targets of BCC's fixup-less `push cs; call near` (static functions)
            fxpos0 = {f.off for f in fixes if f.seg == cs}
            ost = {o for _, _, si, o in pubs if si == cs}
            for q in range(len(img) - 4):
                if img[q] == 0x0e and img[q + 1] == 0xe8 and q + 2 not in fxpos0:
                    t = (q + 4 + struct.unpack_from('<h', img, q + 2)[0]) & 0xffff
                    if t < len(img): ost.add(t)
            ost = sorted(ost)
            objoff = {n: o for o, n in pubname.items() if re.match(r'_(fn|ovr)_[0-9a-f]{4}_[0-9a-f]{4}$', n)}
            origoff = {n: corig(n) for n in objoff}
        else:
            ri = dict(layout.ROOT)[mod]; sseg, smx, sfl, smn = st[ri]
            oimg = mkblob.img; base = sseg * 16; seg_end = smx
            orl = [r - base for r in mkblob.relocs if base <= r < base + 0x10000]
            segval = lambda r: struct.unpack_from('<H', oimg, base + r)[0]
            own = sseg
            def ooff(n):
                m = re.match(r'_fn_([0-9a-f]{4})_([0-9a-f]{4})$', n)
                return int(m.group(2), 16) if m else None
            ost = sorted(o for o in pubname if o < len(img))   # case labels are fixup targets too
            objoff = {n: o for o, n in pubname.items() if ooff(n) is not None}
            origoff = {n: ooff(n) for n in objoff}
        for n in objoff: o2obj[origoff[n]] = objoff[n]
        oo = sorted(origoff.values())
        for fn in transplant:
            fn = fn if fn.startswith('_') else '_' + fn
            lo_obj = objoff[fn]
            # overlay: a transplant also swallows the statics that follow (no names for them on either side)
            pst = sorted(objoff.values()) if ovl else ost
            k = pst.index(lo_obj)
            hi_obj = pst[k + 1] if k + 1 < len(pst) else len(img)
            olo = origoff[fn]
            j = oo.index(olo)
            ohi = oo[j + 1] if j + 1 < len(oo) else seg_end
            ob = bytearray(oimg[base + olo:base + ohi])
            nf = []
            rl = [r - olo for r in orl if olo <= r < ohi]
            for q in range(len(ob) - 4):   # TLINK's same-segment call rewrite back to a far call
                if ob[q:q + 3] == b'\x90\x0e\xe8' and not any(q <= r < q + 5 for r in rl):
                    tgt = (olo + q + 5 + struct.unpack_from('<h', ob, q + 3)[0]) & 0xffff
                    ob[q:q + 5] = b'\x9a\0\0\0\0'
                    nf.append((q + 1, 'self', tgt))
            for r in rl:
                v = segval(olo + r)
                ow = struct.unpack_from('<H', ob, r - 2)[0] if r >= 2 else 0
                far = r >= 3 and ob[r - 3] == 0x9a
                loc, kind, sym = mkblob.target(v, ow, mod)
                if ovl and v == sseg:
                    raise Exception('%s: reference to its own overlay at %04x not supported' % (fn, olo + r))
                if kind == 'grp':
                    nf.append((r, 'grp', None)); struct.pack_into('<H', ob, r, 0)
                elif v == own:
                    if far: nf.append((r - 2, 'self', ow)); struct.pack_into('<HH', ob, r - 2, 0, 0)
                    else: nf.append((r, 'selfbase', None)); struct.pack_into('<H', ob, r, 0)
                elif loc == 'ptr' or (far and kind == 'ext' and sym.startswith('__seg_')):
                    if sym.startswith('__seg_'): sym = '_fn_%04x_%04x' % (v, ow)
                    nf.append((r - 2, 'extptr', sym)); struct.pack_into('<HH', ob, r - 2, 0, 0)
                else:
                    if sym.startswith('__seg_f'):
                        i2 = int(sym[7:]); sym = '_f_%04x_%04x' % (st[i2][0], st[i2][3])
                    elif sym.startswith('__seg_'):
                        i2 = dict(layout.ROOT)[sym[6:]]; sym = '_fn_%04x_%04x' % (st[i2][0], st[i2][3])
                    nf.append((r, 'extbase', sym)); struct.pack_into('<H', ob, r, 0)
            # statics swallowed by the range: calls into them from outside must hit their original positions
            os_ = [o for o in ost if lo_obj < o < hi_obj]
            if os_:
                ws = set()
                for q in range(1, seg_end - 4):
                    if oimg[base + q] == 0x0e and oimg[base + q + 1] == 0xe8 and oimg[base + q - 1] != 0x90:
                        t = (q + 4 + struct.unpack_from('<h', oimg, base + q + 2)[0]) & 0xffff
                        if olo < t < ohi: ws.add(t)
                ws = sorted(ws)
                if len(ws) == len(os_):
                    for a, b in zip(os_, ws): smap[a] = (lo_obj, b - olo)
            edits.append((lo_obj, hi_obj, bytes(ob), nf, True))
    # 1. ENTER sites (outside transplanted ranges)
    for c in fstarts:
        if any(lo <= c < hi for lo, hi, _, _, _ in edits): continue
        if c + 4 <= len(img) and img[c] == 0xc8 and img[c + 3] == 0:
            n = struct.unpack_from('<H', img, c + 1)[0]
            nb = b'\x55\x8b\xec' + (bytes([0x83, 0xec, n]) if n < 0x80 else b'\x81\xec' + struct.pack('<H', n))
            edits.append((c, c + 4, nb, [], False))
    edits.sort()
    # BCC run through TASM (`#pragma inline` / asm statements): TASM writes each record's fixups in ascending order
    tasm = any(t == 0x88 and b'Turbo Assembler' in d for t, d in recs)
    if tasm and not edits: return

    los = [e[0] for e in edits]
    def newoff(x):
        """old code offset -> new; inside a replaced range: relative position clamped"""
        k = bisect.bisect_right(los, x) - 1
        d = sum(len(e[2]) - (e[1] - e[0]) for e in edits[:max(k, 0)])
        if k >= 0:
            lo, hi, nb, _, _ = edits[k]
            if x >= hi: return x + d + len(nb) - (hi - lo)
            if x == lo: return x + d
            return lo + d + min(x - lo, len(nb))
        return x

    # new code image + code fixups
    nimg = bytearray(); p = 0
    for lo, hi, nb, _, _ in edits:
        nimg += img[p:lo] + nb; p = hi
    nimg += img[p:]
    # near self calls (push cs; call rel16) are resolved by BCC without a fixup: re-aim them at the moved targets
    fxpos = {f.off for f in fixes if f.seg == cs}
    fset = set(fstarts)
    for q in range(len(img) - 4):
        if img[q] != 0x0e or img[q + 1] != 0xe8 or q + 2 in fxpos: continue
        t = (q + 4 + struct.unpack_from('<h', img, q + 2)[0]) & 0xffff
        if t not in fset or any(lo <= q < hi for lo, hi, _, _, _ in edits): continue
        nq = newoff(q + 1)
        nt = newoff(smap[t][0]) + smap[t][1] if t in smap else newoff(t)
        struct.pack_into('<h', nimg, nq + 1, (nt - (nq + 3) + 0x8000) % 0x10000 - 0x8000)
    # extra EXTDEFs for transplanted fixups
    newext = []
    def ext(sym):
        if sym in exts: return exts.index(sym)
        if sym not in newext: newext.append(sym)
        return len(exts) + newext.index(sym)
    dgroup = grps.index('DGROUP') if 'DGROUP' in grps else None
    # map old fixups
    code_fx = []   # (new offset, Fix)
    other_fx = {}  # id(fix) -> patched Fix
    for f in fixes:
        if f.seg == cs and any(lo <= f.off < hi for lo, hi, nb, nf, tp in edits if tp):
            continue   # inside a transplanted function: replaced
        if f.tm == 0 and f.ti == cs:
            v = struct.unpack_from('<H', segs[f.seg]['data'], f.off)[0] if f.loc in (1, 3, 5) else 0
            tv = tval(f); nt = newoff(tv)
            if f.dpos is not None:
                struct.pack_into('<H', f.raw, f.dpos, (nt - v) & 0xffff)
            elif f.loc in (1, 3, 5):
                tgt = nimg if f.seg == cs else segs[f.seg]['data']
                o = newoff(f.off) if f.seg == cs else f.off
                struct.pack_into('<H', tgt, o, nt & 0xffff)
        if f.seg == cs: code_fx.append((newoff(f.off), f))
    # transplanted fixups
    for lo, hi, nb, nf, tp in edits:
        if not nf: continue
        nlo = newoff(lo)
        for r, kind, arg in nf:
            o = nlo + r
            if kind == 'grp':
                f = Fix(cs, o, 0xc0 | (2 << 2), bytes([(1 << 4) | (1 << 2) | 1]) + index(dgroup) + index(dgroup), 1, dgroup, None)
            elif kind == 'self':
                # target = function at orig offset arg: its new offset in this OBJ
                tgt = newoff(o2obj[arg]) if arg in o2obj else None
                assert tgt is not None, 'self call target %04x not a public of this OBJ' % arg
                f = Fix(cs, o, 0xc0 | (3 << 2), bytes([(5 << 4) | 0]) + index(cs) + struct.pack('<H', tgt), 0, cs, None)
                struct.pack_into('<HH', nimg, o, 0, 0)
            elif kind == 'selfbase':
                f = Fix(cs, o, 0xc0 | (2 << 2), bytes([(5 << 4) | (1 << 2)]) + index(cs), 0, cs, None)
            elif kind == 'extptr':
                f = Fix(cs, o, 0xc0 | (3 << 2), bytes([(5 << 4) | (1 << 2) | 2]) + index(ext(arg)), 2, ext(arg), None)
            else:
                f = Fix(cs, o, 0xc0 | (2 << 2), bytes([(5 << 4) | (1 << 2) | 2]) + index(ext(arg)), 2, ext(arg), None)
            code_fx.append((o, f))
    code_fx.sort(key=lambda x: x[0])
    # 3. chunks: per function, flush every full 1024 bytes, flush the rest at the end of a function that flushed
    nstarts = sorted({newoff(o) for o in fstarts} | {0})
    bounds = nstarts[1:] + [len(nimg)]
    chunks = []; cstart = 0
    for fs, fe in zip(nstarts, bounds):
        flushed = False
        while fe - cstart >= 1024:
            cut = cstart + 1024
            for o, f in code_fx:   # never split a fixup
                if o < cut < o + SIZE.get(f.loc, 2): cut = o
            chunks.append((cstart, cut)); cstart = cut; flushed = True
        if FLUSH_AT_END and flushed and fe > cstart:
            chunks.append((cstart, fe)); cstart = fe
    if cstart < len(nimg): chunks.append((cstart, len(nimg)))
    if not tasm:
        chunks = reloc_order_cuts(mod, chunks, code_fx, len(nimg))
    # emit
    out = bytearray(); done_code = False; segcount = 0; pubk = {}
    for k, (t, d) in enumerate(recs):
        if t == 0x98:
            segcount += 1
            if segcount == cs:
                a = d[0]; p = 1 + (3 if (a >> 5) == 0 else 0)
                struct.pack_into('<H', d, p, len(nimg))
        elif t == 0x8c and newext and k == max(i for i, (tt, _) in enumerate(recs) if tt == 0x8c):
            out += rec(t, d)
            out += rec(0x8c, b''.join(bytes([len(s)]) + s.encode('latin1') + b'\0' for s in newext))
            continue
        elif t == 0x90:
            p = 0; gi, p = idx(d, 0); si, p = idx(d, p)
            if si == 0: p += 2
            while p < len(d):
                n = d[p]; p += 1 + n
                if si == cs:
                    struct.pack_into('<H', d, p, newoff(struct.unpack_from('<H', d, p)[0]))
                p += 2; _, p = idx(d, p)
        elif t == 0xa0:
            si = idx(d, 0)[0]
            if si == cs:
                if not done_code:
                    done_code = True
                    for a, b in chunks:
                        out += rec(0xa0, index(cs) + struct.pack('<H', a) + nimg[a:b])
                        fb = b''.join(f.bytes(o - a) for o, f in sorted(((o, f) for o, f in code_fx if a <= o < b),
                                                                        key=lambda x: x[0] if tasm else -x[0]))
                        if fb: out += rec(0x9c, fb)
                cur = 'code'; continue
            cur = 'other'
        elif t == 0x9c:
            if cur == 'code': continue
            # other segment: re-emit with patched displacements (same order)
            si, off = last_other
            fs = parse_fixupp(d, si, off)   # positions only; patched copies are in `fixes`
            body = b''
            for f0 in fs:
                f = next(x for x in fixes if x.seg == f0.seg and x.off == f0.off)
                body += f.bytes(f.off - off)
            out += rec(t, body); continue
        if t == 0xa0:
            si, p = idx(d, 0); off = struct.unpack_from('<H', d, p)[0]; p += 2
            last_other = (si, off)
            d = bytearray(index(si) + struct.pack('<H', off) + segs[si]['data'][off:off + len(d) - p])
        out += rec(t, d)
    open(path, 'wb').write(out)


if __name__ == '__main__':
    main()
