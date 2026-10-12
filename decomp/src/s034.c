/* s034: buffered file layer (handles into loose files, .PAK members and cached PAK data) */
#include <string.h>
#include <io.h>
#include <stdlib.h>

typedef struct PakEnt {        /* 20 bytes, f_27fc_0000[] */
    char far *name;
    long size;                 /* +04 */
    void far *data;            /* +08 cached contents (or PAK buffer) */
    long off;                  /* +0c offset inside the PAK */
    unsigned char pak;         /* +10 index of the containing .PAK entry */
    unsigned char refs;        /* +11 open count */
    unsigned flags;            /* +12 low byte = cache age, 0x1000 = inside a PAK */
} PakEnt;

typedef struct FileH {         /* 20 bytes, f_2c12_0000[20] */
    int free;                  /* +00 */
    int fd;                    /* +02 DOS handle, 0 = served from memory */
    long pos;                  /* +04 */
    long start;                /* +08 offset of the member inside the PAK file */
    int ent;                   /* +0c PakEnt index or -1 */
    int mode;                  /* +0e */
    char far *name;            /* +10 */
} FileH;

extern char g_abde;
extern int g_ae4d, g_ae57;
extern char g_ae59[], g_aeaa[];
extern PakEnt far *g_2aa7;
extern PakEnt far f_27fc_0000[];
extern FileH far f_2c12_0000[];
extern int (far *g_3638)(int code, char far *name);

void fn_2148_002c(int d);
void fn_2148_004d(int fd);
int fn_2148_000f(void);
int fn_2148_0121(char far *name, int mode, int perm);
long fn_2148_0094(int fd, long off, int whence);
unsigned fn_2148_00c9(int fd, void far *buf, unsigned n);
unsigned fn_2148_00f5(int fd, void far *buf, unsigned n);
int fn_2148_014d(char far *s);
int fn_1981_000a(char far *name);
int fn_1981_01af(char far *name);
PakEnt far *fn_1981_02c0(int i, PakEnt far *buf);
void fn_1981_031f(int i, PakEnt far *buf);
char far *fn_1981_0365(char far *name);
void far *fn_203b_0007(unsigned long size, int flags);
void fn_203b_0203(void far *p);
long fn_203b_03b4(int flags);
long fn_203b_0482(int flags);
void far *fn_2279_02b5(void far *p);
void fn_2279_025b(void far *s, void far *d, unsigned long n);
void far *fn_2037_0002(void far *p, long off);
int fn_2365_063f(void far *p);
void fn_2309_000c(void);

int fn_1809_0000(char far *name, int mode);
void fn_1809_058d(int h);
long fn_1809_084d(int h, void far *buf, unsigned long n);
long fn_1809_0bde(int h, void far *buf, unsigned long n);
long fn_1809_0e76(int h, long off, int whence);
int fn_1809_11b9(char far *name);
long fn_1809_120c(int h);
int fn_1809_1279(int h, int code, char far *name);
int fn_1809_12c0(int code, char far *name);
void fn_1809_1319(int code, char far *name);
long fn_1809_133b(int h, void far *buf, unsigned n);
int fn_1809_1460(char far *name, int omode);
int fn_1809_1502(int idx, int h);

