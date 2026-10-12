; s141: WW library -- decompressors
;
; int  fn_232c_000c(void far *src, void far *dst, unsigned max)   LCW (format 80) decode, returns bytes written
; void fn_232c_0111(void far *src, void far *dst, unsigned long n) RLE decode: n>0 copy n, n<0 fill -n,
;                                                                  0: word count (big endian) fill

	.386
	locals
S141_TEXT	segment word public use16 'CODE'
	assume	cs:S141_TEXT
	extrn	_fn_2279_02b5:far
	public	_fn_232c_000c, _fn_232c_0111

_fn_232c_000c	proc	far
	enter	0,0
	push	bx
	push	cx
	push	dx
	push	es
	push	di
	push	ds
	push	si
	push	dword ptr [bp+0ah]
	call	far ptr _fn_2279_02b5
	add	sp,4
	mov	di,ax
	mov	es,dx
	push	dword ptr [bp+6]
	call	far ptr _fn_2279_02b5
	add	sp,4
	mov	si,ax
	mov	ds,dx
	mov	dx,[bp+0eh]
	push	bp
	mov	cs:@@start,di
	add	dx,di
	mov	cs:@@end,dx
	cld
	mov	bx,si
	mov	dx,ds
	mov	bp,es
@@loop:	mov	ax,cs:@@end
	sub	ax,di
	jz	short @@done
	mov	cs:@@left,ax
	mov	si,bx
	mov	ds,dx
	lodsb
	or	al,al
	js	short @@hi
	mov	ah,al
	and	ah,0fh
	mov	ch,al
	mov	cl,4
	shr	ch,cl
	mov	cl,ch
	xor	ch,ch
	add	cx,3
	cmp	cx,cs:@@left
	jbe	short @@c1
	mov	cx,cs:@@left
@@c1:	lodsb
	mov	bx,si
	mov	si,di
	sub	si,ax
	mov	ds,bp
	rep	movsb
	jmp	short @@loop
@@hi:	test	al,40h
	jnz	short @@long
	cmp	al,80h
	jz	short @@done
	mov	cl,al
	and	cx,3fh
	cmp	cx,cs:@@left
	jbe	short @@c2
	mov	cx,cs:@@left
@@c2:	rep	movsb
	mov	bx,si
	jmp	short @@loop
@@done:	mov	ax,di
	sub	ax,cs:@@start
	jmp	short @@out
@@long:	mov	cl,al
	and	cx,3fh
	add	cx,3
	cmp	al,0feh
	jnz	short @@notfe
	lodsw
	mov	cx,ax
	lodsb
	mov	bx,si
	cmp	cx,cs:@@left
	jbe	short @@c3
	mov	cx,cs:@@left
@@c3:	rep	stosb
	jmp	@@loop
@@notfe:
	cmp	al,0ffh
	jnz	short @@abs
	lodsw
	mov	cx,ax
@@abs:	lodsw
	mov	bx,si
	add	ax,cs:@@start
	mov	si,ax
	mov	ds,bp
	cmp	cx,cs:@@left
	jbe	short @@c4
	mov	cx,cs:@@left
@@c4:	rep	movsb
	jmp	@@loop
@@out:	pop	bp
	pop	si
	pop	ds
	pop	di
	pop	es
	pop	dx
	pop	cx
	pop	bx
	leave
	ret
@@start	dw	0
@@left	dw	0
@@end	dw	0
	dw	0, 0
_fn_232c_000c	endp

_fn_232c_0111	proc	far
	enter	0,0
	push	es
	push	ds
	pushad
	cld
	cmp	dword ptr [bp+6],0
	jz	short @@out
	cmp	dword ptr [bp+0ah],0
	jz	short @@out
	les	di,[bp+0ah]
	lds	si,[bp+6]
	mov	ebx,[bp+0eh]
@@loop:	or	ebx,ebx
	jz	short @@out
	mov	ax,si
	mov	cx,ds
	shr	ax,4
	add	cx,ax
	mov	ds,cx
	and	si,0fh
	mov	ax,di
	mov	cx,es
	shr	ax,4
	add	cx,ax
	mov	es,cx
	and	di,0fh
	xor	eax,eax
	lodsb
	cmp	al,0
	setg	dl
	jnz	short @@nz
	lodsw
	xchg	al,ah
	jmp	short @@cnt
@@nz:	jge	short @@cnt
	neg	al
@@cnt:	cmp	eax,ebx
	jbe	short @@c1
	mov	eax,ebx
@@c1:	sub	ebx,eax
	mov	ecx,eax
	or	dl,dl
	jz	short @@fill
	shr	cx,1
	rep	movsw
	adc	cx,0
	rep	movsb
	jmp	short @@loop
@@fill:	lodsb
	rep	stosb
	jmp	short @@loop
@@out:	popad
	pop	ds
	pop	es
	leave
	ret
_fn_232c_0111	endp

S141_TEXT	ends
	end
