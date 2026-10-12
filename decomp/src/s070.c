/* s070: WW library -- select the current font, return the previous one */
extern void far *g_ae53;
extern char far *g_362a;
extern char g_3629, g_3628;
extern unsigned g_ad91;
extern int g_ad8f, g_3717, g_371b, g_3719;
void far fn_1e07_0298(void);

void far *fn_1f2d_0002(void far *font)
{
    void far *old;
    char far *info;
    old = g_ae53;
    if (font) {
        g_ae53 = font;
        g_362a = (char far *)font + ((int far *)font)[4];
        info = (char far *)font + ((int far *)font)[2];
        g_3629 = info[4];
        g_3628 = info[5];
        fn_1e07_0298();
        g_3717 = g_ad91 / g_3629;
        g_371b = g_ad8f << 3;
        g_3719 = g_371b / g_3628;
    }
    return old;
}
