/* o2e22: file cache entry flags (lock/unlock, flush unused buffers) */
/* FLAGS: -ml -3 -Y */
#include <string.h>

struct fent { char far *name; char pad[4]; void far *buf; char pad2[5]; unsigned char busy; unsigned flags; };
int fn_1981_01af(char far *name);
struct fent far *fn_1981_02c0(int h, void far *buf);
void fn_1981_031f(int h, void far *buf);
char far *fn_1981_0365(char far *name);
int fn_1809_0000(char far *name, int mode);
void fn_1809_058d(int fd);
void fn_203b_0203(void far *p);

int ovr_2e22_002a(char far *name)
{
    struct fent far *p;
    int fl;
    int fd;
    char buf[20];
    register int h;

    h = fn_1981_01af(name);
    if (h == -1) return 0;
    p = fn_1981_02c0(h, buf);
    fl = p->flags;
    p->flags |= 0x400;
    p->flags &= ~0x800;
    fn_1981_031f(h, buf);
    fd = fn_1809_0000(name, 1);
    fn_1809_058d(fd);
    p = fn_1981_02c0(h, buf);
    p->flags = fl;
    fn_1981_031f(h, buf);
    return 1;
}

int ovr_2e22_002f(int all)
{
    struct fent far *p;
    char buf[20];
    register int i;
    register int n;

    n = 0;
    p = 0;
    i = 0;
    goto next;
    do {
        if (p->buf != 0 && !p->busy && (all || !(p->flags & 0x2000))) {
            fn_203b_0203(p->buf);
            p->buf = 0;
            fn_1981_031f(i, buf);
            n++;
        }
        i++;
next:
        p = fn_1981_02c0(i, buf);
    } while (p->name != 0 && strlen(fn_1981_0365(p->name)) != 0);
    return n;
}

int ovr_2e22_0025(char far *name)
{
    int fl;
    struct fent far *p;
    char buf[20];
    register int h;

    if ((h = fn_1981_01af(name)) == -1) return 0;
    p = fn_1981_02c0(h, buf);
    if (p->buf == 0) goto done;
    fl = p->flags;
    p->flags &= ~0x2400;
    p->flags |= 0x800;
    fn_1981_031f(h, buf);
    fn_1809_058d(fn_1809_0000(name, 1));
    p = fn_1981_02c0(h, buf);
    p->flags = fl;
    fn_1981_031f(h, buf);
done:
    return 1;
}

long ovr_2e22_0020(void)
{
    return 0;
}
