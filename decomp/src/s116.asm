; s116: WW library

	.386
	locals
S116_TEXT	segment word public use16 'CODE'
S116_TEXT	ends
	assume	cs:S116_TEXT


S116_TEXT	segment word public use16 'CODE'
	public	_fn_2093_000e

_fn_2093_000e	proc	far
	enter	0h,0h
	push	ax
	push	di
	push	ds
	push	dx
	push	si
	cld
	lds	si,[bp+6h]
L001b:	lodsb
	or	al,al
	jz	short L0028
	mov	dl,al
	mov	ah,6h
	int	21h
	jmp	short L001b
L0028:	pop	si
	pop	dx
	pop	ds
	pop	di
	pop	ax
	leave
	retf
_fn_2093_000e	endp

S116_TEXT	ends
	end
