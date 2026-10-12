; o2e19: timer-client shutdown helpers (TASM, 8086; same tables as o2e13)
;
; void ovr_2e19_002f(int slot)              forget driver slot
; void ovr_2e19_0034(int slot)              stop driver slot (driver function 0x68)
; void ovr_2e19_003e(int i)                 resume timer client i (paused -> running)
; void ovr_2e19_0020(void)                  resume all timer clients
; void ovr_2e19_002a(int i)                 remove timer client i, restore the PIT and int 8 when none is left
; void ovr_2e19_0025(void)                  remove all timer clients
; void ovr_2e19_0039(int a, int b)          stop every driver slot, then remove all clients
	locals
O2E19_TEXT	segment byte public 'CODE'
O2E19_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:O2E19_TEXT,ds:DGROUP
_DATA	segment word public 'DATA'
_DATA	ends
_BSS	segment word public 'BSS'
_BSS	ends
	extrn	_g_2db2:word, _g_2db0:word, _g_2e36:word, _g_2df2:word, _g_2e12:word
	extrn	_g_2cf8:word, _g_2daa:word, _g_2da6:word, _g_2da8:word, _g_2c90:word
O2E19_TEXT	segment byte public 'CODE'
	public	_ovr_2e19_003e
	public	_ovr_2e19_0039
	public	_ovr_2e19_0034
	public	_ovr_2e19_002f
	public	_ovr_2e19_002a
	public	_ovr_2e19_0025
	public	_ovr_2e19_0020

lookup	proc	near		; bx = slot, ax = function id -> dx:ax entry or 0
	push	es
	cmp	bx,10h
	jae	short @@nf
	shl	bx,1
	shl	bx,1
	les	bx,dword ptr _g_2db2[bx]
	mov	cx,es
	or	cx,bx
	jz	short @@nf
@@lp:	mov	cx,es:[bx]
	cmp	cx,ax
	je	short @@f
	add	bx,4
	cmp	cx,-1
	jne	short @@lp
	mov	ax,0
	mov	dx,0
	pop	es
	ret
@@nf:	mov	ax,0
	mov	dx,0
	pop	es
	ret
@@f:	mov	ax,es:[bx+2]
	mov	dx,es
	pop	es
	ret
lookup	endp

disp	proc	near		; ax = function id, [sp+4] = slot; tail-jumps to the driver
	mov	bx,sp
	mov	bx,ss:[bx+4]
	call	lookup
	cmp	ax,0
	jne	short @@go
	cmp	dx,0
	je	short @@no
@@go:	push	dx
	push	ax
	retf
@@no:	retf
disp	endp

settimer	proc	near
	push	bp
	mov	bp,sp
	push	ds
	push	si
	push	di
	pushf
	cli
	mov	al,36h
	out	43h,al
	mov	ax,[bp+4]
	mov	_g_2db0,ax
	jmp	short $+2
	out	40h,al
	mov	al,ah
	jmp	short $+2
	out	40h,al
	popf
	pop	di
	pop	si
	pop	ds
	pop	bp
	ret
settimer	endp

_ovr_2e19_002f	proc	far
	push	bp
	mov	bp,sp
	push	ds
	push	si
	push	di
	pushf
	cli
	mov	bx,[bp+6]
	cmp	bx,10h
	jae	short @@r
	shl	bx,1
	shl	bx,1
	mov	word ptr _g_2db2[bx],0
	mov	word ptr _g_2db2[bx+2],0
@@r:	popf
	pop	di
	pop	si
	pop	ds
	pop	bp
	ret
_ovr_2e19_002f	endp

_ovr_2e19_0034	proc	far
	mov	bx,sp
	mov	bx,ss:[bx+4]
	cmp	bx,10h
	jae	short @@r
	shl	bx,1
	mov	dx,0
	xchg	dx,word ptr _g_2e12[bx]
	cmp	dx,0
	je	short @@r
	mov	dx,word ptr _g_2df2[bx]
	cmp	dx,-1
	je	short @@x
	push	dx
	call	_ovr_2e19_002a
	nop			; TASM pads the forward far call
	add	sp,2
@@x:	mov	ax,68h
	jmp	disp
@@r:	ret
_ovr_2e19_0034	endp

_ovr_2e19_003e	proc	far
	push	bp
	mov	bp,sp
	push	ds
	push	si
	push	di
	pushf
	cli
	mov	bx,[bp+6]
	shl	bx,1
	cmp	word ptr _g_2cf8[bx],2
	jne	short @@r
	mov	word ptr _g_2cf8[bx],1
@@r:	popf
	pop	di
	pop	si
	pop	ds
	pop	bp
	ret
_ovr_2e19_003e	endp

_ovr_2e19_0020	proc	far
	push	ds
	push	si
	push	di
	pushf
	cli
	mov	si,0Fh
@@lp:	push	si
	call	_ovr_2e19_003e
	add	sp,2
	dec	si
	jge	short @@lp
	popf
	pop	di
	pop	si
	pop	ds
	ret
_ovr_2e19_0020	endp

restore	proc	near		; reinstall the saved int 8 vector
	push	ds
	push	si
	push	di
	push	es
	pushf
	cli
	mov	_g_2daa,0FFFFh
	mov	dx,_g_2da6
	mov	ds,_g_2da8
	mov	ax,0
	mov	es,ax
	mov	es:[20h],dx
	mov	es:[22h],ds
	popf
	pop	es
	pop	di
	pop	si
	pop	ds
	ret
restore	endp

_ovr_2e19_002a	proc	far
	push	bp
	mov	bp,sp
	push	ds
	push	si
	push	di
	pushf
	cli
	mov	bx,[bp+6]
	cmp	bx,-1
	je	short @@r
	shl	bx,1
	cmp	word ptr _g_2cf8[bx],0
	je	short @@r
	mov	word ptr _g_2cf8[bx],0
	dec	_g_2c90
	jnz	short @@r
	push	0
	call	settimer
	add	sp,2
	call	restore
@@r:	popf
	pop	di
	pop	si
	pop	ds
	pop	bp
	ret
_ovr_2e19_002a	endp

_ovr_2e19_0025	proc	far
	push	ds
	push	si
	push	di
	pushf
	cli
	mov	si,0Fh
@@lp:	push	si
	call	_ovr_2e19_002a
	add	sp,2
	dec	si
	jge	short @@lp
	popf
	pop	di
	pop	si
	pop	ds
	ret
_ovr_2e19_0025	endp

_ovr_2e19_0039	proc	far
	push	bp
	mov	bp,sp
	push	ds
	push	si
	push	di
	pushf
	cli
	mov	_g_2e36,0
@@lp:	mov	si,_g_2e36
	shl	si,1
	mov	dx,word ptr _g_2df2[si]
	shl	si,1
	mov	ax,word ptr _g_2db2[si]
	or	ax,word ptr _g_2db2[si+2]
	jz	short @@nx
	cmp	dx,-1
	je	short @@s
	push	dx
	call	_ovr_2e19_002a
	add	sp,2
@@s:	push	word ptr [bp+8]
	push	word ptr [bp+6]
	push	_g_2e36
	call	_ovr_2e19_0034
	add	sp,6
@@nx:	inc	_g_2e36
	cmp	_g_2e36,10h
	jne	short @@lp
	call	_ovr_2e19_0025
	popf
	pop	di
	pop	si
	pop	ds
	pop	bp
	ret
_ovr_2e19_0039	endp

O2E19_TEXT	ends
	end
