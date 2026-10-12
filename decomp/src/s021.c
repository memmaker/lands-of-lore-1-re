/* s021: wall decoration hotspots (buttons, levers, doors) and the message box button bar */
#include "lol.h"

struct Deco {               /* 0x48 bytes, g_5a52[]: wall decorations */
    int w0;
    int shape;               /* +02 -1: none */
    char pad04[0x1c];
    int x;                   /* +20 */
    char pad22[0x12];
    int y;                   /* +34 */
    char pad36[0x10];
    char next;               /* +46 next decoration drawn on the same wall */
    unsigned char flags;     /* +47 1 mirrored */
};

struct Door { int block; char dir; char delta; };

extern struct Deco g_5a52[];
extern int (far *g_282c[])(int block, int dir);
extern char g_2848[];
#define g_2849 (g_2848 + 1)
extern void far *g_5412[];
extern char g_536e[];
extern unsigned char g_531e[];
extern struct Door g_4ed0[];
extern int g_7fb6, g_4be0, g_7fd0, g_7fdf;
extern char far f_2803_0056[];
extern unsigned char far f_2803_0044;
extern char far f_2803_0045;
extern void far *g_7fbc;
extern int g_2f16;
extern unsigned char g_2f43;
extern char far *g_ab32[3];
extern int g_ab2a, g_ab2c, g_ab2e, g_ab30, g_4bde;
extern int g_2f0c, g_2f0e, g_2f10, g_2f12;
extern unsigned long g_2138, g_384c;
extern char g_81fe, g_81ff;
extern int g_3711, g_1f87, g_1f89;
extern unsigned g_ad8b, g_ad8d, g_ad8f, g_ad91;
extern int g_20f6, g_4bf8, g_4bfc, g_4c00, g_2170, g_2172;
extern unsigned g_7fd6;

void far *fn_0845_04ec(void far *name);
int fn_1f36_01e2(void far *p);
int fn_1f36_0224(void far *p);
int fn_0845_03b4(int a, int b, int c, int d);
void fn_154c_000f(int n);
void fn_0845_13d6(int b, unsigned mask);
void fn_067a_0401(int n, int force);
void fn_2120_0007(int n);
int fn_0845_0ac7(void);
void fn_1aff_03b4(int far *x, int far *y, int d);
void fn_1aff_030e(int far *x, int far *y, int b, int cx, int cy);
void fn_07bc_0272(int it, int x, int y, int a, int b);
void fn_0845_0acf(int item);
int fn_09aa_0183(int pos, int dir);
void fn_2169_062e(void);
int fn_0845_046c(int block);
void fn_067a_02f5(int n, int pos);
void fn_067a_026b(int n);
void fn_0bbc_070e(int n, int en);
int fn_1e74_000f(int n);
void far *fn_1f2d_0002(void far *p);
void fn_1ebc_00fe(void);
void fn_1ebc_00e7(void);
void fn_0845_0008(int x, int y, int w, int h, int c1, int c2, int fill);
unsigned fn_1e64_002b(char far *s);
void fn_1f6c_0006(char far *s, int x, int y, void far *c);
int fn_0845_038e(int x, int y, int x1, int y1, int x2, int y2);
int fn_2169_060c(void);
int fn_2169_0790(void);
void fn_163d_0004(void);
int fn_154c_0136(void);
void fn_130a_0784(void);
void fn_14b3_0122(int n);
void fn_14b3_01fa(int n);
void fn_1e59_001d(int x1, int y1, int x2, int y2, int c);
long fn_0bbc_0960(int n);
void fn_0bbc_09a9(int n, long v);
unsigned long ovr_2da3_002f(void);
char far *fn_0845_06f8(int id);
void fn_14b3_0215(void);
void fn_0845_093a(void);

int fn_13e8_00d4(int block, int dir);
int fn_13e8_011c(int block, int dir);
int fn_13e8_017c(int block, int dir);
int fn_13e8_01dc(int block, int dir);
int fn_13e8_01f1(int block, int dir);
int fn_13e8_0261(int block, int dir);
void fn_13e8_0358(int block, int dir, int delta);
void fn_13e8_03e9(int block, int delta);

