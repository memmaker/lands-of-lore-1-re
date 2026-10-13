/* o2d86: a new party member joins (portrait slide-in animation, add to the party list) */
#include <stdio.h>
#include "lol.h"

struct anim { char pad[8]; int w, h; };
struct XY { int x, y; };
struct Join { int a, b, c; unsigned snd; };
struct Ctx { char pad[0xc]; int sp; char pad2[0x1e]; int stack[1]; };
extern char g_1314[], g_1320[], g_132f[], g_133b[], g_1348[], g_1355[], g_137d[], g_138a[];
extern char g_13b2[], g_13be[], g_13e5[], g_13fb[];
extern struct XY g_12fc[];
extern struct Join g_12c4[];
extern void far *g_4d5a, far *g_4d56, far *g_36a7;
extern void far *g_4bec, far *g_4bf0;
extern long g_3850;
extern char g_7fd9, g_81fd;
extern char g_81f2[];
extern int far f_27dd_0000[][14];
extern int far f_2803_3625[];
void ovr_2ded_002f(char far *str, int a, int b, char far *p);
void fn_1dbc_0004(int a, int b, int c, int d, int e, int f, int g, int h);
void far *fn_215f_0003(int p);
void far *fn_215f_001d(int p);
void fn_2279_025b(void far *s, void far *d, long n);
int fn_1e74_000f(int n);
void fn_1e59_001d(int a, int b, int c, int d, int e);
char far *fn_0845_06f8(int id);
void fn_0845_07b3(char far *s, int x, int y, int fg, int bg, int f);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void ovr_2e22_002f(int a);
void ovr_2e22_002a(char far *s);
void fn_067a_0649(int n);
void fn_067a_0401(long v);
struct anim far *ovr_2dfd_0020(char far *name, void far *buf, void far *pal, int a, long b);
void ovr_2dfd_0025(struct anim far *p);
void ovr_2dfd_002a(struct anim far *p, int frame, int x, int y, int c, int d, void far *e, void far *f);
void ovr_2ce1_007f(char far *msg);
void fn_0845_0d5e(struct anim far *p, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m);
void fn_0845_08a5(char far *fmt, int a, int b, int c, ...);
void fn_0845_15d9(int n);
void fn_0845_08aa(void);
void fn_0845_01c4(int kind, char far *fmt, ...);
void ovr_2ceb_0020(void);

void ovr_2d86_0020(void)
{
    ovr_2ded_002f(g_1314, 3, 3, 0);
    fn_1dbc_0004(8, 0, 0xd8, 0, 0x60, 0x78, 3, 3);
    fn_2279_025b(fn_215f_0003(3), g_4d56, 0xfa00L);
}

void ovr_2d86_0025(int a, int b)
{
    int page;
    int y;

    if (b > 9) b = 9;
    fn_2279_025b(g_4d56, fn_215f_0003(3), 0xfa00L);
    fn_1dbc_0004(0xd8, 0, 8, 0, 0x60, 0x78, 3, 3);
    y = (a + 1) * 9 + b + 1;
    fn_1dbc_0004(0x70, 0, 0xc, 0, 0x57, 0xf, 2, 2);
    fn_1dbc_0004(0xc9, 1, 0x11, 0xf, 6, y, 2, 2);
    fn_1dbc_0004(0xd0, 1, 0x59, 0xf, 6, y, 2, 2);
    page = fn_1e74_000f(2);
    fn_1e59_001d(0x15, 0xf, 0x59, y + 0xf, 0xce);
    fn_1dbc_0004(0x70, 0x10, 0xc, y + 0xf, 0x57, 0xe, 2, 2);
    y = 0xf;
    for (b = 0; b < 7; b++) {
        if (g_81f2[b] != -1) {
            if (g_7fd9 == b)
                fn_0845_07b3(fn_0845_06f8(f_27dd_0000[g_81f2[b]][8]), 0x18, y, 0x84, 0, 0);
            else
                fn_0845_07b3(fn_0845_06f8(f_27dd_0000[g_81f2[b]][8]), 0x18, y, 1, 0, 0);
            y += 9;
        }
    }
    fn_1e74_000f(page);
    fn_1ebc_00e7();
    fn_1dbc_0004(8, 0, 8, 0, 0x60, 0x78, 3, 0);
    fn_1ebc_00fe();
}

