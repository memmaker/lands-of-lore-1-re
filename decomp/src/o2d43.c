/* o2d43: text menus (g_20dc[]): draw (ovr_2d43_0020), keyboard/mouse selection (ovr_2d43_0025), point in rect.
   mask/shift hide entries: bit (shift + i) of mask set = entry i shown. */
#include <ctype.h>

struct Menu { int x, y, w, n, sel, c1, c2, c3; };   /* 16 bytes, g_20dc[] */

extern struct Menu g_20dc[];
extern int g_ad8b, g_ad8d, g_4b4e, g_4b50, g_0f88, g_2f0c, g_2f0e, g_2f10, g_2f12;
extern unsigned g_ad8f;
extern char g_3628, g_3629;
extern unsigned char g_2f43;
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_0845_07b3(char far *s, int x, int y, int fg, int bg, int f);
void fn_2120_0007(int n);
int fn_2169_060c(void);
int fn_2169_0790(void);
int fn_2169_0482(int key);
void fn_2169_062e(void);
void ovr_2d43_0020(int m, char far * far *items, unsigned long mask, int shift, int step);
int ovr_2d43_0025(int m, char far * far *items, long unused, unsigned long mask, int shift);

/* index of the n-th shown entry */
static int fn_2d43_0000(int n, unsigned long mask, int shift)
{
    int i;

    if (mask == 0xffffffffUL) return n;
    for (i = 0; n != 0; i++)
        if (mask & (1UL << (i + shift))) n--;
    while (!(mask & (1UL << (i + shift)))) i++;
    return i;
}

/* flash an entry three times */
static void fn_2d43_004a(char far *s, int x, int y, int c1, int c2, int bg)
{
    int i;

    for (i = 0; i < 3; i++) {
        fn_1ebc_00e7();
        fn_0845_07b3(s, x, y, c2, bg, 5);
        fn_2120_0007(2);
        fn_0845_07b3(s, x, y, c1, bg, 5);
        fn_1ebc_00fe();
        fn_2120_0007(2);
    }
}

int ovr_2d43_002a(int x, int y, int x1, int y1, int x2, int y2)
{
    return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}

void ovr_2d43_0020(int m, char far * far *items, unsigned long mask, int shift, int step)
{
    struct Menu far *mn;
    int y0;
    int x0;
    int sel;
    int cnt;
    int y;
    int i, k;

    mn = &g_20dc[m];
    y0 = g_ad8b + mn->y;
    x0 = (g_ad8d + (g_ad8f >> 1)) << 3;
    sel = fn_2d43_0000(mn->sel, mask, shift);
    cnt = mn->n;
    fn_1ebc_00e7();
    for (i = 0; i < cnt; i++) {
        k = fn_2d43_0000(i, mask, shift);
        y = y0 + i * g_3629 + i * step;
        fn_0845_07b3(items[k], x0, y, ((int far *)mn)[k == sel && (g_0f88 != 0 || g_2f43 != 0) ? 6 : 5], 0, 5);
    }
    g_4b4e = step;
    fn_1ebc_00fe();
    fn_2169_062e();
}

int ovr_2d43_0025(int m, char far * far *items, long unused, unsigned long mask, int shift)
{
    int last;
    int result;
    int key;
    int y0;
    int x0;
    int x1;
    int x2;
    int y2;
    int my;
    int lineh;
    int half;
    int c1;
    int c2;
    int old;
    struct Menu far *mn;
    register int cur;
    register int y1;
    int y;

    mn = &g_20dc[m];
    last = mn->n - 1;
    cur = old = mn->sel % (last + 1);
    result = -1;
    lineh = g_3629 + g_4b4e;
    half = g_4b4e >> 1;
    y0 = g_ad8b + mn->y;
    x0 = (g_ad8d + (g_ad8f >> 1)) << 3;
    c1 = mn->c1;
    c2 = mn->c2;
    key = 0;
    g_4b50 = 0;
    if (fn_2169_060c()) key = fn_2169_0790() & 0x8ff;
    x1 = (g_ad8d << 3) + mn->x * g_3628;
    y1 = g_ad8b + mn->y - half;
    x2 = x1 + mn->w * g_3628 - 1;
    y2 = y1 + mn->n * lineh - 1;
    if (!g_2f43) {
        my = g_2f0e;
        if (ovr_2d43_002a(g_2f0c, my, x1, y1, x2, y2) && g_0f88) cur = (my - y1) / lineh;
    }
    switch (key) {
    case 0x60:
        cur--;
        if (cur < 0) cur = last;
        break;
    case 0x62:
        cur++;
        if (cur > last) cur = 0;
        break;
    case 0x5b:
    case 0x65:
        cur = 0;
        break;
    case 0x5d:
    case 0x67:
        cur = last;
        break;
    case 0x41:
    case 0x42:
        if (ovr_2d43_002a(g_2f10, g_2f12, x1, y1, x2, y2)) {
            cur = (g_2f12 - y1) / lineh;
        } else {
            g_4b50 = key;
            break;
        }
    case 0x2b:
    case 0x3d:
    case 0x61:
        result = cur;
        break;
    default:
        for (y1 = 0; y1 < mn->n; y1++) {
            if (toupper(*items[fn_2d43_0000(y1, mask, shift)]) == toupper(fn_2169_0482(key & 0xff))) {
                cur = result = y1;
                break;
            }
        }
        g_4b50 = key;
        break;
    }
    if (cur != old) {
        fn_1ebc_00e7();
        y1 = fn_2d43_0000(old, mask, shift);
        y = y0 + old * lineh;
        fn_0845_07b3(items[y1], x0, y, c1, 0, 5);
        y1 = fn_2d43_0000(cur, mask, shift);
        y = y0 + cur * lineh;
        fn_0845_07b3(items[y1], x0, y, c2, 0, 5);
        fn_1ebc_00fe();
    }
    if (result != -1) {
        y1 = fn_2d43_0000(result, mask, shift);
        fn_1ebc_00e7();
        y = y0 + cur * lineh;
        fn_2d43_004a(items[y1], x0, y, c1, c2, 0);
        fn_1ebc_00fe();
        result = y1;
    }
    mn->sel = cur;
    return result;
}
