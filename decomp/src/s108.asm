; s108: WW library

	.386
	locals
S108_TEXT	segment word public use16 'CODE'
S108_TEXT	ends
	assume	cs:S108_TEXT


S108_TEXT	segment word public use16 'CODE'
	public	_fn_2025_000c

_fn_2025_000c	proc	far
	xor	ah,ah
L000e:	lodsb
	or	al,al
	jz	short L001b
	call	dword ptr [bp-4h]
	dec	di
	loop	L000e
	jmp	short L0022
L001b:	lodsb
	sub	di,ax
	sub	cx,ax
	jg	short L000e
L0022:	retf
_fn_2025_000c	endp

S108_TEXT	ends
	end
