/* s017: monsters (movement, collision, path finding, line of sight, attacks, AI modes) */
#include "lol.h"

extern char far f_2803_0000[];
extern struct Block far *g_4d84[18];
extern char g_2083[];
extern unsigned char g_531e[];
extern unsigned g_7fd6;
extern int g_7fd0, g_7fd2, g_7fd4, g_4d5e, g_4d60;
struct XY { int x, y; };
extern int g_20d3;
extern int far f_2803_0038[];
void fn_070c_05fa(struct Monster far *m);
void fn_0d6c_0f1e(struct Monster far *m);
extern char g_7fe5;

void fn_07bc_0272(int it, int x, int y, int a, int b);
void fn_0845_046c(int b);
int fn_07bc_012d(int type, int flags, int flags2);
int fn_0b6b_032f(int type, int item, int x, int y, int power, int dir, int unused, int owner, int e);
void ovr_2da0_002a(void);
void fn_17d6_0006(int a);
void ovr_2d28_0034(int a, int b, int c, int d);
int fn_2313_0000(void);
int fn_1aff_0420(int a, int b);
int fn_1aff_0434(int a, int b);
int fn_0845_1036(void);
char far *fn_0845_06f8(int id);
int fn_1afa_0010(int x1, int y1, int x2, int y2);
void fn_1aff_0341(int x, int y, int *dx, int *dy, int dir);
void ovr_2cda_0025(int n, int *a, int *b, int c);
int fn_1aff_039a(int x, int y);
int fn_0845_0cf7(int b, int dir, int mask);
int fn_0845_04af(int x1, int y1, int x2, int y2);
struct Item far *fn_080e_000b(int id);
void fn_13e8_03e9(int b, int a);
void fn_080e_013c(int far *list, int it);
void fn_080e_0034(int far *list, int it);
void fn_0845_1343(int b, unsigned mask, int c, int d, int e, int f);
void fn_067a_02f5(int n, int pos);
int fn_1aff_02d2(int a, int b);
int fn_0845_0636(int n, int sides);
void ovr_2d00_002a(int a, int b, int c);
void ovr_2d00_0025(int ch, int a, int b, int c, int d);
void ovr_2d00_0020(int ch);
int ovr_2d46_0048(int ch, int a, int b);
void ovr_2d2c_00b1(struct Monster far *m, int it);
int fn_154c_0057(int id, int a, int b);
char far *fn_0845_06f8(int id);
void fn_0845_01c4(unsigned flags, char far *fmt, ...);
void fn_07bc_044c(int it);
void fn_0a21_022b(int ch);
int fn_070c_03b1(int x, int y);
void fn_067a_0401(int n, int force);
int fn_070c_044a(int who, int ch, int a);
int fn_070c_0793(int who, int ch, int t);
int fn_070c_07e3(int dmg);
int fn_070c_07f5(int who, int dmg, int src, int k, int how);
int fn_09aa_0183(int b, int dir);

int fn_0d6c_156b(int b, int dir, int n, int target);
void fn_0d6c_1383(struct Monster far *m, int n);


int g_241a[16] = { 0, 1, 3, 3, 0, 1, 2, 2, 1, 1, 2, 3, 0, 0, 2, 3 };
int g_243a[8] = { 0, 32, 32, 32, 0, -32, -32, -32 };
int g_244a[8] = { -32, -32, 0, 32, 32, 32, 0, -32 };
char g_245a[3] = { 13, 9, 3 };
int g_245d[8] = { 7, -6, 5, -4, 3, -2, 1, 0 };
int g_246d[8] = { -7, 6, -5, 4, -3, 2, -1, 0 };
int g_247d = 0;
int g_247f = 0;
char g_2481[2] = { 2, -2 };    /* indexed 1..2 through g_2480 */
#define g_2480 (g_2481 - 1)
char g_2483[17] = { 1, 0, 1, 3, 3, 0, 0, 3, 4, 1, 0, 0, 4 };

void fn_0d6c_0004(int x, int y, int *nx, int *ny, int dir)
{
    *nx = (x + g_243a[dir]) & 0x1fff;
    *ny = (y + g_244a[dir]) & 0x1fff;
}

void fn_0d6c_0034(struct Monster far *m)
{
    int t;
    register int it;

    for (it = m->items; it; ) {
        t = it;
        it = f_2803_1cfd[t].next;
        fn_07bc_0272(t, m->x, m->y, 0, 1);
    }
}

