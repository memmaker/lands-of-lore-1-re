; s037: empty code segment (19c9:0000, word aligned: an assembler module) + DGROUP data 0x2ab2..0x2b30
; (layout.py), used by the WW library (s058 s073 s114 s132)
S037_TEXT	segment word public use16 'CODE'
S037_TEXT	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
_DATA	segment
	public	_g_2ab2, _g_2af4, _g_2af8
_g_2ab2	label	byte
	db	66 dup (0)	; 2ab2
_g_2af4	label	byte
	db	014h, 000h, 000h, 000h	; 2af4
_g_2af8	label	byte
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 0ffh, 006h, 002h, 0ffh, 004h, 005h, 003h, 0ffh	; 2af8
	db	000h, 007h, 001h, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh, 0dfh, 0ffh, 0e0h, 0ffh, 0e1h, 0ffh, 0ffh, 0ffh	; 2b08
	db	001h, 000h, 01fh, 000h, 020h, 000h, 021h, 000h, 0c0h, 0ffh, 0a0h, 0ffh, 002h, 000h, 003h, 000h	; 2b18
	db	040h, 000h, 060h, 000h, 0feh, 0ffh, 0fdh, 0ffh	; 2b28
_DATA	ends
	end
