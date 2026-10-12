; s072: WW library -- linear offset helper (assembler: enter frame, saves dx)
;
; int fn_1f6a_0002(int x, int y)   (x-1 < 320 && y-1 < 200) ? x*y : 0

	.386
	locals
S072_TEXT	segment byte public use16 'CODE'
	assume	cs:S072_TEXT
	public	_fn_1f6a_0002

_fn_1f6a_0002	proc	far
	enter	0,0
	push	dx
	xor	ax,ax
	mov	dx,[bp+6]
	dec	dx
	cmp	dx,140h
	jnc	short @@out
	inc	dx
	mov	ax,[bp+8]
	dec	ax
	cmp	ax,0c8h
	jnc	short @@out
	inc	ax
	mul	dx
@@out:	pop	dx
	leave
	ret
_fn_1f6a_0002	endp

S072_TEXT	ends
	end
