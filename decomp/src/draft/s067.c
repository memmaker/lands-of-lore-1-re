//// fn_1ef2_001c @ 2ef2:001c

void __cdecl16far fn_1ef2_001c(undefined2 param_1,undefined2 param_2)

{
  fn_1ee4_0002(param_1,param_2);
  return;
}


//// fn_1ef2_002f @ 2ef2:002f

void __cdecl16far fn_1ef2_002f(long param_1,int param_2,undefined2 param_3,undefined2 param_4)

{
  undefined2 local_6;
  undefined2 uStack_4;
  
  if (param_1 != 0) {
    local_6 = (int)param_1;
    uStack_4 = (undefined2)((ulong)param_1 >> 0x10);
    memcpy(local_6 + param_2 * 3,uStack_4,param_3,param_4,3);
    fn_1ee4_0002(local_6,uStack_4);
  }
  return;
}


//// fn_1ef2_0075 @ 2ef2:0075

void __cdecl16far fn_1ef2_0075(long param_1,undefined2 param_2,code *param_3)

{
  int iVar1;
  uint uVar2;
  undefined1 local_30a [768];
  int local_a;
  ulong local_8;
  undefined2 local_4;
  
  if (param_1 != 0) {
    if (g_362e == 3) {
      memcpy(local_30a);
      fn_1ef2_012e((undefined2)param_1,param_1._2_2_,param_2,&local_a);
      uVar2 = 0;
      local_8 = g_384c;
      do {
        local_8 = local_8 + (long)((int)(uVar2 + local_a) >> 8);
        uVar2 = uVar2 + local_a & 0xff;
        iVar1 = fn_1ef2_01f6((undefined2)param_1,param_1._2_2_,local_4);
        if (iVar1 != 0) {
          while (g_384c < local_8) {
            if (param_3 != (code *)0x0) {
              (*(code *)param_3)(0x1000);
            }
          }
        }
        if (param_3 != (code *)0x0) {
          (*(code *)param_3)(0x1000);
        }
      } while (iVar1 != 0);
    }
    else {
      fn_1ef2_001c((undefined2)param_1,param_1._2_2_);
    }
  }
  return;
}


//// fn_1ef2_012e @ 2ef2:012e

void __cdecl16far fn_1ef2_012e(undefined4 param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  long local_c;
  
  iVar2 = 0;
  for (iVar3 = 0; iVar3 < 0x300; iVar3 = iVar3 + 1) {
    iVar1 = (uint)*(byte *)((int)param_1 + iVar3) -
            (uint)(byte)((undefined1 *)&g_2fac)[iVar3];
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    if (iVar1 < iVar2) {
      iVar1 = iVar2;
    }
    iVar2 = iVar1;
  }
  local_c = (long)param_2 << 8;
  if ((iVar2 != 0) && (local_c = local_c / (long)iVar2, 0x7ffe < local_c)) {
    local_c = 0x7fff;
  }
  *param_3 = (int)local_c;
  iVar3 = *param_3;
  *param_4 = 1;
  while ((*param_4 <= iVar2 && (*param_3 < 0x100))) {
    *param_3 = *param_3 + iVar3;
    *param_4 = *param_4 + 1;
  }
  return;
}


//// fn_1ef2_01f6 @ 2ef2:01f6

int __cdecl16far fn_1ef2_01f6(long param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined2 unaff_SS;
  byte local_306 [768];
  uint local_6;
  int local_4;
  
  local_4 = 0;
  if (param_1 == 0) {
    local_4 = 0;
  }
  else if (g_362e == 3) {
    memcpy(local_306);
    for (iVar2 = 0; iVar2 < 0x300; iVar2 = iVar2 + 1) {
      uVar1 = (uint)*(byte *)((int)param_1 + iVar2);
      local_6 = (uint)local_306[iVar2];
      if (uVar1 != local_6) {
        local_4 = 1;
        if (local_6 < uVar1) {
          if ((int)(local_6 + param_2) < (int)uVar1) {
            uVar1 = local_6 + param_2;
          }
        }
        else if ((int)uVar1 < (int)(local_6 - param_2)) {
          uVar1 = local_6 - param_2;
        }
        local_6 = uVar1;
        uVar1 = local_6;
        local_6._0_1_ = (byte)uVar1;
        local_306[iVar2] = (byte)local_6;
        local_6 = uVar1;
      }
    }
    if (local_4 != 0) {
      fn_1ef2_001c(local_306);
    }
  }
  else {
    fn_1ef2_001c((int)param_1,param_1._2_2_);
  }
  return local_4;
}


//// fn_1ef2_02c0 @ 2ef2:02c0

void __cdecl16far
fn_1ef2_02c0(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  ovr_2ded_0020(param_1,param_2,param_3,param_4,0x300);
  return;
}

