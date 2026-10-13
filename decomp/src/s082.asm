; s082: WW library

	.386
	locals
S082_TEXT	segment word public use16 'CODE'
S082_TEXT	ends
	assume	cs:S082_TEXT


S082_TEXT	segment word public use16 'CODE'
	public	_fn_1f8c_000a

_fn_1f8c_000a	proc	far
	push	ds
	push	cx
	lds	bx,[bp-1ch]
	xlatb
	cmp	al,0ffh
	jnz	short L001d
	lds	bx,[bp-28h]
	mov	al,es:[di]
	xlatb
	jmp	short L0026
L001d:	lds	bx,[bp-14h]
	mov	cx,[bp-42h]
L0023:	xlatb
	loop	L0023
L0026:	or	al,al
	jz	short L002d
	mov	es:[di],al
L002d:	pop	cx
	pop	ds
	retf
_fn_1f8c_000a	endp

S082_TEXT	ends
	end
