; s127: WW library -- keyboard (INT 9 handler, key buffer, scan code to ASCII tables in the code segment)
; segment 2169 (TASM module). The six `db` instructions use a 16-bit displacement < 80h, which TASM
; always shortens to disp8.
; FIXUP-ORDER: b00 b13 b18 bd6 c6e
	.386
S127_TEXT	segment word public use16 'CODE'
S127_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:S127_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	extrn	_fn_1809_0bde:far
	extrn	_fn_1ebc_000c:far
	extrn	_fn_1ebc_0053:far
S127_TEXT	segment
	public	_fn_2169_0276, _fn_2169_0482, _fn_2169_04ba, _fn_2169_04f7, _fn_2169_0516, _fn_2169_0593, _fn_2169_060c, _fn_2169_062e, _fn_2169_06e9, _fn_2169_073a, _fn_2169_0790, _fn_2169_07ae, _fn_2169_07df, _fn_2169_086b, _fn_2169_0945, _fn_2169_0c35, _fn_2169_0e78
L000C	label	byte
	db	0h, 0h, 0ffh, 0h, 1h, 0f0h, 0h, 10h, 0a0h, 0h, 0h, 0h, 3fh, 1h, 0h, 0h	; c
	db	3fh, 1h, 45h, 0h, 3fh, 1h, 89h, 0h, 0a0h, 0h, 89h, 0h, 0h, 0h, 89h, 0h	; 1c
	db	0h, 0h, 45h, 0h, 0h, 0h, 0h, 0h, 0a0h, 0h, 45h, 0h, 1h, 2h, 4h, 8h	; 2c
	db	10h, 20h, 40h, 80h, 20h, 2h, 20h, 3h, 0ch, 6h, 0dh, 7h, 6ah, 6h, 69h, 6h	; 3c
	db	30h, 2h, 30h, 3h, 7dh, 0h, 7dh, 1h, 5ah, 2h, 5ah, 3h, 0h, 2h, 10h, 4h	; 4c
	db	6eh, 4h, 6eh, 2h, 7ch, 0h, 8h, 0h, 8h, 0h, 10h, 0h, 10h, 0h, 10h, 0h	; 5c
	db	10h, 0h, 20h, 0h, 20h, 0h, 40h, 0h, 40h, 0h, 80h, 0h, 80h, 0h, 0h, 1h	; 6c
	db	0h, 4h, 0h, 4h, 0h, 4h, 0h, 1h, 0h, 0h, 0h, 0h, 38h, 1dh, 52h, 53h	; 7c
	db	4bh, 47h, 4fh, 48h, 50h, 49h, 51h, 4dh, 35h, 1ch, 37h, 46h, 3eh, 40h, 4bh, 4ch	; 8c
	db	4fh, 50h, 51h, 53h, 54h, 55h, 56h, 59h, 5fh, 6ch, 7ch, 0h, 3ch, 3ah, 63h, 68h	; 9c
	db	5ch, 5bh, 5dh, 60h, 62h, 65h, 67h, 66h, 37h, 2bh, 7ch	; ac
	db	268 dup (0h)	; b7
	db	7fh, 6eh, 2h, 3h, 4h, 5h, 6h, 7h, 8h, 9h, 0ah, 0bh, 0ch, 0dh, 0fh, 10h	; 1c3
	db	11h, 12h, 13h, 14h, 15h, 16h, 17h, 18h, 19h, 1ah, 1bh, 1ch, 2bh, 3ah, 1fh, 20h	; 1d3
	db	21h, 22h, 23h, 24h, 25h, 26h, 27h, 28h, 29h, 1h, 2ch, 1dh, 2eh, 2fh, 30h, 31h	; 1e3
	db	32h, 33h, 34h, 35h, 36h, 37h, 39h, 64h, 3ch, 3dh, 1eh, 70h, 71h, 72h, 73h, 74h	; 1f3
	db	75h, 76h, 77h, 78h, 79h, 5ah, 7dh, 5bh, 60h, 65h, 69h, 5ch, 61h, 66h, 6ah, 5dh	; 203
	db	62h, 67h, 63h, 68h, 7fh, 7fh, 7fh, 7ah, 7bh, 0h, 0h, 0feh, 87h, 0ffh, 0c0h, 1fh	; 213
	db	20 dup (0h)	; 223
	db	38h, 0efh, 1h	; 237
	db	48 dup (0h)	; 23a
	db	1eh, 2ch, 39h, 3ah, 3ch, 3eh, 40h, 5ah, 80h, 80h, 80h, 0h	; 26a
_fn_2169_0276	proc	far
	push	bx		; 276
	push	cx		; 277
	push	di		; 278
	push	ds		; 279
	test	ax,8000h		; 27a
	jnz	short L0284		; 27d
	test	ah,8h		; 27f
	jz	short L028B		; 282
L0284:
	xor	ax,ax		; 284
	pop	ds		; 286
	pop	di		; 287
	pop	cx		; 288
	pop	bx		; 289
	retn		; 28a
L028B:
	push	cs		; 28b
	pop	ds		; 28c
	push	ax		; 28d
	mov	ax,ds:[35e6h]		; 28e
	mov	cs:[1bdh],ax		; 291
	pop	ax		; 295
	cmp	al,6eh		; 296
	jz	near ptr L034C		; 298
	cmp	al,3eh		; 29c
	jnc	short L02E4		; 29e
	mov	bx,ax		; 2a0
	and	bx,+3fh		; 2a2
	test	ah,1h		; 2a5
	jnz	short L02BF		; 2a8
	mov	al,cs:[bx+353h]		; 2aa
	jmp	short L02C4		; 2af
	mov	al,cs:[bx+3cfh]		; 2b1
	jmp	short L02C4		; 2b6
	mov	al,cs:[bx+40dh]		; 2b8
	jmp	short L02C4		; 2bd
L02BF:
	mov	al,cs:[bx+391h]		; 2bf
L02C4:
	test	ah,2h		; 2c4
	jz	short L02E2		; 2c7
	mov	di,bx		; 2c9
	and	di,+7h		; 2cb
	db	2eh, 8ah, 8dh, 38h, 0h	; 2ce: mov cl,[cs:di+0x38]
	shr	bx,1		; 2d3
	shr	bx,1		; 2d5
	shr	bx,1		; 2d7
	test	cs:[bx+21ch],cl		; 2d9
	jz	short L02E2		; 2de
	and	al,1fh		; 2e0
L02E2:
	jmp	short L034E		; 2e2
L02E4:
	cmp	al,4bh		; 2e4
	jc	short L0340		; 2e6
	cmp	al,6eh		; 2e8
	jnc	short L0316		; 2ea
	xor	bh,bh		; 2ec
	mov	bl,al		; 2ee
	sub	bl,4bh		; 2f0
	test	word ptr cs:[1bdh],200h		; 2f3
	jnz	short L0305		; 2fa
	test	word ptr cs:[1c1h],2h		; 2fc
	jnz	short L030C		; 303
