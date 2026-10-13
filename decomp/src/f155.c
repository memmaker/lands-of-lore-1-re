/* f155: far data segment 2501 (segment table 155, 4 bytes), no relocations.
   Placed in F155_FAR (class FAR_DATA) like the original blob; one variable per address other modules use. */
#pragma option -zEF155_FAR -zFFAR_DATA

unsigned char far f_2501_0000[4] = {
    0x00, 0x07, 0x00, 0xfb
};
