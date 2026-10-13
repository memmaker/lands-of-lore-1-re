/* s124: WW library -- video page segment lookups (g_364b: page segment table) */
#include <dos.h>
extern unsigned g_364b[];

void far *fn_215f_0003(int page)
{
    register int p = page;
    p &= 0xf;
    return MK_FP(g_364b[p | 1], 0);
}

void far *fn_215f_001d(int page)
{
    register int p = page;
    p &= 0xf;
    return MK_FP(g_364b[p & ~1], 0);
}
