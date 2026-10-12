; s040: segment 1aff (TASM module)
	.386
S040_TEXT	segment word public use16 'CODE'
S040_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:S040_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	extrn	_fn_215f_001d:far
S040_TEXT	segment
	public	_fn_1aff_0002, _fn_1aff_001c, _fn_1aff_00b9, _fn_1aff_02d2, _fn_1aff_030e, _fn_1aff_0341, _fn_1aff_0386, _fn_1aff_039a, _fn_1aff_03b4, _fn_1aff_03fd, _fn_1aff_0420, _fn_1aff_0434
_fn_1aff_0002	proc	far
	enter	0h,0h		; 2
	push	dx		; 6
	push	bx		; 7
	mov	ax,[bp+6h]		; 8
	xor	bx,bx		; b
	imul	word ptr [bp+8h]		; d
	mov	bl,al		; 10
	mov	al,ah		; 12
	mov	ah,dl		; 14
	jmp	short L0018		; 16
L0018:
	pop	bx		; 18
	pop	dx		; 19
	leave		; 1a
	retf		; 1b
_fn_1aff_0002	endp

_fn_1aff_001c	proc	far
	enter	0h,0h		; 1c
	push	cx		; 20
	push	di		; 21
	push	si		; 22
	push	ds		; 23
	push	es		; 24
	push	cs		; 25
	pop	es		; 26
	lds	si,[bp+6h]		; 27
	mov	di,39h		; 2a
	mov	cx,40h		; 2d
	rep	movsw		; 30
	pop	es		; 32
	pop	ds		; 33
	pop	si		; 34
	pop	di		; 35
	pop	cx		; 36
	leave		; 37
	retf		; 38
L0039	label	byte
	db	0h, 1h, 2h, 3h, 4h, 5h, 6h, 7h, 8h, 9h, 0ah, 0bh, 0ch, 0dh, 0eh, 0fh, 0h, 1h, 2h, 3h, 4h, 5h, 6h, 7h, 8h, 9h, 0ah, 0bh, 0ch, 0dh, 0eh, 0fh, 0h, 1h, 2h, 3h, 4h, 5h, 6h, 7h, 8h, 9h, 0ah, 0bh, 0ch, 0dh, 0eh, 0fh, 0h, 1h, 2h, 3h, 4h, 5h, 6h, 7h, 8h, 9h, 0ah, 0bh, 0ch, 0dh, 0eh, 0fh, 0h, 1h, 2h, 3h, 4h, 5h, 6h, 7h, 8h, 9h, 0ah, 0bh, 0ch, 0dh, 0eh, 0fh, 0h, 1h, 2h, 3h, 4h, 5h, 6h, 7h, 8h, 9h, 0ah, 0bh, 0ch, 0dh, 0eh, 0fh, 0h, 1h, 2h, 3h, 4h, 5h, 6h, 7h, 8h, 9h, 0ah, 0bh, 0ch, 0dh, 0eh, 0fh, 0h, 1h, 2h, 3h, 4h, 5h, 6h, 7h, 8h, 9h, 0ah, 0bh, 0ch, 0dh, 0eh, 0fh	; 39
_fn_1aff_001c	endp

_fn_1aff_00b9	proc	far
	enter	0ah,0h		; b9
	push	bx		; bd
	push	cx		; be
	push	dx		; bf
	push	di		; c0
	push	si		; c1
	push	ds		; c2
	push	es		; c3
	push	word ptr [bp+12h]		; c4
	call	far ptr _fn_215f_001d		; c7
	add	sp,+2h		; cc
	mov	es,dx		; cf
	mov	di,ax		; d1
	add	di,+70h		; d3
	lds	bx,[bp+0ah]		; d6
	mov	word ptr [bp-2h],0fh		; d9
L00DE:
	mov	word ptr [bp-4h],16h		; de
