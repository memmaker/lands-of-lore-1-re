#!/bin/sh
# dosrun.sh DIR BAT: run DIR/BAT inside DOSBox-X with DIR as C: and the toolchain as D: (no QMP, safe to run in parallel).
cd "$(dirname "$0")/.." && D=$(cd "$1" && pwd) && C=$(mktemp "${TMPDIR:-/tmp}/dosrun.XXXXXX") && cat > "$C" <<EOC
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
mount d "$PWD/toolchain/${TC:-bcpp31}"
c:
call $2
exit
EOC
X=~/tools/dosbox-x-remotedebug/src/dosbox-x; [ -x "$X" ] || X=dosbox-x  # cloud: stock build, headless
SDL_VIDEODRIVER=${SDL_VIDEODRIVER:-$([ "$(uname)" = Linux ] && echo dummy)} DOSBOX_NO_HOST_INPUT=1 timeout 600 "$X" -conf "$C" > /dev/null 2>&1; rm -f "$C"
