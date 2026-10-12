/* s008: UI and misc helpers (boxes, bars, messages, palette fades, string table, hand item, animation player) */
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <mem.h>
#include <stdlib.h>
#include <process.h>
#include <dos.h>
#include "lol.h"

struct Wsa { int w0; unsigned frames; int w4; int w6; int w; int h; };

extern unsigned char far f_2803_0044;
extern char far f_2803_0045;
extern int far f_27dd_0000[][14];
extern char far f_2803_3611[];
extern char far f_2b8c_0000[][0x200];
extern unsigned char g_2fac[];
extern unsigned char g_31ec[];
extern unsigned char g_531e[];
extern int g_4eac[];
extern char g_ab04[];
extern char g_ad99[], g_ae59[], g_aeaa[];
extern int g_ae57;
extern char g_20db;
extern union REGS g_ab0a;
extern char far *g_7d82[];
extern unsigned char far *g_540e;
extern unsigned char far *g_adea;
extern void far *g_4ea0;
extern void far *g_4d5a;
extern void far *g_4d68, far *g_4d6c;
extern void far *g_4bec, far *g_4bf0;
extern void far *g_7fc4;
extern int g_4d70;
extern unsigned long g_384c, g_4c02, g_4bc8;
extern long g_3850;
extern int g_3713, g_20d3, g_20d5, g_20f4, g_20f6;
extern int g_2f10, g_2f12;
extern unsigned g_806a, g_7fd6, g_7fda;
extern int g_4bf6, g_4bf8, g_4d66;
extern int g_7fb6, g_7fd0, g_7fdf, g_7fe1, g_06d7;
extern char g_7fd8, g_81fe;
extern int g_8048, g_ab1a, g_ab20, g_ab22;
extern char far *g_ab1c;

void fn_1e59_001d(int x1, int y1, int x2, int y2, int c);
void fn_1e30_0209(int x1, int y1, int x2, int y2, int c);
void fn_1e54_0001(int x1, int y1, int x2, int y2, int c);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_1ebc_0111(int x1, int y1, int x2, int y2);
void fn_1ebc_01ec(void);
void fn_130a_0784(void);
void fn_130a_028a(void);
void fn_130a_0605(void);
int fn_14b3_01fa(int n);
void fn_14b3_0284(char far *s);
void fn_14b3_0122(int n);
void fn_1ef2_002f(unsigned char far *pal, int i, unsigned char far *rgb);
void fn_1ef2_0075(unsigned char far *pal, int delay, long a);
void fn_0bbc_070e(int a, int b);
void fn_0bbc_07ef(void);
void fn_067a_0401(int n, int force);
void fn_2279_025b(void far *a, void far *b, unsigned long n);
int fn_1aff_0420(int a, int b);
int fn_1e74_000f(int n);
int fn_2365_063f(void far *p);
int fn_19ba_0086(void far *p);
void far *fn_15a7_030c(void far *cache, void far *id);
void far *fn_15a7_00b0(void far *cache, long size, void far *id);
long fn_15a7_04b0(void far *cache);
void far *fn_15a7_043c(void far *cache);
void fn_15a7_0004(void far *cache, unsigned long size);
void fn_15a7_0501(void far *cache);
void fn_15a7_0210(void far *cache, void far *p);
int fn_1f36_0029(void far *hdr);
void fn_1e9f_0002(int x, int y, void far *shape);
char far *fn_212a_014c(void far *tab, int id);
void fn_212a_00e5(char far *src, char far *dst);
void fn_212a_0005(char far *src, char far *dst);
unsigned fn_1e64_002b(char far *s);
void fn_1f6c_0006(char far *s, int x, int y, int c1, int c2);
void fn_234e_0003(int n);
void fn_234e_0062(void);
void fn_1dbc_0017(int a, int b, int c, int d, int e, int f, int g, int h);
void fn_1dbc_0004(int a, int b, int c, int d, int e, int f, int g, int h);
void ovr_2cda_0052(void);
void ovr_2cda_0061(int a);
int fn_154c_0136(void);
int fn_154c_0057(int id, int a, int b);
void fn_07bc_047f(int a, int it, int c, int d, int e);
int fn_09aa_0183(int b, int dir);
void fn_2309_000c(void);
void far *fn_215f_001d(int page);
void ovr_2dfd_002a(struct Wsa far *w, int f, int x, int y, int a, int b, void far *c, void far *d);
int ovr_2d1b_003e(void far *a, void far *b, long t, long c);
unsigned fn_2315_0018(int a);
char far *ovr_2d46_002f(char far *s, int n);
void fn_2148_002c(int d);
void fn_2148_014d(char far *s);
int far *fn_080e_000b(int id);
void fn_203b_0203(void far *p);
void fn_0d6c_0995(struct Monster far *m, int mode);
void fn_0d6c_0742(struct Monster far *m, int a, int b);
void fn_1e9a_000b(int a, int b, int c, int d, int e);

