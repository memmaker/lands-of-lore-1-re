; s038: segment 19c9 (TASM module)
	.386
S038_TEXT	segment word public use16 'CODE'
S038_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:S038_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
	extrn	_fn_215f_001d:far
	extrn	_fn_2279_02b5:far
S038_TEXT	segment
	public	_fn_19c9_0730, _fn_19c9_075b, _fn_19c9_079a, _fn_19c9_07e2, _fn_19c9_089f, _fn_19c9_095d, _fn_19c9_0988, _fn_19c9_09a4, _fn_19c9_09cf, _fn_19c9_0a01, _fn_19c9_0a61, _fn_19c9_0ab1, _fn_19c9_0b15, _fn_19c9_0b55, _fn_19c9_0bc6, _fn_19c9_0c24, _fn_19c9_0c8e, _fn_19c9_0dbf, _fn_19c9_0ff6, _fn_19c9_1100, _fn_19c9_121b, _fn_19c9_123f, _fn_19c9_1265, _fn_19c9_12a2
L0000	label	byte
	db	1064 dup (0h)	; 0
L0428	label	byte
	dd	L0530, L0430	; 428
L0430	label	byte
	db	256 dup (0h)	; 430
L0530	label	byte
	dw	0h, 324h, 647h, 96ah, 0c8bh, 0fabh, 12c7h, 15e1h	; 530
	dw	18f8h, 1c0bh, 1f19h, 2223h, 2527h, 2826h, 2b1eh, 2e10h	; 540
	dw	30fbh, 33deh, 36b9h, 398ch, 3c56h, 3f16h, 41cdh, 447ah	; 550
	dw	471ch, 49b3h, 4c3fh, 4ebfh, 5133h, 539ah, 55f4h, 5842h	; 560
	dw	5a81h, 5cb3h, 5ed6h, 60ebh, 62f1h, 64e7h, 66ceh, 68a5h	; 570
	dw	6a6ch, 6c23h, 6dc9h, 6f5eh, 70e1h, 7254h, 73b5h, 7503h	; 580
	dw	7640h, 776bh, 7883h, 7989h, 7a7ch, 7b5ch, 7c29h, 7ce2h	; 590
	dw	7d89h, 7e1ch, 7e9ch, 7f08h, 7f61h, 7fa6h, 7fd7h, 7ff5h	; 5a0
	dw	7fffh, 7ff5h, 7fd7h, 7fa6h, 7f61h, 7f08h, 7e9ch, 7e1ch	; 5b0
	dw	7d89h, 7ce2h, 7c29h, 7b5ch, 7a7ch, 7989h, 7883h, 776bh	; 5c0
	dw	7640h, 7503h, 73b5h, 7254h, 70e1h, 6f5eh, 6dc9h, 6c23h	; 5d0
	dw	6a6ch, 68a5h, 66ceh, 64e7h, 62f1h, 60ebh, 5ed6h, 5cb3h	; 5e0
	dw	5a81h, 5842h, 55f4h, 539ah, 5133h, 4ebfh, 4c3fh, 49b3h	; 5f0
	dw	471ch, 447ah, 41cdh, 3f16h, 3c56h, 398ch, 36b9h, 33deh	; 600
	dw	30fbh, 2e10h, 2b1eh, 2826h, 2527h, 2223h, 1f19h, 1c0bh	; 610
	dw	18f8h, 15e1h, 12c7h, 0fabh, 0c8bh, 96ah, 647h, 324h	; 620
	dw	0h, 0fcdch, 0f9b9h, 0f696h, 0f375h, 0f055h, 0ed39h, 0ea1fh	; 630
	dw	0e708h, 0e3f5h, 0e0e7h, 0ddddh, 0dad9h, 0d7dah, 0d4e2h, 0d1f0h	; 640
	dw	0cf05h, 0cc22h, 0c947h, 0c674h, 0c3aah, 0c0eah, 0be33h, 0bb86h	; 650
	dw	0b8e4h, 0b64dh, 0b3c1h, 0b141h, 0aecdh, 0ac66h, 0aa0ch, 0a7beh	; 660
	dw	0a57fh, 0a34dh, 0a12ah, 9f15h, 9d0fh, 9b19h, 9932h, 975bh	; 670
	dw	9594h, 93ddh, 9237h, 90a2h, 8f1fh, 8dach, 8c4bh, 8afdh	; 680
	dw	89c0h, 8895h, 877dh, 8677h, 8584h, 84a4h, 83d7h, 831eh	; 690
	dw	8277h, 81e4h, 8164h, 80f8h, 809fh, 805ah, 8029h, 800bh	; 6a0
	dw	8001h, 800bh, 8029h, 805ah, 809fh, 80f8h, 8164h, 81e4h	; 6b0
	dw	8277h, 831eh, 83d7h, 84a4h, 8584h, 8677h, 877dh, 8895h	; 6c0
	dw	89c0h, 8afdh, 8c4bh, 8dach, 8f1fh, 90a2h, 9237h, 93ddh	; 6d0
	dw	9594h, 975bh, 9932h, 9b19h, 9d0fh, 9f15h, 0a12ah, 0a34dh	; 6e0
	dw	0a57fh, 0a7beh, 0aa0ch, 0ac66h, 0aecdh, 0b141h, 0b3c1h, 0b64dh	; 6f0
	dw	0b8e4h, 0bb86h, 0be33h, 0c0eah, 0c3aah, 0c674h, 0c947h, 0cc22h	; 700
	dw	0cf05h, 0d1f0h, 0d4e2h, 0d7dah, 0dad9h, 0ddddh, 0e0e7h, 0e3f5h	; 710
	dw	0e708h, 0ea1fh, 0ed39h, 0f055h, 0f375h, 0f696h, 0f9b9h, 0fcdch	; 720
_fn_19c9_0730	proc	far
	enter	0h,0h		; 730
	push	ax		; 734
	push	bx		; 735
	push	cx		; 736
	push	es		; 737
	push	di		; 738
	les	di,[bp+6h]		; 739
	add	di,79b0h		; 73c
	mov	bx,17h		; 740
	xor	eax,eax		; 743
	cld		; 746
L0747:
	mov	cx,2ch		; 747
	rep	stosd		; 74a
	add	di,90h		; 74d
	dec	bx		; 751
	jnz	short L0747		; 752
	pop	di		; 754
	pop	es		; 755
	pop	cx		; 756
	pop	bx		; 757
	pop	ax		; 758
	leave		; 759
	retf		; 75a
_fn_19c9_0730	endp

_fn_19c9_075b	proc	far
	enter	0h,0h		; 75b
	push	ax		; 75f
	push	bx		; 760
	push	cx		; 761
	push	dx		; 762
	push	ds		; 763
	push	es		; 764
	push	si		; 765
	push	di		; 766
	lds	si,[bp+6h]		; 767
	les	di,[bp+0ah]		; 76a
	add	si,79c3h		; 76d
	mov	bx,17h		; 771
	mov	dx,45h		; 774
	cld		; 777
L0778:
	xor	cx,cx		; 778
