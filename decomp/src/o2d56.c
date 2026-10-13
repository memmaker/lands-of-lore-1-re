/* o2d56: game menu (main/options/save/load/delete dialogs, volume sliders, save slot names) */
#include <stdio.h>
#include <string.h>
#include <dos.h>
#include <io.h>
#include "lol.h"

struct Btn {                    /* GUI button, 0x3c bytes (s118) */
    struct Btn far *next;
    int id, key1, key2;
    unsigned char type[3];
    char pad_d;
    unsigned flags;             /* +0e */
    void far *data[3];          /* +10 */
    int win;                    /* +1c */
    int x, y, w, h;             /* +1e */
    unsigned char col[3][2];
    int w2c;
    unsigned state;             /* +2e */
    int (far *func)(struct Btn far *b);   /* +30 */
    char p34[4];
    int text;                   /* +38 */
    int part;                   /* +3a */
};
struct MItem { int text, x, y, w, h, label, key; };   /* 0x0e bytes */
struct Menu {                   /* 0x69 bytes */
    int win, title, type;
    char n;
    struct MItem items[7];
};
struct Menus { struct Menu m[8]; char names[4][0x3d]; };   /* 2612:0000 */
struct Win { int x, y, w, h; char pad[8]; };
struct I3 { int v[3]; };

extern struct Menus far f_2612_0000;
#define M f_2612_0000
extern struct Btn far f_2803_0592[];
extern struct Btn far f_27b1_0010;
extern void far * far f_2803_00be[];
extern void far * far f_2803_01de[];
extern int far f_2803_002c[];
extern struct Win g_1f3b[];
extern struct Btn g_1142, g_117e;
extern struct I3 g_11be, g_11c4;
extern char g_11ce[], g_11d9[], g_11e4[], g_11f2[], g_11fc[], g_1202[], g_120c[], g_ad41[];
extern char g_81ff, g_81fe, g_81fd, g_8200, g_8201, g_20db, g_7fe5, g_ad49;
extern unsigned g_7fd6, g_7fda;
extern unsigned g_ad8b, g_ad8d, g_ad8f, g_ad91;
extern int g_4d66, g_11ba, g_11bc, g_11ca, g_11cc, g_4b64, g_3649, g_3715, g_3745, g_3747, g_3749;
extern int g_35e2, g_35e4, g_20cd, g_20cf, g_2f0c;
extern void far *g_4b60, far *g_7fbc, far *g_7fb8, far *g_abbe, far *g_4d68, far *g_4d6c;

