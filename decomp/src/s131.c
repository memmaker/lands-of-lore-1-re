/* s131: WW library -- fatal exits (restore video mode, print a message, exit(5)) */
#include <stdio.h>
#include <stdlib.h>
extern char far *g_159c, far *g_15a0;
void far fn_2347_0034(int mode);
void far fn_2093_000e(char far *msg);
void far fn_2169_06e9(void);
void far fn_2309_000c(void);

void fn_2274_0007(void)
{
    fn_2347_0034(9);
    fn_2093_000e(g_159c);
    fn_2169_06e9();
    fn_2309_000c();
    exit(5);
}

void fn_2274_0036(void)
{
    printf(g_15a0);
    fn_2309_000c();
    exit(5);
}
