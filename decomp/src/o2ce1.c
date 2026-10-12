/* o2ce1: automap (level map screen, legend, level switching) */
#include <stdio.h>
#include <process.h>
#include "lol.h"

struct Btn { int x, y, w, h, act, dirty; };                 /* 12 bytes, g_06ec[3] */
struct Sym { char shape; char seen; char dy; int str; };    /* 5 bytes, g_0720[] (shape -1 ends) */
struct Legend { int x, y, str, x2, y2, shape; };            /* 12 bytes, *g_4afc[32] */

#define FL(b) ((char)g_8203[b].flags)
#define SHP(i) (((void far * far *)f_250c_0404)[i])

extern char g_7fe5;
extern int g_4aee, g_4af0, g_4af2;
extern int g_4aea, g_4aec;
extern void far *g_4d5a;
extern long g_3850;
extern int g_20f2;
extern int g_3649;
extern void far *g_4af4, far *g_4af8;
extern struct Legend far *g_4afc;
extern struct Legend far *g_4edc;
extern struct Btn g_06ec[];
extern struct Sym g_0720[];
extern void far *g_0710[];
extern char g_075c[];
extern char g_077d[], g_0787[], g_0791[], g_079d[], g_07a9[], g_07b5[], g_07b9[];
extern int g_2f0c, g_2f0e;
extern char g_2f45;
extern long g_369f;
extern unsigned long g_81f9;
extern int g_7fd0, g_7fdf;
extern char far f_2803_3835[];
extern int far f_24fd_0000[];
extern char far f_2501_0000[], far f_2502_0000[], far f_2503_0000[], far f_2504_0000[];
extern char far f_2505_0000[], far f_2506_0000[], far f_2507_0000[], far f_2508_0000[];
extern char far f_2509_0000[], far f_250a_0000[], far f_250b_0000[], far f_250c_0000[];
extern unsigned char far f_250c_0004[], far f_250c_0104[];
extern void far * far f_250c_0404[][4];

void fn_067a_0401(int snd, int x);
void fn_09aa_0007(int a, int b);
int fn_09aa_0183(int b, int dir);
void ovr_2d5f_0048(void);
void ovr_2d5f_004d(void);
void fn_2279_025b(void far *s, void far *d, unsigned long n);
void fn_231c_0048(int t);
void fn_231c_0008(int t);
void ovr_2d3c_0020(void);
void ovr_2d3c_0025(int lvl);
void ovr_2d2c_0061(int clear);
void ovr_2d2c_002f(void);
void ovr_2d2c_0066(void);
void ovr_2d2c_0075(int lvl, int mode);
void fn_0845_08d9(int n);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_1ebc_0111(int x1, int y1, int x2, int y2);
void fn_1ebc_01ec(void);
void fn_1dbc_0017(int a, int b, int c, int d, int e, int f, int g, int h);
void fn_1dbc_0004(int x1, int y1, int x2, int y2, int w, int h, int s, int d);
void fn_1ef2_0075(unsigned char far *pal, int delay, long a);
int fn_2169_060c(void);
int fn_2169_0790(void);
void fn_163d_0004(void);
long ovr_2ded_002f(char far *name, int page, int dpage, void far *pal);
long ovr_2ded_0020(char far *name, void far *buf, long n);
char far *fn_0845_06f8(int id);
void fn_0845_07b3(char far *s, int x, int y, int c1, int c2, int a);
void fn_19c9_0ff6(int sp, int sx, int sy, int dp, int dx, int dy, int w, int h, int fl, void far *tab);
void fn_19c9_1100(int page, int a, int b, int c, int x, int y, int w, int h, int d, int e, void far *f);
int fn_19c9_12a2(unsigned char far *c, unsigned char far *pal, int n, int z);
void fn_1fd6_000a(int page, void far *p, int x, int y, int a, int flags, ...);
int fn_1e74_000f(int page);
void far *fn_1f2d_0002(void far *font);
void fn_1f6c_0006(char far *s, int x, int y, int c1, int c2);
void far *fn_215f_0003(int page);
void far *fn_1f36_0064(void far *p, int idx);
void fn_1e59_001d(int x1, int y1, int x2, int y2, int c);
void far *fn_0845_04ec(void far *name);
void fn_0845_0631(void far *p);
void fn_2309_000c(void);
int fn_1809_0000(char far *name, int mode);
void fn_1809_058d(int h);
long fn_1809_084d(int h, void far *buf, unsigned long n);

