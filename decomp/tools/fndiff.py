"""fndiff.py OBJ SEG_ROOT_OFF OOOO [LINES]: asmdiff for function _fn_SSSS_OOOO by name (obj offsets from publics)."""
import sys, subprocess, re; sys.path.insert(0, __file__.rsplit('/', 1)[0])
from omf import modules
NAMED = {'_main': '0003'}  # functions whose name cannot carry the orig offset
def orig_off(name):
    """orig offset of a function from its name: fn_SSSS_OOOO / loc_SSSS_OOOO -> OOOO; ovr_SSSS_OOOO -> overlay code
    offset of stub entry OOOO (tools/ovr.py); NAMED for the rest. None if unknown."""
    from names import orig as _o; name = _o(name)
    if name in NAMED: return int(NAMED[name], 16)
    mm = re.match(r'[_@](fn|loc|ovr)_([0-9a-f]{4})_([0-9a-f]{4})(\$.*)?$', name)
    if not mm: return None
    if mm.group(1) == 'ovr':
        from ovr import stub_to_code
        return stub_to_code(int(mm.group(2), 16), int(mm.group(3), 16))
    return int(mm.group(3), 16)
obj, segoff, oo = sys.argv[1], sys.argv[2], sys.argv[3]
lines = sys.argv[4] if len(sys.argv) > 4 else '60'
subprocess.run([sys.executable, '-I', __file__.rsplit('/', 1)[0] + '/cmpobj.py', obj, 'orig/MAIN.EXE', segoff, '0'], stdout=subprocess.DEVNULL)  # refresh obj.bin dump
m = modules(obj)[0]
pubs = sorted((o, n) for n, si, o in m['pubs'] if orig_off(n) is not None)
for (o, n), (o2, _) in zip(pubs, pubs[1:] + [(len(m['segs'][1]['data']), '')]):
    if orig_off(n) == int(oo, 16):
        print("====", n, flush=True)
        subprocess.run([__file__.rsplit('/', 1)[0] + '/asmdiff.sh', segoff, '%x' % o, '%x' % (o2 - o), oo, lines, obj + '.bin'])
