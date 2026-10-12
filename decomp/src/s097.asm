; s097: WW library

	.386
	locals
S097_TEXT	segment word public use16 'CODE'
S097_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S097_TEXT,ds:DGROUP

	extrn	_g_35c8:word, _g_35ca:word, _g_35cc:word

S097_TEXT	segment word public use16 'CODE'
	public	_fn_1fbd_0008

_fn_1fbd_0008	proc	far
	mov	bx,word ptr fs:_g_35cc
	add	bx,word ptr fs:_g_35ca
	or	bh,bh
	jnz	short L0040
	mov	word ptr fs:_g_35cc,bx
	push	ds
	lds	bx,[bp-1ch]
	xlatb
	push	ax
	push	ds
	lds	bx,[bp-20h]
	mov	ah,al
	xlatb
	xchg	ah,al
	or	ah,ah
	js	short L0037
	mov	al,es:[di]
	lds	bx,[bp-24h]
	add	bh,ah
	xlatb
L0037:	pop	ds
	pop	bx
	mov	ah,bh
	mov	es:[di],al
	pop	ds
	retf
L0040:	xor	bh,bh
	mov	word ptr fs:_g_35cc,bx
	add	di,word ptr fs:_g_35c8
	mov	al,es:[di]
	sub	di,word ptr fs:_g_35c8
	push	ax
	push	ds
	lds	bx,[bp-20h]
	mov	ah,al
	xlatb
	xchg	ah,al
	or	ah,ah
	js	short L006b
	mov	al,es:[di]
	lds	bx,[bp-24h]
	add	bh,ah
	xlatb
L006b:	pop	ds
	pop	bx
	mov	ah,bh
	mov	es:[di],al
	retf
_fn_1fbd_0008	endp

S097_TEXT	ends
	end