L0305:
	mov	al,cs:[bx+44bh]		; 305
	jmp	short L034E		; 30a
L030C:
	sub	bl,0fh		; 30c
	mov	al,cs:[bx+46eh]		; 30f
	jmp	short L034E		; 314
L0316:
	cmp	al,70h		; 316
	jc	short L0348		; 318
	cmp	al,79h		; 31a
	ja	short L0348		; 31c
	mov	bl,al		; 31e
	sub	bl,70h		; 320
	mov	bh,0c5h		; 323
	test	ah,7h		; 325
	jz	short L033A		; 328
	mov	bh,98h		; 32a
	test	ah,4h		; 32c
	jnz	short L033A		; 32f
	mov	bh,0a2h		; 331
	test	ah,2h		; 333
	jnz	short L033A		; 336
	mov	bh,0ach		; 338
L033A:
	sub	bh,bl		; 33a
	mov	al,bh		; 33c
	jmp	short L034E		; 33e
L0340:
	cmp	al,41h		; 340
	jc	short L0348		; 342
	add	al,85h		; 344
	jmp	short L034E		; 346
L0348:
	or	al,80h		; 348
	jmp	short L034E		; 34a
L034C:
	mov	al,1bh		; 34c
L034E:
	pop	ds		; 34e
	pop	di		; 34f
	pop	cx		; 350
	pop	bx		; 351
	retn		; 352
L0353	label	byte
	db	0h, 60h, 31h, 32h, 33h, 34h, 35h, 36h, 37h, 38h, 39h, 30h, 2dh, 3dh, 0h, 8h	; 353
	db	9h, 71h, 77h, 65h, 72h, 74h, 79h, 75h, 69h, 6fh, 70h, 5bh, 5dh, 5ch, 0h, 61h	; 363
	db	73h, 64h, 66h, 67h, 68h, 6ah, 6bh, 6ch, 3bh, 27h, 0h, 0dh, 0h, 2dh, 7ah, 78h	; 373
	db	63h, 76h, 62h, 6eh, 6dh, 2ch, 2eh, 2fh, 0h, 0h, 0h, 0h, 0h, 20h, 0h, 7eh	; 383
	db	21h, 40h, 23h, 24h, 25h, 5eh, 26h, 2ah, 28h, 29h, 5fh, 2bh, 0h, 8h, 9h, 51h	; 393
	db	57h, 45h, 52h, 54h, 59h, 55h, 49h, 4fh, 50h, 7bh, 7dh, 7ch, 0h, 41h, 53h, 44h	; 3a3
	db	46h, 47h, 48h, 4ah, 4bh, 4ch, 3ah, 22h, 0h, 0dh, 0h, 2dh, 5ah, 58h, 43h, 56h	; 3b3
	db	42h, 4eh, 4dh, 3ch, 3eh, 3fh, 0h, 0h, 0h, 0h, 0h, 20h, 0h, 7eh, 21h, 40h	; 3c3
	db	23h, 24h, 25h, 5eh, 26h, 2ah, 28h, 29h, 5fh, 2bh, 0h, 8h, 9h, 71h, 77h, 65h	; 3d3
	db	72h, 74h, 79h, 75h, 69h, 6fh, 70h, 7bh, 7dh, 7ch, 0h, 61h, 73h, 64h, 66h, 67h	; 3e3
	db	68h, 6ah, 6bh, 6ch, 3ah, 22h, 0h, 0dh, 0h, 2dh, 7ah, 78h, 63h, 76h, 62h, 6eh	; 3f3
	db	6dh, 3ch, 3eh, 3fh, 0h, 0h, 0h, 0h, 0h, 20h, 0h, 60h, 31h, 32h, 33h, 34h	; 403
	db	35h, 36h, 37h, 38h, 39h, 30h, 2dh, 3dh, 0h, 8h, 9h, 51h, 57h, 45h, 52h, 54h	; 413
	db	59h, 55h, 49h, 4fh, 50h, 5bh, 5dh, 5ch, 0h, 41h, 53h, 44h, 46h, 47h, 48h, 4ah	; 423
	db	4bh, 4ch, 3bh, 27h, 0h, 0dh, 0h, 2dh, 5ah, 58h, 43h, 56h, 42h, 4eh, 4dh, 2ch	; 433
	db	2eh, 2fh, 0h, 0h, 0h, 0h, 0h, 20h, 0aeh, 0adh, 0h, 0h, 0b5h, 0b9h, 0b1h, 0h	; 443
	db	0b8h, 0b0h, 0b7h, 0afh, 0h, 0h, 0b3h, 0h, 0b9h, 0b5h, 0b1h, 0h, 2fh, 0b8h, 0b4h, 0b0h	; 453
	db	0aeh, 2ah, 0b7h, 0b3h, 0afh, 0adh, 2dh, 2bh, 0h, 0dh, 0h, 0h, 37h, 34h, 31h, 0h	; 463
	db	2fh, 38h, 35h, 32h, 30h, 2ah, 39h, 36h, 33h, 2eh, 2dh, 2bh, 0h, 0dh, 0h	; 473
_fn_2169_0276	endp

_fn_2169_0482	proc	far
	enter	0h,0h		; 482
	mov	ax,[bp+6h]		; 486
	call	near ptr _fn_2169_0276		; 489
	leave		; 48c
	retf		; 48d
L048E:
	enter	0h,0h		; 48e
	push	cx		; 492
	push	es		; 493
	push	di		; 494
	mov	ax,[bp+6h]		; 495
	test	word ptr ds:[35e6h],2h		; 498
	jnz	short L04B5		; 49e
	mov	cx,10h		; 4a0
	push	cs		; 4a3
	pop	es		; 4a4
	mov	di,98h		; 4a5
	repne	scasb		; 4a8
	jcxz	short L04B5		; 4aa
	mov	di,0b8h		; 4ac
	dec	di		; 4af
	sub	di,cx		; 4b0
	mov	al,es:[di]		; 4b2
L04B5:
	pop	di		; 4b5
	pop	es		; 4b6
	pop	cx		; 4b7
	leave		; 4b8
	retf		; 4b9
_fn_2169_0482	endp

