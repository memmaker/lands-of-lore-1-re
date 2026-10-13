; s047: CPU type detection (0 = 8086, 1 = 80186, 2 = 80286, 3 = 80386, 4 = 80486 by the flags register and EFLAGS.AC; tools/asmgen.py)

	.386
	locals
S047_TEXT	segment byte public use16 'CODE'
S047_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:S047_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends


S047_TEXT	segment byte public use16 'CODE'
	public	_fn_1c86_000a
_fn_1c86_000a	proc	far
	enter	2,0
	push	ebx
	pushf
	xor	ax,ax
	push	ax
	popf
	pushf
	pop	ax
	and	ax,0f000h
	cmp	ax,0f000h
	jnz	short L_0033
	mov	word ptr [bp-2],1
	mov	al,0ffh
	mov	cl,21h
	shr	al,cl
	jnz	short L_0068
	mov	word ptr [bp-2],0
	jmp	short L_0068
L_0033:
	mov	word ptr [bp-2],2
	mov	ax,7000h
	push	ax
	popf
	pushf
	pop	ax
	and	ax,7000h
	jz	short L_0068
	mov	word ptr [bp-2],3
	pushfd
	pop	eax
	mov	ebx,eax
	xor	eax,40000h
	push	eax
	popfd
	pushfd
	pop	eax
	xor	eax,ebx
	jz	short L_0068
	mov	word ptr [bp-2],4
L_0068:
	popf
	mov	ax,[bp-2]
	pop	ebx
	leave
	retf
_fn_1c86_000a	endp
S047_TEXT	ends
	end
