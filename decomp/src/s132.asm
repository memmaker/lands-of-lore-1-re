; s132: WW library -- far/huge/XMS memory copies
;
; void fn_2279_0008(void huge *src, void huge *dst, unsigned long n)   memmove of linear addresses
; void fn_2279_00fa / 0118 / 0136(src, dst, n)    forward to fn_19ba_000a (save ds/es)
; void fn_2279_0154(src, dst, n), fn_2279_01af(...)   copy in 48K pieces through the handle helpers in s147
; void fn_2279_0211(void)                          nothing
; void fn_2279_025b(src, dst, n)    pick a copier from the table by whether src/dst lie at F000/FE00 and above
; void far *fn_2279_02b5(void far *p)   normalize p (below F000:0)

	.386
	locals
S132_TEXT	segment word public use16 'CODE'
S132_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	extrn	_g_2af4:word
	extrn	_fn_19ba_000a:far, _fn_19ba_0053:far, _fn_19ba_0073:far
	extrn	_fn_2365_0687:far, _fn_2365_07a1:far, _fn_2365_0884:far

S132_TEXT	segment word public use16 'CODE'
	assume	cs:S132_TEXT,ds:DGROUP
	public	_fn_2279_0008, _fn_2279_00fa, _fn_2279_0118, _fn_2279_0136, _fn_2279_0154, _fn_2279_01af
	public	_fn_2279_0211, _fn_2279_025b, _fn_2279_02b5

_fn_2279_0008	proc	far
	enter	0,0
	push	ds
	push	es
	mov	edx,[bp+0eh]
	xor	eax,eax
	xchg	ax,[bp+8]
	shl	eax,4
	add	eax,[bp+6]
	xor	ebx,ebx
	xchg	bx,[bp+0ch]
	shl	ebx,4
	add	ebx,[bp+0ah]
	cmp	eax,ebx
	jz	@@out
	ja	short @@fwd
	std
	add	eax,edx
	add	ebx,edx
@@bk:	mov	ecx,0fff0h
	cmp	ecx,edx
	jc	short @@b1
	mov	ecx,edx
@@b1:	sub	eax,ecx
	push	eax
	shr	eax,4
	mov	ds,ax
	pop	eax
	mov	si,ax
	and	si,0fh
	add	si,cx
	sub	ebx,ecx
	push	ebx
	shr	ebx,4
	mov	es,bx
	pop	ebx
	mov	di,bx
	and	di,0fh
	add	di,cx
	sub	edx,ecx
	test	cx,3
	jnz	short @@b2
	sub	si,4
	sub	di,4
	shr	cx,2
	rep	movsd
	jmp	short @@b3
@@b2:	sub	si,2
	sub	di,2
	shr	cx,1
	rep	movsw
	adc	cx,0
	inc	di
	inc	si
	rep	movsb
@@b3:	or	edx,edx
	jnz	short @@bk
	cld
	jmp	short @@out
@@fwd:	cld
@@fw:	mov	ecx,0fff0h
	cmp	ecx,edx
	jc	short @@f1
	mov	ecx,edx
@@f1:	push	eax
	shr	eax,4
	mov	ds,ax
	pop	eax
	mov	si,ax
	and	si,0fh
	push	ebx
	shr	ebx,4
	mov	es,bx
	pop	ebx
	mov	di,bx
	and	di,0fh
	sub	edx,ecx
	add	eax,ecx
	add	ebx,ecx
	test	cx,3
	jnz	short @@f2
	shr	cx,2
	rep	movsd
	jmp	short @@f3
@@f2:	shr	cx,1
	rep	movsw
	adc	cx,0
	rep	movsb
@@f3:	or	edx,edx
	jnz	short @@fw
@@out:	pop	es
	pop	ds
	leave
	ret
_fn_2279_0008	endp

_fn_2279_00fa	proc	far
	enter	4,0
	push	es
	push	ds
	push	dword ptr [bp+0eh]
	push	dword ptr [bp+0ah]
	push	dword ptr [bp+6]
	call	far ptr _fn_19ba_000a
	add	sp,0ch
	pop	ds
	pop	es
	leave
	ret
_fn_2279_00fa	endp

_fn_2279_0118	proc	far
	enter	4,0
	push	ds
	push	es
	push	dword ptr [bp+0eh]
	push	dword ptr [bp+0ah]
	push	dword ptr [bp+6]
	call	far ptr _fn_19ba_000a
	add	sp,0ch
	pop	es
	pop	ds
	leave
	ret
_fn_2279_0118	endp

_fn_2279_0136	proc	far
	enter	0,0
	push	ds
	push	es
	push	dword ptr [bp+0eh]
	push	dword ptr [bp+0ah]
	push	dword ptr [bp+6]
	call	far ptr _fn_19ba_000a
	add	sp,0ch
	pop	es
	pop	ds
	leave
	ret
