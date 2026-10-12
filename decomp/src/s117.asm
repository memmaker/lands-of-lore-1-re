; s117: WW library

	.386
	locals
S117_TEXT	segment word public use16 'CODE'
S117_TEXT	ends
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S117_TEXT

	extrn	_fn_19ba_0086:far, _fn_1f6a_0002:far, _fn_215f_001d:far, _fn_226d_0007:far, _fn_226d_004e:far

S117_TEXT	segment word public use16 'CODE'
	public	_fn_2096_0000, _fn_2096_014b

_fn_2096_0000	proc	far
	enter	4h,0h
	push	ds
	push	es
	pushad
	cld
	mov	word ptr [bp-2h],0h
	mov	word ptr [bp-4h],0h
	cmp	dword ptr [bp+0eh],0h
	jz	near ptr L012b
	mov	ax,[bp+6h]
	or	ax,ax
	jnl	short L002f
	add	[bp+0ah],ax
	jng	near ptr L012b
	xor	ax,ax
	mov	[bp+6h],ax
L002f:	cmp	ax,140h
	jnl	near ptr L012b
	add	ax,[bp+0ah]
	sub	ax,140h
	jng	short L0045
	sub	[bp+0ah],ax
	jng	near ptr L012b
L0045:	mov	bx,[bp+8h]
	or	bx,bx
	jnl	short L0058
	add	[bp+0ch],bx
	jng	near ptr L012b
	xor	bx,bx
	mov	[bp+8h],bx
L0058:	cmp	bx,0c8h
	jnl	near ptr L012b
	add	bx,[bp+0ch]
	sub	bx,0c8h
	jng	short L0070
	sub	[bp+0ch],bx
	jng	near ptr L012b
L0070:	mov	ax,[bp+0ah]
	dec	ax
	cmp	ax,140h
	jnc	near ptr L012b
	mov	bx,[bp+0ch]
	dec	bx
	cmp	bx,0c8h
	jnc	near ptr L012b
	push	word ptr [bp+0ch]
	push	word ptr [bp+0ah]
	call	far ptr _fn_1f6a_0002
	add	sp,4h
	mov	[bp-2h],ax
	push	dword ptr [bp+0eh]
	call	far ptr _fn_19ba_0086
	add	sp,4h
	or	ax,ax
	jz	short L00c1
	push	dword ptr [bp+0eh]
	call	far ptr _fn_226d_0007
	add	sp,4h
	mov	[bp+10h],dx
	mov	[bp+0eh],ax
	or	ax,dx
	jz	short L012b
	inc	word ptr [bp-4h]
L00c1:	push	word ptr [bp+12h]
	call	far ptr _fn_215f_001d
	add	sp,2h
	or	dx,dx
	jz	short L012b
	mov	es,dx
	mov	di,ax
	mov	ax,140h
	mul	word ptr [bp+8h]
	add	di,ax
	add	di,[bp+6h]
	lds	si,[bp+0eh]
	mov	bx,[bp+0ah]
	mov	dx,140h
	sub	dx,bx
	mov	cx,[bp+0ch]
	or	dx,dx
	jnz	short L0100
	mov	ax,140h
	mul	cx
	mov	cx,ax
	shr	cx,2h
	rep	movsd
	jmp	short L012b
L0100:	test	bx,3h
	jnz	short L0118
	shr	bx,2h
L0109:	push	cx
	mov	cx,bx
	add	ax,cx
	rep	movsd
	add	di,dx
	pop	cx
	loop	L0109
	jmp	short L012b
L0118:	push	cx
	mov	cx,bx
	add	ax,cx
	shr	cx,1
	rep	movsw
	adc	cx,0h
	rep	movsb
	add	di,dx
	pop	cx
	loop	L0118
L012b:	mov	ax,DGROUP
	mov	ds,ax
	popad
	cmp	word ptr [bp-4h],0h
	jz	short L0144
	push	dword ptr [bp+0eh]
	call	far ptr _fn_226d_004e
	add	sp,4h
