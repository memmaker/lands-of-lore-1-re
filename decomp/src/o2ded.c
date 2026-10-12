/* o2ded: whole-file load/save helpers and CPS image loading (header, optional palette, LCW/RLE unpacking) */
/* FLAGS: -ml -3 -Y */

struct CpsHdr {
    char comp;          /* +0 0 raw, 3 LCW, 4 RLE */
    char c1;
    long size;          /* +2 unpacked size */
    unsigned pal;       /* +6 palette bytes following the header */
};

extern long g_368b[];
int fn_1809_0000(char far *name, int mode);
long fn_1809_084d(int h, void far *buf, long n);
long fn_1809_0bde(int h, void far *buf, long n);
void fn_1809_058d(int h);
long fn_1809_120c(int h);
long fn_1809_0e76(int h, long off, int whence);
void far *fn_203b_0007(long size, int flags);
void far *fn_215f_0003(int page);
void far *fn_2037_0002(void far *p, long n);
void fn_2279_025b(void far *s, void far *d, long n);
long fn_232c_0111(void far *s, void far *d, long n);
int fn_232c_000c(void far *s, void far *d, int n);
long ovr_2ded_0034(struct CpsHdr far *src, void far *dst);

long ovr_2ded_0020(char far *name, void far *buf, long n)
{
    int h;

    h = fn_1809_0000(name, 1);
    n = fn_1809_084d(h, buf, n);
    fn_1809_058d(h);
    return n;
}

long ovr_2ded_0025(char far *name, void far *buf, long n)
{
    int h;

    h = fn_1809_0000(name, 2);
    n = fn_1809_0bde(h, buf, n);
    fn_1809_058d(h);
    return n;
}

void far *ovr_2ded_002a(char far *name, int flags)
{
    long size;
    void far *p;
    int h;

    h = fn_1809_0000(name, 1);
    size = fn_1809_120c(h);
    p = fn_203b_0007(size, flags);
    if (p != 0) fn_1809_084d(h, p, size);
    fn_1809_058d(h);
    return p;
}

long ovr_2ded_002f(char far *name, int page, int dpage, void far *pal)
{
    unsigned len;
    struct CpsHdr far *hdr;
    void far *q;
    int h;
    unsigned n;

    hdr = fn_215f_0003(page);
    h = fn_1809_0000(name, 1);
    fn_1809_084d(h, &len, 2L);
    fn_1809_084d(h, hdr, 8L);
    len -= 8;
    n = hdr->pal;
    if (pal != 0 && n != 0)
        fn_1809_084d(h, pal, (unsigned long)n);
    else
        fn_1809_0e76(h, (unsigned long)n, 1);
    hdr->pal = 0;
    len -= n;
    q = fn_2037_0002(fn_215f_0003(page), g_368b[page] - ((unsigned long)len + 8));
    fn_2279_025b(hdr, q, 8L);
    fn_1809_084d(h, (char far *)q + 8, (unsigned long)len);
    fn_1809_058d(h);
    return ovr_2ded_0034(q, fn_215f_0003(dpage));
}

long ovr_2ded_0034(struct CpsHdr far *src, void far *dst)
{
    unsigned pal;
    int comp;
    long size = 0;

    if (src == 0 || dst == 0) return 0;
    size = src->size;
    pal = src->pal;
    comp = src->comp;
    src = fn_2037_0002(src, (unsigned long)pal + 8);
    switch (comp) {
    default:
    case 0:
        fn_2279_025b(src, dst, size);
        break;
    case 3:
        fn_232c_0111(src, dst, size);
        break;
    case 4:
        fn_232c_000c(src, dst, (int)size);
        break;
    }
    return size;
}
