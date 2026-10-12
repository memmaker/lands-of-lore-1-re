//// fn_070c_000a @ 170c:000a

void fn_070c_000a(undefined2 param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if ((param_2 & 0x8000) == 0) {
    uVar1 = *(undefined4 *)((int)(undefined4 *)&g_363e + param_2 * 0x82 + 2);
                    /* WARNING: Subroutine does not return */
    fn_1aff_0420(*(int *)(param_2 * 0x82 + 0x3664) + *(int *)(param_2 * 0x82 + 0x3679),
                  *(undefined2 *)((int)uVar1 + 4));
  }
  uVar1 = *(undefined4 *)((param_2 & 0x7fff) * 0x2e + 0x161b);
  uVar2 = *(undefined4 *)((param_2 & 0x7fff) * 0x2e + 0x161b);
                    /* WARNING: Subroutine does not return */
  fn_1aff_0420(*(undefined2 *)((int)uVar1 + 0x38),*(undefined2 *)((int)uVar2 + 6));
}


//// fn_070c_0060 @ 170c:0060

void fn_070c_0060(void)

{
  undefined2 unaff_DS;
  
  *(undefined1 *)0xb7ff = 0;
                    /* WARNING: Subroutine does not return */
  fn_1aff_0420();
}


//// thunk_FUN_170c_008f @ 170c:0065

void thunk_FUN_170c_008f(void)

{
                    /* WARNING: Subroutine does not return */
  fn_1aff_0420();
}


//// fn_070c_008f @ 170c:008f

void fn_070c_008f(void)

{
                    /* WARNING: Subroutine does not return */
  fn_1aff_0420();
}


//// fn_070c_009f @ 170c:009f

void __cdecl16far fn_070c_009f(int param_1)

{
  int iVar1;
  
  if (g_7fe3 != param_1) {
    iVar1 = (int)g_7fe3;
    g_7fe3 = (char)param_1;
    fn_0a21_022b(iVar1);
  }
  fn_0a21_022b(param_1);
  return;
}


//// fn_070c_00cf @ 170c:00cf

void fn_070c_00cf(undefined2 param_1,uint param_2,int param_3,long param_4)

{
  long *plVar1;
  int iVar2;
  
  if (((param_2 & 0x8000) == 0) &&
     ((*(uint *)((int)(undefined4 *)&g_362a + param_2 * 0x82 + 3) & 8) == 0)) {
    plVar1 = (long *)(param_2 * 0x82 + param_3 * 4 + 0x3699);
    *plVar1 = *plVar1 + param_4;
    do {
      iVar2 = ovr_2cf4_0025(param_2,param_3);
    } while (iVar2 != 0);
  }
  return;
}


//// fn_070c_00e0 @ 170c:00e0

void fn_070c_00e0(void)

{
  long *plVar1;
  undefined2 in_AX;
  undefined2 uVar2;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  
  *(byte *)(unaff_DI + 0x43) = *(byte *)(unaff_DI + 0x43) ^ 0x8b;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + -0x48;
  if ((*(uint *)((int)(undefined4 *)&g_362a + in_BX + 3) & 8) == 0) {
    plVar1 = (long *)(unaff_SI * 0x82 + (unaff_DI + *(int *)(in_BX + unaff_SI)) * 4 + 0x3699);
    *plVar1 = *plVar1 + *(long *)(unaff_BP + 10);
    do {
      uVar2 = ovr_2cf4_0025();
      *(undefined2 *)(unaff_BP + -2) = uVar2;
    } while (*(int *)(unaff_BP + -2) != 0);
  }
  return;
}


//// fn_070c_00e5 @ 170c:00e5

void __cdecl16far fn_070c_00e5(void)

{
  long *plVar1;
  undefined2 uVar2;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  
  if ((*(uint *)((int)(undefined4 *)&g_362a + in_BX * 0x82 + 3) & 8) == 0) {
    plVar1 = (long *)(unaff_SI * 0x82 + unaff_DI * 4 + 0x3699);
    *plVar1 = *plVar1 + *(long *)(unaff_BP + 10);
    do {
      uVar2 = ovr_2cf4_0025();
      *(undefined2 *)(unaff_BP + -2) = uVar2;
    } while (*(int *)(unaff_BP + -2) != 0);
  }
  return;
}


//// fn_070c_012a @ 170c:012a

int __cdecl16far fn_070c_012a(uint param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *local_6;
  
  local_6 = (undefined4 *)fn_070c_01b6((char *)s_File_error_6_14__3e2d_1702 + 10,param_1);
  iVar1 = fn_1aff_0434(param_2,*(undefined2 *)((int)*local_6 + 8));
  if ((param_1 & 0x8000) == 0) {
    iVar2 = fn_0845_1036();
                    /* WARNING: Subroutine does not return */
    fn_1aff_0420(iVar1,*(undefined2 *)(iVar2 * 2 + 0x32));
  }
  if (*(char *)(param_1 * 0x82 + 0x3694) < '\b') {
    if (*(char *)(param_1 * 0x82 + 0x3694) < '\x04') {
      return iVar1;
    }
    iVar2 = iVar1 >> 2;
  }
  else {
    iVar2 = iVar1 >> 1;
  }
  return iVar1 - iVar2;
}


//// fn_070c_016a @ 170c:016a

void fn_070c_016a(void)

{
                    /* WARNING: Subroutine does not return */
  fn_1aff_0420();
}


//// fn_070c_01b6 @ 170c:01b6

undefined4 fn_070c_01b6(undefined2 param_1,uint param_2)

