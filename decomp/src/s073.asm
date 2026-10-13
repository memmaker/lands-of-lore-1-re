; s073: WW library -- print a string in the current font on the current page (assembler module; drafted from the original bytes)

	.386
	locals
S073_TEXT	segment word public use16 'CODE'
S073_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S073_TEXT,ds:DGROUP

	extrn	_g_2af4:word
	extrn	_g_3624:word
	extrn	_g_3626:word
	extrn	_g_ae53:word
	extrn	_fn_19ba_0086:far
	extrn	_fn_1e07_00ff:far
	extrn	_fn_1e07_0255:far
	extrn	_fn_226d_0007:far
	extrn	_fn_226d_004e:far

S073_TEXT	segment word public use16 'CODE'
	public	_loc_1f6c_0004, _fn_1f6c_0006
_loc_1f6c_0004:
	db	000h
L_0005:
	db	000h

_fn_1f6c_0006	proc	far
	enter	0ch,0h
	push	ax
	push	bx
	push	cx
	push	dx
	push	es
	push	di
	push	si
	inc	word ptr _g_2af4
	push	dword ptr [bp+6h]
	call	far ptr _fn_19ba_0086
	add	sp,4h
	mov	[bp-0ch],ax
	or	ax,ax
	jz	short L_003c
	push	0h
	push	dword ptr [bp+6h]
	call	far ptr _fn_226d_0007
	add	sp,6h
	mov	[bp+6h],ax
	mov	[bp+8h],dx
L_003c:
	les	di,dword ptr _g_ae53
	mov	ax,es
	or	ax,di
	jz	short L_0070
	mov	[bp-2h],es
	mov	ax,es:[di+8h]
	mov	[bp-8h],ax
	mov	bx,es:[di+4h]
	xor	ah,ah
	mov	al,es:[bx+di+4h]
	mov	[bp-6h],ax
	les	si,[bp+6h]
	mov	bx,[bp+0ah]
	cmp	bx,0h
	jnl	short L_006a
	xor	bx,bx
L_006a:
	cmp	bx,140h
	jc	short L_0073
L_0070:
	jmp	near ptr L_0110
L_0073:
	mov	[bp-0ah],bx
	mov	cx,[bp+0ch]
	cmp	cx,0h
	jnl	short L_0080
	xor	cx,cx
L_0080:
	cmp	cx,0c8h
	jnl	short L_0070
	mov	ax,[bp+0eh]
	mov	byte ptr cs:L_0005,al
	mov	ax,[bp+10h]
	mov	byte ptr cs:_loc_1f6c_0004,al
	mov	ax,1h
	push	ax
	xor	ax,ax
	push	ax
	push	cs
	mov	ax,offset _loc_1f6c_0004
	push	ax
	call	far ptr _fn_1e07_0255
	add	sp,8h
L_00a8:
	cmp	byte ptr es:[si],0h
	jz	short L_0110
	cmp	byte ptr es:[si],0dh
	jnz	short L_00c1
	mov	bx,[bp-0ah]
	add	cx,[bp-6h]
	add	cx,_g_3626
	inc	si
	jmp	short L_00a8
L_00c1:
	push	es
	xor	ah,ah
	mov	al,es:[si]
	mov	es,[bp-2h]
	push	bx
	mov	bx,[bp-8h]
	add	bx,ax
	xor	ah,ah
	mov	al,es:[bx+di]
	pop	bx
	add	ax,_g_3624
	mov	[bp-4h],ax
	mov	dx,bx
	add	dx,ax
	pop	es
	cmp	dx,140h
	jna	short L_00f2
	mov	bx,[bp-0ah]
	add	cx,[bp-6h]
	add	cx,_g_3626
L_00f2:
	cmp	cx,0c8h
	jnc	short L_0110
	push	cx
	push	bx
	mov	al,es:[si]
	xor	ah,ah
	push	ax
	call	far ptr _fn_1e07_00ff
	add	sp,2h
	pop	bx
	pop	cx
	add	bx,[bp-4h]
	inc	si
	jmp	short L_00a8
L_0110:
	cmp	word ptr [bp-0ch],0h
	jz	short L_0122
	push	dword ptr [bp+6h]
	call	far ptr _fn_226d_004e
	add	sp,4h
L_0122:
	dec	word ptr _g_2af4
	pop	si
	pop	di
	pop	es
	pop	dx
	pop	cx
	pop	bx
	pop	ax
	leave
	retf
_fn_1f6c_0006	endp

S073_TEXT	ends
	end
