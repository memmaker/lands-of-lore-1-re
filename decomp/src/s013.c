/* s013: game timers (scheduler table), character status timers, mana/hit point regeneration, blinking, compass */
#include "lol.h"

struct Timer {              /* 0x13 bytes */
    void (far *fn)(int arg);
    long interval;           /* +04 */
    unsigned long next;      /* +08 */
    int arg;                 /* +0c */
    unsigned long far *clock;/* +0e */
    char enabled;            /* +12 */
};
struct Door { int block; char dir; char delta; };

extern char far f_2803_0000[];
extern void far * far f_2803_00a6[];
extern struct Door g_4ed0[];
extern struct Fly g_4dcc[];
extern unsigned char g_531e[];
extern unsigned long g_3858, g_384c;
extern unsigned char far *g_adea;
extern unsigned g_7fd6, g_806a;
extern int g_206b, g_20d5, g_3649;
extern char g_7fde, g_81dc, g_81de;
extern unsigned char g_81dd;

void fn_0d6c_189f(struct Monster far *m);
int fn_0845_046c(int b);
void fn_067a_02f5(int n, int pos);
void fn_067a_026b(int n);
int fn_070c_012a(int who, int dmg);
void fn_0a21_022b(int ch);
int fn_0845_0636(int n, int sides);
int fn_070c_07f5(int who, int dmg, int src, int k, int how);
char far *fn_0845_06f8(int id);
void fn_0845_01c4(unsigned flags, char far *fmt, ...);
void fn_0a21_0674(int ch, int f, int snd, int redraw);
void ovr_2d1b_0043(void);
void fn_0b6b_0472(struct Fly far *f);
void fn_0845_08a5(char far *fmt, ...);
void fn_0845_13d6(int b, unsigned mask);
int fn_0a21_0997(int ch, int type);
void fn_070c_0a8f(int who, int amt, int force);
int fn_0845_11b7(void);
int fn_231c_008a(int n);
void fn_0845_035b(unsigned char far *src, int lvl, int idx);
void fn_1ebc_0111(int x1, int y1, int x2, int y2);
void fn_1ebc_01ec(void);
void far *fn_0845_04ec(void far *name);
void fn_1fd6_000a(int page, void far *p, int x, int y, int a, int flags, ...);
void fn_0845_114d(int id, int flag);


void fn_0bbc_004a(int arg);
void fn_0bbc_000a(int n);
void fn_0bbc_0143(int arg);
void fn_0bbc_040b(int arg);
void fn_0bbc_0472(int n);
void fn_0bbc_0488(int arg);
void fn_0bbc_058a(int arg);
void fn_0bbc_061e(int arg);
void fn_0bbc_094b(int arg);
void fn_0bbc_06d1(int n, int arg, int en);
void fn_0bbc_070e(int n, int en);

struct Timer g_2298[12] = {
    { fn_0bbc_004a, 15, 0, 0, &g_3858, 1 },
    { fn_0bbc_000a, 6, 0, 0, &g_3858, 1 },
    { fn_0bbc_000a, 6, 3, 1, &g_3858, 1 },
    { fn_0bbc_0143, 15, 0, 0, &g_3858, 1 },
    { fn_0bbc_040b, 1, 0, 0, &g_3858, 1 },
    { fn_0bbc_0472, 0, 0, 0, &g_3858, 0 },
    { fn_0bbc_0472, 0, 0, 1, &g_3858, 0 },
    { fn_0bbc_0472, 0, 0, 2, &g_3858, 0 },
    { fn_0bbc_0488, 1200, 0, 0, &g_3858, 1 },
    { fn_0bbc_058a, 10, 0, 0, &g_3858, 1 },
    { fn_0bbc_061e, 360, 0, 0, &g_3858, 1 },
    { fn_0bbc_094b, 360, 0, 0, &g_384c, 0 },
};
int g_237c = 12;
unsigned long g_237e = 0x0fffffffL;

void fn_0bbc_000a(int n)
{
    struct Monster far *m;
    register int i;

    if (g_206b)
        for (m = &f_2803_15fa[n], i = n; i < 30; i += 2, m += 2) fn_0d6c_189f(m);
}