{
  undefined2 uVar1;
  int iVar2;
  
  if ((param_2 & 0x8000) != 0) {
    iVar2 = *(int *)((param_2 & 0x7fff) * 0x2e + 0x161b) + 0x14;
    uVar1 = fn_070c_01f9();
    return CONCAT22(iVar2,uVar1);
  }
  return CONCAT22((undefined1 *)&g_3803,param_2 * 0x82 + 0x3640);
}


//// fn_070c_01f9 @ 170c:01f9

undefined2 __cdecl16far fn_070c_01f9(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  return *(undefined2 *)(unaff_BP + -4);
}


//// fn_070c_0201 @ 170c:0201

void __cdecl16far fn_070c_0201(int param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  
  iVar1 = ovr_2d74_0025();
  *param_2 = (uint)(byte)((char *)s_EMPTY_3e2d_1f0f + 3)[iVar1 * 4 + param_1];
  *param_3 = 0x80;
  fn_1aff_03b4(param_2,(uint *)param_3,param_3._2_2_,g_7fdf);
  *param_2 = *param_2 | g_7fd2 & 0xff00;
  *param_3 = *param_3 | g_7fd4 & 0xff00;
  return;
}


//// fn_070c_0253 @ 170c:0253

void fn_070c_0253(undefined2 param_1,undefined2 param_2)

{
  undefined2 uVar1;
  
  uVar1 = fn_09aa_0183(g_7fd0,g_7fdf);
  fn_070c_027a((char *)s_This_cannot_be_run_under_Windows_3e2d_198b + 0x1f,uVar1,param_2,uVar1);
  return;
}


//// fn_070c_0274 @ 170c:0274

void __cdecl16far fn_070c_0274(void)

{
  char *pcVar1;
  char in_AL;
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_SS;
  
  pcVar1 = (char *)(unaff_BP + unaff_DI + 0x4c4);
  *pcVar1 = *pcVar1 + in_AL;
  return;
}


//// fn_070c_027a @ 170c:027a

uint fn_070c_027a(undefined2 param_1,int param_2,undefined2 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iStack_a;
  int iStack_8;
  undefined4 uStack_6;
  
  fn_070c_0201(param_3,&iStack_8);
  iVar4 = 0x7fff;
  uVar5 = 0xffff;
  uVar3 = *(uint *)(param_2 * 10 + -0x7df9);
  while ((uVar3 & 0x8000) != 0) {
    iVar1 = (uVar3 & 0x7fff) * 0x2e;
    uStack_6 = (uint *)CONCAT22((undefined1 *)&g_3803,(uint *)(iVar1 + 0x15fa));
    if (*(char *)(iVar1 + 0x160e) < '\r') {
      if (iStack_8 < *(int *)(iVar1 + 0x1601)) {
        iVar2 = -(iStack_8 - *(int *)(iVar1 + 0x1601));
      }
      else {
        iVar2 = iStack_8 - *(int *)(iVar1 + 0x1601);
      }
      if (iStack_a < *(int *)(iVar1 + 0x1603)) {
        iVar1 = -(iStack_a - *(int *)(iVar1 + 0x1603));
      }
      else {
        iVar1 = iStack_a - *(int *)(iVar1 + 0x1603);
      }
      if (iVar2 + iVar1 < iVar4) {
        iVar4 = iVar2 + iVar1;
        uVar5 = uVar3;
      }
    }
    uVar3 = *uStack_6;
  }
  return uVar5;
}


//// fn_070c_027e @ 170c:027e

uint __cdecl16far fn_070c_027e(void)

{
  uint uVar1;
  undefined2 in_DX;
  int iVar2;
  int iVar3;
  int unaff_BP;
  int iVar4;
  uint uVar5;
  undefined2 uVar6;
  undefined2 unaff_SS;
  
  in(in_DX);
  *(byte *)(unaff_BP + 0x57) = *(byte *)(unaff_BP + 0x57) | (byte)in_DX;
  fn_070c_0201(*(undefined2 *)(unaff_BP + 8),unaff_BP + -6);
  iVar4 = 0x7fff;
  uVar5 = 0xffff;
  uVar1 = *(uint *)(*(int *)(unaff_BP + 6) * 10 + -0x7df9);
  while ((uVar1 & 0x8000) != 0) {
    *(undefined2 *)(unaff_BP + -2) = (undefined1 *)&g_3803;
    *(int *)(unaff_BP + -4) = (uVar1 & 0x7fff) * 0x2e + 0x15fa;
    uVar6 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
    iVar2 = (int)*(undefined4 *)(unaff_BP + -4);
    if (*(char *)(iVar2 + 0x14) < '\r') {
      if (*(int *)(unaff_BP + -6) < *(int *)(iVar2 + 7)) {
        iVar2 = -(*(int *)(unaff_BP + -6) - *(int *)(iVar2 + 7));
      }
      else {
        iVar2 = *(int *)(unaff_BP + -6) - *(int *)((int)*(undefined4 *)(unaff_BP + -4) + 7);
      }
      uVar6 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
      iVar3 = (int)*(undefined4 *)(unaff_BP + -4);
      if (*(int *)(unaff_BP + -8) < *(int *)(iVar3 + 9)) {
        iVar3 = -(*(int *)(unaff_BP + -8) - *(int *)(iVar3 + 9));
      }
      else {
        iVar3 = *(int *)(unaff_BP + -8) - *(int *)((int)*(undefined4 *)(unaff_BP + -4) + 9);
      }
      if (iVar2 + iVar3 < iVar4) {
        iVar4 = iVar2 + iVar3;
        uVar5 = uVar1;
      }
    }
    uVar1 = *(uint *)*(undefined4 *)(unaff_BP + -4);
  }
  return uVar5;
}


//// fn_070c_0308 @ 170c:0308

uint __cdecl16far fn_070c_0308(void)

