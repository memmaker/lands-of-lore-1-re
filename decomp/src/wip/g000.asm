; g000: data-only first module of the game (layout.py): DGROUP _DATA 0x94..0x1dcc and the far data segments 2568
; (segment table 167) and 2656 (179). It declares every far data segment 151..194 first, so they keep their order
; whichever module defines them, and pulls the library modules nothing calls by a far reference (SETARGV/SETENVP
; through __argv/_environ; WW s074 s077 s129 s148).
; Data is emitted in the original's LEDATA order (F167, _DATA ..0xd58, F179, rest of _DATA). The original's records
; list their fixups in descending order: a segment is reopened (= new LEDATA) where an original record started and
; FIXUP-ORDER sorts each record's fixups descending.
; FIXUP-ORDER: 1cd0 1ccc 1cc8 1cc4 1cc0 1cbc 1cb8 1bec 1be8 1be0 1bdc 1bd4 1bd0 1bc8 1bc4 1bbc 1bb8 1bb0 1bac 1ba4 1ba0 1b98 1b94 1b8c
; FIXUP-ORDER: 1b88 1b80 1b7c 1b74 1b70 1b68 1b64 1b5c 1b58 1a84 1a80 1a78 1a74 1a6c 1a68 1a60 1a5c 1a54 1a50 1a48 1a44 1a3c 1a38 1a30
; FIXUP-ORDER: 1a2c 1a24 1a20 1a18 1a14 1a0c 1a08 1a00 19fc 19f4 19f0 181e 181a 1594 1590 158c 1588 1584 1580 157c 1578 1574 1570 156c
; FIXUP-ORDER: 1568 1564 1560 155c 1558 1554 1550 154c 1548 1544 1540 153c 1538 1534 1530 152c 1528 1524 1520 151c 1518 1514 1510 150c
; FIXUP-ORDER: 1508 1504 1500 1422 141e 13d8 13d0 13c0 13b4 13b0 13a8 13a4 13a0 139c 1398 1394 1390 cbe cba cb6 cb2 cae caa ca6
; FIXUP-ORDER: ca2 c9e c9a c96 c92 c8e c8a c86 c82 c7e c7a c76 c72 c6e c6a c66 c62 81a 804 7ee 7d8 7c2 7ac 796
; FIXUP-ORDER: 780 76a 754 73e 728 712 6fc 6e6 6d0 6ba 6a4 68e 678 662 64c 636 620 60a 5f4 5de 5c8 5b2 59c 586
; FIXUP-ORDER: 570 55a 544 52e 518 502 4ec 4d6 4c0 4aa 494 47e 468 452 43c 426 425 410 3fa 3e4 3ce 3b8 3a3 3a2
; FIXUP-ORDER: 38c 376 360 34a 334 321 31e 308 2f2 2dc 2c6 2b0 29f 29a 284 26e 258 242 22c 21d 216 200 1ea 1d4
; FIXUP-ORDER: 1be 1a8 19b 192 17c 166 150 13a 124 119 10e f8 e2 cc b6 a0 97 8a 74 5e 48 32 1c 15
; FIXUP-ORDER: 6
F151_FAR	segment para public use16 'FAR_DATA'
F151_FAR	ends
F152_FAR	segment para public use16 'FAR_DATA'
F152_FAR	ends
F153_FAR	segment para public use16 'FAR_DATA'
F153_FAR	ends
F154_FAR	segment para public use16 'FAR_DATA'
F154_FAR	ends
F155_FAR	segment para public use16 'FAR_DATA'
F155_FAR	ends
F156_FAR	segment para public use16 'FAR_DATA'
F156_FAR	ends
F157_FAR	segment para public use16 'FAR_DATA'
F157_FAR	ends
F158_FAR	segment para public use16 'FAR_DATA'
F158_FAR	ends
F159_FAR	segment para public use16 'FAR_DATA'
F159_FAR	ends
F160_FAR	segment para public use16 'FAR_DATA'
F160_FAR	ends
F161_FAR	segment para public use16 'FAR_DATA'
F161_FAR	ends
F162_FAR	segment para public use16 'FAR_DATA'
F162_FAR	ends
F163_FAR	segment para public use16 'FAR_DATA'
F163_FAR	ends
F164_FAR	segment para public use16 'FAR_DATA'
F164_FAR	ends
F165_FAR	segment para public use16 'FAR_DATA'
F165_FAR	ends
F166_FAR	segment para public use16 'FAR_DATA'
F166_FAR	ends
F167_FAR	segment para public use16 'FAR_DATA'
F167_FAR	ends
F168_FAR	segment para public use16 'FAR_DATA'
F168_FAR	ends
F169_FAR	segment para public use16 'FAR_DATA'
F169_FAR	ends
F170_FAR	segment para public use16 'FAR_DATA'
F170_FAR	ends
F171_FAR	segment para public use16 'FAR_DATA'
F171_FAR	ends
F172_FAR	segment para public use16 'FAR_DATA'
F172_FAR	ends
F173_FAR	segment para public use16 'FAR_DATA'
F173_FAR	ends
F174_FAR	segment para public use16 'FAR_DATA'
F174_FAR	ends
F175_FAR	segment para public use16 'FAR_DATA'
F175_FAR	ends
F176_FAR	segment para public use16 'FAR_DATA'
F176_FAR	ends
F177_FAR	segment para public use16 'FAR_DATA'
F177_FAR	ends
F178_FAR	segment para public use16 'FAR_DATA'
F178_FAR	ends
F179_FAR	segment para public use16 'FAR_DATA'
F179_FAR	ends
F180_FAR	segment para public use16 'FAR_DATA'
F180_FAR	ends
F181_FAR	segment para public use16 'FAR_DATA'
F181_FAR	ends
F182_FAR	segment para public use16 'FAR_DATA'
F182_FAR	ends
F183_FAR	segment para public use16 'FAR_DATA'
F183_FAR	ends
F184_FAR	segment para public use16 'FAR_DATA'
F184_FAR	ends
F185_FAR	segment para public use16 'FAR_DATA'
F185_FAR	ends
F186_FAR	segment para public use16 'FAR_DATA'
F186_FAR	ends
F187_FAR	segment para public use16 'FAR_DATA'
F187_FAR	ends
F188_FAR	segment para public use16 'FAR_DATA'
F188_FAR	ends
F189_FAR	segment para public use16 'FAR_DATA'
F189_FAR	ends
F190_FAR	segment para public use16 'FAR_DATA'
F190_FAR	ends
F191_FAR	segment para public use16 'FAR_DATA'
F191_FAR	ends
F192_FAR	segment para public use16 'FAR_DATA'
F192_FAR	ends
F193_FAR	segment para public use16 'FAR_DATA'
F193_FAR	ends
F194_FAR	segment para public use16 'FAR_DATA'
F194_FAR	ends
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	extrn	__argv:word, _environ:word	; pull SETARGV, SETENVP
	extrn	_fn_1f7f_0000:far, _fn_1f84_000a:far, _s129_empty:far, _s148_empty:far	; pull WW s074 s077 s129 s148
	extrn	_fn_09aa_0197:far, _fn_09aa_01e4:far, _fn_09aa_0219:far, _fn_09aa_026a:far, _fn_09aa_02bb:far, _fn_09aa_033f:far
	extrn	_fn_0c59_00ef:far, _fn_0c59_015f:far, _fn_0ca0_0012:far, _fn_0ca0_01cf:far, _fn_0ca0_0281:far, _fn_0ca0_02b2:far
	extrn	_fn_0ca0_030a:far, _fn_0ca0_039a:far, _fn_0ca0_03cf:far, _fn_0ca0_04dc:far, _fn_0ca0_0630:far, _fn_0ca0_0662:far
	extrn	_fn_0ca0_06cb:far, _fn_0ca0_079a:far, _fn_0ca0_07e9:far, _fn_0ca0_08af:far, _fn_13e8_02fa:far, _ovr_2d22_0034:far
	extrn	_ovr_2d22_0039:far, _ovr_2d22_004d:far, _ovr_2d22_0057:far, _ovr_2d56_0020:far, _ovr_2d5f_002a:far, _ovr_2d7a_0020:far
	extrn	_ovr_2d8a_002f:far, _ovr_2d8a_0034:far, _ovr_2d8a_003e:far, _ovr_2d8a_0043:far, _ovr_2d8a_0048:far, _ovr_2d8a_004d:far
	extrn	_ovr_2d8a_0052:far, _ovr_2d8a_0057:far, _ovr_2d8a_005c:far, _ovr_2d8a_0061:far, _ovr_2d8a_0066:far, _ovr_2d8a_006b:far
	extrn	_ovr_2d8a_0070:far, _ovr_2d8a_0075:far
	public	_f_2568_0000, _f_2656_0000
	public	_g_0094, _g_0096, _g_0097, _g_0098, _g_0099, _g_009a, _g_009b, _g_009c, _g_009d, _g_009e, _g_009f, _g_00a0
	public	_g_00a7, _g_00aa, _g_00ab, _g_00ad, _g_00ae, _g_00af, _g_00b0, _g_00b1, _g_00b2, _g_00b3, _g_00b4, _g_00b5
	public	_g_00b6, _g_00b7, _g_00b8, _g_00b9, _g_00ba, _g_00bb, _g_00bc, _g_00bd, _g_00be, _g_00bf, _g_00c0, _g_00c1
	public	_g_00c2, _g_00c7, _g_00c8, _g_00c9, _g_00ca, _g_00cc, _g_00ce, _g_00d0, _g_00d1, _g_00d2, _g_00d4, _g_00d8
	public	_g_00d9, _g_00da, _g_00dc, _g_00e1, _g_00e3, _g_00e4, _g_00e5, _g_00e6, _g_00e7, _g_00e8, _g_00ea, _g_00eb
	public	_g_00ef, _g_00f0, _g_00f4, _g_00fe, _g_00ff, _g_0100, _g_0101, _g_0102, _g_0104, _g_010e, _g_0118, _g_0124
	public	_g_012b, _g_012c, _g_012f, _g_0131, _g_0133, _g_013b, _g_013f, _g_0140, _g_0145, _g_014a, _g_014c, _g_0161
	public	_g_0167, _g_0169, _g_0180, _g_01a4, _g_0200, _g_020a, _g_020d, _g_0230, _g_0233, _g_0256, _g_0258, _g_026a
	public	_g_0272, _g_0276, _g_0277, _g_028d, _g_0294, _g_02a2, _g_02df, _g_0300, _g_030a, _g_034f, _g_036d, _g_03b4
	public	_g_03c8, _g_03c9, _g_03da, _g_03fc, _g_0400, _g_040c, _g_0413, _g_0430, _g_0449, _g_0458, _g_0492, _g_04b8
	public	_g_04c0, _g_04c8, _g_04d0, _g_04d8, _g_04e0, _g_04e8, _g_04f0, _g_04f8, _g_0500, _g_0508, _g_050f, _g_0510
	public	_g_0518, _g_0520, _g_0528, _g_052f, _g_0530, _g_0538, _g_053f, _g_0540, _g_0547, _g_0548, _g_0550, _g_0558
	public	_g_0560, _g_0568, _g_056b, _g_0570, _g_0578, _g_0580, _g_0588, _g_058f, _g_0590, _g_0598, _g_0599, _g_05a0
	public	_g_05a8, _g_05d0, _g_05e0, _g_05e1, _g_05e8, _g_05f0, _g_05f8, _g_0607, _g_0610, _g_0624, _g_0628, _g_0629
	public	_g_0646, _g_0671, _g_0685, _g_0695, _g_06a7, _g_06be, _g_06d5, _g_06d7, _g_06d9, _g_06dd, _g_06e1, _g_06e9
	public	_g_06ec, _g_06ee, _g_06f0, _g_06f2, _g_06f4, _g_06f6, _g_06f8, _g_06fa, _g_06fc, _g_06fe, _g_0702, _g_0704
	public	_g_0706, _g_0708, _g_070a, _g_070e, _g_0710, _g_0714, _g_0718, _g_071c, _g_0720, _g_0721, _g_0722, _g_0723
	public	_g_075c, _g_075d, _g_0774, _g_077d, _g_0780, _g_0787, _g_0790, _g_0791, _g_079d, _g_07a9, _g_07b5, _g_07b9
	public	_g_07c6, _g_07c8, _g_07ef, _g_07f9, _g_0800, _g_081a, _g_0827, _g_0834, _g_0840, _g_0841, _g_084e, _g_087e
	public	_g_0880, _g_088e, _g_0890, _g_08ae, _g_08b4, _g_08ba, _g_08be, _g_08c6, _g_08ce, _g_08db, _g_08e0, _g_08e3
	public	_g_0907, _g_093e, _g_0946, _g_0962, _g_0964, _g_096c, _g_098c, _g_098f, _g_099d, _g_09bc, _g_09c1, _g_09cb
	public	_g_09d5, _g_09e1, _g_09e4, _g_09e6, _g_0a13, _g_0a18, _g_0a20, _g_0a38, _g_0a46, _g_0a54, _g_0a56, _g_0a62
	public	_g_0a68, _g_0a6c, _g_0a6e, _g_0a93, _g_0a9c, _g_0aba, _g_0abc, _g_0afa, _g_0afc, _g_0afe, _g_0b00, _g_0b02
	public	_g_0b04, _g_0b06, _g_0b08, _g_0b0a, _g_0b0c, _g_0b15, _g_0b1f, _g_0b44, _g_0b46, _g_0b4e, _g_0b53, _g_0b58
	public	_g_0b5d, _g_0b62, _g_0b6a, _g_0b77, _g_0b84, _g_0b8d, _g_0baa, _g_0bb2, _g_0bcf, _g_0bf2, _g_0bfe, _g_0c21
	public	_g_0c23, _g_0c2b, _g_0c35, _g_0c36, _g_0c4c, _g_0c4d, _g_0c4f, _g_0c5d, _g_0c60, _g_0c6e, _g_0c70, _g_0c71
	public	_g_0c72, _g_0c84, _g_0c86, _g_0c88, _g_0c8a, _g_0c92, _g_0c94, _g_0c99, _g_0ca7, _g_0cbf, _g_0ccf, _g_0cf4
	public	_g_0cf6, _g_0d26, _g_0d56, _g_0d5f, _g_0d6b, _g_0d75, _g_0d7f, _g_0d89, _g_0d94, _g_0d9e, _g_0da9, _g_0db3
	public	_g_0dbf, _g_0dc8, _g_0dd5, _g_0dde, _g_0dea, _g_0df4, _g_0dfe, _g_0e07, _g_0e08, _g_0e09, _g_0e13, _g_0e1d
	public	_g_0e27, _g_0e28, _g_0e32, _g_0e39, _g_0e3e, _g_0e47, _g_0e54, _g_0e60, _g_0e66, _g_0e6a, _g_0e70, _g_0e74
	public	_g_0e77, _g_0e82, _g_0eb3, _g_0ebf, _g_0ecb, _g_0ed9, _g_0efb, _g_0f04, _g_0f26, _g_0f32, _g_0f3f, _g_0f4c
	public	_g_0f58, _g_0f5d, _g_0f6a, _g_0f6f, _g_0f7a, _g_0f88, _g_0f8a, _g_0f96, _g_0fb4, _g_0fb6, _g_0fc4, _g_0fc6
	public	_g_0fc8, _g_0fca, _g_0fcc, _g_0ff6, _g_0ff8, _g_0fff, _g_1000, _g_1025, _g_1032, _g_1052, _g_1066, _g_1072
	public	_g_107e, _g_108a, _g_1096, _g_10a1, _g_10ab, _g_10b6, _g_10bc, _g_10c5, _g_10d0, _g_10d6, _g_10e3, _g_10eb
	public	_g_10f1, _g_10fb, _g_1105, _g_110d, _g_1119, _g_1125, _g_112e, _g_113a, _g_1142, _g_1152, _g_1156, _g_115a
	public	_g_115e, _g_117e, _g_118e, _g_1192, _g_1196, _g_119a, _g_11ba, _g_11bc, _g_11be, _g_11c4, _g_11ca, _g_11cc
	public	_g_11ce, _g_11d9, _g_11e4, _g_11f2, _g_11fc, _g_1202, _g_120c, _g_1216, _g_1218, _g_121e, _g_1224, _g_1228
	public	_g_122c, _g_122e, _g_1230, _g_1234, _g_1236, _g_1238, _g_123c, _g_123e, _g_1240, _g_1248, _g_1264, _g_126c
	public	_g_1277, _g_1298, _g_12a3, _g_12c4, _g_12c6, _g_12c8, _g_12ca, _g_12fc, _g_12fe, _g_1314, _g_1320, _g_132f
	public	_g_133b, _g_1348, _g_1355, _g_137d, _g_1388, _g_138a, _g_13b2, _g_13be, _g_13e5, _g_13fb, _g_1400, _g_1408
	public	_g_1424, _g_1468, _g_146a, _g_14a0, _g_14ac, _g_14ba, _g_14bc, _g_14be, _g_14c1, _g_14c4, _g_14c8, _g_14ca
	public	_g_14cc, _g_14f3, _g_14fd, _g_150d, _g_1510, _g_151e, _g_1520, _g_1547, _g_154c, _g_1551, _g_1572, _g_157b
	public	_g_1583, _g_158a, _g_1592, _g_1594, _g_1598, _g_159c, _g_15a0, _g_15a4, _g_15a8, _g_15ac, _g_15b0, _g_15e0
	public	_g_15f8, _g_15fc, _g_1600, _g_1604, _g_1608, _g_160c, _g_1610, _g_1614, _g_1618, _g_162c, _g_163a, _g_164a
	public	_g_1658, _g_1666, _g_1676, _g_1684, _g_168b, _g_169e, _g_16ae, _g_16be, _g_16cf, _g_16e0, _g_16eb, _g_16f1
	public	_g_1702, _g_1713, _g_1724, _g_172d, _g_1735, _g_1746, _g_1758, _g_176a, _g_177c, _g_178e, _g_17a0, _g_17b2
	public	_g_17c4, _g_17d6, _g_1807, _g_1808, _g_1819, _g_182b, _g_1842, _g_1853, _g_1864, _g_188a, _g_1891, _g_1895
	public	_g_1899, _g_189d, _g_18a1, _g_18a5, _g_18a9, _g_18ae, _g_18b6, _g_18c2, _g_18c6, _g_18ca, _g_18ce, _g_18d2
	public	_g_18d6, _g_18da, _g_18de, _g_18e9, _g_18f2, _g_18fc, _g_1981, _g_198b, _g_19ae, _g_19da, _g_1a06, _g_1a0c
	public	_g_1a19, _g_1a25, _g_1a31, _g_1a3a, _g_1a3e, _g_1a47, _g_1a4b, _g_1a4f, _g_1a53, _g_1a5d, _g_1a68, _g_1a70
	public	_g_1a72, _g_1a78, _g_1a7a, _g_1a7c, _g_1a80, _g_1a82, _g_1b20, _g_1b29, _g_1b2d, _g_1b39, _g_1b3d, _g_1b49
	public	_g_1b4d, _g_1b58, _g_1b5c, _g_1b66, _g_1b6a, _g_1b76, _g_1b7a, _g_1b86, _g_1b8a, _g_1b94, _g_1b98, _g_1ba3
	public	_g_1ba7, _g_1bb1, _g_1bb5, _g_1bbe, _g_1bc2, _g_1bcd, _g_1bd1, _g_1bdc, _g_1be0, _g_1be2, _g_1be4, _g_1be8
	public	_g_1bea, _g_1c88, _g_1c91, _g_1c95, _g_1ca1, _g_1ca5, _g_1cb1, _g_1cb5, _g_1cc0, _g_1cc4, _g_1cce, _g_1cd2
	public	_g_1cde, _g_1ce2, _g_1cee, _g_1cf2, _g_1cfc, _g_1cfd, _g_1d00, _g_1d0b, _g_1d0f, _g_1d19, _g_1d1d, _g_1d26
	public	_g_1d2a, _g_1d35, _g_1d39, _g_1d44, _g_1d48, _g_1d4a, _g_1d68, _g_1d72, _g_1d7d, _g_1d88, _g_1d93, _g_1da0
	public	_g_1dab, _g_1db5, _g_1dba, _g_1dbf, _g_1dc3, _g_1dc6
