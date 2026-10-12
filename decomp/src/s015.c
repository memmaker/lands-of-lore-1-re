/* s015: main loop, input dispatch, mouse cursor, party buttons (attack, throw, pick up, drop, magic, compass) */
#include "lol.h"

struct Btn { char pad[0x1e]; int x, y; char pad22[0x0c]; unsigned flags; char pad30[8]; int w38; };

extern char far f_2803_0000[];
extern void far * far f_2803_00a6[];
extern int far f_27dd_0000[][14];
extern unsigned char g_531e[];
extern char g_81f2[];
extern unsigned char far *g_adea;
extern void far *g_7fae;
extern unsigned g_7fd6, g_7fda, g_806a, g_8094;
extern int g_7fd0, g_7fdf, g_7fb6, g_81e0, g_8048, g_804a, g_4d72, g_4d66, g_4bf4, g_20d7, g_20d1;
extern int g_2f0c, g_2f0e, g_2f10, g_2f12;
extern char g_7fd9, g_7fdd, g_7fe3, g_7fe5, g_81dc, g_81de;
extern unsigned char g_81dd;

int fn_09aa_0183(int b, int dir);
void ovr_2d1b_0052(int a, int b, int c, int d);
int fn_070c_0253(int ch);
void fn_07bc_047f(int owner, int it, int a, int target, int b);
void fn_0845_1343(int b, unsigned mask, int c, int d, int e, int f);
int fn_070c_012a(int who, int dmg);
int fn_0a21_0997(int ch, int type);
void fn_070c_009f(int ch);
void fn_0bbc_0744(int ch, int type, int time, int replace);
int fn_0845_0ac7(void);
void fn_1aff_030e(int *x, int *y, int b, int a, int c);
int fn_0b6b_032f(int type, int item, int x, int y, int power, int dir, int unused, int owner, int e);
void fn_067a_0401(int n, int force);
void fn_0845_0acf(int item);
char far *fn_0845_06f8(int id);
void fn_0845_01c4(unsigned flags, char far *fmt, ...);
int fn_154c_0057(int id, int a, int b);
void ovr_2ce1_0020(void);
void ovr_2d2c_0043(void);
void fn_0845_035b(unsigned char far *src, int lvl, int idx);
void fn_07bc_044c(int it);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_1f6c_0006(char far *s, int x, int y, int c1, int c2);
void fn_0a21_05ce(void);
int fn_0845_1280(int ch, int cls, int i);
void fn_0a21_022b(int ch);
void ovr_2ceb_0034(int ch);
void ovr_2ceb_0020(void);
int ovr_2d8a_0039(int ch, int cls, int i);
void fn_070c_00cf(int who, int cls, long exp);
void fn_2169_0945(int key);
int fn_1e74_000f(int n);
void ovr_2cda_006b(void);
int fn_1e6f_000a(int x, int y);
int fn_080e_01a6(int far *list, int n);
void fn_07bc_0367(int it, int b);
void fn_07bc_0272(int it, int x, int y, int a, int b);
int fn_0845_038e(int x, int y, int x1, int y1, int x2, int y2);
int fn_09aa_0404(int b, int dir, int f);
void fn_0845_068c(int x, int y, char far *name);
char far *fn_0845_0c08(int item);
int fn_163d_0039(void far *p);
void fn_154c_000f(int n);
long fn_203b_04ce(int n);
char far *fn_0845_09a9(int b);
void fn_0d6b_000f(void);
void fn_231c_0008(int n);
void fn_0845_13d6(int b, unsigned mask);
void fn_0bbc_0645(void);
int fn_0845_0636(int n, int sides);
void fn_0845_093a(void);
void fn_0845_15d9(int a);
void fn_067a_026b(int n);
void ovr_2cf4_0020(int n);

int g_23ba = -1;
signed char g_23bc[21] = { 0, 0, 1, 0, -1, -1, 1, 1, -1, 0, 2, 0, -2, -1, 1, 2, 2, 1, -1, -2, -2 };
signed char g_23d1[21] = { 0, -1, 0, 1, 0, -1, -1, 1, 1, -2, 0, 2, 0, -2, -2, -1, 1, 2, 2, 1, -1 };
unsigned char g_23e6[4] = { 0x40, 0xc0, 0x40, 0xc0 };
unsigned char g_23ea[4] = { 0x40, 0x40, 0xc0, 0xc0 };
char g_23ee[7] = { 7, 13, 7, 0, 0, 15, 7 };
char g_23f5[7] = { 0, 7, 12, 7, 6, 6, 7 };

void fn_0ca0_05bb(register int col);

