; s044: segment 1b79 (TASM module)
	.386
S044_TEXT	segment word public use16 'CODE'
S044_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:S044_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
S044_TEXT	segment
	public	_fn_1b79_0000, _fn_1b79_025c, _fn_1b79_0261, _fn_1b79_027f, _fn_1b79_0284, _fn_1b79_02ac, _fn_1b79_02b1, _fn_1b79_02dd, _fn_1b79_02e3, _fn_1b79_02ef, _fn_1b79_0301, _fn_1b79_035b, _fn_1b79_0367, _fn_1b79_0450, _fn_1b79_0456
_fn_1b79_0000	proc	far
	add	[bx+si],al		; 0
	push	sp		; 2
	db	65h, 73h, 74h	; 3: gs jnc 0x7a
	add	[bx+si],al		; 6
	add	[bx+si],al		; 8
	add	[bx+si],al		; a
	add	[bx+si],al		; c
	add	[bx+si],al		; e
	add	[bx+si],al		; 10
	add	[bx+si],al		; 12
	add	[bx+si],al		; 14
	add	[bx+si],al		; 16
	add	[bx+si],al		; 18
	add	[bx+si],al		; 1a
	add	[bx+si],al		; 1c
	add	[bx+si],al		; 1e
	add	[bx+si],al		; 20
	add	[bx+si],al		; 22
	add	[bx+si],al		; 24
	add	[bx+si],al		; 26
	add	[bx+si],al		; 28
	add	[bx+si],al		; 2a
	add	[bx+si],al		; 2c
	add	[bx+si],al		; 2e
	add	[bx+si],al		; 30
	add	[bx+si],al		; 32
	add	[bx+si],al		; 34
	add	[bx+si],al		; 36
	add	[bx+si],al		; 38
	add	[bx+si],al		; 3a
	add	[bx+si],al		; 3c
	add	[bx+si],al		; 3e
	add	[bx+si],al		; 40
	add	[bx+si],al		; 42
	add	[bx+si],al		; 44
	add	[bx+si],al		; 46
	add	[bx+si],al		; 48
	add	[bx+si],al		; 4a
	add	[bx+si],al		; 4c
	add	[bx+si],al		; 4e
	add	[bx+si],al		; 50
	add	[bx+si],al		; 52
	add	[bx+si],al		; 54
	add	[bx+si],al		; 56
	add	[bx+si],al		; 58
	add	[bx+si],al		; 5a
	add	[bx+si],al		; 5c
	add	[bx+si],al		; 5e
	add	[bx+si],al		; 60
	add	[bx+si],al		; 62
	add	[bx+si],al		; 64
	add	[bx+si],al		; 66
	add	[bx+si],al		; 68
	add	[bx+si],al		; 6a
	add	[bx+si],al		; 6c
	add	[bx+si],al		; 6e
	add	[bx+si],al		; 70
	add	[bx+si],al		; 72
	add	[bx+si],al		; 74
	add	[bx+si],al		; 76
	add	[bx+si],al		; 78
	add	[bx+si],al		; 7a
	add	[bx+si],al		; 7c
	add	[bx+si],al		; 7e
	add	[bx+si],al		; 80
	add	[bx+si],al		; 82
	add	[bx+si],al		; 84
	add	[bx+si],al		; 86
	add	[bx+si],al		; 88
	add	[bx+si],al		; 8a
	add	[bx+si],al		; 8c
	add	[bx+si],al		; 8e
	add	[bx+si],al		; 90
	add	[bx+si],al		; 92
	add	[bx+si],al		; 94
	add	[bx+si],al		; 96
	add	[bx+si],al		; 98
	add	[bx+si],al		; 9a
	add	[bx+si],al		; 9c
	add	[bx+si],al		; 9e
	add	[bx+si],al		; a0
	add	[bx+si],al		; a2
	add	[bx+si],al		; a4
	add	[bx+si],al		; a6
	add	[bx+si],al		; a8
	add	[bx+si],al		; aa
	add	[bx+si],al		; ac
	add	[bx+si],al		; ae
	add	[bx+si],al		; b0
	add	[bx+si],al		; b2
	add	[bx+si],al		; b4
	add	[bx+si],al		; b6
	add	[bx+si],al		; b8
	add	[bx+si],al		; ba
	add	[bx+si],al		; bc
	add	[bx+si],al		; be
	add	[bx+si],al		; c0
	add	[bx+si],al		; c2
	add	[bx+si],al		; c4
	add	[bx+si],al		; c6
	add	[bx+si],al		; c8
	add	[bx+si],al		; ca
	add	[bx+si],al		; cc
	add	[bx+si],al		; ce
	add	[bx+si],al		; d0
	add	[bx+si],al		; d2
	add	[bx+si],al		; d4
	add	[bx+si],al		; d6
	add	[bx+si],al		; d8
	add	[bx+si],al		; da
	add	[bx+si],al		; dc
	add	[bx+si],al		; de
	add	[bx+si],al		; e0
	add	[bx+si],al		; e2
	add	[bx+si],al		; e4
	add	[bx+si],al		; e6
	add	[bx+si],al		; e8
	add	[bx+si],al		; ea
	add	[bx+si],al		; ec
	add	[bx+si],al		; ee
	add	[bx+si],al		; f0
	add	[bx+si],al		; f2
	add	[bx+si],al		; f4
	add	[bx+si],al		; f6
	add	[bx+si],al		; f8
	add	[bx+si],al		; fa
	add	[bx+si],al		; fc
	add	[bx+si],al		; fe
	add	[bx+si],al		; 100
	add	[bx+si],al		; 102
	add	[bx+si],al		; 104
	add	[bx+si],al		; 106
	add	[bx+si],al		; 108
	add	[bx+si],al		; 10a
	add	[bx+si],al		; 10c
	add	[bx+si],al		; 10e
	add	[bx+si],al		; 110
	add	[bx+si],al		; 112
	add	[bx+si],al		; 114
	add	[bx+si],al		; 116
	add	[bx+si],al		; 118
	add	[bx+si],al		; 11a
	add	[bx+si],al		; 11c
	add	[bx+si],al		; 11e
	add	[bx+si],al		; 120
	add	[bx+si],al		; 122
	add	[bx+si],al		; 124
	add	[bx+si],al		; 126
	add	[bx+si],al		; 128
	add	[bx+si],al		; 12a
	add	[bx+si],al		; 12c
	add	[bx+si],al		; 12e
	add	[bx+si],al		; 130
	add	[bx+si],al		; 132
	add	[bx+si],al		; 134
	add	[bx+si],al		; 136
	add	[bx+si],al		; 138
	add	[bx+si],al		; 13a
	add	[bx+si],al		; 13c
	add	[bx+si],al		; 13e
	add	[bx+si],al		; 140
	add	[bx+si],al		; 142
	add	[bx+si],al		; 144
	add	[bx+si],al		; 146
	add	[bx+si],al		; 148
	add	[bx+si],al		; 14a
	add	[bx+si],al		; 14c
	add	[bx+si],al		; 14e
	add	[bx+si],al		; 150
	add	[bx+si],al		; 152
	add	[bx+si],al		; 154
	add	[bx+si],al		; 156
	add	[bx+si],al		; 158
	add	[bx+si],al		; 15a
	add	[bx+si],al		; 15c
	add	[bx+si],al		; 15e
	add	[bx+si],al		; 160
	add	[bx+si],al		; 162
	add	[bx+si],al		; 164
	add	[bx+si],al		; 166
	add	[bx+si],al		; 168
	add	[bx+si],al		; 16a
	add	[bx+si],al		; 16c
	add	[bx+si],al		; 16e
	add	[bx+si],al		; 170
	add	[bx+si],al		; 172
	add	[bx+si],al		; 174
	add	[bx+si],al		; 176
	add	[bx+si],al		; 178
	add	[bx+si],al		; 17a
	add	[bx+si],al		; 17c
	add	[bx+si],al		; 17e
	add	[bx+si],al		; 180
	add	[bx+si],al		; 182
	add	[bx+si],al		; 184
	add	[bx+si],al		; 186
	add	[bx+si],al		; 188
	add	[bx+si],al		; 18a
	add	[bx+si],al		; 18c
	add	[bx+si],al		; 18e
	add	[bx+si],al		; 190
	add	[bx+si],al		; 192
	add	[bx+si],al		; 194
	add	[bx+si],al		; 196
	add	[bx+si],al		; 198
	add	[bx+si],al		; 19a
	add	[bx+si],al		; 19c
	add	[bx+si],al		; 19e
	add	[bx+si],al		; 1a0
	add	[bx+si],al		; 1a2
	add	[bx+si],al		; 1a4
	add	[bx+si],al		; 1a6
	add	[bx+si],al		; 1a8
	add	[bx+si],al		; 1aa
	add	[bx+si],al		; 1ac
	add	[bx+si],al		; 1ae
	add	[bx+si],al		; 1b0
	add	[bx+si],al		; 1b2
	add	[bx+si],al		; 1b4
	add	[bx+si],al		; 1b6
	add	[bx+si],al		; 1b8
	add	[bx+si],al		; 1ba
	add	[bx+si],al		; 1bc
	add	[bx+si],al		; 1be
	add	[bx+si],al		; 1c0
	add	[bx+si],al		; 1c2
	add	[bx+si],al		; 1c4
	add	[bx+si],al		; 1c6
	add	[bx+si],al		; 1c8
	add	[bx+si],al		; 1ca
	add	[bx+si],al		; 1cc
	add	[bx+si],al		; 1ce
	add	[bx+si],al		; 1d0
	add	[bx+si],al		; 1d2
	add	[bx+si],al		; 1d4
	add	[bx+si],al		; 1d6
	add	[bx+si],al		; 1d8
	add	[bx+si],al		; 1da
	add	[bx+si],al		; 1dc
	add	[bx+si],al		; 1de
	add	[bx+si],al		; 1e0
	add	[bx+si],al		; 1e2
	add	[bx+si],al		; 1e4
	add	[bx+si],al		; 1e6
	add	[bx+si],al		; 1e8
	add	[bx+si],al		; 1ea
	add	[bx+si],al		; 1ec
	add	[bx+si],al		; 1ee
	add	[bx+si],al		; 1f0
	add	[bx+si],al		; 1f2
	add	[bx+si],al		; 1f4
	add	[bx+si],al		; 1f6
	add	[bx+si],al		; 1f8
	add	[bx+si],al		; 1fa
	add	[bx+si],al		; 1fc
	add	[bx+si],al		; 1fe
	add	[bx+si],al		; 200
	add	[bx+si],al		; 202
	add	[bx+si],al		; 204
	add	[bx+si],al		; 206
	add	[bx+si],al		; 208
