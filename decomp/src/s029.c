/* s029: digital sound effects (up to 4 VOC-style sample channels mixed into the driver's DMA buffers) */
#include <mem.h>

struct Chan {               /* 0x28 bytes, g_2997[4] */
    void far *data;         /* +00 sample file */
    void far *cur;          /* +04 next block */
    long start;             /* +08 start time */
    unsigned long dur;      /* +0c */
    unsigned long pos;      /* +10 read position */
    unsigned long end;      /* +14 */
    int w18;
    int prio;               /* +1a */
    char c1c;
    unsigned char rate;     /* +1d VOC time constant */
    int ticks;              /* +1e */
    int vol;                /* +20 */
    int state;              /* +22 0 free, 1 done, 2 starting, 3 playing */
    char pad24[4];
};

struct Blk {                /* driver block descriptor */
    int a;
    int b;
    void far *buf;
    unsigned long size;
};

extern int g_20cd, g_20cf, g_3749;
extern unsigned long g_384c;
extern int g_292a, g_2950;
extern char far *g_2952;

int fn_16bf_00d6(int v);
void fn_1b79_0284(int h);
void fn_1b79_027f(int h);
unsigned fn_1b79_0367(int h);
void fn_1b79_0261(int h, int a, struct Blk *b);
void fn_0845_0f81(char far *fmt, ...);
void fn_2279_025b(void far *s, void far *d, unsigned long n);
void far *fn_2037_0002(void far *p, unsigned long off);
void fn_1bbe_050c(void far *p, int n, int vol);
void fn_1bbe_05bc(void far *p, int n);
void fn_1bbe_05e1(void far *s, void far *d, int n);

int fn_16cf_0022(void far *p, int prio, int vol);
int fn_16cf_00b9(void far *p);
int fn_16cf_022f(void);
int fn_16cf_05d0(char mode, int i, int n);
void far *fn_16cf_0a05(void far *p, unsigned long far *len, int far *type);
void far *fn_16cf_0a4b(void far *p, int i);
void far *fn_16cf_0a9b(void far *p, unsigned long far *len, int type);
int fn_16cf_0ae2(void far *p, int prio, int vol);

int g_297c = 0;
int g_297e = -1;
int g_2980 = 0;
int g_2982 = 0;
long g_2984 = 0;
long g_2988 = 0;
long g_298c = 0;
int g_2990 = 0;
int g_2992 = 2;
unsigned char g_2994 = 0xd3;
char g_2995[2] = { 0 };
struct Chan g_2997[4] = { 0 };
void far *g_2a37[5] = { 0 };
void far *g_2a4b = 0;
unsigned long g_2a4f[5] = { 0 };
char g_2a63[12] = { 0 };
int g_2a6f = 0;
void far *g_2a71 = 0;
void far * far *g_2a75 = 0;
char far *g_2a79 = 0;
int g_2a7d = 0;
char g_2a7f[9] = { 1, 6, 4, 7, 6, 4, 6, 4, 8 };

int fn_16cf_000b(void far *p)
{
    return fn_16cf_0022(p, 0xff, 0xff);
}

int fn_16cf_0022(void far *p, int prio, int vol)
{
    if ((g_20cd || g_20cf) && g_292a != -1 && vol) {
        vol = fn_16bf_00d6(vol);
        if (p == 0) prio = 0x100;
        else prio = prio < 0xff ? prio : 0xff;
        if (!fn_16cf_022f()) g_2950 = -1;
        if (!g_2990 || prio >= g_2950) {
            if (g_2990) fn_16cf_00b9(0);
            if (p) {
                g_2950 = prio;
                return fn_16cf_0ae2(p, prio, vol);
            }
        }
    }
    return 0;
}

int fn_16cf_00b9(void far *p)
{
    struct Chan far *c;
    int i;
    int r = 0;
    if (p) {
        i = 0;
        do {
            c = &g_2997[i];
            if (c->data == p && c->state) {
                c->state = 0;
                memset(g_2a37[i + 1], 0x80, g_2a4f[i + 1]);
                r = 1;
            }
            i++;
        } while (i < 4);
        return r;
    }
    if (fn_16cf_022f()) {
        g_2997[0].state = g_2997[1].state = g_2997[2].state = g_2997[3].state = 0;
        fn_1b79_0284(g_292a);
        g_2952[0xf] = 0;
        for (i = 1; i <= 4; i++) memset(g_2a37[i], 0x80, g_2a4f[i]);
        g_297e = -1;
        return 1;
    }
    return 0;
}

int fn_16cf_0181(int i)
{
    if (!g_2a6f || !g_2997[i].state) return 0;
    if (g_297e == -1) {
        fn_1b79_027f(g_292a);
        g_297e = i;
    }
    g_2997[i].start = g_384c;
    return 1;
}

