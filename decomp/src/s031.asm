; s031: load a sound driver file into the music driver slot (g_28fa); compiled C (BCC -S via TASM: the
; original went through TASM, hence the short-jmp+nop pairs and ascending relocations). s033 mirrors it.
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
	?debug	S "s031.c"
	?debug	C E906B54C5D06733033312E63
S031_TEXT	segment byte public use16 'CODE'
S031_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:S031_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
d@	label	byte
d@w	label	word
_DATA	ends
_BSS	segment word public use16 'BSS'
b@	label	byte
b@w	label	word
_BSS	ends
S031_TEXT	segment byte public use16 'CODE'
   ;	
   ;	long fn_17c5_0004(char far *name, long a, long b)
   ;	
	assume	cs:S031_TEXT
_fn_17c5_0004	proc	far
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
   ;	    fn_178d_015e();
   ;	
	call	far ptr _fn_178d_015e
   ;	
   ;	    ovr_2db9_003e(&g_28fa);
   ;	
	push	ds
	push	offset DGROUP:_g_28fa
	call	far ptr _ovr_2db9_003e
	add	sp,4
   ;	
   ;	    if (g_28fa == -1 && g_2908 == 0)
   ;	
	cmp	word ptr DGROUP:_g_28fa,-1
	jne	short @1@86
	cmp	dword ptr DGROUP:_g_2908,large 0
	jne short	@@0
	jmp	near ptr @1@534
@@0:
@1@86:
   ;	
   ;	        goto done;
   ;	    if (g_2910 == g_28ce) {
   ;	
	mov	eax,dword ptr DGROUP:_g_2910
	cmp	eax,dword ptr DGROUP:_g_28ce
	jne	short @1@142
   ;	
   ;	        g_2910 = 0;
   ;	
	mov	dword ptr DGROUP:_g_2910,large 0
   ;	
   ;	        g_2918 = 0;
   ;	
	mov	dword ptr DGROUP:_g_2918,large 0
   ;	
   ;	        g_2914 = 0;
   ;	
	mov	dword ptr DGROUP:_g_2914,large 0
   ;	
   ;	        g_291c = 0;
   ;	
	mov	word ptr DGROUP:_g_291c,0
   ;	
   ;	    } else {
   ;	
	jmp	short @1@170
@1@142:
   ;	
   ;	        ovr_2db9_003e(&g_28fa);
   ;	
	push	ds
	push	offset DGROUP:_g_28fa
	call	far ptr _ovr_2db9_003e
	add	sp,4
@1@170:
   ;	
   ;	    }
   ;	    if (g_28d2 == 0)
   ;	
	cmp	dword ptr DGROUP:_g_28d2,large 0
	jne short	@@1
	jmp	short @1@506
	nop
@@1:
   ;	
   ;	        goto load;
   ;	    if (stricmp(ovr_2db9_0020(name, &g_28fa), (char far *)g_28d2) == 0) {
   ;	
	push	dword ptr DGROUP:_g_28d2
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
	jne	short @1@506
   ;	
   ;	        g_2910 = g_28ce;
   ;	
	mov	eax,dword ptr DGROUP:_g_28ce
	mov	dword ptr DGROUP:_g_2910,eax
   ;	
   ;	        g_2918 = g_28d6;
   ;	
	mov	eax,dword ptr DGROUP:_g_28d6
	mov	dword ptr DGROUP:_g_2918,eax
   ;	
   ;	        g_2914 = g_28d2;
   ;	
	mov	eax,dword ptr DGROUP:_g_28d2
	mov	dword ptr DGROUP:_g_2914,eax
   ;	
   ;	        g_291c = g_28da;
   ;	
	mov	ax,word ptr DGROUP:_g_28da
	mov	word ptr DGROUP:_g_291c,ax
   ;	
   ;	        if (g_28fa == -1) {
   ;	
	cmp	word ptr DGROUP:_g_28fa,-1
	jne	short @1@534
   ;	
   ;	            drv = g_2908;
   ;	
	mov	eax,dword ptr DGROUP:_g_2908
	mov	dword ptr [bp-12],eax
   ;	
   ;	            p = g_2910;
   ;	
	mov	eax,dword ptr DGROUP:_g_2910
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
   ;	    r = ovr_2db9_0039(name, &g_28fa, a, b);
   ;	
	push	dword ptr [bp+14]
	push	dword ptr [bp+10]
	push	ds
	push	offset DGROUP:_g_28fa
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
   ;	
   ;	    if (a) ;
   ;	
	cmp	dword ptr [bp+10],large 0
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
_fn_17c5_0004	endp
	?debug	C E9
	?debug	C FA00000000
S031_TEXT	ends
_DATA	segment word public use16 'DATA'
s@	label	byte
_DATA	ends
S031_TEXT	segment byte public use16 'CODE'
S031_TEXT	ends
	public	_fn_17c5_0004
	extrn	_stricmp:far
	extrn	_ovr_2db9_0039:far
	extrn	_ovr_2db9_0020:far
	extrn	_ovr_2db9_003e:far
	extrn	_fn_178d_015e:far
	extrn	_g_291c:word
	extrn	_g_2918:word
	extrn	_g_2914:word
	extrn	_g_2910:word
	extrn	_g_28da:word
	extrn	_g_28d6:word
	extrn	_g_28d2:word
	extrn	_g_28ce:word
	extrn	_g_2908:dword
	extrn	_g_28fa:word
_s@	equ	s@
	end
