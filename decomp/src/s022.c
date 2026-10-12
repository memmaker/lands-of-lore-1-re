/* s022: text window printer (formatted output, word wrap, scrolling, <MORE> prompt) */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include "lol.h"

struct TextWin {            /* 16 bytes, g_1f3b[] */
    int x, y, w, h;         /* x and w in 8-pixel units */
    int c1, c2;
    int col, row;
};

extern struct TextWin g_1f3b[];
extern char far *g_1614;
extern void (far *g_370d)(char far *s, int a, int b, int c);
extern char g_3644;
extern int g_3649, g_2172;
extern int g_3711, g_3713, g_3715, g_3717, g_3719, g_371b;
extern int g_3624, g_3626;
extern char g_3628, g_3629;
extern unsigned g_ad8b, g_ad8d, g_ad8f, g_ad91, g_ad93, g_ad95;
extern char g_ab3e;
extern char g_ab3f[2];      /* lookahead: current char, next char */
#define g_ab40 g_ab3f[1]
extern char far *g_ab41;
extern char far *g_ab45;
extern int g_ab49, g_ab4b, g_ab4d;
extern char g_ab4f[];

void fn_1f6c_0006(char far *s, int x, int y, int c1, int c2);
void fn_234e_0003(int n);
void fn_234e_0062(void);
void fn_2169_062e(void);
void fn_2169_06e9(void);
void fn_1e59_001d(int x1, int y1, int x2, int y2, int c);
void fn_1dbc_0017(int a, int b, int c, int d, int e, int f, int g, int h);
int fn_1e64_0007(char c);
unsigned fn_1e64_002b(char far *s);

void fn_14b3_0215(void);
void fn_14b3_0284(char far *fmt, ...);
void fn_14b3_062d(void);
void fn_14b3_0731(void);
void fn_14b3_08e1(char far *dst);
char fn_14b3_095d(void);

int g_284c = 0;
char g_284e = 0;
int g_284f = 7;
int g_2851 = 0;
int g_2853 = 0;

void fn_14b3_0001(char far *s, int col, int c1, int c2)
{
    int w;
    int x;
    int y;

    w = (col - 1) * (g_3628 + g_3624);
    x = (g_ad8d + g_ad8f) << 3;
    x -= w;
    y = g_ad8b + (g_ad93 - 1) * (g_3629 + g_3626);
    fn_1f6c_0006(s, x, y, c1 ? c1 : g_1f3b[g_3715].c2, c2 ? c2 : g_1f3b[g_3715].c1);
    if (!g_3649) fn_234e_0062();
    fn_2169_062e();
    fn_2169_06e9();
    if (!g_3649) fn_234e_0003(g_3715);
    fn_1e59_001d(x, y, x + w - 1, g_3629 + g_3626 + y - 1, g_3711);
}

void fn_14b3_00c8(char far *s, int a, int b, int c)
{
    if (s) {
        g_1614 = s;
        g_284f = a;
        g_2851 = b;
        g_2853 = c;
    } else {
        g_1614 = "<MORE>";
        g_284f = 7;
        g_2851 = g_2853 = 0;
    }
}

void fn_14b3_0108(void)
{
    g_3644 = 1;
    g_284c = 0;
}

void fn_14b3_0118(void)
{
    g_3644 = 0;
}

int fn_14b3_0122(int n)
{
    int old;
    int far *p;

    old = g_3715;
    g_3715 = n;
    p = (int far *)&g_1f3b[n];
    g_ad8d = *p; p++;
    g_ad8b = *p; p++;
    g_ad8f = *p; p++;
    g_ad91 = *p; p++;
    g_3713 = *p; p++;
    g_3711 = *p; p++;
    g_ad95 = *p; p++;
    g_ad93 = *p;
    g_284c = 0;
    g_ab49 = g_ad95 / (unsigned)(g_3628 + g_3624);
    g_3717 = (g_ad91 - g_3626) / (unsigned)(g_3629 + g_3626);
    g_371b = g_ad8f << 3;
    g_3719 = g_371b / (g_3628 + g_3624);
    return old;
}

int fn_14b3_01fa(int n)
{
    int old;

    old = fn_14b3_0122(n);
    fn_14b3_0215();
    return old;
}

