"""dis.py SEG [START [END]]: ndisasm root segment SEG (hex para) of orig/MAIN.EXE, offsets relative to the segment.
START/END default to the segment's min/max from results/segtable.tsv."""
import subprocess, sys, os
sys.path.insert(0, os.path.dirname(__file__))
import lolcfg
seg = int(sys.argv[1], 16)
rows = [l.split('\t') for l in open('results/segtable.tsv').read().split('\n')[1:] if l]
mn, mx = max((int(r[4], 16), int(r[2], 16)) for r in rows if int(r[1], 16) == seg and r[3] == '1')
lo = int(sys.argv[2], 16) if len(sys.argv) > 2 else mn
hi = int(sys.argv[3], 16) if len(sys.argv) > 3 else mx
img = open(lolcfg.EXE, 'rb').read()[lolcfg.HDR:]
sys.stdout.write(subprocess.run(['ndisasm', '-b16', '-o', str(lo), '-'], input=img[seg * 16 + lo:seg * 16 + hi],
                                capture_output=True).stdout.decode())
