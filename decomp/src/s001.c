/* s001: TIM (timed animation script) interpreter opcodes */
#pragma option -O-b
#include <mem.h>
#include <stdlib.h>
#include <ctype.h>

struct WsaSlot { void far *wsa; int x; int y; int w8; int flags; };
struct TimFunc { int far *ip; long lastTime; long nextTime; int far *loopIp; int w10; int w12; int far *avtl; };
struct Emc { char pad[0xc]; int sp; char pad2[0x1e]; int stack[1]; };
struct Shape { char far *data; int x; int y; char pad[0xa]; unsigned flags; char pad2[0xb5 - 0x14]; };

extern struct WsaSlot far *g_4baa;
extern struct TimFunc far *g_4bae;
extern long g_384c;
extern int g_4bb2, g_4bb4, g_4bb6;
extern int far *g_4bb8;
extern int far *g_4bbc;
extern int far *g_4bc0;
extern int far *g_4bc4;
extern char g_5275, g_5276;
extern long g_5269;
extern char g_81fe, g_81ff;
extern struct Shape g_4ee0[];
extern int g_7fd0, g_7fd2, g_7fd4, g_7fdf;
extern char far *g_adea;
extern char far *g_4edc;
extern char far *g_540e;
extern int g_20d5;
extern int g_4d70;
extern int g_3711;
extern int g_ad8b, g_ad8d;
extern unsigned g_ad8f, g_ad91;
extern int g_1f87, g_1f89;
extern long g_213c;
extern char far f_2803_0045;
extern char far f_2803_362f[][0x82];

void fn_0845_093a(void);
int fn_13e8_06a1(void);
char far *fn_0845_06f8(int id);
void far *ovr_2d5f_0084(int n, char far *name, int x, int y, int a, int flags);
void ovr_2d5f_008e(int n);
int ovr_2cef_0025(char far *p);
int ovr_2cef_0020(char far *p);
void fn_1ebc_0111(int x1, int y1, int x2, int y2);
void ovr_2dfd_002a(char far *p, int a, int b, int c, int d, int e);
void fn_1ebc_01ec(void);
void fn_178d_0091(int a);
void fn_178d_015e(void);
void fn_17d6_0006(int a);
void fn_17d6_0123(void);
int fn_154c_0136(void);
void fn_13e8_0903(int n, char far *a, char far *b, char far *c);
void fn_2169_062e(void);
void fn_163d_0004(void);
void fn_154c_000f(int a);
void ovr_2d5f_00fc(int a);
void ovr_2d5f_0101(int a);
int fn_07bc_012d(int a, int b, int c);
int fn_0c59_03a8(int h);
void fn_07bc_044c(int h);
void fn_1aff_030e(int far *a, int far *b, int c, int d, int e);
void fn_0845_03d4(int a);
void fn_0845_08d9(int a);
void fn_2279_025b(char far *d, char far *s, long n);
void fn_0845_1430(char far *p);
void fn_1ef2_0075(char far *p, int a, long b);
void ovr_2d5f_00f2(void);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_1dbc_0004(int a, int b, int c, int d, int e, int f, int g, int h);
void fn_130a_03cd(int a, int b, int c, char far *s, long d, int far *p, int e);
void fn_0845_15d9(int a);
void fn_1dbc_0017(int a, int b, int c, int d, int e, int f, int g, int h);
void fn_14b3_0122(int a);
void fn_1e59_001d(int a, int b, int c, int d, int e);
void fn_14b3_01fa(int a);
void fn_067a_003e(int a);
void fn_067a_01d1(int a);
int fn_154c_01d3(int a, int b, int c);
void fn_130a_0a7c(int a, char far *s, long b, int far *p, int c);
void fn_067a_0401(int a, int b);
void fn_130a_0c28(int a, int b);
void fn_130a_0cf6(int a);
void fn_057f_07aa(char c);

typedef int (far *TimOp)(int far *p);
extern TimOp g_1e48[];

int fn_057f_000a(void)
{
    int i;
    for (i = 1; i < 10; i++)
        memset(&g_4baa[i], 0, 12);
    g_4bae->ip = g_4bae->avtl;
    g_4bae->lastTime = g_384c;
    return 1;
}