_fn_2169_04ba	proc	far
	enter	0h,0h		; 4ba
	mov	ax,[bp+6h]		; 4be
	or	ds:[35e6h],ax		; 4c1
	mov	ax,ds:[35e6h]		; 4c5
	test	ax,800h		; 4c8
	jz	short L04F5		; 4cb
	push	ax		; 4cd
	push	ds		; 4ce
	push	cs		; 4cf
	pop	ds		; 4d0
	xor	ax,ax		; 4d1
	mov	cs:[23ch],ax		; 4d3
	mov	cs:[23eh],ax		; 4d7
	mov	cs:[240h],ax		; 4db
	mov	cs:[242h],ax		; 4df
	mov	cs:[244h],ax		; 4e3
	mov	cs:[246h],ax		; 4e7
	mov	cs:[248h],ax		; 4eb
	mov	cs:[24ah],ax		; 4ef
	pop	ds		; 4f3
	pop	ax		; 4f4
L04F5:
	leave		; 4f5
	retf		; 4f6
_fn_2169_04ba	endp

_fn_2169_04f7	proc	far
	enter	0h,0h		; 4f7
	mov	ax,[bp+6h]		; 4fb
	not	ax		; 4fe
	and	ds:[35e6h],ax		; 500
	mov	ax,ds:[35e6h]		; 504
	leave		; 507
	retf		; 508
L0509:
	mov	ax,0h		; 509
	retn		; 50c
L050D:
	push	ax		; 50d
	push	bx		; 50e
	push	cx		; 50f
	push	di		; 510
	pop	di		; 511
	pop	cx		; 512
	pop	bx		; 513
	pop	ax		; 514
	retn		; 515
_fn_2169_04f7	endp

_fn_2169_0516	proc	far
	push	cx		; 516
	push	es		; 517
	push	di		; 518
	push	si		; 519
	pushf		; 51a
	call	near ptr L0509		; 51b
	cld		; 51e
	mov	ax,cs		; 51f
	mov	es,ax		; 521
L0523:
	cli		; 523
	mov	ax,cs:[1b9h]		; 524
	cmp	byte ptr ds:[35eeh],2h		; 528
	jz	short L0536		; 52d
	cmp	ax,cs:[1bbh]		; 52f
	jz	short L0577		; 534
L0536:
	mov	si,ax		; 536
	mov	ax,cs:[si+0b9h]		; 538
	cmp	byte ptr ds:[35eeh],2h		; 53d
	jnz	short L0548		; 542
	or	ax,ax		; 544
	jz	short L0579		; 546
L0548:
	mov	di,26ah		; 548
	mov	cx,0bh		; 54b
	repne	scasb		; 54e
	or	cx,cx		; 550
	jnz	short L055D		; 552
	test	ah,8h		; 554
	jnz	short L055D		; 557
	cmp	al,7ah		; 559
	jc	short L0579		; 55b
L055D:
	cmp	al,41h		; 55d
	jc	short L0568		; 55f
	cmp	al,44h		; 561
	ja	short L0568		; 563
	add	si,+4h		; 565
L0568:
	add	si,+2h		; 568
	and	si,0ffh		; 56b
	mov	cs:[1b9h],si		; 56f
	sti		; 574
	jmp	short L0523		; 575
L0577:
	xor	ax,ax		; 577
L0579:
	mov	cx,cs:[1bfh]		; 579
	mov	cs:[1c1h],cx		; 57e
	sti		; 583
	or	ax,ax		; 584
	jz	short L058D		; 586
	call	near ptr _fn_2169_0276		; 588
	xor	ah,ah		; 58b
L058D:
	popf		; 58d
	pop	si		; 58e
	pop	di		; 58f
	pop	es		; 590
	pop	cx		; 591
	retf		; 592
_fn_2169_0516	endp

_fn_2169_0593	proc	far
	push	cx		; 593
	push	es		; 594
	push	di		; 595
	push	si		; 596
	pushf		; 597
	call	near ptr L0509		; 598
	cld		; 59b
	mov	ax,cs		; 59c
	mov	es,ax		; 59e
L05A0:
	cli		; 5a0
	mov	ax,cs:[1b9h]		; 5a1
	cmp	byte ptr ds:[35eeh],2h		; 5a5
	jz	short L05B3		; 5aa
	cmp	ax,cs:[1bbh]		; 5ac
	jz	short L05E8		; 5b1
L05B3:
	mov	si,ax		; 5b3
	mov	ax,cs:[si+0b9h]		; 5b5
	cmp	byte ptr ds:[35eeh],2h		; 5ba
	jnz	short L05C5		; 5bf
	or	ax,ax		; 5c1
	jz	short L05EA		; 5c3
L05C5:
	mov	di,26ah		; 5c5
	mov	cx,0bh		; 5c8
	repne	scasb		; 5cb
	or	cx,cx		; 5cd
	jnz	short L05D9		; 5cf
	or	al,al		; 5d1
	jz	short L05D9		; 5d3
	cmp	al,7ah		; 5d5
	jc	short L05EA		; 5d7
L05D9:
	add	si,+2h		; 5d9
	and	si,0ffh		; 5dc
	mov	cs:[1b9h],si		; 5e0
	sti		; 5e5
	jmp	short L05A0		; 5e6
L05E8:
	xor	ax,ax		; 5e8
L05EA:
	mov	cx,cs:[1bfh]		; 5ea
	mov	cs:[1c1h],cx		; 5ef
	sti		; 5f4
	or	ax,ax		; 5f5
	jz	short L0606		; 5f7
	mov	ch,ah		; 5f9
	and	ch,8h		; 5fb
	and	ah,0f7h		; 5fe
	call	near ptr _fn_2169_0276		; 601
	or	ah,ch		; 604
L0606:
	popf		; 606
	pop	si		; 607
	pop	di		; 608
	pop	es		; 609
	pop	cx		; 60a
	retf		; 60b
_fn_2169_0593	endp

_fn_2169_060c	proc	far
	push	si		; 60c
	call	near ptr L0509		; 60d
	pushf		; 610
	cli		; 611
	mov	ax,cs:[1b9h]		; 612
	xor	ax,cs:[1bbh]		; 616
	popf		; 61b
	cmp	ax,0h		; 61c
	jz	short L062C		; 61f
	mov	ax,cs:[1b9h]		; 621
	mov	si,ax		; 625
	mov	ax,cs:[si+0b9h]		; 627
L062C:
	pop	si		; 62c
	retf		; 62d
_fn_2169_060c	endp

_fn_2169_062e	proc	far
	push	ax		; 62e
	pushf		; 62f
	cli		; 630
	mov	ax,cs:[1b9h]		; 631
	mov	cs:[1bbh],ax		; 635
	popf		; 639
	pop	ax		; 63a
	retf		; 63b
L063C:
	push	ds		; 63c
	push	di		; 63d
	mov	di,ax		; 63e
	mov	ax,DGROUP		; 640
	mov	ds,ax		; 643
	mov	ax,cs:[di+0b9h]		; 645
	cmp	byte ptr ds:[35eeh],2h		; 64a
	jnz	short L0654		; 64f
	mov	ax,ds:[35efh]		; 651
