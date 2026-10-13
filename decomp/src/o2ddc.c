/* o2ddc: check table entry g_1d48[i] through ovr_2db6_0025 */

extern void far *g_1d48[];
extern int g_292a;
extern char g_1db5[];
int ovr_2db6_0025(void far *p, int far *a, char far *b, int c);

int ovr_2ddc_0020(int i)
{
    void far *p;

    p = g_1d48[i];
    if (p != 0) {
        if (ovr_2db6_0025(p, &g_292a, g_1db5, 0) == 0) i = 0;
    }
    return i;
}