L00E3:
	mov	word ptr [bp-8h],0h		; e3
	mov	word ptr [bp-0ah],0h		; e8
	mov	ds,[bp+0ch]		; ed
	mov	ax,[bx]		; f0
	test	ah,80h		; f2
	jz	short L0100		; f5
	sub	ah,80h		; f7
	mov	[bp-0ah],ax		; fa
	mov	ax,0h		; fd
L0100:
	test	ah,40h		; 100
	jz	short L010D		; 103
	mov	word ptr [bp-8h],1h		; 105
	and	ah,3fh		; 10a
L010D:
	or	ax,ax		; 10d
	jnz	short L0122		; 10f
	mov	ax,[bx+294h]		; 111
	test	ah,40h		; 115
	jz	short L0122		; 118
	mov	word ptr [bp-8h],1h		; 11a
	and	ah,3fh		; 11f
L0122:
	push	bx		; 122
	push	ax		; 123
	lds	bx,[bp+0eh]		; 124
	add	bx,ax		; 127
	mov	al,[bx]		; 129
	mov	[bp-6h],al		; 12b
	pop	ax		; 12e
	pop	bx		; 12f
	add	bx,+2h		; 130
	shl	ax,1		; 133
	add	ax,[bp+8h]		; 135
	mov	ds,ax		; 138
	mov	si,[bp+6h]		; 13a
	cmp	word ptr [bp-8h],+1h		; 13d
	jz	short L0180		; 141
	push	bx		; 143
	xor	bx,bx		; 144
	mov	dx,8h		; 146
L0149:
	mov	cx,4h		; 149
L014C:
	lodsb		; 14c
	mov	bl,al		; 14d
	and	bl,0fh		; 14f
	or	bl,[bp-6h]		; 152
	mov	ah,cs:L0039[bx]		; 155
	mov	bl,al		; 15a
	and	bl,0f0h		; 15c
	shr	bl,1		; 15f
	shr	bl,1		; 161
	shr	bl,1		; 163
	shr	bl,1		; 165
	or	bl,[bp-6h]		; 167
	mov	al,cs:L0039[bx]		; 16a
	stosw		; 16f
	loop	short L014C		; 170
	add	di,138h		; 172
	dec	dx		; 176
	jnz	short L0149		; 177
	sub	di,9f8h		; 179
	pop	bx		; 17d
	jmp	short L01C3		; 17e
L0180:
	push	bx		; 180
	xor	bx,bx		; 181
	mov	dx,8h		; 183
L0186:
	mov	cx,4h		; 186
	add	si,+3h		; 189
L018C:
	mov	al,[si]		; 18c
	dec	si		; 18e
	mov	bl,al		; 18f
	and	bl,0f0h		; 191
	shr	bl,1		; 194
	shr	bl,1		; 196
	shr	bl,1		; 198
	shr	bl,1		; 19a
	or	bl,[bp-6h]		; 19c
	mov	ah,cs:L0039[bx]		; 19f
	mov	bl,al		; 1a4
	and	bl,0fh		; 1a6
	or	bl,[bp-6h]		; 1a9
	mov	al,cs:L0039[bx]		; 1ac
	stosw		; 1b1
	loop	short L018C		; 1b2
	add	si,+5h		; 1b4
	add	di,138h		; 1b7
	dec	dx		; 1bb
	jnz	short L0186		; 1bc
	sub	di,9f8h		; 1be
	pop	bx		; 1c2
L01C3:
	cmp	word ptr [bp-0ah],+0h		; 1c3
	jnz	short L01E3		; 1c7
	dec	word ptr [bp-4h]		; 1c9
	jz	short L01D1		; 1cc
	jmp	near ptr L00E3		; 1ce
L01D1:
	add	di,950h		; 1d1
	mov	ds,[bp+0ch]		; 1d5
	dec	word ptr [bp-2h]		; 1d8
	jz	short L01E0		; 1db
	jmp	near ptr L00DE		; 1dd
L01E0:
	jmp	near ptr L02C9		; 1e0
