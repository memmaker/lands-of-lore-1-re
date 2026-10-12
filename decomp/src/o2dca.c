/* o2dca: digital sound buffer setup (timer rate, DMA-safe buffer split) */
#include <dos.h>
#include <mem.h>

struct sbinfo { char pad[8]; int type; char pad2[2]; int blk; char nblk; };
struct dmar { unsigned long start; unsigned long len; unsigned long p2; unsigned long blk; };
extern int g_2992;
extern char g_2994;
extern int g_2990;
extern int g_2a6f;
extern char far *g_2a37[5];
extern unsigned long g_2a4b;
extern unsigned long g_2a4f[5];
extern void far *g_2a71;
extern char far * far *g_2a75;
extern char far *g_2a79;
extern int g_2a7d;
extern struct sbinfo far *g_2952;
int ovr_2db6_002a(void);
int fn_22d7_000a(void);
unsigned long fn_203b_03b4(int t);
void far *fn_203b_0007(unsigned long size, int flags);
char far *fn_2037_0002(void far *p, unsigned long off);

void ovr_2dca_0020(unsigned rate)
{
    g_2992 = 2;
    g_2994 = 0 - (char)(1000000UL / rate);
}

long ovr_2dca_0025(unsigned long size, unsigned long thr)
{
    void far *mem;
    unsigned long lin;
    unsigned long next;
    unsigned long room;
    unsigned long sz2;
    unsigned long need;
    unsigned long alt;
    int n;
    struct dmar r;
    int found;
    register int t;
    register int i;
    unsigned off;

    if (!ovr_2db6_002a()) return 0;
    memset(g_2a37, 0, 0x48);
    t = fn_22d7_000a();
    switch (t) {
    case 1:
    case 3:
        if (fn_203b_03b4(0) < size) return 0;
        g_2a6f = 1;
        mem = fn_203b_0007(size, 0);
        if (mem == 0) return 0;
        g_2952->type = t;
        lin = FP_SEG(mem);
        lin <<= 4;
        lin += FP_OFF(mem);
        break;
    case 2:
    case 4:
    case 5:
    case 6:
        return 0;
    }
    next = (lin & 0xffff0000UL) + 0x10000UL;
    sz2 = size - 0x1158;
    if (sz2 > 0x7e4f) sz2 = 0x7e4f;
    n = sz2 / 0x45b;
    room = next - lin;
    found = 0;
    while (!found) {
        need = n * 0x456;
        if (need <= room) {
            r.start = lin;
            r.len = need;
            r.p2 = r.start + need;
            r.blk = 0x1158;
            found = 1;
        } else if (size - room >= need) {
            alt = (unsigned)(n * 5 + 0x1158);
            r.start = alt > room ? lin + alt : next;
            r.len = need;
            r.p2 = lin;
            r.blk = 0x1158;
            found = 1;
        }
        if (!found) {
            if (n < 3) return 0;
            n--;
        }
    }
    g_2a4b = r.start;
    g_2a37[0] = fn_2037_0002(mem, g_2a4b - lin);
    g_2a4f[0] = r.len;
    if (g_2a4f[0] < thr) g_2990 = 1;
    else g_2990 = 0;
    for (i = 1; i <= 4; i++) {
        g_2a37[i] = fn_2037_0002(mem, r.p2 + (r.blk >> 2) * (i - 1) - lin);
        g_2a4f[i] = r.blk >> 2;
        memset(g_2a37[i], 0x80, (unsigned)g_2a4f[i]);
    }
    g_2a71 = mem;
    g_2a7d = g_2952->nblk = n;
    g_2952->blk = 0x455;
    g_2a79 = fn_2037_0002(g_2a37[4], 0x456L);
    g_2a75 = (char far * far *)fn_2037_0002(g_2a79, (long)n);
    off = 0;
    for (i = 0; i < n; i++) {
        g_2a75[i] = g_2a37[0] + off;
        g_2a79[i] = 0;
        off += 0x456;
    }
    return 1;
}
