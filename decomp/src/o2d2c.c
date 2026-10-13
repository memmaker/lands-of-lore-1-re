/* o2d2c: level loading (LEVELn.* files, wall/decoration shapes, monster shapes, palettes, level EMC opcodes) */
#include "lol.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mem.h>
#include <dos.h>


struct SpellDef2 { int name; char pad[0x1a]; };     /* 0x1c bytes, f_27dd_0010[] */
struct Deco {                   /* 0x48 bytes, g_5a52[] */
    int sh[10];
    char pad14[0x32];
    char next;                  /* +46 */
    char c47;
};
struct Ovl { void far *p; int a, b; };              /* g_7672[3][4][16] */
struct MT {                     /* 0x53 bytes, f_2803_1b5e[] (= struct MonType) */
    char c00;
    char size;
    int a[9];                   /* +02 attack block */
    int far *atk;               /* +14 */
    int dmg[8];                 /* +18 */
    int res[8];                 /* +28 */
    int w38, w3a;
    char c3c, c3d;
    int w3e;                    /* +3e */
    int w40;                    /* +40 */
    int w42[5];                 /* +42 */
    char c4c[2];
    char c4e[2];
    char c50[3];
};
struct Rec { int idx; int a; int sh; int c; int d; int e; };   /* 12 bytes, LEVELn.INF records */
struct Shift { int block; char dir; char d; };      /* g_4ed0[3] */

extern long g_20ee, g_2130;
extern void far *g_4d68;
extern char g_20db;
extern int g_4b92;
extern int far *g_4edc;
extern int g_4b44, g_4b46, g_4b48;
extern char far *g_4b4a;
extern struct Deco g_5a52[];
extern void far *g_5412[];
extern char g_81f2[];
extern char g_7fd9;
extern struct SpellDef2 far f_27dd_0010[];
extern unsigned g_806a;
extern char g_81fd;
extern int g_7fe1;
extern void far * far f_2803_01de;
extern int g_3649;
extern char far f_2803_3835[];
extern char g_4b22[], g_4b31[];
extern int g_4b40, g_4b42;
extern char g_0e54[], g_0e60[], g_0e66[], g_0e6a[], g_0e70[], g_0e74[], g_0e82[], g_0eb3[], g_0ebf[], g_0ecb[];
extern char g_0ed9[], g_0f04[];
extern char g_ad99[];
extern char far *g_7fcc;
extern void far *g_7fc0, far *g_7fc4, far *g_7fc8;
extern unsigned char far *g_adea;
extern unsigned char far *g_7c72[];
extern int g_20d9;
extern char g_81dc, g_81de;
extern unsigned char far *g_540e;
extern void far *g_4bec, far *g_4bf0;
extern void far *g_4bda;
extern struct Ovl g_7672[3][4][16];
extern char g_536e[], g_53be[];
extern unsigned char g_531e[];
extern char far f_2803_0053[];
extern char far f_2803_0056[];
extern void far * far f_2803_040a[][16];
extern void far * far f_2803_04ca[][16];
extern void far * far f_2803_058a[];
extern char far f_2803_3611[];
extern char far f_2803_35fd[];
extern unsigned g_8094;
extern int g_20d7, g_7fd6, g_206d;
extern unsigned long g_81f9;
extern int g_7fd0, g_7fdf, g_7fd2, g_7fd4;
extern char g_aa03[];
extern char g_7fdc;
extern int g_20d5;
extern int g_0cf4;
extern int g_804a, g_7fda;
extern int g_35e2, g_35e4, g_20cd, g_20cf;
extern char g_7fe5;
extern int g_7fe6, g_7fe8, g_7fea;
extern int g_3745, g_3747, g_3749;
extern char g_8200, g_8201, g_81fe, g_81ff;
extern char g_81e2[];
extern char far *g_0cf6[], far *g_0d26[];
extern char g_2494[];
extern int g_4bf6;
extern struct MT far f_2803_1b5e[];
extern struct Shift g_4ed0[];
extern struct Fly g_4dcc[];

