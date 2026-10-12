/* s030: music driver front end (ADL/ALFX driver calls through the driver struct g_28fa) */
#pragma inline
#include <mem.h>

struct Drv {                    /* g_28fa, defined in s026 */
    int h;                      /* +00 driver handle, -1 = use the far entry */
    char far *name;             /* +02 */
    char pad06[8];
    void far *entry;  /* +0e */
    char pad12[4];
    long data;                  /* +16 */
    char pad1a[4];
    int far *tab;               /* +1e */
    char pad22[6];
    int voice;                  /* +28 */
    long w2a;                   /* +2a */
};

extern struct Drv g_28fa;
extern int g_35e4, g_28de;
extern int g_abd4, g_abd6;

int fn_1b79_02ef(int h, int v);
void fn_1b79_02e3(int h, int v);
void fn_1b79_02b1(int h, int v);
int fn_1b79_02ac(int h, long d, int n, long a, long b);
void fn_1b79_02dd(int h, int v);
void fn_1b79_0301(int h, int v, int a, int b);
void fn_2120_0007(int n);

void fn_178d_00a4(int n, int vol);
void fn_178d_01ef(struct Drv far *s, int n, int vol);

unsigned g_2a9a = 0xffff;

int fn_178d_0007(void)
{
    int r;
    void far *fp;

    r = 0;
    if (g_28fa.h == -1 && g_28fa.entry != 0) {
        fp = g_28fa.entry;
        asm mov bx, 0xb;
        asm pushf;
        asm call dword ptr fp;
        asm mov r, ax;
    }
    return r;
}

int fn_178d_0038(void)
{
    int r;
    void far *fp;

    r = 0;
    if (g_28fa.h != -1) {
        if (g_28fa.voice != -1)
            return fn_1b79_02ef(g_28fa.h, g_28fa.voice) == 1;
    } else if (g_28fa.entry != 0) {
        fp = g_28fa.entry;
        asm mov ax, 0;
        asm mov bx, 7;
        asm pushf;
        asm call dword ptr fp;
        asm mov r, ax;
    }
    return r;
}

void fn_178d_0091(int n)
{
    fn_178d_00a4(n, 0xff);
}

void fn_178d_00a4(int n, int vol)
{
    if (n < 0 || n > 0xfa || !g_35e4)
        return;
    if (g_28fa.h != -1) {
        if (g_28fa.voice != -1) {
            fn_1b79_02e3(g_28fa.h, g_28fa.voice);
            fn_1b79_02b1(g_28fa.h, g_28fa.voice);
            g_28fa.voice = -1;
        }
        g_28fa.voice = fn_1b79_02ac(g_28fa.h, g_28fa.data, n, g_28fa.w2a, 0);
        fn_1b79_02dd(g_28fa.h, g_28fa.voice);
        fn_1b79_0301(g_28fa.h, g_28fa.voice, (vol & 0xff) * 0x5a >> 8, 0);
    } else if (g_28fa.entry != 0) {
        fn_178d_01ef(&g_28fa, n, vol);
    }
}

void fn_178d_015e(void)
{
    if (g_28fa.h != -1) {
        if (g_28fa.voice != -1) {
            fn_1b79_02e3(g_28fa.h, g_28fa.voice);
            fn_1b79_02b1(g_28fa.h, g_28fa.voice);
            g_28fa.voice = -1;
        }
    } else if (g_28fa.entry != 0) {
        fn_178d_01ef(&g_28fa, 0, 0);
    }
}

void fn_178d_01b0(void)
{
    if (g_28fa.h != -1) {
        if (g_28fa.voice != -1)
            fn_1b79_0301(g_28fa.h, g_28fa.voice, 0, 0x7d0);
    } else if (g_28fa.entry != 0) {
        fn_178d_01ef(&g_28fa, 1, 0);
    }
}

void fn_178d_01ef(struct Drv far *s, volatile int n, int vol)
{
    int r;
    void far *fp;
    int stat;

    fp = s->entry;
    if (n == -1 || !fp || !s->data || (n = s->tab[n]) == -1)
        return;
    if (memcmp(s->name, "ALFX", 4) == 0) {
        n &= 0xff;
        do {
            asm xor ax, ax;
            asm mov bx, 0x10;
            asm pushf;
            asm call dword ptr fp;
            asm mov stat, ax;
        } while (stat & 8);
        if (g_2a9a != 0xffff) {
            asm mov cx, g_abd6;
            asm mov dx, 1;
            asm mov ax, g_2a9a;
            asm mov bx, 10;
            asm pushf;
            asm call dword ptr fp;
            asm mov cx, g_abd4;
            asm mov dx, 3;
            asm mov ax, g_2a9a;
            asm mov bx, 10;
            asm pushf;
            asm call dword ptr fp;
            g_2a9a = -1;
        }
        asm mov dx, 0;
        asm mov ax, n;
        asm mov bx, 9;
        asm pushf;
        asm call dword ptr fp;
        asm mov r, ax;
        g_2a9a = -1;
        if (vol != -1 && r != 9) {
            g_2a9a = n;
            asm mov dx, 1;
            asm mov ax, n;
            asm mov bx, 9;
            asm pushf;
            asm call dword ptr fp;
            asm mov g_abd6, ax;
            asm mov dx, 3;
            asm mov ax, n;
            asm mov bx, 9;
            asm pushf;
            asm call dword ptr fp;
            asm mov g_abd4, ax;
            asm mov ax, g_abd4;
            asm neg ax;
            asm add ax, 3fh;
            asm mul byte ptr vol;
            asm xchg ah, al;
            asm xor ah, ah;
            asm neg ax;
            asm add ax, 3fh;
            asm mov cx, ax;
            asm mov dx, 3;
            asm mov ax, n;
            asm mov bx, 10;
            asm pushf;
            asm call dword ptr fp;
            asm mov ax, g_abd6;
            asm mov dx, vol;
            asm mul dl;
            asm mov cl, ah;
            asm xor ch, ch;
            asm mov dx, 1;
            asm mov ax, n;
            asm mov bx, 10;
            asm pushf;
            asm call dword ptr fp;
        }
        asm mov ax, n;
        asm mov bx, 6;
        asm pushf;
        asm call dword ptr fp;
        if (n == 0)
            fn_2120_0007(5);
    } else {
        if (g_28de == 1) {
            if (n < 0) {
                asm mov ax, 4;
                asm mov bx, 11h;
                asm pushf;
                asm call dword ptr fp;
            } else {
                asm mov ax, 4;
                asm mov bx, 10h;
                asm pushf;
                asm call dword ptr fp;
            }
        }
        n = n < 0 ? -n : n;
        asm mov ax, n;
        asm mov bx, 6;
        asm pushf;
        asm call dword ptr fp;
    }
}
