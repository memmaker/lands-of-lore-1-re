/* o2cda: 3D dungeon view renderer (wall tile map, wall decorations, monsters, floor items, compass, scene) */
#include <mem.h>
#include <stdlib.h>
#include "lol.h"

struct Deco4 { void far *p; int a, b, c; };
struct Deco {               /* 0x48 bytes, g_5a52[]: wall decorations */
    int shape[10];
    unsigned char fl[10];    /* +14 */
    int x[10];               /* +1e */
    int y[10];               /* +32 */
    char next;               /* +46 */
    unsigned char flags;     /* +47 */
};
struct Ovl { void far *p; int x, y; };
struct Fly2 { char c0; char pad1[3]; int item; char pad6[5]; char dir; char padc[5]; };   /* 0x11 bytes, g_4dcc[8] */
struct ShapeIdx { int a, b, c, d, e; };
struct Compass { int shape, x, y, flags; };
struct Pos { int x, y; };
struct Lvl { char pad[0x294]; int map[101]; };

extern char g_2083[];
extern char g_0094[], g_0098[], g_009c[];
extern int g_4eac[], g_4ac0[], g_4a9c[];
extern struct Block g_8203[];
extern struct Block far *g_4d84[18];
extern char g_00a0[], g_012b[], g_012f[];
extern int g_1f3b[][8];
extern int g_4ae8, g_4ae6, g_4ae4;
extern unsigned char g_531e[];
extern char g_53be[], g_536e[];
extern char g_0133[], g_0277[];
extern int g_4028[], g_4004[];
extern struct Lvl far *g_7fc8;
extern int g_404c[];
extern int g_7fd0, g_7fdf;
extern struct Pos g_7fd2;
extern int g_4002;
extern int g_3ff8, g_3ffa, g_3ffc, g_3ffe, g_4000;
extern void far *g_4bec, far *g_4bf0;
extern int g_4d70, g_4d72;
extern char far f_27d5_0000[];
extern int far f_2494_0000[], far f_24dc_0000[], far f_244c_0000[];
extern int g_00c2[], g_00ca[], g_00ea[];
extern int g_00b2[];
extern void far *g_7c72[];
extern void far *g_7c82, far *g_7c8e;
extern unsigned char g_00f0[], g_010e[];
extern char g_7fe5;
extern char g_0500[];
extern int far f_2803_002c[];
extern char far f_2803_0053[];
extern char g_052f[][4];
extern void far * far f_2803_04ca[][16];
extern void far * far f_2803_040a[][16];
extern char g_050f[][2];
extern struct Ovl g_7672[][4][16];
extern void far * far f_2803_00be;
extern char g_053f[];
extern struct ItemType far *g_7fb2;
extern struct Fly2 g_4dcc[];
extern struct ShapeIdx far f_24dc_0082[];
extern void far *g_4e54[];
extern void far * far f_2803_00a6[];
extern char far f_27b1_004c[][2];
extern void far *g_7c92[];
extern int g_0599[], g_05e1[], g_0629[];
extern char g_056b[], g_0547[], g_058f[], g_0671[];
extern struct Deco g_5a52[];
extern void far *g_5412[];
extern char g_0695[], g_06a7[], g_06be[];
extern void far * far f_2803_058a[];
extern unsigned g_806a;
extern int g_7fe1, g_06d5, g_06d7;
extern int g_3649;
extern char g_20db;
extern void far * far f_2803_00fe[];
extern struct Compass far f_24dc_0104[];
extern void far * far f_2803_010a[];
extern char far f_2803_030a[];
extern unsigned g_7fd6;
extern unsigned long g_06d9, g_384c;
extern char g_7fdd;
extern struct Deco4 g_4bd0;
extern char far *g_4edc;
extern void far *g_7fc0, far *g_7fc4;
extern int g_7fb6;
extern unsigned char g_06dd[];
extern char g_aa03[];
extern void far * far f_27b1_0000[];
extern char g_06e9[], g_06e1[];

void fn_1e9a_000b(int win, int x, int y, int w, int h);
void fn_1aff_0341(struct Pos party, int far *x, int far *y, int dir);
int fn_1aff_0386(int x, int s);
int fn_1aff_0002(int v, int s);
int fn_1aff_0420(int a, int b);
void fn_1aff_03b4(int far *x, int far *y, int d);
void fn_1aff_00b9(void far *a, int far *map, void far *b, int page);
int fn_1fd1_003d(void far *p, int s);
int fn_1fd1_0024(void far *p, int s);
void fn_1fd6_000a(int page, void far *p, int x, int y, int a, int flags, ...);
void far *fn_0845_04ec(void far *p);
void fn_0845_0631(void far *p);
int fn_0845_1036(void);
void fn_0845_08aa(void);
int fn_0845_04af(int x1, int y1, struct Pos p);
struct Item far *fn_080e_000b(int id);
void fn_080e_0245(int dir, int id, struct Block far *b, int asc);
int fn_1f36_0224(void far *p);
int fn_1f36_01e2(void far *p);
void fn_1ebc_0111(int x1, int y1, int x2, int y2);
void fn_1ebc_01ec(void);
unsigned char fn_2313_0000(void);
void far *fn_215f_001d(int page);
void fn_19c9_0730(void far *p);
void fn_19c9_075b(void far *p, void far *q);
void fn_19c9_0c24(int a, int b);
void fn_234e_0003(int n);
void fn_067a_026b(int n);
void fn_1e59_001d(int x1, int y1, int x2, int y2, int c);