F167_FAR	segment
_f_2568_0000	label	byte
	db	000h, 011h, 060h, 000h, 060h, 001h	; 0000
F167_FAR	ends
F167_FAR	segment
	dd	_fn_09aa_0197	; 0006
	db	021h, 000h, 083h, 000h, 016h, 000h, 013h, 000h, 000h, 000h, 000h, 000h, 000h, 011h, 061h, 000h	; 000a
	db	061h, 001h	; 001a
	dd	_fn_09aa_01e4	; 001c
	db	021h, 000h, 096h, 000h, 016h, 000h, 012h, 000h, 000h, 000h, 000h, 000h, 000h, 011h, 062h, 000h	; 0020
	db	062h, 001h	; 0030
	dd	_fn_09aa_01e4	; 0032
	db	021h, 000h, 096h, 000h, 016h, 000h, 012h, 000h, 000h, 000h, 000h, 000h, 000h, 011h, 05ch, 000h	; 0036
	db	05ch, 001h	; 0046
	dd	_fn_09aa_0219	; 0048
	db	00bh, 000h, 096h, 000h, 016h, 000h, 012h, 000h, 000h, 000h, 000h, 000h, 000h, 011h, 066h, 000h	; 004c
	db	066h, 001h	; 005c
	dd	_fn_09aa_026a	; 005e
	db	035h, 000h, 096h, 000h, 016h, 000h, 012h, 000h, 000h, 000h, 000h, 000h, 000h, 011h, 05bh, 000h	; 0062
	db	05bh, 001h	; 0072
	dd	_fn_09aa_02bb	; 0074
	db	00bh, 000h, 083h, 000h, 016h, 000h, 013h, 000h, 000h, 000h, 000h, 000h, 000h, 011h, 065h, 000h	; 0078
	db	065h, 001h	; 0088
	dd	_fn_09aa_033f	; 008a
	db	035h, 000h, 083h, 000h, 016h, 000h, 013h, 000h, 000h, 000h, 000h, 000h, 000h, 001h, 070h, 000h	; 008e
	db	000h, 000h	; 009e
	dd	_fn_0ca0_0012	; 00a0
	db	050h, 000h, 08fh, 000h, 016h, 000h, 011h, 000h, 000h, 000h, 000h, 000h, 000h, 001h, 071h, 000h	; 00a4
	db	000h, 000h	; 00b4
	dd	_fn_0ca0_0012	; 00b6
	db	050h, 000h, 08fh, 000h, 016h, 000h, 011h, 000h, 001h, 000h, 000h, 000h, 000h, 001h, 072h, 000h	; 00ba
	db	000h, 000h	; 00ca
	dd	_fn_0ca0_0012	; 00cc
	db	050h, 000h, 08fh, 000h, 016h, 000h, 011h, 000h, 002h, 000h, 000h, 000h, 000h, 001h, 073h, 000h	; 00d0
	db	000h, 000h	; 00e0
	dd	_fn_0ca0_0012	; 00e2
	db	050h, 000h, 08fh, 000h, 016h, 000h, 011h, 000h, 003h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 00e6
	db	000h, 000h	; 00f6
	dd	_fn_0ca0_0662	; 00f8
	db	050h, 000h, 0a0h, 000h, 016h, 000h, 011h, 000h, 000h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 00fc
	db	000h, 000h	; 010c
	dd	_fn_0ca0_0662	; 010e
	db	050h, 000h, 0a0h, 000h, 016h, 000h, 011h, 000h, 001h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 0112
	db	000h, 000h	; 0122
	dd	_fn_0ca0_0662	; 0124
	db	050h, 000h, 0a0h, 000h, 016h, 000h, 011h, 000h, 002h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 0128
	db	000h, 000h	; 0138
	dd	_fn_0ca0_0662	; 013a
	db	050h, 000h, 0a0h, 000h, 016h, 000h, 011h, 000h, 003h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 013e
	db	000h, 000h	; 014e
	dd	_fn_0ca0_06cb	; 0150
	db	050h, 000h, 090h, 000h, 016h, 000h, 020h, 000h, 000h, 000h, 000h, 000h, 000h, 011h, 06eh, 000h	; 0154
	db	000h, 000h	; 0164
	dd	_fn_0ca0_079a	; 0166
	db	000h, 000h, 000h, 000h, 040h, 001h, 0c8h, 000h, 003h, 000h, 000h, 000h, 000h, 001h, 000h, 000h	; 016a
	db	000h, 000h	; 017a
	dd	_ovr_2d22_0039	; 017c
	db	050h, 000h, 08fh, 000h, 021h, 000h, 022h, 000h, 000h, 000h, 000h, 000h, 000h, 001h, 000h, 000h	; 0180
	db	000h, 000h	; 0190
	dd	_ovr_2d22_0039	; 0192
	db	050h, 000h, 08fh, 000h, 021h, 000h, 022h, 000h, 001h, 000h, 000h, 000h, 000h, 001h, 000h, 000h	; 0196
	db	000h, 000h	; 01a6
	dd	_ovr_2d22_0039	; 01a8
	db	050h, 000h, 08fh, 000h, 021h, 000h, 022h, 000h, 002h, 000h, 000h, 000h, 000h, 001h, 000h, 000h	; 01ac
	db	000h, 000h	; 01bc
	dd	_ovr_2d22_0039	; 01be
	db	050h, 000h, 08fh, 000h, 021h, 000h, 022h, 000h, 003h, 000h, 000h, 000h, 000h, 001h, 000h, 000h	; 01c2
	db	000h, 000h	; 01d2
	dd	_ovr_2d22_0039	; 01d4
	db	050h, 000h, 08fh, 000h, 042h, 000h, 022h, 000h, 000h, 000h, 000h, 000h, 000h, 001h, 000h, 000h	; 01d8
	db	000h, 000h	; 01e8
	dd	_ovr_2d22_0039	; 01ea
	db	050h, 000h, 08fh, 000h, 042h, 000h, 022h, 000h, 001h, 000h, 000h, 000h, 000h, 001h, 000h, 000h	; 01ee
	db	000h, 000h	; 01fe
	dd	_ovr_2d22_0039	; 0200
	db	050h, 000h, 08fh, 000h, 042h, 000h, 022h, 000h, 002h, 000h, 000h, 000h, 000h, 001h, 000h, 000h	; 0204
	db	000h, 000h	; 0214
	dd	_ovr_2d22_0039	; 0216
	db	050h, 000h, 08fh, 000h, 042h, 000h, 022h, 000h, 003h, 000h, 000h, 000h, 000h, 001h, 000h, 000h	; 021a
	db	000h, 000h	; 022a
	dd	_fn_0ca0_030a	; 022c
	db	050h, 000h, 08fh, 000h, 00ch, 000h, 022h, 000h, 000h, 000h, 000h, 000h, 000h, 001h, 000h, 000h	; 0230
	db	000h, 000h	; 0240
	dd	_fn_0ca0_030a	; 0242
	db	050h, 000h, 08fh, 000h, 00ch, 000h, 022h, 000h, 001h, 000h, 000h, 000h, 000h, 001h, 000h, 000h	; 0246
	db	000h, 000h	; 0256
	dd	_fn_0ca0_030a	; 0258
	db	050h, 000h, 08fh, 000h, 00ch, 000h, 022h, 000h, 002h, 000h, 000h, 000h, 000h, 001h, 000h, 000h	; 025c
	db	000h, 000h	; 026c
	dd	_fn_0ca0_030a	; 026e
	db	050h, 000h, 08fh, 000h, 00ch, 000h, 022h, 000h, 003h, 000h, 000h, 000h, 000h, 010h, 000h, 000h	; 0272
	db	000h, 000h	; 0282
	dd	_fn_0ca0_04dc	; 0284
	db	050h, 000h, 08fh, 000h, 042h, 000h, 022h, 000h, 000h, 000h, 000h, 000h, 000h, 010h, 000h, 000h	; 0288
	db	000h, 000h	; 0298
	dd	_fn_0ca0_04dc	; 029a
	db	050h, 000h, 08fh, 000h, 042h, 000h, 022h, 000h, 001h, 000h, 000h, 000h, 000h, 010h, 000h, 000h	; 029e
	db	000h, 000h	; 02ae
	dd	_fn_0ca0_04dc	; 02b0
	db	050h, 000h, 08fh, 000h, 042h, 000h, 022h, 000h, 002h, 000h, 000h, 000h, 000h, 010h, 000h, 000h	; 02b4
	db	000h, 000h	; 02c4
	dd	_fn_0ca0_04dc	; 02c6
	db	050h, 000h, 08fh, 000h, 042h, 000h, 022h, 000h, 003h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 02ca
	db	000h, 000h	; 02da
	dd	_ovr_2d22_004d	; 02dc
	db	000h, 000h, 000h, 000h, 014h, 000h, 013h, 000h, 000h, 000h, 002h, 000h, 000h, 011h, 000h, 000h	; 02e0
	db	000h, 000h	; 02f0
	dd	_ovr_2d22_004d	; 02f2
	db	000h, 000h, 000h, 000h, 014h, 000h, 013h, 000h, 001h, 000h, 002h, 000h, 000h, 011h, 000h, 000h	; 02f6
F167_FAR	ends
F167_FAR	segment
	db	000h, 000h	; 0306
	dd	_ovr_2d22_004d	; 0308
	db	000h, 000h, 000h, 000h, 014h, 000h, 013h, 000h, 002h, 000h, 002h, 000h, 000h, 011h, 000h, 000h	; 030c
	db	000h, 000h	; 031c
	dd	_ovr_2d22_004d	; 031e
	db	000h, 000h, 000h, 000h, 014h, 000h, 013h, 000h, 003h, 000h, 002h, 000h, 000h, 011h, 000h, 000h	; 0322
	db	000h, 000h	; 0332
	dd	_ovr_2d22_004d	; 0334
	db	000h, 000h, 000h, 000h, 014h, 000h, 013h, 000h, 004h, 000h, 002h, 000h, 000h, 011h, 000h, 000h	; 0338
	db	000h, 000h	; 0348
	dd	_ovr_2d22_004d	; 034a
	db	000h, 000h, 000h, 000h, 014h, 000h, 013h, 000h, 005h, 000h, 002h, 000h, 000h, 011h, 000h, 000h	; 034e
	db	000h, 000h	; 035e
	dd	_ovr_2d22_004d	; 0360
	db	000h, 000h, 000h, 000h, 014h, 000h, 013h, 000h, 006h, 000h, 002h, 000h, 000h, 011h, 000h, 000h	; 0364
	db	000h, 000h	; 0374
	dd	_ovr_2d22_004d	; 0376
	db	000h, 000h, 000h, 000h, 014h, 000h, 013h, 000h, 007h, 000h, 002h, 000h, 000h, 011h, 000h, 000h	; 037a
	db	000h, 000h	; 038a
	dd	_ovr_2d22_004d	; 038c
	db	000h, 000h, 000h, 000h, 014h, 000h, 013h, 000h, 008h, 000h, 002h, 000h, 000h, 011h, 000h, 000h	; 0390
	db	000h, 000h	; 03a0
	dd	_ovr_2d22_004d	; 03a2
	db	000h, 000h, 000h, 000h, 00ch, 000h, 00bh, 000h, 009h, 000h, 002h, 000h, 000h, 011h, 000h, 000h	; 03a6
	db	000h, 000h	; 03b6
	dd	_ovr_2d22_004d	; 03b8
	db	000h, 000h, 000h, 000h, 00ch, 000h, 00bh, 000h, 00ah, 000h, 002h, 000h, 000h, 011h, 06eh, 000h	; 03bc
	db	000h, 000h	; 03cc
	dd	_ovr_2d22_0034	; 03ce
	db	0a0h, 000h, 05dh, 000h, 02bh, 000h, 013h, 000h, 000h, 000h, 002h, 000h, 000h, 011h, 000h, 000h	; 03d2
	db	000h, 000h	; 03e2
	dd	_fn_0ca0_08af	; 03e4
	db	000h, 000h, 066h, 000h, 058h, 000h, 013h, 000h, 000h, 000h, 002h, 000h, 000h, 011h, 000h, 000h	; 03e8
	db	000h, 000h	; 03f8
	dd	_fn_0ca0_08af	; 03fa
	db	'X',0	; 03fe
F167_FAR	ends
F167_FAR	segment
	db	066h, 000h, 058h, 000h, 013h, 000h, 001h, 000h, 002h, 000h, 000h, 011h, 000h, 000h, 000h, 000h	; 0400
