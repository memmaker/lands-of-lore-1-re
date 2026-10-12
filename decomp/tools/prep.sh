#!/bin/sh
# prep.sh NAME [OUT]: compact disassembly of module NAME to OUT (default /dev/stdout) and a dump of its _DATA range
cd "$(dirname "$0")/.." || exit 1
R=$(python3 -I -c "import sys; sys.path.insert(0,'tools'); import layout; r=layout.DATA.get('$1'); print('%x %x' % r if r else '')")
[ -n "$R" ] && python3 -I tools/dsdump.py $R
tools/asm.sh $1 > ${2:-/dev/stdout}
wc -l < ${2:-/dev/stdout} 2>/dev/null
