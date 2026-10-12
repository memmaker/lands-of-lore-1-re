; s042: segment 1b43 (TASM module)
	.386
S042_TEXT	segment word public use16 'CODE'
S042_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:S042_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends
S042_TEXT	segment
	public	_fn_1b43_000e, _fn_1b43_0109
_fn_1b43_000e	proc	far
	enter	10h,0h		; e
	push	bx		; 12
	push	cx		; 13
	push	es		; 14
	push	di		; 15
	push	ds		; 16
	push	si		; 17
	cld		; 18
	cmp	dword ptr [bp+6h],+0h		; 19
	jz	near ptr L00FA		; 1e
	cmp	dword ptr [bp+0ah],+0h		; 22
	jz	near ptr L00FA		; 27
	mov	ax,[bp+10h]		; 2b
	cmp	ax,100h		; 2e
	jc	short L0038		; 31
	mov	word ptr [bp+10h],0ffh		; 33
L0038:
	lds	si,[bp+6h]		; 38
	mov	bx,[bp+0eh]		; 3b
	add	si,bx		; 3e
	add	si,bx		; 40
	add	si,bx		; 42
	lodsb		; 44
	mov	[bp-4h],al		; 45
	lodsb		; 48
	mov	[bp-6h],al		; 49
	lodsb		; 4c
	mov	[bp-8h],al		; 4d
	xor	bx,bx		; 50
	les	di,[bp+0ah]		; 52
	mov	es:[di],bl		; 55
	inc	di		; 58
L0059:
	inc	bx		; 59
	lds	si,[bp+6h]		; 5a
	add	si,bx		; 5d
	add	si,bx		; 5f
	add	si,bx		; 61
	mov	dx,[bp+10h]		; 63
	shr	dx,1		; 66
	lodsb		; 68
	mov	dh,al		; 69
	sub	al,[bp-4h]		; 6b
	imul	dl		; 6e
	shl	ax,1		; 70
	sub	dh,ah		; 72
	mov	[bp-0ah],dh		; 74
	lodsb		; 77
	mov	dh,al		; 78
	sub	al,[bp-6h]		; 7a
	imul	dl		; 7d
	shl	ax,1		; 7f
	sub	dh,ah		; 81
	mov	[bp-0ch],dh		; 83
	lodsb		; 86
	mov	dh,al		; 87
	sub	al,[bp-8h]		; 89
	imul	dl		; 8c
	shl	ax,1		; 8e
	sub	dh,ah		; 90
	mov	[bp-0eh],dh		; 92
	mov	ax,[bp+0eh]		; 95
	mov	[bp-10h],al		; 98
	mov	word ptr [bp-2h],7fffh		; 9b
	mov	cx,0feh		; a0
	lds	si,[bp+6h]		; a3
	add	si,+3h		; a6
	mov	bh,1h		; a9
L00AB:
	add	si,+3h		; ab
	cmp	bh,bl		; ae
	jz	short L00E2		; b0
	sub	si,+3h		; b2
	xor	dx,dx		; b5
	lodsb		; b7
	sub	al,[bp-0ah]		; b8
	mov	ah,al		; bb
	imul	ah		; bd
	add	dx,ax		; bf
	lodsb		; c1
	sub	al,[bp-0ch]		; c2
	mov	ah,al		; c5
	imul	ah		; c7
	add	dx,ax		; c9
	lodsb		; cb
	sub	al,[bp-0eh]		; cc
	mov	ah,al		; cf
	imul	ah		; d1
	add	dx,ax		; d3
	jz	short L00E9		; d5
	cmp	dx,[bp-2h]		; d7
	ja	short L00E2		; da
	mov	[bp-2h],dx		; dc
	mov	[bp-10h],bh		; df
L00E2:
	inc	bh		; e2
	loop	short L00AB		; e4
	mov	bh,[bp-10h]		; e6
L00E9:
	mov	[bp-10h],bh		; e9
	xor	bh,bh		; ec
	mov	al,[bp-10h]		; ee
	stosb		; f1
	cmp	bx,0ffh		; f2
	jnz	near ptr L0059		; f6
L00FA:
	lds	si,[bp+0ah]		; fa
	mov	dx,ds		; fd
	mov	ax,si		; ff
	pop	si		; 101
	pop	ds		; 102
	pop	di		; 103
	pop	es		; 104
	pop	cx		; 105
	pop	bx		; 106
	leave		; 107
	retf		; 108
_fn_1b43_000e	endp

