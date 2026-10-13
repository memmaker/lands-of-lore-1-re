; w000: first module of WW.LIB, data only: the Westwood library's DGROUP _DATA head 0x2e46..0x3638 (layout.py)
; and the #pragma exit record (priority 100) for the overlay function 2e0b:002a.
; The original listed the far pointers' fixups in descending order (BCC style), hence FIXUP-ORDER.
; FIXUP-ORDER: 38 34 30 2c 28 24 20
DGROUP	group	_DATA,_BSS,_EXIT_
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
_EXIT_	segment word public use16 'EXITDATA'
_EXIT_	ends
	extrn	_ovr_2e0b_002a:far
_DATA	segment
	public	_g_2e46, _g_2e56, _g_2e66, _g_2e82, _g_2e8a, _g_2e92, _g_2e9a, _g_2e9c, _g_2ea2, _g_2eaa, _g_2eb2, _g_2eba
	public	_g_2ed8, _g_2eda, _g_2efa, _g_2efc, _g_2efe, _g_2f00, _g_2f02, _g_2f04, _g_2f06, _g_2f0a, _g_2f0c, _g_2f0e
	public	_g_2f10, _g_2f12, _g_2f14, _g_2f16, _g_2f18, _g_2f1a, _g_2f1c, _g_2f1e, _g_2f20, _g_2f22, _g_2f24, _g_2f26
	public	_g_2f28, _g_2f2a, _g_2f2c, _g_2f2e, _g_2f30, _g_2f32, _g_2f34, _g_2f36, _g_2f38, _g_2f3a, _g_2f3c, _g_2f42
	public	_g_2f43, _g_2f44, _g_2f45, _g_2f46, _g_2f48, _g_2f4a, _g_2f4c, _g_2f4e, _g_2f50, _g_2f52, _g_2f54, _g_2f56
	public	_g_2f58, _g_2f5a, _g_2f5c, _g_2f5e, _g_2f6f, _g_2f71, _g_2f73, _g_2f77, _g_2f79, _g_2f7b, _g_2f7d, _g_2f7f
	public	_g_2f81, _g_2f85, _g_2f87, _g_2f89, _g_2f8b, _g_2f8d, _g_2f8f, _g_2f91, _g_2f97, _g_2f9f, _g_2fa9, _g_2fac
	public	_g_2fd9, _g_3000, _g_303f, _g_31ec, _g_334e, _g_3509, _g_3523, _g_3533, _g_35ac, _g_35ae, _g_35b0, _g_35b2
	public	_g_35b4, _g_35b6, _g_35b8, _g_35c8, _g_35ca, _g_35cc, _g_35d2, _g_35d6, _g_35da, _g_35de, _g_35e2, _g_35e4
	public	_g_35e6, _g_35e8, _g_35ea, _g_35ec, _g_35ee, _g_35ef, _g_35f1, _g_35f3, _g_35f6, _g_35fd, _g_3601, _g_360c
	public	_g_360f, _g_3611, _g_3615, _g_3618, _g_361e, _g_3622, _g_3624, _g_3626, _g_3628, _g_3629, _g_362a, _g_362c
	public	_g_362d, _g_362e, _g_3630, _g_3632, _g_3634, _g_3636
_g_2e46	label	byte
	db	000h, 005h, 003h, 002h, 00ah, 00eh, 00ch, 006h, 004h, 00bh, 009h, 001h, 000h, 008h, 007h, 00fh	; 2e46
_g_2e56	label	byte
	db	000h, 001h, 002h, 003h, 004h, 005h, 006h, 007h, 008h, 009h, 00ah, 00bh, 00ch, 00dh, 00eh, 00fh	; 2e56
_g_2e66	label	byte
	dd	DGROUP:_g_2e82	; 2e66
	dd	DGROUP:_g_2e8a	; 2e6a
	dd	DGROUP:_g_2e92	; 2e6e
	dd	DGROUP:_g_2e9a	; 2e72
	dd	DGROUP:_g_2ea2	; 2e76
	dd	DGROUP:_g_2eaa	; 2e7a
	dd	DGROUP:_g_2eb2	; 2e7e
