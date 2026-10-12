/* o2dc3: release the current sound channel buffer and clear the channel block */
#include <mem.h>

extern int g_2a6f;
extern void far *g_2a71;
extern char g_2a37[];
void fn_203b_0203(void far *p);

void ovr_2dc3_0020(void)
{
    switch (g_2a6f) {
    case 1:
        if (g_2a71 != 0) fn_203b_0203(g_2a71);
        break;
    }
    memset(g_2a37, 0, 0x48);
}
