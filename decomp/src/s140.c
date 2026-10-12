/* s140: WW library -- countdown timer slots 1..14: allocate, free, query, set direction */
extern unsigned g_384a, g_3848;

int fn_231c_0008(int t)
{
    int old;
    if (t < 1 || t > 14)
        return 0;
    old = (g_384a & (2 << t)) ? 1 : 0;
    g_384a |= 2 << t;
    return old;
}

int fn_231c_0048(int t)
{
    int old;
    if (t < 1 || t > 14)
        return 0;
    old = (g_384a & (2 << t)) ? 1 : 0;
    g_384a &= ~(2 << t);
    return old;
}

int fn_231c_008a(int t)
{
    if (t < 1 || t > 14)
        return 0;
    return (g_384a & (2 << t)) ? 1 : 0;
}

int fn_231c_00b6(int t, int down)
{
    int old;
    if (t < 1 || t > 14)
        return 0;
    old = (g_3848 & (2 << t)) ? 1 : 0;
    if (down)
        g_3848 |= 2 << t;
    else
        g_3848 &= ~(2 << t);
    return old;
}
