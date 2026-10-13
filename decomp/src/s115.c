/* s115: WW library -- memory allocator (Alloc/Free/Resize/Ram_Free/Heap_Size/Total_Ram_Free)
 * A conventional block keeps a flag byte just below the returned pointer; paragraph-aligned blocks (flag 0x20)
 * store 15 - (padding) in the low nibble. Flags 0x40/0x80 route to other memory managers (s147, s036). */
#include <alloc.h>
#include <mem.h>
#include <dos.h>
#include <stdlib.h>

extern unsigned long g_35d2;   /* lowest free memory seen */
extern unsigned long g_35d6;   /* largest amount used */
extern unsigned long g_35da;   /* free memory at the first allocation */
extern unsigned long g_35de;   /* size of the flag-8 block */
extern int (far *g_363e)(void);/* out of memory callback: nonzero = retry */
extern int g_3642;             /* allocated block count */
extern char far *g_1594;       /* "heap corrupt" message */

void far *fn_19ba_0045(unsigned long size, unsigned flags, int a);
void far *fn_2365_0002(unsigned long size, int a);
void far *fn_2279_02b5(void far *p);
int fn_2365_063f(void far *p);
void fn_2365_0209(void far *p);
int fn_19ba_0086(void far *p);
void fn_19ba_004e(void far *p);
long fn_2365_0c28(int a);
long fn_19ba_0038(int a);
long fn_19ba_002b(int a);
long fn_19ba_001e(int a);
long ovr_2e07_002a(int a);
void fn_2309_000c(void);
void fn_2093_000e(char far *s);
void fn_2169_06e9(void);
void fn_2347_0034(int a);

long fn_203b_03b4(register unsigned flags);
long fn_203b_04ce(register unsigned flags);

void far *fn_203b_0007(unsigned long size, unsigned flags)
{
    char far *p;
    unsigned long req;
    unsigned long avail;
    char far *q;

    p = 0;
    if (g_35da == 0)
        g_35da = fn_203b_03b4(0);
    if (p == 0 && (flags & 0x80))
        p = fn_19ba_0045(size, flags, flags & 2 ? 1 : 0);
    if (p == 0 && (flags & 0x40))
        p = fn_2365_0002(size, flags & 2 ? 1 : 0);
    if (!(flags & 0xc0)) {
        req = size;
        size += flags & 0x20 ? 0x10 : 1;
        for (;;) {          /* retry through the out of memory callback */
            while (!(p = farmalloc(size)))
                break;
            if (p || !g_363e)
                break;
            if (!g_363e())
                break;
        }
        if (p == 0)
            return 0;
        p = fn_2279_02b5(p);
        if (flags & 0x20) {
            register unsigned char pad;

            pad = 0xf - (unsigned char)FP_OFF(p);
            p[pad] = pad | flags;
            p = MK_FP(FP_SEG(p) + 1, 0);
            goto done;
        }
        {
            *p = flags;
            p++;
        }
done:
        if (flags & 0x10) {
            q = p;
            while (req > 0x7d00) {
                memset(q, 0, 0x7d00);
                req -= 0x7d00;
                q = MK_FP(FP_SEG(q) + 0x7d0, FP_OFF(q));
            }
            memset(q, 0, (unsigned)req);
        }
        if (flags & 8)
            g_35de += size;
        avail = fn_203b_04ce(0) + g_35de;
        if (avail < g_35d2)
            g_35d2 = avail;
        if (g_35da - avail > g_35d6)
            g_35d6 = g_35da - avail;
    }
    g_3642++;
    return p;
}

void fn_203b_0203(char far *p)
{
    char far *hdr;
    unsigned char fl;

    if (p == 0)
        return;
    if (fn_2365_063f(p)) {
        fn_2365_0209(p);
        p = 0;
    }
    if (fn_19ba_0086(p)) {
        fn_19ba_004e(p);
        p = 0;
    }
    if (p != 0) {
        hdr = MK_FP(FP_SEG(p) - 1, FP_OFF(p) + 0xf);
        fl = *hdr;
        if (fl & 8)
            g_35de = 0;
        if (fl & 0x20)
            farfree(MK_FP(FP_SEG(hdr), 0xf - (fl & 0xf)));
        else if (FP_OFF(p))
            farfree(MK_FP(FP_SEG(p), FP_OFF(p) - 1));
        else
            farfree(MK_FP(FP_SEG(p) - 1, FP_OFF(p) + 0xf));
    }
    g_3642--;
}

/* only diff: original has `add al,0ffh` where BCC emits `dec al` */
/* NONMATCHING */
void far *fn_203b_02dc(char far *p, unsigned long size)
{
    char far *hdr;
    unsigned char lo;
    unsigned char hi;

    if (FP_OFF(p))
        hdr = (char far *)MK_FP(FP_SEG(p), FP_OFF(p)) - 1;
    else
        hdr = MK_FP(FP_SEG(p) - 1, FP_OFF(p) + 0xf);
    lo = *hdr & 0xf;
    hi = *hdr & 0xf0;
    size += hi & 0x20 ? 0x10 : 1;
    if (hi & 0x20) {
        hdr = farrealloc(MK_FP(FP_SEG(hdr), 0xf - lo), size);
        lo = 0x10 - (unsigned char)FP_OFF(hdr);
        (hdr + lo)[-1] = (lo + 0xff) | hi;
        hdr = MK_FP(FP_SEG(hdr) + 1, 0);
    } else {
        hdr = farrealloc(hdr, size);
        if (hdr != 0) {
            *hdr = hi;
            hdr++;
        }
    }
    return hdr;
}

/* largest free block */
long fn_203b_03b4(register unsigned flags)
{
    long best;
    struct farheapinfo hi;

    if (flags & 0x40)
        return fn_2365_0c28(flags & 2 ? 1 : 0);
    if (flags & 0x80)
        return fn_19ba_0038(flags & 2 ? 1 : 0);
    if (farheapcheck() == _HEAPCORRUPT) {
        fn_2309_000c();
        fn_2093_000e(g_1594);
        fn_2169_06e9();
        exit(5);
    }
    best = farcoreleft();
    hi.ptr = 0;
    while (farheapwalk(&hi) == _HEAPOK) {
        if (hi.in_use == 0 && hi.size > best)
            best = hi.size;
    }
    best -= 0x10;
    return best > 0 ? best : 0;
}

long fn_203b_0482(register unsigned flags)
{
    if (flags & 0x40)
        return ovr_2e07_002a(flags & 2 ? 1 : 0);
    if (flags & 0x80)
        return fn_19ba_001e(flags & 2 ? 1 : 0);
    return g_35da;
}

/* total free memory */
long fn_203b_04ce(register unsigned flags)
{
    long total;
    struct farheapinfo hi;

    if (flags & 0x40)
        return fn_2365_0c28(flags & 2 ? 1 : 0);
    if (flags & 0x80)
        return fn_19ba_002b(flags & 2 ? 1 : 0);
    if (farheapcheck() == _HEAPCORRUPT) {
        fn_2347_0034(9);
        fn_2093_000e(g_1594);
        fn_2169_06e9();
        fn_2309_000c();
        exit(5);
    }
    total = farcoreleft();
    hi.ptr = 0;
    while (farheapwalk(&hi) == _HEAPOK) {
        if (hi.in_use == 0)
            total += hi.size;
    }
    return total;
}
