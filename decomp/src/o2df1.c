/* o2df1: load a file whose first word is its length; accept it only when bytes 2..3 are 00 05 */
/* FLAGS: -ml -3 -Y */

int fn_1981_000a(char far *name);
int fn_1809_0000(char far *name, int mode);
long fn_1809_084d(int fh, void far *buf, long n);
void fn_1809_058d(int fh);
char far *fn_203b_0007(long size, int flags);

char far *ovr_2df1_0020(char far *name)
{
    char ok;
    char far *p;
    unsigned len;
    int fh;

    p = 0;
    if (fn_1981_000a(name)) {
        fh = fn_1809_0000(name, 1);
        if (fn_1809_084d(fh, &len, 2) != 2) return 0;
        p = fn_203b_0007(len, 0x10);
        *(unsigned far *)p = len;
        fn_1809_084d(fh, p + 2, len - 2);
        fn_1809_058d(fh);
    } else {
        return 0;
    }
    ok = 0;
    if (p[2] == 0 && p[3] == 5) ok = 1;
    if (!ok) return 0;
    return p;
}
