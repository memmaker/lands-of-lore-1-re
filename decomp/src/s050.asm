; s050: WW library -- page-to-page rectangle copies (fn_0004 plain, fn_0017 with x in 8-pixel units, fn_0036 transparent colour 0) (assembler module; drafted from the original bytes)

	.386
	locals
S050_TEXT	segment word public use16 'CODE'
S050_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S050_TEXT,ds:DGROUP

	extrn	_fn_215f_001d:far

S050_TEXT	segment word public use16 'CODE'
	public	_fn_1dbc_0004, _fn_1dbc_0017, _fn_1dbc_0036

_fn_1dbc_0004	proc	far
	enter	0ch,0h
	push	ax
	push	bx
	push	cx
	push	dx
	push	ds
	push	si
	push	es
	push	di
	mov	word ptr [bp-6h],0h
	jmp	short L_0047

_fn_1dbc_0004	endp
_fn_1dbc_0017	proc	far
	enter	0ch,0h
	push	ax
	push	bx
	push	cx
	push	dx
	push	ds
	push	si
	push	es
	push	di
	mov	word ptr [bp-6h],0h
	shl	word ptr [bp+6h],3h
	shl	word ptr [bp+0ah],3h
	shl	word ptr [bp+0eh],3h
	jmp	short L_0047

_fn_1dbc_0017	endp
_fn_1dbc_0036	proc	far
	enter	0ch,0h
	push	ax
	push	bx
	push	cx
	push	dx
	push	ds
	push	si
	push	es
	push	di
	mov	word ptr [bp-6h],1h
L_0047:
	pushad
	cld
	mov	word ptr [bp-0ch],140h
	push	word ptr [bp+12h]
	call	far ptr _fn_215f_001d
	add	sp,2h
	mov	[bp-8h],dx
	push	word ptr [bp+14h]
	call	far ptr _fn_215f_001d
	add	sp,2h
	mov	[bp-0ah],dx
	mov	ax,[bp+6h]
	mov	bx,[bp+8h]
	mov	di,[bp+0ah]
	mov	si,[bp+0ch]
	mov	cx,[bp+0eh]
	mov	dx,[bp+10h]
	cmp	ax,140h
	jnl	near ptr L_01f8
	jc	short L_008c
	sub	di,ax
	add	cx,ax
	xor	ax,ax
L_008c:
	cmp	bx,0c8h
	jnl	near ptr L_01f8
	jc	short L_009c
	sub	si,bx
	add	dx,bx
	xor	bx,bx
L_009c:
	cmp	di,140h
	jnl	near ptr L_01f8
	jc	short L_00ac
	sub	ax,di
	add	cx,di
	xor	di,di
L_00ac:
	cmp	si,0c8h
	jnl	near ptr L_01f8
	jc	short L_00bc
	sub	bx,si
	add	dx,si
	xor	si,si
L_00bc:
	push	bx
	mov	bx,140h
	sub	bx,ax
	sub	bx,cx
	jns	short L_00c8
	add	cx,bx
L_00c8:
	pop	bx
	push	ax
	mov	ax,0c8h
	sub	ax,bx
	sub	ax,dx
	jns	short L_00d5
	add	dx,ax
L_00d5:
	pop	ax
	push	ax
	mov	ax,140h
	sub	ax,di
	sub	ax,cx
	jns	short L_00e2
	add	cx,ax
L_00e2:
	pop	ax
	push	ax
	mov	ax,0c8h
	sub	ax,si
	sub	ax,dx
	jns	short L_00ef
	add	dx,ax
L_00ef:
	pop	ax
	cmp	ax,140h
	jnc	near ptr L_01f8
	cmp	di,140h
	jnc	near ptr L_01f8
	cmp	bx,0c8h
	jnc	near ptr L_01f8
	cmp	si,0c8h
	jnc	near ptr L_01f8
	cmp	cx,140h
	ja	near ptr L_01f8
	cmp	dx,0c8h
	ja	near ptr L_01f8
	push	dx
	xchg	ax,bx
	mul	word ptr [bp-0ch]
	add	ax,bx
	push	ax
	mov	ax,si
	mul	word ptr [bp-0ch]
	add	di,ax
	pop	si
	pop	dx
	mov	[bp-2h],cx
	neg	cx
	add	cx,140h
	mov	[bp-4h],cx
	mov	ax,[bp-8h]
	mov	ds,ax
	mov	ax,[bp-0ah]
	mov	es,ax
	mov	ax,es
	mov	bx,ds
	cmp	ax,bx
	jnz	short L_01b1
	cmp	di,si
	jz	near ptr L_01f8
	jc	short L_01b1
	std
	push	dx
	mov	ax,140h
	dec	dx
	mul	dx
	add	ax,[bp-2h]
	dec	ax
	add	si,ax
	add	di,ax
	pop	dx
	mov	bx,[bp-4h]
	neg	bx
	mov	ax,[bp-2h]
	cmp	word ptr [bp-6h],1h
	jz	short L_0198
	or	bx,bx
	jnz	short L_018b
	sub	di,3h
	sub	si,3h
	mul	dx
	mov	cx,ax
	shr	cx,2h
	rep	movsd
	jmp	short L_01f8
L_018b:
	mov	cx,ax
	rep	movsb
	add	di,bx
	add	si,bx
	dec	dx
	jnz	short L_018b
	jmp	short L_01f8
L_0198:
	mov	cx,[bp-2h]
L_019b:
	lodsb
	or	al,al
	jz	short L_01a5
	stosb
	loop	L_019b
	jmp	short L_01a8
L_01a5:
	inc	di
	loop	L_019b
L_01a8:
	add	di,bx
	add	si,bx
	dec	dx
	jnz	short L_0198
	jmp	short L_01f8
L_01b1:
	mov	bx,[bp-4h]
	mov	ax,[bp-2h]
	cmp	word ptr [bp-6h],1h
	jz	short L_01e1
	or	bx,bx
	jnz	short L_01cd
	mul	dx
	mov	cx,ax
	shr	cx,2h
	rep	movsd
	jmp	short L_01f8
L_01cd:
	mov	cx,ax
	shr	cx,1
	rep	movsw
	adc	cx,0h
	rep	movsb
	add	di,bx
	add	si,bx
	dec	dx
	jnz	short L_01cd
	jmp	short L_01f8
L_01e1:
	mov	cx,[bp-2h]
L_01e4:
	lodsb
	or	al,al
	jz	short L_01ee
	stosb
	loop	L_01e4
	jmp	short L_01f1
L_01ee:
	inc	di
	loop	L_01e4
L_01f1:
	add	di,bx
	add	si,bx
	dec	dx
	jnz	short L_01e1
L_01f8:
	cld
	popad
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
_fn_1dbc_0036	endp

S050_TEXT	ends
	end