int fn_1809_0000(char far *name, int mode)
{
    int fd;
    int omode;
    int reopened;
    PakEnt far *ent;
    PakEnt far *pak;
    FileH far *fh;
    long len;
    int i;
    PakEnt far *e;
    PakEnt far *prev;
    PakEnt buf1;
    PakEnt buf2;
    char nm[14];
    int idx;
    int h;
    int d;

    g_abde++;
    fh = f_2c12_0000;
    for (h = 0; h < 20; h++, fh++)
        if (fh->free) break;
    if (h == 20) fn_1809_1319(3, name);
    idx = fn_1981_01af(name);
    ent = fn_1981_02c0(idx, &buf1);
    fn_2148_002c(g_ae59[0] - 'A');
    reopened = 0;
    if (idx != -1 && (ent->flags & 0x1000) && ent->data == 0) {
        d = fn_2148_0121(name, 0x8001, 0x100);
        if (d != -1) {
            fn_2148_004d(d);
            reopened = 1;
        }
    }
    if ((mode & 2) && idx != -1 && ent->data) {
        if (ent->flags & 0x1000) {
            fn_203b_0203(ent->data);
            ent->data = 0;
            fn_1981_031f(idx, &buf1);
        } else {
            fn_1809_1319(9, name);
        }
    }
    if (ent->data && idx != -1) {
        fh->ent = idx;
        fh->free = 0;
        fh->pos = 0;
        fh->name = ent->name;
        fh->fd = 0;
        fh->mode = mode;
        if (ent->flags & 0x1000) pak = fn_1981_02c0(ent->pak, &buf2);
        else pak = 0;
        if (pak && pak->data == ent->data) {
            fh->start = ent->off;
            pak->refs++;
            fn_1981_031f(ent->pak, &buf2);
            goto done;
        }
        fh->start = 0;
        goto done;
    }
    if (idx != -1 && (ent->flags & 0x1000) && !reopened && !(mode & 2)) {
        pak = fn_1981_02c0(ent->pak, &buf2);
        h = fn_1809_0000(fn_1981_0365(pak->name), mode);
        pak = fn_1981_02c0(ent->pak, &buf2);
        fh = &f_2c12_0000[h];
        if (g_2aa7 == f_27fc_0000 && !(f_27fc_0000[fh->ent].flags & 0x100)) {
            e = 0;
            prev = 0;
            while (fn_1809_084d(h, &len, 4L), len) {
                i = 0;
                do {
                    fn_1809_084d(h, nm + i, 1L);
                } while (nm[i++]);
                i = fn_1981_01af(nm);
                if (i != -1) {
                    e = &f_27fc_0000[i];
                    if ((e->flags & 0x1000) && e->pak == fh->ent) {
                        e->off = len + f_27fc_0000[fh->ent].off;
                        if (prev) prev->size = e->off - prev->off;
                        prev = e;
                    }
                }
            }
            if (prev) prev->size = fn_1809_120c(h) - prev->off;
            f_27fc_0000[fh->ent].flags |= 0x100;
        }
        ent->data = pak->data;
        fn_1981_031f(idx, &buf1);
        fh->ent = idx;
        fh->name = ent->name;
        fh->start = ent->off;
        fn_1809_0e76(h, 0L, 0);
        goto cache;
    }
    omode = 0x8001;
    switch (mode) {
    case 1: omode = 0x8001; break;
    case 3: omode = 0x8004; break;
    case 2: omode = 0x8302; break;
    default: fn_1809_1319(1, name);
    }
    if ((mode & 1) && !fn_1809_11b9(name)) {
fail:
        g_abde--;
        return -1;
    }
    while ((fd = fn_1809_1460(name, omode)) == -1) {
        fn_2148_014d(g_aeaa);
        fn_2148_014d(g_ae59);
        if (!fn_1809_12c0(2, name)) goto fail;
    }
    if (reopened && idx != -1) {
        ent->flags &= ~0x1000;
        ent->size = 0;
        fn_1981_031f(idx, &buf1);
    }
    if (idx != -1) {
        ent->size = fn_2148_0094(fd, 0L, 2);
        fn_1981_031f(idx, &buf1);
        fn_2148_0094(fd, 0L, 0);
    }
    fh->ent = idx;
    fh->pos = 0;
    fh->start = 0;
    fh->free = 0;
    fh->fd = fd;
    fh->mode = mode;
    if (idx != -1) fh->name = ent->name;
    else fh->name = 0;
    if (!(mode & 2)) {
cache:
        fn_1809_1502(idx, h);
    }
done:
    if (idx != -1) {
        ent = fn_1981_02c0(idx, &buf1);
        ent->refs++;
        fn_1981_031f(idx, &buf1);
    }
    g_abde--;
    return h;
}

