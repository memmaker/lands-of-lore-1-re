; s134: WW library -- detect Windows / DOS multitasker through int 2Fh, result in g_379a
;
; void fn_22d7_000a(void)   g_379a = 1..6

	.386
	locals
S134_TEXT	segment word public use16 'CODE'
S134_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S134_TEXT,ds:DGROUP

	extrn	_g_379a:word

S134_TEXT	segment word public use16 'CODE'
	public	_fn_22d7_000a

_fn_22d7_000a	proc	far
	push	bx
	push	cx
	push	dx
	push	es
	push	di
	mov	ax,160ah
	int	2fh
	or	ax,ax
	jz	short @@w31
	mov	ax,1600h
	int	2fh
	mov	bl,al
	mov	ax,4
	test	bl,7fh
	jnz	short @@set
	mov	ax,4680h
	int	2fh
	or	ax,ax
	jnz	short @@one
	mov	ax,4b02h
	push	bx
	push	es
	push	di
	xor	bx,bx
	mov	di,bx
	mov	es,bx
	int	2fh
	pop	di
	pop	es
	pop	bx
	or	ax,ax
	jz	short @@one
	mov	ax,1605h
	int	2fh
	mov	ax,5
	cmp	cx,-1
	jz	short @@set
	mov	ax,1606h
	int	2fh
	mov	ax,6
	jmp	short @@set
@@w31:	mov	ax,2
	cmp	cx,2
	jz	short @@set
	mov	ax,3
	jmp	short @@set
@@one:	mov	ax,1
@@set:	mov	_g_379a,ax
	pop	di
	pop	es
	pop	dx
	pop	cx
	pop	bx
	ret
_fn_22d7_000a	endp

S134_TEXT	ends
	end
