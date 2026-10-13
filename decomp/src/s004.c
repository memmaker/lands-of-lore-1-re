/* s004: combat (hit chance, damage, experience, nearest targets) */
#include "lol.h"

extern char g_7fe3;
extern int g_7fd0, g_7fd2, g_7fd4, g_7fdf;
extern int g_20d1;
extern int far f_2803_0032[];
extern int far f_2803_003e[];

int fn_1aff_0420(int a, int b);
int fn_1aff_0434(int a, int b);
int fn_1aff_03fd(int a, int b);
void fn_1aff_03b4(int far *x, int far *y, int a);
void fn_0a21_022b(int who);
int ovr_2cf4_0025(int who, int cls);
int fn_0845_1036(void);
int ovr_2d74_0025(void);
int fn_09aa_0183(int pos, int dir);
int fn_0845_0636(int lo, int hi);
void fn_0d6c_0995(struct Monster far *m, int mode);
void fn_0d6c_0034(struct Monster far *m);
void fn_0845_046c(int block);
int ovr_2d1b_005c(int block);
void fn_0d6c_0742(struct Monster far *m, int a, int b);
void fn_0bbc_0365(struct Char far *c, int a, int b);
void fn_067a_0401(int n, int force);
void fn_0a21_0674(int who, int a, int b, int c);
void fn_0845_08a5(char far *fmt, int a, int b, int c, ...);
void fn_0d6c_0d2a(struct Monster far *m, int src, int e, int k, int dmg);
void fn_067a_027f(int n, int pos);
int fn_0a21_0997(int who, int item);
void fn_0a21_06fd(int who, int a, int d, int b);
void fn_0bbc_0744(int who, int a, int b, int c);

struct Stats far *fn_070c_01b6(int who);
int fn_070c_027a(int block, int a);
void fn_070c_0664(int who, int how);
int fn_070c_06a3(int att, int def, int base, int type, int mode);
void fn_070c_00cf(int who, int cls, long exp);

unsigned char g_1f16[3][4] = { { 0x80 }, { 0x40, 0xc0 }, { 0x40, 0x80, 0xc0 } }   /* x of each member by party size */;

/* NONMATCHING */
int fn_070c_000a(int who)
{
    if (!(who & 0x8000))
        return fn_1aff_0420(fn_1aff_0420(f_2803_362d[who].w37 + f_2803_362d[who].w4c,
                                         f_2803_362d[who].st.atk->w4), f_2803_362d[who].w48);
    who &= 0x7fff;
    return fn_1aff_0420(f_2803_15fa[who].type->w38, f_2803_15fa[who].type->st.atk->dmgMul);
}

void fn_070c_009f(int v)
{
    int old;
    if (g_7fe3 != v) {
        old = g_7fe3;
        g_7fe3 = v;
        fn_0a21_022b(old);
    }
    fn_0a21_022b(v);
}

void fn_070c_00cf(int who, int cls, long exp)
{
    int r;
    if (who & 0x8000) return;
    if (f_2803_362d[who].flags & 8) return;
    f_2803_362d[who].exp[cls] += exp;
    do r = ovr_2cf4_0025(who, cls); while (r);
}

int fn_070c_012a(int who, int dmg)
{
    struct Stats far *s;
    int v;

    s = fn_070c_01b6(who);
    v = fn_1aff_0434(dmg, s->atk->w8);
    if (!(who & 0x8000)) v = fn_1aff_0420(v, f_2803_0032[fn_0845_1036()]);
    if (f_2803_362d[who].skill[1] > 7)
        v -= v >> 1;
    else if (f_2803_362d[who].skill[1] > 3)
        v -= v >> 2;
    return v;
}

struct Stats far *fn_070c_01b6(int who)
{
    struct Stats far *p;
    if (who & 0x8000)
        p = &f_2803_15fa[who & 0x7fff].type->st;
    else
        p = &f_2803_362d[who].st;
    return p;
}