L0654:
	mov	ds:[35efh],ax		; 654
	add	di,+2h		; 657
	and	di,0ffh		; 65a
	cmp	al,41h		; 65e
	jc	short L06DA		; 660
	cmp	al,42h		; 662
	ja	short L06A2		; 664
	push	ax		; 666
	mov	ax,cs:[di+0b9h]		; 667
	cmp	byte ptr ds:[35eeh],2h		; 66c
	jnz	short L0676		; 671
	mov	ax,ds:[35f1h]		; 673
L0676:
	mov	ds:[35f1h],ax		; 676
	add	di,+2h		; 679
	and	di,0ffh		; 67c
	mov	ds:[2f10h],ax		; 680
	mov	ax,cs:[di+0b9h]		; 683
	cmp	byte ptr ds:[35eeh],2h		; 688
	jnz	short L0692		; 68d
	mov	ax,ds:[35f3h]		; 68f
L0692:
	mov	ds:[35f3h],ax		; 692
	add	di,+2h		; 695
	and	di,0ffh		; 698
	mov	ds:[2f12h],ax		; 69c
	pop	ax		; 69f
	jmp	short L06DA		; 6a0
L06A2:
	cmp	al,44h		; 6a2
	ja	short L06DA		; 6a4
	push	ax		; 6a6
	mov	ax,cs:[di+0b9h]		; 6a7
	cmp	byte ptr ds:[35eeh],2h		; 6ac
	jnz	short L06B6		; 6b1
	mov	ax,ds:[35f1h]		; 6b3
L06B6:
	mov	ds:[35f1h],ax		; 6b6
	add	di,+2h		; 6b9
	and	di,0ffh		; 6bc
	mov	ax,cs:[di+0b9h]		; 6c0
	cmp	byte ptr ds:[35eeh],2h		; 6c5
	jnz	short L06CF		; 6ca
	mov	ax,ds:[35f3h]		; 6cc
L06CF:
	mov	ds:[35f3h],ax		; 6cf
	add	di,+2h		; 6d2
	and	di,0ffh		; 6d5
	pop	ax		; 6d9
L06DA:
	cmp	byte ptr ds:[35eeh],2h		; 6da
	jz	short L06E6		; 6df
	mov	cs:[1b9h],di		; 6e1
L06E6:
	pop	di		; 6e6
	pop	ds		; 6e7
	retn		; 6e8
_fn_2169_062e	endp

_fn_2169_06e9	proc	far
	push	bx		; 6e9
	push	cx		; 6ea
	push	es		; 6eb
	push	di		; 6ec
	push	ds		; 6ed
	cld		; 6ee
	mov	ax,cs		; 6ef
	mov	es,ax		; 6f1
L06F3:
	cli		; 6f3
	cmp	byte ptr ds:[35eeh],2h		; 6f4
	jz	short L0709		; 6f9
	mov	ax,cs:[1b9h]		; 6fb
	cmp	ax,cs:[1bbh]		; 6ff
	jnz	short L0709		; 704
	sti		; 706
	jmp	short L06F3		; 707
L0709:
	call	near ptr L063C		; 709
	mov	cx,cs:[1bfh]		; 70c
	mov	cs:[1c1h],cx		; 711
	sti		; 716
	mov	di,26ah		; 717
	mov	cx,0bh		; 71a
	repne	scasb		; 71d
	or	cx,cx		; 71f
	jnz	short L06F3		; 721
	test	ah,8h		; 723
	jnz	short L06F3		; 726
	cmp	al,7ah		; 728
	jnc	short L06F3		; 72a
	call	near ptr _fn_2169_0276		; 72c
	call	near ptr L050D		; 72f
	xor	ah,ah		; 732
	pop	ds		; 734
	pop	di		; 735
	pop	es		; 736
	pop	cx		; 737
	pop	bx		; 738
	retf		; 739
_fn_2169_06e9	endp

_fn_2169_073a	proc	far
	push	bx		; 73a
	push	cx		; 73b
	push	es		; 73c
	push	di		; 73d
	push	ds		; 73e
	cld		; 73f
	mov	ax,cs		; 740
	mov	es,ax		; 742
	mov	ds,ax		; 744
L0746:
	cli		; 746
	cmp	byte ptr ds:[35eeh],2h		; 747
	jz	short L075C		; 74c
	mov	ax,cs:[1b9h]		; 74e
	cmp	ax,cs:[1bbh]		; 752
	jnz	short L075C		; 757
	sti		; 759
	jmp	short L0746		; 75a
L075C:
	call	near ptr L063C		; 75c
	mov	cx,cs:[1bfh]		; 75f
	mov	cs:[1c1h],cx		; 764
	sti		; 769
	mov	di,26ah		; 76a
	mov	cx,0bh		; 76d
	repne	scasb		; 770
	or	cx,cx		; 772
	jnz	short L0746		; 774
	cmp	al,7ah		; 776
	jnc	short L0746		; 778
	mov	ch,ah		; 77a
	and	ch,8h		; 77c
	and	ah,0f7h		; 77f
	call	near ptr _fn_2169_0276		; 782
	or	ah,ch		; 785
	call	near ptr L050D		; 787
	pop	ds		; 78a
	pop	di		; 78b
	pop	es		; 78c
	pop	cx		; 78d
	pop	bx		; 78e
	retf		; 78f
_fn_2169_073a	endp

_fn_2169_0790	proc	far
	cli		; 790
	cmp	byte ptr ds:[35eeh],2h		; 791
	jz	short L07A6		; 796
	mov	ax,cs:[1b9h]		; 798
	cmp	ax,cs:[1bbh]		; 79c
	jnz	short L07A6		; 7a1
	sti		; 7a3
	jmp	short _fn_2169_0790		; 7a4
L07A6:
	call	near ptr L063C		; 7a6
	sti		; 7a9
	call	near ptr L050D		; 7aa
	retf		; 7ad
_fn_2169_0790	endp

_fn_2169_07ae	proc	far
	enter	0h,0h		; 7ae
	push	bx		; 7b2
	push	cx		; 7b3
	push	di		; 7b4
	push	ds		; 7b5
	call	near ptr L0509		; 7b6
	push	word ptr [bp+6h]		; 7b9
	push	cs		; 7bc
	call	near ptr L048E		; 7bd
	add	sp,+2h		; 7c0
	xor	ah,ah		; 7c3
	mov	di,ax		; 7c5
	mov	cl,3h		; 7c7
	shr	di,cl		; 7c9
	mov	cl,al		; 7cb
	and	cl,7h		; 7cd
	mov	al,1h		; 7d0
	shl	al,cl		; 7d2
	and	al,cs:[di+23ch]		; 7d4
	pop	ds		; 7d9
	pop	di		; 7da
	pop	cx		; 7db
	pop	bx		; 7dc
	leave		; 7dd
	retf		; 7de