void fn_0d6c_0073(struct Monster far *m, int dir)
{
    m->dir = dir;
    if ((dir & 1) <= 0 || !ABS(m->dir - m->facing * 2 < 2)) m->facing = m->dir >> 1;
    fn_0845_046c(m->block);
}

int fn_0d6c_0109(struct Monster far *m)
{
    int my;
    int px;
    int py;
    int a;
    int b;
    register int d;
    register int mx;
    int i;

    if (m->type->flags & 8) return 1;
    mx = (m->x & 0xff00) | 0x80;
    my = (m->y & 0xff00) | 0x80;
    px = g_7fd2;
    py = g_7fd4;
    if (m->type->flags & 1)
        d = m->dir >> 1;
    else {
        d = fn_1afa_0010(mx, my, px, py);
        if ((m->type->flags & 2) || (m->dir ^ 4) != d)
            d >>= 1;
        else
            return 0;
    }
    fn_1aff_0341(mx, my, &px, &py, d);
    px = ((char *)&px)[1];
    py = ((char *)&py)[1];
    if (py < 0 || py > 3 || ABS(px) > py) return 0;
    for (i = 0; i < 18; i++) g_4d84[i] = &g_8203[(m->block + g_2083[d + i]) & 0x3ff];
    ovr_2cda_0025(g_245a[py - 1] + px, &a, &b, 13);
    return a < b ? 1 : 0;
}

int fn_0d6c_024d(int x, int y, unsigned fl)
{
    if (fl & 4) return fn_1aff_039a(x, y) == g_7fd0 ? 1 : 0;
    return 0;
}

int fn_0d6c_0278(int blk, int x, int y, int size, unsigned fl, int ign)
{
    struct Item far *p;
    struct Monster far *m;
    int d;
    register int b = blk;
    register int f = fl;

    if (b == g_7fd0) f &= ~1;
    if (f & 1) {
        g_4d5e = b;
        if (fn_0845_0cf7(b, -1, ign)) return 1;
        g_4d5e = 0;
    }
    if (f & 2)
        for (b = g_8203[b].mon; b & 0x8000; b = p->next) {
            m = &f_2803_15fa[b & 0x7fff];
            if (m->mode < 13) {
                d = fn_0845_04af(x, y, m->x, m->y);
                if (size + m->type->size > d) return 2;
            }
            p = fn_080e_000b(b);
        }
    return 0;
}

int fn_0d6c_0338(int x0, int y0, int size, unsigned fl, int ign)
{
    int flag;
    int nx;
    int ny;
    int dx;
    int dy;
    int r;
    int b;
    register int x = x0;
    register int y = y0;

    nx = 0;
    ny = 0;
    dx = 0;
    dy = 0;
    g_4d60 = 0;
    b = fn_1aff_039a(x, y);
    if ((r = fn_0d6c_0278(b, x, y, size, fl, ign)) != 0) return r;
    if (fn_0d6c_024d(x, y, fl)) return 4;
    flag = 0;
    if (x & 0x80) {
        if (((x & 0xff) + size) & 0xff00) {
            nx = x + size;
            b = fn_1aff_039a(nx, y);
            dx = 1;
            g_4d60 = 2;
            if ((r = fn_0d6c_0278(b, x, y, size, fl, ign)) != 0) return r;
            if (fn_0d6c_024d(x + dx, y, fl)) return 4;
            flag = 1;
        }
    } else if (((x & 0xff) - size) & 0xff00) {
        nx = x - size;
        b = fn_1aff_039a(nx, y);
        dx = -1;
        g_4d60 = 6;
        if ((r = fn_0d6c_0278(b, x, y, size, fl, ign)) != 0) return r;
        if (fn_0d6c_024d(x + dx, y, fl)) return 4;
        flag = 1;
    }
    if (y & 0x80) {
        if (((y & 0xff) + size) & 0xff00) {
            ny = y + size;
            b = fn_1aff_039a(x, ny);
            dy = 1;
            g_4d60 = 4;
            if ((r = fn_0d6c_0278(b, x, y, size, fl, ign)) != 0) return r;
            if (fn_0d6c_024d(x, y + dy, fl)) return 4;
            flag &= 1;
        } else
            flag = 0;
    } else if (((y & 0xff) - size) & 0xff00) {
        ny = y - size;
        b = fn_1aff_039a(x, ny);
        dy = -1;
        g_4d60 = 0;
        if ((r = fn_0d6c_0278(b, x, y, size, fl, ign)) != 0) return r;
        if (fn_0d6c_024d(x, y + dy, fl)) return 4;
        flag &= 1;
    } else
        flag = 0;
    if (flag) {
        b = fn_1aff_039a(nx, ny);
        if ((r = fn_0d6c_0278(b, x, y, size, fl, ign)) != 0) return r;
        if (fn_0d6c_024d(x + dx, y + dy, fl)) return 4;
    }
    return 0;
}

