/* o2dc6: load a .VOC file and convert it into the sound channel format (resampled to the output rate) */
#include <string.h>

typedef struct VocHdr {         /* "Creative Voice File\x1a" */
    char sig[20];
    int off;                    /* +14 first block */
    int ver;
    int chk;
} VocHdr;

typedef struct VocBlk {
    char type;
    unsigned char len[3];
    unsigned char rate;         /* +04 time constant */
    unsigned char pack;         /* +05 */
    char pad[2];
} VocBlk;

typedef struct Cur {            /* 12 bytes */
    int pack;
    int rate;
    char far *p;
    unsigned long n;
} Cur;

typedef struct OutHdr {         /* 16 bytes at the start of the converted sound */
    unsigned long len;
    unsigned long blocks;
    long total;
    int rate;
    int fps;
} OutHdr;

typedef union Rec {
    long l;
    unsigned u;
    struct { unsigned char a, b; int w; } s;
} Rec;

extern unsigned long g_2a4f;
extern unsigned char g_2994;
extern int g_2995;
extern int g_2a6f;
extern char g_2a7f[];

int fn_1809_0000(char far *name, int mode);
void fn_1809_058d(int h);
long fn_1809_084d(int h, void far *buf, unsigned long n);
long fn_1809_0e76(int h, long off, int whence);
long fn_1809_120c(int h);
void far *fn_203b_0007(unsigned long size, int flags);
void fn_203b_0203(void far *p);
unsigned long fn_203b_03b4(int flags);
void fn_2279_025b(void far *s, void far *d, unsigned long n);
void far *fn_2037_0002(void far *p, long off);

unsigned char ovr_2dc6_0020(int h);
unsigned long ovr_2dc6_0025(unsigned long n, unsigned char r);
void far *ovr_2dc6_002a(char far *name);
unsigned long ovr_2dc6_002f(int h, unsigned long size, char far *out, unsigned long outsize);
long ovr_2dc6_0034(unsigned char far *p);
void far *ovr_2dc6_0039(void far *dst, long far *v, int hi);

unsigned long ovr_2dc6_0025(unsigned long n, unsigned char r)
{
    if (g_2a4f != 0) {
    if (r < g_2994) {
        g_2995 = (1000000L / (256 - g_2994)) / (1000000L / (256 - r));
        n *= g_2995;
    } else if (r > g_2994) {
        g_2995 = (1000000L / (256 - r)) / (1000000L / (256 - g_2994));
        n /= g_2995;
        g_2995 = -g_2995;
    } else {
        g_2995 = 1;
    }
    return n + (n / g_2a4f + 1) * 4;
    }
    return 0;
}

void far *ovr_2dc6_002a(char far *name)
{
    unsigned long size;
    void far *buf;
    unsigned long out;
    int h;

    if (g_2a6f == 0) return 0;
    h = fn_1809_0000(name, 1);
    size = fn_1809_120c(h);
    out = ovr_2dc6_0025(size, ovr_2dc6_0020(h));
    buf = fn_203b_0007(out, 0xc0);
    if (buf == 0) {
        fn_1809_058d(h);
        return 0;
    }
    if (ovr_2dc6_002f(h, size, buf, out) == 0) {
        fn_203b_0203(buf);
        buf = 0;
    }
    fn_1809_058d(h);
    return buf;
}

unsigned char ovr_2dc6_0020(int h)
{
    unsigned char r;
    long pos;
    long n;
    VocHdr far *hp;
    unsigned char far *b;
    char hdr[0x22];

    if (g_2a6f == 0) return 0;
    pos = fn_1809_0e76(h, 0L, 1);
    n = fn_1809_084d(h, hdr, 0x22L);
    hp = (VocHdr far *)hdr;
    if (hp->off == 0x1a) {
        b = (unsigned char far *)hp + hp->off;
        if (*b == 1) {
            r = b[4];
            goto got;
        }
    }
    r = g_2994;
got:
    if (fn_1809_0e76(h, -n, 1) != pos) fn_1809_0e76(h, pos, 0);
    return r;
}

#define TICKS() if (step) { hdr.blocks += (acc + step / 2) / step; acc = 0; }