void ovr_2cda_0020(int win, int x1, int y1, int x2, int y2);
void ovr_2cda_0025(int n, int far *a, int far *b, int win);
void ovr_2cda_002a(char x, char y, char w, int b, char cols, char rows);
void ovr_2cda_002f(char x, char y, char w, int b, char cols, char rows);
int ovr_2cda_0034(int t);
int ovr_2cda_0039(int x, int y, int far *px, int far *py, int far *pw, int far *ph, void far *shp, int mode);
int ovr_2cda_003e(struct Monster far *m, int b);
void ovr_2cda_0043(int n);
void ovr_2cda_0048(void);
void ovr_2cda_004d(void);
void ovr_2cda_0052(void);
void ovr_2cda_0057(int page);
int ovr_2cda_005c(int page);
void ovr_2cda_0061(int a);
void ovr_2cda_0066(int n, int b);
void ovr_2cda_006b(void);

#define W(k, d) (((char far *)g_4d84[k])[d])

static void setup(int block, register int dir)
{
    int b;
    int i;

    dir *= 18;
    for (i = 0; i < 18; i++) {
        b = g_4eac[i] = (block + g_2083[dir + i]) & 0x3ff;
        g_4d84[i] = &g_8203[b];
        g_4a9c[i] = g_4ac0[i] = -1;
    }
}

void ovr_2cda_0020(int win, int x1, int y1, int x2, int y2)
{
    fn_1e9a_000b(win, x1, y1 << 3, x2 - x1, (y2 - y1) << 3);
}

static void clip(char n, int far *a, int far *b, int win)
{
    register int k = g_00a0[n];

    if (win == -1 && k != 3) k++;
    *a = g_012b[k];
    *b = g_012f[k];
    if (win != -1) fn_1e9a_000b(win, g_1f3b[win][0], *a, g_1f3b[win][2], *b - *a);
}

void ovr_2cda_0025(int n, int far *a, int far *b, int win)
{
    int i;
    int k;
    int v6;
    int v8;
    int nsave;
    register int j;
    register int t;
    int d;

    nsave = n;
    j = n << 1;
    if (g_4a9c[j] != -1) {
        *a = g_4a9c[j];
        *b = g_4a9c[j + 1];
    } else {
        *a = 0;
        *b = 22;
        v6 = 0;
        v8 = 0x78;
        k = n << 1;
        n *= 18;
        for (i = 0; i < 18; i++) {
            t = W(i, g_4ae8);
            if (!(g_531e[t] & 8)) {
                d = g_0133[n + i];
                if (g_53be[t] == 0) continue;
                if (d == -40) continue;
                if (d == -41) {
                    *a = 22;
                    *b = 0;
                    break;
                }
                if (d > 0 && *b > d) *b = d;
                if (d < 0 && -d > *a) *a = -d;
            } else {
                j = (n + i) << 1;
                if (g_0277[j] > *a) {
                    *a = g_0277[j];
                    if (!(g_531e[t] & 0x10)) clip(nsave, &v6, &v8, -1);
                }
                j++;
                if (g_0277[j] < *b) {
                    *b = g_0277[j];
                    if (!(g_531e[t] & 0x10)) clip(nsave, &v6, &v8, -1);
                }
            }
            if (*b < *a) break;
        }
        *a += 14;
        *b += 14;
        g_4028[nsave] = v6;
        g_4004[nsave] = v8;
        g_4a9c[k] = *a;
        k++;
        g_4a9c[k] = *b;
    }
    ovr_2cda_0020(win, *a, 0, *b, 15);
}

void ovr_2cda_002a(char x, char y, char w, int b, char cols, char rows)
{
    int far *dst;
    int far *src;
    int i, j;

    if (g_53be[w] != 0) {
        src = (int far *)&g_7fc8[g_53be[w] - 1] + b;
        src += 0x14a;
        for (i = 0; i < rows; i++) {
            dst = &g_404c[(y + i) * 22 + x];
            for (j = 0; j < cols; j++) {
                if (x + j >= 0 && x + j < 22 && *src) *dst++ = *src++;
                else {
                    dst++;
                    src++;
                }
            }
        }
    }
}

void ovr_2cda_002f(char x, char y, char w, int b, char cols, char rows)
{
    int far *src;
    int j, i, v;

    if (g_53be[w] != 0) {
        src = (int far *)&g_7fc8[g_53be[w] - 1] + b;
        src += 0x14a;
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                if (x + j >= 0 && x + j < 22) {
                    v = (src + i * cols)[cols - 1 - j];
                    if (v) {
                        if (v & 0x4000) v -= 0x4000;
                        else v |= 0x4000;
                        g_404c[(y + i) * 22 + x + j] = v;
                    }
                }
            }
        }
    }
}

