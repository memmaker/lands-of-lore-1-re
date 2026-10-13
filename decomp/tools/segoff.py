"""segoff.py NAME: image offset (hex) that tools/cmpobj.py compares module NAME against: SSSS*16 for root modules
(function names carry segment offsets), the overlay code start for overlays (names carry stub entries)."""
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import layout, ovr
n = sys.argv[1].lower()
if n in dict(layout.FAR): print('%x' % (ovr.segtable()[dict(layout.FAR)[n]][0] * 16))   # data-only far module
elif n in dict(layout.OVR): print('%x' % ovr.overlays().get(dict(layout.OVR)[n], {'img': 0})['img'])   # empty overlay: no code
elif n in dict(layout.ROOT): print('%x' % (ovr.segtable()[dict(layout.ROOT)[n]][0] * 16))
else: print('0')   # data-only module (g000, gbss, w000): no functions to compare
