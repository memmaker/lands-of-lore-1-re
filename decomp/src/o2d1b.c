/* o2d1b: mist/fog spells: palette fades, wall/monster effects */
#include "lol.h"

extern int g_0b44;
extern char g_0b62[];
extern char g_0b6a[];
extern char g_0b77[];
extern char g_0b84[];
extern char g_0b8d[];
extern char g_0baa[];
extern char g_0bb2[];
extern char g_0bcf[];
extern char g_0bf2[];
extern char g_0bfe[];
extern int g_0b46[];
extern char g_0b4e[];
extern char g_0b53[];
extern char g_0b58[];
extern char g_0b5d[];
extern void far * far f_27b1_0000[];
extern int g_4b92;
extern char g_7fe5;
extern int g_8080;
extern unsigned char far *g_4bcc;
extern unsigned char far *g_adea;
extern unsigned char far *g_540e;
extern char g_81dc, g_81de;
extern long g_369f;
extern void far *g_4d56;
extern void far *g_4d5a;
extern unsigned long g_384c;
extern int g_7fd0, g_7fdf;
extern char g_53be[];
extern char g_536e[];
void ovr_2d46_0020(char far *name, int page);
void far *ovr_2d46_0025(int a, int b, int c);
void fn_203b_0203(void far *p);
int fn_1809_0000(char far *name, int mode);
long fn_1809_084d(int fh, void far *buf, long n);
void fn_1809_058d(int fh);
void fn_1ef2_02c0(char far *name, void far *pal);
void fn_1ef2_001c(void far *pal);
void fn_0845_02c6(unsigned char far *src, unsigned char far *dst, int s, int i);
void far *fn_215f_0003(int page);
void far *fn_215f_001d(int page);
int far *ovr_2dfd_0020(char far *name, void far *buf, long size, int flags, void far *pal);
void ovr_2dfd_0025(void far *p);
void ovr_2ce1_007f(char far *msg);
int fn_1e74_000f(int page);
void fn_231c_0048(int t);
void fn_231c_0008(int t);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_0845_15d9(int a);
void far fn_2279_025b(void far *src, void far *dst, long n);
void fn_0bbc_0744(int a, int b, int c, int d);
void fn_067a_0401(int a, int b);
void fn_0845_0d5e(void far *wsa, int start, int end, int delay, int x, int y, void far *cb, void far *a, void far *b, int c, int restore);
int fn_09aa_0183(int a, int b);
void ovr_2d8a_0025(int b, int a, int c, int d);
void fn_0845_08aa(void);
void fn_0845_1430(void far *pal);
int fn_0845_0636(int n, int sides);
int fn_070c_06a3(int who, int m, int x, int y, int z);
void fn_070c_07f5(int m, int r, int who, int a, int y);
void fn_070c_00cf(int who, int cls, long exp);
void fn_070c_05fa(struct Monster far *m);
void fn_0d6c_0034(struct Monster far *m);
void fn_0d6c_0995(struct Monster far *m, int a);
void fn_0d6c_0742(struct Monster far *m, long a);
void fn_0845_1343(int b, unsigned mask, int c, int d, int e, int f);
void fn_0845_046c(int b);
void fn_1dbc_0017(int a, int b, int c, int d, int e, int f, int g, int h);

int ovr_2d1b_0020(void);
void ovr_2d1b_0025(void);
void ovr_2d1b_002a(void);
void ovr_2d1b_002f(unsigned char far *a, unsigned char far *b);
int far *ovr_2d1b_0034(int type, int far *w, int far *h);
void ovr_2d1b_0039(int a, int type);
int ovr_2d1b_003e(unsigned char far *a, unsigned char far *b, unsigned long t, unsigned long n);
void ovr_2d1b_0043(void);
int ovr_2d1b_0048(int blk, int a, int n, int sides, int add, int z);
void ovr_2d1b_004d(int blk);
void ovr_2d1b_0052(unsigned char far *a, unsigned char far *b);
int ovr_2d1b_0057(int blk, int dir);
int ovr_2d1b_005c(int blk);
void ovr_2d1b_0061(void);

