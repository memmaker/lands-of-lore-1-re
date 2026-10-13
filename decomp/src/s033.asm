; s033: mirror of s031 for the digital driver slot g_28b8 (compiled C via TASM, see s031.asm)
	.386p
	ifndef	??version
?debug	macro
	endm
publicdll macro	name
	public	name
	endm
$comm	macro	name,dist,size,count
	comm	dist name:BYTE:count*size
	endm
	else
$comm	macro	name,dist,size,count
	comm	dist name[size]:BYTE:count
	endm
	endif
	?debug	V 300h
	?debug	S "s033.c"
	?debug	C E906B54C5D06733033332E63
S033_TEXT	segment byte public use16 'CODE'
S033_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:S033_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
d@	label	byte
d@w	label	word
_DATA	ends
_BSS	segment word public use16 'BSS'
b@	label	byte
b@w	label	word
_BSS	ends
S033_TEXT	segment byte public use16 'CODE'
   ;	
   ;	long fn_17f8_0003(char far *name, long a, long b)
   ;	
	assume	cs:S033_TEXT
_fn_17f8_0003	proc	far
	push	bp
	mov	bp,sp
	sub	sp,16
   ;	
   ;	{
   ;	    long r;
   ;	    long total;
   ;	    void (far *drv)(void);
   ;	    long p;
   ;	
   ;	    total = 0;
   ;	
	mov	dword ptr [bp-8],large 0
   ;	
   ;	    fn_17d6_0123();
   ;	
	call	far ptr _fn_17d6_0123
   ;	
   ;	    ovr_2db9_003e(&g_28b8);
   ;	
	push	ds
	push	offset DGROUP:_g_28b8
	call	far ptr _ovr_2db9_003e
	add	sp,4
   ;	
   ;	    if (g_28b8 == -1 && g_28c6 == 0)
   ;	
	cmp	word ptr DGROUP:_g_28b8,-1
	jne	short @1@86
	cmp	dword ptr DGROUP:_g_28c6,large 0
	jne short	@@0
	jmp	near ptr @1@534
@@0:
@1@86:
   ;	
   ;	        goto done;
   ;	    if (g_28ce == g_2910) {
   ;	
	mov	eax,dword ptr DGROUP:_g_28ce
	cmp	eax,dword ptr DGROUP:_g_2910
	jne	short @1@142
   ;	
   ;	        g_28ce = 0;
   ;	
	mov	dword ptr DGROUP:_g_28ce,large 0
   ;	
   ;	        g_28d6 = 0;
   ;	
	mov	dword ptr DGROUP:_g_28d6,large 0
   ;	
   ;	        g_28d2 = 0;
   ;	
	mov	dword ptr DGROUP:_g_28d2,large 0
   ;	
   ;	        g_28da = 0;
   ;	
	mov	word ptr DGROUP:_g_28da,0
   ;	
   ;	    } else {
   ;	
	jmp	short @1@170
@1@142:
   ;	
   ;	        ovr_2db9_003e(&g_28b8);
   ;	
	push	ds
	push	offset DGROUP:_g_28b8
	call	far ptr _ovr_2db9_003e
	add	sp,4
@1@170:
   ;	
   ;	    }
   ;	    if (g_2914 == 0)
   ;	
	cmp	dword ptr DGROUP:_g_2914,large 0
	jne short	@@1
	jmp	short @1@506
	nop
@@1:
   ;	
   ;	        goto load;
   ;	    if (stricmp(ovr_2db9_0020(name, &g_28b8), (char far *)g_2914) == 0) {
   ;	
	push	dword ptr DGROUP:_g_2914
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
	jne	short @1@506
   ;	
   ;	        g_28ce = g_2910;
   ;	
	mov	eax,dword ptr DGROUP:_g_2910
	mov	dword ptr DGROUP:_g_28ce,eax
   ;	
   ;	        g_28d6 = g_2918;
   ;	
	mov	eax,dword ptr DGROUP:_g_2918
	mov	dword ptr DGROUP:_g_28d6,eax
   ;	
   ;	        g_28d2 = g_2914;
   ;	
	mov	eax,dword ptr DGROUP:_g_2914
	mov	dword ptr DGROUP:_g_28d2,eax
   ;	
   ;	        g_28da = g_291c;
   ;	
	mov	ax,word ptr DGROUP:_g_291c
	mov	word ptr DGROUP:_g_28da,ax
   ;	
   ;	        if (g_28b8 == -1) {
   ;	
	cmp	word ptr DGROUP:_g_28b8,-1
	jne	short @1@534
   ;	
   ;	            drv = g_28c6;
   ;	
	mov	eax,dword ptr DGROUP:_g_28c6
	mov	dword ptr [bp-12],eax
   ;	
   ;	            p = g_28ce;
   ;	
	mov	eax,dword ptr DGROUP:_g_28ce
	mov	dword ptr [bp-16],eax
   ;	
   ;	            asm push es;
   ;	
 	push	 es
   ;	
   ;	            asm les ax, p;
   ;	
 	les	 ax, [bp-16]
   ;	
   ;	            asm mov dx, es;
   ;	
 	mov	 dx, es
   ;	
   ;	            asm pop es;
   ;	
 	pop	 es
   ;	
   ;	            asm mov bx, 4;
   ;	
 	mov	 bx, 4
   ;	
   ;	            asm pushf;
   ;	
 	pushf	
   ;	
   ;	            asm call dword ptr drv;
   ;	
 	call	 dword ptr [bp-12]
   ;	
   ;	        }
   ;	        goto done;
   ;	
	jmp	short @1@534
@1@506:
   ;	
   ;	    }
   ;	load:
   ;	    r = ovr_2db9_0039(name, &g_28b8, a, b);
   ;	
	push	dword ptr [bp+14]
	push	dword ptr [bp+10]
	push	ds
	push	offset DGROUP:_g_28b8
	push	dword ptr [bp+6]
	call	far ptr _ovr_2db9_0039
	push	dx
	push	ax
	pop	eax
	add	sp,16
	mov	dword ptr [bp-4],eax
   ;	
   ;	    total += r;
   ;	
	add	dword ptr [bp-8],eax
@1@534:
   ;	
   ;	done:
   ;	    return total;
   ;	
	mov	eax,dword ptr [bp-8]
	shld	edx,eax,16
   ;	
   ;	}
   ;	
	leave	
	ret	
_fn_17f8_0003	endp
	?debug	C E9
	?debug	C FA00000000
S033_TEXT	ends
_DATA	segment word public use16 'DATA'
s@	label	byte
_DATA	ends
S033_TEXT	segment byte public use16 'CODE'
S033_TEXT	ends
	public	_fn_17f8_0003
	extrn	_stricmp:far
	extrn	_ovr_2db9_0039:far
	extrn	_ovr_2db9_0020:far
	extrn	_ovr_2db9_003e:far
	extrn	_fn_17d6_0123:far
	extrn	_g_28da:word
	extrn	_g_28d6:word
	extrn	_g_28d2:word
	extrn	_g_28ce:word
	extrn	_g_291c:word
	extrn	_g_2918:word
	extrn	_g_2914:word
	extrn	_g_2910:word
	extrn	_g_28c6:dword
	extrn	_g_28b8:word
_s@	equ	s@
	end
