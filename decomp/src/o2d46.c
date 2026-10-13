/* o2d46: misc helpers (load PAK sub-files, level shape preload, dissolve blit, scratch allocator, script opcodes) */
#include <stdio.h>
#include <string.h>
#include <mem.h>
#include "lol.h"

struct Ctx { char pad[0xc]; int sp; char pad2[0x1e]; int stack[1]; };
#define CARG(c, n) ((c)->stack[(c)->sp + (n)])
struct Deco4 { void far *p; int a, b, c; };
extern int far *g_7fcc;
extern int g_4b92;
extern char g_4b52[];
extern char g_0f96[], g_0fb4[], g_0fb6[];
extern char g_0f8a[][4];
extern char g_20db;
extern void far *g_4ea0;
extern void far *g_4c06[][28];
extern int far *g_4edc;
extern unsigned long g_20ee;
extern unsigned long g_369f;
extern char g_536e[];
extern int g_5a52[][0x24];
extern void far *g_5412[];
extern struct Deco4 g_4bd0;
void ovr_2ded_002f(char far *str, int a, int b, char far *p);
void far *fn_215f_0003(int p);
void far *fn_1f36_0064(void far *p, int idx);
int fn_1f36_0029(void far *p);
void far *fn_203b_0007(long size, int flags);
void fn_2279_025b(void far *s, void far *d, long n);
void far *fn_2037_0002(void far *p, long off);
void far *fn_15a7_030c(void far *cache, void far *id);
void fn_15a7_0210(void far *cache, void far *p);
unsigned far fn_2164_000d(unsigned lo, unsigned hi);
int fn_1e74_000f(int n);
void fn_1f20_0000(int x, int y, int c);
void far *fn_2279_02b5(void far *p);
long fn_0845_13f1(void far *a, void far *b);
void fn_0845_144e(void far *p);
void fn_07bc_047f(int a, int it, int c, int d, int e);
void fn_07bc_044c(int it);
void ovr_2d46_002a(int a, char far *s, ...);
char far *ovr_2d46_002f(char far *name, int n);

int ovr_2d46_0020(char far *s, int n)
{
    ovr_2ded_002f(s, n, n, 0);
    return *g_7fcc;
}

void far *ovr_2d46_0025(int a, int b, int c)
{
    void far *p;
    void far *q;
    int n;

    p = fn_1f36_0064(fn_215f_0003(a), b);
    if (p != 0) {
        n = fn_1f36_0029(p);
        if (c == g_4b92 && n > 15000) c = 0;
        q = fn_203b_0007((long)n, c);
        if (q == 0)
            ovr_2d46_002a(1, g_0f96, b);
        else
            fn_2279_025b(p, q, (long)n);
    } else
        q = 0;
    return q;
}

void ovr_2d46_002a(int a, char far *s, ...)
{
}

char far *ovr_2d46_002f(char far *name, int n)
{
    if (name == 0) return 0;
    memcpy(g_4b52, name, 14);
    g_4b52[8] = 0;
    strcat(g_4b52, g_0fb4);
    if (n == -1) strcat(g_4b52, g_0f8a[g_20db]);
    else strcat(g_4b52, g_0f8a[n]);
    return g_4b52;
}

void ovr_2d46_0034(int a, int b)
{
    long sz;
    void far *p;
    char buf[16];
    int i;

    sprintf(buf, g_0fb6, ABS(b));
    ovr_2d46_0020(buf, 3);
    for (i = 0; i < 0x1c; i++)
        fn_15a7_0210(g_4ea0, fn_15a7_030c(g_4ea0, g_4c06[a][i]));
    for (i = 0; i < 0x1c; i++) {
        p = fn_1f36_0064(fn_215f_0003(3), i);
        sz = ((long)fn_1f36_0029(p) + 1) & ~1L;
        fn_2279_025b(p, g_4c06[a][i], sz);
        if (i != 0x1b) g_4c06[a][i + 1] = fn_2037_0002(g_4c06[a][i], sz);
    }
}