_fn_2169_07ae	endp

_fn_2169_07df	proc	far
	push	bx		; 7df
	push	cx		; 7e0
	push	di		; 7e1
	mov	bx,ax		; 7e2
	push	ax		; 7e4
	push	cs		; 7e5
	call	near ptr _fn_2169_07ae		; 7e6
	add	sp,+2h		; 7e9
	cmp	ax,0h		; 7ec
	jz	short L0865		; 7ef
	mov	ax,bx		; 7f1
	xor	ah,ah		; 7f3
	mov	di,ax		; 7f5
	shr	di,1		; 7f7
	shr	di,1		; 7f9
	shr	di,1		; 7fb
	mov	ch,1h		; 7fd
	mov	cl,al		; 7ff
	and	cl,7h		; 801
	shl	ch,cl		; 804
	test	byte ptr cs:[243h],4h		; 806
	jnz	short L0816		; 80c
	test	byte ptr cs:[244h],1h		; 80e
	jz	short L0819		; 814
L0816:
	or	ah,2h		; 816
L0819:
	test	byte ptr cs:[243h],50h		; 819
	jz	short L0824		; 81f
	or	ah,4h		; 821
L0824:
	test	byte ptr cs:[241h],10h		; 824
	jnz	short L0834		; 82a
	test	byte ptr cs:[243h],2h		; 82c
	jz	short L0837		; 832
L0834:
	or	ah,1h		; 834
L0837:
	test	word ptr cs:[1bfh],1h		; 837
	jz	short L084A		; 83e
	test	cs:[di+21ch],ch		; 840
	jz	short L084A		; 845
	xor	ah,1h		; 847
L084A:
	test	word ptr cs:[1bfh],2h		; 84a
	jz	short L085D		; 851
	test	cs:[di+22ch],ch		; 853
	jz	short L085D		; 858
	xor	ah,1h		; 85a
L085D:
	mov	al,0ffh		; 85d
	cmp	ah,bh		; 85f
	jz	short L0865		; 861
	xor	ax,ax		; 863
L0865:
	or	ax,ax		; 865
	pop	di		; 867
	pop	cx		; 868
	pop	bx		; 869
	retf		; 86a
_fn_2169_07df	endp

_fn_2169_086b	proc	far
	push	ax		; 86b
	push	bx		; 86c
	push	dx		; 86d
	push	ds		; 86e
	push	es		; 86f
	mov	ax,40h		; 870
	mov	es,ax		; 873
	mov	al,es:[17h]		; 875
	test	al,40h		; 879
	jz	short L0883		; 87b
	or	word ptr cs:[1bfh],+1h		; 87d
L0883:
	test	al,20h		; 883
	jz	short L088D		; 885
	or	word ptr cs:[1bfh],+2h		; 887
L088D:
	test	al,2h		; 88d
	jz	short L0897		; 88f
	or	byte ptr cs:[241h],10h		; 891
L0897:
	and	al,1h		; 897
	shl	al,1		; 899
	mov	ah,al		; 89b
	mov	al,es:[18h]		; 89d
	shl	al,1		; 8a1
	shl	al,1		; 8a3
	and	al,0ch		; 8a5
	or	ah,al		; 8a7
	mov	al,es:[96h]		; 8a9
	test	al,8h		; 8ad
	jz	short L08B4		; 8af
	or	ah,40h		; 8b1
L08B4:
	mov	cs:[243h],ah		; 8b4
	test	al,4h		; 8b9
	jz	short L08C3		; 8bb
	or	byte ptr cs:[244h],1h		; 8bd
L08C3:
	test	al,2h		; 8c3
	jz	short L08CD		; 8c5
	mov	byte ptr cs:[260h],1h		; 8c7
L08CD:
	test	al,1h		; 8cd
	jz	short L08D7		; 8cf
	mov	byte ptr cs:[261h],2h		; 8d1
L08D7:
	mov	ax,3509h		; 8d7
	int	21h		; 8da
	mov	cs:[262h],bx		; 8dc
	mov	cs:[264h],es		; 8e1
	mov	bx,cs		; 8e6
	mov	ds,bx		; 8e8
	mov	dx,0c35h		; 8ea
	mov	ax,2509h		; 8ed
	int	21h		; 8f0
	mov	ax,3523h		; 8f2
	int	21h		; 8f5
	mov	cs:[266h],bx		; 8f7
	mov	cs:[268h],es		; 8fc
	mov	bx,cs		; 901
	mov	ds,bx		; 903
	mov	dx,0e77h		; 905
	mov	ax,2523h		; 908
	int	21h		; 90b
	pop	es		; 90d
	pop	ds		; 90e
	pop	dx		; 90f
	pop	bx		; 910
	pop	ax		; 911
	retf		; 912
L0913:
	enter	0h,0h		; 913
	push	si		; 917
	push	bx		; 918
	mov	ax,cs:[1bbh]		; 919
	mov	si,ax		; 91d
	add	ax,2h		; 91f
	and	ax,0ffh		; 922
	cmp	cs:[1b9h],ax		; 925
	jz	short L093E		; 92a
	mov	bx,[bp+6h]		; 92c
	mov	cs:[si+0b9h],bx		; 92f
	mov	cs:[1bbh],ax		; 934
	xor	ax,ax		; 938
	pop	bx		; 93a
	pop	si		; 93b
	leave		; 93c
	retf		; 93d
L093E:
	mov	ax,1h		; 93e
	pop	bx		; 941
	pop	si		; 942
	leave		; 943
	retf		; 944
_fn_2169_086b	endp

_fn_2169_0945	proc	far
	enter	4h,0h		; 945
	push	ax		; 949
	push	bx		; 94a
	push	cx		; 94b
	push	dx		; 94c
	push	es		; 94d
	push	di		; 94e
	push	ds		; 94f
	push	si		; 950
	pushf		; 951
	cli		; 952
	mov	ax,DGROUP		; 953
	mov	ds,ax		; 956
	mov	ax,ds:[35e6h]		; 958
	mov	cs:[1bdh],ax		; 95b
	mov	ax,ds:[2f0ch]		; 95f
	mov	cs:[990h],ax		; 962
	mov	ax,ds:[2f0eh]		; 966
	mov	cs:[992h],ax		; 969
	cmp	byte ptr ds:[35eeh],1h		; 96d
	jnz	short L0982		; 972
	mov	word ptr [bp-4h],4h		; 974
	cmp	byte ptr ds:[0abdeh],0h		; 979
	jnz	near ptr L0C2A		; 97e
