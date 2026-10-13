; s031: music file loader (assembler module like s026/s030)
;
; long fn_17c5_0004(char far *name, long a, long b)  stop music, (re)load the music driver's data file

	.386
	locals
S031_TEXT	segment byte public use16 'CODE'
S031_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:S031_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
_DATA	ends
_BSS	segment word public use16 'BSS'
_BSS	ends

	extrn	_g_28fa:word, _g_2908:dword, _g_2910:dword, _g_2914:dword, _g_2918:dword, _g_291c:word
	extrn	_g_28ce:dword, _g_28d2:dword, _g_28d6:dword, _g_28da:word
	extrn	_fn_178d_015e:far, _ovr_2db9_003e:far, _ovr_2db9_0020:far, _ovr_2db9_0039:far, _stricmp:far

S031_TEXT	segment byte public use16 'CODE'
	public	_fn_17c5_0004

_fn_17c5_0004	proc	far
	push	bp
	mov	bp,sp
	sub	sp,10h
	mov	dword ptr [bp-8],0
	call	far ptr _fn_178d_015e
	push	ds
	push	offset DGROUP:_g_28fa
	call	far ptr _ovr_2db9_003e
	add	sp,4
	cmp	_g_28fa,-1
	jnz	short @@1
	cmp	_g_2908,0
	jnz	short @@1
	jmp	@@done
@@1:	mov	eax,_g_2910
	cmp	eax,_g_28ce
	jnz	short @@free
	mov	_g_2910,0
	mov	_g_2918,0
	mov	_g_2914,0
	mov	_g_291c,0
	jmp	short @@2
@@free:	push	ds
	push	offset DGROUP:_g_28fa
	call	far ptr _ovr_2db9_003e
	add	sp,4
@@2:	cmp	_g_28d2,0
	jnz	short @@3
	jmp	short @@load
	nop
@@3:	push	_g_28d2
	push	ds
	push	offset DGROUP:_g_28fa
	push	dword ptr [bp+6]
	call	far ptr _ovr_2db9_0020
	add	sp,8
	push	dx
	push	ax
	call	far ptr _stricmp
	add	sp,8
	or	ax,ax
	jnz	short @@load
	mov	eax,_g_28ce
	mov	_g_2910,eax
	mov	eax,_g_28d6
	mov	_g_2918,eax
	mov	eax,_g_28d2
	mov	_g_2914,eax
	mov	ax,_g_28da
	mov	_g_291c,ax
	cmp	_g_28fa,-1
	jnz	short @@done
	mov	eax,_g_2908
	mov	[bp-0ch],eax
	mov	eax,_g_2910
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
	push	offset DGROUP:_g_28fa
	push	dword ptr [bp+6]
	call	far ptr _ovr_2db9_0039
	push	dx
	push	ax
	pop	eax
	add	sp,10h
	mov	[bp-4],eax
	add	[bp-8],eax
	cmp	dword ptr [bp+0ah],0
@@done:	mov	eax,[bp-8]
	shld	edx,eax,10h
	leave
	ret
_fn_17c5_0004	endp

S031_TEXT	ends
	end
