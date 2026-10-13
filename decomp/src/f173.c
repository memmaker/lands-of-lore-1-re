/* f173: far data segment 25f7 (segment table 173, 28 bytes), no relocations.
   Placed in F173_FAR (class FAR_DATA) like the original blob; one variable per address other modules use. */
#pragma option -zEF173_FAR -zFFAR_DATA

unsigned int far f_25f7_0000[14] = {
    0x002c, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037, 0x0038,
    0x0039, 0x003a, 0x003b, 0x003c, 0x003d, 0xffff
};