_g_2e82	label	byte
	db	'cga.ovl',0	; 2e82
_g_2e8a	label	byte
	db	'tga.ovl',0	; 2e8a
_g_2e92	label	byte
	db	'ega.ovl',0	; 2e92
_g_2e9a	label	byte
	db	06dh, 067h	; 2e9a
_g_2e9c	label	byte
	db	'a.ovl',0	; 2e9c
_g_2ea2	label	byte
	db	'vga.ovl',0	; 2ea2
_g_2eaa	label	byte
	db	'xga.ovl',0	; 2eaa
_g_2eb2	label	byte
	db	'yga.ovl',0	; 2eb2
_g_2eba	label	byte
	db	050h, 061h, 067h, 065h, 041h, 072h, 072h, 061h, 079h, 053h, 069h, 07ah, 065h, 020h, 069h, 073h	; 2eba
	db	020h, 06eh, 065h, 067h, 061h, 074h, 069h, 076h, 065h, 021h, 00dh, 00ah, 000h, 000h	; 2eca
_g_2ed8	label	byte
	db	' ',0	; 2ed8
_g_2eda	label	byte
	db	00ah, 02ah, 02ah, 020h, 048h, 069h, 06dh, 065h, 06dh, 02eh, 053h, 079h, 073h, 020h, 045h, 072h	; 2eda
	db	072h, 06fh, 072h, 020h, 028h, 025h, 058h, 029h, 020h, 02ah, 02ah, 020h, 025h, 073h, 00ah, 000h	; 2eea
_g_2efa	label	byte
	db	2 dup (0)	; 2efa
_g_2efc	label	byte
	db	2 dup (0)	; 2efc
_g_2efe	label	byte
	db	03fh, 001h	; 2efe
_g_2f00	label	byte
	db	0c7h, 000h	; 2f00
_g_2f02	label	byte
	db	2 dup (0)	; 2f02
_g_2f04	label	byte
	db	2 dup (0)	; 2f04
_g_2f06	label	byte
	db	4 dup (0)	; 2f06
_g_2f0a	label	byte
	db	2 dup (0)	; 2f0a
_g_2f0c	label	byte
	db	2 dup (0)	; 2f0c
_g_2f0e	label	byte
	db	2 dup (0)	; 2f0e
_g_2f10	label	byte
	db	2 dup (0)	; 2f10
_g_2f12	label	byte
	db	2 dup (0)	; 2f12
_g_2f14	label	byte
	db	2 dup (0)	; 2f14
_g_2f16	label	byte
	db	2 dup (0)	; 2f16
_g_2f18	label	byte
	db	2 dup (0)	; 2f18
_g_2f1a	label	byte
	db	03fh, 001h	; 2f1a
_g_2f1c	label	byte
	db	2 dup (0)	; 2f1c
_g_2f1e	label	byte
	db	0c7h, 000h	; 2f1e
_g_2f20	label	byte
	db	2 dup (0)	; 2f20
_g_2f22	label	byte
	db	2 dup (0)	; 2f22
_g_2f24	label	byte
	db	2 dup (0)	; 2f24
_g_2f26	label	byte
	db	2 dup (0)	; 2f26
_g_2f28	label	byte
	db	2 dup (0)	; 2f28
_g_2f2a	label	byte
	db	2 dup (0)	; 2f2a
_g_2f2c	label	byte
	db	2 dup (0)	; 2f2c
_g_2f2e	label	byte
	db	2 dup (0)	; 2f2e
_g_2f30	label	byte
	db	2 dup (0)	; 2f30
_g_2f32	label	byte
	db	2 dup (0)	; 2f32
_g_2f34	label	byte
	db	2 dup (0)	; 2f34
_g_2f36	label	byte
	db	2 dup (0)	; 2f36
_g_2f38	label	byte
	db	2 dup (0)	; 2f38
_g_2f3a	label	byte
	db	2 dup (0)	; 2f3a
