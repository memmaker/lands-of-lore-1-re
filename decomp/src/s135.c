/* s135: WW library -- CD audio through MSCDEX (int 2Fh 1510h device requests on drive g_3828) */
#include <dos.h>
extern unsigned char g_3828;
extern char g_379c, g_37b6, g_37b7, g_37bd, g_37d7, g_37e2, g_37fc, g_3805, g_381b;
extern unsigned char g_37fd, g_37fe, g_37ff, g_3800, g_3801, g_3802, g_3803, g_3804;
extern unsigned g_37aa, g_37ac, g_37cb, g_37cd, g_37c0, g_37f0, g_37f2;
extern long g_37b8, g_3813, g_3817;

void fn_22de_028c(void);

#define MSCDEX(req) { _CX = g_3828; _ES = _DS; _BX = (unsigned)&req; _AX = 0x1510; geninterrupt(0x2f); }

/* Red Book M:S:F (packed 00MMSSFF) -> frame number */
long fn_22de_0005(unsigned long msf)
{
    return ((msf >> 16) & 0xff) * 4500 + ((msf >> 8) & 0xff) * 75 + (msf & 0xff);
}

unsigned long fn_22de_004a(unsigned char m, unsigned char s, unsigned char f)
{
    return ((unsigned long)m << 16) + ((unsigned long)s << 8) + (unsigned long)f;
}

/* play the prepared range; mode 0/1/other picks the audio channel mapping */
void fn_22de_0073(char mode)
{
    g_37fe = g_3800 = g_3802 = g_3804 = 0xff;
    g_37f2 = _DS;
    g_37f0 = (unsigned)&g_37fc;
    if (mode == 0)
        g_3800 = 0;
    else if (mode == 1)
        g_37fe = 0;
    else {
        g_37fd = 0;
        g_37ff = 1;
        g_3801 = 2;
        g_3803 = 3;
    }
    MSCDEX(g_37e2)
}

/* play audio track `track` (to the start of the next one) */
void fn_22de_00d1(char track)
{
    fn_22de_028c();
    g_37b7 = track;
    g_37ac = _DS;
    g_37aa = (unsigned)&g_37b6;
    MSCDEX(g_379c)
    g_3813 = g_37b8;
    g_37b7++;
    g_37ac = _DS;
    g_37aa = (unsigned)&g_37b6;
    MSCDEX(g_379c)
    g_3817 = fn_22de_0005(g_37b8) - fn_22de_0005(g_3813) - 1;
    MSCDEX(g_3805)
    fn_22de_0073(2);
}

void fn_22de_01e8(char m1, char s1, char f1, char m2, char s2, char f2, char mode);

/* play from sector start (MM SS as hi/lo byte, +2 s lead-in) for len seconds */
void fn_22de_016f(unsigned start, unsigned len)
{
    unsigned m1, s1, f1, m2, s2, f2;
    if (len == 0)
        return;
    m2 = m1 = (start >> 8) + 1;
    s2 = s1 = (start & 0xff) + 44;
    f1 = f2 = 0;
    while (len > 59) {
        m2++;
        len -= 60;
    }
    s2 += len;
    if (s2 > 59) {
        m2++;
        s2 -= 60;
    }
    fn_22de_01e8(m1, s1, f1, m2, s2, f2, 2);
}

void fn_22de_01e8(char m1, char s1, char f1, char m2, char s2, char f2, char mode)
{
    g_3813 = fn_22de_004a(m1, s1, f1);
    g_3817 = fn_22de_0005(fn_22de_004a(m2, s2, f2)) - fn_22de_0005(g_3813) - 1;
    MSCDEX(g_3805)
    fn_22de_0073(mode);
}

/* busy bit of the device status */
int fn_22de_0262(void)
{
    g_37cd = _DS;
    g_37cb = (unsigned)&g_37d7;
    MSCDEX(g_37bd)
    return g_37c0 & 0x200;
}

/* stop */
void fn_22de_028c(void)
{
    MSCDEX(g_381b)
}

/* first CD-ROM drive letter (int 2Fh 150Dh) */
int fn_22de_02a4(void)
{
    _ES = _DS;
    _BX = (unsigned)&g_3828;
    _AX = 0x150d;
    geninterrupt(0x2f);
    return g_3828;
}
