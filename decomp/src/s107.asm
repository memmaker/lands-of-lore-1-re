; s107: WW library

	.386
	locals
S107_TEXT	segment word public use16 'CODE'
S107_TEXT	ends
	assume	cs:S107_TEXT


S107_TEXT	segment word public use16 'CODE'
	public	_fn_2023_000a

_fn_2023_000a	proc	far
	push	es
	mov	bx,ds
	mov	es,bx
	xchg	si,di
	jcxz	L0024
L0013:	xor	ax,ax
	repne	scasb
	jz	short L001b
	jcxz	L0024
L001b:	mov	al,es:[di]
	inc	di
	inc	cx
	sub	cx,ax
	jg	short L0013
L0024:	mov	ds,bx
	xchg	si,di
	pop	es
	sub	di,cx
	retf
_fn_2023_000a	endp

S107_TEXT	ends
	end
