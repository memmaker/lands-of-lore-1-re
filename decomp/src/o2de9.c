/* o2de9: IFF FORM file chunk reader/writer */
/* FLAGS: -ml -3 -Y */

int fn_1809_0000(char far *name, int mode);
long fn_1809_084d(int h, void far *buf, long n);
long fn_1809_0bde(int h, void far *buf, long n);
long fn_1809_0e76(int h, long off, int whence);
void fn_1809_058d(int h);
unsigned long fn_2315_0008(unsigned long v);

int ovr_2de9_0020(char far *name)
{
    long id;
    int h;

    h = fn_1809_0000(name, 1);
    fn_1809_084d(h, &id, 4);
    if (id == 0x4d524f46L) fn_1809_0e76(h, 4, 1);
    else {
        fn_1809_058d(h);
        h = -1;
    }
    return h;
}

void ovr_2de9_0025(int h)
{
    if (h != -1) fn_1809_058d(h);
}

unsigned long ovr_2de9_002a(int h, long id)
{
    long cid;
    unsigned long size;
    char first;

    first = 1;
    for (;;) {
        if (fn_1809_084d(h, &cid, 4) != 4 && !first) break;
        if (cid == 0) {
            if (fn_1809_084d(h, &cid, 4) != 4 && !first) break;
        }
        if (fn_1809_084d(h, &size, 4) != 4 && !first) break;
        size = fn_2315_0008(size);
        if (id == cid) {
            fn_1809_0e76(h, -8, 1);
            return size;
        } else if (first) {
            fn_1809_0e76(h, 12, 0);
            first = 0;
        } else {
            size = (size + 1) & ~1L;
            fn_1809_0e76(h, size, 1);
        }
    }
    return 0;
}

unsigned long ovr_2de9_002f(int h, long id, void far *buf, unsigned long max)
{
    long cid;
    unsigned long size;
    char first;

    first = 1;
    for (;;) {
        if (fn_1809_084d(h, &cid, 4) != 4 && !first) break;
        if (cid == 0) {
            if (fn_1809_084d(h, &cid, 4) != 4 && !first) break;
        }
        if (fn_1809_084d(h, &size, 4) != 4 && !first) break;
        size = fn_2315_0008(size);
        if (id == cid) {
            max = max < size ? max : size;
            fn_1809_084d(h, buf, max);
            size = (size + 1) & ~1L;
            if (max < size) fn_1809_0e76(h, size - max, 1);
            return max;
        } else if (first) {
            fn_1809_0e76(h, 12, 0);
            first = 0;
        } else {
            size = (size + 1) & ~1L;
            fn_1809_0e76(h, size, 1);
        }
    }
    return 0;
}

void ovr_2de9_0034(int h, long id, void far *buf, long len)
{
    long cur;
    long pos;
    long end;
    long tmp;
    char zero;
    int odd;

    zero = 0;
    cur = fn_1809_0e76(h, 0, 1);
    end = fn_1809_0e76(h, 0, 2);
    fn_1809_0e76(h, cur, 0);
    if (len == 0) return;
    tmp = id;
    odd = (int)len & 1;
    fn_1809_0bde(h, &tmp, 4);
    pos = fn_1809_0e76(h, 0, 1);
    fn_1809_0bde(h, &tmp, 4);
    fn_1809_0bde(h, buf, len);
    cur = fn_1809_0e76(h, 0, 1);
    if (odd) fn_1809_0bde(h, &zero, 1);
    fn_1809_0e76(h, pos, 0);
    tmp = fn_2315_0008(cur - pos - 4);
    fn_1809_0bde(h, &tmp, 4);
    if (end < cur) {
        fn_1809_0e76(h, 4, 0);
        tmp = fn_2315_0008(cur + odd - 8);
        fn_1809_0bde(h, &tmp, 4);
    }
    fn_1809_0e76(h, 0, 2);
}
