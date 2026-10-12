; s062: WW library -- XOR-delta (WSA/format40) decoding onto a buffer (assembler module; drafted from the original bytes)

	.386
	locals
S062_TEXT	segment word public use16 'CODE'
S062_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S062_TEXT,ds:DGROUP

	extrn	_fn_2279_02b5:far

S062_TEXT	segment word public use16 'CODE'
	public	_fn_1e76_0008, _fn_1e76_0029, _fn_1e76_00a4, _fn_1e76_015e, _fn_1e76_0213

_fn_1e76_0008	proc	far
	push	ax
	push	dx
	push	ds
	push	si
	call	far ptr _fn_2279_02b5
	add	sp,4h
	mov	ds,dx
	mov	si,ax
	push	es
	push	di
	call	far ptr _fn_2279_02b5
	add	sp,4h
	mov	es,dx
	mov	di,ax
	pop	dx
	pop	ax
	retf

_fn_1e76_0008	endp
_fn_1e76_0029	proc	far
	enter	0h,0h
	push	bx
	push	cx
	push	dx
	push	di
	push	ds
	push	es
	push	si
	les	di,[bp+6h]
	lds	si,[bp+0ah]
	push	cs
	call	near ptr _fn_1e76_0008
	cld
	xor	ax,ax
	mov	cx,ax
L_0043:
	lodsb
	or	al,al
	jz	short L_0055
	js	short L_0061
	mov	cl,al
L_004c:
	lodsb
	xor	es:[di],al
	inc	di
	loop	L_004c
	jmp	short L_0043
L_0055:
	mov	cl,[si]
	inc	si
	lodsb
L_0059:
	xor	es:[di],al
	inc	di
	loop	L_0059
	jmp	short L_0043
L_0061:
	sub	al,80h
	jz	short L_0069
	add	di,ax
	jmp	short L_0043
L_0069:
	lodsw
	or	ax,ax
	jng	short L_0074
	add	di,ax
	xor	ah,ah
	jmp	short L_0043
L_0074:
	jz	short L_009b
	sub	ax,8000h
	test	ax,4000h
	jz	short L_008e
	sub	ax,4000h
	mov	cx,ax
	lodsb
L_0084:
	xor	es:[di],al
	inc	di
	loop	L_0084
	xor	ah,ah
	jmp	short L_0043
L_008e:
	mov	cx,ax
L_0090:
	lodsb
	xor	es:[di],al
	inc	di
	loop	L_0090
	xor	ah,ah
	jmp	short L_0043
L_009b:
	pop	si
	pop	es
	pop	ds
	pop	di
	pop	dx
	pop	cx
	pop	bx
	leave
	retf

_fn_1e76_0029	endp
_fn_1e76_00a4	proc	far
	enter	0h,0h
	push	di
L_00a9:
	lodsb
	or	al,al
	jz	short L_00c8
	js	short L_00e1
	mov	cl,al
L_00b2:
	lodsb
	xor	es:[di],al
	inc	di
	inc	dx
	cmp	dx,bx
	jnz	short L_00c4
	xor	dx,dx
	pop	di
	add	di,140h
	push	di
L_00c4:
	loop	L_00b2
	jmp	short L_00a9
L_00c8:
	mov	cl,[si]
	inc	si
	lodsb
L_00cc:
	xor	es:[di],al
	inc	di
	inc	dx
	cmp	dx,bx
	jnz	short L_00dd
	xor	dx,dx
	pop	di
	add	di,140h
	push	di
L_00dd:
	loop	L_00cc
	jmp	short L_00a9
L_00e1:
	sub	al,80h
	jz	short L_00fb
	add	di,ax
	add	dx,ax
L_00e9:
	cmp	dx,bx
	jc	short L_00f9
	sub	dx,bx
	pop	di
	add	di,140h
	push	di
	add	di,dx
	jmp	short L_00e9
L_00f9:
	jmp	short L_00a9
L_00fb:
	lodsw
	or	ax,ax
	jng	short L_0118
	add	di,ax
	add	dx,ax
L_0104:
	cmp	dx,bx
	jc	short L_0114
	sub	dx,bx
	pop	di
	add	di,140h
	push	di
	add	di,dx
	jmp	short L_0104
L_0114:
	xor	ah,ah
	jmp	short L_00a9
