/* o2e26: queries on the file handle table f_2c12_0000 and the PAK entry table */
/* FLAGS: -ml -3 -Y */

typedef struct PakEnt {        /* 20 bytes */
    char far *name;
    long size;
    void far *data;
    long off;
    unsigned char pak;
    unsigned char refs;
    unsigned flags;
} PakEnt;

typedef struct FileH {         /* 20 bytes */
    int free;
    int fd;
    long pos;
    long start;
    int ent;
    int mode;
    char far *name;
} FileH;

extern FileH far f_2c12_0000[];
int fn_1981_01af(char far *name);
PakEnt far *fn_1981_02c0(int i, PakEnt far *buf);
void fn_1981_031f(int i, PakEnt far *buf);
char far *fn_1981_0365(char far *name);

int ovr_2e26_0025(int h)
{
    if (h >= 0 && h < 20 && (f_2c12_0000[h].free == 0 || f_2c12_0000[h].fd != 0))
        return f_2c12_0000[h].fd;
    return -1;
}

int ovr_2e26_0020(void)
{
    int n, i;

    n = 0;
    for (i = 0; i < 20; i++)
        if (f_2c12_0000[i].free != 0) n++;
    return n;
}

int ovr_2e26_002a(char far *name)
{
    PakEnt far *e;
    PakEnt buf;
    int i;

    i = fn_1981_01af(name);
    if (i != -1) {
        e = fn_1981_02c0(i, &buf);
        if (e->flags & 0x1000) {
            e = fn_1981_02c0(e->pak, &buf);
            return ovr_2e26_002a(fn_1981_0365(e->name));
        }
        return e->pak;
    }
    return i;
}

int ovr_2e26_0034(char far *name, int flags)
{
    PakEnt far *e;
    PakEnt buf;
    int i;

    i = fn_1981_01af(name);
    if (i != -1) {
        e = fn_1981_02c0(i, &buf);
        e->flags = flags;
        fn_1981_031f(i, &buf);
        return 1;
    }
    return 0;
}

int ovr_2e26_002f(char far *name)
{
    PakEnt far *e;
    PakEnt buf;
    int i;

    i = fn_1981_01af(name);
    if (i != -1) {
        e = fn_1981_02c0(i, &buf);
        return e->flags;
    }
    return 0;
}
