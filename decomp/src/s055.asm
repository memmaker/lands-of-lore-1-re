; s055: WW library -- clip window (fn_000a) and clipped line drawing on the current page (fn_0209; Cohen-Sutherland helper at 002a) (assembler module; drafted from the original bytes)

	.386
	locals
S055_TEXT	segment word public use16 'CODE'
S055_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S055_TEXT,ds:DGROUP

	extrn	_g_2efa:word
	extrn	_g_2efc:word
	extrn	_g_2efe:word
	extrn	_g_2f00:word
	extrn	_g_3649:word
	extrn	_fn_215f_001d:far

S055_TEXT	segment word public use16 'CODE'
	public	_fn_1e30_000a, _fn_1e30_0209

_fn_1e30_000a	proc	far
	enter	0h,0h
	push	ax
	mov	ax,[bp+6h]
	mov	_g_2efa,ax
	mov	ax,[bp+8h]
	mov	_g_2efc,ax
	mov	ax,[bp+0ah]
	mov	_g_2efe,ax
	mov	ax,[bp+0ch]
	mov	_g_2f00,ax
	pop	ax
	leave
	retf
L_002a:
	push	ax
	push	bp
	push	bx
	push	cx
	push	di
	push	dx
	push	es
	push	si
	mov	word ptr cs:L_01fe,di
	cmp	ax,_g_2efa
	jl	short L_0067
	cmp	ax,_g_2efe
	jg	short L_0067
	cmp	bx,_g_2efc
	jl	short L_0067
	cmp	bx,_g_2f00
	jg	short L_0067
	cmp	cx,_g_2efa
	jl	short L_0067
	cmp	cx,_g_2efe
	jg	short L_0067
	cmp	dx,_g_2efc
	jl	short L_0067
	cmp	dx,_g_2f00
	jng	short L_0091
L_0067:
	call	near ptr L_011f
	xchg	ax,cx
	xchg	bx,dx
	mov	di,si
	call	near ptr L_011f
	mov	bp,di
	or	bp,si
	jz	short L_0091
	test	di,si
	jnz	short L_0094
	shl	si,1
	call	word ptr cs:L_0097[si]
	jc	short L_0067
	xchg	ax,cx
	xchg	bx,dx
	shl	di,1
	call	word ptr cs:L_0097[di]
	jmp	short L_0067
L_0091:
	jmp	near ptr L_0146
L_0094:
	jmp	near ptr L_0200
L_0097:
	dw	L_00b7
	dw	L_00b9
	dw	L_00c2
	dw	L_00b7
	dw	L_00ee
	dw	L_00ee
	dw	L_00c2
	dw	L_00b7
	dw	L_00f7
	dw	L_00b9
	dw	L_00f7
	dw	L_00b7
	dw	L_00b7
	dw	L_00b7
	dw	L_00b7
	dw	L_00b7
L_00b7:
	clc
	retn
L_00b9:
	mov	si,_g_2efc
	call	near ptr L_00d5
	stc
	retn
L_00c2:
	mov	si,_g_2f00
	neg	si
	neg	bx
	neg	dx
	call	near ptr L_00d5
	neg	bx
	neg	dx
	stc
	retn
L_00d5:
	push	dx
	push	ax
	mov	bp,dx
	sub	bp,bx
	neg	ax
	add	ax,cx
	mov	dx,si
	sub	dx,bx
	imul	dx
	idiv	bp
	pop	dx
	add	ax,dx
	pop	dx
	mov	bx,si
	retn
L_00ee:
	mov	si,_g_2efa
	call	near ptr L_010a
	stc
	retn
L_00f7:
	mov	si,_g_2efe
	neg	ax
	neg	cx
	neg	si
	call	near ptr L_010a
	neg	ax
	neg	cx
	stc
	retn
