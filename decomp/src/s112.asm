; s112: WW library

	.386
	locals
S112_TEXT	segment word public use16 'CODE'
S112_TEXT	ends
	assume	cs:S112_TEXT


S112_TEXT	segment word public use16 'CODE'
	public	_fn_202e_0006

_fn_202e_0006	proc	far
	xor	ah,ah
L0008:	or	dh,dh
	js	short L000e
	jnz	short L001b
L000e:	lodsb
	dec	word ptr [bp-3ah]
	or	al,al
	jz	short L0027
	add	dx,[bp-4ah]
	jmp	short L0008
L001b:	push	ax
	call	dword ptr [bp-4h]
	pop	ax
	inc	di
	dec	dh
	loop	L0008
	jmp	short L0047
L0027:	xor	ah,ah
	lodsb
	inc	word ptr [bp-3ah]
	sub	[bp-3ah],ax
	mov	bx,dx
	mul	word ptr [bp-4ah]
	add	ax,bx
	xchg	dl,al
	xchg	al,ah
	add	di,ax
	sub	cx,ax
	xor	ax,ax
	xor	dh,dh
	or	cx,cx
	jg	short L0008
L0047:	mov	cx,0ffffh
	retf
_fn_202e_0006	endp

S112_TEXT	ends
	end
