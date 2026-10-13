; s105: WW library

	.386
	locals
S105_TEXT	segment word public use16 'CODE'
S105_TEXT	ends
	assume	cs:S105_TEXT


S105_TEXT	segment word public use16 'CODE'
	public	_fn_201d_000e

_fn_201d_000e	proc	far
	sub	[bp-3ah],cx
	push	es
	mov	bx,ds
	mov	es,bx
	xchg	si,di
	jcxz	L0020
L001a:	xor	ax,ax
	repne	scasb
	jz	short L0025
L0020:	mov	dx,[bp-54h]
	jmp	short L004e
L0025:	mov	al,es:[di]
	inc	di
	inc	cx
	sub	cx,ax
	jg	short L001a
	jz	short L0020
	add	[bp-3ah],cx
	xor	dx,dx
	mov	ax,cx
	neg	ax
	add	ax,[bp-3ch]
	mul	word ptr [bp-4ah]
	xchg	dl,al
	xchg	al,ah
	sub	ax,[bp-56h]
	add	si,ax
	xor	dh,dh
	mov	cx,ax
	neg	cx
L004e:	mov	ds,bx
	xchg	si,di
	pop	es
	retf
_fn_201d_000e	endp

S105_TEXT	ends
	end
