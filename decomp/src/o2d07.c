/* o2d07: play an animated sequence on screen, then wake the monsters of the current block */

struct anim { int a; unsigned count; };
struct blk { int first; char pad[8]; };
struct mon { int next; char pad[0x2c]; };
extern void far *g_4d5a;
extern void far *g_4d56;
extern void far *g_369f;
extern char g_093e[];
extern char g_0946[];
extern long g_3850;
extern void far *g_4bec;
extern void far *g_4bf0;
extern int g_7fd0;
extern int g_7fdf;
extern struct blk g_8207[];
extern struct mon far f_2803_15fa[];
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
void fn_0845_08aa(void);
int fn_09aa_0183(int a, int b);
void ovr_2d8a_0020(int m, long a, long b);
void fn_0845_15d9(int a);

int ovr_2d07_0020(void)
{
    return 1;
}

void ovr_2d07_0025(void)
{
    int old;
    struct anim far *p;
    register int i;
    int done;

    ovr_2d07_0020();
    old = fn_1e74_000f(2);
    fn_1ebc_00e7();
    fn_2279_025b(fn_215f_001d(0), g_4d5a, 0x9600L);
    fn_1ebc_00fe();
    fn_2279_025b(fn_215f_0003(5), g_4d56, 0xfa00L);
    if ((p = ovr_2dfd_0020(g_093e, fn_215f_0003(5), g_369f, 1, 0L)) == 0) ovr_2ce1_007f(g_0946);
    fn_067a_0401(0x91L);
    done = 0;
    i = 0;
    while (!done) {
        g_3850 = 3;
        fn_2279_025b(g_4d5a, fn_215f_001d(2), 0x9600L);
        ovr_2dfd_002a(p, i % p->count, 0x70, 0, 2, 0x5000, g_4bec, g_4bf0);
        fn_1ebc_0111(0x70, 0, 0x120, 0x80);
        fn_1dbc_0004(0x70, 0, 0x70, 0, 0xb0, 0x78, 2, 0);
        fn_1ebc_01ec();
        while (g_3850 != 0) ;
        if (++i > p->count - 1) done = 1;
    }
    ovr_2dfd_0025(p);
    fn_2279_025b(g_4d56, fn_215f_0003(5), 0xfa00L);
    fn_2279_025b(g_4d5a, fn_215f_001d(2), 0x9600L);
    fn_1e74_000f(old);
    fn_0845_08aa();
    i = g_8207[fn_09aa_0183(g_7fd0, g_7fdf)].first;
    while (i & 0x8000) {
        ovr_2d8a_0020(i, 0xfffffL, 6L);
        i = f_2803_15fa[i & 0x7fff].next;
    }
    fn_0845_15d9(0);
}
