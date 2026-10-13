#!/bin/sh
# rawdiff.sh NAME OOOO [LINES]: like fd.sh, but for a NONMATCHING function (diffs the compiled code, before transplant)
cd "$(dirname "$0")/.." || exit 1
U=$(echo $1 | tr a-z A-Z); T=run/m/$1/RAWFIX.OBJ
cp run/m/$1/$U.RAW $T && python3 -I tools/objfix.py $T $1 >/dev/null && \
python3 -I tools/fndiff.py $T $(python3 -I tools/segoff.py $1) $2 ${3:-60}
