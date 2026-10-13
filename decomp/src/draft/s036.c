//// fn_19ba_000a @ 29ba:000a

undefined2 __cdecl16far fn_19ba_000a(void)

{
  return 0;
}


//// fn_19ba_0011 @ 29ba:0011

undefined2 __cdecl16far fn_19ba_0011(void)

{
  return 0;
}


//// fn_19ba_001e @ 29ba:001e

undefined2 __cdecl16far fn_19ba_001e(void)

{
  return 0;
}


//// fn_19ba_002b @ 29ba:002b

undefined2 __cdecl16far fn_19ba_002b(void)

{
  return 0;
}


//// fn_19ba_0038 @ 29ba:0038

undefined2 __cdecl16far fn_19ba_0038(void)

{
  return 0;
}


//// fn_19ba_0045 @ 29ba:0045

undefined2 __cdecl16far fn_19ba_0045(void)

{
  return 0;
}


//// fn_19ba_004e @ 29ba:004e

void __cdecl16far fn_19ba_004e(void)

{
  return;
}


//// fn_19ba_0053 @ 29ba:0053

void __cdecl16far fn_19ba_0053(undefined4 param_1)

{
  fn_19ba_006a(param_1,0x40000);
  return;
}


//// fn_19ba_006a @ 29ba:006a

undefined2 __cdecl16far fn_19ba_006a(void)

{
  return 0;
}


//// fn_19ba_0073 @ 29ba:0073

undefined2 __cdecl16far fn_19ba_0073(void)

{
  return 0;
}


//// fn_19ba_007a @ 29ba:007a

undefined2 __cdecl16far fn_19ba_007a(void)

{
  return 0;
}


//// fn_19ba_0081 @ 29ba:0081

void __cdecl16far fn_19ba_0081(void)

{
  return;
}


//// fn_19ba_0086 @ 29ba:0086

undefined2 __cdecl16far fn_19ba_0086(void)

{
  return 0;
}


//// fn_19ba_008d @ 29ba:008d

undefined2 __cdecl16far fn_19ba_008d(void)

{
  return 0;
}


//// fn_19ba_0094 @ 29ba:0094

undefined2 __cdecl16far fn_19ba_0094(void)

{
  return 0;
}


//// fn_19ba_009b @ 29ba:009b

void __cdecl16far fn_19ba_009b(void)

{
  return;
}


//// fn_19ba_00a0 @ 29ba:00a0

undefined2 __cdecl16far fn_19ba_00a0(void)

{
  return 0;
}


//// fn_19ba_00a7 @ 29ba:00a7

undefined2 __cdecl16far fn_19ba_00a7(ulong *param_1,ulong *param_2)

{
  undefined2 uVar1;
  long lVar2;
  
  lVar2 = (long)((*param_1 & 0xffffff) - (*param_2 & 0xffffff)) >> 4;
  if (lVar2 < 0) {
    uVar1 = 0xffff;
  }
  else if (lVar2 < 1) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

