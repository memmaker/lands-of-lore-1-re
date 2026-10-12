; s054: WW library -- font glyph drawing (fn_00ff draw one character, fn_0255 set the colour translation table at 000e, fn_0298 no-op) (assembler module; drafted from the original bytes)

	.386
	locals
S054_TEXT	segment word public use16 'CODE'
S054_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S054_TEXT,ds:DGROUP

	extrn	_g_3649:word
	extrn	_g_ae53:word
	extrn	_fn_215f_001d:far

S054_TEXT	segment word public use16 'CODE'
	public	_loc_1e07_000e, _fn_1e07_00ff, _fn_1e07_0255, _fn_1e07_0298
_loc_1e07_000e:
	db	000h, 001h, 002h, 003h, 004h, 005h, 006h, 007h, 008h, 009h, 00ah, 00bh, 00ch, 00dh, 00eh, 00fh
	db	001h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
	db	002h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
	db	003h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
	db	004h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
	db	005h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
	db	006h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
	db	007h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
	db	008h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
	db	009h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
	db	00ah, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
	db	00bh, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
	db	00ch, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
	db	00dh, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
	db	00eh, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
	db	00fh

_fn_1e07_00ff	proc	far
	enter	14h,0h
	push	ax
	push	bx
	push	cx
	push	dx
	push	ds
	push	si
	push	es
	push	di
	push	word ptr _g_3649
	call	far ptr _fn_215f_001d
	add	sp,2h
	mov	[bp-0eh],dx
	les	si,dword ptr _g_ae53
	mov	ax,es
	or	ax,si
	jz	near ptr L_024b
	mov	ax,es:[si+4h]
	mov	[bp-2h],ax
	mov	ax,es:[si+6h]
	mov	[bp-4h],ax
	mov	ax,es:[si+8h]
	mov	[bp-6h],ax
	mov	ax,es:[si+0ch]
	mov	[bp-8h],ax
	mov	bx,[bp+6h]
	xor	bh,bh
	shl	bx,1
	add	bx,[bp-4h]
	mov	cx,es:[bx+si]
	or	cx,cx
	jz	near ptr L_024b
	mov	dx,[bp+8h]
	cmp	dx,140h
	jnc	near ptr L_024b
	mov	bx,[bp+6h]
	add	bx,[bp-6h]
	xor	ah,ah
	mov	al,es:[bx+si]
	mov	[bp-0ah],ax
	add	ax,dx
	cmp	ax,140h
	ja	near ptr L_024b
	mov	di,dx
	mov	dx,[bp+0ah]
	cmp	dx,0c8h
	jnc	near ptr L_024b
	mov	bx,[bp-2h]
	xor	ah,ah
	mov	al,es:[bx+si+4h]
	mov	[bp-14h],al
	add	ax,dx
	cmp	ax,0c8h
	ja	near ptr L_024b
	mov	bx,[bp+6h]
	shl	bx,1
	add	bx,[bp-8h]
	mov	ah,es:[bx+si]
	mov	[bp-10h],ah
	mov	al,es:[bx+si+1h]
	mov	[bp-12h],al
	add	ah,al
	sub	[bp-14h],ah
	add	si,cx
	push	dx
	mov	ax,140h
	mul	dx
	add	di,ax
	pop	dx
	mov	ax,140h
	sub	ax,[bp-0ah]
	mov	[bp-0ch],ax
	mov	ax,[bp-0eh]
	mov	dx,es
	mov	es,ax
	mov	ds,dx
	mov	bx,0eh
	xor	ch,ch
	mov	cl,[bp-10h]
	or	cx,cx
	jz	short L_01fe
	mov	al,0h
	xlat	byte	ptr cs:[bx]
	or	al,al
	jnz	short L_01f2
	push	dx
	mov	ax,140h
	mul	cx
	add	di,ax
	pop	dx
	mov	bx,0eh
	jmp	short L_01fe
L_01f2:
	mov	dx,[bp-0ah]
L_01f5:
	stosb
	dec	dx
	jnz	short L_01f5
	add	di,[bp-0ch]
	loop	L_01f2
L_01fe:
	mov	cl,[bp-12h]
	or	cx,cx
	jz	short L_024b
L_0205:
	mov	dx,[bp-0ah]
L_0208:
	lodsb
	mov	ah,al
	and	al,0fh
	xlat	byte	ptr cs:[bx]
	or	al,al
	jz	short L_0216
	mov	es:[di],al
L_0216:
	inc	di
	dec	dx
	jz	short L_022b
	mov	al,ah
	and	al,0f0h
	xlat	byte	ptr cs:[bx]
	or	al,al
	jz	short L_0227
	mov	es:[di],al
L_0227:
	inc	di
	dec	dx
	jnz	short L_0208
L_022b:
	add	di,[bp-0ch]
	loop	L_0205
	mov	cl,[bp-14h]
	or	cx,cx
	jng	short L_024b
	mov	al,0h
	xlat	byte	ptr cs:[bx]
	or	al,al
	jz	short L_024b
L_023f:
	mov	dx,[bp-0ah]
L_0242:
	stosb
	dec	dx
	jnz	short L_0242
	add	di,[bp-0ch]
	loop	L_023f
L_024b:
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

_fn_1e07_00ff	endp
_fn_1e07_0255	proc	far
	enter	0h,0h
	push	ax
	push	bx
	push	cx
	push	es
	push	di
	push	ds
	push	si
	cld
	lds	si,[bp+6h]
	mov	bx,[bp+0ah]
	and	bx,0fh
	mov	cx,[bp+0ch]
	and	cx,0fh
	cmp	cx,bx
	jl	short L_028f
	sub	cx,bx
	inc	cx
	push	cs
	pop	es
	mov	di,0eh
	add	di,bx
	shl	bx,4h
	add	bx,offset _loc_1e07_000e
L_0285:
	lodsb
	stosb
	mov	es:[bx],al
	add	bx,10h
	loop	L_0285
L_028f:
	pop	si
	pop	ds
	pop	di
	pop	es
	pop	cx
	pop	bx
	pop	ax
	leave
	retf

_fn_1e07_0255	endp
_fn_1e07_0298	proc	far
	retf
_fn_1e07_0298	endp

S054_TEXT	ends
	end
