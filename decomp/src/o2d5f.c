/* o2d5f: dialogue/scene mode (enter/leave, TIM animation slots and their memory, EMC opcodes for scenes) */
#include <stdio.h>
#include <mem.h>
#include "lol.h"

struct TimHdr;
struct Pos3 { unsigned char x, y, w; };
struct WsaRef { char pad[0xe]; char far *p0e; char far *p12; };

struct Scene { char on, mode, c46, c47, c48, c49, c4a; int x, y, w, h; };   /* 2803:0044 */
extern struct Scene far f_2803_0044;
#define S f_2803_0044
extern long far f_2803_0000[];
extern int far f_2803_3625[];
extern void far * far f_2803_00a6[];
extern char g_81fe, g_7fe3, g_7fdc, g_81dc, g_81de;
extern unsigned g_7fd6, g_806a, g_804c;
extern int g_7fd0, g_7fdf;
extern int g_20f6, g_20f4, g_20d5, g_20ec, g_1216, g_804a, g_8048;
extern int g_4bfa, g_4bf8, g_4b92, g_3649, g_3711;
extern int g_4b74, g_4b72, g_4b70, g_4b6e;
extern int g_1f85, g_1f95, g_1f87, g_1f89;
extern unsigned g_ad8b, g_ad8d, g_ad8f, g_ad91;
extern long g_2124, g_2128, g_212c, g_2130;
extern unsigned long g_384c;
extern void far *g_4d56, far *g_4d5a;
extern char far *g_4edc;
extern unsigned char far *g_adea;
extern int far *g_7fcc;
extern void far *g_7fbc;
extern void far *g_4b66, far *g_4b6a;
extern struct Anim g_4ee0[];
extern struct TimHdr far *g_20fc[];
extern struct Pos3 g_1218[];
extern char g_ad99[], g_121e[], g_1224[];

void fn_0a21_022b(int ch);
void fn_09aa_0007(int a, int b);
void fn_0bbc_058a(int a);
void fn_231c_0048(int a);
void fn_231c_0008(int a);
void far *fn_215f_0003(int p);
void fn_2279_025b(void far *d, void far *s, long n);
char far *fn_2279_02b5(void far *p);
void far *fn_2037_0002(void far *p, long off);
void fn_0bbc_070e(int a, int b);
int fn_1e74_000f(int page);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_1e59_001d(int x1, int y1, int x2, int y2, int c);
void fn_0845_0008(int a, int b, int c, int d, int e, int f, int g);
void fn_1e9a_000b(int a, int b, int c, int d, int e);
int fn_14b3_01fa(int a);
int fn_14b3_0122(int a);
void fn_0a21_0a0c(void);
void far *fn_0845_04ec(void far *name);
void fn_1fd6_000a(int page, void far *p, int x, int y, int a, int flags);
void fn_0845_0631(void far *p);
void fn_130a_0784(void);
int ovr_2d74_0025(void);
void fn_0845_1605(void);
void ovr_2ceb_002a(int x, int y, int w, int h, int e);
void ovr_2ceb_0020(void);
void fn_0ca0_097b(void);
void fn_1ef2_0075(char far *p, int a, long b);
void fn_0845_1430(void far *p);
void fn_0638_018b(struct TimHdr far *t);
void fn_0845_08d9(int n);
void fn_0845_03d4(int n);
void ovr_2d2c_0043(void);
void fn_0845_035b(unsigned char far *src, int lvl, int idx);
long fn_0845_13f1(void far *a, void far *b);
char far *ovr_2dfd_0020(char far *name, void far *buf, long size, int flags, void far *pal);
long ovr_2cef_003e(void far *p);
void far *fn_203b_0007(long size, int flags);
void ovr_2dfd_0025(void far *p);
int ovr_2cef_0020(void far *p);
int ovr_2cef_0025(void far *p);
void fn_1ebc_0111(int x1, int y1, int x2, int y2);
void ovr_2dfd_002a(void far *p, int a, int b, int c, int d, int e);
void fn_1ebc_01ec(void);
void fn_0d6b_000f(void);
void fn_0845_144e(void far *p);
void fn_070c_00cf(int who, int cls, long exp);
int fn_2315_0018(int a);
unsigned fn_1f6a_0002(int w, int h);
void fn_2096_014b(int x, int y, int w, int h, void far *p, int page);
void fn_2096_0000(int x, int y, int w, int h, void far *p, int page);
void fn_1dbc_0004(int a, int b, int c, int d, int e, int f, int g, int h);
int fn_09aa_0183(int a, int b);
void fn_0845_13d6(int b, unsigned mask);
int fn_0845_03b4(int a, int b, int c, int d);
void fn_2169_062e(void);
char far *fn_0845_0c08(int item);
void fn_0845_068c(int x, int y, char far *name);
void far *fn_1f2d_0002(void far *p);
char far *fn_0845_06f8(int id);
unsigned fn_1e64_002b(char far *s);
void fn_1f6c_0006(char far *s, int x, int y, int c1, int c2);
void fn_1b63_0004(int x, int y, int w, int h, int a);
int fn_2169_060c(void);
int fn_2169_0790(void);
void fn_163d_0004(void);
void fn_2169_0945(int key);
void fn_0bbc_07ef(void);
void fn_0845_09f1(int n);
void fn_0845_0a5b(void);
void fn_1e54_0001(int x1, int y1, int x2, int y2, int c);

