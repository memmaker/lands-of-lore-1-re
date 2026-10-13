; s030: music driver front end (assembler module like s026: ascending relocations, TASM jump padding)
;
; int  fn_178d_0007(void)            driver function 0xb (status) through the music driver entry
; int  fn_178d_0038(void)            nonzero while the current track plays
; void fn_178d_0091(int track)       fn_178d_00a4(track, 0xff)
; void fn_178d_00a4(int track, int vol)  start a track (MIDI driver handle g_28fa or AdLib entry g_2908)
; void fn_178d_015e(void)            stop the track
; void fn_178d_01b0(void)            fade out
; void fn_178d_01ef(struct Drv far *d, int track, int vol)  AdLib (ALFX) / generic driver play

	.386
	locals
S030_TEXT	segment byte public use16 'CODE'
S030_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:S030_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends

	extrn	_g_28fa:word, _g_2908:dword, _g_2910:dword, _g_2922:word, _g_2924:dword
	extrn	_g_35e4:word, _g_28de:word, _g_abd4:word, _g_abd6:word
	extrn	_fn_1b79_02ef:far, _fn_1b79_02e3:far, _fn_1b79_02b1:far, _fn_1b79_02ac:far
	extrn	_fn_1b79_02dd:far, _fn_1b79_0301:far, _fn_2120_0007:far, _memcmp:far

_DATA	segment word public use16 'DATA'
	public	_g_2a9a
_g_2a9a	dw	-1
s030_alfx	db	'ALFX', 0
	db	5 dup (0)
_DATA	ends

S030_TEXT	segment byte public use16 'CODE'
	public	_fn_178d_0007, _fn_178d_0038, _fn_178d_0091, _fn_178d_00a4
	public	_fn_178d_015e, _fn_178d_01b0, _fn_178d_01ef

_fn_178d_0007	proc	far
	push	bp
	mov	bp,sp
	sub	sp,6
	mov	word ptr [bp-2],0
	cmp	_g_28fa,-1
	jnz	short @@done
	cmp	_g_2908,0
	jz	short @@done
	mov	eax,_g_2908
	mov	[bp-6],eax
	mov	bx,0bh
	pushf
	call	dword ptr [bp-6]
	mov	[bp-2],ax
@@done:	mov	ax,[bp-2]
	leave
	ret
_fn_178d_0007	endp

_fn_178d_0038	proc	far
	push	bp
	mov	bp,sp
	sub	sp,6
	mov	word ptr [bp-2],0
	cmp	_g_28fa,-1
	jz	short @@adl
	cmp	_g_2922,-1
	jz	short @@done
	push	_g_2922
	push	_g_28fa
	call	far ptr _fn_1b79_02ef
	add	sp,4
	cmp	ax,1
	jnz	short @@no
	mov	ax,1
	jmp	short @@ret
@@no:	xor	ax,ax
@@ret:	jmp	short @@out
@@adl:	cmp	_g_2908,0
	jz	short @@done
	mov	eax,_g_2908
	mov	[bp-6],eax
	mov	ax,0
	mov	bx,7
	pushf
	call	dword ptr [bp-6]
	mov	[bp-2],ax
@@done:	mov	ax,[bp-2]
@@out:	leave
	ret
_fn_178d_0038	endp

_fn_178d_0091	proc	far
	push	bp
	mov	bp,sp
	push	0ffh
	push	word ptr [bp+6]
	push	cs
	call	near ptr _fn_178d_00a4
	nop
	add	sp,4
	pop	bp
	ret
_fn_178d_0091	endp

_fn_178d_00a4	proc	far
	push	bp
	mov	bp,sp
	push	si
	push	di
	mov	si,[bp+6]
	mov	di,[bp+8]
	or	si,si
	jnl	short @@1
	jmp	@@done
@@1:	cmp	si,0fah
	jng	short @@2
	jmp	@@done
@@2:	cmp	_g_35e4,0
	jnz	short @@3
	jmp	@@done
@@3:	cmp	_g_28fa,-1
	jz	short @@adl
	cmp	_g_2922,-1
	jz	short @@start
	push	_g_2922
	push	_g_28fa
	call	far ptr _fn_1b79_02e3
	add	sp,4
	push	_g_2922
	push	_g_28fa
	call	far ptr _fn_1b79_02b1
	add	sp,4
	mov	_g_2922,-1
@@start:	push	dword ptr 0
	push	_g_2924
	push	si
	push	_g_2910
	push	_g_28fa
	call	far ptr _fn_1b79_02ac
	add	sp,10h
	mov	_g_2922,ax
	push	ax
	push	_g_28fa
	call	far ptr _fn_1b79_02dd
	add	sp,4
	push	0
	mov	ax,di
	and	ax,0ffh
	imul	ax,ax,5ah
	sar	ax,8
	push	ax
	push	_g_2922
	push	_g_28fa
	call	far ptr _fn_1b79_0301
	jmp	short @@pop
@@adl:	cmp	_g_2908,0
	jz	short @@done
	push	di
	push	si
	push	ds
	push	offset DGROUP:_g_28fa
	push	cs
	call	near ptr _fn_178d_01ef
	nop
@@pop:	add	sp,8
@@done:	pop	di
	pop	si
	pop	bp
	ret
_fn_178d_00a4	endp

_fn_178d_015e	proc	far
	push	bp
	mov	bp,sp
	cmp	_g_28fa,-1
	jz	short @@adl
	cmp	_g_2922,-1
	jz	short @@done
	push	_g_2922
	push	_g_28fa
	call	far ptr _fn_1b79_02e3
	add	sp,4
	push	_g_2922
	push	_g_28fa
	call	far ptr _fn_1b79_02b1
	add	sp,4
	mov	_g_2922,-1
	jmp	short @@done