int ovr_2d1b_0020(void)
{
    int i;
    if (g_0b44 != 1) {
        ovr_2d46_0020(g_0b62, 3);
        for (i = 0; i < 4; i++)
            f_27b1_0000[i] = ovr_2d46_0025(3, i, g_4b92);
        g_0b44 = 1;
    }
    return 1;
}

void ovr_2d1b_0025(void)
{
    int i;
    if (g_0b44 == 1) {
        for (i = 0; i < 4; i++) {
            if (f_27b1_0000[i]) {
                fn_203b_0203(f_27b1_0000[i]);
                f_27b1_0000[i] = 0;
            }
        }
        g_0b44 = 0;
    }
}

void ovr_2d1b_002a(void)
{
    int fh;
    int i;
    if (g_7fe5 == 0xb) {
        fh = fn_1809_0000(g_0b6a, 1);
        fn_1809_084d(fh, g_4bcc, 0x180L);
        fn_1809_058d(fh);
        for (i = 0; i < 0x180; i++)
            g_4bcc[i + 0x180] = g_adea[i + 0x180];
        if (g_8080 & 4) {
            for (i = 1; i < 0x300; i++) {
                g_adea[i] ^= g_4bcc[i];
                g_4bcc[i] ^= g_adea[i];
                g_adea[i] ^= g_4bcc[i];
            }
        }
    }
}

void ovr_2d1b_002f(unsigned char far *a, unsigned char far *b)
{
    int i;
    fn_1ef2_02c0(g_0b77, b);
    for (i = 0x180; i < 0x300; i++) b[i] = g_540e[i] & 0x3f;
    for (i = 0x180; i < 0x300; i++) a[i] = g_540e[i] & 0x3f;
    for (i = 1; i < 0x80; i++) {
        a[i * 3] = 0;
        a[i * 3 + 1] = (g_540e[i * 3 + 1] + g_540e[i * 3 + 2] + g_540e[i * 3]) / 3;
        a[i * 3 + 2] = (g_540e[i * 3 + 1] + g_540e[i * 3 + 2] + g_540e[i * 3]) / 3 * 2;
        if (a[i * 3 + 2] > 0x3f) a[i * 3 + 2] = 0x3f;
    }
    fn_0845_02c6(a, a, g_81dc, g_81de);
    fn_0845_02c6(b, b, g_81dc, g_81de);
    b[0] = 0;
    b[1] = 0;
    b[2] = 0;
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
}

int far *ovr_2d1b_0034(int type, int far *w, int far *h)
{
    int far *p;
    switch (type) {
    case 0:
        p = 0;
        *w = 0;
        *h = 0;
        break;
    case 1:
    case 2:
        if ((p = ovr_2dfd_0020(g_0b84, fn_215f_0003(5), g_369f, 1, 0)) == 0) ovr_2ce1_007f(g_0b8d);
        *w = 0x70;
        *h = 0;
        break;
    case 3:
        if ((p = ovr_2dfd_0020(g_0baa, fn_215f_0003(5), g_369f, 1, 0)) == 0) ovr_2ce1_007f(g_0bb2);
        *w = 0x88;
        *h = 0xc;
        break;
    default:
        p = 0;
        *w = 0;
        *h = 0;
        break;
    }
    return p;
}

