#!/bin/sh
# mc.sh NAME [BCC flags]: compile src/NAME.c (or assemble src/NAME.asm) in DOSBox-X and compare every function with
# the original (tools/cmpobj.py). Root modules sNNN compare against their code segment, overlays oSSSS against the
# overlay. Work dir run/m/NAME. Default flags: -ml -3 -O -Z -Oe -Ol (overlays add -Y); tools/objfix.py then turns
# BCC's ENTER prologues into the push/mov/sub frames of the original compiler.
# Functions marked /* NONMATCHING */ are compared as C, then objfix.py transplants their original bytes into the OBJ
# that relink.sh uses (run/m/NAME/NAME.OBJ).
cd "$(dirname "$0")/.." || exit 1
N=$1; shift; W=run/m/$N; mkdir -p $W; rm -rf $W/*.OBJ $W/OUT.LOG
U=$(echo $N | tr a-z A-Z)
cp src/*.H src/*.h $W/ 2>/dev/null
case $N in o*) F="-ml -3 -O -Z -Oe -Ol -Y";; *) F="-ml -3 -O -Z -Oe -Ol";; esac
[ $# -gt 0 ] && F="$*"
if [ -f src/$N.asm ] || [ -f src/$U.ASM ]; then
  cp src/$N.asm $W/$U.ASM 2>/dev/null || cp src/$U.ASM $W/
  printf '@echo off\r\nset PATH=D:\\INSTALL\r\nTASM /ml /m2 %s.ASM > OUT.LOG\r\n' $U > $W/B.BAT
else
  cp src/$N.c $W/$U.C
  printf '@echo off\r\nset PATH=D:\\INSTALL\r\nBCC -c %s -ID:\\INSTALL %s.C > OUT.LOG\r\n' "$F" $U > $W/B.BAT
fi
tools/dosrun.sh $W B.BAT </dev/null
tr -d '\r' < $W/OUT.LOG | grep -iE "error|warning" | grep -v "messages: *None" | head -30
[ -f $W/$U.OBJ ] || { echo "no OBJ"; exit 1; }
cp $W/$U.OBJ $W/$U.RAW; [ -f src/$N.c ] && python3 -I tools/objfix.py $W/$U.OBJ $N
python3 -I tools/segoff.py $N | { read OFF; python3 -I tools/cmpobj.py $W/$U.OBJ orig/MAIN.EXE $OFF; }
cp $W/$U.RAW $W/$U.OBJ
if [ -f src/$N.c ]; then
  M=$(python3 -I tools/split.py $N --marked)
  cp $W/$U.OBJ $W/$U.RAW
  python3 -I tools/objfix.py $W/$U.OBJ $N $M || exit 1
  [ -n "$M" ] && echo "link OBJ uses original bytes for: $M"
fi
exit 0
