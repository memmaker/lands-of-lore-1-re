/* o2dcd: stop the second sound driver's current sample and release its buffer */

extern int g_28fa, g_2922, g_291e, g_3747, g_2962;
extern void far *g_2924;
extern long g_2908, g_290c, g_28fc, g_28c6;
void fn_1b79_02e3(int h, int c);
void fn_1b79_02b1(int h, int c);
void fn_203b_0203(void far *p);
void ovr_2db3_0025(int far *p);

void ovr_2dcd_0020(void)
{
    if (g_28fa != -1) {
        if (g_3747 == 7) {
            asm mov dx,g_2962
            asm add dx,4
            asm mov al,83h
            asm out dx,al
            asm inc dx
            asm mov al,0fh
            asm out dx,al
        }
        if (g_2922 != -1) {
            fn_1b79_02e3(g_28fa, g_2922);
            fn_1b79_02b1(g_28fa, g_2922);
            g_2922 = -1;
        }
        fn_203b_0203(g_2924);
        g_2924 = 0;
    }
    if (g_2908 == g_28c6) {
        g_2908 = 0;
        g_290c = 0;
        g_28fc = 0;
        g_291e = -1;
    } else {
        ovr_2db3_0025(&g_28fa);
    }
}