L020A:
	push	es		; 20a
	cmp	bx,+10h		; 20b
	jnc	short L0235		; 20e
	shl	bx,1		; 210
	shl	bx,1		; 212
	les	bx,[bx+2db2h]		; 214
	mov	cx,es		; 218
	or	cx,bx		; 21a
	jz	short L0235		; 21c
L021E:
	mov	cx,es:[bx]		; 21e
	cmp	cx,ax		; 221
	jz	short L023D		; 223
	add	bx,+4h		; 225
	cmp	cx,-1h		; 228
	jnz	short L021E		; 22b
	mov	ax,0h		; 22d
	mov	dx,0h		; 230
	pop	es		; 233
	db	0c3h	; 234: ret
L0235:
	mov	ax,0h		; 235
	mov	dx,0h		; 238
	pop	es		; 23b
	db	0c3h	; 23c: ret
L023D:
	mov	ax,es:[bx+2h]		; 23d
	mov	dx,es		; 241
	pop	es		; 243
	db	0c3h	; 244: ret
L0245:
	mov	bx,sp		; 245
	mov	bx,ss:[bx+4h]		; 247
	call	L020A		; 24b
	cmp	ax,0h		; 24e
	jnz	short L0258		; 251
	cmp	dx,+0h		; 253
	jz	short L025B		; 256
