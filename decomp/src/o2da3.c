/* o2da3: voice / sound index files (load index, map a sound id to its length, release) */
/* FLAGS: -ml -3 -Y */
#include <stdio.h>
#include <ctype.h>
#include <mem.h>

struct Rec { int a; char b; char c; long off; };
struct Hdr { int fh; int count; };
struct XY { int a, b; };
extern char g_1572[], g_157b[], g_1583[], g_158a[];
extern void far *g_abbe;
extern void far *g_abc2;
extern void far *g_abc6;
extern unsigned long g_abca, g_abce;
extern int g_4b92;
extern char g_81fe, g_81ff;
extern struct XY g_2862;
void far *fn_215f_0003(int p);
void fn_2279_025b(void far *d, void far *s, long n);
int fn_154c_0136(void);
void fn_203b_0203(void far *p);
void far *fn_203b_0007(long size, int flags);
int fn_1809_0000(char far *name, int mode);
long fn_1809_084d(int fh, void far *buf, long n);
void fn_1809_058d(int fh);
void far *fn_2037_0002(void far *p, long off);
void fn_130a_0784(void);
void fn_154c_029f(void far *p, long n, int a, long b);
unsigned fn_154c_040d(struct Rec *key, struct XY id);
long ovr_2da3_0034(char far *name, char far *dst, int mode);
void ovr_2da3_0039(void far *p);

void ovr_2da3_0020(int id)
{
    char name[14];
    char far *buf;
    unsigned long sz;
    unsigned i;

    sprintf(name, g_1572, id);
    if (id) {
        if (g_abc2 != 0) {
            ovr_2da3_0039(g_abc2);
            while (fn_154c_0136()) ;
            fn_203b_0203(g_abc2);
            fn_203b_0203(g_abbe);
            g_abbe = g_abc2 = 0;
            g_abca = 0;
        }
        buf = fn_215f_0003(5);
        sz = ovr_2da3_0034(name, buf, 0);
        g_abca = sz > g_abce ? sz : g_abce;
        g_abbe = fn_203b_0007(g_abca, g_4b92);
        i = ((int far *)buf)[1] * 8 + 4;
        g_abc2 = fn_203b_0007(i, g_4b92);
        if (g_abbe == 0 || g_abc2 == 0) {
            ovr_2da3_0039(fn_215f_0003(5));
            fn_203b_0203(g_abc2);
            fn_203b_0203(g_abbe);
            g_abbe = g_abc2 = 0;
        fail:
            g_81ff = 0;
            g_81fe = 1;
            return;
        }
        fn_2279_025b(buf, g_abc2, i);
    } else {
        if (g_abc6 != 0) {
            ovr_2da3_0039(g_abc6);
            fn_203b_0203(g_abc6);
            g_abc6 = 0;
            g_abce = 0;
        }
        buf = fn_215f_0003(5);
        sz = ovr_2da3_0034(name, buf, 1);
        i = ((int far *)buf)[1] * 8 + 4;
        g_abc6 = fn_203b_0007(i, g_4b92);
        if (g_abc6 == 0) {
            ovr_2da3_0039(fn_215f_0003(5));
            g_abc6 = 0;
            goto fail;
        }
        fn_2279_025b(buf, g_abc6, i);
        g_abce = sz;
    }
}

int ovr_2da3_0025(void)
{
    return 0;
}

void ovr_2da3_002a(void)
{
    fn_130a_0784();
    fn_154c_029f(g_abbe, g_abca, 0x42e0, 0L);
}

long ovr_2da3_002f(void)
{
    struct Rec key;
    struct Rec r;
    unsigned long n;
    void far *q;

    if (g_2862.a == -1) return 0;
    n = fn_154c_040d(&key, g_2862);
    if (n == 0) return 0;
    do {
        n += 8;
        q = fn_2037_0002((g_2862.a & 0x4000) ? g_abc6 : g_abc2, n);
        fn_2279_025b(q, &r, 8L);
    } while (r.a == key.a && r.b == key.b);
    return (r.off - key.off) * 60 / 22000;
}

long ovr_2da3_0034(char far *name, char far *dst, int mode)
{
    unsigned long off;
    unsigned long prev;
    long pos;
    unsigned long maxsz;
    struct Rec rec;
    struct Hdr hdr;
    char buf[14];
    int i;
    int fh;

    fh = fn_1809_0000(name, 1);
    maxsz = 0;
    hdr.fh = fh;
    hdr.count = 0;
    pos = 4;
    fn_1809_084d(fh, &off, 4L);
    prev = off;
    while (off != 0) {
        if (off - prev > maxsz) maxsz = off - prev;
        rec.off = off;
        i = 0;
        do {
            fn_1809_084d(fh, buf + i, 1L);
            buf[i] = toupper(buf[i]);
        } while (buf[i++] != 0);
        if (mode) {
            sscanf(buf, g_157b, &rec.a, &rec.b, &rec.c);
            rec.a |= 0x4000;
        } else if (buf[0] == '@') {
            sscanf(buf, g_1583, &rec.a, &rec.b);
            rec.c = '0';
            rec.a += 1000;
        } else {
            sscanf(buf, g_158a, &rec.a, &rec.b, &rec.c);
        }
        rec.c -= '0';
        fn_2279_025b(&rec, fn_2037_0002(dst, pos), 8L);
        pos += 8;
        prev = off;
        hdr.count++;
        fn_1809_084d(fh, &off, 4L);
    }
    while (off != 0) ;
    fn_2279_025b(&hdr, dst, 4L);
    return maxsz + 1000;
}

void ovr_2da3_0039(void far *p)
{
    struct Hdr h;

    fn_2279_025b(p, &h, 4L);
    if (h.count) fn_1809_058d(h.fh);
    memset(&h, 0, 4);
    fn_2279_025b(&h, p, 4L);
}
