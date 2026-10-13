/* s019: EMC script opcodes (game callbacks called through EmcData.opcodes) */
#include <mem.h>
#include <stdio.h>
#include <process.h>
#include "lol.h"

extern unsigned char g_531e[];
extern int g_7fdf;
extern struct EmcData far f_2803_3611;
extern int far f_2803_363b;
extern int far f_2c0c_0000[];
extern char g_ad99[], g_ae59[], g_aeaa[];
extern char g_20db;
char far *ovr_2d46_002f(char far *s, int n);
void fn_2309_000c(void);
void fn_0845_1536(void);
void fn_0845_08aa(void);
void fn_2148_002c(int d);
void fn_2148_014d(char far *s);
void ovr_2d2c_00e8(void);
int fn_154c_0057(int id, int a, int b);
int fn_154c_010f(int a, int b);

int fn_0845_0636(int lo, int hi);
void fn_0845_155d(int a);
void fn_130a_0360(int a, int b, int c);
void fn_0845_15d9(int a);
extern char far f_27b1_0010[];
extern unsigned g_804c[];
extern int g_3713;
void fn_09aa_0197(char far *p);
void fn_09aa_026a(char far *p);
void fn_09aa_01e4(char far *p);
void fn_09aa_0219(char far *p);
void fn_09aa_02bb(char far *p);
void fn_09aa_033f(char far *p);
void fn_130a_0001(int n);
void fn_14b3_0122(int n);
void fn_14b3_0284(char far *s);
int fn_2315_0018(int w);
void fn_0845_0bb6(int a);
int fn_0845_0ac7(void);
void fn_07bc_044c(int it);
void fn_0845_0acf(int a);
int fn_07bc_012d(int type, int flags, int flags2);
void fn_130a_0052(int it, int a, int b, int c, int d, int e);
extern struct ItemType far *g_7fb2;

extern struct Anim g_4ee0[];
extern long g_384c;
extern char far *g_4bec, far *g_4bf0, far *g_4edc;
extern int g_3711, g_ad8b, g_ad8d, g_ad8f, g_ad91, g_1f87, g_1f89, g_20d5;
extern int g_8114[], g_81e2[];
extern char far f_2803_0000[];
extern int g_7fd0, g_7fd2, g_7fd4, g_81e0, g_abb8;
extern unsigned g_7fd6;
extern char g_7fe5, g_81dc, g_7fdc, g_7fdd, g_7fde, g_81fe, g_81ff;
extern unsigned char g_81dd;
void fn_0a21_06fd(int ch, int what, int v, int d);
int ovr_2cef_0020(char far *w);
int ovr_2cef_0025(char far *w);
void fn_1ebc_0111(int x1, int y1, int x2, int y2);
void fn_1dbc_0004(int a, int b, int c, int d, int e, int f, int g, int h);
void ovr_2dfd_002a(char far *w, int frame, int x, int y, int flags, ...);
void fn_1ebc_01ec(void);
void fn_0845_0be0(long t);
int fn_0845_03b4(int a, int b, int c, int d);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_1e59_001d(int x1, int y1, int x2, int y2, int c);
void fn_14b3_01fa(int n);
void fn_130a_0c28(int a, int b);
void fn_0845_08d9(int a);
void fn_1ef2_0075(char far *p, int a, int b, int c);
void ovr_2ded_002f(char far *str, int a, int b, char far *p);
void fn_1dff_0008(int a, int b);
void fn_130a_0cf6(int a);
void fn_1aff_030e(int far *x, int far *y, int b, int cx, int cy);
void fn_09aa_05b3(int b);
void fn_0bbc_058a(int a);
void fn_231c_0048(int a);
void fn_231c_0008(int a);
void fn_09aa_0007(int a, int b);
void fn_13e8_0358(int b, int open, int c);
void fn_0845_03d4(int a);
void fn_2279_025b(char far *d, char far *s, long n);
void fn_0845_1430(char far *p);
void ovr_2d5f_00f2(void);
extern char far *g_adea;
extern struct MonType far f_2803_1b5e[];
extern int far f_2803_002c[];
int fn_0d6c_0338(int x, int y, int size, int flags, int f);
int fn_0845_1036(void);
int fn_1aff_0420(int a, int b);
int fn_070c_012a(int who, int dmg);
void fn_0d6c_0995(struct Monster far *m, int mode);
void fn_0d6c_0742(struct Monster far *m, int x, int y);
void fn_0845_046c(int b);
int fn_070c_0253(int a);
int fn_070c_044a(int att, int def, int k);
int fn_070c_07f5(int who, int dmg, int src, int k, int how);
int fn_1afa_0010(int x1, int y1, int x2, int y2);
void fn_0d6c_0073(struct Monster far *m, int dir);
char far *fn_0845_06f8(int id);
void fn_13e8_0903(int n, char far *a, char far *b, char far *c);
int fn_13e8_06a1(void);
void ovr_2d0e_002f(int a, int b);
void ovr_2d0e_0034(int a, int b);
void fn_0bbc_070e(int a, int b);
void fn_0bbc_07b1(int a, int b);
int fn_0c59_03a8(int h);
void fn_070c_00cf(int who, int cls, long exp);
struct TimHdr { int magic; int stop; int numStart; int offFuncs; int offWsa; int offAvtl; int offText; };
struct TimFunc { int far *ip; long lastTime; long nextTime; int far *loopIp; int w10; int w12; int far *avtl; };
struct TimHdr far *fn_0638_0008(char far *name, struct TimHdr far *buf, unsigned long bufSize);
void fn_0638_018b(struct TimHdr far *t);
int fn_0638_01e5(struct TimHdr far *p, int loop);
void fn_0d6b_000f(void);
extern struct TimHdr far *g_20fc[];
extern char far f_2803_0053[];
void ovr_2d2c_00b1(struct Monster far *m, int it);
void fn_067a_0401(int n, int force);
void fn_067a_02f5(int n, int pos);
int fn_0d6c_059d(int x, int y, struct Monster far *m, int fl);
void fn_0845_093a(void);
void fn_154c_000f(int a);
void fn_130a_0784(void);
int fn_130a_03cd(int a, int b, int c, char far *str, struct EmcState far *s, int far *p, int e);
void ovr_2d18_002a(int a, int b);
void fn_070c_0a8f(int a, int b, int c);
void fn_0a21_022b(int ch);
void fn_067a_003e(int a);
int fn_067a_01d1(int a);
struct Item far *fn_080e_000b(int it);
int ovr_2d74_0025(void);
void fn_0845_01c4(unsigned flags, char far *fmt, ...);
int fn_070c_0793(int who, int ch, int t);
int fn_070c_07e3(int dmg);
void fn_07bc_0367(int it, int b);
int fn_070c_06a3(int a, int b, int c, int d, int e);
void fn_0bbc_0365(struct Char far *c, int a, int b);
extern int g_7fe6[];
void fn_0845_1343(int b, unsigned mask, int c, int d, int e, int f);
void ovr_2d5f_012e(void);
void ovr_2d5f_0133(int a);
void fn_130a_0a7c(int n, char far *str, struct EmcState far *s, int far *p, int e);
int fn_154c_01d3(int a, int b, int c);
extern int g_20d7, g_4bea, g_20ec;
void fn_0845_0bf6(void);
void fn_163d_0004(void);
int fn_154c_0136(void);
int fn_2169_060c(void);
int fn_2169_0790(void);
void fn_2169_0945(int k);
void fn_2169_062e(void);
void fn_14b3_0215(void);
void ovr_2ce1_007f(char far *msg);
int fn_0a21_0997(int ch, int type);
extern int g_2794, g_4bde, g_4be0, g_4bb2, g_4bb4;
void ovr_2d46_0039(int a, int b, int c, int d, int e, int f, int g, int h);
void fn_1aff_03b4(int far *x, int far *y, int d);
extern int g_2796;
int ovr_2d00_0025(int a, int b, int c, int d, int e);
void fn_0a21_05ce(void);
void fn_0c59_0377(void);
int fn_130a_0d2b(int a, int b, int c);
extern char far *g_540e;
extern char g_7fe3, g_1f3a;
extern int g_2798[];
int fn_0c59_0410(int a, int b);
int fn_09aa_0183(int b, int dir);
int ovr_2d8a_0039(int a, int b, int c);
void fn_0845_0f86(char far *src, char far *dst, int n);
void fn_234e_0003(int n);
void fn_234e_0062(void);
void fn_1dbc_0017(int a, int b, int c, int d, int e, int f, int g, int h);
void fn_1f24_003f(int a, int b, int c, int d, int e, char far *tbl);
void fn_1ef2_001c(char far *pal);
void fn_1ebc_022a(int a, char b, char c);
void fn_2120_0007(int n);
int ovr_2cf7_0020(void);
void ovr_2d28_0034(int a, int b, int c, int d);
int fn_0845_1280(int a, int b, int c);
struct Win { int a, b; char pad[12]; };
extern struct Win g_1f47[];
int fn_0b6b_032f(int type, int item, int x, int y, int power, int dir, int unused, int owner, int e);