L0258:
	push	dx		; 258
	push	ax		; 259
	retf		; 25a
L025B:
	retf		; 25b
_fn_1b79_0000	endp

_fn_1b79_025c	proc	far
	mov	ax,78h		; 25c
	jmp	short L0245		; 25f
_fn_1b79_025c	endp

_fn_1b79_0261	proc	far
	mov	ax,79h		; 261
	jmp	short L0245		; 264
	mov	ax,86h		; 266
	jmp	short L0245		; 269
	mov	ax,7ah		; 26b
	jmp	short L0245		; 26e
	mov	ax,7bh		; 270
	jmp	short L0245		; 273
	mov	ax,85h		; 275
	jmp	short L0245		; 278
	mov	ax,7ch		; 27a
	jmp	short L0245		; 27d
_fn_1b79_0261	endp

_fn_1b79_027f	proc	far
	mov	ax,7dh		; 27f
	jmp	short L0245		; 282
_fn_1b79_027f	endp

_fn_1b79_0284	proc	far
	mov	ax,7eh		; 284
	jmp	short L0245		; 287
	mov	ax,7fh		; 289
	jmp	short L0245		; 28c
	mov	ax,80h		; 28e
	jmp	short L0245		; 291
	mov	ax,81h		; 293
	jmp	short L0245		; 296
	mov	ax,82h		; 298
	jmp	short L0245		; 29b
	mov	ax,83h		; 29d
	jmp	short L0245		; 2a0
	mov	ax,84h		; 2a2
	jmp	short L0245		; 2a5
	mov	ax,96h		; 2a7
	jmp	short L0245		; 2aa
