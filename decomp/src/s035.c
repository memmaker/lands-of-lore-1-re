/* s035: file directory index (find / fetch / store entries, existence check through PAK parents) */
#include "lol.h"
#include <io.h>
#include <dir.h>
#include <string.h>

struct Dir {                /* 0x14 bytes, see s034 */
    char far *name;
    long size;
    long data;
    long off;
    unsigned char parent, refs;
    unsigned flags;
};

extern struct Dir far f_27fc_0000[];
extern int g_abd8, g_abda, g_abdc, g_ae4d;
extern char g_abde, g_ae59, g_aeaa;
extern char g_abe2[];

void fn_2148_002c(int drive);
void fn_2148_004d(int fd);
int fn_2148_000f(void);
int fn_1809_1460(char far *name, int mode);
void far *fn_2037_0002(void far *base, long off);
void fn_2279_025b(void far *src, void far *dst, long n);
void far *fn_242d_000f();
void far *fn_242d_0108(void far *key, void far *tmp, void far *base, int n, int w, int (far *cmp)());

int fn_1981_01af(char far *name);
struct Dir far *fn_1981_02c0(int idx, void far *buf);
char far *fn_1981_0365(char far *p);

char g_2aa6 = 1;
struct Dir far *g_2aa7 = 0;
char g_2aab = 0;

int fn_1981_000a(char far *name)
{
    struct Dir far *e = 0;
    int parent;
    int r;
    char buf[20];
    int idx;
    int fd;

    if (name) {
        idx = fn_1981_01af(name);
        e = fn_1981_02c0(idx, buf);
        if (idx != -1 && e->data)
            return 1;
        g_abdc = -1;
        fn_2148_002c(g_ae59 - 'A');
        g_abde++;
        fd = open(name, 0x8001, 0x100);
        g_abde--;
        if (fd != -1) {
            g_abde++;
            close(fd);
            r = getdisk();
            g_abde--;
            return r + 1;
        }
        if (idx != -1) {
            parent = e->parent;
            if (idx != -1 && (e->flags & 0x1000)) {
                e = fn_1981_02c0(parent, buf);
                return fn_1981_000a(fn_1981_0365(e->name));
            }
        }
        if (!!g_2aa6) {
            fn_2148_002c(g_aeaa - 'A');
            g_ae4d = 0;
            fd = fn_1809_1460(name, 0x8001);
            if (fd != -1) {
                fn_2148_004d(fd);
                return fn_2148_000f() + 1;
            }
            fn_2148_002c(g_ae59 - 'A');
        }
    }
    return 0;
}

int fn_1981_014c(char far **a, char far **b)
{
    return strcmp(*a, *b);
}

int fn_1981_0167(char far **a, char far **b)
{
    char na[14], nb[14];

    fn_2279_025b(*a, na, 14);
    fn_2279_025b(*b, nb, 14);
    return strcmp(na, nb);
}

int fn_1981_01af(char far *name)
{
    struct Dir far *r;
    struct Dir key;
    struct Dir tmp;
    int res = g_2aa7 == f_27fc_0000;

    if (!name)
        return -1;
    r = 0;
    key.name = strupr(name);
    if (strstr(key.name, ".PAK")) {
        if (res)
            r = fn_242d_0108(&key, &tmp, g_2aa7, g_abda, 0x14, fn_1981_014c);
        else
            r = fn_242d_000f(&key, &tmp, g_2aa7, g_abda, 0x14, fn_1981_0167);
    } else
        r = fn_242d_000f(&key, &tmp,
            res ? (void far *)&f_27fc_0000[g_abda] : fn_2037_0002(g_2aa7, (unsigned long)(unsigned)g_abda * 0x14),
            g_abd8, 0x14, res ? fn_1981_014c : fn_1981_0167);
    if (r)
        return ((long)r - (long)g_2aa7) / 0x14;
    return -1;
}

struct Dir far *fn_1981_02c0(int idx, void far *buf)
{
    if (idx == -1)
        return 0;
    if (g_2aa7 == f_27fc_0000)
        return &f_27fc_0000[idx];
    fn_2279_025b(fn_2037_0002(g_2aa7, (unsigned)(idx * 0x14)), buf, 0x14);
    return buf;
}

void fn_1981_031f(int idx, void far *buf)
{
    if ((g_2aa7 != f_27fc_0000) && idx != -1)
        fn_2279_025b(buf, fn_2037_0002(g_2aa7, (unsigned)(idx * 0x14)), 0x14);
}

char far *fn_1981_0365(char far *p)
{
    if (g_2aa7 == f_27fc_0000)
        return p;
    fn_2279_025b(p, g_abe2, 14);
    return g_abe2;
}
