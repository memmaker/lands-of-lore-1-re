//// fn_0845_0008 @ 1845:0008

void __cdecl16far
fn_0845_0008(int param_1,int param_2,int param_3,int param_4,undefined2 param_5,undefined2 param_6,
             int param_7)

{
  param_3 = param_3 + -1;
  param_4 = param_4 + -1;
  if (param_7 != -1) {
    fn_1e59_001d(param_1 + 1,param_2 + 1,param_1 + param_3 + -1,param_2 + param_4 + -1,param_7);
  }
  fn_1e30_0209(param_1 + 1,param_2,param_1 + param_3,param_2,param_6);
  fn_1e30_0209(param_1 + param_3,param_2,param_1 + param_3,param_2 + param_4 + -1,param_6);
  fn_1e30_0209(param_1,param_2,param_1,param_2 + param_4,param_5);
  fn_1e30_0209(param_1,param_2 + param_4,param_1 + param_3,param_2 + param_4,param_5);
  return;
}


//// fn_0845_00ac @ 1845:00ac

void __cdecl16far
fn_0845_00ac(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
             int param_8,undefined2 param_9,int param_10)

{
  int iVar1;
  
  param_6 = param_6 + -1;
  param_7 = param_7 + -1;
  if (0 < param_5) {
    if (param_3 < 1) {
      param_3 = 0;
    }
    if (param_5 < param_3) {
      param_3 = param_5;
    }
    iVar1 = (param_7 * param_3) / param_5;
    if ((iVar1 < 1) && (0 < param_3)) {
      iVar1 = 1;
    }
    fn_1e30_0209(param_1 + -1,param_2 - param_7,param_1 + -1,param_2,1);
    if (param_10 != 0) {
      if (param_3 < param_5 >> 1) {
        param_8 = 0x90;
      }
      if (param_3 < param_5 >> 2) {
        param_8 = 0x84;
      }
    }
    if (0 < iVar1) {
      fn_1e59_001d(param_1,param_2 - iVar1,param_1 + param_6,param_2,param_8);
    }
    if (iVar1 < param_7) {
      fn_1e59_001d(param_1,param_2 - param_7,param_1 + param_6,param_2 - iVar1,param_9);
    }
    if ((0 < param_4) && (param_4 <= param_5)) {
      param_5 = (param_7 * param_4) / param_5;
      if (param_5 < 1) {
        param_5 = 1;
      }
      fn_1e54_0001(param_1,param_2 - param_5,param_1 + param_6,param_2,param_8 + -2);
    }
  }
  return;
}


//// fn_0845_01c4 @ 1845:01c4

void fn_0845_01c4(undefined2 param_1,uint param_2)

{
  uint uVar1;
  undefined1 auStack_3f8 [768];
  undefined1 auStack_f8 [240];
  undefined2 uStack_8;
  undefined1 *puStack_6;
  
  fn_1ebc_00e7();
  if ((param_2 & 4) == 0) {
    fn_130a_0784();
  }
  else {
    param_2 = param_2 ^ 4;
  }
  uVar1 = (uint)*(byte *)((param_2 & 0x7fff) + 0x21db);
  if ((g_7fd6 & 2) == 0) {
    uStack_8 = fn_14b3_01fa();
    memcpy(auStack_3f8);
    fn_1ef2_002f(auStack_3f8);
    uVar1 = 0xc0;
    fn_0bbc_070e(0x1000b);
  }
  else {
    uStack_8 = fn_14b3_01fa();
  }
  fn_1ebc_00fe();
  puStack_6 = &stack0x000a;
  g_3713 = uVar1;
  vsprintf(auStack_f8);
  fn_14b3_0284(auStack_f8);
  fn_14b3_0122();
  if (((param_2 & 0x8000) == 0) && (*(char *)(param_2 + 0x21d6) != '\0')) {
    fn_067a_0401(*(undefined1 *)(param_2 + 0x21d6),0);
  }
  g_20f4 = param_2 & 0x7fff;
  g_20f6 = 0;
  return;
}


//// fn_0845_01d0 @ 1845:01d0

void fn_0845_01d0(void)

{
  undefined2 uVar1;
  int unaff_BP;
  uint unaff_SI;
  uint uVar2;
  undefined2 unaff_SS;
  
  fn_1ebc_00e7();
  if ((unaff_SI & 4) == 0) {
    fn_130a_0784();
  }
  else {
    unaff_SI = unaff_SI ^ 4;
  }
  uVar2 = (uint)*(byte *)((unaff_SI & 0x7fff) + 0x21db);
  if ((g_7fd6 & 2) == 0) {
    uVar1 = fn_14b3_01fa();
    *(undefined2 *)(unaff_BP + -6) = uVar1;
    memcpy(unaff_BP + -0x3f6);
    fn_1ef2_002f(unaff_BP + -0x3f6);
    uVar2 = 0xc0;
    fn_0bbc_070e(0x1000b);
  }
  else {
    uVar1 = fn_14b3_01fa();
    *(undefined2 *)(unaff_BP + -6) = uVar1;
  }
  fn_1ebc_00fe();
  g_3713 = uVar2;
  *(undefined2 *)(unaff_BP + -2) = unaff_SS;
  *(int *)(unaff_BP + -4) = unaff_BP + 0xc;
  vsprintf(unaff_BP + -0xf6);
  fn_14b3_0284(unaff_BP + -0xf6);
  fn_14b3_0122();
  if (((unaff_SI & 0x8000) == 0) && (*(char *)(unaff_SI + 0x21d6) != '\0')) {
    fn_067a_0401(*(undefined1 *)(unaff_SI + 0x21d6),0);
  }
  g_20f4 = unaff_SI & 0x7fff;
  g_20f6 = 0;
  return;
}


//// fn_0845_01d5 @ 1845:01d5

void __cdecl16far fn_0845_01d5(void)

{
  undefined2 uVar1;
  int unaff_BP;
  uint unaff_SI;
  uint uVar2;
  undefined2 unaff_SS;
  
  if ((unaff_SI & 4) == 0) {
    fn_130a_0784();
  }
  else {
    unaff_SI = unaff_SI ^ 4;
  }
  uVar2 = (uint)*(byte *)((unaff_SI & 0x7fff) + 0x21db);
  if ((g_7fd6 & 2) == 0) {
    uVar1 = fn_14b3_01fa();
    *(undefined2 *)(unaff_BP + -6) = uVar1;
    memcpy(unaff_BP + -0x3f6);
    fn_1ef2_002f(unaff_BP + -0x3f6);
    uVar2 = 0xc0;
    fn_0bbc_070e(0x1000b);
  }
  else {
    uVar1 = fn_14b3_01fa();
    *(undefined2 *)(unaff_BP + -6) = uVar1;
  }
  fn_1ebc_00fe();
  g_3713 = uVar2;
  *(undefined2 *)(unaff_BP + -2) = unaff_SS;
  *(int *)(unaff_BP + -4) = unaff_BP + 0xc;
  vsprintf(unaff_BP + -0xf6);
  fn_14b3_0284(unaff_BP + -0xf6);
  fn_14b3_0122();
  if (((unaff_SI & 0x8000) == 0) && (*(char *)(unaff_SI + 0x21d6) != '\0')) {
    fn_067a_0401(*(undefined1 *)(unaff_SI + 0x21d6),0);
  }
  g_20f4 = unaff_SI & 0x7fff;
  g_20f6 = 0;
  return;
}