void fn_0fbe_000c(int fn)
{
    struct EmcState st;

    fn_0f28_032c(&st, &f_2803_3611);
    fn_0f28_035f(&st, fn);
    while (fn_0f28_04a0(&st))
        ;
}

int fn_0fbe_004c(struct EmcState far *s)
{
    return 0;
}

int fn_0fbe_0053(struct EmcState far *s)
{
    return fn_0845_0636(ARG(s, 0), ARG(s, 1));
}

int fn_0fbe_007f(struct EmcState far *s)
{
    int b;
    int y;
    int x;

    b = ARG(s, 2);
    y = ARG(s, 1);
    x = ARG(s, 0);
    if (g_531e[b] & 4) fn_0845_155d(x);
    fn_130a_0360(x, y, b);
    return 1;
}

int fn_0fbe_00dd(struct EmcState far *s)
{
    return WALL(ARG(s, 0), ARG(s, 1) & 3);
}

int fn_0fbe_0110(struct EmcState far *s)
{
    return g_531e[WALL(ARG(s, 0), ARG(s, 1) & 3)];
}

int fn_0fbe_014b(struct EmcState far *s)
{
    fn_0845_15d9(ARG(s, 0));
    return 1;
}

int fn_0fbe_0168(struct EmcState far *s)
{
    int d;

    d = ARG(s, 0);
    if (d >= 6 && d <= 9)
        d = (d - 6 - g_7fdf) & 3;
    switch (d) {
    case 0: fn_09aa_0197(f_27b1_0010); break;
    case 1: fn_09aa_026a(f_27b1_0010); break;
    case 2: fn_09aa_01e4(f_27b1_0010); break;
    case 3: fn_09aa_0219(f_27b1_0010); break;
    case 4: fn_09aa_02bb(f_27b1_0010); break;
    case 5: fn_09aa_033f(f_27b1_0010); break;
    case 10: case 11: case 12: case 13:
        fn_130a_0001(d - 10);
        break;
    }
    return 1;
}

int fn_0fbe_021a(struct EmcState far *s)
{
    fn_14b3_0122(3);
    g_3713 = 0xfe;
    fn_14b3_0284((char far *)s->dat->text + fn_2315_0018(s->dat->text[ARG(s, 0)]));
    return 1;
}

int fn_0fbe_0273(struct EmcState far *s)
{
    fn_0845_0bb6(ARG(s, 0));
    return 1;
}


int fn_0fbe_0290(struct EmcState far *s)
{
    unsigned n;

    n = ARG(s, 0);
    if (ARG(s, 1))
        g_804c[n >> 4] |= 1 << (n & 15);
    else
        g_804c[n >> 4] &= ~(1u << (n & 15));
    return 1;
}


int fn_0fbe_02e8(struct EmcState far *s)
{
    int n;

    n = ARG(s, 0);
    if (n < 0) return 0;
    return (g_804c[n >> 4] & (1u << (n & 15))) > 0 ? 1 : 0;
}

int fn_0fbe_0322(struct EmcState far *s)
{
    int it;

    it = fn_0845_0ac7();
    fn_07bc_044c(it);
    fn_0845_0acf(0);
    return it;
}

int fn_0fbe_0341(struct EmcState far *s)
{
    return fn_07bc_012d(ARG(s, 0), ARG(s, 1), ARG(s, 2));
}

int fn_0fbe_037f(struct EmcState far *s)
{
    fn_130a_0052(ARG(s, 0), ARG(s, 1), ARG(s, 2), (unsigned char)ARG(s, 3), (unsigned char)ARG(s, 4), ARG(s, 5));
    return 1;
}

int fn_0fbe_03fc(struct EmcState far *s)
{
    int it;

    it = fn_07bc_012d(ARG(s, 0), ARG(s, 1), ARG(s, 2));
    if (it != -1)
        fn_130a_0052(it, ARG(s, 3), ARG(s, 4), ARG(s, 5), ARG(s, 6), ARG(s, 7));
    return it;
}


int fn_0fbe_04a8(struct EmcState far *s)
{
    struct ItemType far *t;
    struct Item far *it;
    int r;

    r = ARG(s, 0);
    if (r < 1) return 0;
    it = &f_2803_1cfd[r];
    t = &g_7fb2[it->type];
    switch (ARG(s, 1)) {
    case 0: r = it->block; break;
    case 1: r = it->x; break;
    case 2: r = it->y; break;
    case 3: r = it->level; break;
    case 4: r = it->type; break;
    case 5: r = it->flags; break;
    case 6: r = t->name; break;
    case 16: r = t->flags; break;
    case 8: r = t->shape; break;
    case 9: r = t->w5; break;
    case 10: r = t->script; break;
    case 11: case 12: case 13: r = (&t->w8)[ARG(s, 1) - 11]; break;
    case 17: r = t->c9; r <<= 8; r |= t->w8; break;
    case 14: r = t->wb; break;
    case 15: r = it->flags & 0x1fff; break;
    default: r = -1; break;
    }
    return r;
}

int fn_0fbe_05fa(struct EmcState far *s)
{
    struct Item far *it;
    int v;

    v = ARG(s, 0);
    if (v < 1) return 0;
    it = &f_2803_1cfd[v];
    v = ARG(s, 2);
    switch (ARG(s, 1)) {
    case 15:
        v &= 0x1fff;
        it->flags &= 0xe000;
        it->flags |= v;
        break;
    case 4: it->type = v; break;
    default: v = -1; break;
    }
    return v;
}

int fn_0fbe_0677(struct EmcState far *s)
{
    struct Char far *c;
    int i;
    int r;

    r = 0;
    c = &f_2803_362d[ARG(s, 0)];
    i = ARG(s, 2);
    switch (ARG(s, 1)) {
    case 0: r = c->flags; break;
    case 1: r = c->cD; break;
    case 5: r = c->hp; break;
    case 6: r = c->maxHp; break;
    case 7: r = c->mp; break;
    case 8: r = c->maxMp; break;
    case 9: r = c->w37; break;
    case 10: r = c->items[i]; break;
    case 11: r = c->skill[i] + c->skillBonus[i]; break;
    case 14: r = c->skillBonus[i]; break;
    case 12: r = c->st.res[i]; break;
    case 13:
        if (i & 0x80) r = c->st.dmg[7];
        else r = c->st.dmg[i];
        break;
    case 15: r = c->wE; break;
    }
    return r;
}

int fn_0fbe_079e(struct EmcState far *s)
{
    struct Char far *c;
    int i;
    int v;

    c = &f_2803_362d[ARG(s, 0)];
    i = ARG(s, 2);
    v = ARG(s, 3);
    switch (ARG(s, 1)) {
    case 0: c->flags = v; break;
    case 1: c->cD = v; break;
    case 5: fn_0a21_06fd(ARG(s, 0), 0, v, 0); break;
    case 6: c->maxHp = v; break;
    case 7: fn_0a21_06fd(ARG(s, 0), 1, v, 0); break;
    case 8: c->maxMp = v; break;
    case 9: c->w37 = v; break;
    case 10: c->items[i] = v; break;
    case 11: c->skill[i] = v; break;
    case 14: c->skillBonus[i] = v; break;
    case 12: c->st.res[i] = v; break;
    case 13:
        if (i & 0x80) c->st.dmg[7] = v;
        else c->st.dmg[i] = v;
        break;
    }
    return 0;
}

