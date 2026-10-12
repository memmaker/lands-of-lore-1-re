; s030: music driver front end (g_28fa driver struct); compiled C (BCC -S of the C source quoted in the
; comments, ENTER expanded): the original went through TASM (#pragma inline), hence ascending relocations.
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
	?debug	S "s030.c"
	?debug	C E930B54C5D06733033302E63
	?debug	C E935B34C5D10443A5C494E5354414C4C5C6D656D2E68
	?debug	C E935B34C5D12443A5C494E5354414C4C5C5F646566732E68
	?debug	C E935B34C5D12443A5C494E5354414C4C5C5F6E756C6C2E68
S030_TEXT	segment byte public use16 'CODE'
S030_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:S030_TEXT,ds:DGROUP
_DATA	segment word public use16 'DATA'
d@	label	byte
d@w	label	word
_DATA	ends
_BSS	segment word public use16 'BSS'
b@	label	byte
b@w	label	word
_BSS	ends
_DATA	segment word public use16 'DATA'
_g_2a9a	label	word
	db	255
	db	255
_g_2a9c	label	byte
	db	65
	db	76
	db	70
	db	88
	db	6 dup (0)
_DATA	ends
S030_TEXT	segment byte public use16 'CODE'
   ;	
   ;	int fn_178d_0007(void)
   ;	
	assume	cs:S030_TEXT
_fn_178d_0007	proc	far
	push	bp
	mov	bp,sp
	sub	sp,6
   ;	
   ;	{
   ;	    int r;
   ;	    void far *fp;
   ;	
   ;	    r = 0;
   ;	
	mov	word ptr [bp-2],0
   ;	
   ;	    if (g_28fa.h == -1 && g_28fa.entry != 0) {
   ;	
	cmp	word ptr DGROUP:_g_28fa,-1
	jne	short @1@226
	cmp	dword ptr DGROUP:_g_28fa+14,large 0
	je	short @1@226
   ;	
   ;	        fp = g_28fa.entry;
   ;	
	mov	eax,dword ptr DGROUP:_g_28fa+14
	mov	dword ptr [bp-6],eax
   ;	
   ;	        asm mov bx, 0xb;
   ;	
 	mov	 bx, 0bH
   ;	
   ;	        asm pushf;
   ;	
 	pushf	
   ;	
   ;	        asm call dword ptr fp;
   ;	
 	call	 dword ptr [bp-6]
   ;	
   ;	        asm mov r, ax;
   ;	
 	mov	 [bp-2], ax
@1@226:
   ;	
   ;	    }
   ;	    return r;
   ;	
	mov	ax,word ptr [bp-2]
   ;	
   ;	}
   ;	
	leave	
	ret	
_fn_178d_0007	endp
   ;	
   ;	int fn_178d_0038(void)
   ;	
	assume	cs:S030_TEXT
_fn_178d_0038	proc	far
	push	bp
	mov	bp,sp
	sub	sp,6
   ;	
   ;	{
   ;	    int r;
   ;	    void far *fp;
   ;	
   ;	    r = 0;
   ;	
	mov	word ptr [bp-2],0
   ;	
   ;	    if (g_28fa.h != -1) {
   ;	
	cmp	word ptr DGROUP:_g_28fa,-1
	je	short @2@198
   ;	
   ;	        if (g_28fa.voice != -1)
   ;	
	cmp	word ptr DGROUP:_g_28fa+40,-1
	je	short @2@394
   ;	
   ;	            return fn_1b79_02ef(g_28fa.h, g_28fa.voice) == 1;
   ;	
	push	word ptr DGROUP:_g_28fa+40
	push	word ptr DGROUP:_g_28fa
	call	far ptr _fn_1b79_02ef
	add	sp,4
	cmp	ax,1
	jne	short @2@142
	mov	ax,1
	jmp	short @2@170
@2@142:
	xor	ax,ax
@2@170:
	jmp	short @2@422
@2@198:
   ;	
   ;	    } else if (g_28fa.entry != 0) {
   ;	
	cmp	dword ptr DGROUP:_g_28fa+14,large 0
	je	short @2@394
   ;	
   ;	        fp = g_28fa.entry;
   ;	
	mov	eax,dword ptr DGROUP:_g_28fa+14
	mov	dword ptr [bp-6],eax
   ;	
   ;	        asm mov ax, 0;
   ;	
 	mov	 ax, 0
   ;	
   ;	        asm mov bx, 7;
   ;	
 	mov	 bx, 7
   ;	
   ;	        asm pushf;
   ;	
 	pushf	
   ;	
   ;	        asm call dword ptr fp;
   ;	
 	call	 dword ptr [bp-6]
   ;	
   ;	        asm mov r, ax;
   ;	
 	mov	 [bp-2], ax
@2@394:
   ;	
   ;	    }
   ;	    return r;
   ;	
	mov	ax,word ptr [bp-2]
@2@422:
   ;	
   ;	}
   ;	
	leave	
	ret	
_fn_178d_0038	endp
   ;	
   ;	void fn_178d_0091(int n)
   ;	
	assume	cs:S030_TEXT
_fn_178d_0091	proc	far
	push	bp
	mov	bp,sp
   ;	
   ;	{
   ;	    fn_178d_00a4(n, 0xff);
   ;	
	push	255
	push	word ptr [bp+6]
	call	far ptr _fn_178d_00a4
	add	sp,4
   ;	
   ;	}
   ;	
	pop	bp
	ret	
_fn_178d_0091	endp
   ;	
   ;	void fn_178d_00a4(int n, int vol)
   ;	
	assume	cs:S030_TEXT
_fn_178d_00a4	proc	far
	push	bp
	mov	bp,sp
	push	si
	push	di
	mov	si,word ptr [bp+6]
	mov	di,word ptr [bp+8]
   ;	
   ;	{
   ;	    if (n < 0 || n > 0xfa || !g_35e4)
   ;	
	or	si,si
	jge short	@@0
	jmp	@4@310
@@0:
	cmp	si,250
	jle short	@@1
	jmp	@4@310
@@1:
	cmp	word ptr DGROUP:_g_35e4,0
	jne short	@@2
	jmp	@4@310
@@2:
   ;	
   ;	        return;
   ;	    if (g_28fa.h != -1) {
   ;	
	cmp	word ptr DGROUP:_g_28fa,-1
	je	short @4@226
   ;	
   ;	        if (g_28fa.voice != -1) {
   ;	
	cmp	word ptr DGROUP:_g_28fa+40,-1
	je	short @4@198
   ;	
   ;	            fn_1b79_02e3(g_28fa.h, g_28fa.voice);
   ;	
	push	word ptr DGROUP:_g_28fa+40
	push	word ptr DGROUP:_g_28fa
	call	far ptr _fn_1b79_02e3
	add	sp,4
   ;	
   ;	            fn_1b79_02b1(g_28fa.h, g_28fa.voice);
   ;	
	push	word ptr DGROUP:_g_28fa+40
	push	word ptr DGROUP:_g_28fa
	call	far ptr _fn_1b79_02b1
	add	sp,4
   ;	
   ;	            g_28fa.voice = -1;
   ;	
	mov	word ptr DGROUP:_g_28fa+40,-1
@4@198:
   ;	
   ;	        }
   ;	        g_28fa.voice = fn_1b79_02ac(g_28fa.h, g_28fa.data, n, g_28fa.w2a, 0);
   ;	
	push	large 0
	push	dword ptr DGROUP:_g_28fa+42
	push	si
	push	dword ptr DGROUP:_g_28fa+22
	push	word ptr DGROUP:_g_28fa
	call	far ptr _fn_1b79_02ac
	add	sp,16
	mov	word ptr DGROUP:_g_28fa+40,ax
   ;	
   ;	        fn_1b79_02dd(g_28fa.h, g_28fa.voice);
   ;	
	push	ax
	push	word ptr DGROUP:_g_28fa
	call	far ptr _fn_1b79_02dd
	add	sp,4
   ;	
   ;	        fn_1b79_0301(g_28fa.h, g_28fa.voice, (vol & 0xff) * 0x5a >> 8, 0);
   ;	
	push	0
	mov	ax,di
	and	ax,255
	imul	ax,ax,90
	sar	ax,8
	push	ax
	push	word ptr DGROUP:_g_28fa+40
	push	word ptr DGROUP:_g_28fa
	call	far ptr _fn_1b79_0301
	jmp	short @4@282
@4@226:
   ;	
   ;	    } else if (g_28fa.entry != 0) {
   ;	
	cmp	dword ptr DGROUP:_g_28fa+14,large 0
	je	short @4@310
   ;	
   ;	        fn_178d_01ef(&g_28fa, n, vol);
   ;	
	push	di
	push	si
	push	ds
	push	offset DGROUP:_g_28fa
	call	far ptr _fn_178d_01ef
@4@282:
	add	sp,8
@4@310:
   ;	
   ;	    }
   ;	}
   ;	
	pop	di
	pop	si
	pop	bp
	ret	
_fn_178d_00a4	endp
   ;	
   ;	void fn_178d_015e(void)
   ;	
	assume	cs:S030_TEXT
_fn_178d_015e	proc	far
	push	bp
	mov	bp,sp
   ;	
   ;	{
   ;	    if (g_28fa.h != -1) {
   ;	
	cmp	word ptr DGROUP:_g_28fa,-1
	je	short @5@114
   ;	
   ;	        if (g_28fa.voice != -1) {
   ;	
	cmp	word ptr DGROUP:_g_28fa+40,-1
	je	short @5@170
   ;	
   ;	            fn_1b79_02e3(g_28fa.h, g_28fa.voice);
   ;	
	push	word ptr DGROUP:_g_28fa+40
	push	word ptr DGROUP:_g_28fa
	call	far ptr _fn_1b79_02e3
	add	sp,4
   ;	
   ;	            fn_1b79_02b1(g_28fa.h, g_28fa.voice);
   ;	
	push	word ptr DGROUP:_g_28fa+40
	push	word ptr DGROUP:_g_28fa
	call	far ptr _fn_1b79_02b1
	add	sp,4
   ;	
   ;	            g_28fa.voice = -1;
   ;	
	mov	word ptr DGROUP:_g_28fa+40,-1
	jmp	short @5@170
@5@114:
   ;	
   ;	        }
   ;	    } else if (g_28fa.entry != 0) {
   ;	
	cmp	dword ptr DGROUP:_g_28fa+14,large 0
	je	short @5@170
   ;	
   ;	        fn_178d_01ef(&g_28fa, 0, 0);
   ;	
	push	large 0
	push	ds
	push	offset DGROUP:_g_28fa
	call	far ptr _fn_178d_01ef
	add	sp,8
@5@170:
   ;	
   ;	    }
   ;	}
   ;	
	pop	bp
	ret	
_fn_178d_015e	endp
   ;	
   ;	void fn_178d_01b0(void)
   ;	
	assume	cs:S030_TEXT
_fn_178d_01b0	proc	far
	push	bp
	mov	bp,sp
   ;	
   ;	{
   ;	    if (g_28fa.h != -1) {
   ;	
	cmp	word ptr DGROUP:_g_28fa,-1
	je	short @6@114
   ;	
   ;	        if (g_28fa.voice != -1)
   ;	
	cmp	word ptr DGROUP:_g_28fa+40,-1
	je	short @6@198
   ;	
   ;	            fn_1b79_0301(g_28fa.h, g_28fa.voice, 0, 0x7d0);
   ;	
	push	large 007D00000h
	push	word ptr DGROUP:_g_28fa+40
	push	word ptr DGROUP:_g_28fa
	call	far ptr _fn_1b79_0301
	jmp	short @6@170
@6@114:
   ;	
   ;	    } else if (g_28fa.entry != 0) {
   ;	
	cmp	dword ptr DGROUP:_g_28fa+14,large 0
	je	short @6@198
   ;	
   ;	        fn_178d_01ef(&g_28fa, 1, 0);
   ;	
	push	large 1
	push	ds
	push	offset DGROUP:_g_28fa
	call	far ptr _fn_178d_01ef
@6@170:
	add	sp,8
@6@198:
   ;	
   ;	    }
   ;	}
   ;	
	pop	bp
	ret	
_fn_178d_01b0	endp
   ;	
   ;	void fn_178d_01ef(struct Drv far *s, int n, int vol)
   ;	
	assume	cs:S030_TEXT
_fn_178d_01ef	proc	far
	push	bp
	mov	bp,sp
	sub	sp,8
   ;	
   ;	{
   ;	    int r;
   ;	    void far *fp;
   ;	    int stat;
   ;	
   ;	    fp = s->entry;
   ;	
	les	bx,dword ptr [bp+6]
	mov	eax,dword ptr es:[bx+14]
	mov	dword ptr [bp-6],eax
   ;	
   ;	    if (n != -1 && fp && s->data) {
   ;	
	cmp	word ptr [bp+10],-1
	jne short	@@3
	jmp	@7@2718
@@3:
	cmp	dword ptr [bp-6],large 0
	jne short	@@4
	jmp	@7@2718
@@4:
	cmp	dword ptr es:[bx+22],large 0
	jne short	@@5
	jmp	@7@2718
@@5:
   ;	
   ;	    n = s->tab[n];
   ;	
	les	bx,dword ptr es:[bx+30]
	mov	ax,word ptr [bp+10]
	shl	ax,1
	add	bx,ax
	mov	ax,word ptr es:[bx]
	mov	word ptr [bp+10],ax
   ;	
   ;	    if (n != -1) {
   ;	
	cmp	word ptr [bp+10],-1
	jne short	@@6
	jmp	@7@2718
@@6:
   ;	
   ;	    if (memcmp(s->name, g_2a9c, 4) == 0) {
   ;	
	push	4
	push	ds
	push	offset DGROUP:_g_2a9c
	les	bx,dword ptr [bp+6]
	push	dword ptr es:[bx+2]
	call	far ptr _memcmp
	add	sp,10
	or	ax,ax
	je short	@@7
	jmp	@7@2186
@@7:
   ;	
   ;	        n &= 0xff;
   ;	
	and	word ptr [bp+10],255
@7@198:
   ;	
   ;	        do {
   ;	            asm xor ax, ax;
   ;	
 	xor	 ax, ax
   ;	
   ;	            asm mov bx, 0x10;
   ;	
 	mov	 bx, 010H
   ;	
   ;	            asm pushf;
   ;	
 	pushf	
   ;	
   ;	            asm call dword ptr fp;
   ;	
 	call	 dword ptr [bp-6]
   ;	
   ;	            asm mov stat, ax;
   ;	
 	mov	 [bp-8], ax
   ;	
   ;	        } while (stat & 8);
   ;	
	test	word ptr [bp-8],8
	jne	short @7@198
   ;	
   ;	        if (g_2a9a != 0xffff) {
   ;	
	cmp	word ptr DGROUP:_g_2a9a,00000FFFFh
	je	short @7@758
   ;	
   ;	            asm mov cx, g_abd6;
   ;	
 	mov	 cx, _g_abd6
   ;	
   ;	            asm mov dx, 1;
   ;	
 	mov	 dx, 1
   ;	
   ;	            asm mov ax, g_2a9a;
   ;	
 	mov	 ax, DGROUP:_g_2a9a
   ;	
   ;	            asm mov bx, 10;
   ;	
 	mov	 bx, 10
   ;	
   ;	            asm pushf;
   ;	
 	pushf	
   ;	
   ;	            asm call dword ptr fp;
   ;	
 	call	 dword ptr [bp-6]
   ;	
   ;	            asm mov cx, g_abd4;
   ;	
 	mov	 cx, _g_abd4
   ;	
   ;	            asm mov dx, 3;
   ;	
 	mov	 dx, 3
   ;	
   ;	            asm mov ax, g_2a9a;
   ;	
 	mov	 ax, DGROUP:_g_2a9a
   ;	
   ;	            asm mov bx, 10;
   ;	
 	mov	 bx, 10
   ;	
   ;	            asm pushf;
   ;	
 	pushf	
   ;	
   ;	            asm call dword ptr fp;
   ;	
 	call	 dword ptr [bp-6]
   ;	
   ;	            g_2a9a = -1;
   ;	
	mov	word ptr DGROUP:_g_2a9a,00000FFFFh
@7@758:
   ;	
   ;	        }
   ;	        asm mov dx, 0;
   ;	
 	mov	 dx, 0
   ;	
   ;	        asm mov ax, n;
   ;	
 	mov	 ax, [bp+10]
   ;	
   ;	        asm mov bx, 9;
   ;	
 	mov	 bx, 9
   ;	
   ;	        asm pushf;
   ;	
 	pushf	
   ;	
   ;	        asm call dword ptr fp;
   ;	
 	call	 dword ptr [bp-6]
   ;	
   ;	        asm mov r, ax;
   ;	
 	mov	 [bp-2], ax
   ;	
   ;	        g_2a9a = -1;
   ;	
	mov	word ptr DGROUP:_g_2a9a,00000FFFFh
   ;	
   ;	        if (vol != -1 && r != 9) {
   ;	
	cmp	word ptr [bp+12],-1
	jne short	@@8
	jmp	@7@2018
@@8:
	cmp	word ptr [bp-2],9
	jne short	@@9
	jmp	@7@2018
@@9:
   ;	
   ;	            g_2a9a = n;
   ;	
	mov	ax,word ptr [bp+10]
	mov	word ptr DGROUP:_g_2a9a,ax
   ;	
   ;	            asm mov dx, 1;
   ;	
 	mov	 dx, 1
   ;	
   ;	            asm mov ax, n;
   ;	
 	mov	 ax, [bp+10]
   ;	
   ;	            asm mov bx, 9;
   ;	
 	mov	 bx, 9
   ;	
   ;	            asm pushf;
   ;	
 	pushf	
   ;	
   ;	            asm call dword ptr fp;
   ;	
 	call	 dword ptr [bp-6]
   ;	
   ;	            asm mov g_abd6, ax;
   ;	
 	mov	 _g_abd6, ax
   ;	
   ;	            asm mov dx, 3;
   ;	
 	mov	 dx, 3
   ;	
   ;	            asm mov ax, n;
   ;	
 	mov	 ax, [bp+10]
   ;	
   ;	            asm mov bx, 9;
   ;	
 	mov	 bx, 9
   ;	
   ;	            asm pushf;
   ;	
 	pushf	
   ;	
   ;	            asm call dword ptr fp;
   ;	
 	call	 dword ptr [bp-6]
   ;	
   ;	            asm mov g_abd4, ax;
   ;	
 	mov	 _g_abd4, ax
   ;	
   ;	            asm mov ax, g_abd4;
   ;	
 	mov	 ax, _g_abd4
   ;	
   ;	            asm neg ax;
   ;	
 	neg	 ax
   ;	
   ;	            asm add ax, 3fh;
   ;	
 	add	 ax, 3fh
   ;	
   ;	            asm mul byte ptr vol;
   ;	
 	mul	 byte ptr [bp+12]
   ;	
   ;	            asm xchg ah, al;
   ;	
 	xchg	 ah, al
   ;	
   ;	            asm xor ah, ah;
   ;	
 	xor	 ah, ah
   ;	
   ;	            asm neg ax;
   ;	
 	neg	 ax
   ;	
   ;	            asm add ax, 3fh;
   ;	
 	add	 ax, 3fh
   ;	
   ;	            asm mov cx, ax;
   ;	
 	mov	 cx, ax
   ;	
   ;	            asm mov dx, 3;
   ;	
 	mov	 dx, 3
   ;	
   ;	            asm mov ax, n;
   ;	
 	mov	 ax, [bp+10]
   ;	
   ;	            asm mov bx, 10;
   ;	
 	mov	 bx, 10
   ;	
   ;	            asm pushf;
   ;	
 	pushf	
   ;	
   ;	            asm call dword ptr fp;
   ;	
 	call	 dword ptr [bp-6]
   ;	
   ;	            asm mov ax, g_abd6;
   ;	
 	mov	 ax, _g_abd6
   ;	
   ;	            asm mov dx, vol;
   ;	
 	mov	 dx, [bp+12]
   ;	
   ;	            asm mul dl;
   ;	
 	mul	 dl
   ;	
   ;	            asm mov cl, ah;
   ;	
 	mov	 cl, ah
   ;	
   ;	            asm xor ch, ch;
   ;	
 	xor	 ch, ch
   ;	
   ;	            asm mov dx, 1;
   ;	
 	mov	 dx, 1
   ;	
   ;	            asm mov ax, n;
   ;	
 	mov	 ax, [bp+10]
   ;	
   ;	            asm mov bx, 10;
   ;	
 	mov	 bx, 10
   ;	
   ;	            asm pushf;
   ;	
 	pushf	
   ;	
   ;	            asm call dword ptr fp;
   ;	
 	call	 dword ptr [bp-6]
@7@2018:
   ;	
   ;	        }
   ;	        asm mov ax, n;
   ;	
 	mov	 ax, [bp+10]
   ;	
   ;	        asm mov bx, 6;
   ;	
 	mov	 bx, 6
   ;	
   ;	        asm pushf;
   ;	
 	pushf	
   ;	
   ;	        asm call dword ptr fp;
   ;	
 	call	 dword ptr [bp-6]
   ;	
   ;	        if (n == 0)
   ;	
	cmp	word ptr [bp+10],0
	jne	short @7@2718
   ;	
   ;	            fn_2120_0007(5);
   ;	
	push	5
	call	far ptr _fn_2120_0007
	pop	cx
	jmp	short @7@2718
@7@2186:
   ;	
   ;	    } else {
   ;	        if (g_28de == 1) {
   ;	
	cmp	word ptr DGROUP:_g_28de,1
	jne	short @7@2494
   ;	
   ;	            if (n < 0) {
   ;	
	cmp	word ptr [bp+10],0
	jge	short @7@2382
   ;	
   ;	                asm mov ax, 4;
   ;	
 	mov	 ax, 4
   ;	
   ;	                asm mov bx, 11h;
   ;	
 	mov	 bx, 11h
   ;	
   ;	                asm pushf;
   ;	
 	pushf	
   ;	
   ;	                asm call dword ptr fp;
   ;	
 	call	 dword ptr [bp-6]
   ;	
   ;	            } else {
   ;	
	jmp	short @7@2494
@7@2382:
   ;	
   ;	                asm mov ax, 4;
   ;	
 	mov	 ax, 4
   ;	
   ;	                asm mov bx, 10h;
   ;	
 	mov	 bx, 10h
   ;	
   ;	                asm pushf;
   ;	
 	pushf	
   ;	
   ;	                asm call dword ptr fp;
   ;	
 	call	 dword ptr [bp-6]
@7@2494:
   ;	
   ;	            }
   ;	        }
   ;	        n = n < 0 ? -n : n;
   ;	
	cmp	word ptr [bp+10],0
	jge	short @7@2550
	mov	ax,word ptr [bp+10]
	neg	ax
	jmp	short @7@2578
@7@2550:
	mov	ax,word ptr [bp+10]
@7@2578:
	mov	word ptr [bp+10],ax
   ;	
   ;	        asm mov ax, n;
   ;	
 	mov	 ax, [bp+10]
   ;	
   ;	        asm mov bx, 6;
   ;	
 	mov	 bx, 6
   ;	
   ;	        asm pushf;
   ;	
 	pushf	
   ;	
   ;	        asm call dword ptr fp;
   ;	
 	call	 dword ptr [bp-6]
@7@2718:
   ;	
   ;	    }
   ;	    }
   ;	    }
   ;	}
   ;	
	leave	
	ret	
_fn_178d_01ef	endp
	?debug	C E9
	?debug	C FA10000000
S030_TEXT	ends
_DATA	segment word public use16 'DATA'
s@	label	byte
_DATA	ends
S030_TEXT	segment byte public use16 'CODE'
S030_TEXT	ends
	public	_fn_178d_01b0
	public	_fn_178d_015e
	public	_fn_178d_0091
	public	_fn_178d_0038
	public	_fn_178d_0007
	public	_g_2a9c
	public	_g_2a9a
	public	_fn_178d_01ef
	public	_fn_178d_00a4
	extrn	_fn_2120_0007:far
	extrn	_fn_1b79_0301:far
	extrn	_fn_1b79_02dd:far
	extrn	_fn_1b79_02ac:far
	extrn	_fn_1b79_02b1:far
	extrn	_fn_1b79_02e3:far
	extrn	_fn_1b79_02ef:far
	extrn	_g_abd6:word
	extrn	_g_abd4:word
	extrn	_g_28de:word
	extrn	_g_35e4:word
	extrn	_g_28fa:word
	extrn	_memcmp:far
_s@	equ	s@
	end