int ovr_2cda_0034(register int t)
{
    return t && !(g_531e[t] & 8);
}

static void draw_walls(register int block, int dir)
{
    int t;
    int u;

    g_4ae8 = g_0094[g_7fdf];
    g_4ae6 = g_0098[g_7fdf];
    g_4ae4 = g_009c[g_7fdf];
    asm {
        mov cx, 0x14a
        mov di, offset g_404c
        push ds
        pop es
        db 0x33, 0xc0
        rep stosw
    }
    g_4002 = ((block >> 5) + (block & 0x1f) + g_7fdf) & 1;
    if (g_4002 == 0) ovr_2cda_002a(0, 15, 1, -330, 22, 15);
    else ovr_2cda_002f(0, 15, 1, -330, 22, 15);
    setup(block, dir);

    if ((t = W(0, g_4ae6)) != 0) ovr_2cda_002a(-2, 3, t, 0x66, 3, 5);
    if ((t = W(6, g_4ae4)) != 0) ovr_2cda_002f(0x15, 3, t, 0x66, 3, 5);
    t = W(1, g_4ae6);
    u = W(2, g_4ae8);
    if (ovr_2cda_0034(t) && !(g_531e[u] & 8)) ovr_2cda_002a(2, 3, t, 0x66, 3, 5);
    else if (t && (g_531e[u] & 8)) ovr_2cda_002a(2, 3, u, 0x66, 3, 5);
    t = W(5, g_4ae4);
    u = W(4, g_4ae8);
    if (ovr_2cda_0034(t) && !(g_531e[u] & 8)) ovr_2cda_002f(0x11, 3, t, 0x66, 3, 5);
    else if (t && (g_531e[u] & 8)) ovr_2cda_002f(0x11, 3, u, 0x66, 3, 5);
    if ((t = W(2, g_4ae6)) != 0) ovr_2cda_002a(8, 3, t, 0x61, 1, 5);
    if ((t = W(4, g_4ae4)) != 0) ovr_2cda_002f(0xd, 3, t, 0x61, 1, 5);
    if (ovr_2cda_0034(W(1, g_4ae8))) ovr_2cda_002a(-4, 3, W(1, g_4ae8), 0x81, 6, 5);
    if (ovr_2cda_0034(W(5, g_4ae8))) ovr_2cda_002a(0x14, 3, W(5, g_4ae8), 0x81, 6, 5);
    if (ovr_2cda_0034(W(2, g_4ae8))) ovr_2cda_002a(2, 3, W(2, g_4ae8), 0x81, 6, 5);
    if (ovr_2cda_0034(W(4, g_4ae8))) ovr_2cda_002a(0xe, 3, W(4, g_4ae8), 0x81, 6, 5);
    if ((t = W(3, g_4ae8)) != 0) ovr_2cda_002a(8, 3, t, 0x81, 6, 5);
    if ((t = W(7, g_4ae6)) != 0) ovr_2cda_002a(0, 3, t, 0x75, 2, 6);
    if ((t = W(11, g_4ae4)) != 0) ovr_2cda_002f(0x14, 3, t, 0x75, 2, 6);
    if ((t = W(8, g_4ae6)) != 0) ovr_2cda_002a(6, 2, t, 0x51, 2, 8);
    if ((t = W(10, g_4ae4)) != 0) ovr_2cda_002f(0xe, 2, t, 0x51, 2, 8);
    if (ovr_2cda_0034(W(8, g_4ae8))) ovr_2cda_002a(-4, 2, W(8, g_4ae8), 0x9f, 10, 8);
    if (ovr_2cda_0034(W(10, g_4ae8))) ovr_2cda_002a(0x10, 2, W(10, g_4ae8), 0x9f, 10, 8);
    if ((t = W(9, g_4ae8)) != 0) ovr_2cda_002a(6, 2, t, 0x9f, 10, 8);
    if ((t = W(12, g_4ae6)) != 0) ovr_2cda_002a(3, 1, t, 0x2d, 3, 12);
    if ((t = W(14, g_4ae4)) != 0) ovr_2cda_002f(0x10, 1, t, 0x2d, 3, 12);
    t = W(12, g_4ae8);
    if (!(g_531e[t] & 8)) ovr_2cda_002a(-13, 1, t, 0xef, 16, 12);
    t = W(14, g_4ae8);
    if (!(g_531e[t] & 8)) ovr_2cda_002a(0x13, 1, t, 0xef, 16, 12);
    if ((t = W(13, g_4ae8)) != 0) ovr_2cda_002a(3, 1, t, 0xef, 16, 12);
    t = W(15, g_4ae6);
    u = W(17, g_4ae4);
    if (t) ovr_2cda_002a(0, 0, t, 0, 3, 15);
    if (u) ovr_2cda_002f(0x13, 0, u, 0, 3, 15);
}