//// fn_0845_01df @ 1845:01df

void __cdecl16far fn_0845_01df(void)

{
  undefined2 uVar1;
  int unaff_BP;
  uint unaff_SI;
  uint uVar2;
  undefined2 unaff_SS;
  
  uVar2 = (uint)*(byte *)((unaff_SI & 0x7fff) + 0x21db);
  if ((g_7fd6 & 2) == 0) {
    uVar1 = fn_14b3_01fa();
    *(undefined2 *)(unaff_BP + -6) = uVar1;
    memcpy(unaff_BP + -0x3f6);
    fn_1ef2_002f(unaff_BP + -0x3f6);
    uVar2 = 0xc0;
    fn_0bbc_070e(0xb);
  }
  else {
    uVar1 = fn_14b3_01fa();
    *(undefined2 *)(unaff_BP + -6) = uVar1;
  }
  fn_1ebc_00fe();
  g_3713 = uVar2;
  *(undefined2 *)(unaff_BP + -2) = unaff_SS;
  *(int *)(unaff_BP + -4) = unaff_BP + 0xc;
  vsprintf(unaff_BP + -0xf6);
  fn_14b3_0284(unaff_BP + -0xf6);
  fn_14b3_0122();
  if (((unaff_SI & 0x8000) == 0) && (*(char *)(unaff_SI + 0x21d6) != '\0')) {
    fn_067a_0401(*(undefined1 *)(unaff_SI + 0x21d6));
  }
  g_20f4 = unaff_SI & 0x7fff;
  g_20f6 = 0;
  return;
}


//// fn_0845_02c6 @ 1845:02c6

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fn_0845_02c6(undefined2 param_1,undefined4 param_2,undefined1 *param_3,int param_4,
                  uint param_5)

{
  fn_2279_025b(param_2,param_3,0x300);
  fn_0845_1430(param_3);
  if (((-1 < (int)param_5) && ((int)param_5 < 8)) && ((_LAB_422c_4079_1 & 0x800) != 0)) {
                    /* WARNING: Subroutine does not return */
    fn_1aff_0420((8 - param_4) * -0x20 + 0x100,(param_5 & 0xfffe) << 5);
  }
                    /* WARNING: Subroutine does not return */
  fn_1aff_0420(*param_3,(8 - param_4) * 0x20);
}


//// fn_0845_0350 @ 1845:0350

void __cdecl16far fn_0845_0350(void)

{
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_SS;
  
  if (0x17f < unaff_DI + 1) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  fn_1aff_0420(*(undefined1 *)((int)*(undefined4 *)(unaff_BP + 10) + unaff_DI + 1));
}


//// fn_0845_035b @ 1845:035b

void __cdecl16far fn_0845_035b(undefined4 param_1,undefined2 param_2,undefined2 param_3)

{
  fn_0845_02c6((char *)s_Lib_error_29_3e2d_1842 + 3,(int)param_1,(int)((ulong)param_1 >> 0x10),
                (int)g_540e,(int)((ulong)g_540e >> 0x10),param_2,param_3);
  fn_1ef2_0075((int)g_540e,(int)((ulong)g_540e >> 0x10),5,0);
  g_20d5 = 0;
  return;
}


//// fn_0845_038e @ 1845:038e