L077A:
	inc	cx		; 77a
	lodsb		; 77b
	cmp	al,0h		; 77c
	jz	short L077A		; 77e
	mov	ax,cx		; 780
	stosb		; 782
	mov	cx,dx		; 783
	sub	cx,ax		; 785
	rep	movsb		; 787
	add	si,0fbh		; 789
	dec	bx		; 78d
	jnz	short L0778		; 78e
	pop	di		; 790
	pop	si		; 791
	pop	es		; 792
	pop	ds		; 793
	pop	dx		; 794
	pop	cx		; 795
	pop	bx		; 796
	pop	ax		; 797
	leave		; 798
	retf		; 799
_fn_19c9_075b	endp

_fn_19c9_079a	proc	far
	enter	0h,0h		; 79a
	push	ax		; 79e
	push	bx		; 79f
	push	cx		; 7a0
	push	dx		; 7a1
	push	ds		; 7a2
	push	es		; 7a3
	push	si		; 7a4
	push	di		; 7a5
	lds	si,[bp+6h]		; 7a6
	les	di,[bp+0ah]		; 7a9
	add	di,42c3h		; 7ac
	mov	bl,17h		; 7b0
	cld		; 7b2
L07B3:
	lodsb		; 7b3
	mov	dx,45h		; 7b4
	sub	dx,ax		; 7b7
	add	di,ax		; 7b9
	mov	cx,dx		; 7bb
	rep	movsb		; 7bd
	mov	cx,dx		; 7bf
	mov	bh,al		; 7c1
	dec	si		; 7c3
L07C4:
	std		; 7c4
	lodsb		; 7c5
	cld		; 7c6
	stosb		; 7c7
	loop	short L07C4		; 7c8
	mov	al,bh		; 7ca
	add	si,dx		; 7cc
	inc	si		; 7ce
	add	di,ax		; 7cf
	add	di,+26h		; 7d1
	dec	bl		; 7d4
	jnz	short L07B3		; 7d6
	pop	di		; 7d8
	pop	si		; 7d9
	pop	es		; 7da
	pop	ds		; 7db
	pop	dx		; 7dc
	pop	cx		; 7dd
	pop	bx		; 7de
	pop	ax		; 7df
	leave		; 7e0
	retf		; 7e1
_fn_19c9_079a	endp

_fn_19c9_07e2	proc	far
	enter	0h,0h		; 7e2
	push	ax		; 7e6
	push	bx		; 7e7
	push	cx		; 7e8
	push	dx		; 7e9
	push	ds		; 7ea
	push	es		; 7eb
	push	si		; 7ec
	push	di		; 7ed
	lds	si,[bp+6h]		; 7ee
	les	di,[bp+0ah]		; 7f1
	add	si,[bp+0eh]		; 7f4
	mov	ax,[bp+10h]		; 7f7
	mov	bx,0b0h		; 7fa
	mul	bl		; 7fd
	add	si,ax		; 7ff
	shl	word ptr [bp+0eh],1		; 801
	mov	ax,[bp+0eh]		; 804
	sub	bx,ax		; 807
	inc	ax		; 809
	xor	dx,dx		; 80a
	mov	ah,al		; 80c
	xor	al,al		; 80e
	div	bx		; 810
	inc	ah		; 812
	dec	bl		; 814
	mov	dh,bl		; 816
	mov	dl,ah		; 818
	mov	ah,al		; 81a
	xor	al,al		; 81c
	xor	cx,cx		; 81e
	ror	eax,10h		; 820
	ror	ebx,10h		; 824
	ror	ecx,10h		; 828
	ror	edx,10h		; 82c
	mov	cx,[bp+0eh]		; 830
	mov	bx,2eh		; 833
	mov	ax,[bp+10h]		; 836
	sub	bx,ax		; 839
	inc	ax		; 83b
	xor	dx,dx		; 83c
	mov	ah,al		; 83e
	xor	al,al		; 840
	div	bx		; 842
	inc	ah		; 844
	mov	dh,bl		; 846
	mov	dl,ah		; 848
	mov	ah,al		; 84a
	xor	al,al		; 84c
	xor	bx,bx		; 84e
	cld		; 850
	push	bp		; 851
L0852:
	ror	eax,10h		; 852
	ror	ebx,10h		; 856
	ror	ecx,10h		; 85a
	ror	edx,10h		; 85e
	xor	bp,bp		; 862
L0864:
	add	bp,ax		; 864
	adc	cl,dl		; 866
	lodsb		; 868
	rep	stosb		; 869
	dec	bl		; 86b
	jnz	short L0864		; 86d
	movsb		; 86f
	mov	bl,dh		; 870
	ror	eax,10h		; 872
	ror	ebx,10h		; 876
	ror	ecx,10h		; 87a
	ror	edx,10h		; 87e
	add	si,cx		; 882
	add	bx,ax		; 884
	jc	short L0897		; 886
	dec	dh		; 888
	jnz	short L0852		; 88a
	pop	bp		; 88c
	pop	di		; 88d
	pop	si		; 88e
	pop	es		; 88f
	pop	ds		; 890
	pop	dx		; 891
	pop	cx		; 892
	pop	bx		; 893
	pop	ax		; 894
	leave		; 895
	retf		; 896
L0897:
	sub	si,0b0h		; 897
	xor	bx,bx		; 89b
	jmp	short L0852		; 89d
_fn_19c9_07e2	endp

_fn_19c9_089f	proc	far
	enter	0h,0h		; 89f
	push	ax		; 8a3
	push	bx		; 8a4
	push	cx		; 8a5
	push	dx		; 8a6
	push	ds		; 8a7
	push	es		; 8a8
	push	si		; 8a9
	push	di		; 8aa
	lds	si,[bp+6h]		; 8ab
	les	di,[bp+0ah]		; 8ae
	add	si,[bp+0eh]		; 8b1
	add	si,1fa0h		; 8b4
	add	di,1fa0h		; 8b8
	mov	bx,0b0h		; 8bc
	shl	word ptr [bp+0eh],1		; 8bf
	mov	ax,[bp+0eh]		; 8c2
	sub	bx,ax		; 8c5
	inc	ax		; 8c7
	xor	dx,dx		; 8c8
	mov	ah,al		; 8ca
	xor	al,al		; 8cc
	div	bx		; 8ce
	inc	ah		; 8d0
	dec	bl		; 8d2
	mov	dh,bl		; 8d4
	mov	dl,ah		; 8d6
	mov	ah,al		; 8d8
	xor	al,al		; 8da
	xor	cx,cx		; 8dc
	ror	eax,10h		; 8de
	ror	ebx,10h		; 8e2
	ror	ecx,10h		; 8e6
	ror	edx,10h		; 8ea
	mov	cx,[bp+0eh]		; 8ee
	mov	bx,4ah		; 8f1
	mov	ax,[bp+10h]		; 8f4
	sub	bx,ax		; 8f7
	inc	ax		; 8f9
	xor	dx,dx		; 8fa
	mov	ah,al		; 8fc
	xor	al,al		; 8fe
	div	bx		; 900
	inc	ah		; 902
	mov	dh,bl		; 904
	mov	dl,ah		; 906
	mov	ah,al		; 908
	xor	al,al		; 90a
	xor	bx,bx		; 90c
	cld		; 90e
	push	bp		; 90f
