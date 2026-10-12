; s084: WW library

	.386
	locals
S084_TEXT	segment word public use16 'CODE'
S084_TEXT	ends
	assume	cs:S084_TEXT


S084_TEXT	segment word public use16 'CODE'
	public	_fn_1f93_000e

_fn_1f93_000e	proc	far
	mov	es:[di],al
	retf
_fn_1f93_000e	endp

S084_TEXT	ends
	end
