/* o2dd6: load digital sound driver i (table g_1be0) into slot g_28b8, allocate its 4 sample buffers */
#include <string.h>
#include <mem.h>

struct DrvEnt { char far *name; char far *arg; int b; int a; };
struct Buf { int h; void far *p; };
extern struct DrvEnt g_1be0[];
extern int g_28b8, g_28fa, g_3747, g_2962, g_28e0, g_28de;
extern char far *g_28fc;
extern struct Buf g_28e2[];
int ovr_2db6_0025(void far *p, int far *a, char far *b, int c);
int fn_1b79_02a7(int h);
void far *fn_203b_0007(long size, int flags);

int ovr_2dd6_0020(int i)
{
    char far *name;
    int b;
    int h;
    int a;
    int j;

    a = g_1be0[i].a;
    b = g_1be0[i].b;
    name = g_1be0[i].name;
    if (name != 0) {
    if (stricmp(name, g_28fc) == 0) {
        memcpy(&g_28b8, &g_28fa, 0x26);
    } else if (ovr_2db6_0025(name, &g_28b8, g_1be0[i].arg, b) == 0) {
        i = 0;
        return i;
    }
    if (i == 7) {
        asm mov dx,g_2962
        asm add dx,4
        asm mov al,83h
        asm out dx,al
        asm inc dx
        asm mov al,0bh
        asm out dx,al
    }
    if (b == 0) {
        h = fn_1b79_02a7(g_28b8);
        for (j = 0; j < 4; j++) {
            g_28e2[j].p = fn_203b_0007((long)h, 0x10);
            g_28e2[j].h = -1;
        }
        g_28e0 = 0;
    }
    if (a != 0) g_28de = 1;
    }
    return i;
}