int fn_0fbe_08cb(struct EmcState far *s)
{
    long t;
    int to;
    int delay;
    int f;
    struct Anim far *a;
    register int fr;
    register int step;
    int from;

    a = &g_4ee0[ARG(s, 0)];
    from = ARG(s, 1);
    to = ARG(s, 2);
    delay = ARG(s, 3);
    if (to < from) step = -1;
    else step = 1;
    for (fr = from; fr != to + step; fr += step) {
        t = g_384c + delay;
        fn_1ebc_0111(a->x, a->y, a->x + ovr_2cef_0020(a->wsa), a->y + ovr_2cef_0025(a->wsa));
        if (a->flags & 0x4000) {
            f = (a->flags & 0x1000) ? 0x5000 : 0x4000;
            fn_1dbc_0004(0x70, 0, 0x70, 0, 0xb0, 0x78, 6, 2);
            ovr_2dfd_002a(a->wsa, fr - 1, a->x, a->y, 2, f, g_4bec, g_4bf0);
            fn_1dbc_0004(0x70, 0, 0x70, 0, 0xb0, 0x78, 2, 0);
        } else
            ovr_2dfd_002a(a->wsa, fr - 1, a->x, a->y, 0, 0);
        fn_1ebc_01ec();
        fn_0845_0be0(t);
    }
    return 1;
}

int fn_0fbe_0a4a(struct EmcState far *s)
{
    return g_7fdf;
}

int fn_0fbe_0a52(struct EmcState far *s)
{
    return fn_0845_03b4(ARG(s, 0), ARG(s, 1), ARG(s, 2), ARG(s, 3));
}

int fn_0fbe_0aa2(struct EmcState far *s)
{
    if (f_2803_0000[0x45] && !g_81fe) return 1;
    fn_14b3_0122(5);
    fn_1ebc_00e7();
    fn_1e59_001d(g_ad8d, g_ad8b, g_ad8d + (unsigned)g_ad8f - 2, g_ad8b + (unsigned)g_ad91 - 2, g_3711);
    fn_14b3_01fa(4);
    fn_1ebc_00fe();
    g_1f87 = 0;
    g_1f89 = 0;
    return 1;
}

int fn_0fbe_0b0f(struct EmcState far *s)
{
    int far *p;

    p = g_4ee0[ARG(s, 0)].frames[ARG(s, 1)];
    p[0] = ARG(s, 2);
    p[1] = ARG(s, 3);
    p[2] = ARG(s, 4);
    p[3] = ARG(s, 5);
    p[4] = ARG(s, 6);
    p[5] = ARG(s, 7);
    p[6] = ARG(s, 8);
    p[7] = ARG(s, 9);
    return 0;
}

int fn_0fbe_0c11(struct EmcState far *s)
{
    fn_130a_0c28(ARG(s, 0), ARG(s, 1));
    return 1;
}

int fn_0fbe_0c40(struct EmcState far *s)
{
    fn_1ebc_00e7();
    return 1;
}

int fn_0fbe_0c4d(struct EmcState far *s)
{
    fn_1ebc_00fe();
    return 1;
}

int fn_0fbe_0c5a(struct EmcState far *s)
{
    fn_0845_08d9(10);
    return 1;
}

int fn_0fbe_0c6a(struct EmcState far *s)
{
    fn_1ef2_0075(g_4edc, 10, 0, 0);
    g_20d5 = 0;
    return 1;
}

int fn_0fbe_0c8a(struct EmcState far *s)
{
    ovr_2ded_002f((char far *)s->dat->text + fn_2315_0018(s->dat->text[ARG(s, 0)]), 3, 3, g_4edc);
    if (ARG(s, 1) != 2) {
        fn_1ebc_00e7();
        fn_1dff_0008(3, ARG(s, 1));
        fn_1ebc_00fe();
    }
    return 1;
}

int fn_0fbe_0d17(struct EmcState far *s)
{
    fn_130a_0cf6(ARG(s, 0));
    return 1;
}

int fn_0fbe_0d34(struct EmcState far *s)
{
    g_4ee0[ARG(s, 0)].cd = 1;
    return 1;
}

int fn_0fbe_0d54(struct EmcState far *s)
{
    g_4ee0[ARG(s, 0)].cc = 1;
    g_4ee0[ARG(s, 0)].cd = 1;
    return 1;
}

int fn_0fbe_0d8c(struct EmcState far *s)
{
    g_8114[ARG(s, 0)] = ARG(s, 1);
    return 1;
}

int fn_0fbe_0db9(struct EmcState far *s)
{
    return g_8114[ARG(s, 0)];
}

int fn_0fbe_0dd3(struct EmcState far *s)
{
    int i;
    int r;

    r = 0;
    i = ARG(s, 1);
    switch (ARG(s, 0)) {
    case 12: r = g_7fde; break;
    case 11: r = g_7fdd; break;
    case 0: r = g_7fd0; break;
    case 1: r = g_7fdf; break;
    case 2: r = g_7fe5; break;
    case 3: r = fn_0845_0ac7(); break;
    case 4: r = g_81dc; break;
    case 5: r = g_81e0; break;
    case 6: r = g_81e2[i]; break;
    case 8: r = g_7fd6; break;
    case 9: r = g_81dd; break;
    case 10: r = g_7fdc; break;
    case 13: r = g_81ff; break;
    case 14: r = g_abb8; break;
    }
    return r;
}

/* NONMATCHING original keeps the index in cx instead of a stack slot */
int fn_0fbe_0e81(struct EmcState far *s)
{
    int v;
    int i;

    i = ARG(s, 1);
    v = ARG(s, 2);
    switch (ARG(s, 0)) {
    case 12: g_7fde = v; break;
    case 11: g_7fdd = v; break;
    case 0:
        g_7fd0 = v;
        fn_1aff_030e(&g_7fd2, &g_7fd4, g_7fd0, 0x80, 0x80);
        fn_09aa_05b3(g_7fd0);
        break;
    case 1: g_7fdf = v; break;
    case 2: g_7fe5 = v; break;
    case 3: fn_0845_0acf(v); break;
    case 4: g_81dc = v; break;
    case 5: g_81e0 = v; break;
    case 6: g_81e2[i] = v; break;
    case 8:
        g_7fd6 = v;
        if (v == 1) {
            if (!g_81fe && !(f_2803_0000[0x45] & 2)) fn_0bbc_058a(1);
            fn_231c_0048(2);
        } else
            fn_231c_0008(2);
        break;
    case 9: g_81dd = v; break;
    case 10:
        g_7fdc = v;
        fn_09aa_0007(0, 0);
        break;
    }
    return 1;
}

int fn_0fbe_0f94(struct EmcState far *s)
{
    int open;
    int b;

    b = ARG(s, 0);
    open = (g_531e[WALL(b, 0)] & 8) ? 0 : 1;
    fn_13e8_0358(b, open, ARG(s, 1));
    return 1;
}

int fn_0fbe_0fe7(struct EmcState far *s)
{
    int it;
    int ch;
    int i;
    int sc;

    ch = 0;
    do {
        if (f_2803_362d[ch].flags & 1) {
            for (i = 0; i <= 3; i++) {
                if ((it = f_2803_362d[ch].items[i]) != 0) {
                    sc = g_7fb2[f_2803_1cfd[it].type].script;
                    if (sc == 0 || sc == 2) return 1;
                }
            }
        }
        ch++;
    } while (ch < 4);
    return 0;
}

int fn_0fbe_1063(struct EmcState far *s)
{
    int b;
    int d;

    b = ARG(s, 0);
    d = ARG(s, 1);
    if (d != -1) {
        if (WALL(b, d) == ARG(s, 2))
            fn_130a_0360(b, d, ARG(s, 3));
        else
            fn_130a_0360(b, d, ARG(s, 2));
    } else {
        d = WALL(b, 0) == ARG(s, 2) ? ARG(s, 3) : ARG(s, 2);
        fn_130a_0360(b, -1, d);
    }
    return 0;
}

int fn_0fbe_1126(struct EmcState far *s)
{
    fn_1ebc_00e7();
    fn_1dbc_0004(ARG(s, 0), ARG(s, 1), ARG(s, 2), ARG(s, 3), ARG(s, 4), ARG(s, 5), ARG(s, 6), ARG(s, 7));
    fn_1ebc_00fe();
    return 1;
}

int fn_0fbe_11cb(struct EmcState far *s)
{
    fn_0845_03d4(10);
    return 1;
}

int fn_0fbe_11db(struct EmcState far *s)
{
    fn_2279_025b(g_adea + 0x180, g_4edc + 0x180, 0x180L);
    fn_0845_1430(g_4edc);
    fn_1ef2_0075(g_4edc, 10, 0, 0);
    g_20d5 = 0;
    return 1;
}

