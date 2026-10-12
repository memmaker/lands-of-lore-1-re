; s100: WW library

	.386
	locals
S100_TEXT	segment word public use16 'CODE'
S100_TEXT	ends
	assume	cs:S100_TEXT


S100_TEXT	segment word public use16 'CODE'
	public	_fn_1fc9_000a

_fn_1fc9_000a	proc	far
	push	ds
	push	ax
	push	ds
	lds	bx,[bp-20h]
	mov	ah,al
	xlatb
	xchg	ah,al
	or	ah,ah
	js	short L0024
	mov	al,es:[di]
	lds	bx,[bp-24h]
	add	bh,ah
	xlatb
	jmp	short L0028
L0024:	pop	ds
	pop	bx
	mov	ah,bh
L0028:	mov	[bp-44h],cx
	lds	bx,[bp-14h]
	mov	cx,[bp-42h]
	mov	al,es:[di]
L0034:	xlatb
	loop	L0034
	mov	cx,[bp-44h]
	or	al,al
	jz	short L0041
	mov	es:[di],al
L0041:	pop	ds
	retf
_fn_1fc9_000a	endp

S100_TEXT	ends
	end