L0982:
	mov	ax,[bp+6h]		; 982
	or	ax,ax		; 985
	jnz	short L09CE		; 987
	jmp	near ptr L0C2A		; 989
L098C	label	byte
	db	0h, 0h, 0h, 0h, 0h, 0h, 0h, 0h, 0ffh, 0ffh, 0ffh, 0h, 0ffh, 1h, 0h, 0h	; 98c
	db	0h, 0h, 0h, 0ffh, 0h, 0h, 0h, 1h, 0h, 0h, 0h, 0h, 1h, 0ffh, 1h, 0h	; 99c
	db	1h, 1h, 8h, 0h, 2h, 0h, 8h, 0h, 6h, 0h, 4h, 0h, 3h, 0h, 8h, 0h	; 9ac
	db	5h, 0h, 8h, 0h, 8h, 0h, 8h, 0h, 8h, 0h, 0h, 0h, 1h, 0h, 8h, 0h	; 9bc
	db	7h, 0h	; 9cc
L09CE:
	push	ds		; 9ce
	pop	es		; 9cf
	push	cs		; 9d0
	pop	ds		; 9d1
	test	word ptr cs:[1bdh],1000h		; 9d2
	jz	near ptr L0B30		; 9d9
	test	ah,4h		; 9dd
	jnz	near ptr L0B30		; 9e0
	test	word ptr cs:[1bdh],2000h		; 9e4
	jz	short L09F9		; 9eb
	cmp	al,2bh		; 9ed
	jz	short L09FD		; 9ef
	cmp	al,3dh		; 9f1
	jz	short L09FD		; 9f3
	cmp	al,6ch		; 9f5
	jz	short L09FD		; 9f7
L09F9:
	cmp	al,63h		; 9f9
	jnz	short L0A15		; 9fb
L09FD:
	mov	al,41h		; 9fd
	or	byte ptr es:[2f45h],1h		; 9ff
	test	ah,8h		; a05
	jz	near ptr L0B2B		; a08
	and	byte ptr es:[2f45h],0feh		; a0c
	jmp	near ptr L0B2B		; a12
L0A15:
	cmp	al,68h		; a15
	jnz	short L0A31		; a17
	mov	al,42h		; a19
	or	byte ptr es:[2f45h],2h		; a1b
	test	ah,8h		; a21
	jz	near ptr L0B2B		; a24
	and	byte ptr es:[2f45h],0fdh		; a28
	jmp	near ptr L0B2B		; a2e
L0A31:
	test	ah,8h		; a31
	jnz	near ptr L0B30		; a34
	cmp	al,61h		; a38
	jz	short L0A5A		; a3a
	cmp	al,5bh		; a3c
	jc	near ptr L0B30		; a3e
	cmp	al,67h		; a42
	ja	near ptr L0B30		; a44
	cmp	al,5dh		; a48
	jna	short L0A5A		; a4a
	cmp	al,65h		; a4c
	jnc	short L0A5A		; a4e
	cmp	al,60h		; a50
	jz	short L0A5A		; a52
	cmp	al,62h		; a54
	jnz	near ptr L0B30		; a56
L0A5A:
	mov	ch,ah		; a5a
	xor	ah,ah		; a5c
	sub	al,5bh		; a5e
	mov	bx,ax		; a60
	shl	bx,1		; a62
	add	bx,994h		; a64
	mov	ax,[bx]		; a68
	mov	bl,ah		; a6a
	cbw		; a6c
	xchg	ax,bx		; a6d
	cbw		; a6e
	xchg	ax,bx		; a6f
	test	ch,2h		; a70
	jnz	short L0A98		; a73
	mov	dx,1h		; a75
	test	ch,1h		; a78
	jz	short L0A80		; a7b
	add	dx,+3h		; a7d
L0A80:
	add	bx,dx		; a80
	db	2eh, 8ah, 9fh, 0eh, 0h	; a82: mov bl,[cs:bx+0xe]
	xchg	ax,bx		; a87
	cbw		; a88
	xchg	ax,bx		; a89
	xchg	bx,dx		; a8a
	add	bx,ax		; a8c
	db	2eh, 8ah, 87h, 0eh, 0h	; a8e: mov al,[cs:bx+0xe]
	cbw		; a93
	xchg	bx,dx		; a94
	jmp	short L0ACD		; a96
L0A98:
	and	bx,+3h		; a98
	and	ax,3h		; a9b
	shl	bx,1		; a9e
	shl	bx,1		; aa0
	or	bx,ax		; aa2
	shl	bx,1		; aa4
	mov	bx,cs:[bx+9aeh]		; aa6
	shl	bx,1		; aab
	shl	bx,1		; aad
	db	2eh, 8bh, 87h, 14h, 0h	; aaf: mov ax,[cs:bx+0x14]
	db	2eh, 8bh, 9fh, 16h, 0h	; ab4: mov bx,[cs:bx+0x16]
	mov	cs:[990h],ax		; ab9
	mov	cs:[992h],bx		; abd
	mov	ax,cs:[990h]		; ac2
	mov	bx,cs:[992h]		; ac6
	jmp	short L0B02		; acb
L0ACD:
	add	cs:[990h],ax		; acd
	jns	short L0ADA		; ad2
	xor	ax,ax		; ad4
	mov	cs:[990h],ax		; ad6
L0ADA:
	add	cs:[992h],bx		; ada
	jns	short L0AE8		; adf
	xor	bx,bx		; ae1
	mov	cs:[992h],bx		; ae3
L0AE8:
	mov	ax,cs:[990h]		; ae8
	mov	bx,cs:[992h]		; aec
	cmp	ax,13fh		; af1
	jng	short L0AF9		; af4
	mov	ax,13fh		; af6
L0AF9:
	cmp	bx,0c7h		; af9
	jng	short L0B02		; afd
	mov	bx,0c7h		; aff
L0B02:
	mov	cs:[990h],ax		; b02
	mov	cs:[992h],bx		; b06
	mov	cx,DGROUP		; b0b
	mov	ds,cx		; b0e
	mov	ds:[2f0ch],ax		; b10
	mov	ds:[2f0eh],bx		; b13
	cmp	word ptr ds:[2f0ah],+0h		; b17
	jnz	short L0B28		; b1c
	call	far ptr _fn_1ebc_000c		; b1e
	call	far ptr _fn_1ebc_0053		; b23
L0B28:
	mov	ax,2dh		; b28
L0B2B:
	push	cs		; b2b
	pop	ds		; b2c
	mov	[bp+6h],ax		; b2d
