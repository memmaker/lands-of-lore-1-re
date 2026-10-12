/* s024: paragraph heap (resource cache allocator) */
#include "lol.h"

struct Blk {                /* 0x20 bytes, precedes every block */
    struct Blk far *next;
    struct Blk far *prev;
    unsigned long paras;    /* block size in paragraphs, header included */
    unsigned time;          /* last use, g_384c >> 4 */
    long tag;               /* owner id, -1 free */
    char pad[14];
};

struct Heap {               /* 0x10 bytes at the start of the heap */
    struct Blk far *free;
    struct Blk far *used;
    unsigned long freeParas;
    unsigned long total;
};

extern unsigned long g_384c;

void fn_2279_025b(void far *s, void far *d, long n);
void far *fn_2037_0002(void far *p, long off);
int fn_16cf_057a(void far *p);
void fn_0845_08a5(char far *fmt, int a, int b, int c, ...);

void fn_15a7_064a(struct Heap far *h, int which, struct Blk far *blk);
void fn_15a7_06e9(struct Heap far *h, int which, struct Blk far *blk, unsigned long paras, long tag, int merge);
void far *fn_15a7_0382(struct Heap far *heap);
int fn_15a7_0210(struct Heap far *heap, void far *mem);

int fn_15a7_0004(struct Heap far *heap, long size)
{
    struct Blk b;
    struct Heap h;

    size = size & ~15L;
    if (!heap || !size) return 0;
    h.freeParas = (size - 16) >> 4;
    h.used = 0;
    h.free = fn_2037_0002(heap, 16);
    h.total = h.freeParas;
    fn_2279_025b(&h, heap, 16);
    b.next = 0;
    b.prev = 0;
    b.paras = h.freeParas;
    b.tag = -1;
    b.time = 0;
    fn_2279_025b(&b, h.free, 32);
    return 1;
}

void far *fn_15a7_00b0(struct Heap far *heap, long size, long tag)
{
    long rest;
    struct Blk far *p;
    long need;
    struct Heap h;
    struct Blk b;
    int found;

    rest = 0;
    if (!heap || !size) return 0;
    fn_2279_025b(heap, &h, 16);
    size += 0x20;
    size = (size + 15) & ~15L;
    need = size >> 4;
    if (h.total < need) return 0;
    b.next = h.free;
    found = 0;
    while (!found && b.next) {
        p = b.next;
        fn_2279_025b(p, &b, 32);
        if (b.paras >= need) {
            found = 1;
            break;
        }
    }
    if (!found) return 0;
    rest = b.paras - need;
    if (rest <= 2) {
        rest = 0;
        need = b.paras;
    }
    fn_15a7_064a(&h, 1, p);
    if (rest) fn_15a7_06e9(&h, 1, fn_2037_0002(p, need << 4), rest, -1L, 0);
    fn_15a7_06e9(&h, 0, p, need, tag, 0);
    h.freeParas -= need;
    fn_2279_025b(&h, heap, 16);
    return fn_2037_0002(p, 32);
}

int fn_15a7_0210(struct Heap far *heap, void far *mem)
{
    struct Blk far *p;
    struct Heap h;
    struct Blk b;

    if (!mem || !heap) return 0;
    fn_2279_025b(heap, &h, 16);
    p = fn_2037_0002(mem, -32);
    fn_2279_025b(p, &b, 32);
    fn_15a7_064a(&h, 0, p);
    fn_15a7_06e9(&h, 1, p, b.paras, -1L, 1);
    h.freeParas += b.paras;
    fn_2279_025b(&h, heap, 16);
    return 1;
}

void fn_15a7_02b6(void far *mem)
{
    unsigned t;

    if (mem) {
        mem = fn_2037_0002(mem, -32);
        mem = fn_2037_0002(mem, 12);
        t = g_384c >> 4;
        fn_2279_025b(&t, mem, 2);
    }
}

void far *fn_15a7_030c(struct Heap far *heap, long tag)
{
    struct Blk far *p;
    struct Heap h;
    struct Blk b;

    if (heap) {
        fn_2279_025b(heap, &h, 16);
        if (h.used) {
            b.next = h.used;
            while (b.next) {
                p = b.next;
                fn_2279_025b(p, &b, 32);
                if (b.tag == tag) return fn_2037_0002(p, 32);
            }
        }
    }
    return 0;
}

void far *fn_15a7_0382(struct Heap far *heap)
{
    struct Blk far *p;
    struct Blk far *best;
    struct Heap h;
    struct Blk b;
    unsigned t;

    if (!heap) return 0;
    fn_2279_025b(heap, &h, 16);
    best = 0;
    t = 0;
    b.next = h.used;
    while (b.next) {
        p = b.next;
        fn_2279_025b(p, &b, 32);
        if (fn_16cf_057a(fn_2037_0002(p, 32)) == -1 && (b.time < t || !best)) {
            t = b.time;
            best = p;
        }
    }
    if (best) best = fn_2037_0002(best, 32);
    return best;
}

