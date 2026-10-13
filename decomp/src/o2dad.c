/* o2dad: load the shape file set n (largest of the 5 sizes the buffer) and index its 34 shapes */
#include <string.h>
#include <io.h>
#include <fcntl.h>

extern char far *g_1618[];
extern char g_18a5[], g_18a9[];
extern void far *g_4b8e;
extern unsigned g_4b8c;
extern void far *g_1594[];
void far *fn_203b_0007(long size, int flags);
void far *fn_212a_014c(void far *p, int n);

int ovr_2dad_0020(int n)
{
    unsigned len;
    unsigned max = 0;
    char name[14];
    int i, fd;

    if (g_4b8e == 0) {
        for (i = 0; i < 5; i++) {
            strcpy(name, g_1618[i]);
            strcat(name, g_18a5);
            fd = open(name, 0x8001, 0x100);
            if (fd != -1) {
                len = lseek(fd, 0, 2);
                close(fd);
                if (len > max) max = len;
            }
        }
        if (max != 0) {
            g_4b8e = fn_203b_0007(max, 0);
            g_4b8c = max;
        } else return 0;
    }
    strcpy(name, g_1618[n]);
    strcat(name, g_18a9);
    fd = open(name, 0x8001, 0x100);
    if (fd == -1) return 0;
    len = lseek(fd, 0, 2);
    lseek(fd, 0, 0);
    if (read(fd, g_4b8e, len) != len) {
        close(fd);
        return 0;
    }
    close(fd);
    g_1594[0] = fn_212a_014c(g_4b8e, 1);
    g_1594[1] = fn_212a_014c(g_4b8e, 2);
    g_1594[2] = fn_212a_014c(g_4b8e, 3);
    g_1594[3] = fn_212a_014c(g_4b8e, 4);
    g_1594[4] = fn_212a_014c(g_4b8e, 5);
    g_1594[5] = fn_212a_014c(g_4b8e, 6);
    g_1594[6] = fn_212a_014c(g_4b8e, 7);
    for (i = 0; i < 18; i++) g_1594[7 + i] = fn_212a_014c(g_4b8e, i + 8);
    g_1594[26] = fn_212a_014c(g_4b8e, 0x1a);
    g_1594[27] = fn_212a_014c(g_4b8e, 0x1b);
    g_1594[28] = fn_212a_014c(g_4b8e, 0x1c);
    g_1594[29] = fn_212a_014c(g_4b8e, 0x1d);
    g_1594[30] = fn_212a_014c(g_4b8e, 0x1e);
    g_1594[31] = fn_212a_014c(g_4b8e, 0x1f);
    g_1594[32] = fn_212a_014c(g_4b8e, 0x20);
    g_1594[25] = fn_212a_014c(g_4b8e, 0x21);
    return 1;
}
