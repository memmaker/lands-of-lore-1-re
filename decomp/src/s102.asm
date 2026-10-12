; s102: WW library

	.386
	locals
S102_TEXT	segment word public use16 'CODE'
S102_TEXT	ends
	assume	cs:S102_TEXT


S102_TEXT	segment word public use16 'CODE'
	public	_fn_1fd1_000e, _fn_1fd1_0024, _fn_1fd1_003d

_fn_1fd1_000e	proc	far
	enter	0h,0h
	push	ds
	push	si
	xor	ax,ax
	cmp	word ptr [bp+8h],0h
	jz	short L0020
	lds	si,[bp+6h]
	lodsw
L0020:	pop	si
	pop	ds
	leave
	retf
_fn_1fd1_000e	endp

_fn_1fd1_0024	proc	far
	enter	0h,0h
	push	ds
	push	si
	push	dx
	mov	ax,[bp+0ah]
	lds	si,[bp+6h]
	mul	word ptr [si+3h]
	mov	al,ah
	mov	ah,dl
	pop	dx
	pop	si
	pop	ds
	leave
	retf
_fn_1fd1_0024	endp

_fn_1fd1_003d	proc	far
	enter	0h,0h
	push	ds
	push	si
	push	dx
	lds	si,[bp+6h]
	add	si,2h
	xor	ax,ax
	lodsb
	mul	word ptr [bp+0ah]
	mov	al,ah
	mov	ah,dl
	pop	dx
	pop	si
	pop	ds
	leave
	retf
_fn_1fd1_003d	endp

S102_TEXT	ends
	end
