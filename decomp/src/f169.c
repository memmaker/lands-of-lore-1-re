/* f169: far data segment 25f0 (segment table 169, 30 bytes), no relocations.
   Placed in F169_FAR (class FAR_DATA) (code segment _TEXT: no empty F###_TEXT); one variable per address other modules use. */
#pragma option -zEF169_FAR -zFFAR_DATA -zC_TEXT

unsigned int far f_25f0_0000[15] = {
    0x002c, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037, 0x0038,
    0x0039, 0x003a, 0x003b, 0x003c, 0x003d, 0x005e, 0xffff
};
