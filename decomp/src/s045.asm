; s045: segment 1bbe (TASM module)
	.386
S045_TEXT	segment word public use16 'CODE'
S045_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:S045_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
S045_TEXT	segment
	public	_fn_1bbe_000c, _fn_1bbe_027d, _fn_1bbe_0283, _fn_1bbe_04ba, _fn_1bbe_04c5, _fn_1bbe_04c9, _fn_1bbe_04ca, _fn_1bbe_05bc, _fn_1bbe_05e1
_fn_1bbe_000c	proc	far
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
	add	[bx+di],al		; 14c
	add	[bp+si],ax		; 14e
	add	ax,[bp+di]		; 150
	add	al,5h		; 152
	add	ax,106h		; 154
	add	[bx+si],cx		; 157
	or	[bx+di],cx		; 159
	or	cl,[bp+di]		; 15b
	or	cx,[si]		; 15d
	or	ax,0e0dh		; 15f
	db	0fh		; 162
	db	0fh, 10h, 11h	; 163: movups xmm2,oword [bx+di]
	adc	[bp+si],dx		; 166
	adc	dx,[bp+di]		; 168
	adc	al,15h		; 16a
	adc	ax,1716h		; 16c
	pop	ss		; 16f
	sbb	[bx+di],bl		; 170
	sbb	[bp+si],bx		; 172
	sbb	bx,[bp+di]		; 174
	sbb	al,1dh		; 176
	sbb	ax,1f1eh		; 178
	pop	ds		; 17b
	and	[bx+di],ah		; 17c
	and	[bp+si],sp		; 17e
	and	sp,[bp+di]		; 180
	and	al,25h		; 182
	and	ax,2726h		; 184
	daa		; 187
	sub	[bx+di],ch		; 188
	sub	[bp+si],bp		; 18a
	sub	bp,[bp+di]		; 18c
	sub	al,2dh		; 18e
	sub	ax,2f2eh		; 190
	das		; 193
	xor	[bx+di],dh		; 194
	xor	[bp+si],si		; 196
	xor	si,[bp+di]		; 198
	xor	al,35h		; 19a
	xor	ax,3736h		; 19c
	aaa		; 19f
	cmp	[bx+di],bh		; 1a0
	cmp	[bp+si],di		; 1a2
	cmp	di,[bp+di]		; 1a4
	cmp	al,3dh		; 1a6
	cmp	ax,3f3eh		; 1a8
	aas		; 1ab
	inc	ax		; 1ac
	inc	cx		; 1ad
	inc	cx		; 1ae
	inc	dx		; 1af
	inc	bx		; 1b0
	inc	bx		; 1b1
	inc	sp		; 1b2
	inc	bp		; 1b3
	inc	bp		; 1b4
	inc	si		; 1b5
	inc	di		; 1b6
	inc	di		; 1b7
	dec	ax		; 1b8
	dec	cx		; 1b9
	dec	cx		; 1ba
	dec	dx		; 1bb
	dec	bx		; 1bc
	dec	bx		; 1bd
	dec	sp		; 1be
	dec	bp		; 1bf
	dec	bp		; 1c0
	dec	si		; 1c1
	dec	di		; 1c2
	dec	di		; 1c3
	push	ax		; 1c4
	push	cx		; 1c5
	push	cx		; 1c6
	push	dx		; 1c7
	push	bx		; 1c8
	push	bx		; 1c9
	push	sp		; 1ca
	push	bp		; 1cb
	push	bp		; 1cc
	push	si		; 1cd
	push	di		; 1ce
	push	di		; 1cf
	pop	ax		; 1d0
	pop	cx		; 1d1
	pop	cx		; 1d2
	pop	dx		; 1d3
	pop	bx		; 1d4
	pop	bx		; 1d5
	pop	sp		; 1d6
	pop	bp		; 1d7
	pop	bp		; 1d8
	pop	si		; 1d9
	pop	di		; 1da
	pop	di		; 1db
	pusha		; 1dc
	popa		; 1dd
	popa		; 1de
	bound	sp,[bp+di+63h]		; 1df
	db	64h, 65h, 65h, 66h, 67h, 67h, 68h, 69h, 69h, 6ah, 6bh	; 1e2: gs push dword 0x6b6a6969
	imul	bp,[si+6dh],+6dh		; 1ed
	outsb		; 1f1
	outsw		; 1f2
	outsw		; 1f3
	db	70h, 71h	; 1f4: jo 0x267
	db	71h, 72h	; 1f6: jno 0x26a
	db	73h, 73h	; 1f8: jnc 0x26d
	db	74h, 75h	; 1fa: jz 0x271
	db	75h, 76h	; 1fc: jnz 0x274
	db	77h, 77h	; 1fe: ja 0x277
	db	78h, 79h	; 200: js 0x27b
	jns	short L027E		; 202
	jpo	short L0281		; 204
	db	7ch, 7dh	; 206: jl 0x285
	jnl	short L0288		; 208
	db	7fh, 7fh	; 20a: jg 0x28b
	add	byte ptr [bx+di-7d7fh],83h		; 20c
	add	word ptr [si-7a7bh],-7ah		; 211
	xchg	ax,[bx-7678h]		; 216
	mov	[bp+si-7475h],cx		; 21a
	mov	[di-7173h],cs		; 21e
	db	8fh		; 222
	db	8fh		; 223
	nop		; 224
	xchg	ax,cx		; 225
	xchg	ax,cx		; 226
	xchg	ax,dx		; 227
	xchg	ax,bx		; 228
	xchg	ax,bx		; 229
	xchg	ax,sp		; 22a
	xchg	ax,bp		; 22b
	xchg	ax,bp		; 22c
	xchg	ax,si		; 22d
	xchg	ax,di		; 22e
	xchg	ax,di		; 22f
	cbw		; 230
	cwd		; 231
	cwd		; 232
	db	9ah, 9bh, 9bh, 9ch, 9dh	; 233: call 0x9d9c:0x9b9b
	popf		; 238
	sahf		; 239
	lahf		; 23a
	lahf		; 23b
	mov	al,ds:[0a1a1h]		; 23c
	mov	ds:[0a3a3h],al		; 23f
	movsb		; 242
	movsw		; 243
	movsw		; 244
	cmpsb		; 245
	cmpsw		; 246
	cmpsw		; 247
	test	al,0a9h		; 248
	test	ax,0abaah		; 24a
	stosw		; 24d
	lodsb		; 24e
	lodsw		; 24f
	lodsw		; 250
	scasb		; 251
	scasw		; 252
	scasw		; 253
	mov	al,0b1h		; 254
	mov	cl,0b2h		; 256
	mov	bl,0b3h		; 258
	mov	ah,0b5h		; 25a
	mov	ch,0b6h		; 25c
	mov	bh,0b7h		; 25e
	mov	ax,0b9b9h		; 260
	mov	dx,0bbbbh		; 263
	mov	sp,0bdbdh		; 266
	mov	si,0bfbfh		; 269
	db	0c0h, 0c1h, 0c1h	; 26c: rol cl,byte 0xc1
	db	0c2h, 0c3h, 0c3h	; 26f: ret 0xc3c3
	db	0c4h		; 272
	db	0c5h, 0c5h, 0c6h, 0c7h, 0c7h	; 273: vshufpd ymm0,ymm7,ymm7,byte 0xc7
	enter	0c9c9h,0cah		; 278
	retf		; 27c
