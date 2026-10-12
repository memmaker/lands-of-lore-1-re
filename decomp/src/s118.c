/* s118: WW library -- GUI button list management */

struct Btn {                /* GUI button (same layout as s025) */
    struct Btn far *next;
    int id;
    int key1;
    int key2;
    unsigned char type[3];
    char pad_d;
    unsigned flags;         /* +0e: 8 = disabled */
    void far *data[3];
    int win;
    int x, y, w, h;
    unsigned char col[3][2];
    int w2c;
    unsigned state;         /* +2e: 1 pressed, 2 highlighted, 4 ..., 8/0x10 previous 1/4 */
    int (far *func)(struct Btn far *b);   /* +30 */
};

extern int g_372d;          /* button list changed: redraw */
void fn_163d_05cc(struct Btn far *b);

/* append b to the list; returns the head */
struct Btn far *fn_20bf_0006(struct Btn far *list, struct Btn far *b)
{
    struct Btn far *head;

    if (b != 0)
        b->next = 0;
    else
        return list;
    if (list != 0) {
        head = list;
        while (list->next != 0)
            list = list->next;
        list->next = b;
    } else
        head = b;
    g_372d = 1;
    return head;
}

struct Btn far *fn_20bf_0073(struct Btn far *b)
{
    if (b != 0 && !(b->flags & 8)) {
        b->flags |= 8;
        fn_163d_05cc(b);
    }
    return b;
}

struct Btn far *fn_20bf_00a8(struct Btn far *b)
{
    if (b != 0 && (b->flags & 8)) {
        b->flags &= ~8;
        fn_163d_05cc(b);
    }
    return b;
}

struct Btn far *fn_20bf_00dd(struct Btn far *list, int id)
{
    while (list != 0) {
        if (list->id == id)
            break;
        list = list->next;
    }
    return list;
}

/* release */
struct Btn far *fn_20bf_010c(struct Btn far *b, int call)
{
    if (b != 0 && !(b->flags & 8)) {
        if (b->state & 1)
            b->state |= 8;
        else
            b->state &= ~8;
        b->state &= ~1;
        b->state &= ~2;
        if (b->state & 4)
            b->state |= 0x10;
        else
            b->state &= ~0x10;
        b->state &= ~4;
        fn_163d_05cc(b);
        if (call && b->func != 0)
            b->func(b);
    }
    return b;
}

/* press */
struct Btn far *fn_20bf_01b2(struct Btn far *b, int call)
{
    if (b != 0 && !(b->flags & 8)) {
        if (b->state & 1)
            b->state |= 8;
        else
            b->state &= ~8;
        b->state |= 1;
        fn_163d_05cc(b);
        if (call && b->func != 0)
            b->func(b);
    }
    return b;
}

/* insert b sorted by id; returns the head */
struct Btn far *fn_20bf_0225(struct Btn far *list, struct Btn far *b)
{
    struct Btn far *head;
    struct Btn far *prev;

    if (list == 0)
        return b;
    if (b == 0)
        return list;
    prev = head = list;
    if ((unsigned)b->id <= (unsigned)head->id) {
        b->next = list;
        return b;
    } else {
        while ((unsigned)b->id > (unsigned)list->id && list->next != 0) {
            prev = list;
            list = list->next;
        }
        if ((unsigned)b->id > (unsigned)list->id)
            list = fn_20bf_0006(head, b);
        else {
            prev->next = b;
            b->next = list;
        }
    }
    g_372d = 1;
    return head;
}

int fn_20bf_02f6(struct Btn far *b)
{
    if (b != 0)
        return !(b->flags & 8);
    return 0;
}

int fn_20bf_0317(struct Btn far *b)
{
    if (b != 0)
        return b->state & 1 ? 1 : 0;
    return 0;
}

int fn_20bf_033b(struct Btn far *b)
{
    if (b != 0)
        return b->state & 2 ? 1 : 0;
    return 0;
}

void fn_20bf_035f(struct Btn far *list)
{
    while (list != 0) {
        fn_163d_05cc(list);
        list = list->next;
    }
}