F167_FAR	ends
F167_FAR	segment
	dd	_fn_0ca0_08af	; 0410
	db	000h, 000h, 055h, 000h, 058h, 000h, 011h, 000h, 002h, 000h, 002h, 000h, 000h, 011h, 000h, 000h	; 0414
	db	000h, 000h	; 0424
	dd	_fn_0ca0_08af	; 0426
	db	058h, 000h, 055h, 000h, 058h, 000h, 011h, 000h, 003h, 000h, 002h, 000h, 000h, 011h, 000h, 000h	; 042a
	db	000h, 000h	; 043a
	dd	_fn_0ca0_07e9	; 043c
	db	000h, 000h, 000h, 000h, 0b0h, 000h, 078h, 000h, 000h, 000h, 002h, 000h, 000h, 011h, 000h, 000h	; 0440
	db	000h, 000h	; 0450
	dd	_fn_0c59_015f	; 0452
	db	06ah, 000h, 0b3h, 000h, 015h, 000h, 015h, 000h, 000h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 0456
	db	000h, 000h	; 0466
	dd	_fn_0c59_015f	; 0468
	db	07fh, 000h, 0b3h, 000h, 015h, 000h, 015h, 000h, 001h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 046c
	db	000h, 000h	; 047c
	dd	_fn_0c59_015f	; 047e
	db	094h, 000h, 0b3h, 000h, 015h, 000h, 015h, 000h, 002h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 0482
	db	000h, 000h	; 0492
	dd	_fn_0c59_015f	; 0494
	db	0a9h, 000h, 0b3h, 000h, 015h, 000h, 015h, 000h, 003h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 0498
	db	000h, 000h	; 04a8
	dd	_fn_0c59_015f	; 04aa
	db	0beh, 000h, 0b3h, 000h, 015h, 000h, 015h, 000h, 004h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 04ae
	db	000h, 000h	; 04be
	dd	_fn_0c59_015f	; 04c0
	db	0d3h, 000h, 0b3h, 000h, 015h, 000h, 015h, 000h, 005h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 04c4
	db	000h, 000h	; 04d4
	dd	_fn_0c59_015f	; 04d6
	db	0e8h, 000h, 0b3h, 000h, 015h, 000h, 015h, 000h, 006h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 04da
	db	000h, 000h	; 04ea
	dd	_fn_0c59_015f	; 04ec
	db	0fdh, 000h, 0b3h, 000h, 015h, 000h, 015h, 000h, 007h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 04f0
	db	000h, 000h	; 0500
	dd	_fn_0c59_015f	; 0502
	db	012h, 001h, 0b3h, 000h, 015h, 000h, 015h, 000h, 008h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 0506
	db	000h, 000h	; 0516
	dd	_fn_0c59_015f	; 0518
	db	012h, 001h, 0b3h, 000h, 015h, 000h, 015h, 000h, 009h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 051c
	db	000h, 000h	; 052c
	dd	_fn_0c59_00ef	; 052e
	db	055h, 000h, 0b3h, 000h, 015h, 000h, 015h, 000h, 0ffh, 0ffh, 000h, 000h, 000h, 011h, 000h, 000h	; 0532
	db	000h, 000h	; 0542
	dd	_fn_0c59_00ef	; 0544
	db	027h, 001h, 0b3h, 000h, 016h, 000h, 015h, 000h, 001h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 0548
	db	000h, 000h	; 0558
	dd	_fn_13e8_02fa	; 055a
	db	018h, 000h, 008h, 000h, 080h, 000h, 060h, 000h, 001h, 000h, 002h, 000h, 000h, 011h, 000h, 000h	; 055e
	db	000h, 000h	; 056e
	dd	_fn_13e8_02fa	; 0570
	db	000h, 000h, 000h, 000h, 0b0h, 000h, 078h, 000h, 000h, 000h, 002h, 000h, 000h, 011h, 000h, 000h	; 0574
	db	000h, 000h	; 0584
	dd	_ovr_2d5f_002a	; 0586
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 058a
	db	000h, 000h	; 059a
	dd	_fn_09aa_0197	; 059c
	db	070h, 000h, 000h, 000h, 0b0h, 000h, 010h, 000h, 001h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 05a0
	db	000h, 000h	; 05b0
	dd	_fn_09aa_01e4	; 05b2
	db	070h, 000h, 06eh, 000h, 0b0h, 000h, 01ah, 000h, 001h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 05b6
	db	000h, 000h	; 05c6
	dd	_fn_09aa_0219	; 05c8
	db	060h, 000h, 058h, 000h, 020h, 000h, 020h, 000h, 001h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 05cc
	db	000h, 000h	; 05dc
	dd	_fn_09aa_026a	; 05de
	db	010h, 001h, 058h, 000h, 020h, 000h, 020h, 000h, 001h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 05e2
	db	000h, 000h	; 05f2
	dd	_fn_09aa_02bb	; 05f4
	db	060h, 000h, 010h, 000h, 020h, 000h, 048h, 000h, 001h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 05f8
	db	000h, 000h	; 0608
	dd	_fn_09aa_033f	; 060a
	db	010h, 001h, 010h, 000h, 020h, 000h, 048h, 000h, 001h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 060e
	db	000h, 000h	; 061e
	dd	_fn_0ca0_0630	; 0620
	db	018h, 000h, 00fh, 000h, 03dh, 000h, 009h, 000h, 000h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 0624
	db	000h, 000h	; 0634
	dd	_fn_0ca0_0630	; 0636
	db	018h, 000h, 018h, 000h, 03dh, 000h, 009h, 000h, 000h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 063a
	db	000h, 000h	; 064a
	dd	_fn_0ca0_0630	; 064c
	db	018h, 000h, 021h, 000h, 03dh, 000h, 009h, 000h, 000h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 0650
	db	000h, 000h	; 0660
	dd	_fn_0ca0_0630	; 0662
	db	018h, 000h, 02ah, 000h, 03dh, 000h, 009h, 000h, 000h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 0666
	db	000h, 000h	; 0676
	dd	_fn_0ca0_0630	; 0678
	db	018h, 000h, 033h, 000h, 03dh, 000h, 009h, 000h, 000h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 067c
	db	000h, 000h	; 068c
	dd	_fn_0ca0_0630	; 068e
	db	018h, 000h, 03ch, 000h, 03dh, 000h, 009h, 000h, 000h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 0692
	db	000h, 000h	; 06a2
	dd	_fn_0ca0_0630	; 06a4
	db	018h, 000h, 045h, 000h, 03dh, 000h, 009h, 000h, 000h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 06a8
	db	000h, 000h	; 06b8
	dd	_fn_0ca0_0630	; 06ba
	db	018h, 000h, 04eh, 000h, 03dh, 000h, 009h, 000h, 000h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 06be
	db	000h, 000h	; 06ce
	dd	_fn_0ca0_0630	; 06d0
	db	018h, 000h, 057h, 000h, 03dh, 000h, 009h, 000h, 000h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 06d4
	db	000h, 000h	; 06e4
	dd	_fn_0ca0_0630	; 06e6
	db	018h, 000h, 060h, 000h, 03dh, 000h, 009h, 000h, 000h, 000h, 000h, 000h, 000h, 001h, 000h, 000h	; 06ea
	db	000h, 000h	; 06fa
	dd	_ovr_2d8a_0034	; 06fc
	db	050h, 000h, 08fh, 000h, 042h, 000h, 022h, 000h, 000h, 000h, 000h, 000h, 000h, 001h, 000h, 000h	; 0700
F167_FAR	ends
F167_FAR	segment
	db	000h, 000h	; 0710
	dd	_ovr_2d8a_0034	; 0712
	db	050h, 000h, 08fh, 000h, 042h, 000h, 022h, 000h, 001h, 000h, 000h, 000h, 000h, 001h, 000h, 000h	; 0716
	db	000h, 000h	; 0726
	dd	_ovr_2d8a_0034	; 0728
	db	050h, 000h, 08fh, 000h, 042h, 000h, 022h, 000h, 002h, 000h, 000h, 000h, 000h, 001h, 000h, 000h	; 072c
	db	000h, 000h	; 073c
	dd	_ovr_2d8a_0034	; 073e
	db	050h, 000h, 08fh, 000h, 042h, 000h, 022h, 000h, 003h, 000h, 000h, 000h, 000h, 011h, 06eh, 000h	; 0742
	db	000h, 000h	; 0752
	dd	_ovr_2d8a_002f	; 0754
	db	000h, 000h, 000h, 000h, 040h, 001h, 0c8h, 000h, 003h, 000h, 000h, 000h, 000h, 001h, 000h, 000h	; 0758
	db	000h, 000h	; 0768
	dd	_fn_0ca0_01cf	; 076a
	db	070h, 000h, 000h, 000h, 058h, 000h, 050h, 000h, 000h, 000h, 000h, 000h, 000h, 001h, 000h, 000h	; 076e
	db	000h, 000h	; 077e
	dd	_fn_0ca0_01cf	; 0780
	db	0c8h, 000h, 000h, 000h, 058h, 000h, 050h, 000h, 001h, 000h, 000h, 000h, 000h, 011h, 019h, 000h	; 0784
	db	06eh, 000h	; 0794
	dd	_ovr_2d56_0020	; 0796
	db	00bh, 000h, 0b2h, 000h, 015h, 000h, 016h, 000h, 000h, 000h, 000h, 000h, 000h, 001h, 014h, 000h	; 079a
	db	000h, 000h	; 07aa
	dd	_ovr_2d7a_0020	; 07ac
	db	020h, 000h, 0b2h, 000h, 016h, 000h, 016h, 000h, 000h, 000h, 000h, 000h, 000h, 001h, 000h, 000h	; 07b0
	db	000h, 000h	; 07c0
	dd	_fn_0ca0_0281	; 07c2
	db	023h, 001h, 060h, 000h, 01bh, 000h, 018h, 000h, 000h, 000h, 000h, 000h, 000h, 001h, 000h, 000h	; 07c6
	db	000h, 000h	; 07d6
	dd	_fn_0ca0_02b2	; 07d8
	db	021h, 001h, 000h, 000h, 01fh, 000h, 01ch, 000h, 000h, 000h, 000h, 000h, 000h, 001h, 000h, 000h	; 07dc
	db	000h, 000h	; 07ec
	dd	_fn_0ca0_039a	; 07ee
	db	021h, 001h, 01fh, 000h, 01fh, 000h, 017h, 000h, 000h, 000h, 000h, 000h, 000h, 001h	; 07f2
F167_FAR	ends
F167_FAR	segment
	db	000h, 000h, 000h, 000h	; 0800
F167_FAR	ends
F167_FAR	segment
	dd	_fn_0ca0_03cf	; 0804
	db	023h, 001h, 038h, 000h, 01dh, 000h, 018h, 000h, 000h, 000h, 000h, 000h, 000h, 011h, 000h, 000h	; 0808
	db	000h, 000h	; 0818
	dd	_ovr_2d22_0057	; 081a
	db	0dch, 000h, 062h, 000h, 02bh, 000h, 013h, 000h, 000h, 000h, 000h, 000h	; 081e
F167_FAR	ends
_DATA	segment
_g_0094	label	byte
	db	002h, 003h	; 0094
_g_0096	label	byte
	db	000h	; 0096
_g_0097	label	byte
	db	001h	; 0097
_g_0098	label	byte
	db	001h	; 0098
_g_0099	label	byte
	db	002h	; 0099
_g_009a	label	byte
	db	003h	; 009a
_g_009b	label	byte
	db	000h	; 009b
_g_009c	label	byte
	db	003h	; 009c
_g_009d	label	byte
	db	000h	; 009d
_g_009e	label	byte
	db	001h	; 009e
_g_009f	label	byte
	db	002h	; 009f
_g_00a0	label	byte
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h	; 00a0
_g_00a7	label	byte
	db	001h, 001h, 001h	; 00a7
_g_00aa	label	byte
	db	001h	; 00aa
_g_00ab	label	byte
	db	001h, 002h	; 00ab
_g_00ad	label	byte
	db	002h	; 00ad
_g_00ae	label	byte
	db	002h	; 00ae
_g_00af	label	byte
	db	003h	; 00af
_g_00b0	label	byte
	db	003h	; 00b0
_g_00b1	label	byte
	db	003h	; 00b1
_g_00b2	label	byte
	db	075h	; 00b2
_g_00b3	label	byte
	db	000h	; 00b3
_g_00b4	label	byte
	db	06ah	; 00b4
_g_00b5	label	byte
	db	000h	; 00b5
_g_00b6	label	byte
	db	0b9h	; 00b6
_g_00b7	label	byte
	db	000h	; 00b7
_g_00b8	label	byte
	db	0b2h	; 00b8
_g_00b9	label	byte
	db	000h	; 00b9
_g_00ba	label	byte
	db	000h	; 00ba
_g_00bb	label	byte
	db	001h	; 00bb
_g_00bc	label	byte
	db	000h	; 00bc
_g_00bd	label	byte
	db	001h	; 00bd
_g_00be	label	byte
	db	000h	; 00be
_g_00bf	label	byte
	db	000h	; 00bf
_g_00c0	label	byte
	db	000h	; 00c0
_g_00c1	label	byte
	db	000h	; 00c1
_g_00c2	label	byte
	db	000h, 000h, 000h, 000h, 001h	; 00c2
_g_00c7	label	byte
	db	000h	; 00c7
_g_00c8	label	byte
	db	001h	; 00c8
_g_00c9	label	byte
	db	000h	; 00c9
_g_00ca	label	byte
	db	001h, 000h	; 00ca
_g_00cc	label	byte
	db	002h, 000h	; 00cc
_g_00ce	label	byte
	db	002h, 000h	; 00ce
_g_00d0	label	byte
	db	003h	; 00d0
_g_00d1	label	byte
	db	000h	; 00d1
_g_00d2	label	byte
	db	003h, 000h	; 00d2
_g_00d4	label	byte
	db	003h, 000h, 004h, 000h	; 00d4
_g_00d8	label	byte
	db	004h	; 00d8
_g_00d9	label	byte
	db	000h	; 00d9
_g_00da	label	byte
	db	005h, 000h	; 00da
_g_00dc	label	byte
	db	005h, 000h, 005h, 000h, 006h	; 00dc
_g_00e1	label	byte
	db	000h, 006h	; 00e1
_g_00e3	label	byte
	db	000h	; 00e3
_g_00e4	label	byte
	db	007h	; 00e4
_g_00e5	label	byte
	db	000h	; 00e5
_g_00e6	label	byte
	db	007h	; 00e6
_g_00e7	label	byte
	db	000h	; 00e7
_g_00e8	label	byte
	db	007h, 000h	; 00e8
_g_00ea	label	byte
	db	005h	; 00ea
_g_00eb	label	byte
	db	000h, 002h, 000h, 008h	; 00eb
_g_00ef	label	byte
	db	000h	; 00ef
_g_00f0	label	byte
	db	07ch, 078h, 074h, 070h	; 00f0
_g_00f4	label	byte
	db	06ch, 068h, 065h, 062h, 05fh, 05ch, 059h, 056h, 053h, 050h	; 00f4
_g_00fe	label	byte
	db	04dh	; 00fe
_g_00ff	label	byte
	db	04ah	; 00ff
_g_0100	label	byte
	db	048h	; 0100
_g_0101	label	byte
	db	046h	; 0101
_g_0102	label	byte
	db	044h, 043h	; 0102
_g_0104	label	byte
	db	041h, 040h, 03eh, 03dh, 03ch, 03bh, 03ah, 039h, 038h, 038h	; 0104
_g_010e	label	byte
	db	098h, 098h, 090h, 088h, 080h, 076h, 06eh, 068h, 062h, 05ch	; 010e
_g_0118	label	byte
	db	058h, 054h, 050h, 04ah, 044h, 040h, 03ch, 038h, 036h, 032h, 030h, 02ch	; 0118
_g_0124	label	byte
	db	02ah, 028h, 026h, 024h, 022h, 020h, 020h	; 0124
_g_012b	label	byte
	db	01eh	; 012b
_g_012c	label	byte
	db	018h, 010h, 000h	; 012c
_g_012f	label	byte
	db	03bh, 047h	; 012f
_g_0131	label	byte
	db	056h, 078h	; 0131
_g_0133	label	byte
	db	0d7h, 0d7h, 0d7h, 0d7h, 0d7h, 0d7h, 0d7h, 0d7h	; 0133
_g_013b	label	byte
	db	0d7h, 0d7h, 0d7h, 0d7h	; 013b
_g_013f	label	byte
	db	0d7h	; 013f
_g_0140	label	byte
	db	0d7h, 0d7h, 0d7h, 0d8h, 0d7h	; 0140
_g_0145	label	byte
	db	0d8h, 0d8h, 002h, 0d8h, 0d8h	; 0145
_g_014a	label	byte
	db	0d8h, 0d8h	; 014a
_g_014c	label	byte
	db	0feh, 0d7h, 0d8h, 0d8h, 0d8h, 0d7h, 003h, 0d8h, 0fdh, 0d8h, 0d8h, 0d8h, 0feh, 0d8h, 008h, 0d8h	; 014c
	db	0d8h, 0d8h, 0feh, 0f8h, 006h	; 015c
_g_0161	label	byte
	db	0d8h, 0d8h, 0fah, 003h, 0d8h, 0fdh	; 0161
_g_0167	label	byte
	db	0d8h, 0d8h	; 0167
_g_0169	label	byte
	db	0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0fah, 0d7h, 010h, 0d8h, 0fah, 0d7h, 010h, 0d8h	; 0169
	db	0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0f2h, 0d8h	; 0179
_g_0180	label	byte
	db	014h, 0d8h, 0d8h, 0d8h, 0f0h, 00eh, 014h, 0d8h, 0edh, 010h, 0d8h, 0d8h, 013h, 0d8h, 0d8h, 0d8h	; 0180
	db	0d8h, 0ech, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d7h, 014h, 0d8h, 0edh, 0d7h, 0d8h, 0d8h, 013h, 0d7h	; 0190
	db	0d7h, 0d7h, 0d7h, 0d7h	; 01a0
_g_01a4	label	byte
	db	0d7h, 0d7h, 0d7h, 0d7h, 0d7h, 0d7h, 0d7h, 0d7h, 0d7h, 0d7h, 0d7h, 0d8h, 0d7h, 0d8h, 0d8h, 0d8h	; 01a4
	db	0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d7h, 0d8h, 0d8h, 0d8h, 0d7h, 0d8h, 0d8h, 0d7h, 0d8h, 0d8h, 0d8h	; 01b4
	db	0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 006h, 0d8h, 0d8h, 0fah, 003h, 0d8h, 0fdh, 0d8h	; 01c4
	db	0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0fah, 0d8h, 010h, 0d8h, 0fah, 0d7h, 010h	; 01d4
	db	0fdh, 0d8h, 013h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0f0h, 0d8h, 0d8h, 0d8h	; 01e4
	db	0edh, 010h, 0d8h, 0d8h, 013h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h	; 01f4
_g_0200	label	byte
	db	0d8h, 0d8h, 0d8h, 0d7h, 0d8h, 0d8h, 0d8h, 0d7h, 0d8h, 0d8h	; 0200
_g_020a	label	byte
	db	0d7h, 0d8h, 0d8h	; 020a
_g_020d	label	byte
	db	0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 003h, 0d8h, 0fdh, 0d8h, 0d8h	; 020d
	db	0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0fdh, 0d8h, 013h, 0fdh	; 021d
	db	0d8h, 013h, 0d8h	; 022d
_g_0230	label	byte
	db	0d8h, 0d8h, 0d8h	; 0230
_g_0233	label	byte
	db	0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0edh, 0d8h, 0d8h, 0d8h, 013h, 0d8h, 0d8h	; 0233
	db	0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h	; 0243
	db	0d8h, 0d8h, 0d8h	; 0253
_g_0256	label	byte
	db	0d8h, 0d8h	; 0256
_g_0258	label	byte
	db	0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h	; 0258
	db	0d8h, 0d8h	; 0268
_g_026a	label	byte
	db	0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h, 0d8h	; 026a
_g_0272	label	byte
	db	0d8h, 0d8h, 0d8h, 0d8h	; 0272
_g_0276	label	byte
	db	0d8h	; 0276
_g_0277	label	byte
	db	016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 0277
	db	016h, 000h, 016h, 000h, 016h, 000h	; 0287
_g_028d	label	byte
	db	016h, 000h, 016h, 000h, 016h, 000h, 016h	; 028d
