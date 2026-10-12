"""rawfn.py OBJ NAME: disassemble one public function straight from the .OBJ (fixup bytes zero)."""
import sys, subprocess; sys.path.insert(0, __file__.rsplit('/', 1)[0])
from omf import modules
m = modules(sys.argv[1])[0]; seg = m['segs'][1]
pubs = sorted((o, n) for n, si, o in m['pubs'] if si == 1)
for (o, n), (o2, _) in zip(pubs, pubs[1:] + [(len(seg['data']), '')]):
    if n == sys.argv[2]:
        p = '/tmp/claude-501/-Users-felix-Projects-decomp-might-magic/42c217d5-cca5-456c-8b3f-48fb9422ef46/scratchpad/raw.bin'
        open(p, 'wb').write(seg['data'][o:o2]); subprocess.run(['ndisasm', '-b16', p])
