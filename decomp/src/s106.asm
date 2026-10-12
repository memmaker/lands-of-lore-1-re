; s106: WW library

	.386
	locals
S106_TEXT	segment word public use16 'CODE'
S106_TEXT	ends
	assume	cs:S106_TEXT


S106_TEXT	segment word public use16 'CODE'
	public	_fn_2022_0004

_fn_2022_0004	proc	far
L0004:	lodsb
	or	al,al
	jz	short L0011
	call	far ptr [bp-4h]
	inc	di
	loop	L0004
	jmp	short L0018
L0011:	lodsb
	add	di,ax
	sub	cx,ax
	jg	short L0004
L0018:	retf
_fn_2022_0004	endp

S106_TEXT	ends
	end
