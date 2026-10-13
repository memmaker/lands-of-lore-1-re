/* s029: digital sound mixer (four VOC channels streamed into the driver's DMA buffers) */
#include "lol.h"
#include <mem.h>

struct Chan {               /* 0x28 bytes: one mixer channel */
    void far *data;         /* sample resource */
    void far *cur;          /* current VOC block */
    unsigned long start;    /* timer tick playback started */
    unsigned long len;      /* duration in ticks */
    unsigned long pos;      /* read offset into data */
    unsigned long end;      /* end offset */
    int x18;
    int prio;
    char x1c;
    unsigned char rate;     /* VOC time constant */
    int freq;
    int vol;
    int active;             /* 0 idle, 1 draining, 2 starting, 3 streaming */
    char pad[4];
};

struct SndHdr {             /* 0x10 bytes: sample resource header */
    long off;
    long len;
    long end;
    long x0c;
};

struct DrvBuf {             /* driver start-output request */
    int rate;
    int x02;
    long buf;
    long size;
};

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
char g_2995 = 0;
char g_2996 = 0;
struct Chan g_chan[4] = {0};
void far *g_2a37[5] = {0};
long g_2a4b = 0;
unsigned long g_2a4f[5] = {0};
char g_2a63[12] = {0};
int g_2a6f = 0;
void far *g_2a71 = 0;
void far * far *g_2a75 = 0;
char far *g_2a79 = 0;
int g_2a7d = 0;
char g_2a7f[9] = {1, 6, 4, 7, 6, 4, 6, 4, 8};

extern int g_20cd, g_20cf, g_292a, g_2950, g_3749;
extern char far *g_2952;
extern unsigned long g_384c;

int fn_16bf_00d6(int v);
void fn_1b79_0284(int h);
void fn_1b79_027f(int h);
void fn_1b79_0261(int h, int a, struct DrvBuf far *p);
int fn_1b79_0367(int h);
void fn_1bbe_050c(void far *p, int n, int vol);
void fn_1bbe_05e1(void far *s, void far *d, int n);
void fn_1bbe_05bc(void far *p, int n);
void fn_0845_0f81(char far *fmt, ...);
void fn_2279_025b(void far *s, void far *d, long n);
void far *fn_2037_0002(void far *p, long off);

int fn_16cf_0022(void far *p, int pri, int vol);
int fn_16cf_00b9(void far *p);
int fn_16cf_022f(void);
int fn_16cf_05d0(char mode, int ch, int n);
void far *fn_16cf_0a05(long p, long far *len, int far *type);
void far *fn_16cf_0a4b(void far *p, int idx);
void far *fn_16cf_0a9b(void far *p, long far *len, int type);
int fn_16cf_0ae2(void far *p, int prio, int vol);

int fn_16cf_000b(void far *p)
{
    return fn_16cf_0022(p, 0xff, 0xff);
}

int fn_16cf_0022(void far *p, int pri, int vol)
{
    if ((g_20cd || g_20cf) && g_292a != -1 && vol) {
        vol = fn_16bf_00d6(vol);
        if (!p)
            pri = 0x100;
        else
            pri = pri < 0xff ? pri : 0xff;
        if (!fn_16cf_022f())
            g_2950 = -1;
        if (!g_2990 || pri >= g_2950) {
            if (g_2990)
                fn_16cf_00b9(0L);
            if (p) {
                g_2950 = pri;
                return fn_16cf_0ae2(p, pri, vol);
            }
        }
    }
    return 0;
}

int fn_16cf_00b9(void far *p)
{
    struct Chan far *c;
    int r = 0;
    int i;

    if (p) {
        for (i = 0; i < 4; i++) {
            c = &g_chan[i];
            if (c->data == p && c->active) {
                c->active = 0;
                memset(g_2a37[i + 1], 0x80, g_2a4f[i + 1]);
                r = 1;
            }
        }
        return r;
    }
    if (fn_16cf_022f()) {
        g_chan[0].active = g_chan[1].active = g_chan[2].active = g_chan[3].active = 0;
        fn_1b79_0284(g_292a);
        g_2952[0xf] = 0;
        for (i = 1; i <= 4; i++)
            memset(g_2a37[i], 0x80, g_2a4f[i]);
        g_297e = -1;
        return 1;
    }
    return 0;
}

int fn_16cf_0181(int i)
{
    if (!g_2a6f || !g_chan[i].active)
        return 0;
    if (g_297e == -1) {
        fn_1b79_027f(g_292a);
        g_297e = i;
    }
    g_chan[i].start = g_384c;
    return 1;
}

int fn_16cf_01c8(int prio)
{
    int f = 0;
    int i;

    if (g_2990) {
        if (!g_chan[0].active)
            f = 1;
        if (!f && g_chan[0].prio <= prio)
            f = 1;
    } else {
        for (i = 0; i < 4 && !f; i++)
            if (!g_chan[i].active)
                f = 1;
        for (i = 0; i < 4 && !f; i++)
            if (g_chan[i].prio <= prio)
                f = 1;
    }
    return f;
}

