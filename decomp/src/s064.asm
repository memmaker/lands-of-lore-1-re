; s064: WW library -- mouse cursor shape setup (assembler module; drafted from the original bytes)

	.386
	locals
S064_TEXT	segment word public use16 'CODE'
S064_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S064_TEXT,ds:DGROUP

	extrn	_g_2f02:word
	extrn	_g_2f04:word
	extrn	_g_2f06:word
	extrn	_g_2f0a:word
	extrn	_g_2f20:word
	extrn	_g_2f22:word
	extrn	_g_2f24:word
	extrn	_g_2f26:word
	extrn	_g_2f36:word
	extrn	_g_2f38:word
	extrn	_g_2f3a:word
	extrn	_g_2f3c:word
	extrn	_g_2f43:word
	extrn	_g_35ac:word
	extrn	_g_363e:word
	extrn	_fn_1ebc_000c:far
	extrn	_fn_1ebc_0053:far
	extrn	_fn_1f36_0029:far
	extrn	_fn_1f36_01e2:far
	extrn	_fn_1f36_026a:far
	extrn	_fn_1f36_0300:far
	extrn	_fn_1f6a_0002:far
	extrn	_fn_203b_0007:far
	extrn	_fn_203b_0203:far
	extrn	_fn_226d_0007:far
	extrn	_fn_226d_004e:far
	extrn	_fn_232c_000c:far

S064_TEXT	segment word public use16 'CODE'
	public	_fn_1e9f_0002

_fn_1e9f_0002	proc	far
	enter	12h,0h
	push	bx
	push	cx
	push	ds
	push	si
	push	es
	push	di
	cld
	cmp	dword ptr [bp+0ah],0h
	jz	near ptr L_01b4
	cmp	byte ptr _g_2f43,0h
	jnz	near ptr L_01b4
	inc	word ptr _g_2f0a
	push	0h
	push	dword ptr [bp+0ah]
	call	far ptr _fn_226d_0007
	add	sp,6h
	mov	[bp-4h],ax
	mov	[bp-2h],dx
	call	far ptr _fn_1ebc_000c
	push	dword ptr [bp-4h]
	call	far ptr _fn_1f36_0029
	add	sp,4h
	mov	[bp-12h],ax
	push	dword ptr [bp-4h]
	call	far ptr _fn_1f36_0300
	add	sp,4h
	mov	[bp-0ah],ax
	push	dword ptr [bp-4h]
	call	far ptr _fn_1f36_01e2
	add	sp,4h
	mov	[bp-0eh],ax
	push	dword ptr [bp-4h]
	call	far ptr _fn_1f36_026a
	add	sp,4h
	mov	[bp-10h],ax
	push	word ptr [bp-10h]
	push	word ptr [bp-0eh]
	call	far ptr _fn_1f6a_0002
	add	sp,4h
	mov	bx,ax
	cmp	_g_2f02,bx
	jnl	short L_00e0
	push	bx
	push	dword ptr _g_2f36
	call	far ptr _fn_203b_0203
	add	sp,4h
	mov	dword ptr _g_2f36,0h
	mov	word ptr _g_2f02,0h
	pop	bx
	push	bx
	push	dword ptr _g_363e
	mov	dword ptr _g_363e,0h
	push	0h
	push	0h
	push	bx
	call	far ptr _fn_203b_0007
	add	sp,6h
	pop	dword ptr _g_363e
	pop	bx
	mov	_g_2f38,dx
	mov	_g_2f36,ax
	cmp	dx,0h
	jz	near ptr L_01af
	mov	_g_2f02,bx
L_00e0:
	mov	bx,[bp-0ah]
	add	bx,20h
	cmp	bx,[bp-12h]
	jnc	short L_00ee
	mov	bx,[bp-12h]
L_00ee:
	cmp	_g_2f04,bx
	jnl	short L_0143
	push	bx
	push	dword ptr _g_2f3a
	call	far ptr _fn_203b_0203
	add	sp,4h
	mov	dword ptr _g_2f3a,0h
	mov	word ptr _g_2f04,0h
	pop	bx
	push	bx
	push	dword ptr _g_363e
	mov	dword ptr _g_363e,0h
	push	0h
	push	0h
	push	bx
	call	far ptr _fn_203b_0007
	add	sp,6h
	pop	dword ptr _g_363e
	pop	bx
	mov	_g_2f3c,dx
	mov	_g_2f3a,ax
	or	ax,dx
	jz	short L_01af
	mov	_g_2f04,bx
L_0143:
	push	ds
	les	di,dword ptr _g_2f3a
	lds	si,[bp-4h]
	mov	ax,[si]
	test	ax,2h
	jz	short L_0159
	mov	cx,[bp-12h]
	rep	movsb
	jmp	short L_0194
L_0159:
	lodsw
	or	ax,2h
	mov	[bp-0ch],ax
	stosw
	mov	cx,4h
	rep	movsw
	test	word ptr [bp-0ch],1h
	jz	short L_0172
	mov	cx,8h
	rep	movsw
L_0172:
	mov	ax,ds
	pop	ds
	push	ds
	push	es
	push	di
	push	word ptr [bp-0ah]
	push	dword ptr _g_35ac
	push	ax
	push	si
	call	far ptr _fn_232c_000c
	add	sp,0ah
	lds	si,dword ptr _g_35ac
	pop	di
	pop	es
	mov	cx,ax
	rep	movsb
L_0194:
	pop	ds
	mov	ax,[bp+6h]
	mov	_g_2f24,ax
	mov	ax,[bp+8h]
	mov	_g_2f26,ax
	mov	bx,[bp-10h]
	mov	_g_2f20,bx
	mov	bx,[bp-0eh]
	mov	_g_2f22,bx
L_01af:
	call	far ptr _fn_1ebc_0053
L_01b4:
	push	dword ptr [bp+0ah]
	call	far ptr _fn_226d_004e
	add	sp,4h
	push	dword ptr [bp+0ah]
	push	dword ptr _g_2f06
	pop	ax
	pop	dx
	pop	dword ptr _g_2f06
	dec	word ptr _g_2f0a
	pop	di
	pop	es
	pop	si
	pop	ds
	pop	cx
	pop	bx
	leave
	retf
_fn_1e9f_0002	endp

S064_TEXT	ends
	end
