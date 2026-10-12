/* s011: view transition animations (step forward/back, turn left/right, swing) */
#include "lol.h"

extern char far f_2803_0000[];
extern unsigned g_7fda;
extern int g_4d70, g_4d72;
extern unsigned long g_3850;
extern void far *g_4edc;
extern char g_1f3a, g_7fdc;

void far *fn_215f_001d(int page);
void far *fn_2037_0002(void far *p, long off);
int ovr_2cda_005c(int page);
void ovr_2cda_0057(int page);
void fn_0845_15d9(int a);
void fn_19c9_09a4(void far *a, void far *b);
void fn_234e_0003(int n);
void fn_19c9_07e2(void far *a, void far *b, int x, int y);
void fn_19c9_089f(void far *a, void far *b, int x, int y);
void fn_19c9_079a(void far *a, void far *b);
void fn_19c9_095d(void far *a, void far *b);
void fn_19c9_09cf(void far *a, void far *b);
void fn_19c9_0a01(void far *a, void far *b, void far *c);
void fn_19c9_0a61(void far *a, void far *b, void far *c);
void fn_19c9_0ab1(void far *a, void far *b, void far *c);
void fn_19c9_0b55(void far *a, int x, int y, int w);
void fn_19c9_0b15(void far *a, int x, void far *b, int y, int w);
int fn_0845_11b7(void);
void fn_1ebc_01ec(void);
void fn_0845_08aa(void);

int g_2270[5] = { 5, 10, 15, 20, 25 };
int g_227a[5] = { 2, 4, 7, 9, 12 };
int g_2284[5] = { 5, 10, 15, 20, 25 };
int g_228e[5] = { 4, 8, 12, 16, 20 };

int fn_0acb_000f(void)
{
    return f_2803_0000[0x44];
}

void fn_0acb_001e(int delay)
{
    void far *pg2;
    void far *buf;
    void far *pg6;
    void far *pg0;
    register int i;
    register int f;

    if (!(g_7fda & 8)) return;
    if (fn_0acb_000f()) return;
    pg2 = fn_215f_001d(2);
    pg6 = fn_215f_001d(6);
    pg0 = fn_215f_001d(0);
    buf = fn_2037_0002(pg2, 0xa500L);
    if (g_4d70 == 2) {
        f = ovr_2cda_005c(6);
        fn_0845_15d9(6);
        fn_19c9_09a4(pg6, buf);
        fn_19c9_09a4(pg2, pg6);
    } else {
        f = ovr_2cda_005c(2);
        fn_0845_15d9(2);
        fn_19c9_09a4(pg2, buf);
        fn_19c9_09a4(pg6, pg6);
    }
    fn_234e_0003(2);
    for (i = 0; i < 5; i++) {
        g_3850 = delay;
        fn_19c9_07e2(pg6, pg2, g_2270[i], g_227a[i]);
        fn_19c9_089f(pg6, pg2, g_2284[i], g_228e[i]);
        if (f) fn_19c9_079a(g_4edc, pg2);
        fn_19c9_095d(pg2, pg0);
        do fn_0845_11b7(); while (g_3850);
        if (!g_1f3a) i++;
    }
    if (f) fn_19c9_079a(g_4edc, buf);
    if (g_7fdc != 2) fn_19c9_095d(buf, pg0);
    fn_1ebc_01ec();
    fn_0845_08aa();
}

void fn_0acb_01b4(int delay)
{
    void far *pg2;
    void far *pg6;
    void far *pg0;
    register int i;
    register int d = delay;

    if (!(g_7fda & 8)) return;
    if (fn_0acb_000f()) return;
    pg2 = fn_215f_001d(2);
    pg6 = fn_215f_001d(6);
    pg0 = fn_215f_001d(0);
    if (g_4d70 == 2) fn_19c9_09a4(pg2, pg6);
    else fn_19c9_09a4(pg6, pg6);
    fn_234e_0003(2);
    for (i = 0; i < 2; i++) {
        g_3850 = d;
        fn_19c9_07e2(pg6, pg2, g_2270[i], g_227a[i]);
        fn_19c9_089f(pg6, pg2, g_2284[i], g_228e[i]);
        fn_19c9_095d(pg2, pg0);
        while (g_3850 > 0);
        if (!g_1f3a) i++;
    }
    while (i > 0) {
        if (!g_1f3a) i--;
        g_3850 = d;
        fn_19c9_07e2(pg6, pg2, g_2270[i], g_227a[i]);
        fn_19c9_089f(pg6, pg2, g_2284[i], g_228e[i]);
        fn_19c9_095d(pg2, pg0);
        while (g_3850 > 0);
        i--;
    }
    if (g_7fdc != 2) fn_19c9_095d(pg6, pg0);
    fn_1ebc_01ec();
    fn_0845_08aa();
}

void fn_0acb_032e(int delay)
{
    void far *pg2;
    void far *pg6;
    void far *pg0;
    register int i;
    register int f;

    if (!(g_7fda & 8)) return;
    pg2 = fn_215f_001d(2);
    pg6 = fn_215f_001d(6);
    pg0 = fn_215f_001d(0);
    f = ovr_2cda_005c(2);
    fn_0845_15d9(2);
    fn_19c9_09a4(pg2, pg6);
    fn_234e_0003(2);
    for (i = 4; i >= 0; i--) {
        g_3850 = delay;
        fn_19c9_07e2(pg6, pg2, g_2270[i], g_227a[i]);
        fn_19c9_089f(pg6, pg2, g_2284[i], g_228e[i]);
        if (f) fn_19c9_079a(g_4edc, pg2);
        fn_19c9_095d(pg2, pg0);
        do fn_0845_11b7(); while (g_3850);
        if (!g_1f3a) i--;
    }
    if (f) fn_19c9_079a(g_4edc, pg6);
    if (g_7fdc != 2) fn_19c9_095d(pg6, pg0);
    fn_1ebc_01ec();
    fn_0845_08aa();
}

