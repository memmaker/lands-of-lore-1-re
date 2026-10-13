; s090: WW library

	.386
	locals
S090_TEXT	segment word public use16 'CODE'
S090_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S090_TEXT,ds:DGROUP

	extrn	_g_35c8:word, _g_35ca:word, _g_35cc:word

S090_TEXT	segment word public use16 'CODE'
	public	_fn_1fa3_000a

_fn_1fa3_000a	proc	far
	mov	bx,word ptr fs:_g_35cc
	add	bx,word ptr fs:_g_35ca
	or	bh,bh
	jnz	short L0042
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
	js	short L0039
	mov	al,es:[di]
	lds	bx,[bp-24h]
	add	bh,ah
	xlatb
L0039:	pop	ds
	pop	bx
	mov	ah,bh
	mov	es:[di],al
	pop	ds
	retf
L0042:	xor	bh,bh
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
	js	short L006d
	mov	al,es:[di]
	lds	bx,[bp-24h]
	add	bh,ah
	xlatb
L006d:	pop	ds
	pop	bx
	mov	ah,bh
	mov	es:[di],al
	retf
_fn_1fa3_000a	endp

S090_TEXT	ends
	end
