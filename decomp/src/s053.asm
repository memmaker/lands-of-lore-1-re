; s053: WW library -- clear a page to colour 0 (fn_0004 page, fn_0031 current page g_3649) (assembler module; drafted from the original bytes)

	.386
	locals
S053_TEXT	segment word public use16 'CODE'
S053_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S053_TEXT,ds:DGROUP

	extrn	_g_3649:word
	extrn	_fn_215f_001d:far

S053_TEXT	segment word public use16 'CODE'
	public	_fn_1e04_0004, _fn_1e04_0031

_fn_1e04_0004	proc	far
	enter	0h,0h
	push	ax
	push	cx
	push	dx
	push	es
	push	di
	cld
	push	word ptr [bp+6h]
	call	far ptr _fn_215f_001d
	add	sp,2h
	mov	es,dx
	xor	di,di
	pushad
	xor	eax,eax
	mov	cx,3e80h
	rep	stosd
	popad
	pop	di
	pop	es
	pop	dx
	pop	cx
	pop	ax
	leave
	retf

_fn_1e04_0004	endp
_fn_1e04_0031	proc	far
	push	word ptr _g_3649
	push	cs
	call	near ptr _fn_1e04_0004
	add	sp,2h
	retf
_fn_1e04_0031	endp

S053_TEXT	ends
	end
