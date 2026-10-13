/* f176: far data segment 25fb (segment table 176, 24 bytes), no relocations.
   Placed in F176_FAR (class FAR_DATA) like the original blob; one variable per address other modules use. */
#pragma option -zEF176_FAR -zFFAR_DATA

unsigned int far f_25fb_0000[12] = {
    0x0000, 0x001a, 0x0014, 0x001b, 0x003d, 0x0037, 0x003e, 0x005c,
    0x0056, 0x005d, 0x0083, 0x007d
};
