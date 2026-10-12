; s083: WW library

	.386
	locals
S083_TEXT	segment word public use16 'CODE'
S083_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S083_TEXT,ds:DGROUP

	extrn	_g_35c8:word, _g_35ca:word, _g_35cc:word

S083_TEXT	segment word public use16 'CODE'
	public	_fn_1f8f_0000

_fn_1f8f_0000	proc	far
	mov	bx,word ptr fs:_g_35cc
	add	bx,word ptr fs:_g_35ca
	or	bh,bh
	jnz	short L0028
	mov	word ptr fs:_g_35cc,bx
	push	ds
	lds	bx,[bp-1ch]
	xlatb
	cmp	al,0ffh
	jnz	short L0023
	lds	bx,[bp-28h]
	mov	al,es:[di]
	xlatb
L0023:	mov	es:[di],al
	pop	ds
	retf
L0028:	xor	bh,bh
	mov	word ptr fs:_g_35cc,bx
	add	di,word ptr fs:_g_35c8
	mov	al,es:[di]
	sub	di,word ptr fs:_g_35c8
	cmp	al,0ffh
	jnz	short L0049
	push	ds
	lds	bx,[bp-28h]
	mov	al,es:[di]
	xlatb
	pop	ds
L0049:	mov	es:[di],al
	retf
_fn_1f8f_0000	endp

S083_TEXT	ends
	end
