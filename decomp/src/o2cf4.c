/* o2cf4: skill level-up for a character; party-wiped check */
#include "lol.h"

extern long far f_2803_0000[];
extern int g_4d66;
char far *fn_0845_06f8(int id);
void fn_0845_01c4(int kind, char far *fmt, char far *name);
int fn_0845_0636(int a, int b);
int fn_1aff_0420(int a, int b);
void fn_067a_0401(long snd);
void fn_0a21_022b(int ch);
void fn_0a21_05ce(void);
void fn_0845_08d9(int n);
void fn_0845_090f(int n);
void fn_0845_03d4(int n);
void fn_070c_0a8f(int ch, int a, int b);
void ovr_2d22_0034(long a);
void ovr_2d5f_0075(int a, int b, int c, int d);
void ovr_2d56_0034(void);

int ovr_2cf4_0025(int ch, int sk)
{
    register int c = ch;
    int n;

    if (f_2803_0000[f_2803_362d[c].skill[sk]] > f_2803_362d[c].exp[sk]) return 0;
    f_2803_362d[c].skill[sk] = f_2803_362d[c].skill[sk] + 1;
    f_2803_362d[c].flags |= 0x200U << sk;
    switch (sk) {
    case 0:
        fn_0845_01c4(0x8003, fn_0845_06f8(0x4023), f_2803_362d[c].name);
        n = fn_0845_0636(4, 6);
    hp:
        f_2803_362d[c].hp += n;
        f_2803_362d[c].maxHp += n;
        break;
    case 2:
        fn_0845_01c4(0x8003, fn_0845_06f8(0x4024), f_2803_362d[c].name);
        n = fn_0845_0636(1, 8) + 0x11;
        n = fn_1aff_0420(n, ((int far *)f_2803_362d[c].st.atk)[6]);
        f_2803_362d[c].mp += n;
        f_2803_362d[c].maxMp += n;
        n = fn_0845_0636(1, 6);
        goto hp;
    case 1:
        fn_0845_01c4(0x8003, fn_0845_06f8(0x4025), f_2803_362d[c].name);
        n = fn_0845_0636(2, 6);
        goto hp;
    }
    fn_067a_0401(0x76);
    fn_0a21_022b(c);
    return 1;
}

int ovr_2cf4_0020(int flags)
{
    struct Char far *c;
    int i;

    c = f_2803_362d;
    for (i = 0; i < 4; i++, c++)
        if ((c->flags & 1) && c->hp > 0) return 0;
    if (g_4d66) ovr_2d22_0034(0);
    fn_0a21_05ce();
    if (flags & 0x40) {
        fn_0845_08d9(0x28);
        c = f_2803_362d;
        for (i = 0; i < 4; i++, c++)
            if (c->flags & 1) fn_070c_0a8f(i, 1, 1);
        fn_0a21_05ce();
        fn_0845_090f(0x28);
        return 0;
    }
    fn_0845_03d4(10);
    ovr_2d5f_0075(0, 1, 1, 0);
    ovr_2d56_0034();
    return 1;
}
