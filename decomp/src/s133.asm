; s133: WW library -- monochrome (B000h) debug screen, active when g_374c != 0
;
; void fn_22a6_0008(int x, int y)     set the cursor (CRTC 0Eh/0Fh) and the write position
; void fn_22a6_004e(void)             clear the screen, cursor home
; void fn_22a6_0075(int n)            scroll up n lines
; void fn_22a6_00c0(int c, int attr)  put a character, advance
; void fn_22a6_00fa(int x, int y, int w, int h, int attr, int style)   frame from the box charset g_374e/g_376e
; void fn_22a6_01ab(char far *s, int x, int y, int attr, int keep)    print with wrap and scroll
; void fn_22a6_0243(char far *s, int x, int y, int attr)
; void fn_22a6_0276(char far *s)      print at the cursor
; int  fn_22a6_029c(int page)         swap the screen with save page `page` (0..7), returns the previous page

	.386
	locals
S133_TEXT	segment word public use16 'CODE'
S133_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	extrn	_g_374c:word, _g_374e:byte, _g_376e:byte, _g_3789:word

S133_TEXT	segment word public use16 'CODE'
	assume	cs:S133_TEXT,ds:DGROUP
	public	_fn_22a6_0008, _fn_22a6_004e, _fn_22a6_0075, _fn_22a6_00c0, _fn_22a6_00fa
	public	_fn_22a6_01ab, _fn_22a6_0243, _fn_22a6_0276, _fn_22a6_029c

curx	dw	0
cury	dw	0
curpos	dw	0

_fn_22a6_0008	proc	far
	enter	0,0
	push	ax
	push	bx
	push	dx
	cmp	_g_374c,0
	jz	short @@out
	mov	ax,[bp+8]
	mov	ah,50h
	imul	ah
	add	ax,[bp+6]
	mov	bx,ax
	mov	dx,3b4h
	mov	al,0eh
	out	dx,al
	inc	dx
	mov	al,bh
	out	dx,al
	dec	dx
	mov	al,0fh
	out	dx,al
	inc	dx
	mov	al,bl
	out	dx,al
	add	bx,bx
	mov	cs:curpos,bx
	mov	ax,[bp+6]
	mov	cs:curx,ax
	mov	ax,[bp+8]
	mov	cs:cury,ax
@@out:	pop	dx
	pop	bx
	pop	ax
	leave
	ret
_fn_22a6_0008	endp

_fn_22a6_004e	proc	far
	push	es
	cmp	_g_374c,0
	jz	short @@out
	pushad
	mov	ax,0b000h
	mov	es,ax
	xor	di,di
	xor	eax,eax
	mov	cx,2000h
	rep	stosd
	push	ax
	push	ax
	call	far ptr _fn_22a6_0008
	add	sp,4
	popad
@@out:	pop	es
	ret
_fn_22a6_004e	endp

_fn_22a6_0075	proc	far
	enter	0,0
	push	ax
	push	bx
	push	cx
	push	es
	push	di
	push	ds
	push	si
	cmp	_g_374c,0
	jz	short @@out
	mov	ax,0b000h
	mov	ds,ax
	mov	es,ax
	mov	ax,[bp+6]
	or	ax,ax
	jz	short @@out
	mov	bx,ax
	xor	ax,ax
@@line:	mov	cx,780h
	xor	di,di
	mov	si,0a0h
	rep	movsw
	dec	cs:cury
	sub	cs:curpos,0a0h
	mov	cx,50h
	rep	stosw
	dec	bx
	jnz	short @@line
@@out:	pop	si
	pop	ds
	pop	di
	pop	es
	pop	cx
	pop	bx
	pop	ax
	leave
	ret
_fn_22a6_0075	endp

_fn_22a6_00c0	proc	far
	enter	0,0
	push	ax
	push	es
	push	di
	cmp	_g_374c,0
	jz	short @@out
	mov	di,cs:curpos
	mov	ax,0b000h
	mov	es,ax
	mov	ax,[bp+6]
	mov	ah,[bp+8]
	stosw
	inc	cs:curx
	push	cs:cury
	push	cs:curx
	call	far ptr _fn_22a6_0008
	add	sp,4
@@out:	pop	di
	pop	es
	pop	ax
	leave
	ret
_fn_22a6_00c0	endp

_fn_22a6_00fa	proc	far
	enter	0,0
	push	ax
	push	bx
	push	cx
	push	ds
	push	si
	push	di
	cmp	_g_374c,0
	jz	@@out
	mov	ax,DGROUP
	mov	ds,ax
	mov	si,offset DGROUP:_g_376e
	mov	di,offset DGROUP:_g_374e
	mov	cl,3
	mov	ax,[bp+10h]
	and	ax,3
	shl	ax,cl
	add	di,ax
	cmp	word ptr [bp+0ah],2
	jc	short @@out
	cmp	word ptr [bp+0ch],2
	jc	short @@out
	sub	word ptr [bp+0ah],2
	sub	word ptr [bp+0ch],2
	push	cs:cury
	push	cs:curx
	push	word ptr [bp+8]
	push	word ptr [bp+6]
	call	far ptr _fn_22a6_0008
	add	sp,4
