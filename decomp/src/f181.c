/* f181: far data segment 26a2 (segment table 181, 24 bytes), no relocations.
   Placed in F181_FAR (class FAR_DATA) like the original blob; one variable per address other modules use. */
#pragma option -zEF181_FAR -zFFAR_DATA

unsigned int far f_26a2_0000[12] = {
    0x000f, 0x0019, 0x0014, 0x000a, 0x0019, 0x0014, 0x0005, 0x0019,
    0x0014, 0x0000, 0x0019, 0x0014
};