_g_0294	label	byte
	db	000h, 016h, 000h, 000h, 016h, 016h, 000h, 000h, 016h, 000h, 016h, 000h, 002h, 000h	; 0294
_g_02a2	label	byte
	db	016h, 000h, 016h, 000h, 016h, 000h, 016h, 002h, 016h, 000h, 004h, 000h, 016h, 000h, 016h, 000h	; 02a2
	db	016h, 016h, 000h, 000h, 003h, 000h, 016h, 003h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 002h	; 02b2
	db	016h, 000h, 016h, 000h, 008h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 002h, 016h, 000h, 000h	; 02c2
	db	006h, 000h, 016h, 000h, 016h, 006h, 016h, 000h, 003h, 000h, 016h, 003h, 000h	; 02d2
_g_02df	label	byte
	db	000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h	; 02df
	db	000h, 016h, 000h, 016h, 006h, 016h, 008h, 00eh, 000h, 010h, 000h, 016h, 003h, 016h, 006h, 010h	; 02ef
	db	000h	; 02ff
_g_0300	label	byte
	db	013h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 0300
_g_030a	label	byte
	db	016h, 000h, 016h, 00eh, 016h, 000h, 016h, 000h, 014h, 000h, 016h, 000h, 016h, 000h, 016h, 010h	; 030a
	db	016h, 016h, 000h, 000h, 014h, 000h, 016h, 013h, 016h, 000h, 010h, 000h, 016h, 000h, 016h, 000h	; 031a
	db	013h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 014h, 016h, 000h, 016h, 000h, 016h, 000h	; 032a
	db	016h, 000h, 016h, 000h, 016h, 012h, 016h, 014h, 016h, 000h, 016h, 013h, 016h, 016h, 000h, 000h	; 033a
	db	016h, 000h, 016h, 000h, 013h	; 034a
_g_034f	label	byte
	db	016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 034f
	db	016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 035f
_g_036d	label	byte
	db	016h, 000h, 000h, 016h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 036d
	db	016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 037d
	db	016h, 000h, 016h, 000h, 016h, 000h, 000h	; 038d
_DATA	ends
_DATA	segment
	db	016h, 016h, 000h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 0394
	db	016h, 000h, 016h, 000h, 016h, 000h, 006h, 000h, 016h, 000h, 016h, 006h, 016h, 000h, 003h, 000h	; 03a4
_g_03b4	label	byte
	db	016h, 003h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 03b4
	db	016h, 000h, 016h, 000h	; 03c4
_g_03c8	label	byte
	db	016h	; 03c8
_g_03c9	label	byte
	db	000h, 016h, 006h, 016h, 000h, 016h, 000h, 010h, 000h, 016h, 003h, 016h, 007h, 00fh, 000h, 013h	; 03c9
	db	003h	; 03d9
_g_03da	label	byte
	db	016h, 000h, 016h, 000h, 013h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 03da
	db	016h, 000h, 016h, 000h, 016h, 000h, 016h, 010h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 013h	; 03ea
	db	016h, 000h	; 03fa
_g_03fc	label	byte
	db	010h, 000h, 016h, 000h	; 03fc
_g_0400	label	byte
	db	016h, 000h, 013h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h	; 0400
_g_040c	label	byte
	db	000h, 016h, 000h, 016h, 000h, 016h, 000h	; 040c
_g_0413	label	byte
	db	016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 0413
	db	000h, 016h, 016h, 000h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 0423
_g_0430	label	byte
	db	016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 0430
	db	016h, 000h, 003h, 000h, 016h, 003h, 016h, 000h, 016h	; 0440
_g_0449	label	byte
	db	000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 0449
_g_0458	label	byte
	db	016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 003h, 016h, 000h, 016h, 000h	; 0458
	db	013h, 003h, 016h, 000h, 016h, 000h, 013h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 0468
	db	016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 0478
	db	016h, 013h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 0488
_g_0492	label	byte
	db	013h, 000h	; 0492
_DATA	ends
_DATA	segment
	db	016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 0494
	db	016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 04a4
	db	016h, 000h, 016h, 000h	; 04b4
_g_04b8	label	byte
	db	016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 04b8
_g_04c0	label	byte
	db	016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 04c0
_g_04c8	label	byte
	db	016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 04c8
_g_04d0	label	byte
	db	016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 04d0
_g_04d8	label	byte
	db	016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 04d8
_g_04e0	label	byte
	db	016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 04e0
_g_04e8	label	byte
	db	016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 04e8
_g_04f0	label	byte
	db	016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 04f0
_g_04f8	label	byte
	db	016h, 000h, 016h, 000h, 016h, 000h, 016h, 000h	; 04f8
_g_0500	label	byte
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 0500
_g_0508	label	byte
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h	; 0508
_g_050f	label	byte
	db	001h	; 050f
_g_0510	label	byte
	db	001h, 001h, 000h, 001h, 0ffh, 000h, 0ffh, 000h	; 0510
_g_0518	label	byte
	db	000h, 000h, 001h, 0ffh, 001h, 0ffh, 000h, 0ffh	; 0518
_g_0520	label	byte
	db	0ffh, 000h, 0ffh, 000h, 000h, 000h, 001h, 001h	; 0520
_g_0528	label	byte
	db	001h, 001h, 000h, 001h, 0ffh, 000h, 000h	; 0528
_g_052f	label	byte
	db	008h	; 052f
_g_0530	label	byte
	db	014h, 000h, 004h, 004h, 008h, 014h, 000h, 000h	; 0530
_g_0538	label	byte
	db	004h, 008h, 014h, 014h, 000h, 004h, 008h	; 0538
_g_053f	label	byte
	db	000h	; 053f
_g_0540	label	byte
	db	0feh, 001h, 0ffh, 002h, 000h, 001h, 0ffh	; 0540
_g_0547	label	byte
	db	0ffh	; 0547
_g_0548	label	byte
	db	0ffh, 002h, 001h, 002h, 001h, 002h, 0ffh, 002h	; 0548
_g_0550	label	byte
	db	003h, 002h, 003h, 0ffh, 0ffh, 002h, 001h, 002h	; 0550
_g_0558	label	byte
	db	001h, 002h, 0ffh, 002h, 003h, 002h, 003h, 002h	; 0558
_g_0560	label	byte
	db	001h, 002h, 0ffh, 002h, 003h, 0ffh, 001h, 002h	; 0560
_g_0568	label	byte
	db	0ffh, 0ffh, 003h	; 0568
_g_056b	label	byte
	db	003h, 009h, 003h, 008h, 003h	; 056b
_g_0570	label	byte
	db	007h, 003h, 003h, 003h, 0f9h, 003h, 0f8h, 003h	; 0570
_g_0578	label	byte
	db	0f7h, 002h, 009h, 002h, 006h, 002h, 002h, 002h	; 0578
_g_0580	label	byte
	db	0fah, 002h, 0f7h, 001h, 005h, 001h, 001h, 001h	; 0580
_g_0588	label	byte
	db	0fbh, 000h, 004h, 000h, 000h, 000h, 0fch	; 0588
_g_058f	label	byte
	db	000h	; 058f
_g_0590	label	byte
	db	001h, 001h, 001h, 004h, 005h, 005h, 005h, 005h	; 0590
_g_0598	label	byte
	db	004h	; 0598
_g_0599	label	byte
	db	060h, 000h, 000h, 000h, 060h, 000h, 0ceh	; 0599
_g_05a0	label	byte
	db	000h, 060h, 000h, 055h, 000h, 060h, 000h, 000h	; 05a0
_g_05a8	label	byte
	db	000h, 060h, 000h, 055h, 000h, 060h, 000h, 0ceh, 000h, 060h, 000h, 000h, 000h, 0a0h, 000h, 0aeh	; 05a8
	db	000h, 0a0h, 000h, 0aah, 000h, 0a0h, 000h, 000h, 000h, 0a0h, 000h, 0aah, 000h, 0a0h, 000h, 0aeh	; 05b8
	db	000h, 000h, 001h, 000h, 001h, 000h, 001h, 000h	; 05c8
_g_05d0	label	byte
	db	000h, 000h, 001h, 000h, 001h, 000h, 000h, 000h, 001h, 000h, 001h, 000h, 000h, 000h, 000h, 000h	; 05d0
_g_05e0	label	byte
	db	001h	; 05e0
_g_05e1	label	byte
	db	06ah, 000h, 000h, 000h, 06ah, 000h, 06ah	; 05e1
_g_05e8	label	byte
	db	000h, 06ah, 000h, 06ah, 000h, 06ah, 000h, 000h	; 05e8
_g_05f0	label	byte
	db	000h, 06ah, 000h, 06ah, 000h, 06ah, 000h, 06ah	; 05f0
_g_05f8	label	byte
	db	000h, 06ah, 000h, 000h, 000h, 0aah, 000h, 056h, 000h, 0aah, 000h, 0aah, 000h, 0aah, 000h	; 05f8
_g_0607	label	byte
	db	000h, 000h, 0aah, 000h, 0aah, 000h, 0aah, 000h, 056h	; 0607
_g_0610	label	byte
	db	000h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 000h, 000h, 001h, 000h, 001h, 000h, 000h, 000h	; 0610
	db	001h, 000h, 001h, 000h	; 0620
_g_0624	label	byte
	db	000h, 000h, 000h, 000h	; 0624
_g_0628	label	byte
	db	001h	; 0628
_g_0629	label	byte
	db	0b0h, 0ffh, 0e0h, 0ffh, 0e0h, 0ffh, 010h, 000h, 010h, 000h, 040h, 000h, 040h, 000h, 000h, 000h	; 0629
	db	070h, 000h, 070h, 000h, 0a0h, 000h, 0a0h, 000h, 0d0h, 000h, 0d0h, 000h, 086h	; 0639
_g_0646	label	byte
	db	0ffh, 000h, 000h, 0e0h, 0ffh, 030h, 000h, 030h, 000h, 000h, 000h, 080h, 000h, 080h, 000h, 0d0h	; 0646
	db	000h, 0b0h, 000h, 098h, 0ffh, 018h, 000h, 018h, 000h, 000h, 000h, 098h, 000h, 098h, 000h, 000h	; 0656
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 0b0h, 000h, 0b0h, 000h	; 0666
_g_0671	label	byte
	db	01bh, 01bh, 01bh, 01bh, 01bh, 01bh, 01bh, 01bh, 01bh, 01bh, 01bh, 01bh, 01bh, 01bh, 014h, 01ch	; 0671
	db	014h, 014h, 014h, 014h	; 0681
_g_0685	label	byte
	db	014h, 014h, 014h, 01ch, 008h, 008h, 008h, 008h, 008h, 008h, 000h, 000h, 000h, 000h, 000h, 000h	; 0685
_g_0695	label	byte
	db	000h, 006h, 001h, 005h, 002h, 004h, 003h, 007h, 00bh, 008h, 00ah, 009h, 00ch, 00eh, 00dh, 00fh	; 0695
	db	011h, 010h	; 06a5
_g_06a7	label	byte
	db	000h, 000h, 000h, 003h, 003h, 003h, 003h, 003h, 008h, 008h, 008h, 008h, 008h, 00dh, 00dh, 00dh	; 06a7
	db	00dh, 00dh, 012h, 012h, 012h, 012h, 012h	; 06b7
_g_06be	label	byte
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 001h, 001h, 001h	; 06be
	db	001h, 001h, 001h, 001h, 001h, 001h, 001h	; 06ce
_g_06d5	label	byte
	db	0ffh, 0ffh	; 06d5
_g_06d7	label	byte
	db	000h, 000h	; 06d7
_g_06d9	label	byte
	db	000h, 000h, 000h, 000h	; 06d9
_g_06dd	label	byte
	db	0ffh, 0ffh, 080h, 080h	; 06dd
_g_06e1	label	byte
	db	000h, 0feh, 001h, 0ffh, 002h, 000h, 001h, 0ffh	; 06e1
_g_06e9	label	byte
	db	00dh, 010h, 000h	; 06e9
_g_06ec	label	byte
	db	000h, 000h	; 06ec
_g_06ee	label	byte
	db	000h, 000h	; 06ee
_g_06f0	label	byte
	db	000h, 000h	; 06f0
_g_06f2	label	byte
	db	000h, 000h	; 06f2
_g_06f4	label	byte
	db	000h, 000h	; 06f4
_g_06f6	label	byte
	db	000h, 000h	; 06f6
_g_06f8	label	byte
	db	000h, 000h	; 06f8
_g_06fa	label	byte
	db	000h, 000h	; 06fa
_g_06fc	label	byte
	db	000h, 000h	; 06fc
_g_06fe	label	byte
	db	000h, 000h, 000h, 000h	; 06fe
_g_0702	label	byte
	db	000h, 000h	; 0702
_g_0704	label	byte
	db	000h, 000h	; 0704
_g_0706	label	byte
	db	000h, 000h	; 0706
_g_0708	label	byte
	db	000h, 000h	; 0708
_g_070a	label	byte
	db	000h, 000h, 000h, 000h	; 070a
_g_070e	label	byte
	db	000h, 000h	; 070e
_g_0710	label	byte
	db	000h, 000h, 000h, 000h	; 0710
_g_0714	label	byte
	db	000h, 000h, 000h, 000h	; 0714
_g_0718	label	byte
	db	000h, 000h, 000h, 000h	; 0718
_g_071c	label	byte
	db	000h, 000h, 000h, 000h	; 071c
_g_0720	label	byte
	db	00eh	; 0720
_g_0721	label	byte
	db	000h	; 0721
_g_0722	label	byte
	db	000h	; 0722
_g_0723	label	byte
	db	007h, 042h, 019h, 000h, 000h, 008h, 042h, 01ah, 000h, 000h, 009h, 042h, 00dh, 000h, 000h, 00ah	; 0723
	db	042h, 00ah, 000h, 000h, 00bh, 042h, 00bh, 000h, 000h, 00ch, 042h, 00fh, 000h, 000h, 00dh, 042h	; 0733
	db	016h, 000h, 000h, 00eh, 042h, 017h, 000h, 000h, 00fh, 042h, 011h, 000h, 000h, 010h, 042h, 012h	; 0743
	db	000h, 0fbh, 051h, 042h, 0ffh, 0ffh, 0ffh, 0ffh, 0ffh	; 0753
_g_075c	label	byte
	db	000h	; 075c
_g_075d	label	byte
	db	080h, 081h, 082h, 083h, 084h, 085h, 086h, 087h, 088h, 001h, 001h, 001h, 001h, 001h, 088h, 087h	; 075d
	db	086h, 085h, 084h, 083h, 082h, 081h, 080h	; 076d
_g_0774	label	byte
	db	080h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 0774
_g_077d	label	byte
	db	070h, 061h, 072h	; 077d
_g_0780	label	byte
	db	'ch.cps',0	; 0780
_g_0787	label	byte
	db	070h, 061h, 072h, 063h, 068h, 02eh, 063h, 070h, 073h	; 0787
_g_0790	label	byte
	db	000h	; 0790
_g_0791	label	byte
	db	061h, 075h, 074h	; 0791
_DATA	ends
_DATA	segment
	db	'obut.shp',0	; 0794
_g_079d	label	byte
	db	'font6pn.fnt',0	; 079d
_g_07a9	label	byte
	db	'font9pn.fnt',0	; 07a9
_g_07b5	label	byte
	db	025h, 073h, 00ah, 000h	; 07b5
_g_07b9	label	byte
	db	06ch, 065h, 076h, 065h, 06ch, 025h, 064h, 02eh, 078h, 078h, 078h, 000h, 000h	; 07b9
_g_07c6	label	byte
	db	000h, 000h	; 07c6
_g_07c8	label	byte
	db	050h, 072h, 06fh, 063h, 065h, 073h, 073h, 05fh, 042h, 065h, 07ah, 065h, 06ch, 05fh, 046h, 058h	; 07c8
	db	03ah, 020h, 043h, 061h, 06eh, 027h, 074h, 020h, 06ch, 06fh, 061h, 064h, 020h, 05fh, 042h, 065h	; 07d8
	db	07ah, 065h, 06ch, 020h, 046h, 058h, 000h	; 07e8
_g_07ef	label	byte
	db	'bezel.wsa',0	; 07ef
_g_07f9	label	byte
	db	042h, 065h, 07ah, 065h, 06ch, 03ah, 020h	; 07f9
_g_0800	label	byte
	db	055h, 06eh, 061h, 062h, 06ch, 065h, 020h, 074h, 06fh, 020h, 06ch, 06fh, 061h, 064h, 020h, 062h	; 0800
	db	065h, 07ah, 065h, 06ch, 02eh, 077h, 073h, 061h, 000h, 000h	; 0810
_g_081a	label	byte
	db	'LITEPAL1.COL',0	; 081a
_g_0827	label	byte
	db	'LITEPAL2.COL',0	; 0827
_g_0834	label	byte
	db	04ch, 049h, 054h, 045h, 050h, 041h, 04ch, 033h, 02eh, 043h, 04fh, 04ch	; 0834
_g_0840	label	byte
	db	000h	; 0840
_g_0841	label	byte
	db	'DARKLITE.WSA',0	; 0841
_g_084e	label	byte
	db	0e1h, 000h, 0e3h, 000h, 0e3h, 000h, 0e3h, 000h, 0dfh, 000h, 0e1h, 000h, 0cch, 000h, 0dfh, 000h	; 084e
	db	0dfh, 000h, 0cch, 000h, 0e1h, 000h, 0dfh, 000h, 0e1h, 000h, 0e3h, 000h, 0dfh, 000h, 0e1h, 000h	; 085e
	db	0e1h, 000h, 0dfh, 000h, 0e3h, 000h, 0e1h, 000h, 02ch, 000h, 019h, 000h, 048h, 000h, 02ch, 000h	; 086e
