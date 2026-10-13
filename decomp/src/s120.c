/* s120: WW library -- busy-wait delay in timer ticks; driver wrapper */
extern unsigned long g_384c;   /* timer tick counter */
extern int g_ad97;
void far fn_2345_0009(int h);

void far fn_2120_0007(register int ticks)
{
    unsigned long until;
    while (ticks--) {
        until = g_384c + 1;
        while (until >= g_384c)
            ;
    }
}

void far fn_2120_0032(void)
{
    fn_2345_0009(g_ad97);
}
