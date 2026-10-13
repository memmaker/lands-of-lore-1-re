/* s020: item placement, wall setting, TIM animation slots, character speech text */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mem.h>
#include <ctype.h>
#include "lol.h"

extern int g_7fdf;
extern char far f_27b1_0010[];
extern char g_7fe5, g_7fe3, g_81fe, g_81ff;
extern unsigned g_7fd6;
extern struct Anim g_4ee0[];
extern unsigned long g_384c, g_4c02;
extern unsigned char far f_2803_3835[];
extern int far f_2803_3625[];
extern int g_4bf8, g_4bfa, g_4bfc, g_4c00, g_4bea;
extern int g_1f87, g_1f89, g_3713, g_20f4, g_20f6, g_2170;
extern int g_7fe6[];
extern unsigned char g_2fac[];
extern void far *g_7fb8;

void fn_09aa_033f(char far *p);
void fn_09aa_02bb(char far *p);
void fn_1aff_030e(int far *x, int far *y, int b, int cx, int cy);
void fn_07bc_0367(int it, int b);
void fn_07bc_0272(int it, int x, int y, int a, int b);
void fn_067a_0401(int n, int force);
int ovr_2cef_0020(char far *w);
int ovr_2cef_0025(char far *w);
void fn_1ebc_0111(int x1, int y1, int x2, int y2);
void ovr_2dfd_002a(char far *w, int frame, int x, int y, int flags, ...);
void fn_1ebc_01ec(void);
void fn_0845_046c(int block);
int ovr_2d74_0025(void);
int fn_154c_01d3(int a, int b, int c);
int fn_14b3_01fa(int n);
void fn_1e9a_000b(int a, int b, int c, int d, int e);
int fn_14b3_0122(int n);
int fn_0845_0636(int lo, int hi);
int fn_154c_0136(void);
void fn_0a21_05ef(int ch, int face);
void fn_0a21_022b(int ch);
void fn_0a21_00ec(int ch, int x, int y, int a);
void fn_0a21_0608(int ch);
void fn_0845_114d(int id, int flag);
char far *fn_0845_06f8(int id);
void fn_1ebc_00e7(void);
void fn_1ef2_002f(unsigned char far *pal, int i, unsigned char far *rgb);
void fn_0bbc_070e(int n, int en);
void fn_1ebc_00fe(void);
int fn_1e74_000f(int n);
void far *fn_1f2d_0002(void far *p);
void fn_14b3_0284(char far *s);

void fn_130a_0605(void);
void fn_130a_0784(void);
void fn_130a_0a7c(int page, char far *fmt, struct EmcState far *s, int far *p, int idx);

int fn_130a_0001(int dir)
{
    int d;

    d = dir - g_7fdf;
    if (ABS(d) > 2) d = -(d ^ 2);
    while (d) {
        if (d > 0) {
            fn_09aa_033f(f_27b1_0010);
            d--;
        } else {
            fn_09aa_02bb(f_27b1_0010);
            d++;
        }
    }
    return 1;
}

void fn_130a_0052(int it, int level, int block, int x, int y, int sub)
{
    fn_1aff_030e(&f_2803_1cfd[it].x, &f_2803_1cfd[it].y, block, x, y);
    if (f_2803_1cfd[it].block) fn_07bc_0367(it, f_2803_1cfd[it].block);
    if (g_7fe5 == level) {
        fn_07bc_0272(it, f_2803_1cfd[it].x, f_2803_1cfd[it].y, sub, 1);
    } else {
        f_2803_1cfd[it].level = level;
        f_2803_1cfd[it].block = block;
        f_2803_1cfd[it].sub = sub;
        f_2803_1cfd[it].flags |= 0x4000;
    }
}

int fn_130a_012a(struct Anim far *a)
{
    int far *f;
    int step;

    f = a->frames[a->cf];
    a->next = 0;
    if (f[1] < f[0]) {
        step = -1;
        a->frame--;
    } else {
        step = 1;
        a->frame++;
    }
    if (a->frame == f[1] + step) {
        if (++a->loops <= f[2] && !a->cd) {
            a->frame = *f;
        } else {
            a->c14 = a->cf;
            if (f[3] != -1 && !(a->cd && f[5])) {
                a->next += f[4];
                a->cf = f[3];
                f = a->frames[a->cf];
                a->frame = *f;
                a->loops = 0;
            } else {
                a->cc = 0;
                a->cd = 0;
                return 0;
            }
        }
    }
    if (f[6] != -1 && a->frame == f[7]) fn_067a_0401(f[6], 0);
    a->next += a->ce;
    return 1;
}

void fn_130a_028a(void)
{
    struct Anim far *a;
    int i;

    if (!(g_7fd6 & 8)) {
        for (i = 0, a = g_4ee0; i < 6; i++, a++) {
            if (a && a->cc && a->next < g_384c && fn_130a_012a(a)) {
                fn_1ebc_0111(a->x, a->y, a->x + ovr_2cef_0020(a->wsa), a->y + ovr_2cef_0025(a->wsa));
                ovr_2dfd_002a(a->wsa, a->frame - 1, a->x, a->y, 0, 0);
                fn_1ebc_01ec();
                a->next += g_384c;
            }
        }
    }
}

