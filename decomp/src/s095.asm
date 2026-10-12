; s095: WW library

	.386
	locals
S095_TEXT	segment word public use16 'CODE'
S095_TEXT	ends
	assume	cs:S095_TEXT


S095_TEXT	segment word public use16 'CODE'
	public	_fn_1fb7_000c

_fn_1fb7_000c	proc	far
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
	js	short L0028
	mov	al,es:[di]
	lds	bx,[bp-24h]
	add	bh,ah
	xlatb
L0028:	pop	ds
	pop	bx
	mov	ah,bh
	mov	es:[di],al
	pop	ds
	retf
_fn_1fb7_000c	endp

S095_TEXT	ends
	end
