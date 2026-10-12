/* o2d9d: flash the palette, open fake walls in front of the party and hurt marked monsters there */
#include "lol.h"

extern unsigned char far *g_540e;
extern long g_384c;
extern long g_3850;
extern char g_7fe5;
extern int g_7fd0, g_7fdf;
extern unsigned char g_531e[];
extern char g_53be[];
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_2279_025b(void far *d, void far *s, long n);
void fn_067a_0401(long v);
int ovr_2d1b_003e(void far *a, void far *b, long t, long n);
int fn_09aa_0183(int a, int b);
void fn_0845_15d9(int n);
int fn_070c_07f5(int who, int dmg, int src, int k, int how);

int ovr_2d9d_0020(void)
{
    long t;
    int r;
    unsigned f;
    unsigned char p1[0x300];
    unsigned char p2[0x300];
    int i;
    int b;
    int m;

    r = 0;
    fn_1ebc_00e7();
    fn_2279_025b(g_540e, p1, 0x300L);
    fn_2279_025b(g_540e, p2, 0x300L);
    for (i = 1; i < 0x80; i++) {
        if (g_540e[i * 3] + 0x10 > 0x3c) p1[i * 3] = 0x3c;
        else p1[i * 3] = g_540e[i * 3] + 0x10;
        p1[i * 3 + 1] = g_540e[i * 3 + 1];
        if (g_540e[i * 3 + 2] + 0x13 > 0x3f) p1[i * 3 + 2] = 0x3f;
        else p1[i * 3 + 2] = g_540e[i * 3 + 2] + 0x13;
    }
    fn_067a_0401(0x92L);
    t = g_384c;
    g_3850 = 0x46;
    while (g_3850 != 0)
        ovr_2d1b_003e(p2, p1, g_384c - t, 0x46L);
    b = fn_09aa_0183(g_7fd0, g_7fdf);
    m = WALL(b, g_7fdf ^ 2);
    f = g_531e[m];
    if ((g_7fe5 == 0x11 && m == 0x2f) || (g_7fe5 == 0x18 && m == 0x2f))
        r = 1;
    m = g_53be[m];
    if ((m == 1 || m == 2) && !(f & 1) && g_7fe5 != 0x16) {
        WALL(b, 0) = 0;
        WALL(b, 1) = 0;
        WALL(b, 2) = 0;
        WALL(b, 3) = 0;
        fn_0845_15d9(0);
        r = 1;
    }
    m = g_8203[b].mon;
    while (m & 0x8000) {
        i = m & 0x7fff;
        m = f_2803_15fa[i].next;
        if (f_2803_15fa[i].type->flags & 0x1000) {
            fn_070c_07f5(i | 0x8000, 0x64, -1, 0, 0x80);
            r = 1;
        }
    }
    t = g_384c;
    g_3850 = 0x46;
    while (g_3850 != 0)
        ovr_2d1b_003e(p1, p2, g_384c - t, 0x46L);
    fn_1ebc_00fe();
    return r;
}
