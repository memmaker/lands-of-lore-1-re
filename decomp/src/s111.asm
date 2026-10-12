; s111: WW library

	.386
	locals
S111_TEXT	segment word public use16 'CODE'
S111_TEXT	ends
	assume	cs:S111_TEXT


S111_TEXT	segment word public use16 'CODE'
	public	_fn_202c_0000

_fn_202c_0000	proc	far
	mov	cx,[bp-3ah]
	or	cx,cx
	jz	short L0024
	push	es
	mov	bx,ds
	mov	es,bx
	xchg	si,di
L000e:	xor	ax,ax
	repne	scasb
	jz	short L0016
	jmp	short L001f
L0016:	mov	al,es:[di]
	inc	di
	inc	cx
	sub	cx,ax
	jg	short L000e
L001f:	mov	ds,bx
	xchg	si,di
	pop	es
L0024:	retf
_fn_202c_0000	endp

S111_TEXT	ends
	end
