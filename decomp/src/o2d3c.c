/* o2d3c: level state save/restore (LEVELn temp files) and savegame load/save */
#include "lol.h"
#include <stdio.h>
#include <string.h>
#include <mem.h>

extern char g_7fe5;
extern char far *g_7fcc;
extern char far *g_4edc;
extern char g_ad99[];
extern char g_0f26[], g_0f32[], g_0f3f[], g_0f4c[], g_0f58[], g_0f5d[], g_0f6a[], g_0f6f[], g_0f7a[];
extern unsigned long g_81f9;
extern struct Fly g_4dcc[];
extern int g_7fd0;
extern int g_3745, g_3747, g_3749;
extern char g_8200, g_8201, g_81fe, g_81ff;
extern int g_35e2, g_35e4, g_20cd, g_20cf;
extern int g_8048;
extern unsigned g_8094;
extern struct MonType far f_2803_1b5e[];
extern struct Item far f_2803_1cfd[];
extern char far f_27b1_01c2[][0x12];
int far *fn_215f_001d(int n);
char far *fn_215f_0003(int page);
long ovr_2ded_0020(char far *name, void far *buf, long n);
void ovr_2ded_0025(char far *name, void far *buf, long n);
long ovr_2ded_002f(char far *name, int page, int dpage, void far *pal);
void fn_2279_025b(void far *s, void far *d, long n);
int fn_20f7_0006(void far *s, void far *d, int n);
int fn_232c_000c(void far *s, void far *d, int n);
int fn_0845_1036(void);
int fn_1809_0000(char far *name, int mode);
long fn_1809_084d(int h, void far *buf, long n);
long fn_1809_0bde(int h, void far *buf, long n);
void fn_1809_058d(int h);
long fn_1809_0e76(int h, long off, int whence);
void fn_0d6c_0742(struct Monster far *m, int x, int y);
void ovr_2d56_003e(int a, int b);
void fn_0845_03d4(int n);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void ovr_2d2c_0025(void);
void fn_1e59_001d(int x1, int y1, int x2, int y2, int c);
void ovr_2d46_0034(int c, int id);
void fn_178d_015e(void);
void fn_17d6_0123(void);
void fn_0a21_0a0c(void);
void ovr_2d0e_002a(void);
void fn_0845_0acf(int item);
void ovr_2d2c_006b(int lvl);
void ovr_2d2c_0043(void);
void fn_0bbc_0143(int arg);
void ovr_2d2c_0061(int a);
void ovr_2d2c_0066(void);
void ovr_2d3c_0020(void);

void ovr_2d3c_0020(void)
{
    int n;
    int m;
    char far *p;
    int far *hdr;
    int stride;
    int i, j, h;

    hdr = fn_215f_001d(2);
    p = fn_215f_0003(3);
    sprintf(g_ad99, g_0f26, g_7fe5);
    ovr_2ded_002f(g_ad99, 2, 2, 0L);
    stride = hdr[2];
    for (i = 0; i < 0x400; i++)
        fn_2279_025b(g_7fcc + i * stride + 6, g_7fcc + i * 4, 4L);
    for (i = 0; i < 0x400; i++)
        for (j = 0; j < 4; j++)
            *p++ ^= WALL(i, j);
    for (i = 0; i < 0x400; i++)
        *p++ = g_8203[i].flags;
    n = fn_20f7_0006(fn_215f_0003(3), g_4edc, 0x1400);
    sprintf(g_ad99, g_0f32, g_7fe5);
    m = fn_0845_1036();
    h = fn_1809_0000(g_ad99, 2);
    fn_1809_0bde(h, &n, 2L);
    fn_1809_0bde(h, g_4edc, (long)n);
    fn_1809_0bde(h, &m, 2L);
    fn_1809_0bde(h, f_2803_15fa, 0x564L);
    fn_1809_0bde(h, g_4dcc, 0x88L);
    fn_1809_058d(h);
    g_81f9 |= 1L << (char)(g_7fe5 - 1);
}

