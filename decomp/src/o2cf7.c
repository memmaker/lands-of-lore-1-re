/* o2cf7: palette fade tables and an animated sequence with palette steps */

struct anim { int a; unsigned count; };
extern void far *g_369f;
extern unsigned long g_384c;
extern char g_081a[], g_0827[], g_0834[], g_0841[];
extern unsigned char g_2fac[];
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void far *fn_215f_0003(int p);
void fn_2279_025b(void far *d, void far *s, long n);
struct anim far *ovr_2dfd_0020(char far *name, void far *buf, void far *pal, int a, long b);
void ovr_2dfd_002a(struct anim far *p, int frame, int a, int b, int c, int d);
void ovr_2dfd_0025(struct anim far *p);
void ovr_2ded_0020(char far *name, void far *buf, long n);
void ovr_2d5f_0048(void);
void ovr_2d5f_004d(void);
void fn_067a_0401(long v);
void fn_1ef2_001c(void far *pal);
void fn_1ef2_0075(void far *pal, int t, long a);

/* 32-bit subtraction codegen differs (sub/sbb operand order); original bytes transplanted */
/* C version: BCC 3.1 does not reproduce the original code from it (tools/inlasm.py) */
#if 0
unsigned char far *ovr_2cf7_0025(unsigned char far *dst, unsigned char far *a, unsigned char far *b, int n)
{
    int acc;
    int step;
    unsigned char far *d0;
    unsigned char far *pa;
    unsigned char far *pb;
    int i, j;

    d0 = dst;
    pa = a;
    pb = b;
    for (i = 0; i < 0x300; i++) {
        *dst = (long)*pb - *pa;
        pa++;
        pb++;
        dst++;
    }
    acc = 0;
    step = 0x100 / n;
    n--;
    for (j = 1; j < n; j++) {
        pa = a;
        pb = d0;
        acc += step;
        for (i = 0; i < 0x300; i++) {
            *dst = *pa + (((char)*pb * acc) >> 8);
            pb++;
            pa++;
            dst++;
        }
    }
    fn_2279_025b(a, d0, 0x300L);
    fn_2279_025b(b, dst, 0x300L);
    return dst + 0x300;
}
#endif
unsigned char far *ovr_2cf7_0025(unsigned char far *dst, unsigned char far *a, unsigned char far *b, int n)
{
    char _l[16];
    _SI;   /* saved by the original */
    _DI;   /* saved by the original */
    asm mov si,[bp+12h]
    asm db 66h	/* mov eax,[bp+0x6] */
    asm mov ax,[bp+6]
    asm db 66h	/* mov [bp-0x8],eax */
    asm mov word ptr _l+8,ax
    asm db 66h	/* mov eax,[bp+0xa] */
    asm mov ax,[bp+0ah]
    asm db 66h	/* mov [bp-0xc],eax */
    asm mov word ptr _l+4,ax
    asm db 66h	/* mov eax,[bp+0xe] */
    asm mov ax,[bp+0eh]
    asm db 66h	/* mov [bp-0x10],eax */
    asm mov word ptr _l,ax
    asm db 33h, 0c9h	/* xor cx,cx */
L_0025:
    asm les bx,dword ptr _l
    asm mov al,es:[bx]
    asm mov ah,0
    asm les bx,dword ptr _l+4
    asm mov dl,es:[bx]
    asm mov dh,0
    asm db 33h, 0dbh	/* xor bx,bx */
    asm db 2bh, 0c2h	/* sub ax,dx */
    asm sbb bx,0
    asm push bx
    asm push ax
    asm db 66h	/* pop eax */
    asm pop ax
    asm les bx,dword ptr [bp+6]
    asm mov es:[bx],al
    asm inc word ptr _l+4
    asm inc word ptr _l
    asm inc word ptr [bp+6]
    asm inc cx
    asm cmp cx,300h
    asm jl L_0025
    asm mov word ptr _l+14,0
    asm mov ax,100h
    asm cwd
    asm idiv si
    asm mov word ptr _l+12,ax
    asm dec si
    asm mov di,1
    asm db 3bh, 0feh	/* cmp di,si */
    asm jnl L_00b4
L_006c:
    asm db 66h	/* mov eax,[bp+0xa] */
    asm mov ax,[bp+0ah]
    asm db 66h	/* mov [bp-0xc],eax */
    asm mov word ptr _l+4,ax
    asm db 66h	/* mov eax,[bp-0x8] */
    asm mov ax,word ptr _l+8
    asm db 66h	/* mov [bp-0x10],eax */
    asm mov word ptr _l,ax
    asm mov ax,word ptr _l+12
    asm add word ptr _l+14,ax
    asm db 33h, 0c9h	/* xor cx,cx */
L_0084:
    asm les bx,dword ptr _l
    asm mov al,es:[bx]
    asm cbw
    asm imul word ptr _l+14
    asm sar ax,8
    asm les bx,dword ptr _l+4
    asm mov dl,es:[bx]
    asm db 2, 0d0h	/* add dl,al */
    asm les bx,dword ptr [bp+6]
    asm mov es:[bx],dl
    asm inc word ptr _l
    asm inc word ptr _l+4
    asm inc word ptr [bp+6]
    asm inc cx
    asm cmp cx,300h
    asm jl L_0084
    asm inc di
    asm db 3bh, 0feh	/* cmp di,si */
    asm jl L_006c
L_00b4:
    asm db 66h, 68h, 0, 3, 0, 0	/* push dword 0x300 */
    asm db 66h	/* push dword [bp-0x8] */
    asm push word ptr _l+8
    asm db 66h	/* push dword [bp+0xa] */
    asm push word ptr [bp+0ah]
    asm call far ptr fn_2279_025b
    asm add sp,0ch
    asm db 66h, 68h, 0, 3, 0, 0	/* push dword 0x300 */
    asm db 66h	/* push dword [bp+0x6] */
    asm push word ptr [bp+6]
    asm db 66h	/* push dword [bp+0xe] */
    asm push word ptr [bp+0eh]
    asm call far ptr fn_2279_025b
    asm add sp,0ch
    asm mov dx,[bp+8]
    asm mov ax,[bp+6]
    asm add ax,300h
Lret:
    ;
}