void fn_1809_058d(int h)
{
    int freed;
    int keep;
    int refs;
    PakEnt far *pak;
    PakEnt far *ent;
    PakEnt buf2;
    PakEnt buf1;
    int idx;

    freed = 0;
    keep = 0;
    pak = 0;
    ent = 0;
    if (!fn_1809_1279(h, 4, 0)) return;
    g_abde++;
    idx = f_2c12_0000[h].ent;
    ent = fn_1981_02c0(idx, &buf1);
    if (idx != -1) {
        if ((ent->flags & 0xff) == 1) keep = 1;
        else ent->flags &= 0xff00;
        refs = --ent->refs;
        fn_1981_031f(idx, &buf1);
        if (ent->flags & 0x1000) {
            pak = fn_1981_02c0(ent->pak, &buf2);
            if (pak->data == ent->data) {
                if ((pak->flags & 0xff) == 1) keep = 1;
                else pak->flags &= 0xff00;
                refs = --pak->refs;
                fn_1981_031f(ent->pak, &buf2);
            }
        }
    }
    if (idx != -1 && ent->data) {
        if (pak && pak->data == ent->data) {
            if (!ent->refs) ent->data = 0;
            if (!pak->refs && (pak->flags & 0x800)) {
                fn_203b_0203(pak->data);
                pak->data = 0;
                freed = 1;
            }
        } else if ((ent->flags & 0x800) && !ent->refs) {
            fn_203b_0203(ent->data);
            ent->data = 0;
            freed = 1;
        }
        fn_1981_031f(idx, &buf1);
        if (pak) fn_1981_031f(ent->pak, &buf2);
        if (!keep && !freed && !refs && !(ent->flags & 0x6000)) {
            for (idx = 0; (ent = fn_1981_02c0(idx, &buf1))->name; idx++) {
                if (ent->data && !ent->refs && !(ent->flags & 0x6000)) {
                    if ((ent->flags & 0xff) == 0xff) {
                        fn_203b_0203(ent->data);
                        ent->data = 0;
                    } else {
                        ent->flags++;
                    }
                    fn_1981_031f(idx, &buf1);
                }
            }
        }
    } else {
        fn_2148_004d(f_2c12_0000[h].fd);
    }
    f_2c12_0000[h].free = 1;
    g_abde--;
}

long fn_1809_084d(int h, void far *buf, unsigned long n)
{
    int fd;
    long avail;
    int idx;
    long total;
    PakEnt far *ent;
    unsigned long chunk;
    void far *tmp;
    unsigned long got;
    PakEnt b;

    if (buf == 0 || n == 0 || !fn_1809_1279(h, 5, 0)) return 0;
    g_abde++;
    fd = f_2c12_0000[h].fd;
    idx = f_2c12_0000[h].ent;
    ent = fn_1981_02c0(idx, &b);
    avail = ent->size;
    if (avail && idx != -1 && ent->size)
        n = ent->size - f_2c12_0000[h].pos < n ? ent->size - f_2c12_0000[h].pos : n;
    total = 0;
    if (n) {
        buf = fn_2279_02b5(buf);
        if (fd) {
            if (fn_2365_063f(buf)) {
                chunk = (fn_203b_03b4(0) >> 1) & ~0xfL;
                chunk = chunk < 0xfff0 ? chunk : 0xfff0;
                tmp = fn_203b_0007(chunk, 0x28);
                while (n) {
                    g_ae4d = 0;
                    got = fn_2148_00c9(fd, tmp, n < chunk ? (unsigned)n : (unsigned)chunk);
                    if (g_ae4d) {
                        got = fn_1809_133b(h, tmp, n < chunk ? (unsigned)n : (unsigned)chunk);
                        fd = f_2c12_0000[h].fd;
                    }
                    fn_2279_025b(tmp, buf, got);
                    n -= got;
                    total = total + got;
                    f_2c12_0000[h].pos = f_2c12_0000[h].pos + got;
                    if (got < chunk) break;
                    buf = (void far *)((long)buf + got);
                }
                fn_203b_0203(tmp);
            } else {
                while (n) {
                    g_ae4d = 0;
                    chunk = fn_2148_00c9(fd, buf, n < 0xfff0 ? (unsigned)n : 0xfff0);
                    if (g_ae4d) {
                        chunk = fn_1809_133b(h, buf, n < 0xfff0 ? (unsigned)n : 0xfff0);
                        fd = f_2c12_0000[h].fd;
                    }
                    n -= chunk;
                    total += chunk;
                    f_2c12_0000[h].pos += chunk;
                    if (chunk < 0xfff0) break;
                    buf = fn_2037_0002(buf, chunk);
                }
            }
        } else {
            fn_2279_025b((void far *)((long)ent->data + f_2c12_0000[h].start + f_2c12_0000[h].pos), buf, n);
            total = n;
            f_2c12_0000[h].pos = f_2c12_0000[h].pos + n;
        }
    }
    fn_1981_031f(idx, &b);
    g_abde--;
    return total;
}

