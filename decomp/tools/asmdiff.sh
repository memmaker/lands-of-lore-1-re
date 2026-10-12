#!/bin/bash
# asmdiff.sh SEG_ROOT_OFF OBJ_FN_START OBJ_FN_LEN ORIG_SEG_OFF [LINES] [OBJ.bin]: disassemble one function from a cmpobj
# dump (default: the newest run/build dump) vs orig and diff. Leaves $OBJBIN.orig / $OBJBIN.fn for inspection.
B=${6:-run/build/INIT.OBJ.bin}
cd "$(dirname "$0")/.." && python3 -I -c "
d=open('orig/MAIN.EXE','rb').read()[14336:]
open('$B.orig','wb').write(d[0x$1+0x$4:0x$1+0x$4+0x$3])
open('$B.fn','wb').write(open('$B','rb').read()[0x$2:0x$2+0x$3])"
diff <(ndisasm -b16 -o0x$4 $B.orig | cut -c1-9,29-) <(ndisasm -b16 -o0x$4 $B.fn | cut -c1-9,29-) | head -${5:-40}
