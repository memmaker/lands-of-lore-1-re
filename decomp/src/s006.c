/* s006: items (allocation, placement on blocks, item scripts) */
#pragma option -O-b
#include <mem.h>
#include "lol.h"

extern char g_7fe5;
extern int g_7fdf;
extern char far f_2803_35fd[];

int fn_1aff_039a(int x, int y);
void fn_080e_005f(int far *list, int it);
void fn_080e_0245(int dir, int it, int far *list, int a);
void fn_0845_1343(int block, int what, int a, int it, int b, int c);
void fn_0845_046c(int block);
void fn_080e_013c(int far *list, int it);
void fn_080e_02f5(int far *list, int it);
struct Item far *fn_080e_000b(int it);
int fn_2315_0018(int a);

void fn_07bc_044c(int it);

int fn_07bc_000e(int it)
{
    if ((f_2803_1cfd[it].flags & 0x4000) && !(g_7fb2[f_2803_1cfd[it].type].flags & 4)) return 1;
    return 0;
}

int fn_07bc_0050(int it)
{
    while (it) {
        if (fn_07bc_000e(it)) return 1;
        it = f_2803_1cfd[it].next;
    }
    return 0;
}

int fn_07bc_0080(int it)
{
    int nx;

    if (fn_07bc_000e(it)) {
        if (f_2803_1cfd[it].next) f_2803_1cfd[f_2803_1cfd[it].next].level = f_2803_1cfd[it].level;
        fn_07bc_044c(it);
        return it;
    }
    for (; nx = f_2803_1cfd[it].next, nx; it = nx) {
        if (fn_07bc_000e(nx)) {
            f_2803_1cfd[it].next = f_2803_1cfd[nx].next;
            fn_07bc_044c(nx);
            return nx;
        }
    }
    return 0;
}

int fn_07bc_012d(int type, int flags, int flags2)
{
    int d;
    int slot;
    int best;
    int i;

    slot = 0;
    best = 0;
    for (i = 1; i < 400; i++) {
        if (f_2803_1cfd[i].flags & 0x8000) {
            best = 0;
            break;
        }
        if (f_2803_1cfd[i].level < 1 || f_2803_1cfd[i].level > 0x1d || f_2803_1cfd[i].level == g_7fe5) continue;
        d = ABS(g_7fe5 - f_2803_1cfd[i].level);
        if (d > best && fn_07bc_0050(i)) {
            best = d;
            slot = i;
        }
    }
    if (best) i = fn_07bc_0080(slot);
    setmem(&f_2803_1cfd[i], 16, 0);
    f_2803_1cfd[i].type = type;
    f_2803_1cfd[i].flags = flags & 0x1fff;
    f_2803_1cfd[i].flags |= flags2;
    f_2803_1cfd[i].level = 0xff;
    return i;
}

void fn_07bc_0272(int it, int x, int y, int sub, int floor)
{
    int b;

    if (!sub) {
        x = (x & 0xffc0) | 0x40;
        y = (y & 0xffc0) | 0x40;
    }
    b = fn_1aff_039a(x, y);
    f_2803_1cfd[it].x = x;
    f_2803_1cfd[it].y = y;
    f_2803_1cfd[it].block = b;
    f_2803_1cfd[it].sub = sub;
    if (floor)
        f_2803_1cfd[it].flags |= 0x4000;
    else
        f_2803_1cfd[it].flags &= ~0x4000;
    fn_080e_005f(&g_8203[b].mon, it);
    fn_080e_0245(g_7fdf, it, &g_8203[b].items, 0);
    if (floor) fn_0845_1343(b, 0x80, -1, it, 0, 0);
    fn_0845_046c(b);
}

void fn_07bc_0367(int it, int b)
{
    fn_080e_013c(&g_8203[b].mon, it);
    fn_080e_02f5(&g_8203[b].items, it);
    fn_0845_1343(b, 0x100, -1, it, 0, 0);
    f_2803_1cfd[it].block = 0;
    f_2803_1cfd[it].level = 0;
}

int fn_07bc_03d0(int far *list, int x, int y, int sub)
{
    struct Item far *p;
    int r;

    while (*list) {
        p = fn_080e_000b(*list);
        if (!(*list & 0x8000) && p->x == x && p->y == y && p->sub == sub) {
            r = *list;
            *list = p->next;
            p->next = 0;
            return r;
        }
        list = &p->next;
    }
    return -1;
}

void fn_07bc_044c(int it)
{
    setmem(&f_2803_1cfd[it], 16, 0);
    f_2803_1cfd[it].flags |= 0x8000;
}

void fn_07bc_047f(int a, int it, int c, int d, int e)
{
    int r;
    struct Emc st;
    int fn;

    if (it)
        fn = g_7fb2[f_2803_1cfd[it].type].script;
    else
        fn = 3;
    if (fn == 0xff) return;
    fn_0f28_032c((void far *)&st, (void far *)f_2803_35fd);
    fn_0f28_035f((void far *)&st, fn);
    st.regs[0] = c;
    st.regs[1] = a;
    st.regs[2] = it;
    st.regs[3] = d;
    st.regs[4] = e;
    if (!(c & fn_2315_0018(st.ip[-1]))) return;
    do r = fn_0f28_04a0((void far *)&st); while (r);
}
