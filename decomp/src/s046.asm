; s046: segment 1c24 (TASM module)
	.386
S046_TEXT	segment word public use16 'CODE'
S046_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:S046_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	extrn	_fn_1ebc_000c:far
	extrn	_fn_1ebc_0053:far
	extrn	_fn_1ebc_0211:far
	extrn	_fn_1ebc_022a:far
	extrn	_fn_1ebc_0245:far
	extrn	_fn_2169_0945:far
S046_TEXT	segment
	public	_fn_1c24_0000, _fn_1c24_0161, _fn_1c24_0290, _fn_1c24_034f, _fn_1c24_049a, _fn_1c24_04eb, _fn_1c24_05ab, _fn_1c24_05e3, _fn_1c24_0626, _fn_1c24_0628
_fn_1c24_0000	proc	far
	push	ax		; 0
	push	cx		; 1
	push	dx		; 2
	mov	cl,6h		; 3
	mov	dx,ds:[2f87h]		; 5
	sar	dx,cl		; 9
	add	dx,+64h		; b
	cmp	dx,ds:[2f1ch]		; e
	jnl	short L001A		; 12
	mov	dx,ds:[2f1ch]		; 14
	jmp	short L0024		; 18
L001A:
	cmp	dx,ds:[2f1eh]		; 1a
	jng	short L0024		; 1e
	mov	dx,ds:[2f1eh]		; 20
L0024:
	mov	ds:[2f0eh],dx		; 24
	mov	cl,6h		; 28
	mov	ax,ds:[2f85h]		; 2a
	sar	ax,cl		; 2d
	add	ax,6bh		; 2f
	mov	cx,ax		; 32
	shl	ax,1		; 34
	add	cx,ax		; 36
	sar	cx,1		; 38
	cmp	cx,ds:[2f18h]		; 3a
	jnl	short L0046		; 3e
	mov	cx,ds:[2f18h]		; 40
	jmp	short L0050		; 44
L0046:
	cmp	cx,ds:[2f1ah]		; 46
	jng	short L0050		; 4a
	mov	cx,ds:[2f1ah]		; 4c
L0050:
	mov	ds:[2f0ch],cx		; 50
	pop	dx		; 54
	pop	cx		; 55
	pop	ax		; 56
	db	0c3h	; 57: ret
L0058:
	enter	2h,0h		; 58
	push	ax		; 5c
	push	bx		; 5d
	push	cx		; 5e
	mov	ax,ds:[2f91h]		; 5f
	and	ax,7h		; 62
	mov	bx,161h		; 65
	db	2eh, 0d7h	; 68: cs xlatb
	mov	bx,ax		; 6a
	xor	bl,ds:[2f45h]		; 6c
	jz	short L00A7		; 70
	mov	ds:[2f45h],al		; 72
	test	bl,2h		; 75
	jz	short L008E		; 78
	mov	cx,42h		; 7a
	test	al,2h		; 7d
	jnz	short L0085		; 7f
	or	cx,800h		; 81
L0085:
	push	cx		; 85
	call	far ptr _fn_2169_0945		; 86
	add	sp,+2h		; 8b
L008E:
	test	bl,1h		; 8e
	jz	short L00A7		; 91
	mov	cx,41h		; 93
	test	al,1h		; 96
	jnz	short L009E		; 98
	or	cx,800h		; 9a
L009E:
	push	cx		; 9e
	call	far ptr _fn_2169_0945		; 9f
	add	sp,+2h		; a4
L00A7:
	mov	bx,ds:[2f97h]		; a7
	test	bl,3h		; ab
	jz	short L00BC		; ae
	mov	cx,2dh		; b0
	push	cx		; b3
	call	far ptr _fn_2169_0945		; b4
	add	sp,+2h		; b9
L00BC:
	test	bl,4h		; bc
	jz	short L00E4		; bf
	mov	ax,ds:[2f89h]		; c1
	or	ax,ax		; c4
	jz	short L00E4		; c6
	cmp	ax,1fffh		; c8
	jnz	short L00D3		; cb
	mov	cx,ds:[2f52h]		; cd
	jmp	short L00D7		; d1
L00D3:
	mov	cx,ds:[2f54h]		; d3
L00D7:
	or	cx,cx		; d7
	jz	short L00E4		; d9
	push	cx		; db
	call	far ptr _fn_2169_0945		; dc
	add	sp,+2h		; e1