{
  uint in_CX;
  int iVar1;
  int iVar2;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  uint unaff_DI;
  undefined2 uVar3;
  undefined2 unaff_SS;
  
  do {
    if (in_BX < unaff_SI) {
      unaff_SI = in_BX;
      unaff_DI = in_CX;
    }
    do {
      in_CX = *(uint *)*(undefined4 *)(unaff_BP + -4);
      if ((in_CX & 0x8000) == 0) {
        return unaff_DI;
      }
      *(undefined2 *)(unaff_BP + -2) = (undefined1 *)&g_3803;
      *(int *)(unaff_BP + -4) = (in_CX & 0x7fff) * 0x2e + 0x15fa;
      uVar3 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
      iVar1 = (int)*(undefined4 *)(unaff_BP + -4);
    } while ('\f' < *(char *)(iVar1 + 0x14));
    if (*(int *)(unaff_BP + -6) < *(int *)(iVar1 + 7)) {
      iVar1 = -(*(int *)(unaff_BP + -6) - *(int *)(iVar1 + 7));
    }
    else {
      iVar1 = *(int *)(unaff_BP + -6) - *(int *)((int)*(undefined4 *)(unaff_BP + -4) + 7);
    }
    uVar3 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
    iVar2 = (int)*(undefined4 *)(unaff_BP + -4);
    if (*(int *)(unaff_BP + -8) < *(int *)(iVar2 + 9)) {
      iVar2 = -(*(int *)(unaff_BP + -8) - *(int *)(iVar2 + 9));
    }
    else {
      iVar2 = *(int *)(unaff_BP + -8) - *(int *)((int)*(undefined4 *)(unaff_BP + -4) + 9);
    }
    in_BX = iVar1 + iVar2;
  } while( true );
}


//// fn_070c_0322 @ 170c:0322

uint fn_070c_0322(undefined2 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined2 uStack_a;
  undefined2 local_8;
  undefined2 uStack_6;
  
  local_8 = 0x7fff;
  uStack_a = 0xffff;
  uStack_6 = 0x15fa;
  uVar3 = 0;
  do {
    if (*(char *)(uStack_6 + 0x14) < '\r') {
      if (param_2 < *(int *)(uStack_6 + 7)) {
        iVar1 = -(param_2 - *(int *)(uStack_6 + 7));
      }
      else {
        iVar1 = param_2 - *(int *)(uStack_6 + 7);
      }
      if (param_3 < *(int *)(uStack_6 + 9)) {
        iVar2 = -(param_3 - *(int *)(uStack_6 + 9));
      }
      else {
        iVar2 = param_3 - *(int *)(uStack_6 + 9);
      }
      if (iVar1 + iVar2 < local_8) {
        uStack_a = uVar3 | 0x8000;
        local_8 = iVar1 + iVar2;
      }
    }
    uVar3 = uVar3 + 1;
    uStack_6 = uStack_6 + 0x2e;
  } while ((int)uVar3 < 0x1e);
  return uStack_a;
}


//// fn_070c_0335 @ 170c:0335

undefined2 __cdecl16far fn_070c_0335(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 uVar4;
  undefined2 unaff_SS;
  
  *(undefined2 *)(unaff_BP + -8) = 0xffff;
  *(undefined2 *)(unaff_BP + -2) = (undefined1 *)&g_3803;
  *(undefined2 *)(unaff_BP + -4) = 0x15fa;
  uVar1 = 0;
  do {
    if (*(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0x14) < '\r') {
      uVar4 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
      iVar2 = (int)*(undefined4 *)(unaff_BP + -4);
      if (unaff_SI < *(int *)(iVar2 + 7)) {
        iVar2 = -(unaff_SI - *(int *)(iVar2 + 7));
      }
      else {
        iVar2 = unaff_SI - *(int *)((int)*(undefined4 *)(unaff_BP + -4) + 7);
      }
      uVar4 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
      iVar3 = (int)*(undefined4 *)(unaff_BP + -4);
      if (unaff_DI < *(int *)(iVar3 + 9)) {
        iVar3 = -(unaff_DI - *(int *)(iVar3 + 9));
      }
      else {
        iVar3 = unaff_DI - *(int *)((int)*(undefined4 *)(unaff_BP + -4) + 9);
      }
      if (iVar2 + iVar3 < *(int *)(unaff_BP + -6)) {
        *(int *)(unaff_BP + -6) = iVar2 + iVar3;
        *(uint *)(unaff_BP + -8) = uVar1 | 0x8000;
      }
    }
    uVar1 = uVar1 + 1;
    *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) + 0x2e;
  } while ((int)uVar1 < 0x1e);
  return *(undefined2 *)(unaff_BP + -8);
}


//// fn_070c_0365 @ 170c:0365

undefined2 __cdecl16far fn_070c_0365(void)

{
  int iVar1;
  uint in_CX;
  int iVar2;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 uVar3;
  undefined2 unaff_SS;
  
  do {
    iVar1 = unaff_SI - *(int *)((int)*(undefined4 *)(unaff_BP + -4) + 7);
    while( true ) {
      uVar3 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
      iVar2 = (int)*(undefined4 *)(unaff_BP + -4);
      if (unaff_DI < *(int *)(iVar2 + 9)) {
        iVar2 = -(unaff_DI - *(int *)(iVar2 + 9));
      }
      else {
        iVar2 = unaff_DI - *(int *)((int)*(undefined4 *)(unaff_BP + -4) + 9);
      }
      if (iVar1 + iVar2 < *(int *)(unaff_BP + -6)) {
        *(int *)(unaff_BP + -6) = iVar1 + iVar2;
        *(uint *)(unaff_BP + -8) = in_CX | 0x8000;
      }
      do {
        in_CX = in_CX + 1;
        *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) + 0x2e;
        if (0x1d < (int)in_CX) {
          return *(undefined2 *)(unaff_BP + -8);
        }
      } while ('\f' < *(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0x14));
      uVar3 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
      iVar1 = (int)*(undefined4 *)(unaff_BP + -4);
      if (*(int *)(iVar1 + 7) <= unaff_SI) break;
      iVar1 = -(unaff_SI - *(int *)(iVar1 + 7));
    }
  } while( true );
}