void ovr_2ce1_0020(void);
void ovr_2ce1_0025(int page);
void ovr_2ce1_002a(int page, char far *title);
void ovr_2ce1_002f(void);
void ovr_2ce1_0034(void);
void ovr_2ce1_0039(void);
void ovr_2ce1_003e(void);
void ovr_2ce1_0043(unsigned char far *src, unsigned char far *dst, unsigned mul, char r, char g, char b, int n, int z);
int ovr_2ce1_0048(unsigned char far *a, unsigned char far *b);
void ovr_2ce1_004d(void);
void ovr_2ce1_0052(void);
void ovr_2ce1_0057(int page, int a, unsigned char far *shp, int b, int c);
int ovr_2ce1_005c(int lvl);
void ovr_2ce1_0061(void);
void ovr_2ce1_0066(int id, int x, int y);
int ovr_2ce1_006b(void);
int ovr_2ce1_0070(void);
void ovr_2ce1_0075(void);
void ovr_2ce1_007a(void);
void ovr_2ce1_007f(char far *msg);
void ovr_2ce1_0084(int lvl);
void ovr_2ce1_0089(int w);
void ovr_2ce1_008e(int w, int x, int y, int d);

void ovr_2ce1_0020(void)
{
    int k;
    int i;

    fn_067a_0401(0x69, 1);
    fn_09aa_0007(0x4e, 1);
    g_4aee = g_7fe5;
    ovr_2d5f_0048();
    fn_2279_025b(f_2803_3835, g_4d5a, 0x50L);
    ovr_2ce1_004d();
    fn_231c_0048(2);
    ovr_2d3c_0020();
    ovr_2d2c_0061(1);
    ovr_2d2c_002f();
    g_4af2 = 0;
    g_4af0 = 0;
    ovr_2d3c_0025(g_4aee);
    ovr_2ce1_0084(g_4aee);
    fn_0845_08d9(10);
    ovr_2ce1_0025(2);
    fn_1ebc_00e7();
    fn_1dbc_0017(0, 0, 0, 0, 0x28, 0xc8, 2, 0);
    fn_1ebc_00fe();
    fn_1ef2_0075(f_250c_0104, 10, 0L);
    g_3850 = 8;
    while (g_4af2 != 1) {
        if (g_4af0 == 1) {
            ovr_2ce1_0025(2);
            fn_1ebc_00e7();
            fn_1dbc_0017(0, 0, 0, 0, 0x28, 0xc8, 2, 0);
            fn_1ebc_00fe();
            g_4af0 = 0;
        }
        if (g_3850 == 0) {
            ovr_2ce1_007a();
            g_3850 = 8;
        }
        ovr_2ce1_0034();
        if (fn_2169_060c()) {
            k = fn_2169_0790();
            fn_163d_0004();
        } else {
            k = 0;
        }
        switch (k) {
        case 0x30:
            if (g_20f2) {
                for (i = 0; i < 0x400; i++) g_8203[i].flags |= 7;
                g_4af0 = 1;
            }
            break;
        case 0x6e:
            g_4af2 = 1;
            break;
        }
    }
    fn_0845_08d9(10);
    ovr_2d2c_0075(g_7fe5, 0);
    fn_2279_025b(g_4d5a, f_2803_3835, 0x50L);
    ovr_2d3c_0025(g_7fe5);
    ovr_2d2c_0066();
    fn_163d_0004();
    ovr_2ce1_0052();
    ovr_2d5f_004d();
    fn_231c_0008(2);
}

void ovr_2ce1_0025(int page)
{
    register int pg = page;
    register int k;

    for (k = 0; k < 2; k++) {
        ovr_2ded_002f(g_077d, pg, pg, f_250c_0104);
        ovr_2ce1_002a(pg, fn_0845_06f8(f_24fd_0000[g_4aee]));
        ovr_2ce1_0061();
    }
    ovr_2ce1_002f();
}

