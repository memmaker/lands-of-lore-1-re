; s092: WW library

	.386
	locals
S092_TEXT	segment word public use16 'CODE'
S092_TEXT	ends
	assume	cs:S092_TEXT


S092_TEXT	segment word public use16 'CODE'
	public	_fn_1fac_0006

_fn_1fac_0006	proc	far
	push	ds
	mov	[bp-44h],cx
	lds	bx,[bp-14h]
	mov	cx,[bp-42h]
L0010:	xlatb
	loop	L0010
	push	ax
	push	ds
	lds	bx,[bp-20h]
	mov	ah,al
	xlatb
	xchg	ah,al
	or	ah,ah
	js	short L002a
	mov	al,es:[di]
	lds	bx,[bp-24h]
	add	bh,ah
	xlatb
L002a:	pop	ds
	pop	bx
	mov	ah,bh
	or	al,al
	jz	short L0035
	mov	es:[di],al
L0035:	mov	cx,[bp-44h]
	pop	ds
	retf
_fn_1fac_0006	endp

S092_TEXT	ends
	end