void fn_0845_0631(void far *p);
void fn_0845_093a(void);
char far *fn_0845_0c08(int it);
int fn_0845_11b7(void);
void fn_0845_1430(unsigned char far *pal);
void fn_0845_1536(void);

unsigned char g_21d6[5] = { 0x0b, 0, 0x2b, 0x1b, 0 };
unsigned char g_21db[5] = { 0xfe, 0xa2, 0x84, 0x97, 0x9f };
int g_21e0 = 0;

void fn_0845_0008(int x, int y, int w, int h, int c1, int c2, int fill)
{
    w--;
    h--;
    if (fill != -1) fn_1e59_001d(x + 1, y + 1, x + w - 1, y + h - 1, fill);
    fn_1e30_0209(x + 1, y, x + w, y, c2);
    fn_1e30_0209(x + w, y, x + w, y + h - 1, c2);
    fn_1e30_0209(x, y, x, y + h, c1);
    fn_1e30_0209(x, y + h, x + w, y + h, c1);
}

void fn_0845_00ac(int x, int y, int val, int val2, int max, int w, int h, int color, int bg, int flag)
{
    register int v = val;
    int len;

    w--;
    h--;
    if (max < 1) return;
    v = v > 0 ? v : 0;
    v = max < v ? max : v;
    len = h * v / max;
    if (len <= 0 && v > 0) len = 1;
    fn_1e30_0209(x - 1, y - h, x - 1, y, 1);
    if (flag) {
        if (max >> 1 > v) color = 0x90;
        if (max >> 2 > v) color = 0x84;
    }
    if (len > 0) fn_1e59_001d(x, y - len, x + w, y, color);
    if (len < h) fn_1e59_001d(x, y - h, x + w, y - len, bg);
    if (val2 > 0 && val2 <= max) {
        len = h * val2 / max;
        if (len <= 0) len = 1;
        fn_1e54_0001(x, y - len, x + w, y, color - 2);
    }
}

/* NONMATCHING */
void fn_0845_01c4(register unsigned flags, char far *fmt, ...)
{
    va_list ap;
    int old;
    char buf[0xf0];
    unsigned char pal[0x300];
    int color;

    fn_1ebc_00e7();
    if (flags & 4) flags ^= 4;
    else fn_130a_0784();
    color = g_21db[flags & 0x7fff];
    if (g_7fd6 & 2)
        old = fn_14b3_01fa(4);
    else {
        old = fn_14b3_01fa(3);
        memcpy(pal, g_2fac, 0x300);
        fn_1ef2_002f(pal, 0xc0, &pal[color * 3]);
        color = 0xc0;
        fn_0bbc_070e(11, 1);
    }
    fn_1ebc_00fe();
    g_3713 = color;
    va_start(ap, fmt);
    vsprintf(buf, fmt, ap);
    fn_14b3_0284(buf);
    fn_14b3_0122(old);
    if (!(flags & 0x8000) && g_21d6[flags]) fn_067a_0401(g_21d6[flags], 0);
    g_20f4 = flags & 0x7fff;
    g_20f6 = 0;
}

