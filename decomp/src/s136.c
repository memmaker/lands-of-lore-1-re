/* s136: WW library -- shutdown (#pragma exit): stop drivers, restore the video mode, check the far heap */
#include <alloc.h>
extern int g_3618, g_35e8, g_388c;
extern char g_2f42, g_1592;
extern void (far *g_361e)(void);
extern char far *g_15a4;
void far ovr_2db3_0020(void);
void far fn_1c24_05ab(void);
void far ovr_2df4_0020(int a, int b, int c);
void far ovr_2ddf_0034(void);
void far fn_2318_0001(void);
void far fn_2169_0e78(void);
int far fn_2347_000f(void);
void far fn_2347_0034(int mode);
void far ovr_2e0b_002a(void);
void far fn_19ba_0081(void);
void far fn_2093_000e(char far *msg);

void fn_2309_000c(void)
{
    if (g_3618) {
        g_3618 = 0;
        ovr_2db3_0020();
        if (g_2f42)
            fn_1c24_05ab();
        if (g_35e8 != -1)
            ovr_2df4_0020(0, 0, 0);
        if (g_1592)
            ovr_2ddf_0034();
        fn_2318_0001();
        fn_2169_0e78();
        if (g_361e)
            g_361e();
        if (fn_2347_000f() != g_388c)
            fn_2347_0034(9);
        ovr_2e0b_002a();
        fn_19ba_0081();
        if (farheapcheck() == _HEAPCORRUPT)
            fn_2093_000e(g_15a4);
    }
}
#pragma exit fn_2309_000c 255
