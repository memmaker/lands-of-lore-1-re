; s145: WW library -- VDS-style driver entry (int 2Fh 1684h, device 303Fh) and its calls
;
; int  fn_2354_000c(void)    look the entry point up once; g_38a2 = entry, g_38a6 = found
; void fn_2354_0041(void)    function 0
; long fn_2354_0051(void)    function 1
; long fn_2354_0063(int n)   int 4Bh 810Bh, then function 2
; void fn_2354_0087(int n)   int 4Bh 810Ch (twice), then function 3
; void fn_2354_00ab(void far *dst, void far *src, int cx, int bx, int dx)   function 6

	.386
	locals
S145_TEXT	segment word public use16 'CODE'
S145_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S145_TEXT,ds:DGROUP

	extrn	_g_38a2:dword, _g_38a4:word, _g_38a6:word

S145_TEXT	segment word public use16 'CODE'
	public	_fn_2354_000c, _fn_2354_0041, _fn_2354_0051, _fn_2354_0063, _fn_2354_0087, _fn_2354_00ab

_fn_2354_000c	proc	far
	push	bx
	push	es
	push	di
	mov	ax,_g_38a6
	test	ax,ax
	jnz	short @@set
	mov	ax,1684h
	mov	bx,303fh
	xor	di,di
	mov	es,di
	int	2fh
	mov	ax,di
	mov	bx,es
	cmp	ax,0
	jnz	short @@found
	cmp	ax,0
	jz	short @@set
@@found:
	mov	word ptr _g_38a2,ax
	mov	_g_38a4,bx
	mov	ax,1
@@set:	mov	_g_38a6,ax
	pop	di
	pop	es
	pop	bx
	ret
_fn_2354_000c	endp

_fn_2354_0041	proc	far
	xor	ax,ax
	cmp	ax,_g_38a6
	jz	short @@out
	mov	ax,0
	call	_g_38a2
@@out:	ret
_fn_2354_0041	endp

_fn_2354_0051	proc	far
	xor	ax,ax
	mov	dx,ax
	cmp	ax,_g_38a6
	jz	short @@out
	mov	ax,1
	call	_g_38a2
@@out:	ret
_fn_2354_0051	endp

_fn_2354_0063	proc	far
	enter	0,0
	push	bx
	xor	ax,ax
	mov	dx,ax
	cmp	ax,_g_38a6
	jz	short @@out
	mov	ah,81h
	mov	al,0bh
	mov	bx,[bp+6]
	xor	dx,dx
	int	4bh
	mov	ax,2
	call	_g_38a2
@@out:	pop	bx
	leave
	ret
_fn_2354_0063	endp

_fn_2354_0087	proc	far
	enter	0,0
	push	bx
	xor	ax,ax
	cmp	ax,_g_38a6
	jz	short @@out
	mov	ah,81h
	mov	al,0ch
	mov	bx,[bp+6]
	xor	dx,dx
	int	4bh
	int	4bh
	mov	ax,3
	call	_g_38a2
@@out:	pop	bx
	leave
	ret
_fn_2354_0087	endp

_fn_2354_00ab	proc	far
	enter	4,0
	push	bx
	push	cx
	push	dx
	push	es
	push	di
	push	ds
	push	si
	xor	ax,ax
	cmp	ax,_g_38a6
	jz	short @@out
	mov	eax,_g_38a2
	mov	[bp-4],eax
	les	di,[bp+6]
	lds	si,[bp+0ah]
	mov	bx,[bp+10h]
	mov	cx,[bp+0eh]
	mov	dx,[bp+12h]
	mov	ax,6
	call	dword ptr [bp-4]
@@out:	pop	si
	pop	ds
	pop	di
	pop	es
	pop	dx
	pop	cx
	pop	bx
	leave
	ret
_fn_2354_00ab	endp

S145_TEXT	ends
	end
