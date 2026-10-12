; s085: WW library

	.386
	locals
S085_TEXT	segment word public use16 'CODE'
S085_TEXT	ends
	assume	cs:S085_TEXT


S085_TEXT	segment word public use16 'CODE'
	public	_fn_1f94_0002

_fn_1f94_0002	proc	far
	push	ds
	cmp	al,0ffh
	jnz	short L0013
	lds	bx,[bp-28h]
	mov	al,es:[di]
	xlatb
	mov	es:[di],al
	jmp	short L0029
L0013:	mov	[bp-44h],cx
	lds	bx,[bp-14h]
	mov	cx,[bp-42h]
L001c:	xlatb
	loop	L001c
	or	al,al
	jz	short L0026
	mov	es:[di],al
L0026:	mov	cx,[bp-44h]
L0029:	pop	ds
	retf
_fn_1f94_0002	endp

S085_TEXT	ends
	end
