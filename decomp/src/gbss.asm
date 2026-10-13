; gbss: the game's uninitialized data, DGROUP _BSS 0x3ff8..0xafa6 (layout.py GAME_BSS; linked after the game
; modules, before the far data). Data only, no code segment: one label per address any module references.
DGROUP	group	_DATA,_BSS
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
	public	_g_3ff8, _g_3ffa, _g_3ffc, _g_3ffe, _g_4000, _g_4002, _g_4004, _g_4009, _g_400a, _g_400b, _g_4010, _g_4019,
	public	_g_401a, _g_401b, _g_401c, _g_401d, _g_401e, _g_4020, _g_4021, _g_4022, _g_4023, _g_4024, _g_4025, _g_4026,
	public	_g_4027, _g_4028, _g_4029, _g_402a, _g_402b, _g_402c, _g_402d, _g_402e, _g_4033, _g_403e, _g_403f, _g_4040,
	public	_g_4041, _g_4043, _g_4047, _g_404c, _g_4057, _g_4058, _g_4059, _g_405a, _g_405b, _g_405c, _g_4060, _g_4061,
	public	_g_4062, _g_4068, _g_4069, _g_4073, _g_4179, _g_418a, _g_418b, _g_418c, _g_424c, _g_424d, _g_424e, _g_4253,
	public	_g_4254, _g_4257, _g_425b, _g_425c, _g_425d, _g_42cf, _g_42d0, _g_42e0, _g_4300, _g_4310, _g_440e, _g_4500,
	public	_g_4680, _g_4a9c, _g_4a9e, _g_4ac0, _g_4ae4, _g_4ae6, _g_4ae8, _g_4aea, _g_4aec, _g_4aee, _g_4af0, _g_4af2,
	public	_g_4af4, _g_4af6, _g_4af8, _g_4afa, _g_4afc, _g_4b00, _g_4b02, _g_4b04, _g_4b06, _g_4b08, _g_4b12, _g_4b18,
	public	_g_4b22, _g_4b31, _g_4b40, _g_4b42, _g_4b44, _g_4b46, _g_4b48, _g_4b4a, _g_4b4c, _g_4b4e, _g_4b50, _g_4b52,
	public	_g_4b5a, _g_4b60, _g_4b62, _g_4b64, _g_4b66, _g_4b68, _g_4b6a, _g_4b6c, _g_4b6e, _g_4b70, _g_4b72, _g_4b74,
	public	_g_4b76, _g_4b86, _g_4b88, _g_4b8c, _g_4b8e, _g_4b90, _g_4b92, _g_4b94, _g_4b9c, _g_4baa, _g_4bac, _g_4bae,
	public	_g_4bb0, _g_4bb2, _g_4bb4, _g_4bb6, _g_4bb8, _g_4bba, _g_4bbc, _g_4bbe, _g_4bc0, _g_4bc2, _g_4bc4, _g_4bc6,
	public	_g_4bc8, _g_4bcc, _g_4bce, _g_4bd0, _g_4bd2, _g_4bd4, _g_4bd6, _g_4bd8, _g_4bda, _g_4bde, _g_4be0, _g_4bea,
	public	_g_4bec, _g_4bee, _g_4bf0, _g_4bf2, _g_4bf4, _g_4bf6, _g_4bf8, _g_4bfa, _g_4bfc, _g_4c00, _g_4c02, _g_4c06,
	public	_g_4c08, _g_4c0a, _g_4c0c, _g_4d56, _g_4d58, _g_4d5a, _g_4d5c, _g_4d5e, _g_4d60, _g_4d62, _g_4d64, _g_4d66,
	public	_g_4d68, _g_4d6a, _g_4d6c, _g_4d6e, _g_4d70, _g_4d72, _g_4d78, _g_4d7a, _g_4d7e, _g_4d80, _g_4d82, _g_4d84,
	public	_g_4d86, _g_4d88, _g_4d8c, _g_4d90, _g_4d94, _g_4d98, _g_4d9c, _g_4da0, _g_4da4, _g_4da8, _g_4dac, _g_4db0,
	public	_g_4db4, _g_4db8, _g_4dbc, _g_4dc0, _g_4dc8, _g_4dcc, _g_4dcd, _g_4dd0, _g_4dd2, _g_4dd4, _g_4dd7, _g_4e54,
	public	_g_4e56, _g_4ea0, _g_4ea2, _g_4eac, _g_4ed0, _g_4ed2, _g_4ed3, _g_4edc, _g_4ede, _g_4ee0, _g_4ee2, _g_4eec,
	public	_g_4eed, _g_4ef4, _g_5000, _g_5269, _g_5275, _g_5276, _g_5301, _g_531e, _g_5321, _g_532b, _g_5330, _g_536e,
	public	_g_53be, _g_53c0, _g_53c1, _g_53c2, _g_540e, _g_5410, _g_5412, _g_5414, _g_5505, _g_5819, _g_5a52, _g_5a54,
	public	_g_5a66, _g_5a70, _g_5a72, _g_5a84, _g_5a86, _g_5a98, _g_5a99, _g_6300, _g_6400, _g_6507, _g_66ce, _g_6a6c,
	public	_g_7000, _g_7004, _g_7308, _g_7672, _g_7674, _g_7783, _g_7785, _g_7800, _g_7c72, _g_7c74, _g_7c82, _g_7c8e,
	public	_g_7c92, _g_7c94, _g_7d00, _g_7d82, _g_7d84, _g_7d88, _g_7e08, _g_7f7f, _g_7fa7, _g_7faa, _g_7fac, _g_7fae,
	public	_g_7fb0, _g_7fb2, _g_7fb4, _g_7fb6, _g_7fb8, _g_7fbc, _g_7fbe, _g_7fc0, _g_7fc2, _g_7fc4, _g_7fc6, _g_7fc8,
	public	_g_7fca, _g_7fcc, _g_7fce, _g_7fd0, _g_7fd2, _g_7fd4, _g_7fd6, _g_7fd8, _g_7fd9, _g_7fda, _g_7fdc, _g_7fdd,
	public	_g_7fde, _g_7fdf, _g_7fe1, _g_7fe3, _g_7fe5, _g_7fe6, _g_7fe8, _g_7fea, _g_7fff, _g_8000, _g_8001, _g_8002,
	public	_g_8003, _g_8046, _g_8048, _g_804a, _g_804c, _g_806a, _g_8080, _g_8094, _g_8114, _g_81dc, _g_81dd, _g_81de,
	public	_g_81e0, _g_81e2, _g_81f2, _g_81f3, _g_81f9, _g_81fd, _g_81fe, _g_81ff, _g_8200, _g_8201, _g_8203, _g_8207,
	public	_g_8b55, _g_96f9, _g_a000, _g_a12a, _g_a1a1, _g_a34d, _g_a3a2, _g_a3a3, _g_a5a5, _g_aa03, _g_ab04, _g_ab0a,
	public	_g_ab0b, _g_ab0d, _g_ab10, _g_ab1a, _g_ab1c, _g_ab20, _g_ab22, _g_ab24, _g_ab26, _g_ab2a, _g_ab2c, _g_ab2e,
	public	_g_ab30, _g_ab32, _g_ab36, _g_ab3a, _g_ab3e, _g_ab3f, _g_ab40, _g_ab41, _g_ab43, _g_ab45, _g_ab49, _g_ab4b,
	public	_g_ab4d, _g_ab4f, _g_aba4, _g_aba6, _g_aba7, _g_abac, _g_abb0, _g_abb2, _g_abb3, _g_abb8, _g_abbe, _g_abc0,
	public	_g_abc2, _g_abc4, _g_abc6, _g_abc8, _g_abca, _g_abce, _g_abd2, _g_abd4, _g_abd6, _g_abd8, _g_abda, _g_abdc,
	public	_g_abde, _g_abdf, _g_abe0, _g_abe2, _g_ad41, _g_ad42, _g_ad43, _g_ad44, _g_ad45, _g_ad46, _g_ad49, _g_ad4d,
	public	_g_ad51, _g_ad8b, _g_ad8d, _g_ad8f, _g_ad91, _g_ad93, _g_ad95, _g_ad97, _g_ad99, _g_adea, _g_adec, _g_ae4d,
	public	_g_ae4f, _g_ae51, _g_ae53, _g_ae57, _g_ae59, _g_aeaa, _g_aefb, _g_af4c, _g_af5c, _g_af6c, _g_af72, _g_af7a,
	public	_g_af88, _g_af8a, _g_af8e, _g_af92, _g_af93, _g_af94