int fn_0d6c_059d(int x, int y, struct Monster far *m, int fl)
{
    int old;
    int r;

    old = m->mode;
    m->mode = 15;
    if (m->type->flags & 0x1000)
        r = fn_0d6c_0338(x, y, m->type->size, 7, 0x20);
    else
        r = fn_0d6c_0338(x, y, m->type->size, 7, fl);
    m->mode = old;
    return r;
}

int fn_0d6c_05f4(struct Monster far *m, int tx, int ty)
{
    int mx;
    int my;
    int nx;
    int ny;
    int k;
    int far *tbl;
    int d;
    register int dir;
    register int w;

    if (++g_247f > 10) {
        g_247f = 0;
        g_247d ^= 1;
    }
    tbl = g_245d;
    if (g_247d) tbl = g_246d;
    dir = m->dir;
    mx = m->x;
    my = m->y;
    if ((d = fn_1afa_0010(m->x, m->y, tx, ty)) == -1) return -1;
    if (m->flags & 8) d ^= 4;
    d -= dir;
    d &= 7;
    if (d) {
        if (d < 5)
            dir++;
        else
            dir--;
        dir &= 7;
    }
    for (k = 7; k > -1; k--) {
        dir = (dir + tbl[k]) & 7;
        fn_0d6c_0004(mx, my, &nx, &ny, dir);
        d = fn_0d6c_059d(nx, ny, m, 4);
        if (!d) return dir;
        if (d == 1 && !(dir & 1) && (m->type->flags & 0x80)) {
            w = WALL(g_4d5e, (dir >> 1) ^ 2);
            if ((g_531e[w] & 0x20) && f_2803_0000[w + 0x56] == 5) {
                fn_13e8_03e9(g_4d5e, 1);
                return -1;
            }
            if (g_531e[w] & 8) return -1;
        }
    }
    return -1;
}

void fn_0d6c_0742(struct Monster far *m, int x0, int y0)
{
    int had;
    int old;
    register int x = x0;
    register int y = y0;

    had = 1;
    old = m->block;
    if (m->block) {
        fn_080e_013c(&g_8203[m->block].mon, m->id | 0x8000);
        g_8203[m->block].drawDir = 5;
        fn_0845_046c(m->block);
    } else
        had = 0;
    m->block = fn_1aff_039a(x, y);
    if (m->x != x || m->y != y) {
        m->x = x;
        m->y = y;
        m->anim++;
        m->anim &= 3;
    }
    if (m->block) {
        fn_080e_0034(&g_8203[m->block].mon, 0x8000 | m->id);
        g_8203[m->block].drawDir = 5;
        fn_0845_046c(m->block);
        if (m->type->moveSnd && had && (((m->type->flags & 0x100) && (m->anim & 1)) || m->block != old)) {
            if (m->block != old) fn_0845_1343(m->block, 0x800, -1, m->id, 0, 0);
            if (!(g_7fd6 & 1)) fn_067a_02f5(m->type->moveSnd, m->block);
        }
    }
}

void fn_0d6c_089e(struct Monster far *m)
{
    int nx;
    int ny;
    register int d;

    if (m->type->flags & 0x400) return;
    d = fn_0d6c_05f4(m, m->tx, m->ty);
    if (d != -1) {
        fn_0d6c_0073(m, d);
        if (!m->c25 || fn_1aff_02d2(m->block, g_7fd0) < 2 || fn_0d6c_156b(m->block, m->dir, 3, g_7fd0) == 5 ||
            !m->c27) {
            fn_0d6c_0004(m->x, m->y, &nx, &ny, d);
            fn_0d6c_0742(m, nx, ny);
        }
    } else if (fn_0d6c_059d(m->x, m->y, m, 4) == 1) {
        g_4d60 ^= 4;
        fn_0d6c_0073(m, g_4d60);
        fn_0d6c_0004(m->x, m->y, &nx, &ny, g_4d60);
        fn_0d6c_0742(m, nx, ny);
    }
}

