"""split.py NAME OUTDIR: split src/NAME.c at functions marked /* NONMATCHING */ (C kept for reading and porting;
the build links the original bytes of that function instead).

Writes OUTDIR/NAME_k.C for the C runs (each = preamble + prototypes of every module function + its functions,
compiled with -zC<NAME>_TEXT so all parts share one code segment) and OUTDIR/PARTS listing the parts in link order:
  C NAME_k            a C part
  FRAG lo hi fname    original bytes [lo, hi) of the module's code segment (segment offsets), public fname at lo
Prints nothing when NAME.c has no NONMATCHING function (single OBJ build).
"""
import os, re, sys

FN = re.compile(r'^[A-Za-z_][^;{}()]*?\b((?:fn|ovr)_([0-9a-f]{4})_([0-9a-f]{4}))\s*\([^;]*\)\s*$')


def functions(lines):
    """[(name, off, head_line, start_line, end_line)] of top-level function definitions"""
    out = []; i = 0
    while i < len(lines):
        m = FN.match(lines[i])
        if m and i + 1 < len(lines) and lines[i + 1].startswith('{'):
            j = i + 1
            while not lines[j].startswith('}'): j += 1
            out.append((m.group(1), int(m.group(3), 16), lines[i], i, j))
            i = j + 1
        elif m and lines[i].rstrip().endswith('}'):   # one-line body: int f(void) { return 1; }
            out.append((m.group(1), int(m.group(3), 16), lines[i], i, i)); i += 1
        else:
            m2 = re.match(r'^([A-Za-z_][^;{}()]*?\b(?:fn|ovr)_([0-9a-f]{4})_([0-9a-f]{4})\s*\([^;{]*\))\s*\{.*\}\s*$', lines[i])
            if m2:
                nm = re.search(r'((?:fn|ovr)_[0-9a-f]{4}_[0-9a-f]{4})', m2.group(1)).group(1)
                out.append((nm, int(m2.group(3), 16), m2.group(1), i, i))
            i += 1
    return out


def main():
    name, outdir = sys.argv[1], sys.argv[2]
    src = open(os.path.join(os.path.dirname(__file__), '..', 'src', name + '.c')).read()
    lines = src.split('\n')
    fns = functions(lines)
    marked = set()
    for k, (n, off, head, s, e) in enumerate(fns):
        p = s - 1
        while p >= 0 and lines[p].strip() == '': p -= 1
        if p >= 0 and 'NONMATCHING' in lines[p]: marked.add(k)
    if sys.argv[2] == '--marked':
        print(' '.join(fns[k][0] for k in sorted(marked))); return
    if not marked: return
    import layout, ovr
    seg_end = None
    if name in dict(layout.ROOT):
        st = ovr.segtable()[dict(layout.ROOT)[name]]
        seg_end = st[1] - st[3]
    pre = '\n'.join(lines[:fns[0][3]])
    protos = '\n'.join(re.sub(r'\s*\{.*$', '', h).rstrip() + ';' for n, off, h, s, e in fns)
    seg = name.upper() + '_TEXT'
    parts = []; cur = []; k = 0
    def flush(last):
        nonlocal cur, k
        if not cur and not last: return
        k += 1
        body = '\n'.join(cur)
        open(os.path.join(outdir, '%s_%d.C' % (name.upper(), k)), 'w').write(pre + '\n' + protos + '\n' + body + '\n')
        parts.append('C %s_%d' % (name.upper(), k)); cur = []
    prev_end = fns[0][3]
    for i, (n, off, head, s, e) in enumerate(fns):
        gap = lines[prev_end:s] if i else []
        if i in marked:
            cur += [l for l in gap if not re.match(r'^\s*(/\*.*\*/)?\s*$', l)]   # keep data defs, drop comments
            flush(False)
            nxt = fns[i + 1][1] if i + 1 < len(fns) else seg_end
            parts.append('FRAG %x %x _%s' % (off, nxt, n))
        else:
            cur += gap + lines[s:e + 1]
        prev_end = e + 1
    cur += lines[prev_end:]
    flush(True)
    open(os.path.join(outdir, 'PARTS'), 'w').write('\n'.join(parts) + '\n')
    print(seg)


if __name__ == '__main__':
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    main()