//// fn_070c_03b1 @ 170c:03b1

int __cdecl16far fn_070c_03b1(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iStack_a;
  int iStack_8;
  int local_6;
  int local_4;
  
  local_4 = 0x7fff;
  local_6 = -1;
  iVar3 = 0;
  do {
    if (((*(uint *)((int)(undefined4 *)&g_362a + iVar3 * 0x82 + 3) & 1) != 0) &&
       (0 < *(int *)(iVar3 * 0x82 + 0x3666))) {
      fn_070c_0201(iVar3,&iStack_8);
      if (iStack_8 < param_1) {
        iVar1 = -(iStack_8 - param_1);
      }
      else {
        iVar1 = iStack_8 - param_1;
      }
      if (iStack_a < param_2) {
        iVar2 = -(iStack_a - param_2);
      }
      else {
        iVar2 = iStack_a - param_2;
      }
      if (iVar1 + iVar2 < local_4) {
        local_6 = iVar3;
        local_4 = iVar1 + iVar2;
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  return local_6;
}


//// fn_070c_03ee @ 170c:03ee

undefined2 fn_070c_03ee(void)

{
  int iVar1;
  int iVar2;
  int unaff_BP;
  int unaff_SI;
  int iVar3;
  int unaff_DI;
  undefined2 unaff_SS;
  
  iVar3 = unaff_SI + -1;
  do {
    fn_070c_0201(iVar3,unaff_BP + -6);
    if (*(int *)(unaff_BP + -6) < unaff_DI) {
      iVar1 = -(*(int *)(unaff_BP + -6) - unaff_DI);
    }
    else {
      iVar1 = *(int *)(unaff_BP + -6) - unaff_DI;
    }
    if (*(int *)(unaff_BP + -8) < *(int *)(unaff_BP + 8)) {
      iVar2 = -(*(int *)(unaff_BP + -8) - *(int *)(unaff_BP + 8));
    }
    else {
      iVar2 = *(int *)(unaff_BP + -8) - *(int *)(unaff_BP + 8);
    }
    if (iVar1 + iVar2 < *(int *)(unaff_BP + -2)) {
      *(int *)(unaff_BP + -2) = iVar1 + iVar2;
      *(int *)(unaff_BP + -4) = iVar3;
    }
    do {
      iVar3 = iVar3 + 1;
      if (3 < iVar3) {
        return *(undefined2 *)(unaff_BP + -4);
      }
    } while (((*(uint *)((int)(undefined4 *)&g_362a + iVar3 * 0x82 + 3) & 1) == 0) ||
            (*(int *)(iVar3 * 0x82 + 0x3666) < 1));
  } while( true );
}


//// fn_070c_03f3 @ 170c:03f3

undefined2 __cdecl16far fn_070c_03f3(void)

{
  int iVar1;
  int iVar2;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  
  do {
    fn_070c_0201(unaff_SI,unaff_BP + -6);
    if (*(int *)(unaff_BP + -6) < unaff_DI) {
      iVar1 = -(*(int *)(unaff_BP + -6) - unaff_DI);
    }
    else {
      iVar1 = *(int *)(unaff_BP + -6) - unaff_DI;
    }
    if (*(int *)(unaff_BP + -8) < *(int *)(unaff_BP + 8)) {
      iVar2 = -(*(int *)(unaff_BP + -8) - *(int *)(unaff_BP + 8));
    }
    else {
      iVar2 = *(int *)(unaff_BP + -8) - *(int *)(unaff_BP + 8);
    }
    if (iVar1 + iVar2 < *(int *)(unaff_BP + -2)) {
      *(int *)(unaff_BP + -2) = iVar1 + iVar2;
      *(int *)(unaff_BP + -4) = unaff_SI;
    }
    do {
      unaff_SI = unaff_SI + 1;
      if (3 < unaff_SI) {
        return *(undefined2 *)(unaff_BP + -4);
      }
    } while (((*(uint *)((int)(undefined4 *)&g_362a + unaff_SI * 0x82 + 3) & 1) == 0) ||
            (*(int *)(unaff_SI * 0x82 + 0x3666) < 1));
  } while( true );
}


//// fn_070c_044a @ 170c:044a

undefined2 fn_070c_044a(undefined2 param_1,uint param_2,uint param_3,int param_4)

{
  uint *puVar1;
  char cVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  undefined4 local_a;
  
  if (param_3 == 0xffff) {
    uVar4 = fn_070c_05f4();
    return uVar4;
  }
  if (param_2 == 0xffff) {
    uVar4 = 1;
  }
  else {
    if (((param_3 & 0x8000) != 0) && ('\f' < *(char *)((param_3 & 0x7fff) * 0x2e + 0x160e))) {
      uVar4 = fn_070c_05f4();
      return uVar4;
    }
    if ((param_2 & 0x8000) == 0) {
      if (param_4 == 1) {
        cVar2 = *(char *)(param_2 * 0x82 + 0x3694);
        iVar5 = *(char *)(param_2 * 0x82 + 0x3697) * 3;
      }
      else {
        cVar2 = *(char *)(param_2 * 0x82 + param_4 + 0x3693);
        iVar5 = (int)*(char *)(param_2 * 0x82 + param_4 + 0x3696);
      }
      iVar5 = cVar2 + iVar5;
    }
    else {
      uVar3 = *(undefined4 *)((param_2 & 0x7fff) * 0x2e + 0x161b);
      iVar5 = (int)*(char *)((int)uVar3 + 0x3d);
    }
    if ((param_3 & 0x8000) == 0) {
      local_a = (undefined4 *)
                CONCAT22((undefined1 *)&g_3803,
                         (undefined4 *)((int)(undefined4 *)&g_363e + param_3 * 0x82 + 2));
    }
    else {
      iVar6 = (param_3 & 0x7fff) * 0x2e;
      local_a = (undefined4 *)
                CONCAT22(*(undefined2 *)(iVar6 + 0x161d),
                         (undefined4 *)(*(int *)(iVar6 + 0x161b) + 0x14));
      puVar1 = (uint *)((param_3 & 0x7fff) * 0x2e + 0x1613);
      *puVar1 = *puVar1 | 0x10;
    }
    iVar6 = fn_0845_0636(0x640001);
    if (iVar6 < 100 - iVar5) {
      iVar5 = fn_0845_1036();
                    /* WARNING: Subroutine does not return */
      fn_1aff_0420(*(undefined2 *)((int)*local_a + 6),*(undefined2 *)(iVar5 * 2 + 0x3e));
    }
    uVar4 = 2;
  }
  return uVar4;
}


//// fn_070c_0468 @ 170c:0468

undefined2 __cdecl16far fn_070c_0468(void)

{
  return 1;
}


//// fn_070c_05e0 @ 170c:05e0

undefined2 fn_070c_05e0(void)

{
  undefined2 in_AX;
  undefined2 uVar1;
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_SS;
  
  *(undefined2 *)(unaff_BP + -0xc) =
       CONCAT11((char)((uint)in_AX >> 8),((char)in_AX + -1) - *(char *)(unaff_BP + unaff_DI + 0x4c4)
               );
  if (*(int *)(unaff_BP + -0xc) <= *(int *)(unaff_BP + -10)) {
    uVar1 = fn_070c_0468();
    return uVar1;
  }
  return 0;
}


//// fn_070c_05f4 @ 170c:05f4

undefined2 __cdecl16far fn_070c_05f4(void)

{
  return 0;
}


//// fn_070c_05fa @ 170c:05fa

void __cdecl16far fn_070c_05fa(undefined4 param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  iVar3 = (int)param_1;
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  fn_0d6c_0995(iVar3,uVar4,0xe);
  fn_0d6c_0034(iVar3,uVar4);
  fn_0845_046c(*(undefined2 *)(iVar3 + 5));
  iVar2 = ovr_2d1b_005c(*(undefined2 *)(iVar3 + 5));
  if ((iVar2 != 0) && ((*(uint *)((int)*(undefined4 *)(iVar3 + 0x21) + 0x3e) & 0x1000) == 0)) {
    pbVar1 = (byte *)(*(int *)(iVar3 + 5) * 10 + -0x7df4);
    *pbVar1 = *pbVar1 | 0x80;
  }
  fn_0d6c_0742(iVar3,uVar4,0,0);
  return;
}


//// fn_070c_0664 @ 170c:0664

void __cdecl16far fn_070c_0664(int param_1,undefined2 param_2)

{
  uint *puVar1;
  undefined4 local_6;
  
  puVar1 = (uint *)((int)(undefined4 *)&g_362a + param_1 * 0x82 + 3);
  local_6 = (uint *)CONCAT22((undefined1 *)&g_3803,puVar1);
  *(undefined2 *)(param_1 * 0x82 + 0x3666) = 0;
  *local_6 = *local_6 | 8;
  fn_0bbc_0365(puVar1,(undefined1 *)&g_3803,0x50001);
  g_20d1 = param_2;
  return;
}


//// fn_070c_06a3 @ 170c:06a3

void fn_070c_06a3(undefined2 param_1,int param_2,undefined2 param_3,undefined2 param_4)

{
  undefined2 uVar1;
  undefined4 *local_6;
  
  if (param_2 == -1) {
    uVar1 = 0x100;
  }
  else {
    local_6 = (undefined4 *)fn_070c_01b6((char *)s_File_error_6_14__3e2d_1702 + 10,param_2);
    uVar1 = *(undefined2 *)((int)*local_6 + 2);
  }
  fn_070c_01b6((char *)s_File_error_6_14__3e2d_1702 + 10,param_3);
                    /* WARNING: Subroutine does not return */
  fn_1aff_0420(param_4,uVar1);
}


//// fn_070c_06e0 @ 170c:06e0

void fn_070c_06e0(void)

{
                    /* WARNING: Subroutine does not return */
  fn_1aff_0420();
}


//// fn_070c_06e5 @ 170c:06e5

int __cdecl16far fn_070c_06e5(void)

{
  int in_AX;
  int iVar1;
  int unaff_BP;
  uint unaff_DI;
  undefined2 unaff_SS;
  
  if (in_AX == 0) {
    iVar1 = 0;
  }
  else {
    if ((unaff_DI & 0x8000) == 0) {
                    /* WARNING: Subroutine does not return */
      fn_1aff_0420();
    }
    iVar1 = fn_1aff_03fd();
    if ((*(int *)(unaff_BP + 0xe) != 2) && (iVar1 != 0)) {
      fn_070c_000a();
      iVar1 = fn_1aff_03fd();
      if (iVar1 < 2) {
        iVar1 = 2;
      }
    }
    if (iVar1 == 1) {
      iVar1 = 2;
    }
  }
  return iVar1;
}


//// fn_070c_0793 @ 170c:0793

int fn_070c_0793(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int local_8;
  
  uVar3 = fn_070c_01b6((char *)s_File_error_6_14__3e2d_1702 + 10,param_2);
  local_8 = 0;
  for (iVar2 = 0; iVar2 < 8; iVar2 = iVar2 + 1) {
    iVar1 = fn_070c_06a3((char *)s_File_error_6_14__3e2d_1702 + 10,param_2,param_3,
                          *(undefined2 *)((int)uVar3 + iVar2 * 2 + 4),iVar2,param_4);
    local_8 = local_8 + iVar1;
  }
  return local_8;
}


//// fn_070c_07e0 @ 170c:07e0

void __cdecl16far fn_070c_07e0(void)

{
  return;
}


//// fn_070c_07e3 @ 170c:07e3

void __cdecl16far fn_070c_07e3(undefined2 param_1)

{
  fn_0845_0636(2,param_1);
  return;
}


//// fn_070c_07f5 @ 170c:07f5

uint __cdecl16far
fn_070c_07f5(uint param_1,uint param_2,uint param_3,int param_4,undefined2 param_5)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined2 uVar5;
  char *pcVar6;
  uint *puVar7;
  int local_6;
  undefined1 *puStack_4;
  
  pcVar6 = (char *)s_File_error_6_14__3e2d_1702 + 10;
  local_6 = 0;
  puStack_4 = (undefined1 *)0x0;
  puVar7 = (uint *)0x0;
  if ((param_1 & 0x8000) == 0) {
    puVar7 = (uint *)CONCAT22((undefined1 *)&g_3803,
                              (uint *)((int)(undefined4 *)&g_362a + param_1 * 0x82 + 3));
    if (((*puVar7 & 1) != 0) && ((*puVar7 & 8) == 0)) {
      if ((*puVar7 & 0x1000) == 0) {
        fn_067a_0401((int)*(char *)((int)(undefined4 *)&g_363e + param_1 * 0x82 + 1),0);
      }
      fn_0a21_0674(param_1,6,4,0);
      pcVar6 = (char *)s_Lib_error_29_3e2d_1842 + 3;
      fn_0845_08a5((char *)s_Damage_inflicted_was__d_3e2d_1f22,0x3e2d,0x28,0x12,1,param_2);
      goto LAB_170c_089a;
    }
  }
  else {
    iVar3 = (param_1 & 0x7fff) * 0x2e;
    local_6 = iVar3 + 0x15fa;
    puStack_4 = (undefined1 *)&g_3803;
    if (*(char *)(iVar3 + 0x160e) < '\r') {
LAB_170c_089a:
      if ((param_1 & 0x8000) == 0) {
        uVar4 = fn_070c_09f7(puVar7);
        return uVar4;
      }
      if ((int)param_2 < 1) {
        *(int *)(local_6 + 0x1d) = *(int *)(local_6 + 0x1d) - param_2;
        param_2 = 0;
        iVar3 = *(int *)(local_6 + 0x1d);
        if (*(int *)((int)*(undefined4 *)(local_6 + 0x21) + 0x3a) <= iVar3) {
          iVar3 = *(int *)((int)*(undefined4 *)(local_6 + 0x21) + 0x3a);
        }
        *(int *)(local_6 + 0x1d) = iVar3;
        if (*(int *)(local_6 + 0x1d) < 2) {
          uVar5 = 1;
        }
        else {
          uVar5 = *(undefined2 *)(local_6 + 0x1d);
        }
        *(undefined2 *)(local_6 + 0x1d) = uVar5;
      }
      else {
        *(int *)(local_6 + 0x1d) = *(int *)(local_6 + 0x1d) - param_2;
        *(uint *)(local_6 + 0x1b) = param_2 | 0x8000;
        *(uint *)(local_6 + 0x19) = *(uint *)(local_6 + 0x19) | 0x10;
        cVar2 = fn_0845_0636(1,0x18);
        *(char *)(local_6 + 0x11) = cVar2 + -0xc;
        cVar2 = fn_0845_0636(1,0x18);
        *(char *)(local_6 + 0x12) = cVar2 + -0xc;
        iVar3 = *(int *)(local_6 + 0x1d);
        if (*(int *)((int)*(undefined4 *)(local_6 + 0x21) + 0x3a) <= iVar3) {
          iVar3 = *(int *)((int)*(undefined4 *)(local_6 + 0x21) + 0x3a);
        }
        *(int *)(local_6 + 0x1d) = iVar3;
        if (*(int *)(local_6 + 0x1d) < 1) {
          uVar5 = 0;
        }
        else {
          uVar5 = *(undefined2 *)(local_6 + 0x1d);
        }
        *(undefined2 *)(local_6 + 0x1d) = uVar5;
        if ((param_3 & 0x8000) == 0) {
          fn_0d6c_0d2a(local_6,puStack_4,param_3,param_5,param_4,param_2);
        }
        fn_067a_027f(*(undefined1 *)((int)*(undefined4 *)(local_6 + 0x21) + 0x52),
                      *(undefined2 *)(local_6 + 5));
        pcVar6 = (char *)s_Lib_error_29_3e2d_1842 + 3;
        fn_0845_046c(*(undefined2 *)(local_6 + 5));
        if (*(int *)(local_6 + 0x1d) < 1) {
          *(undefined2 *)(local_6 + 0x1d) = 0;
          if ((param_3 & 0x8000) == 0) {
            iVar3 = *(int *)((int)*(undefined4 *)(local_6 + 0x21) + 0x3a);
            fn_070c_00cf((char *)s_Lib_error_29_3e2d_1842 + 3,param_3,param_4,iVar3,iVar3 >> 0xf);
          }
          pcVar6 = "G.ADV";
          fn_0d6c_0995(local_6,puStack_4,0xd);
        }
      }
      if ((param_3 & 0x8000) != 0) {
        return param_2;
      }
      if (param_4 == 0) {
        piVar1 = (int *)(param_3 * 0x82 + 0x3671);
        *piVar1 = *piVar1 + param_2;
      }
      fn_070c_00cf(pcVar6,param_3,param_4,param_2,(int)param_2 >> 0xf);
      return param_2;
    }
  }
  return 0;
}


//// fn_070c_086a @ 170c:086a

uint fn_070c_086a(void)

{
  int *piVar1;
  undefined4 uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int unaff_BP;
  uint unaff_SI;
  uint unaff_DI;
  undefined2 uVar7;
  char *pcVar8;
  undefined2 unaff_SS;
  
  fn_067a_0401();
  fn_0a21_0674();
  pcVar8 = (char *)s_Lib_error_29_3e2d_1842 + 3;
  fn_0845_08a5((char *)s_Damage_inflicted_was__d_3e2d_1f22,0x3e2d,0x28,0x10012);
  if ((unaff_DI & 0x8000) != 0) {
    if ((int)unaff_SI < 1) {
      uVar7 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
      iVar6 = (int)*(undefined4 *)(unaff_BP + -4);
      *(int *)(iVar6 + 0x1d) = *(int *)(iVar6 + 0x1d) - unaff_SI;
      unaff_SI = 0;
      iVar5 = *(int *)(iVar6 + 0x1d);
      if (*(int *)((int)*(undefined4 *)(iVar6 + 0x21) + 0x3a) <= iVar5) {
        uVar2 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -4) + 0x21);
        iVar5 = *(int *)((int)uVar2 + 0x3a);
      }
      uVar7 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
      iVar6 = (int)*(undefined4 *)(unaff_BP + -4);
      *(int *)(iVar6 + 0x1d) = iVar5;
      if (*(int *)(iVar6 + 0x1d) < 2) {
        uVar7 = 1;
      }
      else {
        uVar7 = *(undefined2 *)(iVar6 + 0x1d);
      }
      *(undefined2 *)((int)*(undefined4 *)(unaff_BP + -4) + 0x1d) = uVar7;
    }
    else {
      uVar7 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
      iVar5 = (int)*(undefined4 *)(unaff_BP + -4);
      *(int *)(iVar5 + 0x1d) = *(int *)(iVar5 + 0x1d) - unaff_SI;
      *(uint *)(iVar5 + 0x1b) = unaff_SI | 0x8000;
      *(uint *)(iVar5 + 0x19) = *(uint *)(iVar5 + 0x19) | 0x10;
      cVar3 = fn_0845_0636();
      *(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0x11) = cVar3 + -0xc;
      cVar3 = fn_0845_0636();
      uVar7 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
      iVar6 = (int)*(undefined4 *)(unaff_BP + -4);
      *(char *)(iVar6 + 0x12) = cVar3 + -0xc;
      iVar5 = *(int *)(iVar6 + 0x1d);
      if (*(int *)((int)*(undefined4 *)(iVar6 + 0x21) + 0x3a) <= iVar5) {
        uVar2 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -4) + 0x21);
        iVar5 = *(int *)((int)uVar2 + 0x3a);
      }
      uVar7 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
      iVar6 = (int)*(undefined4 *)(unaff_BP + -4);
      *(int *)(iVar6 + 0x1d) = iVar5;
      if (*(int *)(iVar6 + 0x1d) < 1) {
        uVar7 = 0;
      }
      else {
        uVar7 = *(undefined2 *)(iVar6 + 0x1d);
      }
      iVar5 = (int)*(undefined4 *)(unaff_BP + -4);
      *(undefined2 *)(iVar5 + 0x1d) = uVar7;
      if ((*(uint *)(unaff_BP + 10) & 0x8000) == 0) {
        fn_0d6c_0d2a(iVar5,*(undefined2 *)(unaff_BP + -2),*(undefined2 *)(unaff_BP + 10),
                      *(undefined2 *)(unaff_BP + 0xe),*(undefined2 *)(unaff_BP + 0xc));
      }
      fn_067a_027f();
      pcVar8 = (char *)s_Lib_error_29_3e2d_1842 + 3;
      fn_0845_046c();
      uVar7 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
      iVar5 = (int)*(undefined4 *)(unaff_BP + -4);
      if (*(int *)(iVar5 + 0x1d) < 1) {
        *(undefined2 *)(iVar5 + 0x1d) = 0;
        if ((*(uint *)(unaff_BP + 10) & 0x8000) == 0) {
          fn_070c_00cf((char *)s_Lib_error_29_3e2d_1842 + 3,*(undefined2 *)(unaff_BP + 10),
                        *(undefined2 *)(unaff_BP + 0xc),
                        *(undefined2 *)((int)*(undefined4 *)(iVar5 + 0x21) + 0x3a));
        }
        pcVar8 = "G.ADV";
        fn_0d6c_0995(*(undefined4 *)(unaff_BP + -4));
      }
    }
    if ((*(uint *)(unaff_BP + 10) & 0x8000) == 0) {
      if (*(int *)(unaff_BP + 0xc) == 0) {
        piVar1 = (int *)(*(int *)(unaff_BP + 10) * 0x82 + 0x3671);
        *piVar1 = *piVar1 + unaff_SI;
      }
      fn_070c_00cf(pcVar8,*(undefined2 *)(unaff_BP + 10),*(undefined2 *)(unaff_BP + 0xc),unaff_SI);
    }
    return unaff_SI;
  }
  uVar4 = fn_070c_09f7();
  return uVar4;
}


