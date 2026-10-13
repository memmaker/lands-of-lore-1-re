/* s032: sound effects front end (four MIDI channels on the effects driver, or the AdLib driver entry) */
#include "lol.h"

struct SfxSlot {            /* 6 bytes */
    int h;                  /* driver sequence handle, -1 free */
    long data;
};

extern int g_28b8, g_28fa, g_2928, g_35e2, g_28e0;
extern long g_28c6, g_28ce;
extern struct SfxSlot g_28e2[4];

void fn_178d_01ef(void far *d, int track, int vol);
void fn_1b79_02e3(int h, int s);
void fn_1b79_02b1(int h, int s);
int fn_1b79_02ac(int h, long a, int track, long b, long c);
void fn_1b79_02dd(int h, int s);
void fn_1b79_0301(int h, int s, int vol, int time);
void fn_1b79_035b(int h, int s);

void fn_17d6_0019(int track, int vol);

void fn_17d6_0006(int track)
{
    fn_17d6_0019(track, 0xff);
}

void fn_17d6_0019(int track, int vol)
{
    if (track < 0)
        return;
    if (track >= 0xfa)
        return;
    if (!g_35e2 && track > 1)
        return;
    if (g_28b8 != -1) {
        if (g_28e2[g_28e0].h != -1) {
            fn_1b79_02e3(g_28b8, g_28e2[g_28e0].h);
            fn_1b79_02b1(g_28b8, g_28e2[g_28e0].h);
            g_28e2[g_28e0].h = -1;
        }
        g_28e2[g_28e0].h = fn_1b79_02ac(g_28b8, g_28ce, track, g_28e2[g_28e0].data, 0L);
        fn_1b79_02dd(g_28b8, g_28e2[g_28e0].h);
        fn_1b79_0301(g_28b8, g_28e2[g_28e0].h, (vol & 0xff) * 0x5a >> 8, 0);
        g_28e0++;
        if (g_28e0 >= 4)
            g_28e0 = 0;
    } else
        fn_178d_01ef(&g_28b8, track, vol);
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
    } else if (g_28c6) {
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
        for (i = 0; i < 4; i++)
            if (g_28e2[i].h != -1)
                fn_1b79_0301(g_28b8, g_28e2[i].h, 0, 0x7d0);
    } else if (g_28c6) {
        if (g_2928 != -1) {
            fn_1b79_035b(g_28fa, g_2928);
            g_2928 = -1;
        }
        fn_178d_01ef(&g_28b8, 1, 0);
    }
}
