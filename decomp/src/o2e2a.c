/* o2e2a: file helpers (exists, delete through drive/cache, resize) */
/* FLAGS: -ml -3 -Y */
#include <io.h>

struct fent { char pad[8]; void far *buf; };
extern char g_abde;
extern char g_ae59;
int fn_1809_0000(char far *name, int mode);
void fn_1809_058d(int fd);
void fn_2148_002c(int drive);
int fn_1981_01af(char far *name);
struct fent far *fn_1981_02c0(int h, void far *buf);
void fn_203b_0203(void far *p);
void fn_1981_031f(int h, void far *buf);
int fn_2148_006e(char far *name);
int fn_1809_1279(int h, int a, int b, int c);
int ovr_2e26_0025(int h);

int ovr_2e2a_0025(char far *name)
{
    register int fd;

    if (name == 0) return 0;
    fd = fn_1809_0000(name, 2);
    if (fd != -1) {
        fn_1809_058d(fd);
        return 1;
    }
    return 0;
}

int ovr_2e2a_0020(char far *name)
{
    struct fent far *p;
    char buf[20];
    register int h;

    if (name == 0) return 0;
    g_abde++;
    fn_2148_002c(g_ae59 - 'A');
    p = fn_1981_02c0(h = fn_1981_01af(name), buf);
    if (h != -1 && p->buf != 0) {
        fn_203b_0203(p->buf);
        p->buf = 0;
        fn_1981_031f(h, buf);
    }
    h = !fn_2148_006e(name);
    g_abde--;
    return h;
}

int ovr_2e2a_002a(int hh, long size)
{
    register int h = hh;
    register int fd;


    if (fn_1809_1279(h, 6, 0, 0)) {
        fd = ovr_2e26_0025(h);
        if (fd != -1) return chsize(fd, size) != -1 ? 1 : 0;
    }
    return 0;
}
