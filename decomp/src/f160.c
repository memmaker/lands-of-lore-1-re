/* f160: far data segment 2506 (segment table 160, 4 bytes), no relocations.
   Placed in F160_FAR (class FAR_DATA) (code segment _TEXT: no empty F###_TEXT); one variable per address other modules use. */
#pragma option -zEF160_FAR -zFFAR_DATA -zC_TEXT

unsigned int far f_2506_0000[2] = {
    0x00fd, 0x0006
};