L01E3:
	sub	di,+8h		; 1e3
	mov	word ptr [bp-8h],0h		; 1e6
	mov	ax,[bp-0ah]		; 1eb
	test	ah,40h		; 1ee
	jz	short L01FB		; 1f1
	and	ah,3fh		; 1f3
	mov	word ptr [bp-8h],1h		; 1f6
L01FB:
	push	bx		; 1fb
	push	ax		; 1fc
	lds	bx,[bp+0eh]		; 1fd
	add	bx,ax		; 200
	mov	al,[bx]		; 202
	mov	[bp-6h],al		; 204
	pop	ax		; 207
	pop	bx		; 208
	shl	ax,1		; 209
	add	ax,[bp+8h]		; 20b
	mov	ds,ax		; 20e
	mov	si,[bp+6h]		; 210
	cmp	word ptr [bp-8h],+1h		; 213
	jz	short L026D		; 217
	push	bx		; 219
	xor	bx,bx		; 21a
	mov	dx,8h		; 21c
L021F:
	mov	cx,4h		; 21f
L0222:
	lodsb		; 222
	mov	bl,al		; 223
	and	bl,0f0h		; 225
	shr	bl,1		; 228
	shr	bl,1		; 22a
	shr	bl,1		; 22c
	shr	bl,1		; 22e
	or	bl,[bp-6h]		; 230
	mov	ah,cs:L0039[bx]		; 233
	mov	bl,al		; 238
	and	bl,0fh		; 23a
	or	bl,[bp-6h]		; 23d
	mov	al,cs:L0039[bx]		; 240
	or	ah,ah		; 245
	jz	short L024C		; 247
	mov	es:[di],ah		; 249
L024C:
	inc	di		; 24c
	or	al,al		; 24d
	jz	short L0254		; 24f
	mov	es:[di],al		; 251
L0254:
	inc	di		; 254
	xor	bx,bx		; 255
	loop	short L0222		; 257
	add	di,138h		; 259
	dec	dx		; 25d
	jnz	short L021F		; 25e
	sub	di,9f8h		; 260
	pop	bx		; 264
	mov	word ptr [bp-0ah],0h		; 265
	jmp	near ptr L01C3		; 26a
L026D:
	push	bx		; 26d
	xor	bx,bx		; 26e
	mov	dx,8h		; 270
L0273:
	mov	cx,4h		; 273
	add	si,+3h		; 276
L0279:
	mov	al,[si]		; 279
	dec	si		; 27b
	mov	bl,al		; 27c
	and	bl,0fh		; 27e
	or	bl,[bp-6h]		; 281
	mov	ah,cs:L0039[bx]		; 284
	mov	bl,al		; 289
	and	bl,0f0h		; 28b
	shr	bl,1		; 28e
	shr	bl,1		; 290
	shr	bl,1		; 292
	shr	bl,1		; 294
	or	bl,[bp-6h]		; 296
	mov	al,cs:L0039[bx]		; 299
	or	ah,ah		; 29e
	jz	short L02A5		; 2a0
	mov	es:[di],ah		; 2a2
L02A5:
	inc	di		; 2a5
	cmp	al,0h		; 2a6
	jz	short L02AD		; 2a8
	mov	es:[di],al		; 2aa
L02AD:
	inc	di		; 2ad
	xor	bx,bx		; 2ae
	loop	short L0279		; 2b0
	add	si,+5h		; 2b2
	add	di,138h		; 2b5
	dec	dx		; 2b9
	jnz	short L0273		; 2ba
	sub	di,9f8h		; 2bc
	pop	bx		; 2c0
	mov	word ptr [bp-0ah],0h		; 2c1
	jmp	near ptr L01C3		; 2c6
L02C9:
	pop	es		; 2c9
	pop	ds		; 2ca
	pop	si		; 2cb
	pop	di		; 2cc
	pop	dx		; 2cd
	pop	cx		; 2ce
	pop	bx		; 2cf
	leave		; 2d0
	retf		; 2d1
