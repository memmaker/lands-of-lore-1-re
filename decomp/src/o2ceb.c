/* o2ceb: build the button lists of the game screens (button templates f_2568_0000 -> instances f_2803_0592) */
#include "lol.h"

struct BtnDef {                /* 0x16 bytes, f_2568_0000[] */
    int w0, w2, w4;
    long l6;
    int wA, wC, wE, w10, w12, w14;
};
struct Btn {                   /* 0x3c bytes, f_2803_0592[] */
    char p0[4];
    int w4, w6, w8;
    char pA[4];
    int wE;
    char p10[0x0c];
    int w1c, w1e, w20, w22, w24;
    char p26[0x0a];
    long l30;
    char p34[4];
    int w38, w3a;
};
extern struct BtnDef far f_2568_0000[];
extern struct Btn far f_2803_0592[];
extern struct Btn far f_27b1_0010;
extern int far f_2803_3625[];
extern int far f_27b1_0160[];
extern char far f_27b1_016a[][0x16];
extern int far f_25eb_0000[];
extern int far f_25f0_0000[];
extern int far f_25f2_0000[];
extern int far f_25f3_0000[];
extern int far f_25f5_0000[];
extern int far f_25f7_0000[];
extern int far f_25f9_0000[];
extern int far f_25fa_0000[];
extern int g_4b00;
extern void far *g_7fae;
extern unsigned char g_81f2[];
extern unsigned g_806a;
void fn_2279_025b(void far *d, void far *s, long n);
void far *fn_20bf_0006(void far *list, struct Btn far *b);
void fn_163d_0004(void);
int ovr_2d74_0025(void);

static struct Btn far *mkbtn(int id)
{
    struct Btn far *b;
    struct BtnDef far *d;

    b = &f_2803_0592[g_4b00];
    d = &f_2568_0000[id];
    fn_2279_025b(&f_27b1_0010, b, 0x3cL);
    b->w4 = (unsigned)++g_4b00;
    b->w6 = d->w2;
    b->w8 = d->w4;
    b->wE = d->w0;
    b->w1e = d->wA;
    b->w20 = d->wC;
    b->w22 = d->wE - 1;
    b->w24 = d->w10 - 1;
    b->l30 = d->l6;
    b->w38 = d->w12;
    b->w1c = d->w14;
    b->w3a = id;
    return b;
}

static void addlist(int far *ids)
{
    struct Btn far *b;

    while (*ids != -1) {
        b = mkbtn(*ids++);
        g_7fae = fn_20bf_0006(g_7fae, b);
    }
}

static void reset(void)
{
    fn_163d_0004();
    g_4b00 = 0;
    g_7fae = 0;
}

static void addspells(void)
{
    struct Btn far *b;
    int i, n;

    n = i = 0;
    for (; i < 7; i++) {
        if (g_81f2[i] != 0xff) {
            f_2568_0000[n + 0x47].w12 = i;
            b = mkbtn(n + 0x47);
            g_7fae = fn_20bf_0006(g_7fae, b);
            n++;
        }
    }
}

static void addrange(int first, int dx)
{
    int n;
    struct Btn far *b;
    int i;

    n = ovr_2d74_0025();
    for (i = 0; i < n; i++) {
        f_2568_0000[first + i].wA = f_2803_3625[i] + dx;
        b = mkbtn(first + i);
        g_7fae = fn_20bf_0006(g_7fae, b);
    }
}

void ovr_2ceb_0020(void)
{
    reset();
    addlist(f_25eb_0000);
    addrange(7, 0x2c);
    addrange(0xb, 0x2c);
    addrange(0x11, 0);
    addrange(0x1d, 0);
    addrange(0x19, 0x21);
    if (g_806a & 0x2000) addspells();
}

static void addinv(int c)
{
    struct Btn far *b;
    char far *p;
    int i;

    p = f_27b1_016a[f_27b1_0160[f_2803_362d[c].cD]];
    for (i = 0; i < 11; p += 2, i++) {
        if (*p != -1) {
            f_2568_0000[i + 0x21].wA = p[0];
            f_2568_0000[i + 0x21].wC = p[1];
            b = mkbtn(i + 0x21);
            b->w38 = i;
            g_7fae = fn_20bf_0006(g_7fae, b);
        }
    }
}

void ovr_2ceb_0025(int c)
{
    reset();
    addlist(f_25f0_0000);
    addinv(c);
    addrange(0x15, 0);
}

void ovr_2ceb_002a(int x, int y, int w, int h, int flags)
{
    reset();
    f_2568_0000[0x40].wA = x;
    f_2568_0000[0x40].wC = y;
    f_2568_0000[0x40].wE = w;
    f_2568_0000[0x40].w10 = h;
    addlist(f_25f2_0000);
    if (flags & 1) addlist(f_25f3_0000);
    if (flags & 2) addlist(f_25f5_0000);
}

void ovr_2ceb_002f(int c)
{
    reset();
    addlist(f_25f7_0000);
    addinv(c);
}

void ovr_2ceb_0034(int c)
{
    reset();
    f_2568_0000[0xf].wA = f_2803_3625[c] + 0x2c;
    f_2568_0000[0xf].w12 = c;
    addlist(f_25f9_0000);
}

void ovr_2ceb_0039(void)
{
    reset();
    addrange(0x51, 0);
    addlist(f_25fa_0000);
}