int fn_0fbe_122c(struct EmcState far *s)
{
    ovr_2d5f_00f2();
    return 1;
}

int fn_0fbe_1239(struct EmcState far *s)
{
    struct Monster far *m;
    int i;
    int x;
    int y;
    int size;
    register int type;
    int j;
    int stop;

    fn_1aff_030e(&x, &y, ARG(s, 0), ARG(s, 1), ARG(s, 2));
    type = ARG(s, 4);
    size = f_2803_1b5e[type].size;
    if (fn_0d6c_0338(x, y, size, 7, 7)) return -1;
    for (m = f_2803_15fa, i = 0; i < 30; i++, m++) {
        if (!m->hp && m->mode != 13) {
            setmem(m, 0x2e, 0);
            m->id = i;
            m->x = x;
            m->y = y;
            m->facing = ARG(s, 3);
            m->c20 = ARG(s, 4);
            m->type = &f_2803_1b5e[type];
            m->dir = m->facing << 1;
            m->hp = fn_1aff_0420(m->type->maxHp, f_2803_002c[fn_0845_1036()]);
            if (g_7fe5 != 12 || m->c20 != 2)
                m->hp = fn_1aff_0420(m->hp, fn_0845_0636(1, 0x80) + 0xc0);
            if (m->hp <= 0) m->hp = 1;
            m->c25 = m->type->w42;
            m->c27 = fn_0845_0636(1, fn_070c_012a(m->id | 0x8000, 8)) - 1;
            m->c04 = 2;
            m->flags = ARG(s, 5);
            m->items = 0;
            fn_0d6c_0995(m, ARG(s, 6));
            fn_0d6c_0742(m, m->x, m->y);
            m->tx = m->x;
            m->ty = m->y;
            m->tdir = m->dir;
            for (stop = j = 0; j < 4; j++) {
                if (s->stack[j + s->sp + 7] == 0) stop = 1;
                if (!stop) m->c2a[j] = s->stack[j + s->sp + 7];
                else m->c2a[j] = 0;
            }
            fn_0845_046c(m->block);
            return i;
        }
    }
    return -1;
}

int fn_0fbe_14fb(struct EmcState far *s)
{
    return fn_070c_0253(ARG(s, 0));
}

int fn_0fbe_1515(struct EmcState far *s)
{
    return 0;
}

int fn_0fbe_151c(struct EmcState far *s)
{
    return fn_070c_044a(ARG(s, 0), ARG(s, 1), ARG(s, 2));
}

int fn_0fbe_155a(struct EmcState far *s)
{
    register int ch;

    if (ARG(s, 0) == -1) {
        for (ch = 0; ch < 4; ch++)
            fn_070c_07f5(ch, ARG(s, 1), ARG(s, 2), ARG(s, 3), ARG(s, 4));
    } else
        fn_070c_07f5(ARG(s, 0), ARG(s, 1), ARG(s, 2), ARG(s, 3), ARG(s, 4));
    return 1;
}

int fn_0fbe_162c(struct EmcState far *s)
{
    struct Monster far *m;

    m = &f_2803_15fa[ARG(s, 0)];
    if (m->mode == 1 || m->mode == 2) {
        fn_1aff_030e(&m->tx, &m->ty, ARG(s, 1), ARG(s, 2), ARG(s, 3));
        m->tdir = ARG(s, 4) << 1;
        if (m->x != m->tx || m->y != m->ty)
            fn_0d6c_0073(m, fn_1afa_0010(m->x, m->y, m->tx, m->ty));
    }
    return 1;
}

int fn_0fbe_170f(struct EmcState far *s)
{
    fn_13e8_0903(ARG(s, 0), fn_0845_06f8(ARG(s, 1)), fn_0845_06f8(ARG(s, 2)), fn_0845_06f8(ARG(s, 3)));
    return 1;
}

int fn_0fbe_177a(struct EmcState far *s)
{
    return fn_13e8_06a1();
}

int fn_0fbe_1784(struct EmcState far *s)
{
    int d;

    d = ARG(s, 0);
    if (d < 0) ovr_2d0e_0034(-d, 1);
    else ovr_2d0e_002f(d, 1);
    return 1;
}

int fn_0fbe_17b8(struct EmcState far *s)
{
    return ARG(s, 0) > g_81e0 ? 0 : 1;
}

int fn_0fbe_17d9(struct EmcState far *s)
{
    int a;
    int b;

    a = ARG(s, 0) + 5;
    b = ARG(s, 1);
    if (!b) fn_0bbc_070e(a, 0);
    else fn_0bbc_07b1(a, b);
    return 1;
}

int fn_0fbe_181b(struct EmcState far *s)
{
    if (fn_0845_0ac7()) return 0;
    fn_0845_0acf(fn_07bc_012d(ARG(s, 0), ARG(s, 1), ARG(s, 2)));
    return 1;
}

int fn_0fbe_1870(struct EmcState far *s)
{
    int it;

    it = fn_07bc_012d(ARG(s, 0), ARG(s, 1), ARG(s, 2));
    if (!fn_0c59_03a8(it)) {
        fn_07bc_044c(it);
        return 0;
    }
    return 1;
}

int fn_0fbe_18cb(struct EmcState far *s)
{
    fn_070c_00cf(ARG(s, 0), ARG(s, 1), ARG(s, 2));
    return 1;
}

int fn_0fbe_1910(struct EmcState far *s)
{
    char buf[14];
    register int i;

    i = ARG(s, 0);
    if (!g_20fc[i]) {
        sprintf(buf, "%s.TIM", (char far *)s->dat->text + fn_2315_0018(s->dat->text[ARG(s, 1)]));
        g_20fc[i] = fn_0638_0008(buf, 0, 0);
    }
    fn_0d6b_000f();
    return 1;
}

int fn_0fbe_19ad(struct EmcState far *s)
{
    return fn_0638_01e5(g_20fc[ARG(s, 0)], ARG(s, 1));
}

int fn_0fbe_19e1(struct EmcState far *s)
{
    register int i;

    i = ARG(s, 0);
    fn_0638_018b(g_20fc[i]);
    g_20fc[i] = 0;
    return 1;
}

int fn_0fbe_1a1d(struct EmcState far *s)
{
    return fn_0845_0ac7();
}

int fn_0fbe_1a27(struct EmcState far *s)
{
    int m;

    if ((m = ARG(s, 0)) != -1) {
        ovr_2d2c_00b1(&f_2803_15fa[m], ARG(s, 1));
        return 1;
    }
    return 0;
}

int fn_0fbe_1a72(struct EmcState far *s)
{
    fn_067a_0401(ARG(s, 0), 0);
    return 1;
}

int fn_0fbe_1a93(struct EmcState far *s)
{
    int b;

    b = ARG(s, 1);
    b = b == -1 ? g_7fd0 : b;
    fn_067a_02f5(ARG(s, 0), b);
    return 1;
}

int fn_0fbe_1ad1(struct EmcState far *s)
{
    struct TimHdr far *t;
    struct TimFunc far *f;
    int i;

    t = g_20fc[ARG(s, 0)];
    f = (struct TimFunc far *)((char far *)t + t->offFuncs);
    for (i = 0; i < 10; f++, i++)
        *(long far *)&f->ip = 0;
    return 1;
}

int fn_0fbe_1b20(struct EmcState far *s)
{
    int x;
    int y;
    struct Monster far *m;
    int v;

    v = ARG(s, 0);
    if (v == -1) return 1;
    m = &f_2803_15fa[v & 0x7fff];
    v = ARG(s, 2);
    switch (ARG(s, 1)) {
    case 6: m->flags |= v; break;
    case 2:
        fn_1aff_030e(&x, &y, v, m->x & 0xff, m->y & 0xff);
        if (!fn_0d6c_059d(x, y, m, 7))
            fn_0d6c_0742(m, x, y);
        break;
    case 0: fn_0d6c_0995(m, v); break;
    case 1: m->hp = v; break;
    case 3: fn_0d6c_0073(m, v << 1); break;
    default: break;
    }
    return 1;
}