void fn_0acb_0461(int delay)
{
    void far *a;
    void far *b;
    void far *buf;
    void far *z;
    register int d = delay;
    register int f;

    if (!(g_7fda & 8)) return;
    d <<= 1;
    a = fn_215f_001d(g_4d70);
    b = fn_215f_001d(g_4d72);
    z = fn_215f_001d(0);
    if (g_4d70 == 2) buf = fn_2037_0002(a, 0xa500L);
    else buf = fn_2037_0002(b, 0xa500L);
    f = ovr_2cda_005c(g_4d72);
    fn_0845_15d9(g_4d72);
    fn_234e_0003(2);
    g_3850 = d;
    fn_19c9_0a01(b, a, buf);
    if (f) fn_19c9_079a(g_4edc, buf);
    fn_19c9_095d(buf, z);
    do fn_0845_11b7(); while (g_3850);
    g_3850 = d;
    fn_19c9_0a61(b, a, buf);
    if (f) fn_19c9_079a(g_4edc, buf);
    fn_19c9_095d(buf, z);
    do fn_0845_11b7(); while (g_3850);
    g_3850 = d;
    fn_19c9_0ab1(b, a, buf);
    if (f) fn_19c9_079a(g_4edc, buf);
    fn_19c9_095d(buf, z);
    do fn_0845_11b7(); while (g_3850);
    if (g_7fdc != 2) {
        ovr_2cda_0057(g_4d72);
        fn_19c9_09cf(b, z);
    }
    fn_1ebc_01ec();
}

void fn_0acb_0604(int delay)
{
    void far *a;
    void far *b;
    void far *buf;
    void far *z;
    register int d = delay;
    register int f;

    if (!(g_7fda & 8)) return;
    d <<= 1;
    a = fn_215f_001d(g_4d70);
    b = fn_215f_001d(g_4d72);
    z = fn_215f_001d(0);
    if (g_4d70 == 2) buf = fn_2037_0002(a, 0xa500L);
    else buf = fn_2037_0002(b, 0xa500L);
    f = ovr_2cda_005c(g_4d72);
    fn_0845_15d9(g_4d72);
    fn_234e_0003(2);
    g_3850 = d;
    fn_19c9_0ab1(a, b, buf);
    if (f) fn_19c9_079a(g_4edc, buf);
    fn_19c9_095d(buf, z);
    do fn_0845_11b7(); while (g_3850);
    g_3850 = d;
    fn_19c9_0a61(a, b, buf);
    if (f) fn_19c9_079a(g_4edc, buf);
    fn_19c9_095d(buf, z);
    do fn_0845_11b7(); while (g_3850);
    g_3850 = d;
    fn_19c9_0a01(a, b, buf);
    if (f) fn_19c9_079a(g_4edc, buf);
    fn_19c9_095d(buf, z);
    do fn_0845_11b7(); while (g_3850);
    if (g_7fdc != 2) {
        ovr_2cda_0057(g_4d72);
        fn_19c9_09cf(b, z);
    }
    fn_1ebc_01ec();
}

void fn_0acb_07a7(int delay)
{
    void far *a;
    void far *b;
    void far *z;
    register int x;
    register int y;

    if (!(g_7fda & 8)) return;
    delay <<= 1;
    a = fn_215f_001d(g_4d70);
    b = fn_215f_001d(g_4d72);
    z = fn_215f_001d(0);
    fn_0845_15d9(g_4d72);
    g_4d72 ^= g_4d70;
    g_4d70 ^= g_4d72;
    g_4d72 ^= g_4d70;
    fn_234e_0003(2);
    for (x = y = 0x58; x > 0x16; x -= 0x16, y += 0x16) {
        g_3850 = delay;
        fn_19c9_0b55(a, 0x42, y, x / 2);
        fn_19c9_0b15(b, x, a, 0, y / 2);
        fn_19c9_09cf(a, z);
        do fn_0845_11b7(); while (g_3850);
    }
    if (g_7fdc != 2) fn_19c9_09cf(b, z);
    fn_1ebc_01ec();
}

void fn_0acb_089c(int delay)
{
    void far *a;
    void far *b;
    void far *z;
    register int d = delay;

    if (!(g_7fda & 8)) return;
    d <<= 1;
    a = fn_215f_001d(g_4d70);
    b = fn_215f_001d(g_4d72);
    z = fn_215f_001d(0);
    fn_0845_15d9(g_4d72);
    g_4d72 ^= g_4d70;
    g_4d70 ^= g_4d72;
    g_4d72 ^= g_4d70;
    fn_234e_0003(2);
    g_3850 = d;
    fn_19c9_0b15(b, 0, a, 0x6e, 0x21);
    fn_19c9_09cf(a, z);
    do fn_0845_11b7(); while (g_3850);
    g_3850 = d;
    fn_19c9_0b55(a, 0x16, 0, 0x21);
    fn_19c9_0b15(b, 0, a, 0x58, 0x2c);
    fn_19c9_09cf(a, z);
    do fn_0845_11b7(); while (g_3850);
    g_3850 = d;
    fn_19c9_0b55(a, 0x2c, 0, 0xb);
    fn_19c9_0b15(b, 0, a, 0x42, 0x37);
    fn_19c9_09cf(a, z);
    do fn_0845_11b7(); while (g_3850);
    if (g_7fdc != 2) fn_19c9_09cf(b, z);
    fn_1ebc_01ec();
}
