; s074: WW library -- translate one pixel through the caller's table
; (fragment entered with the caller's frame: bp-relative operands are the caller's locals)

	.386
	locals
S074_TEXT	segment word public use16 'CODE'
	assume	cs:S074_TEXT
	public	_fn_1f7f_0000

_fn_1f7f_0000	proc	far
	push	ds
	lds	bx,[bp-1ch]
	xlatb
	mov	es:[di],al
	pop	ds
	ret
_fn_1f7f_0000	endp

S074_TEXT	ends
	end
