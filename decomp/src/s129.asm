; s129: WW library -- empty code segment (the module contributes no code or data at all; TLINK still lays out
; its zero-length segment). Nothing references it, so the relink pulls it with an EXTDEF of this label.

	.386
S129_TEXT	segment byte public use16 'CODE'
	assume	cs:S129_TEXT
	public	_s129_empty
_s129_empty	label	far
S129_TEXT	ends
	end
