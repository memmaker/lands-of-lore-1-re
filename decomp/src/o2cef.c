/* o2cef: character healing animation (ovr_2cef_0034: WSA over a portrait while the HP bar fills) and WSA header
   accessors */
#include "lol.h"

struct Wsa { char pad[8]; int w; int h; char pad0c[0x1b]; long size; };
struct AnimRange { int first, last, w4; };   /* 6 bytes, f_25fb_0000[] */

extern int g_07c6;
extern char g_07c8[], g_07ef[], g_07f9[];
extern void far *g_4d56, far *g_369f, far *g_4bec, far *g_4bf0;
extern long g_3850;
extern int far f_2803_3625[];
extern struct AnimRange far f_25fb_0000[];
void ovr_2ce1_007f(char far *msg);
int fn_1e74_000f(int n);
void fn_067a_0401(int snd, int x);
void far *fn_215f_0003(int page);
void fn_2279_025b(void far *d, void far *s, long n);
void far *ovr_2dfd_0020(char far *name, void far *a, void far *b, int c, long d);
void ovr_2dfd_0025(void far *p);
int ovr_2dfd_002a(void far *w, int f, int x, int y, int a, int b, ...);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_1ebc_01ec(void);
void fn_1ebc_0111(int x1, int y1, int x2, int y2);
void fn_1dbc_0004(int x1, int y1, int x2, int y2, int w, int h, int s, int d);
void fn_070c_0a8f(int c, int n, int f);
void fn_0a21_022b(int c);
void fn_0bbc_0365(struct Char far *c, int a, int b);
int ovr_2cef_0020(struct Wsa far *p);
int ovr_2cef_0025(struct Wsa far *p);

int ovr_2cef_002a(void)
{
    if (g_07c6 != 1) g_07c6 = 1;
    return 1;
}

void ovr_2cef_002f(void)
{
    if (g_07c6 == 1) g_07c6 = 0;
}

void ovr_2cef_0034(int a, int c)
{
    int old;
    int opened;
    int done;
    void far *shp;
    int frame;
    int w;
    int h;
    int delta;
    int acc;
    register int x, y;

    opened = 0;
    if (g_07c6 != 1) {
        if (!ovr_2cef_002a()) ovr_2ce1_007f(g_07c8);
        opened = 1;
    }
    old = fn_1e74_000f(2);
    fn_067a_0401(0x49, 0);
    fn_2279_025b(fn_215f_0003(5), g_4d56, 0xfa00L);
    if ((shp = ovr_2dfd_0020(g_07ef, fn_215f_0003(5), g_369f, 0, 0L)) == 0) ovr_2ce1_007f(g_07f9);
    x = f_2803_3625[c] - 11;
    y = 0x7c;
    w = ovr_2cef_0020(shp);
    h = ovr_2cef_0025(shp);
    fn_1ebc_00e7();
    fn_1dbc_0004(x, y, 0, 0, w, h, 0, 2);
    fn_1ebc_00fe();
    done = 0;
    frame = f_25fb_0000[a].first;
    delta = f_2803_362d[c].maxHp - f_2803_362d[c].hp;
    acc = 0;
    while (!done) {
        acc &= 0xff;
        acc += (delta << 8) / f_25fb_0000[a].last;
        fn_070c_0a8f(c, acc / 256, 1);
        fn_0a21_022b(c);
        g_3850 = 4;
        fn_1dbc_0004(0, 0, x, y, w, h, 2, 2);
        ovr_2dfd_002a(shp, frame, x, y, 2, 0x5000, g_4bec, g_4bf0);
        fn_1ebc_0111(x, y, x + w, y + h);
        fn_1dbc_0004(x, y, x, y, w, h, 2, 0);
        fn_1ebc_01ec();
        while (g_3850 != 0) ;
        if (f_25fb_0000[a].last < ++frame) done = 1;
    }
    f_2803_362d[c].hp = f_2803_362d[c].maxHp;
    fn_1dbc_0004(0, 0, x, y, w, h, 2, 2);
    fn_0bbc_0365(&f_2803_362d[c], 4, 4);
    fn_0a21_022b(c);
    fn_1dbc_0004(x, y, x, y, w, h, 2, 0);
    ovr_2dfd_0025(shp);
    fn_2279_025b(g_4d56, fn_215f_0003(5), 0xfa00L);
    if (opened == 1) ovr_2cef_002f();
    fn_1e74_000f(old);
}

int ovr_2cef_0039(struct EmcState far *s)
{
    ovr_2cef_0034(3 - ARG(s, 0), ARG(s, 1));
    return 1;
}

int ovr_2cef_0020(struct Wsa far *p)
{
    struct Wsa far *q;

    if (p == 0) return 0;
    q = p;
    return q->w;
}

int ovr_2cef_0025(struct Wsa far *p)
{
    struct Wsa far *q;

    if (p == 0) return 0;
    q = p;
    return q->h;
}

long ovr_2cef_003e(struct Wsa far *p)
{
    struct Wsa far *q;

    if (p == 0) return 0;
    q = p;
    return q->size;
}
