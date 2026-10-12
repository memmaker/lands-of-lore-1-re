/* o2e1e: 10-byte checksummed record (8 data bytes + byte 9 checksum, XOR 0xa5 obfuscation): save / load */
/* FLAGS: -ml -3 -Y */
#include <io.h>
#include <fcntl.h>

int fn_1809_0000(char far *name, int mode);
long fn_1809_0bde(int fh, void far *buf, long n);
void fn_1809_058d(int fh);
void ovr_2e1e_002a(unsigned char far *p);
int ovr_2e1e_002f(unsigned char far *p);

int ovr_2e1e_0020(char far *name, unsigned char far *buf)
{
    int ok;
    int fh;

    ovr_2e1e_002a(buf);
    fh = fn_1809_0000(name, 2);
    ok = fn_1809_0bde(fh, buf, 10) == 10 ? 1 : 0;
    fn_1809_058d(fh);
    return ok;
}

int ovr_2e1e_0025(char far *name, unsigned char far *buf)
{
    int n;
    int fh;

    fh = open(name, O_RDONLY | O_BINARY, 0x100);
    if (fh == -1) return 0;
    n = read(fh, buf, 10);
    close(fh);
    if (n != 10) return 0;
    return ovr_2e1e_002f(buf);
}

void ovr_2e1e_002a(unsigned char far *p)
{
    char i;
    unsigned char sum;
    unsigned char far *q;

    sum = 0;
    q = p;
    i = 8;
    while (i--) {
        sum += *q;
        *q += i;
        *q ^= 0xa5;
        q++;
    }
    p[9] = sum ^ 0xa5;
}

int ovr_2e1e_002f(unsigned char far *p)
{
    char i;
    unsigned char far *q;
    unsigned char sum;

    sum = 0;
    q = p;
    i = 8;
    while (i--) {
        *q ^= 0xa5;
        *q -= i;
        sum += *q;
        q++;
    }
    if (p[9] == (sum ^ 0xa5)) return 1;
    else return 0;
}
