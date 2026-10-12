"""Constants of the original MAIN.EXE (Lands of Lore CD 1.02d) shared by the tools."""
EXE = 'orig/MAIN.EXE'
HDR = 14336          # MZ header size
IMG_END = 248896     # end of load image in the file = start of FBOV overlay data
DGROUP = 0x2e2d      # DGROUP paragraph (C0L's `mov dx,DGROUP`)
DS = DGROUP * 16     # DGROUP offset in the image
OVR = IMG_END + 16   # overlay code data start in the file (after the FBOV header)