//// fn_070c_09e0 @ 170c:09e0

int __cdecl16far fn_070c_09e0(void)

{
  int *piVar1;
  int in_AX;
  char in_DL;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_ES;
  char *pcVar2;
  undefined2 unaff_SS;
  bool in_ZF;
  char in_SF;
  char in_OF;
  
  pcVar2 = (char *)s_File_error_6_14__3e2d_1702 + 10;
  if (in_ZF || in_OF != in_SF) {
    *(int *)(unaff_BP + 6) = *(int *)(unaff_BP + 6) + unaff_DI;
    *(undefined2 *)((int)*(undefined4 *)(unaff_BP + -4) + 0x1d) = *(undefined2 *)(in_BX + 0x1d);
  }
  else {
    *(char *)(in_BX + -0x66) = *(char *)(in_BX + -0x66) + in_DL;
    *(uint *)(in_BX + in_AX) = *(uint *)(in_BX + in_AX) | (uint)&stack0x0000;
    if (CONCAT11((char)((uint)unaff_DI >> 8),(char)unaff_DI - *(char *)(unaff_BP + in_AX + 0x4c4))
        != 0) {
      unaff_SI = unaff_SI >> 2;
    }
    fn_0a21_06fd();
    if (*(int *)((int)*(undefined4 *)(unaff_BP + -8) + 0x39) < 1) {
      fn_070c_0664();
    }
    else {
      *(int *)((int)*(undefined4 *)(unaff_BP + -8) + 0x42) = unaff_SI;
      fn_0bbc_0744();
    }
    pcVar2 = (char *)s_PLAYFLD_CPS_3e2d_1a19 + 8;
    fn_0a21_022b();
  }
  if ((*(uint *)(unaff_BP + 10) & 0x8000) == 0) {
    if (*(int *)(unaff_BP + 0xc) == 0) {
      piVar1 = (int *)(*(int *)(unaff_BP + 10) * 0x82 + 0x3671);
      *piVar1 = *piVar1 + unaff_SI;
    }
    fn_070c_00cf(pcVar2,*(undefined2 *)(unaff_BP + 10),*(undefined2 *)(unaff_BP + 0xc),
                  (long)unaff_SI);
  }
  return unaff_SI;
}