/* NONMATCHING */
void fn_0845_02c6(unsigned char far *src, unsigned char far *dst, int s, int i)
{
    fn_2279_025b(src, dst, 0x300L);
    fn_0845_1430(dst);
    s = (8 - s) << 5;
    if (i >= 0 && i < 8 && (g_806a & 0x800)) {
        s = 0x100 - fn_1aff_0420(0x100 - s, (i & 0xfffe) << 5);
        if (s < 0) s = 0;
    }
    i = 0;
    do {
        dst[i] = fn_1aff_0420(dst[i], s);
        i++;
    } while (i < 0x180);
}

void fn_0845_035b(unsigned char far *src, int lvl, int idx)
{
    fn_0845_02c6(src, g_540e, lvl, idx);
    fn_1ef2_0075(g_540e, 5, 0L);
    g_20d5 = 0;
}

/* NONMATCHING */
int fn_0845_038e(int x, int y, int x1, int y1, int x2, int y2)
{
    if (x < x1 || x > x2) return 0;
    return y < y1 || y > y2 ? 0 : 1;
}

int fn_0845_03b4(int x1, int y1, int x2, int y2)
{
    return fn_0845_038e(g_2f10, g_2f12, x1, y1, x2, y2);
}

void fn_0845_03d4(int delay)
{
    unsigned char pal[0x300];
    int old;

    if (g_20d5 == 1) return;
    fn_2279_025b(g_adea, pal, 0x300L);
    setmem(pal, 0x180, 0);
    fn_0845_1430(pal);
    fn_1ef2_0075(pal, delay, 0L);
    fn_1ebc_00e7();
    old = fn_1e74_000f(0);
    fn_1e59_001d(0x70, 0, 0x120, 0x78, 0);
    fn_1e74_000f(old);
    fn_1ebc_00fe();
    g_20d5 = 1;
}

int fn_0845_046c(int b)
{
    int far *p;
    int i;

    if (g_7fb6) return 1;
    p = g_4eac;
    for (i = 0; i < 15; i++, p++)
        if (*p == b) {
        found:
            g_7fb6 = 1;
            return 1;
        }
    if (b == g_7fd0) goto found;
    return 0;
}

int fn_0845_04af(int x1, int y1, int x2, int y2)
{
    return ABS(x1 - x2) + ABS(y1 - y2);
}

/* NONMATCHING */
void far *fn_0845_04ec(void far *name)
{
    void far *p;
    char hdr[0x10];
    register int size;
    register int n;

    if (fn_2365_063f(name) || fn_19ba_0086(name)) {
        p = fn_15a7_030c(g_4ea0, name);
        if (p) return p;
        fn_2279_025b(name, hdr, 0x10L);
        size = fn_1f36_0029(hdr);
        p = fn_15a7_00b0(g_4ea0, (long)size, name);
        if (!p) {
            while (fn_15a7_04b0(g_4ea0) <= (unsigned)(size + 0x10))
                fn_15a7_043c(g_4ea0);
            n = 0;
            while (!(p = fn_15a7_00b0(g_4ea0, (long)size, name))) {
                if (n++) fn_15a7_043c(g_4ea0);
                if (n > 2) fn_15a7_0004(g_4ea0, 15000L);
                fn_15a7_0501(g_4ea0);
            }
        }
        fn_2279_025b(name, p, (long)size);
        return p;
    }
    return name;
}

void fn_0845_0631(void far *p)
{
}

int fn_0845_0636(int n, int sides)
{
    int sum;
    register int s = sides;
    register int i;
    int r;

    sum = 0;
    if (s > 0 && n > 0)
        for (i = 0; i < n; i++) {
            r = (int)((long)rand() * s / 0x8000L) + 1;
            if (r > s) r -= s;
            sum += r;
        }
    return sum;
}

void fn_0845_068c(int x, int y, char far *name)
{
    void far *p;

    p = fn_0845_04ec(name);
    fn_1e9f_0002(x, y, p);
    fn_0845_0631(p);
    g_ab22 = x;
    g_ab20 = y;
    g_ab1c = name;
}

