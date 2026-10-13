/* f166: far data segment 250c (segment table 166, 1464 bytes), no relocations.
   Placed in F166_FAR (class FAR_DATA) like the original blob; one variable per address other modules use. */
#pragma option -zEF166_FAR -zFFAR_DATA

unsigned int far f_250c_0000[2] = {
    0xfff9, 0xff05
};
unsigned int far f_250c_0004[128] = {
    0x0000
};
unsigned int far f_250c_0104[384] = {
    0x0000
};
unsigned int far f_250c_0404[218] = {
    0x0000
};
