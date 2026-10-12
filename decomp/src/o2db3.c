/* o2db3: shut the sound system down (ovr_2db3_0020) and release one sound driver block (ovr_2db3_0025) */
#pragma inline

struct SndDrv {
    int h;                          /* +00 XMS handle, -1: driver held in conventional memory */
    void far *xms;                  /* +02 */
    char pad06[8];
    void (interrupt far *entry)(void);  /* +0e */
    void far *buf;                  /* +12 */
    char pad16[0x0e];
    int timer;                      /* +24 */
};

extern int g_295e, g_295c;
void ovr_2e19_002a(int t);
void ovr_2e19_003e(int t);
void ovr_2e19_0034(int h, long a);
void ovr_2e19_002f(int h);
void ovr_2dcd_0020(void);
void ovr_2dd3_0020(void);
void ovr_2dd9_0020(void);
void ovr_2dc3_0020(void);
void fn_203b_0203(void far *p);

void ovr_2db3_0020(void)
{
    if (g_295e != -1) {
        ovr_2e19_002a(g_295e);
        g_295e = -1;
    }
    ovr_2e19_002a(g_295c);
    g_295c = -1;
    ovr_2dcd_0020();
    ovr_2dd3_0020();
    ovr_2dd9_0020();
    ovr_2dc3_0020();
}

void ovr_2db3_0025(struct SndDrv far *p)
{
    void (interrupt far *f)(void);

    if (p == 0) return;
    if (p->timer != -1) {
        ovr_2e19_003e(p->timer);
        ovr_2e19_002a(p->timer);
        p->timer = -1;
    }
    if (p->h == -1) {
        f = p->entry;
        if (f != 0) {
            _BX = 3;
            (*f)();
        }
    } else {
        ovr_2e19_0034(p->h, 0L);
        ovr_2e19_002f(p->h);
        p->h = -1;
    }
    fn_203b_0203(p->entry);
    fn_203b_0203(p->buf);
    p->buf = 0;
    p->entry = 0;
    p->xms = 0;
}