void ovr_2d86_002a(int ch, int n, int slot)
{
    struct anim far *p;
    int x0, y0;
    int x, y;
    int tx, ty;
    char buf[14];
    int i;

    tx = f_2803_3625[ch] + 0x10;
    ty = 0xa0;
    if (slot != 1) {
        ovr_2d86_0020();
        for (i = 0; i < 9; i++) {
            g_3850 = 1;
            ovr_2d86_0025(slot, i);
            while (g_3850 != 0) ;
        }
    }
    fn_1ebc_00e7();
    fn_2279_025b(fn_215f_001d(0), g_4d5a, 0xfa00L);
    fn_1ebc_00fe();
    x0 = g_12fc[slot].x + 0x20;
    y0 = g_12fc[slot].y + 5;
    ovr_2e22_002f(0);
    sprintf(buf, g_1320, n, g_81fd == 0 ? 0x45 : g_81fd == 1 ? 0x46 : 0x47);
    ovr_2e22_002a(buf);
    ovr_2e22_002a(g_132f);
    ovr_2e22_002a(g_133b);
    fn_067a_0649(g_12c4[n].snd);
    fn_067a_0401(0x5fL);
    if ((p = ovr_2dfd_0020(g_1348, fn_215f_0003(7), g_36a7, 1, 0L)) == 0) ovr_2ce1_007f(g_1355);
    fn_067a_0649(0x80);
    fn_0845_0d5e(p, 0, 0x19, 5, f_2803_3625[ch], 0x94, 0, 0, 0, 0, 0, 0, 0, 1);
    fn_067a_0401(0x80L);
    fn_0845_0d5e(p, 0x1a, 0x34, 5, f_2803_3625[ch], 0x94, 0, 0, 0, 0, 0, 0, 0, 1);
    for (i = 0x10; i >= 0; i--) {
        g_3850 = 1;
        fn_2279_025b(g_4d5a, fn_215f_001d(2), 0xfa00L);
        x = x0 + (int)((unsigned long)(((long)(tx - x0) << 8) / 16 * i) >> 8);
        y = y0 + (int)((unsigned long)(((long)(ty - y0) << 8) / 16 * i) >> 8);
        ovr_2dfd_002a(p, 0x33, x - 0x10, y - 0x10, 2, 0x5000, g_4bec, g_4bf0);
        fn_1dbc_0004(x - 0x10, y - 0x10, x - 0x10, y - 0x10, p->w + 0x30, p->h + 0x30, 2, 0);
        while (g_3850 != 0) ;
    }
    ovr_2dfd_0025(p);
    if ((p = ovr_2dfd_0020(g_137d, fn_215f_0003(7), g_36a7, 1, 0L)) == 0) ovr_2ce1_007f(g_138a);
    fn_067a_0401(0xa8L);
    fn_0845_0d5e(p, 0, 8, 3, x0 - 0x2c, y0 - 0x26, 0, 0, 0, 0, 0, 0, 0, 1);
    ovr_2dfd_0025(p);
    if ((p = ovr_2dfd_0020(g_13b2, fn_215f_0003(7), g_36a7, 1, 0L)) == 0) ovr_2ce1_007f(g_13be);
    fn_0845_0d5e(p, 0, 6, 5, g_12fc[slot].x, g_12fc[slot].y, 0, 0, 0, 0, 0, 0, 0, 0);
    ovr_2dfd_0025(p);
    fn_0845_08a5(g_13e5, 0, 1, 0, (char far *)buf);
    if ((p = ovr_2dfd_0020(buf, fn_215f_0003(7), g_36a7, 1, 0L)) == 0) ovr_2ce1_007f(g_13fb);
    ((void (far *)(int, int))fn_067a_0401)(g_12c4[n].snd, 0);
    fn_0845_0d5e(p, g_12c4[n].b, g_12c4[n].c, g_12c4[n].a, g_12fc[slot].x, g_12fc[slot].y, 0, 0, 0, 0, 0, 0, 0, 0);
    ovr_2dfd_0025(p);
    fn_0845_15d9(2);
    fn_0845_08aa();
}

int ovr_2d86_002f(int ch, int n)
{
    int i;
    int f;
    int slot;

    for (f = i = 0; i < 7; i++) {
        if (!f && g_81f2[i] == -1) {
            f = 1;
            slot = i;
        }
        if (g_81f2[i] == ch) {
            fn_0845_01c4(2, fn_0845_06f8(0x42d0));
            return 0;
        }
    }
    if (ch > 1) ovr_2d86_002a(n, ch, slot - 1);
    g_81f2[slot] = ch;
    ovr_2ceb_0020();
    return 1;
}

int ovr_2d86_0034(struct Ctx far *c)
{
    ovr_2d86_002f(c->stack[c->sp], c->stack[c->sp + 1]);
    return 1;
}
