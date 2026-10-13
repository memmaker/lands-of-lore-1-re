/* s034: file layer over loose files and PAK archives (twenty handles, directory entries cached in memory) */
#include "lol.h"
#include <io.h>
#include <stdlib.h>
#include <string.h>

struct Dir {                /* 0x14 bytes: file directory entry (f_27fc_0000[], accessed through fn_1981_02c0) */
    long name;
    long size;
    long data;              /* far pointer of the cached copy */
    long off;               /* offset inside the parent PAK */
    unsigned char parent;   /* directory index of the PAK */
    unsigned char refs;     /* open handles */
    unsigned flags;         /* 0x1000 in a PAK, 0x800 freeable, low byte cache age */
};

struct FH {                 /* 0x14 bytes: open file */
    int free;
    int fd;                 /* DOS handle, 0 when served from memory */
    long pos;
    long base;              /* offset of the file inside its PAK */
    int dir;
    int mode;
    char far *name;
};

extern struct FH far f_2c12_0000[20];
extern struct Dir far f_27fc_0000[];
extern struct Dir far *g_2aa7;
extern char g_abde, g_ae59, g_aeaa;
extern int g_ae4d, g_ae57;
extern int (far *g_3638)(int msg, char far *name);

int fn_1981_000a(char far *name);
int fn_1981_01af(char far *name);
struct Dir far *fn_1981_02c0(int idx, void far *buf);
void fn_1981_031f(int idx, void far *buf);
char far *fn_1981_0365(char far *name);
int fn_2148_000f(void);
void fn_2148_002c(int drive);
void fn_2148_004d(int fd);
long fn_2148_0094(int fd, long off, int whence);
unsigned fn_2148_00c9(int fd, void far *buf, unsigned n);
unsigned fn_2148_00f5(int fd, void far *buf, unsigned n);
int fn_2148_0121(char far *name, int mode, int perm);
int fn_2148_014d(char far *s);
void far *fn_2279_02b5(void far *p);
void fn_2279_025b(void far *s, void far *d, long n);
void far *fn_2037_0002(void far *p, long off);
int fn_2365_063f(void far *p);
long fn_203b_03b4(int type);
long fn_203b_0482(int type);
void far *fn_203b_0007(long size, int type);
void fn_203b_0203(void far *p);
void fn_2309_000c(void);

int fn_1809_0000(char far *name, int mode);
void fn_1809_058d(int h);
unsigned long fn_1809_084d(int h, void far *buf, unsigned long n);
long fn_1809_0e76(int h, long off, int whence);
int fn_1809_11b9(char far *name);
long fn_1809_120c(int h);
int fn_1809_1279(int h, int err, char far *name);
int fn_1809_12c0(int msg, char far *path);
void fn_1809_1319(int err, char far *name);
long fn_1809_133b(int h, void far *buf, unsigned n);
int fn_1809_1460(char far *name, int mode);
int fn_1809_1502(int idx, int h);

