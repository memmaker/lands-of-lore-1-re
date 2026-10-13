/* o2d15: spell animation that pushes (type < 2) or damages (type >= 2) the monsters in front of the party */
#include "lol.h"

struct anim { int a; unsigned count; };
struct Pair { int a, b; };
extern int g_0a6c;
extern char g_0a6e[], g_0a93[], g_0a9c[];
extern struct Pair g_0a54[];
extern int g_0a62[];
extern char g_7fe5;
extern int g_7fd0, g_7fdf;
extern void far *g_4d5a;
extern void far *g_4d56;
extern void far *g_369f;
int fn_1e74_000f(int m);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_1dbc_0017(int a, int b, int c, int d, int e, int f, int g, int h);
void far *fn_215f_001d(int p);
void far *fn_215f_0003(int p);
void fn_2279_025b(void far *d, void far *s, long n);
struct anim far *ovr_2dfd_0020(char far *name, void far *buf, void far *pal, int a, long b);
void ovr_2dfd_0025(struct anim far *p);
void ovr_2ce1_007f(char far *msg);
void fn_067a_0401(long v);
void fn_0845_0d5e(struct anim far *p, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m);
void fn_0845_15d9(int n);
void fn_0845_08aa(void);
int fn_09aa_0183(int a, int b);
int fn_0845_0cf7(int blk, int a, int b);
void fn_0845_046c(int blk);
int far *fn_080e_000b(int id);
void fn_0d6c_0004(int x, int y, int *nx, int *ny, int dir);
void fn_0d6c_0742(struct Monster far *m, int x, int y);
void fn_0845_1343(int blk, int a, int b, int id, int c, int d);
int fn_070c_06a3(int a, int id, int v, int b, int c);
int fn_070c_07f5(int who, int dmg, int src, int k, int how);

int ovr_2d15_0020(void)
{
    if (g_0a6c != 1) g_0a6c = 1;
    return 1;
}

void ovr_2d15_0025(void)
{
    if (g_0a6c == 1) g_0a6c = 0;
}

void ovr_2d15_002a(int type)
{
    int old;
    int opened;
    struct anim far *p;
    int v;

    opened = 0;
    if (g_0a6c != 1) {
        if (!ovr_2d15_0020()) ovr_2ce1_007f(g_0a6e);
        opened = 1;
    }
    old = fn_1e74_000f(2);
    fn_1ebc_00e7();
    fn_2279_025b(fn_215f_001d(0), g_4d5a, 0xfa00L);
    fn_1ebc_00fe();
    fn_2279_025b(fn_215f_0003(5), g_4d56, 0xfa00L);
    if ((p = ovr_2dfd_0020(g_0a93, fn_215f_0003(5), g_369f, 1, 0L)) == 0) ovr_2ce1_007f(g_0a9c);
    fn_067a_0401(0xadL);
    fn_0845_0d5e(p, 0, 10, 3, 0x70, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    fn_067a_0401(0x97L);
    fn_0845_0d5e(p, g_0a54[type].a, g_0a54[type].b, 3, 0x70, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    fn_067a_0401(0x12L);
    fn_0845_0d5e(p, 10, 0, 3, 0x70, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    ovr_2dfd_0025(p);
    fn_2279_025b(g_4d56, fn_215f_0003(5), 0xfa00L);
    fn_1e74_000f(old);
    fn_2279_025b(g_4d5a, fn_215f_001d(2), 0xfa00L);
    fn_0845_15d9(2);
    if (type < 2) {
        int x, y;
        int far *n;
        struct Monster far *m;
        int save;

        type = fn_09aa_0183(g_7fd0, g_7fdf);
        v = fn_09aa_0183(type, g_7fdf);
        if (!fn_0845_0cf7(v, 0, 4) && !(g_8203[v].mon & 0x8000)) {
            fn_0845_046c(type);
            type = g_8203[type].mon;
            while (type & 0x8000) {
                save = type;
                m = &f_2803_15fa[type & 0x7fff];
                n = fn_080e_000b(type);
                type = *n;
                fn_0d6c_0004(m->x, m->y, &x, &y, g_7fdf * 2);
                fn_0d6c_0004(x, y, &x, &y, g_7fdf * 2);
                fn_0d6c_0004(x, y, &x, &y, g_7fdf * 2);
                fn_0d6c_0004(x, y, &x, &y, g_7fdf * 2);
                fn_0d6c_0004(x, y, &x, &y, g_7fdf * 2);
                fn_0d6c_0004(x, y, &x, &y, g_7fdf * 2);
                fn_0d6c_0004(x, y, &x, &y, g_7fdf * 2);
                fn_0d6c_0004(x, y, &x, &y, g_7fdf * 2);
                fn_0d6c_0742(m, x, y);
                fn_0845_1343(v, 0x800, -1, save, 0, 0);
            }
        }
    } else {
        int far *n;
        int save;
        int r;

        v = fn_09aa_0183(g_7fd0, g_7fdf);
        fn_0845_046c(v);
        v = g_8203[v].mon;
        while (v & 0x8000) {
            save = v;
            n = fn_080e_000b(v);
            v = *n;
            r = g_0a62[type];
            r = fn_070c_06a3(-1, save, r, 0x80, 1);
            fn_070c_07f5(save, r, -1, 2, 0x80);
        }
    }
    if (g_7fe5 == 0x1d) fn_2279_025b(g_4d5a, fn_215f_001d(2), 0xfa00L);
    fn_1ebc_00e7();
    fn_1dbc_0017(0, 0, 0, 0, 0x28, 0xc8, 2, 0);
    fn_1ebc_00fe();
    if (opened == 1) ovr_2d15_0025();
    fn_0845_15d9(2);
    fn_0845_08aa();
}