int ovr_2d5f_008e(int slot);
void ovr_2d5f_00f7(int mode);
void ovr_2d5f_013d(void);
void ovr_2d5f_0133(int a);
void ovr_2d5f_012e(void);
void ovr_2d5f_0142(int a);
void ovr_2d5f_0020(int x, int y, int w, int h, int e);
void ovr_2d5f_0025(void);

static void partyflags(int on)
{
    struct Char far *p;
    int f;
    int c;
    int i;

    p = f_2803_362d;
    for (i = 0; i < 4; i++, p++) {
        if (!(p->flags & 1)) continue;
        if (on) p->flags |= 0x2000; else p->flags &= 0xdfff;
        if (on && !g_81fe) {
            c = g_7fe3;
            g_7fe3 = 0x63;
            f = g_7fd6;
            g_7fd6 = f & 0xfffd;
            fn_0a21_022b(i);
            g_7fd6 = f;
            g_7fe3 = c;
        } else {
            fn_0a21_022b(i);
        }
    }
}

int ovr_2d5f_002f(unsigned f)
{
    int i;

    if (S.mode) return 0;
    S.c48 = ((f & 2) ? 1 : 0) + 1;
    partyflags(1);
    for (i = 0x4c; i <= 0x54; i++) {
        if (!(f & 2) || i < 0x4f) fn_09aa_0007(i, 3);
        else fn_09aa_0007(i, 2);
    }
    return 1;
}

int ovr_2d5f_0034(void)
{
    int i;

    S.c48 = 0;
    if (!S.mode)
        for (i = 0x4c; i <= 0x54; i++) fn_09aa_0007(i, 2);
    partyflags(0);
    return 1;
}

void ovr_2d5f_0039(void)
{
    S.on = 1;
    if (!g_81fe && !(S.mode & 2)) fn_0bbc_058a(1);
    fn_231c_0048(2);
}

void ovr_2d5f_003e(void)
{
    S.on = 0;
    fn_231c_0008(2);
}

int ovr_2d5f_0043(void)
{
    return S.on;
}

void ovr_2d5f_0048(void)
{
    if (!S.c4a) {
        fn_2279_025b(fn_215f_0003(5), g_4d56, 0xfa00L);
        S.c4a = 1;
    }
}

void ovr_2d5f_004d(void)
{
    char far *lo;
    char far *hi;
    int i;

    if (S.c4a == 1) {
        lo = fn_2279_02b5(fn_215f_0003(5));
        hi = fn_2279_02b5(fn_2037_0002(lo, g_2128));
        for (i = 0; i < 6; i++)
            if ((unsigned long)g_4ee0[i].wsa >= (unsigned long)lo && (unsigned long)g_4ee0[i].wsa <= (unsigned long)hi)
                ovr_2d5f_008e(i);
        fn_2279_025b(g_4d56, fn_215f_0003(5), 0xfa00L);
    }
    S.c4a = 0;
}

