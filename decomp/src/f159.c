/* f159: far data segment 2505 (segment table 159, 4 bytes), no relocations.
   Placed in F159_FAR (class FAR_DATA) like the original blob; one variable per address other modules use. */
#pragma option -zEF159_FAR -zFFAR_DATA

unsigned int far f_2505_0000[2] = {
    0x0700, 0xff00
};