static void deco(int blk, int w, int x, int y, int d)
{
    register int sx = x;
    register int sy = y;

    if (FL(blk) & (1 << d)) return;
    if ((f_2803_3835[w] & 0x1f) != 0xd) return;
    fn_19c9_0ff6(g_3649, sx + f_2501_0000[d], sy + f_2502_0000[d], g_3649, sx + f_2501_0000[d], sy + f_2502_0000[d],
                 f_2503_0000[d], f_2504_0000[d], 0, f_250c_0004);
    fn_19c9_0ff6(g_3649, sx + f_2505_0000[d], sy + f_2506_0000[d], g_3649, sx + f_2505_0000[d], sy + f_2506_0000[d],
                 f_2509_0000[d], f_250a_0000[d], 0, f_250c_0004);
    fn_19c9_0ff6(g_3649, sx + f_2507_0000[d], sy + f_2508_0000[d], g_3649, sx + f_2507_0000[d], sy + f_2508_0000[d],
                 f_2509_0000[d], f_250a_0000[d], 0, f_250c_0004);
}

void ovr_2ce1_008e(int b, int x, int y, int d)
{
    int w;

    w = f_2803_3835[b] & 0x1f;
    if (w != 0x1f) {
        fn_1fd6_000a(g_3649, (&f_250c_0404[0][0])[w * 4 + d], x + f_250b_0000[d] - 2, y + f_250c_0000[d] - 2, 0, 0);
        ovr_2ce1_0089(w);
    }
}

void ovr_2ce1_002a(int page, char far *title)
{
    int x0;
    int y0;
    int b;
    char wn;
    char ws;
    char we;
    char ww;
    int n0;
    int n2;
    int n1;
    int n3;
    void far *font;
    int pg;
    register int x;
    register int y;

    pg = fn_1e74_000f(page);
    font = fn_1f2d_0002(g_4af4);
    fn_1f6c_0006(title, 0xec, 8, 1, 0);
    x0 = ovr_2ce1_006b();
    y0 = ovr_2ce1_0070();
    x = g_4aec;
    y = g_4aea;
    for (b = y0 * 32 + x0; b < 0x400; b++) {
        if ((FL(b) & 7) == 7 && !(f_2803_3835[WALL(b, 0)] & 0xc0) && !(f_2803_3835[WALL(b, 2)] & 0xc0) &&
            !(f_2803_3835[WALL(b, 1)] & 0xc0) && !(f_2803_3835[WALL(b, 3)] & 0xc0)) {
            n0 = fn_09aa_0183(b, 0);
            n2 = fn_09aa_0183(b, 2);
            n1 = fn_09aa_0183(b, 1);
            n3 = fn_09aa_0183(b, 3);
            wn = WALL(n0, 2);
            ws = WALL(n2, 0);
            we = WALL(n1, 3);
            ww = WALL(n3, 1);
            fn_19c9_0ff6(g_3649, x, y, g_3649, x, y, 7, 6, 0, f_250c_0004);
            deco(n3, ww, x, y, 3);
            ovr_2ce1_008e(ww, x, y, 3);
            if (f_2803_3835[ww] & 0xc0) fn_19c9_0ff6(g_3649, x, y, g_3649, x, y, 1, 6, 0, f_250c_0004);
            deco(n1, we, x, y, 1);
            ovr_2ce1_008e(we, x, y, 1);
            if (f_2803_3835[we] & 0xc0) fn_19c9_0ff6(g_3649, x + 6, y, g_3649, x + 6, y, 1, 6, 0, f_250c_0004);
            deco(n0, wn, x, y, 0);
            ovr_2ce1_008e(wn, x, y, 0);
            if (f_2803_3835[wn] & 0xc0) fn_19c9_0ff6(g_3649, x, y, g_3649, x, y, 7, 1, 0, f_250c_0004);
            deco(n2, ws, x, y, 2);
            ovr_2ce1_008e(ws, x, y, 2);
            if (f_2803_3835[ws] & 0xc0) fn_19c9_0ff6(g_3649, x, y + 5, g_3649, x, y + 5, 7, 1, 0, f_250c_0004);
        }
        x += 7;
        if (b % 32 == 31) {
            x = g_4aec;
            y += 6;
            b += x0;
        }
    }
    fn_1e74_000f(pg);
    fn_1f2d_0002(font);
    g_06ec[0].dirty = 1;
    g_06ec[1].dirty = 1;
    g_06ec[2].dirty = 1;
}

void ovr_2ce1_002f(void)
{
    int pg;

    pg = fn_1e74_000f(2);
    fn_0845_07b3(fn_0845_06f8(0x4033), 0x127, 0xb6, 0xac, 0, 5);
    fn_1e74_000f(pg);
}