static void blit(void far *shp, void far *tbl, int x, int y, int flags, void far *pal)
{
    int f;

    f = (flags & 0x10) ? 1 : 0;
    f |= (flags & 0x20) ? 0x1000 : 0;
    f |= (flags & 0x40) ? 2 : 0;
    if (f & 0x1000) {
        if (tbl == 0) fn_1fd6_000a(g_4d72, shp, x, y, 0xd, 4 | f | 0x1100, pal, 1, g_4bec, g_4bf0, g_3ffc, g_3ffa);
        else fn_1fd6_000a(g_4d72, shp, x, y, 0xd, 4 | f | 0x9100, tbl, pal, 1, g_4bec, g_4bf0, g_3ffc, g_3ffa);
    } else {
        if (tbl == 0) fn_1fd6_000a(g_4d72, shp, x, y, 0xd, 4 | f | 0x100, pal, 1, g_3ffc, g_3ffa);
        else fn_1fd6_000a(g_4d72, shp, x, y, 0xd, 4 | f | 0x8100, tbl, pal, 1, g_3ffc, g_3ffa);
    }
}

static void draw_wallshape(void far *shp, void far *tbl, int n, int c, int dx, int dy, int flags)
{
    int k;
    int idx;
    int yoff;
    void far *pal;
    int dist;

    yoff = 0;
    c = f_27d5_0000[(g_7fdf << 5) + c];
    k = g_00a0[n] * 5 + c / 5;
    dist = g_00c2[k];
    idx = (n << 5) + c;
    g_3ffe = f_2494_0000[idx] + 0x78;
    if (flags & 1) {
        g_3ffc = g_3ffa = f_24dc_0000[g_3ffe - 0x38];
        dist += 2;
    } else if (flags & 2) {
        g_3ffc = g_00b2[g_00a0[n] * 2];
        g_3ffa = g_00b2[g_00a0[n] * 2 + 1];
        yoff = g_00ea[g_00a0[n]];
        dist += 2;
    }
    if (g_3ffc == 0 || g_3ffa == 0) return;
    n = fn_1fd1_003d(shp, g_3ffa) >> 1;
    if (dx) dx = fn_1aff_0002(dx, g_3ffc);
    if (dy) dy = fn_1aff_0002(dy, g_3ffa);
    g_4000 = f_244c_0000[idx] + dx + 0xc8;
    g_3ffe = g_3ffe + 4 - n + dy - yoff;
    if (dist > 7) dist = 7;
    pal = g_7c72[dist];
    g_3ff8 = fn_1fd1_0024(shp, g_3ffc);
    g_4000 -= g_3ff8 >> 1;
    g_3ffe -= n;
    blit(fn_0845_04ec(shp), tbl, g_4000, g_3ffe, flags, pal);
}

int ovr_2cda_0039(int x, int y, int far *px, int far *py, int far *pw, int far *ph, void far *shp, int mode)
{
    register int r;

    fn_1aff_0341(g_7fd2, &x, &y, g_7fdf);
    if (y < 0) {
        *px = *py = *pw = *ph = 0;
        return 0;
    }
    r = y >> 5;
    *py = g_00f0[r];
    *px = fn_1aff_0386(x, g_010e[r]) + 0xc8;
    *pw = *ph = f_24dc_0000[g_3ffe - 0x38];
    if (mode == 0) *py -= fn_1fd1_003d(shp, g_3ffa) >> 1;
    else *py = ((0x78 - *py) >> 1) + (fn_1fd1_003d(shp, g_3ffa) >> 1);
    return r;
}

static void far *draw_obj(void far *shp, void far *tbl, int x, int y, int dx, int dy, int flags, int dist, int c)
{
    int half;
    void far *pal;
    void far *tbl2;
    int f;
    int r;

    if (flags & 0x80) {
        flags &= ~0x80;
        tbl2 = tbl;
        tbl = 0;
    } else tbl2 = g_7c82;
    r = ovr_2cda_0039(x, y, &g_4000, &g_3ffe, &g_3ffc, &g_3ffa, shp, c);
    if (dist == -1) {
        r = r / 3 - 1;
        r = 7 - r;
        r = r < 7 ? r : 7;
        r = r > 0 ? r : 0;
        pal = g_7c72[r];
    } else {
        setmem(g_0500, 15, dist);
        tbl = g_0500 - 1;
        pal = g_7c8e;
    }
    f = (flags & 0x10) ? 1 : 0;
    f |= (flags & 0x20) ? 0x1000 : 0;
    f |= (flags & 0x40) ? 2 : 0;
    if (g_7fe5 == 0x16) {
        if (pal) ((char far *)pal)[0xff] = 0;
    } else f |= 0x2000;
    if (dx) g_4000 += fn_1aff_0002(dx, g_3ffc);
    if (dy) g_3ffe += fn_1aff_0002(dy, g_3ffa);
    half = fn_1fd1_003d(shp, g_3ffa) >> 1;
    if (f & 0x1000) {
        if (tbl == 0) fn_1fd6_000a(g_4d72, shp, g_4000, g_3ffe, 0xd, 0x24 | f | 0x100, pal, 0, g_4bec, g_4bf0, g_3ffc, g_3ffa, tbl2);
        else fn_1fd6_000a(g_4d72, shp, g_4000, g_3ffe, 0xd, 0x24 | f | 0x8100, tbl, pal, 0, g_4bec, g_4bf0, g_3ffc, g_3ffa, tbl2);
    } else {
        if (tbl == 0) fn_1fd6_000a(g_4d72, shp, g_4000, g_3ffe, 0xd, 0x24 | f | 0x100, pal, 1, g_3ffc, g_3ffa, tbl2);
        else fn_1fd6_000a(g_4d72, shp, g_4000, g_3ffe, 0xd, 0x24 | f | 0x8100, tbl, pal, 1, g_3ffc, g_3ffa, tbl2);
    }
    g_3ff8 = fn_1fd1_0024(shp, g_3ffc);
    g_4000 -= g_3ff8 >> 1;
    g_3ffe -= half;
    return pal;
}