/* clicked a decoration (and those drawn with it)? */
int fn_13e8_0005(register int d)
{
    void far *shp;
    int x;
    int y;
    int w;
    int h;

    while (d) {
        if (g_5a52[d].shape != -1) {
            shp = fn_0845_04ec(g_5412[g_5a52[d].shape]);
            x = g_5a52[d].x + 0x88;
            y = g_5a52[d].y + 8;
            w = fn_1f36_01e2(shp);
            h = fn_1f36_0224(shp);
            if (g_5a52[d].flags & 1) w <<= 1;
            if (fn_0845_03b4(x - 4, y - 4, x + w + 8, y + h + 8)) return 1;
        }
        d = g_5a52[d].next;
    }
    return 0;
}

int fn_13e8_00d4(int block, int dir)
{
    int d;

    d = g_536e[WALL(block, dir)];
    if (fn_13e8_0005(d)) {
        fn_154c_000f(1);
        fn_0845_13d6(block, 0x40);
        return 1;
    }
    return 0;
}

int fn_13e8_011c(int block, int dir)
{
    int d;

    d = g_536e[WALL(block, dir)];
    if (fn_13e8_0005(d)) {
        WALL(block, dir)++;
        g_7fb6 = 1;
        fn_067a_0401(0x1e, 0);
        fn_0845_13d6(block, 0x40);
        return 1;
    }
    return 0;
}

int fn_13e8_017c(int block, int dir)
{
    int d;

    d = g_536e[WALL(block, dir)];
    if (fn_13e8_0005(d)) {
        WALL(block, dir)--;
        g_7fb6 = 1;
        fn_067a_0401(0x1d, 0);
        fn_0845_13d6(block, 0x40);
        return 1;
    }
    return 0;
}

int fn_13e8_01dc(int block, int dir)
{
    fn_0845_13d6(block, 0x40);
    return 1;
}

int fn_13e8_01f1(int block, int dir)
{
    int d;

    d = g_536e[WALL(block, dir)];
    if (fn_13e8_0005(d)) {
        g_4be0 = 0;
        fn_067a_0401(0x4e, 0);
        fn_0845_13d6(block, 0x40);
        if (!g_4be0) {
            fn_2120_0007(0xf);
            fn_13e8_0358(block, dir, 0);
        }
        return 1;
    }
    return 0;
}

int fn_13e8_0261(int block, int dir)
{
    int d;
    int x;
    int y;

    d = g_536e[WALL(block, dir)];
    if (fn_13e8_0005(d) && fn_0845_0ac7()) {
        x = 0x80;
        y = 0xff;
        fn_1aff_03b4(&x, &y, g_7fdf);
        fn_1aff_030e(&x, &y, block, x, y);
        fn_07bc_0272(fn_0845_0ac7(), x, y, 8, 1);
        fn_0845_0acf(0);
        return 1;
    }
    return 0;
}

int fn_13e8_02fa(void)
{
    int b;
    int d;
    int w;

    b = fn_09aa_0183(g_7fd0, g_7fdf);
    d = g_7fdf ^ 2;
    w = WALL(b, d);
    if (f_2803_0056[w]) w = g_282c[f_2803_0056[w]](b, d);
    else w = 0;
    fn_2169_062e();
    return w;
}

void fn_13e8_0358(int block, int dir, int delta)
{
    int i;

    if (g_7fd0 != block && !(g_8203[block].mon & 0x8000)) {
        if (!delta) {
            for (i = 0; i < 3; i++) {
                if (g_4ed0[i].block == block) {
                    delta = -g_4ed0[i].delta;
                    break;
                }
            }
        }
        if (!delta) {
            dir = (g_531e[WALL(block, 0)] & 8) ? 0 : 1;
            if (g_531e[WALL(block, dir)] & 1) delta = 1;
            else delta = -1;
        }
        fn_13e8_03e9(block, delta);
    }
}

/* NONMATCHING original keeps block in si, mask/index in di */
void fn_13e8_03e9(int block, int delta)
{
    char w;
    int free;
    int found;
    char side;
    int i;

    free = found = -1;
    side = (g_531e[WALL(block, 0)] & 8) ? 0 : 1;
    w = WALL(block, side);
    if (g_2849[delta] & g_531e[w]) return;
    for (i = 0; i < 3; i++) {
        if (g_4ed0[i].block == block) {
            found = i;
            break;
        }
        if (g_4ed0[i].block == 0 && free == -1) free = i;
    }
    if (found == -1 && free == -1) {
        while (!(g_2849[delta] & g_531e[w])) w += delta;
        WALL(block, side) = w;
        WALL(block, side ^ 2) = w;
        fn_0845_046c(block);
        return;
    }
    if (found == -1) found = free;
    g_4ed0[found].block = block;
    g_4ed0[found].delta = delta;
    g_4ed0[found].dir = side;
    if (g_2849[-delta] & g_531e[w]) {
        WALL(block, side) += delta;
        WALL(block, side ^ 2) += delta;
        if (delta == -1) i = 0x20;
        else i = 0x1f;
        if (fn_0845_046c(block)) {
            fn_067a_02f5(i, block);
        } else {
            fn_067a_02f5(i, block);
            fn_067a_026b(0);
        }
    }
    fn_0bbc_070e(0, 1);
}