undefined2 __cdecl16far
fn_0845_038e(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined2 uVar1;
  
  if ((((param_1 < param_3) || (param_5 < param_1)) || (param_2 < param_4)) || (param_6 < param_2))
  {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


//// fn_0845_03b4 @ 1845:03b4

void fn_0845_03b4(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
                  undefined2 param_5)

{
  fn_0845_038e(g_2f10,g_2f12,param_2,param_3,param_4,param_5);
  return;
}


//// fn_0845_03d0 @ 1845:03d0

void __cdecl16far fn_0845_03d0(void)

{
  return;
}


//// fn_0845_03d4 @ 1845:03d4

void __cdecl16far fn_0845_03d4(void)

{
  undefined1 local_304 [768];
  undefined2 local_4;
  
  if (g_20d5 != 1) {
    fn_2279_025b(g_adea,local_304);
    setmem();
    fn_0845_1430(local_304);
    fn_1ef2_0075();
    fn_1ebc_00e7();
    local_4 = fn_1e74_000f();
    fn_1e59_001d();
    fn_1e74_000f();
    fn_1ebc_00fe();
    g_20d5 = 1;
  }
  return;
}


//// fn_0845_0450 @ 1845:0450

void __cdecl16far fn_0845_0450(void)

{
  char *pcVar1;
  int in_BX;
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 uStack0004;
  char *pcStack0006;
  undefined2 uStack0008;
  
  pcVar1 = (char *)(in_BX + unaff_DI + 0x2e);
  *pcVar1 = *pcVar1 + (char)in_BX;
  uStack0008 = *(undefined2 *)(unaff_BP + -2);
  pcStack0006 = (char *)s_Lib_error_29_3e2d_1842 + 3;
  uStack0004 = 0x88ae;
  fn_1e74_000f();
  uStack0008 = 0x2e74;
  pcStack0006 = (char *)0x88b4;
  fn_1ebc_00fe();
  g_20d5 = 1;
  return;
}


//// fn_0845_046c @ 1845:046c

undefined2 __cdecl16far fn_0845_046c(int param_1)

{
  int iVar1;
  int *local_6;
  
  if (g_7fb6 == 0) {
    local_6 = &g_4eac;
    iVar1 = 0;
    do {
      if (*local_6 == param_1) goto LAB_1845_0493;
      iVar1 = iVar1 + 1;
      local_6 = (int *)CONCAT22(local_6._2_2_,(int *)local_6 + 1);
    } while (iVar1 < 0xf);
    if (param_1 != g_7fd0) {
      return 0;
    }
LAB_1845_0493:
    g_7fb6 = 1;
  }
  return 1;
}


//// fn_0845_04af @ 1845:04af

int __cdecl16far fn_0845_04af(int param_1,int param_2,int param_3,int param_4)

{
  if (param_1 < param_3) {
    param_1 = -(param_1 - param_3);
  }
  else {
    param_1 = param_1 - param_3;
  }
  if (param_2 < param_4) {
    param_2 = -(param_2 - param_4);
  }
  else {
    param_2 = param_2 - param_4;
  }
  return param_1 + param_2;
}


//// fn_0845_04d0 @ 1845:04d0

int __cdecl16far fn_0845_04d0(void)

{
  uint *puVar1;
  uint uVar2;
  int in_AX;
  int iVar3;
  int in_BX;
  int unaff_SI;
  undefined1 in_CF;
  int in_stack_00000000;
  
  puVar1 = (uint *)(in_BX + unaff_SI + -0x75);
  uVar2 = *puVar1;
  *puVar1 = uVar2 << 3 | (uint)(CONCAT12(in_CF,uVar2) >> 0xe);
  if (in_AX < unaff_SI) {
    iVar3 = -(in_BX - unaff_SI);
  }
  else {
    iVar3 = in_BX - unaff_SI;
  }
  return in_stack_00000000 + iVar3;
}


//// fn_0845_04ec @ 1845:04ec

undefined2 __cdecl16far fn_0845_04ec(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 uVar5;
  ulong in_EDX;
  undefined1 local_16 [16];
  undefined4 local_6;
  
  iVar1 = fn_2365_063f(param_1);
  if ((iVar1 == 0) && (iVar1 = fn_19ba_0086(param_1), iVar1 == 0)) {
  }
  else {
    iVar1 = fn_15a7_030c(g_4ea0,param_1);
    local_6 = CONCAT22((int)in_EDX,iVar1);
    if (iVar1 == 0 && (int)in_EDX == 0) {
      fn_2279_025b(param_1,local_16);
      iVar1 = fn_1f36_0029(local_16);
      iVar2 = fn_15a7_00b0(g_4ea0,(long)iVar1,param_1);
      local_6 = CONCAT22((int)in_EDX,iVar2);
      if (iVar2 == 0 && (int)in_EDX == 0) {
        while( true ) {
          uVar5 = (undefined2)in_EDX;
          uVar3 = fn_15a7_04b0(g_4ea0);
          in_EDX = (ulong)(iVar1 + 0x10);
          if ((long)in_EDX < CONCAT22(uVar5,uVar3)) break;
          fn_15a7_043c(g_4ea0);
        }
        iVar2 = 0;
        while( true ) {
          iVar4 = fn_15a7_00b0(g_4ea0,(long)iVar1,param_1);
          local_6 = CONCAT22((int)in_EDX,iVar4);
          if (iVar4 != 0 || (int)in_EDX != 0) break;
          if (iVar2 != 0) {
            fn_15a7_043c(g_4ea0);
          }
          if (2 < iVar2 + 1) {
            fn_15a7_0004(g_4ea0,15000);
          }
          fn_15a7_0501(g_4ea0);
          iVar2 = iVar2 + 1;
        }
      }
      fn_2279_025b(param_1,local_6,(long)iVar1);
    }
    param_1._0_2_ = (undefined2)local_6;
  }
  return (undefined2)param_1;
}


//// fn_0845_0631 @ 1845:0631

void __cdecl16far fn_0845_0631(void)

{
  return;
}


//// fn_0845_0636 @ 1845:0636

int __cdecl16far fn_0845_0636(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int local_4;
  
  local_4 = 0;
  if (((0 < param_2) && (0 < param_1)) &&
     (iVar2 = 0, pcVar3 = (char *)s_Lib_error_29_3e2d_1842 + 3, 0 < param_1)) {
    do {
      iVar1 = rand(pcVar3);
      iVar1 = (int)(((long)iVar1 * (long)param_2) / 0x8000) + 1;
      if (param_2 < iVar1) {
        iVar1 = iVar1 - param_2;
      }
      local_4 = local_4 + iVar1;
      iVar2 = iVar2 + 1;
      pcVar3 = (char *)0x1000;
    } while (iVar2 < param_1);
  }
  return local_4;
}


//// fn_0845_0650 @ 1845:0650

undefined2 fn_0845_0650(void)

{
  int iVar1;
  int unaff_BP;
  int unaff_SI;
  int iVar2;
  char *pcVar3;
  undefined2 unaff_SS;
  
  iVar2 = 0;
  pcVar3 = (char *)s_Lib_error_29_3e2d_1842 + 3;
  if (0 < *(int *)(unaff_BP + 6)) {
    do {
      iVar1 = rand(pcVar3);
      iVar1 = (int)(((long)iVar1 * (long)unaff_SI) / 0x8000) + 1;
      if (unaff_SI < iVar1) {
        iVar1 = iVar1 - unaff_SI;
      }
      *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + iVar1;
      iVar2 = iVar2 + 1;
      pcVar3 = (char *)0x1000;
    } while (iVar2 < *(int *)(unaff_BP + 6));
  }
  return *(undefined2 *)(unaff_BP + -2);
}


//// fn_0845_0655 @ 1845:0655

undefined2 __cdecl16far fn_0845_0655(void)

{
  int iVar1;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  char *pcVar2;
  undefined2 unaff_SS;
  char in_SF;
  char in_OF;
  
  pcVar2 = (char *)s_Lib_error_29_3e2d_1842 + 3;
  if (in_OF != in_SF) {
    do {
      iVar1 = rand(pcVar2);
      iVar1 = (int)(((long)iVar1 * (long)unaff_SI) / 0x8000) + 1;
      if (unaff_SI < iVar1) {
        iVar1 = iVar1 - unaff_SI;
      }
      *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + iVar1;
      unaff_DI = unaff_DI + 1;
      pcVar2 = (char *)0x1000;
    } while (unaff_DI < *(int *)(unaff_BP + 6));
  }
  return *(undefined2 *)(unaff_BP + -2);
}


//// fn_0845_0664 @ 1845:0664

undefined2 fn_0845_0664(void)

{
  int iVar1;
  long in_EAX;
  long in_EDX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  char *pcVar2;
  undefined2 unaff_SS;
  
  pcVar2 = (char *)s_Lib_error_29_3e2d_1842 + 3;
  while( true ) {
    iVar1 = (int)((in_EAX * in_EDX) / 0x8000) + 1;
    if (unaff_SI < iVar1) {
      iVar1 = iVar1 - unaff_SI;
    }
    *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + iVar1;
    unaff_DI = unaff_DI + 1;
    if (*(int *)(unaff_BP + 6) <= unaff_DI) break;
    iVar1 = rand(pcVar2);
    in_EAX = (long)iVar1;
    in_EDX = (long)unaff_SI;
    pcVar2 = (char *)0x1000;
  }
  return *(undefined2 *)(unaff_BP + -2);
}


//// fn_0845_066e @ 1845:066e

undefined2 __cdecl16far fn_0845_066e(void)

{
  int iVar1;
  long in_EAX;
  long in_EBX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  char *pcVar2;
  undefined2 unaff_SS;
  
  pcVar2 = (char *)s_Lib_error_29_3e2d_1842 + 3;
  while( true ) {
    iVar1 = (int)(in_EAX / in_EBX) + 1;
    if (unaff_SI < iVar1) {
      iVar1 = iVar1 - unaff_SI;
    }
    *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + iVar1;
    unaff_DI = unaff_DI + 1;
    if (*(int *)(unaff_BP + 6) <= unaff_DI) break;
    iVar1 = rand(pcVar2);
    in_EAX = (long)iVar1 * (long)unaff_SI;
    in_EBX = 0x8000;
    pcVar2 = (char *)0x1000;
  }
  return *(undefined2 *)(unaff_BP + -2);
}


//// fn_0845_068c @ 1845:068c

void fn_0845_068c(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  undefined2 in_DX;
  undefined4 local_6;
  
  uVar1 = fn_0845_04ec(param_4);
  local_6 = CONCAT22(in_DX,uVar1);
  fn_1e9f_0002(param_2,param_3,uVar1,in_DX);
  fn_0845_0631(local_6);
  g_ab22 = param_2;
  g_ab20 = param_3;
  g_ab1c = param_4;
  return;
}


//// fn_0845_06d0 @ 1845:06d0

char fn_0845_06d0(void)

{
  char in_AL;
  char in_CF;
  
  return (in_AL + 'U') - in_CF;
}


//// fn_0845_06d5 @ 1845:06d5

void __cdecl16far fn_0845_06d5(void)

{
  return;
}


//// fn_0845_06d6 @ 1845:06d6

void fn_0845_06d6(undefined2 param_1,undefined2 *param_2,undefined2 *param_3,undefined4 *param_4)

{
  *param_2 = g_ab22;
  *param_3 = g_ab20;
  *param_4 = g_ab1c;
  return;
}


//// fn_0845_06df @ 1845:06df

void __cdecl16far fn_0845_06df(void)

{
  undefined2 in_AX;
  undefined2 *in_BX;
  int unaff_BP;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  
  *in_BX = in_AX;
  *(undefined2 *)*(undefined4 *)(unaff_BP + 10) = g_ab20;
  *(undefined4 *)*(undefined4 *)(unaff_BP + 0xe) = g_ab1c;
  return;
}


//// fn_0845_06f8 @ 1845:06f8

undefined1 * fn_0845_06f8(undefined2 param_1,uint param_2)

{
  undefined1 *puVar1;
  undefined2 uVar2;
  undefined1 *puVar3;
  undefined2 uVar4;
  undefined2 unaff_SS;
  undefined1 auStack_206 [512];
  undefined1 *puStack_6;
  
  if (param_2 == 0xffff) {
    uVar4 = 0;
    puStack_6 = (undefined1 *)0x0;
  }
  else {
    uVar4 = uRam0004303a;
    if ((param_2 & 0x4000) != 0) {
      uVar4 = uRam0004303e;
    }
    uVar2 = fn_212a_014c();
    _puStack_6 = (undefined1 *)CONCAT22(uVar4,uVar2);
    fn_2279_025b(uVar2,uVar4,auStack_206);
    _puStack_6 = (undefined1 *)CONCAT22(unaff_SS,auStack_206);
    if (_puStack_6 != (undefined1 *)0x0) {
      fn_212a_00e5(_puStack_6,g_21e0 << 9,0x3b8c);
      puVar3 = (undefined1 *)(g_21e0 << 9);
      _puStack_6 = (undefined1 *)CONCAT22(0x3b8c,puVar3);
      fn_212a_0005(puVar3,0x3b8c,puVar3,0x3b8c);
      g_21e0 = (g_21e0 + 1) % 4;
    }
    puVar1 = _puStack_6;
    uVar4 = (undefined2)((ulong)_puStack_6 >> 0x10);
    puStack_6 = (undefined1 *)puVar1;
  }
  return (undefined1 *)CONCAT22(uVar4,puStack_6);
}


//// fn_0845_0707 @ 1845:0707

undefined2 __cdecl16far fn_0845_0707(void)

{
  return 0;
}


//// caseD_0 @ 1845:070e

undefined2 __cdecl16far switchD_1000:e738::caseD_0(void)

{
  undefined2 uVar1;
  int iVar2;
  uint in_DX;
  undefined2 uVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  
  uVar3 = uRam0004303a;
  if ((in_DX & 0x4000) != 0) {
    uVar3 = uRam0004303e;
  }
  uVar1 = fn_212a_014c();
  *(undefined2 *)(unaff_BP + -2) = uVar3;
  *(undefined2 *)(unaff_BP + -4) = uVar1;
  fn_2279_025b(*(undefined2 *)(unaff_BP + -4),uVar3,unaff_BP + -0x204);
  *(undefined2 *)(unaff_BP + -2) = unaff_SS;
  *(int *)(unaff_BP + -4) = unaff_BP + -0x204;
  if (*(long *)(unaff_BP + -4) != 0) {
    fn_212a_00e5(*(undefined4 *)(unaff_BP + -4),g_21e0 << 9,0x3b8c);
    iVar2 = g_21e0 << 9;
    *(undefined2 *)(unaff_BP + -2) = 0x3b8c;
    *(int *)(unaff_BP + -4) = iVar2;
    fn_212a_0005(iVar2,*(undefined2 *)(unaff_BP + -2),iVar2,*(undefined2 *)(unaff_BP + -2));
    g_21e0 = (g_21e0 + 1) % 4;
  }
  return *(undefined2 *)(unaff_BP + -4);
}


//// fn_0845_07b3 @ 1845:07b3

void __cdecl16far fn_0845_07b3(long param_1)

{
  uint in_stack_00000010;
  undefined1 auStack_f6 [240];
  undefined1 *local_6;
  
  if (param_1 != 0) {
    local_6 = &stack0x0012;
    vsprintf(auStack_f6);
    if ((in_stack_00000010 & 1) != 0) {
      fn_1e64_002b(auStack_f6);
    }
    if ((in_stack_00000010 & 2) != 0) {
      fn_1e64_002b(auStack_f6);
    }
    if ((in_stack_00000010 & 4) != 0) {
      fn_1f6c_0006(auStack_f6);
      fn_1f6c_0006(auStack_f6);
    }
    if ((in_stack_00000010 & 8) != 0) {
      fn_1f6c_0006(auStack_f6);
      fn_1f6c_0006(auStack_f6);
    }
    fn_1f6c_0006(auStack_f6);
  }
  return;
}


//// fn_0845_07d5 @ 1845:07d5

void __cdecl16far fn_0845_07d5(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  vsprintf(unaff_BP + -0xf4);
  if ((*(uint *)(unaff_BP + 0x12) & 1) != 0) {
    fn_1e64_002b(unaff_BP + -0xf4);
  }
  if ((*(uint *)(unaff_BP + 0x12) & 2) != 0) {
    fn_1e64_002b(unaff_BP + -0xf4);
  }
  if ((*(uint *)(unaff_BP + 0x12) & 4) != 0) {
    fn_1f6c_0006(unaff_BP + -0xf4);
    fn_1f6c_0006(unaff_BP + -0xf4);
  }
  if ((*(uint *)(unaff_BP + 0x12) & 8) != 0) {
    fn_1f6c_0006(unaff_BP + -0xf4);
    fn_1f6c_0006(unaff_BP + -0xf4);
  }
  fn_1f6c_0006(unaff_BP + -0xf4);
  return;
}


//// fn_0845_085f @ 1845:085f

void __cdecl16far fn_0845_085f(void)

{
  int unaff_BP;
  
  fn_1f6c_0006(unaff_BP + -0xf4);
  fn_1f6c_0006(unaff_BP + -0xf4);
  fn_1f6c_0006(unaff_BP + -0xf4);
  return;
}


//// fn_0845_08a5 @ 1845:08a5

void __cdecl16far fn_0845_08a5(void)

{
  return;
}


//// fn_0845_08aa @ 1845:08aa

void fn_0845_08aa(void)

{
  fn_234e_0003(2);
  fn_1dbc_0017(0x334e,0xe,0xe0000,0x160000,0x78,uRam00043040);
  fn_234e_0062();
  return;
}


//// fn_0845_08d5 @ 1845:08d5

void fn_0845_08d5(void)

{
  undefined1 auStack_302 [768];
  
  setmem((char *)s_Lib_error_29_3e2d_1842 + 3,auStack_302);
  fn_1ef2_0075(auStack_302);
  g_20d5 = 2;
  return;
}


//// fn_0845_08d9 @ 1845:08d9

void fn_0845_08d9(void)

{
  undefined1 auStack_302 [768];
  
  setmem((char *)s_Lib_error_29_3e2d_1842 + 3,auStack_302);
  fn_1ef2_0075(auStack_302);
  g_20d5 = 2;
  return;
}


//// fn_0845_08da @ 1845:08da

void __cdecl16far fn_0845_08da(void)

{
  undefined1 local_300 [768];
  
  setmem((char *)s_Lib_error_29_3e2d_1842 + 3,local_300);
  fn_1ef2_0075(local_300);
  g_20d5 = 2;
  return;
}


//// fn_0845_090f @ 1845:090f

void __cdecl16far fn_0845_090f(undefined2 param_1)

{
  fn_0845_1430(g_540e);
  fn_1ef2_0075(g_540e,param_1,0);
  g_20d5 = 0;
  return;
}


//// fn_0845_093a @ 1845:093a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far fn_0845_093a(void)

{
  fn_130a_028a();
  if ((g_4bf8 != -1) && (g_4c02 < g_384c)) {
    fn_130a_0605();
  }
  if (((_LAB_422c_4079_1 & 0x800) != 0) || ((g_7fd6 & 4) == 0)) {
    fn_0bbc_07ef();
  }
  if ((((_LAB_422c_4079_1 & 0x4000) != 0) && ((g_7fd6 & 4) == 0)) &&
     ((g_7fe1 == -1 || ((g_7fdf << 6 != g_7fe1 || (g_06d7 != 0)))))) {
    ovr_2cda_0052();
  }
  fn_154c_0136();
  fn_0845_11b7();
  return;
}


//// fn_0845_09a9 @ 1845:09a9

undefined2 __cdecl16far fn_0845_09a9(uint param_1)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  
  uVar2 = param_1 & 0x1f;
  if (uVar2 < 0x1a) {
    iVar1 = uVar2 + 0x41;
    uVar3 = 0x21e8;
  }
  else {
    iVar1 = uVar2 + 0x27;
    uVar3 = 0x21e2;
  }
  sprintf(0xab04,0x3e2d,uVar3,0x3e2d,iVar1,(int)param_1 >> 5);
  return 0xab04;
}


//// fn_0845_09f1 @ 1845:09f1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far fn_0845_09f1(uint param_1)

{
  undefined2 uVar1;
  undefined2 in_DX;
  undefined4 local_6;
  
  _LAB_422c_4079_1 = _LAB_422c_4079_1 | 0x200;
  if (*(byte *)((int)g_7fb2 +
                *(int *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 9 + g_8048 * 0x10) * 0xd + 2) !=
      param_1) {
    uVar1 = fn_0845_04ec(*(undefined4 *)((undefined2 *)&g_7d82 + param_1 * 2));
    local_6 = CONCAT22(in_DX,uVar1);
    fn_1e9f_0002(0,uVar1,in_DX);
    fn_0845_0631(local_6);
    g_ab1a = param_1;
  }
  return;
}


//// fn_0845_0a5b @ 1845:0a5b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far fn_0845_0a5b(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 in_DX;
  
  _LAB_422c_4079_1 = _LAB_422c_4079_1 & 0xfdff;
  if (*(byte *)((int)g_7fb2 +
                *(int *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 9 + g_8048 * 0x10) * 0xd + 2) !=
      g_ab1a) {
    uVar1 = fn_0845_0c08(g_8048);
    uVar1 = fn_0845_04ec(uVar1,in_DX);
    if (g_8048 == 0) {
      uVar2 = 0;
      uVar3 = 0;
    }
    else {
      uVar2 = 10;
      uVar3 = 10;
    }
    fn_1e9f_0002(uVar3,uVar2,uVar1,in_DX);
  }
  return;
}