void fn_09aa_0007(int a, int b);
void fn_0845_114d(int a, int b);
void fn_130a_0784(void);
void fn_0845_09f1(int a);
void fn_231c_0048(int a);
void fn_231c_0008(int a);
void fn_1f2d_0002(void far *p);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_1ebc_0111(int x1, int y1, int x2, int y2);
void fn_1ebc_01ec(void);
void fn_0845_07b3(char far *s, int x, int y, int c, int b, int f);
int fn_163d_0039(void far *list);
struct Btn far *fn_20bf_00dd(void far *list, int id);
void fn_20bf_01b2(struct Btn far *b, int a);
void far *fn_20bf_0006(void far *list, struct Btn far *b);
struct Btn far *fn_20bf_0073(struct Btn far *b);
struct Btn far *fn_20bf_00a8(struct Btn far *b);
void fn_20bf_010c(struct Btn far *b, int a);
void fn_20bf_035f(void far *list);
void fn_163d_05cc(struct Btn far *b);
void fn_0845_0bf6(void);
void fn_0845_093a(void);
void fn_0845_0a5b(void);
void fn_0845_08aa(void);
int fn_1e74_000f(int page);
void fn_1dbc_0017(int a, int b, int c, int d, int e, int f, int g, int h);
void fn_1e59_001d(int x1, int y1, int x2, int y2, int c);
int fn_14b3_0122(int w);
void far *fn_215f_0003(int a);
void fn_2096_014b(int x, int y, int w, int h, void far *p, int a);
void fn_2096_0000(int x, int y, int w, int h, void far *p, int a);
void fn_2279_025b(void far *s, void far *d, long n);
unsigned fn_1e64_002b(char far *s);
void far *fn_0845_04ec(void far *p);
void fn_1fd6_000a(int page, void far *p, int x, int y, int w, int f);
void fn_0845_0631(void far *p);
void fn_154c_000f(int a);
int fn_067a_01d1(int a);
void fn_067a_0401(int a, int b);
int fn_067a_08c2(int a);
void fn_178d_015e(void);
void fn_16cf_0022(void far *p, int a, int b);
int fn_1981_000a(char far *name);
int fn_1809_0000(char far *name, int mode);
int fn_1809_084d(int h, void far *buf, long n);
void fn_1809_058d(int h);
int fn_0845_1036(void);
int fn_0845_1044(int a, int b);
char far *fn_0845_06f8(int id);
void fn_0845_1605(void);
int fn_1aff_0420(int a, int b);
void ovr_2d22_0034(void far *p);
void ovr_2d5f_0133(int a);
void ovr_2d5f_012e(void);
void ovr_2ceb_0020(void);
void ovr_2cfa_0025(int a, int b, int c);
void ovr_2cfa_0020(int x, int y, int w, int h, int a, int b);
void ovr_2db9_0048(int v);
void ovr_2db9_002a(int v);
int ovr_2d3c_002a(char far *name);
void ovr_2d3c_002f(char far *name, char far *desc);
int ovr_2d96_0020(char far *s, int a, int b, void far *list, long c, int d);
void ovr_2da3_002a(void);
void ovr_2dad_0020(int a);
char far *ovr_2d46_002f(char far *s, int a);
void ovr_2ded_0020(char far *s, void far *p, long n);
void ovr_2d2c_0043(void);
void ovr_2e1e_0025(char far *s, void far *p);
void ovr_2e1e_0020(char far *s, void far *p);

int ovr_2d56_0020(struct Btn far *b);
int ovr_2d56_0025(int msg);
void ovr_2d56_002a(int msg);
int ovr_2d56_002f(int mode);
int ovr_2d56_0034(void);
int ovr_2d56_0039(long need);
void ovr_2d56_003e(int from, int to);
void ovr_2d56_0043(void);
int ovr_2d56_0048(struct Btn far *b);
void ovr_2d56_004d(struct Menu far *m);
void ovr_2d56_0052(struct Menu far *m);
void ovr_2d56_0057(struct Menu far *m);
void ovr_2d56_005c(int page, int x, int y, int nv, int ov, int win);
int ovr_2d56_0061(struct Btn far *b);
int ovr_2d56_0066(int slot);
int ovr_2d56_006b(void);
void ovr_2d56_0070(char far *buf, int n);
void ovr_2d56_0075(int save, int force);
void ovr_2d56_007a(int save);
char far *ovr_2d56_007f(int id);
int ovr_2d56_0084(struct Btn far *b);
int ovr_2d56_0089(struct Btn far *b);