_fn_1bbe_000c	endp

_fn_1bbe_027d	proc	far
	retf		; 27d
L027E:
	db	0cch	; 27e: int3
	int	0cdh		; 27f
L0281:
	into		; 281
	iret		; 282
_fn_1bbe_027d	endp

_fn_1bbe_0283	proc	far
	iret		; 283
L0284:
	rcl	cl,1		; 284
	rcl	dx,1		; 286
L0288:
	rcl	bx,cl		; 288
	aam	0d5h		; 28a
	aad	0d6h		; 28c
	xlatb		; 28e
	xlatb		; 28f
	db	0d8h, 0d9h	; 290: fcomp st1
	db	0d9h		; 292
	db	0dah, 0dbh	; 293: fcmovu st3
	db	0dbh, 0dch	; 295: fcmovnu st4
	db	0ddh, 0ddh	; 297: fstp st5
L0299:
	db	0deh		; 299
	db	0dfh		; 29a
	fnstsw	ax		; 29b
	db	0e1h, 0e1h	; 29d: loope 0x280
	loop	short L0284		; 29f
	db	0e3h, 0e4h	; 2a1: jcxz 0x287
	in	ax,0e5h		; 2a3
	out	0e7h,al		; 2a5
	out	0e8h,ax		; 2a7
	db	0e9h, 0e9h, 0eah	; 2a9: jmp 0xed95
	jmp	short L0299		; 2ac
	in	al,dx		; 2ae
	in	ax,dx		; 2af
	in	ax,dx		; 2b0
	out	dx,al		; 2b1
	out	dx,ax		; 2b2
	out	dx,ax		; 2b3
	db	0f0h, 0f1h	; 2b4: lock int1
	db	0f1h	; 2b6: int1
	db	0f2h, 0f3h, 0f3h, 0f4h	; 2b7: rep hlt
	cmc		; 2bb
	cmc		; 2bc
	div	bh		; 2bd
	idiv	ax		; 2bf
	stc		; 2c1
	stc		; 2c2
	cli		; 2c3
	sti		; 2c4
	sti		; 2c5
	cld		; 2c6
	std		; 2c7
	std		; 2c8
	db	0feh		; 2c9
	db	0ffh		; 2ca
	db	0ffh		; 2cb
	db	0ffh		; 2cc
	db	0ffh		; 2cd
	db	0ffh		; 2ce
	db	0ffh		; 2cf
	db	0ffh		; 2d0
	db	0ffh		; 2d1
	db	0ffh		; 2d2
	db	0ffh		; 2d3
	db	0ffh		; 2d4
	db	0ffh		; 2d5
	db	0ffh		; 2d6
	db	0ffh		; 2d7
	db	0ffh		; 2d8
	db	0ffh		; 2d9
	db	0ffh		; 2da
	db	0ffh		; 2db
	db	0ffh		; 2dc
	db	0ffh		; 2dd
	db	0ffh		; 2de
	db	0ffh		; 2df
	db	0ffh		; 2e0
	db	0ffh		; 2e1
	db	0ffh		; 2e2
	db	0ffh		; 2e3
	db	0ffh		; 2e4
	db	0ffh		; 2e5
	db	0ffh		; 2e6
	db	0ffh		; 2e7
	db	0ffh		; 2e8
	db	0ffh		; 2e9
	db	0ffh		; 2ea
	db	0ffh		; 2eb
	db	0ffh		; 2ec
	db	0ffh		; 2ed
	db	0ffh		; 2ee
	db	0ffh		; 2ef
	db	0ffh		; 2f0
	db	0ffh		; 2f1
	db	0ffh		; 2f2
	db	0ffh		; 2f3
	db	0ffh		; 2f4
	db	0ffh		; 2f5
	db	0ffh		; 2f6
	db	0ffh		; 2f7
	db	0ffh		; 2f8
	db	0ffh		; 2f9
	db	0ffh		; 2fa
	db	0ffh		; 2fb
	db	0ffh		; 2fc
	db	0ffh		; 2fd
	db	0ffh		; 2fe
	db	0ffh		; 2ff
	db	0ffh		; 300
	db	0ffh		; 301
	db	0ffh		; 302
	db	0ffh		; 303
	db	0ffh		; 304
	db	0ffh		; 305
	db	0ffh		; 306
	db	0ffh		; 307
	db	0ffh		; 308
	db	0ffh		; 309
	db	0ffh		; 30a
	db	0ffh		; 30b
	db	0ffh		; 30c
	db	0ffh		; 30d
	db	0ffh		; 30e
	db	0ffh		; 30f
	db	0ffh		; 310
	db	0ffh		; 311
	db	0ffh		; 312
	db	0ffh		; 313
	db	0ffh		; 314
	db	0ffh		; 315
	db	0ffh		; 316
	db	0ffh		; 317
	db	0ffh		; 318
	db	0ffh		; 319
	db	0ffh		; 31a
	db	0ffh		; 31b
	db	0ffh		; 31c
	db	0ffh		; 31d
	db	0ffh		; 31e
	db	0ffh		; 31f
	db	0ffh		; 320
	db	0ffh		; 321
	db	0ffh		; 322
	db	0ffh		; 323
	db	0ffh		; 324
	db	0ffh		; 325
	db	0ffh		; 326
	db	0ffh		; 327
	db	0ffh		; 328
	db	0ffh		; 329
	db	0ffh		; 32a
	db	0ffh		; 32b
	db	0ffh		; 32c
	db	0ffh		; 32d
	db	0ffh		; 32e
	db	0ffh		; 32f
	db	0ffh		; 330
	db	0ffh		; 331
	db	0ffh		; 332
	db	0ffh		; 333
	db	0ffh		; 334
	db	0ffh		; 335
	db	0ffh		; 336
	db	0ffh		; 337
	db	0ffh		; 338
	db	0ffh		; 339
	db	0ffh		; 33a
	db	0ffh		; 33b
	db	0ffh		; 33c
	db	0ffh		; 33d
	db	0ffh		; 33e
	db	0ffh		; 33f
	db	0ffh		; 340
	db	0ffh		; 341
	db	0ffh		; 342
	db	0ffh		; 343
	db	0ffh		; 344
	db	0ffh		; 345
	db	0ffh		; 346
	db	0ffh		; 347
	db	0ffh		; 348
	db	0ffh		; 349
	db	0ffh		; 34a
	db	0ffh		; 34b
	db	0ffh		; 34c
	db	0ffh		; 34d
	db	0ffh		; 34e
	db	0ffh		; 34f
	db	0ffh		; 350
	db	0ffh		; 351
	db	0ffh		; 352
	db	0ffh		; 353
	db	0ffh		; 354
	db	0ffh		; 355
	db	0ffh		; 356
	db	0ffh		; 357
	db	0ffh		; 358
	db	0ffh		; 359
	db	0ffh		; 35a
	db	0ffh		; 35b
	db	0ffh		; 35c
	db	0ffh		; 35d
	db	0ffh		; 35e
	db	0ffh		; 35f
	db	0ffh		; 360
	db	0ffh		; 361
	db	0ffh		; 362
	db	0ffh		; 363
	db	0ffh		; 364
	db	0ffh		; 365
	db	0ffh		; 366
	db	0ffh		; 367
	db	0ffh		; 368
	db	0ffh		; 369
	db	0ffh		; 36a
	db	0ffh		; 36b
	db	0ffh		; 36c
	db	0ffh		; 36d
	db	0ffh		; 36e
	db	0ffh		; 36f
	db	0ffh		; 370
	db	0ffh		; 371
	db	0ffh		; 372
	db	0ffh		; 373
	db	0ffh		; 374
	db	0ffh		; 375
	db	0ffh		; 376
	db	0ffh		; 377
	db	0ffh		; 378
	db	0ffh		; 379
	db	0ffh		; 37a
	db	0ffh		; 37b
	db	0ffh		; 37c
	db	0ffh		; 37d
	db	0ffh		; 37e
	db	0ffh		; 37f
	db	0ffh		; 380
	db	0ffh		; 381
	db	0ffh		; 382
	db	0ffh		; 383
	db	0ffh		; 384
	db	0ffh		; 385
	db	0ffh		; 386
	db	0ffh		; 387
	db	0ffh		; 388
	db	0ffh		; 389
	db	0ffh		; 38a
	db	0ffh		; 38b
	db	0ffh		; 38c
	db	0ffh		; 38d
	db	0ffh		; 38e
	db	0ffh		; 38f
	db	0ffh		; 390
	db	0ffh		; 391
	db	0ffh		; 392
	db	0ffh		; 393
	db	0ffh		; 394
	db	0ffh		; 395
	db	0ffh		; 396
	db	0ffh		; 397
	db	0ffh		; 398
	db	0ffh		; 399
	db	0ffh		; 39a
	db	0ffh		; 39b
	db	0ffh		; 39c
	db	0ffh		; 39d
	db	0ffh		; 39e
	db	0ffh		; 39f
	db	0ffh		; 3a0
	db	0ffh		; 3a1
	db	0ffh		; 3a2
	db	0ffh		; 3a3
	db	0ffh		; 3a4
	db	0ffh		; 3a5
	db	0ffh		; 3a6
	db	0ffh		; 3a7
	db	0ffh		; 3a8
	db	0ffh		; 3a9
	db	0ffh		; 3aa
	db	0ffh		; 3ab
	db	0ffh		; 3ac
	db	0ffh		; 3ad
	db	0ffh		; 3ae
	db	0ffh		; 3af
	db	0ffh		; 3b0
	db	0ffh		; 3b1
	db	0ffh		; 3b2
	db	0ffh		; 3b3
	db	0ffh		; 3b4
	db	0ffh		; 3b5
	db	0ffh		; 3b6
	db	0ffh		; 3b7
	db	0ffh		; 3b8
	db	0ffh		; 3b9
	db	0ffh		; 3ba
	db	0ffh		; 3bb
	db	0ffh		; 3bc
	db	0ffh		; 3bd
	db	0ffh		; 3be
	db	0ffh		; 3bf
	db	0ffh		; 3c0
	db	0ffh		; 3c1
	db	0ffh		; 3c2
	db	0ffh		; 3c3
	db	0ffh		; 3c4
	db	0ffh		; 3c5
	db	0ffh		; 3c6
	db	0ffh		; 3c7
	db	0ffh		; 3c8
	db	0ffh		; 3c9
	db	0ffh		; 3ca
	db	0ffh		; 3cb
	db	0ffh		; 3cc
	db	0ffh		; 3cd
	db	0ffh		; 3ce
	db	0ffh		; 3cf
	db	0ffh		; 3d0
	db	0ffh		; 3d1
	db	0ffh		; 3d2
	db	0ffh		; 3d3
	db	0ffh		; 3d4
	db	0ffh		; 3d5
	db	0ffh		; 3d6
	db	0ffh		; 3d7
	db	0ffh		; 3d8
	db	0ffh		; 3d9
	db	0ffh		; 3da
	db	0ffh		; 3db
	db	0ffh		; 3dc
	db	0ffh		; 3dd
	db	0ffh		; 3de
	db	0ffh		; 3df
	db	0ffh		; 3e0
	db	0ffh		; 3e1
	db	0ffh		; 3e2
	db	0ffh		; 3e3
	db	0ffh		; 3e4
	db	0ffh		; 3e5
	db	0ffh		; 3e6
	db	0ffh		; 3e7
	db	0ffh		; 3e8
	db	0ffh		; 3e9
	db	0ffh		; 3ea
	db	0ffh		; 3eb
	db	0ffh		; 3ec
	db	0ffh		; 3ed
	db	0ffh		; 3ee
	db	0ffh		; 3ef
	db	0ffh		; 3f0
	db	0ffh		; 3f1
	db	0ffh		; 3f2
	db	0ffh		; 3f3
	db	0ffh		; 3f4
	db	0ffh		; 3f5
	db	0ffh		; 3f6
	db	0ffh		; 3f7
	db	0ffh		; 3f8
	db	0ffh		; 3f9
	db	0ffh		; 3fa
	db	0ffh		; 3fb
	db	0ffh		; 3fc
	db	0ffh		; 3fd
	db	0ffh		; 3fe
	db	0ffh		; 3ff
	db	0ffh		; 400
	db	0ffh		; 401
	db	0ffh		; 402
	db	0ffh		; 403
	db	0ffh		; 404
	db	0ffh		; 405
	db	0ffh		; 406
	db	0ffh		; 407
	db	0ffh		; 408
	db	0ffh		; 409
	db	0ffh		; 40a
	inc	word ptr [bx+si]		; 40b
	add	[bx+di],al		; 40d
	add	[bp+di],ax		; 40f
	add	ax,[si]		; 411
	add	al,6h		; 413
	push	es		; 415
	pop	es		; 416
	pop	es		; 417
	or	[bx+di],cx		; 418
	or	cl,[bp+si]		; 41a
	or	al,0ch		; 41c
	or	ax,0f0dh		; 41e
	db	0fh, 10h, 10h	; 421: movups xmm2,oword [bx+si]
	adc	dl,[bp+si]		; 424
	adc	dx,[bp+di]		; 426
	adc	ax,1615h		; 428
	push	ss		; 42b
	sbb	[bx+si],bl		; 42c
	sbb	[bx+di],bx		; 42e
	sbb	bx,[bp+di]		; 430
	sbb	al,1ch		; 432
	push	ds		; 434
	push	ds		; 435
	pop	ds		; 436
	pop	ds		; 437
	and	[bx+di],sp		; 438
	and	ah,[bp+si]		; 43a
	and	al,24h		; 43c
	and	ax,2725h		; 43e
	daa		; 441
	sub	[bx+si],ch		; 442
	sub	ch,[bp+si]		; 444
	sub	bp,[bp+di]		; 446
	sub	ax,2e2dh		; 448
	xor	cs:[bx+si],dh		; 44b
	xor	[bx+di],si		; 44e
	xor	si,[bp+di]		; 450
	xor	al,34h		; 452
	db	36h, 36h, 37h	; 454: ss aaa
	aaa		; 457
	cmp	[bx+di],di		; 458
	cmp	bh,[bp+si]		; 45a
	cmp	al,3ch		; 45c
	cmp	ax,3f3dh		; 45e
	aas		; 461
	inc	ax		; 462
	inc	ax		; 463
	inc	dx		; 464
	inc	dx		; 465
	inc	bx		; 466
	inc	bx		; 467
	inc	bp		; 468
	inc	bp		; 469
	inc	si		; 46a
	inc	si		; 46b
	dec	ax		; 46c
	dec	ax		; 46d
	dec	cx		; 46e
	dec	cx		; 46f
	dec	bx		; 470
	dec	bx		; 471
	dec	sp		; 472
	dec	sp		; 473
	dec	si		; 474
	dec	si		; 475
	dec	di		; 476
	dec	di		; 477
	push	cx		; 478
	push	cx		; 479
	push	dx		; 47a
	push	dx		; 47b
	push	sp		; 47c
	push	sp		; 47d
	push	bp		; 47e
	push	bp		; 47f
	push	di		; 480
	push	di		; 481
	pop	ax		; 482
	pop	ax		; 483
	pop	dx		; 484
	pop	dx		; 485
	pop	bx		; 486
	pop	bx		; 487
	pop	bp		; 488
	pop	bp		; 489
	pop	si		; 48a
	pop	si		; 48b
	mov	ds:[0a3a2h],al		; 48c
	mov	ds:[0a5a5h],ax		; 48f
	cmpsb		; 492
	cmpsb		; 493
	test	al,0a8h		; 494
	test	ax,0aba9h		; 496
	stosw		; 499
	lodsb		; 49a
	lodsb		; 49b
	scasb		; 49c
	scasb		; 49d
	scasw		; 49e
	scasw		; 49f
	mov	cl,0b1h		; 4a0
	mov	dl,0b2h		; 4a2
	mov	ah,0b4h		; 4a4
	mov	ch,0b5h		; 4a6
	mov	bh,0b7h		; 4a8
	mov	ax,0bab8h		; 4aa
	mov	dx,0bbbbh		; 4ad
	mov	bp,0bebdh		; 4b0
	mov	si,0c0c0h		; 4b3
	db	0c1h, 0c1h, 0c3h	; 4b6: rol cx,byte 0xc3
	db	0c3h	; 4b9: ret
