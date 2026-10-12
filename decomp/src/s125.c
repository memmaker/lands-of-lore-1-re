/* s125: WW library -- DOS critical error handler: remember the error code and fail the call */
#include <dos.h>
#pragma warn -rvl
extern int g_ae4d;

int far fn_2162_0007(int errval)
{
    g_ae4d = errval;
    hardretn(0);
}

void far fn_2162_001a(void)
{
    harderr(fn_2162_0007);
}
