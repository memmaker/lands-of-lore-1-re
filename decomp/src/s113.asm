; s113: WW library

	.386
	locals
S113_TEXT	segment word public use16 'CODE'
S113_TEXT	ends
	assume	cs:S113_TEXT


S113_TEXT	segment word public use16 'CODE'
	public	_fn_2032_000c

_fn_2032_000c	proc	far
	xor	ah,ah
L000e:	or	dh,dh
	js	short L0014
	jnz	short L0021
L0014:	lodsb
	dec	word ptr [bp-3ah]
	or	al,al
	jz	short L002d
	add	dx,[bp-4ah]
	jmp	short L000e
L0021:	push	ax
	call	far ptr [bp-4h]
	pop	ax
	dec	di
	dec	dh
	loop	L000e
	jmp	short L004d
L002d:	xor	ah,ah
	lodsb
	inc	word ptr [bp-3ah]
	sub	[bp-3ah],ax
	mov	bx,dx
	mul	word ptr [bp-4ah]
	add	ax,bx
	xchg	dl,al
	xchg	al,ah
	sub	di,ax
	sub	cx,ax
	xor	ax,ax
	xor	dh,dh
	or	cx,cx
	jg	short L000e
L004d:	mov	cx,0ffffh
	retf
_fn_2032_000c	endp

S113_TEXT	ends
	end
