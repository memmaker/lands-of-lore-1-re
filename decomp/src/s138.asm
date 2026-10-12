; s138: WW library -- byte order swaps
;
; long fn_2315_0008(long v)   reverse the 4 bytes
; int  fn_2315_0018(int v)    swap the 2 bytes
; long fn_2315_0023(long v)   swap the 2 words

	.386
	locals
S138_TEXT	segment word public use16 'CODE'
	assume	cs:S138_TEXT
	public	_fn_2315_0008, _fn_2315_0018, _fn_2315_0023

_fn_2315_0008	proc	far
	enter	0,0
	mov	ax,[bp+6]
	mov	dx,[bp+8]
	xchg	ah,dl
	xchg	al,dh
	leave
	ret
_fn_2315_0008	endp

_fn_2315_0018	proc	far
	enter	0,0
	mov	ax,[bp+6]
	xchg	ah,al
	leave
	ret
_fn_2315_0018	endp

_fn_2315_0023	proc	far
	enter	0,0
	mov	ax,[bp+8]
	mov	dx,[bp+6]
	leave
	ret
_fn_2315_0023	endp

S138_TEXT	ends
	end
