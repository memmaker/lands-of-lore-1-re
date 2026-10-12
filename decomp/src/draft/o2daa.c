//// ovr_2daa_0020 @ 5cd7:0000

undefined2 __cdecl16far ovr_2daa_0020(long param_1,long param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 extraout_DX;
  undefined2 unaff_DS;
  
  uVar1 = func_0x0001478f();
  *(undefined2 *)0x388c = uVar1;
  func_0x00013e9a(0x1478);
  uVar1 = extraout_DX;
  fn_0000_3c82();
  if ((param_1 == 0) || (iRam000163a8 != 0)) {
    uVar2 = fn_0000_3d34(0);
    if (param_2 <= CONCAT22(uVar1,uVar2)) {
      func_0x000147eb(0x1398);
      func_0x00014580(0x13f8);
      fn_080e_034f();
      func_0x0001132f(0x1840,(int)param_1,(int)((ulong)param_1 >> 0x10));
      *(undefined1 *)0x1592 = 1;
      *(undefined2 *)0x3618 = 1;
      return 0;
    }
    func_0x00013a0e(0x1398,(int)*(undefined4 *)0x1610,(int)((ulong)*(undefined4 *)0x1610 >> 0x10));
    __dos_setvect(0x3f,(int)*(undefined4 *)0x4b88,(int)((ulong)*(undefined4 *)0x4b88 >> 0x10));
  }
  else {
    func_0x00013a0e(0x13c8,(int)*(undefined4 *)0x1608,(int)((ulong)*(undefined4 *)0x1608 >> 0x10));
  }
  return 1;
}

