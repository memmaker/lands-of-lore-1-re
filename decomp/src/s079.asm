; s079: WW library

	.386
	locals
S079_TEXT	segment word public use16 'CODE'
S079_TEXT	ends
	assume	cs:S079_TEXT


S079_TEXT	segment word public use16 'CODE'
	public	_fn_1f86_0008

_fn_1f86_0008	proc	far
	push	ds
	mov	[bp-44h],cx
	lds	bx,[bp-14h]
	mov	cx,[bp-42h]
	mov	al,es:[di]
L0015:	xlatb
	loop	L0015
	or	al,al
	jz	short L001f
	mov	es:[di],al
L001f:	mov	cx,[bp-44h]
	pop	ds
	retf
_fn_1f86_0008	endp

S079_TEXT	ends
	end