L_010a:
	push	dx
	mov	bp,cx
	sub	bp,ax
	sub	dx,bx
	neg	ax
	add	ax,si
	imul	dx
	idiv	bp
	add	bx,ax
	pop	dx
	mov	ax,si
	retn
L_011f:
	xor	si,si
	cmp	bx,_g_2efc
	jnl	short L_012a
	or	si,1h
L_012a:
	cmp	bx,_g_2f00
	jng	short L_0133
	or	si,2h
L_0133:
	cmp	ax,_g_2efa
	jnl	short L_013c
	or	si,4h
L_013c:
	cmp	ax,_g_2efe
	jng	short L_0145
	or	si,8h
L_0145:
	retn
L_0146:
	sub	dx,bx
	jnz	short L_014c
	jmp	short L_01b4
L_014c:
	jg	short L_0153
	neg	dx
	xchg	ax,cx
	sub	bx,dx
L_0153:
	push	dx
	push	ax
	mov	ax,140h
	mul	bx
	mov	bx,ax
	pop	ax
	pop	dx
	mov	si,1h
	sub	cx,ax
	jnz	short L_0168
	jmp	near ptr L_01ea
L_0168:
	jg	short L_016e
	neg	cx
	neg	si
L_016e:
	cmp	cx,dx
	jnl	short L_0194
	xchg	cx,dx
	mov	di,cx
	mov	bp,cx
	shr	bp,1
	add	bx,ax
	mov	ax,word ptr cs:L_01fe
L_0180:
	mov	es:[bx],al
	dec	cx
	jl	short L_0200
	add	bx,140h
	sub	bp,dx
	jnl	short L_0180
	add	bp,di
	add	bx,si
	jmp	short L_0180
L_0194:
	mov	di,cx
	mov	bp,cx
	shr	bp,1
	add	bx,ax
	mov	ax,word ptr cs:L_01fe
L_01a0:
	mov	es:[bx],al
	dec	cx
	jl	short L_0200
	add	bx,si
	sub	bp,dx
	jnl	short L_01a0
	add	bp,di
	add	bx,140h
	jmp	short L_01a0
L_01b4:
	cmp	ax,cx
	jl	short L_01b9
	xchg	ax,cx
L_01b9:
	sub	cx,ax
	inc	cx
	push	dx
	push	ax
	mov	ax,140h
	mul	bx
	mov	bx,ax
	pop	ax
	pop	dx
	add	bx,ax
	mov	di,bx
	mov	ax,word ptr cs:L_01fe
	mov	ah,al
	test	di,1h
	jz	short L_01d9
	stosb
	dec	cx
L_01d9:
	mov	dx,cx
	shr	cx,1
	jz	short L_01e1
	rep	stosw
L_01e1:
	test	dx,1h
	jz	short L_01e8
	stosb
L_01e8:
	jmp	short L_0200
L_01ea:
	mov	cx,dx
	inc	cx
	add	bx,ax
	mov	ax,word ptr cs:L_01fe
L_01f3:
	mov	es:[bx],al
	add	bx,140h
	loop	L_01f3
	jmp	short L_0200
L_01fe:
	db	000h, 000h
L_0200:
	pop	si
	pop	es
	pop	dx
	pop	di
	pop	cx
	pop	bx
	pop	bp
	pop	ax
	retn

_fn_1e30_000a	endp
_fn_1e30_0209	proc	far
	enter	0h,0h
	push	ax
	push	bx
	push	cx
	push	dx
	push	es
	push	di
	push	ds
	push	si
	push	word ptr _g_3649
	call	far ptr _fn_215f_001d
	add	sp,2h
	mov	es,dx
	mov	ax,[bp+6h]
	mov	bx,[bp+8h]
	mov	cx,[bp+0ah]
	mov	dx,[bp+0ch]
	mov	di,[bp+0eh]
	push	bp
	call	near ptr L_002a
	pop	bp
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
_fn_1e30_0209	endp

S055_TEXT	ends
	end