void ovr_2d5f_0052(int mode, int page)
{
    int old;
    void far *shp;
    int i;

    if (mode) {
        fn_0bbc_070e(0xb, 0);
        g_20f6 = 0;
        old = fn_1e74_000f(page);
        fn_1ebc_00e7();
        fn_1e59_001d(0, 0x80, 0x13f, 0xc7, 1);
        fn_0845_0008(0, 0x81, 0x140, 0x47, 0x88, 0xfb, -1);
        fn_0845_0008(1, 0x82, 0x13e, 0x45, 0x88, 0xfb, 0xfc);
        fn_1ebc_00fe();
        fn_1e9a_000b(5, 8, 0x83, 0x130, 0x42);
        fn_1e9a_000b(4, 1, 0x85, 0x26, 0x3c);
        fn_14b3_01fa(4);
        g_7fd6 |= 2;
        S.mode = mode;
        fn_0a21_0a0c();
        if (!g_81fe && !(mode & 2)) {
            for (i = 0; i < ovr_2d74_0025(); ) {
                g_4bfa = 2;
                g_4bf8 = i;
                shp = fn_0845_04ec(f_2803_00a6[0x58]);
                fn_1ebc_00e7();
                fn_1fd6_000a(0, shp, f_2803_3625[g_4bf8] + 8, 0x8e, 0, 0);
                fn_1ebc_00fe();
                fn_0845_0631(shp);
                fn_130a_0784();
                i++;
            }
        }
        fn_1e74_000f(old);
    } else {
        ovr_2d5f_00f7(1);
        ovr_2d5f_013d();
        fn_0845_1605();
        fn_14b3_01fa(4);
        fn_1ebc_00e7();
        fn_14b3_01fa(4);
        fn_1ebc_00fe();
    }
    S.mode = mode;
    S.c46 = 1;
}

void ovr_2d5f_0057(int mode)
{
    if (S.c46) {
        fn_130a_0784();
        S.mode = mode;
        fn_0a21_0a0c();
        if (S.mode) {
            fn_1e9a_000b(4, 0xb, 0x7c, 0x1c, 0x2d);
            fn_1e9a_000b(5, 0x55, 0x7b, 0xe9, 0x36);
            g_1f85 = 0xfc;
            g_1f95 = 0xfc;
            g_1f87 = 0;
            g_1f89 = 0;
            g_7fd6 &= ~2;
        } else {
            fn_14b3_0122(5);
            fn_1ebc_00e7();
            fn_1e59_001d(g_ad8d, g_ad8b, g_ad8d + g_ad8f - 2, g_ad8b + g_ad91 - 2, g_3711);
            fn_14b3_01fa(4);
            fn_1ebc_00fe();
            g_1f87 = 0;
            g_1f89 = 0;
            ovr_2d5f_00f7(0);
        }
    }
    S.c46 = 0;
}

void ovr_2d5f_005c(int x, int y, int w, int h, int e)
{
    ovr_2ceb_002a(x, y, w, h, e);
    S.x = x;
    S.y = y;
    S.w = w;
    S.h = h;
}

void ovr_2d5f_0061(void)
{
    if (S.w + S.h) {
        ovr_2ceb_0020();
        S.x = 0;
        S.y = 0;
        S.w = 0;
        S.h = 0;
        g_20ec = 0;
    }
}

void ovr_2d5f_0066(int a)
{
    if (a) {
        g_7fd6 |= 5;
        ovr_2d5f_0133(0);
    } else {
        g_7fd6 |= 1;
    }
    S.c47 = 1;
    S.mode = a;
    fn_0a21_0a0c();
    fn_0ca0_097b();
}

void ovr_2d5f_006b(int a)
{
    if (a) {
        g_7fd6 &= ~5;
        ovr_2d5f_012e();
    } else {
        g_7fd6 &= ~1;
    }
    S.c47 = 0;
    fn_0ca0_097b();
}

