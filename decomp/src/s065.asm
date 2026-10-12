; s065: WW library -- mouse cursor hide/show/conditional hide (int 33h) with the background save/restore (assembler module; drafted from the original bytes)
; FIXUP-ORDER: 6 51

	.386
	locals
S065_TEXT	segment word public use16 'CODE'
S065_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S065_TEXT,ds:DGROUP

	extrn	_g_2f0a:word
	extrn	_g_2f0c:word
	extrn	_g_2f0e:word
	extrn	_g_2f16:word
	extrn	_g_2f20:word
	extrn	_g_2f22:word
	extrn	_g_2f24:word
	extrn	_g_2f26:word
	extrn	_g_2f2c:word
	extrn	_g_2f2e:word
	extrn	_g_2f30:word
	extrn	_g_2f32:word
	extrn	_g_2f34:word
	extrn	_g_2f36:word
	extrn	_g_2f3a:word
	extrn	_g_2f43:word
	extrn	_g_2f56:word
	extrn	_g_2f58:word
	extrn	_g_2f5a:word
	extrn	_g_2f5c:word
	extrn	_g_2f5e:word
	extrn	_g_2f9f:word
	extrn	_g_2fa9:word
	extrn	_fn_1fd6_000a:far
	extrn	_fn_2096_0000:far
	extrn	_fn_2096_014b:far

S065_TEXT	segment word public use16 'CODE'
	public	_fn_1ebc_000c, _fn_1ebc_0053, _fn_1ebc_00e7, _fn_1ebc_00fe, _fn_1ebc_0111, _fn_1ebc_01ec, _fn_1ebc_0211, _fn_1ebc_022a, _fn_1ebc_0245, _fn_1ebc_026e

_fn_1ebc_000c	proc	far
	push	ax
	push	bx
	push	cx
	push	dx
	push	ds
	mov	ax,DGROUP
	mov	ds,ax
	cmp	byte ptr _g_2f43,0h
	jnz	short L_004d
	cmp	word ptr _g_2f16,0h
	jnz	short L_0043
	push	0h
	push	dword ptr _g_2f36
	push	word ptr _g_2f5c
	push	word ptr _g_2f5a
	push	word ptr _g_2f58
	push	word ptr _g_2f56
	call	far ptr _fn_2096_0000
	add	sp,0eh
L_0043:
	add	word ptr _g_2f16,1h
	adc	word ptr _g_2f16,0h
L_004d:
	pop	ds
	pop	dx
	pop	cx
	pop	bx
	pop	ax
	retf

_fn_1ebc_000c	endp
_fn_1ebc_0053	proc	far
	enter	4h,0h
	push	ax
	push	bx
	push	cx
	push	dx
	push	ds
	mov	ax,DGROUP
	mov	ds,ax
	cmp	byte ptr _g_2f43,0h
	jnz	short L_00e0
	cmp	word ptr _g_2f16,0h
	jz	short L_00e0
	dec	word ptr _g_2f16
	cmp	word ptr _g_2f16,0h
	jnz	short L_00e0
	mov	cx,_g_2f22
	mov	dx,_g_2f20
	mov	ax,_g_2f0c
	sub	ax,_g_2f24
	mov	[bp-2h],ax
	jns	short L_0093
	add	cx,ax
	mov	ax,0h
L_0093:
	mov	bx,_g_2f0e
	sub	bx,_g_2f26
	mov	[bp-4h],bx
	jns	short L_00a5
	add	dx,bx
	mov	bx,0h
L_00a5:
	mov	_g_2f56,ax
	mov	_g_2f58,bx
	mov	_g_2f5a,cx
	mov	_g_2f5c,dx
	push	0h
	push	dword ptr _g_2f36
	push	dx
	push	cx
	push	bx
	push	ax
	call	far ptr _fn_2096_014b
	add	sp,0eh
	push	0h
	push	0h
	push	word ptr [bp-4h]
	push	word ptr [bp-2h]
	push	dword ptr _g_2f3a
	push	0h
	call	far ptr _fn_1fd6_000a
	add	sp,0eh
L_00e0:
	pop	ds
	pop	dx
	pop	cx
	pop	bx
	pop	ax
	leave
	retf

_fn_1ebc_0053	endp
_fn_1ebc_00e7	proc	far
	push	es
	push	di
	push	ds
	push	DGROUP
	pop	ds
	inc	word ptr _g_2f0a
	push	cs
	call	near ptr _fn_1ebc_000c
	dec	word ptr _g_2f0a
	pop	ds
	pop	di
	pop	es
	retf

_fn_1ebc_00e7	endp
_fn_1ebc_00fe	proc	far
	push	ds
	push	DGROUP
	pop	ds
	inc	word ptr _g_2f0a
	push	cs
	call	near ptr _fn_1ebc_0053
	dec	word ptr _g_2f0a
	pop	ds
	retf