@@part:	mov	cx,[bp+0ah]
	cmp	byte ptr [si+2],1
	jz	short @@cnt
	mov	cx,[bp+0ch]
	cmp	byte ptr [si+2],2
	jz	short @@cnt
	mov	cx,1
@@cnt:	jcxz	@@next
@@ch:	xor	ax,ax
	mov	al,[di]
	push	word ptr [bp+0eh]
	push	ax
	call	far ptr _fn_22a6_00c0
	add	sp,4
	mov	al,[si+1]
	cbw
	add	ax,cs:cury
	push	ax
	mov	al,[si]
	cbw
	add	ax,cs:curx
	dec	ax
	push	ax
	call	far ptr _fn_22a6_0008
	add	sp,4
	loop	@@ch
@@next:	add	si,3
	inc	di
	cmp	byte ptr [si+2],0ffh
	jnz	short @@part
	call	far ptr _fn_22a6_0008
	add	sp,4
@@out:	pop	di
	pop	si
	pop	ds
	pop	cx
	pop	bx
	pop	ax
	leave
	ret
_fn_22a6_00fa	endp

_fn_22a6_01ab	proc	far
	enter	0,0
	push	ax
	push	bx
	push	cx
	push	dx
	push	es
	push	di
	push	ds
	push	si
	push	cs:cury
	push	cs:curx
	cmp	word ptr [bp+8],0
	jz	short @@end
	push	word ptr [bp+0ch]
	push	word ptr [bp+0ah]
	call	far ptr _fn_22a6_0008
	add	sp,4
	lds	si,[bp+6]
@@next:	lodsb
	or	al,al
	jz	short @@end
	cmp	al,0dh
	jz	short @@cr
	xor	ah,ah
	push	word ptr [bp+0eh]
	push	ax
	call	far ptr _fn_22a6_00c0
	add	sp,4
	cmp	cs:curx,50h
	jc	short @@chk
	inc	word ptr [bp+0ch]
	push	word ptr [bp+0ch]
	push	0
	call	far ptr _fn_22a6_0008
	add	sp,4
	jmp	short @@chk
@@cr:	inc	word ptr [bp+0ch]
	push	word ptr [bp+0ch]
	push	word ptr [bp+0ah]
	call	far ptr _fn_22a6_0008
	add	sp,4
@@chk:	cmp	cs:cury,19h
	jc	short @@nx
	push	1
	call	far ptr _fn_22a6_0075
	add	sp,2
	dec	word ptr [bp+0ch]
@@nx:	jmp	short @@next
@@end:	cmp	word ptr [bp+10h],0
	jnz	short @@pop
	call	far ptr _fn_22a6_0008
@@pop:	add	sp,4
	pop	si
	pop	ds
	pop	di
	pop	es
	pop	dx
	pop	cx
	pop	bx
	pop	ax
	leave
	ret
_fn_22a6_01ab	endp

_fn_22a6_0243	proc	far
	enter	0,0
	push	ax
	push	bx
	push	cx
	push	dx
	push	es
	push	di
	push	ds
	push	si
	cmp	_g_374c,0
	jz	short @@out
	push	0
	push	word ptr [bp+0eh]
	push	word ptr [bp+0ch]
	push	word ptr [bp+0ah]
	push	dword ptr [bp+6]
	call	far ptr _fn_22a6_01ab
	add	sp,0ch
@@out:	pop	si
	pop	ds
	pop	di
	pop	es
	pop	dx
	pop	cx
	pop	bx
	pop	ax
	leave
	ret
_fn_22a6_0243	endp

_fn_22a6_0276	proc	far
	enter	0,0
	cmp	_g_374c,0
	jz	short @@out
	push	1
	push	2
	push	cs:cury
	push	cs:curx
	push	dword ptr [bp+6]
	call	far ptr _fn_22a6_01ab
	add	sp,0ch
@@out:	leave
	ret
_fn_22a6_0276	endp

_fn_22a6_029c	proc	far
	enter	2,0
	push	ebx
	push	cx
	push	edx
	push	es
	push	di
	push	ds
	push	si
	cld
	mov	bx,_g_3789
	mov	[bp-2],bx
	cmp	_g_374c,0
	jz	short @@out
	mov	ax,[bp+6]
	cmp	ax,bx
	jz	short @@out
	cmp	ax,7
	ja	short @@out
	mov	cx,8
	push	ds
	pop	es
	mov	di,offset DGROUP:_g_3789
	repne	scasw
	neg	cx
	add	cx,7
	sub	di,2
	mov	bx,_g_3789
	mov	ax,es:[di]
	mov	es:[di],bx
	mov	_g_3789,ax
	mov	ax,0b000h
	mov	ds,ax
	shl	cx,8
	add	cx,ax
	mov	es,cx
	xor	di,di
	xor	si,si
	mov	cx,400h
@@swap:	mov	edx,es:[di]
	mov	ebx,[si]
	mov	es:[di],ebx
	mov	[si],edx
	add	si,4
	add	di,4
	loop	@@swap
@@out:	mov	ax,[bp-2]
	pop	si
	pop	ds
	pop	di
	pop	es
	pop	edx
	pop	cx
	pop	ebx
	leave
	ret
_fn_22a6_029c	endp

S133_TEXT	ends
	end