int fn_057f_0053(void)
{
    int i;
    while (g_4bb4 == -1 && g_4bb2 == 0) {
        fn_0845_093a();
        g_4bb2 = fn_13e8_06a1();
    }
    for (i = 0; i < 10; i++)
        g_4bae[i].ip = 0;
    return -1;
}


#pragma option -Ob
int fn_057f_0096(char far *fmt, struct Emc far *s, int arg, char far *out, int far *pos)
{
    int far *q;
    int n = 0;
    int npos = 0;
    char far *start = fmt;
    int stop;

    while (*fmt) {
        if (*fmt++ != '%')
            continue;
        stop = 0;
        switch (*fmt) {
        case 0:
            stop = 1;
            break;
        case ' ':
        case '+':
        case '-':
            fmt++;
            break;
        case '#':
            fmt++;
            switch (*fmt) {
            case 'E': case 'G': case 'X': case 'c': case 'd': case 'e':
            case 'f': case 'g': case 'i': case 's': case 'u': case 'x':
                fmt++;
                break;
            default:
                stop = 1;
                break;
            }
            break;
        }
        if (!stop) {
            switch (*fmt) {
            case 0:
                stop = 1;
                break;
            case '0':
                fmt++;
                break;
            default:
                for (; *fmt && isdigit(*fmt); fmt++)
                    ;
                break;
            }
        }
        if (stop)
            continue;
        switch (*fmt) {
        case 0:
            stop = stop;
            continue;
        case 'n':
            pos[npos] = *fmt;
            pos[npos + 1] = fmt - start;
            npos += 2;
            *(char far * far *)(out + n) = f_2803_362f[s->stack[s->sp + arg]];
            arg++;
            n += 4;
            *fmt = 's';
            fmt++;
            break;
        case 's':
            *(char far * far *)(out + n) = fn_0845_06f8(s->stack[s->sp + arg++]);
            n += 4;
            fmt++;
            break;
        case 'X':
        case 'd':
        case 'u':
        case 'x':
            q = (int far *)(out + n);
            *q = s->stack[s->sp + arg];
            arg++;
            n += 2;
            fmt++;
            break;
        }
    }
    return n;
}
#pragma option -O-b

int fn_057f_02b6(int far *p)
{
    int n = p[0];
    struct WsaSlot far *w = &g_4baa[n];
    w->x = p[2];
    w->y = p[3];
    w->w8 = p[4];
    w->flags = p[5];
    w->wsa = ovr_2d5f_0084(n, (char far *)g_4bc4 + g_4bc4[p[1]], w->x, w->y, 10, w->flags);
    return 1;
}

int fn_057f_034f(int far *p)
{
    int n = *p;
    ovr_2d5f_008e(n);
    memset(&g_4baa[n], 0, 12);
    return 1;
}

int fn_057f_0384(int far *p)
{
    int n = *p;
    struct TimFunc far *t = &g_4bae[n];
    if (t->avtl == 0)
        t->ip = t->avtl = g_4bc0 + g_4bc0[n];
    else
        t->ip = t->avtl;
    return 1;
}

int fn_057f_03f7(int far *p)
{
    struct TimFunc far *t = &g_4bae[*p];
    t->ip = 0;
    return 1;
}

int fn_057f_0426(int far *p)
{
    int fl;
    int y;
    struct Shape far *o;
    o = &g_4ee0[p[0]];
    y = p[1];
    fl = (o->flags & 0x4000) ? 2 : 0;
    fn_1ebc_0111(o->x, o->y, o->x + ovr_2cef_0020(o->data), o->y + ovr_2cef_0025(o->data));
    ovr_2dfd_002a(o->data, y, o->x, o->y, fl, o->flags & 0xf0ff);
    fn_1ebc_01ec();
    return 1;
}

int fn_057f_04c9(void) { return 1; }
int fn_057f_04d1(void) { return 1; }
int fn_057f_04d9(void) { return 1; }
int fn_057f_04e1(void) { return 1; }
int fn_057f_04e9(void) { return 1; }
int fn_057f_04f1(void) { return 1; }
int fn_057f_04f9(void) { return 1; }

int fn_057f_0501(int far *p)
{
    fn_178d_0091(*p);
    return 1;
}

int fn_057f_0515(void)
{
    fn_178d_015e();
    return 1;
}