int fn_16cf_022f(void)
{
    int i;

    if (!g_2a6f || (!g_chan[0].active && !g_chan[1].active && !g_chan[2].active && !g_chan[3].active)) {
        if (g_297e != -1) {
            fn_1b79_0284(g_292a);
            g_2952[0xf] = 0;
            g_chan[0].active = g_chan[1].active = g_chan[2].active = g_chan[3].active = 0;
            for (i = 1; i <= 4; i++)
                memset(g_2a37[i], 0x80, g_2a4f[i]);
            g_297e = -1;
        }
        return 0;
    }
    return 1;
}

int fn_16cf_02b7(void)
{
    struct Chan far *c;
    struct DrvBuf p;
    int r;
    int n;
    int i;

    if (g_297c == 1) {
        fn_0845_0f81("REENTERED!!!!!!\r");
        return 0;
    }
    g_297c = 1;
    if (!g_2a6f || (!g_chan[0].active && !g_chan[1].active && !g_chan[2].active && !g_chan[3].active)) {
        if (g_297e != -1) {
            fn_1b79_0284(g_292a);
            g_2952[0xf] = 0;
            g_chan[0].active = g_chan[1].active = g_chan[2].active = g_chan[3].active = 0;
            for (n = 1; n <= 4; n++)
                memset(g_2a37[n], 0x80, g_2a4f[n]);
            g_297e = -1;
        }
        g_297c = 0;
        return 0;
    }
    for (i = 0; i < 4; i++) {
        c = &g_chan[i];
        if (c->active && c->len < g_384c - c->start && c->pos >= c->end) {
            c->active = 0;
            {
                int j = i + 1;
                memset(g_2a37[j], 0x80, g_2a4f[j]);
            }
        }
    }
    if (g_chan[0].active || g_chan[1].active || g_chan[2].active || g_chan[3].active) {
        if (g_3749 == 4) {
            r = fn_1b79_0367(g_292a);
            n = (int)((g_2a4f[0] - (unsigned)(r + 1)) / g_2a4f[1]) + 1;
            if ((unsigned)n >= g_2a7d)
                n = 0;
        } else {
            n = g_2952[0xf] + 1;
            if ((unsigned)n >= g_2a7d)
                n = 0;
            r = 0;
        }
        if (g_2a79[n] == 0 || r == -1) {
            if (r == -1) {
                g_2984++;
                if (g_2984 - g_2988 > 1) {
                    fn_1b79_0284(g_292a);
                    g_2952[0xf] = 0;
                    p.rate = 0;
                    p.x02 = g_2994;
                    p.buf = g_2a4b;
                    p.size = g_2a4f[0];
                    fn_1b79_0261(g_292a, 0, &p);
                    fn_1b79_027f(g_292a);
                    g_298c++;
                }
            } else
                g_2988 = g_2984;
            fn_16cf_05d0(1, 0, n);
        }
    }
    g_297c = 0;
    return 1;
}

int fn_16cf_04db(void far *p)
{
    struct Chan far *c;
    struct SndHdr h;
    int best = -1;
    int i, idx;

    if (p) {
        for (i = 0; i < 4; i++) {
            c = &g_chan[i];
            if (c->data == p && c->active)
                best = c->len;
        }
        if (best != -1)
            return best;
        fn_2279_025b(p, &h, 16L);
        return h.len;
    }
    idx = -1;
    for (i = 0; i < 4; i++) {
        c = &g_chan[i];
        if (c->active && best < c->len) {
            best = c->len;
            idx = i;
        }
    }
    if (idx != -1)
        return best;
    return 0;
}

int fn_16cf_057a(void far *p)
{
    struct Chan far *c;
    int i;

    if (p) {
        for (i = 0; i < 4; i++) {
            c = &g_chan[i];
            if (c->data == p) {
                if (c->active)
                    return c->pos / c->freq;
                else
                    return -1;
            }
        }
    }
    return -1;
}

