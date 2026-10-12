/* o2df7: set up a video mode: screen pages, page buffers, palette file and default palette */
/* FLAGS: -ml -3 -Y */
#include <dos.h>
#include <mem.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern char far *g_2e66[];
extern char far *g_15a8;
extern char far *g_15ac;
extern char g_ad99[], g_2eba[];
extern char g_2e46[], g_2e56[];
extern long g_368b[];
extern unsigned g_364b[];
extern int g_ad4d[];
extern int g_ad51;
extern void far *g_ae4f;
extern void far *g_adea;
void fn_2347_0034(int mode);
void fn_1c24_04eb(void);
int fn_1e73_0008(char far *name, int a, int b);
void fn_2093_000e(char far *msg);
void fn_2169_062e(void);
void fn_2169_06e9(void);
void fn_2309_000c(void);
void far *fn_203b_0007(long size, int flags);
void far *fn_2279_02b5(void far *p);
void fn_1e04_0031(void);
void far *ovr_2df1_0020(char far *name);
void fn_1f2d_0002(void far *p);
void fn_1ee4_0002(void far *pal);
void fn_1ef2_001c(void far *pal);
void ovr_2de6_0020(void);
void fn_14b3_0122(int n);

int ovr_2df7_0020(int mode, char far *palfile, int alloc)
{
    long total;
    void far *mem;
    long sz;
    int i;

    switch (mode) {
    case 0: break;
    case 1: break;
    case 2: break;
    case 3: memset((void far *)0xa0000000L, 0, 0xfa00); break;
    case 4: break;
    case 5: break;
    case 8: break;
    }
    if (mode != 8) {
        fn_2347_0034(mode);
        fn_1c24_04eb();
        if (!fn_1e73_0008(g_2e66[mode], 0, 0)) {
            fn_2347_0034(9);
            sprintf(g_ad99, g_15a8, g_2e66[mode]);
            fn_2093_000e(g_ad99);
            fn_2169_062e();
            fn_2169_06e9();
            return 0;
        }
    }
    if (alloc) {
        total = 0;
        for (i = 2; i < 16; i += 2) {
            sz = g_368b[i + 1];
            sz = (sz + 15) & ~15L;
            if (sz & 0xff000000L) {
                fn_2309_000c();
                fn_2093_000e(g_2eba);
                fn_2169_06e9();
                exit(5);
            }
            g_368b[i + 1] = sz;
            g_368b[i] = sz;
            total += sz;
        }
        mem = fn_203b_0007(total, g_ad51 | 0x30);
        for (i = 2; i < 16; i += 2) {
            if (g_368b[i] != 0) {
                g_364b[i + 1] = FP_SEG(mem);
                g_364b[i] = FP_SEG(mem);
                mem = (char huge *)mem + g_368b[i];
                mem = fn_2279_02b5(mem);
            }
        }
    } else {
        for (i = 2; i < 16; i += 2) {
            if (g_368b[i + 1] != 0 && i != 0) {
                g_364b[i + 1] = FP_SEG(fn_203b_0007(g_368b[i + 1], g_ad4d[i] | 0x20));
                g_364b[i] = g_364b[i + 1];
            }
        }
    }
    switch (mode) {
    case 0:
    case 1:
        g_364b[0] = g_364b[1] = 0xb800;
        break;
    case 2:
        g_364b[0] = 0xa000;
        g_364b[2] = 0xa200;
        g_364b[4] = 0xa400;
        g_364b[6] = 0xa600;
        g_364b[8] = 0xa800;
        g_364b[10] = 0xaa00;
        g_364b[12] = 0xac00;
        g_364b[14] = 0xae00;
        break;
    case 4:
    case 5:
        g_364b[0] = 0xa000;
        g_364b[2] = 0xa400;
        g_364b[4] = 0xa800;
        g_364b[6] = 0xac00;
        break;
    case 3:
    case 6:
        g_364b[0] = g_364b[1] = 0xa000;
        break;
    case 7:
    case 8:
    default:
        break;
    }
    if (mode != 8) {
        fn_1e04_0031();
        if (palfile != 0) {
            g_ae4f = ovr_2df1_0020(palfile);
            if (g_ae4f == 0) {
                fn_2347_0034(9);
                sprintf(g_ad99, g_15ac, palfile);
                fn_2093_000e(g_ad99);
                fn_2169_06e9();
                return 0;
            }
            fn_1f2d_0002(g_ae4f);
        }
    }
    g_adea = fn_203b_0007(0x300L, 0x10);
    switch (mode) {
    case 5:
        memcpy(g_adea, g_2e56, 16);
        fn_1ee4_0002(g_adea);
        break;
    case 2:
        memcpy(g_adea, g_2e46, 16);
        fn_1ee4_0002(g_adea);
        break;
    case 3:
    case 4:
        fn_1ef2_001c(g_adea);
        break;
    case 8:
    default:
        break;
    }
    ovr_2de6_0020();
    srand(time(0));
    fn_14b3_0122(0);
    return 1;
}