int fn_057f_0522(void) { return 1; }
int fn_057f_052a(void) { return 1; }

int fn_057f_0532(int far *p)
{
    fn_17d6_0006(*p);
    return 1;
}

int fn_057f_0546(void)
{
    fn_17d6_0123();
    return 1;
}

int fn_057f_0553(void)
{
    struct TimFunc far *t;
    if (g_81ff && fn_154c_0136() != 2) {
        fn_057f_07aa(0x15);
        return 1;
    }
    t = &g_4bae[g_4bb6];
    t->loopIp = t->ip;
    return 1;
}

int fn_057f_059b(int far *p)
{
    int r = *p;
    struct TimFunc far *t = &g_4bae[g_4bb6];
    if (t->loopIp) {
        t->ip = t->loopIp;
        if (r && fn_154c_0136() != 2)
            t->nextTime += (int)((long)rand() * r / 0x8000);
    }
    return -2;
}

int fn_057f_060e(int far *p)
{
    g_4bae[*p].loopIp = 0;
    return 1;
}

void fn_057f_0631(int far *p)
{
    int op = *p;
    int r;
    r = g_1e48[op](p + 1);
}

int fn_057f_065c(void)
{
    int i;
    struct TimFunc far *t;
    for (i = 0; i < 10; i++) {
        t = &g_4bae[i];
        if (t->ip)
            t->nextTime = g_384c + 1;
    }
    return 1;
}

int fn_057f_0699(void) { return 1; }

int fn_057f_06a1(int far *p)
{
    char far *s[3];
    int i, n;
    *g_4bbc = *p;
    g_4bb2 = 0;
    n = 0;
    for (i = 1; i <= 3; i++) {
        if (p[i] != -1) {
            s[i - 1] = fn_0845_06f8(p[i]);
            n++;
        } else
            s[i - 1] = 0;
    }
    fn_13e8_0903(n, s[0], s[1], s[2]);
    fn_2169_062e();
    fn_163d_0004();
    return -3;
}

int fn_057f_0730(void)
{
    int r = fn_13e8_06a1();
    if (r && *g_4bbc) {
        fn_154c_000f(0);
        g_4bae[*g_4bb8].loopIp = 0;
        g_4bb4 = *g_4bb8;
        *g_4bb8 = -1;
        g_4bb2 = r;
        g_5275 = 0;
        g_5276 = 0;
        g_5269 = 0;
        if (*g_4bbc)
            fn_057f_07aa(0x15);
    }
    return r;
}

void fn_057f_07aa(char op)
{
    struct TimFunc far *t = &g_4bae[g_4bb4];
    int prev = *t->ip;
    while (((char far *)t->ip)[4] != op) {
        if (((char far *)t->ip)[4] == 1) {
            *t->ip = prev;
            break;
        }
        prev = *t->ip;
        t->ip += *t->ip;
    }
    t->nextTime = g_384c;
}

void fn_057f_0814(int a)
{
    if (a) 0;
}

int fn_057f_081f(int far *p)
{
    ovr_2d5f_00fc(*p);
    return 1;
}

int fn_057f_0833(int far *p)
{
    ovr_2d5f_0101(*p);
    return 1;
}

int fn_057f_0847(void) { return 1; }

int fn_057f_084f(int far *p)
{
    int h = fn_07bc_012d(p[0], p[1], p[2]);
    if (!fn_0c59_03a8(h)) {
        fn_07bc_044c(h);
        return 0;
    }
    return 1;
}

int fn_057f_0887(int far *p)
{
    switch (*p) {
    case 0:
        g_7fd0 = p[1];
        fn_1aff_030e(&g_7fd2, &g_7fd4, g_7fd0, 0x80, 0x80);
        break;
    case 1:
        g_7fdf = p[1];
        break;
    }
    return 1;
}