_fn_1ebc_00fe	endp
_fn_1ebc_0111	proc	far
	enter	0h,0h
	push	ax
	push	bx
	push	cx
	push	dx
	push	es
	push	di
	mov	ax,_g_2f22
	sub	ax,_g_2f24
	neg	ax
	add	ax,[bp+6h]
	jns	short L_012c
	mov	ax,0h
L_012c:
	mov	bx,_g_2f20
	sub	bx,_g_2f26
	neg	bx
	add	bx,[bp+8h]
	jns	short L_013e
	mov	bx,0h
L_013e:
	mov	cx,[bp+0ah]
	add	cx,_g_2f24
	cmp	cx,13fh
	jc	short L_014e
	mov	cx,13fh
L_014e:
	mov	dx,[bp+0ch]
	add	dx,_g_2f26
	cmp	dx,0c7h
	jc	short L_015e
	mov	dx,0c7h
L_015e:
	inc	word ptr _g_2f0a
	cmp	word ptr _g_2f2c,0h
	jnz	short L_0178
	mov	_g_2f2e,ax
	mov	_g_2f30,bx
	mov	_g_2f32,cx
	mov	_g_2f34,dx
L_0178:
	cmp	ax,_g_2f2e
	jc	short L_0181
	mov	_g_2f2e,ax
L_0181:
	cmp	bx,_g_2f30
	jc	short L_018b
	mov	_g_2f30,bx
L_018b:
	cmp	cx,_g_2f32
	ja	short L_0195
	mov	_g_2f32,cx
L_0195:
	cmp	dx,_g_2f34
	ja	short L_019f
	mov	_g_2f34,dx
L_019f:
	test	word ptr _g_2f2c,4000h
	jnz	short L_01d0
	mov	ax,_g_2f0c
	mov	bx,_g_2f0e
	cmp	ax,_g_2f2e
	jc	short L_01d0
	cmp	ax,_g_2f32
	ja	short L_01d0
	cmp	bx,_g_2f30
	jc	short L_01d0
	cmp	bx,_g_2f34
	ja	short L_01d0
	push	cs
	call	near ptr _fn_1ebc_000c
	or	word ptr _g_2f2c,4000h
L_01d0:
	or	word ptr _g_2f2c,8000h
	add	byte ptr _g_2f2c,1h
	adc	byte ptr _g_2f2c,0h
	dec	word ptr _g_2f0a
	pop	di
	pop	es
	pop	dx
	pop	cx
	pop	bx
	pop	ax
	leave
	retf

_fn_1ebc_0111	endp
_fn_1ebc_01ec	proc	far
	push	ax
	inc	word ptr _g_2f0a
	mov	ax,_g_2f2c
	cmp	al,0h
	jz	short L_0208
	dec	al
	jnz	short L_0208
	test	ax,4000h
	jz	short L_0205
	push	cs
	call	near ptr _fn_1ebc_0053
L_0205:
	mov	ax,0h
L_0208:
	mov	_g_2f2c,ax
	dec	word ptr _g_2f0a
	pop	ax
	retf

_fn_1ebc_01ec	endp
_fn_1ebc_0211	proc	far
	push	dx
	push	es
	cmp	byte ptr _g_2f5e,1h
	jnz	short L_0227
	mov	dx,2f85h
	mov	ax,DGROUP
	mov	es,ax
	mov	ax,5301h
	int	33h
L_0227:
	pop	es
	pop	dx
	retf

_fn_1ebc_0211	endp
_fn_1ebc_022a	proc	far
	enter	0h,0h
	cmp	byte ptr _g_2f5e,1h
	jnz	short L_0243
	mov	bh,[bp+6h]
	mov	bl,[bp+8h]
	mov	cl,[bp+0ah]
	mov	ax,5330h
	int	33h
L_0243:
	leave
	retf

_fn_1ebc_022a	endp
_fn_1ebc_0245	proc	far
	push	dx
	push	es
	mov	dx,2f9fh
	mov	ax,DGROUP
	mov	es,ax
	mov	ax,53c1h
	int	33h
	cmp	ax,1h
	jnz	short L_0265
	mov	al,byte ptr _g_2f9f
	cmp	al,1h
	jnz	short L_0265
	mov	ax,1h
	jmp	short L_0268
L_0265:
	mov	ax,0h
L_0268:
	mov	byte ptr _g_2f5e,al
	pop	es
	pop	dx
	retf

_fn_1ebc_0245	endp
_fn_1ebc_026e	proc	far
	mov	ax,0h
	cmp	byte ptr _g_2f5e,1h
	jnz	short L_0280
	mov	ax,53c2h
	int	33h
	mov	_g_2fa9,ax
L_0280:
	retf
_fn_1ebc_026e	endp

S065_TEXT	ends
	end
