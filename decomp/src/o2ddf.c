/* o2ddf: PAK index loading, PAK cache flush, start-up directories */
#include <string.h>
#include <stdlib.h>
#include <dir.h>
#include <dos.h>

typedef struct PakEnt {        /* 20 bytes, f_27fc_0000[] (see s034) */
    char far *name;
    long size;                 /* +04 */
    void far *data;            /* +08 */
    long off;                  /* +0c */
    unsigned char pak;         /* +10 */
    unsigned char refs;        /* +11 */
    unsigned flags;            /* +12 */
} PakEnt;

typedef struct FileH {         /* 20 bytes, f_2c12_0000[20] */
    int free;
    int fd;
    long pos;
    long start;
    int ent;
    int mode;
    char far *name;
} FileH;

extern PakEnt far f_27fc_0000[];
extern FileH far f_2c12_0000[];
extern PakEnt far *g_2aa7;
extern char g_2aa6;
extern int g_abd8, g_abda;
extern char g_ad46;
extern int g_ae4d, g_ae57;
extern char g_ae59[], g_aeaa[], g_aefb[];
extern char g_1dba[], g_1dbf[], g_1dc3[], g_1dc6[];

int fn_1809_0000(char far *name, int mode);
void fn_1809_058d(int h);
long fn_1809_084d(int h, void far *buf, unsigned long n);
long fn_1809_120c(int h);
PakEnt far *fn_1981_02c0(int i, PakEnt far *buf);
void fn_1981_031f(int i, PakEnt far *buf);
char far *fn_1981_0365(char far *name);
void far *fn_203b_0007(unsigned long size, int flags);
long fn_203b_03b4(int flags);
void fn_2279_025b(void far *s, void far *d, unsigned long n);
void far *fn_2037_0002(void far *p, long off);
void fn_2148_002c(int d);
char far *fn_2253_000f(char far *name);
int fn_22de_02a4(void);

int ovr_2ddf_0020(char far *name);
int ovr_2ddf_0025(char far *path);
int ovr_2ddf_002a(char c);
void ovr_2ddf_002f(void);
void ovr_2ddf_0034(void);
void ovr_2ddf_0039(void);
int ovr_2ddf_003e(char far * far *a, char far * far *b);

int ovr_2ddf_0020(char far *name)
{
    unsigned long size;
    void far *buf;
    PakEnt ent;
    char nm[13];
    int h;
    int i;

    for (i = 0; i < 20; i++) f_2c12_0000[i].free = 1;
    g_2aa7 = f_27fc_0000;
    ovr_2ddf_0039();
    if (name != 0) {
        h = fn_1809_0000(name, 1);
        size = fn_1809_120c(h) + 15;
        if (fn_203b_03b4(0x42) < size && fn_203b_03b4(0x82) < size) {
            fn_1809_058d(h);
            return 0;
        }
        buf = fn_203b_0007(size, 0xc2);
        fn_1809_084d(h, buf, size - 15);
        fn_1809_058d(h);
        g_2aa7 = buf;
        g_abda = g_abd8 = 0;
        nm[12] = 0;
        for (;;) {
            fn_2279_025b(buf, &ent, 20L);
            if (ent.name == 0) break;
            ent.name = fn_2037_0002(g_2aa7, (long)ent.name);
            fn_2279_025b(ent.name, nm, 12L);
            if (g_abd8 == 0 && strstr(nm, g_1dba) != 0) {
                g_abda++;
                ent.flags |= 0x100;
            } else {
                g_abd8++;
            }
            fn_2279_025b(&ent, buf, 20L);
            buf = fn_2037_0002(buf, 20L);
        }
    }
    return 1;
}

void ovr_2ddf_002f(void)
{
    PakEnt far *e;
    unsigned fl;
    PakEnt buf;
    int i;
    int warn = 0;

    if (g_2aa7 == 0) ovr_2ddf_0020(0);
    if (g_ad46 == 0) return;
    for (e = fn_1981_02c0(i = 0, &buf); e->name != 0 && strlen(fn_1981_0365(e->name)) != 0;
         i++, e = fn_1981_02c0(i, &buf)) {
        if (e->flags & 0x200) {
            if (fn_203b_03b4(0x42) + fn_203b_03b4(0x82) > 0 && !warn) warn = 1;
            fl = e->flags;
            e->flags |= 0x400;
            e->flags &= ~0x800;
            fn_1981_031f(i, &buf);
            fn_1809_058d(fn_1809_0000(fn_1981_0365(e->name), 1));
            e = fn_1981_02c0(i, &buf);
            e->flags &= ~0xc00;
            e->flags |= fl & 0xc00;
            fn_1981_031f(i, &buf);
        }
    }
}

void ovr_2ddf_0034(void)
{
    fn_2148_002c(g_ae59[0] - 'A');
}

int ovr_2ddf_0025(char far *path)
{
    char far *p;

    strcpy(g_aefb, _argv[0]);
    p = strrchr(g_aefb, '\\');
    if (p == 0) g_aefb[0] = 0;
    else *p = 0;
    p = fn_2253_000f(g_1dbf);
    if (p != 0) {
        strcpy(g_aeaa, p + 3);
    } else {
        if (path != 0 && *path != 0) g_ae57 = fn_22de_02a4();
        else g_ae57 = 0;
        if (g_ae57) {
            strcpy(g_aeaa, g_1dc3);
            strcat(g_aeaa, path);
            g_aeaa[0] = g_ae57 + 'A';
        } else {
            strcpy(g_aeaa, g_aefb);
        }
    }
    getcwd(g_ae59, 80);
    strupr(g_ae59);
    strupr(g_aeaa);
    strupr(g_aefb);
    if (chdir(g_aeaa)) return 0;
    if (chdir(g_ae59)) return 0;
    return 1;
}

int ovr_2ddf_002a(char c)
{
    int old;

    g_ae4d = 0;
    old = g_2aa6;
    g_2aa6 = c;
    return old;
}

int ovr_2ddf_003e(char far * far *a, char far * far *b)
{
    return strcmp(*a, *b);
}

void ovr_2ddf_0039(void)
{
    for (g_abda = 0, strupr(f_27fc_0000[g_abda].name); strstr(f_27fc_0000[g_abda].name, g_1dc6) != 0; g_abda++)
        strupr(f_27fc_0000[g_abda].name);
    for (g_abd8 = 0; f_27fc_0000[g_abd8 + g_abda].name != 0 && *f_27fc_0000[g_abd8 + g_abda].name != 0; g_abd8++)
        strupr(f_27fc_0000[g_abd8 + g_abda].name);
    if (g_abd8)
        qsort(&f_27fc_0000[g_abda], g_abd8, 20, (int (*)(const void *, const void *))ovr_2ddf_003e);
}
