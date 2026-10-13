/* o2da0: animated sequence chosen by how far the party can see ahead; then a random party member is hurt */
#include "lol.h"

struct anim { int a; unsigned count; };
struct Seq { int start, end, snd; };
extern struct Seq far f_26a2_0000[];
extern int g_151e, g_20d3;
extern char g_1520[], g_1547[], g_1551[];
extern unsigned char g_531e[];
extern char g_7fe5;
extern int g_7fd0, g_7fdf;
extern unsigned long g_384c;
extern void far *g_4d5a;
extern void far *g_4d56;
extern void far *g_369f;
extern void far *g_4bec;
extern void far *g_4bf0;
int fn_1e74_000f(int m);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_1ebc_01ec(void);
void fn_1ebc_0111(int a, int b, int c, int d);
void fn_1dbc_0004(int a, int b, int c, int d, int e, int f, int g, int h);
void far *fn_215f_001d(int p);
void far *fn_215f_0003(int p);
void fn_2279_025b(void far *d, void far *s, long n);
struct anim far *ovr_2dfd_0020(char far *name, void far *buf, void far *pal, int a, long b);
void ovr_2dfd_002a(struct anim far *p, int frame, int a, int b, int c, int d, void far *e, void far *f);
void ovr_2dfd_0025(struct anim far *p);
void ovr_2ce1_007f(char far *msg);
void fn_067a_0401(long v);
int fn_09aa_0183(int a, int b);
int fn_0845_0636(int lo, int hi);
int fn_070c_07f5(int who, int dmg, int src, int k, int how);

int ovr_2da0_0020(void)
{
    if (g_151e != 1) g_151e = 1;
    return 1;
}

void ovr_2da0_0025(void)
{
    if (g_151e == 1) g_151e = 0;
}

void ovr_2da0_002a(void)
{
    int old;
    int opened;
    int done;
    struct anim far *p;
    unsigned long t;
    int v;
    int blk, i;

    opened = 0;
    g_20d3 = 1;
    if (g_151e != 1) {
        if (!ovr_2da0_0020()) ovr_2ce1_007f(g_1520);
        opened = 1;
    }
    blk = g_7fd0;
    for (i = 0; i < 3; i++) {
        v = g_8203[blk].mon;
        if ((v & 0x8000) || (g_531e[((char *)&g_8203[fn_09aa_0183(blk, g_7fdf)])[g_7fdf ^ 2]] & 7)) {
            if (v & 0x8000) break;
            break;
        }
        blk = fn_09aa_0183(blk, g_7fdf);
    }
    blk = i;
    old = fn_1e74_000f(2);
    fn_1ebc_00e7();
    fn_2279_025b(fn_215f_001d(0), g_4d5a, 0xfa00L);
    fn_1ebc_00fe();
    done = 0;
    fn_067a_0401(0x94L);
    fn_2279_025b(fn_215f_0003(5), g_4d56, 0xfa00L);
    if ((p = ovr_2dfd_0020(g_1547, fn_215f_0003(5), g_369f, 1, 0L)) == 0) ovr_2ce1_007f(g_1551);
    for (i = f_26a2_0000[blk].start; !done; ) {
        t = g_384c;
        fn_2279_025b(g_4d5a, fn_215f_001d(2), 0x9600L);
        if (f_26a2_0000[blk].snd == i) fn_067a_0401(0xacL);
        ovr_2dfd_002a(p, (unsigned)i % p->count, 0x70, 0, 2, 0x5000, g_4bec, g_4bf0);
        fn_1ebc_0111(0x70, 0, 0x120, 0x78);
        fn_1dbc_0004(0x70, 0, 0x70, 0, 0xb0, 0x78, 2, 0);
        fn_1ebc_01ec();
        while (t + 5 > g_384c) ;
        i++;
        if (f_26a2_0000[blk].end < i) done = 1;
    }
    ovr_2dfd_0025(p);
    fn_2279_025b(g_4d56, fn_215f_0003(5), 0xfa00L);
    fn_1e74_000f(old);
    fn_1ebc_00e7();
    fn_2279_025b(g_4d5a, fn_215f_001d(0), 0x9600L);
    fn_1ebc_00fe();
    fn_2279_025b(g_4d5a, fn_215f_001d(2), 0x9600L);
    blk = fn_0845_0636(1, 4) - 1;
    for (i = 0; i < 4; i++) {
        if (!(f_2803_362d[blk++].flags & 1)) blk %= 4;
        else fn_070c_07f5(i, g_7fe5 + 10, 0x8000, 2, 0x86);
    }
    if (opened == 1) ovr_2da0_0025();
}