void fn_0d6c_0995(struct Monster far *m, int mode)
{
    register int i;

    if (m->mode == 13 && mode != 14) return;
    if (mode == 7) {
        m->tx = g_7fd2;
        m->ty = g_7fd4;
    }
    if (m->mode == 1 && mode == 7) {
        for (m = f_2803_15fa, i = 0; i < 30; i++, m++)
            if (m->mode == 1) {
                m->mode = mode;
                m->c15 = 0;
                m->tx = g_7fd2;
                m->ty = g_7fd4;
                fn_0d6c_0073(m, fn_1afa_0010(m->x, m->y, m->tx, m->ty));
            }
        return;
    }
    m->mode = mode;
    m->c15 = 0;
    if (mode == 14) m->hp = 0;
    if (mode == 13 && (m->flags & 0x20)) {
        m->mode = 0;
        fn_0d6c_0034(m);
        if (g_7fe5 != 0x1d) fn_0d6c_0995(m, 14);
        fn_0845_1343(0x404, -1, m->id, m->id, 0, 0);
        fn_0845_046c(m->block);
        if (m->mode == 14) fn_0d6c_0742(m, 0, 0);
    }
}

void fn_0d6c_0acc(struct Monster far *m, int chr, int dmg)
{
    register int ch = chr;
    register int it;

    if (fn_0845_0636(1, 100) > m->type->hitChance) return;
    switch (m->type->hitKind) {
    case 10:
        ovr_2d00_002a(0x40, 0x48, 0x64);
        break;
    case 9:
        m->hp += dmg;
        m->hp = m->hp < m->type->maxHp ? m->hp : m->type->maxHp;
        break;
    case 1:
        if ((it = ovr_2d46_0048(ch, 0x7ff, 0)) != 0) {
            ovr_2d2c_00b1(m, it);
            if (fn_154c_0057(0x4019, f_2803_362d[ch].wE, 1)) fn_0845_01c4(6, fn_0845_06f8(0x4019));
        }
        break;
    case 3:
        if ((it = ovr_2d46_0048(ch, 0x20, 0)) != 0) {
            fn_07bc_044c(it);
            if (fn_154c_0057(0x401b, f_2803_362d[ch].wE, 1)) fn_0845_01c4(6, fn_0845_06f8(0x401b));
        }
        break;
    case 4:
        if (!(it = ovr_2d46_0048(ch, 0x0f, 0))) break;
        if (fn_154c_0057(0x401e, f_2803_362d[ch].wE, 1))
            fn_0845_01c4(6, fn_0845_06f8(0x401e), f_2803_362d[ch].name);
        fn_07bc_0272(it, m->x, m->y, 0, 1);
        break;
    case 6:
        if (f_2803_362d[ch].mp > 0) {
            m->hp += f_2803_362d[ch].mp;
            f_2803_362d[ch].mp = 0;
            fn_0a21_022b(ch);
            if (fn_154c_0057(0x4020, f_2803_362d[ch].wE, 1))
                fn_0845_01c4(6, fn_0845_06f8(0x4020), f_2803_362d[ch].name);
        }
        break;
    case 2:
        ovr_2d00_0025(ch, 0x80, 0x88, 0x64, 1);
        break;
    case 8:
        ovr_2d00_0020(ch);
        break;
    }
}

void fn_0d6c_0d2a(struct Monster far *m, int chr, int fl0, int x, int dmg)
{
    int it;
    int k;
    register int ch = chr;
    register int f = fl0;

    if (fn_0845_0636(1, 100) > m->type->defChance) return;
    switch (m->type->defKind) {
    case 6:
        if ((f & 0x84) == 0x84) m->c25++;
        break;
    case 4:
        if (f != 3) break;
        m->hp += dmg;
        m->hp = m->hp < m->type->maxHp ? m->hp : m->type->maxHp;
        break;
    case 5:
        if (!(f & 0x80)) break;
        m->hp += dmg;
        m->hp = m->hp < m->type->maxHp ? m->hp : m->type->maxHp;
        break;
    case 1:
    case 2:
        if ((f & 0x3f) == 2) break;
        if (x) break;
        for (k = 0; k < 3; k++) {
            if (!(it = f_2803_362d[ch].items[k])) continue;
            if ((g_7fb2[f_2803_1cfd[it].type].ca & 0x3f) != f) continue;
            ovr_2d46_0048(ch, 0x7ff, 0);
            if (m->type->defKind == 1) {
                ovr_2d2c_00b1(m, it);
                if (fn_154c_0057(0x401c, f_2803_362d[ch].wE, 1)) fn_0845_01c4(6, fn_0845_06f8(0x401c));
            } else {
                fn_07bc_044c(it);
                if (fn_154c_0057(0x401d, f_2803_362d[ch].wE, 1)) fn_0845_01c4(6, fn_0845_06f8(0x401d));
            }
        }
        break;
    case 3:
        if (f & 0x80) fn_0d6c_1383(m, 0x1e);
        break;
    }
}

