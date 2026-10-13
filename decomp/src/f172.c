/* f172: far data segment 25f5 (segment table 172, 32 bytes), no relocations.
   Placed in F172_FAR (class FAR_DATA) (code segment _TEXT: no empty F###_TEXT); one variable per address other modules use. */
#pragma option -zEF172_FAR -zFFAR_DATA -zC_TEXT

unsigned int far f_25f5_0000[16] = {
    0x0001, 0x0002, 0x0000, 0x0003, 0x0004, 0x0005, 0x0006, 0x0041,
    0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x005a, 0x005b, 0xffff
};
