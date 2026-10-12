/* o2d92: modal message box (text window over the current screen, waits for a key; ESC quits the game) */
#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include <io.h>

struct Win { int x, y, w, h; char pad[8]; };
extern struct Win g_1f3b[];
extern int g_3715, g_3622, g_3649, g_ad93, g_ad95;
extern int g_ad8b, g_ad8d, g_ad8f, g_ad91, g_ae57, g_4b86;
extern char g_2fd9[], g_2fac[], g_4b76[], g_1592;
extern char far *g_15b0[], far *g_15f8, far *g_15fc, far *g_15e0, far *g_1600, far *g_1604;
extern void far *g_ae4f, far *g_14ba;
int fn_14b3_0122(int w);
void fn_14b3_0215(void);
void fn_14b3_0284(char far *fmt, ...);
void fn_1ef2_001c(void far *pal);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
int fn_1e74_000f(int n);
void far *fn_1f2d_0002(void far *p);
unsigned fn_1f6a_0002(int w, int h);
long fn_203b_03b4(int n);
void far *fn_203b_0007(long size, int flags);
void fn_203b_0203(void far *p);
int fn_2365_063f(void far *p);
int fn_19ba_0086(void far *p);
char far *fn_215f_001d(int n);
void fn_2279_025b(void far *a, void far *b, long n);
void fn_2096_014b(int x, int y, int w, int h, void far *p, int page);
void fn_2096_0000(int x, int y, int w, int h, void far *p, int page);
void fn_1e54_0001(int x1, int y1, int x2, int y2, int c);
int ovr_2e26_002a(char far *s);
void fn_2169_062e(void);
int fn_2169_0516(void);
int fn_2169_06e9(void);
void fn_2309_000c(void);

static void move(int d)
{
    g_1f3b[g_3715].x -= d;
    g_1f3b[g_3715].y -= d << 3;
    g_1f3b[g_3715].w += d << 1;
    g_1f3b[g_3715].h += d << 4;
    fn_14b3_0122(g_3715);
    g_ad95 = g_ad93 = 0;
}

int ovr_2d92_0020(int mode, char far *msg)
{
    int oldwin;
    int x;
    int y;
    int w;
    int h;
    int x2;
    int y2;
    unsigned size;
    char far *shp;
    void far *font;
    char buf[4];
    char save[3];
    int oldpage;
    int fd;
    char pal[0x300];
    register unsigned alloc;

    alloc = 0;
    memcpy(save, g_2fd9, 3);
    memcpy(pal, g_2fac, 0x300);
    setmem(pal + 0x2d, 3, 0x3f);
    fn_1ef2_001c(pal);
    fn_1ebc_00e7();
    shp = g_15b0[mode];
    oldpage = fn_1e74_000f(0);
    oldwin = fn_14b3_0122(g_3622);
    font = fn_1f2d_0002(g_ae4f);
    x = g_ad8d << 3;
    y = g_ad8b;
    w = g_ad8f << 3;
    h = g_ad91;
    x2 = x + w - 1;
    y2 = y + h - 1;
    size = g_ad91 * 0x140;
    if (g_14ba == 0) {
        alloc = fn_1f6a_0002(g_ad8f << 3, h);
        if (fn_203b_03b4(0) >= (long)alloc)
            g_14ba = fn_203b_0007(alloc, 0);
        else {
            g_14ba = fn_203b_0007(size, 0xc2);
            if (g_14ba == 0) g_14ba = fn_203b_0007(size, 0xc0);
        }
        if (g_14ba == 0) alloc = 0;
    }
    if (g_14ba != 0) {
        if (fn_2365_063f(g_14ba) || fn_19ba_0086(g_14ba))
            fn_2279_025b(fn_215f_001d(0) + g_ad8b * 0x140, g_14ba, size);
        else
            fn_2096_014b(g_ad8d << 3, g_ad8b, g_ad8f << 3, h, g_14ba, 0);
    }
    fn_14b3_0215();
    fn_1e54_0001(x, y, x2, y2, 0xf);
    move(-1);
    g_4b86 = ovr_2e26_002a(msg);
    fn_14b3_0284(shp, msg);
    if (mode == 2 || mode == 0) {
        if (g_ae57) fn_14b3_0284(g_15f8, msg);
        else {
            buf[0] = g_4b86 + '1';
            buf[1] = 0;
            fn_14b3_0284(g_15fc, buf, msg);
        }
    }
    fn_2169_062e();
    if (g_4b76[0] != 0) {
        fd = -1;
        mode = 0;
        while (fd == -1 && mode != 0x1b) {
            fd = open(g_4b76, 1);
            mode = fn_2169_0516();
        }
        close(fd);
    } else mode = fn_2169_06e9();
    if (mode == 0x1b) {
        fn_14b3_0215();
        fn_14b3_0284(g_15e0);
        fn_2169_06e9();
        fn_2309_000c();
        exit(5);
    }
    move(1);
    if (g_14ba != 0) {
        if (fn_2365_063f(g_14ba) || fn_19ba_0086(g_14ba))
            fn_2279_025b(g_14ba, fn_215f_001d(0) + g_ad8b * 0x140, size);
        else
            fn_2096_0000(g_ad8d << 3, g_ad8b, g_ad8f << 3, h, g_14ba, 0);
    }
    fn_14b3_0122(oldwin);
    fn_1f2d_0002(font);
    fn_1e74_000f(oldpage);
    if (alloc) {
        fn_203b_0203(g_14ba);
        g_14ba = 0;
    }
    memcpy(pal + 0x2d, save, 3);
    fn_1ef2_001c(pal);
    fn_1ebc_00fe();
    return 1;
}

int ovr_2d92_0025(int mode, char far *msg)
{
    int old;

    old = g_3649;
    g_3649 = 0;
    ovr_2d92_0020(mode, msg);
    g_3649 = old;
    return 1;
}

int ovr_2d92_002a(int n, char far *msg)
{
    printf(g_1600, msg);
    g_1592 = 0;
    fn_2309_000c();
    exit(5);
    return 0;
}

int ovr_2d92_002f(int n, char far *msg)
{
    printf(g_1604, msg, n);
    g_1592 = 0;
    fn_2309_000c();
    exit(5);
    return 0;
}
