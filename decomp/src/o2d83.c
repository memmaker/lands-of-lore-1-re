/* o2d83: spell/creature summon animation with several sprites flying in */
#include <stdlib.h>

struct anim { int a; unsigned count; char pad[4]; unsigned w; unsigned h; };
extern void far *g_4d5a;
extern void far *g_36a7;
extern char g_126c[];
extern char g_1277[];
extern char g_1298[];
extern char g_12a3[];
extern int g_1264[];
extern int g_7fd0;
extern int g_7fdf;
extern int g_7fb6;
extern long g_3850;
extern void far *g_4bec;
extern void far *g_4bf0;
extern int far f_2803_3625[];
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_1ebc_01ec(void);
void fn_1ebc_0111(int x1, int y1, int x2, int y2);
void fn_1dbc_0004(int a, int b, int c, int d, int e, int f, int g, int h);
void far *fn_215f_001d(int p);
void far *fn_215f_0003(int p);
void fn_2279_025b(void far *d, void far *s, long n);
struct anim far *ovr_2dfd_0020(char far *name, void far *buf, void far *pal, int a, long b);
void ovr_2dfd_002a(struct anim far *p, int frame, int x, int y, int c, int d, void far *e, void far *f);
void ovr_2dfd_0025(struct anim far *p);
void ovr_2ce1_007f(char far *msg);
void fn_067a_0401(long v);
void fn_0845_0d5e(struct anim far *p, int a, int b, int c, int d, int e, long f, long g, long h, long i);
int fn_0845_0c7e(int a, int b, int c, int far *out);
int fn_070c_027a(int blk, int who);
void ovr_2d8a_0020(int m, int who, int x, long t);
void fn_0845_08aa(void);
void fn_0845_15d9(int a);

void ovr_2d83_0020(int n, int who)
{
    int out;
    struct anim far *a;
    int m;
    int dir;
    int xs[6];
    int ys[6];
    int t0[6];
    int i;
    int j;

    fn_1ebc_00e7();
    fn_2279_025b(fn_215f_001d(0), g_4d5a, 0xfa00L);
    fn_1ebc_00fe();
    if ((a = ovr_2dfd_0020(g_126c, fn_215f_0003(7), g_36a7, 0, 0L)) == 0) ovr_2ce1_007f(g_1277);
    fn_067a_0401(0x48L);
    fn_0845_0d5e(a, 0, 7, 4, f_2803_3625[who] - 2, 0x8a, 0L, 0L, 0L, 0L);
    ovr_2dfd_0025(a);
    fn_1ebc_00e7();
    fn_2279_025b(g_4d5a, fn_215f_001d(0), 0xfa00L);
    fn_1ebc_00fe();
    dir = fn_0845_0c7e(g_7fd0, g_7fdf, 4, &out);
    if ((m = fn_070c_027a(out, who)) != -1) {
        ovr_2d8a_0020(m, who, g_1264[n], 5L);
        fn_0845_08aa();
        fn_0845_15d9(0);
        fn_2279_025b(fn_215f_001d(0), g_4d5a, 0xfa00L);
    }
    if ((a = ovr_2dfd_0020(g_1298, fn_215f_0003(7), g_36a7, 0, 0L)) == 0) ovr_2ce1_007f(g_12a3);
    for (i = 0; i < 6; i++) {
        xs[i] = ((0xb0 - a->w) >> 1) + (rand() % 64 - 32) + 0x70;
        ys[i] = ((0x78 - a->h) >> 1) + (rand() % 32 - 16);
        t0[i] = i * 2;
    }
    for (j = 0; j < n * 2 + 12; j++) {
        g_3850 = 4;
        fn_2279_025b(g_4d5a, fn_215f_001d(2), 0xfa00L);
        for (i = 0; i < n + 1; i++) {
            if (t0[i] < j && t0[i] + 13 > j) {
                if (j - t0[i] == 1) fn_067a_0401(0xa2L);
                ovr_2dfd_002a(a, (j - t0[i] + dir * 16) % a->count, xs[i], ys[i], 2, 0x5000, g_4bec, g_4bf0);
                fn_1ebc_0111(xs[i], ys[i], xs[i] + a->w, ys[i] + a->h);
                fn_1dbc_0004(xs[i], ys[i], xs[i], ys[i], a->w, a->h, 2, 0);
                fn_1ebc_01ec();
            }
        }
        if (j < n * 2 + 11) while (g_3850 != 0) ;
    }
    ovr_2dfd_0025(a);
    fn_2279_025b(g_4d5a, fn_215f_001d(2), 0xfa00L);
    fn_0845_08aa();
    g_7fb6 = 1;
}