void ovr_2d1b_0039(int a, int type)
{
    int pal;
    int loaded;
    int flag;
    int res;
    int far *p;
    int w;
    int h;
    unsigned char pal1[0x300];
    unsigned char pal2[0x300];
    int i;

    if (g_0b44 != 1) {
        if (!ovr_2d1b_0020()) ovr_2ce1_007f(g_0bcf);
        loaded = 1;
    } else loaded = 0;
    pal = fn_1e74_000f(2);
    fn_231c_0048(2);
    fn_1ebc_00e7();
    fn_0845_15d9(0);
    fn_2279_025b(fn_215f_001d(0), g_4d5a, 0x9600L);
    fn_1ebc_00fe();
    if (g_7fe5 == 0xb && !(g_8080 & 4)) {
        for (i = 1; i < 0x180; i++) {
            g_adea[i] ^= g_4bcc[i];
            g_4bcc[i] ^= g_adea[i];
            g_adea[i] ^= g_4bcc[i];
        }
        g_8080 |= 4;
        fn_0bbc_0744(a, 8, g_0b4e[type], 1);
    }
    ovr_2d1b_002f(pal1, pal2);
    fn_0845_02c6(g_adea, g_540e, g_81dc, g_81de);
    fn_2279_025b(fn_215f_0003(5), g_4d56, 0xfa00L);
    p = ovr_2d1b_0034(type, &w, &h);
    fn_067a_0401(0x47, 0);
    fn_0845_0d5e(0, 0, 0, 2, 0, 0, 0, g_540e, pal1, 0x28, 0);
    ovr_2d1b_003e(g_540e, pal1, g_384c, 1L);
    if (p) {
        if (type > 2) {
            g_8203[fn_09aa_0183(g_7fd0, g_7fdf)].flags |= 0x10;
            flag = 0;
            fn_067a_0401(0xa5, 0);
        } else flag = 1;
        fn_0845_0d5e(p, 0, p[1], 2, w, h, 0, 0, 0, 0, flag);
    }
    if (p) ovr_2dfd_0025(p);
    fn_2279_025b(g_4d56, fn_215f_0003(5), 0xfa00L);
    if (type < 3) {
        ovr_2d8a_0025(fn_09aa_0183(g_7fd0, g_7fdf), a, g_0b46[type], 3);
        res = 0;
    } else res = ovr_2d1b_0048(fn_09aa_0183(g_7fd0, g_7fdf), a, g_0b53[type], g_0b58[type], g_0b5d[type], 3);
    fn_0845_08aa();
    fn_0845_15d9(0);
    fn_231c_0008(2);
    if (g_7fe5 != 0xb) fn_0845_02c6(g_adea, pal2, g_81dc, g_81de);
    fn_0845_0d5e(0, 0, 0, 2, 0, 0, 0, pal1, pal2, 0x28, 0);
    ovr_2d1b_003e(pal1, pal2, g_384c, 1L);
    if (res) ovr_2d1b_0052(pal1, pal2);
    if (type == 0xb) fn_0bbc_0744(a, 8, g_0b4e[type], 1);
    if (loaded == 1) ovr_2d1b_0025();
    fn_1e74_000f(pal);
}

int ovr_2d1b_003e(unsigned char far *a, unsigned char far *b, unsigned long t, unsigned long n)
{
    int tmp;
    char buf[0x300];
    int i;
    int changed;
    char d;

    for (changed = i = 0; i < 0x300; i++) {
        if (t < n) {
            d = (b[i] & 0x3f) - (a[i] & 0x3f);
            if (d) changed = 1;
            tmp = ((long)d << 8) / (long)n * t >> 8;
            d = (a[i] & 0x3f) + tmp;
        } else {
            d = b[i] & 0x3f;
            g_540e[i] = d;
            changed = 0;
        }
        buf[i] = d;
    }
    fn_1ef2_001c(buf);
    return changed;
}

void ovr_2d1b_0043(void)
{
    int i;
    g_8080 &= ~4;
    if (g_7fe5 == 0xb) {
        for (i = 1; i < 0x300; i++) {
            g_adea[i] ^= g_4bcc[i];
            g_4bcc[i] ^= g_adea[i];
            g_adea[i] ^= g_4bcc[i];
            fn_0845_02c6(g_adea, g_540e, g_81dc, g_81de);
        }
        fn_0845_1430(g_4bcc);
        fn_0845_1430(g_540e);
        fn_0845_0d5e(0, 0, 0, 2, 0, 0, 0, g_4bcc, g_540e, 0x28, 0);
    }
}

