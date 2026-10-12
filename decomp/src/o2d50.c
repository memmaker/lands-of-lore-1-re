/* o2d50: game start-up (load shapes, fonts, palettes, main menu) and init script opcodes */
#include <string.h>
#include <mem.h>
#include <alloc.h>
#include <process.h>
#include "lol.h"

struct Ctx { char pad[0xc]; int sp; char pad2[0x1e]; int stack[1]; };
#define CARG(c, n) ((c)->stack[(c)->sp + (n)])
extern char g_1066[], g_1072[], g_107e[], g_108a[], g_1096[], g_10a1[], g_10ab[], g_10b6[];
extern char g_10bc[], g_10c5[], g_10d0[], g_10d6[], g_10e3[], g_10eb[], g_10f1[], g_10fb[];
extern char g_1105[], g_110d[], g_1119[], g_1125[], g_112e[], g_113a[];
extern int g_1052[][5];
extern void far *g_7d82[];
extern void far *g_7c92[];
extern void far *g_4e54[];
extern void far * far f_2803_00a6[];
extern unsigned char far f_2803_030a[], far f_2803_020a[];
extern void far *g_4d6c;
extern int g_4b92;
extern char g_20db;
extern char g_1f3a;
extern unsigned char far *g_adea;
extern void far *g_ae4f;
extern void far *g_7fb8, far *g_7fbc;
extern int far *g_7fcc;
extern void far *g_7faa;
extern int far *g_4edc;
extern int g_3747;
extern long g_3697;
extern int g_4d70, g_4d72;
extern char **_argv;
extern int g_20e2, g_1fa1;
extern unsigned g_ad8b, g_ad8d, g_ad8f, g_ad91;
extern int g_2134;
extern char g_ae59[];
extern void far *g_4ea0;
extern int g_7fd0;
extern void far *g_4c06[][28];
extern void far *g_540e, far *g_4bcc, far *g_4d5a, far *g_4d56, far *g_4d62;
extern void far *g_4bec, far *g_4bf0;
extern long g_20f8;
extern unsigned long g_4b94;
extern int g_20d9;
extern struct ItemType far *g_7fb2;

int ovr_2d46_0020(char far *s, int n);
void far *ovr_2d46_0025(int a, int b, int c);
char far *ovr_2d46_002f(char far *name, int n);
void far *fn_215f_0003(int p);
void far *fn_1f36_0064(void far *p, int idx);
void fn_1e9f_0002(int x, int y, void far *shape);
void fn_0845_0acf(int item);
void fn_203b_0203(void far *p);
void far *fn_203b_0007(long size, int flags);
int fn_1809_0000(char far *name, int mode);
long fn_1809_120c(int h);
long fn_1809_084d(int h, void far *buf, unsigned long n);
void fn_1809_058d(int h);
int ovr_2d2c_00e3(int a, int b, int c);
int fn_1c86_000a(void);
void fn_1ef2_001c(void far *pal);
void ovr_2ded_002f(char far *str, int a, int b, void far *p);
void fn_1dbc_0017(int a, int b, int c, int d, int e, int f, int g, int h);
void fn_1ef2_0075(unsigned char far *pal, int delay, long a);
void far *ovr_2df1_0020(char far *name);
void fn_1f2d_0002(void far *p);
void ovr_2dfa_0020(void far *p, int n);
void ovr_2da3_0020(int id);
void fn_17c5_0004(char far *name, void far *buf, long size);
void fn_178d_0091(int song);
int fn_178d_0038(void);
void fn_0845_07b3(char far *s, int x, int y, int fg, int bg, int f);
int fn_1981_000a(char far *name);
char far *fn_0845_06f8(int id);
void fn_14b3_0122(int n);
void fn_2096_014b(int x, int y, int w, int h, void far *p, int page);
void fn_2096_0000(int x, int y, int w, int h, void far *p, int page);
void ovr_2cfa_0020(int x, int y, int w, int h, int style, int fill);
void ovr_2d43_0020(int m, char far * far *items, unsigned long mask, int shift, int step);
int ovr_2d43_0025(int m, char far * far *items, long unused, unsigned long mask, int shift);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_2169_062e(void);
int ovr_2d56_002f(int a);
void ovr_2d56_0043(void);
void far fn_2309_000c(void);
void fn_2148_002c(int drive);
void fn_2148_014d(char far *s);
void fn_0845_0bf6(void);
void fn_0845_14a6(char far *arg);
int fn_15a7_0004(void far *p, unsigned long size);
void fn_2279_025b(void far *s, void far *d, long n);
void fn_1b43_000e(void far *pal, unsigned char far *tab, int a, int b);
int fn_067a_0572(unsigned long size);
void fn_0845_09f1(int n);
void fn_067a_060c(void);
void ovr_2d2c_007f(char far *s, int a);
void ovr_2d2c_0084(char far *s);
int ovr_2e22_0025(char far *name);
void ovr_2d1b_0020(void);
void ovr_2d03_0020(void);
void fn_14b3_00c8(char far *s, int a, long b);
void fn_14b3_0108(void);
void fn_0845_0a5b(void);
void ovr_2d50_0048(void);