void fn_130a_0360(int block, int dir, int v)
{
    int i;

    if (dir == -1) {
        for (i = 0; i < 4; i++) WALL(block, i) = v;
        if (f_2803_3835[v] == 0x11) {
            g_8203[block].flags &= ~0x10;
            g_8203[block].flags |= 0x20;
        } else {
            g_8203[block].flags &= ~0x20;
        }
    } else {
        WALL(block, dir) = v;
    }
    fn_0845_046c(block);
}

int fn_130a_03cd(int ch, int type, int c, char far *str, struct EmcState far *s, int far *p, int e)
{
    int save;
    int skip;
    int who;
    int i;

    skip = 0;
    if (ch != -1 && (ch & 0x70)) {
        ch ^= 0x70;
        who = 0;
    } else {
        if (ch == 1) ch = g_7fe3 ? f_2803_362d[g_7fe3].wE : 0;
        who = ch;
    }
    fn_130a_0784();
    if (ch < 0) {
        ch = (long)rand() * ovr_2d74_0025() / 0x8000L;
        who = ch;
    } else if (ch > 0) {
        for (i = 0; i < 4; i++) {
            if (f_2803_362d[i].wE == ch && (f_2803_362d[i].flags & 1)) {
                if (who == ch) who = i;
                ch = i;
                break;
            }
        }
        if (i == 4) {
            if (ch == 8) skip = 1;
            else return 0;
        }
    }
    if (!skip) {
        g_4bf8 = ch;
        g_4bfa = type;
        g_4bfc = strlen(str) >> 1;
        g_4c00 = c;
    }
    if (s) fn_154c_01d3(ARG(s, 2), who, 0);
    else if (p) fn_154c_01d3(p[2], who, 0);
    if (g_81fe) {
        switch (type) {
        case 0:
            fn_130a_0a7c(3, str, s, p, e);
            break;
        case 1:
            g_1f87 = 0;
            g_1f89 = 0;
            fn_14b3_01fa(4);
            fn_1e9a_000b(4, 0x10, 0x7b, 0x17, 0x2f);
            fn_130a_0a7c(4, str, s, p, e);
            fn_1e9a_000b(4, 0x0b, 0x7b, 0x1c, 0x2f);
            break;
        case 2:
            g_1f87 = 0;
            g_1f89 = 0;
            save = fn_14b3_01fa(4);
            fn_1e9a_000b(4, 0x09, 0x85, 0x1e, 0x3c);
            fn_130a_0a7c(4, str, s, p, 3);
            fn_14b3_0122(save);
            fn_1e9a_000b(4, 0x01, 0x85, 0x25, 0x3c);
            break;
        }
    }
    g_20f6 = 0;
    if (!skip) fn_130a_0605();
    return 1;
}

void fn_130a_0605(void)
{
    int y;
    int def;
    register int face;
    register int x;

    x = 0;
    y = 0;
    def = 0;
    switch (g_4bfa) {
    case 0:
        x = f_2803_3625[g_4bf8];
        y = 0x90;
        def = 1;
        break;
    case 1:
        if (!g_81fe) {
            x = f_2803_3625[g_4bf8];
            y = 0x90;
        } else {
            x = 0x5a;
            y = 0x82;
        }
        break;
    case 2:
        if (!g_81fe) {
            y = 0x91;
            x = f_2803_3625[g_4bf8] + 10;
        } else {
            x = 0x10;
            y = 0x86;
        }
        break;
    }
    face = fn_0845_0636(1, 6) - 1;
    if (f_2803_362d[g_4bf8].face == face) face++;
    if (face > 5) face -= 5;
    face += 7;
    if (g_81ff) {
        if (fn_154c_0136() == 2) g_4bfc = 2;
        else g_4bfc = 1;
    }
    if (--g_4bfc) {
        fn_0a21_05ef(g_4bf8, face);
        if (def) fn_0a21_022b(g_4bf8);
        else fn_0a21_00ec(g_4bf8, x, y, 0);
        g_4c02 = g_384c + 10;
    } else if (g_4bfc == 0 && g_4c00) {
        fn_0a21_0608(g_4bf8);
        if (def) {
            fn_0a21_022b(g_4bf8);
            fn_0845_114d(0, 0);
        } else {
            fn_0a21_00ec(g_4bf8, x, y, 0);
        }
        g_4bf8 = -1;
    }
}

void fn_130a_0784(void)
{
    if (g_4bf8 != -1) {
        g_4bfc = 1;
        g_4c00 = 1;
        fn_130a_0605();
        g_4bf8 = -1;
        g_4bfc = 1;
        if (g_4bfa == 0) fn_0845_114d(0, 0);
    }
}

/* scan fmt for printf conversions, build the va_list in out from script arguments;
   %n (character name) and %a are rewritten in place, save[] remembers the original chars */

int fn_130a_07be(char far *fmt, struct EmcState far *s, int far *p, int idx, char far *out, int far *save);

