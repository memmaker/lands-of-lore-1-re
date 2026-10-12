/* s035: PAK file directory lookup (files inside .PAK archives, CD vs hard disk) */
#include <string.h>
#include <io.h>
#include <dir.h>

typedef struct PakEnt {        /* 20 bytes */
    char far *name;
    long pos;
    long size;
    long unk0c;
    unsigned char pak;         /* +0x10: index of the containing .PAK entry */
    unsigned char pad;
    unsigned flags;            /* +0x12: 0x1000 = inside a PAK */
} PakEnt;

extern char g_2aa6;
extern PakEnt far *g_2aa7;
extern PakEnt far f_27fc_0000[];
extern int g_abd8, g_abda, g_abdc;
extern char g_abde;
extern int g_ae4d;
extern char g_ae59[], g_aeaa[];
extern char g_abe2[];

void fn_2148_002c(int d);
void fn_2148_004d(int fh);
int fn_2148_000f(void);
int fn_1809_1460(char far *name, int mode);
void far *fn_2037_0002(void far *p, long off);
void fn_2279_025b(void far *a, void far *b, long n);
void far *fn_242d_000f(void far *key, void far *tmp, void far *base, int n, int w, int (far *cmp)());
void far *fn_242d_0108(void far *key, void far *tmp, void far *base, int n, int w, int (far *cmp)());
int fn_1981_01af(char far *name);
PakEnt far *fn_1981_02c0(int i, PakEnt far *buf);
char far *fn_1981_0365(char far *name);

int fn_1981_000a(char far *name)
{
    PakEnt far *e;
    int pak;
    int d;
    PakEnt buf;
    register int i;
    int fh;

    e = 0;
    if (name) {
        i = fn_1981_01af(name);
        e = fn_1981_02c0(i, &buf);
        if (i != -1 && e->size != 0) return 1;
        g_abdc = -1;
        fn_2148_002c(g_ae59[0] - 'A');
        g_abde++;
        fh = open(name, 0x8001, 0x100);
        g_abde--;
        if (fh != -1) {
            g_abde++;
            close(fh);
            d = getdisk();
            g_abde--;
            return d + 1;
        }
        if (i != -1) {
            pak = e->pak;
            if (i != -1 && (e->flags & 0x1000)) {
                e = fn_1981_02c0(pak, &buf);
                return fn_1981_000a(fn_1981_0365(e->name));
            }
        }
        if (g_2aa6) {
            fn_2148_002c(g_aeaa[0] - 'A');
            g_ae4d = 0;
            fh = fn_1809_1460(name, 0x8001);
            if (fh != -1) {
                fn_2148_004d(fh);
                return fn_2148_000f() + 1;
            }
            fn_2148_002c(g_ae59[0] - 'A');
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
    char x[14];
    char y[14];

    fn_2279_025b(*a, x, 14L);
    fn_2279_025b(*b, y, 14L);
    return strcmp(x, y);
}

int fn_1981_01af(char far *name)
{
    PakEnt far *found;
    PakEnt key;
    PakEnt tmp;
    register int direct;

    direct = g_2aa7 == f_27fc_0000 ? 1 : 0;
    if (!name) return -1;
    found = 0;
    key.name = strupr(name);
    if (strstr(key.name, ".PAK")) {
        if (direct) found = fn_242d_0108(&key, &tmp, g_2aa7, g_abda, 20, fn_1981_014c);
        else found = fn_242d_000f(&key, &tmp, g_2aa7, g_abda, 20, fn_1981_0167);
    } else {
        found = fn_242d_000f(&key, &tmp,
            direct ? &f_27fc_0000[g_abda] : fn_2037_0002(g_2aa7, (long)(unsigned)g_abda * 20),
            g_abd8, 20, direct ? fn_1981_014c : fn_1981_0167);
    }
    if (found) return ((long)found - (long)g_2aa7) / 20;
    return -1;
}

PakEnt far *fn_1981_02c0(int i, PakEnt far *buf)
{
    if (i == -1) return 0;
    if (g_2aa7 == f_27fc_0000) return &f_27fc_0000[i];
    fn_2279_025b(fn_2037_0002(g_2aa7, (unsigned)(i * 20)), buf, 20L);
    return buf;
}

void fn_1981_031f(int i, PakEnt far *e)
{
    if ((g_2aa7 != f_27fc_0000) && i != -1)
        fn_2279_025b(e, fn_2037_0002(g_2aa7, (unsigned)(i * 20)), 20L);
}

char far *fn_1981_0365(char far *name)
{
    if (g_2aa7 == f_27fc_0000) return name;
    fn_2279_025b(name, g_abe2, 14L);
    return g_abe2;
}