void ovr_2d50_004d(void)
{
    int i;

    ovr_2d46_0020(g_1066, 3);
    for (i = 0; i < 0x8a; i++)
        if (fn_1f36_0064(fn_215f_0003(3), i))
            fn_1e9f_0002(0, 0, fn_1f36_0064(fn_215f_0003(3), i));
    g_7d82[0] = ovr_2d46_0025(3, 0, 0);
    fn_0845_0acf(0);
}

void ovr_2d50_0020(char far *name)
{
    unsigned long max;
    unsigned long sz;
    int fh[3];
    int i;

    if (g_4d6c) {
        fn_203b_0203(g_4d6c);
        g_4d6c = 0;
    }
    if (name == 0) return;
    max = 0;
    for (i = 0; i < 3; i++) {
        fh[i] = fn_1809_0000(ovr_2d46_002f(name, i), 1);
        sz = fn_1809_120c(fh[i]);
        if (sz > max) max = sz;
    }
    g_4d6c = fn_203b_0007(max, g_4b92);
    fn_1809_084d(fh[g_20db], g_4d6c, fn_1809_120c(fh[g_20db]));
    for (i = 0; i < 3; i++) fn_1809_058d(fh[i]);
}

void ovr_2d50_0025(void)
{
    int i;

    for (i = 0; i < 400; i++) f_2803_1cfd[i].flags |= 0x8000;
}

void ovr_2d50_002a(void)
{
    int i;
    int n;

    n = ovr_2d46_0020(g_1072, 3);
    for (i = 1; i < n; i++) g_7d82[i] = ovr_2d46_0025(3, i, g_4b92);
}

void ovr_2d50_002f(void)
{
    int i;
    int n;

    n = ovr_2d46_0020(g_107e, 3);
    for (i = 0; i < n; i++) g_7c92[i] = ovr_2d46_0025(3, i, g_4b92);
}

void ovr_2d50_0034(void)
{
    int i;
    int n;
    int k;

    n = ovr_2d46_0020(g_108a, 3);
    for (i = 0; i < n; i++) {
        k = ovr_2d2c_00e3(3, i, 1);
        k = k == 1 ? g_4b92 : 0;
        f_2803_00a6[i] = ovr_2d46_0025(3, i, k);
    }
    n = ovr_2d46_0020(g_1096, 3);
    for (i = 0; i < n; i++) g_4e54[i] = ovr_2d46_0025(3, i, g_4b92);
}

void ovr_2d50_0039(void)
{
    int i;
    int sel;

    g_1f3a = fn_1c86_000a() >= 4;
    memset(g_adea, 0, 0x300);
    fn_1ef2_001c(g_adea);
    ovr_2ded_002f(g_10a1, 2, 2, g_adea);
    fn_1dbc_0017(0, 0, 0, 0, 0x28, 0xc8, 2, 0);
    fn_1ef2_0075(g_adea, 0x1e, 0L);
    g_7fb8 = g_ae4f;
    g_7fbc = ovr_2df1_0020(g_10ab);
    fn_1f2d_0002(g_7fb8);
    g_7fcc = fn_215f_0003(3);
    g_7faa = fn_203b_0007(10000L, 0x20);
    g_4edc = fn_203b_0007(0x1400L, 0x20);
    ovr_2dfa_0020(g_7faa, 10000);
    ovr_2da3_0020(0);
    ovr_2d50_0020(g_10b6);
    ovr_2d50_004d();
    if (g_3747 == 6 || g_3747 == 7) {
        fn_17c5_0004(g_10bc, fn_215f_0003(3), g_3697);
        fn_178d_0091(0);
        while (fn_178d_0038()) ;
        fn_17c5_0004(0, 0, 0L);
    }
    g_4d72 = 2;
    g_4d70 = 6;
    fn_1f2d_0002(g_7fbc);
    fn_0845_07b3(g_10c5, 0x104, 0xc1, 0x67, 0, 4);
    fn_1f2d_0002(g_7fb8);
    if (stricmp(_argv[1], g_10d0) == 0) {
        int m;
        char far *items[5];

        fn_1ebc_00fe();
        fn_1ebc_00e7();
        m = fn_1981_000a(g_10d6) ? 1 : 0;
        for (i = 0; i < 5; i++) items[i] = strdup(fn_0845_06f8(g_1052[m][i]));
        g_20e2 = m == 1 ? 4 : 3;
        g_20e2++;
        g_1fa1 = g_20e2 * 8 + 0xb;
        fn_14b3_0122(6);
        fn_2096_014b(g_ad8d * 8, g_ad8b, g_ad8f * 8, g_ad91, fn_215f_0003(3), 0);
        ovr_2cfa_0020(g_ad8d * 8, g_ad8b, g_ad8f * 8, g_ad91, 5, 1);
        ovr_2cfa_0020(g_ad8d * 8 + 1, g_ad8b + 1, g_ad8f * 8 - 2, g_ad91 - 2, 5, 0);
        ovr_2d43_0020(0, items, 0xffffL, 0, 0);
        fn_1ebc_00fe();
        fn_2169_062e();
        do {
            sel = ovr_2d43_0025(0, items, 0L, 0xffL, 0);
        } while (sel == -1);
        fn_1ebc_00e7();
        sel = g_1052[m][sel];
        for (i = 0; i < 4; i++) farfree(items[i]);
        fn_2096_0000(g_ad8d * 8, g_ad8b, g_ad8f * 8, g_ad91, fn_215f_0003(3), 0);
        switch (sel) {
        case 0x4248:
            fn_0845_14a6(g_10e3);
            break;
        case 0x4249:
            fn_0845_14a6(g_10eb);
            break;
        case 0x4001:
            ovr_2d50_0048();
            fn_1ebc_00fe();
            if (ovr_2d56_002f(0)) {
                ovr_2d56_0043();
                g_2134 = 1;
                return;
            }
            fn_2309_000c();
            fn_2148_002c(g_ae59[0] - 'A');
            fn_2148_014d(g_ae59);
            execl(g_10f1, g_10fb, 0L);
            break;
        case 0x424a:
            fn_0845_0bf6();
            break;
        case 0x42dd:
            fn_0845_14a6(g_1105);
            break;
        }
    }
    fn_1ebc_00fe();
    ovr_2d50_0048();
}