void fn_0d6c_0f1e(struct Monster far *m)
{
    int dmg;
    int t;
    int who;
    register int ch;

    ch = fn_070c_03b1(m->x, m->y);
    who = m->id | 0x8000;
    fn_067a_0401(m->type->atkSnd, 0);
    if ((t = fn_070c_044a(who, ch, 0)) != 0) {
        dmg = fn_070c_0793(who, ch, t);
        who = fn_070c_07e3(dmg);
        fn_070c_07f5(ch, who, m->id | 0x8000, 0, 0);
        fn_0d6c_0acc(m, ch, who);
    }
    fn_0d6c_0995(m, 8);
    fn_0845_046c(m->block);
}

int fn_0d6c_0fcb(int b)
{
    int o;

    o = g_8203[b].mon;
    return o & 0x8000 ? o & 0x7fff : -1;
}

int fn_0d6c_0fea(struct Monster far *m)
{
    int b;
    register int d;
    register int i;

    b = m->block;
    d = m->dir >> 1;
    if ((m->next & 0x8000) || fn_0d6c_0fcb(b) != m->id) return 1;
    for (i = 0; i < 3; i++) {
        d++;
        d &= 3;
        if (fn_0d6c_0fcb(fn_09aa_0183(b, d)) != -1) return 1;
    }
    return 0;
}

void fn_0d6c_1050(struct Monster far *m)
{
    int far *p;
    int x;
    int y;
    int px;
    int py;
    int t;
    register int f;

    x = m->x;
    y = m->y;
    switch (m->dir >> 1) {
    case 0:
    case 2:
        p = &x;
        break;
    case 1:
    case 3:
        p = &y;
        break;
    default:
        p = &x;
    }
    f = (*p & 0x7f) == 0 ? 1 : 0;
    t = m->type->size > 0x3f || (f && !fn_0d6c_0fea(m)) ? 1 : 0;
    if (f && t) return;
    if (!t)
        *p += (*p & 0x80) ? 32 : -32;
    else
        *p += (*p & 0x80) ? -32 : 32;
    if (fn_0d6c_059d(x, y, m, 4)) return;
    px = g_7fd2;
    py = g_7fd4;
    fn_1aff_0341(x, y, &px, &py, m->dir >> 1);
    if (py <= 0xa0 && ABS(px) <= 0x50) fn_0d6c_0742(m, x, y);
}

void fn_0d6c_1183(struct Monster far *m)
{
    int px;
    int py;
    register int d;

    if (!(m->flags & 8)) {
        px = g_7fd2;
        py = g_7fd4;
        d = fn_1afa_0010(m->x & 0xff00, m->y & 0xff00, g_7fd2 & 0xff00, py & 0xff00);
        fn_1aff_0341(m->x, m->y, &px, &py, d >> 1);
        if (py <= 0xa0 && ABS(px) <= 0x50) {
            if (m->dir != d || m->facing != d >> 1) {
                fn_0d6c_0073(m, d);
                fn_0845_046c(m->block);
            } else
                fn_0d6c_0f1e(m);
            return;
        }
    }
    if (m->x == m->tx && m->y == m->ty) {
        fn_0d6c_0073(m, m->tdir);
        if (fn_0845_0636(1, 100) > 50)
            fn_0d6c_0995(m, 3);
        else
            fn_0d6c_0995(m, 4);
    } else
        fn_0d6c_089e(m);
}

void fn_0d6c_129f(struct Monster far *m)
{
    if (m->x != m->tx || m->y != m->ty)
        fn_0d6c_089e(m);
    else if (m->dir != m->tdir)
        fn_0d6c_0073(m, g_241a[m->facing * 4 + (m->tdir >> 1)] << 1);
}

void fn_0d6c_12fc(struct Monster far *m)
{
    register int i;

    if (m->flags & 0x10) {
        for (i = 0; i < 30; i++)
            if (f_2803_15fa[i].mode == 1) fn_0d6c_0995(&f_2803_15fa[i], 7);
    } else if (m->mode == 1)
        fn_0d6c_129f(m);
}