int fn_16cf_05d0(char mode, int ch, int n)
{
    long rem;
    void far *src;
    void far *dst;
    int type;
    unsigned char len[4];
    struct Chan far *c;
    struct DrvBuf p;

    if (mode) {
        for (ch = 0; ch < 4; ch++) {
            c = &g_chan[ch];
            if (c->active) {
                while (c->cur) {
                    c->cur = fn_16cf_0a05((long)c->cur, (long far *)len, &type);
                    switch (type) {
                    case 0xd000:
                        len[1] = 0xd3;
                        p.rate = len[0];
                        p.x02 = g_2994;
                        g_2980 = c->freq = 1000000L / (0x100 - (c->rate = len[1])) / 60;
                        g_2982 = g_2992 * g_2980;
                        break;
                    case 0xf000:
                        goto done1;
                    case 0:
                        c->cur = 0;
                        goto done1;
                    }
                }
            done1:
                dst = g_2a37[ch + 1];
                if (c->pos >= c->end) {
                    c->active = 1;
                    memset(dst, 0x80, g_2a4f[1]);
                } else {
                    src = fn_2037_0002(c->data, c->pos);
                    p.buf = g_2a4b;
                    if ((rem = c->end - c->pos) < g_2a4f[1])
            p.size = rem;
        else
            p.size = g_2a4f[1];
                    fn_2279_025b(src, dst, p.size);
                    fn_1bbe_050c(dst, p.size, c->vol);
                    if (p.size < g_2a4f[1])
                        memset(fn_2037_0002(dst, p.size), 0x80, g_2a4f[1] - p.size);
                    c->pos += p.size;
                    p.size = g_2a4f[1];
                }
            }
        }
        fn_1bbe_05e1(g_2a37[1], g_2a75[n], g_2a4f[1]);
        g_2a79[n] = 1;
        if (++n >= g_2a7d)
            n = 0;
        g_2a79[n] = 0;
        memset(g_2a75[n], 0x80, g_2a4f[1]);
    } else if (g_297e == -1) {
        c = &g_chan[ch];
        while (c->cur) {
            c->cur = fn_16cf_0a05((long)c->cur, (long far *)len, &type);
            switch (type) {
            case 0xd000:
                len[1] = 0xd3;
                p.rate = len[0];
                p.x02 = g_2994;
                g_2980 = c->freq = 1000000L / (0x100 - (c->rate = len[1])) / 60;
                g_2982 = g_2992 * g_2980;
                break;
            case 0xf000:
                goto done0;
            case 0:
                c->cur = 0;
                goto done0;
            }
        }
    done0:
        src = fn_2037_0002(c->data, c->pos);
        dst = g_2a37[0];
        p.buf = g_2a4b;
        if ((rem = c->end - c->pos) < g_2a4f[1])
            p.size = rem;
        else
            p.size = g_2a4f[1];
        fn_2279_025b(src, dst, p.size);
        fn_1bbe_050c(dst, p.size, c->vol);
        if (p.size < g_2a4f[1])
            memset(fn_2037_0002(dst, p.size), 0x80, g_2a4f[1] - p.size);
        c->pos += p.size;
        p.size = g_2a4f[0];
        fn_1bbe_05bc(dst, g_2a4f[1]);
        if (c->pos >= c->end)
            c->active = 1;
        else
            c->active = 3;
        memset(g_2a75[1], 0x80, g_2a4f[1]);
        fn_1b79_0261(g_292a, 0, &p);
        fn_16cf_0181(ch);
        g_2a79[0] = 1;
        g_2a79[1] = 0;
    }
    return g_chan[0].active | g_chan[1].active | g_chan[2].active | g_chan[3].active;
}

void far *fn_16cf_0a05(long p, long far *len, int far *type)
{
    long hdr;

    fn_2279_025b((void far *)p, &hdr, 4L);
    *type = ((unsigned *)&hdr)[1] & 0xf000;
    ((unsigned *)&hdr)[1] ^= *type;
    *len = hdr;
    return (void far *)(p - 4UL);
}

void far *fn_16cf_0a4b(void far *p, int idx)
{
    struct Chan far *c;
    struct SndHdr h;

    fn_2279_025b(p, &h, 16L);
    c = &g_chan[idx];
    c->len = h.len;
    c->end = h.end;
    return fn_2037_0002(p, h.off);
}

void far *fn_16cf_0a9b(void far *p, long far *len, int type)
{
    int t;

    do {
        p = fn_16cf_0a05((long)p, len, &t);
        if (!t) {
            *len = 0;
            return 0;
        }
    } while (t != type);
    return p;
}

int fn_16cf_0ae2(void far *p, int prio, int vol)
{
    long len;
    struct Chan far *c;
    int slot, i;

    if (!p || !g_2a6f)
        return 0;
    slot = -1;
    for (i = 0; i < 4 && slot == -1; i++)
        if (!g_chan[i].active)
            slot = i;
    for (i = 0; i < 4 && slot == -1; i++)
        if (g_chan[i].prio <= prio)
            slot = i;
    if (slot == -1)
        return 0;
    c = &g_chan[slot];
    memset(c, 0, sizeof(struct Chan));
    c->prio = prio;
    c->vol = vol;
    c->cur = fn_16cf_0a4b(c->data = p, slot);
    c->cur = fn_16cf_0a9b(c->cur, &len, 0xf000);
    if (!c->cur)
        return 0;
    c->pos = len;
    c->freq = g_2980;
    c->active = 2;
    fn_16cf_05d0(0, slot, 0);
    return 1;
}
