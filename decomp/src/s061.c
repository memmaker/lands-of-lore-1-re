/* s061: WW library -- set the current page, return the old one */
extern int g_3649;

int fn_1e74_000f(int page)
{
    int old;
    old = g_3649;
    g_3649 = page;
    return old;
}
