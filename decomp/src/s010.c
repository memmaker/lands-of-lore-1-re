/* s010: character portraits (faces, hit/magic point bars, equipment checks, portrait layout) */
#include "lol.h"

struct BarDef { int x; int color; int tcolor; int flag; int str; };

extern char far f_2803_0000[];
extern void far * far f_2803_00a6[];
extern char far f_2803_020a[];
extern int far f_2803_3625[];
extern char far f_27b1_004d[];
extern char far *g_4c06[][28];
extern void far *g_7fbc;
extern char g_81f2[];
extern char g_7fd9, g_7fe3, g_81fe;
extern int g_3649, g_4d66;
extern unsigned g_7fd6;
extern long g_3850;

void far *fn_0845_04ec(void far *name);
void fn_0845_0631(void far *p);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_1fd6_000a(int page, void far *p, int x, int y, int a, int flags, ...);
void far *fn_1f2d_0002(void far *p);
int fn_1e74_000f(int n);
void fn_0845_0008(int x, int y, int w, int h, int c1, int c2, int fill);
void fn_0845_00ac(int x, int y, int val, int val2, int max, int w, int h, int color, int bg, int flag);
char far *fn_0845_06f8(int id);
void fn_1f6c_0006(char far *s, int x, int y, int c1, int c2);
int fn_0845_122b(struct Char far *c, int cls);
void fn_1b63_0004(int page, int x, int y, int w, int h);
void fn_0845_07b3(char far *fmt, int x, int y, int c1, int c2, unsigned flags, ...);
int ovr_2d74_0025(void);
void fn_1e54_0001(int x1, int y1, int x2, int y2, int c);
void fn_1dbc_0004(int a, int b, int c, int d, int e, int f, int g, int h);
void fn_0bbc_0744(int ch, int a, int snd, int b);

void fn_0a21_022b(int ch);
void fn_0a21_05ce(void);
void fn_0a21_0674(int ch, int f, int snd, int redraw);

struct BarDef g_2256[2] = { { 0x21, 0xa2, 0xa0, 0, 0x4253 }, { 0x27, 0x9a, 0x98, 1, 0x4254 } };

char far *fn_0a21_000b(int ch)
{
    struct Char far *c;
    int it;
    int t;
    int best;
    int i;

    c = &f_2803_362d[ch];
    best = -1;
    t = 0;
    for (i = 0; i < 2; i += 2)
        if (c->items[i] && g_7fb2[f_2803_1cfd[c->items[i]].type].w8 > best) {
            it = c->items[i];
            t = f_2803_1cfd[it].type;
            best = g_7fb2[t].w8;
        }
    best = f_27b1_004d[g_7fb2[t].shape * 2];
    if (best == 0x5a) {
        best = c->cD - 1;
        if (best < 0) best = 0;
        best += 0x44;
    }
    return f_2803_00a6[best];
}

void fn_0a21_00ec(int ch, int x, int y, int page)
{
    struct Char far *c;
    void far *p;
    int f;

    c = &f_2803_362d[ch];
    if (c->face < 7 && c->faceDef) c->face = c->faceDef;
    if (c->faceDef == 0 && c->face > 1 && c->face < 7) c->face = c->faceDef;
    f = c->face;
    if ((c->flags & 0x1108) && c->face < 7) f = 1;
    if (c->hp <= c->maxHp >> 1) f += 14;
    p = fn_0845_04ec(g_4c06[ch][f]);
    if (!page) fn_1ebc_00e7();
    fn_1fd6_000a(page, p, x, y, 0, 0x100, f_2803_020a, (c->flags & 0x80) ? 1 : 0);
    fn_0845_0631(p);
    if (c->flags & 0x40) {
        p = fn_0845_04ec(f_2803_00a6[21]);
        fn_1fd6_000a(page, p, x, y, 0, 0);
        fn_0845_0631(p);
    }
    if (!page) fn_1ebc_00fe();
}

