/* s003: sound effects and music (VOC cache, AdLib tracks, positional volume) */
#include <stdio.h>
#include <string.h>

struct Track { char file; char song; char sfx; };
struct Sfx { int voc; int vol; };

extern struct Track far f_26a4_0000[];
extern char far f_26a4_00f0[][10];
extern struct Sfx far f_26a4_09e2[];
extern char far f_2781_0000[];
extern char far f_2791_0000[];
extern char far f_27a1_0000[];

extern unsigned g_7fda;
extern void far *g_4d62;
extern int g_3745, g_3747, g_3749;
extern char g_8200, g_8201;
extern int g_7fd0;
extern int g_7fb6;
extern int g_2144, g_2146;
extern int g_2148[], g_215c[];
extern unsigned g_2140, g_2142;
extern int g_4b92;

int fn_17f8_0003(char far *name, void far *buf, long size);
void fn_17c5_0004(char far *name, void far *buf, long size);
void far *fn_2037_0002(void far *p, long off);
void fn_178d_015e(void);
void fn_178d_0091(int song);
void fn_178d_01b0(void);
void ovr_2db9_0048(int vol);
void fn_2120_0007(int n);
void fn_0845_0f81(char far *fmt, ...);
int fn_1aff_02d2(int a, int b);
int fn_1afa_0010(int x1, int y1, int x2, int y2);
int fn_0845_0cf7(int pos, int a, int b);
int fn_16cf_01c8(int pan);
void fn_15a7_02b6(void far *p);
void fn_16cf_0022(void far *p, int pan, int vol);
void fn_17d6_0019(int n, int vol);
void fn_203b_0203(void far *p);
void far *fn_203b_0007(unsigned long size, int flags);
void ovr_2dc3_0020(void);
long ovr_2dca_0025(unsigned long a, unsigned long b);
void fn_15a7_0004(void far *p, unsigned long size);
long fn_15a7_04b0(void far *cache);
void far *fn_15a7_030c(void far *cache, long id);
void far *fn_15a7_043c(void far *cache);
void far *fn_15a7_00b0(void far *cache, long size, long id);
void fn_15a7_0501(void far *cache);
void fn_15a7_0210(void far *cache, void far *p);
void fn_16cf_00b9(void far *p);
int fn_1981_000a(char far *name);
int fn_1809_0000(char far *name, int mode);
long fn_1809_120c(int h);
void fn_1809_058d(int h);
int ovr_2dc6_0020(int h);
long ovr_2dc6_0025(long size, int a);
long ovr_2dc6_002f(int h, long size, void far *buf, long len);
void ovr_2d46_002a(int a, char far *fmt, ...);

void fn_067a_023d(void);
void fn_067a_02f5(int n, int pos);
void fn_067a_0417(int n, int vol, int force);
void far *fn_067a_0649(int n);

void far *g_1e8c = 0;
char g_1e90 = -1;
char g_1e91 = -1;
int g_1e92 = 0;
int g_1e94 = -1;
int g_1e96 = 0;
int g_1e98 = 0;
int g_1e9a[8] = { -32, -31, 1, 33, 32, 31, -1, -33 };
int g_1eaa = -1;

void fn_067a_0003(void)
{
    fn_17f8_0003(0, g_4d62, 0x6590L);
    fn_17c5_0004(0, g_4d62, 0x6590L);
    g_1e90 = -1;
    g_1e91 = -1;
}