_fn_1bbe_0283	endp

_fn_1bbe_04ba	proc	far
	db	0c4h		; 4ba
	db	0c4h		; 4bb
	db	0c6h, 0c6h, 0c7h	; 4bc: mov dh,0xc7
	db	0c7h		; 4bf
	leave		; 4c0
	leave		; 4c1
	retf	0cccah		; 4c2
_fn_1bbe_04ba	endp

_fn_1bbe_04c5	proc	far
	db	0cch	; 4c5: int3
L04C6:
	int	0cdh		; 4c6
	iret		; 4c8
_fn_1bbe_04c5	endp

_fn_1bbe_04c9	proc	far
	iret		; 4c9
_fn_1bbe_04c9	endp

_fn_1bbe_04ca	proc	far
	rcl	al,1		; 4ca
	rcl	dl,cl		; 4cc
	rcl	bx,cl		; 4ce
	aad	0d5h		; 4d0
	db	0d6h	; 4d2: salc
	db	0d6h	; 4d3: salc
	db	0d8h, 0d8h	; 4d4: fcomp st0
	db	0d9h		; 4d6
	db	0d9h		; 4d7
	db	0dbh, 0dbh	; 4d8: fcmovnu st3
	db	0dch		; 4da
	db	0dch		; 4db
	db	0deh		; 4dc
	db	0deh		; 4dd
	db	0dfh		; 4de
	db	0dfh		; 4df
	db	0e1h, 0e1h	; 4e0: loope 0x4c3
	loop	short L04C6		; 4e2
	in	al,0e4h		; 4e4
	in	ax,0e5h		; 4e6
	out	0e7h,ax		; 4e8
	db	0e8h, 0e8h, 0eah	; 4ea: call 0xefd5
	db	0eah, 0ebh, 0ebh, 0edh, 0edh	; 4ed: jmp 0xeded:0xebeb
	out	dx,al		; 4f2
	out	dx,al		; 4f3
	db	0f0h, 0f0h, 0f1h	; 4f4: lock int1
	db	0f1h	; 4f7: int1
	db	0f3h, 0f3h, 0f4h	; 4f8: rep hlt
	hlt		; 4fb
	div	dh		; 4fc
	div	di		; 4fe
	stc		; 500
	stc		; 501
	cli		; 502
	cli		; 503
	cld		; 504
	cld		; 505
	std		; 506
	std		; 507
	db	0ffh		; 508
	inc	word ptr [bx+si]		; 509
	db	0h, 0c8h	; 50b: add al,cl
	add	[bx+si],al		; 50d
	add	[bp+di+51h],dl		; 50f
	push	dx		; 512
	push	es		; 513
	push	di		; 514
	mov	cx,[bp+0ah]		; 515
	mov	dx,[bp+0ch]		; 518
	les	di,[bp+6h]		; 51b
	cmp	dx,+64h		; 51e
	jz	near ptr L05B5		; 521
	cmp	dx,+4bh		; 525
	jz	short L05A3		; 528
	cmp	dx,+32h		; 52a
	jz	short L0586		; 52d
	cmp	dx,+19h		; 52f
	jz	short L0565		; 532
	cmp	dx,+0ch		; 534
	jz	short L0540		; 537
	mov	al,80h		; 539
