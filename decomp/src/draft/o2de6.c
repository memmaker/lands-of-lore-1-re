//// ovr_2de6_0020 @ 5f74:0000

void __cdecl16far ovr_2de6_0020(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_CS;
  undefined2 unaff_DS;
  
  iVar3 = 0;
  iVar2 = 0;
  *(undefined4 *)0x3850 = 0xf;
  do {
    iVar1 = func_0x00014700(unaff_CS);
    if (iVar1 == 0) {
      iVar2 = iVar2 + 1;
    }
    else {
      iVar3 = iVar3 + 1;
    }
    unaff_CS = 0x1470;
  } while (*(long *)0x3850 != 0);
  *(uint *)0xad97 = (uint)(iVar2 < iVar3);
  return;
}

