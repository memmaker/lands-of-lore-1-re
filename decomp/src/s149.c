/* s149: WW library -- binary and linear search over arrays that may live in XMS/EMS-backed memory
 * (such elements are copied to `tmp` before comparing) */
int far fn_2365_063f(void far *p);
int far fn_19ba_0086(void far *p);
void far *far fn_2037_0002(void far *p, long off);
void far fn_2279_025b(void far *src, void far *dst, unsigned long n);

void far *fn_242d_000f(void far *key, void far *tmp, void far *base, int n, unsigned size,
                       int (far *cmp)(void far *, void far *))
{
    int hi, lo;
    void far *p;
    int r;
    int special;
    register int mid;
    register unsigned sz = size;

    special = fn_2365_063f(base) || fn_19ba_0086(base);
    lo = 0;
    hi = n - 1;
    for (;;) {
        mid = (lo + hi) >> 1;
        if (special) {
            p = fn_2037_0002(base, (long)mid * sz);
            fn_2279_025b(p, tmp, (unsigned long)sz);
            r = cmp(key, tmp);
        } else {
            p = (char far *)base + mid * sz;
            r = cmp(key, p);
        }
        if (r == 0)
            break;
        if (lo > hi)
            return 0;
        if (r < 0)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return p;
}

void far *fn_242d_0108(void far *key, void far *tmp, void far *base, unsigned n, unsigned size,
                       int (far *cmp)(void far *, void far *))
{
    int r;
    unsigned long off;
    void far *p;
    int special;
    register unsigned i;
    register unsigned cnt = n;

    special = fn_2365_063f(base) || fn_19ba_0086(base);
    for (off = i = 0; i < cnt; off += size, i++) {
        if (special) {
            p = fn_2037_0002(base, off);
            fn_2279_025b(p, tmp, (unsigned long)size);
            r = cmp(key, tmp);
        } else {
            p = (char far *)base + off;
            r = cmp(key, p);
        }
        if (r == 0)
            break;
    }
    if (i == cnt)
        return 0;
    else
        return p;
}
