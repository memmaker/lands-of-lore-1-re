#!/bin/sh
# asm.sh NAME: compact disassembly (offset + instruction) of root module NAME for reading
cd "$(dirname "$0")/.." || exit 1
python3 -I tools/dis.py $1 | awk '{printf "%s ", substr($1,5); for(i=3;i<=NF;i++) printf "%s ", $i; print ""}' | sed 's/0xffffffffffff/0x/g; s/ $//'