int fn_130a_07be(fmt, s, p, idx, out, save)
char far *fmt;
struct EmcState far *s;
int far *p;
register int idx;
char far *out;
int far *save;
{
    int n;
    int far *ip;
    int k;
    char far *start;
    int done;

    n = 0;
    k = 0;
    start = fmt;
    while (*fmt) {
        if (*fmt++ != '%') continue;
        done = 0;
        switch (*fmt) {
        case 0:
            done = 1;
            break;
        case ' ': case '+': case '-':
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
                done = 1;
                break;
            }
            break;
        }
        if (!done) {
            switch (*fmt) {
            case 0:
                done = 1;
                break;
            case '0':
                fmt++;
                break;
            default:
                while (*fmt && isdigit(*fmt)) fmt++;
                break;
            }
        }
        if (done) continue;
        switch (*fmt) {
        case 0:
            done = done;    /* keeps case 0 in the jump table */
            continue;
        case 'n':
            save[k] = *fmt;
            save[k + 1] = fmt - start;
            k += 2;
            *(char far * far *)(out + n) = f_2803_362d[s ? ARG(s, idx) : p[idx]].name;
            idx++;
            n += 4;
            *fmt = 's';
            fmt++;
            break;
        case 's':
            if (s) *(char far * far *)(out + n) = fn_0845_06f8(ARG(s, idx++));
            else *(char far * far *)(out + n) = fn_0845_06f8(p[idx++]);
            n += 4;
            fmt++;
            break;
        case 'a':
            save[k] = *fmt;
            save[k + 1] = fmt - start;
            k += 2;
            ip = (int far *)(out + n);
            *ip = g_4bea;
            n += 2;
            *fmt = 'd';
            fmt++;
            break;
        case 'X': case 'd': case 'u': case 'x':
            ip = (int far *)(out + n);
            *ip = s ? ARG(s, idx) : p[idx];
            idx++;
            n += 2;
            fmt++;
            break;
        }
    }
    return n;
}

void fn_130a_0a7c(int page, char far *fmt, struct EmcState far *s, int far *p, int idx)
{
    int r;
    int oldWin;
    void far *oldFont;
    char buf[0x400];
    unsigned char pal[0x300];
    char args[30] = { 0 };
    int save[20];
    int i;

    fn_1ebc_00e7();
    if (page == 3) {
        if (g_7fd6 & 2) {
            page = fn_14b3_01fa(4);
            g_3713 = 0xfe;
        } else {
            page = fn_14b3_01fa(3);
            g_3713 = 0xc0;
            memcpy(pal, g_2fac, 0x300);
            fn_1ef2_002f(pal, 0xc0, pal + 0xfe * 3);
            fn_0bbc_070e(0x0b, 1);
            g_20f4 = 0;
            g_20f6 = 0;
        }
    } else {
        page = fn_14b3_0122(page);
        g_3713 = 0xfe;
    }
    fn_1ebc_00fe();
    oldWin = fn_1e74_000f(0);
    oldFont = fn_1f2d_0002(g_7fb8);
    setmem(save, sizeof(save), 0);
    r = fn_130a_07be(fmt, s, p, idx, args, save);
    if (r) {
        vsprintf(buf, fmt, args);
        g_2170 = strlen(buf);
        fn_14b3_0284(buf);
    } else {
        g_2170 = strlen(fmt);
        fn_14b3_0284(fmt);
    }
    for (i = 0; i < 10; i += 2) {
        if (!save[i]) break;
        fmt[save[i + 1]] = save[i];
    }
    fn_14b3_0122(page);
    fn_1e74_000f(oldWin);
    fn_1f2d_0002(oldFont);
    g_20f6 = 0;
}

void fn_130a_0c28(int n, char seq)
{
    int far *f;
    struct Anim far *a;

    a = &g_4ee0[n];
    a->cf = seq;
    f = a->frames[a->cf];
    a->cc = 1;
    a->next = g_384c + a->ce;
    a->frame = *f;
    a->loops = 0;
    fn_1ebc_0111(a->x, a->y, a->x + ovr_2cef_0020(a->wsa), a->y + ovr_2cef_0025(a->wsa));
    ovr_2dfd_002a(a->wsa, a->frame - 1, a->x, a->y, 0, 0);
    fn_1ebc_01ec();
}

void fn_130a_0cf6(int n)
{
    g_4ee0[n].cc = 0;
    g_4ee0[n].cd = 0;
    if (n == 5) g_4ee0[n].wsa = 0;
}

int fn_130a_0d2b(int any, int ch, int type)
{
    int i;
    int end;
    int j;

    if (any == 0) {
        for (i = 0; i < 0x30; i++)
            if (g_7fe6[i] && f_2803_1cfd[g_7fe6[i]].type == type) return 0;
    }
    i = ch;
    end = i;
    if (i == -1) {
        i = 0;
        end = 4;
    }
    if (i < end) do {
        if (f_2803_362d[i].flags & 1) {
            for (j = 0; j < 11; j++)
                if (f_2803_362d[i].items[j] && f_2803_1cfd[f_2803_362d[i].items[j]].type == type) return i;
        }
        i++;
    } while (i < end);
    return -1;
}