L0910:
	ror	eax,10h		; 910
	ror	ebx,10h		; 914
	ror	ecx,10h		; 918
	ror	edx,10h		; 91c
	xor	bp,bp		; 920
L0922:
	add	bp,ax		; 922
	adc	cl,dl		; 924
	lodsb		; 926
	rep	stosb		; 927
	dec	bl		; 929
	jnz	short L0922		; 92b
	movsb		; 92d
	mov	bl,dh		; 92e
	ror	eax,10h		; 930
	ror	ebx,10h		; 934
	ror	ecx,10h		; 938
	ror	edx,10h		; 93c
	add	si,cx		; 940
	add	bx,ax		; 942
	jc	short L0955		; 944
	dec	dh		; 946
	jnz	short L0910		; 948
	pop	bp		; 94a
	pop	di		; 94b
	pop	si		; 94c
	pop	es		; 94d
	pop	ds		; 94e
	pop	dx		; 94f
	pop	cx		; 950
	pop	bx		; 951
	pop	ax		; 952
	leave		; 953
	retf		; 954
L0955:
	sub	si,0b0h		; 955
	xor	bx,bx		; 959
	jmp	short L0910		; 95b
_fn_19c9_089f	endp

_fn_19c9_095d	proc	far
	enter	0h,0h		; 95d
	push	ax		; 961
	push	cx		; 962
	push	ds		; 963
	push	es		; 964
	push	si		; 965
	push	di		; 966
	lds	si,[bp+6h]		; 967
	les	di,[bp+0ah]		; 96a
	add	di,+70h		; 96d
	mov	ax,78h		; 970
L0973:
	mov	cx,2ch		; 973
	rep	movsd		; 976
	add	di,90h		; 979
	dec	ax		; 97d
	jnz	short L0973		; 97e
	pop	di		; 980
	pop	si		; 981
	pop	es		; 982
	pop	ds		; 983
	pop	cx		; 984
	pop	ax		; 985
	leave		; 986
	retf		; 987
_fn_19c9_095d	endp

_fn_19c9_0988	proc	far
	enter	0h,0h		; 988
	push	cx		; 98c
	push	ds		; 98d
	push	es		; 98e
	push	si		; 98f
	push	di		; 990
	lds	si,[bp+6h]		; 991
	les	di,[bp+0ah]		; 994
	mov	cx,14a0h		; 997
	rep	movsd		; 99a
	pop	di		; 99d
	pop	si		; 99e
	pop	es		; 99f
	pop	ds		; 9a0
	pop	cx		; 9a1
	leave		; 9a2
	retf		; 9a3
_fn_19c9_0988	endp

_fn_19c9_09a4	proc	far
	enter	0h,0h		; 9a4
	push	ax		; 9a8
	push	cx		; 9a9
	push	ds		; 9aa
	push	es		; 9ab
	push	si		; 9ac
	push	di		; 9ad
	lds	si,[bp+6h]		; 9ae
	les	di,[bp+0ah]		; 9b1
	add	si,+70h		; 9b4
	mov	ax,78h		; 9b7
L09BA:
	mov	cx,2ch		; 9ba
	rep	movsd		; 9bd
	add	si,90h		; 9c0
	dec	ax		; 9c4
	jnz	short L09BA		; 9c5
	pop	di		; 9c7
	pop	si		; 9c8
	pop	es		; 9c9
	pop	ds		; 9ca
	pop	cx		; 9cb
	pop	ax		; 9cc
	leave		; 9cd
	retf		; 9ce
_fn_19c9_09a4	endp

_fn_19c9_09cf	proc	far
	enter	0h,0h		; 9cf
	push	ax		; 9d3
	push	cx		; 9d4
	push	ds		; 9d5
	push	es		; 9d6
	push	si		; 9d7
	push	di		; 9d8
	lds	si,[bp+6h]		; 9d9
	les	di,[bp+0ah]		; 9dc
	add	si,+70h		; 9df
	add	di,+70h		; 9e2
	mov	ax,78h		; 9e5
L09E8:
	mov	cx,2ch		; 9e8
	rep	movsd		; 9eb
	add	si,90h		; 9ee
	add	di,90h		; 9f2
	dec	ax		; 9f6
	jnz	short L09E8		; 9f7
	pop	di		; 9f9
	pop	si		; 9fa
	pop	es		; 9fb
	pop	ds		; 9fc
	pop	cx		; 9fd
	pop	ax		; 9fe
	leave		; 9ff
	retf		; a00
_fn_19c9_09cf	endp

_fn_19c9_0a01	proc	far
	enter	0h,0h		; a01
	push	ax		; a05
	push	bx		; a06
	push	cx		; a07
	push	ds		; a08
	push	es		; a09
	push	si		; a0a
	push	di		; a0b
	lds	si,[bp+6h]		; a0c
	les	di,[bp+0eh]		; a0f
	add	si,111h		; a12
	mov	bx,78h		; a16
L0A19:
	lodsb		; a19
	mov	ah,al		; a1a
	stosw		; a1c
	mov	cx,0eh		; a1d
L0A20:
	lodsb		; a20
	mov	ah,al		; a21
	stosw		; a23
	stosb		; a24
	loop	short L0A20		; a25
	add	si,131h		; a27
	add	di,84h		; a2b
	dec	bx		; a2f
	jnz	short L0A19		; a30
	lds	si,[bp+0ah]		; a32
	mov	di,[bp+0eh]		; a35
	add	si,+70h		; a38
	add	di,+2ch		; a3b
	mov	cx,21h		; a3e
	mov	bx,78h		; a41
L0A44:
	movsw		; a44
	lodsb		; a45
	mov	ah,al		; a46
	stosw		; a48
	loop	short L0A44		; a49
	mov	cx,21h		; a4b
	add	si,0ddh		; a4e
	add	di,+2ch		; a52
	dec	bx		; a55
	jnz	short L0A44		; a56
	pop	di		; a58
	pop	si		; a59
	pop	es		; a5a
	pop	ds		; a5b
	pop	cx		; a5c
	pop	bx		; a5d
	pop	ax		; a5e
	leave		; a5f
	retf		; a60
_fn_19c9_0a01	endp

_fn_19c9_0a61	proc	far
	enter	0h,0h		; a61
	push	ax		; a65
	push	bx		; a66
	push	cx		; a67
	push	dx		; a68
	push	ds		; a69
	push	es		; a6a
	push	si		; a6b
	push	di		; a6c
	lds	si,[bp+6h]		; a6d
	les	di,[bp+0eh]		; a70
	add	si,0f4h		; a73
	mov	cx,2ch		; a77
	mov	bx,78h		; a7a
	mov	dx,2h		; a7d
L0A80:
	lodsb		; a80
	mov	ah,al		; a81
	stosw		; a83
	loop	short L0A80		; a84
	add	si,114h		; a86
	add	di,+58h		; a8a
	mov	cx,2ch		; a8d
	dec	bx		; a90
	jnz	short L0A80		; a91
	dec	dx		; a93
	jnz	short L0AA0		; a94
	pop	di		; a96
	pop	si		; a97
	pop	es		; a98
	pop	ds		; a99
	pop	dx		; a9a
	pop	cx		; a9b
	pop	bx		; a9c
	pop	ax		; a9d
	leave		; a9e
	retf		; a9f