@@adl:	cmp	_g_2908,0
	jz	short @@done
	push	dword ptr 0
	push	ds
	push	offset DGROUP:_g_28fa
	push	cs
	call	near ptr _fn_178d_01ef
	nop
	add	sp,8
@@done:	pop	bp
	ret
_fn_178d_015e	endp

_fn_178d_01b0	proc	far
	push	bp
	mov	bp,sp
	cmp	_g_28fa,-1
	jz	short @@adl
	cmp	_g_2922,-1
	jz	short @@done
	push	dword ptr 7d00000h
	push	_g_2922
	push	_g_28fa
	call	far ptr _fn_1b79_0301
	jmp	short @@pop
@@adl:	cmp	_g_2908,0
	jz	short @@done
	push	dword ptr 1
	push	ds
	push	offset DGROUP:_g_28fa
	push	cs
	call	near ptr _fn_178d_01ef
	nop
@@pop:	add	sp,8
@@done:	pop	bp
	ret
_fn_178d_01b0	endp

_fn_178d_01ef	proc	far
	push	bp
	mov	bp,sp
	sub	sp,8
	les	bx,[bp+6]
	mov	eax,es:[bx+0eh]
	mov	[bp-6],eax
	cmp	word ptr [bp+0ah],-1
	jnz	short @@1
	jmp	@@done
@@1:	cmp	dword ptr [bp-6],0
	jnz	short @@2
	jmp	@@done
@@2:	cmp	dword ptr es:[bx+16h],0
	jnz	short @@3
	jmp	@@done
@@3:	les	bx,es:[bx+1eh]
	mov	ax,[bp+0ah]
	shl	ax,1
	add	bx,ax
	mov	ax,es:[bx]
	mov	[bp+0ah],ax
	cmp	word ptr [bp+0ah],-1
	jnz	short @@4
	jmp	@@done
@@4:	push	4
	push	ds
	push	offset DGROUP:s030_alfx
	les	bx,[bp+6]
	push	dword ptr es:[bx+2]
	call	far ptr _memcmp
	add	sp,0ah
	or	ax,ax
	jz	short @@adlib
	jmp	@@other
@@adlib:	and	word ptr [bp+0ah],0ffh
@@busy:	xor	ax,ax
	mov	bx,10h
	pushf
	call	dword ptr [bp-6]
	mov	[bp-8],ax
	test	word ptr [bp-8],8
	jnz	short @@busy
	cmp	_g_2a9a,0ffffh
	jz	short @@play
	mov	cx,_g_abd6
	mov	dx,1
	mov	ax,_g_2a9a
	mov	bx,0ah
	pushf
	call	dword ptr [bp-6]
	mov	cx,_g_abd4
	mov	dx,3
	mov	ax,_g_2a9a
	mov	bx,0ah
	pushf
	call	dword ptr [bp-6]
	mov	_g_2a9a,0ffffh
@@play:	mov	dx,0
	mov	ax,[bp+0ah]
	mov	bx,9
	pushf
	call	dword ptr [bp-6]
	mov	[bp-2],ax
	mov	_g_2a9a,0ffffh
	cmp	word ptr [bp+0ch],-1
	jnz	short @@5
	jmp	short @@go
	nop
@@5:	cmp	word ptr [bp-2],9
	jnz	short @@6
	jmp	short @@go
	nop
@@6:	mov	ax,[bp+0ah]
	mov	_g_2a9a,ax
	mov	dx,1
	mov	ax,[bp+0ah]
	mov	bx,9
	pushf
	call	dword ptr [bp-6]
	mov	_g_abd6,ax
	mov	dx,3
	mov	ax,[bp+0ah]
	mov	bx,9
	pushf
	call	dword ptr [bp-6]
	mov	_g_abd4,ax
	mov	ax,_g_abd4
	neg	ax
	add	ax,3fh
	mul	byte ptr [bp+0ch]
	xchg	ah,al
	xor	ah,ah
	neg	ax
	add	ax,3fh
	mov	cx,ax
	mov	dx,3
	mov	ax,[bp+0ah]
	mov	bx,0ah
	pushf
	call	dword ptr [bp-6]
	mov	ax,_g_abd6
	mov	dx,[bp+0ch]
	mul	dl
	mov	cl,ah
	xor	ch,ch
	mov	dx,1
	mov	ax,[bp+0ah]
	mov	bx,0ah
	pushf
	call	dword ptr [bp-6]
@@go:	mov	ax,[bp+0ah]
	mov	bx,6
	pushf
	call	dword ptr [bp-6]
	cmp	word ptr [bp+0ah],0
	jnz	short @@done
	push	5
	call	far ptr _fn_2120_0007
	pop	cx
	jmp	short @@done
@@other:	cmp	_g_28de,1
	jnz	short @@abs
	cmp	word ptr [bp+0ah],0
	jnl	short @@on
	mov	ax,4
	mov	bx,11h
	pushf
	call	dword ptr [bp-6]
	jmp	short @@abs
@@on:	mov	ax,4
	mov	bx,10h
	pushf
	call	dword ptr [bp-6]
@@abs:	cmp	word ptr [bp+0ah],0
	jnl	short @@pos
	mov	ax,[bp+0ah]
	neg	ax
	jmp	short @@set
@@pos:	mov	ax,[bp+0ah]
@@set:	mov	[bp+0ah],ax
	mov	ax,[bp+0ah]
	mov	bx,6
	pushf
	call	dword ptr [bp-6]
@@done:	leave
	ret
_fn_178d_01ef	endp

S030_TEXT	ends
	end
