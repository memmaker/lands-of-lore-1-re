; s081: WW library

	.386
	locals
S081_TEXT	segment word public use16 'CODE'
S081_TEXT	ends
	assume	cs:S081_TEXT


S081_TEXT	segment word public use16 'CODE'
	public	_fn_1f8b_0004

_fn_1f8b_0004	proc	far
	push	ds
	lds	bx,[bp-1ch]
	xlatb
	cmp	al,0ffh
	jnz	short L0014
	lds	bx,[bp-28h]
	mov	al,es:[di]
	xlatb
L0014:	mov	es:[di],al
	pop	ds
	retf
_fn_1f8b_0004	endp

S081_TEXT	ends
	end