L00E4:
	test	bl,8h		; e4
	jz	short L010C		; e7
	mov	ax,ds:[2f8bh]		; e9
	or	ax,ax		; ec
	jz	short L010C		; ee
	cmp	ax,1fffh		; f0
	jnz	short L00FB		; f3
	mov	cx,ds:[2f46h]		; f5
	jmp	short L00FF		; f9
L00FB:
	mov	cx,ds:[2f48h]		; fb
L00FF:
	or	cx,cx		; ff
	jz	short L010C		; 101
	push	cx		; 103
	call	far ptr _fn_2169_0945		; 104
	add	sp,+2h		; 109
L010C:
	test	bl,10h		; 10c
	jz	short L0134		; 10f
	mov	ax,ds:[2f8dh]		; 111
	or	ax,ax		; 114
	jz	short L0134		; 116
	cmp	ax,1fffh		; 118
	jnz	short L0123		; 11b
	mov	cx,ds:[2f4ah]		; 11d
	jmp	short L0127		; 121
L0123:
	mov	cx,ds:[2f4ch]		; 123
L0127:
	or	cx,cx		; 127
	jz	short L0134		; 129
	push	cx		; 12b
	call	far ptr _fn_2169_0945		; 12c
	add	sp,+2h		; 131
L0134:
	test	bl,20h		; 134
	jz	short L015C		; 137
	mov	ax,ds:[2f8fh]		; 139
	or	ax,ax		; 13c
	jz	short L015C		; 13e
	cmp	ax,1fffh		; 140
	jnz	short L014B		; 143
	mov	cx,ds:[2f4eh]		; 145
	jmp	short L014F		; 149
L014B:
	mov	cx,ds:[2f50h]		; 14b
L014F:
	or	cx,cx		; 14f
	jz	short L015C		; 151
	push	cx		; 153
	call	far ptr _fn_2169_0945		; 154
	add	sp,+2h		; 159
L015C:
	pop	cx		; 15c
	pop	bx		; 15d
	pop	ax		; 15e
	leave		; 15f
	ret		; 160
_fn_1c24_0000	endp

_fn_1c24_0161	proc	far
	add	[bp+si],al		; 161
	add	al,6h		; 163
	add	[bp+di],ax		; 165
	add	ax,5007h		; 167
	push	bx		; 16a
	push	cx		; 16b
	push	dx		; 16c
	push	ds		; 16d
	push	si		; 16e
	push	es		; 16f
	push	di		; 170
	mov	di,dx		; 171
	mov	ax,DGROUP		; 173
	mov	ds,ax		; 176
	cmp	byte ptr ds:[2f43h],0h		; 178
	db	0fh, 85h, 6h, 1h	; 17d: jnz near 0x287
	cmp	byte ptr ds:[2f44h],0h		; 181
	jz	near ptr L0287		; 186
	cmp	word ptr ds:[2f0ah],+0h		; 18a
	jnz	near ptr L0287		; 18f
	cmp	byte ptr ds:[35eeh],1h		; 193
	jnz	short L01A3		; 198
	cmp	byte ptr ds:[0abdeh],0h		; 19a
	jnz	near ptr L0287		; 19f
L01A3:
	call	_fn_1c24_0000		; 1a3
	mov	cx,ds:[2f0ch]		; 1a6
	mov	dx,ds:[2f0eh]		; 1aa
	cmp	byte ptr ds:[35eeh],0h		; 1ae
	jnz	short L01C0		; 1b3
	test	word ptr ds:[35e6h],1000h		; 1b5
	jnz	short L01C0		; 1bb
	call	L0058		; 1bd
L01C0:
	cmp	byte ptr ds:[35eeh],2h		; 1c0
	jz	near ptr L0287		; 1c5
	cmp	word ptr ds:[2f0ah],+0h		; 1c9
	jnz	near ptr L0287		; 1ce
	cmp	word ptr ds:[3630h],+0h		; 1d2
	jz	short L01F2		; 1d7
	mov	ax,cx		; 1d9
	mov	cx,dx		; 1db
	sub	ax,ds:[3634h]		; 1dd
	mov	bx,ds:[3630h]		; 1e1
	cwd		; 1e5
	idiv	bx		; 1e6
	imul	bx		; 1e8
	add	ax,ds:[3634h]		; 1ea
	mov	dx,cx		; 1ee
	mov	cx,ax		; 1f0
L01F2:
	cmp	word ptr ds:[3632h],+0h		; 1f2
	jz	short L020E		; 1f7
	mov	ax,dx		; 1f9
	sub	ax,ds:[3636h]		; 1fb
	mov	bx,ds:[3632h]		; 1ff
	cwd		; 203
	idiv	bx		; 204
	imul	bx		; 206
	add	ax,ds:[3636h]		; 208
	mov	dx,ax		; 20c
