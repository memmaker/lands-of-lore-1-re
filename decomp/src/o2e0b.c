/* o2e0b: XMS cache setup (size the available extended memory, allocate and register blocks) */
/* FLAGS: -ml -3 -Y */
#include <mem.h>

struct xblk { int handle; unsigned long base; unsigned long size; unsigned long org; };
struct xmove { unsigned long len; unsigned long one; unsigned long x; unsigned long y; };
extern unsigned long g_af8a;
extern int g_af88;
extern long g_af8e;
extern long g_38a8;
extern struct xblk g_af6c;
extern struct xblk g_af7a;
long ovr_2e0e_003e(void);
unsigned ovr_2e0e_0039(int a);
int ovr_2e0e_0034(int kb);
int ovr_2e0e_0025(int h);
void ovr_2e0e_002f(int h);
void fn_2365_0ac2(struct xmove far *m, unsigned long a);

unsigned long ovr_2e0b_0020(void)
{
    unsigned long total;
    unsigned long res;

    if (ovr_2e0e_003e() == 0) return 0;
    g_af8a = (unsigned long)ovr_2e0e_0039(0) << 10;
    total = g_af8a;
    res = 0x420;
    if (res >= total) return 0;
    else return total - res;
}

int ovr_2e0b_0025(unsigned long size, unsigned long max)
{
    unsigned long kb;
    long extra;
    struct xblk far *q;
    struct xmove m;

    extra = 0;
    max = max < 0xd59f80UL ? max : 0xd59f80UL;
    if (ovr_2e0b_0020() == 0) return 0;
    memset(&g_af6c, 0, 0x1c);
    size = (size + 15) & ~15L;
    size += 16;
    if (size > g_af8a) return 0;
    else {
        extra = g_af8a - (size + 16);
        if (extra < 0) extra = 0;
        extra = extra < max ? extra : max;
        extra = (extra + 15) & ~15L;
        if (extra != 0) extra += 16;
    }
    kb = (size + extra + 0x3ff) >> 10;
    g_af88 = ovr_2e0e_0034((int)kb);
    g_af8e = 0;
    if (g_af88 == 0) {
        g_38a8 = 0;
        return 0;
    }
    g_af8a = size + extra;
    if (size != 0) {
        q = &g_af6c;
        q->handle = g_af88;
        q->base = 0;
        q->size = size;
        q->org = 0;
        m.len = size - 16;
        m.one = 1;
        m.x = 0;
        m.y = 0;
        fn_2365_0ac2(&m, q->base);
    }
    if (extra != 0) {
        q = &g_af7a;
        q->handle = g_af88;
        q->base = size;
        q->size = extra;
        q->org = size;
        m.len = (unsigned long)extra - 16;
        m.one = 1;
        m.x = size;
        m.y = size;
        fn_2365_0ac2(&m, q->base);
    }
    return 1;
}

void ovr_2e0b_002a(void)
{
    if (g_38a8 == 0) return;
    if (g_af88 != 0) {
        while (ovr_2e0e_0025(g_af88)) ;
        ovr_2e0e_002f(g_af88);
    }
    g_38a8 = 0;
}
