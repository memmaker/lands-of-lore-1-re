; s099: WW library

	.386
	locals
S099_TEXT	segment word public use16 'CODE'
S099_TEXT	ends
	assume	cs:S099_TEXT


S099_TEXT	segment word public use16 'CODE'
	public	_fn_1fc6_0004

_fn_1fc6_0004	proc	far
	push	ds
	push	ax
	push	ds
	lds	bx,[bp-20h]
	mov	ah,al
	xlatb
	xchg	ah,al
	or	ah,ah
	js	short L001e
	mov	al,es:[di]
	lds	bx,[bp-24h]
	add	bh,ah
	xlatb
	jmp	short L0031
L001e:	pop	ds
	pop	bx
	mov	ah,bh
	mov	[bp-44h],cx
	lds	bx,[bp-14h]
	mov	cx,[bp-42h]
L002b:	xlatb
	loop	L002b
	mov	cx,[bp-44h]
L0031:	or	al,al
	jz	short L0038
	mov	es:[di],al
L0038:	pop	ds
	retf
_fn_1fc6_0004	endp

S099_TEXT	ends
	end
