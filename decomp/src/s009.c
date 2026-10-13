/* s009: party movement (step/turn buttons, blocked checks, automap reveal) and the move-button animation */
#include "lol.h"

struct Btn { char pad[0x2e]; unsigned flags; char pad30[8]; int w38; };

extern char far f_2803_0000[];
extern void far * far f_2803_00a6[];
extern char far f_2803_030a[];
extern unsigned char far f_2803_3835[];
extern int g_2176[], g_218c[];
extern int g_ab24;
extern unsigned long g_ab26, g_384c;
extern unsigned g_806a, g_7fda, g_8094;
extern int g_7fd0, g_7fd2, g_7fd4, g_7fdf;
extern char g_7fd8, g_7fdc;

void far *fn_0845_04ec(void far *name);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_1fd6_000a(int k, void far *p, int x, int y, int a, int mode, char far *t, int b);
int fn_1e74_000f(int n);
int fn_1f36_0224(void far *p);
int fn_1f36_01e2(void far *p);
void fn_1b63_0004(int x, int y, int w, int h, int a);
void fn_1dbc_0004(int a, int b, int c, int d, int e, int f, int g, int h);
void fn_0845_13d6(int b, unsigned mask);
void fn_0845_114d(int id, int flag);
void fn_0acb_0461(int n);
void fn_0acb_0604(int n);
void fn_0acb_01b4(int n);
void fn_0acb_001e(int n);
void fn_0acb_032e(int n);
void fn_0acb_07a7(int n);
void fn_0acb_089c(int n);
void fn_0845_15d9(int a);
void fn_2169_062e(void);
void fn_154c_000f(int n);
char far *fn_0845_06f8(int id);
void fn_0845_01c4(unsigned flags, char far *fmt, ...);
void fn_067a_0401(int n, int force);
int fn_0845_0cf7(int b, int dir, int mask);
struct Item far *fn_080e_000b(int id);
void fn_1aff_030e(int *x, int *y, int b, int a, int c);

int fn_09aa_0183(int b, int dir);
void fn_09aa_0458(int dir, int f, int c, int key);
void fn_09aa_05b3(int b);
void fn_09aa_06d7(int b);

int g_220a[22] = { 86, 296, 12, 33, 290, 12, 33, 54, 12, 33, 54, 180, 180, 180, 180, 32, 132, 132, 132, 150, 150, 150 };
int g_2236[4] = { -32, 1, 32, -1 };
int g_223e[3] = { 1, -1, 3 };
int g_2244[3] = { 2, -1, 0 };
int g_224a[3] = { -1, 0, 1 };
int g_2250[3] = { -32, 0, 32 };

void fn_09aa_0007(int n, int md)
{
    int old;
    int k;
    int y;
    int x2;
    int y2;
    void far *p;
    register int mode = md;
    register int x;

    if (n == 0x4e && !(g_806a & 0x1000)) return;
    if (f_2803_0000[0x45] && f_2803_0000[0x44]) return;
    if (!mode) n = g_ab24;
    k = 0;
    x = g_2176[n];
    y = g_218c[n];
    switch (mode) {
    case 1:
        mode = 0x100;
        g_ab24 = n;
        break;
    case 0:
        if (!g_ab24) return;
        do ; while (g_ab26 > g_384c);
        mode = 0;
        g_ab24 = 0;
        break;
    case 2:
        mode = 0;
        g_ab24 = 0;
        break;
    case 3:
        g_ab24 = 0;
        k = 6;
        mode = 0;
        x2 = x;
        y2 = y;
        x = 0;
        y = 0;
        break;
    }
    p = fn_0845_04ec(f_2803_00a6[n]);
    fn_1ebc_00e7();
    fn_1fd6_000a(k, p, x, y, 0, mode, f_2803_030a, 1);
    if (k == 6) {
        old = fn_1e74_000f(6);
        fn_1b63_0004(x, y, fn_1f36_01e2(p), fn_1f36_0224(p), 1);
        fn_1dbc_0004(x, y, x2, y2, fn_1f36_01e2(p), fn_1f36_0224(p), k, 0);
        fn_1e74_000f(old);
    }
    fn_1ebc_00fe();
    g_ab26 = g_384c + 6;
}

int fn_09aa_0183(int b, int dir)
{
    return (b + g_2236[dir]) & 0x3ff;
}

int fn_09aa_0197(struct Btn far *btn)
{
    int f;

    if (btn->w38 && !(g_7fda & 4)) return 0;
    f = (btn->flags & 0x1080) == 0x1080 ? 1 : 0;
    fn_09aa_0458(g_7fdf, f, 0, 0x50);
    return 1;
}

int fn_09aa_01e4(struct Btn far *btn)
{
    if (btn->w38 && !(g_7fda & 4)) return 0;
    fn_09aa_0458(g_7fdf ^ 2, 0, 1, 0x53);
    return 1;
}

int fn_09aa_0219(struct Btn far *btn)
{
    int f;

    if (btn->w38 && !(g_7fda & 4)) return 0;
    f = (btn->flags & 0x1080) == 0x1080 ? 1 : 0;
    fn_09aa_0458((g_7fdf - 1) & 3, f, 2, 0x52);
    return 1;
}

