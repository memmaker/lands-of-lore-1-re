/* s033: switch sound driver file (mirror of s031 with the roles of the two driver slots swapped) */
#pragma inline

extern int g_28b8;
extern void (far *g_28c6)(void);
extern long g_2910, g_2914, g_2918;
extern int g_291c;
extern long g_28ce, g_28d2, g_28d6;
extern int g_28da;

void fn_17d6_0123(void);
void ovr_2db9_003e(int *drv);
char far *ovr_2db9_0020(char far *name, int *drv);
long ovr_2db9_0039(char far *name, int *drv, long a, long b);
int stricmp(const char far *a, const char far *b);

long fn_17f8_0003(char far *name, long a, long b)
{
    long r;
    long total;
    void (far *drv)(void);
    long p;

    total = 0;
    fn_17d6_0123();
    ovr_2db9_003e(&g_28b8);
    if (g_28b8 == -1 && g_28c6 == 0)
        goto done;
    if (g_28ce == g_2910) {
        g_28ce = 0;
        g_28d6 = 0;
        g_28d2 = 0;
        g_28da = 0;
    } else {
        ovr_2db9_003e(&g_28b8);
    }
    if (g_2914 == 0)
        goto load;
    if (stricmp(ovr_2db9_0020(name, &g_28b8), (char far *)g_2914) == 0) {
        g_28ce = g_2910;
        g_28d6 = g_2918;
        g_28d2 = g_2914;
        g_28da = g_291c;
        if (g_28b8 == -1) {
            drv = g_28c6;
            p = g_28ce;
            asm push es;
            asm les ax, p;
            asm mov dx, es;
            asm pop es;
            asm mov bx, 4;
            asm pushf;
            asm call dword ptr drv;
        }
        goto done;
    }
load:
    r = ovr_2db9_0039(name, &g_28b8, a, b);
    total += r;
done:
    return total;
}
