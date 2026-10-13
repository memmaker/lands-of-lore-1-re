; s114: WW library

	.386
	locals
S114_TEXT	segment word public use16 'CODE'
S114_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S114_TEXT,ds:DGROUP

	extrn	_g_2af8:word

S114_TEXT	segment word public use16 'CODE'
	public	_fn_2037_0002

_fn_2037_0002	proc	far
	enter	0h,0h
	push	ebx
	mov	ax,[bp+6h]
	mov	dx,[bp+8h]
	cmp	dx,word ptr _g_2af8
	jz	short L001a
	cmp	dx,0f000h
	jc	short L0022
L001a:	add	ax,[bp+0ah]
	adc	dx,[bp+0ch]
	jmp	short L0043
L0022:	movzx	ebx,word ptr [bp+8h]
	shl	ebx,4h
	mov	word ptr [bp+8h],0h
	add	ebx,[bp+6h]
	add	ebx,[bp+0ah]
	mov	ax,bx
	and	ax,0fh
	shr	ebx,4h
	mov	dx,bx
L0043:	pop	ebx
	leave
	retf
_fn_2037_0002	endp

S114_TEXT	ends
	end
