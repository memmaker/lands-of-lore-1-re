; s045: 8-bit PCM sample helpers (050c scales a buffer to 100/75/50/25/12 percent volume around 80h; 05bc, 05e1 mix through the clamp tables at 000c-050b; tools/asmgen.py)

	.386
	locals
S045_TEXT	segment byte public use16 'CODE'
S045_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:S045_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends

	extrn	_g_3749:byte

S045_TEXT	segment byte public use16 'CODE'
	public	_fn_1bbe_050c, _fn_1bbe_05bc, _fn_1bbe_05e1
L_000c:
	db	16 dup (0)
	db	16 dup (0)
	db	16 dup (0)
	db	16 dup (0)
	db	16 dup (0)
	db	16 dup (0)
	db	16 dup (0)
	db	16 dup (0)
	db	16 dup (0)
	db	16 dup (0)
	db	16 dup (0)
	db	16 dup (0)
	db	16 dup (0)
	db	16 dup (0)
	db	16 dup (0)
	db	16 dup (0)
	db	16 dup (0)
	db	16 dup (0)
	db	16 dup (0)
	db	16 dup (0)
	db	0, 1, 1, 2, 3, 3, 4, 5, 5, 6, 1, 1, 8, 9, 9, 0ah
	db	0bh, 0bh, 0ch, 0dh, 0dh, 0eh, 0fh, 0fh, 10h, 11h, 11h, 12h, 13h, 13h, 14h, 15h
	db	15h, 16h, 17h, 17h, 18h, 19h, 19h, 1ah, 1bh, 1bh, 1ch, 1dh, 1dh, 1eh, 1fh, 1fh
	db	20h, 21h, 21h, 22h, 23h, 23h, 24h, 25h, 25h, 26h, 27h, 27h, 28h, 29h, 29h, 2ah
	db	2bh, 2bh, 2ch, 2dh, 2dh, 2eh, 2fh, 2fh, 30h, 31h, 31h, 32h, 33h, 33h, 34h, 35h
	db	35h, 36h, 37h, 37h, 38h, 39h, 39h, 3ah, 3bh, 3bh, 3ch, 3dh, 3dh, 3eh, 3fh, 3fh
	db	40h, 41h, 41h, 42h, 43h, 43h, 44h, 45h, 45h, 46h, 47h, 47h, 48h, 49h, 49h, 4ah
	db	4bh, 4bh, 4ch, 4dh, 4dh, 4eh, 4fh, 4fh, 50h, 51h, 51h, 52h, 53h, 53h, 54h, 55h
	db	55h, 56h, 57h, 57h, 58h, 59h, 59h, 5ah, 5bh, 5bh, 5ch, 5dh, 5dh, 5eh, 5fh, 5fh
	db	60h, 61h, 61h, 62h, 63h, 63h, 64h, 65h, 65h, 66h, 67h, 67h, 68h, 69h, 69h, 6ah
	db	6bh, 6bh, 6ch, 6dh, 6dh, 6eh, 6fh, 6fh, 70h, 71h, 71h, 72h, 73h, 73h, 74h, 75h
	db	75h, 76h, 77h, 77h, 78h, 79h, 79h, 7ah, 7bh, 7bh, 7ch, 7dh, 7dh, 7eh, 7fh, 7fh
	db	80h, 81h, 81h, 82h, 83h, 83h, 84h, 85h, 85h, 86h, 87h, 87h, 88h, 89h, 89h, 8ah
	db	8bh, 8bh, 8ch, 8dh, 8dh, 8eh, 8fh, 8fh, 90h, 91h, 91h, 92h, 93h, 93h, 94h, 95h
	db	95h, 96h, 97h, 97h, 98h, 99h, 99h, 9ah, 9bh, 9bh, 9ch, 9dh, 9dh, 9eh, 9fh, 9fh
	db	0a0h, 0a1h, 0a1h, 0a2h, 0a3h, 0a3h, 0a4h, 0a5h, 0a5h, 0a6h, 0a7h, 0a7h, 0a8h, 0a9h, 0a9h, 0aah
	db	0abh, 0abh, 0ach, 0adh, 0adh, 0aeh, 0afh, 0afh, 0b0h, 0b1h, 0b1h, 0b2h, 0b3h, 0b3h, 0b4h, 0b5h
	db	0b5h, 0b6h, 0b7h, 0b7h, 0b8h, 0b9h, 0b9h, 0bah, 0bbh, 0bbh, 0bch, 0bdh, 0bdh, 0beh, 0bfh, 0bfh
	db	0c0h, 0c1h, 0c1h, 0c2h, 0c3h, 0c3h, 0c4h, 0c5h, 0c5h, 0c6h, 0c7h, 0c7h, 0c8h, 0c9h, 0c9h, 0cah
	db	0cbh, 0cbh, 0cch, 0cdh, 0cdh, 0ceh, 0cfh, 0cfh, 0d0h, 0d1h, 0d1h, 0d2h, 0d3h, 0d3h, 0d4h, 0d5h
	db	0d5h, 0d6h, 0d7h, 0d7h, 0d8h, 0d9h, 0d9h, 0dah, 0dbh, 0dbh, 0dch, 0ddh, 0ddh, 0deh, 0dfh, 0dfh
	db	0e0h, 0e1h, 0e1h, 0e2h, 0e3h, 0e3h, 0e4h, 0e5h, 0e5h, 0e6h, 0e7h, 0e7h, 0e8h, 0e9h, 0e9h, 0eah
	db	0ebh, 0ebh, 0ech, 0edh, 0edh, 0eeh, 0efh, 0efh, 0f0h, 0f1h, 0f1h, 0f2h, 0f3h, 0f3h, 0f4h, 0f5h
	db	0f5h, 0f6h, 0f7h, 0f7h, 0f8h, 0f9h, 0f9h, 0fah, 0fbh, 0fbh, 0fch, 0fdh, 0fdh, 0feh, 0ffh, 0ffh
	db	0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh
	db	0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh
	db	0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh
	db	0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh
	db	0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh
	db	0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh
	db	0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh
	db	0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh
	db	0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh
	db	0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh
	db	0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh
	db	0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh
	db	0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh
	db	0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh
	db	0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh
	db	0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh
	db	0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh
	db	0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh
	db	0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh
	db	0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh
	db	0, 0, 1, 1, 3, 3, 4, 4, 6, 6, 7, 7, 9, 9, 0ah, 0ah
	db	0ch, 0ch, 0dh, 0dh, 0fh, 0fh, 10h, 10h, 12h, 12h, 13h, 13h, 15h, 15h, 16h, 16h
	db	18h, 18h, 19h, 19h, 1bh, 1bh, 1ch, 1ch, 1eh, 1eh, 1fh, 1fh, 21h, 21h, 22h, 22h
	db	24h, 24h, 25h, 25h, 27h, 27h, 28h, 28h, 2ah, 2ah, 2bh, 2bh, 2dh, 2dh, 2eh, 2eh
	db	30h, 30h, 31h, 31h, 33h, 33h, 34h, 34h, 36h, 36h, 37h, 37h, 39h, 39h, 3ah, 3ah
	db	3ch, 3ch, 3dh, 3dh, 3fh, 3fh, 40h, 40h, 42h, 42h, 43h, 43h, 45h, 45h, 46h, 46h
	db	48h, 48h, 49h, 49h, 4bh, 4bh, 4ch, 4ch, 4eh, 4eh, 4fh, 4fh, 51h, 51h, 52h, 52h
	db	54h, 54h, 55h, 55h, 57h, 57h, 58h, 58h, 5ah, 5ah, 5bh, 5bh, 5dh, 5dh, 5eh, 5eh
	db	0a2h, 0a2h, 0a3h, 0a3h, 0a5h, 0a5h, 0a6h, 0a6h, 0a8h, 0a8h, 0a9h, 0a9h, 0abh, 0abh, 0ach, 0ach
	db	0aeh, 0aeh, 0afh, 0afh, 0b1h, 0b1h, 0b2h, 0b2h, 0b4h, 0b4h, 0b5h, 0b5h, 0b7h, 0b7h, 0b8h, 0b8h
	db	0bah, 0bah, 0bbh, 0bbh, 0bdh, 0bdh, 0beh, 0beh, 0c0h, 0c0h, 0c1h, 0c1h, 0c3h, 0c3h, 0c4h, 0c4h
	db	0c6h, 0c6h, 0c7h, 0c7h, 0c9h, 0c9h, 0cah, 0cah, 0cch, 0cch, 0cdh, 0cdh, 0cfh, 0cfh, 0d0h, 0d0h
	db	0d2h, 0d2h, 0d3h, 0d3h, 0d5h, 0d5h, 0d6h, 0d6h, 0d8h, 0d8h, 0d9h, 0d9h, 0dbh, 0dbh, 0dch, 0dch
	db	0deh, 0deh, 0dfh, 0dfh, 0e1h, 0e1h, 0e2h, 0e2h, 0e4h, 0e4h, 0e5h, 0e5h, 0e7h, 0e7h, 0e8h, 0e8h
	db	0eah, 0eah, 0ebh, 0ebh, 0edh, 0edh, 0eeh, 0eeh, 0f0h, 0f0h, 0f1h, 0f1h, 0f3h, 0f3h, 0f4h, 0f4h
	db	0f6h, 0f6h, 0f7h, 0f7h, 0f9h, 0f9h, 0fah, 0fah, 0fch, 0fch, 0fdh, 0fdh, 0ffh, 0ffh, 0, 0