L0AA0:
	lds	si,[bp+0ah]		; aa0
	mov	di,[bp+0eh]		; aa3
	add	si,+70h		; aa6
	add	di,+58h		; aa9
	mov	bx,78h		; aac
	jmp	short L0A80		; aaf
_fn_19c9_0a61	endp

_fn_19c9_0ab1	proc	far
	enter	0h,0h		; ab1
	push	ax		; ab5
	push	bx		; ab6
	push	cx		; ab7
	push	ds		; ab8
	push	es		; ab9
	push	si		; aba
	push	di		; abb
	lds	si,[bp+6h]		; abc
	les	di,[bp+0eh]		; abf
	add	si,0bdh		; ac2
	mov	cx,21h		; ac6
	mov	bx,78h		; ac9
L0ACC:
	movsw		; acc
	lodsb		; acd
	mov	ah,al		; ace
	stosw		; ad0
	loop	short L0ACC		; ad1
	mov	cx,21h		; ad3
	add	si,0ddh		; ad6
	add	di,+2ch		; ada
	dec	bx		; add
	jnz	short L0ACC		; ade
	lds	si,[bp+0ah]		; ae0
	mov	di,[bp+0eh]		; ae3
	add	si,+70h		; ae6
	add	di,84h		; ae9
	mov	cx,0eh		; aed
	mov	bx,78h		; af0
L0AF3:
	lodsb		; af3
	mov	ah,al		; af4
	stosw		; af6
	stosb		; af7
	loop	short L0AF3		; af8
	lodsb		; afa
	mov	ah,al		; afb
	stosw		; afd
	mov	cx,0eh		; afe
	add	si,131h		; b01
	add	di,84h		; b05
	dec	bx		; b09
	jnz	short L0AF3		; b0a
	pop	di		; b0c
	pop	si		; b0d
	pop	es		; b0e
	pop	ds		; b0f
	pop	cx		; b10
	pop	bx		; b11
	pop	ax		; b12
	leave		; b13
	retf		; b14
_fn_19c9_0ab1	endp

_fn_19c9_0b15	proc	far
	enter	0h,0h		; b15
	push	ax		; b19
	push	bx		; b1a
	push	cx		; b1b
	push	dx		; b1c
	push	ds		; b1d
	push	es		; b1e
	push	si		; b1f
	push	di		; b20
	lds	si,[bp+6h]		; b21
	les	di,[bp+0ch]		; b24
	add	si,+70h		; b27
	add	di,+70h		; b2a
	add	si,[bp+0ah]		; b2d
	add	di,[bp+10h]		; b30
	mov	ax,[bp+12h]		; b33
	mov	bx,78h		; b36
	mov	dx,140h		; b39
	sub	dx,ax		; b3c
	sub	dx,ax		; b3e
L0B40:
	mov	cx,ax		; b40
	rep	movsw		; b42
	add	si,dx		; b44
	add	di,dx		; b46
	dec	bx		; b48
	jnz	short L0B40		; b49
	pop	di		; b4b
	pop	si		; b4c
	pop	es		; b4d
	pop	ds		; b4e
	pop	dx		; b4f
	pop	cx		; b50
	pop	bx		; b51
	pop	ax		; b52
	leave		; b53
	retf		; b54
_fn_19c9_0b15	endp

_fn_19c9_0b55	proc	far
	enter	0h,0h		; b55
	push	ax		; b59
	push	bx		; b5a
	push	cx		; b5b
	push	dx		; b5c
	push	ds		; b5d
	push	es		; b5e
	push	si		; b5f
	push	di		; b60
	lds	si,[bp+6h]		; b61
	les	di,[bp+6h]		; b64
	add	si,+70h		; b67
	add	si,[bp+0ah]		; b6a
	mov	dx,[bp+0ah]		; b6d
	mov	ax,[bp+0eh]		; b70
	shl	ax,1		; b73
	add	dx,ax		; b75
	sub	dx,[bp+0ch]		; b77
	mov	bx,140h		; b7a
	add	bx,dx		; b7d
	sub	bx,ax		; b7f
	sub	bx,ax		; b81
	ror	edx,10h		; b83
	mov	dx,140h		; b87
	sub	dx,ax		; b8a
	ror	ebx,10h		; b8c
	mov	bx,78h		; b90
L0B93:
	ror	edx,10h		; b93
	ror	ebx,10h		; b97
	mov	cx,[bp+0eh]		; b9b
	rep	movsw		; b9e
	xchg	si,di		; ba0
	sub	si,ax		; ba2
	sub	di,dx		; ba4
	mov	cx,[bp+0eh]		; ba6
	rep	movsw		; ba9
	ror	edx,10h		; bab
	xchg	si,di		; baf
	add	si,bx		; bb1
	add	di,dx		; bb3
	ror	ebx,10h		; bb5
	dec	bx		; bb9
	jnz	short L0B93		; bba
	pop	di		; bbc
	pop	si		; bbd
	pop	es		; bbe
	pop	ds		; bbf
	pop	dx		; bc0
	pop	cx		; bc1
	pop	bx		; bc2
	pop	ax		; bc3
	leave		; bc4
	retf		; bc5
_fn_19c9_0b55	endp

_fn_19c9_0bc6	proc	far
	enter	0h,0h		; bc6
	push	bx		; bca
	push	cx		; bcb
	push	dx		; bcc
	push	ds		; bcd
	push	es		; bce
	push	di		; bcf
	push	si		; bd0
	push	fs		; bd1
	cld		; bd3
	push	+0h		; bd4
	call	far ptr _fn_215f_001d		; bd6
	add	sp,+2h		; bdb
	mov	fs,dx		; bde
	push	word ptr [bp+6h]		; be0
	call	far ptr _fn_215f_001d		; be3
	add	sp,+2h		; be8
	push	dx		; beb
	les	di,[bp+8h]		; bec
	pop	ds		; bef
	mov	si,70h		; bf0
	mov	cx,78h		; bf3
L0BF6:
	push	cx		; bf6
	mov	cx,2ch		; bf7
L0BFA:
	repe	cmpsd		; bfa
	jz	short L0C12		; bfd
	mov	eax,[si-4h]		; bff
	mov	fs:[si-4h],eax		; c03
	mov	es:[di-4h],eax		; c08
	cmp	cx,+0h		; c0d
	jnz	short L0BFA		; c10
L0C12:
	add	si,90h		; c12
	pop	cx		; c16
	loop	short L0BF6		; c17
	pop	fs		; c19
	pop	si		; c1b
	pop	di		; c1c
	pop	es		; c1d
	pop	ds		; c1e
	pop	dx		; c1f
	pop	cx		; c20
	pop	bx		; c21
	leave		; c22
	retf		; c23
_fn_19c9_0bc6	endp

