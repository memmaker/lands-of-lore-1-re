; s069: WW library -- colour remapping (fn_0000 shape header palette, fn_003f a page rectangle through a table) (assembler module; drafted from the original bytes)

	.386
	locals
S069_TEXT	segment word public use16 'CODE'
S069_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S069_TEXT,ds:DGROUP

	extrn	_fn_215f_0003:far

S069_TEXT	segment word public use16 'CODE'
	public	_fn_1f24_0000, _fn_1f24_003f

_fn_1f24_0000	proc	far
	enter	0h,0h
	push	ax
	push	bx
	push	cx
	push	dx
	push	ds
	push	si
	push	es
	push	di
	cmp	dword ptr [bp+6h],0h
	jz	short L_002f
	les	di,[bp+6h]
	lds	si,[bp+0ah]
	mov	al,es:[di]
	test	al,1h
	jz	short L_002f
	add	di,0ah
	mov	bx,si
	mov	cx,10h
L_0028:
	mov	al,es:[di]
	xlatb
	stosb
	loop	L_0028
L_002f:
	mov	dx,[bp+8h]
	mov	ax,[bp+6h]
	pop	di
	pop	es
	pop	si
	pop	ds
	pop	dx
	pop	cx
	pop	bx
	pop	ax
	leave
	retf

_fn_1f24_0000	endp
_fn_1f24_003f	proc	far
	enter	0h,0h
	push	ax
	push	bx
	push	cx
	push	dx
	push	ds
	push	si
	push	es
	push	di
	cld
	push	word ptr [bp+0eh]
	call	far ptr _fn_215f_0003
	add	sp,2h
	mov	es,dx
	mov	di,ax
	mov	ax,140h
	mul	word ptr [bp+8h]
	add	di,ax
	add	di,[bp+6h]
	cmp	word ptr [bp+12h],0h
	jz	short L_0088
	lds	si,[bp+10h]
	mov	bx,si
	mov	dx,[bp+0ch]
L_0074:
	mov	cx,[bp+0ah]
L_0077:
	mov	al,es:[di]
	xlatb
	stosb
	loop	L_0077
	add	di,140h
	sub	di,[bp+0ah]
	dec	dx
	jnz	short L_0074
L_0088:
	pop	di
	pop	es
	pop	si
	pop	ds
	pop	dx
	pop	cx
	pop	bx
	pop	ax
	leave
	retf
_fn_1f24_003f	endp

S069_TEXT	ends
	end