void fn_203b_0203(void far *p);
void far *fn_203b_0007(unsigned long size, int flags);
char far *ovr_2d46_002f(char far *name, int n);
int fn_1809_0000(char far *name, int mode);
long fn_1809_084d(int h, void far *buf, long n);
void fn_1809_058d(int h);
long fn_1809_120c(int h);
void fn_1809_0e76(int h, long off, int whence);
char far *fn_215f_0003(int page);
char far *fn_215f_001d(int page);
void far *fn_2037_0002(void far *p, long off);
void fn_2279_025b(void far *s, void far *d, long n);
void fn_1dbc_0004(int a, int b, int c, int d, int e, int f, int g, int h);
void fn_1dbc_0017(int a, int b, int c, int d, int e, int f, int g, int h);
void fn_1e59_001d(int x1, int y1, int x2, int y2, int c);
char far *fn_0845_06f8(int id);
void fn_0845_07b3(char far *s, int x, int y, int fg, int bg, int f);
void far *fn_0845_04ec(void far *name);
void fn_0845_0631(void far *p);
void fn_0845_144e(void far *p);
void fn_1fd6_000a(int page, void far *data, int x, int y, int frame, int flags);
int fn_1e74_000f(int page);
void fn_1dff_0008(int a, int b);
void fn_0845_08aa(void);
void fn_0845_15d9(int n);
void fn_0a21_05ce(void);
void fn_0c59_0377(void);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_1aff_001c(void far *p);
void fn_1b43_0109(void far *pal, void far *tab, int a, int b);
void fn_0845_02c6(unsigned char far *src, unsigned char far *dst, int s, int i);
void fn_0845_035b(unsigned char far *src, int lvl, int idx);
void fn_0f28_0009(void far *d);
int fn_0f28_0114(char far *name, void far *d, void far *opcodes, void far *buf);
void fn_067a_0003(void);
void fn_067a_01d1(int a);
void fn_067a_023d(void);
void far *fn_067a_0649(int n);
void fn_067a_084d(char far *name, int n);
int far *fn_080e_000b(int id);
void fn_080e_00b4(int far *list, int item);
void fn_0845_09f1(int n);
void fn_0845_08d9(int n);
void fn_0845_0a5b(void);
void fn_0845_155d(int n);
void fn_0845_1605(void);
void fn_0845_13d6(int b, unsigned mask);
void fn_0845_03d4(int n);
void fn_130a_0784(void);
void fn_0bbc_070e(int a, int b);
int fn_07bc_012d(int type, int a, int b);
void fn_0fbe_000c(int n);
void fn_2169_062e(void);
void fn_0b6b_0272(struct Fly far *f, int x, int y, int kind);
void fn_1aff_030e(int far *x, int far *y, int b, int cx, int cy);
void fn_231c_0008(int n);
void fn_231c_0048(int n);
void far *fn_1f36_0064(void far *p, int idx);
int fn_1f36_0029(void far *p);
int fn_1f36_01e2(void far *p);
int fn_2315_0018(int w);
long ovr_2ded_002f(char far *name, int page, int dpage, void far *pal);
long ovr_2ded_0020(char far *name, void far *buf, long n);
void far *ovr_2d46_003e(long n, unsigned flags);
void ovr_2d46_0043(void far *p);
void ovr_2d46_0020(char far *s, int n);
void ovr_2d46_002a(int fatal, char far *fmt, ...);
void ovr_2d5f_012e(void);
void ovr_2d5f_0025(void);
void ovr_2d0e_0020(int page);
void ovr_2d0e_002f(int n, int snd);
void ovr_2d1b_002a(void);
void ovr_2d1b_0061(void);
void ovr_2da3_0020(int lvl);
void ovr_2d3c_0020(void);
void ovr_2d3c_0025(int lvl);
void ovr_2ce1_0043(void far *a, void far *b, int c, char d, int e, char f, int g, int h);
void ovr_2d74_0020(int n);
void ovr_2ceb_0020(void);

#define STR(s, n) ((char far *)(s)->dat->text + fn_2315_0018((s)->dat->text[ARG(s, n)]))

void ovr_2d2c_0020(void);
void ovr_2d2c_0025(void);
void ovr_2d2c_002a(char far *name);
void ovr_2d2c_002f(void);
void ovr_2d2c_0034(char far *a, char far *b, int keep);
int ovr_2d2c_0039(int idx);
void ovr_2d2c_003e(void);
void ovr_2d2c_0043(void);
void ovr_2d2c_0048(char far *name);
void ovr_2d2c_004d(char far *name, int a, int b, long sz1, long sz2, char far *pal);
void ovr_2d2c_0052(int type, void far *shp);
void ovr_2d2c_0057(char far *name, int type, int c);
void ovr_2d2c_005c(void);
void ovr_2d2c_0061(int clear);
void ovr_2d2c_0066(void);
void ovr_2d2c_006b(int lvl);
void ovr_2d2c_0070(void);
void ovr_2d2c_0075(int lvl, int mode);
void ovr_2d2c_007a(char far *name);
void ovr_2d2c_007f(char far *name, int n);
void ovr_2d2c_0084(char far *name);
int ovr_2d2c_0089(struct EmcState far *s);
int ovr_2d2c_008e(struct EmcState far *s);
int ovr_2d2c_0093(struct EmcState far *s);
int ovr_2d2c_0098(struct EmcState far *s);
int ovr_2d2c_009d(struct EmcState far *s);
int ovr_2d2c_00a2(struct EmcState far *s);
int ovr_2d2c_00a7(struct EmcState far *s);
int ovr_2d2c_00ac(struct EmcState far *s);
void ovr_2d2c_00b1(struct Monster far *m, int item);
int ovr_2d2c_00b6(struct EmcState far *s);
int ovr_2d2c_00bb(struct EmcState far *s);
int ovr_2d2c_00c0(struct EmcState far *s);
int ovr_2d2c_00c5(struct EmcState far *s);
int ovr_2d2c_00ca(struct EmcState far *s);
int ovr_2d2c_00cf(struct EmcState far *s);
int ovr_2d2c_00d4(struct EmcState far *s);
void far *ovr_2d2c_00d9(int h, int idx, int far *hdr, int flags);
int ovr_2d2c_00de(struct EmcState far *s);
int ovr_2d2c_00e3(int page, int idx, int n);
void ovr_2d2c_00e8(void);
void far *ovr_2d2c_00ed(int page, int idx, int flags);
void ovr_2d2c_00f2(int type);

