/* s025: GUI button list (input dispatch and drawing) */
#include "lol.h"

struct Btn {                /* GUI button */
    struct Btn far *next;
    int id;
    int key1;
    int key2;
    unsigned char type[3];  /* draw type: normal, pressed, highlighted */
    char pad_d;
    unsigned flags;
    void far *data[3];
    int win;
    int x, y, w, h;         /* x/y negative: from the window's right/bottom edge */
    unsigned char col[3][2];
    int w2c;
    unsigned state;
    int (far *func)(struct Btn far *b);
};

struct TextWin {
    int x, y, w, h;
    int c1, c2;
    int col, row;
};

extern struct TextWin g_1f3b[];
extern int g_372d;
extern unsigned g_abd2;
extern int g_2f0c, g_2f0e, g_2f10, g_2f12;
extern unsigned char g_2f43;
extern int g_3649, g_370b;

int fn_2169_0593(void);
int fn_2169_073a(void);
int fn_2169_060c(void);
int fn_2169_0790(void);
int fn_2169_07ae(int key);
void fn_1ebc_0111(int x1, int y1, int x2, int y2);
void fn_1ebc_01ec(void);
void fn_1fd6_000a(int page, void far *shp, int x, int y, int win, int flags);
void fn_1f6c_0006(void far *s, int x, int y, int c1, int c2);
void fn_1e54_0001(int x1, int y1, int x2, int y2, int c);
void fn_1e59_000c(int x1, int y1, int x2, int y2, int c);
void fn_1db2_0003(struct Btn far *b, int a);

int fn_163d_0068(struct Btn far *b, int key);
void fn_163d_05cc(struct Btn far *b);

struct Btn far *g_2890 = 0;
struct Btn far *g_2894 = 0;
int g_2898[16] = { 0, 0x100, 0x200, 0x100, 0x400, 0x100, 0x400, 0x100,
                   0x800, 0x100, 0x200, 0x100, 0x400, 0x100, 0x400, 0x100 };

void fn_163d_0004(void)
{
    g_372d = 1;
}

int fn_163d_000f(struct Btn far *b)
{
    int k;

    k = 0;
    if (fn_2169_0593()) {
        k = fn_2169_073a();
        k |= 0x8000;
    }
    return fn_163d_0068(b, k);
}

int fn_163d_0039(struct Btn far *b)
{
    int k;

    k = 0;
    if (fn_2169_060c()) {
        k = fn_2169_0790();
        if (k == 0x2d) return 0;
    }
    return fn_163d_0068(b, k);
}

