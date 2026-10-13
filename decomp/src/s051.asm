; s051: WW library -- shape blitter (flag word selects the per-pixel routine from the table at 0006; optional remap tables) (assembler module; drafted from the original bytes)
; FIXUP-ORDER: 120

	.386
	locals
S051_TEXT	segment word public use16 'CODE'
S051_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S051_TEXT,ds:DGROUP

	extrn	_g_35b2:word
	extrn	_g_35b4:word
	extrn	_g_3649:word
	extrn	_g_3940:word
	extrn	_fn_215f_001d:far

S051_TEXT	segment word public use16 'CODE'
	public	_loc_1ddc_0006, _fn_1ddc_0026
_loc_1ddc_0006:
	dw	L_0163
	dw	L_01b2
	dw	0
	dw	0
	dw	L_016d
	dw	L_01d6
	dw	0
	dw	0
	dw	L_0179
	dw	L_01fe
	dw	0
	dw	0
	dw	L_0193
	dw	L_0218
	dw	0
	dw	0

_fn_1ddc_0026	proc	far
	enter	1eh,0h
	push	ax
	push	bx
	push	cx
	push	dx
	push	ds
	push	si
	push	es
	push	di
	push	fs
	push	di
	mov	di,6h
	test	word ptr [bp+10h],1h
	jz	short L_0057
	les	ax,[bp+di+12h]
	mov	[bp-1ah],ax
	mov	[bp-18h],es
	add	di,4h
	les	ax,[bp+di+12h]
	mov	[bp-1eh],ax
	mov	[bp-1ch],es
	add	di,4h
L_0057:
	pop	di
	mov	bx,[bp+10h]
	and	bx,0fh
	shl	bx,1
	mov	ax,word ptr cs:_loc_1ddc_0006[bx]
	mov	[bp-10h],ax
	test	word ptr [bp+10h],8h
	jz	short L_0081
	mov	ax,_g_35b4
	mov	[bp-14h],ax
	mov	ax,_g_35b2
	mov	[bp-12h],ax
	mov	ax,[bp+16h]
	mov	[bp-16h],al
L_0081:
	push	word ptr _g_3649
	call	far ptr _fn_215f_001d
	add	sp,2h
	mov	es,dx
	mov	si,1f3bh
	mov	cl,4h
	mov	ax,[bp+0eh]
	shl	ax,cl
	add	si,ax
	mov	cl,3h
	mov	ax,[si]
	shl	ax,cl
	mov	[bp-2h],ax
	mov	[bp-4h],ax
	mov	ax,[si+4h]
	shl	ax,cl
	add	[bp-4h],ax
	mov	ax,[si+2h]
	mov	[bp-6h],ax
	add	ax,[si+6h]
	mov	[bp-8h],ax
	lds	si,[bp+12h]
	mov	ax,[bp+8h]
	sub	ax,[bp-6h]
	jns	short L_00dc
	add	ax,[bp+0ch]
	jg	short L_00ce
L_00cb:
	jmp	near ptr L_0157
L_00ce:
	xchg	ax,[bp+0ch]
	sub	ax,[bp+0ch]
	add	[bp+8h],ax
	mul	word ptr [bp+0ah]
	add	si,ax
L_00dc:
	mov	ax,[bp-8h]
	sub	ax,[bp+8h]
	js	short L_00cb
	jz	short L_00cb
	cmp	ax,[bp+0ch]
	jnc	short L_00ee
	mov	[bp+0ch],ax
L_00ee:
	mov	word ptr [bp-0ah],0h
	mov	ax,[bp+6h]
	sub	ax,[bp-2h]
	jns	short L_0106
	neg	ax
	mov	[bp-0ah],ax
	add	[bp+6h],ax
	sub	[bp+0ah],ax