void ovr_2d2c_002a(char far *name)
{
    unsigned long max;
    unsigned long sz;
    int h[3];
    register int i;

    g_2130 = g_20ee;
    if (g_4d68) {
        fn_203b_0203(g_4d68);
        g_4d68 = 0;
    }
    if (!name) return;
    max = 0;
    for (i = 0; i < 3; i++) {
        h[i] = fn_1809_0000(ovr_2d46_002f(name, i), 1);
        sz = fn_1809_120c(h[i]);
        if (sz > max) max = sz;
    }
    g_4d68 = fn_203b_0007(max, g_4b92);
    fn_1809_084d(h[g_20db], g_4d68, fn_1809_120c(h[g_20db]));
    for (i = 0; i < 3; i++) fn_1809_058d(h[i]);
}

void ovr_2d2c_002f(void)
{
    register int i;

    for (i = 0; i < 30; i++) {
        setmem(&f_2803_15fa[i], 0x2e, 0);
        f_2803_15fa[i].mode = 0x10;
    }
}

void ovr_2d2c_0034(char far *a, char far *b, int keep)
{
    int n;
    register int h;

    setmem(g_4edc, 5000, 0);
    g_4b44 = fn_1809_0000(a, 1);
    fn_1809_084d(g_4b44, fn_215f_0003(3), 2L);
    fn_1809_084d(g_4b44, fn_215f_0003(3) + 2, (long)(*(int far *)fn_215f_0003(3) << 2));
    h = fn_1809_0000(b, 1);
    fn_1809_084d(h, &n, 2L);
    g_4b4a = fn_2037_0002(fn_215f_0003(7), 15000L);
    fn_1809_084d(h, g_4b4a, (unsigned long)(unsigned)(n * 0x48));
    fn_1809_058d(h);
    if (keep == 0) {
        g_4b46 = 1;
        g_4b48 = 1;
    }
}

int ovr_2d2c_0039(int idx)
{
    int j;
    int far *p;
    int far *q;
    register int v;
    register int n;

    p = g_4edc;
    q = g_4edc + 2000;
    if (q[idx]) return q[idx];
    n = g_4b46++;
    fn_2279_025b(g_4b4a + idx * 0x48, &g_5a52[n], 0x48L);
    for (j = 0; j < 10; j++) {
        if ((v = g_5a52[n].sh[j]) == -1) continue;
        if (p[v]) g_5a52[n].sh[j] = p[v];
        else {
            g_5412[g_4b48] = ovr_2d2c_00d9(g_4b44, v, (int far *)fn_215f_0003(3), g_4b92);
            p[v] = g_4b48;
            g_5a52[n].sh[j] = g_4b48;
            g_4b48++;
        }
    }
    q[idx] = n;
    if (g_5a52[n].next) g_5a52[n].next = ovr_2d2c_0039(g_5a52[n].next);
    return n;
}

void ovr_2d2c_003e(void)
{
    fn_1809_058d(g_4b44);
}

void ovr_2d2c_0020(void)
{
    int sel;
    register int i;
    register int y;

    fn_1dbc_0004(0x70, 0, 0xc, 0, 0x57, 0xf, 2, 2);
    y = 0;
    for (i = 0; i < 7; i++)
        if (g_81f2[i] != -1) y += 9;
    if (y == 18) y = 27;
    if (y) {
        fn_1dbc_0004(0xc9, 1, 0x11, 0xf, 6, y, 2, 2);
        fn_1dbc_0004(0xd0, 1, 0x59, 0xf, 6, y, 2, 2);
        fn_1e59_001d(0x15, 0xf, 0x59, y + 0xf, 0xce);
    }
    fn_1dbc_0004(0x70, 0x10, 0xc, y + 0xf, 0x57, 0xe, 2, 2);
    sel = g_7fd9;
    y = 0xf;
    for (i = 0; i < 7; i++) {
        if (g_81f2[i] != -1) {
            if (i == sel) fn_0845_07b3(fn_0845_06f8(f_27dd_0010[g_81f2[i]].name), 0x18, y, 0x84, 0, 0);
            else fn_0845_07b3(fn_0845_06f8(f_27dd_0010[g_81f2[i]].name), 0x18, y, 1, 0, 0);
            y += 9;
        }
    }
}

void ovr_2d2c_0043(void)
{
    int page;

    ovr_2ded_002f(g_0e54, 3, 3, 0L);
    if (g_806a & 0x4000) {
        fn_1dbc_0017(g_81fd == 0 ? 0xe : g_81fd == 1 ? 0x13 : 0x1c, 0x20, 0x24, 0, 4, 0x20, 2, 2);
        g_7fe1 = -1;
    }
    if (g_806a & 0x1000) fn_1fd6_000a(2, fn_0845_04ec(f_2803_01de), 0x122, 0x20, 0, 0);
    page = fn_1e74_000f(2);
    if (g_806a & 0x2000) ovr_2d2c_0020();
    else g_7fd9 = 0;
    if (g_806a & 0x800) ovr_2d5f_012e();
    fn_0845_08aa();
    fn_0845_15d9(2);
    fn_0a21_05ce();
    fn_0c59_0377();
    ovr_2d0e_0020(g_3649);
    fn_1e74_000f(page);
    fn_1ebc_00e7();
    fn_1dff_0008(2, 0);
    fn_0845_08aa();
    fn_1ebc_00fe();
}