/* NONMATCHING */
void fn_067a_003e(int n)
{
    char name[20];
    int r;

    if (!(g_7fda & 2)) {
        if (g_1e90 == -2) return;
        fn_17f8_0003(0, 0, 0);
        fn_17c5_0004(0, 0, 0);
        fn_17f8_0003("LORESFX", g_4d62, 0x6590L);
        g_1e90 = -2;
        g_1e91 = f_26a4_0000[n].song;
        return;
    }
    n -= 250;
    if (f_26a4_0000[n].file == g_1e90 && f_26a4_0000[n].song == g_1e91) {
        fn_067a_023d();
        return;
    }
    fn_067a_023d();
    sprintf(name, "LORE%02d%c", f_26a4_0000[n].file, f_26a4_0000[n].song);
    fn_17f8_0003(0, 0, 0);
    fn_17c5_0004(0, 0, 0);
    if (g_3747 == 7 || g_3747 == 6 || g_3747 == 4)
        r = fn_17f8_0003("LORESFX", g_4d62, 0x6590L);
    else
        r = fn_17f8_0003(name, g_4d62, 0x6590L);
    if (0x6590L - r > 1)
        fn_17c5_0004(name, fn_2037_0002(g_4d62, r), 0x6590L - r);
    g_1e90 = f_26a4_0000[n].file;
    g_1e91 = f_26a4_0000[n].song;
}


int fn_067a_01d1(int n);

int fn_067a_01d1(n)
register int n;
{
    register int old;

    if (n == -1) return g_1e94;
    old = g_1e94;
    g_1e94 = n;
    if (g_7fda & 2) {
        fn_067a_003e(n);
        n -= 250;
        fn_178d_015e();
        g_1e92 = 1;
        fn_178d_0091(f_26a4_0000[n].sfx);
        ovr_2db9_0048(g_8201 * 0x91 / 100 + 0x6e);
    }
    return old;
}


void fn_067a_023d(void)
{
    if (g_7fda & 2) {
        if (g_1e92) {
            fn_178d_01b0();
            fn_2120_0007(3);
        }
        g_1e92 = 0;
    }
    fn_067a_01d1(-1);
}

void fn_067a_026b(int n)
{
    fn_067a_02f5(n, g_7fd0);
}

void fn_067a_027f(int n, int pos)
{
    if (g_2144) {
        if (g_2146 < 10) {
            g_2148[g_2146] = n;
            g_215c[g_2146] = pos;
            g_2146++;
        } else
            fn_0845_0f81("OVERFLOWED QUEUED DELAY Sound Effect\r");
    } else
        fn_067a_02f5(n, pos);
}

void fn_067a_02c7(void)
{
    int i;
    for (i = 0; i < g_2146; i++)
        fn_067a_02f5(g_2148[i], g_215c[i]);
}

/* NONMATCHING */
void fn_067a_02f5(int n, int pos)
{
    int dir;
    int cnt;
    int d;

    if (!(g_7fda & 1)) return;
    if (g_1e96 > 0) fn_067a_0417(g_1e96, g_1e98, 0);
    if (pos) {
        d = fn_1aff_02d2(g_7fd0, pos);
        if (d > (g_3745 == 6 || g_3745 == 7 ? 3 : 15)) {
            g_1e96 = 0;
            return;
        }
    }
    g_1e96 = n;
    g_1e98 = (15 - (pos || d < 2 ? d : 0)) << 4;
    if (g_7fd0 != pos) {
        d = g_7fd0;
        cnt = 3;
        while (d != pos && cnt) {
            dir = fn_1afa_0010(d & 0x1f, d >> 5, pos & 0x1f, pos >> 5);
            d += g_1e9a[dir];
            if (d != pos && fn_0845_0cf7(d, 0, 1)) g_1e98 >>= 1;
            cnt--;
        }
    }
    if (n && !g_7fb6) fn_067a_02f5(0, 0);
}

void fn_067a_0401(int n, int force)
{
    fn_067a_0417(n, 0xff, force);
}

