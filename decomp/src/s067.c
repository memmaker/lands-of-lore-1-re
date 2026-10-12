/* s067: WW library -- VGA palette set / fade */
#include <mem.h>

extern unsigned char g_2fac[];          /* current palette (768 bytes) */
extern int g_362e;                      /* video mode (3 = VGA) */
extern unsigned long g_384c;            /* tick counter */
void far fn_1e07_0255(void far *pal, int first, int n);
void far fn_1ee4_0002(void far *pal);
void far ovr_2ded_0020(void far *a, void far *b, long n);
int fn_1ef2_01f6(unsigned char far *pal, int speed);
void fn_1ef2_012e(unsigned char far *pal, int speed, int far *step, int far *count);

void fn_1ef2_0005(void far *pal)
{
    fn_1e07_0255(pal, 0, 15);
}

void fn_1ef2_001c(void far *pal)
{
    fn_1ee4_0002(pal);
}

void fn_1ef2_002f(unsigned char far *pal, int idx, void far *rgb)
{
    unsigned char far *p;
    if (pal == 0)
        return;
    p = pal;
    memcpy(p + idx * 3, rgb, 3);
    fn_1ee4_0002(pal);
}

void fn_1ef2_0075(unsigned char far *pal, int speed, void (far *idle)(void))
{
    int count;
    unsigned long until;
    int step;
    unsigned char buf[0x300];
    int frac, changed;
    if (pal == 0)
        return;
    if (g_362e != 3) {
        fn_1ef2_001c(pal);
    } else {
        memcpy(buf, g_2fac, 0x300);
        fn_1ef2_012e(pal, speed, &step, &count);
        frac = 0;
        until = g_384c;
        do {
            changed = 0;
            frac += step;
            until += frac >> 8;
            frac &= 0xff;
            changed = fn_1ef2_01f6(pal, count);
            if (changed) {
                while (g_384c < until) {
                    if (idle)
                        idle();
                }
            }
            if (idle)
                idle();
        } while (changed);
    }
}

void fn_1ef2_012e(unsigned char far *pal, int speed, int far *step, int far *count)
{
    int a, b, st;
    long q;
    int i, max;
    max = 0;
    for (i = 0; i < 0x300; i++) {
        int d;
        a = pal[i];
        b = g_2fac[i];
        d = a - b;
        d = d < 0 ? -d : d;
        max = max > d ? max : d;
    }
    q = (long)speed << 8;
    if (max) {
        q /= max;
        q = q < 0x7fff ? q : 0x7fff;
    }
    *step = q;
    st = *step;
    for (*count = 1; *count <= max && *step < 0x100; (*count)++)
        *step += st;
}

int fn_1ef2_01f6(unsigned char far *pal, int speed)
{
    int changed, c;
    unsigned char buf[0x300];
    int i, t;
    changed = 0;
    if (pal == 0)
        return 0;
    if (g_362e != 3) {
        fn_1ef2_001c(pal);
    } else {
        memcpy(buf, g_2fac, 0x300);
        for (i = 0; i < 0x300; i++) {
            t = pal[i];
            c = buf[i];
            if (t == c)
                continue;
            changed = 1;
            c = c < t ? (c = c + speed, c < t ? c : t) : (c = c - speed, c > t ? c : t);
            buf[i] = c;
        }
        if (changed)
            fn_1ef2_001c(buf);
    }
    return changed;
}

void fn_1ef2_02c0(void far *a, void far *b)
{
    ovr_2ded_0020(a, b, 0x300);
}