_fn_1b79_0284	endp

_fn_1b79_02ac	proc	far
	mov	ax,97h		; 2ac
	jmp	short L0245		; 2af
_fn_1b79_02ac	endp

_fn_1b79_02b1	proc	far
	mov	ax,98h		; 2b1
	jmp	short L0245		; 2b4
	mov	ax,99h		; 2b6
	jmp	short L0245		; 2b9
	mov	ax,9ah		; 2bb
	jmp	short L0245		; 2be
	mov	ax,9bh		; 2c0
	jmp	short L0245		; 2c3
	mov	ax,9ch		; 2c5
	jmp	near ptr L0245		; 2c8
	mov	ax,9dh		; 2cb
	jmp	near ptr L0245		; 2ce
	mov	ax,9eh		; 2d1
	jmp	near ptr L0245		; 2d4
	mov	ax,9fh		; 2d7
	jmp	near ptr L0245		; 2da
_fn_1b79_02b1	endp

_fn_1b79_02dd	proc	far
	mov	ax,0aah		; 2dd
	jmp	near ptr L0245		; 2e0
_fn_1b79_02dd	endp

_fn_1b79_02e3	proc	far
	mov	ax,0abh		; 2e3
	jmp	near ptr L0245		; 2e6
	mov	ax,0adh		; 2e9
	jmp	near ptr L0245		; 2ec
_fn_1b79_02e3	endp

_fn_1b79_02ef	proc	far
	mov	ax,0aeh		; 2ef
	jmp	near ptr L0245		; 2f2
	mov	ax,0afh		; 2f5
	jmp	near ptr L0245		; 2f8
	mov	ax,0b0h		; 2fb
	jmp	near ptr L0245		; 2fe
_fn_1b79_02ef	endp

_fn_1b79_0301	proc	far
	mov	ax,0b1h		; 301
	jmp	near ptr L0245		; 304
	mov	ax,0b2h		; 307
	jmp	near ptr L0245		; 30a
	mov	ax,0b3h		; 30d
	jmp	near ptr L0245		; 310
	mov	ax,0b4h		; 313
	jmp	near ptr L0245		; 316
	mov	ax,0b5h		; 319
	jmp	near ptr L0245		; 31c
	mov	ax,0b6h		; 31f
	jmp	near ptr L0245		; 322
	mov	ax,0b7h		; 325
	jmp	near ptr L0245		; 328
	mov	ax,0b9h		; 32b
	jmp	near ptr L0245		; 32e
	mov	ax,0bah		; 331
	jmp	near ptr L0245		; 334
	mov	ax,0bbh		; 337
	jmp	near ptr L0245		; 33a
	mov	ax,0bch		; 33d
	jmp	near ptr L0245		; 340
	mov	ax,0bdh		; 343
	jmp	near ptr L0245		; 346
	mov	ax,0beh		; 349
	jmp	near ptr L0245		; 34c
	mov	ax,0bfh		; 34f
	jmp	near ptr L0245		; 352
	mov	ax,0c0h		; 355
	jmp	near ptr L0245		; 358
