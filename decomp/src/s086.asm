; s086: WW library

	.386
	locals
S086_TEXT	segment word public use16 'CODE'
S086_TEXT	ends
	assume	cs:S086_TEXT


S086_TEXT	segment word public use16 'CODE'
	public	_fn_1f96_000c

_fn_1f96_000c	proc	far
	push	ds
	mov	[bp-44h],cx
	cmp	al,0ffh
	jnz	short L001d
	lds	bx,[bp-28h]
	mov	al,es:[di]
	xlatb
	jmp	short L0029
L001d:	lds	bx,[bp-14h]
	mov	cx,[bp-42h]
	mov	al,es:[di]
L0026:	xlatb
	loop	L0026
L0029:	or	al,al
	jz	short L0030
	mov	es:[di],al
L0030:	mov	cx,[bp-44h]
	pop	ds
	retf
_fn_1f96_000c	endp

S086_TEXT	ends
	end