void fn_0ca0_000d(void)
{
}

/* NONMATCHING */
int fn_0ca0_0012(struct Btn far *b)
{
    int k;
    register int s;
    register int i;

    if (f_2803_362d[b->w38].flags & 0x314c) return 1;
    {
        int blk;

        blk = fn_09aa_0183(g_7fd0, g_7fdf);
        if (g_8203[blk].flags & 0x10) {
            ovr_2d1b_0052(0, 0, 0, 0);
            return 1;
        }
    }
    k = fn_070c_0253(b->w38);
    s = 0;
    for (i = 0; i <= 3; i++)
        if (f_2803_362d[b->w38].items[i]) {
            fn_07bc_047f(b->w38, f_2803_362d[b->w38].items[i], 0x400, k, s);
            fn_0845_1343(g_7fd0, 0x400, b->w38, f_2803_362d[b->w38].items[i], k, s);
            s -= 10;
        }
    if (!s) {
        fn_07bc_047f(b->w38, 0, 0x400, k, s);
        fn_0845_1343(g_7fd0, 0x400, b->w38, 0, k, s);
    }
    s = f_2803_362d[b->w38].dmgDealt ? 4 : fn_070c_012a(b->w38, 8) + 4;
    if (fn_0a21_0997(b->w38, 0xe6)) s >>= 1;
    f_2803_362d[b->w38].flags |= 4;
    fn_070c_009f(b->w38);
    fn_0bbc_0744(b->w38, 1, s, 1);
    return 1;
}

int fn_0ca0_01cf(struct Btn far *b)
{
    int blk;
    int x;
    int y;
    register int w;

    if (g_7fd6 & 1) return 0;
    blk = fn_09aa_0183(g_7fd0, g_7fdf);
    w = WALL(blk, g_7fdf ^ 2);
    if (g_531e[w] & 2) return 0;
    if (!fn_0845_0ac7()) return 0;
    fn_1aff_030e(&x, &y, g_7fd0, 0x80, 0x80);
    if (fn_0b6b_032f(0, fn_0845_0ac7(), x, y, 12, g_7fdf << 1, 6, g_7fe3, 0x3f)) {
        fn_067a_0401(0x12, 0);
        fn_0845_0acf(0);
    }
    g_7fb6 = 1;
    return 1;
}

int fn_0ca0_0281(struct Btn far *b)
{
    if (g_81e0 == 1)
        fn_0845_01c4(0, fn_0845_06f8(0x402d), g_81e0);
    else
        fn_0845_01c4(0, fn_0845_06f8(0x402e), g_81e0);
    return 1;
}

int fn_0ca0_02b2(struct Btn far *b)
{
    if (g_806a & 0x4000) {
        if (g_7fdd) {
            if (fn_154c_0057(0x425b, -1, 1)) fn_0845_01c4(4, fn_0845_06f8(0x425b));
        } else
            fn_0845_01c4(0, fn_0845_06f8(g_7fdf + 0x402f));
        return 1;
    }
    return 0;
}

int fn_0ca0_030a(struct Btn far *b)
{
    fn_070c_009f(b->w38);
    fn_0845_01c4(0, fn_0845_06f8(0x4047), f_2803_362d[b->w38].name, f_2803_362d[b->w38].hp,
                 f_2803_362d[b->w38].maxHp, f_2803_362d[b->w38].mp, f_2803_362d[b->w38].maxMp);
    return 1;
}

int fn_0ca0_039a(struct Btn far *b)
{
    if (g_806a & 0x1000) {
        ovr_2ce1_0020();
        ovr_2d2c_0043();
        fn_0845_035b(g_adea, g_81dc, g_81de);
        return 1;
    }
    return 0;
}

int fn_0ca0_03cf(struct Btn far *b)
{
    int held;
    int m;

    if (g_806a & 0x800) {
        held = fn_0845_0ac7();
        if (f_2803_1cfd[held].type == 0xf8) {
            if (g_81dd + 100 > 200)
                fn_0845_01c4(0, fn_0845_06f8(0x4061));
            else {
                fn_0845_01c4(0, fn_0845_06f8(0x4062));
                fn_07bc_044c(g_8048);
                fn_067a_0401(0xb5, 0);
                fn_0845_0acf(0);
                g_81dd += 100;
                if (g_81dc) fn_0845_035b(g_adea, g_81dc, g_81de);
            }
        } else {
            m = g_81dd / 33 + 0x405d;
            m = g_81dd == 0 ? 0x405c : m;
            m = g_81dd >= 100 ? 0x4060 : m;
            fn_0845_01c4(0, fn_0845_06f8(0x405b), fn_0845_06f8(m));
            if (g_81dc) fn_0845_035b(g_adea, g_81dc, g_81de);
        }
        return 1;
    }
    return 0;
}

