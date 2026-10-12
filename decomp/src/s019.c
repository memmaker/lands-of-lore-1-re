/* s019: EMC script opcodes (game callbacks called through EmcData.opcodes) */
#include "lol.h"

extern unsigned char g_531e[];
extern int g_7fdf;
extern struct EmcData far f_2803_3611;

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

struct Anim {               /* 0xb5 bytes, g_4ee0[]: TIM/WSA animation slots */
    char far *wsa;
    int x, y;                /* +04 */
    char pad8[4];
    char cc, cd;             /* +0c */
    char pade[4];
    unsigned flags;          /* +12 */
    char c14;
    int frames[10][8];       /* +15 */
};
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

/* NONMATCHING original computes the word index before the bit mask */
int fn_0fbe_0290(struct EmcState far *s)
{
    unsigned n;

    n = ARG(s, 0);
    if (ARG(s, 1))
        g_804c[n / 16] |= 1 << (n % 16);
    else
        g_804c[n / 16] &= ~(1 << (n % 16));
    return 1;
}

/* NONMATCHING original computes the word index before the bit mask */
int fn_0fbe_02e8(struct EmcState far *s)
{
    int n;

    n = ARG(s, 0);
    if (n < 0) return 0;
    return g_804c[n >> 4] & (1 << (n & 15)) ? 1 : 0;
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

/* NONMATCHING original shares only the case 10 tail with cases 11-13 */
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
    case 17: r = (t->c9 << 8) | t->w8; break;
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