void fn_0845_06d6(int far *x, int far *y, char far * far *name)
{
    *x = g_ab22;
    *y = g_ab20;
    *name = g_ab1c;
}

char far *fn_0845_06f8(int id)
{
    char buf[0x200];
    char far *p;

    if (id == -1) return 0;
    p = fn_212a_014c(id & 0x4000 ? g_4d6c : g_4d68, id & 0x3fff);
    fn_2279_025b(p, buf, 0x200L);
    p = buf;
    if (p) {
        fn_212a_00e5(p, f_2b8c_0000[g_21e0]);
        p = f_2b8c_0000[g_21e0];
        fn_212a_0005(p, p);
        g_21e0 = (g_21e0 + 1) % 4;
    }
    return p;
}

/* NONMATCHING */
void fn_0845_07b3(char far *fmt, int x, int y, int c1, int c2, unsigned flags, ...)
{
    char buf[0xf0];
    va_list ap;

    if (!fmt) return;
    va_start(ap, flags);
    vsprintf(buf, fmt, ap);
    if (flags & 1) x -= fn_1e64_002b(buf) >> 1;
    if (flags & 2) x -= fn_1e64_002b(buf);
    if (flags & 4) {
        fn_1f6c_0006(buf, x - 1, y, 1, c2);
        fn_1f6c_0006(buf, x, y + 1, 1, c2);
    }
    if (flags & 8) {
        fn_1f6c_0006(buf, x - 1, y, 0xe3, c2);
        fn_1f6c_0006(buf, x, y + 1, 0xe3, c2);
    }
    fn_1f6c_0006(buf, x, y, c1, c2);
}

void fn_0845_08a5(void)
{
}

void fn_0845_08aa(void)
{
    fn_234e_0003(2);
    fn_1dbc_0017(0xe, 0, 0xe, 0, 0x16, 0x78, 0, g_4d70);
    fn_234e_0062();
}

void fn_0845_08d9(int delay)
{
    unsigned char pal[0x300];

    setmem(pal, 0x300, 0);
    fn_1ef2_0075(pal, delay, 0L);
    g_20d5 = 2;
}

void fn_0845_090f(int delay)
{
    fn_0845_1430(g_540e);
    fn_1ef2_0075(g_540e, delay, 0L);
    g_20d5 = 0;
}

void fn_0845_093a(void)
{
    fn_130a_028a();
    if (g_4bf8 != -1 && g_384c > g_4c02) fn_130a_0605();
    if ((g_806a & 0x800) || !(g_7fd6 & 4)) fn_0bbc_07ef();
    if ((g_806a & 0x4000) && !(g_7fd6 & 4) && (g_7fe1 == -1 || (g_7fdf << 6) != g_7fe1 || g_06d7))
        ovr_2cda_0052();
    fn_154c_0136();
    fn_0845_11b7();
}

char far *fn_0845_09a9(int b)
{
    int c;

    c = b;
    c &= 0x1f;
    if (c > 25) {
        c -= 26;
        sprintf(g_ab04, "A%c%d", c + 'A', b >> 5);
    } else
        sprintf(g_ab04, "%c%d", c + 'A', b >> 5);
    return g_ab04;
}

/* NONMATCHING */
void fn_0845_09f1(int n)
{
    void far *p;

    g_806a |= 0x200;
    if (g_7fb2[f_2803_1cfd[g_8048].type].shape != n) {
        p = fn_0845_04ec(g_7d82[n]);
        fn_1e9f_0002(0, 0, p);
        fn_0845_0631(p);
        g_ab1a = n;
    }
}

void fn_0845_0a5b(void)
{
    g_806a &= ~0x200;
    if (g_7fb2[f_2803_1cfd[g_8048].type].shape != g_ab1a)
        fn_1e9f_0002(g_8048 ? 10 : 0, g_8048 ? 10 : 0, fn_0845_04ec(fn_0845_0c08(g_8048)));
}

int fn_0845_0ac7(void)
{
    return g_8048;
}

