; s146: WW library -- call the driver entry g_38a8 (function 0Bh) with ds:si = the far argument;
; on failure (ax = 0) report the error code in bl through ovr_2e04_0020
;
; int fn_2362_0004(void far *p)

	.386
	locals
S146_TEXT	segment word public use16 'CODE'
S146_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S146_TEXT,ds:DGROUP

	extrn	_g_38a8:dword
	extrn	_ovr_2e04_0020:far

S146_TEXT	segment word public use16 'CODE'
	public	_fn_2362_0004

_fn_2362_0004	proc	far
	enter	0,0
	push	bx
	push	dx
	push	si
	push	es
	push	ds
	pop	es
	lds	si,[bp+6]
	mov	ah,0bh
	call	es:_g_38a8
	mov	si,es
	mov	ds,si
	pop	es
	cmp	ax,0
	jnz	short @@out
	xor	bh,bh
	push	bx
	call	far ptr _ovr_2e04_0020
	pop	bx
	xor	ax,ax
@@out:	pop	si
	pop	dx
	pop	bx
	leave
	ret
_fn_2362_0004	endp

S146_TEXT	ends
	end
