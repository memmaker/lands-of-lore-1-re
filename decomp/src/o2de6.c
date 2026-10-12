/* o2de6: sample fn_2345_0000 for 15 ticks, store the majority result in g_ad97 */

extern long g_3850;
extern int g_ad97;
int fn_2345_0000(void);

void ovr_2de6_0020(void)
{
    int yes, no;

    yes = no = 0;
    g_3850 = 15;
    do {
        if (fn_2345_0000()) yes++;
        else no++;
    } while (g_3850 != 0);
    g_ad97 = yes > no ? 1 : 0;
}
