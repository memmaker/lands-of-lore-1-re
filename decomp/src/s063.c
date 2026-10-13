/* s063: WW library -- define a text window (x, y, w, h) */
struct Win { int x, y, w, h; char pad[8]; };
extern struct Win g_1f3b[];
extern int g_3715;
void far fn_14b3_0122(int win);

void fn_1e9a_000b(int win, int x, int y, int w, int h)
{
    g_1f3b[win].x = x;
    g_1f3b[win].y = y;
    g_1f3b[win].w = w;
    g_1f3b[win].h = h;
    if (g_3715 == win)
        fn_14b3_0122(win);
}