/* NONMATCHING */
void fn_0845_0acf(int item)
{
    void far *p;
    register int it = item;
    register int off;

    if (it && (g_7fb2[f_2803_1cfd[it].type].flags & 0x80)) {
        fn_07bc_047f(-1, it, 0x400, 0, 0);
        if (f_2803_1cfd[it].flags & 0x8000) it = 0;
    }
    if (!it || (g_806a & 0x200))
        off = 0;
    else {
        off = 10;
        if (!f_2803_0045 || g_81fe)
            fn_0845_01c4(0, fn_0845_06f8(0x403e), fn_0845_06f8(g_7fb2[f_2803_1cfd[it].type].name));
    }
    g_8048 = it;
    p = fn_0845_04ec(fn_0845_0c08(it));
    fn_1e9f_0002(off, off, p);
    fn_0845_0631(p);
}

void fn_0845_0bb6(unsigned ticks)
{
    unsigned long end;

    end = g_384c + ticks;
    while (end > g_384c) fn_0845_093a();
}

void fn_0845_0be0(unsigned long t)
{
    while (t > g_384c) fn_0845_093a();
}

void fn_0845_0bf6(void)
{
    fn_2309_000c();
    exit(0);
}

char far *fn_0845_0c08(int it)
{
    struct ItemType far *t;
    int s;

    if (it) {
        t = &g_7fb2[f_2803_1cfd[it].type];
        if (t->flags & 0x200)
            s = t->shape + (f_2803_1cfd[it].flags & 0x1fff) - 1;
        else
            s = t->shape;
    } else
        s = 0;
    return g_7d82[s];
}

int fn_0845_0c7e(int b, int dir, int n, int far *out)
{
    register int cur = b;
    register int i;
    int nb;

    nb = fn_09aa_0183(cur, dir);
    *out = -1;
    for (i = 0; i < n; i++) {
        if (g_8203[cur].mon & 0x8000) {
            *out = cur;
            break;
        }
        if (g_531e[WALL(nb, dir ^ 2)] & 7) {
            *out = nb;
            break;
        }
        cur = nb;
        nb = fn_09aa_0183(cur, dir);
    }
    return i;
}

int fn_0845_0cf7(int b, int dir, int mask)
{
    if (g_8203[b].flags & 0x10) return 1;
    if (dir != -1) {
        if (mask & g_531e[WALL(b, dir ^ 2)]) return 1;
    } else
        for (dir = 0; dir < 4; dir++)
            if (mask & g_531e[WALL(b, dir)]) return 1;
    return 0;
}

void fn_0845_0d5e(struct Wsa far *wsa, int start, int end, int delay, int x, int y, void (far *cb)(struct Wsa far *w, int x, int y), void far *a, void far *b, int c, int restore)
{
    int done;
    int frame;
    int r;
    int fwd;
    unsigned long t0;
    int w, h, w2, h2;
    register int px;
    register int py;

    done = 0;
    t0 = g_384c;
    w = wsa->w;
    h = wsa->h;
    px = x;
    py = y;
    w2 = w;
    h2 = h;
    if (wsa) {
        if (x < 0) {
            px = 0;
            w2 += px;
        }
        if (y < 0) {
            py = 0;
            h2 += py;
        }
    }
    fwd = start > end ? 0 : 1;
    frame = start;
    while (done != 1) {
        g_3850 = delay;
        if (wsa || cb) fn_2279_025b(g_4d5a, fn_215f_001d(2), 0xfa00L);
        if (cb) cb(wsa, x, y);
        if (wsa) ovr_2dfd_002a(wsa, frame % wsa->frames, x, y, 2, 0x5000, g_4bec, g_4bf0);
        if (wsa || cb) {
            fn_1ebc_0111(px, py, px + w2, py + h2);
            fn_1dbc_0004(px, py, px, py, w2, h2, 2, 0);
            fn_1ebc_01ec();
        }
        do {
            if (a && b) {
                r = ovr_2d1b_003e(a, b, g_384c - t0, (long)c);
                if (!r && !wsa) return;
            }
        } while (g_3850);
        if (wsa) {
            if (fwd == 1) {
                if (++frame >= end) done = 1;
            } else {
                if (--frame < end) done = 1;
            }
        }
    }
    if (restore && (wsa || cb)) {
        fn_2279_025b(g_4d5a, fn_215f_001d(2), 0xfa00L);
        fn_1ebc_0111(px, py, px + w2, py + h2);
        fn_1dbc_0004(px, py, px, py, px + w2, py + h2, 2, 0);
        fn_1ebc_01ec();
    }
}

