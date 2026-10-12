/* o2d4d: animated full-screen sequences (ovr_2d4d_002a plays sequence n with two moving shapes) */
#include <stdio.h>

struct SeqPos { int x1, y1, x2, y2, snd; };   /* 10 bytes, g_0fc4[] */

extern int g_0ff6, g_2144, g_7fd0, g_7fdf, g_0ff8[];
extern char g_1000[], g_1025[], g_1032[];
extern void far *g_4d5a, far *g_4d56, far *g_369f;
extern struct SeqPos g_0fc4[];
void ovr_2ce1_007f(char far *msg);
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
void fn_067a_02c7(void);

int ovr_2d4d_0020(void)
{
    if (g_0ff6 != 1) g_0ff6 = 1;
    return 1;
}

void ovr_2d4d_0025(void)
{
    if (g_0ff6 == 1) g_0ff6 = 0;
}

void ovr_2d4d_002a(int a, int n)
{
    int old;
    void far *shp;
    char name[14];
    int opened = 0;

    if (g_0ff6 != 1) {
        if (!ovr_2d4d_0020()) ovr_2ce1_007f(g_1000);
        opened = 1;
    }
    g_2144 = 1;
    ovr_2d8a_0025(fn_09aa_0183(g_7fd0, g_7fdf), a, g_0ff8[n], 0x80);
    g_2144 = 0;
    old = fn_1e74_000f(2);
    fn_1ebc_00e7();
    fn_2279_025b(fn_215f_001d(0), fn_215f_001d(2), 0xfa00L);
    fn_1ebc_00fe();
    fn_0845_15d9(2);
    fn_2279_025b(fn_215f_001d(2), g_4d5a, 0xfa00L);
    fn_067a_0401(0x9b, 0);
    fn_2279_025b(fn_215f_0003(5), g_4d56, 0xfa00L);
    sprintf(name, g_1025, n + 1);
    if ((shp = ovr_2dfd_0020(name, fn_215f_0003(5), g_369f, 1, 0L)) == 0) ovr_2ce1_007f(g_1032);
    fn_067a_0401(g_0fc4[n].snd, 0);
    fn_0845_0d5e(shp, g_0fc4[n].x1, g_0fc4[n].y1, 7, 0x70, 0, 0L, 0L, 0L, 0L);
    fn_0845_0d5e(shp, g_0fc4[n].x2, g_0fc4[n].y2, 14, 0x70, 0, 0L, 0L, 0L, 0L);
    ovr_2dfd_0025(shp);
    fn_2279_025b(g_4d56, fn_215f_0003(5), 0xfa00L);
    fn_1e74_000f(old);
    fn_1ebc_00e7();
    fn_2279_025b(g_4d5a, fn_215f_001d(0), 0xfa00L);
    fn_1ebc_00fe();
    if (opened == 1) ovr_2d4d_0025();
    fn_0845_08aa();
    fn_067a_02c7();
}