_g_3ff8	label	byte
	db	2 dup (?)
_g_3ffa	label	byte
	db	2 dup (?)
_g_3ffc	label	byte
	db	2 dup (?)
_g_3ffe	label	byte
	db	2 dup (?)
_g_4000	label	byte
	db	2 dup (?)
_g_4002	label	byte
	db	2 dup (?)
_g_4004	label	byte
	db	5 dup (?)
_g_4009	label	byte
	db	1 dup (?)
_g_400a	label	byte
	db	1 dup (?)
_g_400b	label	byte
	db	5 dup (?)
_g_4010	label	byte
	db	9 dup (?)
_g_4019	label	byte
	db	1 dup (?)
_g_401a	label	byte
	db	1 dup (?)
_g_401b	label	byte
	db	1 dup (?)
_g_401c	label	byte
	db	1 dup (?)
_g_401d	label	byte
	db	1 dup (?)
_g_401e	label	byte
	db	2 dup (?)
_g_4020	label	byte
	db	1 dup (?)
_g_4021	label	byte
	db	1 dup (?)
_g_4022	label	byte
	db	1 dup (?)
_g_4023	label	byte
	db	1 dup (?)
_g_4024	label	byte
	db	1 dup (?)
_g_4025	label	byte
	db	1 dup (?)
