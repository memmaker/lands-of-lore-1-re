/* o2d7d: screen wipe between two pages; death / game-over handling */
#include "lol.h"

struct Page { int w0, w2; void far *p; };
extern struct Page g_1228, g_1230, g_1238;
extern unsigned long g_384c;
void far *fn_215f_001d(int page);
void fn_1ebc_0111(int x1, int y1, int x2, int y2);
void fn_1ebc_01ec(void);
void fn_19c9_0dbf(struct Page *s, int sx, int sy, struct Page *d, int dx, int dy, int w, int h, int f);
void fn_0845_08aa(void);
void fn_0845_15d9(int n);
void fn_067a_0401(long snd);
void ovr_2d28_0034(int a, int b, int c, int d);
int fn_1e74_000f(int n);
void fn_1e59_001d(int x1, int y1, int x2, int y2, int c);

void ovr_2d7d_0020(int n)
{
    unsigned long t;
    int i;

    g_1238.p = fn_215f_001d(0);
    g_1228.p = fn_215f_001d(6);
    g_1230.p = fn_215f_001d(2);
    fn_1ebc_0111(0x70, 0, 0x120, 0x78);
    fn_19c9_0dbf(&g_1238, 0x70, 0, &g_1228, 0, 0, 0xb0, 0x78, 0);
    fn_1ebc_01ec();
    for (i = 0; i < n; i++) {
        t = g_384c;
        fn_1ebc_0111(0x70, 0, 0x120, 0x78);
        fn_19c9_0dbf(&g_1228, 0, (0x7800 / n * i) >> 8, &g_1238, 0x70, 0, 0xb0, 0x78 - ((0x7800 / n * i) >> 8), 0);
        fn_19c9_0dbf(&g_1230, 0x70, 0, &g_1238, 0x70, 0x78 - ((0x7800 / n * i) >> 8), 0xb0, (0x7800 / n * i) >> 8, 0);
        fn_1ebc_01ec();
        while (g_384c - t < 1) ;
    }
    fn_1ebc_0111(0x70, 0, 0x120, 0x78);
    t = g_384c;
    fn_19c9_0dbf(&g_1230, 0x70, 0, &g_1238, 0x70, 0, 0xb0, 0x78, 0);
    while (g_384c - t < 1) ;
    fn_1ebc_01ec();
    fn_0845_08aa();
}

struct Dlg { char pad[0x0c]; int sel; char pad2[0x1e]; int res[1]; };

int ovr_2d7d_0025(struct Dlg far *p)
{
    int v;
    int w;
    unsigned s;
    int i;

    v = p->res[p->sel];
    if (v == 1) {
        fn_0845_15d9(2);
        ovr_2d7d_0020(9);
        fn_067a_0401(0xffffL);
        ovr_2d28_0034(0x1e, 4, 0, 1);
    } else {
        s = -1;
        for (i = 0; i < 4; i++) {
            if ((f_2803_362d[i].flags & 1) && f_2803_362d[i].wE < 0) {
                switch (i) {
                case 0: s = 0x36; break;
                case 5: s = 0x35; break;
                case 8: s = 0x34; break;
                case 9: s = 0x33; break;
                }
                break;
            }
        }
        w = fn_1e74_000f(2);
        fn_1e59_001d(0x70, 0, 0x120, 0x78, 0);
        fn_1e74_000f(w);
        ((void (far *)(int, int))fn_067a_0401)(s, 0);
        ovr_2d7d_0020(12);
    }
    return 1;
}