//// fn_0845_0ac7 @ 1845:0ac7

undefined2 __cdecl16far fn_0845_0ac7(void)

{
  return g_8048;
}


//// fn_0845_0acf @ 1845:0acf

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far fn_0845_0acf(int param_1)

{
  undefined2 uVar1;
  undefined2 in_DX;
  undefined2 extraout_DX;
  undefined2 uVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 local_6;
  
  pcVar3 = (char *)s_Lib_error_29_3e2d_1842 + 3;
  if ((param_1 != 0) &&
     ((*(uint *)((int)g_7fb2 +
                 *(int *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 9 + param_1 * 0x10) * 0xd + 3) & 0x80) !=
      0)) {
    pcVar3 = (char *)s_File_error_16_24__3e2d_17b2 + 10;
    fn_07bc_047f(0xffff,param_1,0x400,0);
    if ((*(uint *)(param_1 * 0x10 + 0x1d0b) & 0x8000) != 0) {
      param_1 = 0;
    }
  }
  if ((param_1 == 0) || ((_LAB_422c_4079_1 & 0x200) != 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 10;
    if ((f_2803_0045 == '\0') || (g_81fd._1_1_ != '\0')) {
      uVar4 = fn_0845_06f8(pcVar3,*(undefined2 *)
                                    ((int)g_7fb2 +
                                    *(int *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 9 + param_1 * 0x10) *
                                    0xd));
      uVar4 = fn_0845_06f8(pcVar3,0x403e,uVar4);
      fn_0845_01c4(pcVar3,0,uVar4);
      in_DX = extraout_DX;
    }
  }
  g_8048 = param_1;
  uVar1 = fn_0845_0c08();
  uVar1 = fn_0845_04ec(uVar1,in_DX);
  local_6 = CONCAT22(in_DX,uVar1);
  fn_1e9f_0002(uVar2,uVar2,uVar1,in_DX);
  fn_0845_0631(local_6);
  return;
}


//// fn_0845_0bb6 @ 1845:0bb6

void __cdecl16far fn_0845_0bb6(uint param_1)

{
  ulong uVar1;
  
  uVar1 = g_384c + param_1;
  while (g_384c < uVar1) {
    fn_0845_093a();
  }
  return;
}


//// fn_0845_0be0 @ 1845:0be0

void __cdecl16far fn_0845_0be0(ulong param_1)

{
  while (g_384c < param_1) {
    fn_0845_093a();
  }
  return;
}


//// fn_0845_0bf6 @ 1845:0bf6

void __cdecl16far fn_0845_0bf6(void)

{
  fn_2309_000c();
  exit(0);
  return;
}


//// fn_0845_0c08 @ 1845:0c08

undefined2 __cdecl16far fn_0845_0c08(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = (int)g_7fb2 + *(int *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 9 + param_1 * 0x10) * 0xd
    ;
    if ((*(uint *)(iVar2 + 3) & 0x200) == 0) {
      uVar1 = (uint)*(byte *)(iVar2 + 2);
    }
    else {
      uVar1 = ((uint)*(byte *)(iVar2 + 2) + (*(uint *)(param_1 * 0x10 + 0x1d0b) & 0x1fff)) - 1;
    }
  }
  return ((undefined2 *)&g_7d82)[uVar1 * 2];
}


