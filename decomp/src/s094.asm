; s094: WW library

	.386
	locals
S094_TEXT	segment word public use16 'CODE'
S094_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S094_TEXT,ds:DGROUP

	extrn	_g_35c8:word, _g_35ca:word, _g_35cc:word

S094_TEXT	segment word public use16 'CODE'
	public	_fn_1fb3_0002

_fn_1fb3_0002	proc	far
	mov	bx,fs:_g_35cc
	add	bx,fs:_g_35ca
	or	bh,bh
	jnz	short L0019
	mov	fs:_g_35cc,bx
	mov	es:[di],al
	retf
L0019:	xor	bh,bh
	mov	fs:_g_35cc,bx
	add	di,fs:_g_35c8
	mov	al,es:[di]
	sub	di,fs:_g_35c8
	push	ax
	push	ds
	lds	bx,[bp-20h]
	mov	ah,al
	xlatb
	xchg	ah,al
	or	ah,ah
	js	short L0044
	mov	al,es:[di]
	lds	bx,[bp-24h]
	add	bh,ah
	xlatb
L0044:	pop	ds
	pop	bx
	mov	ah,bh
	mov	es:[di],al
	retf
_fn_1fb3_0002	endp

S094_TEXT	ends
	end
