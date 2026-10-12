/* o2d00: character status effects (0x100 on a character; 0x40 / 0x80 / 0x1000 rolled per character) */
#include "lol.h"

char far *fn_0845_06f8(int id);
void fn_0845_01c4(int kind, char far *fmt, char far *name);
int fn_0845_0636(int lo, int hi);
void fn_0a21_022b(int ch);
int fn_0a21_0997(int ch, int item);
void fn_0a21_05ce(void);
void fn_0bbc_0744(int ch, int a, int b, int c);
int fn_154c_0057(int id, int v, int n);

void ovr_2d00_0020(int c)
{
    if (!(f_2803_362d[c].flags & 1) || (f_2803_362d[c].flags & 0x108)) return;
    f_2803_362d[c].flags |= 0x100;
    fn_0bbc_0744(c, 5, 0x14, 1);
    fn_0a21_022b(c);
    fn_0845_01c4(0, fn_0845_06f8(0x4026), f_2803_362d[c].name);
}

int ovr_2d00_0025(int c, int type, int mask, int chance, int flags)
{
    int r;

    r = 0;
    if (!(f_2803_362d[c].flags & 1) || (f_2803_362d[c].flags & mask)) return 0;
    if (fn_0845_0636(1, 100) > chance) return 0;
    switch (type) {
    case 0x1000:
        f_2803_362d[c].flags |= 0x1000;
        r = 1;
        fn_0bbc_0744(c, 7, 0x78, 1);
        break;
    case 0x80:
        if (fn_0a21_0997(c, 0xe1)) break;
        f_2803_362d[c].flags |= 0x80;
        fn_0bbc_0744(c, 4, 10, 1);
        if (fn_154c_0057(0x4021, f_2803_362d[c].wE, 1))
            fn_0845_01c4(6, fn_0845_06f8(0x4021), f_2803_362d[c].name);
        r = 1;
        break;
    case 0x40:
        fn_0bbc_0744(c, 3, 0xe10, 1);
        f_2803_362d[c].flags |= 0x40;
        r = 1;
        break;
    }
    if (flags & r) {
        fn_0a21_022b(c);
        return 0;
    }
    return r;
}

void ovr_2d00_002a(int type, int mask, int chance)
{
    int i, r;

    r = i = 0;
    for (; i < 4; i++) r |= ovr_2d00_0025(i, type, mask, chance, 0);
    if (r) fn_0a21_05ce();
}
