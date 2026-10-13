/* f164: far data segment 250a (segment table 164, 4 bytes), no relocations.
   Placed in F164_FAR (class FAR_DATA) (code segment _TEXT: no empty F###_TEXT); one variable per address other modules use. */
#pragma option -zEF164_FAR -zFFAR_DATA -zC_TEXT

unsigned char far f_250a_0000[4] = {
    0x03, 0x01, 0x03, 0x01
};
