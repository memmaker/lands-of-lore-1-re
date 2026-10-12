/* s032: sound effect channels played through the digital driver slot g_28b8 (4 rotating handles) */

struct Sfx {                /* 6 bytes, g_28e2[4] */
    int h;
    long data;
};

extern int g_28b8;
extern void far *g_28c6;
extern long g_28ce;
extern int g_28e0;
extern struct Sfx g_28e2[4];
extern int g_28fa;
extern int g_2928;
extern int g_35e2;

void fn_178d_01ef(int far *drv, int a, int b);
int fn_1b79_02ac(int drv, long file, int n, long data, long z);
void fn_1b79_02b1(int drv, int h);
void fn_1b79_02dd(int drv, int h);
void fn_1b79_02e3(int drv, int h);
void fn_1b79_0301(int drv, int h, int vol, int z);
void fn_1b79_035b(int drv, int h);

void fn_17d6_0019(int n, int vol);

void fn_17d6_0006(int n)
{
    fn_17d6_0019(n, 0xff);
}

void fn_17d6_0019(int n, int vol)
{
    if (n < 0 || n >= 250 || (g_35e2 == 0 && n > 1))
        return;
    if (g_28b8 != -1) {
        if (g_28e2[g_28e0].h != -1) {
            fn_1b79_02e3(g_28b8, g_28e2[g_28e0].h);
            fn_1b79_02b1(g_28b8, g_28e2[g_28e0].h);
            g_28e2[g_28e0].h = -1;
        }
        g_28e2[g_28e0].h = fn_1b79_02ac(g_28b8, g_28ce, n, g_28e2[g_28e0].data, 0);
        fn_1b79_02dd(g_28b8, g_28e2[g_28e0].h);
        fn_1b79_0301(g_28b8, g_28e2[g_28e0].h, ((vol & 0xff) * 90) >> 8, 0);
        if (++g_28e0 >= 4)
            g_28e0 = 0;
    } else {
        fn_178d_01ef(&g_28b8, n, vol);
    }
}

void fn_17d6_0123(void)
{
    int i;

    if (g_28b8 != -1) {
        for (i = 0; i < 4; i++) {
            if (g_28e2[i].h != -1) {
                fn_1b79_02e3(g_28b8, g_28e2[i].h);
                fn_1b79_02b1(g_28b8, g_28e2[i].h);
                g_28e2[i].h = -1;
            }
        }
    } else if (g_28c6 != 0) {
        if (g_2928 != -1) {
            fn_1b79_035b(g_28fa, g_2928);
            g_2928 = -1;
        }
        fn_178d_01ef(&g_28b8, 0, 0);
    }
}

void fn_17d6_01b0(void)
{
    int i;

    if (g_28b8 != -1) {
        for (i = 0; i < 4; i++) {
            if (g_28e2[i].h != -1)
                fn_1b79_0301(g_28b8, g_28e2[i].h, 0, 2000);
        }
    } else if (g_28c6 != 0) {
        if (g_2928 != -1) {
            fn_1b79_035b(g_28fa, g_2928);
            g_2928 = -1;
        }
        fn_178d_01ef(&g_28b8, 1, 0);
    }
}
