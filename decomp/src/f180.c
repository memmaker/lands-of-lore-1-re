/* f180: far data segment 26a0 (segment table 180, 26 bytes), no relocations.
   Placed in F180_FAR (class FAR_DATA) like the original blob; one variable per address other modules use. */
#pragma option -zEF180_FAR -zFFAR_DATA

unsigned int far f_26a0_0000[12] = {
    0x000b, 0x0010, 0x000e, 0x0011, 0x001a, 0x0016, 0x001b, 0x0023,
    0x0020, 0x000b, 0x0010, 0x000e
};
unsigned int far f_26a0_0018 = 0x0000;
