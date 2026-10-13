/* o2d80: magic drain animation: character c (all four with -1) loses up to 4 MP over 16 frames under a WSA */
#include <dos.h>
#include "lol.h"

struct WsaHdr { int w0; unsigned frames; };

extern char g_1240[], g_1248[];
extern unsigned long g_36a3;
extern long g_3850;
extern void far *g_4bec, far *g_4bf0;
extern int far f_2803_3625[];
void ovr_2ce1_007f(char far *msg);
int fn_1e74_000f(int n);
void fn_067a_0401(int snd, int x);
void fn_17d6_0006(int snd);
void far *fn_215f_001d(int page);
void fn_2279_025b(void far *d, void far *s, long n);
struct WsaHdr far *ovr_2dfd_0020(char far *name, void far *a, unsigned long b, int c, long d);
void ovr_2dfd_0025(void far *p);
int ovr_2dfd_002a(void far *w, int f, int x, int y, int a, int b, ...);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_1ebc_01ec(void);
void fn_1ebc_0111(int x1, int y1, int x2, int y2);
void fn_1dbc_0004(int x1, int y1, int x2, int y2, int w, int h, int s, int d);
void fn_0a21_022b(int c);
void fn_0a21_05ce(void);
void fn_0845_15d9(int n);
void fn_0845_08aa(void);

void ovr_2d80_0020(int c)
{
    int old;
    int amt[4];
    int x[4];
    int y[4];
    int acc[4];
    int maxv = 4;
    unsigned fr = 0;
    int first;
    int k;
    struct WsaHdr far *shp;
    int end;

    fn_1ebc_00e7();
    fn_2279_025b(fn_215f_001d(0), fn_215f_001d(2), 0xfa00L);
    fn_1ebc_00fe();
    fn_2279_025b(fn_215f_001d(2), fn_215f_001d(6), 0x9600L);
    if (c == -1) {
        first = 0;
        end = 4;
    } else {
        first = c;
        end = c + 1;
    }
    for (c = first; c < end; c++) {
        if (f_2803_362d[c].flags & 1) {
            x[c] = f_2803_3625[c] - 6;
            y[c] = 0x8a;
            f_2803_362d[c].lastDmg = 0;
            if (f_2803_362d[c].mp > maxv) amt[c] = maxv;
            else amt[c] = f_2803_362d[c].mp;
            fn_1ebc_0111(x[c], y[c], x[c] + 0x4d, y[c] + 0x2c);
            fn_1dbc_0004(x[c], y[c], c * 0x4d, 0x20, 0x4d, 0x2c, 0, 2);
            fn_1ebc_01ec();
        }
    }
    fn_067a_0401(0x9a, 0);
    if ((shp = ovr_2dfd_0020(g_1240, MK_FP(FP_SEG(fn_215f_001d(6)), 0x6400), g_36a3 - 0x6400, 1, 0L)) == 0)
        ovr_2ce1_007f(g_1248);
    fn_17d6_0006(0x9a);
    old = fn_1e74_000f(2);
    for (k = 0; k < 16; k++) {
        g_3850 = 4;
        for (c = first; c < end; c++) {
            if (f_2803_362d[c].flags & 1) {
                fn_1dbc_0004(c * 0x4d, 0x20, x[c], y[c], 0x4d, 0x2c, 2, 2);
                fn_0a21_022b(c);
                ovr_2dfd_002a(shp, fr % shp->frames, x[c] + 0x15, y[c] + 6, 2, 0x5000, g_4bec, g_4bf0);
                acc[c] &= 0xff;
                acc[c] += (amt[c] << 8) / 16;
                f_2803_362d[c].mp -= acc[c] >> 8;
                fn_1ebc_0111(x[c], y[c], x[c] + 0x4d, y[c] + 0x2c);
                fn_1dbc_0004(x[c], y[c], x[c], y[c], 0x85, 0x33, 2, 0);
                fn_1ebc_01ec();
            }
        }
        while (g_3850 != 0) ;
        fr++;
    }
    ovr_2dfd_0025(shp);
    fn_1e74_000f(old);
    fn_0a21_05ce();
    fn_0845_15d9(2);
    fn_0845_08aa();
}
