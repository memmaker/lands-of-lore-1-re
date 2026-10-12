; s104: WW library

	.386
	locals
S104_TEXT	segment word public use16 'CODE'
S104_TEXT	ends
	assume	cs:S104_TEXT


S104_TEXT	segment word public use16 'CODE'
	public	_fn_2019_0008

_fn_2019_0008	proc	far
	sub	[bp-3ah],cx
	push	es
	mov	bx,ds
	mov	es,bx
	xchg	si,di
	jcxz	L001a
L0014:	xor	ax,ax
	repne	scasb
	jz	short L001f
L001a:	mov	dx,[bp-54h]
	jmp	short L0048
L001f:	mov	al,es:[di]
	inc	di
	inc	cx
	sub	cx,ax
	jg	short L0014
	jz	short L001a
	add	[bp-3ah],cx
	xor	dx,dx
	mov	ax,cx
	neg	ax
	add	ax,[bp-3ch]
	mul	word ptr [bp-4ah]
	xchg	dl,al
	xchg	al,ah
	sub	ax,[bp-56h]
	sub	si,ax
	xor	dh,dh
	mov	cx,ax
	neg	cx
L0048:	mov	ds,bx
	xchg	si,di
	pop	es
	retf
_fn_2019_0008	endp

S104_TEXT	ends
	end
