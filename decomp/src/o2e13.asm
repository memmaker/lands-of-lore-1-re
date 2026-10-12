; o2e13: timer/sound-driver multiplexer (TASM, 8086: push imm emulated, far calls to own procs as push cs/call)
;
; void ovr_2e13_0020(void)                    reset the driver tables
; int  ovr_2e13_0034(void far *drv)           register a driver image ("Copy" signature), returns slot or -1
; void far *ovr_2e13_002f(int slot)           driver function 0x64 (info block)
; void ovr_2e13_0039(int slot, ...)           start driver slot (functions 0x67/0x66)
; void ovr_2e13_0043(...)                     driver function 0x65
; int  ovr_2e13_0048(void far *handler)       install a timer client, returns its index or -1
; void ovr_2e13_004d(void)                    release all timer clients
; int  ovr_2e13_0052(void)                    current PIT divisor
; void ovr_2e13_0057(int i, long hz)          set client i rate in Hz
; void ovr_2e13_002a(int i, int n)            set client i rate in 10000/n units
; void ovr_2e13_003e(int i, long div)         set client i divisor
; void ovr_2e13_0025(int i)                   pause client i
	locals
O2E13_TEXT	segment byte public 'CODE'
O2E13_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:O2E13_TEXT,ds:DGROUP
_DATA	segment word public 'DATA'
_DATA	ends
_BSS	segment word public 'BSS'
_BSS	ends
	extrn	_g_2db2:word, _g_2db0:word, _g_2e36:word, _g_2e3e:word, _g_2e3c:word
	extrn	_g_2df2:word, _g_2e12:word, _g_2dac:word, _g_2dae:word, _g_2cf8:word
	extrn	_g_2d5e:word, _g_2da2:word, _g_2da4:word, _g_2daa:word, _g_2d1a:word
	extrn	_g_2c90:word, _g_2cd6:word, _g_2c92:word, _g_2d18:word, _g_2da6:word
	extrn	_g_2da8:word, _g_2cd2:word, _g_2cd4:word
	extrn	_fn_1b79_0450:far, _fn_1b79_0456:far
O2E13_TEXT	segment byte public 'CODE'
	public	_ovr_2e13_0057
	public	_ovr_2e13_0052
	public	_ovr_2e13_004d
	public	_ovr_2e13_0048
	public	_ovr_2e13_0043
	public	_ovr_2e13_003e
	public	_ovr_2e13_0039
	public	_ovr_2e13_0034
	public	_ovr_2e13_002f
	public	_ovr_2e13_002a
	public	_ovr_2e13_0025
	public	_ovr_2e13_0020

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

_ovr_2e13_0034	proc	far
	push	bp
	mov	bp,sp
	push	ds
	push	si
	push	di
	push	es
	pushf
	cli
	mov	_g_2e36,0
@@lp:	mov	si,_g_2e36
	shl	si,1
	shl	si,1
	mov	ax,word ptr _g_2db2[si]
	or	ax,word ptr _g_2db2[si+2]
	jz	short @@fnd
	inc	_g_2e36
	cmp	_g_2e36,10h
	jne	short @@lp
	mov	ax,0FFFFh
	jmp	short @@ret
@@fnd:	les	di,dword ptr [bp+6]
	mov	ax,0FFFFh
	cmp	word ptr es:[di+2],6F43h
	jne	short @@ret
	cmp	word ptr es:[di+4],7970h
	jne	short @@ret
	add	di,es:[di]
	mov	word ptr _g_2db2[si],di
	mov	word ptr _g_2db2[si+2],es
	push	_g_2e36
	call	_ovr_2e13_002f
	nop			; TASM pads the forward far call
	add	sp,2
	mov	es,dx
	mov	di,ax
	or	dx,ax
	mov	ax,0FFFFh
	jz	short @@ret
	mov	dx,es:[di]
	cmp	dx,_g_2e3e
	ja	short @@ret
	mov	ax,_g_2e36
@@ret:	popf
	pop	es
	pop	di
	pop	si
	pop	ds
	pop	bp
	ret
