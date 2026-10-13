/* o2dd0: select sound driver table entry i and initialise its state */
#include <string.h>
#include <mem.h>

struct drv { char far *name; void far *p; int flag; int x; };
extern struct drv g_1a78[];
extern char g_28b8[];
extern char far *g_28ba;
extern char g_28fa[];
extern int g_2962;
extern int g_2920;
extern int g_2922;
extern void far *g_2924;
int ovr_2db6_0025(char far *name, char far *a, void far *b, int c);
int fn_1b79_02a7(int v);
void far *fn_203b_0007(long v, int n);

int ovr_2dd0_0020(int i)
{
    char far *name;
    int x;
    int t;
    int f;

    x = g_1a78[i].x;
    f = g_1a78[i].flag;
    name = g_1a78[i].name;
    if (name != 0) {
        if (stricmp(name, g_28ba) == 0) {
            memcpy(g_28fa, g_28b8, 0x26);
        } else if (ovr_2db6_0025(name, g_28fa, g_1a78[i].p, f) == 0) {
            i = 0;
            goto done;
        }
        if (i == 7) {
            _DX = g_2962;
            asm {
                add dx,4
                mov al,0x83
                out dx,al
                inc dx
                mov al,0xb
                out dx,al
            }
        }
        g_2920 = x;
        if (f == 0) {
            t = fn_1b79_02a7(*(int *)g_28fa);
            g_2924 = fn_203b_0007((long)t, 0x10);
            g_2922 = -1;
        }
    }
done:
    return i;
}
