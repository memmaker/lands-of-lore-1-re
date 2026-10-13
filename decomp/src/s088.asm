; s088: WW library

	.386
	locals
S088_TEXT	segment word public use16 'CODE'
S088_TEXT	ends
	assume	cs:S088_TEXT


S088_TEXT	segment word public use16 'CODE'
	public	_fn_1f9e_0000

_fn_1f9e_0000	proc	far
	push	ds
	lds	bx,[bp-1ch]
	xlatb
	push	ax
	push	ds
	lds	bx,[bp-20h]
	mov	ah,al
	xlatb
	xchg	ah,al
	or	ah,ah
	js	short L001c
	mov	al,es:[di]
	lds	bx,[bp-24h]
	add	bh,ah
	xlatb
L001c:	pop	ds
	pop	bx
	mov	ah,bh
	mov	es:[di],al
	pop	ds
	retf
_fn_1f9e_0000	endp

S088_TEXT	ends
	end
