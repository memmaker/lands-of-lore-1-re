/* s144: WW library -- set the clip rectangle to a text window (x and w in 8-pixel columns) */
struct Win { int x, y, w, h; int pad[4]; };
extern struct Win g_1f3b[];
void far fn_1ebc_0111(int x1, int y1, int x2, int y2);
void far fn_1ebc_01ec(void);

void fn_234e_0003(int n)
{
    register int i = n;
    int y, w, h;
    register int x;
    x = g_1f3b[i].x << 3;
    y = g_1f3b[i].y;
    w = g_1f3b[i].w << 3;
    h = g_1f3b[i].h;
    fn_1ebc_0111(x, y, x + w - 1, y + h - 1);
}

void fn_234e_0062(void)
{
    fn_1ebc_01ec();
}
