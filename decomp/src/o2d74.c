/* o2d74: party members joining and leaving (EMC opcode ovr_2d74_002a: arg > 0 adds character id, < 0 removes) */
#include "lol.h"

extern struct Char far f_2656_0000[];   /* 9 character templates */
extern int g_7fd6;
extern char g_7fe3;
void fn_2279_025b(void far *d, void far *s, long n);
void ovr_2d46_0034(int c, int id);
int fn_0845_0636(int lo, int hi);
int fn_07bc_012d(int type, int a, int b);
void fn_07bc_047f(int c, int it, int a, int b, int d);
void fn_0a21_0a0c(void);
void fn_0a21_0674(int c, int a, int b, int d);
void ovr_2ceb_0020(void);
void ovr_2d2c_0043(void);

int ovr_2d74_0025(void)
{
    int i, n;

    for (n = i = 0; i < 4; i++)
        if (f_2803_362d[i].flags & 1) n++;
    return n;
}

int ovr_2d74_0020(int id)
{
    int i, c;

    if ((c = ovr_2d74_0025()) == 4) return 0;
    for (i = 0; i < 9; i++) {
        if (f_2656_0000[i].wE == id) {
            id = i;
            break;
        }
    }
    if (i == 9) return 0;
    fn_2279_025b(&f_2656_0000[id], &f_2803_362d[c], 0x82L);
    ovr_2d46_0034(c, f_2803_362d[c].wE);
    f_2803_362d[c].w4e = fn_0845_0636(1, 12) + 6;
    for (i = 0; i < 11; i++) {
        if (f_2803_362d[c].items[i] != 0) {
            f_2803_362d[c].items[i] = fn_07bc_012d(f_2803_362d[c].items[i], 0, 0);
            fn_07bc_047f(c, f_2803_362d[c].items[i], 0x80, 0, 0);
        }
    }
    fn_0a21_0a0c();
    if (c != 0) fn_0a21_0674(c, 2, 6, 0);
    return 1;
}

int ovr_2d74_002a(struct EmcState far *s)
{
    int id, i;

    id = ARG(s, 0);
    if (id < 0) {
        id = ABS(id);
        for (i = 0; i < 4; i++) {
            if ((f_2803_362d[i].flags & 1) && f_2803_362d[i].wE == id) {
                f_2803_362d[i].flags &= ~1;
                fn_0a21_0a0c();
                if (g_7fd6 == 0) {
                    ovr_2ceb_0020();
                    ovr_2d2c_0043();
                }
                if (g_7fe3 == i) g_7fe3 = 0;
                break;
            }
        }
    } else {
        ovr_2d74_0020(id);
        if (g_7fd6 == 0) {
            ovr_2ceb_0020();
            ovr_2d2c_0043();
        }
    }
    return 1;
}