void ovr_2d5f_0070(int a, int b, int c, int d, int e, int f)
{
    ovr_2d5f_0039();
    if (a) {
        if (c) ovr_2d5f_0066(1);
        if (!d) g_7fdc = 0;
        if (b) ovr_2d5f_0052(a, 0);
        if (f) {
            fn_1ef2_0075(g_4edc, 10, 0L);
            g_20d5 = 0;
        }
        ovr_2d5f_005c(0, 0, 0x140, 0x82, e);
    } else {
        if (c) ovr_2d5f_0066(a);
        if (!d) g_7fdc = 0;
        ovr_2d5f_002f(e);
        if (f) {
            fn_2279_025b(g_adea + 0x180, g_4edc + 0x180, 0x180L);
            fn_0845_1430(g_4edc);
            fn_1ef2_0075(g_4edc, 10, 0L);
            g_20d5 = 0;
        }
        if (b) ovr_2d5f_0052(a, 0);
        ovr_2d5f_005c(0x70, 0, 0xb0, 0x78, e);
    }
}

int ovr_2d5f_0075(int a, int b, int c, int d)
{
    int save;
    int i;

    if (!S.on) return 0;
    ovr_2d5f_003e();
    if (S.c46) ovr_2d5f_0057(S.mode);
    if (S.c47) ovr_2d5f_006b(S.mode);
    save = S.mode;
    S.mode = 0;
    fn_0a21_0a0c();
    ovr_2d5f_0061();
    S.mode = save;
    if (c) {
        for (i = 0; i < 6; i++) ovr_2d5f_008e(i);
        for (i = 0; i < 10; i++)
            if (g_20fc[i]) {
                fn_0638_018b(g_20fc[i]);
                g_20fc[i] = 0;
            }
    }
    ovr_2d5f_0034();
    if (a) {
        if ((g_20d5 != 2 && g_20d5 != 1) || (g_20d5 == 1 && S.mode)) {
            if (S.mode) fn_0845_08d9(10);
            else fn_0845_03d4(10);
        }
        S.mode = 0;
        fn_0a21_0a0c();
        if (b) ovr_2d2c_0043();
        fn_0845_035b(g_adea, g_81dc, g_81de);
    } else if (b) {
        S.mode = 0;
        fn_0a21_0a0c();
        ovr_2d2c_0043();
    } else {
        S.mode = 0;
        fn_0a21_0a0c();
    }
    g_7fdc = d;
    return 1;
}

void ovr_2d5f_007a(struct WsaRef far *old, struct WsaRef far *w)
{
    long d;

    d = fn_0845_13f1(old->p0e, old);
    w->p0e = fn_2279_02b5(fn_2037_0002(w, d));
    d = fn_0845_13f1(old->p12, old);
    if (d > 0) w->p12 = fn_2279_02b5(fn_2037_0002(w, d));
    else w->p12 = 0;
}

int ovr_2d5f_007f(int slot, long n, long far *pos, long max, void far *base)
{
    char far *p;

    if (n + *pos > max) return 0;
    p = fn_2279_02b5(fn_2037_0002(base, *pos));
    movmem(g_4ee0[slot].wsa, p, (unsigned)n);
    ovr_2d5f_007a((struct WsaRef far *)g_4ee0[slot].wsa, (struct WsaRef far *)p);
    g_4ee0[slot].wsa = p;
    *pos += n;
    return 1;
}

