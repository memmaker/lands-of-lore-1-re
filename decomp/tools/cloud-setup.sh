#!/bin/sh
# cloud-setup.sh: fetch the gitignored build inputs (toolchain, orig, gog, ghidra) from the private assets repo and
# install DOSBox-X, so relink.sh/mc.sh work in a fresh Linux container. Idempotent; run from a SessionStart hook.
cd "$(dirname "$0")/.." || exit 1
[ -f orig/MAIN.EXE ] && [ -d toolchain/bcpp31 ] && command -v dosbox-x >/dev/null && exit 0
command -v dosbox-x >/dev/null || { apt-get update -qq && apt-get install -y -qq dosbox-x; } >/dev/null 2>&1 \
  || echo "cloud-setup: dosbox-x install failed" >&2
if [ ! -f orig/MAIN.EXE ]; then
  T=$(mktemp -d) && git clone -q --depth 1 https://github.com/memmaker/lol1-decomp-assets.git "$T" \
    && cp -R "$T"/toolchain "$T"/orig "$T"/gog "$T"/ghidra . && rm -rf "$T" \
    || { echo "cloud-setup: cannot clone memmaker/lol1-decomp-assets (give the Claude GitHub app access)" >&2; exit 1; }
fi
