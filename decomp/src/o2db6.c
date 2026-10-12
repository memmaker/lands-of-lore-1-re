/* o2db6: load and initialise the sound/music drivers */
#include <string.h>
#include <stdlib.h>
#include <mem.h>
#include <dos.h>

struct drvinfo { char pad[4]; char id[4]; char pad2[4]; int port; int irq; int dma; int irq2; };
struct drv {
    int h;                          /* 00 */
    char far *name;                 /* 02 */
    char ext[4];                    /* 06 */
    char id[4];                     /* 0a */
    void (interrupt far *code)();   /* 0e */
    void far *buf;                  /* 12 */
    char pad[0x0e];
    int timer;                      /* 24 */
};
struct sbstate { unsigned ds; char pad[0x0f]; char on; };
extern int g_295c;
extern int g_295e;
extern int g_3745;
extern int g_3747;
extern int g_3749;
extern int g_2962;
extern char g_1a3e[];
extern char g_1a47[];
extern char g_1a4b[];
extern char g_1a4f[];
extern char g_1a53[];
extern char g_1a5d[];
extern char g_1a68[];
extern char far *g_2938;
extern struct sbstate far *g_2952;
void far fn_2318_0002(void);
void far fn_16bf_00af(void);
void ovr_2e13_0020(void);
int ovr_2e13_0048(void far *fn);
void ovr_2e13_0057(int h, long rate);
void ovr_2e13_0025(int h);
int ovr_2e13_0034(void far *code);
struct drvinfo far *ovr_2e13_002f(int h);
int ovr_2e13_0043(int h, int port, int irq, int dma, int irq2);
void ovr_2e13_0039(int h, int port, int irq, int dma, int irq2);
void ovr_2e19_002f(int h);
int ovr_2dd0_0020(int i);
int ovr_2dd6_0020(int i);
int ovr_2ddc_0020(int i);
int fn_1981_000a(char far *name);
void ovr_2db3_0025(struct drv far *d);
void (interrupt far *ovr_2db9_0034(char far *name))();
void fn_203b_0203(void far *p);
void far *fn_203b_0007(long size, int flags);
int fn_1b79_02b6(int h);
void fn_1b79_02bb(int h, void far *buf, int n);

int ovr_2db6_0020(int a, int b, int c)
{
    ovr_2e13_0020();
    g_295c = ovr_2e13_0048(fn_2318_0002);
    ovr_2e13_0057(g_295c, 0x3c);
    ovr_2e13_0025(g_295c);
    g_3747 = ovr_2dd0_0020(b);
    g_3745 = ovr_2dd6_0020(a);
    g_3749 = ovr_2ddc_0020(c);
    if (g_3749 != 0) {
        g_295e = ovr_2e13_0048(fn_16bf_00af);
        ovr_2e13_0057(g_295e, 0x3c);
        ovr_2e13_0025(g_295e);
    }
    return 1;
}

int ovr_2db6_0025(char far *name, struct drv far *d, char far *id, register int mode)
{
    void (interrupt far *entry)();
    struct drvinfo far *info;
    char far *env;
    char far *q;
    register int n;

    if (name == 0) return 0;
    if (!fn_1981_000a(name)) return 0;
    if (d->code != 0) {
        if (stricmp(d->name, name) == 0) return 1;
        ovr_2db3_0025(d);
    }
    entry = d->code = ovr_2db9_0034(name);
    if (d->code == 0) return 0;
    if (mode != 0) {
        _BX = 2;
        entry();
        if (mode < 0) {
            _AX = 4;
            _BX = 0x10;
            entry();
        }
        d->timer = ovr_2e13_0048((char far *)d->code + 3);
        if (d->timer == -1) {
fail:
            fn_203b_0203(d->code);
            d->code = 0;
            return 0;
        }
        ovr_2e13_0057(d->timer, mode < 0 ? -mode : mode);
        ovr_2e13_0025(d->timer);
        strcpy(d->ext, stricmp(name, g_1a3e) == 0 ? g_1a47 : g_1a4b);
    } else {
        d->h = ovr_2e13_0034(d->code);
        if (d->h == -1) goto fail;
        info = ovr_2e13_002f(d->h);
        memcpy(d->id, info->id, 4);
        strcpy(d->ext, g_1a4f);
        if (stricmp(name, g_1a53) == 0 || stricmp(name, g_1a5d) == 0) {
            if ((env = getenv(g_1a68)) != 0) {
                if ((q = strchr(env, 'A')) != 0) {
                    q++;
                    info->port = strtol(q, 0, 16);
                    g_2962 = info->port;
                }
                if ((q = strchr(env, 'I')) != 0) {
                    q++;
                    info->irq = info->irq2 = strtol(q, 0, 10);
                }
                if ((q = strchr(env, 'D')) != 0) {
                    q++;
                    info->dma = strtol(q, 0, 10);
                }
            }
        }
        if (!ovr_2e13_0043(d->h, info->port, info->irq, info->dma, info->irq2)) {
            ovr_2e19_002f(d->h);
            goto fail;
        }
        ovr_2e13_0039(d->h, info->port, info->irq, info->dma, info->irq2);
        if ((n = fn_1b79_02b6(d->h)) != 0) {
            d->buf = fn_203b_0007(n, 0);
            fn_1b79_02bb(d->h, d->buf, n);
        }
    }
    d->name = name;
    d->ext[0] = 0;
    if (id != 0) memcpy(d->ext, id, 4);
    return 1;
}

int ovr_2db6_002a(void)
{
    char far *p;

    p = g_2938;
    if (p == 0) return 0;
    while (*(int far *)p != -1) p = (char far *)p + 1;
    g_2952 = (struct sbstate far *)p;
    g_2952->ds = _DS;
    g_2952->on = 1;
    return 1;
}