_fn_1bbe_050c	proc	far
	enter	0,0
	push	bx
	push	cx
	push	dx
	push	es
	push	di
	mov	cx,[bp+0ah]
	mov	dx,[bp+0ch]
	les	di,dword ptr [bp+6]
	cmp	dx,64h
	jz	near ptr L_05b5
	cmp	dx,4bh
	jz	short L_05a3
	cmp	dx,32h
	jz	short L_0586
	cmp	dx,19h
	jz	short L_0565
	cmp	dx,0ch
	jz	short L_0540
	mov	al,80h
L_053b:
	stosb
	loop	short L_053b
	jmp	short L_05b5
L_0540:
	mov	al,es:[di]
	xor	al,80h
	jns	short L_0558
	neg	al
	sar	al,1
	sar	al,1
	sar	al,1
	neg	al
	xor	al,80h
	stosb
	loop	short L_0540
	jmp	short L_05b5
L_0558:
	sar	al,1
	sar	al,1
	sar	al,1
	xor	al,80h
	stosb
	loop	short L_0540
	jmp	short L_05b5
L_0565:
	mov	al,es:[di]
	xor	al,80h
	jns	short L_057b
	neg	al
	sar	al,1
	sar	al,1
	neg	al
	xor	al,80h
	stosb
	loop	short L_0565
	jmp	short L_05b5