void ovr_2d2c_0048(char far *name)
{
    int far *p;
    register int i;

    p = (int far *)fn_215f_001d(2);
    setmem(g_8203, 0x2800, 0);
    ovr_2ded_002f(name, 2, 2, 0L);
    for (i = 0; i < 0x400; i++) {
        fn_2279_025b(fn_215f_0003(2) + i * p[2] + 6, &g_8203[i], 4L);
        g_8203[i].drawDir = 5;
        if (f_2803_3835[WALL(i, 0)] == 0x11) {
            g_8203[i].flags &= 0xef;
            g_8203[i].flags |= 0x20;
        }
    }
}

void ovr_2d2c_004d(char far *name, int a, int b, long sz1, long sz2, char far *pal)
{
    char far *p;
    char buf[0x180];
    char fname[14];
    register int n;
    int j;

    if (name) {
        strcpy(g_4b22, name);
        g_4b40 = a;
        g_4b42 = b;
        strcpy(g_4b31, pal);
    } else {
        name = g_4b22;
        a = g_4b40;
        b = g_4b42;
        pal = g_4b31;
    }
    sprintf(g_ad99, g_0e60, name, g_0e66);
    ovr_2ded_002f(g_ad99, 3, 3, 0L);
    p = g_7fcc;
    n = *(int far *)p;
    p += 2;
    if (sz1 == 0xffff) sz1 = (unsigned)(n << 5);
    if (!g_7fc4) g_7fc4 = ovr_2d46_003e(sz1, 0);
    if (!g_7fc0) g_7fc0 = ovr_2d46_003e((unsigned)n, 0);
    fn_2279_025b(p, g_7fc0, (unsigned)n);
    p += n;
    fn_1aff_001c(p);
    p += 0x80;
    if (pal) ovr_2ded_0020(pal, p, 0x180L);
    fn_2279_025b(p, g_adea, 0x180L);
    fn_2279_025b(g_adea + 0x180, buf, 0x180L);
    setmem(g_adea + 0x180, 0x180, -1);
    fn_2279_025b(buf, g_adea + 0x180, 0x180L);
    ovr_2d1b_002a();
    p += 0x180;
    fn_2279_025b(p, g_7fc4, sz1);
    sprintf(g_ad99, g_0e6a, name, g_0e70);
    if (sz2 == 0xffff) sz2 = (unsigned long)ovr_2ded_002f(g_ad99, 3, 3, 0L) - 2;
    else ovr_2ded_002f(g_ad99, 3, 3, 0L);
    if (!g_7fc8) g_7fc8 = ovr_2d46_003e(sz2, 0x20);
    fn_2279_025b(g_7fcc + 2, g_7fc8, sz2);
    for (n = 0; n < 8; n++) {
        if (!g_7c72[n]) g_7c72[n] = ovr_2d46_003e(0x100L, 0);
        if (n == 7) continue;
        {
            int k = 100 - n * b;
            k = k <= 0 ? 0 : k * 0xff / 100;
            fn_1b43_0109(g_adea, g_7c72[n], a, k);
        }
        for (j = 0; j < 0x80; j++)
            if (g_7c72[n][j] == 0xff) g_7c72[n][j] = 0;
        for (j = 0x80; j < 0x100; j++) g_7c72[n][j] = j;
    }
    for (j = 0; j < 0x100; j++) g_7c72[7][j] = j;
    g_20d9 = 0;
    fn_0845_02c6(g_adea, g_540e, g_81dc, g_81de);
    sprintf(fname, g_0e74, g_7fe5);
    n = fn_1809_0000(fname, 1);
    fn_1809_084d(n, g_4bec, 0x100L);
    fn_1809_084d(n, g_4bf0, 0x1400L);
    fn_1809_058d(n);
    g_20d9 = 1;
}

void ovr_2d2c_0052(int type, void far *shp)
{
    int k;
    char far *p;
    int cnt;
    int map[256];
    unsigned char pal[256];
    char row[64];
    register int i;
    register int j;

    setmem(g_7fcc, 0xfa00, 0);
    fn_1fd6_000a(2, shp, 0, 0, 0, 0);
    memset(row, 0, 0x40);
    p = fn_215f_001d(2);
    for (j = 0; j < 0x40; j++) {
        row[j] = *p;
        p += 0x140;
    }
    for (i = 0; i < 16; i++) {
        fn_2279_025b((char far *)f_2803_04ca[type][i] + 10, pal, 0x100L);
        cnt = pal[0];
        memset(map, -1, 0xff);
        for (j = 0; j < cnt; j++) {
            p = memchr(row, pal[j + 1], 0x40);
            if (p) map[j] = (int)p - (int)row;
        }
        for (k = 0; k < 8; k++) {
            fn_2279_025b((char far *)f_2803_04ca[type][i] + 10, pal, 0x100L);
            for (j = 0; j < cnt; j++) {
                if (map[j] != -1) {
                    char c = (fn_215f_0003(2) + map[j] * 0x140 + k)[1];
                    if (c) pal[j + 1] = c;
                }
            }
            fn_2279_025b(&pal[1], (char far *)f_2803_040a[type][i] + k * cnt, (long)cnt);
        }
    }
}

