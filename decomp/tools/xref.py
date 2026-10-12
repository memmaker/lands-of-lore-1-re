"""xref.py [ADDR...]: DGROUP references of every game code module (root sNNN and overlays oSSSS), from ndisasm.
Counts direct memory operands ([0x1234], [bx+0x1234] without a segment override) and immediates >= 0x94 that are
followed by `push ds`/preceded by it or loaded into si/di/dx/ax next to a DS pointer use (heuristic: any immediate
word >= 0x94 in `mov reg,imm` / `push imm`). Writes results/dsxref.tsv (addr, kind, modules); with ADDRs prints them."""
import os, re, subprocess, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import mkblob as m, layout

def dis(code, org=0):
    return subprocess.run(['ndisasm', '-b16', '-o', str(org), '-'], input=bytes(code), capture_output=True).stdout.decode()

MEM = re.compile(r'(?<![a-z]:)\[(?:(?:bx|si|di|bp)(?:\+(?:si|di))?\+)?(0x[0-9a-f]+)\]')
IMM = re.compile(r'^(?:mov [a-d]x|mov [sd]i|push word|push dword),(?:word )?(0x[0-9a-f]+)$|^push word (0x[0-9a-f]+)$')

def scan(text):
    mem, imm = set(), set()
    for l in text.splitlines():
        ins = l[28:].strip() if len(l) > 28 else ''
        if 'bp' in ins and '[bp' in ins and '+0x' not in ins.split('[bp')[1][:3]: pass
        for mm in MEM.finditer(ins):
            if re.search(r'\[(?:bp)', ins) and not re.search(r'\[bp\+(?:si|di)', ins): continue
            if re.search(r'(es|cs|ss):\[', ins): continue
            mem.add(int(mm.group(1), 16))
        mi = IMM.match(ins)
        if mi:
            v = int(mi.group(1) or mi.group(2), 16)
            if 0x94 <= v < 0xb0ea: imm.add(v)
    return mem, imm

def build():
    refs = {}
    for n, i in layout.GAME + layout.WWLIB:
        a, b = m.entry(i)
        mem, imm = scan(dis(m.img[a:b]))
        for v in mem: refs.setdefault(v, {}).setdefault(n, set()).add('m')
        for v in imm: refs.setdefault(v, {}).setdefault(n, set()).add('i')
    for n, s in layout.OVR:
        o = m.ovrs.get(s)
        if not o: continue
        mem, imm = scan(dis(m.e[o['file']:o['file'] + o['size']]))
        for v in mem: refs.setdefault(v, {}).setdefault(n, set()).add('m')
        for v in imm: refs.setdefault(v, {}).setdefault(n, set()).add('i')
    with open('results/dsxref.tsv', 'w') as f:
        f.write('addr\trefs\n')
        for v in sorted(refs):
            f.write('%04x\t%s\n' % (v, ' '.join(n + ':' + ''.join(sorted(k)) for n, k in sorted(refs[v].items()))))

if __name__ == '__main__':
    os.chdir(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
    build()