static int frame0(struct Monster far *m, int base)
{
    int r;

    if (base) {
        switch (m->mode) {
        case 13: r = -1; break;
        default: r = base + m->anim;
        }
    } else if (m->hitDmg) r = 12;
    else switch (m->mode) {
    case 13: r = -1; break;
    case 8: r = m->c15 + 13; break;
    case 11: r = 14; break;
    case 5:
        if (m->hitDmg) r = 12;
        else if (m->type->flags & 4) r = 13;
        else r = 0;
        break;
    default:
        if (m->hitDmg) r = 12;
        else r = base + m->anim;
    }
    return r;
}

static int frame1(struct Monster far *m)
{
    int r, hp, b;

    hp = fn_1aff_0420(m->type->maxHp, f_2803_002c[fn_0845_1036()]);
    if (m->hp > (hp >> 1)) b = 0;
    else if (m->hp > (hp >> 2)) b = 4;
    else b = 8;
    switch (m->mode) {
    case 11: r = 12; break;
    case 13: r = m->c15 + 12; break;
    case 8: r = b + m->c15; break;
    default: r = b;
    }
    return r;
}

static int frame3(struct Monster far *m, int base)
{
    int r;

    switch (m->mode) {
    case 8: r = m->c15 + 6; break;
    case 11: r = 5; break;
    case 5:
        if (m->hitDmg) r = 5;
        else r = 6;
        break;
    default:
        if (m->hitDmg) r = 5;
        else r = m->anim;
        break;
    }
    return r;
}

static int frame2(struct Monster far *m)
{
    return m->c15 < 13 ? m->c15 : 13;
}

/* register/stack-slot choices differ; original bytes transplanted (with following statics) */
/* NONMATCHING */
int ovr_2cda_003e(struct Monster far *m, register int b)
{
    int r;

    switch (f_2803_0053[m->type->c00]) {
    case 0: r = frame0(m, b); break;
    case 1: r = frame1(m); break;
    case 2: r = frame2(m); break;
    case 3: r = frame3(m, b); break;
    default: break;
    }
    return r;
}

static void draw_monster(int mon)
{
    struct Monster far *m;
    struct Ovl *pp;
    void far *ref;
    char far *ovl;
    int h12;
    int i;
    int unused;
    int frame;
    int k;
    int fl;
    int w;
    int h;
    void far *shp;
    void far *pal;
    int col;
    char tbl[256];
    register int si;
    register int di;
    int c;

    m = &f_2803_15fa[mon];
    si = g_052f[g_7fdf][m->facing];
    frame = ovr_2cda_003e(m, si & ~0x10);
    if (frame != -1) {
        di = m->flags & 7;
        fl = (m->type->flags & 0x200) ? 1 : 0;
        si &= 0x10;
        ref = f_2803_04ca[m->type->c00][frame];
        if (m->type->flags & 0x800) si |= 0x20;
        shp = fn_0845_04ec(ref);
        if (di) {
            ovl = f_2803_040a[m->type->c00][frame & 0xf];
            ovl += ((unsigned char far *)shp)[10] * (di - 1);
        } else ovl = 0;
        pal = draw_obj(shp, ovl, m->x + g_050f[m->c0b][0], m->y + g_050f[m->c0b][1], 0, 0, si | 1, -1, fl);
        fn_0845_0631(shp);
        for (i = 0; i < 4; i++) {
            if ((k = m->c2a[i] - 1) == -1) break;
            pp = &g_7672[m->type->c00][k][frame];
            shp = fn_0845_04ec(pp->p);
            if (pp->p) {
                di = fn_1aff_0002(pp->x, g_3ffc);
                fn_1aff_0002(pp->y, g_3ffa);
                if (si) fn_1fd1_0024(shp, g_3ffc);
                blit(shp, 0, g_4000, g_3ffe, si | 1, pal);
            }
            fn_0845_0631(shp);
        }
    } else {
        ref = f_2803_04ca[m->type->c00][0];
        shp = fn_0845_04ec(ref);
        ovr_2cda_0039(m->x + g_050f[m->c0b][0], m->y + g_050f[m->c0b][1], &g_4000, &g_3ffe, &g_3ffc, &g_3ffa, shp, fl);
        fn_0845_0631(shp);
    }
    if (!m->hitDmg) return;
    shp = fn_0845_04ec(ref);
    di = fn_1fd1_0024(shp, g_3ffc) >> 1;
    h12 = fn_1fd1_003d(shp, g_3ffa) >> 1;
    si = m->mode != 13 ? m->type->maxHp / (m->hitDmg & 0x7fff) : m->c15 << 1;
    shp = fn_0845_04ec(f_2803_00be);
    switch (m->type->flags & 0xc000) {
    case 0x4000: col = 0x3f; break;
    case 0x8000: col = 0xf; break;
    case 0xc000: col = 0x4a; break;
    default: col = 0;
    }
    if (col) {
        for (c = 0; c < 256; c++) {
            tbl[c] = c;
            if (c >= 2 && c <= 7) tbl[c] = tbl[c] + col;
        }
    }
    di += m->dx;
    h12 += m->dy;
    if (si > 4) si = 4;
    if (si < 1) si = 1;
    w = g_3ffc / si;
    h = g_3ffa / si;
    fn_1fd6_000a(g_4d72, shp, g_4000 + di, g_3ffe + h12, 0xd, 0x124, (char far *)tbl, col ? 1 : 0, w, h);
}

