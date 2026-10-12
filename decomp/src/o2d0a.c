/* o2d0a: show an item/scene picture n full screen (or flash the palette when there is none) */
#include <stdio.h>
#include "lol.h"

extern int g_0962, g_0964[];
extern char g_096c[], g_098f[], g_099d[];
extern void far *g_4d5a, far *g_4d56, far *g_369f, far *g_adea;
extern int g_7fd0, g_7fdf, g_7fb6;
extern unsigned char far *g_540e;
extern long g_384c;
void ovr_2ce1_007f(char far *msg);
int fn_1e74_000f(int n);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void far *fn_215f_001d(int n);
void far *fn_215f_0003(int n);
void fn_2279_025b(void far *a, void far *b, long n);
void fn_067a_0401(int snd, int x);
int fn_0845_0c7e(int a, int b, int c, int far *d);
unsigned far *ovr_2dfd_0020(char far *name, void far *a, void far *b, int c, long d);
void ovr_2dfd_0025(void far *p);
void fn_0845_0d5e(void far *shp, int a, int b, int c, int x, int y, long e, long f, long g, long h);
int ovr_2d1b_003e(void far *a, void far *b, long t, long n);
void fn_0845_08aa(void);
void fn_0845_15d9(int n);

int ovr_2d0a_0020(void)
{
    if (g_0962 != 1) g_0962 = 1;
    return 1;
}

void ovr_2d0a_0025(void)
{
    if (g_0962 == 1) g_0962 = 0;
}

void ovr_2d0a_002a(int n)
{
    int old;
    int flag = 0;
    unsigned far *shp;
    int x;
    long t;
    unsigned char pal[0x300];
    char name[14];
    int r, i;

    if (g_0962 != 1) {
        if (ovr_2d0a_0020() == 0) ovr_2ce1_007f(g_096c);
        flag = 1;
    }
    old = fn_1e74_000f(2);
    fn_1ebc_00e7();
    fn_2279_025b(fn_215f_001d(0), g_4d5a, 0x9600L);
    fn_1ebc_00fe();
    fn_067a_0401(g_0964[n], 0);
    fn_2279_025b(fn_215f_0003(5), g_4d56, 0xfa00L);
    r = fn_0845_0c7e(g_7fd0, g_7fdf, 3, &x);
    if (r != 0) {
        sprintf(name, g_098f, r);
        if ((shp = ovr_2dfd_0020(name, fn_215f_0003(5), g_369f, 1, 0)) == 0) ovr_2ce1_007f(g_099d);
        fn_0845_0d5e(shp, 0, 6, 1, ((0xb0 - shp[4]) >> 1) + 0x70, (0x78 - shp[5]) >> 1, 0, 0, 0, 0);
        ovr_2dfd_0025(shp);
    } else {
        for (i = 0; i < 0x300; i++) pal[i] = g_540e[i];
        for (i = 1; i < 0x80; i++) {
            pal[i * 3] = 0x3f;
            pal[i * 3 + 1] = g_540e[i * 3 + 1];
            pal[i * 3 + 2] = g_540e[i * 3 + 2];
        }
        t = g_384c;
        while (ovr_2d1b_003e(g_adea, pal, g_384c - t, 10) == 1);
        t = g_384c;
        while (ovr_2d1b_003e(pal, g_adea, g_384c - t, 50) == 1);
    }
    fn_2279_025b(g_4d56, fn_215f_0003(5), 0xfa00L);
    fn_2279_025b(g_4d5a, fn_215f_001d(2), 0x9600L);
    fn_1e74_000f(old);
    fn_0845_08aa();
    g_7fb6 = 1;
    fn_0845_15d9(0);
    if (flag == 1) ovr_2d0a_0025();
}

int ovr_2d0a_002f(struct EmcState far *s)
{
    ovr_2d0a_002a(ARG(s, 0));
    return 1;
}