int fn_1809_0000(char far *name, int mode)
{
    int fd;
    int omode;
    int opened;
    struct Dir far *e;
    struct Dir far *pe;
    struct FH far *fh;
    long off;
    int k;
    struct Dir far *d;
    struct Dir far *prev;
    char buf1[20];
    char buf2[20];
    char nm[14];
    int idx, slot;

    g_abde++;
    for (fh = f_2c12_0000, slot = 0; slot < 20; slot++, fh++)
        if (fh->free)
            break;
    if (slot == 20)
        fn_1809_1319(3, name);
    idx = fn_1981_01af(name);
    e = fn_1981_02c0(idx, buf1);
    fn_2148_002c(g_ae59 - 'A');
    opened = 0;
    if (idx != -1 && (e->flags & 0x1000) && !e->data) {
        int t = fn_2148_0121(name, 0x8001, 0x100);
        if (t != -1) {
            fn_2148_004d(t);
            opened = 1;
        }
    }
    if ((mode & 2) && idx != -1 && e->data) {
        if (e->flags & 0x1000) {
            fn_203b_0203((void far *)e->data);
            e->data = 0;
            fn_1981_031f(idx, buf1);
        } else
            fn_1809_1319(9, name);
    }
    if (e->data && idx != -1) {
        fh->dir = idx;
        fh->free = 0;
        fh->pos = 0;
        fh->name = (char far *)e->name;
        fh->fd = 0;
        fh->mode = mode;
        if (e->flags & 0x1000)
            pe = fn_1981_02c0(e->parent, buf2);
        else
            pe = 0;
        if (pe && pe->data == e->data) {
            fh->base = e->off;
            pe->refs++;
            fn_1981_031f(e->parent, buf2);
        } else
            fh->base = 0;
        goto done;
    }
    if (idx != -1 && (e->flags & 0x1000) && !opened && !(mode & 2)) {
        pe = fn_1981_02c0(e->parent, buf2);
        slot = fn_1809_0000(fn_1981_0365((char far *)pe->name), mode);
        pe = fn_1981_02c0(e->parent, buf2);
        fh = &f_2c12_0000[slot];
        if (g_2aa7 == f_27fc_0000 && !(f_27fc_0000[fh->dir].flags & 0x100)) {
            d = 0;
            prev = 0;
            while (fn_1809_084d(slot, &off, 4L), off) {
                k = 0;
                do
                    fn_1809_084d(slot, &nm[k], 1L);
                while (nm[k++]);
                k = fn_1981_01af(nm);
                if (k != -1) {
                    d = &f_27fc_0000[k];
                    if ((d->flags & 0x1000) && d->parent == fh->dir) {
                        d->off = off + f_27fc_0000[fh->dir].off;
                        if (prev)
                            prev->size = d->off - prev->off;
                        prev = d;
                    }
                }
            }
            if (prev)
                prev->size = fn_1809_120c(slot) - prev->off;
            f_27fc_0000[fh->dir].flags |= 0x100;
        }
        e->data = pe->data;
        fn_1981_031f(idx, buf1);
        fh->dir = idx;
        fh->name = (char far *)e->name;
        fh->base = e->off;
        fn_1809_0e76(slot, 0L, 0);
        goto cache;
    }
    omode = 0x8001;
    switch (mode) {
    case 1:
        omode = 0x8001;
        break;
    case 3:
        omode = 0x8004;
        break;
    case 2:
        omode = 0x8302;
        break;
    default:
        fn_1809_1319(1, name);
    }
    if ((mode & 1) && !fn_1809_11b9(name)) {
        g_abde--;
        return -1;
    }
    for (;;) {
        fd = fn_1809_1460(name, omode);
        if (fd != -1)
            break;
        fn_2148_014d(&g_aeaa);
        fn_2148_014d(&g_ae59);
        if (!fn_1809_12c0(2, name)) {
            g_abde--;
            return -1;
        }
    }
    if (opened && idx != -1) {
        e->flags &= 0xefff;
        e->size = 0;
        fn_1981_031f(idx, buf1);
    }
    if (idx != -1) {
        e->size = fn_2148_0094(fd, 0L, 2);
        fn_1981_031f(idx, buf1);
        fn_2148_0094(fd, 0L, 0);
    }
    fh->dir = idx;
    fh->pos = 0;
    fh->base = 0;
    fh->free = 0;
    fh->fd = fd;
    fh->mode = mode;
    if (idx != -1)
        fh->name = (char far *)e->name;
    else
        fh->name = 0;
    if (!(mode & 2))
cache:
        fn_1809_1502(idx, slot);
done:
    if (idx != -1) {
        e = fn_1981_02c0(idx, buf1);
        e->refs++;
        fn_1981_031f(idx, buf1);
    }
    g_abde--;
    return slot;
}

