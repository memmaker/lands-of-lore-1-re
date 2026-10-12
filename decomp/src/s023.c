/* s023: character speech (voice index lookup and playback) */
#include "lol.h"

struct VocEnt {             /* 8 bytes: voice index entry */
    unsigned id;
    char voice;
    char more;              /* nonzero: continuation of the previous entry */
    long off;
};

extern void far *g_abbe;
extern long g_abca;
extern char far *g_abc2;
extern char far *g_abc6;
extern unsigned long g_abac;
extern struct VocEnt g_abb0;
extern int g_aba4;
extern char g_aba6, g_aba7;
extern int g_abb8;
extern unsigned long g_2138, g_384c;
extern long g_213c;
extern char g_7fe3, g_81fe, g_81ff;
extern int g_4bf8, g_4bfa, g_4c00, g_20f6;

int fn_16cf_057a(void far *p);
void fn_16cf_00b9(void far *p);
int fn_16cf_022f(void);
int fn_16cf_0022(void far *p, int pan, int vol);
void fn_2279_025b(void far *s, void far *d, long n);
void far *fn_2037_0002(void far *p, long off);
void far *fn_242d_000f(void far *key, void far *tmp, void far *base, int n, int w, int (far *cmp)());
void fn_1809_0e76(int h, long off, int whence);
int ovr_2dc6_0020(int h);
long ovr_2dc6_0025(long size, int a);
long ovr_2dc6_002f(int h, long size, void far *buf, long len);
void fn_0845_093a(void);
void fn_130a_0784(void);
void fn_130a_0605(void);

int fn_154c_01d3(unsigned id, int ch, int flag);
int fn_154c_029f(void far *buf, long len, unsigned id, int ch, int x);
int far fn_154c_03fc(struct VocEnt far *a, struct VocEnt far *b);
unsigned fn_154c_040d(struct VocEnt far *e, unsigned id, int ch);
char fn_154c_057b(int ch);

int g_2862 = -1;
int g_2864 = -1;

void fn_154c_000f(int flag)
{
    if (fn_16cf_057a(g_abbe) > -1) {
        g_aba4 = 0;
        g_abac = 0;
        g_2138 = 0;
        fn_16cf_00b9(g_abbe);
        if (flag) g_abb8 = 1;
    }
}

int fn_154c_0057(unsigned id, int ch, int flag)
{
    int i;
    int r;

    if (ch == 1) ch = g_7fe3 != 0 ? g_7fe3 : 0;
    else if (ch < 0) ch = 0;
    else if (ch) {
        for (i = 0; i < 4; i++) {
            if (f_2803_362d[i].wE == ch && (f_2803_362d[i].flags & 1)) {
                ch = i;
                break;
            }
        }
        if (i == 4) return 0;
    }
    r = fn_154c_01d3(id, ch, 0);
    if (r && flag) {
        fn_130a_0784();
        g_4bf8 = ch;
        g_4bfa = 0;
        g_4c00 = 1;
        g_20f6 = 0;
        fn_130a_0605();
    }
    return !(r && !g_81fe) ? 1 : 0;
}

int fn_154c_010f(int id, int ch)
{
    if (id && ch) {
        g_aba4 = id + 1000;
        g_aba6 = ch;
        g_aba7 = 0;
    }
    return 1;
}

int fn_154c_0136(void)
{
    unsigned long t;
    int r;

    if (fn_16cf_057a(g_abbe) != -1) return 2;
    t = g_384c;
    r = 0;
    g_2862 = g_2864 = -1;
    if (g_abac) r = fn_154c_01d3(g_abb0.id, g_abb0.voice, g_abb0.more);
    if (!r && g_aba4) {
        r = fn_154c_01d3(g_aba4, g_aba6, g_aba7);
        g_aba4 = 0;
    }
    if (r) {
        g_213c = g_384c - t;
        return 2;
    }
    return fn_16cf_022f() ? 1 : 0;
}

int fn_154c_01d3(unsigned id, int ch, int flag)
{
    void far *buf;
    int r;

    ch = fn_154c_057b(ch);
    if (g_2862 == id && g_2864 == ch) return 1;
    if (((id & 0x4000) ? g_abc6 : g_abc2) == 0 || !g_81ff) return 0;
    while (fn_16cf_022f() && fn_16cf_057a(g_abbe) != -1) fn_0845_093a();
    r = fn_154c_029f(g_abbe, g_abca, id, ch, flag);
    buf = g_abbe;
    if (r) {
        g_2862 = id;
        g_2864 = ch;
        r = fn_16cf_0022(buf, 0xff, g_81ff * 200 / 100 + 0x37);
        g_abb8 = 0;
    }
    return r;
}

int fn_154c_029f(void far *buf, long len, unsigned id, int ch, int x)
{
    struct VocEnt e2;
    struct VocEnt e;
    int h[2];
    long size;
    unsigned n;

    if (buf && len) {
        if (g_abac) {
            n = g_abac;
            fn_2279_025b(&g_abb0, &e, 8);
        } else {
            n = fn_154c_040d(&e, id, ch);
            if (!n) {
                g_abac = 0;
                return 0;
            }
        }
        g_abac = (unsigned long)n + 8;
        fn_2279_025b(fn_2037_0002((id & 0x4000) ? g_abc6 : g_abc2, g_abac), &e2, 8);
        if (e2.id == e.id && e2.voice == e.voice) fn_2279_025b(&e2, &g_abb0, 8);
        else g_abac = 0;
        size = e2.off - e.off;
        fn_2279_025b((id & 0x4000) ? g_abc6 : g_abc2, h, 4);
        fn_1809_0e76(h[0], e.off, 0);
        size = ovr_2dc6_0025(size, ovr_2dc6_0020(h[0]));
        if (ovr_2dc6_002f(h[0], size, buf, len)) return 1;
    }
    return 0;
}

int far fn_154c_03fc(struct VocEnt far *a, struct VocEnt far *b)
{
    return a->id - b->id;
}

unsigned fn_154c_040d(struct VocEnt far *e, unsigned id, int ch)
{
    int hdr[2];
    char far *base;
    long step;
    char tmp[8];
    char far *p;
    char far *idx;

    idx = (id & 0x4000) ? g_abc6 : g_abc2;
    fn_2279_025b(idx, hdr, 4);
    base = fn_2037_0002(idx, 4);
    e->id = id;
    p = fn_242d_000f(e, tmp, fn_2037_0002(base, 8), hdr[1] - 2, 8, fn_154c_03fc);
    if (p == 0) {
    fail:
        fn_2279_025b(base, e, 8);
        return 0;
    }
    fn_2279_025b(p, e, 8);
    if (e->voice != '_') {
        step = 8;
        if (e->voice > ch) step = -step;
        while (e->voice != ch && e->id == id) {
            p = fn_2037_0002(p, step);
            fn_2279_025b(p, e, 8);
            if (e->voice == '0') goto fail;
        }
    }
    while (e->more) {
        p = fn_2037_0002(p, -8);
        fn_2279_025b(p, e, 8);
    }
    return (unsigned)p - (unsigned)idx;
}

char fn_154c_057b(int ch)
{
    if (ch >= 0x41) return ch;
    if (!(f_2803_362d[ch].flags & 1)) return 0;
    return f_2803_362d[ch].name[0];
}
