#!/bin/sh
# dosrun.sh DIR BAT: run DIR/BAT inside DOSBox-X with DIR as C: and the toolchain as D: (no QMP, safe to run in parallel).
cd "$(dirname "$0")/.." && D=$(cd "$1" && pwd) && C=$(mktemp -t dosrun) && cat > "$C" <<EOC
[sdl]
output=surface
[dosbox]
machine=svga_s3
memsize=16
[cpu]
core=normal
cycles=max
[autoexec]
mount c "$D"
mount d "$PWD/toolchain/bcpp31"
c:
call $2
exit
EOC
DOSBOX_NO_HOST_INPUT=1 timeout 600 ~/tools/dosbox-x-remotedebug/src/dosbox-x -conf "$C" > /dev/null 2>&1; rm -f "$C"