int ovr_2d56_0020(struct Btn far *b)
{
    int loaded, run, id;

    fn_09aa_0007(0x4c, 1);
    g_7fd6 |= 4;
    if (g_4d66 == 1) ovr_2d22_0034(&f_27b1_0010);
    fn_0845_114d(0, 1);
    fn_130a_0784();
    ovr_2d5f_0133(1);
    loaded = 0;
    fn_0845_09f1(0);
    fn_231c_0048(2);
    g_11ba = 1;
    ovr_2d56_004d(&M.m[0]);
    fn_09aa_0007(0x4c, 0);
    ovr_2d56_0057(&M.m[0]);
    fn_1f2d_0002(g_7fbc);
    fn_1ebc_00e7();
    fn_0845_07b3(g_11ce, (g_ad8d + 1) << 3, g_ad8b + g_ad91 - 12, 0xcc, 0, 8);
    fn_1ebc_00fe();
    fn_1f2d_0002(g_7fb8);
    run = 1;
    while (run) {
        id = fn_163d_0039(g_4b60);
        if (!id) continue;
        if (id & 0x8000) {
            b = fn_20bf_00dd(g_4b60, id);
            ovr_2d56_0052(&M.m[0]);
            switch (id & 0x7fff) {
            case 1:
                if (ovr_2d56_002f(0)) {
                    loaded = 1;
                    run = 0;
                }
                break;
            case 2:
                if (ovr_2d56_002f(1)) run = 0;
                break;
            case 3:
                if (ovr_2d56_002f(2)) ;
                break;
            case 4:
                ovr_2d56_0084(b);
                break;
            case 5:
                ovr_2d56_0089(b);
                break;
            case 7:
                run = 0;
                break;
            case 6:
                if (ovr_2d56_0025(0x400a)) fn_0845_0bf6();
                break;
            }
            if (run) {
                ovr_2d56_004d(&M.m[0]);
                ovr_2d56_0057(&M.m[0]);
                fn_1f2d_0002(g_7fbc);
                fn_1ebc_00e7();
                fn_0845_07b3(g_11d9, (g_ad8d + 1) << 3, g_ad8b + g_ad91 - 12, 0xcc, 0, 8);
                fn_1ebc_00fe();
                fn_1f2d_0002(g_7fb8);
            }
        }
        fn_0845_093a();
    }
    g_7fd6 &= ~4;
    fn_20bf_01b2(b, 0);
    fn_0845_0a5b();
    ovr_2d5f_012e();
    if (loaded) ;
    ovr_2ceb_0020();
    fn_231c_0008(2);
    fn_0845_08aa();
    ovr_2d56_0043();
    if (!g_81ff) g_81fe = 1;
    return 1;
}

int ovr_2d56_0048(struct Btn far *b)
{
    int page, x, y, w, h, col, s;

    page = fn_1e74_000f(2);
    x = b->x + (g_1f3b[b->win].x << 3);
    y = b->y + g_1f3b[b->win].y;
    w = b->w;
    h = b->h;
    g_1f3b[12].x = x >> 3;
    g_1f3b[12].y = y;
    g_1f3b[12].w = w >> 3;
    g_1f3b[12].h = h;
    switch (b->state & 5) {
    case 4:
        s = 2;
        col = 0xfe;
        break;
    case 1:
    case 5:
        s = 0;
        col = 0xfe;
        break;
    default:
        s = 2;
        col = 0xcc;
    }
    ovr_2cfa_0025(12, s, 1);
    fn_0845_07b3(ovr_2d56_007f(b->text), x + (w >> 1), y + 4, col, 0, 9);
    if (!page) {
        fn_1ebc_0111(x, y, x + w, y + h);
        fn_1dbc_0017(x >> 3, y, x >> 3, y, w >> 3, h, 2, 0);
        fn_1ebc_01ec();
    }
    fn_1e74_000f(page);
    return 1;
}

static void frame(struct Btn far *b, int c)
{
    int x, y, w, h;

    if (b) {
        x = b->x;
        y = b->y;
        w = b->w;
        h = b->h;
        x += g_1f3b[b->win].x << 3;
        y += g_1f3b[b->win].y;
        if (!g_3649) fn_1ebc_0111(x, y, x + w, y + h);
        fn_1e59_001d(x, y, x + w - 1, y + h - 1, c);
        if (!g_3649) fn_1ebc_01ec();
    }
}

void ovr_2d56_004d(struct Menu far *m)
{
    fn_14b3_0122(m->win);
    fn_1ebc_00e7();
    fn_2096_014b(g_ad8d << 3, g_ad8b, g_ad8f << 3, g_ad91, fn_215f_0003(7), 0);
    fn_1ebc_00fe();
}

void ovr_2d56_0052(struct Menu far *m)
{
    fn_14b3_0122(m->win);
    fn_1ebc_00e7();
    fn_2096_0000(g_ad8d << 3, g_ad8b, g_ad8f << 3, g_ad91, fn_215f_0003(7), 0);
    fn_1ebc_00fe();
}