_g_4026	label	byte
	db	1 dup (?)
_g_4027	label	byte
	db	1 dup (?)
_g_4028	label	byte
	db	1 dup (?)
_g_4029	label	byte
	db	1 dup (?)
_g_402a	label	byte
	db	1 dup (?)
_g_402b	label	byte
	db	1 dup (?)
_g_402c	label	byte
	db	1 dup (?)
_g_402d	label	byte
	db	1 dup (?)
_g_402e	label	byte
	db	5 dup (?)
_g_4033	label	byte
	db	11 dup (?)
_g_403e	label	byte
	db	1 dup (?)
_g_403f	label	byte
	db	1 dup (?)
_g_4040	label	byte
	db	1 dup (?)
_g_4041	label	byte
	db	2 dup (?)
_g_4043	label	byte
	db	4 dup (?)
_g_4047	label	byte
	db	5 dup (?)
_g_404c	label	byte
	db	11 dup (?)
_g_4057	label	byte
	db	1 dup (?)
_g_4058	label	byte
	db	1 dup (?)
_g_4059	label	byte
	db	1 dup (?)
_g_405a	label	byte
	db	1 dup (?)
_g_405b	label	byte
	db	1 dup (?)
_g_405c	label	byte
	db	4 dup (?)
_g_4060	label	byte
	db	1 dup (?)
_g_4061	label	byte
	db	1 dup (?)
_g_4062	label	byte
	db	6 dup (?)
_g_4068	label	byte
	db	1 dup (?)
_g_4069	label	byte
	db	10 dup (?)
_g_4073	label	byte
	db	262 dup (?)
_g_4179	label	byte
	db	17 dup (?)
_g_418a	label	byte
	db	1 dup (?)
_g_418b	label	byte
	db	1 dup (?)
_g_418c	label	byte
	db	192 dup (?)
_g_424c	label	byte
	db	1 dup (?)
_g_424d	label	byte
	db	1 dup (?)
_g_424e	label	byte
	db	5 dup (?)
_g_4253	label	byte
	db	1 dup (?)
_g_4254	label	byte
	db	3 dup (?)
_g_4257	label	byte
	db	4 dup (?)
_g_425b	label	byte
	db	1 dup (?)
_g_425c	label	byte
	db	1 dup (?)
_g_425d	label	byte
	db	114 dup (?)
_g_42cf	label	byte
	db	1 dup (?)
_g_42d0	label	byte
	db	16 dup (?)
_g_42e0	label	byte
	db	32 dup (?)
_g_4300	label	byte
	db	16 dup (?)
_g_4310	label	byte
	db	254 dup (?)
_g_440e	label	byte
	db	242 dup (?)
_g_4500	label	byte
	db	384 dup (?)
_g_4680	label	byte
	db	1052 dup (?)
_g_4a9c	label	byte
	db	2 dup (?)
_g_4a9e	label	byte
	db	34 dup (?)
_g_4ac0	label	byte
	db	36 dup (?)
_g_4ae4	label	byte
	db	2 dup (?)
_g_4ae6	label	byte
	db	2 dup (?)
