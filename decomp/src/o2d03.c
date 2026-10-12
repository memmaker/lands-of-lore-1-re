/* o2d03: lightning spell (bolt animation over the view) */
#include "lol.h"

struct Shp { int w0; unsigned char h; unsigned w; };
struct Bolt { int on; int x; int y; int len; int pos; int speed; int state; int frame; };
extern int g_08ba;
extern char g_08ce[];
extern char g_08db[];
extern char g_0907[];
extern void far *g_088e[];
extern char g_08ae[];
extern char g_08b4[];
extern int g_08be[];
extern int g_08c6[];
extern int g_4b92;
extern int g_4b02;
extern int g_4b04;
extern struct Bolt far *g_4b06[];
extern int g_7fd0, g_7fdf;
extern char g_531e[];
extern int g_2144;
extern void far *g_4d56;
extern void far *g_4d5a;
extern unsigned long g_384c;
extern void far *g_4bec;
extern void far *g_4bf0;
extern int g_3649;
long ovr_2ded_002f(char far *name, int page, int dpage, void far *pal);
void far *ovr_2d46_0025(int a, int b, int c);
void fn_203b_0203(void far *p);
void far *fn_203b_0007(long size, int flags);
int fn_07bc_012d(int type, int flags, int flags2);
void fn_07bc_044c(int h);
void fn_0845_1343(int b, unsigned mask, int c, int d, int e, int f);
int fn_09aa_0183(int a, int b);
int fn_070c_06a3(int who, int m, int x, int y, int z);
void fn_070c_07f5(int m, int r, int who, int a, int y);
void ovr_2ce1_007f(char far *msg);
void fn_067a_0401(int a, int b);
int fn_1e74_000f(int page);
void far *fn_215f_0003(int page);
void far *fn_215f_001d(int page);
void far fn_2279_025b(void far *src, void far *dst, long n);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_1ebc_01ec(void);
void fn_19c9_0c8e(int a, int b);
int fn_19c9_123f(int a);
int fn_19c9_121b(int a);
void fn_0845_08aa(void);
void fn_067a_02c7(void);
struct Shp far *fn_0845_04ec(void far *name);
void fn_0845_0631(void far *p);
void far fn_1fd6_000a(int page, void far *data, int x, int y, int frame, int flags, ...);

int ovr_2d03_0020(void);
void ovr_2d03_0025(void);
void ovr_2d03_002a(int x, int type);
void ovr_2d03_002f(int x, int y, int n, int state, int frame, int pos, int len);

int ovr_2d03_0020(void)
{
    register int i;
    if (g_08ba != 1) {
        ovr_2ded_002f(g_08ce, 3, 3, 0);
        for (i = 0; i < 8; i++)
            g_088e[i] = ovr_2d46_0025(3, i, g_4b92);
        g_08ba = 1;
    }
    return 1;
}

void ovr_2d03_0025(void)
{
    register int i;
    if (g_08ba == 1) {
        for (i = 0; i < 8; i++) {
            if (g_088e[i]) {
                fn_203b_0203(g_088e[i]);
                g_088e[i] = 0;
            }
        }
        g_08ba = 0;
    }
}