_g_2f3c	label	byte
	db	6 dup (0)	; 2f3c
_g_2f42	label	byte
	db	1 dup (0)	; 2f42
_g_2f43	label	byte
	db	1 dup (0)	; 2f43
_g_2f44	label	byte
	db	001h	; 2f44
_g_2f45	label	byte
	db	1 dup (0)	; 2f45
_g_2f46	label	byte
	db	'b',0	; 2f46
_g_2f48	label	byte
	db	'`',0	; 2f48
_g_2f4a	label	byte
	db	'\',0	; 2f4a
_g_2f4c	label	byte
	db	'f',0	; 2f4c
_g_2f4e	label	byte
	db	'[',0	; 2f4e
_g_2f50	label	byte
	db	'e',0	; 2f50
_g_2f52	label	byte
	db	2 dup (0)	; 2f52
_g_2f54	label	byte
	db	2 dup (0)	; 2f54
_g_2f56	label	byte
	db	2 dup (0)	; 2f56
_g_2f58	label	byte
	db	2 dup (0)	; 2f58
_g_2f5a	label	byte
	db	2 dup (0)	; 2f5a
_g_2f5c	label	byte
	db	2 dup (0)	; 2f5c
_g_2f5e	label	byte
	db	17 dup (0)	; 2f5e
_g_2f6f	label	byte
	db	2 dup (0)	; 2f6f
_g_2f71	label	byte
	db	2 dup (0)	; 2f71
_g_2f73	label	byte
	db	4 dup (0)	; 2f73
_g_2f77	label	byte
	db	2 dup (0)	; 2f77
_g_2f79	label	byte
	db	2 dup (0)	; 2f79
_g_2f7b	label	byte
	db	2 dup (0)	; 2f7b
_g_2f7d	label	byte
	db	2 dup (0)	; 2f7d
_g_2f7f	label	byte
	db	2 dup (0)	; 2f7f
_g_2f81	label	byte
	db	4 dup (0)	; 2f81
_g_2f85	label	byte
	db	2 dup (0)	; 2f85
_g_2f87	label	byte
	db	2 dup (0)	; 2f87
_g_2f89	label	byte
	db	2 dup (0)	; 2f89
_g_2f8b	label	byte
	db	2 dup (0)	; 2f8b
_g_2f8d	label	byte
	db	2 dup (0)	; 2f8d
_g_2f8f	label	byte
	db	2 dup (0)	; 2f8f
_g_2f91	label	byte
	db	6 dup (0)	; 2f91
_g_2f97	label	byte
	db	8 dup (0)	; 2f97
_g_2f9f	label	byte
	db	10 dup (0)	; 2f9f
_g_2fa9	label	byte
	db	3 dup (0)	; 2fa9
_g_2fac	label	byte
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 2fac
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 2fbc
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 2fcc
_g_2fd9	label	byte
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 2fd9
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 2fe9
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 2ff9
_g_3000	label	byte
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 3000
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 3010
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 3020
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 3030
_g_303f	label	byte
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 303f
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 304f
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 305f
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 306f
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 307f
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 308f
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 309f
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 30af
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 30bf
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 30cf
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 30df
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 30ef
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 30ff
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 310f
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 311f
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 312f
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 313f
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 314f
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 315f
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 316f
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 317f
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 318f
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 319f
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 31af
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 31bf
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 31cf
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 31df
_g_31ec	label	byte
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 31ec
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 31fc
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 320c
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 321c
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 322c
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 323c
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 324c
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 325c
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 326c
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 327c
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 328c
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 329c
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 32ac
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 32bc
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 32cc
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 32dc
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 32ec
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 32fc
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 330c
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 331c
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 332c
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 333c
	db	0ffh, 000h	; 334c
_g_334e	label	byte
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 334e
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 335e
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 336e
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 337e
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 338e
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 339e
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 33ae
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 33be
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 33ce
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 33de
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 33ee
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 33fe
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 340e
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 341e
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 342e
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 343e
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 344e
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 345e
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 346e
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 347e
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 348e
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 349e
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 34ae
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 34be
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 34ce
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 34de
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 34ee
	db	0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 34fe
