; s089: WW library

	.386
	locals
S089_TEXT	segment word public use16 'CODE'
S089_TEXT	ends
	assume	cs:S089_TEXT


S089_TEXT	segment word public use16 'CODE'
	public	_fn_1fa0_0006

_fn_1fa0_0006	proc	far
	push	ds
	push	cx
	lds	bx,[bp-1ch]
	xlatb
	lds	bx,[bp-14h]
	mov	cx,[bp-42h]
L0012:	xlatb
	loop	L0012
	push	ax
	push	ds
	lds	bx,[bp-20h]
	mov	ah,al
	xlatb
	xchg	ah,al
	or	ah,ah
	js	short L002c
	mov	al,es:[di]
	lds	bx,[bp-24h]
	add	bh,ah
	xlatb
L002c:	pop	ds
	pop	bx
	mov	ah,bh
	or	al,al
	jz	short L0037
	mov	es:[di],al
L0037:	pop	cx
	pop	ds
	retf
_fn_1fa0_0006	endp

S089_TEXT	ends
	end