void fn_070c_0201(int sub, int far *x, int far *y)
{
    *x = g_1f16[0][(ovr_2d74_0025() << 2) + sub - 4];   /* g_1f16[count - 1][sub] */
    *y = 0x80;
    fn_1aff_03b4(x, y, g_7fdf);
    *x |= g_7fd2 & 0xff00;
    *y |= g_7fd4 & 0xff00;
}

int fn_070c_0253(int a)
{
    int b;
    b = fn_09aa_0183(g_7fd0, g_7fdf);
    return fn_070c_027a(b, a);
}

int fn_070c_027a(int block, int a)
{
    struct Monster far *m;
    int x, y;
    int best, res, cur, d;

    fn_070c_0201(a, &x, &y);
    cur = g_8203[block].mon;
    best = 0x7fff;
    res = -1;
    while (cur & 0x8000) {
        m = &f_2803_15fa[cur & 0x7fff];
        if (m->mode < 13) {
            d = ABS(x - m->x) + ABS(y - m->y);
            if (d < best) {
                best = d;
                res = cur;
            }
        }
        cur = m->next;
    }
    return res;
}


int fn_070c_0322(int x, int y)
{
    struct Monster far *m;
    int best, res;
    int i, d;

    best = 0x7fff;
    res = -1;
    m = f_2803_15fa;
    for (i = 0; i < 30; i++, m++) {
        if (m->mode >= 13) continue;
        d = ABS(x - m->x) + ABS(y - m->y);
        if (d < best) {
            best = d;
            res = i | 0x8000;
        }
    }
    return res;
}


int fn_070c_03b1(int x, int y)
{
    int best, res;
    int px, py;
    int i, d;

    best = 0x7fff;
    res = -1;
    i = 0;
    do {
        if ((f_2803_362d[i].flags & 1) && f_2803_362d[i].hp > 0) {
            fn_070c_0201(i, &px, &py);
            d = ABS(px - x) + ABS(py - y);
            if (d < best) {
                best = d;
                res = i;
            }
        }
        i++;
    } while (i < 4);
    return res;
}

/* NONMATCHING */
int fn_070c_044a(int att, int def, int k)
{
    struct Stats far *pa;
    struct Stats far *pd;
    int r, d, e;
    int chance;

    if (def == -1) return 0;
    if (att == -1) return 1;
    if ((def & 0x8000) && f_2803_15fa[def & 0x7fff].mode >= 13) return 0;
    if (att & 0x8000) {
        pa = &f_2803_15fa[att & 0x7fff].type->st;
        chance = 100 - f_2803_15fa[att & 0x7fff].type->evade;
    } else {
        pa = &f_2803_362d[att].st;
        if (k == 1)
            chance = 100 - (f_2803_362d[att].skill[k] + f_2803_362d[att].skillBonus[k] * 3);
        else
            chance = 100 - (f_2803_362d[att].skill[k] + f_2803_362d[att].skillBonus[k]);
    }
    if (def & 0x8000) {
        pd = &f_2803_15fa[def & 0x7fff].type->st;
        f_2803_15fa[def & 0x7fff].flags |= 0x10;
    } else
        pd = &f_2803_362d[def].st;
    r = fn_0845_0636(1, 100);
    if (r >= chance) return 2;
    e = fn_1aff_0420(pd->atk->defense, f_2803_003e[fn_0845_1036()]);
    d = fn_1aff_0434(e, pa->atk->hit);
    if (r < d) return 0;
    return 1;
}

void fn_070c_05fa(struct Monster far *m)
{
    fn_0d6c_0995(m, 14);
    fn_0d6c_0034(m);
    fn_0845_046c(m->block);
    if (ovr_2d1b_005c(m->block) && !(m->type->flags & 0x1000))
        g_8203[m->block].flags |= 0x80;
    fn_0d6c_0742(m, 0, 0);
}

void fn_070c_0664(int who, int how)
{
    struct Char far *c;
    c = &f_2803_362d[who];
    c->hp = 0;
    c->flags |= 8;
    fn_0bbc_0365(c, 1, 5);
    g_20d1 = how;
}