_g_4ae8	label	byte
	db	2 dup (?)
_g_4aea	label	byte
	db	2 dup (?)
_g_4aec	label	byte
	db	2 dup (?)
_g_4aee	label	byte
	db	2 dup (?)
_g_4af0	label	byte
	db	2 dup (?)
_g_4af2	label	byte
	db	2 dup (?)
_g_4af4	label	byte
	db	2 dup (?)
_g_4af6	label	byte
	db	2 dup (?)
_g_4af8	label	byte
	db	2 dup (?)
_g_4afa	label	byte
	db	2 dup (?)
_g_4afc	label	byte
	db	4 dup (?)
_g_4b00	label	byte
	db	2 dup (?)
_g_4b02	label	byte
	db	2 dup (?)
_g_4b04	label	byte
	db	2 dup (?)
_g_4b06	label	byte
	db	2 dup (?)
_g_4b08	label	byte
	db	10 dup (?)
_g_4b12	label	byte
	db	6 dup (?)
_g_4b18	label	byte
	db	10 dup (?)
_g_4b22	label	byte
	db	15 dup (?)
_g_4b31	label	byte
	db	15 dup (?)
_g_4b40	label	byte
	db	2 dup (?)
_g_4b42	label	byte
	db	2 dup (?)
_g_4b44	label	byte
	db	2 dup (?)
_g_4b46	label	byte
	db	2 dup (?)
_g_4b48	label	byte
	db	2 dup (?)
_g_4b4a	label	byte
	db	2 dup (?)
_g_4b4c	label	byte
	db	2 dup (?)
_g_4b4e	label	byte
	db	2 dup (?)
_g_4b50	label	byte
	db	2 dup (?)
_g_4b52	label	byte
	db	8 dup (?)
_g_4b5a	label	byte
	db	6 dup (?)
_g_4b60	label	byte
	db	2 dup (?)
_g_4b62	label	byte
	db	2 dup (?)
_g_4b64	label	byte
	db	2 dup (?)
_g_4b66	label	byte
	db	2 dup (?)
_g_4b68	label	byte
	db	2 dup (?)
_g_4b6a	label	byte
	db	2 dup (?)
_g_4b6c	label	byte
	db	2 dup (?)
_g_4b6e	label	byte
	db	2 dup (?)
_g_4b70	label	byte
	db	2 dup (?)
_g_4b72	label	byte
	db	2 dup (?)
_g_4b74	label	byte
	db	2 dup (?)
_g_4b76	label	byte
	db	16 dup (?)
_g_4b86	label	byte
	db	2 dup (?)
_g_4b88	label	byte
	db	4 dup (?)
_g_4b8c	label	byte
	db	2 dup (?)
_g_4b8e	label	byte
	db	2 dup (?)
_g_4b90	label	byte
	db	2 dup (?)
_g_4b92	label	byte
	db	2 dup (?)
_g_4b94	label	byte
	db	8 dup (?)
_g_4b9c	label	byte
	db	14 dup (?)
_g_4baa	label	byte
	db	2 dup (?)
_g_4bac	label	byte
	db	2 dup (?)
_g_4bae	label	byte
	db	2 dup (?)
_g_4bb0	label	byte
	db	2 dup (?)
_g_4bb2	label	byte
	db	2 dup (?)
_g_4bb4	label	byte
	db	2 dup (?)
_g_4bb6	label	byte
	db	2 dup (?)
_g_4bb8	label	byte
	db	2 dup (?)
_g_4bba	label	byte
	db	2 dup (?)
_g_4bbc	label	byte
	db	2 dup (?)
_g_4bbe	label	byte
	db	2 dup (?)
_g_4bc0	label	byte
	db	2 dup (?)
_g_4bc2	label	byte
	db	2 dup (?)
_g_4bc4	label	byte
	db	2 dup (?)
_g_4bc6	label	byte
	db	2 dup (?)
_g_4bc8	label	byte
	db	4 dup (?)
_g_4bcc	label	byte
	db	2 dup (?)
_g_4bce	label	byte
	db	2 dup (?)
_g_4bd0	label	byte
	db	2 dup (?)
_g_4bd2	label	byte
	db	2 dup (?)
_g_4bd4	label	byte
	db	2 dup (?)
_g_4bd6	label	byte
	db	2 dup (?)
_g_4bd8	label	byte
	db	2 dup (?)