//// fn_070c_09f7 @ 170c:09f7

int __cdecl16far fn_070c_09f7(void)

{
  int *piVar1;
  int iVar2;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  
  if (*(int *)(unaff_BP + 0xe) == 4) {
    iVar2 = fn_0a21_0997();
    if (iVar2 != 0) {
      unaff_SI = unaff_SI >> 2;
    }
  }
  fn_0a21_06fd();
  if (*(int *)((int)*(undefined4 *)(unaff_BP + -8) + 0x39) < 1) {
    fn_070c_0664();
  }
  else {
    *(int *)((int)*(undefined4 *)(unaff_BP + -8) + 0x42) = unaff_SI;
    fn_0bbc_0744();
  }
  fn_0a21_022b();
  if ((*(uint *)(unaff_BP + 10) & 0x8000) == 0) {
    if (*(int *)(unaff_BP + 0xc) == 0) {
      piVar1 = (int *)(*(int *)(unaff_BP + 10) * 0x82 + 0x3671);
      *piVar1 = *piVar1 + unaff_SI;
    }
    fn_070c_00cf((char *)s_PLAYFLD_CPS_3e2d_1a19 + 8,*(undefined2 *)(unaff_BP + 10),
                  *(undefined2 *)(unaff_BP + 0xc),(long)unaff_SI);
  }
  return unaff_SI;
}


