; s039: direction from one map point to another (octant lookup on the signs and ratio of dx, dy; tools/asmgen.py)

	.386
	locals
S039_TEXT	segment byte public use16 'CODE'
S039_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:S039_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends


S039_TEXT	segment byte public use16 'CODE'
	public	_fn_1afa_0010
dirtab	db	1, 2, 1, 0, 7, 6, 7, 0, 3, 2, 3, 4, 5, 6, 5, 4
_fn_1afa_0010	proc	far
	enter	0,0
	push	bx
	push	cx
	push	dx
	xor	bx,bx
	mov	dx,[bp+8]
	mov	cx,[bp+0ch]
	sub	dx,cx
	jns	short L_0026
	inc	bx
	neg	dx
L_0026:
	shl	bx,1
	mov	ax,[bp+6]
	mov	cx,[bp+0ah]
	sub	cx,ax
	jns	short L_0035
	inc	bx
	neg	cx
L_0035:
	cmp	cx,dx
	jc	short L_003b
	xchg	cx,dx
L_003b:
	rcl	bx,1
	mov	ax,dx
	inc	ax
	shr	ax,1
	cmp	cx,ax
	rcl	bx,1
	xor	ax,ax
	mov	al,byte ptr cs:dirtab[bx]
	pop	dx
	pop	cx
	pop	bx
	leave
	retf
_fn_1afa_0010	endp
S039_TEXT	ends
	end
