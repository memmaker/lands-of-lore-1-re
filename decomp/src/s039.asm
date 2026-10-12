; s039: segment 1afa (TASM module)
	.386
S039_TEXT	segment word public use16 'CODE'
S039_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:S039_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
S039_TEXT	segment
	public	_fn_1afa_0000, _fn_1afa_0010
_fn_1afa_0000	proc	far
	db	1h, 2h, 1h, 0h, 7h, 6h, 7h, 0h, 3h, 2h, 3h, 4h, 5h, 6h, 5h, 4h	; 0
_fn_1afa_0000	endp

_fn_1afa_0010	proc	far
	db	0c8h, 0h, 0h, 0h	; 10: enter 0x0,0x0
	push	bx		; 14
	push	cx		; 15
	push	dx		; 16
	xor	bx,bx		; 17
	mov	dx,[bp+8h]		; 19
	mov	cx,[bp+0ch]		; 1c
	sub	dx,cx		; 1f
	jns	short L0026		; 21
	inc	bx		; 23
	neg	dx		; 24
L0026:
	shl	bx,1		; 26
	mov	ax,[bp+6h]		; 28
	mov	cx,[bp+0ah]		; 2b
	sub	cx,ax		; 2e
	jns	short L0035		; 30
	inc	bx		; 32
	neg	cx		; 33
L0035:
	cmp	cx,dx		; 35
	jc	short L003B		; 37
	xchg	cx,dx		; 39
L003B:
	rcl	bx,1		; 3b
	mov	ax,dx		; 3d
	inc	ax		; 3f
	shr	ax,1		; 40
	cmp	cx,ax		; 42
	rcl	bx,1		; 44
	xor	ax,ax		; 46
	mov	al,cs:[bx+0h]		; 48
	pop	dx		; 4d
	pop	cx		; 4e
	pop	bx		; 4f
	leave		; 50
	retf		; 51
_fn_1afa_0010	endp
S039_TEXT	ends
	end
