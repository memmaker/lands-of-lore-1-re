; s068: WW library -- write a pixel of the current page
;
; void fn_1f20_0000(int x, int y, int c)   page[g_3944[y] + x] = c when on screen

	.386
	locals
S068_TEXT	segment word public use16 'CODE'
S068_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S068_TEXT,ds:DGROUP

	extrn	_g_3649:word, _g_3944:word
	extrn	_fn_215f_001d:far

S068_TEXT	segment word public use16 'CODE'
	public	_fn_1f20_0000

_fn_1f20_0000	proc	far
	enter	0,0
	push	ax
	push	bx
	push	dx
	push	es
	push	di
	push	_g_3649
	call	far ptr _fn_215f_001d
	add	sp,2
	mov	es,dx
	xor	di,di
	mov	bx,[bp+8]
	cmp	bx,0c8h
	jnc	short @@out
	add	bx,bx
	add	di,_g_3944[bx]
	mov	bx,[bp+6]
	cmp	bx,140h
	jnc	short @@out
	add	di,bx
	mov	bx,[bp+0ah]
	mov	es:[di],bl
@@out:	pop	di
	pop	es
	pop	dx
	pop	bx
	pop	ax
	leave
	ret
_fn_1f20_0000	endp

S068_TEXT	ends
	end
