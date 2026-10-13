/* f175: far data segment 25fa (segment table 175, 4 bytes), no relocations.
   Placed in F175_FAR (class FAR_DATA) (code segment _TEXT: no empty F###_TEXT); one variable per address other modules use. */
#pragma option -zEF175_FAR -zFFAR_DATA -zC_TEXT

unsigned int far f_25fa_0000[2] = {
    0x0055, 0xffff
};