_fn_19c9_0c24	proc	far
	enter	0h,0h		; c24
	push	bx		; c28
	push	cx		; c29
	push	dx		; c2a
	push	ds		; c2b
	push	es		; c2c
	push	di		; c2d
	push	si		; c2e
	push	fs		; c2f
	push	+0h		; c31
	call	far ptr _fn_215f_001d		; c33
	add	sp,+2h		; c38
	mov	fs,dx		; c3b
	push	word ptr [bp+8h]		; c3d
	call	far ptr _fn_215f_001d		; c40
	add	sp,+2h		; c45
	push	dx		; c48
	push	word ptr [bp+6h]		; c49
	call	far ptr _fn_215f_001d		; c4c
	add	sp,+2h		; c51
	mov	ds,dx		; c54
	pop	es		; c56
	mov	si,70h		; c57
	mov	di,si		; c5a
	cld		; c5c
	mov	cx,78h		; c5d
L0C60:
	push	cx		; c60
	mov	cx,2ch		; c61
L0C64:
	repe	cmpsd		; c64
	jz	short L0C7A		; c67
	sub	di,+4h		; c69
	mov	eax,[di]		; c6c
	mov	fs:[di],eax		; c6f
	mov	di,si		; c73
	cmp	cx,+0h		; c75
	jnz	short L0C64		; c78
L0C7A:
	add	si,90h		; c7a
	mov	di,si		; c7e
	pop	cx		; c80
	loop	short L0C60		; c81
	pop	fs		; c83
	pop	si		; c85
	pop	di		; c86
	pop	es		; c87
	pop	ds		; c88
	pop	dx		; c89
	pop	cx		; c8a
	pop	bx		; c8b
	leave		; c8c
	retf		; c8d
_fn_19c9_0c24	endp

_fn_19c9_0c8e	proc	far
	enter	0h,0h		; c8e
	push	bx		; c92
	push	cx		; c93
	push	dx		; c94
	push	ds		; c95
	push	es		; c96
	push	di		; c97
	push	si		; c98
	push	fs		; c99
	push	+0h		; c9b
	call	far ptr _fn_215f_001d		; c9d
	add	sp,+2h		; ca2
	mov	fs,dx		; ca5
	push	word ptr [bp+8h]		; ca7
	call	far ptr _fn_215f_001d		; caa
	add	sp,+2h		; caf
	push	dx		; cb2
	push	word ptr [bp+6h]		; cb3
	call	far ptr _fn_215f_001d		; cb6
	add	sp,+2h		; cbb
	mov	ds,dx		; cbe
	pop	es		; cc0
	mov	si,0h		; cc1
	mov	di,si		; cc4
	cld		; cc6
	mov	cx,0c8h		; cc7
L0CCA:
	push	cx		; cca
	mov	cx,50h		; ccb
L0CCE:
	repe	cmpsd		; cce
	jz	short L0CE4		; cd1
	sub	di,+4h		; cd3
	mov	eax,[di]		; cd6
	mov	fs:[di],eax		; cd9
	mov	di,si		; cdd
	cmp	cx,+0h		; cdf
	jnz	short L0CCE		; ce2
L0CE4:
	add	si,+0h		; ce4
	mov	di,si		; ce7
	pop	cx		; ce9
	loop	short L0CCA		; cea
	pop	fs		; cec
	pop	si		; cee
	pop	di		; cef
	pop	es		; cf0
	pop	ds		; cf1
	pop	dx		; cf2
	pop	cx		; cf3
	pop	bx		; cf4
	leave		; cf5
	retf		; cf6
L0CF7:
	mov	cs:[2h],dx		; cf7
	mov	cs:[6h],cx		; cfc
	mov	cs:[0h],ax		; d01
	mov	cs:[4h],bx		; d05
	mov	word ptr cs:[8h],0h		; d0a
	mov	word ptr cs:[0ah],0h		; d11
	mov	cs:[0ch],dx		; d18
	mov	word ptr cs:[0eh],0h		; d1d
	mov	ax,cs:[2h]		; d24
	mov	bx,cs:[0h]		; d28
	mov	cx,bx		; d2d
	add	cx,ax		; d2f
	js	short L0DB0		; d31
	jz	short L0DB0		; d33
	cmp	cx,bx		; d35
	ja	short L0D4B		; d37
	sub	ax,cx		; d39
	mov	cs:[8h],ax		; d3b
	mov	cs:[2h],cx		; d3f
	mov	word ptr cs:[0h],0h		; d44
L0D4B:
	mov	dx,cs:[10h]		; d4b
	sub	dx,cs:[0h]		; d50
	js	short L0DB0		; d55
	jz	short L0DB0		; d57
	cmp	dx,cs:[2h]		; d59
	ja	short L0D65		; d5e
	mov	cs:[2h],dx		; d60
L0D65:
	mov	ax,cs:[2h]		; d65
	sub	cs:[0ch],ax		; d69
	mov	ax,cs:[6h]		; d6e
	mov	bx,cs:[4h]		; d72
	mov	cx,bx		; d77
	add	cx,ax		; d79
	js	short L0DB0		; d7b
	jz	short L0DB0		; d7d
	cmp	cx,bx		; d7f
	ja	short L0D95		; d81
	sub	ax,cx		; d83
	mov	cs:[0ah],ax		; d85
	mov	cs:[6h],cx		; d89
	mov	word ptr cs:[4h],0h		; d8e
L0D95:
	mov	dx,cs:[12h]		; d95
	sub	dx,cs:[4h]		; d9a
	js	short L0DB0		; d9f
	jz	short L0DB0		; da1
	cmp	dx,cs:[6h]		; da3
	ja	short L0DAF		; da8
	mov	cs:[6h],dx		; daa
L0DAF:
	retn		; daf
L0DB0:
	mov	word ptr cs:[2h],0ffffh		; db0
	mov	word ptr cs:[6h],0ffffh		; db7
	retn		; dbe
_fn_19c9_0c8e	endp

_fn_19c9_0dbf	proc	far
	enter	34h,0h		; dbf
	push	bx		; dc3
	push	cx		; dc4
	push	dx		; dc5
	push	ds		; dc6
	push	es		; dc7
	push	di		; dc8
	push	si		; dc9
	cmp	word ptr [bp+16h],+0h		; dca
	jz	short L0DD6		; dce
	cmp	word ptr [bp+18h],+0h		; dd0
	jnz	short L0DD9		; dd4
L0DD6:
	jmp	near ptr L0FED		; dd6
L0DD9:
	cmp	word ptr [bp+1ah],+2h		; dd9
	jnz	short L0DFA		; ddd
	mov	di,2h		; ddf
	les	ax,[bp+di+1ah]		; de2
	mov	[bp-4h],ax		; de5
	mov	[bp-2h],es		; de8
	add	di,+4h		; deb
	les	ax,[bp+di+1ah]		; dee
	mov	[bp-8h],ax		; df1
	mov	[bp-6h],es		; df4
	add	di,+4h		; df7
