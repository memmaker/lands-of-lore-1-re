; s057: WW library -- rectangle fill / xor on the current page (x1, y1, x2, y2, colour)
;
; void fn_1e59_000c(int x1, int y1, int x2, int y2, int c)   xor variant (lodsb from ds:si, as in the original)
; void fn_1e59_001d(int x1, int y1, int x2, int y2, int c)   solid fill

	.386
	locals
S057_TEXT	segment word public use16 'CODE'
S057_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S057_TEXT,ds:DGROUP

	extrn	_g_3649:word
	extrn	_fn_215f_001d:far

S057_TEXT	segment word public use16 'CODE'
	public	_fn_1e59_000c, _fn_1e59_001d

_fn_1e59_000c	proc	far
	enter	2,0
	push	ax
	push	bx
	push	cx
	push	dx
	push	es
	push	di
	mov	word ptr [bp-2],1
	jmp	short fill_common
_fn_1e59_000c	endp

_fn_1e59_001d	proc	far
	enter	2,0
	push	ax
	push	bx
	push	cx
	push	dx
	push	es
	push	di
	mov	word ptr [bp-2],0
fill_common:
	cld
	push	_g_3649
	call	far ptr _fn_215f_001d
	add	sp,2
	mov	es,dx
	xor	di,di
	mov	ax,[bp+6]
	cmp	ax,140h
	jnc	short @@out
	mov	bx,[bp+0ah]
	cmp	bx,140h
	jnc	short @@out
	cmp	ax,bx
	jna	short @@1
	xchg	ax,bx
@@1:	mov	cx,[bp+8]
	cmp	cx,0c8h
	jnc	short @@out
	mov	dx,[bp+0ch]
	cmp	dx,0c8h
	jnc	short @@out
	cmp	cx,dx
	jna	short @@2
	xchg	cx,dx
@@2:	sub	dx,cx
	inc	dx
	sub	bx,ax
	inc	bx
	push	dx
	push	ax
	mov	ax,140h
	mul	cx
	add	di,ax
	pop	dx
	add	di,dx
	pop	dx
	mov	ax,140h
	sub	ax,bx
	xchg	ax,[bp+0eh]
	mov	ah,al
	cmp	word ptr [bp-2],0
	jz	short @@fill
@@xor:	mov	cx,bx
@@x1:	lodsb
	xor	al,ah
	stosb
	loop	@@x1
	add	di,[bp+0eh]
	dec	dx
	jg	short @@xor
	jmp	short @@out
@@fill:	mov	cx,bx
	shr	cx,1
	rep	stosw
	adc	cx,0
	rep	stosb
	add	di,[bp+0eh]
	dec	dx
	jg	short @@fill
@@out:	pop	di
	pop	es
	pop	dx
	pop	cx
	pop	bx
	pop	ax
	leave
	ret
_fn_1e59_001d	endp

S057_TEXT	ends
	end