_fn_1aff_00b9	endp

_fn_1aff_02d2	proc	far
	push	bp		; 2d2
	mov	bp,sp		; 2d3
	push	bx		; 2d5
	push	cx		; 2d6
	push	dx		; 2d7
	mov	ax,[bp+6h]		; 2d8
	mov	bx,[bp+8h]		; 2db
	mov	cl,3h		; 2de
	mov	dl,al		; 2e0
	and	dl,1fh		; 2e2
	shl	ax,cl		; 2e5
	mov	dh,ah		; 2e7
	mov	al,bl		; 2e9
	and	al,1fh		; 2eb
	shl	bx,cl		; 2ed
	mov	ah,bh		; 2ef
	sub	ah,dh		; 2f1
	jns	short L02F7		; 2f3
	neg	ah		; 2f5
L02F7:
	sub	al,dl		; 2f7
	jns	short L02FD		; 2f9
	neg	al		; 2fb
L02FD:
	cmp	al,ah		; 2fd
	jl	short L0303		; 2ff
	xchg	al,ah		; 301
L0303:
	shr	al,1		; 303
	add	al,ah		; 305
	xor	ah,ah		; 307
	pop	dx		; 309
	pop	cx		; 30a
	pop	bx		; 30b
	pop	bp		; 30c
	retf		; 30d
_fn_1aff_02d2	endp

_fn_1aff_030e	proc	far
	enter	0h,0h		; 30e
	push	ax		; 312
	push	bx		; 313
	push	cx		; 314
	push	es		; 315
	push	di		; 316
	mov	ax,[bp+0eh]		; 317
	mov	bx,ax		; 31a
	and	bx,+1fh		; 31c
	xchg	bh,bl		; 31f
	or	bx,[bp+10h]		; 321
	mov	cl,3h		; 324
	and	ax,0ffe0h		; 326
	shl	ax,cl		; 329
	or	ax,[bp+12h]		; 32b
	les	di,[bp+6h]		; 32e
	mov	es:[di],bx		; 331
	les	di,[bp+0ah]		; 334
	mov	es:[di],ax		; 337
	pop	di		; 33a
	pop	es		; 33b
	pop	cx		; 33c
	pop	bx		; 33d
	pop	ax		; 33e
	leave		; 33f
	retf		; 340
_fn_1aff_030e	endp

_fn_1aff_0341	proc	far
	enter	0h,0h		; 341
	push	ax		; 345
	push	bx		; 346
	push	dx		; 347
	push	ds		; 348
	push	si		; 349
	push	es		; 34a
	push	di		; 34b
	lds	si,[bp+0ah]		; 34c
	les	di,[bp+0eh]		; 34f
	mov	dx,[bp+12h]		; 352
	mov	ax,[si]		; 355
	mov	bx,[bp+8h]		; 357
	sub	ax,[bp+6h]		; 35a
	sub	bx,es:[di]		; 35d
	or	dx,dx		; 360
	jz	short L0378		; 362
	cmp	dx,+2h		; 364
	jz	short L036A		; 367
	xchg	ax,bx		; 369
L036A:
	cmp	dx,+3h		; 36a
	jz	short L0376		; 36d
	neg	ax		; 36f
	cmp	dx,+1h		; 371
	jz	short L0378		; 374
L0376:
	neg	bx		; 376
L0378:
	mov	[si],ax		; 378
	mov	es:[di],bx		; 37a
	pop	di		; 37d
	pop	es		; 37e
	pop	si		; 37f
	pop	ds		; 380
	pop	dx		; 381
	pop	bx		; 382
	pop	ax		; 383
	leave		; 384
	retf		; 385
_fn_1aff_0341	endp

_fn_1aff_0386	proc	far
	enter	0h,0h		; 386
	push	dx		; 38a
	mov	dx,[bp+6h]		; 38b
	mov	ax,[bp+8h]		; 38e
	imul	dx		; 391
	mov	al,ah		; 393
	mov	ah,dl		; 395
	pop	dx		; 397
	leave		; 398
	retf		; 399