L0144:	mov	ax,[bp-2h]
	pop	es
	pop	ds
	leave
	retf
_fn_2096_0000	endp
S117_TEXT	ends
DGROUP	group	_DATA,_BSS
S117_TEXT	segment word public use16 'CODE'

_fn_2096_014b	proc	far
	enter	4h,0h
	push	ds
	push	es
	pushad
	cld
	mov	word ptr [bp-4h],0h
	mov	word ptr [bp-2h],0h
	cmp	dword ptr [bp+0eh],0h
	jz	near ptr L0276
	mov	ax,[bp+6h]
	or	ax,ax
	jnl	short L017a
	add	[bp+0ah],ax
	jng	near ptr L0276
	xor	ax,ax
	mov	[bp+6h],ax
L017a:	cmp	ax,140h
	jnl	near ptr L0276
	add	ax,[bp+0ah]
	sub	ax,140h
	jng	short L0190
	sub	[bp+0ah],ax
	jng	near ptr L0276
L0190:	mov	bx,[bp+8h]
	or	bx,bx
	jnl	short L01a3
	add	[bp+0ch],bx
	jng	near ptr L0276
	xor	bx,bx
	mov	[bp+8h],bx
L01a3:	cmp	bx,0c8h
	jnl	near ptr L0276
	add	bx,[bp+0ch]
	sub	bx,0c8h
	jng	short L01bb
	sub	[bp+0ch],bx
	jng	near ptr L0276
L01bb:	mov	ax,[bp+0ah]
	dec	ax
	cmp	ax,140h
	jnc	near ptr L0276
	mov	bx,[bp+0ch]
	dec	bx
	cmp	bx,0c8h
	jnc	near ptr L0276
	push	word ptr [bp+0ch]
	push	word ptr [bp+0ah]
	call	far ptr _fn_1f6a_0002
	add	sp,4h
	mov	[bp-2h],ax
	push	dword ptr [bp+0eh]
	call	far ptr _fn_19ba_0086
	add	sp,4h
	or	ax,ax
	jz	short L020c
	push	dword ptr [bp+0eh]
	call	far ptr _fn_226d_0007
	add	sp,4h
	mov	[bp+10h],dx
	mov	[bp+0eh],ax
	or	ax,dx
	jz	short L0276
	inc	word ptr [bp-4h]
L020c:	push	word ptr [bp+12h]
	call	far ptr _fn_215f_001d
	add	sp,2h
	or	dx,dx
	jz	short L0276
	mov	ds,dx
	mov	si,ax
	mov	ax,140h
	mul	word ptr [bp+8h]
	add	si,ax
	add	si,[bp+6h]
	les	di,[bp+0eh]
	mov	bx,[bp+0ah]
	mov	dx,140h
	sub	dx,bx
	mov	cx,[bp+0ch]
	or	dx,dx
	jnz	short L024b
	mov	ax,140h
	mul	cx
	mov	cx,ax
	shr	cx,2h
	rep	movsd
	jmp	short L0276
L024b:	test	bx,3h
	jnz	short L0263
	shr	bx,2h
L0254:	push	cx
	mov	cx,bx
	add	ax,cx
	rep	movsd
	add	si,dx
	pop	cx
	loop	L0254
	jmp	short L0276
L0263:	push	cx
	mov	cx,bx
	add	ax,cx
	shr	cx,1
	rep	movsw
	adc	cx,0h
	rep	movsb
	add	si,dx
	pop	cx
	loop	L0263
L0276:	mov	ax,DGROUP
	mov	ds,ax
	popad
	cmp	word ptr [bp-4h],0h
	jz	short L028f
	push	dword ptr [bp+0eh]
	call	far ptr _fn_226d_004e
	add	sp,4h
L028f:	mov	ax,[bp-2h]
	pop	es
	pop	ds
	leave
	retf
_fn_2096_014b	endp

S117_TEXT	ends
	end