void fn_0d6c_1354(struct Monster far *m)
{
    if (++m->c15 > 2) fn_070c_05fa(m);
    fn_0845_046c(m->block);
}

void fn_0d6c_1383(struct Monster far *m, int n)
{
    m->flags |= 8;
    m->dir = ((int (*)(int, int, struct XY))fn_1afa_0010)(m->x, m->y, *(struct XY *)&g_7fd2) ^ 4;
    fn_0d6c_0995(m, 9);
    m->c15 = n;
}

void fn_0d6c_13c5(struct Monster far *m)
{
    int b;
    register int i;

    if (fn_0d6c_0109(m)) fn_0d6c_0995(m, 7);
    for (i = 0; i < 4; i++) {
        b = fn_09aa_0183(m->block, i);
        if (b == g_7fd0) fn_0d6c_0995(m, 7);
    }
}

/* C version: BCC 3.1 does not reproduce the original code from it (tools/inlasm.py) */
#if 0
void fn_0d6c_1419(struct Monster far *m)
{
    int cnt;
    int nx;
    int ny;
    register int d;
    register int i;

    if (m->c15 == 0) {
        m->dir &= 6;
        fn_0d6c_0004(m->x, m->y, &nx, &ny, m->dir);
        if (!fn_0d6c_059d(nx, ny, m, 4)) {
            fn_0d6c_0742(m, nx, ny);
            return;
        }
        m->c15 = g_2480[fn_0845_0636(1, 2)];
        m->dir += m->c15;
        m->dir &= 6;
        return;
    }
    cnt = m->id;
    d = (m->dir - m->c15) & 6;
    for (i = 0; i < 7; i++) {
        fn_0d6c_0004(m->x, m->y, &nx, &ny, d);
        if (!fn_0d6c_059d(nx, ny, m, 4)) {
            fn_0d6c_0742(m, nx, ny);
            fn_0d6c_0073(m, d);
            if (i) return;
            if (++cnt > 3) m->c15 = 0;
            m->c15 &= 0xff;
            m->c15 |= cnt << 8;
            return;
        }
        d += m->c15;
        d &= 6;
    }
    fn_0d6c_0995(m, 3);
}
#endif
void fn_0d6c_1419(struct Monster far *m)
{
    char _l[6];
    asm les bx,dword ptr [bp+6]
    asm cmp byte ptr es:[bx+15h],0
    asm jnz L_008f
    asm and byte ptr es:[bx+17h],6
    asm mov al,es:[bx+17h]
    asm cbw
    asm push ax
    asm push ss
    asm lea ax,word ptr _l
    asm push ax
    asm push ss
    asm lea ax,word ptr _l+2
    asm push ax
    asm push word ptr es:[bx+9]
    asm push word ptr es:[bx+7]
    ((void (far *)(void))fn_0d6c_0004)();
    asm add sp,0eh
    asm push 4
    asm db 66h	/* push dword [bp+0x6] */
    asm push word ptr [bp+6]
    asm push word ptr _l
    asm push word ptr _l+2
    ((void (far *)(void))fn_0d6c_059d)();
    asm add sp,0ah
    asm db 0bh, 0c0h	/* or ax,ax */
    asm jnz L_0061
    asm push word ptr _l
    asm push word ptr _l+2
    asm db 66h	/* push dword [bp+0x6] */
    asm push word ptr [bp+6]
    ((void (far *)(void))fn_0d6c_0742)();
    asm add sp,8
    asm db 0e9h, 0edh, 0	/* jmp 0x14e */
L_0061:
    asm db 66h, 68h, 1, 0, 2, 0	/* push dword 0x20001 */
    asm call far ptr fn_0845_0636
    asm add sp,4
    asm db 8bh, 0d8h	/* mov bx,ax */
    asm mov al,[bx+2480h]
    asm cbw
    asm db 8bh, 0d0h	/* mov dx,ax */
    asm les bx,dword ptr [bp+6]
    asm mov es:[bx+15h],dl
    asm mov al,es:[bx+15h]
    asm add es:[bx+17h],al
    asm and byte ptr es:[bx+17h],6
    asm db 0e9h, 0bfh, 0	/* jmp 0x14e */
L_008f:
    asm les bx,dword ptr [bp+6]
    asm mov al,es:[bx+15h]
    asm cbw
    asm db 8bh, 0d0h	/* mov dx,ax */
    asm mov al,es:[bx+16h]
    asm cbw
    asm mov word ptr _l+4,ax
    asm mov al,es:[bx+17h]
    asm cbw
    asm db 2bh, 0c2h	/* sub ax,dx */
    asm db 8bh, 0f0h	/* mov si,ax */
    asm db 83h, 0e6h, 6	/* and si,0x6 */
    asm db 33h, 0ffh	/* xor di,di */
L_00af:
    asm push si
    asm push ss
    asm lea ax,word ptr _l
    asm push ax
    asm push ss
    asm lea ax,word ptr _l+2
    asm push ax
    asm les bx,dword ptr [bp+6]
    asm push word ptr es:[bx+9]
    asm push word ptr es:[bx+7]
    ((void (far *)(void))fn_0d6c_0004)();
    asm add sp,0eh
    asm push 4
    asm db 66h	/* push dword [bp+0x6] */
    asm push word ptr [bp+6]
    asm push word ptr _l
    asm push word ptr _l+2
    ((void (far *)(void))fn_0d6c_059d)();
    asm add sp,0ah
    asm db 0bh, 0c0h	/* or ax,ax */
    asm jnz L_012b
    asm push word ptr _l
    asm push word ptr _l+2
    asm db 66h	/* push dword [bp+0x6] */
    asm push word ptr [bp+6]
    ((void (far *)(void))fn_0d6c_0742)();
    asm add sp,8
    asm push si
    asm db 66h	/* push dword [bp+0x6] */
    asm push word ptr [bp+6]
    ((void (far *)(void))fn_0d6c_0073)();
    asm add sp,6
    asm db 0bh, 0ffh	/* or di,di */
    asm db 75h, 4ah	/* jnz 0x14e */
    asm inc word ptr _l+4
    asm mov ax,word ptr _l+4
    asm cmp ax,3
    asm jng L_0117
    asm les bx,dword ptr [bp+6]
    asm mov byte ptr es:[bx+15h],0
L_0117:
    asm les bx,dword ptr [bp+6]
    asm and byte ptr es:[bx+15h],0ffh
    asm mov al,byte ptr _l+4
    asm shl al,8
    asm or es:[bx+15h],al
    asm db 0ebh, 23h	/* jmp 0x14e */
L_012b:
    asm les bx,dword ptr [bp+6]
    asm mov al,es:[bx+15h]
    asm cbw
    asm db 3, 0f0h	/* add si,ax */
    asm db 83h, 0e6h, 6	/* and si,0x6 */
    asm inc di
    asm cmp di,7
    asm jnl L_0141
    asm jmp L_00af
L_0141:
    asm push 3
    asm db 66h	/* push dword [bp+0x6] */
    asm push word ptr [bp+6]
    ((void (far *)(void))fn_0d6c_0995)();
    asm add sp,6
Lret:
    ;
}

