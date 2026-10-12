; s075: WW library -- translate a pixel through two caller tables (second one [bp-42h] times), skip colour 0
; (fragment entered with the caller's frame: bp-relative operands are the caller's locals)

	.386
	locals
S075_TEXT	segment word public use16 'CODE'
	assume	cs:S075_TEXT
	public	_fn_1f7f_000a

_fn_1f7f_000a	proc	far
	push	ds
	push	cx
	lds	bx,[bp-1ch]
	xlatb
	lds	bx,[bp-14h]
	mov	cx,[bp-42h]
@@1:	xlatb
	loop	@@1
	or	al,al
	jz	short @@2
	mov	es:[di],al
@@2:	pop	cx
	pop	ds
	ret
_fn_1f7f_000a	endp

S075_TEXT	ends
	end
