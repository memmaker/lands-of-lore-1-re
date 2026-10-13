/* s143: WW library -- BIOS video mode get/set */
#include <dos.h>
extern union REGS g_af4c, g_af5c;
extern int g_388c, g_388e[];

int fn_2347_000f(void)
{
    g_af5c.x.ax = 0x0f00;
    int86(0x10, &g_af5c, &g_af4c);
    return g_af4c.x.ax & 0xff;
}

void fn_2347_0034(int mode)
{
    g_af5c.x.ax = mode < 9 ? g_388e[mode] : g_388c;
    if (g_388e[mode] != g_388c)
        int86(0x10, &g_af5c, &g_af4c);
}