_g_087e	label	byte
	db	000h, 000h	; 087e
_g_0880	label	byte
	db	000h, 000h, 002h, 000h, 004h, 000h, 001h, 000h, 001h, 000h, 002h, 000h, 001h, 000h	; 0880
_g_088e	label	byte
	db	000h, 000h	; 088e
_g_0890	label	byte
	db	000h, 000h, 000h, 000h	; 0890
_DATA	ends
_DATA	segment
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 0894
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 08a4
_g_08ae	label	byte
	db	0ffh, 001h, 002h, 003h, 004h, 0ffh	; 08ae
_g_08b4	label	byte
	db	005h, 006h, 007h, 007h, 006h, 005h	; 08b4
_g_08ba	label	byte
	db	000h, 000h, 000h, 000h	; 08ba
_g_08be	label	byte
	db	062h, 000h, 0a7h, 000h, 0a7h, 000h, 0a8h, 000h	; 08be
_g_08c6	label	byte
	db	014h, 000h, 028h, 000h, 050h, 000h, 064h, 000h	; 08c6
_g_08ce	label	byte
	db	'fireball.shp',0	; 08ce
_g_08db	label	byte
	db	050h, 072h, 06fh, 063h, 065h	; 08db
_g_08e0	label	byte
	db	073h, 073h, 05fh	; 08e0
_g_08e3	label	byte
	db	046h, 069h, 072h, 065h, 062h, 061h, 06ch, 06ch, 05fh, 046h, 058h, 03ah, 020h, 043h, 061h, 06eh	; 08e3
	db	027h, 074h, 020h, 06ch, 06fh, 061h, 064h, 020h, 066h, 069h, 072h, 065h, 062h, 061h, 06ch, 06ch	; 08f3
	db	020h, 046h, 058h, 000h	; 0903
_g_0907	label	byte
	db	050h, 072h, 06fh, 063h, 065h, 073h, 073h, 05fh, 046h, 069h, 072h, 065h, 062h, 061h, 06ch, 06ch	; 0907
	db	03ah, 020h, 055h, 06eh, 061h, 062h, 06ch, 065h, 020h, 074h, 06fh, 020h, 061h, 06ch, 06ch, 06fh	; 0917
	db	063h, 020h, 06dh, 065h, 06dh, 06fh, 072h, 079h, 020h, 066h, 06fh, 072h, 020h, 066h, 069h, 072h	; 0927
	db	065h, 062h, 061h, 06ch, 06ch, 000h, 000h	; 0937
_g_093e	label	byte
	db	'fog.wsa',0	; 093e
_g_0946	label	byte
	db	'Fog: Unable to load fog.wsa',0	; 0946
_g_0962	label	byte
	db	000h, 000h	; 0962
_g_0964	label	byte
	db	062h, 000h, 0a7h, 000h, 0a7h, 000h, 0a8h, 000h	; 0964
_g_096c	label	byte
	db	050h, 072h, 06fh, 063h, 065h, 073h, 073h, 05fh, 047h, 061h, 073h, 05fh, 046h, 058h, 03ah, 020h	; 096c
	db	043h, 061h, 06eh, 027h, 074h, 020h, 06ch, 06fh, 061h, 064h, 020h, 05fh, 047h, 061h, 073h, 020h	; 097c
_g_098c	label	byte
	db	'FX',0	; 098c
_g_098f	label	byte
	db	'gasexp%0d.wsa',0	; 098f
_g_099d	label	byte
	db	'Gas: Unable to load gasexp.wsa',0	; 099d
_g_09bc	label	byte
	db	000h, 000h, 000h, 000h, 000h	; 09bc
_g_09c1	label	byte
	db	028h, 001h, 034h, 001h, 02bh, 001h, 031h, 001h, 02eh, 001h	; 09c1
_g_09cb	label	byte
	db	073h, 000h, 073h, 000h, 074h, 000h, 074h, 000h, 075h, 000h	; 09cb
_g_09d5	label	byte
	db	004h, 004h, 004h, 004h, 002h, 002h, 002h, 003h, 003h, 000h, 001h, 001h	; 09d5
_g_09e1	label	byte
	db	'%d',0	; 09e1
_g_09e4	label	byte
	db	000h, 000h	; 09e4
_g_09e6	label	byte
	db	050h, 072h, 06fh, 063h, 065h, 073h, 073h, 05fh, 047h, 075h, 061h, 072h, 064h, 069h, 061h, 06eh	; 09e6
	db	05fh, 046h, 058h, 03ah, 020h, 043h, 061h, 06eh, 027h, 074h, 020h, 06ch, 06fh, 061h, 064h, 020h	; 09f6
	db	05fh, 047h, 075h, 061h, 072h, 064h, 069h, 061h, 06eh, 020h, 046h, 058h, 000h	; 0a06
_g_0a13	label	byte
	db	067h, 075h, 061h, 072h, 064h	; 0a13
_g_0a18	label	byte
	db	'ian.wsa',0	; 0a18
_g_0a20	label	byte
	db	047h, 075h, 061h, 072h, 064h, 069h, 061h, 06eh, 03ah, 020h, 055h, 06eh, 061h, 062h, 06ch, 065h	; 0a20
	db	020h, 074h, 06fh, 020h, 06ch, 06fh, 061h, 064h	; 0a30
_g_0a38	label	byte
	db	' guardian.wsa',0	; 0a38
_g_0a46	label	byte
	db	067h, 075h, 061h, 072h, 064h, 069h, 061h, 06eh, 02eh, 077h, 073h, 061h, 000h, 000h	; 0a46
_g_0a54	label	byte
	db	011h, 000h	; 0a54
_g_0a56	label	byte
	db	01ah, 000h, 00bh, 000h, 010h, 000h, 01bh, 000h, 023h, 000h, 01bh, 000h	; 0a56
_g_0a62	label	byte
	db	023h, 000h, 000h, 000h, 04bh, 000h	; 0a62
_g_0a68	label	byte
	db	07dh, 000h, 0afh, 000h	; 0a68
_g_0a6c	label	byte
	db	000h, 000h	; 0a6c
_g_0a6e	label	byte
	db	050h, 072h, 06fh, 063h, 065h, 073h, 073h, 05fh, 048h, 061h, 06eh, 064h, 05fh, 046h, 058h, 03ah	; 0a6e
	db	020h, 043h, 061h, 06eh, 027h, 074h, 020h, 06ch, 06fh, 061h, 064h, 020h, 05fh, 048h, 061h, 06eh	; 0a7e
	db	064h, 020h, 046h, 058h, 000h	; 0a8e
_g_0a93	label	byte
	db	'hand.wsa',0	; 0a93
_g_0a9c	label	byte
	db	'Hand: Unable to load HAND.WSA',0	; 0a9c
_g_0aba	label	byte
	db	000h, 000h	; 0aba
_g_0abc	label	byte
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 0abc
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 0acc
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 0adc
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 0aec
_g_0afa	label	byte
	db	000h, 000h	; 0afa
_g_0afc	label	byte
	db	000h, 000h	; 0afc
_g_0afe	label	byte
	db	000h, 000h	; 0afe
_g_0b00	label	byte
	db	000h, 000h	; 0b00
_g_0b02	label	byte
	db	000h, 000h	; 0b02
_g_0b04	label	byte
	db	000h, 000h	; 0b04
_g_0b06	label	byte
	db	000h, 000h	; 0b06
_g_0b08	label	byte
	db	000h, 000h	; 0b08
_g_0b0a	label	byte
	db	000h, 000h	; 0b0a
_g_0b0c	label	byte
	db	'heal.shp',0	; 0b0c
_g_0b15	label	byte
	db	'heali.shp',0	; 0b15
_g_0b1f	label	byte
	db	050h, 072h, 06fh, 063h, 065h, 073h, 073h, 05fh, 048h, 065h, 061h, 06ch, 05fh, 046h, 058h, 03ah	; 0b1f
	db	020h, 043h, 061h, 06eh, 027h, 074h, 020h, 06ch, 06fh, 061h, 064h, 020h, 05fh, 048h, 065h, 061h	; 0b2f
	db	06ch, 020h, 046h, 058h, 000h	; 0b3f
_g_0b44	label	byte
	db	000h, 000h	; 0b44
_g_0b46	label	byte
	db	00ah, 000h, 014h, 000h, 01eh, 000h, 037h, 000h	; 0b46
_g_0b4e	label	byte
	db	014h, 01ch, 028h, 03ch, 050h	; 0b4e
_g_0b53	label	byte
	db	001h, 002h, 00fh, 014h, 023h	; 0b53
_g_0b58	label	byte
	db	00ah, 00ah, 003h, 004h, 004h	; 0b58
_g_0b5d	label	byte
	db	005h, 00ah, 01eh, 00ah, 00ah	; 0b5d
_g_0b62	label	byte
	db	'ice.shp',0	; 0b62
_g_0b6a	label	byte
	db	'SWAMPICE.COL',0	; 0b6a
_g_0b77	label	byte
	db	'swampice.col',0	; 0b77
_g_0b84	label	byte
	db	'snow.wsa',0	; 0b84
_g_0b8d	label	byte
	db	049h, 063h, 065h, 03ah, 020h, 055h, 06eh	; 0b8d
_DATA	ends
_DATA	segment
	db	'able to load snow.wsa',0	; 0b94
_g_0baa	label	byte
	db	'ice.wsa',0	; 0baa
_g_0bb2	label	byte
	db	'Ice: Unable to load snow.wsa',0	; 0bb2
_g_0bcf	label	byte
	db	050h, 072h, 06fh, 063h, 065h, 073h, 073h, 05fh, 049h, 063h, 065h, 05fh, 046h, 058h, 03ah, 020h	; 0bcf
	db	043h, 061h, 06eh, 027h, 074h, 020h, 06ch, 06fh, 061h, 064h, 020h, 05fh, 049h, 063h, 065h, 020h	; 0bdf
	db	046h, 058h, 000h	; 0bef
_g_0bf2	label	byte
	db	'shatter.wsa',0	; 0bf2
_g_0bfe	label	byte
	db	053h, 068h, 061h, 074h, 074h, 065h, 072h, 03ah, 020h, 055h, 06eh, 061h, 062h, 06ch, 065h, 020h	; 0bfe
	db	074h, 06fh, 020h, 06ch, 06fh, 061h, 064h, 020h, 073h, 068h, 061h, 074h, 074h, 065h, 072h, 02eh	; 0c0e
	db	077h, 073h, 061h	; 0c1e
_g_0c21	label	byte
	db	000h, 001h	; 0c21
_g_0c23	label	byte
	db	002h, 006h, 003h, 001h, 001h, 003h, 005h, 004h	; 0c23
_g_0c2b	label	byte
	db	030h, 034h, 030h, 034h, 02eh, 02fh, 032h, 033h, 031h, 035h	; 0c2b
_g_0c35	label	byte
	db	035h	; 0c35
_g_0c36	label	byte
	db	07ah, 041h, 07bh, 041h, 07ah, 041h, 07bh, 041h, 07ch, 041h, 07dh, 041h, 07eh, 041h, 07fh, 041h	; 0c36
	db	080h, 041h, 081h, 041h, 081h, 041h	; 0c46
_g_0c4c	label	byte
	db	000h	; 0c4c
_g_0c4d	label	byte
	db	080h, 000h	; 0c4d
_g_0c4f	label	byte
	db	000h, 000h, 000h, 010h, 002h, 000h, 000h, 001h, 001h, 000h, 000h, 000h, 000h, 000h	; 0c4f
_g_0c5d	label	byte
	db	'%d',0	; 0c5d
_g_0c60	label	byte
	db	069h, 06eh, 076h, 065h, 06eh, 074h, 025h, 064h, 02eh, 063h, 070h, 073h, 000h, 000h	; 0c60
_g_0c6e	label	byte
	db	000h, 000h	; 0c6e
_g_0c70	label	byte
	db	006h	; 0c70
_g_0c71	label	byte
	db	005h	; 0c71
_g_0c72	label	byte
	db	0abh, 000h, 006h, 004h, 0abh, 000h, 008h, 004h, 0aah, 000h, 006h, 003h, 0aah, 000h, 006h, 002h	; 0c72
	db	0a9h, 000h	; 0c82
_g_0c84	label	byte
	db	000h, 000h	; 0c84
_g_0c86	label	byte
	db	0ffh, 0ffh	; 0c86
_g_0c88	label	byte
	db	000h, 000h	; 0c88
_g_0c8a	label	byte
	db	012h, 000h, 023h, 000h, 032h, 000h, 048h, 000h	; 0c8a
_g_0c92	label	byte
	db	000h, 000h	; 0c92
_DATA	ends
_DATA	segment
_g_0c94	label	byte
	db	050h, 072h, 06fh, 063h, 065h	; 0c94
_g_0c99	label	byte
	db	073h, 073h, 05fh, 04ch, 069h, 074h, 06eh, 069h, 06eh, 067h, 05fh, 046h, 058h, 03ah	; 0c99
_g_0ca7	label	byte
	db	020h, 043h, 061h, 06eh, 027h, 074h, 020h, 06ch, 06fh, 061h, 064h, 020h, 05fh, 04ch, 069h, 074h	; 0ca7
	db	06eh, 069h, 06eh, 067h, 020h, 046h, 058h, 000h	; 0cb7
_g_0cbf	label	byte
	db	'litning%00d.wsa',0	; 0cbf
_g_0ccf	label	byte
	db	04ch, 069h, 074h, 06eh, 069h, 06eh, 067h, 03ah, 020h, 055h, 06eh, 061h, 062h, 06ch, 065h, 020h	; 0ccf
	db	074h, 06fh, 020h, 06ch, 06fh, 061h, 064h, 020h, 06ch, 069h, 074h, 06eh, 069h, 06eh, 067h, 02eh	; 0cdf
	db	077h, 073h, 061h, 000h, 000h	; 0cef
_g_0cf4	label	byte
	db	000h, 000h	; 0cf4
_DATA	ends
_DATA	segment
_g_0cf6	label	byte
	dd	DGROUP:_g_0d56	; 0cf6
	dd	DGROUP:_g_0d5f	; 0cfa
	dd	DGROUP:_g_0d6b	; 0cfe
	dd	DGROUP:_g_0d75	; 0d02
	dd	DGROUP:_g_0d7f	; 0d06
	dd	DGROUP:_g_0d89	; 0d0a
	dd	DGROUP:_g_0d94	; 0d0e
	dd	DGROUP:_g_0d9e	; 0d12
	dd	DGROUP:_g_0da9	; 0d16
	dd	DGROUP:_g_0db3	; 0d1a
	dd	DGROUP:_g_0dbf	; 0d1e
	dd	DGROUP:_g_0dc8	; 0d22
_g_0d26	label	byte
	dd	DGROUP:_g_0dd5	; 0d26
	dd	DGROUP:_g_0dde	; 0d2a
	dd	DGROUP:_g_0dea	; 0d2e
	dd	DGROUP:_g_0df4	; 0d32
	dd	DGROUP:_g_0dfe	; 0d36
	dd	DGROUP:_g_0e08	; 0d3a
	dd	DGROUP:_g_0e13	; 0d3e
	dd	DGROUP:_g_0e1d	; 0d42
	dd	DGROUP:_g_0e28	; 0d46
	dd	DGROUP:_g_0e32	; 0d4a
	dd	DGROUP:_g_0e3e	; 0d4e
	dd	DGROUP:_g_0e47	; 0d52
_g_0d56	label	byte
	db	04bh, 045h	; 0d56
_DATA	ends
F179_FAR	segment
_f_2656_0000	label	byte
	db	001h, 000h, 04dh, 069h, 063h, 068h, 061h, 065h, 06ch, 000h, 000h, 000h, 000h, 000h, 0ffh, 0ffh	; 0000
	db	000h, 000h, 011h	; 0010
	dw	001c2h	; 0013
