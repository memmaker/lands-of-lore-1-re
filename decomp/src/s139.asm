; s139: WW library -- countdown timers
;
; void fn_2318_0000(void), fn_2318_0001(void)   empty
; void fn_2318_0002(void)   tick: for each of the 16 timers g_384c[] enabled in g_384a, count down (bit set in
;                           g_3848) to 0 or up; then ++g_3846

	.386
	locals
S139_TEXT	segment word public use16 'CODE'
S139_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	assume	cs:S139_TEXT,ds:DGROUP

	extrn	_g_3846:word, _g_3848:word, _g_384a:word, _g_384c:dword

S139_TEXT	segment word public use16 'CODE'
	public	_fn_2318_0000, _fn_2318_0001, _fn_2318_0002

_fn_2318_0000	proc	far
	ret
_fn_2318_0000	endp

_fn_2318_0001	proc	far
	ret
_fn_2318_0001	endp

_fn_2318_0002	proc	far
	push	ax
	push	bx
	push	cx
	push	ds
	push	si
	mov	ax,DGROUP
	mov	ds,ax
	mov	si,offset DGROUP:_g_384c
	mov	cx,10h
	mov	ax,_g_384a
	mov	bx,_g_3848
@@next:	bt	ax,0
	jnc	short @@skip
	bt	bx,0
	jnc	short @@up
	cmp	dword ptr [si],0
	jz	short @@skip
	dec	dword ptr [si]
	jmp	short @@skip
@@up:	inc	dword ptr [si]
@@skip:	shr	ax,1
	jz	short @@done
	shr	bx,1
	add	si,4
	loop	@@next
@@done:	inc	_g_3846
	pop	si
	pop	ds
	pop	cx
	pop	bx
	pop	ax
	ret
_fn_2318_0002	endp

S139_TEXT	ends
	end
