/* o2d96: single-line text input with blinking cursor */

extern int g_ad8b;
extern int g_ad8d;
extern int g_ad8f;
extern int g_ad91;
extern int g_3711;
extern int g_3713;
extern unsigned long g_14c4;
extern int g_14c8;
extern unsigned long g_384c;
void fn_2169_04ba(int m);
void fn_2169_04f7(int m);
int fn_2169_0482(int key);
int fn_1e74_000f(int page);
int fn_14b3_0122(int font);
void fn_14b3_0215(void);
int fn_1e64_0007(char c);
void fn_1ebc_00e7(void);
void fn_1ebc_00fe(void);
void fn_0845_07b3(char far *s, int x, int y, int fg, int bg, int f);
int fn_163d_0039(void far *p);
void fn_1e59_001d(int x1, int y1, int x2, int y2, int c);

void ovr_2d96_0025(int x, int on);

int ovr_2d96_0020(char far *buf, int maxlen, int font, void far *in, void (far *cb)(void), int flags)
{
    int key;
    char far *p;
    int oldfont;
    int maxw;
    int cw;
    int result;
    int done;
    int oldpage;
    int x0;
    int w;
    int n;

    result = 0;
    fn_2169_04ba(2);
    fn_2169_04f7(0x2000);
    oldpage = fn_1e74_000f(0);
    oldfont = fn_14b3_0122(font);
    x0 = g_ad8d << 3;
    maxw = (g_ad8f << 3) - (fn_1e64_0007('W') + 1);
    p = buf;
    n = w = 0;
    while (w < maxw && *p) {
        w += fn_1e64_0007(*p++);
        n++;
    }
    *p = 0;
    if (flags & 1) flags |= 4;
    fn_1ebc_00e7();
    if (flags & 4) fn_14b3_0215();
    fn_0845_07b3(buf, x0, g_ad8b + 2, g_3713, g_3711, 0);
    ovr_2d96_0025(x0 + w, 1);
    fn_1ebc_00fe();
    done = 0;
    while (!done) {
        if (cb) cb();
        key = fn_163d_0039(in);
        ovr_2d96_0025(x0 + w, 1);
        if (key & 0x8000) {
            done = 1;
            result = key;
            continue;
        }
        switch (key) {
        case 0:
            break;
        case 0x6e:
            done = 1;
            *buf = 0;
            result = 0x6e;
            break;
        case 0x2b:
        case 0x6c:
            done = 1;
            result = 0x2b;
            break;
        case 0x0f:
            if (n == 0) break;
            p--;
            ovr_2d96_0025(x0 + w, 0);
            w -= fn_1e64_0007(*p);
            ovr_2d96_0025(x0 + w, 1);
            *p = 0;
            n--;
            break;
        default:
            key = fn_2169_0482(key) & 0xff;
            if (key == ' ' && n == 0) break;
            if (key < 0x20) break;
            if (key > 0x7e) break;
            cw = fn_1e64_0007(key);
            if (w + cw < maxw && n < maxlen) {
                p[0] = key;
                p[1] = 0;
                n++;
                fn_1ebc_00e7();
                ovr_2d96_0025(x0 + w, 0);
                fn_0845_07b3(p, x0 + w, g_ad8b + 2, g_3713, g_3711, 0);
                fn_1ebc_00fe();
                w += cw;
                ovr_2d96_0025(x0 + w, 1);
                *++p = 0;
            }
            break;
        }
    }
    fn_2169_04f7(2);
    fn_2169_04ba(0x2000);
    fn_14b3_0122(oldfont);
    fn_1e74_000f(oldpage);
    return result;
}

void ovr_2d96_0025(int x, int on)
{
    if (!on) {
        g_14c4 = 0;
        g_14c8 = 1;
    }
    if (g_14c4 <= g_384c) {
        g_14c8 = !g_14c8;
        if (on) g_14c4 = g_384c + 20;
        fn_1ebc_00e7();
        fn_1e59_001d(x, g_ad8b, x + fn_1e64_0007('W'), g_ad8b + g_ad91 - 1, g_14c8 ? g_3713 : g_3711);
        fn_1ebc_00fe();
    }
}