void ovr_2d03_002a(int x, int type)
{
    int cnt;
    int m;
    int blk;
    int loaded;
    int n;
    unsigned long t;
    int pal;
    int pg1;
    int pg2;
    int tmp;
    int h;
    struct Monster far *p;
    register int i;
    register int pw;
    int r;

    pg1 = 4;
    pg2 = 2;
    switch (type) {
    case 0: n = 4; pw = 1; break;
    case 1: n = 5; pw = 1; break;
    case 2: n = 6; pw = 1; break;
    case 3: n = 5; pw = 0; break;
    }
    blk = g_7fd0;
    h = fn_07bc_012d(9, 0, 0);
    for (i = 0; i < 3; i++) {
        fn_0845_1343(blk, 0x200, -1, h, 0, 0);
        m = g_8203[blk].mon;
        if ((m & 0x8000) || (g_531e[((char *)&g_8203[blk])[g_7fdf ^ 2]] & 7)) {
            while (m & 0x8000) {
                r = g_08c6[type];
                r = fn_070c_06a3(x, m, r, 4, 1);
                p = &f_2803_15fa[m & 0x7fff];
                m = p->next;
                g_2144 = 1;
                fn_070c_07f5(0x8000 | p->id, r, x, 2, 4);
                g_2144 = 0;
            }
            break;
        }
        blk = fn_09aa_0183(blk, g_7fdf);
    }
    fn_07bc_044c(h);
    pw += i;
    if (pw > 3) pw = 3;
    g_4b04 = 0 - (pw << 4);
    g_4b02 = 0 - (pw << 4);
    loaded = 0;
    if (g_08ba != 1) {
        if (!ovr_2d03_0020()) ovr_2ce1_007f(g_08db);
        loaded = 1;
    }
    fn_067a_0401(0x45, 0);
    pal = fn_1e74_000f(pg2);
    fn_2279_025b(fn_215f_0003(5), g_4d56, 0xfa00L);
    fn_1ebc_00e7();
    fn_2279_025b(fn_215f_001d(0), g_4d5a, 0xfa00L);
    fn_1ebc_00fe();
    for (i = 0; i < 3; i++) g_4b06[i] = 0;
    cnt = 1;
    if (n - 3 > 0) cnt = n - 3;
    for (i = 0; i < cnt; i++) {
        if ((g_4b06[i] = fn_203b_0007(16L, 0)) == 0) ovr_2ce1_007f(g_0907);
        g_4b06[i]->x = 200;
        g_4b06[i]->y = 0x3c;
        g_4b06[i]->on = 1;
        g_4b06[i]->len = i * 50 % 255 + 200;
        g_4b06[i]->pos = 1000;
        g_4b06[i]->speed = 10;
        g_4b06[i]->state = 2;
        g_4b06[i]->frame = 0;
    }
    fn_2279_025b(g_4d5a, fn_215f_001d(pg2), 0xfa00L);
    while (cnt != 0) {
        fn_1e74_000f(pg2);
        t = g_384c;
        for (i = 0; i < n && i < 3; i++) {
            if (g_4b06[i]->on != 1) continue;
            ovr_2d03_002f(g_4b06[i]->x, g_4b06[i]->y, n, g_4b06[i]->state, g_4b06[i]->frame, g_4b06[i]->pos, g_4b06[i]->len);
            if (g_4b06[i]->state != 1) {
                if (g_4b06[i]->speed < 40) g_4b06[i]->speed += 2;
                else g_4b06[i]->speed = 40;
                if (g_4b06[i]->pos < g_4b06[i]->speed) {
                    if (i >= 1) {
                        g_4b06[i]->on = 0;
                        cnt--;
                    } else {
                        g_4b06[i]->pos = 0;
                        g_4b06[i]->speed = 0;
                        g_4b06[i]->state = 1;
                        g_4b06[i]->frame = 0;
                    }
                    fn_067a_0401(g_08be[pw], 0);
                } else g_4b06[i]->pos -= g_4b06[i]->speed;
            } else {
                g_4b06[i]->frame++;
                if (g_4b06[i]->frame >= 6) {
                    g_4b06[i]->on = 0;
                    cnt--;
                }
            }
        }
        while (g_384c - t < 1) ;
        fn_1ebc_00e7();
        fn_19c9_0c8e(pg2, pg1);
        tmp = pg2;
        pg2 = pg1;
        pg1 = tmp;
        fn_2279_025b(g_4d5a, fn_215f_001d(pg2), 0xfa00L);
        fn_1ebc_00fe();
    }
    for (i = 0; i < 3; i++) {
        if (g_4b06[i]) {
            fn_203b_0203(g_4b06[i]);
            g_4b06[i] = 0;
        }
    }
    fn_1ebc_00e7();
    fn_2279_025b(g_4d5a, fn_215f_0003(0), 0xfa00L);
    fn_1ebc_00fe();
    fn_2279_025b(g_4d56, fn_215f_0003(5), 0xfa00L);
    fn_1e74_000f(pal);
    fn_0845_08aa();
    fn_1ebc_01ec();
    fn_067a_02c7();
    fn_0845_1343(blk, 0x20, x, 3, 0, 0);
    if (loaded == 1) ovr_2d03_0025();
}

void ovr_2d03_002f(int x, int y, int n, int state, int frame, int pos, int len)
{
    struct Shp far *p;
    register int fr = frame;
    register int ps = pos;

    if (state == 1) {
        if (g_08b4[fr] != -1 && fr < 6) {
            p = fn_0845_04ec(g_088e[g_08b4[fr]]);
            fn_1fd6_000a(g_3649, p,
                x + (int)((unsigned long)ps * fn_19c9_121b(len) >> 16) - (ps / 8 + (p->w + g_4b04)) / 2,
                y + (int)((unsigned long)ps * fn_19c9_123f(len) >> 16) - (p->h + g_4b02 + ps / 8) / 2,
                0, 0x1004, g_4bec, g_4bf0,
                (ps / 8 + (p->w + g_4b04) << 8) / p->w,
                ((p->h + g_4b02 + ps / 8) << 8) / p->h);
            fn_0845_0631(p);
        }
        if (g_08ae[fr] != -1 && fr < 6) {
            p = fn_0845_04ec(g_088e[g_08ae[fr]]);
            fn_1fd6_000a(g_3649, p,
                x + (int)((unsigned long)ps * fn_19c9_121b(len) >> 16) - (ps / 8 + (p->w + g_4b04)) / 2,
                y + (int)((unsigned long)ps * fn_19c9_123f(len) >> 16) - (p->h + g_4b02 + ps / 8) / 2,
                0, 4,
                (ps / 8 + (p->w + g_4b04) << 8) / p->w,
                ((p->h + g_4b02 + ps / 8) << 8) / p->h);
            fn_0845_0631(p);
        }
    } else {
        p = fn_0845_04ec(g_088e[0]);
        fn_1fd6_000a(g_3649, p,
            x + (int)((unsigned long)ps * fn_19c9_121b(len) >> 16) - (ps / 8 + (p->w + g_4b04)) / 2,
            y + (int)((unsigned long)ps * fn_19c9_123f(len) >> 16) - (p->h + g_4b02 + ps / 8) / 2,
            0, 0x1004, g_4bec, g_4bf0,
            (ps / 8 + (p->w + g_4b04) << 8) / p->w,
            ((p->h + g_4b02 + ps / 8) << 8) / p->h);
        fn_0845_0631(p);
    }
}