void fn_0845_0f72(void)
{
}

void fn_0845_0f77(void)
{
}

void fn_0845_0f7c(void)
{
}

void fn_0845_0f81(char far *fmt, ...)
{
}

/* NONMATCHING */
void fn_0845_0f86(unsigned char far *src, unsigned char far *dst, unsigned mask)
{
    register int i;
    int k;
    unsigned char far *s;
    unsigned char far *d;
    int v;

    if (!src) return;
    if (!dst) return;
    s = src;
    d = dst;
    fn_2279_025b(s, d, 6L);
    s += 6;
    d += 6;
    for (i = 2; i < 0x80; i++)
        for (k = 0; k < 3; k++) {
            v = *s & 0x3f;
            s++;
            if (mask & (1 << k)) v += (0x3f - v) >> 1;
            else v -= v >> 1;
            *d = v;
            d++;
        }
    fn_2279_025b(s, d, 0x180L);
}

int fn_0845_1036(void)
{
    return (int)(g_7fda & 0x30) >> 4;
}

int fn_0845_1044(int a, int b)
{
    return (int)(((long)b << 8) / a);
}

/* NONMATCHING */
int fn_0845_105c(int a, int b, unsigned long t, long total)
{
    char far *pa;
    char far *pb;
    char far *pc;
    char rgb[3];
    int changed;
    unsigned char pal[0x300];
    register int i;
    int v;

    pa = (char far *)&g_2fac[a * 3];
    pb = (char far *)&g_2fac[b * 3];
    pc = (char far *)g_540e + a * 3;
    for (i = 0, changed = i; i < 3; i++, pa++, pb++, pc++) {
        if (t < total) {
            v = (*pb & 0x3f) - (*pa & 0x3f);
            if (v) changed = 1;
            v = (*pa & 0x3f) + (int)(((long)v << 8) / total * t >> 8);
        } else {
            v = *pb;
            *pc = v;
            changed = 0;
        }
        rgb[i] = v;
    }
    memcpy(pal, g_2fac, 0x300);
    fn_1ef2_002f(pal, a, (unsigned char far *)rgb);
    return changed;
}

/* NONMATCHING */
void fn_0845_114d(int id, int flag)
{
    int old;

    if (g_20f4 == id || !id) {
        g_20f6 = 1;
        g_4bc8 = g_384c;
    }
    if (flag) {
        fn_130a_0784();
        if (!f_2803_0044) {
            fn_1ebc_00e7();
            old = fn_14b3_01fa(3);
            fn_1ebc_00fe();
            fn_14b3_0122(old);
        }
        g_20f6 = 0;
        fn_0bbc_070e(11, 0);
    }
}

/* NONMATCHING */
int fn_0845_11b7(void)
{
    int old;
    register int r;

    if (!g_20f6) return 0;
    r = fn_0845_105c(0xc0, 0xfc, g_384c - g_4bc8, 0x3cL);
    if (!r && !f_2803_0044) {
        old = fn_14b3_01fa(3);
        fn_1ebc_00e7();
        fn_14b3_0122(old);
        fn_1ebc_00fe();
        fn_0bbc_070e(11, 0);
        g_20f6 = 0;
    }
    return r;
}

int fn_0845_122b(struct Char far *c, int k)
{
    int i, n;

    for (n = i = 0; i < 4; i++)
        if (f_27dd_0000[k][9 + i] <= c->mp && f_27dd_0000[k][15 + i] < c->hp) n++;
    return n;
}

