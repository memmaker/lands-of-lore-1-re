/* o2db0: startup: config, memory checks, overlay EMS/XMS setup, sound drivers, then the game proper */
/* WIP: all 3 functions match and the EXE relinks MATCH, but only once tools/mkblob.py pubsort() sorts _main as
   its address name _ovr_2db0_002a (ALIAS reversed); with the plain name sort main takes stub entry 0020. */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <mem.h>
#include <dos.h>

extern unsigned char g_ad41, g_ad42, g_ad43, g_ad44, g_ad45, g_ad46, g_ad49;
extern char g_ae59, g_20db, g_2f43;
extern char g_18f2[], g_18fc[], g_198b[], g_19ae[], g_19da[], g_1a06[], g_1a0c[], g_1a19[], g_1a25[], g_1a31[], g_1a3a[];
extern long g_18c6, g_18ca, g_18ce, g_18d2, g_18d6, g_18da, g_18b6, g_18c2, g_4b94;
extern long g_368b, g_368f, g_3693, g_3697, g_369b, g_369f, g_36a3, g_36a7, g_36ab, g_36af;
extern void far *g_4b8e, far *g_18ae;
extern unsigned g_2140, g_2142;
extern int g_4b92, g_362e, g_3745, g_3747, g_3749;
extern int (far *g_3638)();
extern int (far *g_363e)();
unsigned long ovr_2cfd_0025(void);
long ovr_2cfd_0020(void);
int ovr_2e1e_0025(char far *name, unsigned char far *cfg);
void far *fn_203b_0007(long size, int flags);
void fn_203b_0203(void far *p);
long fn_203b_03b4(int flags);
int ovr_2dad_0020(int n);
char far *fn_212a_014c(void far *p, int n);
int fn_22d7_000a(void);
int fn_2354_000c(void);
long ovr_2e0b_0020(void);
void ovr_2e0b_0025(long a, long b);
void fn_19ba_007a(long a, long b);
void ovr_2ddf_0025(char far *s);
void ovr_2ddf_002a(int n);
void ovr_2ddf_0020(char far *s);
void ovr_2e22_002a(char far *s);
int ovr_2daa_0020(char far *s, long n, int a);
void fn_2169_04ba(int n);
void fn_2309_000c(void);
void ovr_2db6_0020(int a, int b, int c);
int ovr_2df7_0020(int a, void far *b, int c);
int ovr_2d92_0025();
int fn_2274_0007();
void ovr_2d40_0020(int argc, char far * far *argv);
void fn_2148_002c(int drive);
int ovr_2db0_0020(void);
unsigned long ovr_2db0_0025(void);

