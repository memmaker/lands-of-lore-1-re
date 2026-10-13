; s078: WW library

	.386
	locals
S078_TEXT	segment word public use16 'CODE'
S078_TEXT	ends
	assume	cs:S078_TEXT


S078_TEXT	segment word public use16 'CODE'
	public	_fn_1f84_000e

_fn_1f84_000e	proc	far
	push	ds
	mov	[bp-44h],cx
	lds	bx,[bp-14h]
	mov	cx,[bp-42h]
L0018:	xlatb
	loop	L0018
	or	al,al
	jz	short L0022
	mov	es:[di],al
L0022:	mov	cx,[bp-44h]
	pop	ds
	retf
_fn_1f84_000e	endp

S078_TEXT	ends
	end