int fn_163d_0068(struct Btn far *b, register int key)
{
    int clr;
    int mx;
    int my;
    unsigned t;
    int k;
    int res;
    int fire;
    register unsigned ev;
    int inside;
    int hit;

    clr = 0;
    if (!b) return key & 0x7fff;
    if (b != g_2894 || g_372d) {
        g_2890 = 0;
        g_abd2 = 0;
        if (fn_2169_07ae(0x41)) g_abd2 |= 0x200;
        if (fn_2169_07ae(0x42)) g_abd2 |= 0x2000;
        g_2894 = b;
        g_372d = 0;
        for (; b; b = b->next) fn_163d_05cc(b);
    }
    mx = g_2f0c;
    my = g_2f0e;
    ev = 0;
    if (!g_2f43) {
        int m;

        m = 0;
        k = key & 0xff;
        if (key < 0) {
            if (k == 0xc7) m = 0x1000;
            if (k == 0xc6) m = 0x100;
        } else {
            if (k == 0x42) m = 0x1000;
            if (k == 0x41) m = 0x100;
        }
        if (key & 0x800) m <<= 2;
        ev |= m;
        if (m) {
            mx = g_2f10;
            my = g_2f12;
        }
        g_abd2 &= ~((m & 0x4400) >> 1);
        g_abd2 |= (m & 0x1100) << 1;
        ev |= g_abd2;
        ev |= (g_abd2 << 2) ^ 0x8800;
    }
    b = g_2894;
    if (g_2890) b = g_2890;
    if (g_2890 && (g_2890->flags & 8)) g_2890 = 0;
    res = 0;
    for (; b; b = b->next) {
        if (b->flags & 8) continue;
        b->state &= ~0x18;
        b->state |= (b->state & 3) << 3;
        {
            int x;
            int y;

            x = b->x;
            if (x < 0) x += g_1f3b[b->win].w << 3;
            x += g_1f3b[b->win].x << 3;
            y = b->y;
            if (y < 0) y += g_1f3b[b->win].h;
            y += g_1f3b[b->win].y;
            if (mx < x || my < y || x + b->w < mx || y + b->h < my) inside = 0;
            else inside = 1;
        }
        b->state &= 0xff7f;
        k = key & 0x7fff;
        if (k) {
            if (b->key1 == k) goto lo;
            if (b->key2 == k) {
                ev = b->flags & 0xf000;
                if (!ev) {
                lo:
                    ev = b->flags & 0xf00;
                }
                inside = 1;
                b->state |= 0x80;
                key = 0;
                g_2890 = b;
            }
        }
        fire = 0;
        if (!inside) b->state &= ~6;
        if ((ev & 0x3300) && (b->flags & 4) && inside && (b == g_2890 || !g_2890)) {
            b->state |= 6;
            if (!g_2890) g_2890 = b;
        } else if ((ev & 0x8800) && !(b->flags & 4) && inside) {
            b->state |= 6;
        } else b->state &= ~6;
        if (g_2890 && (g_2890->flags & 0x40)) hit = g_2890 == b ? 1 : 0;
        else hit = inside;
        if (hit) {
            if ((ev & 0x1100) && inside && !g_2890) {
                key = 0;
                g_2890 = b;
            }
            if ((b->flags & ev) && (inside || !(b->flags & 1))) {
                t = ev & b->flags;
                t = (t & 0xf00) | ((t & 0xf000) >> 4);
                t >>= 8;
                switch (g_2898[t]) {
                default:
                    b->state ^= 1;
                    res = b->id | 0x8000;
                    fire = 1;
                    if (b->flags & 4) {
                        b->state |= 4;
                        b->state |= 2;
                    }
                    g_2890 = b;
                    break;
                case 0x400:
                    if (((b->flags & 1) && g_2890 == b) || !(b->flags & 1)) {
                        b->state ^= 1;
                        res = b->id | 0x8000;
                        fire = 1;
                    }
                    if (!(b->flags & 4)) {
                        b->state &= ~4;
                        b->state &= ~2;
                    }
                    break;
                case 0x800:
                    if (!(b->flags & 4)) {
                        b->state |= 4;
                        b->state |= 2;
                    }
                    if (!(b->flags & 1)) fire = 1;
                    break;
                case 0x200:
                    if (b->flags & 4) {
                        b->state |= 4;
                        b->state |= 2;
                    }
                    if (!(b->flags & 1)) fire = 1;
                    break;
                }
            }
        }
        if ((ev & 0x2200) && inside) {
            b->state |= 6;
            if (!(b->flags & 4) && !(b->state & 1)) {
                clr = 1;
                b->state |= 1;
            }
        }
        if ((b->state & 0x80) || (ev & 0x8800) == 0x8800) {
            g_2890 = 0;
            if (!inside || (b->flags & 4)) b->state &= ~6;
        }
        if (!inside && b == g_2890 && !(b->flags & 0x40)) g_2890 = 0;
        if ((b->state & 0x18) != (b->state & 3) << 3) fn_163d_05cc(b);
        if (clr) b->state &= ~1;
        if (fire) {
            b->state &= 0xff;
            b->state |= ev;
            if ((b->func && b->func(b)) || (b->flags & 0x20)) break;
        }
        if (g_2890 == b && (b->flags & 0x40)) break;
    }
    if (!res) res = key & 0x7fff;
    return res;
}

void fn_163d_05cc(struct Btn far *b)
{
    void far *data;
    int x0;
    int y0;
    unsigned type;
    unsigned c1;
    unsigned c2;
    int x;
    int y;
    int x2;
    int y2;

    if (!b) return;
    if (b->flags & 8) {
        if (b->flags & 0x10) fn_1db2_0003(b, g_370b);
        return;
    }
    switch (b->state & 5) {
    case 4:
    case 5:
        type = b->type[2];
        data = b->data[2];
        c1 = b->col[2][0];
        c2 = b->col[2][1];
        break;
    case 1:
        type = b->type[1];
        data = b->data[1];
        c1 = b->col[1][0];
        c2 = b->col[1][1];
        break;
    default:
        type = b->type[0];
        data = b->data[0];
        c1 = b->col[0][0];
        c2 = b->col[0][1];
        break;
    }
    x = b->x;
    if (x < 0) x += g_1f3b[b->win].w << 3;
    x0 = x;
    x += g_1f3b[b->win].x << 3;
    x2 = x + b->w - 1;
    y = b->y;
    if (y < 0) y += g_1f3b[b->win].h;
    y0 = y;
    y += g_1f3b[b->win].y;
    y2 = y + b->h - 1;
    switch (type) {
    case 1:
        if (!g_3649) fn_1ebc_0111(x, y, x2, y2);
        fn_1fd6_000a(g_3649, data, x0, y0, b->win, 0x10);
        if (!g_3649) fn_1ebc_01ec();
        break;
    case 2:
        if (!g_3649) fn_1ebc_0111(x, y, x2, y2);
        fn_1f6c_0006(data, x, y, c1, c2);
        if (!g_3649) fn_1ebc_01ec();
        break;
    case 3:
        break;
    case 4:
        if (data) ((void (far *)(struct Btn far *))data)(b);
        break;
    case 5:
        if (!g_3649) fn_1ebc_0111(x, y, x2, y2);
        fn_1e54_0001(x, y, x + b->w - 1, y + b->h - 1, c1);
        if (!g_3649) fn_1ebc_01ec();
        break;
    case 6:
        if (!g_3649) fn_1ebc_0111(x, y, x2, y2);
        fn_1e59_000c(x, y, x + b->w - 1, y + b->h - 1, c1);
        if (!g_3649) fn_1ebc_01ec();
        break;
    }
}