int main(int argc, char far * far *argv)   /* ovr_2db0_002a */
{
    void far *p;
    long a = 0;
    long b = 0;
    long c = 0;
    long d = 0;
    long e = 0;

    e = ovr_2cfd_0025();
    if (ovr_2e1e_0025(g_18f2, &g_ad41) == 0) {
        printf(g_18fc);
        getch();
        exit(1);
    }
    p = fn_203b_0007(16, 0);
    fn_203b_0203(p);
    g_18c6 = fn_203b_03b4(0);
    ovr_2dad_0020(g_ad49);
    if (ovr_2db0_0025() < 0x7a120UL) {
        printf(fn_212a_014c(g_4b8e, 0x22), 0x7a120L);
        getch();
        exit(1);
    }
    g_20db = g_ad49;
    g_18da = ovr_2cfd_0020();
    if (g_ad44) {
        if (fn_22d7_000a() != 3) {
            if (ovr_2db0_0020()) {
                printf(fn_212a_014c(g_4b8e, 0x23));
                g_18ca = 0;
                g_ad44 = 0;
            } else {
                g_18ca = 0x54ac8L;
                g_2140 = 0x2800;
                g_2142 = g_2140 >> 1;
                g_2140 += 0x1158;
            }
        } else if (fn_22d7_000a() == 3) {
            printf(g_198b);
            getch();
            exit(1);
        } else if (!fn_2354_000c()) {
            printf(fn_212a_014c(g_4b8e, 0x24));
            g_ad44 = 0;
            g_18ca = 0;
        } else g_18ca = 0x54ac8L;
    } else g_18ca = 0;
    if (g_ad44 == 0) g_18ca = 0;
    b = 0;
    a = ovr_2e0b_0020();
    if (a < 0) a = 0;
    d = b + a;
    g_18d6 = 0x1c800L;
    g_18d2 = g_18ca + 0xbb800L;
    g_18ce = 0x7d000L;
    c = g_18da + 0x472e8L;
    g_18b6 = (long)*(int far *)MK_FP(_psp - 1, 3) << 4;
    if (g_18d6 + g_18d2 + g_18ce <= d && d >= 0x1e8480L && c + g_18b6 <= e && argc > 1) {
        if (g_18ca != 0 && g_18d6 + g_18d2 + g_18ce + 0x19000L <= d) {
            do {
                g_18d2 += 0xc800;
                g_18ce += 0xc800;
                if (g_18d2 - 0xddec8L >= 0x1f4000L) break;
            } while (g_18d6 + g_18d2 + g_18ce + 0x19000L <= d);
        }
    } else {
        printf(g_19ae, e, c + g_18b6);
        printf(g_19da, a, 0x1e8480L, 0);
        exit(1);
    }
    g_4b94 = (g_18ca = g_18d2 - 0xddec8L) - g_18c2;
    _OvrInitEms(0, 0, g_18d6 / 16);
    _OvrInitExt(0, g_18d6);
    if (b != 0) {
        fn_19ba_007a(g_18d2, 0xf23000L);
        g_18d2 = fn_203b_03b4(0x80);
        g_18ce = fn_203b_03b4(0x82);
        g_4b92 = 0x80;
    } else {
        ovr_2e0b_0025(g_18d2, 0xf23000L);
        g_18d2 = fn_203b_03b4(0x40);
        g_18ce = fn_203b_03b4(0x42);
        g_4b92 = 0x40;
    }
    ovr_2ddf_0025(g_1a06);
    ovr_2ddf_002a(1);
    ovr_2ddf_0020(g_1a0c);
    ovr_2e22_002a(g_1a19);
    ovr_2e22_002a(g_1a25);
    if (ovr_2daa_0020(g_1a31, c - 0x400, 1)) return 1;
    if (!g_ad45) fn_2169_04ba(0x3000);
    g_362e = 3;
    switch (g_ad41) {
    case 7: case 8: case 10: case 11: case 12:
        g_362e = 3;
        break;
    default:
        printf(fn_212a_014c(g_4b8e, 0x27));
        fn_2309_000c();
        getch();
        exit(1);
    }
    g_368b = g_368f = 0xfa00L;
    g_3693 = g_3697 = 0xfbf4L;
    g_369b = g_369f = 0xffffL;
    g_36a3 = g_36a7 = 0x9600L;
    g_36ab = g_36af = 0;
    if (!g_ad46) g_ad44 = 0;
    ovr_2db6_0020(g_ad43, g_ad42, g_ad44);
    if (g_ad42 != g_3747 || g_ad43 != g_3745)
        printf(fn_212a_014c(g_4b8e, 0x28));
    else if (g_ad44 != g_3749 && fn_22d7_000a() == 3)
        printf(fn_212a_014c(g_4b8e, 0x29));
    if (ovr_2df7_0020(g_362e, g_18ae, 0)) {
        g_3638 = ovr_2d92_0025;
        g_363e = fn_2274_0007;
        g_2f43 = 0;
        ovr_2d40_0020(argc, argv);
    }
    fn_2309_000c();
    fn_2148_002c(g_ae59 - 'A');
    return 0;
}

int ovr_2db0_0020(void)
{
    char far *p;

    asm push es
    asm mov ah,0c0h
    asm int 15h
    asm add bx,0dh
    asm mov word ptr p,bx
    asm mov word ptr p+2,es
    asm pop es
    return memicmp(p, g_1a3a, 3) == 0;
}

unsigned long ovr_2db0_0025(void)
{
    struct dfree df;

    getdfree(0, &df);
    if (df.df_sclus == 0xffff) return 0;
    return (unsigned long)df.df_avail * df.df_bsec * df.df_sclus;
}