void fn_0bbc_004a(int arg)
{
    unsigned fl;
    int d;
    int snd;
    int dir;
    register int i;
    register int b;

    for (i = 0; i < 3; i++) {
        b = g_4ed0[i].block;
        if (!b) continue;
        d = g_4ed0[i].delta;
        dir = g_4ed0[i].dir;
        WALL(b, dir) += d;
        WALL(b, dir ^ 2) += d;
        fl = g_531e[WALL(b, dir)];
        if (fl & 0x20)
            snd = 0x21;
        else
            snd = d == -1 ? 0x20 : 0x1f;
        if (!(g_7fd6 & 1)) {
            if (fn_0845_046c(b))
                fn_067a_02f5(snd, b);
            else {
                fn_067a_02f5(snd, b);
                fn_067a_026b(0);
            }
        }
        if (fl & 0x30) g_4ed0[i].block = 0;
    }
}

void fn_0bbc_0143(int arg)
{
    struct Char far *c;
    int max;
    register int k;
    register int ch;

    c = f_2803_362d;
    for (max = ch = 0; ch < 4; ch++, c++) {
        if (!(c->flags & 1)) continue;
        for (k = 0; k < 5; k++) {
            if (!c->timerType[k]) continue;
            if (--c->timer[k] > 0) {
                if (c->timer[k] > max) max = c->timer[k];
                continue;
            }
            switch (c->timerType[k]) {
            case 1:
                if (c->dmgDealt) {
                    c->dmgDealt = 0;
                    c->timer[k] = fn_070c_012a(ch, 6);
                    if (c->timer[k] > max) max = c->timer[k];
                } else
                    goto clr;
            redraw:
                fn_0a21_022b(ch);
                break;
            clr:
                c->flags &= ~4;
                goto redraw;
            case 2:
                c->lastDmg = 0;
                fn_0a21_022b(ch);
                break;
            case 3:
                c->flags &= ~0x40;
                fn_0a21_022b(ch);
                break;
            case 4:
                max = fn_0845_0636(1, 2);
                if (fn_070c_07f5(ch, max, 0x8000, 0, 0x80)) {
                    fn_0845_01c4(2, fn_0845_06f8(0x4022), c->name);
                    c->timer[k] = 10;
                    if (c->timer[k] > max) max = c->timer[k];
                }
                break;
            case 5:
                c->flags &= ~0x100;
                fn_0845_01c4(0, fn_0845_06f8(0x4027), c->name);
                fn_0a21_022b(ch);
                break;
            case 6:
                fn_0a21_0674(ch, 0, 0, 1);
                break;
            case 7:
                c->flags &= ~0x1000;
                fn_0a21_022b(ch);
                break;
            case 8:
                ovr_2d1b_0043();
                break;
            }
            if (c->timer[k] <= 0) c->timerType[k] = 0;
        }
    }
    if (max)
        fn_0bbc_06d1(3, max * 15, 1);
    else
        fn_0bbc_070e(3, 0);
}

void fn_0bbc_0365(struct Char far *c, int from, int to)
{
    int i;
    int k;

    for (i = from; i <= to; i++) {
        switch (i) {
        case 1:
            c->flags &= ~4;
            c->dmgDealt = 0;
            break;
        case 2:
            c->lastDmg = 0;
            break;
        case 3:
            c->flags &= ~0x40;
            break;
        case 4:
            c->flags &= ~0x80;
            break;
        case 5:
            c->flags &= ~0x100;
            break;
        case 7:
            c->flags &= ~0x1000;
            break;
        }
        for (k = 0; k < 5; k++)
            if (c->timerType[k] == i) {
                c->timerType[k] = 0;
                c->timer[k] = 0;
            }
    }
    fn_0bbc_06d1(3, 1, 1);
}

void fn_0bbc_040b(int arg)
{
    struct Fly far *f;
    register int i;

    for (i = 0, f = g_4dcc; i < 8; i++, f++)
        if (f->active) {
            fn_0b6b_0472(f);
            fn_0845_08a5("%d:      idx: %-5d      x: %-4X      y: %-4X", 0, i + 12, 0, i, g_4dcc[i].item,
                         g_4dcc[i].x, g_4dcc[i].y);
        }
}

void fn_0bbc_0472(int n)
{
    fn_0845_13d6(n + 0x401, -1);
}

void fn_0bbc_0488(int arg)
{
    struct Char far *c;
    int hp;
    register int ch;
    register int mp;

    c = f_2803_362d;
    for (ch = 0; ch < 4; ch++, c++) {
        if (!(c->flags & 1)) continue;
        hp = c->flags & 8 ? 0 : 1;
        mp = c->flags & 8 ? 0 : 1;
        if (mp && fn_0a21_0997(ch, 0xe3)) mp = c->maxMp / 10;
        if (hp && fn_0a21_0997(ch, 0xe4)) hp = 4;
        c->mp += g_7fde ? -(c->maxMp >> 5) : mp;
        c->mp = c->mp > 0 ? c->mp : 0;
        c->mp = c->mp < c->maxMp ? c->mp : c->maxMp;
        if (!(c->flags & 0x80)) fn_070c_0a8f(ch, hp, 0);
        fn_0a21_022b(ch);
    }
}

