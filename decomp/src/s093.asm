; s093: WW library

	.386
	locals
S093_TEXT	segment word public use16 'CODE'
S093_TEXT	ends
	assume	cs:S093_TEXT


S093_TEXT	segment word public use16 'CODE'
	public	_fn_1faf_000a

_fn_1faf_000a	proc	far
	push	ds
	mov	[bp-44h],cx
	lds	bx,[bp-14h]
	mov	cx,[bp-42h]
	mov	al,es:[di]
L0017:	xlatb
	loop	L0017
	push	ax
	push	ds
	lds	bx,[bp-20h]
	mov	ah,al
	xlatb
	xchg	ah,al
	or	ah,ah
	js	short L0031
	mov	al,es:[di]
	lds	bx,[bp-24h]
	add	bh,ah
	xlatb
L0031:	pop	ds
	pop	bx
	mov	ah,bh
	or	al,al
	jz	short L003c
	mov	es:[di],al
L003c:	mov	cx,[bp-44h]
	pop	ds
	retf
_fn_1faf_000a	endp

S093_TEXT	ends
	end