void fn_1809_058d(int h)
{
    int freed;
    int single;
    int refs;
    struct Dir far *pe;
    struct Dir far *e;
    char buf2[20];
    char buf1[20];
    int idx;

    freed = 0;
    single = 0;
    pe = 0;
    e = 0;
    if (!fn_1809_1279(h, 4, 0L))
        return;
    g_abde++;
    idx = f_2c12_0000[h].dir;
    e = fn_1981_02c0(idx, buf1);
    if (idx != -1) {
        if ((e->flags & 0xff) == 1)
            single = 1;
        else
            e->flags &= 0xff00;
        e->refs--;
        refs = e->refs;
        fn_1981_031f(idx, buf1);
        if (e->flags & 0x1000) {
            pe = fn_1981_02c0(e->parent, buf2);
            if (pe->data == e->data) {
                if ((pe->flags & 0xff) == 1)
                    single = 1;
                else
                    pe->flags &= 0xff00;
                pe->refs--;
                refs = pe->refs;
                fn_1981_031f(e->parent, buf2);
            }
        }
    }
    if (idx != -1 && e->data) {
        if (pe && pe->data == e->data) {
            if (!e->refs)
                e->data = 0;
            if (!pe->refs && (pe->flags & 0x800)) {
                fn_203b_0203((void far *)pe->data);
                pe->data = 0;
                freed = 1;
            }
        } else if ((e->flags & 0x800) && !e->refs) {
            fn_203b_0203((void far *)e->data);
            e->data = 0;
            freed = 1;
        }
        fn_1981_031f(idx, buf1);
        if (pe)
            fn_1981_031f(e->parent, buf2);
        if (!single && !freed && !refs && !(e->flags & 0x6000)) {
            for (idx = 0; e = fn_1981_02c0(idx, buf1), e->name; idx++) {
                if (e->data && !e->refs && !(e->flags & 0x6000)) {
                    if ((e->flags & 0xff) == 0xff) {
                        fn_203b_0203((void far *)e->data);
                        e->data = 0;
                    } else
                        e->flags++;
                    fn_1981_031f(idx, buf1);
                }
            }
        }
    } else
        fn_2148_004d(f_2c12_0000[h].fd);
    f_2c12_0000[h].free = 1;
    g_abde--;
}

unsigned long fn_1809_084d(int h, void far *buf, unsigned long n)
{
    int fd;
    long size;
    int idx;
    unsigned long got;
    struct Dir far *e;
    long chunk;
    void far *tmp;
    unsigned long r;
    char dbuf[20];

    if (!buf || !n || !fn_1809_1279(h, 5, 0L))
        return 0;
    g_abde++;
    fd = f_2c12_0000[h].fd;
    idx = f_2c12_0000[h].dir;
    e = fn_1981_02c0(idx, dbuf);
    size = e->size;
    if (size && idx != -1 && e->size)
        n = e->size - f_2c12_0000[h].pos < n ? e->size - f_2c12_0000[h].pos : n;
    got = 0;
    if (n) {
        buf = fn_2279_02b5(buf);
        if (fd) {
            if (fn_2365_063f(buf)) {
                chunk = fn_203b_03b4(0) >> 1 & ~15L;
                chunk = (unsigned long)chunk < 0xfff0 ? chunk : 0xfff0;
                tmp = fn_203b_0007(chunk, 0x28);
                while (n) {
                    g_ae4d = 0;
                    r = fn_2148_00c9(fd, tmp, n < chunk ? (unsigned)n : (unsigned)chunk);
                    if (g_ae4d) {
                        r = fn_1809_133b(h, tmp, n < chunk ? (unsigned)n : (unsigned)chunk);
                        fd = f_2c12_0000[h].fd;
                    }
                    fn_2279_025b(tmp, buf, r);
                    n -= r;
                    got = got + r;
                    f_2c12_0000[h].pos = f_2c12_0000[h].pos + r;
                    if (r < chunk)
                        break;
                    buf = (void far *)((long)buf + r);
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
                    got += chunk;
                    f_2c12_0000[h].pos += chunk;
                    if ((unsigned long)chunk < 0xfff0)
                        break;
                    buf = fn_2037_0002(buf, chunk);
                }
            }
        } else {
            fn_2279_025b((void far *)(e->data + f_2c12_0000[h].base + f_2c12_0000[h].pos), buf, n);
            got = n;
            f_2c12_0000[h].pos = f_2c12_0000[h].pos + n;
        }
    }
    fn_1981_031f(idx, dbuf);
    g_abde--;
    return got;
}

