/* s123: WW library -- DOS file call wrappers that flag "inside DOS" (g_abde) for the critical error handler */
#include <io.h>
#include <dir.h>
#include <dos.h>

extern char g_abde;

int far fn_2148_000f(void)
{
    int r;
    g_abde++;
    r = getdisk();
    g_abde--;
    return r;
}

int far fn_2148_002c(int drive)
{
    int r;
    g_abde++;
    r = setdisk(drive);
    g_abde--;
    return r;
}

int far fn_2148_004d(int fd)
{
    int r;
    g_abde++;
    r = close(fd);
    g_abde--;
    return r;
}

int far fn_2148_006e(char far *path)
{
    int r;
    g_abde++;
    r = unlink(path);
    g_abde--;
    return r;
}

long far fn_2148_0094(int fd, long off, int whence)
{
    long r;
    g_abde++;
    r = lseek(fd, off, whence);
    g_abde--;
    return r;
}

int far fn_2148_00c9(int fd, void far *buf, unsigned n)
{
    int r;
    g_abde++;
    r = read(fd, buf, n);
    g_abde--;
    return r;
}

int far fn_2148_00f5(int fd, void far *buf, unsigned n)
{
    int r;
    g_abde++;
    r = write(fd, buf, n);
    g_abde--;
    return r;
}

int far fn_2148_0121(char far *path, int access, unsigned mode)
{
    int r;
    g_abde++;
    r = open(path, access, mode);
    g_abde--;
    return r;
}

int far fn_2148_014d(char far *path)
{
    int r;
    g_abde++;
    r = chdir(path);
    g_abde--;
    return r;
}
