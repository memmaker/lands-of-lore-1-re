"""Module layout of MAIN.EXE for the full relink (link order = list order).

ROOT: (module, segtable index) for game code segments (segtable 1..47) and the Westwood library (49..149).
FAR:  (module, segtable index) for far data segments (150..197).
OVR:  (module, stub segment) for VROOMM overlays.
DATA / BSS: DGROUP byte ranges [a, b) contributed as blob data by a module.
Modules get address names (s001, f150, o2cda) until they are identified; rename here and in src/ together.
"""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ovr

GAME = [('s%03d' % i, i) for i in range(1, 48)]
WWLIB = [('s%03d' % i, i) for i in range(49, 150)]
WWHEAD = 'w000'   # data-only first module of WW.LIB
ROOT = GAME + WWLIB
# far data segments 151..194 (150: C0 _FARDATA; 195-197 (2c2b): C0 _FARBSS, _OVERLAY_, OVERLAY.LIB _OVRDATA_).
# FAR_OWN: segments whose relocations show the module that defines them; the rest are blobs of their own.
FAR_ALL = list(range(151, 195))
FAR_OWN = {'g000': [167, 179], 's005': [190]}
FAR = [('f%03d' % i, i) for i in FAR_ALL if not any(i in v for v in FAR_OWN.values())]
EMPTY_OVR = [0x2dbf, 0x2dc1, 0x2de4]   # overlay stubs with no code (empty overlaid segments)
OVR = [('o%04x' % s, s) for s in sorted(list(ovr.overlays()) + EMPTY_OVR)]

# DGROUP _DATA by module (ranges without pointers split by tools/xref.py's results/dsxref.tsv: data is laid out in
# module order, so each range starts at its module's first referenced item; s005 (no code) holds the shared globals)
# (the order of the original relocation table fixes which module owns which pointers):
# g000 is a data-only module linked first; C0L's 147-byte _DATA precedes it, OVERLAY.LIB _DATA (6 bytes) follows
# the game at 0x2e40, the Westwood library from 0x2e46, CL.LIB (ATEXIT, CTYPE, EXIT, ...) from 0x3ae2.
DATA = {'g000': (0x94, 0x1dcc), 's001': (0x1dcc, 0x1e8c), 's003': (0x1e8c, 0x1f16),
        's004': (0x1f16, 0x1f3a), 's005': (0x1f3a, 0x2196), 's007': (0x2196, 0x21d6), 's008': (0x21d6, 0x220a),
        's009': (0x220a, 0x2256), 's010': (0x2256, 0x2270), 's011': (0x2270, 0x2298), 's013': (0x2298, 0x23b0), 's014': (0x23b0, 0x23ba), 's015': (0x23ba, 0x241a),
        's017': (0x241a, 0x2494), 's019': (0x2494, 0x280e),
        's020': (0x280e, 0x282c), 's021': (0x282c, 0x284c), 's022': (0x284c, 0x2862), 's023': (0x2862, 0x2866), 's024': (0x2866, 0x2b30), 's040': (0x2b30, 0x2e40),
        'w000': (0x2e46, 0x3638), 's128': (0x3638, 0x3940), 's147': (0x3940, 0x3ae2)}
# LEDATA order of g000 (its relocations interleave far data and _DATA)
PIECES = {'g000': [('F167_FAR', None), ('_DATA', 0xd58), ('F179_FAR', None), ('_DATA', None)]}
GAME_BSS = (0x3ff8, 0xafa6)   # _BSS start (empty seg 322c:0008) .. first RTL _BSS (324 bytes of RTL BSS to 0xb0ea)
# #pragma exit entries (_EXIT_ records: priority, target seg:off) by contributing module, in link order
EXITS = {'s036': [(0x64, 0x19ba, 0x0081)], 'w000': [(0x64, 0x2e0b, 0x002a)], 's136': [(0xff, 0x2309, 0x000c)]}
BSS = {'gbss': GAME_BSS}


def order():
    """OBJs on the TLINK command line (the Westwood modules go into WW.LIB, see lib_order)"""
    return ['g000'] + [n for n, _ in GAME] + ['gbss'] + [n for n, _ in FAR] + [n for n, _ in OVR]


def lib_order():
    """modules of WW.LIB in library order"""
    return [WWHEAD] + [n for n, _ in WWLIB]


def rsp(parts={}):
    """TLINK response file: C0L, root OBJs, /o overlays, EXE, MAP, libraries (parts: module -> OBJ names of a
    split module)"""
    root = [x for n in order() if n not in dict(OVR) for x in parts.get(n, [n.upper()])]
    ov = [n.upper() for n, _ in OVR]
    lines = ['D:\\INSTALL\\C0L +']
    lines += [' '.join(root[k:k + 10]) + ' +' for k in range(0, len(root), 10)]
    lines += [('/o ' if k == 0 else '') + ' '.join(ov[k:k + 10]) + ' +' for k in range(0, len(ov), 10)]
    lines[-1] = lines[-1][:-2]
    # map name: TLINK leaves its last characters in the padding after _EXEINFO_; its first letter in the original was 'p'
    lines += ['MAIN', 'PMAIN', LIBS]
    return '\r\n'.join(lines) + '\r\n'


def tlib_rsp():
    """TLIB response file building WW.LIB from the module OBJs in library order"""
    mods = lib_order()
    return ''.join('+%s.OBJ %s\r\n' % (n.upper(), '&' if k < len(mods) - 1 else '') for k, n in enumerate(mods))



# C0L's _TEXT is followed by CL.LIB modules in library index order (TLINK lays out a library's modules in index
# order, whatever pulled them). CL.LIB's index is three alphabetical batches (A.._STPCPY, CPRINTF..WHEREXY,
# ATOL..XFFLUSH), which is why the original looks like several sorted runs.
LIBS = 'D:\\INSTALL\\OVERLAY WW D:\\INSTALL\\CL'