unsigned long fn_1809_0bde(int h, void far *buf, unsigned long n)
{
    int fd;
    unsigned long got;
    struct Dir far *e;
    long chunk;
    void far *tmp;
    unsigned long r;
    char dbuf[20];
    int idx;

    if (!fn_1809_1279(h, 6, 0L))
        return 0;
    fd = f_2c12_0000[h].fd;
    idx = f_2c12_0000[h].dir;
    e = fn_1981_02c0(idx, dbuf);
    if (!fd) {
        fn_1809_1319(9, fn_1981_0365((char far *)e->name));
        return 0;
    }
    g_abde++;
    got = 0;
    if (fn_2365_063f(buf)) {
        chunk = fn_203b_03b4(0) >> 1 & ~15L;
        chunk = (unsigned long)chunk < 0xfff0 ? chunk : 0xfff0;
        tmp = fn_203b_0007(chunk, 0x28);
        while (n) {
            r = n < chunk ? n : chunk;
            fn_2279_025b(buf, tmp, r);
            r = fn_2148_00f5(fd, tmp, (unsigned)r);
            n -= r;
            got = got + r;
            f_2c12_0000[h].pos = f_2c12_0000[h].pos + r;
            if (!r)
                break;
            if (idx != -1)
                e->size = f_2c12_0000[h].pos < e->size ? e->size : f_2c12_0000[h].pos;
            buf = (void far *)((long)buf + r);
        }
        fn_203b_0203(tmp);
    } else {
        while (n) {
            chunk = fn_2148_00f5(fd, buf, n < 0xfff0 ? (unsigned)n : 0xfff0);
            n -= chunk;
            got += chunk;
            f_2c12_0000[h].pos += chunk;
            if (!chunk)
                break;
            if (idx != -1)
                e->size = f_2c12_0000[h].pos < e->size ? e->size : f_2c12_0000[h].pos;
            buf = fn_2279_02b5(buf = (void far *)((long)buf + chunk));
        }
    }
    fn_1981_031f(idx, dbuf);
    g_abde--;
    return got;
}

long fn_1809_0e76(int h, long off, int whence)
{
    int fd;
    int idx;
    struct Dir far *e;
    char dbuf[20];

    if (!fn_1809_1279(h, 7, 0L))
        return 0;
    g_abde++;
    idx = f_2c12_0000[h].dir;
    fd = f_2c12_0000[h].fd;
    e = fn_1981_02c0(idx, dbuf);
    if (!fd) {
        switch (whence) {
        case 0:
            off = off < 0 ? 0 : off;
            f_2c12_0000[h].pos = 0;
            break;
        case 2:
            off = off > 0 ? 0 : off;
            f_2c12_0000[h].pos = e->size;
            break;
        default:
            fn_1809_1319(8, fn_1981_0365(f_2c12_0000[h].name));
        case 1:
            break;
        }
        f_2c12_0000[h].pos += off;
        f_2c12_0000[h].pos = f_2c12_0000[h].pos < e->size - 1 ? f_2c12_0000[h].pos : e->size - 1;
        f_2c12_0000[h].pos = f_2c12_0000[h].pos > 0 ? f_2c12_0000[h].pos : 0;
    } else if (idx != -1 && (e->flags & 0x1000)) {
        switch (whence) {
        case 0:
            f_2c12_0000[h].pos = off;
            break;
        case 2:
            off = off > 0 ? 0 : off;
            if (-off > e->size)
                fn_1809_1319(8, fn_1981_0365(f_2c12_0000[h].name));
            f_2c12_0000[h].pos = e->size + off;
            break;
        case 1:
            f_2c12_0000[h].pos += off;
            if (f_2c12_0000[h].pos < 0)
                f_2c12_0000[h].pos = 0;
            if (f_2c12_0000[h].pos >= e->size)
                f_2c12_0000[h].pos = e->size;
            break;
        default:
            fn_1809_1319(8, fn_1981_0365(f_2c12_0000[h].name));
        }
        fn_2148_0094(fd, f_2c12_0000[h].pos + f_2c12_0000[h].base, 0);
    } else {
        f_2c12_0000[h].pos = fn_2148_0094(fd, off, whence);
        if (idx != -1)
            f_2c12_0000[h].pos -= f_2c12_0000[h].base;
    }
    g_abde--;
    return f_2c12_0000[h].pos;
}

int fn_1809_11b9(char far *name)
{
    if (!name)
        return 0;
    while (!fn_1981_000a(name)) {
        do {
            if (!fn_1809_12c0(2, name))
                return 0;
            fn_2148_002c(g_aeaa - 'A');
        } while (fn_2148_014d(&g_aeaa));
    }
    return 1;
}

long fn_1809_120c(int h)
{
    struct Dir far *e;
    char dbuf[20];

    if (f_2c12_0000[h].dir != -1) {
        e = fn_1981_02c0(f_2c12_0000[h].dir, dbuf);
        if (e->size)
            return e->size;
    }
    return filelength(f_2c12_0000[h].fd);
}

int fn_1809_1279(int h, int err, char far *name)
{
    if (h < 0 || h >= 20)
        fn_1809_1319(err, name);
    if (f_2c12_0000[h].free)
        fn_1809_1319(err, name);
    return 1;
}

