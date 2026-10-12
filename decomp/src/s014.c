/* s014: inventory bar (48 slots, 9 visible, scrolling, item combination animation) */
#include "lol.h"

struct Btn { char pad[0x1e]; int x, y; char pad22[0x0c]; unsigned flags; char pad30[8]; int w38; };

extern char far f_2803_0000[];
extern void far * far f_2803_00a6[];
extern int far f_27d3_0000[];
extern int g_7fe6[48];
extern int g_8046, g_3649;
extern char far *g_4d56;
extern long g_369f;
extern unsigned long g_3850;

void far *fn_0845_0c08(int item);
void far *fn_0845_04ec(void far *name);
void fn_0845_0631(void far *p);
void fn_1fd6_000a(int page, void far *p, int x, int y, int a, int flags, ...);
void fn_1ebc_0111(int x1, int y1, int x2, int y2);
void fn_1ebc_01ec(void);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_09aa_0007(int n, int md);
int fn_0845_0ac7(void);
void fn_0845_0acf(int item);
char far *fn_215f_0003(int page);
void fn_2279_025b(char far *d, char far *s, long n);
void far *ovr_2dfd_0020(char far *name, char far *buf, long size, int a, long b);
void ovr_2dfd_002a(void far *p, int a, int b, int c, int d, int e);
void ovr_2dfd_0025(void far *p);
void fn_1dbc_0004(int a, int b, int c, int d, int e, int f, int g, int h);
void fn_17d6_0006(int a);
void fn_07bc_044c(int it);
int fn_07bc_012d(int type, int flags, int flags2);

void fn_0c59_0377(void);

void fn_0c59_000d(int page, int item, int x, int y)
{
    void far *p;

    if (item) {
        p = fn_0845_04ec(fn_0845_0c08(item));
        fn_1fd6_000a(page, p, x, y, 0, 0);
        fn_0845_0631(p);
    }
}

void fn_0c59_0055(int slot)
{
    int f;
    register int i;
    register int x;

    x = f_27d3_0000[slot];
    i = slot + g_8046;
    if (i >= 48) i -= 48;
    f = i & 1 ? 0 : 1;
    fn_1ebc_0111(x, 0xb3, x + 0x16, 0xc9);
    fn_1fd6_000a(g_3649, fn_0845_04ec(f_2803_00a6[4]), x, 0xb3, 0, f);
    fn_0c59_000d(g_3649, g_7fe6[i], x + 1, 0xb4);
    fn_1ebc_01ec();
}

int fn_0c59_00ef(struct Btn far *b)
{
    register int k;

    g_8046 += b->flags & 0x1000 ? b->w38 * 9 : b->w38;
    k = b->w38 < 0 ? 0x4a : 0x4b;
    fn_09aa_0007(k, 1);
    if (g_8046 < 0) g_8046 += 48;
    if (g_8046 >= 48) g_8046 -= 48;
    fn_0c59_0377();
    fn_09aa_0007(k, 0);
    return 1;
}

int fn_0c59_015f(struct Btn far *b)
{
    int other;
    void far *wsa;
    int i;
    register int s;
    register int held;

    s = g_8046 + b->w38;
    if (s >= 48) s -= 48;
    held = fn_0845_0ac7();
    other = g_7fe6[s];
    if ((f_2803_1cfd[held].type == 0x119 || f_2803_1cfd[other].type == 0x119) &&
        (f_2803_1cfd[held].type == 0xdc || f_2803_1cfd[other].type == 0xdc)) {
        fn_2279_025b(fn_215f_0003(5), g_4d56, 0xfa00L);
        wsa = ovr_2dfd_0020("truth.wsa", fn_215f_0003(5), g_369f, 0, 0L);
        fn_1ebc_00e7();
        g_7fe6[s] = 0;
        fn_0c59_0055(b->w38);
        fn_1dbc_0004(b->x, b->y - 3, b->x, b->y - 3, 0x19, 0x1b, 0, 2);
        fn_17d6_0006(0x63);
        for (i = 0; i < 25; i++) {
            g_3850 = 7;
            fn_1dbc_0004(b->x, b->y - 3, 0, 0, 0x19, 0x1b, 2, 2);
            ovr_2dfd_002a(wsa, i, 0, 0, 2, 0x4000);
            fn_1dbc_0004(0, 0, b->x, b->y - 3, 0x19, 0x1b, 2, 0);
            while (g_3850);
        }
        ovr_2dfd_0025(wsa);
        fn_2279_025b(g_4d56, fn_215f_0003(5), 0xfa00L);
        fn_07bc_044c(held);
        fn_07bc_044c(other);
        fn_0845_0acf(0);
        g_7fe6[s] = fn_07bc_012d(0x118, 0, 0);
        fn_1ebc_00fe();
    } else {
        fn_0845_0acf(g_7fe6[s]);
        g_7fe6[s] = held;
    }
    fn_0c59_0055(b->w38);
    return 1;
}

void fn_0c59_0377(void)
{
    register int i;

    if (!f_2803_0000[0x45] || !f_2803_0000[0x44])
        for (i = 0; i < 9; i++) fn_0c59_0055(i);
}

int fn_0c59_03a8(int item)
{
    int i;
    register int s;

    for (i = 0; i < 48; i++) {
        s = g_8046 + i;
        if (s >= 48) s -= 48;
        if (!g_7fe6[s]) break;
    }
    if (i == 48) return 0;
    while (g_8046 - s > 0 || g_8046 + 9 <= s) {
        g_8046++;
        if (g_8046 >= 48) g_8046 -= 48;
        fn_0c59_0377();
    }
    g_7fe6[s] = item;
    fn_0c59_0377();
    return 1;
}

int fn_0c59_0410(int type, int redraw)
{
    register int s;
    register int held;

    for (s = 0; s < 48; s++)
        if (g_7fe6[s] && f_2803_1cfd[g_7fe6[s]].type == type) break;
    if (s == 48) return -1;
    g_8046 = s;
    held = fn_0845_0ac7();
    fn_0845_0acf(g_7fe6[s]);
    g_7fe6[s] = held;
    if (redraw) fn_0c59_0377();
    return held;
}