//// fn_0845_0c7e @ 1845:0c7e

int __cdecl16far fn_0845_0c7e(int param_1,uint param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = fn_09aa_0183(param_1,param_2);
  *param_4 = -1;
  iVar3 = 0;
  if (0 < param_3) {
    do {
      iVar2 = iVar1;
      if ((*(uint *)(param_1 * 10 + -0x7df9) & 0x8000) != 0) {
        *param_4 = param_1;
        return iVar3;
      }
      if ((*(byte *)(*(char *)(iVar2 * 10 + (param_2 ^ 2) + -0x7dfd) + 0x531e) & 7) != 0) {
        *param_4 = iVar2;
        return iVar3;
      }
      iVar1 = fn_09aa_0183(iVar2,param_2);
      iVar3 = iVar3 + 1;
      param_1 = iVar2;
    } while (iVar3 < param_3);
  }
  return iVar3;
}


//// fn_0845_0cf7 @ 1845:0cf7

undefined2 __cdecl16far fn_0845_0cf7(int param_1,uint param_2,byte param_3)

{
  undefined2 uVar1;
  int iVar2;
  
  if ((*(byte *)(param_1 * 10 + -0x7df4) & 0x10) == 0) {
    if (param_2 == 0xffff) {
      iVar2 = 0;
      do {
        if ((param_3 & *(byte *)(*(char *)(param_1 * 10 + iVar2 + -0x7dfd) + 0x531e)) != 0)
        goto LAB_1845_0d10;
        iVar2 = iVar2 + 1;
      } while (iVar2 < 4);
    }
    else if ((param_3 & *(byte *)(*(char *)(param_1 * 10 + (param_2 ^ 2) + -0x7dfd) + 0x531e)) != 0)
    goto LAB_1845_0d10;
    uVar1 = 0;
  }
  else {
LAB_1845_0d10:
    uVar1 = 1;
  }
  return uVar1;
}