void ovr_2d2c_0057(char far *name, int type, int c)
{
    struct Ovl far *q;
    int id;
    int found;
    void far *t;
    unsigned char far *shp;
    void far *tab[16];
    register int i;
    register int j;

    ovr_2d2c_00f2(type);
    ovr_2d46_0020(name, 3);
    for (j = 0; j < 16; j++) {
        tab[j] = fn_1f36_0064(fn_215f_0003(3), j);
        for (found = i = 0; i < j; i++) {
            if (tab[j] == tab[i]) {
                f_2803_04ca[type][j] = f_2803_04ca[type][i];
                found = 1;
                break;
            }
        }
        if (!found) f_2803_04ca[type][j] = ovr_2d2c_00ed(3, j, g_4b92);
        shp = fn_0845_04ec(f_2803_04ca[type][j]);
        if (g_7fe5 == 0x1d || g_7fe5 == 0x17) f_2803_040a[type][j] = fn_203b_0007((unsigned long)shp[10] << 3, 0);
        else f_2803_040a[type][j] = ovr_2d46_003e((unsigned long)shp[10] << 3, 0);
        fn_0845_0631(shp);
        if (!f_2803_040a[type][j]) ovr_2d46_002a(1, g_0e82);
    }
    for (j = 0; j < 4; j++)
        for (i = 0; i < 16; i++) {
            q = &g_7672[type][j][i];
            id = j * 16 + i + 0x11;
            q->p = ovr_2d2c_00ed(3, id, g_4b92);
            q->a = ovr_2d2c_00e3(3, id, 2);
            q->b = ovr_2d2c_00e3(3, id, 1);
        }
    f_2803_0053[type] = c;
    t = ovr_2d2c_00ed(3, 0x10, 0);
    ovr_2d2c_0052(type, t);
    fn_0845_144e(t);
}

void ovr_2d2c_005c(void)
{
    int k;
    register int i;
    register int j;

    for (i = 0; i < 2; i++)
        if (f_2803_058a[i]) {
            fn_0845_144e(f_2803_058a[i]);
            f_2803_058a[i] = 0;
        }
    for (j = 0; j < 3; j++)
        for (i = 0; i < 16; i++) {
            if (f_2803_04ca[j][i]) {
                fn_0845_144e(f_2803_04ca[j][i]);
                f_2803_04ca[j][i] = 0;
            }
            if (f_2803_040a[j][i]) {
                ovr_2d46_0043(f_2803_040a[j][i]);
                f_2803_040a[j][i] = 0;
            }
            for (k = 0; k < 4; k++)
                if (g_7672[j][k][i].p) {
                    fn_0845_144e(g_7672[j][k][i].p);
                    g_7672[j][k][i].p = 0;
                }
        }
    for (i = 0; i < 400; i++)
        if (g_5412[i]) {
            fn_0845_144e(g_5412[i]);
            g_5412[i] = 0;
        }
    if (g_4bda) {
        fn_0f28_0009(f_2803_3611);
        ovr_2d46_0043(g_4bda);
    }
    if (g_7fc8) {
        ovr_2d46_0043(g_7fc8);
        g_7fc8 = 0;
    }
    if (g_7fc4) {
        ovr_2d46_0043(g_7fc4);
        g_7fc4 = 0;
    }
    if (g_7fc0) {
        ovr_2d46_0043(g_7fc0);
        g_7fc0 = 0;
    }
    for (i = 0; i < 8; i++)
        if (g_7c72[i]) {
            ovr_2d46_0043(g_7c72[i]);
            g_7c72[i] = 0;
        }
    if (g_4d68) {
        ovr_2d46_0043(g_4d68);
        g_4d68 = 0;
    }
    ovr_2d46_0043((void far *)-1L);
    fn_067a_0003();
    asm db 0b9h         /* mov cx,1; mov di,offset g_536e: as bytes, so BCC keeps j in di */
    asm dw 1
    asm db 0bfh
    asm dw offset g_536e
    asm push ds
    asm pop es
    asm db 33h, 0c0h
    asm rep stosw
    asm stosb
}

void ovr_2d2c_0061(int clear)
{
    int far *r;
    int far *p;
    register int i;

    for (i = 0; i < 0x400; i++) {
        p = &g_8203[i].mon;
        g_8203[i].drawDir = 5;
        while (*p & 0x8000) {
            r = fn_080e_000b(*p);
            p = r;
        }
        if (*p) {
            f_2803_1cfd[*p].level = g_7fe5;
            f_2803_1cfd[*p].block = i;
            *p = 0;
        }
    }
    if (clear) setmem(g_4dcc, 0x88, 0);
}

