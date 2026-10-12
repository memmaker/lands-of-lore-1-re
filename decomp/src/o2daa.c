/* o2daa: startup checks (overlay file open, free memory) before entering the game */
#include <dos.h>

extern int g_388c;
extern char far *g_1608;
extern char far *g_1610;
extern void interrupt (far *g_4b88)();
extern char g_1592;
extern int g_3618;
extern int far _OvrDosHandle;   /* OVERLAY.LIB OVRDATA: 2c2b:0128 */
int fn_2347_000f(void);
void fn_2162_001a(void);
void fn_2124_0002(void);
void fn_2093_000e(char far *s);
long fn_203b_03b4(int t);
void fn_2169_086b(void);
void fn_2318_0000(void);
void ovr_2ddf_002f(void);
void fn_1981_01af(void far *p);

int ovr_2daa_0020(void far *p, long need)
{
    g_388c = fn_2347_000f();
    fn_2162_001a();
    fn_2124_0002();
    if (p != 0 && _OvrDosHandle == 0) {
        fn_2093_000e(g_1608);
        return 1;
    }
    if (fn_203b_03b4(0) < need) {
        fn_2093_000e(g_1610);
        setvect(0x3f, g_4b88);
        return 1;
    }
    fn_2169_086b();
    fn_2318_0000();
    ovr_2ddf_002f();
    fn_1981_01af(p);
    g_1592 = 1;
    g_3618 = 1;
    return 0;
}