_fn_1b43_0109	proc	far
	enter	10h,0h		; 109
	push	bx		; 10d
	push	cx		; 10e
	push	es		; 10f
	push	di		; 110
	push	ds		; 111
	push	si		; 112
	cld		; 113
	cmp	dword ptr [bp+6h],+0h		; 114
	jz	near ptr L01F5		; 119
	cmp	dword ptr [bp+0ah],+0h		; 11d
	jz	near ptr L01F5		; 122
	mov	ax,[bp+10h]		; 126
	cmp	ax,100h		; 129
	jc	short L0133		; 12c
	mov	word ptr [bp+10h],0ffh		; 12e
L0133:
	lds	si,[bp+6h]		; 133
	mov	bx,[bp+0eh]		; 136
	add	si,bx		; 139
	add	si,bx		; 13b
	add	si,bx		; 13d
	lodsb		; 13f
	mov	[bp-4h],al		; 140
	lodsb		; 143
	mov	[bp-6h],al		; 144
	lodsb		; 147
	mov	[bp-8h],al		; 148
	xor	bx,bx		; 14b
	les	di,[bp+0ah]		; 14d
	mov	es:[di],bl		; 150
	inc	di		; 153
L0154:
	inc	bx		; 154
	lds	si,[bp+6h]		; 155
	add	si,bx		; 158
	add	si,bx		; 15a
	add	si,bx		; 15c
	mov	dx,[bp+10h]		; 15e
	shr	dx,1		; 161
	lodsb		; 163
	mov	dh,al		; 164
	sub	al,[bp-4h]		; 166
	imul	dl		; 169
	shl	ax,1		; 16b
	sub	dh,ah		; 16d
	mov	[bp-0ah],dh		; 16f
	lodsb		; 172
	mov	dh,al		; 173
	sub	al,[bp-6h]		; 175
	imul	dl		; 178
	shl	ax,1		; 17a
	sub	dh,ah		; 17c
	mov	[bp-0ch],dh		; 17e
	lodsb		; 181
	mov	dh,al		; 182
	sub	al,[bp-8h]		; 184
	imul	dl		; 187
	shl	ax,1		; 189
	sub	dh,ah		; 18b
	mov	[bp-0eh],dh		; 18d
	mov	ax,[bp+0eh]		; 190
	mov	[bp-10h],al		; 193
	mov	word ptr [bp-2h],7fffh		; 196
	mov	cx,7fh		; 19b
	lds	si,[bp+6h]		; 19e
	add	si,+3h		; 1a1
	mov	bh,1h		; 1a4
L01A6:
	add	si,+3h		; 1a6
	cmp	bh,bl		; 1a9
	jz	short L01DD		; 1ab
	sub	si,+3h		; 1ad
	xor	dx,dx		; 1b0
	lodsb		; 1b2
	sub	al,[bp-0ah]		; 1b3
	mov	ah,al		; 1b6
	imul	ah		; 1b8
	add	dx,ax		; 1ba
	lodsb		; 1bc
	sub	al,[bp-0ch]		; 1bd
	mov	ah,al		; 1c0
	imul	ah		; 1c2
	add	dx,ax		; 1c4
	lodsb		; 1c6
	sub	al,[bp-0eh]		; 1c7
	mov	ah,al		; 1ca
	imul	ah		; 1cc
	add	dx,ax		; 1ce
	jz	short L01E4		; 1d0
	cmp	dx,[bp-2h]		; 1d2
	ja	short L01DD		; 1d5
	mov	[bp-2h],dx		; 1d7
	mov	[bp-10h],bh		; 1da
L01DD:
	inc	bh		; 1dd
	loop	short L01A6		; 1df
	mov	bh,[bp-10h]		; 1e1
L01E4:
	mov	[bp-10h],bh		; 1e4
	xor	bh,bh		; 1e7
	mov	al,[bp-10h]		; 1e9
	stosb		; 1ec
	cmp	bx,0ffh		; 1ed
	jnz	near ptr L0154		; 1f1
L01F5:
	lds	si,[bp+0ah]		; 1f5
	mov	dx,ds		; 1f8
	mov	ax,si		; 1fa
	pop	si		; 1fc
	pop	ds		; 1fd
	pop	di		; 1fe
	pop	es		; 1ff
	pop	cx		; 200
	pop	bx		; 201
	leave		; 202
	retf		; 203
_fn_1b43_0109	endp
S042_TEXT	ends
	end
