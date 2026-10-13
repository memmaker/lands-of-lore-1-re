; s109: WW library

	.386
	locals
S109_TEXT	segment word public use16 'CODE'
S109_TEXT	ends
	assume	cs:S109_TEXT


S109_TEXT	segment word public use16 'CODE'
	public	_fn_2027_0004

_fn_2027_0004	proc	far
	push	es
	mov	ax,ds
	mov	es,ax
	xchg	si,di
	jcxz	L001e
L000d:	xor	ax,ax
	repne	scasb
	jz	short L0015
	jcxz	L001e
L0015:	mov	al,es:[di]
	inc	di
	inc	cx
	sub	cx,ax
	jg	short L000d
L001e:	mov	ax,es
	mov	ds,ax
	xchg	si,di
	pop	es
	add	di,cx
	retf
_fn_2027_0004	endp

S109_TEXT	ends
	end
