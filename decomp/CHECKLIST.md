# Lands of Lore (CD 1.02d, GOG) — byte-exact decompilation + Go/Ebiten port

Tick items as they are done. Lessons go to NOTES.md (project) and ~/notes/how-to-decompile.md, ~/notes/c-to-go.md (general).

Targets: `MAIN.EXE` (md5 263998ec…, 356928 bytes: 248896 root + 108032 FBOV overlays), `LOLCD.EXE` (launcher, 19356 bytes).
`MAINW.EXE` is a variant (later, optional). Go port lives in `~/Projects/lands-of-lore-go`.

## Phase 0 — identify
- [x] Fork KForestland/lands-of-lore-1-re → memmaker/lands-of-lore-1-re (upstream = file formats + EMC2 scripts, no EXE decomp)
- [x] Extract GOG installer (innoextract); game data is the ISO `GAME.DAT` (volume LOL_V102); LOLCD.EXE launches MAIN.EXE/MAINW.EXE
- [x] EXE packing: none (MZ, CS:IP 0:0 = Borland C0, VROOMM `FBOV` overlays appended)
- [x] Toolchain: **Borland C++ 3.1** (C0L.OBJ of 3.1 matches byte-exact up to TLINK far→near call rewrites; 3.0 and 2.0 differ). TLINK 5.1 sig `fb 50`
- [x] Memory model: **large** (C0L; C0M has different DGROUP offsets)
- [ ] Verify MAIN.EXE boots in DOSBox-X with GAME.DAT mounted

## Phase 1 — toolchain
- [x] Obtain BC++ 3.0 → toolchain/bcpp30/install (CA sets joined, BC/CMDLINE/BIN/TASM/INCLUDE/STARTUP/*LIB unzipped)
- [x] BC++ 3.1 → toolchain/bcpp31/install (CA part header is 5 bytes in 3.1, 4 in 3.0; hex part suffixes .CAA)
- [x] Hello world (run/hello): TLINK 5.1 header `01 00 fb 50 6a 72`, lfarlc 0x3e identical; tools/dosrun.sh mounts bcpp31 as D:
- [x] RTL fingerprint (tools/fingerprint.py knows TLINK's far→near call rewrite): C0L + CL.LIB fill segment 0000 (22211/22522 bytes), OVERLAY.LIB = segment 1c8d → results/rtl_matches.tsv. VNEWN/VDELN/SRBSYNC hits are 7-12 byte false positives
- [x] Compiler flags (provisional, 1 fn): `bcc -c -ml -3 -O -Z` (run/flags/T1.C = fn_057f_000a 73/73 bytes; -O2, no -Z, no -O all differ)
- [x] Build pipeline (DOSBox-X batch, per-OBJ compare)
- [x] Final flags `-ml -3 -O -Z -Oe -Ol`; ENTER quirk handled by tools/objfix.py; NONMATCHING transplant
- [x] Other compilers ruled out: BC 4.0, TC++ 3.0, BC 3.0 patch

## Phase 2 — analysis
- [ ] Name functions from upstream RE (format decoders, EMC2/TIM opcode tables) + ScummVM kyra/lol (reading only)
- [ ] Use upstream Python tools as test oracles (LCW/CPS/SHP/WSA decode == ours)
- [x] Ghidra project ghidra/proj/LOL (MzLoader + FbovLoader: 80 overlays, 450 entries); results/decomp_raw.c = 1450 functions (3 failed)
- [x] Exact segment table from TLINK's FBOV segment info → results/segtable.tsv (151 code, 80 overlay, 50 data, 14 DGROUP-class); DGROUP = 2e2d
- [x] Tools ported to MAIN.EXE (tools/lolcfg.py, cmpobj/fndiff/asmdiff/ovr)
- [ ] Segment → module map (results/modules.tsv)
- [ ] Identify asm modules

## Phase 3 — rewrite to byte-exact C
- [x] Relink pipeline with blobs, full-EXE compare from day one — **MATCH** (md5 263998ec…, see NOTES.md)
- [ ] Every module from C/ASM (list per module below)
  - [x] s001 TIM interpreter (47/49 match, relink MATCH)
  - [x] s002 4/4, s003 sound 10/16, s004 combat 11/18, s006 9/9, s007 9/9
  - [x] s008 UI/misc 46/57, s009 movement 12/14, s010 portraits 11/11, s011 view transitions 8/8
  - [x] s012 flying objects 6/6, s013 timers 17/18, s014 inventory 7/7, s015 main loop/buttons 18/19
  - [x] s016 1/1, s017 monster AI 25/28 (MonType spells/think delay, Monster tdir/c1f decoded)
  - [ ] s018–s047 game modules (30 left)
  - [ ] s049–s149 WW library (~100 small modules, maybe TASM)
  - [ ] 80 overlays (objfix needs overlay support)
- [ ] Data/BSS modules generated as readable C
- [ ] Full MAIN.EXE identical, independent of originals; tag raw-decompile-1.0
- [ ] LOLCD.EXE identical

## Phase 4 — Go/Ebiten port (~/Projects/lands-of-lore-go)
- [ ] Machine translation C → Go (bards-tale-go approach), host lockstep goroutine
- [ ] DOS layer (files, CD/ISO reads, timer, keyboard, mouse), VGA 320x200
- [ ] Sound (AdLib .ADL / MIDI / VOC speech)
- [ ] Boot → intro → character select → in game
- [ ] Idiomatic cleanup pass (names, types)
- [ ] **Enhancement 1: turn-based mode toggled by a key** (as goeob: time only runs for N ticks after each action, "TURN" badge)

## Phase 5 — goplay
- [ ] `-import SRC`: folders, zip, ISO/BIN/CUE, GOG installer (setup_*.exe/.bin), loose files (internal/gameimport)
- [ ] COVER.PNG, wasm build
- [ ] Register in goplay games.js + deploy.sh, local test, publish, live check
- [ ] Notes updated (~/notes, goplay README games table)
