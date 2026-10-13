/* f171: far data segment 25f3 (segment table 171, 30 bytes), no relocations.
   Placed in F171_FAR (class FAR_DATA) like the original blob; one variable per address other modules use. */
#pragma option -zEF171_FAR -zFFAR_DATA

unsigned int far f_25f3_0000[15] = {
    0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037, 0x0038, 0x0039,
    0x003a, 0x003b, 0x003c, 0x003d, 0x005a, 0x005b, 0xffff
};