void ovr_2ce1_0034(void)
{
    int mx;
    int my;
    register int i;

    mx = g_2f0c;
    my = g_2f0e;
    if (g_2f45 == 1) {
        for (i = 0; i < 3 && (g_06ec[i].x > mx || g_06ec[i].y > my || g_06ec[i].w + g_06ec[i].x < mx ||
                              g_06ec[i].h + g_06ec[i].y < my); i++)
            g_06ec[i].act = 0;
        switch (i) {
        case 0:
            g_06ec[i].act = 1;
            g_06ec[i].dirty = 1;
            ovr_2ce1_002f();
            while (g_2f45 != 0) ;
            ovr_2ce1_0039();
            g_06ec[i].act = 0;
            g_06ec[i].dirty = 1;
            ovr_2ce1_002f();
            break;
        case 1:
            g_06ec[i].act = 1;
            g_06ec[i].dirty = 1;
            ovr_2ce1_002f();
            while (g_2f45 != 0) ;
            ovr_2ce1_003e();
            g_06ec[i].act = 0;
            g_06ec[i].dirty = 1;
            ovr_2ce1_002f();
            break;
        case 2:
            g_06ec[i].act = 1;
            g_06ec[i].dirty = 1;
            ovr_2ce1_002f();
            while (g_2f45 != 0) ;
            g_4af2 = 1;
            g_06ec[i].act = 0;
            g_06ec[i].dirty = 1;
            ovr_2ce1_002f();
            break;
        }
    }
}

void ovr_2ce1_0039(void)
{
    register int l;
    int i;

    for (l = g_4aee + 1; ovr_2ce1_005c(l) != 1; l = (l + 1) & 0x1f) ;
    if (l < 0x20 && g_4aee != l) {
        for (i = 0; g_0720[i].shape != -1; i++) g_0720[i].seen = 0;
        g_4aee = l;
        ovr_2d2c_0075(g_4aee, 0);
        ovr_2d3c_0025(g_4aee);
        ovr_2ce1_0084(g_4aee);
        g_4af0 = 1;
    }
}

void ovr_2ce1_003e(void)
{
    register int l;
    int i;

    for (l = g_4aee - 1; ovr_2ce1_005c(l) != 1; l = (l - 1) & 0x1f) ;
    if (l >= 0 && g_4aee != l) {
        for (i = 0; g_0720[i].shape != -1; i++) g_0720[i].seen = 0;
        g_4aee = l;
        ovr_2d2c_0075(g_4aee, 0);
        ovr_2d3c_0025(g_4aee);
        ovr_2ce1_0084(g_4aee);
        g_4af0 = 1;
    }
}

void ovr_2ce1_0043(unsigned char far *src, unsigned char far *dst, unsigned mul, char r, char g, char b, int n, int z)
{
    int i;
    int c;
    unsigned char far *p;
    unsigned char buf[0x300];
    register int k;
    register int cnt = n;
    int j;
    unsigned v;

    k = 0;
    for (j = 0; j < cnt; j++) {
        v = src[k] * mul / 64L + r;
        if (v > 63) v = 63;
        buf[k] = v;
        k++;
        v = src[k] * mul / 64L + g;
        if (v > 63) v = 63;
        buf[k] = v;
        k++;
        v = src[k] * mul / 64L + b;
        if (v > 63) v = 63;
        buf[k] = v;
        k++;
    }
    k = 0;
    for (i = 0; i < cnt; i++) {
        p = buf + k;
        c = fn_19c9_12a2(p, src, cnt, z);
        dst[i] = c;
        k += 3;
    }
}

int ovr_2ce1_0048(unsigned char far *a, unsigned char far *b)
{
    volatile int d;
    int dr;
    register int dg;
    int db;

    dr = a[0] - b[0];
    dg = a[1] - b[1];
    db = a[2] - b[2];
    dr *= dr;
    dg *= dg;
    db *= db;
    d = dr + dg + db;
}