//// fn_070c_0a8f @ 170c:0a8f

void __cdecl16far fn_070c_0a8f(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 local_6;
  
  param_1 = param_1 * 0x82;
  local_6 = (uint *)CONCAT22((undefined1 *)&g_3803,
                             (uint *)((int)(undefined4 *)&g_362a + param_1 + 3));
  if ((0 < *(int *)(param_1 + 0x3666)) || (param_3 != 0)) {
    if (param_2 < 1) {
      param_2 = 1;
    }
    *(int *)(param_1 + 0x3666) = *(int *)(param_1 + 0x3666) + param_2;
    iVar1 = *(int *)(param_1 + 0x3666);
    if (*(int *)(param_1 + 0x3668) <= iVar1) {
      iVar1 = *(int *)(param_1 + 0x3668);
    }
    *(int *)(param_1 + 0x3666) = iVar1;
    if (*(int *)(param_1 + 0x3666) < 2) {
      uVar2 = 1;
    }
    else {
      uVar2 = *(undefined2 *)(param_1 + 0x3666);
    }
    *(undefined2 *)(param_1 + 0x3666) = uVar2;
    if ((*(int *)(param_1 + 0x3666) != 0) && ((*local_6 & 8) != 0)) {
      *local_6 = *local_6 & 0xfff7;
    }
  }
  return;
}


//// fn_070c_0ae0 @ 170c:0ae0

void __cdecl16far fn_070c_0ae0(void)

{
  uint *puVar1;
  undefined2 in_AX;
  undefined2 uVar2;
  int in_BX;
  int unaff_BP;
  undefined2 unaff_ES;
  undefined2 uVar3;
  undefined2 unaff_SS;
  
  *(undefined2 *)(in_BX + 0x39) = in_AX;
  if (*(int *)(in_BX + 0x39) < 2) {
    uVar2 = 1;
  }
  else {
    uVar2 = *(undefined2 *)(in_BX + 0x39);
  }
  puVar1 = (uint *)*(undefined4 *)(unaff_BP + -4);
  uVar3 = (undefined2)((ulong)puVar1 >> 0x10);
  *(undefined2 *)((int)(uint *)puVar1 + 0x39) = uVar2;
  if ((*(int *)((int)(uint *)puVar1 + 0x39) != 0) && ((*puVar1 & 8) != 0)) {
    *puVar1 = *puVar1 & 0xfff7;
  }
  return;
}

