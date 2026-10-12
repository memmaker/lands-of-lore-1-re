; s091: WW library

	.386
	locals
S091_TEXT	segment word public use16 'CODE'
S091_TEXT	ends
	assume	cs:S091_TEXT


S091_TEXT	segment word public use16 'CODE'
	public	_fn_1faa_0006

_fn_1faa_0006	proc	far
	push	ax
	push	ds
	lds	bx,[bp-20h]
	mov	ah,al
	xlatb
	xchg	ah,al
	or	ah,ah
	js	short L001d
	mov	al,es:[di]
	lds	bx,[bp-24h]
	add	bh,ah
	xlatb
L001d:	pop	ds
	pop	bx
	mov	ah,bh
	mov	es:[di],al
	retf
_fn_1faa_0006	endp

S091_TEXT	ends
	end
