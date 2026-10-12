; s052: WW library -- copy a whole 320x200 page to another (unless both name the same page pair)
;
; void fn_1dff_0008(int src, int dst)

	.386
	locals
	extrn	_fn_215f_0003:far, _fn_215f_001d:far
S052_TEXT	segment word public use16 'CODE'
	assume	cs:S052_TEXT
	public	_fn_1dff_0008

_fn_1dff_0008	proc	far
	enter	0,0
	push	ds
	push	es
	pushad
	mov	ax,[bp+6]
	and	ax,0fffeh
	mov	bx,[bp+8]
	db	81h,0e3h	; and bx,0fffeh in its long imm16 form (TASM would shorten it)
	dw	0fffeh
	cmp	ax,bx
	jz	short @@out
	push	word ptr [bp+6]
	call	far ptr _fn_215f_0003
	add	sp,2
	or	dx,dx
	jz	short @@out
	push	dx
	push	word ptr [bp+8]
	call	far ptr _fn_215f_001d
	add	sp,2
	or	dx,dx
	jz	short @@out
	mov	es,dx
	pop	ds
	xor	si,si
	xor	di,di
	mov	cx,3e80h
	rep	movsd
@@out:	popad
	pop	es
	pop	ds
	leave
	ret
_fn_1dff_0008	endp

S052_TEXT	ends
	end