//// fn_0845_0d5e @ 1845:0d5e

void __cdecl16far
fn_0845_0d5e(long param_1,uint param_2,int param_3,int param_4,int param_5,int param_6,
             code *param_7,long param_8,long param_9,undefined2 param_10,int param_11)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  undefined2 uVar5;
  int iVar6;
  uint extraout_DX;
  uint extraout_DX_00;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined2 uVar10;
  char *pcVar11;
  undefined4 uVar12;
  uint local_6;
  
  pcVar11 = (char *)s_Lib_error_29_3e2d_1842 + 3;
  bVar4 = false;
  uVar10 = (undefined2)((ulong)param_1 >> 0x10);
  iVar7 = (int)param_1;
  iVar1 = *(int *)(iVar7 + 8);
  iVar2 = *(int *)(iVar7 + 10);
  iVar8 = param_5;
  iVar9 = param_6;
  if (param_1 != 0) {
    if (param_5 < 0) {
      iVar8 = 0;
    }
    if (param_6 < 0) {
      iVar9 = 0;
    }
  }
  bVar3 = param_3 < (int)param_2;
  local_6 = param_2;
LAB_1845_0efe:
  do {
    if (bVar4) {
      if ((param_11 != 0) && ((param_1 != 0 || (param_7 != (code *)0x0)))) {
        uVar12 = 64000;
        uVar10 = fn_215f_001d();
        fn_2279_025b(uRam0004302a,uVar10,param_2,uVar12);
        fn_1ebc_0111(iVar8,iVar9,iVar8 + iVar1,iVar9 + iVar2);
        fn_1dbc_0004((char *)s_PageArraySize_is_negative__3e2d_2eba + 2,iVar8,iVar9,iVar8,iVar9,
                      iVar8 + iVar1,iVar9 + iVar2,2);
        fn_1ebc_01ec();
      }
      return;
    }
    g_3850 = (long)param_4;
    if ((param_1 != 0) || (param_7 != (code *)0x0)) {
      uVar12 = 64000;
      uVar5 = fn_215f_001d();
      pcVar11 = (char *)0x3279;
      fn_2279_025b(uRam0004302a,uVar5,param_2,uVar12);
    }
    if (param_7 != (code *)0x0) {
      (*(code *)param_7)();
      param_2 = extraout_DX;
    }
    if (param_1 == 0) {
      if (param_7 != (code *)0x0) goto LAB_1845_0e5a;
    }
    else {
      ovr_2dfd_002a(pcVar11,iVar7,uVar10,local_6 % *(uint *)(iVar7 + 2),param_5,param_6,0x50000002,
                    g_4bec,g_4bf0);
LAB_1845_0e5a:
      fn_1ebc_0111(iVar8,iVar9,iVar8 + iVar1,iVar9 + iVar2);
      fn_1dbc_0004((char *)s_PageArraySize_is_negative__3e2d_2eba + 2,iVar8,iVar9,iVar8,iVar9,iVar1
                    ,iVar2,2);
      pcVar11 = (char *)s_PageArraySize_is_negative__3e2d_2eba + 2;
      param_2 = extraout_DX_00;
      fn_1ebc_01ec();
    }
    do {
      if ((param_8 != 0) && (param_9 != 0)) {
        pcVar11 = (char *)0x3d1b;
        iVar6 = ovr_2d1b_003e(param_8,param_9);
        if ((iVar6 == 0) && (param_1 == 0)) {
          return;
        }
      }
    } while (g_3850 != 0);
  } while (param_1 == 0);
  if (bVar3) {
    local_6 = local_6 - 1;
    if (param_3 <= (int)local_6) goto LAB_1845_0efe;
  }
  else {
    local_6 = local_6 + 1;
    if ((int)local_6 < param_3) goto LAB_1845_0efe;
  }
  bVar4 = true;
  goto LAB_1845_0efe;
}