_ovr_2e13_0034	endp

_ovr_2e13_0043	proc	far
	mov	ax,65h
	jmp	disp
_ovr_2e13_0043	endp

_ovr_2e13_0039	proc	far
	push	bp
	mov	bp,sp
	push	ds
	push	si
	push	di
	push	es
	pushf
	cli
	cmp	word ptr [bp+6],10h
	jb	short @@ok
	jmp	@@ret
@@ok:	mov	_g_2e3c,0FFFFh
	push	word ptr [bp+6]
	call	_ovr_2e13_002f
	nop			; TASM pads the forward far call
	add	sp,2
	mov	es,dx
	mov	di,ax
	mov	si,es:[di+14h]
	cmp	si,-1
	je	short @@x
	mov	ax,67h
	mov	bx,[bp+6]
	call	lookup
	mov	bx,ax
	or	bx,dx
	jz	short @@x
	mov	es,dx
	mov	bx,ax
	push	es
	push	bx
	call	_ovr_2e13_0048
	nop			; TASM pads the forward far call
	add	sp,4
	mov	bx,[bp+6]
	shl	bx,1
	mov	word ptr _g_2df2[bx],ax
	mov	_g_2e3c,ax
	push	0
	push	si
	push	ax
	call	_ovr_2e13_0057
	nop			; TASM pads the forward far call
	add	sp,6
@@x:	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8]
	push	word ptr [bp+6]
	mov	ax,66h
	push	cs
	call	disp
	add	sp,0Ah
	mov	bx,[bp+6]
	shl	bx,1
	mov	word ptr _g_2e12[bx],1
	cmp	_g_2e3c,-1
	je	short @@ret
	push	_g_2e3c
	call	_ovr_2e13_0025
	nop			; TASM pads the forward far call
	add	sp,2
@@ret:	popf
	pop	es
	pop	di
	pop	si
	pop	ds
	pop	bp
	ret
_ovr_2e13_0039	endp

_ovr_2e13_0052	proc	far
	push	ds
	push	si
	push	di
	pushf
	cli
	mov	ax,_g_2db0
	popf
	pop	di
	pop	si
	pop	ds
	ret
_ovr_2e13_0052	endp

_ovr_2e13_002f	proc	far
	push	bp
	mov	bp,sp
	push	seg _ovr_2e13_0052
	push	offset _ovr_2e13_0052
	push	word ptr [bp+6]
	mov	ax,64h
	push	cs
	call	disp
	add	sp,6
	pop	bp
	ret
_ovr_2e13_002f	endp

rate	proc	near
	push	bp
	mov	bp,sp
	push	ds
	push	si
	push	di
	mov	ax,0
	cmp	word ptr [bp+4],0D68Dh
	jae	short @@s
	mov	ax,[bp+4]
	mov	bx,20BCh
	mov	cx,2710h
	mul	cx
	div	bx
@@s:	push	ax
	call	settimer
	add	sp,2
	pop	di
	pop	si
	pop	ds
	pop	bp
	ret
rate	endp

div32	proc	near
	push	bp
	mov	bp,sp
	push	ds
	push	si
	push	di
	push	bp
	mov	ax,[bp+4]
	mov	dx,[bp+6]
	mov	bx,[bp+8]
	mov	cx,[bp+0Ah]
	or	cx,cx
	jnz	short @@long
	or	dx,dx
	jz	short @@short
	or	bx,bx
	jz	short @@short
@@long:	mov	bp,cx
	mov	cx,20h
	xor	di,di
	xor	si,si
@@lp:	shl	ax,1
	rcl	dx,1
	rcl	si,1
	rcl	di,1
	cmp	di,bp
	jb	short @@nx
	ja	short @@sub
	cmp	si,bx
	jb	short @@nx
@@sub:	sub	si,bx
	sbb	di,bp
	inc	ax
@@nx:	loop	@@lp
	jmp	short @@done
@@short:	div	bx
	xor	dx,dx
@@done:	pop	bp
	pop	di
	pop	si
	pop	ds
	pop	bp
	ret