L053B:
	stosb		; 53b
	loop	short L053B		; 53c
	jmp	short L05B5		; 53e
L0540:
	mov	al,es:[di]		; 540
	xor	al,80h		; 543
	jns	short L0558		; 545
	neg	al		; 547
	sar	al,1		; 549
	sar	al,1		; 54b
	sar	al,1		; 54d
	neg	al		; 54f
	xor	al,80h		; 551
	stosb		; 553
	loop	short L0540		; 554
	jmp	short L05B5		; 556
L0558:
	sar	al,1		; 558
	sar	al,1		; 55a
	sar	al,1		; 55c
	xor	al,80h		; 55e
	stosb		; 560
	loop	short L0540		; 561
	jmp	short L05B5		; 563
L0565:
	mov	al,es:[di]		; 565
	xor	al,80h		; 568
	jns	short L057B		; 56a
	neg	al		; 56c
	sar	al,1		; 56e
	sar	al,1		; 570
	neg	al		; 572
	xor	al,80h		; 574
	stosb		; 576
	loop	short L0565		; 577
	jmp	short L05B5		; 579
L057B:
	sar	al,1		; 57b
	sar	al,1		; 57d
	xor	al,80h		; 57f
	stosb		; 581
	loop	short L0565		; 582
	jmp	short L05B5		; 584
