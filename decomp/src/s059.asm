; s059: WW library -- read a pixel of the current page
;
; int fn_1e6f_000a(int x, int y)   page[g_3944[y] + x], 0 when off screen

	.386
	locals
S059_TEXT	segment word public use16 'CODE'
S059_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S059_TEXT,ds:DGROUP

	extrn	_g_3649:word, _g_3944:word
	extrn	_fn_215f_001d:far

S059_TEXT	segment word public use16 'CODE'
	public	_fn_1e6f_000a

_fn_1e6f_000a	proc	far
	enter	0,0
	push	bx
	push	dx
	push	es
	push	di
	push	_g_3649
	call	far ptr _fn_215f_001d
	add	sp,2
	mov	es,dx
	xor	di,di
	xor	ax,ax
	mov	bx,[bp+8]
	cmp	bx,0c8h
	jnc	short @@out
	add	bx,bx
	add	di,_g_3944[bx]
	mov	bx,[bp+6]
	cmp	bx,140h
	jnc	short @@out
	add	di,bx
	movzx	ax,byte ptr es:[di]
@@out:	pop	di
	pop	es
	pop	dx
	pop	bx
	leave
	ret
_fn_1e6f_000a	endp

S059_TEXT	ends
	end
