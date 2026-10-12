; s148: WW library -- empty code segment (the module contributes no code or data at all; TLINK still lays out
; its zero-length segment). Nothing references it, so the relink pulls it with an EXTDEF of this label.

	.386
S148_TEXT	segment byte public use16 'CODE'
	assume	cs:S148_TEXT
	public	_s148_empty
_s148_empty	label	far
S148_TEXT	ends
	end
