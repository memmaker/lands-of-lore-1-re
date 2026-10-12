/* o2d99: show the monsters on the party's block frozen behind a picture overlay (scene with blinking frame) */
#include "lol.h"

extern int far f_26a0_0018;
extern char g_14cc[], g_14f3[], g_14fd[];
extern int g_14ca, g_2144, g_3649;
extern int g_7fd0, g_7fdf;
extern void far *g_4d5a, far *g_4d56, far *g_369f;
void ovr_2ce1_007f(char far *msg);
int fn_1e74_000f(int n);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void far *fn_215f_001d(int n);
void far *fn_215f_0003(int n);
void fn_2279_025b(void far *a, void far *b, long n);
void fn_067a_0401(int snd, int x);
void fn_067a_02c7(void);
int fn_09aa_0183(int x, int y);
void ovr_2d8a_0020(int m, int a, int b, long c);
void fn_0845_15d9(int n);
void fn_2096_014b(int x, int y, int w, int h, void far *p, int page);
void fn_2096_0000(int x, int y, int w, int h, void far *p, int page);
void far *ovr_2dfd_0020(char far *name, void far *a, void far *b, int c, long d);
void ovr_2dfd_0025(void far *p);
void fn_0845_0d5e(void far *shp, int a, int b, int c, int x, int y, void far *e, long f, long g, long h);
void fn_0845_08aa(void);
void ovr_2d99_002f(void);

int ovr_2d99_0020(void)
{
    if (f_26a0_0018 != 1) f_26a0_0018 = 1;
    return 1;
}

void ovr_2d99_0025(void)
{
    if (f_26a0_0018 == 1) f_26a0_0018 = 0;
}

void ovr_2d99_002a(int a, int b)
{
    int old;
    int flag = 0;
    void far *shp;
    int next;
    int ids[6];
    int mode[6];
    int c15[6];
    int m, n;

    if (f_26a0_0018 != 1) {
        if (ovr_2d99_0020() == 0) ovr_2ce1_007f(g_14cc);
        flag = 1;
    }
    old = fn_1e74_000f(2);
    fn_1ebc_00e7();
    fn_2279_025b(fn_215f_001d(0), g_4d5a, 0xfa00L);
    fn_1ebc_00fe();
    fn_2279_025b(fn_215f_0003(5), g_4d56, 0x10000L);
    fn_067a_0401(0x4a, 0);
    n = 0;
    m = g_8203[fn_09aa_0183(g_7fd0, g_7fdf)].mon;
    while (m & 0x8000) {
        next = f_2803_15fa[m & 0x7fff].next;
        if (f_2803_15fa[m & 0x7fff].mode < 13) {
            ids[n] = m & 0x7fff;
            n++;
            if (!(f_2803_15fa[m & 0x7fff].type->flags & 0x2000)) {
                g_2144 = 1;
                ovr_2d8a_0020(m, b, a, 0);
                g_2144 = 0;
                f_2803_15fa[m & 0x7fff].flags &= ~0x10;
            }
        }
        m = next;
    }
    for (m = 0; m < n; m++) {
        mode[m] = f_2803_15fa[ids[m]].mode;
        c15[m] = f_2803_15fa[ids[m]].c15;
        f_2803_15fa[ids[m]].mode = 8;
        f_2803_15fa[ids[m]].c15 = 0;
    }
    fn_0845_15d9(g_3649);
    fn_2096_014b(0x70, 0, 0xb0, 0x78, fn_215f_0003(7), g_3649);
    for (m = 0; m < n; m++) {
        f_2803_15fa[ids[m]].mode = mode[m];
        f_2803_15fa[ids[m]].c15 = c15[m];
    }
    if ((shp = ovr_2dfd_0020(g_14f3, fn_215f_0003(5), g_369f, 0, 0)) == 0) ovr_2ce1_007f(g_14fd);
    fn_1ebc_00e7();
    fn_0845_0d5e(shp, 0, 0x25, 2, 0, 0, 0, 0, 0, 0);
    for (m = 0; m < 1; m++)
        fn_0845_0d5e(shp, 0x26, 0x29, 8, 0, 0, (void far *)ovr_2d99_002f, 0, 0, 0);
    ovr_2dfd_0025(shp);
    fn_1ebc_00fe();
    fn_2279_025b(g_4d56, fn_215f_0003(5), 0x10000L);
    fn_1e74_000f(old);
    fn_1ebc_00e7();
    fn_2279_025b(g_4d5a, fn_215f_001d(0), 0xfa00L);
    fn_0845_08aa();
    fn_1ebc_00fe();
    fn_067a_02c7();
    if (flag == 1) ovr_2d99_0025();
}

void ovr_2d99_002f(void)
{
    if (g_14ca) fn_2096_0000(0x70, 0, 0xb0, 0x78, fn_215f_0003(6), g_3649);
    g_14ca = g_14ca == 0 ? 1 : 0;
}
