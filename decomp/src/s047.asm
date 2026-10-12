; s047: segment 1c86 (TASM module)
	.386
S047_TEXT	segment word public use16 'CODE'
S047_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:S047_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
S047_TEXT	segment
	public	_fn_1c86_000a
_fn_1c86_000a	proc	far
	enter	2h,0h		; a
	push	ebx		; e
	pushf		; 10
	xor	ax,ax		; 11
	push	ax		; 13
	popf		; 14
	pushf		; 15
	pop	ax		; 16
	and	ax,0f000h		; 17
	cmp	ax,0f000h		; 1a
	jnz	short L0033		; 1d
	mov	word ptr [bp-2h],1h		; 1f
	mov	al,0ffh		; 24
	mov	cl,21h		; 26
	shr	al,cl		; 28
	jnz	short L0068		; 2a
	mov	word ptr [bp-2h],0h		; 2c
	jmp	short L0068		; 31
L0033:
	mov	word ptr [bp-2h],2h		; 33
	mov	ax,7000h		; 38
	push	ax		; 3b
	popf		; 3c
	pushf		; 3d
	pop	ax		; 3e
	and	ax,7000h		; 3f
	jz	short L0068		; 42
	mov	word ptr [bp-2h],3h		; 44
	pushfd		; 49
	pop	eax		; 4b
	mov	ebx,eax		; 4d
	xor	eax,40000h		; 50
	push	eax		; 56
	popfd		; 58
	pushfd		; 5a
	pop	eax		; 5c
	xor	eax,ebx		; 5e
	jz	short L0068		; 61
	mov	word ptr [bp-2h],4h		; 63
L0068:
	popf		; 68
	mov	ax,[bp-2h]		; 69
	pop	ebx		; 6c
	leave		; 6e
	retf		; 6f
_fn_1c86_000a	endp
S047_TEXT	ends
	end
