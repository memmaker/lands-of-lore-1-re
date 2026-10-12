; s121: WW library

	.386
	locals
S121_TEXT	segment word public use16 'CODE'
S121_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S121_TEXT,ds:DGROUP

	extrn	_g_abdf:word, _g_abe0:word

S121_TEXT	segment word public use16 'CODE'
	public	_fn_2124_0002, _fn_2124_0033

_fn_2124_0002	proc	far
	push	ax
	push	bx
	push	dx
	mov	ah,19h
	int	21h
	mov	_g_abdf,al
	mov	dl,al
	mov	ah,0eh
	int	21h
	dec	al
	xor	ah,ah
	mov	dx,ax
L0018:	mov	bl,dl
	inc	bl
	mov	ax,440eh
	int	21h
	jnc	short L002a
	cmp	al,0fh
	jnz	short L002a
	dec	dx
	jmp	short L0018
L002a:	mov	ax,dx
	mov	_g_abe0,al
	pop	dx
	pop	bx
	pop	ax
	retf
_fn_2124_0002	endp

_fn_2124_0033	proc	far
	enter	0h,0h
	push	bx
	push	dx
	mov	dx,[bp+6h]
	push	bx
	mov	bl,dl
	inc	bl
	mov	ax,440eh
	int	21h
	pop	bx
	jnc	short L004f
	cmp	al,1h
	jz	short L005e
	jmp	short L0059
L004f:	cmp	al,0h
	jz	short L005e
	dec	al
	cmp	al,dl
	jz	short L005e
L0059:	mov	ax,0h
	jmp	short L0061
L005e:	mov	ax,1h
L0061:	pop	dx
	pop	bx
	leave
	retf
_fn_2124_0033	endp

S121_TEXT	ends
	end