char far *ovr_2d5f_0084(int slot, char far *name, int x, int y, int delay, unsigned flags)
{
    long size;
    long sz;
    void far *mem;
    struct Anim far *a;

    {
        int f;

        f = 0;
        a = &g_4ee0[slot];
        a->x = x;
        a->y = y;
        a->ce = delay;
        a->flags = flags;
        a->cc = 0;
        a->c14 = -1;
        f |= (flags & 0x10) ? 2 : 0;
        f |= (flags & 8) ? 1 : 0;
        sz = 0xfa00;
        fn_2279_025b(fn_215f_0003(5), g_4d5a, sz);
        sprintf(g_ad99, g_121e, name, g_1224);
        a->wsa = ovr_2dfd_0020(g_ad99, fn_215f_0003(5), 0xfa00L, f, g_4edc);
        if (a->wsa == 0) return 0;
    }
    {
        int ok;
        ok = 0;
        size = (ovr_2cef_003e(a->wsa) + 15) & ~15L;
        if (flags & 0x20) ok = ovr_2d5f_007f(slot, size, &g_2124, 0xfa00L, fn_215f_0003(3));
        if (!ok && (flags & 0x40)) ok = ovr_2d5f_007f(slot, size, &g_212c, 0x9600L, fn_215f_0003(7));
        if (!ok && (flags & 0x80)) {
            sz = g_2128;
            ok = ovr_2d5f_007f(slot, size, &g_2128, g_2130, fn_215f_0003(5));
        }
        if (!ok) {
            mem = fn_203b_0007(size, 0x30);
            if (mem != 0) {
                fn_2279_025b(a->wsa, mem, size);
                ovr_2d5f_007a((struct WsaRef far *)a->wsa, mem);
                a->wsa = mem;
            } else {
                ovr_2dfd_0025(a->wsa);
                return 0;
            }
        }
    }
    fn_2279_025b(g_4d5a, fn_215f_0003(5), sz);
    if (flags & 1) {
        if (g_20d5 != 1) fn_0845_03d4(10);
        fn_2279_025b(g_adea + 0x180, g_4edc + 0x180, 0x180L);
    } else if (flags & 2) {
        fn_0845_08d9(10);
    }
    if (flags & 7) {
        fn_1ebc_0111(x, y, x + ovr_2cef_0020(a->wsa), y + ovr_2cef_0025(a->wsa));
        ovr_2dfd_002a(a->wsa, 0, x, y, 0, 0);
        fn_1ebc_01ec();
    }
    if (flags & 3) {
        fn_0845_1430(g_4edc);
        fn_1ef2_0075(g_4edc, 10, 0L);
        g_20d5 = 0;
    }
    fn_0d6b_000f();
    ovr_2cef_003e(a->wsa);
    return a->wsa;
}

int ovr_2d5f_0089(char far *wsa, long n, long far *pos, void far *base)
{
    char far *lo;
    char far *hi;
    char far *src;
    long off;
    long len;
    int i;

    lo = fn_2279_02b5(base);
    hi = fn_2279_02b5(fn_2037_0002(lo, *pos));
    if (wsa != 0) {
        if ((unsigned long)wsa < (unsigned long)lo || (unsigned long)wsa > (unsigned long)hi) return 0;
        off = fn_0845_13f1(wsa, lo);
        src = fn_2279_02b5(fn_2037_0002(wsa, n));
        len = *pos - off - n;
        movmem(src, wsa, (unsigned)len);
        lo = fn_2279_02b5(src);
        for (i = 0; i < 6; i++)
            if ((unsigned long)g_4ee0[i].wsa >= (unsigned long)lo && (unsigned long)g_4ee0[i].wsa <= (unsigned long)hi)
                g_4ee0[i].wsa = fn_2037_0002(g_4ee0[i].wsa, -n);
        *pos -= n;
    }
    return 1;
}

int ovr_2d5f_008e(int slot)
{
    struct Anim far *a;
    long size;
    int ok;

    a = &g_4ee0[slot];
    if (a->wsa != 0) {
        size = (ovr_2cef_003e(a->wsa) + 15) & ~15L;
        ovr_2dfd_0025(a->wsa);
        ok = ovr_2d5f_0089(a->wsa, size, &g_2124, fn_215f_0003(3));
        if (!ok) ok = ovr_2d5f_0089(a->wsa, size, &g_212c, fn_215f_0003(7));
        if (!ok) ok = ovr_2d5f_0089(a->wsa, size, &g_2128, fn_215f_0003(5));
        if (!ok) fn_0845_144e(a->wsa);
        a->wsa = 0;
        a->cc = 0;
        setmem(a, 0xb5, 0);
        return 1;
    }
    return 0;
}

int ovr_2d5f_0093(void)
{
    ovr_2d5f_0048();
    return 1;
}

int ovr_2d5f_0098(void)
{
    ovr_2d5f_004d();
    return 1;
}

int ovr_2d5f_009d(struct EmcState far *s)
{
    ovr_2d5f_0052(ARG(s, 0), ARG(s, 1));
    return 1;
}

int ovr_2d5f_00a2(struct EmcState far *s)
{
    ovr_2d5f_0057(ARG(s, 0));
    return 1;
}

