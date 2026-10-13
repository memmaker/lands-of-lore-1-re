/* s036: memory manager stubs (the EMS/XMS paths are compiled out) and a block address compare */
#include "lol.h"

void far *fn_19ba_006a(unsigned long size, unsigned long flags);
void fn_19ba_0081(void);

#pragma exit fn_19ba_0081 100

/* DGROUP 2ab2-2b30: no references from this module; 2af4/2af8 are used by later modules */
char g_2ab2[0x42] = {0};
int g_2af4 = 20;
int g_2af6 = 0;
int g_2af8 = 0;
char g_2afa[6] = {0};
signed char g_2b00[16] = {-1, 6, 2, -1, 4, 5, 3, -1, 0, 7, 1, -1, -1, -1, -1, -1};
int g_2b10[16] = {-33, -32, -31, -1, 1, 31, 32, 33, -64, -96, 2, 3, 64, 96, -2, -3};

int fn_19ba_000a(void)
{
    return 0;
}

unsigned long fn_19ba_0011(void)
{
    return 0;
}

unsigned long fn_19ba_001e(void)
{
    return 0;
}

unsigned long fn_19ba_002b(void)
{
    return 0;
}

unsigned long fn_19ba_0038(void)
{
    return 0;
}

void far *fn_19ba_0045(void)
{
    return 0;
}

void fn_19ba_004e(void)
{
}

void far *fn_19ba_0053(unsigned long size)
{
    return fn_19ba_006a(size, 0x40000UL);
}

void far *fn_19ba_006a(unsigned long size, unsigned long flags)
{
    return 0;
}

int fn_19ba_0073(void)
{
    return 0;
}

int fn_19ba_007a(void)
{
    return 0;
}

void fn_19ba_0081(void)
{
}

int fn_19ba_0086(void)
{
    return 0;
}

int fn_19ba_008d(void)
{
    return 0;
}

int fn_19ba_0094(void)
{
    return 0;
}

void fn_19ba_009b(void)
{
}

int fn_19ba_00a0(void)
{
    return 0;
}

int fn_19ba_00a7(unsigned long far *a, unsigned long far *b)
{
    long d = (long)((*a & 0xffffffUL) - (*b & 0xffffffUL)) >> 4;

    if (d < 0)
        return -1;
    if (d > 0)
        return 1;
    return 0;
}