void ovr_2ce1_004d(void)
{
    register unsigned n;

    ovr_2ded_002f(g_0787, 2, 2, f_250c_0104);
    n = ovr_2ded_002f(g_0791, 3, 5, 0);
    g_4af8 = (char far *)fn_215f_0003(5) + n;
    n += ovr_2ded_0020(g_079d, g_4af8, g_369f - n);
    g_4af4 = (char far *)fn_215f_0003(5) + n;
    ovr_2ded_0020(g_07a9, g_4af4, g_369f - n);
    g_06ec[0].x = 0xfc;
    g_06ec[0].y = 0xaf;
    g_06ec[0].w = 0x15;
    g_06ec[0].h = 0x19;
    g_06ec[1].x = 0xe7;
    g_06ec[1].y = 0xaf;
    g_06ec[1].w = 0x15;
    g_06ec[1].h = 0x19;
    g_06ec[2].x = 0x113;
    g_06ec[2].y = 0xaf;
    g_06ec[2].w = 0x28;
    g_06ec[2].h = 0x16;
    for (n = 0; n < 0x6d; n++) SHP(n) = fn_1f36_0064(fn_215f_0003(5), n + 0xb);
    g_0710[0] = SHP(0x30);
    g_0710[1] = SHP(0x31);
    g_0710[2] = SHP(0x32);
    g_0710[3] = SHP(0x33);
    ovr_2ce1_0043(f_250c_0104, f_250c_0004, 0x34, 0, 0, 0, 0x100, 0);
    for (n = 0; g_0720[n].shape != -1; n++) g_0720[n].seen = 0;
}

void ovr_2ce1_0052(void)
{
}

void ovr_2ce1_0057(int page, int a, unsigned char far *shp, int b, int c)
{
    int pg;
    register int p = page;

    pg = fn_1e74_000f(p);
    fn_1e59_001d(0, 0, shp[2], *(int far *)(shp + 3), 0);
    fn_1fd6_000a(g_3649, shp, 0, 0, 0, 0);
    fn_19c9_1100(p, 0, 0, a, b, c, shp[2], *(int far *)(shp + 3), 0, 0, f_250c_0004);
    fn_1e74_000f(pg);
}

int ovr_2ce1_005c(int lvl)
{
    return (g_81f9 & (1L << (lvl - 1))) ? 1 : 0;
}

void ovr_2ce1_0061(void)
{
    int x0;
    int y0;
    struct Legend far *list;
    int pg;
    void far *font;
    int row;
    register int i;

    row = 0;
    x0 = ovr_2ce1_006b();
    y0 = ovr_2ce1_0070();
    font = fn_1f2d_0002(g_4af8);
    list = g_4afc;
    if (list != 0) {
        for (i = 0; list[i].x != -1 && i < 0x20; i++) {
            if ((FL(list[i].x + (list[i].y << 5)) & 7) == 7 && list[i].str != -1) {
                ovr_2ce1_0066(list[i].str, 0xf4, row * 8 + 0x16);
                if (list[i].shape != -1) {
                    g_8203[list[i].x2 + (list[i].y2 << 5)].flags |= 7;
                    fn_1fd6_000a(2, f_250c_0404[list[i].shape][0], (list[i].x2 - x0) * 7 + g_4aec - 3,
                                 (list[i].y2 - y0) * 6 + g_4aea - 3, 0, 0);
                    fn_1fd6_000a(2, f_250c_0404[list[i].shape][0], 0xe7, row * 8 + 0x13, 0, 0);
                }
                row++;
            }
        }
    }
    pg = fn_1e74_000f(2);
    for (i = 0; g_0720[i].shape != -1; i++) {
        if (g_0720[i].seen == 1) {
            fn_19c9_0ff6(g_3649, 0xeb, row * 8 + 0x15, g_3649, 0xeb, row * 8 + 0x15, 7, 6, 0, f_250c_0004);
            fn_1fd6_000a(g_3649, f_250c_0404[g_0720[i].shape][0], 0xe8, row * 8 + g_0720[i].dy + 0x12, 0, 0);
            ovr_2ce1_0066(g_0720[i].str, 0xf4, row * 8 + 0x16);
            row++;
        }
    }
    fn_1e74_000f(pg);
    fn_1f2d_0002(font);
}

void ovr_2ce1_0066(int id, int x, int y)
{
    int pg;

    pg = fn_1e74_000f(2);
    fn_1f6c_0006(fn_0845_06f8(id), x, y, 0xef, 0);
    fn_1e74_000f(pg);
}

int ovr_2ce1_006b(void)
{
    int x0;
    int y;
    int x1;

    x0 = 0;
    y = 32;
    while (x0 < 32 && y == 32) {
        for (y = 0; y < 32 && g_8203[(y << 5) + x0].flags == 0; y++) ;
        if (y == 32) x0++;
    }
    x1 = 31;
    y = 32;
    while (x1 > 0 && y == 32) {
        for (y = 0; y < 32 && g_8203[(y << 5) + x1].flags == 0; y++) ;
        if (y == 32) x1--;
    }
    if (x1 <= x0) {
        g_4aec = 5;
        return 0;
    }
    g_4aec = ((32 - (x1 - x0)) >> 1) * 7 + 5;
    return x0;
}