void fn_14b3_0215(void)
{
    int x1;
    int y1;
    int x2;
    int y2;

    x1 = g_ad8d << 3;
    y1 = g_ad8b;
    x2 = (g_ad8d + g_ad8f) << 3;
    y2 = g_ad8b + g_ad91;
    fn_1e59_001d(x1, y1, x2 - 1, y2 - 1, g_3711);
    g_ad95 = g_ab49 = 0;
    g_ad93 = 0;
    g_284c = 0;
}

void fn_14b3_0270(int n)
{
    fn_14b3_0284("%d", n);
}

void fn_14b3_0284(char far *fmt, ...)
{
    char c;
    char buf[10];
    int c2;
    int c1;
    va_list ap;

    va_start(ap, fmt);
    g_284e = 0;
    g_ab4d = g_ab4b = 0;
    g_ab4f[0] = 0;
    g_ab3f[0] = g_ab40 = 0;
    g_ab45 = fmt;
    g_ab41 = 0;
    c2 = g_3713;
    c1 = g_3711;
    if (!g_3649) fn_234e_0003(g_3715);
    for (;;) {
        c = fn_14b3_095d();
        if (!c) break;
        if (g_ab41 == 0 && c == '%') {
            switch (tolower(g_ab3f[0])) {
            case 's':
                g_ab41 = va_arg(ap, char far *);
                if (g_ab41 == 0) break;
            next:
                g_ab3e = g_ab40;
                g_ab3f[0] = g_ab40 = 0;
                c = fn_14b3_095d();
                break;
            case 'd':
                g_ab41 = buf;
                sprintf(buf, "%d", va_arg(ap, int));
                goto next;
            }
        }
        switch (c) {
        case 24:
            fn_14b3_0731();
            g_ab49 = fn_14b3_095d();
            g_ab49 = g_ab49 < 0 ? 0 : g_ab49;
            g_ab49 = g_3719 - 1 < g_ab49 ? g_3719 - 1 : g_ab49;
            goto tab;
        case 25:
            fn_14b3_0731();
            g_ad93 = fn_14b3_095d();
            g_ad93 = g_3717 - 1 < g_ad93 ? g_3717 - 1 : g_ad93;
            break;
        case 1:
            fn_14b3_0731();
            if (g_370d == 0) break;
            if (!g_3649) fn_234e_0062();
            g_370d(g_1614, g_284f, g_2851, g_2853);
            if (!g_3649) fn_234e_0003(g_3715);
            g_2172 = 0;
            break;
        case 12:
            fn_14b3_0215();
            break;
        case 13:
            fn_14b3_0731();
            g_284c++;
            g_ad95 = 0;
            goto nl;
        case 2:
            fn_14b3_0731();
            g_3711 = fn_14b3_095d();
            break;
        case 6:
            fn_14b3_0731();
            g_3713 = fn_14b3_095d();
            break;
        case 9:
            fn_14b3_0731();
            g_ab49 = ((g_ab49 + 8) & ~7) - 1;
            if (g_ab49 >= g_3719) g_ab49 = 0;
        tab:
            g_ad95 = g_ab49 * (g_3628 + g_3624);
            break;
        case 19: {
            int x0;
            int xb;
            int y;

            fn_14b3_0731();
            x0 = g_ad95;
            xb = g_ad8d << 3;
            y = g_ad8b + g_ad93 * (g_3629 + g_3626);
            g_ab49 = ((g_ab49 + 8) & ~7) - 1;
            if (g_ab49 >= g_3719) {
                g_ad95 = g_ab49 = 0;
                fn_1e59_001d(xb + x0, y, xb + g_371b - 1, g_3629 + g_3626 + y - 1, g_3711);
                g_284c++;
            nl:
                g_ad93++;
            } else {
                g_ad95 = g_ab49 * (g_3628 + g_3624);
                fn_1e59_001d(xb + x0, y, xb + g_ad95 - 1, g_3629 + g_3626 + y - 1, g_3711);
            }
            break;
        }
        case 27:
            c = 0x7f;
        case 29:
            if (c != 0x7f) c = 0;
            c += fn_14b3_095d();
        default:
            g_ab4b += fn_1e64_0007(c);
            g_ab4f[g_ab4d++] = c;
            g_ab4f[g_ab4d] = 0;
            if (g_ad95 + g_ab4b > g_371b) fn_14b3_0731();
            break;
        }
    }
    if (g_ab4d) fn_14b3_0731();
    g_1f3b[g_3715].col = g_ad95;
    g_1f3b[g_3715].row = g_ad93;
    g_3713 = c2;
    g_1f3b[g_3715].c1 = g_3713;
    g_3711 = c1;
    g_1f3b[g_3715].c2 = g_3711;
    if (!g_3649) fn_234e_0062();
}

