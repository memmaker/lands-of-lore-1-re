/* s002: TIM (timed animation script) loader and scheduler */
#pragma option -O-l

struct TimHdr { int magic; int stop; int numStart; int offFuncs; int offWsa; int offAvtl; int offText; };
struct TimCmd { int len; int delay; char op; char pad; int param[1]; };
struct TimFunc { int far *ip; unsigned long lastTime; unsigned long nextTime; struct TimCmd far *loopIp; int w10; int w12;
                 int far *avtl; };

typedef int (far *TimOp)(int far *p);

extern TimOp g_1dcc[];
extern struct TimFunc far *g_4bae;
extern void far *g_4baa;
extern long g_384c;
extern long g_213c;
extern int g_4bb2, g_4bb4, g_4bb6;
extern int far *g_4bb8;
extern int far *g_4bbc;
extern int far *g_4bc0;
extern int far *g_4bc4;
extern char g_5275, g_5276;
extern long g_5269;
extern char g_81ff;

int ovr_2de9_0020(char far *name);
void ovr_2de9_0025(int h);
unsigned ovr_2de9_002a(int h, long tag);
void ovr_2de9_002f(int h, long tag, void far *buf, unsigned long len);
void fn_1809_0e76(int h, long a, int b);
void far *fn_203b_0007(unsigned long size, int flags);
void fn_0845_144e(void far *p);
void fn_0845_093a(void);
int fn_154c_0136(void);
void fn_057f_07aa(char c);

struct TimHdr far *fn_0638_0008(char far *name, struct TimHdr far *buf, unsigned long bufSize)
{
    struct TimHdr far *t;
    int h;
    unsigned size, n;

    h = ovr_2de9_0020(name);
    fn_1809_0e76(h, 0, 0);
    size = ovr_2de9_002a(h, 0x4d524f46L);       /* FORM */
    size += 4;
    if (size < 0x14) return 0;
    size += 0x168;
    if (buf == 0 || bufSize < size) {
        buf = fn_203b_0007(size, 0x30);
        buf->magic = 0xbabe;
    } else
        buf->magic = 0;
    n = ovr_2de9_002a(h, 0x4c545641L);          /* AVTL */
    t = buf;
    t->stop = -1;
    t->numStart = 0;
    t->offFuncs = 0xe;
    t->offWsa = t->offFuncs + 0xf0;
    t->offAvtl = t->offWsa + 0x78;
    t->offText = t->offAvtl + n;
    g_4bc0 = (int far *)((char far *)t + t->offAvtl);
    g_4bc4 = (int far *)((char far *)t + t->offText);
    ovr_2de9_002f(h, 0x4c545641L, g_4bc0, n);
    n = ovr_2de9_002a(h, 0x54584554L);          /* TEXT */
    if (n) ovr_2de9_002f(h, 0x54584554L, g_4bc4, n);
    g_4bae = (struct TimFunc far *)((char far *)t + t->offFuncs);
    g_4bae->ip = 0;
    g_4bae->avtl = g_4bc0 + *g_4bc0;
    ovr_2de9_0025(h);
    return buf;
}

void fn_0638_018b(struct TimHdr far *t)
{
    if (t->magic == (int)0xbabe) fn_0845_144e(t);
}

void fn_0638_01a6(struct TimFunc far *f)
{
    f->ip += *f->ip;
    f->lastTime = f->nextTime;
    f->nextTime += f->ip[1] + g_213c;
    g_213c = 0;
}

int fn_0638_01e5(char far *p, int loop)
{
    int r;
    int n;
    struct TimFunc far *cur;
    int run;

    if (p == 0) return 0;
    {
        char far *b = p;
        struct TimHdr far *t = (struct TimHdr far *)p;
        g_4bb8 = &t->stop;
        g_4bbc = &t->numStart;
        g_4bae = (struct TimFunc far *)(b + t->offFuncs);
        g_4baa = b + t->offWsa;
        g_4bc0 = (int far *)(b + t->offAvtl);
        g_4bc4 = (int far *)(b + t->offText);
    }
    if (g_4bae->ip == 0) {
        g_4bae->ip = g_4bae->avtl;
        g_4bae->lastTime = g_4bae->nextTime = g_384c;
    }
    do {
        fn_0845_093a();
        g_4bb6 = 0;
        while (g_4bb6 < 10) {
            cur = &g_4bae[g_4bb6];
            if (*g_4bb8 != -1) g_1dcc[28](g_4bbc);
            fn_0845_093a();
            if (*g_4bbc > 1 && cur->loopIp && g_81ff && fn_154c_0136() != 2) {
                cur->loopIp = 0;
                g_5275 = 0;
                g_5276 = 0;
                g_5269 = 0;
                g_4bb4 = g_4bb6;
                fn_057f_07aa(0x15);
                g_4bb4 = -1;
            }
            if (cur->ip == 0) goto next;
            run = 1;
            n = 0;
            while (cur->nextTime <= g_384c && run == 1) {
                int op;
                struct TimCmd far *ip;
                if (n++ > 0) {
                    if (*g_4bb8 != -1) g_1dcc[28](g_4bbc);
                    fn_0845_093a();
                }
                ip = (struct TimCmd far *)cur->ip;
                op = ip->op;
                switch (r = g_1dcc[op](ip->param)) {
                case -1:
                    loop = 0;
                    run = 0;
                    g_4bb6 = 11;
                    break;
                case -3:
                    *g_4bb8 = g_4bb6;
                    g_4bb4 = -1;
                    break;
                case -2:
                    run = 0;
                    break;
                case 22:
                    cur->loopIp = 0;
                }
                fn_0638_01a6(cur);
            }
        next:
            g_4bb6++;
        }
    } while (loop == 1);
    return g_4bb2;
}