int fn_0d6c_156b(int blk, int dir, int n, int target)
{
    volatile int dist;
    int b;
    int k;
    register int i = blk;
    register int t = target;

    if ((dist = fn_1aff_02d2(i, t)) > n) return 5;
    k = fn_1afa_0010(i & 0x1f, i >> 5, t & 0x1f, t >> 5);
    if (k & 1) return 5;
    if (dir << 1 != k) return 5;
    if ((i & 0x1f) != (t & 0x1f) && (i & 0xffe0) != (t & 0xffe0)) return 5;
    b = i;
    for (i = 0; i < n; i++) {
        b = fn_09aa_0183(b, dir);
        if (b == t) return dir;
        if (g_531e[WALL(b, dir ^ 2)] & 2) break;
        if (g_8203[b].mon & 0x8000) break;
    }
    return 5;
}

/* NONMATCHING */
int fn_0d6c_1630(struct Monster far *m)
{
    struct Monster far *o;
    int f;
    int dir;
    register int s;

    if (!m->c25) return 0;
    if (m->c27 > 0) {
        m->c27--;
        return 0;
    }
    if ((dir = fn_0d6c_156b(m->block, m->facing, 4, g_7fd0)) == 5) return 0;
    if (m->type->flags & 0x10)
        s = fn_0845_0636(1, m->type->nSpells) - 1;
    else {
        s = m->c26;
        if (++m->c26 >= m->type->nSpells) m->c26 = 0;
    }
    s = m->type->spells[s];
    if (s & 0xc000) {
        if (fn_1aff_02d2(m->block, g_7fd0) > 1) {
            f = (s & 0x4000) ? 0 : 1;
            if ((s = fn_07bc_012d(s & 0x3fff, 0, 0)) != 0)
                if (fn_0b6b_032f(f, s, m->x, m->y, 12, dir << 1, -1, m->id | 0x8000, 0x3f) == 0)
                    fn_07bc_044c(s);
        }
    } else if (!(s & 0x2000)) {
        if (fn_1aff_02d2(m->block, g_7fd0) >= 2) return 0;
        switch (s) {
        case 4:
            ovr_2da0_002a();
            break;
        case 3:
            for (o = f_2803_15fa, s = 0; s < 30; s++, o++)
                if (fn_1aff_02d2(o->block, m->block) <= 6) fn_0d6c_0995(m, 7);
            fn_0845_01c4(2, fn_0845_06f8(0x401a));
            break;
        case 1:
            fn_17d6_0006(0x93);
            ovr_2d28_0034(10, 2, 2, 1);
            for (s = 0; s < 4; s++)
                if (f_2803_362d[s].flags & 1) {
                    if ((f = ovr_2d46_0048(s, 15, 0)) != 0)
                        ((void (*)(int, struct XY, int, int))fn_07bc_0272)(f, *(struct XY *)&g_7fd2, 0, 1);
                    fn_070c_07f5(s, 20, -1, 0, 2);
                }
            break;
        default:
            return 0;
        }
    }
    if (m->c25 != -1) m->c25--;
    m->c27 = fn_1aff_0420(8, m->type->st.atk->w8);
    return 1;
}