div32	endp

recalc	proc	near
	push	ds
	push	si
	push	di
	push	es
	pushf
	cli
	cld
	mov	_g_2dac,0FFFFh
	mov	_g_2dae,0FFFFh
	mov	si,0
@@lp:	mov	bx,si
	shl	bx,1
	cmp	word ptr _g_2cf8[bx],0
	je	short @@nx
	shl	bx,1
	mov	ax,word ptr _g_2d5e[bx]
	mov	dx,word ptr _g_2d5e[bx+2]
	cmp	dx,_g_2dae
	jb	short @@set
	ja	short @@nx
	cmp	ax,_g_2dac
	jae	short @@nx
@@set:	mov	_g_2dac,ax
	mov	_g_2dae,dx
@@nx:	inc	si
	cmp	si,10h
	jbe	short @@lp
	mov	ax,_g_2dac
	mov	dx,_g_2dae
	cmp	ax,_g_2da2
	jne	short @@chg
	cmp	dx,_g_2da4
	je	short @@ret
@@chg:	mov	_g_2daa,0FFFFh
	mov	_g_2da2,ax
	mov	_g_2da4,dx
	push	ax
	call	rate
	add	sp,2
	push	ds
	pop	es
	mov	di,offset DGROUP:_g_2d1a
	mov	cx,22h
	mov	ax,0
	rep	stosw
@@ret:	popf
	pop	es
	pop	di
	pop	si
	pop	ds
	ret
recalc	endp

_ovr_2e13_0020	proc	far
	push	ds
	push	si
	push	di
	push	es
	pushf
	cli
	mov	_g_2c90,0
	cld
	mov	ax,ds
	mov	es,ax
	mov	di,offset DGROUP:_g_2db2
	mov	cx,20h
	mov	ax,0
	rep	stosw
	mov	di,offset DGROUP:_g_2df2
	mov	cx,10h
	mov	ax,0FFFFh
	rep	stosw
	mov	di,offset DGROUP:_g_2e12
	mov	cx,10h
	mov	ax,0
	rep	stosw
	popf
	pop	es
	pop	di
	pop	si
	pop	ds
	ret
_ovr_2e13_0020	endp

_ovr_2e13_004d	proc	far
	push	ds
	push	si
	push	di
	pushf
	cli
	mov	si,0Fh
@@lp:	push	si
	call	_ovr_2e13_0025
	nop			; TASM pads the forward far call
	add	sp,2
	dec	si
	jge	short @@lp
	popf
	pop	di
	pop	si
	pop	ds
	ret
_ovr_2e13_004d	endp

_ovr_2e13_0057	proc	far
	push	bp
	mov	bp,sp
	push	ds
	push	si
	push	di
	pushf
	cli
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8]
	push	0Fh
	push	4240h
	call	div32
	add	sp,8
	push	dx
	push	ax
	push	word ptr [bp+6]
	call	_ovr_2e13_003e
	nop			; TASM pads the forward far call
	add	sp,6
	popf
	pop	di
	pop	si
	pop	ds
	pop	bp
	ret
_ovr_2e13_0057	endp

_ovr_2e13_002a	proc	far
	push	bp
	mov	bp,sp
	push	ds
	push	si
	push	di
	pushf
	cli
	cmp	word ptr [bp+8],0
	jne	short @@nz
	mov	ax,0D68Dh
	mov	dx,0
	jmp	short @@go
@@nz:	mov	ax,2710h
	mov	bx,2E9Ch
	mul	word ptr [bp+8]
	div	bx
	mov	dx,0
@@go:	push	dx
	push	ax
	push	word ptr [bp+6]
	call	_ovr_2e13_003e
	nop			; TASM pads the forward far call
	add	sp,6
	popf
	pop	di
	pop	si
	pop	ds
	pop	bp
	ret
_ovr_2e13_002a	endp

