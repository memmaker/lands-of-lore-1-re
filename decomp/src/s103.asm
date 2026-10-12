; s103: WW library

	.386
	locals
S103_TEXT	segment word public use16 'CODE'
S103_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S103_TEXT,ds:DGROUP

	extrn	_g_2b30:word, _g_2b50:word, _g_2b70:word, _g_2b90:word, _g_35ac:word, _g_35b6:word, _g_35c8:word, _g_35ca:word, _g_35cc:word, _g_3940:word
	extrn	_fn_215f_001d:far, _fn_226d_0007:far, _fn_226d_004e:far, _fn_232c_000c:far

S103_TEXT	segment word public use16 'CODE'
	public	_fn_1fd6_000a, _fn_1fd6_0436

_fn_1fd6_000a	proc	far
	enter	5ah,0h
	push	eax
	push	bx
	push	cx
	push	dx
	push	ds
	push	es
	push	di
	push	si
	push	0h
	push	dword ptr [bp+8h]
	call	far ptr _fn_226d_0007
	add	sp,6h
	mov	[bp+0ah],dx
	mov	[bp+8h],ax
	push	ds
	push	fs
	mov	ax,2e2dh	; FIXUP []
	mov	fs,ax
	les	di,[bp+8h]
	mov	ax,es
	add	ax,di
	jnz	short L003f
	jmp	near ptr L041c
L003f:	mov	[bp-52h],ds
	test	byte ptr es:[di],1h
	jz	short L004d
	or	word ptr [bp+12h],400h
L004d:	mov	di,2h
	test	word ptr [bp+12h],8000h
	jz	short L0063
	les	ax,[bp+di+12h]
	mov	[bp-1ch],ax
	mov	[bp-1ah],es
	add	di,4h
L0063:	test	word ptr [bp+12h],100h
	jz	short L0085
	les	ax,[bp+di+12h]
	mov	[bp-14h],ax
	mov	[bp-12h],es
	mov	ax,[bp+di+16h]
	or	ax,ax
	jnz	short L007f
	and	word ptr [bp+12h],0feffh
L007f:	mov	[bp-42h],ax
	add	di,6h
L0085:	test	word ptr [bp+12h],1000h
	jz	short L00a4
	les	ax,[bp+di+12h]
	mov	[bp-20h],ax
	mov	[bp-1eh],es
	add	di,4h
	les	ax,[bp+di+12h]
	mov	[bp-24h],ax
	mov	[bp-22h],es
	add	di,4h
L00a4:	test	word ptr [bp+12h],200h
	jz	short L00d8
	inc	word ptr fs:_g_35b6
	inc	word ptr fs:_g_35b6
	and	word ptr fs:_g_35b6,0fh
	mov	bx,35b8h
	add	bx,fs:_g_35b6
	mov	ax,fs:[bx]
	mov	fs:_g_35c8,ax
	mov	word ptr fs:_g_35cc,0h
	mov	word ptr fs:_g_35ca,100h
L00d8:	test	word ptr [bp+12h],4000h
	jz	short L00e9
	mov	ax,[bp+di+12h]
	mov	fs:_g_35ca,ax
	add	di,2h
L00e9:	test	word ptr [bp+12h],800h
	jz	short L00f9
	mov	ax,[bp+di+12h]
	mov	[bp-58h],al
	add	di,2h
L00f9:	test	word ptr [bp+12h],4h
	jz	short L010e
	les	ax,[bp+di+12h]
	mov	[bp-4ah],ax
	mov	[bp-4ch],es
	add	di,4h
	jmp	short L0113
L010e:	mov	word ptr [bp-4ch],100h
L0113:	test	word ptr [bp+12h],2000h
	jz	short L0126
	les	ax,[bp+di+12h]
	mov	[bp-28h],ax
	mov	[bp-26h],es
	add	di,4h
L0126:	mov	word ptr [bp-4eh],0h
	xor	bx,bx
	mov	bl,[bp+12h]
	and	bl,0fh
	shl	bl,1
	shl	bl,1
	mov	eax,fs:_g_2b30[bx]
	mov	[bp-8h],eax
	mov	eax,fs:_g_2b50[bx]
	mov	[bp-0ch],eax
	mov	eax,fs:_g_2b70[bx]
	mov	[bp-10h],eax
	mov	bl,[bp+13h]
	and	bl,3fh
	shl	bl,1
	shl	bl,1
	mov	eax,fs:_g_2b90[bx]
	mov	[bp-4h],eax
	push	word ptr [bp+6h]
	call	far ptr _fn_215f_001d
	pop	ax
	mov	es,dx
	xor	di,di
	mov	si,1f3bh
	mov	cl,4h
	mov	ax,[bp+10h]
	shl	ax,cl
	add	si,ax
	mov	cl,3h
	mov	ax,[si]
	shl	ax,cl
	add	di,ax
	test	word ptr [bp+12h],10h
	jnz	short L0194
	sub	[bp+0ch],ax