//// fn_0845_0f72 @ 1845:0f72

void __cdecl16far fn_0845_0f72(void)

{
  return;
}


//// fn_0845_0f77 @ 1845:0f77

void __cdecl16far fn_0845_0f77(void)

{
  return;
}


//// fn_0845_0f7c @ 1845:0f7c

void __cdecl16far fn_0845_0f7c(void)

{
  return;
}


//// fn_0845_0f81 @ 1845:0f81

void __cdecl16far fn_0845_0f81(void)

{
  return;
}


//// fn_0845_0f86 @ 1845:0f86

void __cdecl16far fn_0845_0f86(long param_1,long param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_c;
  undefined4 local_8;
  int local_4;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    fn_2279_025b(param_1,param_2,6);
    local_8._0_2_ = (byte *)param_1;
    local_8._2_2_ = (undefined2)((ulong)param_1 >> 0x10);
    local_8 = (byte *)CONCAT22(local_8._2_2_,(byte *)((int)(byte *)local_8 + 6));
    local_c._0_2_ = (char *)param_2;
    local_c._2_2_ = (undefined2)((ulong)param_2 >> 0x10);
    local_c = (char *)CONCAT22(local_c._2_2_,(char *)((int)(char *)local_c + 6));
    for (iVar3 = 2; iVar3 < 0x80; iVar3 = iVar3 + 1) {
      local_4 = 0;
      do {
        uVar2 = *local_8 & 0x3f;
        local_8 = (byte *)CONCAT22(local_8._2_2_,(byte *)local_8 + 1);
        if ((param_3 & 1 << ((byte)local_4 & 0x1f)) == 0) {
          cVar1 = -(char)((int)uVar2 >> 1);
        }
        else {
          cVar1 = (char)((int)(0x3f - uVar2) >> 1);
        }
        *local_c = (char)uVar2 + cVar1;
        local_c = (char *)CONCAT22(local_c._2_2_,(char *)local_c + 1);
        local_4 = local_4 + 1;
      } while (local_4 < 3);
    }
    fn_2279_025b(local_8,local_c,0x180);
  }
  return;
}


//// fn_0845_1036 @ 1845:1036

int __cdecl16far fn_0845_1036(void)

{
  return (int)(g_7fda & 0x30) >> 4;
}


//// fn_0845_1044 @ 1845:1044

undefined2 __cdecl16far fn_0845_1044(int param_1,int param_2)

{
  return (int)(((long)param_2 << 8) / (long)param_1);
}


//// fn_0845_105c @ 1845:105c

undefined2 __cdecl16far fn_0845_105c(int param_1,int param_2,ulong param_3,ulong param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_SS;
  undefined1 local_314 [768];
  undefined2 local_14;
  char local_12 [4];
  undefined4 local_e;
  undefined4 local_a;
  undefined4 local_6;
  
  local_6 = (byte *)CONCAT22(0x3e2d,(undefined1 *)&g_2fac + param_1 * 3);
  local_a = (char *)CONCAT22(0x3e2d,(undefined1 *)&g_2fac + param_2 * 3);
  local_e = (char *)CONCAT22(g_540e._2_2_,(char *)((int)g_540e + param_1 * 3));
  local_14 = 0;
  for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {
    if (param_3 < param_4) {
      iVar2 = ((int)*local_a & 0x3fU) - ((int)(char)*local_6 & 0x3fU);
      if (iVar2 != 0) {
        local_14 = 1;
      }
      cVar1 = (*local_6 & 0x3f) + (char)((((long)iVar2 << 8) / (long)param_4) * param_3 >> 8);
    }
    else {
      cVar1 = *local_a;
      *local_e = cVar1;
      local_14 = 0;
    }
    local_12[iVar3] = cVar1;
    local_6 = (byte *)CONCAT22(local_6._2_2_,(byte *)local_6 + 1);
    local_a = (char *)CONCAT22(local_a._2_2_,(char *)local_a + 1);
    local_e = (char *)CONCAT22(local_e._2_2_,(char *)local_e + 1);
  }
  memcpy(local_314);
  fn_1ef2_002f(local_314);
  return local_14;
}


//// fn_0845_114d @ 1845:114d

void __cdecl16far fn_0845_114d(int param_1,int param_2)

{
  undefined2 uVar1;
  
  if ((g_20f4 == param_1) || (param_1 == 0)) {
    g_20f6 = 1;
    g_4bc8 = g_384c;
  }
  if (param_2 != 0) {
    fn_130a_0784();
    if (f_2803_0044 == '\0') {
      fn_1ebc_00e7();
      uVar1 = fn_14b3_01fa();
      fn_1ebc_00fe(uVar1);
      fn_14b3_0122();
    }
    g_20f6 = 0;
    fn_0bbc_070e(0xb);
  }
  return;
}


//// fn_0845_11b7 @ 1845:11b7

int __cdecl16far fn_0845_11b7(void)

{
  int iVar1;
  
  if (g_20f6 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = fn_0845_105c(0xfc00c0,g_384c - g_4bc8,0x3c);
    if ((iVar1 == 0) && (f_2803_0044 == '\0')) {
      fn_14b3_01fa();
      fn_1ebc_00e7();
      fn_14b3_0122();
      fn_1ebc_00fe();
      fn_0bbc_070e(0xb);
      g_20f6 = 0;
    }
  }
  return iVar1;
}


//// fn_0845_122b @ 1845:122b

