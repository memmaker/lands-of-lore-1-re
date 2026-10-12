#!/bin/sh
# ofd.sh NAME CODEOFF [LINES]: asmdiff of the function of mc.sh's build of NAME (ENTER-fixed, no transplant) that
# starts at orig offset CODEOFF (overlay code offset / root segment offset).
cd "$(dirname "$0")/.." || exit 1
N=$1; U=$(echo $N | tr a-z A-Z); W=run/m/$N
cp $W/$U.RAW $W/F.OBJ && python3 -I tools/objfix.py $W/F.OBJ $N || exit 1
python3 -I tools/fndiff.py $W/F.OBJ $(python3 -I tools/segoff.py $N) $2 ${3:-60}