int fn_09aa_026a(struct Btn far *btn)
{
    int f;

    if (btn->w38 && !(g_7fda & 4)) return 0;
    f = (btn->flags & 0x1080) == 0x1080 ? 1 : 0;
    fn_09aa_0458((g_7fdf + 1) & 3, f, 3, 0x54);
    return 1;
}

int fn_09aa_02bb(struct Btn far *btn)
{
    if (btn->w38 && !(g_7fda & 4)) return 0;
    fn_09aa_0007(0x4f, 1);
    g_7fdf = (g_7fdf - 1) & 3;
    g_7fdc = 1;
    fn_0845_13d6(g_7fd0, 0x4000);
    fn_0845_114d(2, 0);
    if (g_7fdc) fn_0acb_0461(1);
    else fn_0845_15d9(0);
    fn_09aa_0007(0x4f, 0);
    fn_0845_13d6(g_7fd0, 0x10);
    return 1;
}

int fn_09aa_033f(struct Btn far *btn)
{
    if (btn->w38 && !(g_7fda & 4)) return 0;
    fn_09aa_0007(0x51, 1);
    g_7fdf = (g_7fdf + 1) & 3;
    g_7fdc = 1;
    fn_0845_13d6(g_7fd0, 0x4000);
    fn_0845_114d(2, 0);
    fn_09aa_0007(0x51, 0);
    if (g_7fdc) fn_0acb_0604(1);
    else fn_0845_15d9(0);
    fn_0845_13d6(g_7fd0, 0x10);
    return 1;
}

void fn_09aa_03c3(int a)
{
    fn_2169_062e();
    if (a) fn_0acb_01b4(2);
    fn_154c_000f(1);
    fn_0845_01c4(0x8002, fn_0845_06f8(0x403f));
    fn_067a_0401(0x13, 0);
}


int fn_09aa_0404(int b, int dir, int f)
{
    struct Item far *p;
    int o;

    if (fn_0845_0cf7(b, dir, 1)) return 0;
    if (!(o = g_8203[b].mon)) return 1;
    for (; o; o = p->next) {
        if (o & 0x8000) return 0;
        p = fn_080e_000b(o);
    }
    return 1;
}


void fn_09aa_0458(int dir, int f, int c, int key)
{
    int old;
    register int nb;
    int i;

    if (key) fn_09aa_0007(key, 1);
    old = g_7fd0;
    nb = fn_09aa_0183(old, dir);
    if (!fn_09aa_0404(nb, dir, f)) {
        fn_09aa_03c3(c == 0);
        fn_09aa_0007(key, 0);
        return;
    }
    g_7fd8 = dir;
    g_7fd0 = nb;
    g_7fdc = 1;
    fn_1aff_030e(&g_7fd2, &g_7fd4, g_7fd0, 0x80, 0x80);
    g_8094 &= ~0x200;
    fn_0845_13d6(old, 4);
    fn_0845_13d6(nb, 1);
    if (!(g_8094 & 0x200)) {
        fn_0845_114d(2, 0);
        if (g_7fdc) {
            switch (c) {
            case 0: fn_0acb_001e(2); break;
            case 1: fn_0acb_032e(2); break;
            case 2: fn_0acb_07a7(1); break;
            case 3: fn_0acb_089c(1); break;
            }
        } else
            fn_0845_15d9(0);
        fn_09aa_0007(key, 0);
        if (g_7fd0 == nb) {
            fn_0845_13d6(old, 8);
            fn_0845_13d6(nb, 2);
            if (WALL(nb, 0) == 0x1a)
                for (i = 0; i < 4; i++) WALL(nb, i) = 0;
        }
    }
    fn_09aa_05b3(g_7fd0);
}

void fn_09aa_05b3(int b)
{
    if (g_806a & 0x1000) {
        g_8203[b].flags |= 7;
        fn_09aa_06d7(b);
    }
}

int fn_09aa_05d4(int b, int x, int y, int dx, int dy)
{
    int w1;
    int w2;
    int nb;

    x += dx;
    y += dy;
    if ((x & 0xffe0) || (y & 0xffe0)) return 0;
    dx++;
    dy++;
    w1 = g_223e[dx];
    nb = b + g_224a[dx];
    if (w1 != -1 && (f_2803_3835[WALL(nb, w1)] & 0xc0)) return 0;
    w2 = g_2244[dy];
    nb = b + g_2250[dy];
    if (w2 != -1 && (f_2803_3835[WALL(nb, w2)] & 0xc0)) return 0;
    nb = b + g_224a[dx] + g_2250[dy];
    if (w1 != -1 && w2 != -1 && (f_2803_3835[WALL(nb, w1)] & 0xc0) && (f_2803_3835[WALL(nb, w2)] & 0xc0))
        return 0;
    g_8203[nb].flags |= 7;
    return 1;
}

void fn_09aa_06d7(int blk)
{
    int y;
    register int b = blk;
    register int x;

    x = b;
    x &= 0x1f;
    y = b >> 5;
    fn_09aa_05d4(b, x, y, -1, -1);
    fn_09aa_05d4(b, x, y, 1, -1);
    fn_09aa_05d4(b, x, y, -1, 1);
    fn_09aa_05d4(b, x, y, 1, 1);
    fn_09aa_05d4(b, x, y, 0, -1);
    fn_09aa_05d4(b, x, y, 0, 1);
    fn_09aa_05d4(b, x, y, -1, 0);
    fn_09aa_05d4(b, x, y, 1, 0);
}
