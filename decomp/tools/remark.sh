#!/bin/sh
# remark.sh NAME: drop every NONMATCHING marker of src/NAME.c, rebuild, then re-mark only the functions that still differ
cd "$(dirname "$0")/.." || exit 1
N=$1
sed -i '' '/^\/\* NONMATCHING.*\*\/$/d' src/$N.c
F=$(tools/mc.sh $N 2>&1 | grep "diff at" | sed 's/^_\([^:]*\):.*/\1/' | tr '\n' ' ')
[ -n "$F" ] && python3 -I tools/mark.py $N $F
tools/mc.sh $N 2>&1 | grep -E "functions match|uses original"