int fn_0845_1280(int ch, int cls, int i)
{
    if (f_27dd_0000[cls][9 + i] > f_2803_362d[ch].mp) {
        if (fn_154c_0057(0x4043, f_2803_362d[ch].wE, 1))
            fn_0845_01c4(6, fn_0845_06f8(0x4043), f_2803_362d[ch].name);
        return 1;
    }
    if (f_27dd_0000[cls][15 + i] >= f_2803_362d[ch].hp) {
        fn_0845_01c4(2, fn_0845_06f8(0x4179), f_2803_362d[ch].name);
        return 1;
    }
    return 0;
}

void fn_0845_1343(int b, unsigned mask, int c, int d, int e, int f)
{
    struct Emc s;

    if (!g_4bf6) {
        fn_0f28_032c((void far *)&s, (void far *)f_2803_3611);
        fn_0f28_035f((void far *)&s, b);
        s.regs[0] = mask;
        s.regs[1] = c;
        s.regs[2] = d;
        s.regs[3] = e;
        s.regs[4] = f;
        s.regs[5] = b;
        s.regs[6] = g_7fd8;
        if (mask & fn_2315_0018(s.ip[-1]))
            while (fn_0f28_04a0((void far *)&s));
    }
    fn_0845_046c(b);
}

void fn_0845_13d6(int b, unsigned mask)
{
    fn_0845_1343(b, mask, -1, 0, 0, 0);
}

long fn_0845_13f1(unsigned ao, unsigned as, unsigned bo, unsigned bs)
{
    unsigned long a, b;

    a = ((unsigned long)as << 4) + ao;
    b = ((unsigned long)bs << 4) + bo;
    return a - b;
}

void fn_0845_1430(unsigned char far *pal)
{
    fn_2279_025b(g_31ec, pal + 0x240, 12L);
}

void fn_0845_144e(void far *p)
{
    if (p) {
        if (fn_2365_063f(p) || fn_19ba_0086(p))
            fn_15a7_0210(g_4ea0, fn_15a7_030c(g_4ea0, p));
        fn_203b_0203(p);
    }
}

void fn_0845_14a6(char far *arg)
{
    char far *s;

    fn_2309_000c();
    fn_0845_1536();
    s = ovr_2d46_002f(" ", g_20db);
    sprintf(g_ad99, "%s %s", g_ae59, arg);
    if (g_ae57) {
        fn_2148_002c(g_aeaa[0] - 'A');
        fn_2148_014d(g_aeaa);
        fn_2148_014d(s + 2);
    }
    execl("LANDS.EXE", "LANDS.EXE", g_ad99, (char *)0);
}

void fn_0845_1531(void)
{
}

void fn_0845_1536(void)
{
    g_ab0a.h.ah = 2;
    g_ab0a.x.dx = 0x1900;
    g_ab0a.h.bh = 0;
    int86(0x10, &g_ab0a, &g_ab0a);
}

int fn_0845_155d(int b)
{
    int next;
    struct Monster far *m;
    int far *pn;
    register int o;
    register int n;

    n = 0;
    o = g_8203[b].mon;
    while (o) {
        pn = fn_080e_000b(o);
        next = *pn;
        if (o & 0x8000) {
            m = &f_2803_15fa[o & 0x7fff];
            n++;
            fn_0d6c_0995(m, 14);
            fn_0845_046c(m->block);
            fn_0d6c_0742(m, 0, 0);
        }
        o = next;
    }
    return n;
}

void fn_0845_15d9(int a)
{
    if (!(g_7fd6 & 1) && !g_4d66 && g_20d3 && g_7fc4) ovr_2cda_0061(a);
}

void fn_0845_1605(void)
{
    if (g_81fe) {
        fn_1e9a_000b(4, 0xb, 0x7c, 0x1c, 0x2d);
        fn_1e9a_000b(5, 0x55, 0x7b, 0xe9, 0x36);
    } else {
        fn_1e9a_000b(4, 0xb, 0x7c, 0x1c, 9);
        fn_1e9a_000b(5, 0x55, 0x7b, 0xe9, 0x12);
    }
}