long fn_1809_0bde(int h, void far *buf, unsigned long n)
{
    int fd;
    long total;
    PakEnt far *ent;
    unsigned long chunk;
    void far *tmp;
    unsigned long got;
    PakEnt b;
    int idx;

    if (!fn_1809_1279(h, 6, 0)) return 0;
    fd = f_2c12_0000[h].fd;
    idx = f_2c12_0000[h].ent;
    ent = fn_1981_02c0(idx, &b);
    if (fd == 0) {
        fn_1809_1319(9, fn_1981_0365(ent->name));
        return 0;
    }
    g_abde++;
    total = 0;
    if (fn_2365_063f(buf)) {
        chunk = (fn_203b_03b4(0) >> 1) & ~0xfL;
        chunk = chunk < 0xfff0 ? chunk : 0xfff0;
        tmp = fn_203b_0007(chunk, 0x28);
        while (n) {
            got = n < chunk ? n : chunk;
            fn_2279_025b(buf, tmp, got);
            got = fn_2148_00f5(fd, tmp, (unsigned)got);
            n -= got;
            total = total + got;
            f_2c12_0000[h].pos = f_2c12_0000[h].pos + got;
            if (!got) break;
            if (idx != -1)
                ent->size = f_2c12_0000[h].pos < ent->size ? ent->size : f_2c12_0000[h].pos;
            buf = (void far *)((long)buf + got);
        }
        fn_203b_0203(tmp);
    } else {
        while (n) {
            chunk = fn_2148_00f5(fd, buf, n < 0xfff0 ? (unsigned)n : 0xfff0);
            n -= chunk;
            total += chunk;
            f_2c12_0000[h].pos += chunk;
            if (!chunk) break;
            if (idx != -1)
                ent->size = f_2c12_0000[h].pos < ent->size ? ent->size : f_2c12_0000[h].pos;
            buf = (void far *)((long)buf + chunk);
            buf = fn_2279_02b5(buf);
        }
    }
    fn_1981_031f(idx, &b);
    g_abde--;
    return total;
}

long fn_1809_0e76(int h, long off, int whence)
{
    int fd;
    int idx;
    PakEnt far *ent;
    PakEnt b;

    if (!fn_1809_1279(h, 7, 0)) return 0;
    g_abde++;
    idx = f_2c12_0000[h].ent;
    fd = f_2c12_0000[h].fd;
    ent = fn_1981_02c0(idx, &b);
    if (!fd) {
        switch (whence) {
        case 0:
            off = off < 0 ? 0 : off;
            f_2c12_0000[h].pos = 0;
            break;
        case 2:
            off = off > 0 ? 0 : off;
            f_2c12_0000[h].pos = ent->size;
            break;
        case 1:
            break;
        default:
            fn_1809_1319(8, fn_1981_0365(f_2c12_0000[h].name));
        }
        f_2c12_0000[h].pos += off;
        f_2c12_0000[h].pos = f_2c12_0000[h].pos < ent->size - 1 ? f_2c12_0000[h].pos : ent->size - 1;
        f_2c12_0000[h].pos = f_2c12_0000[h].pos > 0 ? f_2c12_0000[h].pos : 0;
    } else if (idx != -1 && (ent->flags & 0x1000)) {
        switch (whence) {
        case 0:
            f_2c12_0000[h].pos = off;
            break;
        case 2:
            off = off > 0 ? 0 : off;
            if (-off > ent->size) fn_1809_1319(8, fn_1981_0365(f_2c12_0000[h].name));
            f_2c12_0000[h].pos = ent->size + off;
            break;
        case 1:
            f_2c12_0000[h].pos += off;
            if (f_2c12_0000[h].pos < 0) f_2c12_0000[h].pos = 0;
            if (f_2c12_0000[h].pos >= ent->size) f_2c12_0000[h].pos = ent->size;
            break;
        default:
            fn_1809_1319(8, fn_1981_0365(f_2c12_0000[h].name));
        }
        fn_2148_0094(fd, f_2c12_0000[h].pos + f_2c12_0000[h].start, 0);
    } else {
        f_2c12_0000[h].pos = fn_2148_0094(fd, off, whence);
        if (idx != -1) f_2c12_0000[h].pos -= f_2c12_0000[h].start;
    }
    g_abde--;
    return f_2c12_0000[h].pos;
}

int fn_1809_11b9(char far *name)
{
    if (!name) return 0;
    while (!fn_1981_000a(name)) {
        do {
            if (!fn_1809_12c0(2, name)) return 0;
            fn_2148_002c(g_aeaa[0] - 'A');
        } while (fn_2148_014d(g_aeaa));
    }
    return 1;
}

long fn_1809_120c(int h)
{
    PakEnt far *ent;
    PakEnt b;

    if (f_2c12_0000[h].ent != -1) {
        ent = fn_1981_02c0(f_2c12_0000[h].ent, &b);
        if (ent->size) return ent->size;
    }
    return filelength(f_2c12_0000[h].fd);
}