void fn_14b3_062d(void)
{
    int y;

    if (g_3717 - 1 <= g_284c && g_3644 != 0) {
        g_284c = 0;
        if (g_370d) {
            if (!g_3649) fn_234e_0062();
            g_370d(g_1614, g_284f, g_2851, g_2853);
            if (!g_3649) fn_234e_0003(g_3715);
            g_2172 = 0;
        }
    }
    y = (g_ad91 / (g_3629 + g_3626) - 1) * (g_3629 + g_3626);
    if (g_ad91 - (g_3629 + g_3626))
        fn_1dbc_0017(g_ad8d, g_ad8b + (g_3629 + g_3626), g_ad8d, g_ad8b, g_ad8f,
                     g_ad91 - (g_3629 + g_3626), g_3649, g_3649);
    fn_1e59_001d(g_ad8d << 3, g_ad8b + y, ((g_ad8d + g_ad8f) << 3) - 1, g_ad8b + g_ad91 - 1, g_3711);
}

void fn_14b3_0731(void)
{
    int brk;
    int w;
    int maxw;
    int x;
    int y;
    char ch;
    int n;
    int i;

    while (g_ad93 >= g_3717) {
        fn_14b3_062d();
        if (g_ad93 >= g_3717) g_ad93--;
    }
    x = (g_ad8d << 3) + g_ad95;
    y = g_ad8b + g_ad93 * (g_3629 + g_3626);
    maxw = g_371b;
    n = g_ab4d;
    w = g_ab4b;
    if (g_ad95 + w > maxw) {
        if (g_3717 - 1 <= g_284c && g_3644 != 0) maxw -= g_284f * (g_3628 + g_3624);
        maxw = maxw - g_ad95;
        brk = 0;
        for (i = n - 1; i > 0; i--) {
            ch = g_ab4f[i];
            w -= fn_1e64_0007(ch);
            if (brk == 0 && w <= maxw) brk = i;
            if (brk != 0 && ch == ' ') {
                n = i;
                g_284e = 0;
                break;
            }
        }
        if (i == 0) {
            if (g_ad95 != 0 && !g_284e) {
                n = w = 0;
                g_284e = 1;
            } else n = brk;
        }
    }
    ch = g_ab4f[n];
    g_ab4f[n] = 0;
    fn_1f6c_0006(g_ab4f, x, y, g_3713, g_3711);
    g_ad95 += w;
    g_2172 += strlen(g_ab4f);
    g_ab4f[n] = ch;
    if (ch == ' ') n++;
    if (g_ab4f[n] == ' ') n++;
    strcpy(g_ab4f, g_ab4f + n);
    g_ab4d = strlen(g_ab4f);
    g_ab4b = fn_1e64_002b(g_ab4f);
    if (g_ab4d != 0 || g_ad95 >= g_371b) {
        g_ad95 = g_ab49 = 0;
        g_ad93++;
        g_284c++;
        fn_14b3_0731();
    }
}

void fn_14b3_08e1(char far *dst)
{
    char z;
    char c;

    c = z = 0;
    if (g_ab41) {
        if (*g_ab41 == 0) {
            g_ab41 = 0;
            c = g_ab3e;
        } else c = *g_ab41++;
    }
    if (!c && g_ab45) {
        if (*g_ab45 == 0) g_ab45 = 0;
        else c = *g_ab45++;
    }
    *dst++ = c;
    *dst = z;
}

char fn_14b3_095d(void)
{
    char c;

    if (!g_ab3f[0]) fn_14b3_08e1(g_ab3f);
    c = g_ab3f[0];
    g_ab3f[0] = g_ab40;
    g_ab40 = 0;
    if (!g_ab3f[0]) fn_14b3_08e1(g_ab3f);
    return c;
}
