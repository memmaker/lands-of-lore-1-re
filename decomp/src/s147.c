/* s147: WW library -- XMS memory manager. Up to two XMS heaps (g_af6c), blocks carry a 16-byte header in
 * XMS (size, physical previous, free-list next/prev; next == 1 marks an allocated block). Handles returned
 * to callers are "XMS pointers": 0xF0 | heap index in the top byte, offset from the heap base below. */
#include <mem.h>
#include <dos.h>

struct heap { int used; unsigned long base, size, head; };
struct blk { unsigned long size, phys, next, prev; };
struct xmove { unsigned long len; int sh; unsigned long so; int dh; unsigned long doff; };

extern long g_38a8;
extern struct heap g_af6c[];
extern int g_af88;

int fn_2362_0004(struct xmove far *m);
char far *fn_2037_0002(void far *p, unsigned long off);

extern unsigned g_3944[];
int far *g_3940 = (int far *)g_3944;
unsigned g_3944[207] = {
    0,320,640,960,1280,1600,1920,2240,2560,2880,3200,3520,3840,4160,4480,4800,
    5120,5440,5760,6080,6400,6720,7040,7360,7680,8000,8320,8640,8960,9280,9600,9920,
    10240,10560,10880,11200,11520,11840,12160,12480,12800,13120,13440,13760,14080,14400,14720,15040,
    15360,15680,16000,16320,16640,16960,17280,17600,17920,18240,18560,18880,19200,19520,19840,20160,
    20480,20800,21120,21440,21760,22080,22400,22720,23040,23360,23680,24000,24320,24640,24960,25280,
    25600,25920,26240,26560,26880,27200,27520,27840,28160,28480,28800,29120,29440,29760,30080,30400,
    30720,31040,31360,31680,32000,32320,32640,32960,33280,33600,33920,34240,34560,34880,35200,35520,
    35840,36160,36480,36800,37120,37440,37760,38080,38400,38720,39040,39360,39680,40000,40320,40640,
    40960,41280,41600,41920,42240,42560,42880,43200,43520,43840,44160,44480,44800,45120,45440,45760,
    46080,46400,46720,47040,47360,47680,48000,48320,48640,48960,49280,49600,49920,50240,50560,50880,
    51200,51520,51840,52160,52480,52800,53120,53440,53760,54080,54400,54720,55040,55360,55680,56000,
    56320,56640,56960,57280,57600,57920,58240,58560,58880,59200,59520,59840,60160,60480,60800,61120,
    61440,61760,62080,62400,62720,63040,63360,63680,64000
};

void far *fn_2365_0b36(int idx, unsigned long off);
int fn_2365_0b63(void far *p);
int fn_2365_063f(void far *p);
int fn_2365_0ac2(struct blk far *b, unsigned long a);
int fn_2365_0afc(struct blk far *b, unsigned long a);
int fn_2365_05e4(void far *p);
unsigned long fn_2365_0602(void far *p);
int fn_2365_07a1(void far *x, char far *dst, unsigned long n);

void far *fn_2365_0002(unsigned long size, register int idx)
{
    struct heap far *e;
    unsigned long start, cur, nxt;
    struct blk h, h2;

    e = &g_af6c[idx];
    if (!g_38a8 || !size || !e->used || e->head == 1) return 0;
    size = (size + 15) & ~15L;
    start = cur = e->head;
    for (;;) {
        fn_2365_0afc(&h, cur);
        if (h.size >= size) break;
        cur = h.next;
        if (start == cur) return 0;
    }
    if (size + 0x40 >= h.size) size = h.size;
    if (size == h.size) {
        if (h.prev == cur) e->head = 1;
        else {
            fn_2365_0afc(&h2, h.prev);
            h2.next = h.next;
            fn_2365_0ac2(&h2, h.prev);
            fn_2365_0afc(&h2, h.next);
            h2.prev = h.prev;
            fn_2365_0ac2(&h2, h.next);
            e->head = h.next;
        }
        h.next = 1;
        fn_2365_0ac2(&h, cur);
    } else {
        h.size -= size + 0x10;
        fn_2365_0ac2(&h, cur);
        h2.size = size;
        h2.phys = cur;
        h2.next = 1;
        cur += h.size + 0x10;
        fn_2365_0ac2(&h2, cur);
        nxt = cur + h2.size + 0x10;
        if (e->base + e->size > nxt) {
            fn_2365_0afc(&h, nxt);
            h.phys = cur;
            fn_2365_0ac2(&h, nxt);
        }
    }
    return fn_2365_0b36(idx, cur + 0x10);
}