L020E:
	mov	ds:[2f0ch],cx		; 20e
	mov	ds:[2f0eh],dx		; 212
	cmp	byte ptr ds:[35eeh],2h		; 216
	jz	short L022F		; 21b
	cmp	byte ptr ds:[35eeh],0h		; 21d
	jz	short L022F		; 222
	test	word ptr ds:[35e6h],1000h		; 224
	jnz	short L022F		; 22a
	call	L0058		; 22c
L022F:
	cmp	word ptr ds:[2f16h],+0h		; 22f
	jnz	short L027F		; 234
	cmp	ds:[2f28h],cx		; 236
	jnz	short L0242		; 23a
	cmp	ds:[2f2ah],dx		; 23c
	jz	short L027F		; 240
L0242:
	mov	ax,ds:[2f2ch]		; 242
	and	ax,0c000h		; 245
	cmp	ax,0c000h		; 248
	jz	short L025A		; 24b
	call	far ptr _fn_1ebc_000c		; 24d
	test	word ptr ds:[2f2ch],8000h		; 252
	jz	short L027A		; 258
L025A:
	cmp	cx,ds:[2f2eh]		; 25a
	jc	short L027A		; 25e
	cmp	cx,ds:[2f32h]		; 260
	ja	short L027A		; 264
	cmp	dx,ds:[2f30h]		; 266
	jc	short L027A		; 26a
	cmp	dx,ds:[2f34h]		; 26c
	ja	short L027A		; 270
	or	word ptr ds:[2f2ch],4000h		; 272
	jmp	short L027F		; 278
L027A:
	call	far ptr _fn_1ebc_0053		; 27a
L027F:
	mov	ds:[2f28h],cx		; 27f
	mov	ds:[2f2ah],dx		; 283
L0287:
	pop	di		; 287
	pop	es		; 288
	pop	si		; 289
	pop	ds		; 28a
	pop	dx		; 28b
	pop	cx		; 28c
	pop	bx		; 28d
	pop	ax		; 28e
	retf		; 28f
_fn_1c24_0161	endp

_fn_1c24_0290	proc	far
	or	[bx+si],al		; 290
	add	[bx+si],al		; 292
	add	[bx+si],al		; 294
	add	[bx+si],al		; 296
	add	[bx+si],al		; 298
	add	[bx+si],al		; 29a
L029C:
	push	ax		; 29c
	push	dx		; 29d
	push	es		; 29e
	push	si		; 29f
	mov	ax,169h		; 2a0
	mov	ds:[2f7bh],ax		; 2a3
	mov	ax,cs		; 2a6
	mov	ds:[2f7dh],ax		; 2a8
	mov	ax,2f85h		; 2ab
	mov	ds:[2f7fh],ax		; 2ae
	mov	ax,DGROUP		; 2b1
	mov	ds:[2f81h],ax		; 2b4
	mov	word ptr ds:[2f77h],7fh		; 2b7
	mov	word ptr ds:[2f79h],7fh		; 2bd
	mov	dx,2f77h		; 2c3
	mov	es,ax		; 2c6
	mov	ax,53c0h		; 2c8
	int	33h		; 2cb
	mov	ds:[2f6fh],dx		; 2cd
	mov	ds:[2f71h],es		; 2d1
	mov	si,dx		; 2d5
	mov	ax,es:[si]		; 2d7
	mov	ds:[2f73h],ax		; 2da
	mov	ax,es:[si+2h]		; 2dd
	mov	ds:[2f73h],ax		; 2e1
	mov	ax,1h		; 2e4
	push	ax		; 2e7
	push	ax		; 2e8
	push	ax		; 2e9
	call	far ptr _fn_1ebc_022a		; 2ea
	add	sp,+6h		; 2ef
	pop	si		; 2f2
	pop	es		; 2f3
	pop	dx		; 2f4
	pop	ax		; 2f5
	retf		; 2f6
L02F7:
	enter	0h,0h		; 2f7
	push	bx		; 2fb
	push	cx		; 2fc
	mov	bx,[bp+4h]		; 2fd
	mov	ax,bx		; 300
	xor	bl,ds:[2f45h]		; 302
	jz	short L033F		; 306
	mov	ds:[2f45h],al		; 308
	test	bl,2h		; 30b
	jz	short L0324		; 30e
	mov	cx,42h		; 310
	test	al,2h		; 313
	jnz	short L031B		; 315
	or	cx,800h		; 317
