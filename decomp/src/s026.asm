; s026: sound driver enable switches and timer callback (assembler module: its relocations are in ascending
; order, one record per module, unlike BCC's descending per-1024-byte chunks)
;
; int  fn_16bf_0001(int on)   music driver on/off; returns the old state, calls driver function 0x10/0x11
; int  fn_16bf_0058(int on)   sound effects driver on/off (driver 2)
; void fn_16bf_00af(void)     timer callback: services the digital sound driver (g_2952) with all registers saved
; int  fn_16bf_00d6(int v)    g_2970[i] for the first threshold g_2964[i] below v

	.386
	locals
S026_TEXT	segment byte public use16 'CODE'
S026_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:S026_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends

	extrn	_g_35e2:word, _g_35e4:word
	extrn	_fn_17d6_0123:far, _fn_178d_015e:far, _fn_16cf_02b7:far

_DATA	segment word public use16 'DATA'
	public	_g_28b8
	public	_g_28ba
	public	_g_28c6
	public	_g_28ca
	public	_g_28ce
	public	_g_28d2
	public	_g_28d6
	public	_g_28da
	public	_g_28dc
	public	_g_28de
	public	_g_28e0
	public	_g_28e2
	public	_g_28e4
	public	_g_28e6
	public	_g_28fa
	public	_g_28fc
	public	_g_2908
	public	_g_290c
	public	_g_2910
	public	_g_2914
	public	_g_2918
	public	_g_291c
	public	_g_291e
	public	_g_2920
	public	_g_2922
	public	_g_2924
	public	_g_2926
	public	_g_2928
	public	_g_292a
	public	_g_2938
	public	_g_2950
	public	_g_2952
	public	_g_2956
	public	_g_2958
	public	_g_295a
	public	_g_295c
	public	_g_295e
	public	_g_2962
	public	_g_2964
	public	_g_2970
_g_28b8	dw	-1
_g_28ba	dw	0, 0, 0, 0, 0, 0
_g_28c6	dd	0
_g_28ca	dw	0, 0
_g_28ce	dw	0, 0
_g_28d2	dw	0, 0
_g_28d6	dw	0, 0
_g_28da	dw	0
_g_28dc	dw	-1
_g_28de	dw	0
_g_28e0	dw	0
_g_28e2	dw	-1
_g_28e4	dw	0
_g_28e6	dw	0, -1, 0, 0, -1, 0, 0, -1, 0, 0
_g_28fa	dw	-1
_g_28fc	dw	0, 0, 0, 0, 0, 0
_g_2908	dd	0
_g_290c	dw	0, 0
_g_2910	dw	0, 0
_g_2914	dw	0, 0
_g_2918	dw	0, 0
_g_291c	dw	0
_g_291e	dw	-1
_g_2920	dw	0
_g_2922	dw	-1
_g_2924	dw	0
_g_2926	dw	0
_g_2928	dw	-1
_g_292a	dw	-1, 0, 0, 0, 0, 0, 0
_g_2938	dw	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1
_g_2950	dw	-1
_g_2952	dd	0
_g_2956	dw	255
_g_2958	dw	255
_g_295a	dw	255
_g_295c	dw	-1
_g_295e	dw	-1, 0
_g_2962	dw	544
_g_2964	dw	223, 159, 95, 47, 15, 0
_g_2970	dw	100, 75, 50, 25, 12, 0
_DATA	ends

S026_TEXT	segment byte public use16 'CODE'
	public	_fn_16bf_0001, _fn_16bf_0058, _fn_16bf_00af, _fn_16bf_00d6

_fn_16bf_0001	proc	far
	push	bp
	mov	bp,sp
	sub	sp,6
	push	si
	mov	si,[bp+6]
	mov	ax,_g_35e2
	mov	[bp-2],ax
	mov	_g_35e2,si
	or	si,si
	jnz	short @@1
	call	far ptr _fn_17d6_0123
@@1:	cmp	_g_28b8,-1
	jnz	short @@done
	cmp	_g_28c6,0
	jz	short @@done
	mov	eax,_g_28c6
	mov	[bp-6],eax
	cmp	_g_35e2,0
	jnz	short @@on
	mov	ax,1
	mov	bx,10h
	pushf
	call	dword ptr [bp-6]
	jmp	short @@done
@@on:	mov	ax,1
	mov	bx,11h
	pushf
	call	dword ptr [bp-6]
@@done:	mov	ax,[bp-2]
	pop	si
	leave
	ret
_fn_16bf_0001	endp

_fn_16bf_0058	proc	far
	push	bp
	mov	bp,sp
	sub	sp,6
	push	si
	mov	si,[bp+6]
	mov	ax,_g_35e4
	mov	[bp-2],ax
	mov	_g_35e4,si
	or	si,si
	jnz	short @@1
	call	far ptr _fn_178d_015e
@@1:	cmp	_g_28fa,-1
	jnz	short @@done
	cmp	_g_2908,0
	jz	short @@done
	mov	eax,_g_2908
	mov	[bp-6],eax
	cmp	_g_35e4,0
	jnz	short @@on
	mov	ax,2
	mov	bx,10h
	pushf
	call	dword ptr [bp-6]
	jmp	short @@done
@@on:	mov	ax,2
	mov	bx,11h
	pushf
	call	dword ptr [bp-6]
@@done:	mov	ax,[bp-2]
	pop	si
	leave
	ret
_fn_16bf_0058	endp

_fn_16bf_00af	proc	far
	push	bp
	mov	bp,sp
	pushad
	push	ds
	push	es
	push	fs
	push	gs
	pushfd
	cld
	cmp	_g_2952,0
	jz	short @@1
	call	far ptr _fn_16cf_02b7
@@1:	popfd
	pop	gs
	pop	fs
	pop	es
	pop	ds
	popad
	pop	bp
	ret
_fn_16bf_00af	endp

_fn_16bf_00d6	proc	far
	push	bp
	mov	bp,sp
	xor	cx,cx
	xor	dx,dx
	jmp	short @@test
@@body:	mov	bx,dx
	shl	bx,1
	mov	ax,_g_2964[bx]
	cmp	ax,[bp+6]
	jge	short @@next
	mov	cx,1
	jmp	short @@test
@@next:	inc	dx
@@test:	or	cx,cx
	jnz	short @@out
	mov	bx,dx
	shl	bx,1
	cmp	_g_2964[bx],0
	jnz	short @@body
@@out:	mov	bx,dx
	shl	bx,1
	mov	ax,_g_2970[bx]
	pop	bp
	ret
_fn_16bf_00d6	endp

S026_TEXT	ends
	end
