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
/* NONMATCHING */
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