_g_4bda	label	byte
	db	4 dup (?)
_g_4bde	label	byte
	db	2 dup (?)
_g_4be0	label	byte
	db	10 dup (?)
_g_4bea	label	byte
	db	2 dup (?)
_g_4bec	label	byte
	db	2 dup (?)
_g_4bee	label	byte
	db	2 dup (?)
_g_4bf0	label	byte
	db	2 dup (?)
_g_4bf2	label	byte
	db	2 dup (?)
_g_4bf4	label	byte
	db	2 dup (?)
_g_4bf6	label	byte
	db	2 dup (?)
_g_4bf8	label	byte
	db	2 dup (?)
_g_4bfa	label	byte
	db	2 dup (?)
_g_4bfc	label	byte
	db	4 dup (?)
_g_4c00	label	byte
	db	2 dup (?)
_g_4c02	label	byte
	db	4 dup (?)
_g_4c06	label	byte
	db	2 dup (?)
_g_4c08	label	byte
	db	2 dup (?)
_g_4c0a	label	byte
	db	2 dup (?)
_g_4c0c	label	byte
	db	330 dup (?)
_g_4d56	label	byte
	db	2 dup (?)
_g_4d58	label	byte
	db	2 dup (?)
_g_4d5a	label	byte
	db	2 dup (?)
_g_4d5c	label	byte
	db	2 dup (?)
_g_4d5e	label	byte
	db	2 dup (?)
_g_4d60	label	byte
	db	2 dup (?)
_g_4d62	label	byte
	db	2 dup (?)
_g_4d64	label	byte
	db	2 dup (?)
_g_4d66	label	byte
	db	2 dup (?)
_g_4d68	label	byte
	db	2 dup (?)
_g_4d6a	label	byte
	db	2 dup (?)
_g_4d6c	label	byte
	db	2 dup (?)
_g_4d6e	label	byte
	db	2 dup (?)
_g_4d70	label	byte
	db	2 dup (?)
_g_4d72	label	byte
	db	6 dup (?)
_g_4d78	label	byte
	db	2 dup (?)
_g_4d7a	label	byte
	db	4 dup (?)
_g_4d7e	label	byte
	db	2 dup (?)
_g_4d80	label	byte
	db	2 dup (?)
_g_4d82	label	byte
	db	2 dup (?)
_g_4d84	label	byte
	db	2 dup (?)
_g_4d86	label	byte
	db	2 dup (?)
_g_4d88	label	byte
	db	4 dup (?)
_g_4d8c	label	byte
	db	4 dup (?)
_g_4d90	label	byte
	db	4 dup (?)
_g_4d94	label	byte
	db	4 dup (?)
_g_4d98	label	byte
	db	4 dup (?)
_g_4d9c	label	byte
	db	4 dup (?)
_g_4da0	label	byte
	db	4 dup (?)
_g_4da4	label	byte
	db	4 dup (?)
_g_4da8	label	byte
	db	4 dup (?)
_g_4dac	label	byte
	db	4 dup (?)
_g_4db0	label	byte
	db	4 dup (?)
_g_4db4	label	byte
	db	4 dup (?)
_g_4db8	label	byte
	db	4 dup (?)
_g_4dbc	label	byte
	db	4 dup (?)
_g_4dc0	label	byte
	db	8 dup (?)
_g_4dc8	label	byte
	db	4 dup (?)
_g_4dcc	label	byte
	db	1 dup (?)
_g_4dcd	label	byte
	db	3 dup (?)
_g_4dd0	label	byte
	db	2 dup (?)
_g_4dd2	label	byte
	db	2 dup (?)
_g_4dd4	label	byte
	db	3 dup (?)
_g_4dd7	label	byte
	db	125 dup (?)
_g_4e54	label	byte
	db	2 dup (?)
_g_4e56	label	byte
	db	74 dup (?)
_g_4ea0	label	byte
	db	2 dup (?)
_g_4ea2	label	byte
	db	10 dup (?)
_g_4eac	label	byte
	db	36 dup (?)
_g_4ed0	label	byte
	db	2 dup (?)
_g_4ed2	label	byte
	db	1 dup (?)
_g_4ed3	label	byte
	db	9 dup (?)
_g_4edc	label	byte
	db	2 dup (?)
_g_4ede	label	byte
	db	2 dup (?)
_g_4ee0	label	byte
	db	2 dup (?)