/* NONMATCHING */
void fn_0d6c_189f(struct Monster far *m)
{
    register int f;

    if (m->mode > 14) return;
    f = g_2483[m->mode];
    if (m->c1f++ < m->type->c3c && !(f & 4)) return;
    m->c1f = 0;
    if (m->type->flags & 0x40) {
        m->hp += fn_0845_0636(1, 8);
        if (m->hp > m->type->maxHp) m->hp = m->type->maxHp;
    }
    if (m->flags & 8) {
        m->tx = g_7fd2;
        m->ty = g_7fd4;
    }
    if (((f & 2) && fn_0d6c_0109(m)) || ((f & 1) && (m->flags & 0x10))) fn_0d6c_0995(m, 7);
    if (m->mode != 11 && m->mode != 14 && !(fn_2313_0000() & 3)) {
        m->c0b = (m->c0b + 1) & 0xf;
        fn_0845_046c(m->block);
    }
    switch (m->mode) {
    case 12:
        m->c15++;
        fn_0845_046c(m->block);
        if (m->c15 > 13) fn_0845_1343(0x404, -1, m->id, m->id, 0, 0);
        break;
    case 0:
    case 1:
        fn_0d6c_12fc(m);
        break;
    case 2:
        fn_0d6c_129f(m);
        break;
    case 3:
        fn_0d6c_13c5(m);
        break;
    case 4:
        fn_0d6c_1419(m);
        break;
    case 5:
        g_20d3 = 1;
        if (--m->c15 > 0 && ((int (*)(struct XY, int, int))fn_0845_04af)(*(struct XY *)&g_7fd2, m->x, m->y) <= 0x100) {
            if (!(m->flags & 8)) {
                fn_0d6c_1050(m);
                break;
            }
        }
        goto seven;
    case 6:
        if (--m->c15 > 0) break;
    seven:
        fn_0d6c_0995(m, 7);
        break;
    case 7:
        if (!fn_0d6c_1630(m)) fn_0d6c_1183(m);
        goto redraw;
    case 8:
        if (++m->c15 > 2) {
            fn_0d6c_0995(m, 5);
            m->c15 = fn_1aff_0434(8, m->type->st.atk->w8);
            m->c15 = fn_1aff_0420(m->c15, f_2803_0038[fn_0845_1036()]);
        }
    redraw:
        fn_0845_046c(m->block);
        break;
    case 9:
        if (--m->c15 == 0) {
            fn_0d6c_0995(m, 7);
            m->flags &= ~8;
        } else
            fn_0d6c_1183(m);
        break;
    case 13:
        fn_0d6c_1354(m);
        break;
    case 14:
        m->hitDmg = 0;
        return;
    }
    if (m->hitDmg) {
        if (m->hitDmg & 0x8000)
            m->hitDmg &= 0x7fff;
        else
            m->hitDmg = 0;
        fn_0845_046c(m->block);
    }
    m->flags &= ~0x10;
}
