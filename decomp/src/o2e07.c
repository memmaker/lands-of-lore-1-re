/* o2e07: file offsets inside the resource pack g_af88 (opened lazily through o2e0e) */
/* FLAGS: -ml -3 -Y */

struct PakEnt { long off; char rest[10]; };
extern struct PakEnt g_af72[];
extern unsigned g_af88;
extern long g_af8e;
int fn_2365_063f(char far *name);
unsigned long fn_2365_0602(char far *name);
void fn_2365_0afc(void far *buf, long off);
void ovr_2e0e_0020(unsigned h);
void ovr_2e0e_0025(unsigned h);
long ovr_2e0e_002a(unsigned long h);

long ovr_2e07_0025(char far *name)
{
    long buf[4];

    if (fn_2365_063f(name) == 0) return 0;
    fn_2365_0afc(buf, fn_2365_0602(name) - 16);
    return buf[0];
}

long ovr_2e07_002a(int i)
{
    return g_af72[i].off;
}

long ovr_2e07_0020(char far *name)
{
    if (g_af8e == 0) {
        ovr_2e0e_0020(g_af88);
        g_af8e = ovr_2e0e_002a(g_af88);
        ovr_2e0e_0020(g_af88);
        if (g_af8e == 0) return 0;
    }
    return g_af8e + fn_2365_0602(name);
}

int ovr_2e07_002f(void)
{
    if (g_af8e != 0) {
        ovr_2e0e_0025(g_af88);
        g_af8e = 0;
        return 1;
    }
    return 0;
}