_g_4ee2	label	byte
	db	10 dup (?)
_g_4eec	label	byte
	db	1 dup (?)
_g_4eed	label	byte
	db	7 dup (?)
_g_4ef4	label	byte
	db	268 dup (?)
_g_5000	label	byte
	db	617 dup (?)
_g_5269	label	byte
	db	12 dup (?)
_g_5275	label	byte
	db	1 dup (?)
_g_5276	label	byte
	db	139 dup (?)
_g_5301	label	byte
	db	29 dup (?)
_g_531e	label	byte
	db	3 dup (?)
_g_5321	label	byte
	db	10 dup (?)
_g_532b	label	byte
	db	5 dup (?)
_g_5330	label	byte
	db	62 dup (?)
_g_536e	label	byte
	db	80 dup (?)
_g_53be	label	byte
	db	2 dup (?)
_g_53c0	label	byte
	db	1 dup (?)
_g_53c1	label	byte
	db	1 dup (?)
_g_53c2	label	byte
	db	76 dup (?)
_g_540e	label	byte
	db	2 dup (?)
_g_5410	label	byte
	db	2 dup (?)
_g_5412	label	byte
	db	2 dup (?)
_g_5414	label	byte
	db	241 dup (?)
_g_5505	label	byte
	db	788 dup (?)
_g_5819	label	byte
	db	569 dup (?)
_g_5a52	label	byte
	db	2 dup (?)
_g_5a54	label	byte
	db	18 dup (?)
_g_5a66	label	byte
	db	10 dup (?)
_g_5a70	label	byte
	db	2 dup (?)
_g_5a72	label	byte
	db	18 dup (?)
_g_5a84	label	byte
	db	2 dup (?)
_g_5a86	label	byte
	db	18 dup (?)
_g_5a98	label	byte
	db	1 dup (?)
_g_5a99	label	byte
	db	2151 dup (?)
_g_6300	label	byte
	db	256 dup (?)
_g_6400	label	byte
	db	263 dup (?)
_g_6507	label	byte
	db	455 dup (?)
_g_66ce	label	byte
	db	926 dup (?)
_g_6a6c	label	byte
	db	1428 dup (?)
_g_7000	label	byte
	db	4 dup (?)
_g_7004	label	byte
	db	772 dup (?)
_g_7308	label	byte
	db	874 dup (?)
_g_7672	label	byte
	db	2 dup (?)
_g_7674	label	byte
	db	271 dup (?)
_g_7783	label	byte
	db	2 dup (?)
_g_7785	label	byte
	db	123 dup (?)
_g_7800	label	byte
	db	1138 dup (?)
_g_7c72	label	byte
	db	2 dup (?)
_g_7c74	label	byte
	db	14 dup (?)
_g_7c82	label	byte
	db	12 dup (?)
_g_7c8e	label	byte
	db	4 dup (?)
_g_7c92	label	byte
	db	2 dup (?)
_g_7c94	label	byte
	db	108 dup (?)
_g_7d00	label	byte
	db	130 dup (?)
_g_7d82	label	byte
	db	2 dup (?)
_g_7d84	label	byte
	db	4 dup (?)
_g_7d88	label	byte
	db	128 dup (?)
_g_7e08	label	byte
	db	375 dup (?)
_g_7f7f	label	byte
	db	40 dup (?)
_g_7fa7	label	byte
	db	3 dup (?)
_g_7faa	label	byte
	db	2 dup (?)
_g_7fac	label	byte
	db	2 dup (?)
_g_7fae	label	byte
	db	2 dup (?)
_g_7fb0	label	byte
	db	2 dup (?)
_g_7fb2	label	byte
	db	2 dup (?)
_g_7fb4	label	byte
	db	2 dup (?)
_g_7fb6	label	byte
	db	2 dup (?)
_g_7fb8	label	byte
	db	4 dup (?)
_g_7fbc	label	byte
	db	2 dup (?)
_g_7fbe	label	byte
	db	2 dup (?)
_g_7fc0	label	byte
	db	2 dup (?)
_g_7fc2	label	byte
	db	2 dup (?)
_g_7fc4	label	byte
	db	2 dup (?)
_g_7fc6	label	byte
	db	2 dup (?)
_g_7fc8	label	byte
	db	2 dup (?)
_g_7fca	label	byte
	db	2 dup (?)