F179_FAR	ends
F179_FAR	segment
	dw	seg F186_FAR	; 0015
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 0017
	db	000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h	; 0027
	db	000h, 000h, 014h, 000h, 014h, 000h, 006h, 000h, 006h, 000h, 000h, 000h, 000h, 000h, 000h, 080h	; 0037
	db	001h, 040h, 001h, 005h, 000h, 002h, 000h, 000h, 000h, 02ch, 000h, 000h, 000h, 000h, 000h, 000h	; 0047
	db	000h, 000h, 000h, 08ah, 000h, 000h, 000h, 000h, 000h, 0a2h, 000h, 000h, 000h, 000h, 000h, 001h	; 0057
	db	001h, 001h, 000h, 000h, 000h, 001h, 000h, 000h, 000h, 001h, 000h, 000h, 000h, 001h, 000h, 000h	; 0067
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 001h, 000h, 054h, 069h, 06dh	; 0077
	db	06fh, 074h, 068h, 079h, 000h, 000h, 000h, 000h, 000h, 002h, 000h, 000h, 000h, 016h	; 0087
	dw	001c2h	; 0095
	dw	seg F186_FAR	; 0097
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 0099
	db	000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h	; 00a9
	db	000h, 000h, 01bh, 000h, 01bh, 000h, 005h, 000h, 005h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 00b9
	db	001h, 000h, 001h, 000h, 000h, 000h, 000h, 000h, 000h, 05dh, 000h, 083h, 000h, 000h, 000h, 000h	; 00c9
	db	000h, 000h, 000h, 099h, 000h, 000h, 000h, 000h, 000h, 0a2h, 000h, 000h, 000h, 000h, 000h, 003h	; 00d9
	db	002h, 001h, 000h, 000h, 000h, 0c4h, 009h, 000h, 000h, 0e8h, 003h, 000h, 000h, 0fah, 000h, 000h	; 00e9
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 001h, 000h, 042h, 061h, 063h	; 00f9
	db	063h, 061h, 074h, 061h, 000h, 000h, 000h, 000h, 003h, 003h, 000h, 000h, 000h, 017h	; 0109
	dw	001c2h	; 0117
	dw	seg F186_FAR	; 0119
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 011b
	db	000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h	; 012b
	db	000h, 000h, 016h, 000h, 016h, 000h, 012h, 000h, 012h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 013b
	db	001h, 000h, 001h, 000h, 000h, 000h, 000h, 000h, 000h, 06ch, 000h, 095h, 000h, 000h, 000h, 000h	; 014b
	db	000h, 091h, 000h, 099h, 000h, 000h, 000h, 000h, 000h, 081h, 000h, 000h, 000h, 000h, 000h, 001h	; 015b
	db	001h, 003h, 000h, 000h, 000h, 001h, 000h, 000h, 000h, 001h, 000h, 000h, 000h, 0a0h, 00fh, 000h	; 016b
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 001h, 000h, 04ch, 06fh, 072h	; 017b
	db	061h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 001h, 004h, 000h, 000h, 000h, 018h	; 018b
	dw	001d4h	; 0199
	dw	seg F186_FAR	; 019b
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 019d
	db	000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h	; 01ad
	db	000h, 000h, 019h, 000h, 030h, 000h, 005h, 000h, 005h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 01bd
	db	001h, 000h, 001h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 01cd
	db	000h, 000h, 000h, 089h, 000h, 000h, 000h, 000h, 000h, 0a2h, 000h, 000h, 000h, 000h, 000h, 001h	; 01dd
	db	004h, 001h, 000h, 000h, 000h, 001h, 000h, 000h, 000h, 099h, 03ah, 000h, 000h, 001h, 000h, 000h	; 01ed
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 001h, 000h, 043h, 06fh, 06eh	; 01fd
	db	072h, 061h, 064h, 000h, 000h, 000h, 000h, 000h, 000h, 0fbh, 0ffh, 000h, 000h, 01ah	; 020d
	dw	001c2h	; 021b
	dw	seg F186_FAR	; 021d
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 021f
	db	000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h	; 022f
	db	000h, 000h, 017h, 000h, 017h, 000h, 00ah, 000h, 00ah, 000h, 000h, 000h, 000h, 000h, 000h, 06eh	; 023f
	db	001h, 066h, 001h, 002h, 000h, 003h, 000h, 000h, 000h, 02ch, 000h, 000h, 000h, 000h, 000h, 000h	; 024f
	db	000h, 000h, 000h, 08ah, 000h, 000h, 000h, 000h, 000h, 0a2h, 000h, 000h, 000h, 000h, 000h, 001h	; 025f
	db	001h, 001h, 000h, 000h, 000h, 001h, 000h, 000h, 000h, 001h, 000h, 000h, 000h, 001h, 000h, 000h	; 026f
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 001h, 000h, 050h, 061h, 075h	; 027f
	db	06ch, 073h, 06fh, 06eh, 000h, 000h, 000h, 000h, 000h, 006h, 000h, 000h, 000h, 019h	; 028f
	dw	001c2h	; 029d
	dw	seg F186_FAR	; 029f
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 02a1
	db	000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h	; 02b1
	db	000h, 000h, 069h, 000h, 069h, 000h, 02dh, 000h, 02dh, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 02c1
	db	001h, 000h, 001h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 02d1
	db	000h, 000h, 000h, 08ah, 000h, 000h, 000h, 000h, 000h, 081h, 000h, 000h, 000h, 000h, 000h, 005h	; 02e1
	db	002h, 003h, 000h, 000h, 000h, 040h, 09ch, 000h, 000h, 0f5h, 001h, 000h, 000h, 0ach, 00dh, 000h	; 02f1
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 001h, 000h, 044h, 061h, 077h	; 0301
	db	06eh, 000h, 000h, 000h	; 0311
F179_FAR	ends
F179_FAR	segment
	db	000h, 000h, 000h, 000h, 001h, 007h, 000h, 000h, 000h, 018h	; 0315
	dw	001d4h	; 031f
	dw	seg F186_FAR	; 0321
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 0323
	db	000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h	; 0333
	db	000h, 000h, 032h, 000h, 032h, 000h, 050h, 000h, 050h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 0343
	db	001h, 000h, 001h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 0353
	db	000h, 000h, 000h, 08ah, 000h, 000h, 000h, 000h, 000h, 081h, 000h, 000h, 000h, 000h, 000h, 001h	; 0363
	db	002h, 00ah, 001h, 0feh, 0b1h, 001h, 000h, 000h, 000h, 0f5h, 001h, 000h, 000h, 001h, 000h, 000h	; 0373
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 001h, 000h, 04bh, 069h, 065h	; 0383
	db	072h, 061h, 06eh, 000h, 000h, 000h, 000h, 000h, 002h, 0f8h, 0ffh, 000h, 000h, 015h	; 0393
	dw	001e6h	; 03a1
	dw	seg F186_FAR	; 03a3
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 03a5
	db	000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h	; 03b5
	db	000h, 000h, 017h, 000h, 017h, 000h, 008h, 000h, 008h, 000h, 000h, 000h, 000h, 000h, 000h, 0a6h	; 03c5
	db	001h, 04ch, 001h, 005h, 000h, 001h, 000h, 000h, 000h, 02ch, 000h, 000h, 000h, 000h, 000h, 000h	; 03d5
	db	000h, 000h, 000h, 08ah, 000h, 000h, 000h, 000h, 000h, 0a2h, 000h, 000h, 000h, 000h, 000h, 001h	; 03e5
	db	001h, 001h, 000h, 000h, 000h, 001h, 000h, 000h, 000h, 001h, 000h	; 03f5
F179_FAR	ends
F179_FAR	segment
	db	000h, 000h, 001h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 0400
	db	001h, 000h, 041h, 06bh, 027h, 073h, 068h, 065h, 06ch, 000h, 000h, 000h, 000h, 004h, 0f7h, 0ffh	; 0410
	db	000h, 000h, 014h	; 0420
	dw	0020ah	; 0423
F179_FAR	ends
F179_FAR	segment
	dw	seg F186_FAR	; 0425
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 0427
	db	000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h, 000h, 001h	; 0437
	db	000h, 000h, 01ch, 000h, 01ch, 000h, 020h, 000h, 020h, 000h, 000h, 000h, 000h, 000h, 000h, 040h	; 0447
	db	001h, 000h, 001h, 001h, 000h, 001h, 000h, 000h, 000h, 02ch, 000h, 000h, 000h, 000h, 000h, 000h	; 0457
	db	000h, 000h, 000h, 08ah, 000h, 000h, 000h, 000h, 000h, 0a2h, 000h, 000h, 000h, 000h, 000h, 001h	; 0467
	db	001h, 001h, 000h, 000h, 000h, 001h, 000h, 000h, 000h, 001h, 000h, 000h, 000h, 001h, 000h, 000h	; 0477
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 0487
F179_FAR	ends
_DATA	segment
	db	'EP.SHP',0	; 0d58
_g_0d5f	label	byte
	db	'FOREST1.SHP',0	; 0d5f
_g_0d6b	label	byte
	db	'MANOR.SHP',0	; 0d6b
_g_0d75	label	byte
	db	'CAVE1.SHP',0	; 0d75
_g_0d7f	label	byte
	db	'SWAMP.SHP',0	; 0d7f
_g_0d89	label	byte
	db	'URBISH.SHP',0	; 0d89
_g_0d94	label	byte
	db	'MINE1.SHP',0	; 0d94
_g_0d9e	label	byte
	db	'TOWER1.SHP',0	; 0d9e
_g_0da9	label	byte
	db	'YVEL1.SHP',0	; 0da9
_g_0db3	label	byte
	db	'CATWALK.SHP',0	; 0db3
_g_0dbf	label	byte
	db	'RUIN.SHP',0	; 0dbf
_g_0dc8	label	byte
	db	'CIMMERIA.SHP',0	; 0dc8
_g_0dd5	label	byte
	db	'KEEP.DAT',0	; 0dd5
_g_0dde	label	byte
	db	'FOREST1.DAT',0	; 0dde
_g_0dea	label	byte
	db	'MANOR.DAT',0	; 0dea
_g_0df4	label	byte
	db	'CAVE1.DAT',0	; 0df4
_g_0dfe	label	byte
	db	053h, 057h, 041h, 04dh, 050h, 02eh, 044h, 041h, 054h	; 0dfe
_g_0e07	label	byte
	db	000h	; 0e07
_g_0e08	label	byte
	db	055h	; 0e08
_g_0e09	label	byte
	db	'RBISH.DAT',0	; 0e09
_g_0e13	label	byte
	db	'MINE1.DAT',0	; 0e13
_g_0e1d	label	byte
	db	054h, 04fh, 057h, 045h, 052h, 031h, 02eh, 044h, 041h, 054h	; 0e1d
_g_0e27	label	byte
	db	000h	; 0e27
_g_0e28	label	byte
	db	'YVEL1.DAT',0	; 0e28
_g_0e32	label	byte
	db	043h, 041h, 054h, 057h, 041h, 04ch, 04bh	; 0e32
_g_0e39	label	byte
	db	'.DAT',0	; 0e39
_g_0e3e	label	byte
	db	'RUIN.DAT',0	; 0e3e
_g_0e47	label	byte
	db	'CIMMERIA.DAT',0	; 0e47
_g_0e54	label	byte
	db	'PLAYFLD.CPS',0	; 0e54
_g_0e60	label	byte
	db	'%s.%s',0	; 0e60
_g_0e66	label	byte
	db	'VCN',0	; 0e66
_g_0e6a	label	byte
	db	'%s.%s',0	; 0e6a
_g_0e70	label	byte
	db	'VMP',0	; 0e70
_g_0e74	label	byte
	db	04ch, 045h, 056h	; 0e74
_g_0e77	label	byte
	db	'EL%02d.TLC',0	; 0e77
_g_0e82	label	byte
	db	'Load_Monster_Shapes: Unable to alloc monster pal',0	; 0e82
_g_0eb3	label	byte
	db	'level%d.ini',0	; 0eb3
_g_0ebf	label	byte
	db	'level%d.inf',0	; 0ebf
_g_0ecb	label	byte
	db	'level%00d.wll',0	; 0ecb
_g_0ed9	label	byte
	db	058h, 04dh, 053h, 020h, 073h, 068h, 061h, 070h, 065h, 020h, 073h, 069h, 07ah, 065h, 020h, 025h	; 0ed9
	db	064h, 020h, 069h, 073h, 020h, 074h, 06fh, 06fh, 020h, 062h, 069h, 067h, 020h, 066h, 06fh, 072h	; 0ee9
	db	020h, 074h	; 0ef9
_g_0efb	label	byte
	db	'rans buf',0	; 0efb
_g_0f04	label	byte
	db	058h, 04dh, 053h, 020h, 073h, 068h, 061h, 070h, 065h, 020h, 023h, 025h, 064h, 020h, 073h, 069h	; 0f04
	db	07ah, 065h, 020h, 025h, 064h, 020h, 069h, 073h, 020h, 074h, 06fh, 06fh, 020h, 062h, 069h, 067h	; 0f14
	db	000h, 000h	; 0f24
_g_0f26	label	byte
	db	'level%d.cmz',0	; 0f26
_g_0f32	label	byte
	db	'_LEVEL%d.TMP',0	; 0f32
_g_0f3f	label	byte
	db	'_LEVEL%d.TMP',0	; 0f3f
_g_0f4c	label	byte
	db	'level%d.cmz',0	; 0f4c
_g_0f58	label	byte
	db	'CD04',0	; 0f58
_g_0f5d	label	byte
	db	'_LEVEL%d.TMP',0	; 0f5d
_g_0f6a	label	byte
	db	'CD04',0	; 0f6a
_g_0f6f	label	byte
	db	'V CD1.02 D',0	; 0f6f
_g_0f7a	label	byte
	db	05fh, 04ch, 045h, 056h, 045h, 04ch, 025h, 064h, 02eh, 054h, 04dh, 050h, 000h, 000h	; 0f7a
_g_0f88	label	byte
	db	001h, 000h	; 0f88
_g_0f8a	label	byte
	db	045h, 04eh, 047h, 000h, 046h, 052h, 045h, 000h, 047h, 045h, 052h, 000h	; 0f8a
_g_0f96	label	byte
	db	'Unable to allocate shape #%d.',0	; 0f96
_g_0fb4	label	byte
	db	'.',0	; 0fb4
_g_0fb6	label	byte
	db	046h, 041h, 043h, 045h, 025h, 030h, 032h, 064h, 02eh, 053h, 048h, 050h, 000h, 000h	; 0fb6
_g_0fc4	label	byte
	db	000h, 000h	; 0fc4
_g_0fc6	label	byte
	db	007h, 000h	; 0fc6
_g_0fc8	label	byte
	db	007h, 000h	; 0fc8
_g_0fca	label	byte
	db	00dh, 000h	; 0fca
_g_0fcc	label	byte
	db	09bh, 000h, 000h, 000h, 010h, 000h, 010h, 000h, 011h, 000h, 09bh, 000h, 000h, 000h, 018h, 000h	; 0fcc
	db	018h, 000h, 018h, 000h, 0aeh, 000h, 000h, 000h, 013h, 000h, 013h, 000h, 013h, 000h, 0aeh, 000h	; 0fdc
	db	000h, 000h, 010h, 000h, 010h, 000h, 011h, 000h, 0afh, 000h	; 0fec
_g_0ff6	label	byte
	db	000h, 000h	; 0ff6
_g_0ff8	label	byte
	db	01eh, 000h, 046h, 000h, 06eh, 000h, 0c8h	; 0ff8
_g_0fff	label	byte
	db	000h	; 0fff
_g_1000	label	byte
	db	050h, 072h, 06fh, 063h, 065h, 073h, 073h, 05fh, 04dh, 069h, 073h, 074h, 05fh, 046h, 058h, 03ah	; 1000
	db	020h, 043h, 061h, 06eh, 027h, 074h, 020h, 06ch, 06fh, 061h, 064h, 020h, 05fh, 04dh, 069h, 073h	; 1010
	db	074h, 020h, 046h, 058h, 000h	; 1020
_g_1025	label	byte
	db	'mists%0d.wsa',0	; 1025
_g_1032	label	byte
	db	04dh, 069h, 073h, 074h, 03ah, 020h, 055h, 06eh, 061h, 062h, 06ch, 065h, 020h, 074h, 06fh, 020h	; 1032
	db	06ch, 06fh, 061h, 064h, 020h, 06dh, 069h, 073h, 074h, 073h, 02eh, 077h, 073h, 061h, 000h, 000h	; 1042
_g_1052	label	byte
	db	048h, 042h, 049h, 042h, 0ddh, 042h	; 1052
_DATA	ends
_DATA	segment
	db	04ah, 042h, 000h, 000h, 048h, 042h, 049h, 042h, 0ddh, 042h, 001h, 040h, 04ah, 042h	; 1058
_g_1066	label	byte
	db	'ITEMICN.SHP',0	; 1066
_g_1072	label	byte
	db	'ITEMICN.SHP',0	; 1072
_g_107e	label	byte
	db	'ITEMSHP.SHP',0	; 107e
_g_108a	label	byte
	db	'GAMESHP.SHP',0	; 108a
_g_1096	label	byte
	db	'THROWN.SHP',0	; 1096
_g_10a1	label	byte
	db	'title.cps',0	; 10a1
_g_10ab	label	byte
	db	'FONT6P.FNT',0	; 10ab
_g_10b6	label	byte
	db	'LANDS',0	; 10b6
_g_10bc	label	byte
	db	'LOLSYSEX',0	; 10bc
_g_10c5	label	byte
	db	'V CD1.02 D',0	; 10c5
_g_10d0	label	byte
	db	'PLAIN',0	; 10d0
_g_10d6	label	byte
	db	'_save000.dat',0	; 10d6
_g_10e3	label	byte
	db	'CHARGEN',0	; 10e3
_g_10eb	label	byte
	db	'INTRO',0	; 10eb
_g_10f1	label	byte
	db	'LOLCD.EXE',0	; 10f1
_g_10fb	label	byte
	db	'LOLCD.EXE',0	; 10fb
_g_1105	label	byte
	db	'HISTORY',0	; 1105
_g_110d	label	byte
	db	'PLAYFLD.CPS',0	; 110d
_g_1119	label	byte
	db	'ONETIME.INF',0	; 1119
_g_1125	label	byte
	db	'ITEM.INF',0	; 1125
_g_112e	label	byte
	db	'STARTUP.PAK',0	; 112e
_g_113a	label	byte
	db	03ch, 04dh, 04fh, 052h, 045h, 03eh, 000h, 000h	; 113a
_g_1142	label	byte
	db	000h, 000h, 000h, 000h, 014h, 000h, 060h, 000h, 000h, 000h, 001h, 001h, 001h, 000h, 087h, 044h	; 1142
_g_1152	label	byte
	db	000h, 000h, 000h, 000h	; 1152
_g_1156	label	byte
	db	000h, 000h, 000h, 000h	; 1156
_g_115a	label	byte
	db	000h, 000h, 000h, 000h	; 115a
_g_115e	label	byte
	db	00ah, 000h, 080h, 000h, 014h, 000h, 019h, 000h, 010h, 000h, 0feh, 001h, 0feh, 001h, 0feh, 001h	; 115e
	db	0feh, 001h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 116e
_g_117e	label	byte
	db	000h, 000h, 000h, 000h, 015h, 000h, 062h, 000h, 000h, 000h, 001h, 001h, 001h, 000h, 087h, 044h	; 117e
_g_118e	label	byte
	db	000h, 000h, 000h, 000h	; 118e