L0DFA:
	push	ds		; dfa
	push	si		; dfb
	lds	si,[bp+6h]		; dfc
	mov	word ptr cs:[14h],0h		; dff
	mov	word ptr cs:[16h],0h		; e06
	mov	cx,[si]		; e0d
	mov	cs:[10h],cx		; e0f
	mov	[bp-1ah],cx		; e14
	mov	cx,[si+2h]		; e17
	mov	cs:[12h],cx		; e1a
	mov	cx,[si+4h]		; e1f
	mov	[bp-1eh],cx		; e22
	mov	cx,[si+6h]		; e25
	mov	[bp-1ch],cx		; e28
	pop	si		; e2b
	pop	ds		; e2c
	mov	ax,[bp+0ah]		; e2d
	mov	bx,[bp+0ch]		; e30
	mov	dx,[bp+16h]		; e33
	mov	cx,[bp+18h]		; e36
	call	near ptr L0CF7		; e39
	cmp	word ptr cs:[2h],-1h		; e3c
	jz	short L0DD6		; e42
	mov	cx,cs:[8h]		; e44
	mov	[bp-0ah],cx		; e49
	mov	cx,cs:[0ah]		; e4c
	mov	[bp-0ch],cx		; e51
	mov	cx,cs:[0ch]		; e54
	mov	[bp-12h],cx		; e59
	mov	cx,cs:[0eh]		; e5c
	mov	[bp-14h],cx		; e61
	mov	cx,cs:[2h]		; e64
	mov	[bp-0eh],cx		; e69
	mov	cx,cs:[6h]		; e6c
	mov	[bp-10h],cx		; e71
	mov	cx,cs:[0h]		; e74
	mov	[bp-16h],cx		; e79
	mov	cx,cs:[4h]		; e7c
	mov	[bp-18h],cx		; e81
	push	ds		; e84
	push	si		; e85
	lds	si,[bp+0eh]		; e86
	mov	word ptr cs:[14h],0h		; e89
	mov	word ptr cs:[16h],0h		; e90
	mov	cx,[si]		; e97
	mov	cs:[10h],cx		; e99
	mov	[bp-30h],cx		; e9e
	mov	cx,[si+2h]		; ea1
	mov	cs:[12h],cx		; ea4
	mov	cx,[si+4h]		; ea9
	mov	[bp-34h],cx		; eac
	mov	cx,[si+6h]		; eaf
	mov	[bp-32h],cx		; eb2
	pop	si		; eb5
	pop	ds		; eb6
	mov	ax,[bp+12h]		; eb7
	mov	bx,[bp+14h]		; eba
	mov	dx,[bp-0eh]		; ebd
	mov	cx,[bp-10h]		; ec0
	call	near ptr L0CF7		; ec3
	cmp	word ptr cs:[2h],-1h		; ec6
	jnz	short L0ED1		; ecc
	jmp	near ptr L0FED		; ece
L0ED1:
	mov	cx,cs:[8h]		; ed1
	mov	[bp-20h],cx		; ed6
	mov	cx,cs:[0ah]		; ed9
	mov	[bp-22h],cx		; ede
	mov	cx,cs:[0ch]		; ee1
	mov	[bp-28h],cx		; ee6
	mov	cx,cs:[0eh]		; ee9
	mov	[bp-2ah],cx		; eee
	mov	cx,cs:[2h]		; ef1
	mov	[bp-24h],cx		; ef6
	mov	cx,cs:[6h]		; ef9
	mov	[bp-26h],cx		; efe
	mov	cx,cs:[0h]		; f01
	mov	[bp-2ch],cx		; f06
	mov	cx,cs:[4h]		; f09
	mov	[bp-2eh],cx		; f0e
	les	di,[bp-34h]		; f11
	lds	si,[bp-1eh]		; f14
	mov	ax,[bp-30h]		; f17
	mov	bx,[bp-2eh]		; f1a
	add	bx,[bp-0ch]		; f1d
	mul	bx		; f20
	add	di,ax		; f22
	push	es		; f24
	push	di		; f25
	call	far ptr _fn_2279_02b5		; f26
	add	sp,+4h		; f2b
	mov	es,dx		; f2e
	mov	di,ax		; f30
	mov	ax,[bp-1ah]		; f32
	mov	bx,[bp-18h]		; f35
	add	bx,[bp-22h]		; f38
	mul	bx		; f3b
	add	si,ax		; f3d
	push	ds		; f3f
	push	si		; f40
	call	far ptr _fn_2279_02b5		; f41
	add	sp,+4h		; f46
	mov	ds,dx		; f49
	mov	si,ax		; f4b
	mov	dx,[bp-24h]		; f4d
	mov	cx,[bp-26h]		; f50
L0F53:
	push	di		; f53
	push	si		; f54
	add	si,[bp-20h]		; f55
	add	si,[bp-16h]		; f58
	add	di,[bp-0ah]		; f5b
	add	di,[bp-2ch]		; f5e
	push	cx		; f61
	cmp	word ptr [bp+1ah],+0h		; f62
	jnz	short L0F74		; f66
	mov	cx,dx		; f68
	shr	cx,1		; f6a
	rep	movsw		; f6c
	adc	cx,cx		; f6e
	rep	movsb		; f70
	jmp	short L0FDA		; f72
L0F74:
	cmp	word ptr [bp+1ah],+1h		; f74
	jnz	short L0F99		; f78
	and	cl,1h		; f7a
	jz	short L0F8C		; f7d
	mov	cx,dx		; f7f
L0F81:
	movsb		; f81
	loop	short L0F86		; f82
	jmp	short L0FDA		; f84
L0F86:
	inc	si		; f86
	inc	di		; f87
	loop	short L0F81		; f88
	jmp	short L0FDA		; f8a
L0F8C:
	mov	cx,dx		; f8c
L0F8E:
	inc	si		; f8e
	inc	di		; f8f
	loop	short L0F94		; f90
	jmp	short L0FDA		; f92
L0F94:
	movsb		; f94
	loop	short L0F8E		; f95
	jmp	short L0FDA		; f97
L0F99:
	cmp	word ptr [bp+1ah],+2h		; f99
	jnz	short L0FC2		; f9d
	mov	cx,dx		; f9f
L0FA1:
	lodsb		; fa1
	push	ax		; fa2
	push	ds		; fa3
	lds	bx,[bp-4h]		; fa4
	mov	ah,al		; fa7
	xlatb		; fa9
	xchg	ah,al		; faa
	or	ah,ah		; fac
	js	short L0FB9		; fae
	mov	al,es:[di]		; fb0
	lds	bx,[bp-8h]		; fb3
	add	bh,ah		; fb6
	xlatb		; fb8
L0FB9:
	pop	ds		; fb9
	pop	bx		; fba
	mov	ah,bh		; fbb
	stosb		; fbd
	loop	short L0FA1		; fbe
	jmp	short L0FDA		; fc0
L0FC2:
	cmp	word ptr [bp+1ah],+3h		; fc2
	jnz	short L0FDA		; fc6
	sub	si,[bp-20h]		; fc8
	add	si,[bp-0eh]		; fcb
	sub	si,[bp-20h]		; fce
	dec	si		; fd1
	mov	cx,dx		; fd2
L0FD4:
	movsb		; fd4
	sub	si,+2h		; fd5
	loop	short L0FD4		; fd8
L0FDA:
	pop	cx		; fda
	pop	si		; fdb
	pop	di		; fdc
	add	di,[bp-30h]		; fdd
	add	si,[bp-1ah]		; fe0
	sub	cx,+1h		; fe3
	or	cx,cx		; fe6
	jz	short L0FED		; fe8
	jmp	near ptr L0F53		; fea