void fn_13e8_05a4(void)
{
    int n;
    int oldWin;
    void far *oldFont;
    char far * far *lbl;
    int x;
    int i;

    oldWin = fn_1e74_000f(0);
    oldFont = fn_1f2d_0002(g_7fbc);
    n = g_2f16;
    if (!g_2f43)
        while (g_2f16) fn_1ebc_00fe();
    lbl = g_ab32;
    x = g_ab30;
    for (i = 1; i <= g_4bde; i++) {
        fn_1ebc_00e7();
        fn_0845_0008(x, g_ab2e, 0x4a, 9, 0x88, 0xfb, -1);
        fn_1f6c_0006(*lbl, x + 0x25 - (fn_1e64_002b(*lbl) >> 1), g_ab2e + 2, (void far *)(i != g_ab2a ? 0xfeU : 0x90U));
        fn_1ebc_00fe();
        x += g_ab2c;
        lbl++;
    }
    if (!g_2f43)
        while (n--) fn_1ebc_00e7();
    fn_1e74_000f(oldWin);
    fn_1f2d_0002(oldFont);
}

/* message box buttons: returns the chosen button or 0 */
int fn_13e8_06a1(void)
{
    int old;
    int r;
    int x;
    int i;

    r = 0;
    old = g_ab2a;
    for (x = g_ab30, i = 1; i <= g_4bde; x += g_ab2c, i++) {
        if (fn_0845_038e(g_2f0c, g_2f0e, x, g_ab2e, x + 0x4a, g_ab2e + 9)) {
            g_ab2a = i;
            break;
        }
    }
    if (g_4bde == 0) {
        if (fn_2169_060c()) {
            i = fn_2169_0790() & 0xfff;
            fn_163d_0004();
            if (i == 0x2b || i == 0x3d) {
                fn_154c_000f(1);
                g_2138 = 0;
            }
        }
        if (fn_154c_0136() != 2 && g_2138 <= g_384c) {
            r = 1;
            fn_2169_062e();
            fn_163d_0004();
        }
    } else if (fn_2169_060c()) {
        i = fn_2169_0790() & 0xfff;
        fn_163d_0004();
        switch (i) {
        case 0x4f: case 0x5c:
            if (g_4bde > 1) {
                g_ab2a--;
                if (g_ab2a < 1) g_ab2a = g_4bde;
            }
            break;
        case 0x59: case 0x66:
            if (g_4bde > 1) {
                if (++g_ab2a > g_4bde) g_ab2a = 1;
            }
            break;
        case 0x2b: case 0x3d:
            fn_154c_000f(1);
            g_2138 = 0;
            r = g_ab2a;
            break;
        case 0x841: case 0x842:
            for (x = g_ab30, i = 1; i <= g_4bde; x += g_ab2c, i++) {
                if (fn_0845_038e(g_2f10, g_2f12, x, g_ab2e, x + 0x4a, g_ab2e + 9)) {
                    g_ab2a = i;
                    r = g_ab2a;
                    break;
                }
            }
            break;
        }
    }
    if (old != g_ab2a) fn_13e8_05a4();
    if (r) {
        fn_130a_0784();
        if (!g_81fe && f_2803_0045) {
            fn_14b3_0122(5);
            fn_1ebc_00e7();
            fn_1e59_001d(g_ad8d, g_ad8b + g_ad91 - 9, g_ad8d + g_ad8f - 1, g_ad8b + g_ad91 - 1, g_3711);
            fn_1ebc_00fe();
        } else {
            fn_1ebc_00e7();
            fn_1e59_001d(g_ad8d, g_ad8b, g_ad8d + g_ad8f - 2, g_ad8b + g_ad91 - 1, g_3711);
            fn_14b3_01fa(4);
            fn_1ebc_00fe();
            g_1f87 = 0;
            g_1f89 = 0;
        }
    }
    return r;
}