_g_1192	label	byte
	db	000h, 000h, 000h, 000h	; 1192
_g_1196	label	byte
	db	000h, 000h, 000h, 000h	; 1196
_g_119a	label	byte
	db	00ah, 000h, 080h, 000h, 076h, 000h, 019h, 000h, 010h, 000h, 0feh, 001h, 0feh, 001h, 0feh, 001h	; 119a
	db	0feh, 001h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 11aa
_g_11ba	label	byte
	db	001h, 000h	; 11ba
_g_11bc	label	byte
	db	000h, 000h	; 11bc
_g_11be	label	byte
	db	000h, 000h, 00ah, 000h, 07ch, 000h	; 11be
_g_11c4	label	byte
	db	00ah, 000h, 072h, 000h, 00ah, 000h	; 11c4
_g_11ca	label	byte
	db	00bh, 000h	; 11ca
_g_11cc	label	byte
	db	0ffh, 0ffh	; 11cc
_g_11ce	label	byte
	db	'V CD1.02 D',0	; 11ce
_g_11d9	label	byte
	db	'V CD1.02 D',0	; 11d9
_g_11e4	label	byte
	db	'_SAVE%03d.DAT',0	; 11e4
_g_11f2	label	byte
	db	'LEVEL%02d',0	; 11f2
_g_11fc	label	byte
	db	'LANDS',0	; 11fc
_g_1202	label	byte
	db	'LANDS.CFG',0	; 1202
_g_120c	label	byte
	db	'LANDS.CFG',0	; 120c
_g_1216	label	byte
	db	000h, 000h	; 1216
_g_1218	label	byte
	db	090h, 078h, 00ch, 09fh, 080h, 01eh	; 1218
_g_121e	label	byte
	db	'%s.%s',0	; 121e
_g_1224	label	byte
	db	'WSA',0	; 1224
_g_1228	label	byte
	db	0b0h, 000h, 078h, 000h	; 1228
_g_122c	label	byte
	db	000h, 000h	; 122c
_g_122e	label	byte
	db	000h, 000h	; 122e
_g_1230	label	byte
	db	040h, 001h, 0c8h, 000h	; 1230
_g_1234	label	byte
	db	000h, 000h	; 1234
_g_1236	label	byte
	db	000h, 000h	; 1236
_g_1238	label	byte
	db	040h, 001h, 0c8h, 000h	; 1238
_g_123c	label	byte
	db	000h, 000h	; 123c
_g_123e	label	byte
	db	000h, 000h	; 123e
_g_1240	label	byte
	db	'sap.wsa',0	; 1240
_g_1248	label	byte
	db	'SAP: Unable to load sap.wsa',0	; 1248
_g_1264	label	byte
	db	007h, 000h, 00fh, 000h, 019h, 000h, 03ch, 000h	; 1264
_g_126c	label	byte
	db	'spark1.wsa',0	; 126c
_g_1277	label	byte
	db	'SPARK: Unable to load SPARK1.WSA',0	; 1277
_g_1298	label	byte
	db	'spark2.wsa',0	; 1298
_g_12a3	label	byte
	db	'SPARK: Unable to load SPARK2.WSA',0	; 12a3
_g_12c4	label	byte
	db	000h, 000h	; 12c4
_g_12c6	label	byte
	db	000h, 000h	; 12c6
_g_12c8	label	byte
	db	000h, 000h	; 12c8
_g_12ca	label	byte
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 004h, 000h, 000h, 000h, 013h, 000h	; 12ca
	db	0b6h, 000h, 004h, 000h, 000h, 000h, 013h, 000h, 04dh, 000h, 004h, 000h, 000h, 000h, 013h, 000h	; 12da
	db	0b9h, 000h, 004h, 000h, 000h, 000h, 013h, 000h, 0b8h, 000h, 004h, 000h, 000h, 000h, 013h, 000h	; 12ea
	db	0bah, 000h	; 12fa
_g_12fc	label	byte
	db	016h, 000h	; 12fc
_g_12fe	label	byte
	db	016h, 000h, 016h, 000h, 01fh, 000h, 016h, 000h, 028h, 000h, 016h, 000h, 031h, 000h, 016h, 000h	; 12fe
	db	03ah, 000h, 016h, 000h, 043h, 000h	; 130e
_g_1314	label	byte
	db	'PLAYFLD.CPS',0	; 1314
_g_1320	label	byte
	db	'write%0d%c.wsa',0	; 1320
_g_132f	label	byte
	db	'writing.wsa',0	; 132f
_g_133b	label	byte
	db	'spellexp.wsa',0	; 133b
_g_1348	label	byte
	db	'getspell.wsa',0	; 1348
_g_1355	label	byte
	db	053h, 070h, 065h	; 1355
_DATA	ends
_DATA	segment
	db	'llBook: Unable to load getspell anim',0	; 1358
_g_137d	label	byte
	db	073h, 070h, 065h, 06ch, 06ch, 065h, 078h, 070h, 02eh, 077h, 073h	; 137d
_g_1388	label	byte
	db	'a',0	; 1388
_g_138a	label	byte
	db	'SpellBook: Unable to load spellexp anim',0	; 138a
_g_13b2	label	byte
	db	'writing.wsa',0	; 13b2
_g_13be	label	byte
	db	'SpellBook: Unable to load writing anim',0	; 13be
_g_13e5	label	byte
	db	'Loading Spellbook: %s',0	; 13e5
_g_13fb	label	byte
	db	053h, 070h, 065h, 06ch, 06ch	; 13fb
_g_1400	label	byte
	db	042h, 06fh, 06fh, 06bh, 03ah, 020h, 055h, 06eh	; 1400
_g_1408	label	byte
	db	'able to load spellbook anim',0	; 1408
_DATA	ends
_DATA	segment
_g_1424	label	byte
	dd	_ovr_2d8a_0043	; 1424
	dd	_ovr_2d8a_003e	; 1428
	dd	_ovr_2d8a_004d	; 142c
	dd	_ovr_2d8a_0048	; 1430
	dd	_ovr_2d8a_0052	; 1434
	dd	_ovr_2d8a_0057	; 1438
	dd	_ovr_2d8a_0061	; 143c
	db	000h, 000h, 000h, 000h	; 1440
	dd	_ovr_2d8a_005c	; 1444
	dd	_ovr_2d8a_0066	; 1448
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 144c
	dd	_ovr_2d8a_006b	; 1454
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 1458
	dd	_ovr_2d8a_0075	; 1464
_g_1468	label	byte
	db	000h, 000h	; 1468
_g_146a	label	byte
	db	000h, 000h	; 146a
	dd	_ovr_2d8a_0070	; 146c
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 1470
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 1480
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 1490
_g_14a0	label	byte
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 14a0
_g_14ac	label	byte
	db	025h, 073h, 02eh, 00dh, 000h, 000h	; 14ac
_DATA	ends
_DATA	segment
	dd	DGROUP:_g_14be	; 14b2
	dd	DGROUP:_g_14c1	; 14b6
_g_14ba	label	byte
	db	000h, 000h	; 14ba
_g_14bc	label	byte
	db	000h, 000h	; 14bc
_g_14be	label	byte
	db	00dh, 020h, 000h	; 14be
_g_14c1	label	byte
	db	00dh, 00ah, 000h	; 14c1
_g_14c4	label	byte
	db	000h, 000h, 000h, 000h	; 14c4
_g_14c8	label	byte
	db	001h, 000h	; 14c8
_g_14ca	label	byte
	db	000h, 000h	; 14ca
_g_14cc	label	byte
	db	050h, 072h, 06fh, 063h, 065h, 073h, 073h, 05fh, 053h, 077h, 061h, 072h, 06dh, 05fh, 046h, 058h	; 14cc
	db	03ah, 020h, 043h, 061h, 06eh, 027h, 074h, 020h, 06ch, 06fh, 061h, 064h, 020h, 05fh, 053h, 077h	; 14dc
	db	061h, 072h, 06dh, 020h, 046h, 058h, 000h	; 14ec
_g_14f3	label	byte
	db	'swarm.wsa',0	; 14f3
_g_14fd	label	byte
	db	053h, 077h, 061h, 072h, 06dh, 03ah, 020h, 055h, 06eh, 061h, 062h, 06ch, 065h, 020h, 074h, 06fh	; 14fd
_g_150d	label	byte
	db	020h, 06ch, 06fh	; 150d
_g_1510	label	byte
	db	061h, 064h, 020h, 053h, 057h, 041h, 052h, 04dh, 02eh, 057h, 053h, 041h, 000h, 000h	; 1510
_g_151e	label	byte
	db	000h, 000h	; 151e
_g_1520	label	byte
	db	050h, 072h, 06fh, 063h, 065h, 073h, 073h, 05fh, 056h, 069h, 070h, 065h, 072h, 05fh, 046h, 058h	; 1520
	db	03ah, 020h, 043h, 061h, 06eh, 027h, 074h, 020h, 06ch, 06fh, 061h, 064h, 020h, 05fh, 056h, 069h	; 1530
	db	070h, 065h, 072h, 020h, 046h, 058h, 000h	; 1540
_g_1547	label	byte
	db	076h, 069h, 070h, 065h, 072h	; 1547
_g_154c	label	byte
	db	'.wsa',0	; 154c
_g_1551	label	byte
	db	056h, 069h, 070h, 065h, 072h, 03ah, 020h, 055h, 06eh, 061h, 062h, 06ch, 065h, 020h, 074h, 06fh	; 1551
	db	020h, 06ch, 06fh, 061h, 064h, 020h, 076h, 069h, 070h, 065h, 072h, 02eh, 077h, 073h, 061h, 000h	; 1561
	db	000h	; 1571
_g_1572	label	byte
	db	'%02d.TLK',0	; 1572
_g_157b	label	byte
	db	'%3X%c%c',0	; 157b
_g_1583	label	byte
	db	'@%4d%c',0	; 1583
_g_158a	label	byte
	db	'%3d%c%c',0	; 158a
_g_1592	label	byte
	db	000h, 000h	; 1592
_DATA	ends
_DATA	segment
_g_1594	label	byte
	dd	DGROUP:_g_162c	; 1594
_g_1598	label	byte
	dd	DGROUP:_g_163a	; 1598
_g_159c	label	byte
	dd	DGROUP:_g_164a	; 159c
_g_15a0	label	byte
	dd	DGROUP:_g_1658	; 15a0
_g_15a4	label	byte
	dd	DGROUP:_g_1666	; 15a4
_g_15a8	label	byte
	dd	DGROUP:_g_1676	; 15a8
_g_15ac	label	byte
	dd	DGROUP:_g_168b	; 15ac
_g_15b0	label	byte
	dd	DGROUP:_g_169e	; 15b0
	dd	DGROUP:_g_16ae	; 15b4
	dd	DGROUP:_g_16be	; 15b8
	dd	DGROUP:_g_16cf	; 15bc
	dd	DGROUP:_g_16e0	; 15c0
	dd	DGROUP:_g_16f1	; 15c4
	dd	DGROUP:_g_1702	; 15c8
	dd	DGROUP:_g_1713	; 15cc
	dd	DGROUP:_g_1724	; 15d0
	dd	DGROUP:_g_1735	; 15d4
	dd	DGROUP:_g_1746	; 15d8
	dd	DGROUP:_g_1758	; 15dc
_g_15e0	label	byte
	dd	DGROUP:_g_176a	; 15e0
	dd	DGROUP:_g_177c	; 15e4
	dd	DGROUP:_g_178e	; 15e8
	dd	DGROUP:_g_17a0	; 15ec
	dd	DGROUP:_g_17b2	; 15f0
	dd	DGROUP:_g_17c4	; 15f4
_g_15f8	label	byte
	dd	DGROUP:_g_17d6	; 15f8
_g_15fc	label	byte
	dd	DGROUP:_g_1807	; 15fc
_g_1600	label	byte
	dd	DGROUP:_g_1819	; 1600
_g_1604	label	byte
	dd	DGROUP:_g_182b	; 1604
_g_1608	label	byte
	dd	DGROUP:_g_1842	; 1608
_g_160c	label	byte
	dd	DGROUP:_g_1853	; 160c
_g_1610	label	byte
	dd	DGROUP:_g_1864	; 1610
_g_1614	label	byte
	dd	DGROUP:_g_188a	; 1614
_g_1618	label	byte
	dd	DGROUP:_g_1891	; 1618
	dd	DGROUP:_g_1895	; 161c
	dd	DGROUP:_g_1899	; 1620
	dd	DGROUP:_g_189d	; 1624
	dd	DGROUP:_g_18a1	; 1628
_g_162c	label	byte
	db	04ch, 069h, 062h, 020h, 065h, 072h, 072h, 06fh, 072h, 020h, 031h, 00dh, 00ah, 000h	; 162c
_g_163a	label	byte
	db	04ch, 069h, 062h, 020h, 06dh, 065h, 073h, 073h, 061h, 067h, 065h, 020h, 032h, 00dh, 00ah, 000h	; 163a
_g_164a	label	byte
	db	04ch, 069h, 062h, 020h, 065h, 072h, 072h, 06fh, 072h, 020h, 033h, 00dh, 00ah, 000h	; 164a
_g_1658	label	byte
	db	04ch, 069h, 062h, 020h, 065h, 072h, 072h, 06fh, 072h, 020h, 034h, 00dh, 00ah, 000h	; 1658
_g_1666	label	byte
	db	00dh, 00ah, 04ch, 069h, 062h, 020h, 065h, 072h, 072h, 06fh, 072h, 020h, 035h, 00dh, 00ah, 000h	; 1666
_g_1676	label	byte
	db	00dh, 00ah, 04ch, 069h, 062h, 020h, 065h, 072h, 072h, 06fh, 072h, 020h, 036h, 020h	; 1676
_g_1684	label	byte
	db	022h, 025h, 073h, 022h, 00dh, 00ah, 000h	; 1684
_g_168b	label	byte
	db	00dh, 00ah, 04ch, 069h, 062h, 020h, 065h, 072h, 072h, 06fh, 072h, 020h, 037h, 020h, 025h, 073h	; 168b
	db	00dh, 00ah, 000h	; 169b
_g_169e	label	byte
	db	'File error 0(8)',0	; 169e
_g_16ae	label	byte
	db	'File error 1(9)',0	; 16ae
_g_16be	label	byte
	db	'File error 2(10)',0	; 16be
_g_16cf	label	byte
	db	'File error 3(11)',0	; 16cf
_g_16e0	label	byte
	db	046h, 069h, 06ch, 065h, 020h, 065h, 072h, 072h, 06fh, 072h, 020h	; 16e0
_g_16eb	label	byte
	db	'4(12)',0	; 16eb
_g_16f1	label	byte
	db	'File error 5(13)',0	; 16f1
_g_1702	label	byte
	db	'File error 6(14)',0	; 1702
_g_1713	label	byte
	db	'File error 7(15)',0	; 1713
_g_1724	label	byte
	db	046h, 069h, 06ch, 065h, 020h, 065h, 072h, 072h, 06fh	; 1724
_g_172d	label	byte
	db	'r 8(16)',0	; 172d
_g_1735	label	byte
	db	'File error 9(17)',0	; 1735
_g_1746	label	byte
	db	'File error 10(18)',0	; 1746
_g_1758	label	byte
	db	'File error 11(19)',0	; 1758
_g_176a	label	byte
	db	'File error 12(20)',0	; 176a
_g_177c	label	byte
	db	'File error 13(21)',0	; 177c
_g_178e	label	byte
	db	'File error 14(22)',0	; 178e
_g_17a0	label	byte
	db	'File error 15(23)',0	; 17a0
_g_17b2	label	byte
	db	'File error 16(24)',0	; 17b2
_g_17c4	label	byte
	db	'File error 17(25)',0	; 17c4
_g_17d6	label	byte
	db	00dh, 049h, 06eh, 073h, 065h, 072h, 074h, 020h, 043h, 044h, 020h, 063h, 06fh, 06eh, 074h, 061h	; 17d6
	db	069h, 06eh, 069h, 06eh, 067h, 020h, 025h, 073h, 020h, 069h, 06eh, 074h, 06fh, 020h, 066h, 069h	; 17e6
	db	072h, 073h, 074h, 020h, 043h, 044h, 02dh, 052h, 04fh, 04dh, 020h, 064h, 072h, 069h, 076h, 065h	; 17f6
	db	000h	; 1806
_g_1807	label	byte
	db	04ch	; 1807
_g_1808	label	byte
	db	069h, 062h, 020h, 065h, 072h, 072h, 06fh, 072h, 020h, 032h, 036h, 020h, 025h, 073h, 00dh, 00ah	; 1808
	db	000h	; 1818
_g_1819	label	byte
	db	04ch, 069h, 062h, 020h, 065h, 072h, 072h, 06fh, 072h, 020h, 032h, 037h, 020h, 025h, 073h, 00dh	; 1819
	db	00ah, 000h	; 1829
_g_182b	label	byte
	db	04ch, 069h, 062h, 020h, 065h, 072h, 072h, 06fh, 072h, 020h, 032h, 038h, 020h, 025h, 073h, 020h	; 182b
	db	028h, 025h, 064h, 029h, 00dh, 00ah, 000h	; 183b
_g_1842	label	byte
	db	00dh, 00ah, 04ch, 069h, 062h, 020h, 065h, 072h, 072h, 06fh, 072h, 020h, 032h, 039h, 00dh, 00ah	; 1842
	db	000h	; 1852
_g_1853	label	byte
	db	00dh, 00ah, 04ch, 069h, 062h, 020h, 065h, 072h, 072h, 06fh, 072h, 020h, 033h, 030h, 00dh, 00ah	; 1853
	db	000h	; 1863