L0B30:
	mov	si,cs:[1bbh]		; b30
	mov	[bp-2h],si		; b35
	mov	di,cs:[1b9h]		; b38
	push	ax		; b3d
	push	cs		; b3e
	call	near ptr L0913		; b3f
	add	sp,+2h		; b42
	or	ax,ax		; b45
	jnz	short L0B5A		; b47
	mov	ax,[bp+6h]		; b49
	cmp	al,2dh		; b4c
	jz	short L0B5D		; b4e
	cmp	al,41h		; b50
	jz	short L0B5D		; b52
	cmp	al,42h		; b54
	jz	short L0B5D		; b56
	jmp	short L0B85		; b58
L0B5A:
	jmp	near ptr L0C21		; b5a
L0B5D:
	push	word ptr cs:[990h]		; b5d
	push	cs		; b62
	call	near ptr L0913		; b63
	add	sp,+2h		; b66
	or	ax,ax		; b69
	jnz	short L0B5A		; b6b
	add	word ptr [bp-4h],+2h		; b6d
	push	word ptr cs:[992h]		; b71
	push	cs		; b76
	call	near ptr L0913		; b77
	add	sp,+2h		; b7a
	or	ax,ax		; b7d
	jnz	short L0B5A		; b7f
	add	word ptr [bp-4h],+2h		; b81
L0B85:
	mov	bx,101h		; b85
	mov	ax,[bp+6h]		; b88
	cmp	al,2dh		; b8b
	jz	short L0BAB		; b8d
	cmp	al,7fh		; b8f
	jz	short L0BAB		; b91
	test	ah,8h		; b93
	jz	short L0BB0		; b96
	xor	bl,bl		; b98
	test	word ptr cs:[1bdh],800h		; b9a
	jnz	short L0BB0		; ba1
	cmp	al,41h		; ba3
	jz	short L0BB0		; ba5
	cmp	al,42h		; ba7
	jz	short L0BB0		; ba9
L0BAB:
	mov	cs:[1bbh],si		; bab
L0BB0:
	mov	di,ax		; bb0
	and	di,+7fh		; bb2
	mov	cl,3h		; bb5
	shr	di,cl		; bb7
	mov	cl,al		; bb9
	and	cl,7h		; bbb
	shl	bx,cl		; bbe
	not	bh		; bc0
	test	cs:[di+23ch],bl		; bc2
	jz	short L0BD7		; bc7
	test	word ptr cs:[1bdh],1h		; bc9
	jnz	short L0BD7		; bd0
	mov	cs:[1bbh],si		; bd2
L0BD7:
	and	cs:[di+23ch],bh		; bd7
	or	cs:[di+23ch],bl		; bdc
	mov	ax,DGROUP		; be1
	mov	ds,ax		; be4
	cmp	byte ptr ds:[35eeh],1h		; be6
	jnz	short L0C1C		; beb
	mov	ax,[bp+6h]		; bed
	cmp	al,7dh		; bf0
	jz	short L0C1C		; bf2
	mov	cs:[98ch],ax		; bf4
	mov	ax,ds:[3846h]		; bf8
	mov	cs:[98eh],ax		; bfb
	xor	cx,cx		; bff
	push	cx		; c01
	push	word ptr [bp-4h]		; c02
	push	cs		; c05
	mov	bx,98ch		; c06
	push	bx		; c09
	push	word ptr ds:[35e8h]		; c0a
	call	far ptr _fn_1809_0bde		; c0e
	add	sp,+0ah		; c13
	mov	word ptr ds:[3846h],0h		; c16
L0C1C:
	mov	ax,1h		; c1c
	jmp	short L0C2A		; c1f
L0C21:
	mov	ax,[bp-2h]		; c21
	mov	cs:[1bbh],ax		; c24
	xor	ax,ax		; c28
L0C2A:
	popf		; c2a
	pop	si		; c2b
	pop	ds		; c2c
	pop	di		; c2d
	pop	es		; c2e
	pop	dx		; c2f
	pop	cx		; c30
	pop	bx		; c31
	pop	ax		; c32
	leave		; c33
	retf		; c34
_fn_2169_0945	endp

_fn_2169_0c35	proc	far
	push	ax		; c35
	push	bx		; c36
	push	cx		; c37
	push	di		; c38
	push	ds		; c39
	push	dx		; c3a
	push	es		; c3b
	push	si		; c3c
	cld		; c3d
	and	word ptr cs:[1bfh],-4h		; c3e
	mov	ax,40h		; c44
	mov	es,ax		; c47
	test	byte ptr es:[17h],40h		; c49
	jz	short L0C57		; c4f
	or	word ptr cs:[1bfh],+1h		; c51
L0C57:
	test	byte ptr es:[17h],20h		; c57
	jz	short L0C65		; c5d
	or	word ptr cs:[1bfh],+2h		; c5f
L0C65:
	mov	byte ptr cs:[0b8h],1h		; c65
	test	byte ptr es:[96h],10h		; c6b
	jnz	short L0C79		; c71
	mov	byte ptr cs:[0b8h],0h		; c73
L0C79:
	mov	ax,DGROUP		; c79
	mov	ds,ax		; c7c
	mov	dx,ds:[35e6h]		; c7e
	mov	cs:[1bdh],dx		; c82
	mov	ax,cs		; c87
	mov	ds,ax		; c89
	mov	es,ax		; c8b
	cld		; c8d
	xor	ah,ah		; c8e
	mov	bx,101h		; c90
	in	al,60h		; c93
	mov	bx,cs:[25eh]		; c95
	mov	cs:[bx+24ch],al		; c9a
	inc	bx		; c9f
	and	bx,+0fh		; ca0
	mov	cs:[25eh],bx		; ca3
	mov	bx,101h		; ca8
	cmp	al,0e1h		; cab
	jnz	short L0CB5		; cad
	mov	byte ptr cs:[261h],3h		; caf
L0CB5:
	cmp	byte ptr cs:[261h],0h		; cb5
	jz	short L0CCD		; cbb
	dec	byte ptr cs:[261h]		; cbd
	test	dx,80h		; cc2
	jnz	near ptr L0E3A		; cc6
	jmp	near ptr L0E4C		; cca
L0CCD:
	cmp	al,0e0h		; ccd
	jnz	short L0CDA		; ccf
	mov	byte ptr cs:[260h],1h		; cd1
	jmp	near ptr L0E3A		; cd7
L0CDA:
	test	al,80h		; cda
	jz	short L0CE5		; cdc
	xor	bl,bl		; cde
	and	al,7fh		; ce0
	or	ah,8h		; ce2
L0CE5:
	cmp	byte ptr cs:[260h],0h		; ce5
	jz	short L0D13		; ceb
	mov	byte ptr cs:[260h],0h		; ced
	mov	byte ptr cs:[0e74h],1h		; cf3
	mov	di,88h		; cf9
	mov	cx,10h		; cfc
	repne	scasb		; cff
	jcxz	short L0D05		; d01
	jmp	short L0D08		; d03
