/* s122: WW library -- text compression with the common-letter pair table, string table lookup */
#include <dos.h>

extern char g_38b0[16];        /* 16 most common characters */
extern char g_38c0[16][8];     /* their 8 most common followers */

void far *fn_2037_0002(void far *p, long off);
void far fn_2279_025b(void far *src, void far *dst, unsigned long n);
int far fn_2365_063f(void far *p);
int far fn_19ba_0086(void far *p);

/* copy a string, ESC c expands to c + 0x7f */
void far fn_212a_0005(char far *src, char far *dst)
{
    if (src != 0 && dst != 0) {
        while (*src != 0) {
            *dst = *src == 0x1b ? (src++, *src + 0x7f) : *src;
            src++;
            dst++;
        }
        *dst = 0;
    }
}

/* pack: a common pair becomes 0x80 | i << 3 | j; chars > 0x7f are escaped; returns the packed length */
int far fn_212a_0052(char far *src, char far *dst)
{
    char next;
    int j;
    register int n;
    register unsigned char c;
    register int i;

    n = 0;
    while (c = *src, src++, next = *src, c) {
        if (c > 0x7f) {
            *dst++ = 0x1b;
            n++;
            c = c - 0x7f;
        } else {
            for (i = 0; i < 16; i++) {
                if (g_38b0[i] == c) {
                    for (j = 0; j < 8; j++) {
                        if (g_38c0[i][j] == next) {
                            c = i << 3 | j | 0x80;
                            src++;
                        }
                    }
                }
            }
        }
        *dst++ = c;
        n++;
    }
    *dst = 0;
    return n;
}

/* unpack (inverse of fn_212a_0052 without the escapes); returns the length */
int far fn_212a_00e5(char far *src, char far *dst)
{
    register int n;
    register int c;
    register int k;

    n = 0;
    while (c = *src, src++, c) {
        if (c & 0x80) {
            c &= 0x7f;
            k = (c & 0x78) >> 3;
            *dst++ = g_38b0[k];
            n++;
            c = g_38c0[k][c & 7];
        }
        *dst++ = c;
        n++;
    }
    *dst++ = 0;
    return n;
}

/* string idx of a table that starts with word offsets */
char far *fn_212a_014c(char far *tab, register int idx)
{
    unsigned far *offs;
    unsigned off;

    if (tab == 0 || idx < 0)
        return 0;
    if (fn_2365_063f(tab) || fn_19ba_0086(tab)) {
        fn_2279_025b(fn_2037_0002(tab, (unsigned long)(unsigned)(idx << 1)), (void far *)&off, 2L);
        return fn_2037_0002(tab, (unsigned long)off);
    } else {
        offs = (unsigned far *)tab;
        return tab + offs[idx];
    }
}