void far *fn_15a7_043c(struct Heap far *heap)
{
    void far *p;
    struct Heap h;

    if (heap) {
        fn_2279_025b(heap, &h, 16);
        if (h.used) fn_0845_08a5("Mem free oldest from %lX used chain = %lX", 0x28, 0xf, 1, heap, h.used);
        p = fn_15a7_0382(heap);
        if (fn_15a7_0210(heap, p)) return p;
    }
    return 0;
}

long fn_15a7_04b0(struct Heap far *heap)
{
    long n;
    struct Heap h;

    if (!heap) return 0;
    fn_2279_025b(heap, &h, 16);
    n = (h.freeParas << 4) - 0x20 - 0xf;
    n = n > 0 ? n : 0;
    return n;
}

void fn_15a7_0501(struct Heap far *heap)
{
    struct Blk far *cur;
    struct Blk far *prev;
    struct Blk far *dst;
    long bytes;
    struct Heap h;
    struct Blk b;

    if (!heap) return;
    fn_2279_025b(heap, &h, 16);
    if (!h.freeParas) return;
    if (!h.free) return;
    prev = 0;
    cur = h.used;
    dst = fn_2037_0002(heap, 16);
    h.used = dst;
    while (cur) {
        fn_2279_025b(cur, &b, 32);
        bytes = b.paras << 4;
        if (cur != dst) fn_2279_025b(cur, dst, bytes);
        cur = b.next;
        if (b.next) b.next = fn_2037_0002(dst, bytes);
        b.prev = prev;
        fn_2279_025b(&b, dst, 32);
        prev = dst;
        dst = fn_2037_0002(dst, bytes);
    }
    h.free = 0;
    fn_15a7_06e9(&h, 1, dst, h.freeParas, -1L, 0);
    fn_2279_025b(&h, heap, 16);
}

void fn_15a7_064a(struct Heap far *h, int which, struct Blk far *blk)
{
    struct Blk far * far *head;
    struct Blk b;

    if (!h) return;
    if (!blk) return;
    if (which) head = &h->free;
    else head = &h->used;
    fn_2279_025b(blk, &b, 32);
    if (b.prev) fn_2279_025b(&b, b.prev, 4);
    else *head = b.next;
    if (b.next) fn_2279_025b(&b.prev, fn_2037_0002(b.next, 4), 4);
}

void fn_15a7_06e9(struct Heap far *h, int which, struct Blk far *blk, unsigned long paras, long tag, int merge)
{
    struct Blk far * far *head;
    struct Blk far *prev;
    struct Blk far *cur;
    unsigned long n;
    struct Blk b;
    struct Blk pb;
    int first;

    prev = 0;
    cur = 0;
    first = 1;
    if (!h) return;
    if (!blk) return;
    if (!paras) return;
    if (which) head = &h->free;
    else head = &h->used;
    if (*head == 0) {
        b.next = 0;
        b.prev = 0;
        b.paras = paras;
        b.time = g_384c >> 4;
        b.tag = tag;
        fn_2279_025b(&b, blk, 32);
        *head = blk;
        return;
    }
    cur = *head;
    fn_2279_025b(cur, &b, 32);
    while (cur && (unsigned long)cur < (unsigned long)blk) {
        fn_2279_025b(&b, &pb, 32);
        prev = cur;
        cur = b.next;
        if (cur) fn_2279_025b(cur, &b, 32);
    }
    if (merge) {
        if (prev && fn_2037_0002(prev, pb.paras << 4) == blk) {
            pb.paras += paras;
            fn_2279_025b(&pb, prev, 32);
            blk = prev;
            prev = 0;
            first = 0;
            n = pb.paras;
        } else n = paras;
        if (cur && fn_2037_0002(blk, n << 4) == cur) {
            if (!first) {
                pb.paras += b.paras;
                pb.next = b.next;
                fn_2279_025b(&pb, blk, 32);
                cur = b.next;
            } else {
                cur = b.next;
                paras += b.paras;
            }
        }
    }
    if (prev) fn_2279_025b(&blk, prev, 4);
    else if (first) *head = blk;
    if (cur) fn_2279_025b(&blk, fn_2037_0002(cur, 4), 4);
    if (first) {
        b.prev = prev;
        b.next = cur;
        b.paras = paras;
        b.time = g_384c >> 4;
        b.tag = tag;
        fn_2279_025b(&b, blk, 32);
    }
}
