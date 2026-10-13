; s041: segment 1b43 (TASM module)
	.386
S041_TEXT	segment word public use16 'CODE'
S041_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:S041_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
S041_TEXT	segment
	public	_fn_1b43_000c
_fn_1b43_000c	proc	far
	retf		; c
_fn_1b43_000c	endp
S041_TEXT	ends
	end