int __cdecl16far fn_0845_122b(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  iVar1 = 0;
  for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
    uVar3 = (undefined2)((ulong)param_1 >> 0x10);
    if ((*(int *)(param_2 * 0x1c + iVar2 * 2 + 0x12) <= *(int *)((int)param_1 + 0x3d)) &&
       (*(int *)(param_2 * 0x1c + iVar2 * 2 + 0x1e) < *(int *)((int)param_1 + 0x39))) {
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}


//// fn_0845_1280 @ 1845:1280

undefined2 __cdecl16far fn_0845_1280(int param_1,int param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  
  pcVar2 = (char *)s_Lib_error_29_3e2d_1842 + 3;
  if (*(int *)(param_1 * 0x82 + 0x366a) < *(int *)(param_2 * 0x1c + param_3 * 2 + 0x12)) {
    pcVar2 = (char *)0x254c;
    iVar1 = fn_154c_0057(0x4043,*(undefined2 *)
                                  ((int)(undefined2 *)&g_363a + param_1 * 0x82 + 1),1);
    if (iVar1 == 0) {
      return 1;
    }
    uVar3 = fn_0845_06f8(0x254c,0x4043,param_1 * 0x82 + 0x362f,(undefined1 *)&g_3803);
    uVar4 = 6;
  }
  else {
    if (*(int *)(param_2 * 0x1c + param_3 * 2 + 0x1e) < *(int *)(param_1 * 0x82 + 0x3666)) {
      return 0;
    }
    uVar3 = fn_0845_06f8((char *)s_Lib_error_29_3e2d_1842 + 3,0x4179,param_1 * 0x82 + 0x362f,
                          (undefined1 *)&g_3803);
    uVar4 = 2;
  }
  fn_0845_01c4(pcVar2,uVar4,uVar3);
  return 1;
}


//// fn_0845_1343 @ 1845:1343

void __cdecl16far
fn_0845_1343(undefined2 param_1,uint param_2,undefined2 param_3,undefined2 param_4,
             undefined2 param_5,undefined2 param_6)

{
  char *pcVar1;
  uint uVar2;
  undefined1 local_f8 [14];
  uint local_ea;
  undefined2 local_e8;
  undefined2 local_e6;
  undefined2 local_e4;
  undefined2 local_e2;
  undefined2 local_e0;
  int local_de;
  
  if (g_4bf6 == 0) {
    fn_0f28_032c(local_f8);
    fn_0f28_035f(local_f8);
    local_ea = param_2;
    local_e8 = param_3;
    local_e6 = param_4;
    local_e4 = param_5;
    local_e2 = param_6;
    local_e0 = param_1;
    local_de = (int)g_7fd8;
    uVar2 = fn_2315_0018(*(undefined2 *)((int)local_f8._0_4_ + -2));
    param_2 = param_2 & uVar2;
    pcVar1 = (char *)0x3315;
    while (param_2 != 0) {
      param_2 = fn_0f28_04a0(pcVar1,local_f8);
      pcVar1 = (char *)s_Damage_inflicted_was__d_3e2d_1f22 + 6;
    }
  }
  fn_0845_046c(param_1);
  return;
}


//// fn_0845_13d6 @ 1845:13d6

void __cdecl16far fn_0845_13d6(undefined2 param_1,undefined2 param_2)

{
  fn_0845_1343(param_1,param_2,0xffff,0);
  return;
}


//// fn_0845_13f1 @ 1845:13f1

int __cdecl16far fn_0845_13f1(int param_1,int param_2,int param_3,int param_4)

{
  return (param_2 * 0x10 + param_1) - (param_4 * 0x10 + param_3);
}


//// fn_0845_1430 @ 1845:1430

void __cdecl16far fn_0845_1430(int param_1,undefined2 param_2)

{
  fn_2279_025b(0x31ec,0x3e2d,param_1 + 0x240,param_2,0xc);
  return;
}


//// fn_0845_144e @ 1845:144e

void __cdecl16far fn_0845_144e(long param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 in_DX;
  
  if (param_1 != 0) {
    iVar1 = fn_2365_063f(param_1);
    if ((iVar1 != 0) || (iVar1 = fn_19ba_0086(param_1), iVar1 != 0)) {
      uVar2 = fn_15a7_030c(g_4ea0,param_1);
      fn_15a7_0210(g_4ea0,uVar2,in_DX);
    }
    fn_203b_0203(param_1);
    return;
  }
  return;
}


//// fn_0845_14a6 @ 1845:14a6

void __cdecl16far fn_0845_14a6(undefined4 param_1)

{
  int iVar1;
  undefined2 in_DX;
  
  fn_2309_000c();
  fn_0845_1536();
  iVar1 = ovr_2d46_002f(0x21ed,0x3e2d,(int)g_20db);
  sprintf(0xad99,0x3e2d,(char *)s__s__s_3e2d_21ef,0x3e2d,(undefined1 *)&g_ae59,0x3e2d,
                param_1,iVar1,in_DX);
  if (g_ae57 != 0) {
    fn_2148_002c();
    fn_2148_014d((undefined1 *)&g_aeaa,0x3e2d);
    fn_2148_014d(iVar1 + 2,in_DX);
  }
  execl((char *)s_LANDS_EXE_3e2d_21f5,0x3e2d,(char *)s_LANDS_EXE_3e2d_21ff,0x3e2d,0xad99,
                0x3e2d,0);
  return;
}


//// fn_0845_1531 @ 1845:1531

void __cdecl16far fn_0845_1531(void)

{
  return;
}


//// fn_0845_1536 @ 1845:1536

void __cdecl16far fn_0845_1536(void)

{
  g_ab0b = 2;
  g_ab10 = 0x1900;
  g_ab0d = 0;
  int86(0x10,0xab0a,0x3e2d,0xab0a,0x3e2d);
  return;
}


//// fn_0845_155d @ 1845:155d

int __cdecl16far fn_0845_155d(int param_1)

{
  uint uVar1;
  uint *puVar2;
  undefined2 in_DX;
  uint uVar3;
  int iVar4;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar4 = 0;
  uVar1 = *(uint *)(param_1 * 10 + -0x7df9);
  while (uVar3 = uVar1, uVar3 != 0) {
    puVar2 = (uint *)fn_080e_000b();
    local_c = (uint *)CONCAT22(in_DX,puVar2);
    uVar1 = *local_c;
    if ((uVar3 & 0x8000) != 0) {
      local_8 = CONCAT22((undefined1 *)&g_3803,(uVar3 & 0x7fff) * 0x2e + 0x15fa);
      iVar4 = iVar4 + 1;
      fn_0d6c_0995();
      fn_0845_046c();
      fn_0d6c_0742(local_8,0);
    }
  }
  return iVar4;
}


//// fn_0845_15d9 @ 1845:15d9

void __cdecl16far fn_0845_15d9(undefined2 param_1)

{
  if (((((g_7fd6 & 1) == 0) && (iRam00043036 == 0)) && (g_20d3 != 0)) &&
     (g_7fc4 != 0)) {
    ovr_2cda_0061(param_1);
  }
  return;
}


//// fn_0845_1605 @ 1845:1605

void __cdecl16far fn_0845_1605(void)

{
  undefined2 uVar1;
  
  if (g_81fd._1_1_ == '\0') {
    fn_1e9a_000b(4,0xb,0x7c,0x1c,9);
    uVar1 = 0x12;
  }
  else {
    fn_1e9a_000b(4,0xb,0x7c,0x1c,0x2d);
    uVar1 = 0x36;
  }
  fn_1e9a_000b(5,0x55,0x7b,0xe9,uVar1);
  return;
}