void ovr_2d50_0048(void)
{
    unsigned char pal[0x300];
    int i;

    g_4ea0 = fn_203b_0007(15000L, 0x20);
    if (fn_15a7_0004(g_4ea0, 15000L) != 1) {
        fn_2309_000c();
        exit(0);
    }
    ovr_2ded_002f(g_110d, 3, 3, g_adea);
    fn_2279_025b(g_adea, pal, 0x300L);
    memset(g_adea, 0x3f, 0x180);
    memcpy(g_adea + 3, pal + 3, 3);
    memset(g_adea + 0x240, 0x3f, 3);
    memset(g_adea + 0x243, 0x3f, 3);
    memset(g_adea + 0x246, 0x3f, 3);
    memset(g_adea + 0x249, 0x3f, 3);
    fn_1b43_000e(g_adea, f_2803_030a, 1, 0x60);
    fn_1b43_000e(g_adea, f_2803_020a, 0x90, 0x41);
    fn_2279_025b(pal, g_adea, 0x300L);
    setmem(&g_7fd0, 0x233, 0);
    for (i = 0; i < 3; i++) g_4c06[i][0] = fn_203b_0007(25000L, g_4b92);
    g_540e = fn_203b_0007(0x300L, 0x20);
    g_4bcc = fn_203b_0007(0x300L, 0);
    g_4d5a = fn_203b_0007(0x10000L, g_4b92);
    g_4d56 = fn_203b_0007(0x10000L, g_4b92);
    g_20f8 = 0x6590;
    g_4d62 = fn_203b_0007(g_20f8, 0x20);
    fn_067a_0572(g_4b94);
    ovr_2d50_002a();
    fn_0845_09f1(0x85);
    fn_067a_060c();
    ovr_2d50_002f();
    ovr_2d50_0034();
    ovr_2d50_0025();
    ovr_2d2c_007f(g_1119, 0);
    ovr_2d2c_0084(g_1125);
    ovr_2e22_0025(g_112e);
    g_4bec = fn_203b_0007(0x100L, 0);
    g_4bf0 = fn_203b_0007(0x1400L, 0x20);
    g_20d9 = 1;
    ovr_2d1b_0020();
    ovr_2d03_0020();
    fn_14b3_00c8(g_113a, 10, 0x1fL);
    fn_14b3_0108();
    fn_0845_0a5b();
}

int ovr_2d50_003e(struct Ctx far *c)
{
    g_7fb2 = fn_203b_0007((unsigned)(CARG(c, 0) * 13), 0);
    return 1;
}

int ovr_2d50_0043(struct Ctx far *c)
{
    int n;
    int i;

    n = CARG(c, 0);
    g_7fb2[n].name = CARG(c, 1);
    g_7fb2[n].shape = CARG(c, 2);
    g_7fb2[n].w5 = CARG(c, 3);
    g_7fb2[n].script = CARG(c, 4);
    g_7fb2[n].flags = CARG(c, 8);
    g_7fb2[n].wb = CARG(c, 9);
    for (i = 0; i < 3; i++) (&g_7fb2[n].w8)[i] = c->stack[i + c->sp + 5];
    return 1;
}