_g_1864	label	byte
	db	00dh, 00ah, 04eh, 06fh, 074h, 020h, 065h, 06eh, 06fh, 075h, 067h, 068h, 020h, 06dh, 065h, 06dh	; 1864
	db	06fh, 072h, 079h, 020h, 074h, 06fh, 020h, 072h, 075h, 06eh, 020h, 070h, 072h, 06fh, 067h, 072h	; 1874
	db	061h, 06dh, 02eh, 00dh, 00ah, 000h	; 1884
_g_188a	label	byte
	db	'<MORE>',0	; 188a
_g_1891	label	byte
	db	'ENG',0	; 1891
_g_1895	label	byte
	db	'FRE',0	; 1895
_g_1899	label	byte
	db	'GER',0	; 1899
_g_189d	label	byte
	db	'ITA',0	; 189d
_g_18a1	label	byte
	db	'SPA',0	; 18a1
_g_18a5	label	byte
	db	'.LM',0	; 18a5
_g_18a9	label	byte
	db	02eh, 04ch, 04dh, 000h, 000h	; 18a9
_DATA	ends
_DATA	segment
_g_18ae	label	byte
	dd	DGROUP:_g_18de	; 18ae
	dd	DGROUP:_g_18e9	; 18b2
_g_18b6	label	byte
	db	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h	; 18b6
_g_18c2	label	byte
	db	000h, 000h, 000h, 000h	; 18c2
_g_18c6	label	byte
	db	000h, 000h, 000h, 000h	; 18c6
_g_18ca	label	byte
	db	000h, 000h, 000h, 000h	; 18ca
_g_18ce	label	byte
	db	000h, 000h, 000h, 000h	; 18ce
_g_18d2	label	byte
	db	000h, 000h, 000h, 000h	; 18d2
_g_18d6	label	byte
	db	000h, 000h, 000h, 000h	; 18d6
_g_18da	label	byte
	db	000h, 000h, 000h, 000h	; 18da
_g_18de	label	byte
	db	'FONT9P.FNT',0	; 18de
_g_18e9	label	byte
	db	'MAIN.EXE',0	; 18e9
_g_18f2	label	byte
	db	'LANDS.CFG',0	; 18f2
_g_18fc	label	byte
	db	054h, 068h, 065h, 020h, 073h, 065h, 074h, 075h, 070h, 020h, 070h, 072h, 06fh, 067h, 072h, 061h	; 18fc
	db	06dh, 020h, 06dh, 075h, 073h, 074h, 020h, 062h, 065h, 020h, 072h, 075h, 06eh, 020h, 066h, 069h	; 190c
	db	072h, 073h, 074h, 02eh, 00ah, 04ch, 065h, 020h, 070h, 072h, 06fh, 067h, 072h, 061h, 06dh, 06dh	; 191c
	db	065h, 020h, 064h, 065h, 020h, 063h, 06fh, 06eh, 066h, 069h, 067h, 075h, 072h, 061h, 074h, 069h	; 192c
	db	06fh, 06eh, 020h, 064h, 06fh, 069h, 074h, 020h, 064h, 027h, 061h, 062h, 06fh, 072h, 064h, 020h	; 193c
	db	088h, 074h, 072h, 065h, 020h, 06ch, 061h, 06eh, 063h, 082h, 02eh, 00ah, 05ah, 075h, 065h, 072h	; 194c
	db	073h, 074h, 020h, 06dh, 075h, 0e1h, 020h, 064h, 061h, 073h, 020h, 053h, 065h, 074h, 075h, 070h	; 195c
	db	02dh, 050h, 072h, 06fh, 067h, 072h, 061h, 06dh, 06dh, 020h, 062h, 065h, 074h, 072h, 069h, 065h	; 196c
	db	062h, 065h, 06eh, 020h, 077h	; 197c
_g_1981	label	byte
	db	065h, 072h, 064h, 065h, 06eh, 02eh, 00ah, 00dh, 00ah, 000h	; 1981
_g_198b	label	byte
	db	054h, 068h, 069h, 073h, 020h, 063h, 061h, 06eh, 06eh, 06fh, 074h, 020h, 062h, 065h, 020h, 072h	; 198b
	db	075h, 06eh, 020h, 075h, 06eh, 064h, 065h, 072h, 020h, 057h, 069h, 06eh, 064h, 06fh, 077h, 073h	; 199b
	db	02eh, 00ah, 000h	; 19ab
_g_19ae	label	byte
	db	020h, 052h, 041h, 04dh, 020h, 041h, 076h, 061h, 069h, 06ch, 061h, 062h, 06ch, 065h, 03ah, 020h	; 19ae
	db	025h, 038h, 06ch, 064h, 00ah, 020h, 052h, 041h, 04dh, 020h, 052h, 065h, 071h, 075h, 069h, 072h	; 19be
	db	065h, 064h, 020h, 03ah, 020h, 025h, 038h, 06ch, 064h, 00ah, 00ah, 000h	; 19ce
_g_19da	label	byte
	db	020h, 058h, 04dh, 053h, 020h, 041h, 076h, 061h, 069h, 06ch, 061h, 062h, 06ch, 065h, 03ah, 020h	; 19da
	db	025h, 038h, 06ch, 064h, 00ah, 020h, 058h, 04dh, 053h, 020h, 052h, 065h, 071h, 075h, 069h, 072h	; 19ea
	db	065h, 064h, 020h, 03ah, 020h, 025h, 038h, 06ch, 064h, 00ah, 00ah, 000h	; 19fa
_g_1a06	label	byte
	db	'\DATA',0	; 1a06
_g_1a0c	label	byte
	db	'FILEDATA.FDT',0	; 1a0c
_g_1a19	label	byte
	db	'PLAYFLD.CPS',0	; 1a19
_g_1a25	label	byte
	db	'STARTUP.PAK',0	; 1a25
_g_1a31	label	byte
	db	'MAIN.EXE',0	; 1a31
_g_1a3a	label	byte
	db	'T3E',0	; 1a3a
_g_1a3e	label	byte
	db	'ALFX.DRV',0	; 1a3e
_g_1a47	label	byte
	db	'ADL',0	; 1a47
_g_1a4b	label	byte
	db	'SND',0	; 1a4b
_g_1a4f	label	byte
	db	'XMI',0	; 1a4f
_g_1a53	label	byte
	db	'SBDIG.ADV',0	; 1a53
_g_1a5d	label	byte
	db	'SBPDIG.ADV',0	; 1a5d
_g_1a68	label	byte
	db	'BLASTER',0	; 1a68
_g_1a70	label	byte
	db	'.',0	; 1a70
_g_1a72	label	byte
	db	02eh, 058h, 04dh, 049h, 000h, 000h	; 1a72
_g_1a78	label	byte
	db	000h, 000h	; 1a78
_g_1a7a	label	byte
	db	000h, 000h	; 1a7a
_g_1a7c	label	byte
	db	000h, 000h, 000h, 000h	; 1a7c
_g_1a80	label	byte
	db	000h, 000h	; 1a80
_g_1a82	label	byte
	db	000h, 000h	; 1a82
_DATA	ends
_DATA	segment
	dd	DGROUP:_g_1b20	; 1a84
	dd	DGROUP:_g_1b29	; 1a88
	db	048h, 000h, 000h, 000h	; 1a8c
	dd	DGROUP:_g_1b2d	; 1a90
	dd	DGROUP:_g_1b39	; 1a94
	db	024h, 001h, 000h, 000h	; 1a98
	dd	DGROUP:_g_1b3d	; 1a9c
	dd	DGROUP:_g_1b49	; 1aa0
	db	024h, 001h, 001h, 000h	; 1aa4
	dd	DGROUP:_g_1b4d	; 1aa8
	dd	DGROUP:_g_1b58	; 1aac
	db	000h, 000h, 000h, 000h	; 1ab0
	dd	DGROUP:_g_1b5c	; 1ab4
	dd	DGROUP:_g_1b66	; 1ab8
	db	000h, 000h, 000h, 000h	; 1abc
	dd	DGROUP:_g_1b6a	; 1ac0
	dd	DGROUP:_g_1b76	; 1ac4
	db	000h, 000h, 000h, 000h	; 1ac8
	dd	DGROUP:_g_1b7a	; 1acc
	dd	DGROUP:_g_1b86	; 1ad0
	db	000h, 000h, 000h, 000h	; 1ad4
	dd	DGROUP:_g_1b8a	; 1ad8
	dd	DGROUP:_g_1b94	; 1adc
	db	000h, 000h, 000h, 000h	; 1ae0
	dd	DGROUP:_g_1b98	; 1ae4
	dd	DGROUP:_g_1ba3	; 1ae8
	db	000h, 000h, 000h, 000h	; 1aec
	dd	DGROUP:_g_1ba7	; 1af0
	dd	DGROUP:_g_1bb1	; 1af4
	db	000h, 000h, 000h, 000h	; 1af8
	dd	DGROUP:_g_1bb5	; 1afc
	dd	DGROUP:_g_1bbe	; 1b00
	db	000h, 000h, 000h, 000h	; 1b04
	dd	DGROUP:_g_1bc2	; 1b08
	dd	DGROUP:_g_1bcd	; 1b0c
	db	000h, 000h, 000h, 000h	; 1b10
	dd	DGROUP:_g_1bd1	; 1b14
	dd	DGROUP:_g_1bdc	; 1b18
	db	000h, 000h, 000h, 000h	; 1b1c
_g_1b20	label	byte
	db	'ALFX.DRV',0	; 1b20
_g_1b29	label	byte
	db	'ADL',0	; 1b29
_g_1b2d	label	byte
	db	'PCSOUND.DRV',0	; 1b2d
_g_1b39	label	byte
	db	'PCS',0	; 1b39
_g_1b3d	label	byte
	db	'PCSOUND.DRV',0	; 1b3d
_g_1b49	label	byte
	db	'PCS',0	; 1b49
_g_1b4d	label	byte
	db	'PCSPKR.ADV',0	; 1b4d
_g_1b58	label	byte
	db	'PCS',0	; 1b58
_g_1b5c	label	byte
	db	'TANDY.ADV',0	; 1b5c
_g_1b66	label	byte
	db	'TAN',0	; 1b66
_g_1b6a	label	byte
	db	'MT32MPU.ADV',0	; 1b6a
_g_1b76	label	byte
	db	'XMI',0	; 1b76
_g_1b7a	label	byte
	db	'MT32MPU.ADV',0	; 1b7a
_g_1b86	label	byte
	db	'C55',0	; 1b86
_g_1b8a	label	byte
	db	'ADLIB.ADV',0	; 1b8a
_g_1b94	label	byte
	db	'ADL',0	; 1b94
_g_1b98	label	byte
	db	'ADLIBG.ADV',0	; 1b98
_g_1ba3	label	byte
	db	'ADL',0	; 1ba3
_g_1ba7	label	byte
	db	'PASFM.ADV',0	; 1ba7
_g_1bb1	label	byte
	db	'ADL',0	; 1bb1
_g_1bb5	label	byte
	db	'SBFM.ADV',0	; 1bb5
_g_1bbe	label	byte
	db	'ADL',0	; 1bbe
_g_1bc2	label	byte
	db	'SBP1FM.ADV',0	; 1bc2
_g_1bcd	label	byte
	db	'ADL',0	; 1bcd
_g_1bd1	label	byte
	db	'SBP2FM.ADV',0	; 1bd1
_g_1bdc	label	byte
	db	'ADL',0	; 1bdc
_g_1be0	label	byte
	db	000h, 000h	; 1be0
_g_1be2	label	byte
	db	000h, 000h	; 1be2
_g_1be4	label	byte
	db	000h, 000h, 000h, 000h	; 1be4
_g_1be8	label	byte
	db	000h, 000h	; 1be8
_g_1bea	label	byte
	db	000h, 000h	; 1bea
_DATA	ends
_DATA	segment
	dd	DGROUP:_g_1c88	; 1bec
	dd	DGROUP:_g_1c91	; 1bf0
	db	048h, 000h, 000h, 000h	; 1bf4
	dd	DGROUP:_g_1c95	; 1bf8
	dd	DGROUP:_g_1ca1	; 1bfc
	db	024h, 001h, 000h, 000h	; 1c00
	dd	DGROUP:_g_1ca5	; 1c04
	dd	DGROUP:_g_1cb1	; 1c08
	db	024h, 001h, 001h, 000h	; 1c0c
	dd	DGROUP:_g_1cb5	; 1c10
	dd	DGROUP:_g_1cc0	; 1c14
	db	000h, 000h, 000h, 000h	; 1c18
	dd	DGROUP:_g_1cc4	; 1c1c
	dd	DGROUP:_g_1cce	; 1c20
	db	000h, 000h, 000h, 000h	; 1c24
	dd	DGROUP:_g_1cd2	; 1c28
	dd	DGROUP:_g_1cde	; 1c2c
	db	000h, 000h, 000h, 000h	; 1c30
	dd	DGROUP:_g_1ce2	; 1c34
	dd	DGROUP:_g_1cee	; 1c38
	db	000h, 000h, 000h, 000h	; 1c3c
	dd	DGROUP:_g_1cf2	; 1c40
	dd	DGROUP:_g_1cfc	; 1c44
	db	000h, 000h, 000h, 000h	; 1c48
	dd	DGROUP:_g_1d00	; 1c4c
	dd	DGROUP:_g_1d0b	; 1c50
	db	000h, 000h, 000h, 000h	; 1c54
	dd	DGROUP:_g_1d0f	; 1c58
	dd	DGROUP:_g_1d19	; 1c5c
	db	000h, 000h, 000h, 000h	; 1c60
	dd	DGROUP:_g_1d1d	; 1c64
	dd	DGROUP:_g_1d26	; 1c68
	db	000h, 000h, 000h, 000h	; 1c6c
	dd	DGROUP:_g_1d2a	; 1c70
	dd	DGROUP:_g_1d35	; 1c74
	db	000h, 000h, 000h, 000h	; 1c78
	dd	DGROUP:_g_1d39	; 1c7c
	dd	DGROUP:_g_1d44	; 1c80
	db	000h, 000h, 000h, 000h	; 1c84
_g_1c88	label	byte
	db	'ALFX.DRV',0	; 1c88
_g_1c91	label	byte
	db	'ADL',0	; 1c91
_g_1c95	label	byte
	db	'PCSOUND.DRV',0	; 1c95
_g_1ca1	label	byte
	db	'PCS',0	; 1ca1
_g_1ca5	label	byte
	db	'PCSOUND.DRV',0	; 1ca5
_g_1cb1	label	byte
	db	'PCS',0	; 1cb1
_g_1cb5	label	byte
	db	'PCSPKR.ADV',0	; 1cb5
_g_1cc0	label	byte
	db	'PCS',0	; 1cc0
_g_1cc4	label	byte
	db	'TANDY.ADV',0	; 1cc4
_g_1cce	label	byte
	db	'TAN',0	; 1cce
_g_1cd2	label	byte
	db	'MT32MPU.ADV',0	; 1cd2
_g_1cde	label	byte
	db	'XMI',0	; 1cde
_g_1ce2	label	byte
	db	'MT32MPU.ADV',0	; 1ce2
_g_1cee	label	byte
	db	'C55',0	; 1cee
_g_1cf2	label	byte
	db	'ADLIB.ADV',0	; 1cf2
_g_1cfc	label	byte
	db	041h	; 1cfc
_g_1cfd	label	byte
	db	'DL',0	; 1cfd
_g_1d00	label	byte
	db	'ADLIBG.ADV',0	; 1d00
_g_1d0b	label	byte
	db	'ADL',0	; 1d0b
_g_1d0f	label	byte
	db	'PASFM.ADV',0	; 1d0f
_g_1d19	label	byte
	db	'ADL',0	; 1d19
_g_1d1d	label	byte
	db	'SBFM.ADV',0	; 1d1d
_g_1d26	label	byte
	db	'ADL',0	; 1d26
_g_1d2a	label	byte
	db	'SBP1FM.ADV',0	; 1d2a
_g_1d35	label	byte
	db	'ADL',0	; 1d35
_g_1d39	label	byte
	db	'SBP2FM.ADV',0	; 1d39
_g_1d44	label	byte
	db	'ADL',0	; 1d44
_g_1d48	label	byte
	db	000h, 000h	; 1d48
_g_1d4a	label	byte
	db	000h, 000h	; 1d4a
_DATA	ends
_DATA	segment
	dd	DGROUP:_g_1d68	; 1d4c
	dd	DGROUP:_g_1d72	; 1d50
	dd	DGROUP:_g_1d7d	; 1d54
	dd	DGROUP:_g_1d88	; 1d58
	dd	DGROUP:_g_1d93	; 1d5c
	dd	DGROUP:_g_1da0	; 1d60
	dd	DGROUP:_g_1dab	; 1d64
_g_1d68	label	byte
	db	'SBDIG.ADV',0	; 1d68
_g_1d72	label	byte
	db	'SBPDIG.ADV',0	; 1d72
_g_1d7d	label	byte
	db	'PASDIG.ADV',0	; 1d7d
_g_1d88	label	byte
	db	'ALGDIG.ADV',0	; 1d88
_g_1d93	label	byte
	db	'TANDYDIG.ADV',0	; 1d93
_g_1da0	label	byte
	db	'IBMBAK.COM',0	; 1da0
_g_1dab	label	byte
	db	'ADLIB.COM',0	; 1dab
_g_1db5	label	byte
	db	056h, 04fh, 043h, 000h, 000h	; 1db5
_g_1dba	label	byte
	db	'.PAK',0	; 1dba
_g_1dbf	label	byte
	db	'-CD',0	; 1dbf
_g_1dc3	label	byte
	db	'A:',0	; 1dc3
_g_1dc6	label	byte
	db	02eh, 050h, 041h, 04bh, 000h, 000h	; 1dc6
_DATA	ends
	end