static void draw_block(int n)
{
    struct Item far *it;
    struct Item far *q;
    int x;
    int y;
    void far *shp;
    struct Block far *blk;
    register int si;
    register int di;
    int cx, dx;

    blk = g_4d84[n];
    si = blk->mon;
    q = fn_080e_000b(si);
    if (blk->drawDir != g_7fdf) {
        blk->draw = 0;
        blk->drawDir = g_7fdf;
        while (si) {
            q = fn_080e_000b(si);
            fn_080e_0245(g_7fdf, si, g_4d84[n], 1);
            q = fn_080e_000b(si);
            si = q->next;
        }
    }
    si = blk->draw;
    while (si) {
        if (si & 0x8000) {
            si &= 0x7fff;
            if (n < 15) draw_monster(si);
            si = *(int far *)&f_2803_15fa[si].c02;
            continue;
        }
        it = &f_2803_1cfd[si];
        shp = 0;
        it = &f_2803_1cfd[si];
        x = g_053f[si & 7] << 1;
        y = g_053f[(si >> 1) & 7] + 5;
        if (it->sub < 2 || (it->sub >= 2 && n < 15)) {
            if (it->sub >= 2) y -= (it->sub - 1) * 6;
            di = 0;
            if ((g_7fb2[it->type].flags & 0x1000) && !(it->flags & 0xc000)) {
                cx = g_7fb2[it->type].shape;
                if (g_7fb2[it->type].flags & 0x800) cx = 7;
                for (dx = 0; dx < 8; dx++)
                    if (g_4dcc[dx].c0 && g_4dcc[dx].item == si) break;
                if (f_24dc_0082[cx].e && ((it->x ^ it->y) & 0x20)) di |= f_24dc_0082[cx].e;
                di |= f_24dc_0082[cx].d;
                if (dx != 8) {
                    si = g_7fdf - (g_4dcc[dx].dir >> 1);
                    switch (si) {
                    case 0: si = f_24dc_0082[cx].b; break;
                    case -3: case 1: si = f_24dc_0082[cx].c; break;
                    case -1: case 3: di |= 0x10; si = f_24dc_0082[cx].c; break;
                    case -2: case 2: si = f_24dc_0082[cx].a; break;
                    }
                    shp = fn_0845_04ec(g_4e54[si]);
                }
                y += fn_1f36_0224(shp) >> 2;
            } else if (g_7fb2[it->type].flags & 0x40)
                shp = fn_0845_04ec(f_2803_00a6[g_7fb2[it->type].shape]);
            else
                shp = fn_0845_04ec(g_7c92[f_27b1_004c[g_7fb2[it->type].shape][0]]);
            if (shp) {
                draw_obj(shp, 0, it->x, it->y, x, y, di, -1, 0);
                fn_0845_0631(shp);
            }
        }
        si = it->drawNext;
    }
}

