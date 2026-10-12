/* o2e04: fatal error on an unexpected character code */
#include <stdio.h>
#include <stdlib.h>

extern char g_2ed8[];
extern char g_2eda[];
void fn_2309_000c(void);

void ovr_2e04_0020(int c)
{
    char far *s;

    if (c < 0x80 || c == 0xa0) return;
    s = g_2ed8;
    fn_2309_000c();
    printf(g_2eda, c, s);
    exit(1);
}