int fn_1809_1279(int h, int code, char far *name)
{
    if (h < 0 || h >= 20) fn_1809_1319(code, name);
    if (f_2c12_0000[h].free) fn_1809_1319(code, name);
    return 1;
}

int fn_1809_12c0(int code, char far *name)
{
    char far *p;

    p = 0;
    if (name) {
        p = strrchr(name, '\\');
        if (p) p++;
        else p = name;
    }
    strupr(p);
    return (*g_3638)(code, p);
}

void fn_1809_1319(int code, char far *name)
{
    (*g_3638)(code, name);
    fn_2309_000c();
    exit(code);
}

long fn_1809_133b(int h, void far *buf, unsigned n)
{
    unsigned long got;
    int nh;

again:
    g_ae4d = 0;
    fn_2148_014d(g_aeaa);
    nh = fn_1809_0000(fn_1981_0365(f_2c12_0000[h].name), f_2c12_0000[h].mode);
    fn_1809_0e76(nh, f_2c12_0000[h].pos, 0);
    fn_2148_004d(f_2c12_0000[h].fd);
    fn_2279_025b(&f_2c12_0000[nh], &f_2c12_0000[h], 20L);
    f_2c12_0000[nh].free = 1;
    got = fn_2148_00c9(f_2c12_0000[h].fd, buf, n);
    if (g_ae4d) {
        if (fn_1809_12c0(2, fn_1981_0365(f_2c12_0000[h].name)) && fn_2148_014d(g_aeaa)) goto again;
        return 0;
    }
    return got;
}

int fn_1809_1460(char far *name, int omode)
{
    int fd;

    g_ae4d = 0;
    fd = fn_2148_0121(name, omode, omode == 0x8001 ? 0x100 : 0x180);
    if (!g_ae4d || !g_ae57 || fn_2148_000f() != g_aeaa[0] - 'A') return fd;
    g_ae4d = 0;
    fn_2148_002c(g_aeaa[0] - 'A');
    fn_2148_014d(g_aeaa);
    fd = fn_2148_0121(name, omode, omode == 0x8001 ? 0x100 : 0x180);
    if (!g_ae4d) return fd;
    g_ae4d = 0;
    return -1;
}

int fn_1809_1502(int idx, int h)
{
    long size;
    long avail;
    PakEnt far *ent;
    FileH far *fh;
    int mf;

    ent = 0;
    if (idx == -1) return 0;
    {
    PakEnt buf1;
    ent = fn_1981_02c0(idx, &buf1);
    if (!(ent->flags & 0x600)) return 0;
    if (ent->data) return 0;
    size = ent->size;
    mf = 0;
    if (fn_203b_03b4(0x42) >= size || fn_203b_0482(0x42) >= size) mf = 0x40;
    if (!mf) {
        ent->flags &= 0xd1ff;
        fn_1981_031f(idx, &buf1);
        return 0;
    }
    mf |= 2;
    avail = fn_203b_03b4(mf);
    while (avail < size) {
        int i;
        unsigned age;
        int best;
        long sum;

        age = 0;
        best = -1;
        sum = avail;
        for (i = 0; (ent = fn_1981_02c0(i, &buf1))->name; i++) {
            if (ent->data && !ent->refs && !(ent->flags & 0x2000)) {
                sum += ent->size;
                if ((ent->flags & 0xff) > age) {
                    age = ent->flags & 0xff;
                    best = i;
                }
            }
        }
        if (!sum || best == -1) break;
        ent = fn_1981_02c0(best, &buf1);
        fn_203b_0203(ent->data);
        ent->data = 0;
        avail = fn_203b_03b4(mf);
        fn_1981_031f(best, &buf1);
    }
    if (avail < size) return 0;
    fh = &f_2c12_0000[h];
    ent = fn_1981_02c0(idx, &buf1);
    ent->data = fn_203b_0007(size, mf);
    if (!ent->data) return 0;
    fn_1809_084d(h, ent->data, size);
    fh->pos = 0;
    fh->start = 0;
    if (ent->flags & 0x1000) {
        int x;
        PakEnt far *pak;
        PakEnt buf2;
        pak = fn_1981_02c0(ent->pak, &buf2);
        pak->refs--;
        fn_1981_031f(ent->pak, &buf2);
    }
    fn_2148_004d(fh->fd);
    fh->fd = 0;
    fn_1981_031f(idx, &buf1);
    return 1;
    }
}