L0FED:
	pop	si		; fed
	pop	di		; fee
	pop	es		; fef
	pop	ds		; ff0
	pop	dx		; ff1
	pop	cx		; ff2
	pop	bx		; ff3
	leave		; ff4
	retf		; ff5
_fn_19c9_0dbf	endp

_fn_19c9_0ff6	proc	far
	enter	0h,0h		; ff6
	push	bx		; ffa
	push	cx		; ffb
	push	dx		; ffc
	push	ds		; ffd
	push	es		; ffe
	push	di		; fff
	push	si		; 1000
	cmp	word ptr [bp+12h],+0h		; 1001
	jz	short L100D		; 1005
	cmp	word ptr [bp+14h],+0h		; 1007
	jnz	short L1010		; 100b
L100D:
	jmp	near ptr L10F7		; 100d
L1010:
	push	ds		; 1010
	push	si		; 1011
	lds	si,[bp+18h]		; 1012
	les	di,cs:[42ch]		; 1015
	mov	cx,80h		; 101a
	rep	movsw		; 101d
	pop	si		; 101f
	pop	ds		; 1020
	mov	ax,DGROUP		; 1021
	mov	es,ax		; 1024
	mov	di,1f3bh		; 1026
	mov	ax,[bp+16h]		; 1029
	add	ax,ax		; 102c
	add	ax,ax		; 102e
	add	ax,ax		; 1030
	add	ax,ax		; 1032
	add	di,ax		; 1034
	mov	ax,es:[di+4h]		; 1036
	add	ax,ax		; 103a
	add	ax,ax		; 103c
	add	ax,ax		; 103e
	mov	cs:[10h],ax		; 1040
	mov	ax,es:[di+6h]		; 1044
	mov	cs:[12h],ax		; 1048
	mov	ax,es:[di]		; 104c
	add	ax,ax		; 104f
	add	ax,ax		; 1051
	add	ax,ax		; 1053
	mov	cs:[14h],ax		; 1055
	mov	ax,es:[di+2h]		; 1059
	mov	cs:[16h],ax		; 105d
	mov	ax,[bp+0eh]		; 1061
	mov	bx,[bp+10h]		; 1064
	mov	dx,[bp+12h]		; 1067
	mov	cx,[bp+14h]		; 106a
	call	near ptr L0CF7		; 106d
	cmp	word ptr cs:[2h],-1h		; 1070
	jz	short L100D		; 1076
	push	word ptr [bp+0ch]		; 1078
	call	far ptr _fn_215f_001d		; 107b
	add	sp,+2h		; 1080
	mov	es,dx		; 1083
	push	word ptr [bp+6h]		; 1085
	call	far ptr _fn_215f_001d		; 1088
	add	sp,+2h		; 108d
	mov	ds,dx		; 1090
	mov	ax,[bp+0ah]		; 1092
	mov	bx,14h		; 1095
	mul	bx		; 1098
	mov	cx,ds		; 109a
	add	cx,ax		; 109c
	mov	ds,cx		; 109e
	mov	ax,cs:[4h]		; 10a0
	add	ax,cs:[16h]		; 10a4
	mov	bx,14h		; 10a9
	mul	bx		; 10ac
	mov	cx,es		; 10ae
	add	cx,ax		; 10b0
	mov	es,cx		; 10b2
	cld		; 10b4
	mov	si,[bp+8h]		; 10b5
	mov	dx,cs:[2h]		; 10b8
	mov	cx,cs:[6h]		; 10bd
L10C2:
	push	si		; 10c2
	add	si,cs:[8h]		; 10c3
	mov	di,cs:[0h]		; 10c8
	add	di,cs:[14h]		; 10cd
	push	cx		; 10d2
	mov	bx,430h		; 10d3
	mov	cx,dx		; 10d6
L10D8:
	lodsb		; 10d8
	xlat	byte ptr cs:[bx]		; 10d9
	or	al,al		; 10db
	jz	short L10E2		; 10dd
	mov	es:[di],al		; 10df
L10E2:
	inc	di		; 10e2
	loop	short L10D8		; 10e3
	pop	cx		; 10e5
	pop	si		; 10e6
	mov	bx,es		; 10e7
	add	bx,+14h		; 10e9
	mov	es,bx		; 10ec
	mov	bx,ds		; 10ee
	add	bx,+14h		; 10f0
	mov	ds,bx		; 10f3
	loop	short L10C2		; 10f5
L10F7:
	pop	si		; 10f7
	pop	di		; 10f8
	pop	es		; 10f9
	pop	ds		; 10fa
	pop	dx		; 10fb
	pop	cx		; 10fc
	pop	bx		; 10fd
	leave		; 10fe
	retf		; 10ff
_fn_19c9_0ff6	endp

_fn_19c9_1100	proc	far
	enter	0h,0h		; 1100
	push	bx		; 1104
	push	cx		; 1105
	push	dx		; 1106
	push	ds		; 1107
	push	es		; 1108
	push	di		; 1109
	push	si		; 110a
	cmp	word ptr [bp+12h],+0h		; 110b
	jz	short L1117		; 110f
	cmp	word ptr [bp+14h],+0h		; 1111
	jnz	short L111A		; 1115
L1117:
	jmp	near ptr L1212		; 1117
L111A:
	push	ds		; 111a
	push	si		; 111b
	lds	si,[bp+1ah]		; 111c
	les	di,cs:[42ch]		; 111f
	mov	cx,80h		; 1124
	rep	movsw		; 1127
	pop	si		; 1129
	pop	ds		; 112a
	mov	ax,DGROUP		; 112b
	mov	es,ax		; 112e
	mov	di,1f3bh		; 1130
	mov	ax,[bp+16h]		; 1133
	add	ax,ax		; 1136
	add	ax,ax		; 1138
	add	ax,ax		; 113a
	add	ax,ax		; 113c
	add	di,ax		; 113e
	mov	ax,es:[di+4h]		; 1140
	add	ax,ax		; 1144
	add	ax,ax		; 1146
	add	ax,ax		; 1148
	mov	cs:[10h],ax		; 114a
	mov	ax,es:[di+6h]		; 114e
	mov	cs:[12h],ax		; 1152
	mov	ax,es:[di]		; 1156
	add	ax,ax		; 1159
	add	ax,ax		; 115b
	add	ax,ax		; 115d
	mov	cs:[14h],ax		; 115f
	mov	ax,es:[di+2h]		; 1163
	mov	cs:[16h],ax		; 1167
	mov	ax,[bp+0eh]		; 116b
	mov	bx,[bp+10h]		; 116e
	mov	dx,[bp+12h]		; 1171
	mov	cx,[bp+14h]		; 1174
	call	near ptr L0CF7		; 1177
	cmp	word ptr cs:[2h],-1h		; 117a
	jz	short L1117		; 1180
	push	word ptr [bp+0ch]		; 1182
	call	far ptr _fn_215f_001d		; 1185
	add	sp,+2h		; 118a
	mov	es,dx		; 118d
	push	word ptr [bp+6h]		; 118f
	call	far ptr _fn_215f_001d		; 1192
	add	sp,+2h		; 1197
	mov	ds,dx		; 119a
	mov	ax,[bp+0ah]		; 119c
	mov	bx,14h		; 119f
	mul	bx		; 11a2
	mov	cx,ds		; 11a4
	add	cx,ax		; 11a6
	mov	ds,cx		; 11a8
	mov	ax,cs:[4h]		; 11aa
	add	ax,cs:[16h]		; 11ae
	mov	bx,14h		; 11b3
	mul	bx		; 11b6
	mov	cx,es		; 11b8
	add	cx,ax		; 11ba
	mov	es,cx		; 11bc
	cld		; 11be
	mov	si,[bp+8h]		; 11bf
	mov	dx,cs:[2h]		; 11c2
	mov	cx,cs:[6h]		; 11c7
