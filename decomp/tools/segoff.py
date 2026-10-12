"""segoff.py NAME: image offset (hex) that tools/cmpobj.py compares module NAME against: SSSS*16 for root modules
(function names carry segment offsets), the overlay code start for overlays (names carry stub entries)."""
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import layout, ovr
n = sys.argv[1].lower()
if n in dict(layout.OVR): print('%x' % (ovr.overlays()[dict(layout.OVR)[n]]['img']))
else: print('%x' % (ovr.segtable()[dict(layout.ROOT)[n]][0] * 16))
