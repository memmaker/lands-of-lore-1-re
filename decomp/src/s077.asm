; s077: WW library

	.386
	locals
S077_TEXT	segment word public use16 'CODE'
S077_TEXT	ends
	assume	cs:S077_TEXT


S077_TEXT	segment word public use16 'CODE'
	public	_fn_1f84_000a

_fn_1f84_000a	proc	far
	mov	es:[di],al
	retf
_fn_1f84_000a	endp

S077_TEXT	ends
	end
