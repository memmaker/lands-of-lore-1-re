#!/bin/sh
# fd.sh NAME OOOO [LINES]: asm diff of function OOOO of the last tools/mc.sh NAME build vs the original
cd "$(dirname "$0")/.." || exit 1
U=$(echo $1 | tr a-z A-Z)
python3 -I tools/fndiff.py run/m/$1/$U.OBJ $(python3 -I tools/segoff.py $1) $2 ${3:-60}
