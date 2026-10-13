/* s036: stub entry points (EMS/XMS hooks compiled out) and a 24-bit address comparator */

int fn_19ba_000a(void) { return 0; }
long fn_19ba_0011(void) { return 0; }
long fn_19ba_001e(void) { return 0; }
long fn_19ba_002b(void) { return 0; }
long fn_19ba_0038(void) { return 0; }
void far *fn_19ba_0045(void) { return 0; }
void fn_19ba_004e(void) { }
void far *fn_19ba_006a(void far *p, long n);

void far *fn_19ba_0053(void far *p)
{
    return fn_19ba_006a(p, 0x40000L);
}

void far *fn_19ba_006a(void far *p, long n) { return 0; }
int fn_19ba_0073(void) { return 0; }
int fn_19ba_007a(void) { return 0; }
void fn_19ba_0081(void) { }
#pragma exit fn_19ba_0081 100
int fn_19ba_0086(void far *p) { return 0; }
int fn_19ba_008d(void) { return 0; }
int fn_19ba_0094(void) { return 0; }
void fn_19ba_009b(void) { }
int fn_19ba_00a0(void) { return 0; }

int fn_19ba_00a7(unsigned long far *a, unsigned long far *b)
{
    long d;

    d = (long)((*a & 0xffffffL) - (*b & 0xffffffL)) >> 4;
    if (d < 0) return -1;
    else if (d > 0) return 1;
    else return 0;
}