L0D05:
	jmp	near ptr L0E4C		; d05
L0D08:
	mov	al,[di+0fh]		; d08
	mov	byte ptr cs:[0e74h],0h		; d0b
	jmp	short L0D25		; d11
L0D13:
	cmp	al,7ah		; d13
	jnz	short L0D1B		; d15
	mov	al,80h		; d17
	jmp	short L0D25		; d19
L0D1B:
	mov	di,ax		; d1b
	and	di,+7fh		; d1d
	mov	al,cs:[di+1c3h]		; d20
L0D25:
	test	byte ptr cs:[244h],1h		; d25
	jnz	short L0D4A		; d2b
	test	byte ptr cs:[243h],4h		; d2d
	jz	short L0D4D		; d33
	cmp	al,5ah		; d35
	jnz	short L0D4A		; d37
	cmp	byte ptr cs:[0b8h],1h		; d39
	jz	short L0D4A		; d3f
	test	dx,80h		; d41
	jnz	short L0D4A		; d45
	jmp	near ptr L0E4C		; d47
L0D4A:
	or	ah,2h		; d4a
L0D4D:
	test	byte ptr cs:[243h],50h		; d4d
	jz	short L0D58		; d53
	or	ah,4h		; d55
L0D58:
	push	ax		; d58
	mov	ax,DGROUP		; d59
	mov	ds,ax		; d5c
	push	cs		; d5e
	call	near ptr L048E		; d5f
	add	sp,+2h		; d62
	push	cs		; d65
	pop	ds		; d66
	test	byte ptr cs:[241h],10h		; d67
	jnz	short L0D77		; d6d
	test	byte ptr cs:[243h],2h		; d6f
	jz	short L0D7A		; d75
L0D77:
	or	ah,1h		; d77
L0D7A:
	mov	di,ax		; d7a
	and	di,+7fh		; d7c
	shr	di,1		; d7f
	shr	di,1		; d81
	shr	di,1		; d83
	mov	bx,ax		; d85
	and	bx,+7fh		; d87
	and	bl,7h		; d8a
	db	2eh, 8ah, 0afh, 38h, 0h	; d8d: mov ch,[cs:bx+0x38]
	test	word ptr cs:[1bfh],1h		; d92
	jz	short L0DA5		; d99
	test	cs:[di+21ch],ch		; d9b
	jz	short L0DA5		; da0
	xor	ah,1h		; da2
L0DA5:
	test	word ptr cs:[1bfh],2h		; da5
	jz	short L0DB8		; dac
	test	cs:[di+22ch],ch		; dae
	jz	short L0DB8		; db3
	xor	ah,1h		; db5
L0DB8:
	mov	cs:[275h],ah		; db8
	cmp	ax,668h		; dbd
	jz	short L0E3A		; dc0
	cmp	ax,64ch		; dc2
	jz	short L0E3A		; dc5
	cmp	ax,230h		; dc7
	jz	short L0DD1		; dca
	cmp	ax,27eh		; dcc
	jnz	short L0DD8		; dcf
L0DD1:
	mov	word ptr cs:[0ch],1h		; dd1
L0DD8:
	cmp	ax,420h		; dd8
	jnz	short L0DE9		; ddb
	push	ax		; ddd
	mov	ax,ds:[35e2h]		; dde
	xor	ax,1h		; de1
	push	ax		; de4
	add	sp,+2h		; de5
	pop	ax		; de8
L0DE9:
	cmp	ax,434h		; de9
	jnz	short L0DFA		; dec
	push	ax		; dee
	mov	ax,ds:[35e4h]		; def
	xor	ax,1h		; df2
	push	ax		; df5
	add	sp,+2h		; df6
	pop	ax		; df9
L0DFA:
	push	ax		; dfa
	push	cs		; dfb
	call	near ptr _fn_2169_0945		; dfc
	pop	ax		; dff
	cmp	al,6eh		; e00
	jnz	short L0E13		; e02
	cmp	word ptr cs:[86h],+0h		; e04
	jz	short L0E13		; e0a
	push	ax		; e0c
	call	dword ptr cs:[84h]		; e0d
	pop	ax		; e12
L0E13:
	mov	di,26ah		; e13
	mov	cx,0ah		; e16
	repne	scasb		; e19
	or	cx,cx		; e1b
	jnz	short L0E3A		; e1d
	mov	di,40h		; e1f
	mov	cx,22h		; e22
	shr	cx,1		; e25
	repne	scasw		; e27
	jcxz	short L0E34		; e29
	mov	bx,[di+20h]		; e2b
	and	bx,dx		; e2e
	jz	short L0E34		; e30
	jmp	short L0E3A		; e32
L0E34:
	test	dx,4h		; e34
	jz	short L0E4C		; e38
L0E3A:
	pop	si		; e3a
	pop	es		; e3b
	pop	dx		; e3c
	pop	ds		; e3d
	pop	di		; e3e
	pop	cx		; e3f
	pop	bx		; e40
	pop	ax		; e41
	inc	word ptr cs:[25ch]		; e42
	jmp	dword ptr cs:[262h]		; e47
L0E4C:
	in	al,61h		; e4c
	mov	ah,al		; e4e
	or	al,80h		; e50
	out	61h,al		; e52
	xchg	ah,al		; e54
	out	61h,al		; e56
	mov	ax,40h		; e58
	mov	es,ax		; e5b
	mov	al,es:[96h]		; e5d
	and	al,0fdh		; e61
	mov	es:[96h],al		; e63
	mov	al,20h		; e67
	out	20h,al		; e69
	pop	si		; e6b
	pop	es		; e6c
	pop	dx		; e6d
	pop	ds		; e6e
	pop	di		; e6f
	pop	cx		; e70
	pop	bx		; e71
	pop	ax		; e72
	iret		; e73
L0E74	label	byte
	db	0h, 0h, 0h, 0cfh	; e74
_fn_2169_0c35	endp

_fn_2169_0e78	proc	far
	push	ax		; e78
	push	dx		; e79
	push	ds		; e7a
	cmp	dword ptr cs:[266h],+0h		; e7b
	jz	short L0E98		; e82
	lds	dx,cs:[266h]		; e84
	mov	ax,2523h		; e89
	int	21h		; e8c
	mov	dword ptr cs:[266h],0h		; e8e
L0E98:
	cmp	dword ptr cs:[262h],+0h		; e98
	jz	short L0EAB		; e9f
	lds	dx,cs:[262h]		; ea1
	mov	ax,2509h		; ea6
	int	21h		; ea9
L0EAB:
	pop	ds		; eab
	pop	dx		; eac
	pop	ax		; ead
	retf		; eae
_fn_2169_0e78	endp
S127_TEXT	ends
	end
