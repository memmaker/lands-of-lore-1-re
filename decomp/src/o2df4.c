/* o2df4: input recording / playback file control (mode 0 stop, 1 record to name, 2 play back from name) */
/* FLAGS: -ml -3 -Y */
#include <stdlib.h>

extern int g_35e8, g_35ec, g_3846;
extern char g_35ee;
extern int g_35ef, g_35ea, g_35f1, g_35f3, g_2f0c, g_2f0e;
extern char g_2f45;
extern long g_3842;
void fn_2169_04f7(int m);
void fn_2169_04ba(int m);
void fn_2169_0945(int k);
void fn_1809_058d(int h);
int fn_1809_0000(char far *name, int mode);
long fn_1809_084d(int h, void far *buf, long n);
int ovr_2ddf_002a(int on);
void ovr_2e2a_0020(char far *name);
void ovr_2e2a_0025(char far *name);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);

void ovr_2df4_0020(int mode, char far *name)
{
    int old;

    switch (mode) {
    case 0:
        g_35ee = mode;
        if (g_35e8 != -1) {
            fn_2169_04f7(0x800);
            fn_1809_058d(g_35e8);
        }
        g_35e8 = -1;
        g_35ec = 1;
        break;
    case 1:
        if (g_35e8 == -1) {
            old = ovr_2ddf_002a(0);
            ovr_2e2a_0020(name);
            ovr_2e2a_0025(name);
            srand(0x1234);
            g_3842 = 0x12344321L;
            g_35e8 = fn_1809_0000(name, 3);
            ovr_2ddf_002a(old);
            g_35ee = mode;
            fn_2169_04ba(0x800);
            fn_2169_0945(0x2d);
        }
        break;
    case 2:
        if (g_35e8 == -1) {
            g_35e8 = fn_1809_0000(name, 1);
            srand(0x1234);
            g_3842 = 0x12344321L;
        }
        g_35ec = 1;
        fn_1809_084d(g_35e8, &g_35ef, 2L);
        if (fn_1809_084d(g_35e8, &g_35ea, 2L) == 2) {
            if ((g_35ef >= 0x41 && g_35ef <= 0x44) || g_35ef == 0x2d) {
                fn_1809_084d(g_35e8, &g_35f1, 2L);
                if (fn_1809_084d(g_35e8, &g_35f3, 2L) == 2) {
                    g_2f0c = g_35f1;
                    g_2f0e = g_35f3;
                    g_2f45 = 0;
                    fn_1ebc_00e7();
                    fn_1ebc_00fe();
                    g_35ec = 0;
                } else {
                    g_35ec = 1;
                }
            } else {
                g_35ec = 0;
            }
        }
        break;
    }
    g_3846 = 0;
    g_35ee = mode;
}
