/* f170: far data segment 25f2 (segment table 170, 4 bytes), no relocations.
   Placed in F170_FAR (class FAR_DATA) (code segment _TEXT: no empty F###_TEXT); one variable per address other modules use. */
#pragma option -zEF170_FAR -zFFAR_DATA -zC_TEXT

unsigned int far f_25f2_0000[2] = {
    0x0040, 0xffff
};