int ovr_2d1b_0048(int blk, int a, int n, int sides, int add, int z)
{
    struct Monster far *p;
    int hit;
    int dmg;
    int m;
    int r;

    m = g_8203[blk].mon;
    hit = 0;
    while (m & 0x8000) {
        dmg = fn_0845_0636(n, sides) + add;
        r = fn_070c_06a3(a, m, dmg, z, 2);
        p = &f_2803_15fa[m & 0x7fff];
        if (p->hp <= r) {
            fn_070c_00cf(a, 2, (long)p->hp);
            m = p->next;
            if (p->flags & 0x20) {
                p->mode = 0;
                fn_0d6c_0034(p);
                if (g_7fe5 != 0x1d) fn_0d6c_0995(p, 0xe);
                fn_0845_1343(0x404, 0xffff, m, m, 0, 0);
                fn_0845_046c(p->block);
                if (p->mode == 0xe) fn_0d6c_0742(p, 0L);
            } else fn_070c_05fa(p);
        } else {
            hit = 1;
            fn_070c_07f5(m, r, a, 2, 3);
            p->hitDmg = 0;
            m = p->next;
        }
        if (p->flags & 0x20) break;
    }
    return hit;
}

void ovr_2d1b_004d(int blk)
{
    struct Monster far *p;
    int m;

    m = g_8203[blk].mon;
    while (m & 0x8000) {
        m &= 0x7fff;
        p = &f_2803_15fa[m];
        if (p->mode == 0xb) {
            if (p->flags & 0x20) {
                p->mode = 0;
                fn_0d6c_0034(p);
                if (g_7fe5 != 0x1d) fn_0d6c_0995(p, 0xe);
                fn_0845_1343(0x404, 0xffff, m, m, 0, 0);
                fn_0845_046c(p->block);
                if (p->mode == 0xe) fn_0d6c_0742(p, 0L);
            } else fn_070c_05fa(p);
        }
        m = p->next;
    }
}

void ovr_2d1b_0052(unsigned char far *a, unsigned char far *b)
{
    int pg;
    int far *p;
    int blk;

    fn_1ebc_00e7();
    pg = fn_1e74_000f(2);
    blk = fn_09aa_0183(g_7fd0, g_7fdf);
    g_8203[blk].flags &= ~0x10;
    fn_1dbc_0017(0, 0, 0, 0, 0x140, 0xc8, 0, 2);
    fn_0845_15d9(2);
    fn_2279_025b(fn_215f_001d(2), g_4d5a, 0xfa00L);
    fn_2279_025b(fn_215f_0003(5), g_4d56, 0xfa00L);
    if ((p = ovr_2dfd_0020(g_0bf2, fn_215f_0003(5), g_369f, 1, 0)) == 0) ovr_2ce1_007f(g_0bfe);
    fn_067a_0401(0xa6, 0);
    fn_0845_0d5e(p, 0, p[1], 1, 0x3a, 0, 0, a, b, 0x14, 1);
    ovr_2dfd_0025(p);
    fn_2279_025b(g_4d56, fn_215f_0003(5), 0xfa00L);
    fn_1e74_000f(pg);
    fn_0845_08aa();
    fn_0845_15d9(0);
    fn_1ebc_00fe();
}

int ovr_2d1b_0057(int blk, int dir)
{
    int w;
    w = WALL(blk, dir);
    if (g_53be[w] == 0 && g_536e[w] == 0 && !((char)g_8203[blk].flags & 0x80)) return 1;
    return 0;
}

int ovr_2d1b_005c(int blk)
{
    int w;
    w = WALL(blk, 0);
    if (g_53be[w] == 0 && g_536e[w] == 0 && !((char)g_8203[blk].flags & 0x40)) return 1;
    return 0;
}

void ovr_2d1b_0061(void)
{
    int i;
    for (i = 0; i < 0x400; i++) {
        if (g_8203[i].flags & 0x10) {
            g_8203[i].flags &= ~0x10;
            if (ovr_2d1b_0057(i, 0) && ovr_2d1b_0057(i, 1)) g_8203[i].flags |= 0x40;
        } else if (g_8203[i].flags & 0x40) g_8203[i].flags &= ~0x40;
        else if (g_8203[i].flags & 0x80) g_8203[i].flags &= ~0x80;
    }
}
