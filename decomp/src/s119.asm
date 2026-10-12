; s119: WW library

	.386
	locals
S119_TEXT	segment word public use16 'CODE'
S119_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S119_TEXT,ds:DGROUP

	extrn	_g_0040:word
	extrn	_fn_2279_02b5:far

S119_TEXT	segment word public use16 'CODE'
	public	_fn_20f7_0006, _fn_20f7_01a2

_fn_20f7_0006	proc	far
	enter	0h,0h
	push	bx
	push	cx
	push	dx
	push	es
	push	di
	push	ds
	push	si
	cld
	push	dword ptr [bp+0ah]
	call	far ptr _fn_2279_02b5
	add	sp,4h
	mov	es,dx
	mov	di,ax
	push	dword ptr [bp+6h]
	call	far ptr _fn_2279_02b5
	add	sp,4h
	mov	si,ax
	mov	ds,dx
	mov	dx,[bp+0eh]
	push	bp
	cld
	mov	bp,si
	add	bp,dx
	mov	word ptr cs:[1a2h],1h
	mov	cs:[1a4h],di
	mov	cs:[1a6h],si
	mov	cs:[1a8h],di
	mov	al,81h
	stosb
	lodsb
	stosb
L0056:	mov	cs:[1ach],di
	mov	di,es
	mov	cs:[1aah],di
	mov	di,ds
	mov	es,di
	mov	di,cs:[1a6h]
	mov	word ptr cs:[1aeh],1h
L0072:	mov	al,[si]
	cmp	al,_g_0040[si]
	jnz	short L00b9
	mov	bx,di
	mov	di,si
	mov	cx,bp
	sub	cx,di
	repe	scasb
	dec	di
	mov	cx,di
	sub	cx,si
	cmp	cx,41h
	jc	short L00b7
	mov	word ptr cs:[1a2h],0h
	mov	si,di
	mov	es,cs:[1aah]
	mov	di,cs:[1ach]
	mov	ah,al
	mov	al,0feh
	stosb
	xchg	ax,cx
	stosw
	mov	al,ch
	stosb
	mov	cs:[1ach],di
	mov	di,ds
	mov	es,di
	mov	di,bx
	jmp	short L0072
L00b7:	mov	di,bx
L00b9:	mov	cx,si
	sub	cx,di
	jz	short L00fb
	repne	scasb
	jnz	short L00fb
	mov	bx,cs:[1aeh]
	mov	ah,[bx+si-1h]
	cmp	ah,es:[bx+di-2h]
	jnz	short L00b9
	mov	dx,si
	mov	bx,di
	dec	di
	mov	cx,bp
	sub	cx,si
	repe	cmpsb
	jnz	short L00df
	inc	di
L00df:	mov	si,dx
	mov	ax,di
	sub	ax,bx
	mov	di,bx
	cmp	ax,cs:[1aeh]
	jc	short L0072
	mov	cs:[1aeh],ax
	dec	bx
	mov	cs:[1b0h],bx
	jmp	near ptr L0072
L00fb:	mov	cx,cs:[1aeh]
	mov	es,cs:[1aah]
	mov	di,cs:[1ach]
	cmp	cx,2h
	jna	short L013f
	cmp	cx,0ah
	ja	short L012f
	mov	ax,si
	sub	ax,cs:[1b0h]
	cmp	ax,0fffh
	ja	short L012f
	mov	bl,cl
	sub	bl,3h
	mov	cl,4h
	shl	bl,cl
	add	ah,bl
	xchg	ah,al
	jmp	short L0179
L012f:	cmp	cx,40h
	ja	short L0168
	sub	cl,3h
	or	cl,0c0h
	mov	al,cl
	stosb
	jmp	short L0170
L013f:	cmp	word ptr cs:[1a2h],0h
	jnz	short L014f
L0147:	mov	cs:[1a8h],di
	mov	al,80h
	stosb
L014f:	mov	bx,cs:[1a8h]
	cmp	byte ptr es:[bx],0bfh
	jz	short L0147
	inc	byte ptr es:[bx]
	lodsb
	stosb
	mov	word ptr cs:[1a2h],1h
	jmp	short L0186
L0168:	mov	al,0ffh
	stosb
	mov	ax,cs:[1aeh]
	stosw
L0170:	mov	ax,cs:[1b0h]
	sub	ax,cs:[1a6h]
L0179:	stosw
	add	si,cs:[1aeh]
	mov	word ptr cs:[1a2h],0h
L0186:	cmp	si,bp
	jnc	short L018d
	jmp	near ptr L0056
L018d:	mov	ax,80h
	stosb
	mov	ax,di
	sub	ax,cs:[1a4h]
	pop	bp
	pop	si
	pop	ds
	pop	di
	pop	es
	pop	dx
	pop	cx
	pop	bx
	leave
	retf
_fn_20f7_0006	endp

_fn_20f7_01a2	proc	far
	add	[bx+si],al
	add	[bx+si],al
	add	[bx+si],al
	add	[bx+si],al
	add	[bx+si],al
	add	[bx+si],al
	add	[bx+si],al
	add	[bx+si],al
	enter	0ah,0h
	push	es
	push	ds
	pushad
	cld
	lds	si,[bp+0ah]
	les	di,[bp+6h]
	mov	ebx,[bp+0eh]
	mov	dword ptr [bp-6h],0h
	xor	edx,edx
L01d0:	or	ebx,ebx
	jz	near ptr L028b
	mov	ax,ds
	mov	cx,si
	shr	cx,4h
	add	ax,cx
	mov	ds,ax
	and	si,0fh
	mov	ax,es
	mov	cx,di
	shr	cx,4h
	add	ax,cx
	mov	es,ax
	and	di,0fh
	or	edx,edx
	jnz	short L01fe
	mov	[bp-8h],es
	mov	[bp-0ah],di
L01fe:	xor	cx,cx
	cmp	edx,ebx
	jnc	short L0231
	mov	al,es:[di]
	mov	ecx,0fff0h
	cmp	ecx,ebx
	jc	short L0216
	mov	ecx,ebx
L0216:	mov	[bp-2h],cx
	push	di
	repe	scasb
	pop	di
	neg	cx
	add	cx,[bp-2h]
	dec	cx
	cmp	cx,2h
	jnc	short L0231
	inc	di
	inc	dx
	cmp	dx,7fh
	jc	short L01d0
	xor	cx,cx
L0231:	push	cx
	or	dx,dx
	jz	short L0251
	sub	ebx,edx
	les	di,[bp-0ah]
	mov	[si],dl
	inc	si
	inc	dword ptr [bp-6h]
	add	[bp-6h],edx
L0247:	mov	al,es:[di]
	mov	[si],al
	inc	si
	inc	di
	dec	dx
	jnz	short L0247
L0251:	pop	cx
	or	cx,cx
	jz	near ptr L01d0
	sub	ebx,ecx
	mov	al,es:[di]
	add	di,cx
	cmp	cx,7fh
	ja	short L0275
	neg	cl
	mov	[si],cl
	inc	si
	mov	[si],al
	inc	si
	add	dword ptr [bp-6h],2h
	jmp	near ptr L01d0
L0275:	mov	byte ptr [si],0h
	inc	si
	xchg	ch,cl
	mov	[si],cx
	add	si,2h
	mov	[si],al
	inc	si
	add	dword ptr [bp-6h],4h
	jmp	near ptr L01d0
L028b:	popad
	mov	dx,[bp-4h]
	mov	ax,[bp-6h]
	pop	ds
	pop	es
	leave
	retf
_fn_20f7_01a2	endp

S119_TEXT	ends
	end