/* register/stack-slot choices differ; original bytes transplanted (with following statics) */
/* NONMATCHING */
void ovr_2cda_0043(int n)
{
    void far *pal;
    int w;
    int h;
    int d;
    int c;
    int x;
    int y;
    int flg;
    int s;
    int i;
    int dist;
    int ox;
    int oy;
    void far *ref;
    void far *shp;
    register int si;
    register int di;

    pal = 0;
    for (i = 1; i >= 0; i--) {
        si = (n << 1) + i;
        w = g_0599[si];
        h = g_05e1[si];
        s = g_056b[si];
        c = s < 0 ? -s : s;
        dist = g_00ca[g_00a0[n] * 5] + 2;
        if (dist > 7) dist = 7;
        if (w == 0 || h == 0) continue;
        d = (g_0547[si] + g_7fdf) & 3;
        di = g_536e[W(n, d)];
        while (di > 0) {
            if ((g_5a52[di].flags & 8) && n != 3 && n != 9 && n != 13) {
                di = g_5a52[di].next;
                continue;
            }
            if (g_058f[c] == 1 && ((g_5a52[di].flags & 2) || ((g_5a52[di].flags & 4) && g_4002))) s = -s;
            ox = 0;
            oy = 0;
            if (g_5a52[di].fl[c] & 1) {
                ox = g_5a52[di].x[c];
                oy = g_5a52[di].y[c];
                c = g_058f[c];
                pal = g_7c72[dist];
            } else if (g_5a52[di].shape[c] != -1) {
                w = 0x100;
                h = 0x100;
                pal = g_7c8e;
            }
            if (g_5a52[di].shape[c] != -1) {
                ref = g_5412[g_5a52[di].shape[c]];
                shp = fn_0845_04ec(ref);
                if (shp) {
                    if (s >= 0) {
                        x = g_0629[si] + fn_1aff_0002(g_5a52[di].x[c], w) + ox;
                        flg = 0x104;
                    } else {
                        x = g_0629[si] + fn_1aff_0002(g_5a52[di].x[c], w) + ox;
                        if (g_056b[si] == s) {
                            x = g_0629[si] - fn_1aff_0002(g_5a52[di].x[c], w);
                            x -= fn_1fd1_0024(shp, w) + ox;
                        }
                        flg = 0x105;
                    }
                    y = g_0671[si] + fn_1aff_0002(g_5a52[di].y[c], h) + oy;
                    fn_1fd6_000a(g_4d72, shp, x + 0x70, y, 0xd, flg, pal, 1, w, h);
                    fn_0845_0631(shp);
                    if ((g_5a52[di].flags & 1) && c >= 0 && c <= 3) {
                        shp = fn_0845_04ec(ref);
                        x += fn_1fd1_0024(shp, w);
                        flg ^= 1;
                        fn_1fd6_000a(g_4d72, shp, x + 0x70, y, 0xd, flg, pal, 1, w, h);
                        fn_0845_0631(shp);
                    }
                }
            }
            di = g_5a52[di].next;
            c = g_056b[si] < 0 ? -g_056b[si] : g_056b[si];
        }
    }
}

/* register/stack-slot choices differ; original bytes transplanted (with following statics) */

void ovr_2cda_0048(void)
{
    int off;
    int a;
    int b;
    int a2;
    int b2;
    int n;
    int fl;
    register int si;
    register int di;

    for (di = 0; di < 18; di++) {
        n = g_0695[di];
        si = W(n, g_4ae8);
        ovr_2cda_0025(n, &a, &b, 13);
        if (b > a) {
            ovr_2cda_0043(n);
            fl = g_531e[si];
            if (n == 16) fl |= 0x80;
            ovr_2cda_0066(n, 0);
            if (g_4d84[n]->mon && (fl & 0x80)) draw_block(n);
            ovr_2cda_0066(n, 1);
            if (g_531e[si] & 8) {
                off = (si - g_06a7[si]) * 20;
                clip(n, &a2, &b2, 13);
                draw_wallshape(fn_0845_04ec(f_2803_058a[g_06be[si]]), 0, n, 10, 0, -off, 2);
                ovr_2cda_0025(n, &a2, &b2, 13);
            }
        }
    }
}

void ovr_2cda_004d(void)
{
    register int si;

    if (!(g_806a & 0x4000)) return;
    if (g_7fe1 == -1) {
        g_06d5 = -1;
        g_7fe1 = g_7fdf << 6;
    }
    si = ((g_7fe1 + 4) >> 3) & 0x1f;
    if (si == g_06d5) return;
    g_06d5 = si;
    if (!g_3649) fn_1ebc_0111(0x125, 5, 0x13c, 0x18);
    fn_1fd6_000a(g_3649, f_2803_00fe[g_20db], 0x126, 3, 0, 0);
    fn_1fd6_000a(g_3649, f_2803_010a[f_24dc_0104[si].shape], f_24dc_0104[si].x + 0x12a, f_24dc_0104[si].y + 9, 0,
                 f_24dc_0104[si].flags | 0x300, f_2803_030a, 1);
    fn_1fd6_000a(g_3649, f_2803_010a[f_24dc_0104[si].shape], f_24dc_0104[si].x + 0x12b, f_24dc_0104[si].y + 8, 0,
                 f_24dc_0104[si].flags);
    if (!g_3649) fn_1ebc_01ec();
}

/* register/stack-slot choices differ; original bytes transplanted (with following statics) */

void ovr_2cda_0052(void)
{
    int sgn;
    int dx;

    if (!(g_806a & 0x4000)) return;
    if (g_7fd6 & 4) return;
    if (g_7fe1 == -1) goto reset;
    if (g_06d9 >= g_384c) return;
    if ((g_7fdf << 6) == g_7fe1 && g_06d7 == 0) return;
    g_06d9 = g_384c + 3;
    sgn = g_06d7 < 0 ? -1 : 1;
    if (g_06d7) g_06d7 -= (((g_06d7 < 0 ? -g_06d7 : g_06d7) >> 4) + 2) * sgn;
    if (g_7fdd) dx = fn_2313_0000() - g_7fe1;
    else dx = (g_7fdf << 6) - g_7fe1;
    if (dx <= -0x80) dx += 0x100;
    if (dx >= 0x80) dx -= 0x100;
    dx >>= 2;
    g_06d7 += dx;
    g_06d7 = g_06d7 < 0x18 ? g_06d7 : 0x18;
    g_06d7 = g_06d7 > -0x18 ? g_06d7 : -0x18;
    g_7fe1 += g_06d7;
    if (g_7fe1 < 0) g_7fe1 += 0x100;
    if (g_7fe1 > 0xff) g_7fe1 -= 0x100;
    if ((g_7fe1 >> 6) == g_7fdf && g_06d7 < 2 && abs(dx) < 4) {
        g_7fe1 = g_7fdf << 6;
reset:
        g_06d7 = 0;
    }
    ovr_2cda_004d();
}

