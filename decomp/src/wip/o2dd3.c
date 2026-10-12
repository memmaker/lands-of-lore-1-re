/* o2dd3: stop the first sound driver's four channels and release their buffers */
/* FLAGS: -ml -3 -Y */

struct SndCh { int h; void far *p; };

extern int g_28b8, g_28dc, g_3745, g_2962;
extern struct SndCh g_28e2[4];
extern long g_2908, g_28c6, g_28ca, g_28ba;
void fn_1b79_02e3(int h, int c);
void fn_1b79_02b1(int h, int c);
void fn_203b_0203(void far *p);
void ovr_2db3_0025(int far *p);

void ovr_2dd3_0020(void)
{
    int i;

    if (g_28b8 != -1) {
        if (g_3745 == 7) {
            asm mov dx,g_2962
            asm add dx,4
            asm mov al,83h
            asm out dx,al
            asm inc dx
            asm mov al,0fh
            asm out dx,al
        }
        for (i = 0; i < 4; i++) {
            if (g_28e2[i].h != -1) {
                fn_1b79_02e3(g_28b8, g_28e2[i].h);
                fn_1b79_02b1(g_28b8, g_28e2[i].h);
                g_28e2[i].h = -1;
            }
            fn_203b_0203(g_28e2[i].p);
            g_28e2[i].p = 0;
        }
    }
    if (g_2908 == g_28c6) {
        g_28c6 = 0;
        g_28ca = 0;
        g_28ba = 0;
        g_28dc = -1;
    } else {
        ovr_2db3_0025(&g_28b8);
    }
}