void fn_13e8_0903(int n, char far *a, char far *b, char far *c)
{
    if (n == 1 && g_81ff) {
        fn_14b3_0122(5);
        g_4bde = 0;
        g_ab32[0] = 0;
        g_ab32[1] = 0;
        g_ab32[2] = 0;
    } else {
        g_ab2a = 1;
        g_4bde = n;
        g_ab32[0] = a;
        g_ab32[1] = b;
        g_ab32[2] = c;
        fn_14b3_0122(5);
        g_ab2e = g_ad8b + g_ad91 - 9;
        if (n == 1) {
            g_ab2c = 0;
            g_ab30 = g_ad8d + g_ad8f - 0x4d;
        } else {
            g_ab2c = g_ad8f / n;
            g_ab30 = g_ad8d + (g_ab2c >> 1) - 0x25;
        }
        fn_13e8_05a4();
        fn_2169_062e();
    }
}

/* <MORE> prompt: wait for a click/key (or the voice to end) */
void fn_13e8_09b7(void)
{
    int wait;
    int n;
    int key;
    int clicked;
    int oldWin;
    void far *oldFont;
    long old;
    int savC00;
    int savBfc;
    unsigned long deadline;
    int x;
    int y;

    oldWin = fn_1e74_000f(0);
    oldFont = fn_1f2d_0002(g_7fbc);
    old = fn_0bbc_0960(0xb);
    g_20f6 = 0;
    if (g_4bf8 != -1) {
        savC00 = g_4c00;
        g_4c00 = 0;
        savBfc = g_4bfc;
        if (g_4bfc > 0x24) g_4bfc = 0x24;
    }
    {
        unsigned long t;

        if (g_81ff) {
            t = ovr_2da3_002f();
            if (t && g_2170) {
                deadline = g_384c + (long)g_2172 * ovr_2da3_002f() / (long)g_2170;
                goto done;
            }
        }
        deadline = 0;
    done:;
    }
    x = (g_ad8d + g_ad8f) * 8 - 0x4d;
    if (f_2803_0044 == 0 || !(g_7fd6 & 2)) {
        y = g_ad8b + g_ad91 - 10;
    } else if (f_2803_0045 == 0 && (g_7fd6 & 2)) {
        x += 6;
        y = g_ad8b + g_ad91 - 2;
    } else {
        y = g_ad8b + g_ad91 - 5;
    }
    fn_1ebc_00e7();
    fn_0845_0008(x, y, 0x4a, 9, 0x88, 0xfb, -1);
    fn_1f6c_0006(fn_0845_06f8(0x4073), x + 0x25 - (fn_1e64_002b(fn_0845_06f8(0x4073)) >> 1), y + 2, (void far *)0x90);
    fn_1ebc_00fe();
    fn_2169_062e();
    n = g_2f16;
    if (!g_2f43)
        while (g_2f16) fn_1ebc_00fe();
    wait = 1;
    clicked = 0;
    do {
        while (!fn_2169_060c()) {
            fn_0845_093a();
            if (g_81ff && (g_384c > deadline || fn_154c_0136() != 2) && deadline) {
                wait = 0;
                key = 0x2b;
                break;
            }
        }
        if (wait) key = fn_2169_0790() & 0x8ff;
        fn_163d_0004();
        switch (key) {
        case 0x41: case 0x42:
            if (fn_0845_03b4(x, y, x + 0x4a, y + 9)) clicked = 1;
            break;
        case 0x841: case 0x842:
            if (!clicked) break;
        case 0x2b: case 0x3d:
            wait = 0;
            break;
        }
    } while (wait);
    if (!g_2f43)
        while (n--) fn_1ebc_00e7();
    fn_1ebc_00e7();
    fn_1e59_001d(x, y, x + 0x4a, y + 9, g_3711);
    fn_14b3_0215();
    fn_1ebc_00fe();
    fn_0bbc_09a9(0xb, old);
    if (g_4bf8 != -1) {
        g_4c00 = savC00;
        if (savBfc > 0x24) savBfc -= 0x24;
        else savBfc >>= 1;
        g_4bfc = savBfc;
    }
    fn_1f2d_0002(oldFont);
    fn_1e74_000f(oldWin);
    fn_2169_062e();
}

/* wall type actions (f_2803_0056[wall]) */
int (far *g_282c[7])(int block, int dir) = {
    0, fn_13e8_00d4, fn_13e8_011c, fn_13e8_017c, fn_13e8_01dc, fn_13e8_01f1, fn_13e8_0261
};
char g_2848[3] = { 0x20, 0, 0x10 };     /* door wall bit by delta + 1 */
