/* o2d8a: spell casting (cost, dispatch to the spell handlers) */
#include "lol.h"

struct SpellDef {               /* 0x1c bytes, f_27dd_0010[] */
    int name;
    int mp[6];                  /* +02 */
    int hp[6];                  /* +0e */
    unsigned char fn;           /* +1a handler index */
    unsigned char flags;        /* +1b */
};
struct Spell {                  /* g_4d78 */
    int id;
    struct SpellDef far *def;   /* +02 */
    int caster;                 /* +06 */
    int level;                  /* +08 */
    int target;                 /* +0a */
};
struct Pick { char pad[0x38]; int c; };
extern struct Spell g_4d78;
extern struct SpellDef far f_27dd_0010[];
extern int (far *g_1424[])(struct Spell far *s);
extern int (far *g_1468[])(struct Spell far *s);
extern int g_4d82;
extern int g_7fd0, g_7fdf;
extern char g_7fe5;
extern char g_14ac[];
int fn_070c_06a3(int who, int m, int x, int y, int z);
void fn_070c_07f5(int m, int r, int who, int a, int y);
char far *fn_0845_06f8(int id);
void fn_0845_01c4(int kind, char far *fmt, ...);
int fn_0845_0cf7(int b, int d, int a);
int fn_09aa_0183(int a, int b);
void fn_0a21_022b(int c);
void fn_0a21_06fd(int c, int a, int v, int b);
void ovr_2ceb_0039(void);
void ovr_2ceb_0020(void);
int ovr_2d18_002a(int a, int b);
void ovr_2d83_0020(int a, int b);
void ovr_2d03_002a(int a, int b);
void ovr_2d4d_002a(int a, int b);
void ovr_2d1b_0039(int a, int b);
void ovr_2d99_002a(int a, int b);
void ovr_2d15_002a(int a);
void ovr_2d07_0025(void);
void ovr_2d28_002a(int a, int b);
void ovr_2d9d_0020(int a);
void ovr_2d12_002a(int a, int b);

void ovr_2d8a_0020(int m, int who, int x, int y, int z);
void ovr_2d8a_0025(int b, int a, int c, int d);
void ovr_2d8a_002a(void);
int ovr_2d8a_002f(void);
int ovr_2d8a_0034(struct Pick far *p);
int ovr_2d8a_0039(int caster, int id, int level);
int ovr_2d8a_003e(struct Spell far *s);
int ovr_2d8a_0043(struct Spell far *s);
int ovr_2d8a_0048(struct Spell far *s);
int ovr_2d8a_004d(struct Spell far *s);
int ovr_2d8a_0052(struct Spell far *s);
int ovr_2d8a_0057(struct Spell far *s);
int ovr_2d8a_005c(struct Spell far *s);
int ovr_2d8a_0061(struct Spell far *s);
int ovr_2d8a_0066(struct Spell far *s);
void ovr_2d8a_006b(struct Spell far *s);
int ovr_2d8a_0070(struct Spell far *s);
void ovr_2d8a_0075(struct Spell far *s);

void ovr_2d8a_0020(int m, int who, int x, int y, int z)
{
    int r;
    z = z ? 1 : 2;
    r = fn_070c_06a3(who, m, x, y, z);
    fn_070c_07f5(m, r, who, 2, y);
}

void ovr_2d8a_0025(int b, int a, int c, int d)
{
    register int m;
    register int i;
    int r;
    m = g_8203[b].mon;
    while (m & 0x8000) {
        r = fn_070c_06a3(a, m, c, d, 2);
        i = m & 0x7fff;
        m = f_2803_15fa[i].next;
        fn_070c_07f5(0x8000 | i, r, a, 2, d);
        if ((f_2803_15fa[i].flags & 0x20) && g_7fe5 != 0x16) break;
    }
}

void ovr_2d8a_002a(void)
{
    fn_0845_01c4(0, fn_0845_06f8(0x4040));
    ovr_2ceb_0039();
}

int ovr_2d8a_002f(void)
{
    struct Char far *c;
    c = &f_2803_362d[g_4d78.caster];
    fn_0845_01c4(0, fn_0845_06f8(0x4041));
    c->mp += g_4d78.def->mp[g_4d78.level];
    c->mp = c->mp < c->maxMp ? c->mp : c->maxMp;
    c->hp += g_4d78.def->hp[g_4d78.level];
    c->hp = c->hp < c->maxHp ? c->hp : c->maxHp;
    fn_0a21_022b(g_4d78.caster);
    ovr_2ceb_0020();
    return 1;
}

int ovr_2d8a_0034(struct Pick far *p)
{
    fn_0845_01c4(0, g_14ac, f_2803_362d[p->c].name);
    g_4d82 = p->c;
    if (g_1468[f_27dd_0010[g_4d78.id].fn])
        g_1468[f_27dd_0010[g_4d78.id].fn](&g_4d78);
    ovr_2ceb_0020();
    return 1;
}

int ovr_2d8a_003e(struct Spell far *s)
{
    if (s->level < 3) ovr_2d8a_002a();
    else ovr_2d18_002a(-1, s->level);
    return 1;
}

int ovr_2d8a_0043(struct Spell far *s)
{
    ovr_2d83_0020(s->level, s->caster);
    return 1;
}

int ovr_2d8a_0048(struct Spell far *s)
{
    ovr_2d03_002a(s->caster, s->level);
    return 1;
}

int ovr_2d8a_0057(struct Spell far *s)
{
    ovr_2d4d_002a(s->caster, s->level);
    return 1;
}

int ovr_2d8a_0070(struct Spell far *s)
{
    return ovr_2d18_002a(s->target, s->level);
}

int ovr_2d8a_004d(struct Spell far *s)
{
    ovr_2d1b_0039(s->caster, s->level);
    return 1;
}

int ovr_2d8a_0039(int caster, int id, int level)
{
    struct Spell far *s;
    s = &g_4d78;
    s->caster = caster;
    s->id = id;
    s->def = &f_27dd_0010[id];
    s->level = level < 0 ? -level : level;
    if ((f_27dd_0010[id].flags & 1) && fn_0845_0cf7(fn_09aa_0183(g_7fd0, g_7fdf), g_7fdf, 1)) {
        fn_0845_01c4(2, fn_0845_06f8(0x4257));
        return 0;
    }
    if (caster < 0) {
        s->caster = -caster - 1;
        return g_1424[id](s);
    }
    if (s->def->mp[level] <= f_2803_362d[caster].mp && s->def->hp[level] < f_2803_362d[caster].hp) {
        fn_0a21_06fd(caster, 1, -s->def->mp[level], 1);
        fn_0a21_06fd(caster, 0, -s->def->hp[level], 1);
        fn_0a21_022b(caster);
        if (g_1424[s->def->fn]) g_1424[s->def->fn](s);
    } else return 0;
    return 1;
}

int ovr_2d8a_0066(struct Spell far *s)
{
    ovr_2d99_002a(10, s->caster);
    return 1;
}

int ovr_2d8a_0052(struct Spell far *s)
{
    ovr_2d15_002a(s->level);
    return 1;
}

int ovr_2d8a_005c(struct Spell far *s)
{
    ovr_2d07_0025();
    return 1;
}

int ovr_2d8a_0061(struct Spell far *s)
{
    ovr_2d28_002a(s->level, s->caster);
    return 1;
}

void ovr_2d8a_006b(struct Spell far *s)
{
    ovr_2d9d_0020(s->caster);
}

void ovr_2d8a_0075(struct Spell far *s)
{
    ovr_2d12_002a(s->caster, s->level);
}
