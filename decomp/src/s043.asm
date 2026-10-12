; s043: segment 1b63 (TASM module)
	.386
S043_TEXT	segment word public use16 'CODE'
S043_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:S043_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	extrn	_fn_215f_001d:far
S043_TEXT	segment
	public	_fn_1b63_0004, _fn_1b63_00e2
_fn_1b63_0004	proc	far
	enter	2h,0h		; 4
	push	ax		; 8
	push	bx		; 9
	push	cx		; a
	push	dx		; b
	push	ds		; c
	push	es		; d
	push	di		; e
	push	si		; f
	push	word ptr ds:[3649h]		; 10
	call	far ptr _fn_215f_001d		; 14
	add	sp,+2h		; 19
	mov	es,dx		; 1c
	mov	di,[bp+6h]		; 1e
	mov	cx,[bp+0ah]		; 21
	cmp	cx,+0h		; 24
	jng	short L0035		; 27
	cmp	di,140h		; 29
	jnl	short L0035		; 2d
	or	di,di		; 2f
	jns	short L0044		; 31
	jmp	short L0038		; 33
L0035:
	jmp	near ptr L00D8		; 35
L0038:
	add	di,cx		; 38
	cmp	di,+0h		; 3a
	jng	short L0035		; 3d
	mov	cx,di		; 3f
	mov	di,0h		; 41
L0044:
	mov	bx,cx		; 44
	add	bx,di		; 46
	cmp	bx,140h		; 48
	jl	short L0053		; 4c
	mov	cx,140h		; 4e
	sub	cx,di		; 51
L0053:
	mov	word ptr [bp-2h],140h		; 53
	sub	[bp-2h],cx		; 58
	mov	bx,[bp+8h]		; 5b
	mov	si,[bp+0ch]		; 5e
	cmp	si,+0h		; 61
	jng	short L00D8		; 64
	cmp	bx,140h		; 66
	jnl	short L00D8		; 6a
	or	bx,bx		; 6c
	jns	short L007C		; 6e
	add	bx,si		; 70
	cmp	bx,+0h		; 72
	jng	short L00D8		; 75
	mov	si,bx		; 77
	mov	bx,0h		; 79
L007C:
	mov	ax,si		; 7c
	add	ax,bx		; 7e
	cmp	ax,0c8h		; 80
	jl	short L008A		; 83
	mov	si,0c8h		; 85
	sub	si,bx		; 88
L008A:
	mov	dx,bx		; 8a
	add	dx,di		; 8c
	and	dx,+1h		; 8e
	push	si		; 91
	shl	bx,1		; 92
	lds	si,ds:[3940h]		; 94
	mov	ax,[bx+si]		; 98
	add	di,ax		; 9a
	pop	si		; 9c
	mov	ax,[bp+0eh]		; 9d
	mov	bx,dx		; a0
	mov	dh,cl		; a2
	and	dh,1h		; a4
	shr	cx,1		; a7
	mov	[bp+0ah],cx		; a9
L00AC:
	cmp	cx,+0h		; ac
	jnz	short L00B6		; af
	mov	cx,1h		; b1
	jmp	short L00BE		; b4
L00B6:
	mov	es:[bx+di],al		; b6
	add	di,+2h		; b9
	loop	short L00B6		; bc
L00BE:
	cmp	dh,1h		; be
	jnz	short L00CC		; c1
	cmp	bl,0h		; c3
	jnz	short L00CB		; c6
	stosb		; c8
	jmp	short L00CC		; c9
L00CB:
	inc	di		; cb
L00CC:
	xor	bx,+1h		; cc
	add	di,[bp-2h]		; cf
	mov	cx,[bp+0ah]		; d2
	dec	si		; d5
	jnz	short L00AC		; d6
L00D8:
	pop	si		; d8
	pop	di		; d9
	pop	es		; da
	pop	ds		; db
	pop	dx		; dc
	pop	cx		; dd
	pop	bx		; de
	pop	ax		; df
	leave		; e0
	retf		; e1
_fn_1b63_0004	endp

_fn_1b63_00e2	proc	far
	enter	0ah,0h		; e2
	push	ax		; e6
	push	bx		; e7
	push	cx		; e8
	push	dx		; e9
	push	ds		; ea
	push	si		; eb
	push	es		; ec
	push	di		; ed
	push	word ptr [bp+14h]		; ee
	call	far ptr _fn_215f_001d		; f1
	add	sp,+2h		; f6
	mov	[bp-0ah],dx		; f9
	push	word ptr [bp+12h]		; fc
	call	far ptr _fn_215f_001d		; ff
	add	sp,+2h		; 104
	mov	[bp-8h],dx		; 107
	mov	si,[bp+6h]		; 10a
	mov	ax,[bp+8h]		; 10d
	mov	dx,140h		; 110
	mul	dx		; 113
	add	si,ax		; 115
	mov	di,[bp+0ah]		; 117
	mov	ax,[bp+0ch]		; 11a
	mov	dx,140h		; 11d
	mul	dx		; 120
	add	di,ax		; 122
	les	bx,[bp+16h]		; 124
	mov	[bp-6h],es		; 127
	mov	es,[bp-0ah]		; 12a
	mov	dx,[bp+10h]		; 12d
L0130:
	mov	[bp-2h],si		; 130
	mov	[bp-4h],di		; 133
	mov	cx,[bp+0eh]		; 136
L0139:
	mov	ds,[bp-8h]		; 139
	lodsb		; 13c
	mov	ds,[bp-6h]		; 13d
	xlatb		; 140
	stosb		; 141
	loop	short L0139		; 142
	mov	si,[bp-2h]		; 144
	add	si,140h		; 147
	mov	di,[bp-4h]		; 14b
	add	di,140h		; 14e
	dec	dx		; 152
	jnz	short L0130		; 153
	pop	di		; 155
	pop	es		; 156
	pop	si		; 157
	pop	ds		; 158
	pop	dx		; 159
	pop	cx		; 15a
	pop	bx		; 15b
	pop	ax		; 15c
	leave		; 15d
	retf		; 15e
_fn_1b63_00e2	endp
S043_TEXT	ends
	end