int ovr_2ce1_0070(void)
{
    int y0;
    int x;
    int y1;

    y0 = 0;
    x = 32;
    while (y0 < 32 && x == 32) {
        for (x = 0; x < 32 && g_8203[(y0 << 5) + x].flags == 0; x++) ;
        if (x == 32) y0++;
    }
    y1 = 31;
    x = 32;
    while (y1 > 0 && x == 32) {
        for (x = 0; x < 32 && g_8203[(y1 << 5) + x].flags == 0; x++) ;
        if (x == 32) y1--;
    }
    if (y1 <= y0) {
        g_4aea = 4;
        return 0;
    }
    g_4aea = ((32 - (y1 - y0)) >> 1) * 6 + 4;
    return y0;
}

void ovr_2ce1_0075(void)
{
}

void ovr_2ce1_007a(void)
{
    void far *shp;
    int pg;
    register int x0;
    register int y0;

    x0 = ovr_2ce1_006b();
    y0 = ovr_2ce1_0070();
    if (g_7fe5 == g_4aee) {
        shp = fn_0845_04ec(g_0710[g_7fdf]);
        pg = fn_1e74_000f(2);
        fn_1e59_001d(0, 0, 0x10, 0x10, 0);
        fn_1fd6_000a(2, shp, 0, 0, 0, 0);
        fn_0845_0631(shp);
        fn_1ebc_0111(g_4aec + (g_7fd0 - x0) % 32 * 7, g_4aea + (g_7fd0 - (y0 << 5)) / 32 * 6,
                     g_4aec + (g_7fd0 - x0) % 32 * 7 + 0x10, g_4aea + (g_7fd0 - (y0 << 5)) / 32 * 6 + 0x10);
        fn_1dbc_0004(g_4aec + (g_7fd0 - x0) % 32 * 7, g_4aea + (g_7fd0 - (y0 << 5)) / 32 * 6,
                     g_4aec + (g_7fd0 - x0) % 32 * 7, g_4aea + (g_7fd0 - (y0 << 5)) / 32 * 6, 0x10, 0x10, 2, 0);
        fn_19c9_0ff6(2, 0, 0, 0, g_4aec + (g_7fd0 - x0) % 32 * 7 - 3, g_4aea + (g_7fd0 - (y0 << 5)) / 32 * 6 - 2,
                     0x10, 0x10, 0, g_075c);
        fn_1ebc_01ec();
        fn_1e74_000f(pg);
        for (x0 = 1; x0 < 0x18; x0++) {
            if (x0 == 1) g_075c[0x18] = g_075c[x0];
            g_075c[x0] = g_075c[x0 + 1];
        }
    }
}

void ovr_2ce1_007f(char far *msg)
{
    fn_2309_000c();
    printf(g_07b5, msg);
    exit(0);
}

void ovr_2ce1_0084(int lvl)
{
    int h;
    int v0;
    int v1;
    int v2;
    int v3;
    int v4;
    int v5;
    char name[18];
    register int i;
    register int ok;

    g_4afc = g_4edc;
    for (i = 0; i < 32; i++) {
        g_4afc[i].x = -1;
        g_4afc[i].shape = -1;
    }
    i = 0;
    sprintf(name, g_07b9, lvl);
    h = fn_1809_0000(name, 1);
    if (h == -1) return;
    for (; i < 32; i++) {
        ok = fn_1809_084d(h, &v0, 2L) == 2;
        ok &= fn_1809_084d(h, &v1, 2L) == 2;
        ok &= fn_1809_084d(h, &v2, 2L) == 2;
        ok &= fn_1809_084d(h, &v3, 2L) == 2;
        ok &= fn_1809_084d(h, &v4, 2L) == 2;
        ok &= fn_1809_084d(h, &v5, 2L) == 2;
        if (!ok) break;
        g_4afc[i].x2 = v0;
        g_4afc[i].y2 = v1;
        g_4afc[i].shape = v2;
        g_4afc[i].x = v3;
        g_4afc[i].y = v4;
        g_4afc[i].str = v5;
    }
    fn_1809_058d(h);
}

void ovr_2ce1_0089(int w)
{
    int c;
    int i;

    for (c = w, i = 0, c &= 0x7f; g_0720[i].shape != -1; i++) {
        if (g_0720[i].shape == c) {
            g_0720[i].seen = 1;
            break;
        }
    }
}
