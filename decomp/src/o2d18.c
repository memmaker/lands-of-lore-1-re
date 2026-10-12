/* o2d18: party heal/restore animation (loads the sparkle shapes, raises each character's HP bar over 16 steps) */
#include "lol.h"

extern int g_0b0a;                       /* shapes loaded */
extern void far *g_0afa[4];
extern void far *g_0aba[16];
extern char g_0b0c[], g_0b15[], g_0b1f[];
extern int g_4b92;
extern void far *g_540e;
extern long g_3850;
extern void far *g_4bec, far *g_4bf0;
extern int g_3649;
extern int far f_2803_3625[];
extern char far f_25fd_0000[], far f_25fd_0010[], far f_25fd_0020[], far f_25fd_0030[], far f_25fd_0040[];
extern char far f_25fd_0050[];
long ovr_2ded_002f(char far *name, int page, int dpage, void far *pal);
void far *ovr_2d46_0025(int a, int b, int c);
void ovr_2ce1_0043(void far *a, void far *b, int c, char d, int e, char f, int g, int h);
void ovr_2ce1_007f(char far *msg);
void fn_203b_0203(void far *p);
void far fn_1ebc_0111(int x1, int y1, int x2, int y2);
void far fn_1ebc_01ec(void);
void fn_1dbc_0004(int x1, int y1, int x2, int y2, int w, int h, int s, int d);
int fn_1e74_000f(int page);
void fn_067a_0401(int n, int force);
void fn_070c_0a8f(int who, int amt, int force);
void fn_0a21_022b(int who);
void far *fn_0845_04ec(void far *name);
void fn_1fd6_000a(int page, void far *p, int x, int y, int a, int flags, ...);
void fn_1e59_001d(int x1, int y1, int x2, int y2, int c);
void fn_19c9_1100(int page, int a, int b, int c, int x, int y, int w, int h, int d, int e, void far *f);
void fn_0bbc_0365(struct Char far *c, int from, int to);
void fn_0845_08aa(void);
int ovr_2d18_0020(void);
void ovr_2d18_0025(void);

int ovr_2d18_0020(void)
{
    register int i;

    if (g_0b0a != 1) {
        ovr_2ded_002f(g_0b0c, 3, 3, 0L);
        g_0afa[0] = ovr_2d46_0025(3, 0, g_4b92);
        g_0afa[1] = ovr_2d46_0025(3, 1, g_4b92);
        g_0afa[2] = ovr_2d46_0025(3, 2, g_4b92);
        g_0afa[3] = ovr_2d46_0025(3, 3, g_4b92);
        ovr_2ded_002f(g_0b15, 3, 3, 0L);
        for (i = 0; i < 16; i++)
            g_0aba[i] = ovr_2d46_0025(3, i, g_4b92);
        g_0b0a = 1;
    }
    ovr_2ce1_0043(g_540e, f_25fd_0050, 0x34, 0x16, 0x14, 0, 0x100, 1);
    return 1;
}

void ovr_2d18_0025(void)
{
    register int i;

    if (g_0b0a == 1) {
        for (i = 0; i < 4; i++) {
            if (g_0afa[i]) {
                fn_203b_0203(g_0afa[i]);
                g_0afa[i] = 0;
            }
        }
        for (i = 0; i < 16; i++) {
            if (g_0aba[i]) {
                fn_203b_0203(g_0aba[i]);
                g_0aba[i] = 0;
            }
        }
        g_0b0a = 0;
    }
}

void ovr_2d18_002a(register int who, register int kind)
{
    int page;
    int dmg[4];
    int x[4];
    int y[4];
    int v[4];
    int step;
    int first;
    int lim;
    int opened;
    int flag;
    char far *seqA;
    char far *seqB;

    opened = 0;
    if (g_0b0a != 1) {
        if (!ovr_2d18_0020()) ovr_2ce1_007f(g_0b1f);
        opened = 1;
    }
    switch (kind) {
    case 0:
        seqA = f_25fd_0000; seqB = f_25fd_0020; flag = 0; lim = 0x19;
        break;
    case 1:
        seqA = f_25fd_0010; seqB = f_25fd_0030; flag = 0; lim = 0x2d;
        break;
    case 2:
    case 3:
        seqA = f_25fd_0010; seqB = f_25fd_0040; flag = 1; lim = 10000;
        break;
    default:
        seqA = f_25fd_0010; seqB = f_25fd_0040; lim = kind; flag = 1;
        break;
    }
    if (who == -1) {
        first = 0;
        kind = 4;
    } else {
        first = who;
        kind = who + 1;
    }
    for (who = first; who < kind; who++) {
        if (f_2803_362d[who].flags & 1) {
            x[who] = f_2803_3625[who] - 6;
            y[who] = 0x8a;
            f_2803_362d[who].lastDmg = 0;
            if (f_2803_362d[who].maxHp - f_2803_362d[who].hp < lim)
                dmg[who] = f_2803_362d[who].maxHp - f_2803_362d[who].hp;
            else
                dmg[who] = lim;
            fn_1ebc_0111(x[who], y[who], x[who] + 0x4d, y[who] + 0x2c);
            fn_1dbc_0004(x[who], y[who], who * 0x4d, 0x20, 0x4d, 0x2c, 0, 2);
            fn_1ebc_01ec();
        }
    }
    page = fn_1e74_000f(2);
    fn_067a_0401(0x44, 0);
    step = 0;
    do {
        g_3850 = 4;
        for (who = first; who < kind; who++) {
            if (f_2803_362d[who].flags & 1) {
                fn_1dbc_0004(who * 0x4d, 0x20, x[who], y[who], 0x4d, 0x2c, 2, 2);
                v[who] &= 0xff;
                v[who] += (dmg[who] << 8) / 16;
                fn_070c_0a8f(who, v[who] / 256, 1);
                fn_0a21_022b(who);
                fn_1fd6_000a(2, fn_0845_04ec(g_0afa[seqA[step]]), x[who], y[who], 0, 0x1000, g_4bec, g_4bf0);
                fn_1e59_001d(0, 0, 0x1f, 0x1f, 0);
                fn_1fd6_000a(g_3649, fn_0845_04ec(g_0aba[seqB[step]]), 0, 0, 0, 0);
                fn_19c9_1100(g_3649, 0, 0, 2, x[who] + 7, y[who] + 6, 0x20, 0x20, 0, 0, f_25fd_0050);
                fn_1ebc_0111(x[who], y[who], x[who] + 0x4d, y[who] + 0x2c);
                fn_1dbc_0004(x[who], y[who], x[who], y[who], 0x4d, 0x2c, 2, 0);
                fn_1ebc_01ec();
            }
        }
        while (g_3850) ;
        step++;
    } while (step < 16);
    for (who = first; who < kind; who++) {
        if (f_2803_362d[who].flags & 1) {
            fn_1dbc_0004(who * 0x4d, 0x20, x[who], y[who], 0x4d, 0x2c, 2, 2);
            if (flag) fn_0bbc_0365(&f_2803_362d[who], 4, 4);
            fn_0a21_022b(who);
            fn_1ebc_0111(x[who], y[who], x[who] + 0x4d, y[who] + 0x2c);
            fn_1dbc_0004(x[who], y[who], x[who], y[who], 0x4d, 0x2c, 2, 0);
            fn_1ebc_01ec();
        }
    }
    fn_1e74_000f(page);
    if (opened == 1) ovr_2d18_0025();
    fn_0845_08aa();
}