_g_7fcc	label	byte
	db	2 dup (?)
_g_7fce	label	byte
	db	2 dup (?)
_g_7fd0	label	byte
	db	2 dup (?)
_g_7fd2	label	byte
	db	2 dup (?)
_g_7fd4	label	byte
	db	2 dup (?)
_g_7fd6	label	byte
	db	2 dup (?)
_g_7fd8	label	byte
	db	1 dup (?)
_g_7fd9	label	byte
	db	1 dup (?)
_g_7fda	label	byte
	db	2 dup (?)
_g_7fdc	label	byte
	db	1 dup (?)
_g_7fdd	label	byte
	db	1 dup (?)
_g_7fde	label	byte
	db	1 dup (?)
_g_7fdf	label	byte
	db	2 dup (?)
_g_7fe1	label	byte
	db	2 dup (?)
_g_7fe3	label	byte
	db	2 dup (?)
_g_7fe5	label	byte
	db	1 dup (?)
_g_7fe6	label	byte
	db	2 dup (?)
_g_7fe8	label	byte
	db	2 dup (?)
_g_7fea	label	byte
	db	21 dup (?)
_g_7fff	label	byte
	db	1 dup (?)
_g_8000	label	byte
	db	1 dup (?)
_g_8001	label	byte
	db	1 dup (?)
_g_8002	label	byte
	db	1 dup (?)
_g_8003	label	byte
	db	67 dup (?)
_g_8046	label	byte
	db	2 dup (?)
_g_8048	label	byte
	db	2 dup (?)
_g_804a	label	byte
	db	2 dup (?)
_g_804c	label	byte
	db	30 dup (?)
_g_806a	label	byte
	db	22 dup (?)
_g_8080	label	byte
	db	20 dup (?)
_g_8094	label	byte
	db	128 dup (?)
_g_8114	label	byte
	db	200 dup (?)
_g_81dc	label	byte
	db	1 dup (?)
_g_81dd	label	byte
	db	1 dup (?)
_g_81de	label	byte
	db	2 dup (?)
_g_81e0	label	byte
	db	2 dup (?)
_g_81e2	label	byte
	db	16 dup (?)
_g_81f2	label	byte
	db	1 dup (?)
_g_81f3	label	byte
	db	6 dup (?)
_g_81f9	label	byte
	db	4 dup (?)
_g_81fd	label	byte
	db	1 dup (?)
_g_81fe	label	byte
	db	1 dup (?)
_g_81ff	label	byte
	db	1 dup (?)
_g_8200	label	byte
	db	1 dup (?)
_g_8201	label	byte
	db	2 dup (?)
_g_8203	label	byte
	db	4 dup (?)
_g_8207	label	byte
	db	2382 dup (?)
_g_8b55	label	byte
	db	2980 dup (?)
_g_96f9	label	byte
	db	2311 dup (?)
_g_a000	label	byte
	db	298 dup (?)
_g_a12a	label	byte
	db	119 dup (?)
_g_a1a1	label	byte
	db	428 dup (?)
_g_a34d	label	byte
	db	85 dup (?)
_g_a3a2	label	byte
	db	1 dup (?)
_g_a3a3	label	byte
	db	514 dup (?)
_g_a5a5	label	byte
	db	1118 dup (?)
_g_aa03	label	byte
	db	257 dup (?)
_g_ab04	label	byte
	db	6 dup (?)
_g_ab0a	label	byte
	db	1 dup (?)
_g_ab0b	label	byte
	db	2 dup (?)
_g_ab0d	label	byte
	db	3 dup (?)
_g_ab10	label	byte
	db	10 dup (?)
_g_ab1a	label	byte
	db	2 dup (?)
_g_ab1c	label	byte
	db	4 dup (?)
_g_ab20	label	byte
	db	2 dup (?)
_g_ab22	label	byte
	db	2 dup (?)
_g_ab24	label	byte
	db	2 dup (?)
_g_ab26	label	byte
	db	4 dup (?)
_g_ab2a	label	byte
	db	2 dup (?)
_g_ab2c	label	byte
	db	2 dup (?)
_g_ab2e	label	byte
	db	2 dup (?)
_g_ab30	label	byte
	db	2 dup (?)
_g_ab32	label	byte
	db	4 dup (?)
_g_ab36	label	byte
	db	4 dup (?)