L031B:
	push	cx		; 31b
	call	far ptr _fn_2169_0945		; 31c
	add	sp,+2h		; 321
L0324:
	test	bl,1h		; 324
	jz	short L034B		; 327
	mov	cx,41h		; 329
	test	al,1h		; 32c
	jnz	short L0334		; 32e
	or	cx,800h		; 330
L0334:
	push	cx		; 334
	call	far ptr _fn_2169_0945		; 335
	add	sp,+2h		; 33a
	jmp	short L034B		; 33d
L033F:
	mov	cx,2dh		; 33f
	push	cx		; 342
	call	far ptr _fn_2169_0945		; 343
	add	sp,+2h		; 348
L034B:
	pop	cx		; 34b
	pop	bx		; 34c
	leave		; 34d
	db	0c3h	; 34e: ret
_fn_1c24_0290	endp

_fn_1c24_034f	proc	far
	enter	4h,0h		; 34f
	push	ax		; 353
	push	bx		; 354
	push	cx		; 355
	push	dx		; 356
	push	ds		; 357
	push	si		; 358
	push	es		; 359
	push	di		; 35a
	mov	[bp-4h],bx		; 35b
	mov	[bp-2h],ax		; 35e
	mov	ax,DGROUP		; 361
	mov	ds,ax		; 364
	cmp	byte ptr ds:[2f43h],0h		; 366
	jnz	near ptr L0490		; 36b
	cmp	byte ptr ds:[2f44h],0h		; 36f
	jz	near ptr L0490		; 374
	mov	ax,[bp-2h]		; 378
	and	ax,1eh		; 37b
	jnz	short L0389		; 37e
	cmp	word ptr ds:[2f0ah],+0h		; 380
	jnz	near ptr L0490		; 385
L0389:
	cmp	byte ptr ds:[35eeh],1h		; 389
	jnz	short L0399		; 38e
	cmp	byte ptr ds:[0abdeh],0h		; 390
	jnz	near ptr L0490		; 395
L0399:
	cmp	word ptr ds:[2f14h],+1h		; 399
	jnz	short L03A2		; 39e
	shr	cx,1		; 3a0
L03A2:
	cmp	cx,13fh		; 3a2
	jna	short L03AB		; 3a6
	mov	cx,13fh		; 3a8
L03AB:
	cmp	byte ptr ds:[35eeh],0h		; 3ab
	jnz	short L03C3		; 3b0
	test	word ptr ds:[35e6h],1000h		; 3b2
	jnz	short L03C3		; 3b8
	push	word ptr [bp-4h]		; 3ba
	call	L02F7		; 3bd
	add	sp,+2h		; 3c0
L03C3:
	cmp	byte ptr ds:[35eeh],2h		; 3c3
	jz	near ptr L0490		; 3c8
	cmp	word ptr ds:[2f0ah],+0h		; 3cc
	jnz	near ptr L0490		; 3d1
L03D5:
	cmp	word ptr ds:[3630h],+0h		; 3d5
	jz	short L03F5		; 3da
	mov	ax,cx		; 3dc
	mov	cx,dx		; 3de
	sub	ax,ds:[3634h]		; 3e0
	mov	bx,ds:[3630h]		; 3e4
	cwd		; 3e8
	idiv	bx		; 3e9
	imul	bx		; 3eb
	add	ax,ds:[3634h]		; 3ed
	mov	dx,cx		; 3f1
	mov	cx,ax		; 3f3
L03F5:
	cmp	word ptr ds:[3632h],+0h		; 3f5
	jz	short L0411		; 3fa
	mov	ax,dx		; 3fc
	sub	ax,ds:[3636h]		; 3fe
	mov	bx,ds:[3632h]		; 402
	cwd		; 406
	idiv	bx		; 407
	imul	bx		; 409
	add	ax,ds:[3636h]		; 40b
	mov	dx,ax		; 40f
L0411:
	mov	ds:[2f0ch],cx		; 411
	mov	ds:[2f0eh],dx		; 415
	cmp	byte ptr ds:[35eeh],2h		; 419
	jz	short L0438		; 41e
	cmp	byte ptr ds:[35eeh],0h		; 420
	jz	short L0438		; 425
	test	word ptr ds:[35e6h],1000h		; 427
	jnz	short L0438		; 42d
	push	word ptr [bp-4h]		; 42f
	call	L02F7		; 432
	add	sp,+2h		; 435