int fn_0ca0_04dc(struct Btn far *b)
{
    int fl;
    register int held;

    held = fn_0845_0ac7();
    if (!held) return 1;
    fl = g_7fb2[f_2803_1cfd[held].type].flags;
    if (fl & 1) {
        if (!(f_2803_362d[b->w38].flags & 8) || (fl & 0x20)) {
            fn_07bc_047f(b->w38, held, 0x400, 0, 0);
            fn_0845_1343(g_7fd0, 0x400, b->w38, held, 0, 0);
        } else
            fn_0845_01c4(2, fn_0845_06f8(0x402c), f_2803_362d[b->w38].name);
    } else if (fl & 8)
        fn_0845_01c4(2, fn_0845_06f8(0x4029));
    else if (fl & 0x10)
        fn_0845_01c4(2, fn_0845_06f8(0x402a));
    else
        fn_0845_01c4(2, fn_0845_06f8(0x402b));
    return 1;
}

void fn_0ca0_05bb(register int col)
{
    int y;
    register int i;

    col = col ? 0x84 : 1;
    y = 0xf;
    for (i = 0; i < 7; i++) {
        if (g_81f2[i] == -1) break;
        if (g_7fd9 == i) {
            fn_1ebc_00e7();
            fn_1f6c_0006(fn_0845_06f8(f_27dd_0000[g_81f2[i]][8]), 0x18, y, col, 0);
            fn_1ebc_00fe();
            break;
        }
        y += 9;
    }
}

int fn_0ca0_0630(struct Btn far *b)
{
    if (g_7fd9 != b->w38) {
        fn_0ca0_05bb(0);
        g_7fd9 = b->w38;
        fn_0ca0_05bb(1);
        fn_0a21_05ce();
    }
    return 1;
}

int fn_0ca0_0662(struct Btn far *b)
{
    register int ch;

    ch = b->w38;
    if (!(f_2803_362d[ch].flags & 0x314c) && !fn_0845_1280(ch, g_81f2[g_7fd9], 0)) {
        f_2803_362d[ch].flags ^= 0x10;
        fn_0a21_022b(ch);
        ovr_2ceb_0034(ch);
        g_23ba = b->w38;
    }
    return 1;
}

int fn_0ca0_06cb(struct Btn far *b)
{
    register int ch;
    register int lvl;

    lvl = (g_2f12 - 0x90) >> 3;
    ch = b->w38;
    ovr_2ceb_0020();
    if (!fn_0845_1280(ch, g_81f2[g_7fd9], lvl)) {
        f_2803_362d[ch].flags |= 4;
        f_2803_362d[ch].flags &= ~0x10;
        if (!ovr_2d8a_0039(ch, g_81f2[g_7fd9], lvl))
            f_2803_362d[ch].flags &= ~4;
        else {
            fn_0bbc_0744(ch, 1, 8, 1);
            fn_070c_00cf(ch, 2, (long)(lvl * lvl));
            goto done;
        }
    } else
        f_2803_362d[ch].flags &= ~0x10;
    fn_0a21_022b(ch);
done:
    g_23ba = -1;
    return 1;
}

int fn_0ca0_079a(struct Btn far *b)
{
    f_2803_362d[g_23ba].flags &= ~0x10;
    fn_0a21_022b(g_23ba);
    g_23ba = -1;
    if (!(b->flags & 0x80)) {
        if (b->flags & 0x100)
            fn_2169_0945(0x41);
        else
            fn_2169_0945(0x42);
    }
    ovr_2ceb_0020();
    return 1;
}

int fn_0ca0_07e9(struct Btn far *b)
{
    int old;
    register unsigned i;
    register int it;

    if (g_7fd6 & 1) return 0;
    if (fn_0845_0ac7()) return 0;
    old = fn_1e74_000f(g_4d72);
    ovr_2cda_006b();
    for (i = 0; i < 21; i++)
        if ((it = fn_1e6f_000a(g_2f10 + g_23bc[i], g_2f12 + g_23d1[i])) != 0) break;
    fn_1e74_000f(old);
    if (!it) return 0;
    if (it > 0x80)
        i = g_7fd0;
    else
        i = fn_09aa_0183(g_7fd0, g_7fdf);
    if ((it = fn_080e_01a6(&g_8203[i].draw, it & 0x7f)) != -1) {
        fn_07bc_0367(it, i);
        fn_0845_0acf(it);
    }
    g_7fb6 = 1;
    return 1;
}

