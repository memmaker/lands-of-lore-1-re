/* o2d7a: rest the party (heal hit points / magic over time) */
#include "lol.h"

extern int g_4d66;
extern int g_20d3;
extern int g_7fd6;
extern char g_1f3a;
extern unsigned long g_384c;
extern char far f_27b1_0010[];
void fn_09aa_0007(int a, int b);
void ovr_2d22_0034(void far *p);
void fn_0a21_06b8(int a, int b, int c);
void fn_0a21_0674(int c, int a, int b, int d);
void fn_0a21_05ce(void);
void fn_0a21_022b(int c);
char far *fn_0845_06f8(int id);
void fn_0845_01c4(int kind, char far *fmt, ...);
void fn_0845_08aa(void);
void fn_0845_15d9(int a);
void fn_0845_090f(int a);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_1e59_001d(int a, int b, int c, int d, int e);
void fn_0bbc_000a(int a);
void fn_0bbc_004a(int a);
void fn_0bbc_040b(int a);
void ovr_2d1b_0061(void);
int fn_2169_060c(void);
int fn_2169_0790(void);
void fn_2169_0945(int k);
void fn_163d_0004(void);
void fn_070c_07f5(int c, int a, int b, int d, int e);
void fn_070c_0a8f(int c, int a, int b);
void fn_067a_0401(int voice, int a);

int ovr_2d7a_0020(void)
{
    struct Char far *p;
    unsigned long tC;
    unsigned long tA;
    unsigned long tB;
    int a;
    int b;
    int c;
    int i;
    int m1;
    int m2;
    int m3;
    register int mpm;
    register int hpm;
    int mask;
    int k;

    m1 = -1;
    m2 = -1;
    m3 = -1;
    mpm = 0;
    hpm = 0;
    mask = 0;
    fn_09aa_0007(0x4d, 1);
    if (g_4d66 == 1) ovr_2d22_0034(f_27b1_0010);
    for (p = f_2803_362d, i = 0; i < 4; i++, p++) {
        if (!(p->flags & 1) || (p->flags & 8)) continue;
        if (p->maxHp > m1) m1 = p->maxHp;
        if (p->maxMp > m2) m2 = p->maxMp;
        if (p->flags & 0x80) {
            mask |= 1 << i;
            if (p->hp > m3) m3 = p->hp;
        } else if (p->hp < p->maxHp) hpm |= 1 << i;
        if (p->mp < p->maxMp) mpm |= 1 << i;
        p->flags |= 0x1000;
    }
    if (hpm == 0 && mpm == 0) {
        for (p = f_2803_362d, i = 0; i < 4; i++, p++)
            p->flags &= ~0x1000;
        if (mask != 0) {
            fn_0a21_06b8(0, 0, 0);
            for (p = f_2803_362d, i = 0; i < 4; i++, p++)
                if (mask & 1 << i) fn_0a21_0674(i, 3, 8, 0);
            fn_0845_01c4(0x8000, fn_0845_06f8(0x405a));
            fn_0a21_05ce();
        } else {
            fn_0a21_06b8(2, 4, 1);
            fn_0845_01c4(0x8000, fn_0845_06f8(0x4058));
        }
        fn_09aa_0007(0x4d, 0);
        return 1;
    }
    fn_1ebc_00e7();
    fn_1e59_001d(0x70, 0, 0x120, 0x78, 1);
    fn_1ebc_00fe();
    fn_0a21_05ce();
    fn_0845_01c4(0x8000, fn_0845_06f8(0x4057));
    fn_09aa_0007(0x4d, 0);
    a = 600 / m1 + 1;
    a = a < 30 ? a : 30;
    b = 600 / m2 + 1;
    b = b < 30 ? b : 30;
    c = (600 / m3 + 1) >> 1;
    c = c < 15 ? c : 15;
    tA = g_384c + a;
    tB = g_384c + b;
    tC = g_384c + c;
    g_20d3 = 0;
    g_7fd6 |= 1;
    for (i = 0; i < (g_1f3a ? 32 : 16); i++) {
        fn_0bbc_000a(0);
        fn_0bbc_000a(1);
        fn_0bbc_004a(0);
        fn_0bbc_040b(0);
        if (g_20d3) break;
    }
    ovr_2d1b_0061();
    while ((mpm || hpm) && !g_20d3) {
        for (i = 0; i < (g_1f3a ? 8 : 4); i++) {
            fn_0bbc_000a(0);
            fn_0bbc_000a(1);
            fn_0bbc_004a(0);
            fn_0bbc_040b(0);
            if (g_20d3) break;
        }
        if (fn_2169_060c()) {
            k = fn_2169_0790();
            if (k != 0 && !(k & 0x800)) {
                fn_2169_0945(k);
                break;
            }
            fn_163d_0004();
        }
        if (g_20d3) break;
        if (g_384c > tC) {
            for (p = f_2803_362d, i = 0; i < 4; i++, p++) {
                if (mask & 1 << i) {
                    fn_070c_07f5(i, 1, 0x8000, 1, 0x80);
                    if (p->flags & 8) mask &= ~(1 << i);
                }
            }
            tC = g_384c + c;
        }
        if (g_384c > tA) {
            for (p = f_2803_362d, i = 0; i < 4; i++, p++) {
                if (hpm & 1 << i) {
                    fn_070c_0a8f(i, 1, 0);
                    fn_0a21_022b(i);
                    if (p->hp == p->maxHp) hpm &= ~(1 << i);
                }
            }
            tA = g_384c + a;
        }
        if (g_384c > tB) {
            for (p = f_2803_362d, i = 0; i < 4; i++, p++) {
                if (mpm & 1 << i) {
                    p->mp++;
                    fn_0a21_022b(i);
                    if (p->mp == p->maxMp) mpm &= ~(1 << i);
                }
            }
            tB = g_384c + b;
        }
    }
    for (p = f_2803_362d, i = 0; i < 4; i++, p++) {
        if (p->flags & 0x1000) {
            p->flags &= ~0x1000;
            if (g_20d3) {
                if (p->lastDmg) {
                    mpm = 5;
                    fn_067a_0401(p->voice, 0);
                } else mpm = 4;
                fn_0a21_0674(i, mpm, 6, 1);
            } else fn_0a21_0674(i, 0, 0, 1);
        } else if (!p->lastDmg) fn_0a21_0674(i, 4, 0, 1);
    }
    g_7fd6 &= ~1;
    g_20d3 = 1;
    fn_0845_08aa();
    fn_0845_15d9(0);
    fn_0845_01c4(0x8000, fn_0845_06f8(0x4059));
    fn_0845_090f(0x28);
    return 1;
}