void ovr_2d2c_0066(void)
{
    register int i;
    register int b;

    for (i = 0; i < 400; i++) {
        if (f_2803_1cfd[i].level == g_7fe5) {
            b = f_2803_1cfd[i].block;
            fn_080e_00b4(&g_8203[b].mon, i);
            g_8203[b].drawDir = 5;
        }
        f_2803_1cfd[i].drawNext = 0;
    }
}

void ovr_2d2c_006b(int lvl)
{
    char buf[30];
    register int i;

    g_8094 |= 0x800;
    fn_0845_09f1(0x85);
    g_20d7 = 0;
    fn_067a_023d();
    fn_130a_0784();
    ovr_2d2c_005c();
    ovr_2d2c_0061(1);
    ovr_2d2c_002f();
    ovr_2d1b_0061();
    ovr_2d2c_00f2(0);
    ovr_2d2c_00f2(1);
    for (i = 5; i <= 7; i++) fn_0bbc_070e(i, 0);
    g_7fe5 = lvl;
    g_7fd6 = 0;
    ovr_2d5f_0025();
    ovr_2da3_0020(lvl);
    ovr_2d2c_0075(g_7fe5, 1);
    g_206d = 1;
    sprintf(buf, g_0eb3, lvl);
    if (g_81f9 & (1L << (g_7fe5 - 1))) ovr_2d2c_007f(buf, 0);
    else ovr_2d2c_007f(buf, 1);
    g_206d = 0;
    if (g_81f9 & (1L << (g_7fe5 - 1))) ovr_2d3c_0025(g_7fe5);
    sprintf(buf, g_0ebf, lvl);
    ovr_2d2c_007a(buf);
    ovr_2d2c_0066();
    fn_0845_155d(g_7fd0);
    ovr_2ce1_0043(g_adea, g_aa03, 0x20, 0x10, 0, 0, 0x80, 1);
    g_7fdc = 0;
    if (g_20d5 == 3) fn_0845_08d9(10);
    ovr_2d2c_0043();
    fn_0845_035b(g_adea, g_81dc, g_81de);
    fn_0845_0a5b();
    fn_067a_01d1(g_0cf4);
    fn_2169_062e();
}

void ovr_2d2c_0070(void)
{
    g_7fd9 = 0;
    g_7fe1 = -1;
    g_804a = -1;
    g_7fda |= 0x1b;
    g_35e4 = 1;
    g_35e2 = 1;
    g_20cd = 1;
    g_20cf = 1;
    g_7fe5 = 1;
    ovr_2d0e_002f(0x29, 0);
    g_7fe6 = fn_07bc_012d(0xd8, 0, 0);
    g_7fe8 = fn_07bc_012d(0xd9, 0, 0);
    g_7fea = fn_07bc_012d(0xda, 0, 0);
    setmem(g_81f2, 7, -1);
    g_81f2[0] = 0;
    g_81fd = g_20db;
    if (g_3749 == 0) {
        g_81ff = 0;
        g_81fe = 1;
    } else {
        g_81ff = 0x4b;
        g_81fe = g_20db != 0;
    }
    g_8201 = g_3747 ? 0x4b : 0;
    g_8200 = g_3745 ? 0x4b : 0;
    fn_0845_1605();
    asm mov cx,8
    asm mov di,offset g_81e2
    asm push ds
    asm pop es
    asm mov ax,100h
    asm rep stosw
    if (_argc > 1) {
        switch ((int)atol(_argv[1])) {
        case 0: ovr_2d74_0020(-9); break;
        case 1: ovr_2d74_0020(-1); break;
        case 2: ovr_2d74_0020(-8); break;
        case 3: ovr_2d74_0020(-5); break;
        }
    } else ovr_2d74_0020(-5);
    ovr_2ceb_0020();
    ovr_2d2c_006b(1);
    fn_1ebc_00fe();
}

void ovr_2d2c_0075(int lvl, int mode)
{
    int n;
    char fname[14];
    struct Rec r;
    register int h;

    sprintf(fname, g_0ecb, lvl);
    h = fn_1809_0000(fname, 1);
    fn_1809_084d(h, &n, 2L);
    ovr_2d2c_0034(g_0cf6[n], g_0d26[n], 0);
    while (fn_1809_084d(h, &r, 12L)) {
        g_53be[r.idx] = r.a;
        if (mode == 1) {
            if (r.sh > 0) g_536e[r.idx] = ovr_2d2c_0039(r.sh);
            else g_536e[r.idx] = r.sh;
        }
        f_2803_0056[r.idx] = r.c;
        g_531e[r.idx] = r.d;
        f_2803_3835[r.idx] = r.e;
    }
    fn_1809_058d(h);
    ovr_2d2c_003e();
}

void ovr_2d2c_007a(char far *name)
{
    fn_0f28_0114(name, f_2803_3611, g_2494, 0L);
    fn_0845_13d6(0x400, -1);
}

void ovr_2d2c_007f(char far *name, int n)
{
    g_4bf6 = 1;
    fn_0f28_0114(name, f_2803_3611, g_2494, fn_215f_0003(7));
    fn_0fbe_000c(0);
    if (n) fn_0fbe_000c(n);
    fn_0f28_0009(f_2803_3611);
    g_4bf6 = 0;
}