L_057b:
	sar	al,1
	sar	al,1
	xor	al,80h
	stosb
	loop	short L_0565
	jmp	short L_05b5
L_0586:
	mov	al,es:[di]
	xor	al,80h
	jns	short L_059a
	neg	al
	sar	al,1
	neg	al
	xor	al,80h
	stosb
	loop	short L_0586
	jmp	short L_05b5
L_059a:
	sar	al,1
	xor	al,80h
	stosb
	loop	short L_0586
	jmp	short L_05b5
L_05a3:
	mov	bx,40ch
	push	ds
	push	cs
	pop	ds
L_05a9:
	mov	al,es:[di]
	xor	al,80h
	xlatb
	xor	al,80h
	stosb
	loop	short L_05a9
	pop	ds
L_05b5:
	pop	di
	pop	es
	pop	dx
	pop	cx
	pop	bx
	leave
	retf
_fn_1bbe_050c	endp

_fn_1bbe_05bc	proc	far
	enter	0,0
	push	bx
	push	cx
	push	dx
	push	es
	push	di
	cmp	word ptr _g_3749,4
	jnz	short L_05da
	mov	cx,[bp+0ah]
	les	di,dword ptr [bp+6]
L_05d2:
	mov	al,es:[di]
	sub	al,80h
	stosb
	loop	short L_05d2
L_05da:
	pop	di
	pop	es
	pop	dx
	pop	cx
	pop	bx
	leave
	retf
_fn_1bbe_05bc	endp

_fn_1bbe_05e1	proc	far
	enter	2,0
	push	bx
	push	cx
	push	dx
	push	di
	push	ds
	push	es
	push	si
	mov	dx,[bp+0eh]
	mov	cx,dx
	mov	ax,dx
	shl	ax,1
	add	ax,dx
	dec	ax
	mov	[bp-2],ax
	xor	ah,ah
	cmp	word ptr _g_3749,4
	jz	short L_062d
	lds	si,dword ptr [bp+6]
	les	di,dword ptr [bp+0ah]
L_060a:
	xor	bh,bh
	mov	bl,[si]
	add	si,dx
	mov	al,[si]
	add	bx,ax
	add	si,dx
	mov	al,[si]
	add	bx,ax
	add	si,dx
	mov	al,[si]
	add	bx,ax
	mov	al,byte ptr cs:L_000c[bx]
	stosb
	sub	si,[bp-2]
	loop	short L_060a
	jmp	short L_0656
L_062d:
	lds	si,dword ptr [bp+6]
	les	di,dword ptr [bp+0ah]
L_0633:
	xor	bh,bh
	mov	bl,[si]
	add	si,dx
	mov	al,[si]
	add	bx,ax
	add	si,dx
	mov	al,[si]
	add	bx,ax
	add	si,dx
	mov	al,[si]
	add	bx,ax
	mov	al,byte ptr cs:L_000c[bx]
	sub	al,80h
	stosb
	sub	si,[bp-2]
	loop	short L_0633
L_0656:
	pop	si
	pop	es
	pop	ds
	pop	di
	pop	dx
	pop	cx
	pop	bx
	leave
	retf
_fn_1bbe_05e1	endp
S045_TEXT	ends
	end
