/* f175: far data segment 25fa (segment table 175, 4 bytes), no relocations.
   Placed in F175_FAR (class FAR_DATA) like the original blob; one variable per address other modules use. */
#pragma option -zEF175_FAR -zFFAR_DATA

unsigned int far f_25fa_0000[2] = {
    0x0055, 0xffff
};