void fn_0a21_022b(int chr)
{
    struct Char far *c;
    void far *save;
    int x;
    int k;
    int n;
    register int ch = chr;
    register int page;
    int d;

    c = &f_2803_362d[ch];
    if (!(c->flags & 1)) return;
    if (g_7fd6 & 2) return;
    save = fn_1f2d_0002(g_7fbc);
    page = fn_1e74_000f(6);
    x = f_2803_3625[ch];
    fn_0845_0008(0, 0, 0x42, 0x22, 1, 1, -1);
    fn_0a21_00ec(ch, 0, 1, g_3649);
    k = 0;
    fn_0845_00ac(0x21, 0x20, f_2803_362d[ch].mp, k, f_2803_362d[ch].maxMp, 5, 0x20, 0xa2, 1, 0);
    fn_0845_00ac(0x27, 0x20, f_2803_362d[ch].hp, k, f_2803_362d[ch].maxHp, 5, 0x20, 0x9a, 1, 1);
    fn_1f6c_0006(fn_0845_06f8(0x4253), 0x21, 1, 0xa0, 0);
    fn_1f6c_0006(fn_0845_06f8(0x4254), 0x27, 1, 0x98, 0);
    n = fn_0845_122b(&f_2803_362d[ch], g_81f2[g_7fd9]);
    if (f_2803_362d[ch].flags & 0x10) {
        fn_1fd6_000a(g_3649, fn_0845_04ec(f_2803_00a6[73]), 0x2c, 0, 0, 0);
        if (n < 4) fn_1b63_0004(0x2c, (n << 3) + 1, 0x16, 0x20 - (n << 3), 1);
    } else {
        fn_1fd6_000a(g_3649, fn_0845_04ec(fn_0a21_000b(ch)), 0x2c, 0, 0, 0);
        fn_1fd6_000a(g_3649, fn_0845_04ec(f_2803_00a6[72 + c->c41]), 0x2c, 0x11, 0, 0);
        if (!n) fn_1b63_0004(0x2c, 0x11, 0x16, 0xf, 1);
    }
    d = f_2803_362d[ch].flags & 0x314c;
    if ((d && (d != 4 || !f_2803_362d[ch].dmgDealt)) || g_4d66) fn_1b63_0004(0x2c, 0, 0x16, 0x22, 1);
    if (f_2803_362d[ch].dmgDealt) {
        fn_1fd6_000a(g_3649, fn_0845_04ec(f_2803_00a6[34]), 0x2c, 0, 0, 0);
        fn_0845_07b3("%d", 0x39, 7, 0xfe, 0, 1, f_2803_362d[ch].dmgDealt);
    }
    if (f_2803_362d[ch].lastDmg > 0) fn_0845_07b3("%d", 0x11, 0x1c, 0xfe, 0, 1, f_2803_362d[ch].lastDmg);
    if (!page) fn_1ebc_00e7();
    fn_1e54_0001(0, 0, 0x41, 0x21, g_7fe3 != ch || ovr_2d74_0025() == 1 ? 1 : 0xd4);
    fn_1dbc_0004(0, 0, x, 0x8f, 0x42, 0x22, g_3649, page);
    if (!page) fn_1ebc_00fe();
    fn_1f2d_0002(save);
    fn_1e74_000f(page);
}

void fn_0a21_05ce(void)
{
    register int i;
    register int n;

    n = ovr_2d74_0025();
    for (i = 0; i < n; i++) fn_0a21_022b(i);
}

void fn_0a21_05ef(int ch, char f)
{
    f_2803_362d[ch].face = f;
}

void fn_0a21_0608(int ch)
{
    switch (f_2803_362d[ch].face) {
    case 1:
    one:
        fn_0a21_0674(ch, 0, 0, 0);
        break;
    case 6:
        if (f_2803_362d[ch].faceDef != 5) goto one;
        f_2803_362d[ch].face = 5;
        break;
    default:
        f_2803_362d[ch].face = 0;
    }
}