L0438:
	cmp	word ptr ds:[2f16h],+0h		; 438
	jnz	short L0488		; 43d
	cmp	ds:[2f28h],cx		; 43f
	jnz	short L044B		; 443
	cmp	ds:[2f2ah],dx		; 445
	jz	short L0488		; 449
L044B:
	mov	ax,ds:[2f2ch]		; 44b
	and	ax,0c000h		; 44e
	cmp	ax,0c000h		; 451
	jz	short L0463		; 454
	call	far ptr _fn_1ebc_000c		; 456
	test	word ptr ds:[2f2ch],8000h		; 45b
	jz	short L0483		; 461
L0463:
	cmp	cx,ds:[2f2eh]		; 463
	jc	short L0483		; 467
	cmp	cx,ds:[2f32h]		; 469
	ja	short L0483		; 46d
	cmp	dx,ds:[2f30h]		; 46f
	jc	short L0483		; 473
	cmp	dx,ds:[2f34h]		; 475
	ja	short L0483		; 479
	or	word ptr ds:[2f2ch],4000h		; 47b
	jmp	short L0488		; 481
L0483:
	call	far ptr _fn_1ebc_0053		; 483
L0488:
	mov	ds:[2f28h],cx		; 488
	mov	ds:[2f2ah],dx		; 48c
L0490:
	pop	di		; 490
	pop	es		; 491
	pop	si		; 492
	pop	ds		; 493
	pop	dx		; 494
	pop	cx		; 495
	pop	bx		; 496
	pop	ax		; 497
	leave		; 498
	retf		; 499
_fn_1c24_034f	endp

_fn_1c24_049a	proc	far
	or	[bx+si],al		; 49a
	add	[bx+si],al		; 49c
	add	[bx+si],al		; 49e
	add	[bx+si],al		; 4a0
	add	[bx+si],al		; 4a2
	add	[bx+si],al		; 4a4
	enter	2h,0h		; 4a6
	push	ax		; 4aa
	push	bx		; 4ab
	push	cx		; 4ac
	push	dx		; 4ad
	push	ds		; 4ae
	push	si		; 4af
	push	es		; 4b0
	push	di		; 4b1
	mov	cx,ds:[2f0ch]		; 4b2
	mov	ax,ds:[2f28h]		; 4b6
	sub	ax,cx		; 4b9
	jnc	short L04BF		; 4bb
	neg	ax		; 4bd
L04BF:
	cmp	ax,1h		; 4bf
	jnl	short L04D6		; 4c2
	mov	cx,ds:[2f0eh]		; 4c4
	mov	ax,ds:[2f2ah]		; 4c8
	sub	ax,cx		; 4cb
	jnc	short L04D1		; 4cd
	neg	ax		; 4cf
L04D1:
	cmp	ax,1h		; 4d1
	jl	short L04E1		; 4d4
L04D6:
	mov	cx,ds:[2f0ch]		; 4d6
	mov	dx,ds:[2f0eh]		; 4da
	jmp	near ptr L03D5		; 4de
L04E1:
	pop	di		; 4e1
	pop	es		; 4e2
	pop	si		; 4e3
	pop	ds		; 4e4
	pop	dx		; 4e5
	pop	cx		; 4e6
	pop	bx		; 4e7
	pop	ax		; 4e8
	leave		; 4e9
	retf		; 4ea
_fn_1c24_049a	endp

_fn_1c24_04eb	proc	far
	push	bx		; 4eb
	push	cx		; 4ec
	push	dx		; 4ed
	push	es		; 4ee
	mov	ax,3533h		; 4ef
	int	21h		; 4f2
	mov	word ptr ds:[2f0ch],0a0h		; 4f4
	mov	word ptr ds:[2f0eh],64h		; 4fa
	mov	word ptr ds:[2f16h],1h		; 500
	mov	word ptr ds:[2f2ch],0h		; 506
	mov	word ptr ds:[2f1ah],13fh		; 50c
	mov	word ptr ds:[2f1eh],0c7h		; 512
	mov	ax,es		; 518
	or	ax,bx		; 51a
	jz	short L0526		; 51c
	mov	bl,es:[bx]		; 51e
	cmp	bl,0cfh		; 521
	jnz	short L0530		; 524
L0526:
	mov	ax,0h		; 526
	mov	byte ptr ds:[2f42h],0h		; 529
	db	0ebh, 76h	; 52e: jmp short 0x5a6