void ovr_2d2c_0084(char far *name)
{
    fn_0f28_0114(name, f_2803_35fd, g_2494, 0L);
}

int ovr_2d2c_0089(struct EmcState far *s)
{
    char far *pal = 0;

    if (ARG(s, 5) != -1) pal = STR(s, 5);
    ovr_2d2c_004d(STR(s, 0), ARG(s, 1), ARG(s, 2), (unsigned)ARG(s, 3), (unsigned)ARG(s, 4), *pal ? pal : 0);
    return 1;
}

int ovr_2d2c_008e(struct EmcState far *s)
{
    ovr_2d2c_0048(STR(s, 0));
    return 1;
}

int ovr_2d2c_0093(struct EmcState far *s)
{
    ovr_2d2c_0057(STR(s, 0), ARG(s, 1), ARG(s, 2));
    return 1;
}

int ovr_2d2c_0098(struct EmcState far *s)
{
    ovr_2d2c_0034(STR(s, 0), STR(s, 1), 1);
    return 1;
}

int ovr_2d2c_009d(struct EmcState far *s)
{
    ovr_2d2c_003e();
    return 1;
}

int ovr_2d2c_00a2(struct EmcState far *s)
{
    register int i;

    ovr_2d46_0020(STR(s, 0), 3);
    f_2803_058a[0] = ovr_2d2c_00ed(3, ARG(s, 1), g_4b92);
    f_2803_058a[1] = ovr_2d2c_00ed(3, ARG(s, 2), g_4b92);
    for (i = 0; i < 20; i++) {
        g_531e[i + 3] |= 7;
        if (i % 5 == 4) g_531e[i + 3] &= 0xf8;
        if (i % 5 == 3) g_531e[i + 3] &= 0xfd;
    }
    if (ARG(s, 3))
        for (i = 0; i < 10; i++) g_531e[i + 3] &= 0xfd;
    if (ARG(s, 4))
        for (i = 0; i < 10; i++) g_531e[i + 13] &= 0xfd;
    return 1;
}

int ovr_2d2c_00a7(struct EmcState far *s)
{
    struct MT far *m;
    void far *shp;
    int mx;
    register int i;
    int v;

    m = &f_2803_1b5e[ARG(s, 0)];
    m->c00 = ARG(s, 1);
    for (mx = i = 0; i < 16; i++) {
        shp = fn_0845_04ec(f_2803_04ca[m->c00][i]);
        v = fn_1f36_01e2(shp);
        if (v > mx) mx = v;
        fn_0845_0631(shp);
    }
    m->size = mx;
    m->a[0] = ((long)ARG(s, 2) << 8) / 100;
    m->a[1] = 0x100;
    m->a[2] = ((long)ARG(s, 3) << 8) / 100;
    m->a[3] = ARG(s, 4);
    m->a[4] = ((long)ARG(s, 5) << 8) / 100;
    m->a[5] = ((long)ARG(s, 6) << 8) / 100;
    m->a[6] = ((long)ARG(s, 7) << 8) / 100;
    m->a[7] = ((long)ARG(s, 8) << 8) / 100;
    m->a[8] = 0;
    for (i = 0; i < 8; i++) {
        m->dmg[i] = ARG(s, i + 9);
        m->res[i] = ((long)ARG(s, i + 0x11) << 8) / 100;
    }
    m->atk = &m->a[0];
    m->w38 = ARG(s, 0x19);
    m->w3a = ARG(s, 0x1a);
    m->w3e = ARG(s, 0x1b);
    m->c3c = 1;
    m->w40 = ARG(s, 0x1c);
    m->w40 = ARG(s, 0x1d);
    for (i = 0; i < 5; i++) m->w42[i] = ARG(s, i + 0x1e);
    for (i = 0; i < 2; i++) {
        m->c4c[i] = ARG(s, i + 0x23);
        m->c4e[i] = ARG(s, i + 0x25);
    }
    for (i = 0; i < 3; i++) m->c50[i] = ARG(s, i + 0x27);
    return 1;
}

int ovr_2d2c_00ac(struct EmcState far *s)
{
    ovr_2d2c_002a(STR(s, 0));
    return 1;
}

void ovr_2d2c_00b1(struct Monster far *m, int item)
{
    int far *p;

    p = &m->items;
    while (*p) p = &f_2803_1cfd[*p].next;
    *p = item;
    f_2803_1cfd[item].next = 0;
}

int ovr_2d2c_00b6(struct EmcState far *s)
{
    fn_067a_084d(STR(s, 0), ARG(s, 1));
    return 0;
}

int ovr_2d2c_00bb(struct EmcState far *s)
{
    return fn_067a_0649(ARG(s, 0)) ? 1 : 0;
}

int ovr_2d2c_00c0(struct EmcState far *s)
{
    ovr_2d2c_0043();
    return 1;
}

int ovr_2d2c_00c5(struct EmcState far *s)
{
    int old;

    old = g_81dc;
    g_81dc = ARG(s, 0);
    if (ARG(s, 1) == 1) fn_0845_035b(g_adea, ARG(s, 0), g_81de);
    return old;
}

