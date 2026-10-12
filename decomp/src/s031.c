/* s031: load a sound driver file into the music driver slot (g_28fa); s033 mirrors it for g_28b8 */
#pragma inline

extern int g_28fa;
extern void (far *g_2908)(void);
extern long g_28ce, g_28d2, g_28d6;
extern int g_28da;
extern long g_2910, g_2914, g_2918;
extern int g_291c;

void fn_178d_015e(void);
void ovr_2db9_003e(int *drv);
char far *ovr_2db9_0020(char far *name, int *drv);
long ovr_2db9_0039(char far *name, int *drv, long a, long b);
int stricmp(const char far *a, const char far *b);

long fn_17c5_0004(char far *name, long a, long b)
{
    long r;
    long total;
    void (far *drv)(void);
    long p;

    total = 0;
    fn_178d_015e();
    ovr_2db9_003e(&g_28fa);
    if (g_28fa == -1 && g_2908 == 0)
        goto done;
    if (g_2910 == g_28ce) {
        g_2910 = 0;
        g_2918 = 0;
        g_2914 = 0;
        g_291c = 0;
    } else {
        ovr_2db9_003e(&g_28fa);
    }
    if (g_28d2 == 0)
        goto load;
    if (stricmp(ovr_2db9_0020(name, &g_28fa), (char far *)g_28d2) == 0) {
        g_2910 = g_28ce;
        g_2918 = g_28d6;
        g_2914 = g_28d2;
        g_291c = g_28da;
        if (g_28fa == -1) {
            drv = g_2908;
            p = g_2910;
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
    r = ovr_2db9_0039(name, &g_28fa, a, b);
    total += r;
    if (a) ;
done:
    return total;
}
