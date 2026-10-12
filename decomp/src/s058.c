/* s058: WW library -- character and string pixel widths in the current font */
extern unsigned char far *g_362a;
extern int g_3624;
extern int g_2af4;
char far *far fn_226d_0007(char far *s, int flags);
void far fn_226d_004e(char far *s);

int fn_1e64_0007(unsigned char c)
{
    int w;
    w = g_362a[c] + g_3624;
    return w;
}

int fn_1e64_002b(char far *s)
{
    char far *p;
    int cur, max;
    max = 0;
    if (s == 0)
        return 0;
    g_2af4++;
    p = fn_226d_0007(s, 0);
    cur = 0;
    while (*p) {
        if (*p == '\r') {
            p++;
            max = max > cur ? max : cur;
            cur = 0;
        } else
            cur += fn_1e64_0007(*p++);
    }
    max = max > cur ? max : cur;
    fn_226d_004e(s);
    g_2af4--;
    return max;
}
