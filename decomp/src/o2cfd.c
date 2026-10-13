/* o2cfd: memory requirement estimates for the selected sound/music drivers */
#include <dos.h>

extern unsigned char g_ad42, g_ad43, g_ad44;
int fn_22d7_000a(void);
long ovr_2cfd_0020(void);

long ovr_2cfd_002a(void)
{
    long n;

    n = ovr_2cfd_0020();
    if (fn_22d7_000a() == 3) return n + 0x83590L;
    return n + 0x872e8L;
}

long ovr_2cfd_0025(void)
{
    unsigned far *p;
    long n = 0;

    p = MK_FP(_psp, 0);
    n = (unsigned)(p[1] - _psp);
    return n << 4;
}

long ovr_2cfd_0020(void)
{
    long n = 0;

    switch (g_ad42) {
    case 0: break;
    case 1: case 8: case 9: case 10: case 11: case 12:
        n += 7000; g_ad42 = 1; break;
    case 4: n += 1700; break;
    case 5: n += 8500; break;
    case 6: case 7: n += 10500; break;
    default: g_ad42 = 0;
    }
    if (g_ad43 != g_ad42) {
        switch (g_ad43) {
        case 0: break;
        case 1: case 8: case 9: case 10: case 11: case 12:
            n += 7000; g_ad43 = 1; break;
        case 4: n += 1700; break;
        case 5: n += 8500; break;
        case 6: case 7: n += 10500; break;
        default: g_ad43 = 0;
        }
    } else if (g_ad42 == 6 || g_ad42 == 7) {
        n += 1000;
    }
    switch (g_ad44) {
    case 0: break;
    case 1: n += 0xf0a; break;
    case 2: n += 0x1036; break;
    case 4: n += 0x1194; break;
    case 5: n += 0xed8; break;
    default: g_ad44 = 0;
    }
    return n;
}
