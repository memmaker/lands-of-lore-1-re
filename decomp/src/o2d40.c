/* o2d40: (arg > 1) reset the game state for a new start */

extern int far g_2f54;
extern void (far *g_370d)(void);
extern int g_35e4, g_35e2, g_20cd, g_20cf, g_4bf8, g_374c, g_20d5, g_2134, g_7fb6;
void fn_13e8_09b7(void);
void ovr_2d50_0039(void);
void ovr_2d2c_0070(void);
void fn_231c_0008(int);
void fn_0ca0_0c33(void);

void ovr_2d40_0020(int n)
{
    if (n > 1) {
        g_2f54 = 0x60;
        g_370d = fn_13e8_09b7;
        g_35e4 = 1;
        g_35e2 = 1;
        g_20cd = 1;
        g_20cf = 1;
        g_4bf8 = -1;
        g_374c = 0;
        g_20d5 = 3;
        ovr_2d50_0039();
        if (g_2134 == 0) ovr_2d2c_0070();
        g_7fb6 = 1;
        fn_231c_0008(1);
        fn_0ca0_0c33();
    }
}
