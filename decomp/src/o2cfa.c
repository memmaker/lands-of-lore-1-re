/* o2cfa: draw beveled GUI boxes (frame styles g_084e, window table g_1f3b) */

struct style { int fill; int light; int dark; int corner; };
struct win { int x; int y; int w; int h; char pad[8]; };
struct inner { int style; int border; };
extern struct style g_084e[];
extern struct win g_1f3b[];
extern struct inner g_087e[];
extern int g_3649;
void fn_1e59_001d(int x1, int y1, int x2, int y2, int c);
void fn_1e30_0209(int x1, int y1, int x2, int y2, int c);
void fn_1f20_0000(int x, int y, int c);
void fn_1ebc_0111(int x1, int y1, int x2, int y2);
void fn_1ebc_01ec(void);

void ovr_2cfa_0020(int x, int y, int w, int h, int style, int fill)
{
    struct style far *b;

    w--;
    h--;
    b = &g_084e[style];
    if (fill) fn_1e59_001d(x, y, x + w, y + h, b->fill);
    fn_1e30_0209(x, y + h, x + w, y + h, b->light);
    fn_1e30_0209(x + w, y, x + w, y + h, b->light);
    fn_1e30_0209(x, y, x + w, y, b->dark);
    fn_1e30_0209(x, y, x, y + h, b->dark);
    fn_1f20_0000(x, y + h, b->corner);
    fn_1f20_0000(x + w, y, b->corner);
}

void ovr_2cfa_0025(int n, int k, int hi)
{
    int w;
    int h;
    int s;
    int st;
    int x;
    int y;
    int bd;

    x = g_1f3b[n].x << 3;
    y = g_1f3b[n].y;
    w = g_1f3b[n].w << 3;
    h = g_1f3b[n].h;
    s = hi ? 2 : 0;
    if (g_3649 == 0) fn_1ebc_0111(x, y, x + w, y + h);
    ovr_2cfa_0020(x, y, w, h, s + 1, 1);
    st = g_087e[k].style;
    bd = g_087e[k].border;
    if (bd != 0) ovr_2cfa_0020(x + bd, y + bd, w - bd * 2, h - bd * 2, st + s, 0);
    if (g_3649 == 0) fn_1ebc_01ec();
}