int fn_1809_12c0(int msg, char far *path)
{
    char far *p;

    p = 0;
    if (path) {
        p = strrchr(path, '\\');
        if (p)
            p++;
        else
            p = path;
    }
    strupr(p);
    return (*g_3638)(msg, p);
}

void fn_1809_1319(int err, char far *name)
{
    (*g_3638)(err, name);
    fn_2309_000c();
    exit(err);
}

long fn_1809_133b(int h, void far *buf, unsigned n)
{
    long r;
    int nh;

    do {
        g_ae4d = 0;
        fn_2148_014d(&g_aeaa);
        nh = fn_1809_0000(fn_1981_0365(f_2c12_0000[h].name), f_2c12_0000[h].mode);
        fn_1809_0e76(nh, f_2c12_0000[h].pos, 0);
        fn_2148_004d(f_2c12_0000[h].fd);
        fn_2279_025b(&f_2c12_0000[nh], &f_2c12_0000[h], 20L);
        f_2c12_0000[nh].free = 1;
        r = fn_2148_00c9(f_2c12_0000[h].fd, buf, n);
        if (!g_ae4d)
            return r;
    } while (fn_1809_12c0(2, fn_1981_0365(f_2c12_0000[h].name)) && fn_2148_014d(&g_aeaa));
    return 0;
}

int fn_1809_1460(char far *name, int mode)
{
    int fd;

    g_ae4d = 0;
    fd = fn_2148_0121(name, mode, mode == 0x8001 ? 0x100 : 0x180);
    if (!g_ae4d || !g_ae57 || fn_2148_000f() != g_aeaa - 'A')
        return fd;
    g_ae4d = 0;
    fn_2148_002c(g_aeaa - 'A');
    fn_2148_014d(&g_aeaa);
    fd = fn_2148_0121(name, mode, mode == 0x8001 ? 0x100 : 0x180);
    if (!g_ae4d)
        return fd;
    g_ae4d = 0;
    return -1;
}

int fn_1809_1502(int idx, int h)
{
    long need;
    long avail;
    struct Dir far *e;
    struct FH far *fh;
    int k;
    union {
        struct Dir far *p;
        struct {
            int idx;
            unsigned prio;
        } b;
    } u;
    long total;
    char buf1[20];
    char buf2[20];
    int memf;

    e = 0;
    if (idx != -1) {
        e = fn_1981_02c0(idx, buf1);
        if ((e->flags & 0x600) && !e->data) {
            need = e->size;
            memf = 0;
            if (fn_203b_03b4(0x42) >= need || fn_203b_0482(0x42) >= need)
                memf = 0x40;
            if (!memf) {
                e->flags &= 0xd1ff;
                fn_1981_031f(idx, buf1);
            } else {
                memf |= 2;
                avail = fn_203b_03b4(memf);
                while (avail < need) {
                    u.b.prio = 0;
                    u.b.idx = -1;
                    total = avail;
                    for (k = 0; e = fn_1981_02c0(k, buf1), e->name; k++) {
                        if (e->data && !e->refs && !(e->flags & 0x2000)) {
                            total += e->size;
                            if ((e->flags & 0xff) > u.b.prio) {
                                u.b.prio = e->flags & 0xff;
                                u.b.idx = k;
                            }
                        }
                    }
                    if (!total || u.b.idx == -1)
                        break;
                    e = fn_1981_02c0(u.b.idx, buf1);
                    fn_203b_0203((void far *)e->data);
                    e->data = 0;
                    avail = fn_203b_03b4(memf);
                    fn_1981_031f(u.b.idx, buf1);
                }
                if (avail >= need) {
                    fh = &f_2c12_0000[h];
                    e = fn_1981_02c0(idx, buf1);
                    e->data = (long)fn_203b_0007(need, memf);
                    if (!e->data)
                        return 0;
                    fn_1809_084d(h, (void far *)e->data, need);
                    fh->pos = 0;
                    fh->base = 0;
                    if (e->flags & 0x1000) {
                        u.p = fn_1981_02c0(e->parent, buf2);
                        u.p->refs--;
                        fn_1981_031f(e->parent, buf2);
                    }
                    fn_2148_004d(fh->fd);
                    fh->fd = 0;
                    fn_1981_031f(idx, buf1);
                    return 1;
                }
            }
        }
    }
    return 0;
}