int ovr_2d2c_00ca(struct EmcState far *s)
{
    register int i;

    fn_0845_03d4(10);
    fn_1ebc_00e7();
    fn_1e59_001d(0x70, 0, 0x120, 0x78, 0);
    fn_1ebc_00fe();
    fn_231c_0048(2);
    for (i = 0; i < 8; i++)
        if (g_4dcc[i].active && g_4dcc[i].type == 0)
            fn_0b6b_0272(&g_4dcc[i], g_4dcc[i].x, g_4dcc[i].y, 1);
    ovr_2d2c_0025();
    ovr_2d3c_0020();
    g_7fd0 = ARG(s, 1);
    g_7fdf = ARG(s, 2);
    fn_1aff_030e(&g_7fd2, &g_7fd4, g_7fd0, 0x80, 0x80);
    ovr_2d2c_006b(ARG(s, 0));
    fn_231c_0008(2);
    s->ip = 0;
    return 1;
}

int ovr_2d2c_00cf(struct EmcState far *s)
{
    _DX = ARG(s, 0);
    asm mov cx,2
    asm mov di,offset g_536e
    asm add di,3
    asm push ds
    asm pop es
    asm db 8ah, 0c2h, 8ah, 0e0h
    asm rep stosw
    asm stosb
    asm mov cx,2
    asm mov di,offset g_536e
    asm add di,0dh
    asm push ds
    asm pop es
    asm db 8ah, 0c2h, 8ah, 0e0h
    asm rep stosw
    asm stosb
    return 1;
}

int ovr_2d2c_00d4(struct EmcState far *s)
{
    return ovr_2d2c_0039(ARG(s, 0));
}

void far *ovr_2d2c_00d9(int h, int idx, int far *hdr, int flags)
{
    long far *q;
    long off;
    char far *buf;
    char far *r;
    register int size;

    if (*hdr <= idx) return 0;
    q = (long far *)(hdr + 1);
    q += idx;
    off = *q;
    off += 2;
    if (!off) return 0;
    buf = fn_2037_0002(fn_215f_0003(3), 15000L);
    fn_1809_0e76(h, off, 0);
    fn_1809_084d(h, buf, 0x10L);
    size = fn_1f36_0029(buf);
    fn_1809_0e76(h, off, 0);
    fn_1809_084d(h, buf, (long)size);
    size = fn_1f36_0029(buf);
    if (flags == g_4b92 && size > 15000) {
        flags = 0;
        ovr_2d46_002a(0, g_0ed9, size);
    }
    r = fn_203b_0007((long)size, flags);
    fn_2279_025b(buf, r, (long)size);
    return r;
}

int ovr_2d2c_00de(struct EmcState far *s)
{
    g_0cf4 = ARG(s, 0);
    return 1;
}

void far *ovr_2d2c_00ed(int page, int idx, int flags)
{
    void far *src;
    void far * volatile r;      /* volatile: the original reloads r from the frame for the copy */
    register int size;

    src = fn_1f36_0064(fn_215f_0003(page), idx);
    if (src) {
        size = fn_1f36_0029(src);
        if (flags == g_4b92 && size > 15000) {
            flags = 0;
            ovr_2d46_002a(0, g_0f04, idx, size);
        }
        r = fn_203b_0007((long)size, flags);
        if (r) fn_2279_025b(src, r, (long)size);
    } else r = 0;
    return r;
}

int ovr_2d2c_00e3(int page, int idx, int n)
{
    int huge *p;

    p = fn_1f36_0064(fn_215f_0003(page), idx);
    return *(p - n);
}

void ovr_2d2c_00e8(void)
{
    register int i;
    register int j;

    for (j = 0; j < 3; j++)
        for (i = 0; i < 16; i++) {
            if (f_2803_04ca[j][i]) {
                fn_0845_144e(f_2803_04ca[j][i]);
                f_2803_04ca[j][i] = 0;
            }
            if (f_2803_040a[j][i]) {
                ovr_2d46_0043(f_2803_040a[j][i]);
                f_2803_040a[j][i] = 0;
            }
        }
}

void ovr_2d2c_0025(void)
{
    int fl;
    int d;
    register int b;
    register int dir;
    register int i;

    for (i = 0; i < 3; i++) {
        b = g_4ed0[i].block;
        if (b) {
            d = g_4ed0[i].d;
            dir = g_4ed0[i].dir;
            do {
                WALL(b, dir) += d;
                WALL(b, dir ^ 2) += d;
                fl = g_531e[WALL(b, dir)];
            } while (!(fl & 0x30));
            g_4ed0[i].block = 0;
        }
    }
}

void ovr_2d2c_00f2(int type)
{
    register int i;

    for (i = 0; i < 16; i++) {
        if (f_2803_04ca[type][i]) {
            fn_0845_144e(f_2803_04ca[type][i]);
            f_2803_04ca[type][i] = 0;
        }
        if (f_2803_040a[type][i]) {
            if (g_7fe5 == 0x1d || g_7fe5 == 0x17) fn_0845_144e(f_2803_040a[type][i]);
            else ovr_2d46_0043(f_2803_040a[type][i]);
            f_2803_040a[type][i] = 0;
        }
    }
}
