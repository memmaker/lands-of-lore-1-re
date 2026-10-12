; o2dfa: store three words (args 1..3) into g_35ac, g_35ae, g_35b0 (TASM: enter prologue, ax preserved)
	.386
O2DFA_TEXT	segment byte public use16 'CODE'
O2DFA_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:O2DFA_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	extrn	_g_35ac:word, _g_35ae:word, _g_35b0:word
O2DFA_TEXT	segment byte public use16 'CODE'
	public	_ovr_2dfa_0020
_ovr_2dfa_0020	proc	far
	enter	0,0
	push	ax
	mov	ax,[bp+10]
	mov	_g_35b0,ax
	mov	ax,[bp+6]
	mov	_g_35ac,ax
	mov	ax,[bp+8]
	mov	_g_35ae,ax
	pop	ax
	leave
	ret
_ovr_2dfa_0020	endp
O2DFA_TEXT	ends
	end
