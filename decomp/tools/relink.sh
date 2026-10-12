#!/bin/sh
# relink.sh [OBJ|PARTS|module ...]: blobs for every module without an OBJ + the given OBJs into run/link, TLINK in
# DOSBox-X, then compare with orig/MAIN.EXE (if present). A bare module name takes tools/mc.sh's build of it
# (run/m/NAME/P/PARTS for a split module, else run/m/NAME/NAME.OBJ).
cd "$(dirname "$0")/.." && mkdir -p run/link && rm -f run/link/*.OBJ run/link/MAIN.EXE run/link/PMAIN.MAP || exit 1
ARGS=""
[ "$1" = all ] && set -- $(ls src/*.c src/*.asm 2>/dev/null | sed "s#src/##; s#\..*##" | sort -u)
for a in "$@"; do
  case $a in
    *.OBJ|*PARTS) ARGS="$ARGS $a";;
    *) if [ -f run/m/$a/P/PARTS ]; then ARGS="$ARGS run/m/$a/P/PARTS"
       else ARGS="$ARGS run/m/$a/$(echo $a | tr a-z A-Z).OBJ"; fi;;
  esac
done
python3 -I tools/mkblob.py run/link $ARGS || exit 1
printf '@echo off\r\nset PATH=D:\\INSTALL\r\ndate 02/10/1994\r\ntime 00:00:00\r\ndel WW.LIB\r\nTLIB WW.LIB @TLIB.RSP > TLIB.LOG\r\nTLINK /c /m /s @LINK.RSP > LINK.LOG\r\n' > run/link/LINK.BAT
tools/dosrun.sh run/link LINK.BAT </dev/null && cat run/link/LINK.LOG || exit 1
if [ -f orig/MAIN.EXE ]; then python3 -I tools/cmpexe.py run/link/MAIN.EXE orig/MAIN.EXE; else echo "built run/link/MAIN.EXE (no orig: parity not checked)"; fi