_g_ab3a	label	byte
	db	4 dup (?)
_g_ab3e	label	byte
	db	1 dup (?)
_g_ab3f	label	byte
	db	1 dup (?)
_g_ab40	label	byte
	db	1 dup (?)
_g_ab41	label	byte
	db	2 dup (?)
_g_ab43	label	byte
	db	2 dup (?)
_g_ab45	label	byte
	db	4 dup (?)
_g_ab49	label	byte
	db	2 dup (?)
_g_ab4b	label	byte
	db	2 dup (?)
_g_ab4d	label	byte
	db	2 dup (?)
_g_ab4f	label	byte
	db	85 dup (?)
_g_aba4	label	byte
	db	2 dup (?)
_g_aba6	label	byte
	db	1 dup (?)
_g_aba7	label	byte
	db	5 dup (?)
_g_abac	label	byte
	db	4 dup (?)
_g_abb0	label	byte
	db	2 dup (?)
_g_abb2	label	byte
	db	1 dup (?)
_g_abb3	label	byte
	db	5 dup (?)
_g_abb8	label	byte
	db	6 dup (?)
_g_abbe	label	byte
	db	2 dup (?)
_g_abc0	label	byte
	db	2 dup (?)
_g_abc2	label	byte
	db	2 dup (?)
_g_abc4	label	byte
	db	2 dup (?)
_g_abc6	label	byte
	db	2 dup (?)
_g_abc8	label	byte
	db	2 dup (?)
_g_abca	label	byte
	db	4 dup (?)
_g_abce	label	byte
	db	4 dup (?)
_g_abd2	label	byte
	db	2 dup (?)
_g_abd4	label	byte
	db	2 dup (?)
_g_abd6	label	byte
	db	2 dup (?)
_g_abd8	label	byte
	db	2 dup (?)
_g_abda	label	byte
	db	2 dup (?)
_g_abdc	label	byte
	db	2 dup (?)
_g_abde	label	byte
	db	1 dup (?)
_g_abdf	label	byte
	db	1 dup (?)
_g_abe0	label	byte
	db	2 dup (?)
_g_abe2	label	byte
	db	351 dup (?)
_g_ad41	label	byte
	db	1 dup (?)
_g_ad42	label	byte
	db	1 dup (?)
_g_ad43	label	byte
	db	1 dup (?)
_g_ad44	label	byte
	db	1 dup (?)
_g_ad45	label	byte
	db	1 dup (?)
_g_ad46	label	byte
	db	3 dup (?)
_g_ad49	label	byte
	db	4 dup (?)
_g_ad4d	label	byte
	db	4 dup (?)
_g_ad51	label	byte
	db	58 dup (?)
_g_ad8b	label	byte
	db	2 dup (?)
_g_ad8d	label	byte
	db	2 dup (?)
_g_ad8f	label	byte
	db	2 dup (?)
_g_ad91	label	byte
	db	2 dup (?)
_g_ad93	label	byte
	db	2 dup (?)
_g_ad95	label	byte
	db	2 dup (?)
_g_ad97	label	byte
	db	2 dup (?)
_g_ad99	label	byte
	db	81 dup (?)
_g_adea	label	byte
	db	2 dup (?)
_g_adec	label	byte
	db	97 dup (?)
_g_ae4d	label	byte
	db	2 dup (?)
_g_ae4f	label	byte
	db	2 dup (?)
_g_ae51	label	byte
	db	2 dup (?)
_g_ae53	label	byte
	db	4 dup (?)
_g_ae57	label	byte
	db	2 dup (?)
_g_ae59	label	byte
	db	81 dup (?)
_g_aeaa	label	byte
	db	81 dup (?)
_g_aefb	label	byte
	db	81 dup (?)
_g_af4c	label	byte
	db	16 dup (?)
_g_af5c	label	byte
	db	16 dup (?)
_g_af6c	label	byte
	db	6 dup (?)
_g_af72	label	byte
	db	8 dup (?)
_g_af7a	label	byte
	db	14 dup (?)
_g_af88	label	byte
	db	2 dup (?)
_g_af8a	label	byte
	db	4 dup (?)
_g_af8e	label	byte
	db	4 dup (?)
_g_af92	label	byte
	db	1 dup (?)
_g_af93	label	byte
	db	1 dup (?)
_g_af94	label	byte
	db	18 dup (?)
_BSS	ends
	end