int fn_16cf_01c8(int prio)
{
    int f = 0, i;
    if (g_2990) {
        if (!g_2997[0].state) f = 1;
        if (!f && g_2997[0].prio <= prio) f = 1;
    } else {
        for (i = 0; i < 4 && !f; i++) if (!g_2997[i].state) f = 1;
        for (i = 0; i < 4 && !f; i++) if (g_2997[i].prio <= prio) f = 1;
    }
    return f;
}

int fn_16cf_022f(void)
{
    int i;
    if (!g_2a6f || (!g_2997[0].state && !g_2997[1].state && !g_2997[2].state && !g_2997[3].state)) {
        if (g_297e != -1) {
            fn_1b79_0284(g_292a);
            g_2952[0xf] = 0;
            g_2997[0].state = g_2997[1].state = g_2997[2].state = g_2997[3].state = 0;
            for (i = 1; i <= 4; i++) memset(g_2a37[i], 0x80, g_2a4f[i]);
            g_297e = -1;
        }
        return 0;
    }
    return 1;
}

int fn_16cf_02b7(void)
{
    struct Chan far *c;
    struct Blk blk;
    int j, i;
    unsigned n;
    int pos;
    if (g_297c == 1) {
        fn_0845_0f81("REENTERED!!!!!!\r");
        return 0;
    }
    g_297c = 1;
    if (!g_2a6f || (!g_2997[0].state && !g_2997[1].state && !g_2997[2].state && !g_2997[3].state)) {
        if (g_297e != -1) {
            fn_1b79_0284(g_292a);
            g_2952[0xf] = 0;
            g_2997[0].state = g_2997[1].state = g_2997[2].state = g_2997[3].state = 0;
            for (j = 1; j <= 4; j++) memset(g_2a37[j], 0x80, g_2a4f[j]);
            g_297e = -1;
        }
        g_297c = 0;
        return 0;
    }
    i = 0;
    do {
        c = &g_2997[i];
        if (c->state && c->dur < g_384c - c->start && c->pos >= c->end) {
            int k;
            c->state = 0;
            k = i + 1;
            memset(g_2a37[k], 0x80, g_2a4f[k]);
        }
        i++;
    } while (i < 4);
    if (g_2997[0].state || g_2997[1].state || g_2997[2].state || g_2997[3].state) {
        if (g_3749 == 4) {
            pos = fn_1b79_0367(g_292a);
            n = (g_2a4f[0] - (unsigned)(pos + 1)) / g_2a4f[1] + 1;
            if (n >= g_2a7d) n = 0;
        } else {
            n = g_2952[0xf] + 1;
            if (n >= g_2a7d) n = 0;
            pos = 0;
        }
        if (g_2a79[n] == 0 || pos == -1) {
            if (pos == -1) {
                g_2984++;
                if (g_2984 - g_2988 > 1) {
                    fn_1b79_0284(g_292a);
                    g_2952[0xf] = 0;
                    blk.a = 0;
                    blk.b = g_2994;
                    blk.buf = g_2a4b;
                    blk.size = g_2a4f[0];
                    fn_1b79_0261(g_292a, 0, &blk);
                    fn_1b79_027f(g_292a);
                    g_298c++;
                }
            } else g_2988 = g_2984;
            fn_16cf_05d0(1, 0, n);
        }
    }
    g_297c = 0;
    return 1;
}

int fn_16cf_04db(void far *p)
{
    struct Chan far *c;
    int hdr[8];
    int r = -1, i, best;
    if (p) {
        i = 0;
        do {
            c = &g_2997[i];
            if (c->data == p && c->state) r = c->dur;
            i++;
        } while (i < 4);
        if (r != -1) return r;
        fn_2279_025b(p, hdr, 0x10L);
        return hdr[2];
    }
    best = -1;
    i = 0;
    do {
        c = &g_2997[i];
        if (c->state && r < c->dur) {
            r = c->dur;
            best = i;
        }
        i++;
    } while (i < 4);
    if (best != -1) return r;
    return 0;
}

#pragma option -O-b
int fn_16cf_057a(void far *p)
{
    struct Chan far *c;
    int i;
    if (p) {
        i = 0;
        do {
            c = &g_2997[i];
            if (c->data == p) {
                if (c->state) return c->pos / c->ticks;
                else break;
            }
            i++;
        } while (i < 4);
    }
    return -1;
}

#pragma option -Ob

#define NEXT_BLOCK(c, out) \
    while (c->cur) { \
        c->cur = fn_16cf_0a05(c->cur, &len, &type); \
        switch (type) { \
        case 0xd000: \
            ((unsigned char *)&len)[1] = 0xd3; \
            blk.a = ((unsigned char *)&len)[0]; \
            blk.b = g_2994; \
            g_2980 = c->ticks = 1000000L / (0x100 - (c->rate = ((unsigned char *)&len)[1])) / 60; \
            g_2982 = g_2992 * g_2980; \
            break; \
        case 0xf000: \
            goto out; \
        case 0: \
            c->cur = 0; \
            goto out; \
        } \
    } \
