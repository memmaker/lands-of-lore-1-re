/* o2d12: animated sequence at the party's block (ovr_2d12_002a); returns whether the block held 0x8000 */
#include "lol.h"

extern int g_09e4, g_7fd0, g_7fdf;
extern char g_7fe5;
extern char g_09e6[], g_0a13[], g_0a20[], g_0a46[];
extern void far *g_4d5a, far *g_4d56, far *g_36a7;
void ovr_2ce1_007f(char far *msg);
void fn_0845_0c7e(int b, int dir, int n, int far *out);
int fn_09aa_0183(int b, int dir);
void ovr_2d8a_0025(int b, int a, int c, int d);
int fn_1e74_000f(int n);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void far *fn_215f_001d(int page);
void far *fn_215f_0003(int page);
void fn_2279_025b(void far *d, void far *s, long n);
void fn_0845_15d9(int n);
void fn_067a_0401(int snd, int x);
void far *ovr_2dfd_0020(char far *name, void far *a, void far *b, int c, long d);
void ovr_2dfd_0025(void far *p);
void fn_0845_0d5e(void far *shp, int a, int b, int c, int x, int y, long e, long f, long g, long h);
void fn_0845_08aa(void);
void ovr_2d2c_0043(void);

int ovr_2d12_0020(void)
{
    if (g_09e4 != 1) g_09e4 = 1;
    return 1;
}

void ovr_2d12_0025(void)
{
    if (g_09e4 == 1) g_09e4 = 0;
}

int ovr_2d12_002a(int a)
{
    int old;
    int tmp;
    void far *shp;
    int r;
    int opened = 0;

    if (g_09e4 != 1) {
        if (!ovr_2d12_0020()) ovr_2ce1_007f(g_09e6);
        opened = 1;
    }
    fn_0845_0c7e(g_7fd0, g_7fdf, 3, &tmp);
    old = fn_1e74_000f(2);
    fn_1ebc_00e7();
    fn_2279_025b(fn_215f_001d(0), fn_215f_001d(2), 0xfa00L);
    fn_1ebc_00fe();
    fn_2279_025b(fn_215f_001d(2), g_4d5a, 0xfa00L);
    if ((shp = ovr_2dfd_0020(g_0a13, fn_215f_0003(7), g_36a7, 1, 0L)) == 0) ovr_2ce1_007f(g_0a20);
    fn_067a_0401(0x9c, 0);
    fn_0845_0d5e(shp, 0, 0x25, 2, 0x70, 0, 0L, 0L, 0L, 0L);
    fn_2279_025b(fn_215f_001d(6), g_4d56, 0x9600L);
    fn_2279_025b(fn_215f_001d(2), g_4d5a, 0xfa00L);
    r = (g_8203[fn_09aa_0183(g_7fd0, g_7fdf)].mon & 0x8000) ? 1 : 0;
    ovr_2d8a_0025(fn_09aa_0183(g_7fd0, g_7fdf), a, 0xc8, 0x80);
    fn_2279_025b(g_4d5a, fn_215f_001d(2), 0xfa00L);
    fn_0845_08aa();
    fn_0845_15d9(2);
    if (g_7fe5 == 0x18)
        shp = ovr_2dfd_0020(g_0a46, fn_215f_0003(7), g_36a7, 1, 0L);
    else
        fn_2279_025b(g_4d56, fn_215f_001d(6), 0x9600L);
    fn_2279_025b(fn_215f_001d(2), g_4d5a, 0xfa00L);
    fn_067a_0401(0xb0, 0);
    fn_0845_0d5e(shp, 0x26, 0x30, 8, 0x70, 0, 0L, 0L, 0L, 0L);
    ovr_2dfd_0025(shp);
    fn_1e74_000f(old);
    fn_1ebc_00e7();
    ovr_2d2c_0043();
    fn_1ebc_00fe();
    if (opened == 1) ovr_2d12_0025();
    fn_0845_08aa();
    return r;
}
