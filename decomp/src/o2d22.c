/* o2d22: character stats screen (attributes, skill/experience bars, equipment slots) */
#include <stdio.h>
#include <mem.h>
#include "lol.h"

struct Atk2 { int w0; int w2; char pad[0xc]; int w10; };
struct Btn2 { char pad[0x38]; int slot; };
struct Mask { int mask; int idx; };
extern int g_4b18[5];
extern int g_4b12[3];
extern char g_0c4c;
extern struct Mask g_0c4d[];
extern char g_0c21[], g_0c2b[];
extern int g_0c36[];
extern char g_0c5d[], g_0c60[];
extern int g_3649, g_2136, g_4d66, g_2f10;
extern unsigned g_7fd6;
extern char g_7fe3;
extern void far *g_4d5a, far *g_4d56;
extern long far f_2803_0000[];
extern void far * far f_2803_00a6[];
extern int far f_27b1_0160[];
extern char far f_27b1_016a[][0x16];
int fn_1aff_0420(int a, int b);
int fn_070c_000a(int who);
char far *fn_0845_06f8(int id);
void fn_0845_07b3(char far *s, int x, int y, int fg, int bg, int f, ...);
void fn_1dbc_0004(int a, int b, int c, int d, int e, int f, int g, int h);
void fn_1dbc_0017(int a, int b, int c, int d, int e, int f, int g, int h);
void fn_0845_0bb6(int n);
int fn_1e74_000f(int n);
void ovr_2ded_002f(char far *str, int a, int b, char far *p);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_0a21_05ce(void);
void far *fn_0845_04ec(void far *name);
void fn_1fd6_000a(int page, void far *p, int x, int y, int a, int flags);
int fn_1f36_01e2(void far *p);
void fn_1e30_0209(int x1, int y1, int x2, int y2, int c);
void ovr_2ceb_0020(void);
void ovr_2ceb_0025(int c);
void far *fn_215f_0003(int p);
void fn_2279_025b(void far *s, void far *d, long n);
void fn_0c59_0377(void);
void fn_1dff_0008(int a, int b);
void ovr_2d5f_0034(void);
void ovr_2d5f_002f(int a);
void fn_0845_08aa(void);
void fn_231c_0008(int n);
void fn_231c_0048(int n);
void fn_0c59_000d(int page, int item, int x, int y);
void fn_0845_01c4(int kind, char far *fmt, ...);
int fn_0845_0ac7(void);
void fn_0845_0acf(int item);
void fn_07bc_047f(int a, int it, int c, int d, int e);
void fn_0a21_022b(int ch);
void fn_1e59_001d(int x1, int y1, int x2, int y2, int c);
void ovr_2d22_002f(int ch);
void ovr_2d22_003e(int slot);
void ovr_2d22_0052(int x, int y, int w, int h, int val, int max, int c1, int c2);

static int stat(int ch, int which)
{
    struct Char far *p;
    int v;

    switch (which) {
    case 0:
        for (v = which = 0; which < 8; which++) v += f_2803_362d[ch].st.dmg[which];
        if (v == 0)
            v = ((struct Atk2 far *)f_2803_362d[ch].st.atk)->w10;
        else
            v += f_2803_362d[ch].w4a;
        v = fn_1aff_0420(v, ((struct Atk2 far *)f_2803_362d[ch].st.atk)->w2);
        v = fn_1aff_0420(v, f_2803_362d[ch].w46);
        break;
    case 1:
        v = fn_070c_000a(ch);
        break;
    case 2:
    case 3:
    case 4:
        p = &f_2803_362d[ch];
        which = which - 2;
        v = p->skill[which] + p->skillBonus[which];
        break;
    default:
        v = -1;
    }
    return v;
}

void ovr_2d22_0020(int ch)
{
    int i;

    for (i = 0; i < 5; i++) g_4b18[i] = stat(ch, i);
}

static void drawstat(int which, int full, int val)
{
    int y;
    int dx;
    int x0;
    int x1;
    int k;
    int col;
    char far *s;

    if (g_3649 == 0) dx = 0x70; else dx = 0;
    switch (which) {
    case 0:
    case 1:
        k = which;
        x0 = 0x6c;
        s = fn_0845_06f8(k + 0x4014);
        x1 = 0xc8;
        y = k * 10 + 0x16;
        col = 0x9e;
        break;
    case 2:
    case 3:
    case 4:
        k = which - 2;
        x0 = 0x6c;
        s = fn_0845_06f8(k + 0x4016);
        x1 = 0xc8;
        y = k * 10 + 0x3e;
        col = (f_2803_362d[g_7fe3].flags & (0x200 << k)) ? 0xfe : 0xb4;
        break;
    default:
        return;
    }
    if (full) fn_0845_07b3(s, x0 + dx, y, col, 0, 4);
    if (dx) fn_1dbc_0004(x1 + 0x5e, y, x1 + dx - 0x12, y, 0x12, 8, 6, g_3649);
    fn_0845_07b3(g_0c5d, x1 + dx, y, col, 0, 6, val);
}

