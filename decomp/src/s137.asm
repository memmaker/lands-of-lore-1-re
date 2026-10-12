; s137: WW library -- pseudo random number generator (3-byte shift register at g_3842)
;
; int fn_2313_0000(void)

	.386
	locals
S137_TEXT	segment word public use16 'CODE'
S137_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S137_TEXT,ds:DGROUP

	extrn	_g_3842:byte

S137_TEXT	segment word public use16 'CODE'
	public	_fn_2313_0000

_fn_2313_0000	proc	far
	push	ds
	push	si
	mov	ax,DGROUP
	mov	ds,ax
	mov	si,offset DGROUP:_g_3842
	mov	al,[si]
	shr	al,1
	shr	al,1
	rcl	byte ptr [si+2],1
	rcl	byte ptr [si+1],1
	cmc
	sbb	al,[si]
	shr	al,1
	rcr	byte ptr [si],1
	mov	al,[si]
	xor	al,[si+1]
	xor	ah,ah
	pop	si
	pop	ds
	ret
_fn_2313_0000	endp

S137_TEXT	ends
	end
