/* s071: WW library -- shape file header / frame table accessors */
struct ShpHdr {
    char pad0[2];
    unsigned char b2;   /* 2 */
    int w3;             /* 3 */
    unsigned char b5;   /* 5 */
    char pad6[2];
    int w8;             /* 8 */
};
void far fn_2279_025b(void far *src, void far *dst, long n);
void far *far fn_2037_0002(void far *p, long off);
int far fn_2365_063f(void far *p);
int far fn_19ba_0086(void far *p);
void far *far fn_226d_0007(void far *p, int flags);
void far fn_226d_004e(void far *p);

int fn_1f36_0001(void far *p)
{
    int n;
    n = 0;
    fn_2279_025b(p, &n, 2L);
    return n;
}

int fn_1f36_0029(void far *p)
{
    int n;
    if (p == 0)
        return 0;
    fn_2279_025b(fn_2037_0002(p, 6L), &n, 2L);
    return n;
}

void far *fn_1f36_0064(void far *p, int idx)
{
    long off;
    int n;
    if (p == 0 || idx < 0)
        return 0;
    if (fn_2365_063f(p) || fn_19ba_0086(p)) {
        n = fn_1f36_0001(p);
        if (idx >= n)
            return 0;
        fn_2279_025b(fn_2037_0002(p, idx * sizeof(long) + 2), &off, 4L);
    } else {
        n = *(int far *)p;
        if (idx >= n)
            return 0;
        off = *(long far *)fn_2037_0002(p, idx * sizeof(long) + 2);
    }
    return fn_2037_0002(p, off + 2);
}

int fn_1f36_013d(void far *p, int idx)
{
    int n;
    n = 0;
    if (p) {
        p = fn_2037_0002(p, -((idx + 1) * 2));
        fn_2279_025b(p, &n, 2L);
    }
    return n;
}

int fn_1f36_018e(void far *p)
{
    struct ShpHdr far *h;
    int r;
    r = 0;
    h = fn_226d_0007(p, 0);
    if (h) {
        r = h->b2;
        h->b2 = h->b5;
        fn_226d_004e(p);
    }
    return r;
}

int fn_1f36_01e2(void far *p)
{
    struct ShpHdr far *h;
    int r;
    r = 0;
    h = fn_226d_0007(p, 0);
    if (h) {
        r = h->w3;
        fn_226d_004e(p);
    }
    return r;
}

int fn_1f36_0224(void far *p)
{
    struct ShpHdr far *h;
    int r;
    r = 0;
    h = fn_226d_0007(p, 0);
    if (h) {
        r = h->b2;
        fn_226d_004e(p);
    }
    return r;
}

int fn_1f36_026a(void far *p)
{
    struct ShpHdr far *h;
    int r;
    r = 0;
    h = fn_226d_0007(p, 0);
    if (h) {
        r = h->b5;
        fn_226d_004e(p);
    }
    return r;
}

int fn_1f36_02b0(void far *p, unsigned char v)
{
    struct ShpHdr far *h;
    int r;
    r = 0;
    h = fn_226d_0007(p, 0);
    if (h) {
        r = h->b2;
        h->b2 = v;
        fn_226d_004e(p);
    }
    return r;
}

int fn_1f36_0300(void far *p)
{
    struct ShpHdr far *h;
    int r;
    r = 0;
    h = fn_226d_0007(p, 0);
    if (h) {
        r = h->w8;
        fn_226d_004e(p);
    }
    return r;
}