void fn_2365_0209(void far *p)
{
    struct heap far *e;
    unsigned long addr, nxt, nn;
    struct blk h, h2, h3, h4;

    if (!fn_2365_063f(p)) return;
    addr = fn_2365_0602(p) - 0x10;
    e = &g_af6c[fn_2365_0b63(p)];
    fn_2365_0afc(&h, addr);
    if (h.next != 1) return;
    if (h.phys == 1) h3.next = 1;
    else fn_2365_0afc(&h3, h.phys);
    nxt = addr + h.size + 0x10;
    if (e->base + e->size <= nxt) {
        h2.next = 1;
        nxt = 1;
        nn = 1;
    } else {
        fn_2365_0afc(&h2, nxt);
        nn = nxt + h2.size + 0x10;
        if (e->base + e->size > nn) fn_2365_0afc(&h4, nn);
        else nn = 1;
    }
    if (h3.next == 1 && h2.next == 1) {
        if (e->head == 1) {
            e->head = addr;
            h.next = h.prev = addr;
        } else {
            h.next = e->head;
            fn_2365_0afc(&h2, h.next);
            h.prev = h2.prev;
            h2.prev = addr;
            if (e->head == h2.next) memcpy(&h3, &h2, 16);
            else {
                fn_2365_0ac2(&h2, h.next);
                fn_2365_0afc(&h3, h.prev);
            }
            h3.next = addr;
            fn_2365_0ac2(&h3, h.prev);
        }
        fn_2365_0ac2(&h, addr);
        return;
    }
    if (h3.next == 1) {
        h.size += h2.size + 0x10;
        if (h2.next == nxt) h.next = h.prev = addr;
        else {
            h.next = h2.next;
            h.prev = h2.prev;
            fn_2365_0afc(&h2, h.next);
            h2.prev = addr;
            fn_2365_0ac2(&h2, h.next);
            fn_2365_0afc(&h3, h.prev);
            h3.next = addr;
            fn_2365_0ac2(&h3, h.prev);
        }
        fn_2365_0ac2(&h, addr);
        if (e->head == nxt) e->head = addr;
        if (nn != 1) {
            h4.phys = addr;
            fn_2365_0ac2(&h4, nn);
        }
        return;
    }
    if (h2.next == 1) {
        if (nxt != 1) {
            h2.phys = h.phys;
            fn_2365_0ac2(&h2, nxt);
        }
        h3.size += h.size + 0x10;
        fn_2365_0ac2(&h3, h.phys);
    } else {
        h3.size += h.size + h2.size + 0x20;
        fn_2365_0ac2(&h3, h.phys);
        if (e->head == nxt) e->head = h.phys;
        if (nn != 1) {
            h4.phys = h.phys;
            fn_2365_0ac2(&h4, nn);
        }
        memcpy(&h, &h2, 16);
        fn_2365_0afc(&h3, h.prev);
        h3.next = h.next;
        fn_2365_0ac2(&h3, h.prev);
        fn_2365_0afc(&h2, h.next);
        h2.prev = h.prev;
        fn_2365_0ac2(&h2, h.next);
    }
}

int fn_2365_05e4(void far *p)
{
    return g_af6c[fn_2365_0b63(p)].used;
}

unsigned long fn_2365_0602(void far *p)
{
    unsigned long r = ((long)p & 0xffffffL) + g_af6c[fn_2365_0b63(p)].base;
    return r;
}

int fn_2365_063f(void far *p)
{
    unsigned long t = (unsigned long)p;
    register int i;

    if (((unsigned *)&t)[1] < 0xf000) return 0;
    i = ((unsigned char *)&t)[3] & 0xf;
    if (i > 2) return 0;
    ((unsigned *)&t)[1] &= 0xff;
    if (g_af6c[i].size <= t) return 0;
    return 1;
}

int fn_2365_0687(char far *src, void far *x, unsigned long n)
{
    char buf[2];
    char far *q;
    struct xmove m;

    if (n & 1) {
        n--;
        if (fn_2365_0602(x) & 1) {
            fn_2365_07a1((char far *)x - 1, buf, 2L);
            buf[1] = *src;
            fn_2365_0687(buf, (char far *)x - 1, 2L);
            src++;
            (*(unsigned long *)&x)++;
        } else {
            fn_2365_07a1((void far *)((unsigned long)x + n), buf, 2L);
            q = fn_2037_0002(src, n);
            buf[0] = *q;
            fn_2365_0687(buf, (void far *)((unsigned long)x + n), 2L);
        }
    }
    m.len = n;
    m.sh = 0;
    m.so = (unsigned long)(void far *)src;
    m.dh = fn_2365_05e4(x);
    m.doff = fn_2365_0602(x);
    return fn_2362_0004(&m);
}