static unsigned char far *mkpal(void)
{
    unsigned char far *ret;
    unsigned char far *p;
    unsigned char far *buf;
    unsigned char far *r;

    buf = fn_215f_0003(3);
    r = buf + 0x300;
    ret = r + 0x300;
    ovr_2ded_0020(g_081a, buf, 0x300L);
    p = ovr_2cf7_0025(ret, g_2fac, buf, 0x15);
    ovr_2ded_0020(g_0827, p, 0x300L);
    r = p;
    p += 0x300;
    ovr_2ded_0020(g_0834, buf, 0x300L);
    p = ovr_2cf7_0025(p, r, buf, 4);
    return ret;
}

int ovr_2cf7_0020(void)
{
    struct anim far *a;
    unsigned char far *pal;
    unsigned long t;
    int i;

    fn_1ebc_00e7();
    ovr_2d5f_0048();
    a = ovr_2dfd_0020(g_0841, fn_215f_0003(5), g_369f, 2, 0L);
    if (a == 0) return 0;
    pal = mkpal();
    for (i = 0; i < 0x15; i++) {
        t = g_384c + 0x14;
        ovr_2dfd_002a(a, i, 0, 0, 0, 0);
        fn_1ef2_001c(pal);
        pal += 0x300;
        if (i == 2 || i == 5 || i == 8 || i == 0xb || i == 0xd || i == 0xf || i == 0x11 || i == 0x13)
            fn_067a_0401(0x5fL);
        while (t > g_384c) ;
    }
    fn_067a_0401(0x5bL);
    fn_1ef2_0075(pal, 0x12c, 0L);
    pal += 0x300;
    for (i = 0x16; i < 0x26; i++) {
        t = g_384c + 0xc;
        ovr_2dfd_002a(a, i, 0, 0, 0, 0);
        if (i == 0x16 || i == 0x18 || i == 0x1c || i == 0x20) {
            fn_067a_0401(0x83L);
            fn_1ef2_001c(pal);
            pal += 0x300;
        }
        while (t > g_384c) ;
    }
    ovr_2dfd_0025(a);
    ovr_2d5f_004d();
    fn_1ebc_00fe();
    return 1;
}
