; s142: WW library -- vertical retrace
;
; int  fn_2345_0000(void)        VGA status bit 3 (in retrace)
; void fn_2345_0009(int state)   wait until the retrace bit equals state, then until it changes

	.386
	locals
S142_TEXT	segment word public use16 'CODE'
	assume	cs:S142_TEXT
	public	_fn_2345_0000, _fn_2345_0009

_fn_2345_0000	proc	far
	mov	dx,3dah
	in	al,dx
	and	al,8
	xor	ah,ah
	ret
_fn_2345_0000	endp

_fn_2345_0009	proc	far
	enter	0,0
	push	ax
	push	bx
	push	dx
	mov	bx,[bp+6]
	mov	dx,3dah
	and	bl,1
	shl	bl,3
@@1:	in	al,dx
	and	al,8
	xor	al,bl
	jz	@@1
@@2:	in	al,dx
	and	al,8
	xor	al,bl
	jnz	@@2
	pop	dx
	pop	bx
	pop	ax
	leave
	ret
_fn_2345_0009	endp

S142_TEXT	ends
	end