void ovr_2d46_0039(int x0, int y0, int x1, int y1, unsigned n, unsigned m, int page1, int page2)
{
    int far *a;
    int far *b;
    int t;
    unsigned k;
    unsigned j;
    unsigned l;
    int x, y, x2, y2;
    int c;
    int old;
    unsigned i;
    register unsigned r;

    a = g_4edc;
    b = a + 0x140;
    for (i = 0; i < n; i++) a[i] = i;
    for (i = 0; i < m; i++) b[i] = i;
    for (i = 0; i < n; i++) {
        r = fn_2164_000d(0, n - 1);
        j = i;
        t = a[r];
        a[r] = a[j];
        a[j] = t;
    }
    for (i = 0; i < m; i++) {
        r = fn_2164_000d(0, m - 1);
        j = i;
        t = b[r];
        b[r] = b[j];
        b[j] = t;
    }
    old = fn_1e74_000f(page1);
    for (k = 0; k < m; k++) {
        l = k;
        for (i = 0; i < n; i++) {
            x = x0 + a[i];
            y = y0 + b[l];
            x2 = x1 + a[i];
            y2 = y1 + b[l];
            l++;
            if (l >= m) l = 0;
            fn_1e74_000f(page1);
            c = *((unsigned char far *)fn_215f_0003(2) + y * 320 + x);
            fn_1e74_000f(page2);
            fn_1f20_0000(x2, y2, c);
        }
    }
    fn_1e74_000f(old);
}

void far *ovr_2d46_003e(long n, unsigned flags)
{
    void far *p;
    unsigned long pad;

    pad = ((flags & 0x20) && (g_20ee & 0xf)) ? 0x10 - (g_20ee & 0xf) : 0;
    if (g_20ee + pad + n > g_369f)
        p = fn_203b_0007(n, flags);
    else {
        p = fn_2037_0002(fn_215f_0003(5), g_20ee + pad);
        p = fn_2279_02b5(p);
        g_20ee += n + pad;
    }
    return p;
}

void ovr_2d46_0043(void far *p)
{
    void far *q;
    long d;

    if (p == 0) return;
    q = fn_2279_02b5(fn_215f_0003(5));
    p = fn_2279_02b5(p);
    if (p != (void far *)-1L) {
        d = fn_0845_13f1(p, q);
        if (d < 0 || d > g_369f) {
            fn_0845_144e(p);
            return;
        }
        d = ABS(d);
        g_20ee = g_20ee < d ? g_20ee : d;
    } else
        g_20ee = 0;
}

int ovr_2d46_0048(int ch, unsigned mask)
{
    int i;
    int r;

    r = 0;
    for (i = 0; i < 0xb; i++) {
        if (mask & (1 << i)) {
            r = f_2803_362d[ch].items[i];
            if (r) {
                f_2803_362d[ch].items[i] = 0;
                fn_07bc_047f(ch, r, 0x100, 0, 0);
                break;
            }
        }
    }
    return r;
}

void ovr_2d46_0057(int lo, int hi)
{
    int i;

    for (i = 1; i < 400; i++)
        if (f_2803_1cfd[i].level >= lo && f_2803_1cfd[i].level <= hi)
            fn_07bc_044c(i);
}

int ovr_2d46_005c(struct Ctx far *c)
{
    ovr_2d46_0057(CARG(c, 0), CARG(c, 1));
    return 1;
}

int ovr_2d46_004d(struct Ctx far *c)
{
    if (CARG(c, 0) == 0)
        setmem(&g_4bd0, 10, 0);
    else {
        g_4bd0.p = g_5412[g_5a52[g_536e[CARG(c, 0)]][CARG(c, 1)]];
        g_4bd0.a = CARG(c, 2);
        g_4bd0.b = CARG(c, 3);
        g_4bd0.c = CARG(c, 4);
    }
    return 1;
}

void ovr_2d46_0052(void)
{
}
