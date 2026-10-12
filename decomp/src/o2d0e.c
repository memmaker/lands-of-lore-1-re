/* o2d0e: the party gold/coin stack display (g_81e0 coins, 5 piles in g_09bc) */

extern int g_3649, g_81e0;
extern char g_09bc[];
extern int g_09c1[], g_09cb[];
extern char g_09d5[];
extern char g_09e1[];
extern void far *g_7fbc;
void fn_1e30_000a(int x, int y, int w, int h);
void fn_1e30_0209(int x1, int y1, int x2, int y2, int c);
void far *fn_1f2d_0002(void far *p);
void fn_0845_07b3(char far *s, int x, int y, int c1, int c2, int a, int n);
void fn_1ebc_0111(int x1, int y1, int x2, int y2);
void fn_1dbc_0004(int a, int b, int c, int d, int w, int h, int e, int f);
void fn_1ebc_01ec(void);
void fn_1e59_001d(int x1, int y1, int x2, int y2, int c);
void fn_067a_0401(int snd, int x);
void fn_0845_0bb6(int n);
void ovr_2d0e_0025(int page);
void ovr_2d0e_002f(int n, int snd);

void ovr_2d0e_0020(int page)
{
    int old;
    int y;
    void far *p;
    register int i;
    register int x;

    old = g_3649;
    ovr_2d0e_0025(page);
    g_3649 = page;
    fn_1e30_000a(0, 0, 0x140, 0xc8);
    for (i = 0; i < 5; i++) {
        x = g_09c1[i];
        y = g_09cb[i];
        if (g_09bc[i] != 0) {
            fn_1e30_0209(x, y, x, y - (g_09bc[i] - 1), 0xd2);
            fn_1e30_0209(x + 1, y, x + 1, y - (g_09bc[i] - 1), 0xd1);
            fn_1e30_0209(x + 2, y, x + 2, y - (g_09bc[i] - 1), 0xd0);
            fn_1e30_0209(x + 3, y, x + 3, y - (g_09bc[i] - 1), 0xd1);
            fn_1e30_0209(x + 4, y, x + 4, y - (g_09bc[i] - 1), 0xd2);
        }
    }
    p = fn_1f2d_0002(g_7fbc);
    fn_0845_07b3(g_09e1, 0x131, 0x62, 0xfe, 0, 1, g_81e0);
    fn_1f2d_0002(p);
    g_3649 = old;
    if (page == 6) {
        fn_1ebc_0111(0x124, 0x61, 0x13d, 0x77);
        fn_1dbc_0004(0x124, 0x61, 0x124, 0x61, 0x19, 0x16, 6, 0);
        fn_1ebc_01ec();
    }
}

void ovr_2d0e_0025(int page)
{
    int old;

    old = page;
    g_3649 = page;
    fn_1e59_001d(0x124, 0x61, 0x13c, 0x76, 0xfc);
    g_3649 = old;
}

void ovr_2d0e_002a(void)
{
    int n;

    asm mov cx,2
    asm mov di,offset g_09bc
    asm push ds
    asm pop es
    asm db 33h, 0c0h    /* xor ax,ax as BCC encodes it */
    asm rep stosw
    asm stosb
    n = g_81e0;
    g_81e0 = 0;
    ovr_2d0e_002f(n, 0);
}

void ovr_2d0e_002f(int n, int snd)
{
    int x, step, i, k;

    x = n;
    if (snd) fn_067a_0401(0x65, 0);
    step = x / 30;
    step = step == 0 ? 1 : step;
    while (x) {
        if (step > x) step = x;
        if (g_81e0 < 60) {
            for (i = 0; i < step; i++) {
                if (g_81e0 < 60) {
                    k = g_09d5[g_81e0 % 12] - g_81e0 / 12;
                    if (k < 0) k += 5;
                    g_09bc[k]++;
                }
                g_81e0++;
            }
        } else g_81e0 += step;
        if (snd) {
            ovr_2d0e_0020(6);
            if (x) fn_0845_0bb6(1);
        }
        x -= step;
    }
}

void ovr_2d0e_0034(int n, int snd)
{
    int x, step, i, k;

    x = n;
    if (snd) fn_067a_0401(0x65, 0);
    if (x > g_81e0) x = g_81e0;
    step = x / 30;
    step = step == 0 ? 1 : step;
    while (g_81e0 > 0 && x) {
        if (step > x) step = x;
        if (g_81e0 - step < 60) {
            for (i = 0; i < step; i++) {
                g_81e0--;
                if (g_81e0 < 60) {
                    k = g_09d5[g_81e0 % 12] - g_81e0 / 12;
                    if (k < 0) k += 5;
                    g_09bc[k]--;
                }
            }
        } else g_81e0 -= step;
        if (snd) {
            ovr_2d0e_0020(6);
            if (x) fn_0845_0bb6(1);
        }
        x -= step;
    }
}