int fn_0ca0_08af(struct Btn far *b)
{
    int x;
    int y;
    int blk;
    int fl;
    register int k;

    if (g_7fd6 & 1) return 0;
    if (!fn_0845_0ac7()) return 0;
    if (b->w38 > 1) {
        blk = fn_09aa_0183(g_7fd0, g_7fdf);
        k = WALL(blk, g_7fdf ^ 2);
        fl = g_531e[k];
        if (!(fl & 0x80)) return 1;
        if (fl & 2) return 1;
    } else
        blk = g_7fd0;
    k = ((char far *)f_27dd_0000)[(g_7fdf << 2) + b->w38];
    fn_1aff_030e(&x, &y, blk, g_23e6[k], g_23ea[k]);
    fn_07bc_0272(fn_0845_0ac7(), x, y, 0, 1);
    fn_0845_0acf(0);
    return 1;
}

void fn_0ca0_097b(void)
{
    int my;
    int blk;
    register int s;
    register int mx;

    if (!(g_7fda & 4)) return;
    s = -1;
    mx = g_2f0c;
    my = g_2f0e;
    if (!(g_7fd6 & 4) && f_2803_0000[0x48] == 0 && fn_0845_038e(mx, my, 0x60, 0, 0x12f, 0x88) &&
        !fn_0845_038e(mx, my, 0x80, 0x10, 0x10f, 0x77)) {
        if (fn_0845_038e(mx, my, 0x70, 0, 0x11f, 0x0f)) s = 0;
        if (fn_0845_038e(mx, my, 0x110, 0x58, 0x12f, 0x13f)) s = 1;
        if (fn_0845_038e(mx, my, 0x70, 0x6e, 0x11f, 0x87)) s = 2;
        if (fn_0845_038e(mx, my, 0x60, 0x58, 0x7f, 0x77)) s = 3;
        if (fn_0845_038e(mx, my, 0x60, 0x10, 0x7f, 0x57)) s = 4;
        if (fn_0845_038e(mx, my, 0x110, 0x10, 0x12f, 0x57)) s = 5;
        if (s < 4) {
            mx = (g_7fdf + s) & 3;
            blk = fn_09aa_0183(g_7fd0, mx);
            if (!fn_09aa_0404(blk, mx, 0)) s = 6;
        }
    }
    if (s != g_804a) {
        if (s == -1) {
            mx = g_8048 == 0 ? 0 : 8;
            fn_0845_068c(mx, mx, fn_0845_0c08(g_8048));
        } else
            fn_0845_068c(g_23ee[s], g_23f5[s], f_2803_00a6[10 + s]);
        g_804a = s;
    }
}

void fn_0ca0_0b2f(void)
{
    register int k;

    k = fn_163d_0039(g_7fae);
    if (k && g_23ba != -1 && !(k & 0x8800)) {
        ovr_2ceb_0020();
        f_2803_362d[g_23ba].flags &= ~0x10;
        fn_0a21_022b(g_23ba);
        fn_2169_0945(k);
        g_23ba = -1;
        k = 0;
    }
    switch (k) {
    case 0x37:
        if (g_4d66) break;
        if (g_81f2[1] != -1) {
            fn_0ca0_05bb(0);
            g_7fd9++;
            if (g_81f2[g_7fd9] == -1) g_7fd9 = 0;
            fn_0ca0_05bb(1);
            fn_0a21_05ce();
        }
        k = 0;
        break;
    case 0x71a:
        fn_0845_01c4(0, "Lands of Lore %2d(%s):%d:%lu\r", g_7fe5, fn_0845_09a9(g_7fd0), g_7fdf, fn_203b_04ce(0));
        break;
    case 0x2b:
    case 0x3d:
        fn_154c_000f(1);
        break;
    }
    if (k & 0x8000) fn_0d6b_000f();
}

void fn_0ca0_0c33(void)
{
    fn_231c_0008(2);
    g_4bf4 = 0;
    g_8094 |= 0x800;
    while (!g_4bf4) {
        if (g_20d7) {
            fn_0845_13d6(g_20d7, 2);
            g_20d7 = 0;
        }
        fn_0bbc_0645();
        fn_0ca0_097b();
        fn_0ca0_0b2f();
        fn_0845_0636(1, 2);
        fn_0845_093a();
        if (g_7fb6)
            fn_0845_15d9(0);
        else
            fn_067a_026b(0);
        if (g_20d1 != -1) {
            ovr_2cf4_0020(g_20d1);
            g_20d1 = -1;
        }
    }
}
