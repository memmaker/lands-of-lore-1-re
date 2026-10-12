/* o2d28: earthquake / flash effect sequences: WSA animation with a palette and screen-shake callback */
#include <stdio.h>

struct Quake { char a; char b; int snd; };   /* 4 bytes, g_0c70[] */

extern int g_0c6e, g_0c84, g_0c86, g_0c88, g_0c92, g_7fd0, g_7fdf, g_7fb6, g_0c8a[];
extern struct Quake g_0c70[];
extern char g_0c94[], g_0cbf[], g_0ccf[];
extern void far *g_4d5a, far *g_4d56, far *g_369f;
extern char far *g_540e;
extern long g_3850;
extern unsigned long g_384c;
void ovr_2ce1_007f(char far *msg);
int fn_09aa_0183(int b, int dir);
void ovr_2d8a_0025(int b, int a, int c, int d);
int fn_1e74_000f(int n);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_1ebc_022a(int a, char b, char c);
void far *fn_215f_001d(int page);
void far *fn_215f_0003(int page);
void fn_2279_025b(void far *d, void far *s, long n);
void fn_0845_15d9(int n);
void fn_067a_0401(int snd, int x);
void far *ovr_2dfd_0020(char far *name, void far *a, void far *b, int c, long d);
void ovr_2dfd_0025(void far *p);
void fn_0845_0d5e(void far *shp, int a, int b, int c, int x, int y, void far *e, long f, long g, long h);
void fn_0845_08aa(void);
void fn_1ef2_001c(void far *pal);
void fn_1dbc_0004(int x1, int y1, int x2, int y2, int w, int h, int s, int d);
void fn_234e_0003(int n);
void fn_234e_0062(void);
unsigned char fn_2313_0000(void);
void ovr_2d28_002f(void);
void ovr_2d28_0034(int dur, int dx, int dy, int restore);

int ovr_2d28_0020(void)
{
    if (g_0c6e != 1) g_0c6e = 1;
    return 1;
}

void ovr_2d28_0025(void)
{
    if (g_0c6e == 1) g_0c6e = 0;
}

void ovr_2d28_002a(int n, int a)
{
    int old;
    int opened;
    void far *shp;
    char name[14];
    int i;

    opened = 0;
    if (g_0c6e != 1) {
        if (!ovr_2d28_0020()) ovr_2ce1_007f(g_0c94);
        opened = 1;
    }
    fn_1ebc_00e7();
    fn_2279_025b(fn_215f_001d(0), fn_215f_001d(2), 0xfa00L);
    fn_0845_15d9(2);
    old = fn_1e74_000f(2);
    fn_2279_025b(fn_215f_001d(2), g_4d5a, 0xfa00L);
    fn_2279_025b(fn_215f_0003(5), g_4d56, 0xfa00L);
    g_0c86 = g_0c70[n].snd;
    g_0c88 = 0;
    g_0c84 = g_0c70[n].b;
    sprintf(name, g_0cbf, n + 1);
    if ((shp = ovr_2dfd_0020(name, fn_215f_0003(5), g_369f, 1, 0L)) == 0) ovr_2ce1_007f(g_0ccf);
    for (i = 0; i < 4; i++)
        fn_0845_0d5e(shp, 0, g_0c70[n].a, 3, 0x5d, 0, (void far *)ovr_2d28_002f, 0L, 0L, 0L);
    ovr_2dfd_0025(shp);
    fn_1ef2_001c(g_540e);
    fn_2279_025b(g_4d56, fn_215f_0003(5), 0xfa00L);
    fn_1e74_000f(old);
    fn_2279_025b(g_4d5a, fn_215f_001d(2), 0xfa00L);
    fn_2279_025b(g_4d5a, fn_215f_001d(0), 0xfa00L);
    fn_0845_08aa();
    ovr_2d8a_0025(fn_09aa_0183(g_7fd0, g_7fdf), a, g_0c8a[n], 5);
    g_7fb6 = 1;
    fn_0845_15d9(0);
    fn_1ebc_00fe();
    if (opened == 1) ovr_2d28_0025();
}

void ovr_2d28_002f(void)
{
    char pal[0x300];
    int i;

    if (g_0c84 == 2) ovr_2d28_0034(1, 2, 3, 0);
    if (g_0c92 % g_0c84 == 0) {
        fn_2279_025b(g_540e, pal, 0x300L);
        for (i = 6; i < 0x180; i++) {
            pal[i] = pal[i] * 0x78 / 0x40;
            if (pal[i] > 0x3f) pal[i] = 0x3f;
        }
        fn_1ef2_001c(pal);
    } else {
        fn_1ef2_001c(g_540e);
    }
    if (g_0c84 == 2) {
        if (g_0c88 == 0) {
            fn_067a_0401(g_0c86, 0);
            g_0c88 = 1;
        }
    } else if (!(g_0c92 & 7)) {
        fn_067a_0401(g_0c86, 0);
    }
    g_0c92++;
}

#define RND(n) ((n) ? fn_2313_0000() % ((n) * 2) - (n) : 0)

void ovr_2d28_0034(int dur, int dx, int dy, int restore)
{
    unsigned long end;
    int x = 0, y = 0;

    fn_234e_0003(2);
    fn_1dbc_0004(0x70, 0, 0x70, 0, 0xb0, 0x78, 0, 6);
    end = g_384c + dur;
    fn_1ebc_022a(8, 1, 5);
    while (g_384c < end) {
        g_3850 = 2;
        if (dx) x = RND(dx);
        if (dy) y = RND(dy);
        fn_1dbc_0004(x < 0 ? 0x70 - x : 0x70, y < 0 ? 0 - y : 0, x < 0 ? 0x70 : x + 0x70, y < 0 ? 0 : y,
                     0xb0 - (x < 0 ? -x : x), 0x78 - (y < 0 ? -y : y), 6, 0);
        while (g_3850 != 0) ;
    }
    if (restore == 1) {
        fn_1dbc_0004(0x70, 0, 0x70, 0, 0xb0, 0x78, 6, 0);
        fn_0845_08aa();
    }
    fn_234e_0062();
}
