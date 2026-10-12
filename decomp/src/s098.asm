; s098: WW library

	.386
	locals
S098_TEXT	segment word public use16 'CODE'
S098_TEXT	ends
	assume	cs:S098_TEXT


S098_TEXT	segment word public use16 'CODE'
	public	_fn_1fc4_0004

_fn_1fc4_0004	proc	far
	push	ax
	push	ds
	lds	bx,[bp-20h]
	mov	ah,al
	xlatb
	xchg	ah,al
	or	ah,ah
	js	short L001b
	mov	al,es:[di]
	lds	bx,[bp-24h]
	add	bh,ah
	xlatb
L001b:	pop	ds
	pop	bx
	mov	ah,bh
	mov	es:[di],al
	retf
_fn_1fc4_0004	endp

S098_TEXT	ends
	end