/* NONMATCHING */
void fn_0bbc_058a(int arg)
{
    struct Char far *c;
    register int ch;

    c = f_2803_362d;
    for (ch = 0; ch < 4; ch++, c++) {
        if ((c->flags & 1) && !(c->flags & 8) && c->face <= 1) {
            if (c->face == 1) {
                c->face = 0;
                fn_0a21_022b(ch);
                c->w4e = fn_0845_0636(1, 12) + 6;
            } else if (--c->w4e <= 0 && !arg) {
                c->face = 1;
                fn_0a21_022b(ch);
                fn_0bbc_06d1(9, 0, 1);
            }
        }
    }
}

void fn_0bbc_061e(int arg)
{
    if ((g_806a & 0x800) && (g_806a & 0x400) && g_81dc && g_81dd) g_81dd--;
}

void fn_0bbc_0645(void)
{
    struct Timer far *t;
    register int i;

    for (i = 0, t = g_2298; i < g_237c; i++, t++) {
        fn_0845_11b7();
        if (t->enabled && t->next < *t->clock) {
            if (fn_231c_008a(2) || t->clock != &g_3858) {
                t->fn(t->arg);
                if (t->enabled) t->next = *t->clock + t->interval;
            }
        }
    }
}

void fn_0bbc_06d1(int n, int arg, int en)
{
    struct Timer far *t;

    t = &g_2298[n];
    t->enabled = en;
    t->next = *t->clock + t->interval;
    t->arg = arg;
}

void fn_0bbc_070e(int n, int en)
{
    struct Timer far *t;

    t = &g_2298[n];
    t->enabled = en;
    t->next = *t->clock + t->interval;
}

void fn_0bbc_0744(int ch, int type, char time, int replace)
{
    struct Char far *c;
    int i;

    c = &f_2803_362d[ch];
    for (i = 0; i < 5; i++)
        if (c->timerType[i] == 0 || (replace && c->timerType[i] == type)) {
            c->timerType[i] = type;
            c->timer[i] = time;
            g_2298[3].next = *g_2298[3].clock;
            g_2298[3].enabled = 1;
            break;
        }
}

void fn_0bbc_07b1(int n, int interval)
{
    struct Timer far *t;

    t = &g_2298[n];
    t->enabled = 1;
    t->interval = interval;
    t->next = *t->clock + t->interval;
}

void fn_0bbc_07ef(void)
{
    int frame;
    int v;

    if (g_7fd6 & 4) return;
    if (!(g_806a & 0x800)) return;
    if (!g_81dc || !g_81dd) {
        frame = 8;
        if (g_81de != frame && !g_20d5) fn_0845_035b(g_adea, g_81dc, frame);
    } else {
        v = g_81dd < 100 ? g_81dd : 100;
        frame = (3 - (v - 1) / 25) * 2;
        if (g_81de != -1) {
            if ((g_81de & ~1) == (frame & ~1)) {
                if (g_384c > g_237e) {
                    frame = g_81de ^ 1;
                    goto reset;
                }
                frame = g_81de;
            } else if (!g_20d5)
                fn_0845_035b(g_adea, g_81dc, frame);
        } else {
            if (!g_20d5) fn_0845_035b(g_adea, g_81dc, frame);
        reset:
            g_237e = g_384c + fn_0845_0636(1, 30) + 10;
        }
    }
    if (g_81de != frame) {
        fn_1ebc_0111(0x123, 0x38, 0x140, 0x50);
        fn_1fd6_000a(g_3649, fn_0845_04ec(f_2803_00a6[35 + frame]), 0x123, 0x38, 0, 0);
        fn_1ebc_01ec();
        g_81de = frame;
    }
}

void fn_0bbc_094b(int arg)
{
    g_2298[11].enabled = 0;
    fn_0845_114d(0, 0);
}

long fn_0bbc_0960(int n)
{
    long r;

    if (g_2298[n].enabled) {
        g_2298[n].enabled = 0;
        r = g_2298[n].next - *g_2298[n].clock;
        return r;
    }
    return -1;
}

void fn_0bbc_09a9(int n, long t)
{
    if (t != -1) {
        g_2298[n].enabled = 1;
        g_2298[n].next = *g_2298[n].clock + t;
    }
}
