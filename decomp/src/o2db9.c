/* o2db9: driver file loading and driver volume/control calls */
/* FLAGS: -ml -3 -O -Z -Oe -Ol -Ob -Y -B */
#include <string.h>
#include <dir.h>

struct drv {
    int h;                          /* 00 */
    char far *name;                 /* 02 */
    char ext[4];                    /* 06 */
    char id[4];                     /* 0a */
    void (interrupt far *code)();   /* 0e */
    void far *x12;                  /* 12 */
    void far *buf;                  /* 16 */
    char far *path;                 /* 1a */
    void far *hdr;                  /* 1e */
    int owned;                      /* 22 */
};
extern char g_4b9c[];
extern char g_1a70[];
extern char g_1a72[];
extern int g_28fa;
extern int g_28b8;
extern int g_2922;
extern int g_2958;
extern int g_295a;
extern void (interrupt far *g_2908)();
extern void (interrupt far *g_28c6)();
int fn_1981_000a(char far *name);
void far *ovr_2ded_002a(char far *name, int flags);
int fn_1809_0000(char far *name, int mode);
long fn_1809_120c(int fh);
void fn_1809_058d(int fh);
long fn_1809_084d(int fh, void far *buf, long n);
long fn_203b_03b4(int a);
void far *fn_203b_0007(long size, int flags);
void fn_203b_0203(void far *p);
void far *fn_2037_0002(void far *p, long n);
void fn_1b79_0301(int a, int b, int c, int d);
void fn_16bf_0058(int on);
void fn_16bf_0001(int on);
void ovr_2db9_003e(struct drv far *d);

void far *ovr_2db9_0034(char far *name)
{
    if (!fn_1981_000a(name)) return 0;
    return ovr_2ded_002a(name, 0x20);
}

char far *ovr_2db9_0020(char far *name, struct drv far *d)
{
    if (name == 0 || d == 0 || (d->h == -1 && d->code == 0)) return 0;
    fnsplit(name, 0, 0, g_4b9c, 0);
    strcat(g_4b9c, g_1a70);
    strcat(g_4b9c, d->ext);
    if (!fn_1981_000a(g_4b9c)) {
        if (d->h != -1) {
            fnsplit(name, 0, 0, g_4b9c, 0);
            strcat(g_4b9c, g_1a72);
            if (!fn_1981_000a(g_4b9c)) return 0;
        } else return 0;
    }
    return g_4b9c;
}

long ovr_2db9_0039(char far *name, struct drv far *d, void far *buf, long size)
{
    long len;
    long total;
    char far *path;
    void (interrupt far *fp)();
    void far *p;
    register int fh;
    register int n;

    total = 0;
    path = ovr_2db9_0020(name, d);
    if (path == 0) return 0;
    ovr_2db9_003e(d);
    fh = fn_1809_0000(path, 1);
    len = fn_1809_120c(fh);
    len += (n = strlen(path) + 1);
    if (buf != 0) {
        if (len > size) {
fail:
            fn_1809_058d(fh);
            d->path = 0;
            return 0;
        }
    } else if (fn_203b_03b4(0) < len + 16) goto fail;
    if (d->h == -1) {
        if (buf != 0) {
            d->hdr = buf;
            buf = fn_2037_0002(buf, 500L);
        } else {
            d->hdr = fn_203b_0007(500L, 0);
            d->owned = 1;
        }
        total += 500;
        len -= fn_1809_084d(fh, d->hdr, 500L);
    }
    if (buf != 0) {
        d->buf = buf;
    } else {
        d->buf = fn_203b_0007(len + n, 0x20);
        d->owned = 1;
    }
    d->path = fn_2037_0002(d->buf, len - n);
    strcpy(d->path, path);
    total += len;
    fn_1809_084d(fh, d->buf, len);
    fn_1809_058d(fh);
    if (d->h == -1) {
        fp = d->code;
        p = d->buf;
        asm push es
        asm les ax, p
        asm mov dx, es
        asm pop es
        _BX = 4;
        fp();
    }
    return total;
}

void ovr_2db9_003e(struct drv far *d)
{
    if (d->buf != 0 && d->owned != 0) {
        fn_203b_0203(d->buf);
        fn_203b_0203(d->hdr);
    }
    d->owned = 0;
    d->path = 0;
    d->buf = 0;
    d->hdr = 0;
}

int ovr_2db9_002f(int x)
{
    void (interrupt far *f)();
    if (g_28fa == -1 && g_2908 != 0) {
        f = g_2908;
        _AX = x;
        _BX = 0x15;
        f();
    }
    return 1;
}

int ovr_2db9_0043(int x)
{
    void (interrupt far *f)();
    if (g_28fa == -1 && g_2908 != 0) {
        f = g_2908;
        _AX = x;
        _BX = 0x14;
        f();
    }
    return 1;
}

#pragma option -r-
int ovr_2db9_0048(int x)
{
    void (interrupt far *f)();
    x = x < 0xff ? x : 0xff;
    g_2958 = x = x > 0 ? x : 0;
    if (g_28fa == -1 && g_2908 != 0) {
        f = g_2908;
        _AX = x;
        _BX = 0x12;
        f();
    } else if (g_28fa != -1 && g_2922 != -1) {
        fn_1b79_0301(g_28fa, g_2922, ((g_2958 & 0xff) * 90) >> 8, 0);
    }
    if (x == 0) fn_16bf_0058(0); else fn_16bf_0058(1);
    return 1;
}

int ovr_2db9_002a(int x)
{
    void (interrupt far *f)();
    x = x < 0xff ? x : 0xff;
    g_295a = x = x > 0 ? x : 0;
    if (g_28b8 == -1 && g_28c6 != 0) {
        f = g_28c6;
        _AX = x;
        _BX = 0x13;
        f();
    }
    if (x == 0) fn_16bf_0001(0); else fn_16bf_0001(1);
    return 1;
}

int ovr_2db9_004d(void)
{
    int r;
    void (interrupt far *f)();
    if (g_28fa == -1 && g_2908 != 0) {
        f = g_2908;
        _BX = 0x16;
        f();
        r = _AX;
    }
    return r;
}

int ovr_2db9_0025(void)
{
    int r;
    void (interrupt far *f)();
    if (g_28b8 == -1 && g_28c6 != 0) {
        f = g_28c6;
        _BX = 0x17;
        f();
        r = _AX;
    }
    return r;
}
