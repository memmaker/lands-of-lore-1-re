; s066: WW library -- VGA palette upload with retrace sync (fn_0002) and one fade step (fn_0097) (assembler module; drafted from the original bytes)

	.386
	locals
S066_TEXT	segment word public use16 'CODE'
S066_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S066_TEXT,ds:DGROUP

	extrn	_g_ad97:word

S066_TEXT	segment word public use16 'CODE'
	public	_fn_1ee4_0002, _fn_1ee4_0097

_fn_1ee4_0002	proc	far
	enter	2h,0h
	push	ax
	push	bx
	push	cx
	push	dx
	push	es
	push	di
	push	ds
	push	si
	cld
	mov	bx,_g_ad97
	and	bl,1h
	shl	bl,3h
	push	ds
	pop	es
	mov	di,2fach
	lds	si,[bp+6h]
	mov	word ptr [bp-2h],300h
L_0026:
	mov	cx,[bp-2h]
	repe	cmpsb
	jz	short L_008d
	dec	si
	dec	di
	inc	cx
	xor	dx,dx
	mov	ax,cx
	mov	cx,3h
	div	cx
	or	dx,dx
	jz	short L_0043
	neg	dx
	add	dx,3h
	inc	ax
L_0043:
	mov	cx,ax
	add	cx,ax
	add	cx,ax
	mov	word ptr [bp-2h],0h
	cmp	cx,102h
	jna	short L_005e
	sub	cx,102h
	mov	[bp-2h],cx
	mov	cx,102h
L_005e:
	sub	si,dx
	sub	di,dx
	neg	ax
	add	ax,100h
	mov	dx,3c8h
	out	dx,al
	mov	dx,3dah
L_006e:
	in	al,dx
	and	al,8h
	xor	al,bl
	jz	short L_006e
L_0075:
	in	al,dx
	and	al,8h
	xor	al,bl
	jnz	short L_0075
	mov	dx,3c9h
	pushf
	cli
L_0081:
	lodsb
	stosb
	out	dx,al
	loop	L_0081
	popf
	cmp	word ptr [bp-2h],0h
	jnz	short L_0026
L_008d:
	pop	si
	pop	ds
	pop	di
	pop	es
	pop	dx
	pop	cx
	pop	bx
	pop	ax
	leave
	retf

_fn_1ee4_0002	endp
_fn_1ee4_0097	proc	far
	enter	2h,0h
	push	bx
	push	cx
	push	es
	push	di
	push	si
	les	di,[bp+6h]
	mov	si,di
	mov	ax,[bp+0ah]
	add	di,ax
	add	di,ax
	add	di,ax
	mov	ax,[bp+0ch]
	add	si,ax
	add	si,ax
	add	si,ax
	mov	word ptr [bp-2h],0h
	mov	cx,3h
L_00bf:
	mov	al,es:[si]
	sub	al,es:[di]
	jz	short L_00d7
	mov	word ptr [bp-2h],1h
	inc	byte ptr es:[di]
	jnc	short L_00d7
	dec	byte ptr es:[di]
	dec	byte ptr es:[di]
L_00d7:
	inc	di
	inc	si
	loop	L_00bf
	mov	ax,[bp-2h]
	pop	si
	pop	di
	pop	es
	pop	cx
	pop	bx
	leave
	retf
_fn_1ee4_0097	endp

S066_TEXT	ends
	end