unsigned long ovr_2dc6_002f(int h, unsigned long size, char far *out, unsigned long outsize)
{
    unsigned long step;
    unsigned long acc;
    int done;
    int first;
    char far *rbuf;
    char far *rp;
    unsigned long avail;
    long blen;
    long mark;
    long cnt;
    char far *wp;
    char far *hp;
    int tog;
    VocBlk blk;
    Rec rec;
    unsigned long i;
    char far *src;
    char far *dst;
    char c;
    char far *sp;
    long n2;
    Cur cur;
    OutHdr hdr;
    char str[28];
    register unsigned bs;
    register unsigned left;

    if (g_2a6f == 0) return 0;
    avail = fn_203b_03b4(0);
    avail = (avail & 0xffe00L) < 0xfe00L ? avail & 0xffe00L : 0xfe00L;
    if (avail == 0) return 0;
    bs = avail < 0xfff0L ? (unsigned)avail : 0xfff0;
    rbuf = fn_203b_0007((unsigned long)bs, 8);
    if (g_2995 < 0) bs = bs / -g_2995 * -g_2995;
    else bs = bs / (g_2995 + 1);
    size -= fn_1809_084d(h, rbuf, bs > size ? size : bs);
    rp = rbuf + ((VocHdr far *)rbuf)->off;
    outsize &= ~3L;
    hdr.len = outsize - 4;
    hdr.blocks = 0;
    hdr.total = 0;
    hp = fn_2037_0002(out, hdr.len);
    mark = 0x10;
    cnt = 0;
    done = 0;
    first = 0;
    tog = 1;
    memset(&cur, 0, sizeof cur);
    step = 0;
    acc = 0;
    while (!done) {
        left = (unsigned)rbuf + bs - (unsigned)rp;
        if (left < 8) {
            if (left) fn_2279_025b(rp, rbuf, (unsigned long)left);
            rp = rbuf;
            size -= fn_1809_084d(h, rp + left, bs - left > size ? size : bs - left);
        }
        fn_2279_025b(rp, &blk, 8L);
        rp += g_2a7f[blk.type];
        left = (unsigned)rbuf + bs - (unsigned)rp;
        switch (blk.type) {
        case 0:
            done = 1;
            break;
        case 1:
            if (blk.rate != cur.rate) {
                step = 0x411aL / (256 - blk.rate);
                hdr.rate = g_2994;
                hdr.fps = 1000000L / (256 - g_2994) / 60;
                TICKS();
                rec.s.w = 0;
                cur.pack = rec.s.a = blk.pack;
                cur.rate = blk.rate;
                rec.s.b = g_2994;
                first = 1;
            }
        case 2:
            blen = ovr_2dc6_0034((unsigned char far *)&blk) - (blk.type == 1 ? 2L : 0L);
            acc += blen;
            if (cnt + blen > g_2a4f || first) {
                mark += cnt;
                hp = ovr_2dc6_0039(hp, &mark, 0xf000);
                wp = fn_2037_0002(out, mark);
                cnt = 0;
                tog = !tog;
                if (first) {
                    first = 0;
                    hp = ovr_2dc6_0039(hp, &rec.l, 0xd000);
                }
            }
            for (;;) {
                cur.p = rp;
                n2 = cur.n = (long)left > blen ? blen : left;
                if (g_2995 < 0) {
                    n2 /= -g_2995;
                    src = dst = cur.p;
                    for (i = 0; i < n2; i++) {
                        *dst++ = *src;
                        src += -g_2995;
                    }
                    fn_2279_025b(cur.p, wp, n2);
                } else {
                    n2 *= g_2995;
                    src = cur.p + (int)cur.n - 1;
                    dst = rbuf + bs + (int)n2 - 1;
                    for (i = 0; i < cur.n; i++) {
                        int j;
                        c = *src--;
                        for (j = 0; j < g_2995; j++) *dst-- = c;
                    }
                    fn_2279_025b(rbuf + bs, wp, n2);
                }
                wp = fn_2037_0002(wp, n2);
                cnt += n2;
                blen -= cur.n;
                if (blen == 0) break;
                rp = rbuf;
                size -= (unsigned)(left = fn_1809_084d(h, rp, bs > size ? size : bs));
            }
            rp += (int)cur.n;
            break;
        case 4:
            TICKS();
            rec.u = *(unsigned *)&blk.rate;
            rec.s.w = (int)hdr.blocks;
            hp = ovr_2dc6_0039(hp, &rec.l, 0xe000);
            break;
        case 5:
            blen = ovr_2dc6_0034((unsigned char far *)&blk);
            if ((long)left < blen) {
                if (left) {
                    strncpy(str, rp, left);
                    blen -= left;
                }
                sp = str + left;
                rp = rbuf;
                size -= (unsigned)fn_1809_084d(h, rp, bs < size ? bs : size);
            } else {
                str[0] = 0;
                sp = str;
            }
            strncpy(sp, rp, (int)blen);
            rp = fn_2037_0002(rp, blen);
            rec.s.w = 0;
            rec.u = (strlen(str) + 4) >> 2;
            hp = ovr_2dc6_0039(hp, &rec.l, 0xc000);
            hp = fn_2037_0002(hp, (unsigned long)rec.u);
            fn_2279_025b(str, hp, (unsigned long)rec.u);
            break;
        case 3: case 6: case 7: case 8:
            break;
        default:
            fn_203b_0203(rbuf);
            return 0;
        }
    }
    if (cnt) {
        mark += cnt;
        hp = ovr_2dc6_0039(hp, &mark, 0xf000);
    }
    hdr.total = mark;
    rec.l = 0;
    ovr_2dc6_0039(hp, &rec.l, 0);
    if (acc) hdr.blocks += (acc + step / 2) / step;
    fn_2279_025b(&hdr, out, 16L);
    fn_203b_0203(rbuf);
    return outsize;
}

long ovr_2dc6_0034(unsigned char far *p)
{
    unsigned char b[4];

    b[3] = 0;
    b[2] = p[3];
    b[1] = p[2];
    b[0] = p[1];
    return *(long *)b;
}

void far *ovr_2dc6_0039(void far * volatile dst, long far *v, int hi)
{
    long t;

    t = *v;
    ((int *)&t)[1] |= hi;
    fn_2279_025b(&t, dst, 4L);
    dst = fn_2037_0002(dst, -4L);
}