_g_3509	label	byte
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 3509
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 3519
_g_3523	label	byte
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 3523
_g_3533	label	byte
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 3533
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 3543
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 3553
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 3563
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 3573
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 3583
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh	; 3593
	db	000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h, 0ffh, 000h	; 35a3
_g_35ac	label	byte
	db	2 dup (0)	; 35ac
_g_35ae	label	byte
	db	2 dup (0)	; 35ae
_g_35b0	label	byte
	db	2 dup (0)	; 35b0
_g_35b2	label	byte
	db	2 dup (0)	; 35b2
_g_35b4	label	byte
	db	2 dup (0)	; 35b4
_g_35b6	label	byte
	db	2 dup (0)	; 35b6
_g_35b8	label	byte
	db	001h, 000h, 003h, 000h, 002h, 000h, 005h, 000h, 004h, 000h, 003h, 000h, 002h, 000h, 001h, 000h	; 35b8
_g_35c8	label	byte
	db	001h, 000h	; 35c8
_g_35ca	label	byte
	db	2 dup (0)	; 35ca
_g_35cc	label	byte
	db	6 dup (0)	; 35cc
_g_35d2	label	byte
	db	040h, 042h, 00fh, 000h	; 35d2
_g_35d6	label	byte
	db	4 dup (0)	; 35d6
_g_35da	label	byte
	db	4 dup (0)	; 35da
_g_35de	label	byte
	db	4 dup (0)	; 35de
_g_35e2	label	byte
	db	001h, 000h	; 35e2
_g_35e4	label	byte
	db	001h, 000h	; 35e4
_g_35e6	label	byte
	db	011h, 000h	; 35e6
_g_35e8	label	byte
	db	0ffh, 0ffh	; 35e8
_g_35ea	label	byte
	db	2 dup (0)	; 35ea
_g_35ec	label	byte
	db	2 dup (0)	; 35ec
_g_35ee	label	byte
	db	1 dup (0)	; 35ee
_g_35ef	label	byte
	db	2 dup (0)	; 35ef
_g_35f1	label	byte
	db	2 dup (0)	; 35f1
_g_35f3	label	byte
	db	3 dup (0)	; 35f3
_g_35f6	label	byte
	db	025h, 030h, 034h, 078h, 03ah, 025h, 030h	; 35f6
_g_35fd	label	byte
	db	'4x ',0	; 35fd
_g_3601	label	byte
	db	'%04x-%04x ',0	; 3601
_g_360c	label	byte
	db	0b3h, 020h, 000h	; 360c
_g_360f	label	byte
	db	025h, 030h	; 360f
_g_3611	label	byte
	db	'2X ',0	; 3611
_g_3615	label	byte
	db	02eh, 000h, 000h	; 3615
_g_3618	label	byte
	db	6 dup (0)	; 3618
_g_361e	label	byte
	db	4 dup (0)	; 361e
_g_3622	label	byte
	db	001h, 000h	; 3622
_g_3624	label	byte
	db	2 dup (0)	; 3624
_g_3626	label	byte
	db	2 dup (0)	; 3626
_g_3628	label	byte
	db	008h	; 3628
_g_3629	label	byte
	db	008h	; 3629
_g_362a	label	byte
	db	2 dup (0)	; 362a
_g_362c	label	byte
	db	1 dup (0)	; 362c
_g_362d	label	byte
	db	1 dup (0)	; 362d
_g_362e	label	byte
	db	0ffh, 0ffh	; 362e
_g_3630	label	byte
	db	2 dup (0)	; 3630
_g_3632	label	byte
	db	2 dup (0)	; 3632
_g_3634	label	byte
	db	2 dup (0)	; 3634
_g_3636	label	byte
	db	2 dup (0)	; 3636
_DATA	ends
_EXIT_	segment
	db	1, 100
	dd	_ovr_2e0b_002a
_EXIT_	ends
	end