void ovr_2d3c_0025(int lvl)
{
    char far *p;
    char far *q;
    int n;
    int m;
    int far *hdr;
    struct Monster far *mon;
    int stride;
    int i, j, h;

    hdr = fn_215f_001d(2);
    sprintf(g_ad99, g_0f3f, lvl);
    h = fn_1809_0000(g_ad99, 1);
    fn_1809_084d(h, &n, 2L);
    fn_1809_084d(h, g_7fcc, (long)n);
    fn_1809_084d(h, &m, 2L);
    fn_1809_084d(h, f_2803_15fa, 0x564L);
    fn_1809_084d(h, g_4dcc, 0x88L);
    fn_1809_058d(h);
    fn_232c_000c(g_7fcc, g_4edc, 0x1400);
    sprintf(g_ad99, g_0f4c, lvl);
    ovr_2ded_002f(g_ad99, 3, 3, 0L);
    stride = hdr[2];
    for (i = 0; i < 0x400; i++)
        fn_2279_025b(g_7fcc + i * stride + 6, g_7fcc + i * 4, 4L);
    setmem(g_8203, 0x2800, 0);
    p = fn_215f_0003(3);
    q = g_4edc;
    for (i = 0; i < 0x400; i++)
        for (j = 0; j < 4; j++) {
            WALL(i, j) = *p ^ *q;
            q++;
            p++;
        }
    for (i = 0; i < 0x400; i++)
        g_8203[i].flags = *q++;
    mon = f_2803_15fa;
    for (i = 0; i < 30; i++, mon++) {
        if (mon->block) {
            mon->block = 0;
            mon->type = &f_2803_1b5e[mon->c20];
            fn_0d6c_0742(mon, mon->x, mon->y);
        }
    }
    ovr_2d56_003e(m, fn_0845_1036());
}

int ovr_2d3c_002a(char far *name)
{
    int i;
    char buf[10];
    long len;
    int h;

    fn_0845_03d4(10);
    fn_1ebc_00e7();
    ovr_2d2c_0025();
    fn_1e59_001d(0x70, 0, 0x11f, 0x77, 0);
    fn_1ebc_00fe();
    h = fn_1809_0000(name, 1);
    fn_1809_0e76(h, 0x3cL, 1);
    fn_1809_084d(h, buf, 5L);
    if (strcmp(buf, g_0f58)) {
        fn_1809_058d(h);
        return 2;
    }
    fn_1809_084d(h, buf, 11L);
    fn_1809_084d(h, f_2803_362d, 0x208L);
    for (i = 0; i < 4; i++) {
        if (f_2803_362d[i].flags & 1) {
            ovr_2d46_0034(i, f_2803_362d[i].wE);
            f_2803_362d[i].st.atk = (struct Attack far *)f_27b1_01c2[f_2803_362d[i].cD];
        }
    }
    fn_1809_084d(h, &g_7fd0, 0x233L);
    if (!g_3747) g_8201 = 0;
    if (g_8201) g_35e4 = 1;
    else {
        fn_178d_015e();
        g_35e4 = 0;
    }
    if (!g_3745) g_8200 = 0;
    if (g_8200) {
        g_35e2 = 1;
        g_20cd = 1;
    } else {
        fn_17d6_0123();
        g_35e2 = 0;
        g_20cd = 0;
    }
    if (!g_3749) {
        g_81ff = 0;
        g_81fe = 1;
        g_20cd = 0;
    }
    if (g_81ff) g_20cf = 1;
    else g_20cf = 0;
    fn_1809_084d(h, f_2803_1cfd, 0x1900L);
    for (i = 0; i < 0x400; i++) {
        g_8203[i].mon = 0;
        g_8203[i].draw = 0;
        g_8203[i].drawDir = 5;
    }
    for (i = 0; i < 30; i++) {
        if (g_81f9 & (1L << i)) {
            fn_1809_084d(h, &len, 4L);
            fn_1809_084d(h, g_4edc, 0x9c0L);
            sprintf(g_ad99, g_0f5d, i + 1);
            ovr_2ded_0025(g_ad99, g_4edc, len);
        } else
            fn_1809_0e76(h, 0x9c4L, 1);
    }
    fn_0a21_0a0c();
    ovr_2d0e_002a();
    fn_0845_0acf(g_8048);
    ovr_2d2c_006b(g_7fe5);
    ovr_2d2c_0043();
    fn_0bbc_0143(0);
    fn_1809_058d(h);
    g_8094 |= 0x800;
    return 1;
}

void ovr_2d3c_002f(char far *name, char far *desc)
{
    int i;
    long len;
    int h;

    ovr_2d2c_0025();
    ovr_2d3c_0020();
    h = fn_1809_0000(name, 2);
    fn_1809_0bde(h, desc, 0x3cL);
    fn_1809_0bde(h, g_0f6a, 5L);
    fn_1809_0bde(h, g_0f6f, 11L);
    fn_1809_0bde(h, f_2803_362d, 0x208L);
    fn_1809_0bde(h, &g_7fd0, 0x233L);
    ovr_2d2c_0061(0);
    fn_1809_0bde(h, f_2803_1cfd, 0x1900L);
    ovr_2d2c_0066();
    for (i = 0; i < 30; i++) {
        if (g_81f9 & (1L << i)) {
            sprintf(g_ad99, g_0f7a, i + 1);
            len = ovr_2ded_0020(g_ad99, g_4edc, 0xfa00L);
            fn_1809_0bde(h, &len, 4L);
            fn_1809_0bde(h, g_4edc, 0x9c0L);
        } else
            fn_1809_0bde(h, g_4edc, 0x9c4L);
    }
    fn_1809_058d(h);
}
