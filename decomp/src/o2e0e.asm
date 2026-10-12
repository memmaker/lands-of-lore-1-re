; o2e0e: XMS driver interface (TASM: enter prologues, `cmp ax,0`)
;
; void far *ovr_2e0e_003e(void)   detect the XMS driver (int 2Fh 4300h/4310h), store its entry in g_38a8
; int ovr_2e0e_0039(int f)        XMS 08h query free extended memory: largest block (f == 0) or total
; int ovr_2e0e_0034(int kb)       XMS 09h allocate kb KB: handle, 0 on error (error code to ovr_2e04_0020)
; int ovr_2e0e_002f(int h)        XMS 0Ah free handle h: 1, 0 on error
; int ovr_2e0e_002a(int h)        XMS 0Ch lock handle h: linear address low word (dx = high), 0 on error
; void ovr_2e0e_0025(int h)       XMS 0Dh unlock handle h
; int ovr_2e0e_0020(int h)        XMS 0Eh handle information: stores lock count, free handles, size in g_af92..
	.386
	locals
O2E0E_TEXT	segment byte public use16 'CODE'
O2E0E_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:O2E0E_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	extrn	_g_38a8:dword, _g_af92:byte, _g_af93:byte, _g_af94:word
	extrn	_ovr_2e04_0020:far
O2E0E_TEXT	segment byte public use16 'CODE'
	public	_ovr_2e0e_003e
	public	_ovr_2e0e_0039
	public	_ovr_2e0e_0034
	public	_ovr_2e0e_002f
	public	_ovr_2e0e_002a
	public	_ovr_2e0e_0025
	public	_ovr_2e0e_0020
_ovr_2e0e_003e	proc	far
	push	bx
	push	es
	mov	ax,4300h
	int	2fh
	cmp	al,80h
	jne	short @@none
	mov	ax,4310h
	int	2fh
	mov	ax,bx
	mov	dx,es
	jmp	short @@store
@@none:
	xor	ax,ax
	xor	dx,dx
@@store:
	mov	word ptr _g_38a8,ax
	mov	word ptr _g_38a8+2,dx
	pop	es
	pop	bx
	ret
_ovr_2e0e_003e	endp

_ovr_2e0e_0039	proc	far
	enter	0,0
	push	bx
	push	dx
	mov	ax,[bp+6]
	mov	ah,8
	call	_g_38a8
	cmp	word ptr [bp+6],0
	je	short @@ret
	mov	ax,dx
@@ret:
	pop	dx
	pop	bx
	leave
	ret
_ovr_2e0e_0039	endp

_ovr_2e0e_0034	proc	far
	enter	0,0
	push	bx
	push	dx
	mov	dx,[bp+6]
	mov	ah,9
	call	_g_38a8
	mov	ax,dx
	cmp	ax,0
	jne	short @@ret
	xor	bh,bh
	push	bx
	call	_ovr_2e04_0020
	add	sp,2
	xor	ax,ax
@@ret:
	pop	dx
	pop	bx
	leave
	ret
_ovr_2e0e_0034	endp

_ovr_2e0e_002f	proc	far
	enter	0,0
	push	bx
	push	dx
	mov	dx,[bp+6]
	mov	ah,0ah
	call	_g_38a8
	cmp	ax,0
	jne	short @@ret
	xor	bh,bh
	push	bx
	call	_ovr_2e04_0020
	add	sp,2
	xor	ax,ax
@@ret:
	pop	dx
	pop	bx
	leave
	ret
_ovr_2e0e_002f	endp

_ovr_2e0e_002a	proc	far
	enter	0,0
	push	bx
	mov	dx,[bp+6]
	mov	ah,0ch
	call	_g_38a8
	cmp	ax,0
	jne	short @@ok
	xor	dx,dx
	xor	bx,bx
@@ok:
	mov	ax,bx
	pop	bx
	leave
	ret
_ovr_2e0e_002a	endp

_ovr_2e0e_0025	proc	far
	enter	0,0
	push	bx
	push	dx
	mov	dx,[bp+6]
	mov	ah,0dh
	call	_g_38a8
	pop	dx
	pop	bx
	leave
	ret
_ovr_2e0e_0025	endp

_ovr_2e0e_0020	proc	far
	enter	0,0
	push	bx
	push	dx
	mov	dx,[bp+6]
	mov	ah,0eh
	call	_g_38a8
	cmp	ax,0
	jne	short @@ok
	xor	bh,bh
	push	bx
	call	_ovr_2e04_0020
	add	sp,2
	xor	ax,ax
@@ok:
	mov	_g_af92,bh
	mov	_g_af93,bl
	mov	_g_af94,dx
	pop	dx
	pop	bx
	leave
	ret
_ovr_2e0e_0020	endp
O2E0E_TEXT	ends
	end