void ovr_2d22_0025(int ch)
{
    int i;
    int changed;
    int cur[5];
    int step[5];
    int d;

    changed = 0;
    for (i = 0; i < 5; i++) {
        cur[i] = stat(ch, i);
        d = cur[i] - g_4b18[i];
        step[i] = d / 15;
        if (d < 0) {
            if (step[i] == 0) step[i] = -1;
            changed = 1;
        } else if (d > 0) {
            if (step[i] == 0) step[i] = 1;
            changed = 1;
        }
    }
    if (changed) do {
        changed = 0;
        for (i = 0; i < 5; i++) {
            if (cur[i] == g_4b18[i]) continue;
            g_4b18[i] += step[i];
            if ((step[i] < 0 && cur[i] > g_4b18[i]) || (step[i] > 0 && cur[i] < g_4b18[i]))
                g_4b18[i] = cur[i];
            drawstat(i, 0, g_4b18[i]);
            changed = 1;
        }
        fn_0845_0bb6(1);
    } while (changed);
}

void ovr_2d22_002a(int ch)
{
    int i;

    for (i = 0; i < 5; i++) drawstat(i, 1, stat(ch, i));
    g_0c4c |= 1 << ch;
}

void ovr_2d22_002f(int ch)
{
    struct Char far *p;
    int old;
    int i;
    char buf[14];

    old = fn_1e74_000f(2);
    p = &f_2803_362d[ch];
    if (ABS(p->wE) != g_2136) {
        sprintf(buf, g_0c60, g_0c21[ABS(p->wE)]);
        ovr_2ded_002f(buf, 3, 3, 0);
        fn_1dbc_0017(0, 0, 0xe, 0, 0x1a, 0x78, 2, 6);
    } else
        fn_1dbc_0017(0xe, 0, 0, 0, 0x1a, 0x78, 6, 2);
    fn_1ebc_00e7();
    fn_1dbc_0017(0xa, 0x8f, 0xa, 0x8f, 0x1d, 0x23, 0, 2);
    fn_1ebc_00fe();
    fn_0a21_05ce();
    fn_0845_07b3(p->name, 0x9d, 9, 0xfe, 0, 5);
    ovr_2d22_002a(ch);
    for (i = 0; i < 0xb; i++) ovr_2d22_003e(i);
    fn_0845_07b3(fn_0845_06f8(0x4033), 0xb6, 0x67, 0xac, 0, 5);
    {
        int n;
        int x;
        void far *shp;
        int j;

        x = 0;
        j = 0;
        memset(g_4b12, -1, 6);
        n = 0;
        for (; g_0c4d[j].mask; j++) {
            if (g_0c4d[j].mask & p->flags) {
                i = g_0c4d[j].idx;
                shp = fn_0845_04ec(f_2803_00a6[i]);
                fn_1fd6_000a(g_3649, shp, x + 0x6c, 0x62, 0, 0);
                x = fn_1f36_01e2(shp) + x + 2;
                g_4b12[n++] = i;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        long b;
        long a;
        long t;

        a = p->exp[i];
        b = f_2803_0000[p->skill[i]];
        a -= f_2803_0000[p->skill[i] - 1];
        b -= f_2803_0000[p->skill[i] - 1];
        while (b & 0xffff8000L) {
            b >>= 1;
            t = a;
            a = t >> 1;
            if (t != 0 && a == 0) a = 1;
        }
        ovr_2d22_0052(0x9a, i * 10 + 0x40, 0x22, 5, (int)a, (int)b, 0x84, 0);
    }
    fn_1ebc_00e7();
    fn_1e30_0209(0xe, 0x78, 0xc2, 0x78, 1);
    fn_1dbc_0004(0, 0, 0x70, 0, 0xd0, 0x79, 2, 0);
    fn_1dbc_0017(0xa, 0x8f, 0xa, 0x8f, 0x1d, 0x23, 2, 0);
    fn_1ebc_00fe();
    fn_1e74_000f(old);
}

int ovr_2d22_0034(void far *b)
{
    int old;
    int i;

    g_7fd6 &= ~0xc;
    ovr_2ceb_0020();
    g_4d66 = 0;
    for (i = 0; i < 4; i++)
        if (g_0c4c & (1 << i)) f_2803_362d[i].flags &= 0xf1ff;
    fn_1ebc_00e7();
    fn_2279_025b(g_4d5a, fn_215f_0003(2), 0xfa00L);
    old = fn_1e74_000f(2);
    fn_0a21_05ce();
    fn_0c59_0377();
    fn_1e74_000f(old);
    fn_1dff_0008(2, 0);
    ovr_2d5f_0034();
    fn_2279_025b(g_4d56, fn_215f_0003(2), 0xfa00L);
    fn_1ebc_00fe();
    g_2136 = -1;
    fn_0845_08aa();
    fn_231c_0008(2);
    return 1;
}

int ovr_2d22_0039(struct Btn2 far *b)
{
    fn_231c_0048(2);
    if (g_4d66 == 0) {
        fn_1ebc_00e7();
        fn_2279_025b(fn_215f_0003(2), g_4d56, 0xfa00L);
        fn_1dbc_0017(0, 0, 0, 0, 0x28, 0xc8, 0, 2);
        fn_2279_025b(fn_215f_0003(2), g_4d5a, 0xfa00L);
        fn_1ebc_00fe();
        g_7fd6 |= 0xc;
        ovr_2d5f_002f(1);
    }
    g_7fe3 = b->slot;
    g_4d66 = 1;
    ovr_2d22_002f(g_7fe3);
    ovr_2ceb_0025(g_7fe3);
    return 1;
}

void ovr_2d22_003e(int slot)
{
    int y;
    int it;
    int frame;
    int x;
    int t;

    t = f_27b1_0160[f_2803_362d[g_7fe3].cD];
    x = f_27b1_016a[t][slot * 2];
    y = f_27b1_016a[t][slot * 2 + 1];
    if (x == -1) return;
    if (y == -1) return;
    if (g_3649 == 0) x += 0x70;
    it = f_2803_362d[g_7fe3].items[slot];
    if (it) {
        if (slot >= 9) frame = 5;
        else frame = 4;
    } else
        frame = g_0c2b[slot];
    fn_1ebc_00e7();
    fn_1fd6_000a(g_3649, fn_0845_04ec(f_2803_00a6[frame]), x, y, 0, 0);
    if (it) {
        if (slot >= 9) {
            x -= 5;
            y -= 5;
        }
        fn_0c59_000d(g_3649, it, x + 1, y + 1);
    }
    fn_1ebc_00fe();
}

void ovr_2d22_0043(int it, unsigned mask)
{
    int k;
    int i;

    for (i = 0; i < 0xb; i++) {
        if (mask & (1 << i)) {
            k = i <= 3 ? 0x418b : 0x418a;
            fn_0845_01c4(0, fn_0845_06f8(k), fn_0845_06f8(g_7fb2[f_2803_1cfd[it].type].name), fn_0845_06f8(g_0c36[i]));
            return;
        }
    }
    fn_0845_01c4(f_2803_1cfd[it].type == 0xe7 ? 2 : 0, fn_0845_06f8(0x418c));
}

void ovr_2d22_0048(int slot)
{
    fn_0845_01c4(0, fn_0845_06f8(g_0c36[slot] + 8));
}

int ovr_2d22_004d(struct Btn2 far *b)
{
    int it;
    unsigned m;

    if (fn_0845_0ac7()) {
        m = g_7fb2[f_2803_1cfd[fn_0845_0ac7()].type].w5;
        if (!(m & (1 << b->slot))) {
            ovr_2d22_0043(fn_0845_0ac7(), m);
            return 1;
        }
    } else if (f_2803_362d[g_7fe3].items[b->slot] == 0) {
        ovr_2d22_0048(b->slot);
        return 1;
    }
    it = fn_0845_0ac7();
    fn_0845_0acf(f_2803_362d[g_7fe3].items[b->slot]);
    f_2803_362d[g_7fe3].items[b->slot] = it;
    ovr_2d22_003e(b->slot);
    ovr_2d22_0020(g_7fe3);
    if (fn_0845_0ac7()) fn_07bc_047f(g_7fe3, fn_0845_0ac7(), 0x100, 0, 0);
    if (it) fn_07bc_047f(g_7fe3, it, 0x80, 0, 0);
    ovr_2d22_003e(b->slot);
    fn_0a21_022b(g_7fe3);
    ovr_2d22_0025(g_7fe3);
    return 1;
}

void ovr_2d22_0052(int x, int y, int w, int h, int val, int max, int c1, int c2)
{
    int n;

    if (max < 1) return;
    val = val > 0 ? val : 0;
    val = max < val ? max : val;
    w--;
    h--;
    if (w == 0 || h == 0) return;
    n = (int)((long)w * val / max);
    n += (n == 0 && val != 0) ? 1 : 0;
    if (n) fn_1e59_001d(x, y, x + n - 1, y + h, c1);
    if (n < w && c2) fn_1e59_001d(x + n, y, x + w, y + h, c2);
}

int ovr_2d22_0057(void)
{
    int v;

    v = g_2f10 - 0xdc;
    v = v > 0 ? v : 0;
    v = v / 14;
    v = v < 2 ? v : 2;
    v = g_4b12[v];
    switch (v) {
    case -1: v = -1; break;
    case 0: v = 0x424c; break;
    case 2: v = 0x424d; break;
    case 1: v = 0x424e; break;
    }
    if (v != -1) fn_0845_01c4(0x8002, fn_0845_06f8(v));
    return 1;
}
