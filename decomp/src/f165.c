/* f165: far data segment 250b (segment table 165, 4 bytes), no relocations.
   Placed in F165_FAR (class FAR_DATA) like the original blob; one variable per address other modules use. */
#pragma option -zEF165_FAR -zFFAR_DATA

unsigned char far f_250b_0000[4] = {
    0xff, 0x06, 0xff, 0xf8
};