void ovr_2d56_0057(struct Menu far *m)
{
    struct MItem far *it;
    struct Btn far *b;
    void far *p;
    int k, v;
    struct I3 xs, ws;
    int j, i;

    g_4b60 = 0;
    fn_1e74_000f(2);
    fn_14b3_0122(m->win);
    ovr_2cfa_0025(g_3715, 2, 1);
    if (ovr_2d56_007f(m->title))
        fn_0845_07b3(ovr_2d56_007f(m->title), (g_ad8d << 3) + (g_ad8f << 2), g_ad8b + 6, 0xfe, 0, 9);
    if (!ovr_2d56_007f(m->items[0].text))
        fn_0845_07b3(ovr_2d56_007f(0x4009), (g_ad8d << 3) + (g_ad8f << 2), g_ad8b + 0x2a, 0xcc, 0, 9);
    for (i = 0; i < m->n; i++) {
        b = &f_2803_0592[i];
        it = &m->items[i];
        if (!ovr_2d56_007f(it->text)) continue;
        fn_2279_025b(&f_27b1_0010, b, 0x3cL);
        b->next = 0;
        b->id = i + 1;
        b->key1 = it->key;
        b->key2 = 0;
        b->x = it->x;
        b->y = it->y;
        b->w = it->w;
        b->h = it->h;
        b->type[0] = 4;
        b->type[1] = 4;
        b->type[2] = 4;
        b->pad_d = 0;
        b->flags = 0x4443;
        b->data[0] = (void far *)ovr_2d56_0048;
        b->data[1] = (void far *)ovr_2d56_0048;
        b->data[2] = (void far *)ovr_2d56_0048;
        b->win = m->win;
        b->state = 0;
        b->text = it->text;
        g_4b60 = fn_20bf_0006(g_4b60, b);
        fn_20bf_00a8(b);
        fn_20bf_010c(b, 0);
        fn_163d_05cc(b);
        if (it->label)
            fn_0845_07b3(ovr_2d56_007f(it->label),
                b->x + (g_1f3b[b->win].x << 3) - 1 - fn_1e64_002b(ovr_2d56_007f(it->label)),
                b->y + g_1f3b[b->win].y + 3, 0xcc, 0, 8);
    }
    if (g_4b64 >= 4 && m->type == 1) {
        g_1142.data[0] = f_2803_00be[11];
        g_1142.data[1] = f_2803_00be[13];
        g_1142.data[2] = f_2803_00be[13];
        g_1142.next = 0;
        g_1142.win = m->win;
        fn_20bf_010c(&g_1142, 0);
        fn_20bf_0073(&g_1142);
        frame(&g_1142, 0xe1);
        g_4b60 = fn_20bf_0006(g_4b60, &g_1142);
        g_117e.data[0] = f_2803_00be[12];
        g_117e.data[1] = f_2803_00be[14];
        g_117e.data[2] = f_2803_00be[14];
        g_117e.next = 0;
        g_117e.win = m->win;
        fn_20bf_010c(&g_117e, 0);
        fn_20bf_0073(&g_117e);
        frame(&g_117e, 0xe1);
        g_4b60 = fn_20bf_0006(g_4b60, &g_117e);
    }
    if (m->type == 2) {
        xs = g_11be;
        ws = g_11c4;
        for (k = i; m->items[i].text != -1; i++) {
            for (j = 0; j <= 2; j++) {
                b = &f_2803_0592[k];
                k++;
                it = &m->items[i];
                fn_2279_025b(&f_27b1_0010, b, 0x3cL);
                b->next = 0;
                b->id = k;
                b->key1 = 0;
                b->key2 = 0;
                b->x = it->x + xs.v[j];
                b->y = it->y;
                b->w = ws.v[j];
                b->h = it->h;
                b->type[0] = 0;
                b->type[1] = 0;
                b->type[2] = 0;
                b->pad_d = 0;
                if (j == 1) b->flags = 0x6606;
                else b->flags = 0x4406;
                b->data[0] = 0;
                b->data[1] = 0;
                b->data[2] = 0;
                b->win = m->win;
                b->state = 0;
                b->func = ovr_2d56_0061;
                b->text = m->items[i].text;
                b->part = j;
                g_4b60 = fn_20bf_0006(g_4b60, b);
                fn_20bf_00a8(b);
                fn_20bf_010c(b, 0);
            }
            p = fn_0845_04ec(f_2803_01de[7]);
            fn_1fd6_000a(g_3649, p, it->x, it->y, m->win, 0x10);
            fn_0845_0631(p);
            switch (m->items[i].text) {
            case 3: v = g_8201; break;
            case 4: v = g_8200; break;
            case 5: v = g_81ff; break;
            }
            ovr_2d56_005c(g_3649, it->x + xs.v[1], it->y, v, 0, m->win);
            if (it->label)
                fn_0845_07b3(ovr_2d56_007f(it->label),
                    it->x + (g_1f3b[b->win].x << 3) + -5 - fn_1e64_002b(ovr_2d56_007f(it->label)),
                    it->y + g_1f3b[b->win].y + 3, 0xcc, 0, 8);
        }
    }
    fn_1ebc_00e7();
    fn_14b3_0122(m->win);
    fn_1dbc_0017(g_ad8d, g_ad8b, g_ad8d, g_ad8b, g_ad8f, g_ad91, 2, 0);
    fn_1ebc_00fe();
    fn_1e74_000f(0);
}