int fn_0fbe_1c17(struct EmcState far *s)
{
    struct Monster far *m;
    int r;
    int v;

    r = -1;
    v = ARG(s, 0);
    if (v == -1) return 0;
    m = &f_2803_15fa[v & 0x7fff];
    switch (ARG(s, 1)) {
    case 8: r = f_2803_0053[m->type->c00]; break;
    case 7: r = m->type->flags; break;
    case 6: r = m->flags; break;
    case 1: r = m->hp; break;
    case 5: r = m->type->maxHp; break;
    case 0: r = m->mode; break;
    case 2: r = m->block; break;
    case 3: r = m->facing; break;
    case 4: r = m->c20; break;
    default: break;
    }
    return r;
}

int fn_0fbe_1cea(struct EmcState far *s)
{
    fn_0845_093a();
    return 1;
}

int fn_0fbe_1cf7(struct EmcState far *s)
{
    fn_154c_000f(1);
    fn_130a_0784();
    return fn_130a_03cd(ARG(s, 0), ARG(s, 1), 1, fn_0845_06f8(ARG(s, 2)), s, 0, 3);
}

int fn_0fbe_1d58(struct EmcState far *s)
{
    if (ARG(s, 3))
        ovr_2d18_002a(ARG(s, 0), ARG(s, 1));
    else {
        fn_070c_0a8f(ARG(s, 0), ARG(s, 1), 1);
        if (ARG(s, 2)) fn_0a21_022b(ARG(s, 0));
    }
    return 1;
}

int fn_0fbe_1df1(struct EmcState far *s)
{
    fn_067a_003e(ARG(s, 0));
    return 1;
}

int fn_0fbe_1e0e(struct EmcState far *s)
{
    return fn_067a_01d1(ARG(s, 0));
}

int fn_0fbe_1e28(struct EmcState far *s)
{
    struct Item far *p;
    int id;
    register int n;

    id = g_8203[ARG(s, 0)].mon;
    for (n = 0; id; id = p->next) {
        if (!(id & 0x8000)) n++;
        p = fn_080e_000b(id);
    }
    return n;
}

int fn_0fbe_1e6c(struct EmcState far *s)
{
    int k;
    int bestIdx;
    struct Char far *c;
    register int i;
    register int best;
    int v;

    bestIdx = -1;
    best = 0;
    k = ARG(s, 0);
    for (i = 0; i < ovr_2d74_0025(); i++) {
        c = &f_2803_362d[i];
        v = (c->skillBonus[k] + c->skill[k]) * 10 + ARG(s, 1) + 25;
        if (v > best) {
            best = v;
            bestIdx = i;
        }
    }
    return fn_0845_0636(1, 100) <= best ? bestIdx : -1;
}

int fn_0fbe_1f05(struct EmcState far *s)
{
    struct Monster far *m;
    int i;
    int n;

    n = 0;
    for (m = f_2803_15fa, i = 0; i < 30; i++, m++)
        if (m->hp > 0 && m->mode != 13) n++;
    return n;
}

int fn_0fbe_1f39(struct EmcState far *s)
{
    fn_154c_000f(1);
    fn_130a_0784();
    return 1;
}

int fn_0fbe_1f4e(struct EmcState far *s)
{
    int v;
    int i;

    v = ARG(s, 0);
    for (i = 0; i < 4; i++)
        if ((f_2803_362d[i].flags & 9) && f_2803_362d[i].wE == v) return 1;
    return 0;
}

int fn_0fbe_1fa0(struct EmcState far *s)
{
    int flags;
    int id;
    register int n;

    flags = ARG(s, 0);
    id = ARG(s, 1);
    n = ARG(s, 2);
    fn_0845_01c4(flags, fn_0845_06f8(id), ARG(s, 3), ARG(s, 4), ARG(s, 5), ARG(s, 6), ARG(s, 7), ARG(s, 8), ARG(s, 9));
    if (n > 0) fn_067a_0401(n, 0);
    return 1;
}

int fn_0fbe_2087(struct EmcState far *s)
{
    return fn_070c_0793(ARG(s, 0), ARG(s, 1), ARG(s, 2));
}

int fn_0fbe_20c5(struct EmcState far *s)
{
    return fn_070c_07e3(ARG(s, 0));
}

int fn_0fbe_20df(struct EmcState far *s)
{
    register int it;

    it = ARG(s, 0);
    if (f_2803_1cfd[it].block)
        fn_07bc_0367(it, f_2803_1cfd[it].block);
    fn_07bc_044c(it);
    return 1;
}

int fn_0fbe_2126(struct EmcState far *s)
{
    return fn_070c_06a3(ARG(s, 0), ARG(s, 1), ARG(s, 2), ARG(s, 3), ARG(s, 4));
}

int fn_0fbe_2188(struct EmcState far *s)
{
    int x;
    int y;
    register int r;

    if (ARG(s, 8) & 0x8000)
        fn_1aff_030e(&x, &y, ARG(s, 2), ARG(s, 3), ARG(s, 4));
    else
        fn_1aff_030e(&x, &y, ARG(s, 2), 0x80, 0x80);
    r = fn_0b6b_032f(ARG(s, 0), ARG(s, 1), x, y, ARG(s, 5), ARG(s, 6) << 1, ARG(s, 7), ARG(s, 8), 0x3f);
    if (!r) fn_07bc_044c(ARG(s, 1));
    return r;
}

int fn_0fbe_2290(struct EmcState far *s)
{
    fn_0bbc_0365(&f_2803_362d[ARG(s, 0)], ARG(s, 1), ARG(s, 2));
    return 1;
}

int fn_0fbe_22dc(struct EmcState far *s)
{
    int i;

    for (i = 0; i < 0x30; i++)
        if (!g_7fe6[i]) return 0;
    return 1;
}

int fn_0fbe_22fb(struct EmcState far *s)
{
    struct Monster far *m;
    int found;
    int doMon;
    int doItems;
    struct Item far *p;
    int b;
    int x;
    int lvl;
    register int id;
    register int next;

    found = 0;
    b = ARG(s, 0);
    x = ARG(s, 1);
    lvl = ARG(s, 2);
    doMon = ARG(s, 3);
    doItems = ARG(s, 5);
    next = g_8203[b].mon;
    while (next) {
        id = next;
        p = fn_080e_000b(next);
        next = p->next;
        if (!(id & 0x8000)) {
            if (!(f_2803_1cfd[id].flags & 0x4000)) continue;
            if (!doItems) continue;
            fn_130a_0052(id, lvl, x, f_2803_1cfd[id].x & 0xff, f_2803_1cfd[id].y & 0xff, f_2803_1cfd[id].sub);
            if (ARG(s, 4) && g_7fe5 == lvl)
                fn_0845_1343(x, 0x80, -1, id, 0, 0);
            found = 1;
        } else {
            if (!doMon) continue;
            m = &f_2803_15fa[id & 0x7fff];
            fn_0d6c_0995(m, 14);
            fn_0845_046c(m->block);
            fn_0d6c_0742(m, 0, 0);
            found = 1;
        }
    }
    return found;
}

int fn_0fbe_248a(struct EmcState far *s)
{
    if (ARG(s, 1)) ovr_2d5f_012e();
    else ovr_2d5f_0133(0);
    return 1;
}

int fn_0fbe_24b4(struct EmcState far *s)
{
    fn_130a_0a7c(3, fn_0845_06f8(ARG(s, 0)), s, 0, 1);
    return 1;
}

int fn_0fbe_24e9(struct EmcState far *s)
{
    int r;

    r = fn_154c_01d3(ARG(s, 0), 0, 0);
    if (!(r && !g_81fe))
        fn_130a_0a7c(4, fn_0845_06f8(ARG(s, 0)), s, 0, 1);
    return 1;
}

int fn_0fbe_254c(struct EmcState far *s)
{
    int i;

    for (i = 0; i < 30; i++)
        if (f_2803_15fa[i].c20 == ARG(s, 0) || ARG(s, 0) == -1)
            return f_2803_15fa[i].mode != 1 ? 1 : 0;
    return 1;
}

int fn_0fbe_25aa(struct EmcState far *s)
{
    g_20d7 = ARG(s, 0);
    return 1;
}

int fn_0fbe_25c4(struct EmcState far *s)
{
    fn_0845_0bf6();
    return 1;
}

int fn_0fbe_25d1(struct EmcState far *s)
{
    struct Monster far *m;
    int id;

    id = ARG(s, 0) & 0x7fff;
    if (id >= 0) {
        m = &f_2803_15fa[id];
        fn_0d6c_0995(m, 14);
        fn_0845_046c(m->block);
        fn_0d6c_0742(m, 0, 0);
    }
    return 1;
}