void fn_0a21_0674(int ch, int f, int snd, int redraw)
{
    f_2803_362d[ch].faceDef = f;
    if (f && snd) fn_0bbc_0744(ch, 6, snd, 1);
    if (redraw) fn_0a21_022b(ch);
}

void fn_0a21_06b8(int f, int snd, int redraw)
{
    struct Char far *c;
    register int i;

    c = f_2803_362d;
    for (i = 0; i < 4; i++, c++)
        if (c->flags & 1) fn_0a21_0674(i, f, snd, 0);
    if (redraw) fn_0a21_05ce();
}

void fn_0a21_06fd(int ch, int magic, int val, int mode)
{
    struct Char far *c;
    void far *save;
    int page;
    int cur;
    long scale;
    int k;
    int step;
    int max;
    int end;
    register int old;
    register int nv;

    c = &f_2803_362d[ch];
    if (!(c->flags & 1)) return;
    if (magic) {
        old = c->mp;
        max = c->maxMp;
        k = 0;
    } else {
        old = c->hp;
        max = c->maxHp;
        k = 1;
    }
    switch (mode) {
    case 0: nv = val; break;
    case 1: nv = old + val; break;
    case 2: nv = max + val; break;
    }
    nv = nv < max ? nv : max;
    nv = nv > 0 ? nv : 0;
    if (magic)
        c->mp = nv;
    else {
        c->hp = nv;
        if (c->hp < 1) c->flags |= 8;
    }
    if (g_7fd6 & 2) return;
    save = fn_1f2d_0002(g_7fbc);
    page = fn_1e74_000f(0);
    fn_1ebc_00e7();
    scale = 0x2000L / max;
    max = scale * max >> 8;
    old = scale * old >> 8;
    end = nv = scale * nv >> 8;
    end = end < max ? end : max;
    end = end > 0 ? end : 0;
    nv += nv <= old ? -2 : 2;
    nv = nv < max ? nv : max;
    nv = nv > 0 ? nv : 0;
    if (nv != old) {
        step = nv < old ? -2 : 2;
        cur = old;
        while (cur != nv || nv != end) {
            if (ABS(cur - nv) < ABS(step)) step >>= 1;
            cur += step;
            g_3850 = 1;
            fn_0845_00ac(g_2256[k].x + f_2803_3625[ch], 0xaf, cur, 0, max, 5, 0x20, g_2256[k].color, 1, g_2256[k].flag);
            fn_1f6c_0006(fn_0845_06f8(g_2256[k].str), g_2256[k].x + f_2803_3625[ch], 0x90, g_2256[k].tcolor, 0);
            if (cur == nv) {
                nv = end;
                step = -step;
            }
            while (g_3850);
        }
    }
    fn_1ebc_00fe();
    fn_1f2d_0002(save);
    fn_1e74_000f(page);
}

int fn_0a21_0997(int ch, int type)
{
    int i;

    if (ch >= 0 && ch < 4 && (f_2803_362d[ch].flags & 1))
        for (i = 0; i < 11; i++)
            if (f_2803_362d[ch].items[i] && f_2803_1cfd[f_2803_362d[ch].items[i]].type == type) return 1;
    return 0;
}

void fn_0a21_0a0c(void)
{
    int n;
    int gap;
    int i;

    n = ovr_2d74_0025();
    if (f_2803_0000[0x45] && !g_81fe) {
        gap = 0x118 - n * 0x21;
        gap /= n + 1;
        for (i = 0; i < n; i++) f_2803_3625[i] = gap * (i + 1) + i * 0x21 + 10;
    } else {
        gap = 0xeb - n * 0x42;
        gap /= n + 1;
        for (i = 0; i < n; i++) f_2803_3625[i] = gap * (i + 1) + i * 0x42 + 0x53;
    }
}