/* NONMATCHING */
void fn_067a_0417(int n, int vol, int force)
{
    void far *p;
    int pan;
    unsigned v;

    if (!force && !(g_7fda & 1)) return;
    if (n == 1) {
        if (g_1eaa == -1) return;
        if (g_1eaa == 1) return;
    }
    g_1eaa = n;
    if (f_26a4_09e2[n].vol > 0) {
        pan = f_26a4_09e2[n].vol * vol;
        pan >>= 8;
    } else
        pan = -f_26a4_09e2[n].vol;
    if (fn_16cf_01c8(pan))
        p = fn_067a_0649(n);
    else
        p = 0;
    if (p) {
        fn_15a7_02b6(p);
        if (vol == 0xff)
            v = g_8200 * 200 / 100 + 0x37;
        else
            v = (unsigned)((g_8200 * 200 / 100 + 0x37) * vol) >> 8;
        fn_16cf_0022(p, pan, v);
        return;
    }
    if (f_26a4_09e2[n].vol < 0) vol = 0xff;
    switch (g_3745) {
    case 4: n = f_27a1_0000[n]; break;
    case 6: n = f_2791_0000[n]; break;
    case 7: n = f_2781_0000[n]; break;
    }
    if (n == 0xa8) n = 0xa7;
    fn_17d6_0019(n, vol);
}

int fn_067a_0572(unsigned long size)
{
    if (!g_3749) return 0;
    if (g_1e8c) {
        fn_203b_0203(g_1e8c);
        g_1e8c = 0;
        ovr_2dc3_0020();
    }
    if (size && ovr_2dca_0025(g_2140, g_2142)) {
        g_1e8c = fn_203b_0007(size, g_4b92);
        if (g_1e8c)
            fn_15a7_0004(g_1e8c, size);
        else
            ovr_2dc3_0020();
    }
    return g_1e8c ? 1 : 0;
}

void fn_067a_060c(void)
{
    int i;
    if (!g_3749) return;
    for (i = 0; i <= 0x2d; i++) {
        fn_067a_0649(i);
        if (fn_15a7_04b0(g_1e8c) < 10000) return;
    }
}

void fn_067a_0644(void)
{
}

/* NONMATCHING */
void far *fn_067a_0649(int n)
{
    void far *p;
    long size;
    void far *q;
    char name[20];
    int h;

    if (n == -1) return 0;
    if (!g_3749) return 0;
    h = f_26a4_09e2[n].voc;
    if (h == -1) return 0;
    p = fn_15a7_030c(g_1e8c, n);
    if (p) return p;
    sprintf(name, "%s.VOC", f_26a4_00f0[h]);
    if (name[0] == 'X') return p;
    if (name[0] == 'E' && name[1] == 'M') return p;
    if (!fn_1981_000a(name)) return p;
    h = fn_1809_0000(name, 1);
    size = fn_1809_120c(h);
    size = ovr_2dc6_0025(size, ovr_2dc6_0020(h));
    while (fn_15a7_04b0(g_1e8c) < size) {
        q = fn_15a7_043c(g_1e8c);
        if (!q) break;
    }
    p = fn_15a7_00b0(g_1e8c, size, n);
    if (!p) {
        while (!p) {
            q = fn_15a7_043c(g_1e8c);
            if (!q) break;
            p = fn_15a7_00b0(g_1e8c, size, n);
        }
        if (!p) {
            fn_16cf_00b9(0);
            fn_15a7_0501(g_1e8c);
            p = fn_15a7_00b0(g_1e8c, size, n);
        }
    }
    if (p) {
        if (!ovr_2dc6_002f(h, size, p, size))
            ovr_2d46_002a(1, "Unable to load voc file %s", name);
    }
    fn_1809_058d(h);
    return p;
}

void fn_067a_084d(char far *name, int n)
{
    void far *p;
    int h;

    if (name && (unsigned)n <= 250) {
        h = f_26a4_09e2[n].voc;
        p = fn_15a7_030c(g_1e8c, n);
        if (h != -1) {
            if (p) fn_15a7_0210(g_1e8c, p);
            strcpy(f_26a4_00f0[h], name);
        }
    }
}

int fn_067a_08c2(int n)
{
    char far *s;

    do {
        n++;
        if (n == 0x2f) n++;
        if (f_26a4_09e2[n].voc == 199) {
            n = 11;
            break;
        }
        s = f_26a4_00f0[f_26a4_09e2[n].voc];
    } while (*s == 'X' || !strcmp(s, "EMPTY"));
    return n;
}
