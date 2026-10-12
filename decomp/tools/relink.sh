#!/bin/sh
# relink.sh [OBJ ...]: blobs for every module without an OBJ + the given OBJs into run/link, TLINK in DOSBox-X,
# then compare with orig/MAIN.EXE (if present).
cd "$(dirname "$0")/.." && mkdir -p run/link && rm -f run/link/*.OBJ run/link/MAIN.EXE run/link/PMAIN.MAP && \
python3 -I tools/mkblob.py run/link "$@" && printf '@echo off\r\nset PATH=D:\\INSTALL\r\ndate 02/10/1994\r\ntime 00:00:00\r\ndel WW.LIB\r\nTLIB WW.LIB @TLIB.RSP > TLIB.LOG\r\nTLINK /c /m /s @LINK.RSP > LINK.LOG\r\n' > run/link/LINK.BAT && \
tools/dosrun.sh run/link LINK.BAT && cat run/link/LINK.LOG || exit 1
if [ -f orig/MAIN.EXE ]; then python3 -I tools/cmpexe.py run/link/MAIN.EXE orig/MAIN.EXE; else echo "built run/link/MAIN.EXE (no orig: parity not checked)"; fi
