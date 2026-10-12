/* s007: object lists (items and monsters on blocks, draw order) */
#include "lol.h"

struct Pos { int x, y; };
extern struct Pos g_7fd2;

void ovr_2d46_002a(int fatal, char far *fmt, ...);
void fn_1aff_0341(struct Pos party, int far *x, int far *y, int dir);

struct Item far *fn_080e_000b(int id)
{
    if (id & 0x8000) return (struct Item far *)&f_2803_15fa[id & 0x7fff];
    return &f_2803_1cfd[id];
}

void fn_080e_0034(int far *list, int id)
{
    struct Item far *p;
    p = fn_080e_000b(id);
    p->next = *list;
    *list = id;
}

void fn_080e_005f(int far *list, int id)
{
    struct Item far *q;
    struct Item far *p;

    while (*list & 0x8000) {
        q = fn_080e_000b(*list);
        list = &q->next;
    }
    p = fn_080e_000b(id);
    p->next = *list;
    p->level = 0xff;
    *list = id;
}

void fn_080e_00b4(int far *list, int id)
{
    struct Item far *q;
    struct Item far *p;
    int old;

    while (*list & 0x8000) {
        q = fn_080e_000b(*list);
        list = &q->next;
    }
    p = fn_080e_000b(id);
    p->level = 0xff;
    old = *list;
    if (*list == id) return;
    *list = id;
    for (list = &p->next; *list; list = &q->next)
        q = fn_080e_000b(*list);
    *list = old;
}

void fn_080e_013c(int far *list, int id)
{
    struct Item far *q;

    while (*list) {
        if (*list == id) {
            q = fn_080e_000b(id);
            *list = q->next;
            q->next = 0;
            return;
        }
        q = fn_080e_000b(*list);
        list = &q->next;
    }
    ovr_2d46_002a(0, "L_R_O: Object %d didn't exist.", id);
}

int fn_080e_01a6(int far *list, int n)
{
    struct Item far *q;

    while (*list) {
        if (!(*list & 0x8000) && !--n) return *list;
        q = fn_080e_000b(*list);
        list = &q->drawNext;
    }
    return -1;
}

int fn_080e_01f3(struct Item far *p, int dir)
{
    int x, y;

    x = p->x;
    y = p->y;
    fn_1aff_0341(g_7fd2, &x, &y, dir);
    if (y < 0) y = 0;
    return (p->sub << 12) | (0xfff - y);
}

/* NONMATCHING */
void fn_080e_0245(int dir, int id, struct Block far *b, int asc)
{
    struct Item far *p;
    struct Item far *q;
    int far *list;
    int key;

    if (b->drawDir != dir) {
        b->drawDir = 5;
        return;
    }
    p = fn_080e_000b(id);
    key = fn_080e_01f3(p, dir);
    for (list = &b->draw; *list; list = &q->drawNext) {
        q = fn_080e_000b(*list);
        if (asc) {
            if (fn_080e_01f3(q, dir) >= key) break;
        } else {
            if (fn_080e_01f3(q, dir) > key) break;
        }
    }
    p->drawNext = *list;
    *list = id;
}

void fn_080e_02f5(struct Block far *b, int id)
{
    struct Item far *q;
    int far *list;

    if (b->drawDir == 5) return;
    for (list = &b->draw; *list; list = &q->drawNext) {
        if (*list == id) {
            q = fn_080e_000b(*list);
            *list = q->drawNext;
            q->drawNext = 0;
            return;
        }
        q = fn_080e_000b(*list);
    }
    ovr_2d46_002a(1, "RemoveIdx: Object didn't exist.");
}