int fn_0fbe_262d(struct EmcState far *s)
{
    g_4bea = ARG(s, 0);
    return 1;
}

int fn_0fbe_2647(struct EmcState far *s)
{
    int k;

    fn_163d_0004();
    fn_154c_0136();
    if (fn_2169_060c()) {
        k = fn_2169_0790();
        if (k && !(k & 0x800)) {
            if (ARG(s, 0)) {
                fn_2169_0945(k);
                g_20ec = 1;
            } else
                fn_2169_062e();
            return 1;
        }
    }
    return 0;
}

int fn_0fbe_269d(struct EmcState far *s)
{
    register int w;
    register int f;

    w = ARG(s, 0);
    f = ARG(s, 1);
    fn_14b3_0122(w);
    if (f & 1) fn_14b3_0215();
    if (f & 3) {
        g_1f47[w].a = 0;
        g_1f47[w].b = 0;
    }
    fn_130a_0a7c(w, fn_0845_06f8(ARG(s, 2)), s, 0, 3);
    return 1;
}

int fn_0fbe_2725(struct EmcState far *s)
{
    struct Monster far *m;
    int mask;
    int n;
    int i;

    for (i = mask = 0; ARG(s, i) != -1; i++)
        mask |= 1 << ARG(s, i);
    for (m = f_2803_15fa, n = i = 0; i < 30; i++, m++)
        if ((mask & (1 << m->c20)) && m->mode < 14) n++;
    return n;
}

int fn_0fbe_2798(struct EmcState far *s)
{
    int far *p;

    p = &ARG(s, 0);
    if (p[3] > 0x61) ovr_2ce1_007f("Cmd_Animate_Wall: Too many anim frames passed for stack");
    fn_130a_0360(p[0], p[1], (p + 4)[(unsigned)p[2] % (unsigned)p[3]]);
    return 0;
}

int fn_0fbe_27f6(struct EmcState far *s)
{
    int hi;
    int a;
    int c;
    register int i;
    register int type;
    int lo;

    a = ARG(s, 0);
    type = ARG(s, 1);
    c = ARG(s, 2);
    if (c == 0) {
        for (i = 0; i < 0x30; i++)
            if (g_7fe6[i] && f_2803_1cfd[g_7fe6[i]].type == type) return 1;
        if (f_2803_1cfd[fn_0845_0ac7()].type == type) return 1;
    }
    if (a == -1) {
        lo = 0;
        hi = 3;
    } else
        lo = hi = a;
    for (i = lo; i <= hi; i++)
        if (fn_0a21_0997(i, type)) return 1;
    return 0;
}

int fn_0fbe_28b5(struct EmcState far *s)
{
    return g_4be0 = ARG(s, 0);
}

int fn_0fbe_28cc(struct EmcState far *s)
{
    struct TimHdr far *t;

    t = g_20fc[ARG(s, 0)];
    t->stop = 0;
    g_4bb2 = 0;
    t->numStart = g_4bde ? g_4bde : 1;
    g_4bb4 = -1;
    return 1;
}

int fn_0fbe_2922(struct EmcState far *s)
{
    int x;
    int y;

    x = ARG(s, 1);
    if (x != -1) x &= 0xff;
    y = ARG(s, 2);
    if (y != -1) y &= 0xff;
    if (ARG(s, 3) || g_2794 == -1)
        g_2794 = g_8203[ARG(s, 0)].mon;
    else
        g_2794 = g_8203[g_2794].mon;
    while (g_2794) {
        if (!(g_2794 & 0x8000)
            && (x == -1 || (f_2803_1cfd[g_2794].x & 0xff) == x)
            && (y == -1 || (f_2803_1cfd[g_2794].y & 0xff) == y))
            return g_2794;
        g_2794 = g_8203[g_2794 & 0x7fff].mon;
    }
    return 0;
}

int fn_0fbe_29f0(struct EmcState far *s)
{
    fn_07bc_0367(ARG(s, 0), ARG(s, 1));
    return 1;
}

int fn_0fbe_2a1f(struct EmcState far *s)
{
    struct Item far *p;
    int b;
    register int id;
    int m;

    b = ARG(s, 0);
    m = ARG(s, 1);
    if (m == -1)
        id = g_8203[b].mon;
    else {
        p = fn_080e_000b(m | 0x8000);
        id = p->next;
    }
    while (id) {
        p = fn_080e_000b(id);
        if (id & 0x8000) return id & 0x7fff;
        id = p->next;
    }
    return -1;
}

int fn_0fbe_2a97(struct EmcState far *s)
{
    struct Item far *p;
    int b;
    register int m;
    int id;

    b = ARG(s, 0);
    m = ARG(s, 1) | 0x8000;
    for (id = g_8203[b].mon; id & 0x8000; id = p->next) {
        if (m == -1 || id == m) return id & 0x7fff;
        p = fn_080e_000b(id);
    }
    return -1;
}

int fn_0fbe_2aff(struct EmcState far *s)
{
    fn_1ebc_00e7();
    ovr_2d46_0039(ARG(s, 0), ARG(s, 1), ARG(s, 2), ARG(s, 3), ARG(s, 4), ARG(s, 5), ARG(s, 6), ARG(s, 7));
    fn_1ebc_00fe();
    return 1;
}

int fn_0fbe_2ba4(struct EmcState far *s)
{
    int x;
    int y;

    x = ARG(s, 0);
    y = ARG(s, 1);
    fn_1aff_03b4(&x, &y, ARG(s, 2));
    return ARG(s, 3) ? x : y;
}

int fn_0fbe_2c12(struct EmcState far *s)
{
    if (ARG(s, 0)) g_2796 = 0;
    else g_2796++;
    while (g_2796 < 4) {
        if (f_2803_362d[g_2796].flags & 1) return g_2796;
        g_2796++;
    }
    return -1;
}

int fn_0fbe_2c5c(struct EmcState far *s)
{
    return ovr_2d00_0025(ARG(s, 0), ARG(s, 1), ARG(s, 2), ARG(s, 3), ARG(s, 4));
}

int fn_0fbe_2cbe(struct EmcState far *s)
{
    if (ARG(s, 0) != -1) fn_0a21_022b(ARG(s, 0));
    else fn_0a21_05ce();
    return 1;
}

int fn_0fbe_2cf4(struct EmcState far *s)
{
    int type;
    int i;
    int j;

    type = ARG(s, 0);
    for (i = 0; i < 0x30; i++) {
        if (g_7fe6[i] && f_2803_1cfd[g_7fe6[i]].type == type) {
            g_7fe6[i] = 0;
            fn_0c59_0377();
            return 1;
        }
    }
    for (i = 0; i < 4; i++) {
        if (!(f_2803_362d[i].flags & 1)) continue;
        for (j = 0; j < 11; j++) {
            if (f_2803_362d[i].items[j] && f_2803_1cfd[f_2803_362d[i].items[j]].type == type) {
                f_2803_362d[i].items[j] = 0;
                return 1;
            }
        }
    }
    return 0;
}

int fn_0fbe_2dc7(struct EmcState far *s)
{
    fn_231c_0008(ARG(s, 0));
    return 1;
}

int fn_0fbe_2de4(struct EmcState far *s)
{
    fn_231c_0048(ARG(s, 0));
    return 1;
}

int fn_0fbe_2e01(struct EmcState far *s)
{
    int r;

    r = g_4ee0[ARG(s, 0)].c14;
    g_4ee0[ARG(s, 0)].c14 = -1;
    return r;
}

int fn_0fbe_2e3f(struct EmcState far *s)
{
    return fn_130a_0d2b(ARG(s, 0), ARG(s, 1), ARG(s, 2));
}

int fn_0fbe_2e7d(struct EmcState far *s)
{
    fn_2279_025b(g_540e + 0x180, g_adea + 0x180, 0x180L);
    fn_1ef2_0075(g_adea, 10, 0, 0);
    g_20d5 = 0;
    return 1;
}

int fn_0fbe_2ec1(struct EmcState far *s)
{
    return g_7fe3;
}

int fn_0fbe_2eca(struct EmcState far *s)
{
    return fn_09aa_0183(ARG(s, 0), ARG(s, 1));
}