L_0106:
	mov	word ptr [bp-0ch],0h
	mov	ax,[bp-4h]
	sub	ax,[bp+6h]
	js	short L_00cb
	jz	short L_00cb
	cmp	ax,[bp+0ah]
	jnc	short L_0123
	xchg	ax,[bp+0ah]
	sub	ax,[bp+0ah]
	mov	[bp-0ch],ax
L_0123:
	push	si
	push	ds
	mov	ax,DGROUP
	mov	ds,ax
	mov	bx,[bp+8h]
	shl	bx,1
	lds	si,dword ptr _g_3940
	mov	di,[bx+si]
	pop	ds
	pop	si
	add	di,[bp+6h]
	mov	[bp-0eh],di
	mov	dx,[bp+0ch]
L_0140:
	add	si,[bp-0ah]
	mov	cx,[bp+0ah]
	call	[bp-10h]
	add	si,[bp-0ch]
	add	word ptr [bp-0eh],140h
	mov	di,[bp-0eh]
	dec	dx
	jnz	short L_0140
L_0157:
	pop	fs
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
L_0163:
	shr	cx,1
	rep	movsw
	adc	cx,0h
	rep	movsb
	retn
L_016d:
	lodsb
	or	al,al
	jz	short L_0175
	mov	es:[di],al
L_0175:
	inc	di
	loop	L_016d
	retn
L_0179:
	mov	fs,[bp-14h]
	mov	gs,[bp-12h]
	mov	ah,[bp-16h]
L_0182:
	lodsb
	mov	bl,[di]
	and	bl,7h
	cmp	ah,bl
	jnl	short L_018f
	mov	al,fs:[di]
L_018f:
	stosb
	loop	L_0182
	retn
L_0193:
	mov	fs,[bp-14h]
	mov	gs,[bp-12h]
	mov	ah,[bp-16h]
L_019c:
	lodsb
	or	al,al
	jz	short L_01ab
	mov	bl,gs:[di]
	and	bl,7h
	cmp	ah,bl
	jnl	short L_01ae
L_01ab:
	mov	al,fs:[di]
L_01ae:
	stosb
	loop	L_019c
	retn
L_01b2:
	lodsb
	push	ax
	push	ds
	lds	bx,[bp-1ah]
	mov	ah,al
	xlatb
	xchg	ah,al
	cmp	ah,0ffh
	jz	short L_01cb
	mov	al,es:[di]
	lds	bx,[bp-1eh]
	add	bh,ah
	xlatb
L_01cb:
	pop	ds
	pop	bx
	mov	ah,bh
	mov	es:[di],al
	inc	di
	loop	L_01b2
	retn
L_01d6:
	lodsb
	or	al,al
	jz	short L_01fa
	push	ax
	push	ds
	lds	bx,[bp-1ah]
	mov	ah,al
	xlatb
	xchg	ah,al
	cmp	ah,0ffh
	jz	short L_01f3
	mov	al,es:[di]
	lds	bx,[bp-1eh]
	add	bh,ah
	xlatb
L_01f3:
	pop	ds
	pop	bx
	mov	ah,bh
	mov	es:[di],al
L_01fa:
	inc	di
	loop	L_01d6
	retn
L_01fe:
	mov	fs,[bp-14h]
	mov	gs,[bp-12h]
	mov	ah,[bp-16h]
L_0207:
	lodsb
	mov	bl,[di]
	and	bl,7h
	cmp	ah,bl
	jnl	short L_0214
	mov	al,fs:[di]
L_0214:
	stosb
	loop	L_0207
	retn
L_0218:
	mov	fs,[bp-14h]
	mov	gs,[bp-12h]
	mov	ah,[bp-16h]
L_0221:
	lodsb
	or	al,al
	jz	short L_0230
	mov	bl,gs:[di]
	and	bl,7h
	cmp	ah,bl
	jnl	short L_0233
L_0230:
	mov	al,fs:[di]
L_0233:
	stosb
	loop	L_0221
	retn
_fn_1ddc_0026	endp

S051_TEXT	ends
	end
