# Lands of Lore (MAIN.EXE) decomp notes

## Toolchain
- Borland C++ 3.1, large model. Proof: C0L.OBJ of 3.1 matches MAIN.EXE at 0000:0000 byte-exact except TLINK rewrites;
  3.0's C0L has different DGROUP offsets (`cs:[0260]` vs `[0291]`), 3.1's C0M too (`[7d]` → `[92]`).
- BC++ 3.1 install disks: `.CAn` split archives with a **5-byte** part header (3.0: 4 bytes) and hex part suffixes
  (`.CAA`, `.CAB`). Strip, concatenate, Info-ZIP unzip.
- TLINK 5.1 rewrites same-segment far transfers: `9A off seg` → `90 0E E8 rel` (call) and `EA off seg` → `90 90 E9 rel`
  (jmp). The masked fingerprint must accept both forms or RTL modules (SETARGV, SETENVP) go unmatched.
- VPRINTER failed the first masked search only because it sits in a gap; by size + masked compare it is exact.

## Layout (results/segtable.tsv: TLINK's segment table from the FBOV header, exeinfo field = FILE offset)
- 0000 C0 + CL.LIB _TEXT; 057f..1c86 game modules; 1c8d OVERLAY.LIB; 1db2..242d ~100 small segments (a second
  library linked after OVERLAY.LIB, presumably Westwood's own); 244c..2c2b far data; 2c3c..2c45 VROOMM tables;
  2cda..2e2a 80 overlay stubs; 2e2d DGROUP (0xb0ea bytes); 393c STACK.

## Full relink: MATCH (tools/relink.sh, blobs from tools/mkblob.py, layout in tools/layout.py)
Every fact below was needed to get the relinked MAIN.EXE byte-identical:
- Command: `TLINK /c /m /s C0L <root OBJs> /o <overlay OBJs>, MAIN, P…, OVERLAY WW CL` — library order
  **OVERLAY, WW, CL** (DGROUP shows it: OVERLAY.LIB _DATA at 0x2e40, Westwood data 0x2e46, CL data 0x3ae2).
- CL.LIB's index is not alphabetical (three sorted batches); TLINK lays out a library's modules in *index* order no
  matter who pulled them. The "two RTL runs" in _TEXT are just that, plus wrong guesses for twin modules sharing bytes
  (prefer GETVECT, UNLINK, TOLOWER/TOUPPER, _STPCPY, HARD, FNSPLIT, MEMxxx/STRxxx over DOSVECT, REMOVE, Fxxx …).
  READU/WRITEU are 3-byte `jmp` modules (`_read`/`_write`) too short to fingerprint.
- SETARGV/SETENVP are only reached through DS offsets: blobs must EXTDEF `__argv`/`_environ` to pull them.
- 4 Westwood modules (s074 s077 s129 s148) are never far-referenced: force them with EXTDEFs.
- Code segments are word aligned when they start even (BCC/TASM default), byte otherwise.
- Segment 150 is C0's `_FARDATA`, 195-197 C0's `_FARBSS`/`_OVERLAY_` + `_OVRDATA_`; 3 overlay stubs are empty
  (2dbf 2dc1 2de4) but still need an (empty) overlaid segment each.
- `#pragma exit` records: _EXIT_ holds 19ba:0081 (game), OVRUSER, the overlay entry 2e0b:002a (from a data-only
  WW.LIB module `w000`) and 2309:000c (WW s136).
- Header size: TLINK sizes the relocation table *before* rewriting same-segment far calls, so blobs must contain the
  original `9A` calls with fixups (otherwise the header is 0x200 bytes short).
- Overlay self references (`push seg ownfunc`): TLINK writes the stub key with bit 0 set unless the OBJ carries
  COMENT class A1 (`TD`, "new OMF extensions") — every BCC object has it.
- Relocation table order = module order × FIXUPP order. It reveals module ownership: a data-only first module (g000)
  owns far segments 167/179 and DGROUP 0x94..; s005 owns far seg 190; DGROUP pointer data belongs to s001 s013 s019
  s021 s040 (game) and w000 s128 s147 (WW). g000 pre-declares all far segments so their order stays put.
- The 13 bytes after `_EXEINFO_`'s table are a stale filename buffer + the link **date**: `main.exe\0\0\0` +
  first letter of the map file name ('p') + DOS date 1994-02-10. relink.sh runs `date 02/10/1994` in DOSBox-X
  (format with slashes; `02-10-1994` is silently ignored).

## Compiling game modules (tools/mc.sh NAME → run/m/NAME/NAME.OBJ; tools/relink.sh NAME)
- Flags `bcc -c -ml -3 -O -Z -Oe -Ol -Ob` (-Oe/-Ol fix register-variable and loop-rotation choices; -Ob removes the
  dead `jmp` after an if/else whose arms both jump and lets backward conditional jumps hit a shared return directly —
  judged worse on s001 alone, it fixed 4 of s008 and 4 of s009. s001/s002/s006 need `#pragma option -O-b` (-Ob drops
  a dead store `r = f();` the original kept); tools/remark.sh NAME re-marks after a flag change. -Om -Ov -Oi -Op
  -Ot -O2 -Ox -r- -k- -2 all worse; -Oc -Og -Oa -Os neutral). BC++ 4.0 BCC: 0/49 (saves si/di everywhere);
  TC++ 3.0 and the BC 3.0 patch disk have no -3. BCPP31.ZIP's BCC.EXE is byte-identical to ours.
- The original BCC never emitted ENTER (558 `push bp; mov bp,sp; sub sp,N`, still `leave`); ours always does.
  tools/objfix.py rewrites ENTER into the long frame (+2 / +3 bytes) and re-chunks the code LEDATAs.
- BCC OBJ layout: fixups of a FIXUPP in descending offset order, no threads. The original compiler's code LEDATAs are
  cut every 1024 bytes *across* function boundaries (no flush at function end — s001's reloc order proves it;
  objfix.FLUSH_AT_END=False). Reloc order in the EXE = descending within each 1024-byte chunk.
- Locals: declare in frame order (first declared = highest bp offset).
- Functions that won't match get `/* NONMATCHING reason */` above them: mc.sh still compiles/compares the C, then
  objfix.py transplants the original bytes (relocations → fixups) into the link OBJ, so the EXE stays identical.

## C idioms that pin BCC's code (collected while matching)
- Stack slots are handed out in order of first use, not declaration; when the original has a later-used local nearer
  bp, the other local lives in a nested `{ int blk; ... }` block (inner-scope slots come after the outer ones).
- Prototype `char` params change call code: `char` args are computed in 8 bits (`mov al; shl al,1`) and adjacent
  constant pushes are not merged into `push dword`; when the original merges or computes in 16 bits, prototype `int`.
- `if (!(flags & X)) return 0; ... return 1;` vs `if (flags & X) { ... return 1; } return 0;` differ (jz to the end).
- `x = c ? 8 : 0` -> jz/else-first; the original's `jnz` + `xor ax,ax` first comes from `c == 0 ? 0 : 8`.
- Switch with few sparse cases -> value table + loop scan (`mov cx,N; mov bx,table; cmp [cs:bx]`) after the code.
- char truth tests: `if (c)` / `c == 0` -> `cmp byte [..],0`; `!c` -> `mov al,..; cbw; or ax,ax`.
- `end = nv = expr;` -> `mov di,dx; mov ax,dx; mov [end],ax`; separate statements store di directly.
- A register param must be a register *local copy* to get si (`register int ch = chr;`); the first register local gets si.
- A temp used only between calls (`d = flags & mask; if (d && ...)`) lands in dx/cx without frame space.
- Ternary order is the branch order: `a <= b ? -2 : 2` puts the -2 on the fall-through path.
- Far scalar globals at fixed offsets of a far segment: declare `extern char far f_2803_0000[];` and index it
  (`f_2803_0000[0x45]`) to get `mov ax,SEG; mov es,ax; cmp byte [es:0x45]`.

### More BCC idioms (s015–s017)
- `register` gives priority for si; plain ints are auto-allocated to si/di by usage.
- `((char *)&px)[1]` gives `mov al,[bp-3]; cbw`; `(char)(px>>8)` does not.
- `d = f(); if (!d)` tests dx/ax differently from `if (!(d = f()))`.
- `push dword [g_7fd2]` (x,y passed together) means the original passed a `struct XY` by value; call through a cast prototype.
- An unused local still stored to the stack (`mov [bp-2],ax`) needs `volatile` or BCC drops the store.
- `ternary` as a call argument computes into ax then pushes; the original `push 3 / push 4` form is if/else with two full calls.
- A char table indexed from 1 may start inside the previous variable (g_2480 = g_2481-1): define the real bytes and `#define` the base.
- `c = (c & 0xff) | (n << 8)` on a char compiles to `and byte,0xff; shl al,8; or` (an original bug, kept).

### s029
- `#pragma option -O-b` / `-Ob` works *between functions*: switch jump optimisation off for one function only (s029
  fn_16cf_057a keeps the dead `jmp` after `if (c->state) return x; break;`).
- `(unsigned long)p - 4` gives `sub eax,4`; `(long)p - 4` gives `add eax,-4`.
- A `k = i + 1` temp in a block gives `mov dx,di; inc dx` and indexes with `[bx+base]`; `a[i + 1]` folds the +1
  into the displacement.