void ovr_2d56_005c(int page, int x, int y, int nv, int ov, int win)
{
    int pg;
    void far *p;

    x += 2;
    pg = fn_1e74_000f(page);
    fn_1ebc_00e7();
    p = fn_0845_04ec(f_2803_01de[9]);
    fn_1fd6_000a(g_3649, p, x + ov, y, win, 0x10);
    fn_0845_0631(p);
    p = fn_0845_04ec(f_2803_01de[8]);
    fn_1fd6_000a(g_3649, p, x + nv, y, win, 0x10);
    fn_0845_0631(p);
    fn_1ebc_00fe();
    fn_1e74_000f(pg);
}

int ovr_2d56_0061(struct Btn far *b)
{
    int old, nv, x;

    switch (b->text) {
    case 3:
        if (g_3747 == 0 || g_3747 == 4) return 0;
        old = g_8201;
        break;
    case 4:
        if (g_3745 == 0 || g_3745 == 4) return 0;
        old = g_8200;
        break;
    case 5:
        if (g_3749 == 0 || g_abbe == 0) return 0;
        old = g_81ff;
        break;
    }
    nv = old;
    x = b->x;
    switch (b->part) {
    case 1:
        nv = g_2f0c - (b->x + (g_1f3b[b->win].x << 3) + 7);
        break;
    case 2:
        x -= 0x72;
        nv += 10;
        break;
    case 0:
        nv -= 10;
        x += 10;
        break;
    }
    if (nv < 0) nv = 0;
    if (nv > 100) nv = 100;
    if (nv == old) return 0;
    ovr_2d56_005c(0, x, b->y, nv, old, b->win);
    fn_154c_000f(0);
    switch (b->text) {
    case 3:
        g_8201 = nv;
        if (nv) {
            ovr_2db9_0048(g_8201 * 0x91 / 100 + 0x6e);
            g_7fda |= 2;
            if (!old) {
                g_35e4 = 1;
                fn_067a_01d1(fn_067a_01d1(-1));
            }
        } else {
            g_7fda &= ~2;
            ovr_2db9_0048(0);
            fn_178d_015e();
            g_35e4 = 0;
        }
        break;
    case 4:
        g_8200 = nv;
        if (nv) {
            ovr_2db9_002a(g_8200 * 200 / 100 + 0x37);
            g_7fda |= 1;
        } else
            g_7fda &= ~1;
        if (g_7fda & 1) {
            g_35e2 = 1;
            g_20cd = 1;
        } else {
            ovr_2db9_002a(1);
            g_35e2 = 0;
            g_20cd = 0;
        }
        fn_067a_0401(g_11ca, 0);
        if ((g_11ca = fn_067a_08c2(g_11ca)) == 0x2f) g_11ca++;
        break;
    case 5:
        g_81ff = nv;
        if (g_81ff && g_abbe) {
            fn_16cf_0022(g_abbe, 0xff, g_81ff * 200 / 100 + 0x37);
            g_20cf = 1;
        } else
            g_20cf = 0;
        break;
    }
    return 1;
}

