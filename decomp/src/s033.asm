; s033: sound effects file loader (assembler module, mirror of s031)
;
; long fn_17e7_0003(char far *name, long a, long b)  stop effects, (re)load the effects driver's data file (shares the music data when the names match)

	.386
	locals
S033_TEXT	segment byte public use16 'CODE'
S033_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:S033_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends

	extrn	_g_28b8:word, _g_28c6:dword, _g_28ce:dword, _g_28d2:dword, _g_28d6:dword, _g_28da:word
	extrn	_g_2910:dword, _g_2914:dword, _g_2918:dword, _g_291c:word
	extrn	_fn_17d6_0123:far, _ovr_2db9_003e:far, _ovr_2db9_0020:far, _ovr_2db9_0039:far, _stricmp:far

S033_TEXT	segment byte public use16 'CODE'
	public	_fn_17e7_0003

_fn_17e7_0003	proc	far
	push	bp
	mov	bp,sp
	sub	sp,10h
	mov	dword ptr [bp-8],0
	call	far ptr _fn_17d6_0123
	push	ds
	push	offset DGROUP:_g_28b8
	call	far ptr _ovr_2db9_003e
	add	sp,4
	cmp	_g_28b8,-1
	jnz	short @@1
	cmp	_g_28c6,0
	jnz	short @@1
	jmp	@@done
@@1:	mov	eax,_g_28ce
	cmp	eax,_g_2910
	jnz	short @@free
	mov	_g_28ce,0
	mov	_g_28d6,0
	mov	_g_28d2,0
	mov	_g_28da,0
	jmp	short @@2
@@free:	push	ds
	push	offset DGROUP:_g_28b8
	call	far ptr _ovr_2db9_003e
	add	sp,4
@@2:	cmp	_g_2914,0
	jnz	short @@3
	jmp	short @@load
	nop
@@3:	push	_g_2914
	push	ds
	push	offset DGROUP:_g_28b8
	push	dword ptr [bp+6]
	call	far ptr _ovr_2db9_0020
	add	sp,8
	push	dx
	push	ax
	call	far ptr _stricmp
	add	sp,8
	or	ax,ax
	jnz	short @@load
	mov	eax,_g_2910
	mov	_g_28ce,eax
	mov	eax,_g_2918
	mov	_g_28d6,eax
	mov	eax,_g_2914
	mov	_g_28d2,eax
	mov	ax,_g_291c
	mov	_g_28da,ax
	cmp	_g_28b8,-1
	jnz	short @@done
	mov	eax,_g_28c6
	mov	[bp-0ch],eax
	mov	eax,_g_28ce
	mov	[bp-10h],eax
	push	es
	les	ax,[bp-10h]
	mov	dx,es
	pop	es
	mov	bx,4
	pushf
	call	dword ptr [bp-0ch]
	jmp	short @@done
@@load:	push	dword ptr [bp+0eh]
	push	dword ptr [bp+0ah]
	push	ds
	push	offset DGROUP:_g_28b8
	push	dword ptr [bp+6]
	call	far ptr _ovr_2db9_0039
	push	dx
	push	ax
	pop	eax
	add	sp,10h
	mov	[bp-4],eax
	add	[bp-8],eax
@@done:	mov	eax,[bp-8]
	shld	edx,eax,10h
	leave
	ret
_fn_17e7_0003	endp

S033_TEXT	ends
	end
