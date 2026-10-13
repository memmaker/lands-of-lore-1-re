; s043: assembler screen-page helpers (fn_215f_001d = page segment; 0004 draws through the table at g_3940, 00e2 copies between pages; tools/asmgen.py)

	.386
	locals
S043_TEXT	segment byte public use16 'CODE'
S043_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:S043_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends

	extrn	_fn_215f_001d:far
	extrn	_g_3649:byte
	extrn	_g_3940:byte

S043_TEXT	segment byte public use16 'CODE'
	public	_fn_1b63_0004, _fn_1b63_00e2
_fn_1b63_0004	proc	far
	enter	2,0
	push	ax
	push	bx
	push	cx
	push	dx
	push	ds
	push	es
	push	di
	push	si
	push	word ptr _g_3649
	call	far ptr _fn_215f_001d
	add	sp,2
	mov	es,dx
	mov	di,[bp+6]
	mov	cx,[bp+0ah]
	cmp	cx,0
	jng	short L_0035
	cmp	di,140h
	jnl	short L_0035
	or	di,di
	jns	short L_0044
	jmp	short L_0038
L_0035:
	jmp	near ptr L_00d8
L_0038:
	add	di,cx
	cmp	di,0
	jng	short L_0035
	mov	cx,di
	mov	di,0
L_0044:
	mov	bx,cx
	add	bx,di
	cmp	bx,140h
	jl	short L_0053
	mov	cx,140h
	sub	cx,di
L_0053:
	mov	word ptr [bp-2],140h
	sub	[bp-2],cx
	mov	bx,[bp+8]
	mov	si,[bp+0ch]
	cmp	si,0
	jng	short L_00d8
	cmp	bx,140h
	jnl	short L_00d8
	or	bx,bx
	jns	short L_007c
	add	bx,si
	cmp	bx,0
	jng	short L_00d8
	mov	si,bx
	mov	bx,0
L_007c:
	mov	ax,si
	add	ax,bx
	cmp	ax,0c8h
	jl	short L_008a
	mov	si,0c8h
	sub	si,bx
L_008a:
	mov	dx,bx
	add	dx,di
	and	dx,1
	push	si
	shl	bx,1
	lds	si,dword ptr _g_3940
	mov	ax,[bx+si]
	add	di,ax
	pop	si
	mov	ax,[bp+0eh]
	mov	bx,dx
	mov	dh,cl
	and	dh,1
	shr	cx,1
	mov	[bp+0ah],cx
L_00ac:
	cmp	cx,0
	jnz	short L_00b6
	mov	cx,1
	jmp	short L_00be
L_00b6:
	mov	es:[bx+di],al
	add	di,2
	loop	short L_00b6
L_00be:
	cmp	dh,1
	jnz	short L_00cc
	cmp	bl,0
	jnz	short L_00cb
	stosb
	jmp	short L_00cc
L_00cb:
	inc	di
L_00cc:
	xor	bx,1
	add	di,[bp-2]
	mov	cx,[bp+0ah]
	dec	si
	jnz	short L_00ac
L_00d8:
	pop	si
	pop	di
	pop	es
	pop	ds
	pop	dx
	pop	cx
	pop	bx
	pop	ax
	leave
	retf
_fn_1b63_0004	endp

_fn_1b63_00e2	proc	far
	enter	0ah,0
	push	ax
	push	bx
	push	cx
	push	dx
	push	ds
	push	si
	push	es
	push	di
	push	word ptr [bp+14h]
	call	far ptr _fn_215f_001d
	add	sp,2
	mov	[bp-0ah],dx
	push	word ptr [bp+12h]
	call	far ptr _fn_215f_001d
	add	sp,2
	mov	[bp-8],dx
	mov	si,[bp+6]
	mov	ax,[bp+8]
	mov	dx,140h
	mul	dx
	add	si,ax
	mov	di,[bp+0ah]
	mov	ax,[bp+0ch]
	mov	dx,140h
	mul	dx
	add	di,ax
	les	bx,dword ptr [bp+16h]
	mov	word ptr [bp-6],es
	mov	es,word ptr [bp-0ah]
	mov	dx,[bp+10h]
L_0130:
	mov	[bp-2],si
	mov	[bp-4],di
	mov	cx,[bp+0eh]
L_0139:
	mov	ds,word ptr [bp-8]
	lodsb
	mov	ds,word ptr [bp-6]
	xlatb
	stosb
	loop	short L_0139
	mov	si,[bp-2]
	add	si,140h
	mov	di,[bp-4]
	add	di,140h
	dec	dx
	jnz	short L_0130
	pop	di
	pop	es
	pop	si
	pop	ds
	pop	dx
	pop	cx
	pop	bx
	pop	ax
	leave
	retf
_fn_1b63_00e2	endp
S043_TEXT	ends
	end