L0194:	mov	ax,[si+4h]
	shl	ax,cl
	mov	[bp-2eh],ax
	mov	ax,[si+2h]
	mov	[bp-2ah],ax
	test	word ptr [bp+12h],10h
	jz	short L01ac
	add	[bp+0eh],ax
L01ac:	add	ax,[si+6h]
	mov	[bp-2ch],ax
	lds	si,[bp+8h]
	lodsw
	mov	[bp-30h],ax
	xor	ax,ax
	lodsb
	test	word ptr [bp+12h],4h
	jz	short L01d1
	mul	word ptr [bp-4ch]
	mov	al,ah
	mov	ah,dl
	or	ax,ax
	jnz	short L01d1
	jmp	near ptr L041c
L01d1:	test	word ptr [bp+12h],20h
	jz	short L01df
	mov	dx,ax
	shr	dx,1
	sub	[bp+0eh],dx
L01df:	mov	[bp-32h],ax
	lodsw
	mov	[bp-38h],ax
	test	word ptr [bp+12h],4h
	jz	short L01fb
	mul	word ptr [bp-4ah]
	mov	al,ah
	mov	ah,dl
	or	ax,ax
	jnz	short L01fb
	jmp	near ptr L041c
L01fb:	test	word ptr [bp+12h],20h
	jz	short L0209
	mov	dx,ax
	shr	dx,1
	sub	[bp+0ch],dx
L0209:	mov	[bp-34h],ax
	mov	[bp-36h],ax
	add	si,3h
	lodsw
	mov	bx,ax
	mov	ax,10h
	test	word ptr [bp-30h],4h
	jz	short L0222
	mov	al,[si]
	inc	si
L0222:	test	word ptr [bp+12h],8000h
	jnz	short L0236
	test	word ptr [bp-30h],1h
	jz	short L0236
	mov	[bp-1ch],si
	mov	[bp-1ah],ds
L0236:	test	word ptr [bp+12h],400h
	jz	short L023f
	add	si,ax
L023f:	test	word ptr [bp-30h],2h
	jnz	short L0264
	push	es
	push	di
	push	bx
	mov	bx,ds
	mov	ds,[bp-52h]
	les	di,_g_35ac
	push	es
	push	di
	push	bx
	push	si
	call	far ptr _fn_232c_000c
	add	sp,0ah
	lds	si,_g_35ac
	pop	di
	pop	es
L0264:	test	word ptr [bp+12h],2h
	jnz	short L0273
	mov	ax,[bp+0eh]
	sub	ax,[bp-2ah]
	jmp	short L027c
L0273:	mov	ax,[bp-2ch]
	sub	ax,[bp+0eh]
	sub	ax,[bp-32h]
L027c:	jns	short L02d5
	add	[bp-32h],ax
	jg	short L0286
	jmp	near ptr L041c
L0286:	neg	ax
	mov	[bp-44h],ax
L028b:	mov	word ptr [bp-54h],0h
	mov	[bp-18h],si
	mov	[bp-16h],ds
	mov	cx,[bp-38h]
	mov	[bp-3ah],cx
	xor	dx,dx
	call	far ptr [bp-0ch]
	mov	ax,[bp-4ch]
	add	[bp-4eh],ax
	test	word ptr [bp-4eh],0ff00h
	jz	short L028b
	xor	ax,ax
	xchg	al,[bp-4dh]
	sub	[bp-44h],ax
	jg	short L028b
	jns	short L02c8
	lds	si,[bp-18h]
	xor	al,al
	neg	word ptr [bp-44h]
	mov	ah,[bp-44h]
	add	[bp-4eh],ax
L02c8:	test	word ptr [bp+12h],2h
	jnz	short L02d5
	mov	ax,[bp-2ah]
	mov	[bp+0eh],ax
L02d5:	test	word ptr [bp+12h],2h
	jnz	short L02e4
	mov	ax,[bp-2ch]
	sub	ax,[bp+0eh]
	jmp	short L02ed