/* NONMATCHING */
int fn_070c_06a3(int att, int def, int base, int type, int mode)
{
    struct Stats far *pa;
    struct Stats far *pd;
    int v, t;

    if (att != -1) {
        pa = fn_070c_01b6(att);
        v = pa->atk->dmgMul;
    } else
        v = 0x100;
    pd = fn_070c_01b6(def);
    if (!(v = fn_1aff_0420(base, v))) return 0;
    if (!(att & 0x8000)) {
        if (!(v = fn_1aff_0420(v, f_2803_362d[att].w46))) return 0;
    }
    v = fn_1aff_03fd(v, (type & 0x80) ? pd->w22 : pd->res[type]);
    if (mode != 2 && v) {
        t = (fn_070c_000a(def) << 7) / v;
        v = fn_1aff_03fd(v, 0x100 - (t > 0xd9 ? 0xd9 : t));
        if (v < 2) v = 2;
    }
    if (v == 1) v = 2;
    return v;
}


int fn_070c_0793(int who, int def, int mode)
{
    struct Stats far *p;
    int sum;
    int i;

    p = fn_070c_01b6(who);
    if (who & 0x8000) ;
    for (sum = i = 0; i < 8; i++)
        sum += fn_070c_06a3(who, def, p->dmg[i], i, mode);
    return sum;
}

int fn_070c_07e3(int n)
{
    return fn_0845_0636(2, n);
}

/* NONMATCHING */
int fn_070c_07f5(int who, int dmg, int src, int k, int how)
{
    struct Monster far *m;
    struct Char far *c;

    m = 0;
    c = 0;
    if (who & 0x8000) {
        m = &f_2803_15fa[who & 0x7fff];
        if (m->mode >= 13) return 0;
    } else {
        c = &f_2803_362d[who];
        if (!(c->flags & 1)) return 0;
        if (c->flags & 8) return 0;
        if (!(c->flags & 0x1000)) fn_067a_0401(c->voice, 0);
        fn_0a21_0674(who, 6, 4, 0);
        fn_0845_08a5("Damage inflicted was %d", 0x28, 0x12, 1, dmg);
    }
    if (who & 0x8000) {
        if (dmg > 0) {
            m->hp -= dmg;
            m->hitDmg = dmg | 0x8000;
            m->flags |= 0x10;
            m->dx = fn_0845_0636(1, 0x18) - 12;
            m->dy = fn_0845_0636(1, 0x18) - 12;
            m->hp = m->hp < m->type->maxHp ? m->hp : m->type->maxHp;
            m->hp = m->hp > 0 ? m->hp : 0;
            if (!(src & 0x8000)) fn_0d6c_0d2a(m, src, how, k, dmg);
            fn_067a_027f(m->type->sound, m->block);
            fn_0845_046c(m->block);
            if (m->hp <= 0) {
                m->hp = 0;
                if (!(src & 0x8000)) fn_070c_00cf(src, k, m->type->maxHp);
                fn_0d6c_0995(m, 13);
            }
        } else {
            m->hp -= dmg;
            dmg = 0;
            m->hp = m->hp < m->type->maxHp ? m->hp : m->type->maxHp;
            m->hp = m->hp > 1 ? m->hp : 1;
        }
    } else {
        if (how == 4 && fn_0a21_0997(who, 0xe5)) dmg >>= 2;
        fn_0a21_06fd(who, 0, -dmg, 1);
        if (c->hp <= 0)
            fn_070c_0664(who, how);
        else {
            c->lastDmg = dmg;
            fn_0bbc_0744(who, 2, 4, 1);
        }
        fn_0a21_022b(who);
    }
    if (!(src & 0x8000)) {
        if (!k) f_2803_362d[src].dmgDealt += dmg;
        fn_070c_00cf(src, k, dmg);
    }
    return dmg;
}

void fn_070c_0a8f(int who, int amt, int force)
{
    struct Char far *c;
    c = &f_2803_362d[who];
    if (c->hp > 0 || force) {
        if (amt < 1) amt = 1;
        c->hp += amt;
        c->hp = c->hp < c->maxHp ? c->hp : c->maxHp;
        c->hp = c->hp > 1 ? c->hp : 1;
        if (c->hp && (c->flags & 8)) c->flags &= ~8;
    }
}