L11CC:
	push	si		; 11cc
	add	si,cs:[8h]		; 11cd
	mov	di,cs:[0h]		; 11d2
	add	di,cs:[14h]		; 11d7
	mov	ax,[bp+18h]		; 11dc
	cmp	ax,1h		; 11df
	jnz	short L11EA		; 11e2
	mov	ax,cx		; 11e4
	shr	ax,1		; 11e6
	add	di,ax		; 11e8
L11EA:
	push	cx		; 11ea
	mov	bx,430h		; 11eb
	mov	cx,dx		; 11ee
L11F0:
	lodsb		; 11f0
	or	al,al		; 11f1
	jz	short L11FD		; 11f3
	mov	al,es:[di]		; 11f5
	xlat	byte ptr cs:[bx]		; 11f8
	mov	es:[di],al		; 11fa
L11FD:
	inc	di		; 11fd
	loop	short L11F0		; 11fe
	pop	cx		; 1200
	pop	si		; 1201
	mov	bx,es		; 1202
	add	bx,+14h		; 1204
	mov	es,bx		; 1207
	mov	bx,ds		; 1209
	add	bx,+14h		; 120b
	mov	ds,bx		; 120e
	loop	short L11CC		; 1210
L1212:
	pop	si		; 1212
	pop	di		; 1213
	pop	es		; 1214
	pop	ds		; 1215
	pop	dx		; 1216
	pop	cx		; 1217
	pop	bx		; 1218
	leave		; 1219
	retf		; 121a
_fn_19c9_1100	endp

_fn_19c9_121b	proc	far
	enter	0h,0h		; 121b
	push	bx		; 121f
	push	cx		; 1220
	push	dx		; 1221
	push	ds		; 1222
	push	es		; 1223
	push	di		; 1224
	push	si		; 1225
	lds	si,cs:[428h]		; 1226
	mov	ax,[bp+6h]		; 122b
	xor	ah,ah		; 122e
	add	ax,ax		; 1230
	mov	bx,ax		; 1232
	mov	ax,[bx+si]		; 1234
	pop	si		; 1236
	pop	di		; 1237
	pop	es		; 1238
	pop	ds		; 1239
	pop	dx		; 123a
	pop	cx		; 123b
	pop	bx		; 123c
	leave		; 123d
	retf		; 123e
_fn_19c9_121b	endp

_fn_19c9_123f	proc	far
	enter	0h,0h		; 123f
	push	bx		; 1243
	push	cx		; 1244
	push	dx		; 1245
	push	ds		; 1246
	push	es		; 1247
	push	di		; 1248
	push	si		; 1249
	lds	si,cs:[428h]		; 124a
	mov	ax,[bp+6h]		; 124f
	add	al,40h		; 1252
	xor	ah,ah		; 1254
	add	ax,ax		; 1256
	mov	bx,ax		; 1258
	mov	ax,[bx+si]		; 125a
	pop	si		; 125c
	pop	di		; 125d
	pop	es		; 125e
	pop	ds		; 125f
	pop	dx		; 1260
	pop	cx		; 1261
	pop	bx		; 1262
	leave		; 1263
	retf		; 1264
_fn_19c9_123f	endp

_fn_19c9_1265	proc	far
	enter	0h,0h		; 1265
	push	bx		; 1269
	push	cx		; 126a
	push	dx		; 126b
	push	ds		; 126c
	push	es		; 126d
	push	di		; 126e
	push	si		; 126f
	lds	si,[bp+6h]		; 1270
	les	di,[bp+0ah]		; 1273
	lodsb		; 1276
	sub	al,es:[di]		; 1277
	inc	di		; 127a
	mov	bl,al		; 127b
	imul	bl		; 127d
	mov	cx,ax		; 127f
	lodsb		; 1281
	sub	al,es:[di]		; 1282
	inc	di		; 1285
	mov	bl,al		; 1286
	imul	bl		; 1288
	add	cx,ax		; 128a
	lodsb		; 128c
	sub	al,es:[di]		; 128d
	inc	di		; 1290
	mov	bl,al		; 1291
	imul	bl		; 1293
	add	cx,ax		; 1295
	mov	ax,cx		; 1297
	pop	si		; 1299
	pop	di		; 129a
	pop	es		; 129b
	pop	ds		; 129c
	pop	dx		; 129d
	pop	cx		; 129e
	pop	bx		; 129f
	leave		; 12a0
	retf		; 12a1
_fn_19c9_1265	endp

_fn_19c9_12a2	proc	far
	enter	4h,0h		; 12a2
	push	bx		; 12a6
	push	cx		; 12a7
	push	dx		; 12a8
	push	ds		; 12a9
	push	es		; 12aa
	push	di		; 12ab
	push	si		; 12ac
	mov	word ptr [bp-2h],7fffh		; 12ad
	mov	word ptr [bp-4h],101h		; 12b2
	lds	si,[bp+6h]		; 12b7
	les	di,[bp+0ah]		; 12ba
	mov	cx,0h		; 12bd
L12C0:
	and	word ptr [bp+10h],0ffh		; 12c0
	jz	short L12D5		; 12c5
	cmp	cx,0c0h		; 12c7
	jc	short L12D5		; 12cb
	cmp	cx,0c3h		; 12cd
	ja	short L12D5		; 12d1
	jmp	short L12FB		; 12d3
L12D5:
	lodsb		; 12d5
	sub	al,es:[di]		; 12d6
	inc	di		; 12d9
	imul	al		; 12da
	mov	dx,ax		; 12dc
	lodsb		; 12de
	sub	al,es:[di]		; 12df
	inc	di		; 12e2
	imul	al		; 12e3
	add	dx,ax		; 12e5
	lodsb		; 12e7
	sub	al,es:[di]		; 12e8
	inc	di		; 12eb
	imul	al		; 12ec
	add	dx,ax		; 12ee
	cmp	dx,[bp-2h]		; 12f0
	ja	short L12FB		; 12f3
	mov	[bp-2h],dx		; 12f5
	mov	[bp-4h],cx		; 12f8
L12FB:
	sub	si,+3h		; 12fb
	inc	cx		; 12fe
	cmp	cx,[bp+0eh]		; 12ff
	jc	short L12C0		; 1302
	mov	ax,[bp-4h]		; 1304
	pop	si		; 1307
	pop	di		; 1308
	pop	es		; 1309
	pop	ds		; 130a
	pop	dx		; 130b
	pop	cx		; 130c
	pop	bx		; 130d
	leave		; 130e
	retf		; 130f
_fn_19c9_12a2	endp
S038_TEXT	ends
	end