int ovr_2d5f_00a7(struct EmcState far *s)
{
    ovr_2d5f_005c(ARG(s, 0), ARG(s, 1), ARG(s, 2), ARG(s, 3), ARG(s, 4));
    return 1;
}

int ovr_2d5f_00ac(void)
{
    ovr_2d5f_0061();
    return 1;
}

int ovr_2d5f_00b1(struct EmcState far *s)
{
    ovr_2d5f_0066(ARG(s, 0));
    return 1;
}

int ovr_2d5f_00b6(struct EmcState far *s)
{
    ovr_2d5f_006b(ARG(s, 0));
    return 1;
}

int ovr_2d5f_00bb(struct EmcState far *s)
{
    ovr_2d5f_0070(ARG(s, 0), ARG(s, 1), ARG(s, 2), ARG(s, 3), ARG(s, 4), ARG(s, 5));
    return 1;
}

int ovr_2d5f_00c0(struct EmcState far *s)
{
    return ovr_2d5f_0075(ARG(s, 0), ARG(s, 1), ARG(s, 2), ARG(s, 3));
}

int ovr_2d5f_00c5(void)
{
    ovr_2d5f_0039();
    return 1;
}

int ovr_2d5f_00ca(void)
{
    ovr_2d5f_003e();
    return 1;
}

int ovr_2d5f_00cf(void)
{
    return ovr_2d5f_0043();
}

int ovr_2d5f_00d4(struct EmcState far *s)
{
    int cls;
    int ch;
    int lvl;

    ch = ARG(s, 0);
    cls = ARG(s, 1);
    lvl = f_2803_362d[ch].skill[cls];
    fn_070c_00cf(ch, cls, f_2803_0000[lvl] - f_2803_362d[ch].exp[cls]);
    return f_2803_362d[ch].skill[cls] - lvl;
}

int ovr_2d5f_00d9(struct EmcState far *s)
{
    int slot;

    slot = ARG(s, 1);
    return ovr_2d5f_0084(slot, (char far *)s->dat->text + fn_2315_0018(s->dat->text[ARG(s, 0)]),
                         ARG(s, 2), ARG(s, 3), ARG(s, 4), ARG(s, 5)) ? 1 : 0;
}

int ovr_2d5f_00de(struct EmcState far *s)
{
    return ovr_2d5f_008e(ARG(s, 0));
}

int ovr_2d5f_00e3(struct EmcState far *s)
{
    return ovr_2d5f_002f(ARG(s, 0));
}

int ovr_2d5f_00e8(void)
{
    return ovr_2d5f_0034();
}

int ovr_2d5f_00ed(struct EmcState far *s)
{
    long *p;

    switch (ARG(s, 0)) {
    case 2: p = &g_2124; break;
    case 6: p = &g_212c; break;
    case 4: p = &g_2128; break;
    }
    *p = (long)ARG(s, 1) * 320;
    return 1;
}

void ovr_2d5f_00f2(void)
{
    if (g_20d5 != 2) fn_0845_03d4(10);
    ovr_2d2c_0043();
    fn_0845_035b(g_adea, g_81dc, g_81de);
    g_20d5 = 0;
}

