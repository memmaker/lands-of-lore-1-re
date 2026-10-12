; s076: WW library

	.386
	locals
S076_TEXT	segment word public use16 'CODE'
S076_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S076_TEXT,ds:DGROUP

	extrn	_g_35c8:word, _g_35ca:word, _g_35cc:word

S076_TEXT	segment word public use16 'CODE'
	public	_fn_1f81_0004

_fn_1f81_0004	proc	far
	mov	bx,fs:_g_35cc
	add	bx,fs:_g_35ca
	or	bh,bh
	jnz	short L0021
	mov	fs:_g_35cc,bx
	push	ds
	lds	bx,[bp-1ch]
	xlatb
	mov	es:[di],al
	pop	ds
	retf
L0021:	xor	bh,bh
	mov	fs:_g_35cc,bx
	add	di,fs:_g_35c8
	mov	al,es:[di]
	sub	di,fs:_g_35c8
	mov	es:[di],al
	retf
_fn_1f81_0004	endp

S076_TEXT	ends
	end