L0586:
	mov	al,es:[di]		; 586
	xor	al,80h		; 589
	jns	short L059A		; 58b
	neg	al		; 58d
	sar	al,1		; 58f
	neg	al		; 591
	xor	al,80h		; 593
	stosb		; 595
	loop	short L0586		; 596
	jmp	short L05B5		; 598
L059A:
	sar	al,1		; 59a
	xor	al,80h		; 59c
	stosb		; 59e
	loop	short L0586		; 59f
	jmp	short L05B5		; 5a1
L05A3:
	mov	bx,40ch		; 5a3
	push	ds		; 5a6
	push	cs		; 5a7
	pop	ds		; 5a8
L05A9:
	mov	al,es:[di]		; 5a9
	xor	al,80h		; 5ac
	xlatb		; 5ae
	xor	al,80h		; 5af
	stosb		; 5b1
	loop	short L05A9		; 5b2
	pop	ds		; 5b4
L05B5:
	pop	di		; 5b5
	pop	es		; 5b6
	pop	dx		; 5b7
	pop	cx		; 5b8
	pop	bx		; 5b9
	leave		; 5ba
	retf		; 5bb
_fn_1bbe_04ca	endp

_fn_1bbe_05bc	proc	far
	enter	0h,0h		; 5bc
	push	bx		; 5c0
	push	cx		; 5c1
	push	dx		; 5c2
	push	es		; 5c3
	push	di		; 5c4
	cmp	word ptr ds:[3749h],+4h		; 5c5
	jnz	short L05DA		; 5ca
	mov	cx,[bp+0ah]		; 5cc
	les	di,[bp+6h]		; 5cf