void ovr_2cda_0057(register int page)
{
    void far *shp;

    if (g_4bd0.p) {
        shp = fn_0845_04ec(g_4bd0.p);
        fn_1fd6_000a(page, shp, g_4bd0.a, g_4bd0.b, 2, 0);
        if (g_4bd0.c & 1) fn_1fd6_000a(page, shp, g_4bd0.a + fn_1f36_01e2(shp), g_4bd0.b, 2, 1);
    }
}

/* register/stack-slot choices differ; original bytes transplanted (with following statics) */

int ovr_2cda_005c(register int page)
{
    void far *shp;
    void far *buf;

    if (g_4bd0.p) {
        buf = fn_215f_001d(page);
        fn_19c9_0730(buf);
        shp = fn_0845_04ec(g_4bd0.p);
        fn_1fd6_000a(page, shp, g_4bd0.a, g_4bd0.b, 2, 0);
        fn_19c9_075b(buf, g_4edc);
        return 1;
    }
    return 0;
}

/* register/stack-slot choices differ; original bytes transplanted (with following statics) */

void ovr_2cda_0061(register int a)
{
    if (a && a != g_4d72) {
        g_4d72 ^= g_4d70;
        g_4d70 ^= g_4d72;
        g_4d72 ^= g_4d70;
        fn_0845_08aa();
    }
    if (a && a != g_4d72) {
        g_4d72 ^= g_4d70;
        g_4d70 ^= g_4d72;
        g_4d72 ^= g_4d70;
        fn_0845_08aa();
    }
    draw_walls(g_7fd0, g_7fdf);
    fn_1aff_00b9(g_7fc4, g_404c, g_7fc0, g_4d72);
    ovr_2cda_0048();
    if (!a) {
        ovr_2cda_0057(g_4d72);
        fn_234e_0003(2);
        fn_19c9_0c24(g_4d72, g_4d70);
        g_4d72 ^= g_4d70;
        g_4d70 ^= g_4d72;
        g_4d72 ^= g_4d70;
        fn_1ebc_01ec();
    }
    fn_067a_026b(0);
    ovr_2cda_004d();
    g_7fb6 = 0;
}

/* register/stack-slot choices differ; original bytes transplanted (with following statics) */

void ovr_2cda_0066(n, b)
register int n;
int b;
{
    int x;
    int y;
    int k;
    int fl;
    int w;
    void far *tbl;
    register int j;

    fl = ((char far *)g_4d84[n])[9];
    if (!(fl & 0xf0)) return;
    k = b ? 0 : 2;
    for (j = 0; j < 2; j++, k++) {
        if (!(fl & (0x10 << k))) continue;
        x = 0x80;
        y = g_06dd[k];
        w = k == 3 ? 0x80 : 0x20;
        tbl = k == 3 ? (void far *)g_aa03 : 0;
        fn_1aff_03b4(&x, &y, g_7fdf);
        x = ((g_4eac[n] & 0x1f) << 8) | x;
        y = ((g_4eac[n] >> 5) << 8) | y;
        draw_obj(fn_0845_04ec(f_27b1_0000[k]), tbl, x, y, 0, k == 1 ? -20 : 0, w, -1, 0);
    }
}

/* register/stack-slot choices differ; original bytes transplanted (with following statics) */
/* NONMATCHING */
void ovr_2cda_006b(void)
{
    int a;
    int b;
    int k;
    int x;
    struct Item far *it;
    void far *shp;
    register int si;
    register int di;

    setup(g_7fd0, g_7fdf);
    fn_1e59_001d(0x70, 0, 0x11f, 0x77, 0);
    for (di = 0; di < 2; di++) {
        ovr_2cda_0025(g_06e9[di], &a, &b, 13);
        si = g_4d84[g_06e9[di]]->draw;
        k = (di << 7) + 1;
        while (si) {
            if (si & 0x8000) {
                si &= 0x7fff;
                si = *(int far *)&f_2803_15fa[si].c02;
                continue;
            }
            it = &f_2803_1cfd[si];
            if ((it->flags & 0x4000) && fn_0845_04af(it->x, it->y, g_7fd2) < 0x140) {
                x = g_06e1[si & 7] << 1;
                si = g_06e1[(si >> 1) & 7] + 5;
                if (it->sub >= 2) si -= (it->sub - 1) * 6;
                if (g_7fb2[it->type].flags & 0x40)
                    shp = fn_0845_04ec(f_2803_00a6[g_7fb2[it->type].shape]);
                else
                    shp = fn_0845_04ec(g_7c92[f_27b1_004c[g_7fb2[it->type].shape][0]]);
                draw_obj(shp, 0, it->x, it->y, x, si, 0, k, 0);
                fn_0845_0631(shp);
            }
            si = it->drawNext;
            k++;
        }
    }
}