int ovr_2d56_0025(int msg)
{
    int res, run, id;

    res = 0;
    M.m[1].title = msg;
    ovr_2d56_004d(&M.m[1]);
    ovr_2d56_0057(&M.m[1]);
    run = 1;
    while (run) {
        id = fn_163d_0039(g_4b60);
        if (id & 0x8000) {
            switch (id & 0x7fff) {
            case 1: res = 1; break;
            case 2: res = 0; break;
            }
            run = 0;
        }
        fn_0845_093a();
    }
    ovr_2d56_0052(&M.m[1]);
    return res;
}

void ovr_2d56_002a(int msg)
{
    int run, id;

    M.m[2].title = msg;
    ovr_2d56_004d(&M.m[2]);
    ovr_2d56_0057(&M.m[2]);
    run = 1;
    while (run) {
        id = fn_163d_0039(g_4b60);
        if (id & 0x8000) {
            switch (id & 0x7fff) {
            }
            run = 0;
        }
        fn_0845_093a();
    }
    ovr_2d56_0052(&M.m[2]);
}

#define LAST(s) (g_4b64 + ((s) ? g_11ba : 0) - 1)

int ovr_2d56_002f(int mode)
{
    int run, res;
    struct Btn far *b;
    char n1[14], n2[14];
    int id;

    res = 0;
    g_4b64 = ovr_2d56_006b();
    g_11bc = LAST(mode == 1);
    g_11bc = g_11bc > 0 ? g_11bc : 0;
    ovr_2d56_007a(mode == 1);
    switch (mode) {
    case 0: M.m[3].title = 0x400e; break;
    case 1: M.m[3].title = 0x400d; break;
    case 2: M.m[3].title = 0x400f; break;
    }
    ovr_2d56_004d(&M.m[3]);
    ovr_2d56_0057(&M.m[3]);
    ovr_2d56_0075(mode == 1, 1);
    run = 1;
    while (run) {
        ovr_2d56_0075(mode == 1, 0);
        id = fn_163d_0039(g_4b60);
        if (id & 0x8000) {
            id &= 0x7fff;
            b = fn_20bf_00dd(g_4b60, id);
            switch (id) {
            case 0x14:
                g_11bc++;
                g_11bc = LAST(mode == 1) > g_11bc ? g_11bc : LAST(mode == 1);
                ovr_2d56_007a(mode == 1);
                fn_20bf_035f(g_4b60);
                break;
            case 0x15:
                g_11bc--;
                g_11bc = g_11bc > 0 ? g_11bc : 0;
                ovr_2d56_007a(mode == 1);
                fn_20bf_035f(g_4b60);
                break;
            case 5:
                res = 0;
                run = 0;
                break;
            default:
                ovr_2d56_0052(&M.m[3]);
                id--;
                ovr_2d56_0070(n1, g_11bc - id);
                switch (mode) {
                case 0:
                    id = ovr_2d3c_002a(n1);
                    switch (id) {
                    case 0: ovr_2d56_002a(0x425d); break;
                    case 1: return 1;
                    case 2: ovr_2d56_002a(0x425c); break;
                    }
                    if (id == 1) return 1;
                    break;
                case 1:
                    res = ovr_2d56_0066(id);
                    if (res) return res;
                    break;
                case 2:
                    if (!ovr_2d56_0025(0x400b)) return 1;
                    mode = g_11bc - id;
                    ovr_2d56_0070(n1, g_11bc - id);
                    unlink(n1);
                    for (;;) {
                        mode++;
                        ovr_2d56_0070(n2, mode);
                        if (!fn_1981_000a(n2)) break;
                        rename(n2, n1);
                        strcpy(n1, n2);
                    }
                    return 1;
                }
                ovr_2d56_004d(&M.m[3]);
                ovr_2d56_0057(&M.m[3]);
                ovr_2d56_0075(mode == 1, 1);
            }
            fn_20bf_010c(b, 0);
        }
        fn_0845_093a();
    }
    ovr_2d56_0052(&M.m[3]);
    return res;
}

