; s080: WW library

	.386
	locals
S080_TEXT	segment word public use16 'CODE'
S080_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S080_TEXT,ds:DGROUP

	extrn	_g_35c8:word, _g_35ca:word, _g_35cc:word

S080_TEXT	segment word public use16 'CODE'
	public	_fn_1f88_0004

_fn_1f88_0004	proc	far
	mov	bx,fs:_g_35cc
	add	bx,fs:_g_35ca
	or	bh,bh
	jnz	short L001b
	mov	fs:_g_35cc,bx
	mov	es:[di],al
	retf
L001b:	xor	bh,bh
	mov	fs:_g_35cc,bx
	add	di,fs:_g_35c8
	mov	al,es:[di]
	sub	di,fs:_g_35c8
	mov	es:[di],al
	retf
_fn_1f88_0004	endp

S080_TEXT	ends
	end