L05D2:
	mov	al,es:[di]		; 5d2
	sub	al,80h		; 5d5
	stosb		; 5d7
	loop	short L05D2		; 5d8
L05DA:
	pop	di		; 5da
	pop	es		; 5db
	pop	dx		; 5dc
	pop	cx		; 5dd
	pop	bx		; 5de
	leave		; 5df
	retf		; 5e0
_fn_1bbe_05bc	endp

_fn_1bbe_05e1	proc	far
	enter	2h,0h		; 5e1
	push	bx		; 5e5
	push	cx		; 5e6
	push	dx		; 5e7
	push	di		; 5e8
	push	ds		; 5e9
	push	es		; 5ea
	push	si		; 5eb
	mov	dx,[bp+0eh]		; 5ec
	mov	cx,dx		; 5ef
	mov	ax,dx		; 5f1
	shl	ax,1		; 5f3
	add	ax,dx		; 5f5
	dec	ax		; 5f7
	mov	[bp-2h],ax		; 5f8
	xor	ah,ah		; 5fb
	cmp	word ptr ds:[3749h],+4h		; 5fd
	db	74h, 29h	; 602: jz 0x62d
	lds	si,[bp+6h]		; 604
	les	di,[bp+0ah]		; 607
L060A:
	xor	bh,bh		; 60a
	mov	bl,[si]		; 60c
	add	si,dx		; 60e
	mov	al,[si]		; 610
	add	bx,ax		; 612
	add	si,dx		; 614
	mov	al,[si]		; 616
	add	bx,ax		; 618
	add	si,dx		; 61a
	mov	al,[si]		; 61c
	add	bx,ax		; 61e
	db	2eh, 8ah, 87h, 0ch, 0h	; 620: mov al,[cs:bx+0xc]
	stosb		; 625
	sub	si,[bp-2h]		; 626
	loop	short L060A		; 629
	db	0ebh, 29h	; 62b: jmp short 0x656
L062D:
	lds	si,[bp+6h]		; 62d
	les	di,[bp+0ah]		; 630
L0633:
	xor	bh,bh		; 633
	mov	bl,[si]		; 635
	add	si,dx		; 637
	mov	al,[si]		; 639
	add	bx,ax		; 63b
	add	si,dx		; 63d
	mov	al,[si]		; 63f
	add	bx,ax		; 641
	add	si,dx		; 643
	mov	al,[si]		; 645
	add	bx,ax		; 647
	mov	al,cs:[bx+0ch]		; 649
	sub	al,80h		; 64e
	stosb		; 650
	sub	si,[bp-2h]		; 651
	loop	short L0633		; 654
L0656:
	pop	si		; 656
	pop	es		; 657
	pop	ds		; 658
	pop	di		; 659
	pop	dx		; 65a
	pop	cx		; 65b
	pop	bx		; 65c
	leave		; 65d
	retf		; 65e
_fn_1bbe_05e1	endp
S045_TEXT	ends
	end