int fn_0fbe_2ef6(struct EmcState far *s)
{
    fn_0845_0acf(ARG(s, 0));
    return 1;
}

int fn_0fbe_2f13(struct EmcState far *s)
{
    return fn_0c59_0410(ARG(s, 0), ARG(s, 1));
}

int fn_0fbe_2f3f(struct EmcState far *s)
{
    return ovr_2d8a_0039(ARG(s, 0), ARG(s, 1), ARG(s, 2));
}

int fn_0fbe_2f7d(struct EmcState far *s)
{
    char pal[0x300];
    char tbl[0x100];
    int i;

    fn_0845_0f86(g_540e, pal, ARG(s, 0));
    fn_0845_1430(pal);
    fn_0845_1430(g_540e);
    if (g_1f3a) {
        for (i = 0; i < 0x100; i++) tbl[i] = i;
        tbl[1] = 6;
        fn_234e_0003(2);
        fn_1dbc_0017(0xe, 0, 0xe, 0, 0x16, 0x78, 0, 2);
        fn_1f24_003f(0x70, 0, 0xb0, 0x78, 0, tbl);
        fn_234e_0062();
    }
    fn_1ef2_001c(pal);
    fn_1ebc_022a(12, 1, 2);
    fn_2120_0007(2);
    fn_1ef2_001c(g_540e);
    if (g_1f3a) {
        fn_234e_0003(2);
        fn_1dbc_0017(0xe, 0, 0xe, 0, 0x16, 0x78, 2, 0);
        fn_234e_0062();
    }
    return 0;
}

int fn_0fbe_3081(struct EmcState far *s)
{
    return ovr_2cf7_0020();
}

int fn_0fbe_308b(struct EmcState far *s)
{
    int t;

    t = ARG(s, 0);
    if ((t >= 0x46 && t <= 0x4a) || (t >= 0x51 && t <= 0x59) || (t >= 0x5d && t <= 0x61) || (t >= 0x66 && t <= 0x6a))
        fn_067a_0401(12, 1);
    else
        fn_067a_0401(g_2798[g_7fb2[t].c9 & 3], 1);
    return 1;
}

int fn_0fbe_30f8(struct EmcState far *s)
{
    ovr_2d28_0034(ARG(s, 0), ARG(s, 1), ARG(s, 2), 1);
    return 1;
}

int fn_0fbe_313b(struct EmcState far *s)
{
    if (ARG(s, 1)) {
        g_8203[ARG(s, 0)].flags &= 0xef;
        g_8203[ARG(s, 0)].flags |= 0x20;
    } else
        g_8203[ARG(s, 0)].flags &= 0xdf;
    return 1;
}

int fn_0fbe_319d(struct EmcState far *s)
{
    int snd;
    int i;

    snd = -1;
    for (i = 0; i < 4; i++) {
        if ((f_2803_362d[i].flags & 1) && f_2803_362d[i].wE < 0) {
            switch (i) {
            case 0: snd = 0x88; break;
            case 5: snd = 0x32; break;
            case 8: snd = 0x31; break;
            case 9: snd = 0x30; break;
            }
            break;
        }
    }
    fn_067a_0401(snd, 1);
    return 1;
}

int fn_0fbe_3218(struct EmcState far *s)
{
    return fn_09aa_0183(ARG(s, 0), ARG(s, 1));
}

int fn_0fbe_3244(struct EmcState far *s)
{
    return fn_0845_1280(ARG(s, 0), ARG(s, 1), ARG(s, 2));
}

int fn_0fbe_3282(struct EmcState far *s)
{
    int mode;
    char far *p;

    switch (f_2803_363b) {
    default: mode = 0; break;
    case -9: mode = 1; break;
    case -1: mode = 2; break;
    case -5: mode = 3; break;
    }
    while (fn_154c_0136())
        ;
    p = ovr_2d46_002f(" ", g_20db);
    sprintf(g_ad99, "%d HOMIE %d %s", mode, fn_0845_1036(), g_ae59);
    fn_2309_000c();
    fn_0845_1536();
    fn_2148_002c(g_aeaa[0] - 'A');
    fn_2148_014d(g_aeaa);
    fn_2148_014d(p + 2);
    execl("FINALE.EXE", "FINALE.EXE", g_ad99, (char far *)0);
    return 0;
}

int fn_0fbe_333f(struct EmcState far *s)
{
    ovr_2d2c_00e8();
    return 0;
}

int fn_0fbe_334b(struct EmcState far *s)
{
    int v;

    v = ARG(s, 0);
    fn_0845_155d(v);
    return 1;
}

int fn_0fbe_336f(struct EmcState far *s)
{
    fn_0845_15d9(2);
    fn_234e_0003(2);
    ovr_2d46_0039(0x70, 0, 0x70, 0, 0xb0, 0x78, 2, 0);
    fn_0845_08aa();
    fn_234e_0062();
    return 1;
}

int fn_0fbe_33a8(struct EmcState far *s)
{
    fn_0845_08aa();
    return 1;
}

int fn_0fbe_33b5(struct EmcState far *s)
{
    if (ARG(s, 0) == -1) {
        fn_154c_000f(1);
        return 1;
    }
    if (ARG(s, 0) == -2)
        return fn_154c_0136();
    return fn_154c_0057(ARG(s, 0), ARG(s, 1), ARG(s, 2));
}

int fn_0fbe_342b(struct EmcState far *s)
{
    return fn_154c_010f(ARG(s, 0), ARG(s, 1));
}


int fn_0fbe_3457(struct EmcState far *s)
{
    int v;
    int far *p;

    v = ARG(s, 0);
    if (v < 0) {
        v = -v;
        if (v < 50) return 50;
        v += 99;
        v = v / 100 * 100;
        return v;
    }
    for (p = f_2c0c_0000; *p; p++)
        if (*p >= v) return *p;
    return 0;
}

int fn_0fbe_34b8(struct EmcState far *s)
{
    return g_20db;
}

/* opcode table (EmcData.opcodes) */
int ovr_2d2c_0089();
int ovr_2d2c_008e();
int ovr_2d2c_0093();
int ovr_2d50_003e();
int ovr_2d50_0043();
int ovr_2d2c_0098();
int ovr_2d2c_009d();
int ovr_2d2c_00a2();
int ovr_2d5f_00d9();
int ovr_2d5f_00de();
int ovr_2d2c_00de();
int ovr_2d5f_0124();
int ovr_2d5f_0129();
int ovr_2d2c_00d4();
int ovr_2d2c_00cf();
int ovr_2d2c_00ca();
int ovr_2d2c_00a7();
int ovr_2d5f_011a();
int ovr_2d5f_011f();
int ovr_2d74_002a();
int ovr_2d5f_0110();
int ovr_2d5f_0115();
int ovr_2d2c_00ac();
int ovr_2d5f_0106();
int ovr_2d2c_00c5();
int ovr_2d2c_00c0();
int ovr_2d86_0034();
int ovr_2d77_0020();
int ovr_2d5f_0093();
int ovr_2d5f_0098();
int ovr_2d5f_009d();
int ovr_2d5f_00a2();
int ovr_2d5f_00a7();
int ovr_2d5f_00ac();
int ovr_2d5f_00b1();
int ovr_2d5f_00b6();
int ovr_2d5f_00bb();
int ovr_2d5f_00c0();
int ovr_2d2c_00b6();
int ovr_2d2c_00bb();
int ovr_2d5f_00c5();
int ovr_2d5f_00ca();
int ovr_2d5f_00cf();
int ovr_2d46_004d();
int ovr_2cef_0039();
int ovr_2d7d_0025();
int ovr_2d5f_00d4();
int ovr_2d5f_00ed();
int ovr_2d5f_00e3();
int ovr_2d5f_00e8();
int ovr_2d0a_002f();
int ovr_2d5f_0138();

