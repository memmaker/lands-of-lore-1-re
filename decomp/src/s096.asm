; s096: WW library

	.386
	locals
S096_TEXT	segment word public use16 'CODE'
S096_TEXT	ends
	assume	cs:S096_TEXT


S096_TEXT	segment word public use16 'CODE'
	public	_fn_1fba_0002

_fn_1fba_0002	proc	far
	push	ds
	push	cx
	lds	bx,[bp-1ch]
	xlatb
	push	ax
	push	ds
	lds	bx,[bp-20h]
	mov	ah,al
	xlatb
	xchg	ah,al
	or	ah,ah
	js	short L0021
	mov	al,es:[di]
	lds	bx,[bp-24h]
	add	bh,ah
	xlatb
	jmp	short L0025
L0021:	pop	ds
	pop	bx
	mov	ah,bh
L0025:	lds	bx,[bp-14h]
	mov	cx,[bp-42h]
L002b:	xlatb
	loop	L002b
	or	al,al
	jz	short L0035
	mov	es:[di],al
L0035:	pop	cx
	pop	ds
	retf
_fn_1fba_0002	endp

S096_TEXT	ends
	end