_ovr_2e13_003e	proc	far
	push	bp
	mov	bp,sp
	push	ds
	push	si
	push	di
	pushf
	cli
	mov	bx,[bp+6]
	shl	bx,1
	mov	ax,word ptr _g_2cf8[bx]
	push	ax
	mov	word ptr _g_2cf8[bx],1
	shl	bx,1
	mov	ax,[bp+8]
	mov	dx,[bp+0Ah]
	mov	word ptr _g_2d5e[bx],ax
	mov	word ptr _g_2d5e[bx+2],dx
	mov	word ptr _g_2d1a[bx],0
	mov	word ptr _g_2d1a[bx+2],0
	call	recalc
	pop	ax
	mov	bx,[bp+6]
	shl	bx,1
	mov	word ptr _g_2cf8[bx],ax
	popf
	pop	di
	pop	si
	pop	ds
	pop	bp
	ret
_ovr_2e13_003e	endp

_ovr_2e13_0025	proc	far
	push	bp
	mov	bp,sp
	push	ds
	push	si
	push	di
	pushf
	cli
	mov	bx,[bp+6]
	shl	bx,1
	cmp	word ptr _g_2cf8[bx],1
	jne	short @@r
	mov	word ptr _g_2cf8[bx],2
@@r:	popf
	pop	di
	pop	si
	pop	ds
	pop	bp
	ret
_ovr_2e13_0025	endp

clrtab	proc	near
	push	ds
	push	si
	push	di
	push	es
	pushf
	cli
	cld
	mov	_g_2da2,0FFFFh
	mov	_g_2da4,0FFFFh
	push	ds
	pop	es
	mov	di,offset DGROUP:_g_2cf8
	mov	cx,11h
	mov	ax,0
	rep	stosw
	mov	di,offset DGROUP:_g_2d1a
	mov	cx,22h
	rep	stosw
	mov	di,offset DGROUP:_g_2d5e
	mov	cx,22h
	rep	stosw
	popf
	pop	es
	pop	di
	pop	si
	pop	ds
	ret
clrtab	endp

_ovr_2e13_0048	proc	far
	push	bp
	mov	bp,sp
	push	ds
	push	si
	push	di
	push	es
	pushf
	cli
	mov	cx,ds
	mov	bx,0
@@lp:	cmp	word ptr _g_2cf8[bx],0
	je	short @@f
	add	bx,2
	cmp	bx,20h
	jb	short @@lp
	mov	ax,0FFFFh
	jmp	short @@ret
@@f:	mov	ax,bx
	shr	ax,1
	mov	word ptr _g_2cf8[bx],1
	mov	word ptr _g_2cd6[bx],cx
	shl	bx,1
	les	si,dword ptr [bp+6]
	mov	word ptr _g_2c92[bx],si
	mov	word ptr _g_2c92[bx+2],es
	inc	_g_2c90
	cmp	_g_2c90,1
	jne	short @@ret
	push	ax
	call	clrtab
	mov	_g_2d18,1
	call	hook
	push	0
	push	0D68Dh
	push	10h
	call	_ovr_2e13_003e
	add	sp,6
	push	10h
	call	_ovr_2e13_0025
	add	sp,2
	pop	ax
	mov	bx,ax
	shl	bx,1
	mov	word ptr _g_2cf8[bx],1
@@ret:	popf
	pop	es
	pop	di
	pop	si
	pop	ds
	pop	bp
	ret
_ovr_2e13_0048	endp

hook	proc	near		; hook int 8, old vector to g_2da6
	push	ds
	push	si
	push	di
	push	es
	push	dx
	pushf
	cli
	mov	ax,0
	mov	es,ax
	mov	bx,es:[20h]
	mov	es,es:[22h]
	mov	_g_2da6,bx
	mov	_g_2da8,es
	call	_fn_1b79_0450
	mov	_g_2cd2,dx
	mov	_g_2cd4,ax
	call	_fn_1b79_0456
	mov	ds,ax
	mov	ax,0
	mov	es,ax
	mov	es:[20h],dx
	mov	es:[22h],ds
	popf
	pop	dx
	pop	es
	pop	di
	pop	si
	pop	ds
	ret
hook	endp
O2E13_TEXT	ends
	end