int ovr_2d56_0066(int slot)
{
    char n[14];
    char far *p;
    int res, run, first, r;

    p = M.names[slot];
    if (*p == '[' && !ovr_2d56_0039(500000L)) {
        ovr_2d56_002a(0x42cf);
        return 0;
    }
    if (*p == '[') *p = 0;
    ovr_2d56_004d(&M.m[4]);
    ovr_2d56_0057(&M.m[4]);
    res = 0;
    run = 1;
    first = 1;
    if (*p == '[') slot = g_4b64;
    fn_1e74_000f(0);
    fn_14b3_0122(8);
    fn_1ebc_00e7();
    ovr_2cfa_0020((g_ad8d << 3) - 1, g_ad8b - 1, (g_ad8f << 3) + 2, g_ad91 + 2, 4, 0);
    fn_1ebc_00fe();
    while (run) {
        r = ovr_2d96_0020(p, 0x3c, 8, g_4b60, 0L, first);
        first = 2;
        if (r & 0x8000) {
            fn_20bf_010c(fn_20bf_00dd(g_4b60, r & 0x7fff), 0);
            switch (r & 0x7fff) {
            case 1:
                if (*p) {
                    ovr_2d56_0070(n, g_11bc - slot);
                    ovr_2d3c_002f(n, p);
                    run = 0;
                    res = 1;
                }
                break;
            case 2:
                run = 0;
                res = 0;
                ovr_2d56_007a(1);
                break;
            }
        }
    }
    ovr_2d56_0052(&M.m[4]);
    return res;
}

int ovr_2d56_0034(void)
{
    struct Btn far *b;
    int id, run;

    fn_067a_01d1(0x145);
    fn_130a_0784();
    fn_0845_114d(0, 1);
    fn_0845_09f1(0);
    g_7fd6 |= 4;
    ovr_2d5f_0133(1);
    fn_231c_0048(2);
    ovr_2d56_004d(&M.m[5]);
    ovr_2d56_0057(&M.m[5]);
    run = 1;
    while (run) {
        id = fn_163d_0039(g_4b60);
        if (id & 0x8000) {
            b = fn_20bf_00dd(g_4b60, id);
            ovr_2d56_0052(&M.m[5]);
            switch (id & 0x7fff) {
            case 1:
                fn_0845_0bf6();
                break;
            case 2:
                if (ovr_2d56_002f(0)) run = 0;
                break;
            }
            if (run) {
                ovr_2d56_004d(&M.m[5]);
                ovr_2d56_0057(&M.m[5]);
            }
        }
        fn_0845_093a();
    }
    fn_0845_0a5b();
    g_7fd6 &= ~4;
    ovr_2d5f_012e();
    fn_20bf_01b2(b, 0);
    ovr_2ceb_0020();
    fn_231c_0008(2);
    fn_0845_08aa();
    return 1;
}

int ovr_2d56_006b(void)
{
    char n[14];
    int i;

    i = 0;
    while (ovr_2d56_0070(n, i), fn_1981_000a(n)) i++;
    return i;
}

void ovr_2d56_0070(char far *buf, int n)
{
    sprintf(buf, g_11e4, n);
}

void ovr_2d56_0075(int save, int force)
{
    if (!force && g_11bc == g_11cc) return;
    g_11cc = g_11bc;
    if (g_11bc >= 4) fn_20bf_00a8(&g_117e);
    else {
        fn_20bf_0073(&g_117e);
        frame(&g_117e, 0xe1);
    }
    if (LAST(save) > g_11bc) fn_20bf_00a8(&g_1142);
    else {
        fn_20bf_0073(&g_1142);
        frame(&g_1142, 0xe1);
    }
}

int ovr_2d56_0039(long need)
{
    struct dfree d;

    getdfree(0, &d);
    if (d.df_sclus != 0xffff && (long)d.df_avail * d.df_bsec * d.df_sclus > need) return 1;
    return 0;
}

/* NONMATCHING */
void ovr_2d56_007a(int save)
{
    char n[14];
    int i, h;

    for (i = 0; i < 4; i++) {
        if (g_11bc - i >= 0) {
            if (g_11bc - i == g_4b64) {
                if (save) {
                    strcpy(M.names[i], ovr_2d56_007f(0x4010));
                    continue;
                }
            } else {
                ovr_2d56_0070(n, g_11bc - i);
                if (fn_1981_000a(n)) {
                    h = fn_1809_0000(n, 1);
                    fn_1809_084d(h, M.names[i], 0x3cL);
                    fn_1809_058d(h);
                    continue;
                }
            }
        }
        M.names[i][0] = 0;
    }
}