_fn_2279_0136	endp

_fn_2279_0154	proc	far
	enter	0,0
	push	ds
	push	es
	inc	_g_2af4
	mov	edx,[bp+0eh]
	mov	eax,[bp+6]
	mov	ebx,[bp+0ah]
@@loop:	mov	ecx,0c000h
	cmp	ecx,edx
	jc	short @@1
	mov	ecx,edx
@@1:	pushad
	push	ecx
	push	ebx
	push	eax
	call	far ptr _fn_19ba_0053
	add	sp,4
	push	dx
	push	ax
	call	far ptr _fn_2365_0687
	call	far ptr _fn_19ba_0073
	add	sp,0ch
	popad
	sub	edx,ecx
	add	eax,ecx
	add	ebx,ecx
	or	edx,edx
	jnz	short @@loop
	dec	_g_2af4
	pop	es
	pop	ds
	leave
	ret
_fn_2279_0154	endp

_fn_2279_01af	proc	far
	enter	0,0
	push	ds
	push	es
	inc	_g_2af4
	mov	edx,[bp+0eh]
	mov	eax,[bp+6]
	mov	ebx,[bp+0ah]
@@loop:	mov	ecx,0c000h
	cmp	ecx,edx
	jc	short @@1
	mov	ecx,edx
@@1:	pushad
	push	ecx
	push	eax
	push	ebx
	call	far ptr _fn_19ba_0053
	add	sp,4
	pop	ebx
	push	dx
	push	ax
	push	ebx
	call	far ptr _fn_2365_07a1
	add	sp,4
	call	far ptr X_fn_19ba_0073
	add	sp,8
	popad
	sub	edx,ecx
	add	eax,ecx
	add	ebx,ecx
	or	edx,edx
	jnz	short @@loop
	dec	_g_2af4
	pop	es
	pop	ds
	leave
	ret
_fn_2279_01af	endp

_fn_2279_0211	proc	far
	enter	0,0
	push	ds
	push	es
	pop	es
	pop	ds
	leave
	ret
_fn_2279_0211	endp

copytab	label	dword
	dd	_fn_2279_0136
	dd	_fn_2279_0154
	dd	_fn_2279_0211
	dd	_fn_2279_00fa
	dd	_fn_2279_01af
	dd	X_fn_2365_0884
	dd	_fn_2279_0211
	dd	X_fn_2365_07a1
	dd	_fn_2279_0211
	dd	_fn_2279_0211
	dd	_fn_2279_0211
	dd	_fn_2279_0211
	dd	_fn_2279_0118
	dd	X_fn_2365_0687
	dd	_fn_2279_0211
	dd	_fn_2279_0008

_fn_2279_025b	proc	far
	enter	0,0
	push	ds
	push	es
	pushad
	cmp	dword ptr [bp+0eh],0
	jz	short @@out
	cmp	dword ptr [bp+6],0
	jz	short @@out
	cmp	dword ptr [bp+0ah],0
	jz	short @@out
	xor	bx,bx
	cmp	word ptr [bp+8],0f000h
	rcl	bx,1
	cmp	word ptr [bp+8],0fe00h
	rcl	bx,1
	cmp	word ptr [bp+0ch],0f000h
	rcl	bx,1
	cmp	word ptr [bp+0ch],0fe00h
	rcl	bx,1
	shl	bx,2
	add	bx,offset copytab
	push	dword ptr [bp+0eh]
	push	dword ptr [bp+0ah]
	push	dword ptr [bp+6]
	call	dword ptr cs:[bx]
	add	sp,0ch
@@out:	popad
	pop	es
	pop	ds
	leave
	ret
_fn_2279_025b	endp

_fn_2279_02b5	proc	far
	enter	0,0
	mov	ax,[bp+6]
	mov	dx,[bp+8]
	cmp	dx,0f000h
	jnc	short @@out
	shr	ax,4
	add	dx,ax
	mov	ax,[bp+6]
	and	ax,0fh
@@out:	leave
	ret
_fn_2279_02b5	endp

S132_TEXT	ends
; Forward-referenced aliases: TASM defers the fixups of a line that holds a forward reference (from that
; reference to the end of the line) to a later flush, which reproduces the original relocation order
; (call at 01e9, then the three external table entries, then the table's own-segment entries).
X_fn_2365_0884	equ	_fn_2365_0884
X_fn_2365_07a1	equ	_fn_2365_07a1
X_fn_2365_0687	equ	_fn_2365_0687
X_fn_19ba_0073	equ	_fn_19ba_0073
	end
