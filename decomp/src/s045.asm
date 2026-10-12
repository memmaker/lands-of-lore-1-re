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
	public	_fn_1bbe_050c, _fn_1bbe_05bc, _fn_1bbe_05e1
L000C	label	byte
	db	321 dup (0h)	; c
	db	1h, 1h, 2h, 3h, 3h, 4h, 5h, 5h, 6h, 1h, 1h, 8h, 9h, 9h, 0ah, 0bh	; 14d
	db	0bh, 0ch, 0dh, 0dh, 0eh, 0fh, 0fh, 10h, 11h, 11h, 12h, 13h, 13h, 14h, 15h, 15h	; 15d
	db	16h, 17h, 17h, 18h, 19h, 19h, 1ah, 1bh, 1bh, 1ch, 1dh, 1dh, 1eh, 1fh, 1fh, 20h	; 16d
	db	21h, 21h, 22h, 23h, 23h, 24h, 25h, 25h, 26h, 27h, 27h, 28h, 29h, 29h, 2ah, 2bh	; 17d
	db	2bh, 2ch, 2dh, 2dh, 2eh, 2fh, 2fh, 30h, 31h, 31h, 32h, 33h, 33h, 34h, 35h, 35h	; 18d
	db	36h, 37h, 37h, 38h, 39h, 39h, 3ah, 3bh, 3bh, 3ch, 3dh, 3dh, 3eh, 3fh, 3fh, 40h	; 19d
	db	41h, 41h, 42h, 43h, 43h, 44h, 45h, 45h, 46h, 47h, 47h, 48h, 49h, 49h, 4ah, 4bh	; 1ad
	db	4bh, 4ch, 4dh, 4dh, 4eh, 4fh, 4fh, 50h, 51h, 51h, 52h, 53h, 53h, 54h, 55h, 55h	; 1bd
	db	56h, 57h, 57h, 58h, 59h, 59h, 5ah, 5bh, 5bh, 5ch, 5dh, 5dh, 5eh, 5fh, 5fh, 60h	; 1cd
	db	61h, 61h, 62h, 63h, 63h, 64h, 65h, 65h, 66h, 67h, 67h, 68h, 69h, 69h, 6ah, 6bh	; 1dd
	db	6bh, 6ch, 6dh, 6dh, 6eh, 6fh, 6fh, 70h, 71h, 71h, 72h, 73h, 73h, 74h, 75h, 75h	; 1ed
	db	76h, 77h, 77h, 78h, 79h, 79h, 7ah, 7bh, 7bh, 7ch, 7dh, 7dh, 7eh, 7fh, 7fh, 80h	; 1fd
	db	81h, 81h, 82h, 83h, 83h, 84h, 85h, 85h, 86h, 87h, 87h, 88h, 89h, 89h, 8ah, 8bh	; 20d
	db	8bh, 8ch, 8dh, 8dh, 8eh, 8fh, 8fh, 90h, 91h, 91h, 92h, 93h, 93h, 94h, 95h, 95h	; 21d
	db	96h, 97h, 97h, 98h, 99h, 99h, 9ah, 9bh, 9bh, 9ch, 9dh, 9dh, 9eh, 9fh, 9fh, 0a0h	; 22d
	db	0a1h, 0a1h, 0a2h, 0a3h, 0a3h, 0a4h, 0a5h, 0a5h, 0a6h, 0a7h, 0a7h, 0a8h, 0a9h, 0a9h, 0aah, 0abh	; 23d
	db	0abh, 0ach, 0adh, 0adh, 0aeh, 0afh, 0afh, 0b0h, 0b1h, 0b1h, 0b2h, 0b3h, 0b3h, 0b4h, 0b5h, 0b5h	; 24d
	db	0b6h, 0b7h, 0b7h, 0b8h, 0b9h, 0b9h, 0bah, 0bbh, 0bbh, 0bch, 0bdh, 0bdh, 0beh, 0bfh, 0bfh, 0c0h	; 25d
	db	0c1h, 0c1h, 0c2h, 0c3h, 0c3h, 0c4h, 0c5h, 0c5h, 0c6h, 0c7h, 0c7h, 0c8h, 0c9h, 0c9h, 0cah, 0cbh	; 26d
	db	0cbh, 0cch, 0cdh, 0cdh, 0ceh, 0cfh, 0cfh, 0d0h, 0d1h, 0d1h, 0d2h, 0d3h, 0d3h, 0d4h, 0d5h, 0d5h	; 27d
	db	0d6h, 0d7h, 0d7h, 0d8h, 0d9h, 0d9h, 0dah, 0dbh, 0dbh, 0dch, 0ddh, 0ddh, 0deh, 0dfh, 0dfh, 0e0h	; 28d
	db	0e1h, 0e1h, 0e2h, 0e3h, 0e3h, 0e4h, 0e5h, 0e5h, 0e6h, 0e7h, 0e7h, 0e8h, 0e9h, 0e9h, 0eah, 0ebh	; 29d
	db	0ebh, 0ech, 0edh, 0edh, 0eeh, 0efh, 0efh, 0f0h, 0f1h, 0f1h, 0f2h, 0f3h, 0f3h, 0f4h, 0f5h, 0f5h	; 2ad
	db	0f6h, 0f7h, 0f7h, 0f8h, 0f9h, 0f9h, 0fah, 0fbh, 0fbh, 0fch, 0fdh, 0fdh, 0feh	; 2bd
	db	322 dup (0ffh)	; 2ca
	db	0h, 0h, 1h, 1h, 3h, 3h, 4h, 4h, 6h, 6h, 7h, 7h, 9h, 9h, 0ah, 0ah	; 40c
	db	0ch, 0ch, 0dh, 0dh, 0fh, 0fh, 10h, 10h, 12h, 12h, 13h, 13h, 15h, 15h, 16h, 16h	; 41c
	db	18h, 18h, 19h, 19h, 1bh, 1bh, 1ch, 1ch, 1eh, 1eh, 1fh, 1fh, 21h, 21h, 22h, 22h	; 42c
	db	24h, 24h, 25h, 25h, 27h, 27h, 28h, 28h, 2ah, 2ah, 2bh, 2bh, 2dh, 2dh, 2eh, 2eh	; 43c
	db	30h, 30h, 31h, 31h, 33h, 33h, 34h, 34h, 36h, 36h, 37h, 37h, 39h, 39h, 3ah, 3ah	; 44c
	db	3ch, 3ch, 3dh, 3dh, 3fh, 3fh, 40h, 40h, 42h, 42h, 43h, 43h, 45h, 45h, 46h, 46h	; 45c
	db	48h, 48h, 49h, 49h, 4bh, 4bh, 4ch, 4ch, 4eh, 4eh, 4fh, 4fh, 51h, 51h, 52h, 52h	; 46c
	db	54h, 54h, 55h, 55h, 57h, 57h, 58h, 58h, 5ah, 5ah, 5bh, 5bh, 5dh, 5dh, 5eh, 5eh	; 47c
	db	0a2h, 0a2h, 0a3h, 0a3h, 0a5h, 0a5h, 0a6h, 0a6h, 0a8h, 0a8h, 0a9h, 0a9h, 0abh, 0abh, 0ach, 0ach	; 48c
	db	0aeh, 0aeh, 0afh, 0afh, 0b1h, 0b1h, 0b2h, 0b2h, 0b4h, 0b4h, 0b5h, 0b5h, 0b7h, 0b7h, 0b8h, 0b8h	; 49c
	db	0bah, 0bah, 0bbh, 0bbh, 0bdh, 0bdh, 0beh, 0beh, 0c0h, 0c0h, 0c1h, 0c1h, 0c3h, 0c3h, 0c4h, 0c4h	; 4ac
	db	0c6h, 0c6h, 0c7h, 0c7h, 0c9h, 0c9h, 0cah, 0cah, 0cch, 0cch, 0cdh, 0cdh, 0cfh, 0cfh, 0d0h, 0d0h	; 4bc
	db	0d2h, 0d2h, 0d3h, 0d3h, 0d5h, 0d5h, 0d6h, 0d6h, 0d8h, 0d8h, 0d9h, 0d9h, 0dbh, 0dbh, 0dch, 0dch	; 4cc
	db	0deh, 0deh, 0dfh, 0dfh, 0e1h, 0e1h, 0e2h, 0e2h, 0e4h, 0e4h, 0e5h, 0e5h, 0e7h, 0e7h, 0e8h, 0e8h	; 4dc
	db	0eah, 0eah, 0ebh, 0ebh, 0edh, 0edh, 0eeh, 0eeh, 0f0h, 0f0h, 0f1h, 0f1h, 0f3h, 0f3h, 0f4h, 0f4h	; 4ec
	db	0f6h, 0f6h, 0f7h, 0f7h, 0f9h, 0f9h, 0fah, 0fah, 0fch, 0fch, 0fdh, 0fdh, 0ffh, 0ffh, 0h, 0h	; 4fc
_fn_1bbe_050c	proc	far
	enter	0h,0h		; 50c
	push	bx		; 510
	push	cx		; 511
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
_fn_1bbe_050c	endp

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
	jz	short L062D		; 602
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
	mov	al,cs:L000C[bx]		; 620
	stosb		; 625
	sub	si,[bp-2h]		; 626
	loop	short L060A		; 629
	jmp	short L0656		; 62b
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
	mov	al,cs:L000C[bx]		; 649
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