/* NONMATCHING */
char far *ovr_2d56_007f(int id)
{
    char far *p;

    switch (id) {
    case -6:
    case -5:
    case -4:
    case -3:
    case -2:
        p = M.names[-id - 2];
        if (!*p) p = 0;
        return p;
    case -9:
        id = fn_0845_1036() + 0x406f;
        break;
    case -10:
        id = (g_7fda & 8) ? 0x4068 : 0x4069;
        break;
    case -11:
        id = (g_7fda & 4) ? 0x4068 : 0x4069;
        break;
    case -12:
        id = g_81fd + 0x42d6;
        break;
    case -14:
        id = g_81fe ? 0x4068 : 0x4069;
        break;
    }
    return fn_0845_06f8(id);
}

/* NONMATCHING */
int ovr_2d56_0084(struct Btn far *b)
{
    int id, run, old, nw;

    if (!g_81ff) g_81fe = 1;
    ovr_2d56_004d(&M.m[6]);
    ovr_2d56_0057(&M.m[6]);
    run = 1;
    while (run) {
        id = fn_163d_0039(g_4b60);
        if (id & 0x8000) {
            b = fn_20bf_00dd(g_4b60, id & 0x7fff);
            switch (id & 0x7fff) {
            case 1:
                nw = (old = fn_0845_1036()) + 1;
                if (nw > 2) nw = 0;
                g_7fda &= 0xf;
                g_7fda |= nw << 4;
                ovr_2d56_003e(old, nw);
                break;
            case 2:
                g_7fda ^= 8;
                break;
            case 3:
                g_7fda ^= 4;
                break;
            case 4:
                if (g_81fd) g_81fd--;
                else g_81fd = 2;
                break;
            case 5:
                if (!g_81ff || !g_3749) g_81fe = 1;
                else g_81fe = !g_81fe;
                fn_0845_1605();
                break;
            case 6:
                run = 0;
                break;
            }
            fn_20bf_010c(b, 0);
            fn_163d_05cc(b);
        }
        fn_0845_093a();
    }
    ovr_2d56_0052(&M.m[6]);
    return -1;
}

int ovr_2d56_0089(struct Btn far *b)
{
    int id, run;

    ovr_2d56_004d(&M.m[7]);
    ovr_2d56_0057(&M.m[7]);
    ovr_2da3_002a();
    run = 1;
    while (run) {
        id = fn_163d_0039(g_4b60);
        if (id & 0x8000) {
            b = fn_20bf_00dd(g_4b60, id & 0x7fff);
            if ((id & 0x7fff) == 1) run = 0;
            fn_20bf_010c(b, 0);
            fn_163d_05cc(b);
        }
        fn_0845_093a();
    }
    ovr_2d56_0052(&M.m[7]);
    return -1;
}

void ovr_2d56_003e(int from, int to)
{
    struct Monster far *m;
    int i, f;

    if (from == to) return;
    f = fn_0845_1044(f_2803_002c[from], f_2803_002c[to]);
    for (m = f_2803_15fa, i = 0; i < 30; i++, m++) {
        if (m->mode < 14 && m->block && m->hp > 0) {
            m->hp = fn_1aff_0420(m->hp, f);
            if (to < from) m->hp++;
            if (m->hp == 0) m->hp = 1;
        }
    }
}

void ovr_2d56_0043(void)
{
    char buf[14];

    if (g_20db == g_81fd) return;
    g_20db = g_81fd;
    ovr_2dad_0020(g_20db);
    sprintf(buf, g_11f2, g_7fe5);
    ovr_2ded_0020(ovr_2d46_002f(g_11fc, -1), g_4d6c, 0xffffL);
    ovr_2ded_0020(ovr_2d46_002f(buf, -1), g_4d68, 0xffffL);
    ovr_2d2c_0043();
    ovr_2e1e_0025(g_1202, g_ad41);
    g_ad49 = g_81fd;
    ovr_2e1e_0020(g_120c, g_ad41);
}