out:

/* NONMATCHING min(remain, chunk): the original stores without the "jnc; jmp" BCC emits for every spelling tried */
int fn_16cf_05d0(char mode, int i, int n)
{
    unsigned long remain;
    void far *src;
    void far *dst;
    int type;
    unsigned long len;
    struct Chan far *c;
    struct Blk blk;
    if (mode) {
        for (i = 0; i < 4; i++) {
            c = &g_2997[i];
            if (c->state) {
                NEXT_BLOCK(c, out1)
                dst = g_2a37[i + 1];
                if (c->pos >= c->end) {
                    c->state = 1;
                    memset(dst, 0x80, g_2a4f[1]);
                } else {
                    src = fn_2037_0002(c->data, c->pos);
                    blk.buf = g_2a4b;
                    blk.size = (remain = c->end - c->pos) < g_2a4f[1] ? remain : g_2a4f[1];
                    fn_2279_025b(src, dst, blk.size);
                    fn_1bbe_050c(dst, blk.size, c->vol);
                    if (blk.size < g_2a4f[1])
                        memset(fn_2037_0002(dst, blk.size), 0x80, g_2a4f[1] - blk.size);
                    c->pos += blk.size;
                    blk.size = g_2a4f[1];
                }
            }
        }
        fn_1bbe_05e1(g_2a37[1], g_2a75[n], g_2a4f[1]);
        g_2a79[n] = 1;
        if (++n >= g_2a7d) n = 0;
        g_2a79[n] = 0;
        memset(g_2a75[n], 0x80, g_2a4f[1]);
    } else if (g_297e == -1) {
        c = &g_2997[i];
        NEXT_BLOCK(c, out0)
        src = fn_2037_0002(c->data, c->pos);
        dst = g_2a37[0];
        blk.buf = g_2a4b;
        remain = c->end - c->pos;
        blk.size = remain >= g_2a4f[1] ? g_2a4f[1] : remain;
        fn_2279_025b(src, dst, blk.size);
        fn_1bbe_050c(dst, blk.size, c->vol);
        if (blk.size < g_2a4f[1])
            memset(fn_2037_0002(dst, blk.size), 0x80, g_2a4f[1] - blk.size);
        c->pos += blk.size;
        blk.size = g_2a4f[0];
        fn_1bbe_05bc(dst, g_2a4f[1]);
        if (c->pos >= c->end) c->state = 1;
        else c->state = 3;
        memset(g_2a75[1], 0x80, g_2a4f[1]);
        fn_1b79_0261(g_292a, 0, &blk);
        fn_16cf_0181(i);
        g_2a79[0] = 1;
        g_2a79[1] = 0;
    }
    return g_2997[0].state | g_2997[1].state | g_2997[2].state | g_2997[3].state;
}

void far *fn_16cf_0a05(void far *p, unsigned long far *len, int far *type)
{
    unsigned long h;
    fn_2279_025b(p, &h, 4L);
    *type = ((int *)&h)[1] & 0xf000;
    ((int *)&h)[1] ^= *type;
    *len = h;
    return (void far *)((unsigned long)p - 4);
}

void far *fn_16cf_0a4b(void far *p, int i)
{
    struct Chan far *c;
    unsigned long hdr[4];
    fn_2279_025b(p, hdr, 0x10L);
    c = &g_2997[i];
    c->dur = hdr[1];
    c->end = hdr[2];
    return fn_2037_0002(p, hdr[0]);
}

void far *fn_16cf_0a9b(void far *p, unsigned long far *len, int type)
{
    int t;
    do {
        p = fn_16cf_0a05(p, len, &t);
        if (t == 0) {
            *len = 0;
            return 0;
        }
    } while (t != type);
    return p;
}

int fn_16cf_0ae2(void far *p, int prio, int vol)
{
    unsigned long len;
    struct Chan far *c;
    int i, slot;
    if (!p || !g_2a6f) return 0;
    slot = -1;
    for (i = 0; i < 4 && slot == -1; i++) if (!g_2997[i].state) slot = i;
    for (i = 0; i < 4 && slot == -1; i++) if (g_2997[i].prio <= prio) slot = i;
    if (slot == -1) return 0;
    c = &g_2997[slot];
    memset(c, 0, sizeof *c);
    c->prio = prio;
    c->vol = vol;
    c->cur = fn_16cf_0a4b(c->data = p, slot);
    c->cur = fn_16cf_0a9b(c->cur, &len, 0xf000);
    if (!c->cur) return 0;
    c->pos = len;
    c->ticks = g_2980;
    c->state = 2;
    fn_16cf_05d0(0, slot, 0);
    return 1;
}