L0530:
	mov	ax,0h		; 530
	int	33h		; 533
	cmp	ax,0ffffh		; 535
	jnz	short L0526		; 538
	call	far ptr _fn_1ebc_0245		; 53a
	or	ax,ax		; 53f
	jz	short L0561		; 541
	push	cs		; 543
	call	L029C		; 544
	call	far ptr _fn_1ebc_0211		; 547
	call	_fn_1c24_0000		; 54c
	mov	word ptr ds:[2f14h],0h		; 54f
	mov	byte ptr ds:[2f42h],1h		; 555
	mov	byte ptr ds:[2f43h],1h		; 55a
	jmp	short L05A3		; 55f
L0561:
	mov	word ptr ds:[2f14h],0h		; 561
	mov	ax,3h		; 567
	int	33h		; 56a
	cmp	cx,0a0h		; 56c
	jz	short L0578		; 570
	mov	word ptr ds:[2f14h],1h		; 572
L0578:
	mov	cx,0a0h		; 578
	mov	dx,64h		; 57b
	mov	byte ptr ds:[2f42h],1h		; 57e
	mov	byte ptr ds:[2f43h],1h		; 583
	cmp	word ptr ds:[2f14h],+1h		; 588
	jnz	short L0591		; 58d
	shl	cx,1		; 58f
L0591:
	mov	ax,4h		; 591
	int	33h		; 594
	mov	ax,0ch		; 596
	mov	cx,1fh		; 599
	push	cs		; 59c
	pop	es		; 59d
	mov	dx,34fh		; 59e
	int	33h		; 5a1
L05A3:
	mov	ax,1h		; 5a3
L05A6:
	pop	es		; 5a6
	pop	dx		; 5a7
	pop	cx		; 5a8
	pop	bx		; 5a9
	retf		; 5aa
_fn_1c24_04eb	endp

_fn_1c24_05ab	proc	far
	push	ax		; 5ab
	push	cx		; 5ac
	push	dx		; 5ad
	push	es		; 5ae
	cmp	byte ptr ds:[2f42h],0h		; 5af
	jz	short L05DE		; 5b4
	mov	byte ptr ds:[2f42h],0h		; 5b6
	cmp	byte ptr ds:[2f5eh],1h		; 5bb
	jz	short L05D1		; 5c0
	mov	ax,0ch		; 5c2
	mov	cx,0h		; 5c5
	push	cs		; 5c8
	pop	es		; 5c9
	mov	dx,34fh		; 5ca
	int	33h		; 5cd
	jmp	short L05DE		; 5cf
L05D1:
	mov	dx,ds:[2f6fh]		; 5d1
	mov	es,ds:[2f71h]		; 5d5
	mov	ax,53c0h		; 5d9
	int	33h		; 5dc
L05DE:
	pop	es		; 5de
	pop	dx		; 5df
	pop	cx		; 5e0
	pop	ax		; 5e1
	retf		; 5e2
_fn_1c24_05ab	endp

_fn_1c24_05e3	proc	far
	enter	0h,0h		; 5e3
	push	bx		; 5e7
	push	cx		; 5e8
	push	dx		; 5e9
	push	di		; 5ea
	push	si		; 5eb
	mov	cx,[bp+6h]		; 5ec
	mov	si,[bp+0ah]		; 5ef
	mov	dx,[bp+8h]		; 5f2
	mov	di,[bp+0ch]		; 5f5
	inc	word ptr ds:[2f0ah]		; 5f8
	mov	ax,ds:[2f0ch]		; 5fc
	mov	bx,ds:[2f0eh]		; 5ff
	cmp	ax,cx		; 603
	jl	short L0618		; 605
	cmp	ax,si		; 607
	jg	short L0618		; 609
	cmp	bx,dx		; 60b
	jl	short L0618		; 60d
	cmp	bx,di		; 60f
	jg	short L0618		; 611
	mov	ax,1h		; 613
	jmp	short L061B		; 616
L0618:
	mov	ax,0h		; 618
L061B:
	dec	word ptr ds:[2f0ah]		; 61b
	pop	si		; 61f
	pop	di		; 620
	pop	dx		; 621
	pop	cx		; 622
	pop	bx		; 623
	leave		; 624
	retf		; 625
_fn_1c24_05e3	endp

_fn_1c24_0626	proc	far
	sti		; 626
	retf		; 627
_fn_1c24_0626	endp

_fn_1c24_0628	proc	far
	cli		; 628
	retf		; 629
_fn_1c24_0628	endp
S046_TEXT	ends
	end