_fn_1aff_0386	endp

_fn_1aff_039a	proc	far
	enter	0h,0h		; 39a
	push	bx		; 39e
	push	cx		; 39f
	xor	ax,ax		; 3a0
	mov	bx,[bp+8h]		; 3a2
	mov	ah,bh		; 3a5
	mov	cl,3h		; 3a7
	shr	ax,cl		; 3a9
	mov	bx,[bp+6h]		; 3ab
	or	al,bh		; 3ae
	pop	cx		; 3b0
	pop	bx		; 3b1
	leave		; 3b2
	retf		; 3b3
_fn_1aff_039a	endp

_fn_1aff_03b4	proc	far
	enter	0h,0h		; 3b4
	push	ax		; 3b8
	push	bx		; 3b9
	push	cx		; 3ba
	push	dx		; 3bb
	push	ds		; 3bc
	push	si		; 3bd
	push	es		; 3be
	push	di		; 3bf
	mov	dx,[bp+0eh]		; 3c0
	or	dx,dx		; 3c3
	jz	short L03F3		; 3c5
	lds	si,[bp+6h]		; 3c7
	les	di,[bp+0ah]		; 3ca
	mov	ax,[si]		; 3cd
	mov	bx,es:[di]		; 3cf
	test	dx,1h		; 3d2
	jz	short L03D9		; 3d6
	xchg	ax,bx		; 3d8
L03D9:
	cmp	dx,+1h		; 3d9
	jz	short L03E4		; 3dc
	sub	bx,100h		; 3de
	neg	bx		; 3e2
L03E4:
	cmp	dx,+3h		; 3e4
	jz	short L03EE		; 3e7
	sub	ax,100h		; 3e9
	neg	ax		; 3ec
L03EE:
	mov	[si],ax		; 3ee
	mov	es:[di],bx		; 3f0
L03F3:
	pop	di		; 3f3
	pop	es		; 3f4
	pop	si		; 3f5
	pop	ds		; 3f6
	pop	dx		; 3f7
	pop	cx		; 3f8
	pop	bx		; 3f9
	pop	ax		; 3fa
	leave		; 3fb
	retf		; 3fc
_fn_1aff_03b4	endp

_fn_1aff_03fd	proc	far
	enter	0h,0h		; 3fd
	push	dx		; 401
	mov	ax,[bp+6h]		; 402
	mov	dx,[bp+8h]		; 405
	or	dx,dx		; 408
	jns	short L040E		; 40a
	neg	dx		; 40c
L040E:
	mul	dx		; 40e
	mov	al,ah		; 410
	mov	ah,dl		; 412
	mov	dx,[bp+8h]		; 414
	or	dx,dx		; 417
	jns	short L041D		; 419
	neg	ax		; 41b
L041D:
	pop	dx		; 41d
	leave		; 41e
	retf		; 41f
_fn_1aff_03fd	endp

_fn_1aff_0420	proc	far
	enter	0h,0h		; 420
	push	dx		; 424
	mov	ax,[bp+6h]		; 425
	mov	dx,[bp+8h]		; 428
	mul	dx		; 42b
	mov	al,ah		; 42d
	mov	ah,dl		; 42f
	pop	dx		; 431
	leave		; 432
	retf		; 433
_fn_1aff_0420	endp

_fn_1aff_0434	proc	far
	enter	0h,0h		; 434
	push	dx		; 438
	push	bx		; 439
	xor	dx,dx		; 43a
	mov	ax,[bp+6h]		; 43c
	mov	dl,ah		; 43f
	mov	ah,al		; 441
	xor	al,al		; 443
	div	word ptr [bp+8h]		; 445
	pop	bx		; 448
	pop	dx		; 449
	leave		; 44a
	retf		; 44b
_fn_1aff_0434	endp
S040_TEXT	ends
	end