#pragma option -Ob
int fn_057f_08cd(int far *p)
{
    switch (*p) {
    case 0:
        fn_0845_03d4(10);
        break;
    case 1:
        fn_2279_025b(g_adea + 0x180, g_4edc + 0x180, 0x180);
        fn_0845_1430(g_4edc);
        fn_1ef2_0075(g_4edc, 10, 0);
        g_20d5 = 0;
        break;
    case 2:
        fn_0845_08d9(10);
        break;
    case 3:
        fn_0845_1430(g_4edc);
        fn_1ef2_0075(g_4edc, 10, 0);
        g_20d5 = 0;
        break;
    case 4:
        ovr_2d5f_00f2();
        break;
    case 5:
        fn_0845_1430(g_4edc);
        fn_1ef2_0075(g_540e, 10, 0);
        g_20d5 = 0;
        break;
    default:
        break;
    }
    return 1;
}
#pragma option -O-b

int fn_057f_099a(int far *p)
{
    fn_1ebc_00e7();
    fn_1dbc_0004(p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]);
    fn_1ebc_00fe();
    return 1;
}

int fn_057f_09d6(int far *p)
{
    fn_130a_03cd(p[0], p[1], 1, fn_0845_06f8(p[2]), 0, p, 3);
    return 1;
}

int fn_057f_0a0a(int far *p)
{
    int n = *p;
    fn_0845_15d9(n);
    if (g_4d70 != 2 && n == 2)
        fn_1dbc_0017(0x70, 0, 0x70, 0, 0xb0, 0x78, g_4d70, 2);
    return 1;
}

int fn_057f_0a47(void)
{
    fn_0845_093a();
    return 1;
}

int fn_057f_0a54(void)
{
    if (!(f_2803_0045 && !g_81fe)) {
        fn_14b3_0122(5);
        fn_1ebc_00e7();
        fn_1e59_001d(g_ad8d, g_ad8b, g_ad8d + g_ad8f - 2, g_ad8b + g_ad91 - 2, g_3711);
        fn_14b3_01fa(4);
        fn_1ebc_00fe();
        g_1f87 = 0;
        g_1f89 = 0;
    }
    return 1;
}

int fn_057f_0ac1(int far *p)
{
    fn_067a_003e(*p);
    return 1;
}

int fn_057f_0ad5(int far *p)
{
    fn_067a_01d1(*p);
    return 1;
}

int fn_057f_0ae9(int far *p)
{
    int r;
    long t = g_384c;
    r = fn_154c_01d3(*p, 0, 0);
    if (r == 0 || g_81fe)
        fn_130a_0a7c(4, fn_0845_06f8(*p), 0, p, 1);
    g_213c = g_384c - t;
    return 1;
}

int fn_057f_0b4a(int far *p)
{
    fn_067a_0401(*p, 0);
    return 1;
}

int fn_057f_0b62(int far *p)
{
    fn_130a_0c28(p[0], p[1]);
    return 1;
}

int fn_057f_0b7c(int far *p)
{
    fn_130a_0cf6(*p);
    return 1;
}

int fn_057f_0b90(void) { return 1; }

TimOp g_1dcc[] = {
    (TimOp)fn_057f_000a, (TimOp)fn_057f_0053, fn_057f_02b6, fn_057f_034f, fn_057f_0384, fn_057f_03f7,
    fn_057f_0426, (TimOp)fn_057f_04c9, (TimOp)fn_057f_04d1, (TimOp)fn_057f_04d9, (TimOp)fn_057f_04e1,
    (TimOp)fn_057f_04e9, (TimOp)fn_057f_04f1, (TimOp)fn_057f_04f9, fn_057f_0501, (TimOp)fn_057f_0515,
    (TimOp)fn_057f_0522, (TimOp)fn_057f_052a, fn_057f_0532, (TimOp)fn_057f_0546, (TimOp)fn_057f_0553,
    fn_057f_059b, fn_057f_060e, (TimOp)fn_057f_065c, (TimOp)fn_057f_0699, (TimOp)fn_057f_0631, 0, 0,
    (TimOp)fn_057f_0730, fn_057f_06a1, (TimOp)fn_057f_0b90
};
TimOp g_1e48[] = {
    fn_057f_081f, fn_057f_0833, (TimOp)fn_057f_0847, fn_057f_084f, fn_057f_0887, fn_057f_08cd, fn_057f_099a,
    fn_057f_09d6, fn_057f_0a0a, (TimOp)fn_057f_0a47, (TimOp)fn_057f_0a54, fn_057f_0ac1, fn_057f_0ad5,
    fn_057f_0ae9, fn_057f_0b4a, fn_057f_0b62, fn_057f_0b7c
};
