/* s012: flying objects (thrown items, missiles, spell projectiles) */
#include "lol.h"

struct Fly {                /* 0x11 bytes, g_4dcc[8] */
    char active;
    char type;
    int owner;               /* +02 */
    int item;                /* +04 */
    int x, y;                /* +06 */
    char power;              /* +0a */
    char dir;                /* +0b */
    char range;              /* +0c */
    char pad;
    char e;                  /* +0e */
    char flags;              /* +0f */
    char f10;                /* +10 */
};

extern struct Fly g_4dcc[];
struct XY { int x, y; };
extern struct XY g_7fd2;
extern int g_20d3;

void fn_07bc_0272(int it, int x, int y, int a, int b);
void fn_07bc_044c(int it);
void fn_07bc_047f(int owner, int it, int a, int target, int b);
int fn_1aff_039a(int x, int y);
void fn_0845_046c(int b);
void fn_080e_013c(int far *list, int it);
void fn_080e_02f5(int far *list, int it);
int fn_09aa_0183(int b, int dir);
void fn_0845_1343(int b, long a, int it, long c);
struct Item far *fn_080e_000b(int id);
int fn_070c_0322(int x, int y);
int fn_070c_03b1(int x, int y);
void fn_070c_00cf(int who, int cls, long exp);
int fn_0845_04af(struct XY a, int x2, int y2);
void fn_0d6c_0004(int x, int y, int *nx, int *ny, int dir);
int fn_0d6c_0338(int x, int y, int mask, int flags, int f);

void fn_0b6b_0006(struct Fly far *f)
{
    int b;

    switch (f->type) {
    case 0:
        fn_07bc_0272(f->item, f->x, f->y, f->power, f->power ? 0 : 1);
        break;
    case 1:
        if (f->power)
            fn_07bc_0272(f->item, f->x, f->y, f->power, 0);
        else {
            fn_07bc_044c(f->item);
            b = fn_1aff_039a(f->x, f->y);
            fn_0845_046c(b);
        }
        break;
    }
}

void fn_0b6b_008a(struct Fly far *f, int x, int y)
{
    register int b;

    b = fn_1aff_039a(f->x, f->y);
    fn_080e_013c(&g_8203[b].mon, f->item);
    fn_080e_02f5((int far *)&g_8203[b], f->item);
    f->x = x;
    f->y = y;
    fn_0b6b_0006(f);
    fn_0845_046c(b);
}

void fn_0b6b_00f9(struct Fly far *f, int x, int y, int kind)
{
    int b;
    int cur;
    struct Item far *p;
    register int o;

    switch (kind) {
    case 1:
        b = fn_09aa_0183(f_2803_1cfd[f->item].block, f->dir >> 1);
        fn_0845_1343(b, -0x8000L, f->item, 0L);
        return;
    case 2:
        if (g_7fb2[f_2803_1cfd[f->item].type].flags & 0x4000) {
            for (o = g_8203[f_2803_1cfd[f->item].block].mon; o & 0x8000; ) {
                cur = o;
                p = fn_080e_000b(o);
                o = p->next;
                fn_07bc_047f(f->owner, f->item, 0x8000, cur, 0);
            }
            return;
        }
        x = fn_070c_0322(x, y);
        break;
    case 4:
        g_20d3 = 1;
        if (g_7fb2[f_2803_1cfd[f->item].type].flags & 0x4000) {
            for (o = 0; o < 4; o++)
                if (f_2803_362d[o].flags & 1) fn_07bc_047f(f->owner, f->item, 0x8000, o, 0);
            return;
        }
        x = fn_070c_03b1(x, y);
        break;
    default:
        return;
    }
    fn_07bc_047f(f->owner, f->item, 0x8000, x, 0);
}

void fn_0b6b_0272(struct Fly far *f, int x, int y, int kind)
{
    int b;

    b = fn_1aff_039a(f->x, f->y);
    fn_080e_013c(&g_8203[b].mon, f->item);
    fn_080e_02f5((int far *)&g_8203[b], f->item);
    if (kind == 1) {
        x = f->x;
        y = f->y;
    }
    switch (f->type) {
    case 0:
    case 1:
        fn_0b6b_00f9(f, x, y, kind);
        f->x = (x & 0xffc0) | 0x40;
        f->y = (y & 0xffc0) | 0x40;
        f->power = 0;
        fn_0b6b_0006(f);
    }
    f->active = 0;
}

int fn_0b6b_032f(char type, int item, int x, int y, char power, char dir, int unused, int owner, char e)
{
    struct Fly far *p;
    long best;
    long d;
    int idx;
    register int i;

    best = fn_0845_04af(g_7fd2, x, y);
    for (i = 0, idx = -1, p = g_4dcc; i < 8; i++, p++) {
        if (!p->active) {
            best = -1;
            break;
        }
        d = fn_0845_04af(g_7fd2, p->x, p->y);
        if (d > best) {
            best = d;
            idx = i;
        }
    }
    if (best != -1 && idx != -1) {
        i = idx;
        p = &g_4dcc[i];
        fn_0b6b_0272(p, x, y, 8);
    }
    if (i == 8) return 0;
    p->active = 1;
    p->type = type;
    p->item = item;
    p->x = x;
    p->y = y;
    p->power = power;
    p->dir = dir;
    p->range = -1;
    p->owner = owner;
    p->flags = 7;
    p->f10 = 2;
    p->e = e;
    if (owner != -1) {
        if (owner & 0x8000)
            p->flags &= ~2;
        else {
            p->flags &= ~4;
            fn_070c_00cf(owner, 1, 2L);
        }
    }
    fn_0b6b_0006(p);
    return 1;
}

void fn_0b6b_0472(struct Fly far *f)
{
    int r;
    int nx;
    int ny;

    fn_0d6c_0004(f->x, f->y, &nx, &ny, f->dir);
    if ((r = fn_0d6c_0338(nx, ny, g_7fb2[f->item].flags & 0x4000 ? 0x100 : 0x3f, f->flags, f->f10)) != 0)
        fn_0b6b_0272(f, nx, ny, r);
    else if (!--f->range)
        fn_0b6b_0272(f, nx, ny, 8);
    else
        fn_0b6b_008a(f, nx, ny);
}