L_0118:
	jz	short L_015b
	sub	ax,8000h
	test	ax,4000h
	jz	short L_0140
	sub	ax,4000h
	mov	cx,ax
	lodsb
L_0128:
	xor	es:[di],al
	inc	di
	inc	dx
	cmp	dx,bx
	jnz	short L_0139
	xor	dx,dx
	pop	di
	add	di,140h
	push	di
L_0139:
	loop	L_0128
	xor	ah,ah
	jmp	near ptr L_00a9
L_0140:
	mov	cx,ax
L_0142:
	lodsb
	xor	es:[di],al
	inc	di
	inc	dx
	cmp	dx,bx
	jnz	short L_0154
	xor	dx,dx
	pop	di
	add	di,140h
	push	di
L_0154:
	loop	L_0142
	xor	ah,ah
	jmp	near ptr L_00a9
L_015b:
	pop	di
	leave
	retf

_fn_1e76_00a4	endp
_fn_1e76_015e	proc	far
	push	di
L_015f:
	lodsb
	or	al,al
	jz	short L_017e
	js	short L_0197
	mov	cl,al
L_0168:
	lodsb
	mov	es:[di],al
	inc	di
	inc	dx
	cmp	dx,bx
	jnz	short L_017a
	xor	dx,dx
	pop	di
	add	di,140h
	push	di
L_017a:
	loop	L_0168
	jmp	short L_015f
L_017e:
	mov	cl,[si]
	inc	si
	lodsb
L_0182:
	mov	es:[di],al
	inc	di
	inc	dx
	cmp	dx,bx
	jnz	short L_0193
	xor	dx,dx
	pop	di
	add	di,140h
	push	di
L_0193:
	loop	L_0182
	jmp	short L_015f
L_0197:
	sub	al,80h
	jz	short L_01b1
	add	di,ax
	add	dx,ax
L_019f:
	cmp	dx,bx
	jc	short L_01af
	sub	dx,bx
	pop	di
	add	di,140h
	push	di
	add	di,dx
	jmp	short L_019f
L_01af:
	jmp	short L_015f
L_01b1:
	lodsw
	or	ax,ax
	jng	short L_01ce
	add	di,ax
	add	dx,ax
L_01ba:
	cmp	dx,bx
	jc	short L_01ca
	sub	dx,bx
	pop	di
	add	di,140h
	push	di
	add	di,dx
	jmp	short L_01ba
L_01ca:
	xor	ah,ah
	jmp	short L_015f
L_01ce:
	jz	short L_0211
	sub	ax,8000h
	test	ax,4000h
	jz	short L_01f6
	sub	ax,4000h
	mov	cx,ax
	lodsb
L_01de:
	mov	es:[di],al
	inc	di
	inc	dx
	cmp	dx,bx
	jnz	short L_01ef
	xor	dx,dx
	pop	di
	add	di,140h
	push	di
L_01ef:
	loop	L_01de
	xor	ah,ah
	jmp	near ptr L_015f
L_01f6:
	mov	cx,ax
L_01f8:
	lodsb
	mov	es:[di],al
	inc	di
	inc	dx
	cmp	dx,bx
	jnz	short L_020a
	xor	dx,dx
	pop	di
	add	di,140h
	push	di
L_020a:
	loop	L_01f8
	xor	ah,ah
	jmp	near ptr L_015f
L_0211:
	pop	di
	retf

_fn_1e76_015e	endp
_fn_1e76_0213	proc	far
	enter	0h,0h
	push	bx
	push	cx
	push	dx
	push	di
	push	ds
	push	es
	push	si
	les	di,[bp+6h]
	lds	si,[bp+0ah]
	push	cs
	call	near ptr _fn_1e76_0008
	mov	bx,[bp+0eh]
	cld
	xor	ax,ax
	mov	cx,ax
	mov	dx,ax
	cmp	word ptr [bp+10h],0h
	jz	short L_023e
	push	cs
	call	near ptr _fn_1e76_015e
	jmp	short L_0242
L_023e:
	push	cs
	call	near ptr _fn_1e76_00a4
L_0242:
	pop	si
	pop	es
	pop	ds
	pop	di
	pop	dx
	pop	cx
	pop	bx
	leave
	retf
_fn_1e76_0213	endp

S062_TEXT	ends
	end