void ovr_2d5f_00f7(int mode)
{
    int old;
    unsigned long t;
    unsigned sz;
    int y;

    if (!g_81fe) {
        fn_1ebc_00e7();
        if (!mode) fn_14b3_0122(fn_14b3_01fa(4));
        fn_1ebc_00fe();
        ovr_2d5f_0142(1);
        return;
    }
    sz = fn_1f6a_0002(0x140, 0x28);
    if (mode == 1) {
        g_4b66 = fn_203b_0007((unsigned long)sz, g_4b92);
        g_4b6a = fn_203b_0007((unsigned long)sz, g_4b92);
        fn_2279_025b(g_7fcc, g_4b6a, (unsigned long)sz);
        fn_1ebc_00e7();
        fn_2096_014b(0x50, 0x8e, 0xf0, 0x25, g_7fcc, 0);
        fn_1ebc_00fe();
        fn_2279_025b(g_7fcc, g_4b66, (unsigned long)sz);
        fn_2279_025b(g_4b6a, g_7fcc, (unsigned long)sz);
    } else {
        fn_1ebc_00e7();
        fn_14b3_0122(fn_14b3_01fa(4));
        fn_1ebc_00fe();
        old = fn_1e74_000f(2);
        fn_2279_025b(g_7fcc, g_4b6a, (unsigned long)sz);
        fn_2279_025b(g_4b66, g_7fcc, (unsigned long)sz);
        fn_2096_0000(0x50, 0x8e, 0xf0, 0x25, g_7fcc, g_3649);
        for (y = 0xb1; y > 0x8d; y--) {
            t = g_384c + 1;
            fn_1ebc_00e7();
            fn_1dbc_0004(0x53, y, 0x53, y - 1, 0xeb, 3, 0, 0);
            fn_1dbc_0004(0x53, y + 1, 0x53, y + 1, 0xeb, 1, 2, 0);
            fn_1ebc_00fe();
            while (t > g_384c) ;
        }
        fn_2279_025b(g_4b6a, g_7fcc, (unsigned long)sz);
        fn_1e74_000f(old);
        fn_0845_144e(g_4b66);
        fn_0845_144e(g_4b6a);
        g_7fd6 &= ~2;
    }
}

void ovr_2d5f_013d(void)
{
    void far *mem;
    int old;
    unsigned long t;
    int y;
    unsigned sz;

    if (!g_81fe) {
        ovr_2d5f_0142(0);
        fn_14b3_01fa(3);
        return;
    }
    fn_1ebc_00e7();
    g_20f6 = 0;
    g_20f4 = 0;
    fn_0bbc_070e(0xb, 0);
    fn_14b3_0122(fn_14b3_01fa(3));
    fn_1ebc_00fe();
    sz = fn_1f6a_0002(0x140, 10);
    old = fn_1e74_000f(2);
    mem = fn_203b_0007((unsigned long)sz, g_4b92);
    fn_2279_025b(g_7fcc, mem, (unsigned long)sz);
    fn_1ebc_00e7();
    fn_1dbc_0004(0x53, 0x8c, 0, 0, 0xeb, 3, 0, 2);
    fn_1ebc_00fe();
    for (y = 0x8c; y < 0xb1; y++) {
        t = g_384c + 1;
        fn_1ebc_00e7();
        fn_1dbc_0004(0, 0, 0x53, y, 0xeb, 3, 2, 0);
        fn_1ebc_00fe();
        while (t > g_384c) ;
    }
    fn_2279_025b(mem, g_7fcc, (unsigned long)sz);
    fn_0845_144e(mem);
    fn_1e74_000f(old);
    g_7fd6 |= 2;
}

void ovr_2d5f_00fc(int a)
{
    ovr_2d5f_0039();
    ovr_2d5f_0020(0x70, 0, 0xb0, 0x78, a);
    g_7fd6 |= 3;
    ovr_2d5f_00f7(1);
    ovr_2d5f_013d();
    fn_0845_1605();
    ovr_2d5f_002f(a);
}

void ovr_2d5f_0101(int a)
{
    int i;

    ovr_2d5f_0034();
    ovr_2d5f_00f7(0);
    ovr_2d5f_0025();
    for (i = 0; i < 6; i++) ovr_2d5f_008e(i);
    g_7fd6 = 0;
    if (a == 1) ovr_2d5f_00f2();
    fn_2169_062e();
    ovr_2d5f_003e();
}

int ovr_2d5f_002a(void)
{
    int b;

    b = fn_09aa_0183(g_7fd0, g_7fdf);
    fn_0845_13d6(b, 0x40);
    if (!g_20ec || !fn_0845_03b4(g_4b74, g_4b72, g_4b70, g_4b6e)) {
        fn_2169_062e();
        g_20ec = 0;
    }
    return 1;
}

void ovr_2d5f_0020(int x, int y, int w, int h, int e)
{
    ovr_2ceb_002a(x, y, w, h, e);
    g_4b74 = x;
    g_4b72 = y;
    g_4b70 = x + w;
    g_4b6e = y + h;
    fn_0845_068c(g_8048 ? 10 : 0, g_8048 ? 10 : 0, fn_0845_0c08(g_8048));
    g_804a = -1;
    if (w == 0x140) {
        ovr_2d5f_0133(0);
        g_1216 = 1;
    }
}