int fn_2365_07a1(void far *x, char far *dst, unsigned long n)
{
    char buf[2];
    char far *q;
    struct xmove m;

    if (n & 1) {
        n--;
        if (fn_2365_0602(x) & 1) {
            fn_2365_07a1((char far *)x - 1, buf, 2L);
            *dst = buf[1];
            dst++;
            (*(unsigned long *)&x)++;
        } else {
            fn_2365_07a1((void far *)((unsigned long)x + n), buf, 2L);
            q = fn_2037_0002(dst, n);
            *q = buf[0];
        }
    }
    m.len = n;
    m.sh = fn_2365_05e4(x);
    m.so = fn_2365_0602(x);
    m.dh = 0;
    m.doff = (unsigned long)(void far *)dst;
    return fn_2362_0004(&m);
}

void fn_2365_0884(unsigned long src, unsigned long dst, unsigned long n)
{
    char b[2], a[2];
    struct xmove m;

    if (n & 1) {
        if (n == 1) {
            m.len = 2;
            m.sh = fn_2365_05e4((void far *)dst);
            m.so = fn_2365_0602((void far *)dst);
            m.dh = 0;
            m.doff = (unsigned long)(void far *)a;
            fn_2362_0004(&m);
            m.len = 2;
            m.sh = fn_2365_05e4((void far *)src);
            m.so = fn_2365_0602((void far *)src);
            m.dh = 0;
            m.doff = (unsigned long)(void far *)b;
            fn_2362_0004(&m);
            a[0] = b[0];
            m.len = 2;
            m.sh = 0;
            m.so = (unsigned long)(void far *)a;
        tail:
            m.dh = fn_2365_05e4((void far *)dst);
            m.doff = fn_2365_0602((void far *)dst);
            fn_2362_0004(&m);
            return;
        } else {
            if (src & 1) {
                m.len = 2;
                m.sh = fn_2365_05e4((void far *)src);
                m.so = fn_2365_0602((void far *)src);
                m.dh = fn_2365_05e4((void far *)dst);
                m.doff = fn_2365_0602((void far *)dst);
                fn_2362_0004(&m);
                src = src + 1;
                dst = dst + 1;
            } else {
                m.len = 2;
                m.sh = fn_2365_05e4((void far *)src);
                m.so = fn_2365_0602((void far *)(src + (n - 2)));
                m.dh = fn_2365_05e4((void far *)dst);
                m.doff = fn_2365_0602((void far *)(dst + (n - 2)));
                fn_2362_0004(&m);
            }
            n--;
        }
    }
    m.len = n;
    m.sh = fn_2365_05e4((void far *)src);
    m.so = fn_2365_0602((void far *)src);
    goto tail;
}

int fn_2365_0ac2(struct blk far *b, unsigned long a)
{
    struct xmove m;

    m.len = 0x10;
    m.sh = 0;
    m.so = (unsigned long)(void far *)b;
    m.dh = g_af88;
    m.doff = a;
    return fn_2362_0004(&m);
}

int fn_2365_0afc(struct blk far *b, unsigned long a)
{
    struct xmove m;

    m.len = 0x10;
    m.sh = g_af88;
    m.so = a;
    m.dh = 0;
    m.doff = (unsigned long)(void far *)b;
    return fn_2362_0004(&m);
}

/* original loads the segment with `mov edx,[bp-2]` (66 prefix) where BCC emits `mov dx,[bp-2]` */
/* NONMATCHING */
void far *fn_2365_0b36(register int idx, unsigned long off)
{
    long t = off - g_af6c[idx].base;

    ((unsigned char *)&t)[3] |= 0xf0 | idx;
    return (void far *)t;
}

int fn_2365_0b63(void far *p)
{
    void far *t = p;
    return ((unsigned char *)&t)[3] & 0xf;
}

int fn_2365_0b7d(register int idx, unsigned long far *total, unsigned long far *largest)
{
    struct heap far *e;
    unsigned long cur, start;
    struct blk h;

    e = &g_af6c[idx];
    *total = *largest = 0;
    if (!g_38a8 || !e->used || idx >= 2 || e->head == 1) return 0;
    start = cur = e->head;
    do {
        fn_2365_0afc(&h, cur);
        cur = h.next;
        if (*largest < h.size) *largest = h.size;
        *total += h.size;
    } while (start != cur);
    return 1;
}

long fn_2365_0c28(int idx)
{
    long total, largest;

    fn_2365_0b7d(idx, &total, &largest);
    largest -= 0x10;
    largest = largest > 0 ? largest : 0;
    return largest;
}

long fn_2365_0c68(int idx)
{
    long total, largest;

    fn_2365_0b7d(idx, &total, &largest);
    return total;
}
