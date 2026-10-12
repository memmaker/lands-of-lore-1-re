; s110: WW library

	.386
	locals
S110_TEXT	segment word public use16 'CODE'
S110_TEXT	ends
	assume	cs:S110_TEXT


S110_TEXT	segment word public use16 'CODE'
	public	_fn_2029_0008

_fn_2029_0008	proc	far
	mov	cx,[bp-3ah]
	or	cx,cx
	jz	short L002f
	push	es
	mov	bx,ds
	mov	es,bx
	xchg	si,di
L0016:	xor	ax,ax
	repne	scasb
	jz	short L0021
	mov	dx,[bp-54h]
	jmp	short L002a
L0021:	mov	al,es:[di]
	inc	di
	inc	cx
	sub	cx,ax
	jg	short L0016
L002a:	mov	ds,bx
	xchg	si,di
	pop	es
L002f:	retf
_fn_2029_0008	endp

S110_TEXT	ends
	end