void ovr_2d5f_0025(void)
{
    ovr_2ceb_0020();
    g_4b74 = 0;
    g_4b72 = 0;
    g_4b70 = 0;
    g_4b6e = 0;
    g_20ec = 0;
    if (g_1216) {
        ovr_2d5f_012e();
        g_1216 = 0;
    }
}

int ovr_2d5f_0106(struct EmcState far *s)
{
    void far *font;
    struct Pos3 *p;
    int x;
    int y;
    int old;
    int w;
    int tw;

    old = fn_1e74_000f(0);
    font = fn_1f2d_0002(g_7fbc);
    p = &g_1218[ARG(s, 0)];
    x = p->x * 2;
    y = p->y;
    w = p->w;
    tw = fn_1e64_002b(fn_0845_06f8(0x4033));
    fn_1ebc_00e7();
    fn_0845_0008(x - w - tw, y - 9, tw + w, 9, 0x88, 0xfb, 0xfc);
    fn_1f6c_0006(fn_0845_06f8(0x4033), x - (w >> 1) - tw + 1, y - 7, 0x90, 0);
    fn_1ebc_00fe();
    if (ARG(s, 1) == 1) {
        fn_1ebc_00e7();
        fn_1b63_0004(x - w - tw + 1, y - 8, tw + w - 2, 7, 1);
        fn_1ebc_00fe();
    }
    fn_1e74_000f(old);
    fn_1f2d_0002(font);
    return 1;
}

int ovr_2d5f_010b(struct EmcState far *s)
{
    int k;

    if (fn_2169_060c()) {
        k = fn_2169_0790();
        fn_163d_0004();
        if (k && !(k & 0x800)) {
            if (ARG(s, 0)) {
                fn_2169_0945(k);
                g_20ec = 1;
            } else {
                fn_2169_062e();
            }
            return 1;
        }
    }
    return 0;
}

int ovr_2d5f_0110(struct EmcState far *s)
{
    ovr_2d5f_00fc(ARG(s, 0));
    return 1;
}

int ovr_2d5f_0115(struct EmcState far *s)
{
    ovr_2d5f_0101(ARG(s, 0));
    return 1;
}

int ovr_2d5f_011a(struct EmcState far *s)
{
    int v;

    v = ARG(s, 0);
    if (v) g_804c |= 0x80;
    else g_804c &= ~0x80;
    ovr_2d5f_00f7(v);
    return 1;
}

int ovr_2d5f_011f(void)
{
    ovr_2d5f_013d();
    return 1;
}

int ovr_2d5f_0124(struct EmcState far *s)
{
    ovr_2d5f_0020(ARG(s, 0), ARG(s, 1), ARG(s, 2), ARG(s, 3), ARG(s, 4));
    return 1;
}

int ovr_2d5f_0129(void)
{
    ovr_2d5f_0025();
    return 1;
}

void ovr_2d5f_012e(void)
{
    g_806a |= 0x400;
    g_81de = -1;
    fn_0bbc_07ef();
}

void ovr_2d5f_0133(int a)
{
    g_806a &= ~0x400;
    if ((g_806a & 0x800) && a) {
        fn_1ebc_0111(0x123, 0x38, 0x140, 0x50);
        fn_1fd6_000a(0, fn_0845_04ec(f_2803_00a6[0x2b]), 0x123, 0x38, 0, 0);
        fn_1ebc_01ec();
        g_81de = 8;
    }
}

int ovr_2d5f_0138(struct EmcState far *s)
{
    if (ARG(s, 0) == 1) fn_0845_09f1(0x85);
    else fn_0845_0a5b();
    return 1;
}

void ovr_2d5f_0142(int a)
{
    int c;
    int old;

    if (ovr_2d74_0025() == 1) return;
    c = a ? 0xd4 : 1;
    old = fn_1e74_000f(0);
    fn_1ebc_00e7();
    fn_1e54_0001(f_2803_3625[g_7fe3], 0x8f, f_2803_3625[g_7fe3] + 0x41, 0xb0, c);
    fn_1ebc_00fe();
    fn_1e74_000f(old);
}