int (far *g_2494[])(struct EmcState far *s) = {
    fn_0fbe_007f,
    fn_0fbe_00dd,
    fn_0fbe_014b,
    fn_0fbe_0053,
    fn_0fbe_0168,
    fn_0fbe_021a,
    fn_0fbe_0273,
    fn_0fbe_0290,
    fn_0fbe_02e8,
    (int (far *)(struct EmcState far *))ovr_2d2c_0089,
    (int (far *)(struct EmcState far *))ovr_2d2c_008e,
    (int (far *)(struct EmcState far *))ovr_2d2c_0093,
    fn_0fbe_0322,
    (int (far *)(struct EmcState far *))ovr_2d50_003e,
    (int (far *)(struct EmcState far *))ovr_2d50_0043,
    fn_0fbe_0341,
    fn_0fbe_037f,
    fn_0fbe_03fc,
    fn_0fbe_04a8,
    fn_0fbe_0677,
    fn_0fbe_079e,
    (int (far *)(struct EmcState far *))ovr_2d2c_0098,
    (int (far *)(struct EmcState far *))ovr_2d2c_009d,
    fn_0fbe_004c,
    (int (far *)(struct EmcState far *))ovr_2d2c_00a2,
    (int (far *)(struct EmcState far *))ovr_2d5f_00d9,
    fn_0fbe_08cb,
    (int (far *)(struct EmcState far *))ovr_2d5f_00de,
    fn_0fbe_0a4a,
    fn_0fbe_319d,
    (int (far *)(struct EmcState far *))ovr_2d2c_00de,
    (int (far *)(struct EmcState far *))ovr_2d5f_0124,
    (int (far *)(struct EmcState far *))ovr_2d5f_0129,
    fn_0fbe_0a52,
    fn_0fbe_0aa2,
    fn_0fbe_0b0f,
    fn_0fbe_0c11,
    fn_0fbe_0c40,
    fn_0fbe_0c4d,
    fn_0fbe_0c5a,
    fn_0fbe_0c6a,
    fn_0fbe_0c8a,
    fn_0fbe_0d17,
    fn_0fbe_0d34,
    fn_0fbe_0d54,
    fn_0fbe_0db9,
    fn_0fbe_0d8c,
    fn_0fbe_0dd3,
    fn_0fbe_0e81,
    fn_0fbe_0f94,
    fn_0fbe_0fe7,
    fn_0fbe_313b,
    fn_0fbe_1063,
    (int (far *)(struct EmcState far *))ovr_2d2c_00d4,
    (int (far *)(struct EmcState far *))ovr_2d2c_00cf,
    fn_0fbe_1126,
    fn_0fbe_1239,
    fn_0fbe_11cb,
    fn_0fbe_11db,
    fn_0fbe_122c,
    (int (far *)(struct EmcState far *))ovr_2d2c_00ca,
    fn_0fbe_14fb,
    fn_0fbe_1515,
    (int (far *)(struct EmcState far *))ovr_2d2c_00a7,
    fn_0fbe_151c,
    fn_0fbe_155a,
    (int (far *)(struct EmcState far *))ovr_2d5f_011a,
    (int (far *)(struct EmcState far *))ovr_2d5f_011f,
    fn_0fbe_162c,
    fn_0fbe_170f,
    fn_0fbe_1784,
    fn_0fbe_17b8,
    fn_0fbe_17d9,
    fn_0fbe_181b,
    fn_0fbe_308b,
    (int (far *)(struct EmcState far *))ovr_2d74_002a,
    fn_0fbe_1870,
    fn_0fbe_18cb,
    fn_0fbe_1910,
    fn_0fbe_19ad,
    fn_0fbe_19e1,
    (int (far *)(struct EmcState far *))ovr_2d5f_0110,
    (int (far *)(struct EmcState far *))ovr_2d5f_0115,
    fn_0fbe_1a1d,
    fn_0fbe_3244,
    fn_0fbe_1a27,
    (int (far *)(struct EmcState far *))ovr_2d2c_00ac,
    fn_0fbe_1a72,
    fn_0fbe_177a,
    fn_0fbe_1ad1,
    fn_0fbe_0110,
    fn_0fbe_1b20,
    fn_0fbe_1c17,
    fn_0fbe_333f,
    fn_0fbe_1cf7,
    fn_0fbe_1cea,
    fn_0fbe_1a93,
    fn_0fbe_1d58,
    (int (far *)(struct EmcState far *))ovr_2d5f_0106,
    fn_0fbe_1df1,
    fn_0fbe_1e0e,
    fn_0fbe_334b,
    fn_0fbe_1e28,
    fn_0fbe_1e6c,
    fn_0fbe_1f05,
    fn_0fbe_3282,
    fn_0fbe_1f39,
    (int (far *)(struct EmcState far *))ovr_2d2c_00c5,
    fn_0fbe_2087,
    fn_0fbe_20c5,
    fn_0fbe_1f4e,
    fn_0fbe_1fa0,
    fn_0fbe_20df,
    fn_0fbe_2126,
    fn_0fbe_2188,
    fn_0fbe_2290,
    fn_0fbe_22dc,
    fn_0fbe_22fb,
    fn_0fbe_248a,
    (int (far *)(struct EmcState far *))ovr_2d2c_00c0,
    (int (far *)(struct EmcState far *))ovr_2d86_0034,
    fn_0fbe_24b4,
    fn_0fbe_24e9,
    fn_0fbe_254c,
    fn_0fbe_25aa,
    (int (far *)(struct EmcState far *))ovr_2d77_0020,
    fn_0fbe_25c4,
    fn_0fbe_25d1,
    fn_0fbe_262d,
    fn_0fbe_2647,
    fn_0fbe_269d,
    fn_0fbe_2725,
    fn_0fbe_2798,
    fn_0fbe_27f6,
    fn_0fbe_28b5,
    fn_0fbe_28cc,
    fn_0fbe_2922,
    fn_0fbe_29f0,
    (int (far *)(struct EmcState far *))ovr_2d5f_0093,
    (int (far *)(struct EmcState far *))ovr_2d5f_0098,
    (int (far *)(struct EmcState far *))ovr_2d5f_009d,
    (int (far *)(struct EmcState far *))ovr_2d5f_00a2,
    (int (far *)(struct EmcState far *))ovr_2d5f_00a7,
    (int (far *)(struct EmcState far *))ovr_2d5f_00ac,
    (int (far *)(struct EmcState far *))ovr_2d5f_00b1,
    (int (far *)(struct EmcState far *))ovr_2d5f_00b6,
    (int (far *)(struct EmcState far *))ovr_2d5f_00bb,
    (int (far *)(struct EmcState far *))ovr_2d5f_00c0,
    (int (far *)(struct EmcState far *))ovr_2d2c_00b6,
    (int (far *)(struct EmcState far *))ovr_2d2c_00bb,
    fn_0fbe_2a1f,
    fn_0fbe_2a97,
    fn_0fbe_2aff,
    fn_0fbe_2ba4,
    (int (far *)(struct EmcState far *))ovr_2d5f_00c5,
    (int (far *)(struct EmcState far *))ovr_2d5f_00ca,
    (int (far *)(struct EmcState far *))ovr_2d5f_00cf,
    fn_0fbe_2c12,
    fn_0fbe_2c5c,
    fn_0fbe_2cbe,
    fn_0fbe_2cf4,
    fn_0fbe_2dc7,
    fn_0fbe_2de4,
    fn_0fbe_2e01,
    (int (far *)(struct EmcState far *))ovr_2d46_004d,
    fn_0fbe_2e3f,
    fn_0fbe_2e7d,
    fn_0fbe_2eca,
    fn_0fbe_2ec1,
    fn_0fbe_2ef6,
    (int (far *)(struct EmcState far *))ovr_2cef_0039,
    fn_0fbe_05fa,
    fn_0fbe_2f13,
    fn_0fbe_2f3f,
    (int (far *)(struct EmcState far *))ovr_2d7d_0025,
    (int (far *)(struct EmcState far *))ovr_2d5f_00d4,
    fn_0fbe_2f7d,
    fn_0fbe_3081,
    (int (far *)(struct EmcState far *))ovr_2d5f_00ed,
    (int (far *)(struct EmcState far *))ovr_2d5f_00e3,
    (int (far *)(struct EmcState far *))ovr_2d5f_00e8,
    fn_0fbe_30f8,
    (int (far *)(struct EmcState far *))ovr_2d0a_002f,
    fn_0fbe_3218,
    fn_0fbe_336f,
    fn_0fbe_33a8,
    (int (far *)(struct EmcState far *))ovr_2d5f_0138,
    fn_0fbe_33b5,
    fn_0fbe_342b,
    fn_0fbe_3457,
    fn_0fbe_34b8,
    fn_0fbe_004c,
};
int g_2794 = -1;
int g_2796 = 0;
int g_2798[4] = { 12, 62, 63, -1 };
int g_27a0[4] = { -1, -1, -1, -1 };
