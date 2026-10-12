; s087: WW library

	.386
	locals
S087_TEXT	segment word public use16 'CODE'
S087_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S087_TEXT,ds:DGROUP

	extrn	_g_35c8:word, _g_35ca:word, _g_35cc:word

S087_TEXT	segment word public use16 'CODE'
	public	_fn_1f99_0006

_fn_1f99_0006	proc	far
	mov	bx,word ptr fs:_g_35cc
	add	bx,word ptr fs:_g_35ca
	or	bh,bh
	jnz	short L002a
	mov	word ptr fs:_g_35cc,bx
	cmp	al,0ffh
	jnz	short L0026
	push	ds
	lds	bx,[bp-28h]
	mov	al,es:[di]
	xlatb
	pop	ds
L0026:	mov	es:[di],al
	retf
L002a:	xor	bh,bh
	mov	word ptr fs:_g_35cc,bx
	add	di,word ptr fs:_g_35c8
	mov	al,es:[di]
	sub	di,word ptr fs:_g_35c8
	cmp	al,0ffh
	jnz	short L004b
	push	ds
	lds	bx,[bp-28h]
	mov	al,es:[di]
	xlatb
	pop	ds
L004b:	mov	es:[di],al
	retf
_fn_1f99_0006	endp

S087_TEXT	ends
	end