L02e4:	mov	ax,[bp+0eh]
	add	ax,[bp-32h]
	sub	ax,[bp-2ah]
L02ed:	js	short L0349
	jz	short L0349
	cmp	ax,[bp-32h]
	jnc	short L0306
	mov	[bp-32h],ax
	test	word ptr [bp+12h],2h
	jz	short L0306
	mov	ax,[bp-2ah]
	mov	[bp+0eh],ax
L0306:	mov	word ptr [bp-3ch],0h
	mov	ax,[bp+0ch]
	or	ax,ax
	jns	short L0324
	add	[bp-34h],ax
	neg	ax
	mov	[bp-3ch],ax
	cmp	ax,[bp-36h]
	jnc	short L0349
	xor	ax,ax
	mov	[bp+0ch],ax
L0324:	mov	word ptr [bp-3eh],0h
	mov	ax,[bp-2eh]
	sub	ax,[bp+0ch]
	js	short L0349
	jz	short L0349
	cmp	ax,[bp-34h]
	jnc	short L034c
	mov	[bp-34h],ax
	mov	ax,[bp-36h]
	sub	ax,[bp-3ch]
	sub	ax,[bp-34h]
	mov	[bp-3eh],ax
	jmp	short L034c
L0349:	jmp	near ptr L041c
L034c:	mov	word ptr [bp-50h],140h
	push	si
	push	ds
	mov	ds,[bp-52h]
	mov	bx,[bp+0eh]
	test	word ptr [bp+12h],2h
	jz	short L0367
	neg	word ptr [bp-50h]
	add	bx,[bp-32h]
	dec	bx
L0367:	shl	bx,1
	lds	si,_g_3940
	mov	ax,[bx+si]
	pop	ds
	pop	si
	add	ax,[bp+0ch]
	add	di,ax
	mov	[bp-40h],di
	test	word ptr [bp+12h],1h
	jz	short L0392
	mov	ax,[bp-3ch]
	xchg	ax,[bp-3eh]
	mov	[bp-3ch],ax
	mov	ax,[bp-34h]
	dec	ax
	add	di,ax
	add	[bp-40h],ax
L0392:	test	word ptr [bp+12h],4h
	jz	short L03b5
	mov	word ptr [bp-3eh],0h
	xor	dx,dx
	mov	ax,[bp-3ch]
	mov	[bp-56h],ax
	xchg	dl,ah
	xchg	ah,al
	div	word ptr [bp-4ah]
	mov	[bp-3ch],ax
	neg	dx
	mov	[bp-54h],dx
L03b5:	test	word ptr [bp-4eh],0ff00h
	jz	short L03be
	jmp	short L03de
L03be:	xor	dx,dx
	mov	ax,[bp-4ch]
	add	[bp-4eh],ax
	test	word ptr [bp-4eh],0ff00h
	jnz	short L03d8
	mov	cx,[bp-38h]
	mov	[bp-3ah],cx
	call	far ptr [bp-0ch]
	jmp	short L03be
L03d8:	mov	[bp-18h],si
	mov	[bp-16h],ds
L03de:	mov	ax,[bp-38h]
	mov	[bp-3ah],ax
	xor	dx,dx
	xor	ax,ax
	mov	cx,[bp-3ch]
	call	far ptr [bp-8h]
	cmp	word ptr [bp-3ah],0h
	jz	short L0404
	add	cx,[bp-34h]
	jng	short L03fc
	call	far ptr [bp-10h]
L03fc:	add	cx,[bp-3eh]
	jcxz	L0404
	call	far ptr [bp-0ch]
L0404:	mov	ax,[bp-50h]
	add	[bp-40h],ax
	mov	di,[bp-40h]
	dec	word ptr [bp-32h]
	jz	short L041c
	dec	byte ptr [bp-4dh]
	jz	short L03be
	lds	si,[bp-18h]
	jmp	short L03de
L041c:	pop	fs
	pop	ds
	push	dword ptr [bp+8h]
	call	far ptr _fn_226d_004e
	add	sp,4h
	pop	si
	pop	di
	pop	es
	pop	ds
	pop	dx
	pop	cx
	pop	bx
	pop	eax
	leave
	retf
_fn_1fd6_000a	endp

_fn_1fd6_0436	proc	far
	retf
_fn_1fd6_0436	endp

S103_TEXT	ends
	end