_fn_1b79_0301	endp

_fn_1b79_035b	proc	far
	mov	ax,0c1h		; 35b
	jmp	near ptr L0245		; 35e
	mov	ax,0c2h		; 361
	jmp	near ptr L0245		; 364
_fn_1b79_035b	endp

_fn_1b79_0367	proc	far
	mov	ax,0dch		; 367
	jmp	near ptr L0245		; 36a
	cmp	word ptr cs:[0h],+0h		; 36d
	jz	short L0378		; 373
	jmp	near ptr L042C		; 375
L0378:
	mov	word ptr cs:[0h],1h		; 378
	cld		; 37f
	push	ax		; 380
	push	bx		; 381
	push	cx		; 382
	push	dx		; 383
	push	si		; 384
	push	di		; 385
	push	bp		; 386
	push	es		; 387
	push	ds		; 388
	mov	ax,DGROUP		; 389
	mov	es,ax		; 38c
	mov	cs:[206h],ss		; 38e
	mov	cs:[208h],sp		; 393
	mov	ax,cs		; 398
	mov	ss,ax		; 39a
	mov	sp,206h		; 39c
	mov	word ptr es:[2daah],0h		; 39f
L03A6:
	mov	si,es:[2daah]		; 3a6
	shl	si,1		; 3ab
	cmp	word ptr es:[si+2cf8h],+2h		; 3ad
	jnz	short L0405		; 3b3
	mov	ds,es:[si+2cd6h]		; 3b5
	shl	si,1		; 3ba
	mov	ax,es:[si+2d1ah]		; 3bc
	mov	dx,es:[si+2d1ch]		; 3c1
	add	ax,es:[2da2h]		; 3c6
	adc	dx,es:[2da4h]		; 3cb
	cmp	dx,es:[si+2d60h]		; 3d0
	jc	short L03E0		; 3d5
	ja	short L03EC		; 3d7
	cmp	ax,es:[si+2d5eh]		; 3d9
	jnc	short L03EC		; 3de
L03E0:
	mov	es:[si+2d1ah],ax		; 3e0
	mov	es:[si+2d1ch],dx		; 3e5
	jmp	short L0405		; 3ea
L03EC:
	sub	ax,es:[si+2d5eh]		; 3ec
	sbb	dx,es:[si+2d60h]		; 3f1
	mov	es:[si+2d1ah],ax		; 3f6
	mov	es:[si+2d1ch],dx		; 3fb
	call	dword ptr es:[si+2c92h]		; 400
L0405:
	inc	word ptr es:[2daah]		; 405
	cmp	word ptr es:[2daah],+10h		; 40a
	jna	short L03A6		; 410
	mov	ss,cs:[206h]		; 412
	mov	sp,cs:[208h]		; 417
	pop	ds		; 41c
	pop	es		; 41d
	pop	bp		; 41e
	pop	di		; 41f
	pop	si		; 420
	pop	dx		; 421
	pop	cx		; 422
	pop	bx		; 423
	pop	ax		; 424
	mov	word ptr cs:[0h],0h		; 425
L042C:
	push	ax		; 42c
	mov	al,20h		; 42d
	out	20h,al		; 42f
	pop	ax		; 431
	cmp	word ptr cs:[2h],6554h		; 432
	jnz	short L0445		; 439
	cmp	word ptr cs:[4h],7473h		; 43b
	jnz	short L0445		; 442
	iret		; 444
L0445:
	sti		; 445
	db	0cch	; 446: int3
	jmp	short L0445		; 447
	pushf		; 449
	call	dword ptr es:[2da6h]		; 44a
	db	0c3h	; 44f: ret
_fn_1b79_0367	endp

_fn_1b79_0450	proc	far
	mov	ax,cs		; 450
	mov	dx,449h		; 452
	retf		; 455
_fn_1b79_0450	endp

_fn_1b79_0456	proc	far
	mov	ax,cs		; 456
	mov	dx,36dh		; 458
	retf		; 45b
_fn_1b79_0456	endp
S044_TEXT	ends
	end
