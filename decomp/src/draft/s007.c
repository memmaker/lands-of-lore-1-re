//// fn_080e_000b @ 180e:000b

int __cdecl16far fn_080e_000b(uint param_1)

{
  int iVar1;
  
  if ((param_1 & 0x8000) == 0) {
    iVar1 = param_1 * 0x10 + 0x1cfd;
  }
  else {
    iVar1 = (param_1 & 0x7fff) * 0x2e + 0x15fa;
  }
  return iVar1;
}


//// fn_080e_0034 @ 180e:0034

void fn_080e_0034(undefined2 param_1,undefined2 *param_2,undefined2 param_3)

{
  undefined2 *puVar1;
  undefined2 in_DX;
  undefined4 uStack_6;
  
  puVar1 = (undefined2 *)fn_080e_000b(param_3);
  uStack_6 = (undefined2 *)CONCAT22(in_DX,puVar1);
  *uStack_6 = *param_2;
  *param_2 = param_3;
  return;
}


//// fn_080e_0040 @ 180e:0040

void __cdecl16far fn_080e_0040(void)

{
  undefined2 uVar1;
  undefined2 in_DX;
  int unaff_BP;
  undefined2 unaff_SI;
  undefined2 unaff_SS;
  
  uVar1 = fn_080e_000b();
  *(undefined2 *)(unaff_BP + -2) = in_DX;
  *(undefined2 *)(unaff_BP + -4) = uVar1;
  *(undefined2 *)*(undefined4 *)(unaff_BP + -4) = *(undefined2 *)*(undefined4 *)(unaff_BP + 6);
  *(undefined2 *)*(undefined4 *)(unaff_BP + 6) = unaff_SI;
  return;
}


//// fn_080e_005f @ 180e:005f

void __cdecl16far fn_080e_005f(uint *param_1,uint param_2)

{
  uint *puVar1;
  undefined2 in_DX;
  undefined4 local_a;
  undefined4 local_6;
  
  while ((*param_1 & 0x8000) != 0) {
    puVar1 = (uint *)fn_080e_000b(*param_1);
    local_6 = (uint *)CONCAT22(in_DX,puVar1);
    param_1 = local_6;
  }
  puVar1 = (uint *)fn_080e_000b(param_2);
  local_a = (uint *)CONCAT22(in_DX,puVar1);
  *local_a = *param_1;
  *(undefined1 *)((int)puVar1 + 0xb) = 0xff;
  *param_1 = param_2;
  return;
}


//// fn_080e_00b4 @ 180e:00b4

void __cdecl16far fn_080e_00b4(uint *param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  undefined2 in_DX;
  undefined4 uStack_a;
  undefined4 uStack_6;
  
  while ((*param_1 & 0x8000) != 0) {
    puVar2 = (uint *)fn_080e_000b(*param_1);
    uStack_6 = (uint *)CONCAT22(in_DX,puVar2);
    param_1 = uStack_6;
  }
  puVar2 = (uint *)fn_080e_000b(param_2);
  uStack_a = (uint *)CONCAT22(in_DX,puVar2);
  *(undefined1 *)((int)puVar2 + 0xb) = 0xff;
  uVar1 = *param_1;
  if (*param_1 != param_2) {
    *param_1 = param_2;
    while( true ) {
      if (*uStack_a == 0) break;
      puVar2 = (uint *)fn_080e_000b(*uStack_a);
      uStack_6 = (uint *)CONCAT22(in_DX,puVar2);
      uStack_a = uStack_6;
    }
    *uStack_a = uVar1;
  }
  return;
}


//// fn_080e_00c0 @ 180e:00c0

void __cdecl16far fn_080e_00c0(void)

{
  int *piVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined2 in_DX;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  
  do {
    uVar2 = fn_080e_000b(*(undefined2 *)*(undefined4 *)(unaff_BP + 6));
    *(undefined2 *)(unaff_BP + -2) = in_DX;
    *(undefined2 *)(unaff_BP + -4) = uVar2;
    *(undefined4 *)(unaff_BP + 6) = *(undefined4 *)(unaff_BP + -4);
  } while ((*(uint *)*(undefined4 *)(unaff_BP + 6) & 0x8000) != 0);
  uVar2 = fn_080e_000b();
  *(undefined2 *)(unaff_BP + -6) = in_DX;
  *(undefined2 *)(unaff_BP + -8) = uVar2;
  *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -8) + 0xb) = 0xff;
  piVar1 = (int *)*(undefined4 *)(unaff_BP + 6);
  *(int *)(unaff_BP + -10) = *piVar1;
  if (*piVar1 != unaff_SI) {
    *(int *)*(undefined4 *)(unaff_BP + 6) = unaff_SI;
    uVar3 = *(undefined4 *)(unaff_BP + -8);
    while( true ) {
      *(undefined4 *)(unaff_BP + 6) = uVar3;
      if (*(int *)*(undefined4 *)(unaff_BP + 6) == 0) break;
      uVar2 = fn_080e_000b(*(undefined2 *)*(undefined4 *)(unaff_BP + 6));
      *(undefined2 *)(unaff_BP + -2) = in_DX;
      *(undefined2 *)(unaff_BP + -4) = uVar2;
      uVar3 = *(undefined4 *)(unaff_BP + -4);
    }
    *(int *)*(undefined4 *)(unaff_BP + 6) = *(int *)(unaff_BP + -10);
  }
  return;
}


//// fn_080e_013c @ 180e:013c

void __cdecl16far fn_080e_013c(int *param_1,int param_2)

{
  int *piVar1;
  undefined2 in_DX;
  undefined4 local_6;
  
  while( true ) {
    if (*param_1 == 0) {
      ovr_2d46_002a(0,(char *)s_L_R_O__Object__d_didn_t_exist__3e2d_2196,0x3e2d,param_2);
      return;
    }
    if (*param_1 == param_2) break;
    piVar1 = (int *)fn_080e_000b(*param_1);
    local_6 = (int *)CONCAT22(in_DX,piVar1);
    param_1 = local_6;
  }
  piVar1 = (int *)fn_080e_000b(param_2);
  local_6 = (int *)CONCAT22(in_DX,piVar1);
  *param_1 = *local_6;
  *local_6 = 0;
  return;
}


//// fn_080e_01a6 @ 180e:01a6

uint __cdecl16far fn_080e_01a6(uint *param_1,int param_2)

{
  int iVar1;
  uint *in_DX;
  
  while( true ) {
    if (*param_1 == 0) {
      return 0xffff;
    }
    if (((*param_1 & 0x8000) == 0) && (param_2 = param_2 + -1, param_2 == 0)) break;
    iVar1 = fn_080e_000b(*param_1);
    param_1 = (uint *)CONCAT22(in_DX,(uint *)(iVar1 + 2));
    in_DX = (uint *)(iVar1 + 2);
  }
  return *param_1;
}


//// fn_080e_01c0 @ 180e:01c0

undefined2 __cdecl16far fn_080e_01c0(void)

{
  undefined2 *in_BX;
  
  return *in_BX;
}


//// fn_080e_01f3 @ 180e:01f3

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl16far fn_080e_01f3(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  int local_6;
  undefined2 local_4;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  local_4 = *(undefined2 *)(iVar1 + 7);
  local_6 = *(int *)(iVar1 + 9);
  fn_1aff_0341(g_7fd2,&local_4);
  if (local_6 < 0) {
    local_6 = 0;
  }
  return (uint)*(byte *)(iVar1 + 4) << 0xc | 0xfffU - local_6;
}


//// fn_080e_0245 @ 180e:0245

void __cdecl16far fn_080e_0245(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 in_DX;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 local_e;
  undefined4 local_a;
  
  piVar6 = (int *)((ulong)param_3 >> 0x10);
  iVar5 = (int)param_3;
  if (*(char *)(iVar5 + 8) == param_1) {
    iVar1 = fn_080e_000b(param_2);
    iVar2 = fn_080e_01f3(iVar1,in_DX,param_1);
    piVar4 = (int *)(iVar5 + 6);
    while (local_e = (int *)CONCAT22(piVar6,piVar4), *local_e != 0) {
      piVar6 = piVar4;
      iVar5 = fn_080e_000b(*local_e);
      local_a = CONCAT22(piVar6,iVar5);
      if (param_4 == 0) {
        iVar3 = fn_080e_01f3(local_a,param_1);
        if (iVar2 < iVar3) break;
      }
      else {
        iVar3 = fn_080e_01f3(iVar5,piVar6,param_1);
        if (iVar2 <= iVar3) break;
      }
      piVar4 = (int *)(iVar5 + 2);
    }
    *(int *)(iVar1 + 2) = *local_e;
    *local_e = param_2;
  }
  else {
    *(undefined1 *)(iVar5 + 8) = 5;
  }
  return;
}


//// fn_080e_02f5 @ 180e:02f5

void __cdecl16far fn_080e_02f5(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uStack_a;
  
  piVar3 = (int *)((ulong)param_1 >> 0x10);
  if (*(char *)((int)param_1 + 8) != '\x05') {
    piVar2 = (int *)((int)param_1 + 6);
    while (uStack_a = (int *)CONCAT22(piVar3,piVar2), *uStack_a != 0) {
      if (*uStack_a == param_2) {
        iVar1 = fn_080e_000b(*uStack_a);
        *uStack_a = *(int *)(iVar1 + 2);
        *(undefined2 *)(iVar1 + 2) = 0;
        return;
      }
      piVar3 = piVar2;
      iVar1 = fn_080e_000b(*uStack_a);
      piVar2 = (int *)(iVar1 + 2);
    }
    ovr_2d46_002a(1,(char *)s_RemoveIdx__Object_didn_t_exist__3e2d_21b5,0x3e2d);
  }
  return;
}


//// fn_080e_0345 @ 180e:0345

void fn_080e_0345(void)

{
  undefined2 uVar1;
  int in_DX;
  int unaff_BP;
  undefined2 unaff_SS;
  
  do {
    uVar1 = fn_080e_000b();
    *(int *)(unaff_BP + -2) = in_DX;
    *(undefined2 *)(unaff_BP + -4) = uVar1;
    in_DX = *(int *)(unaff_BP + -4) + 2;
    *(undefined2 *)(unaff_BP + -6) = *(undefined2 *)(unaff_BP + -2);
    *(int *)(unaff_BP + -8) = in_DX;
    if (*(int *)*(undefined4 *)(unaff_BP + -8) == 0) {
      ovr_2d46_002a(1,(char *)s_RemoveIdx__Object_didn_t_exist__3e2d_21b5);
      return;
    }
  } while (*(int *)*(undefined4 *)(unaff_BP + -8) != *(int *)(unaff_BP + 10));
  uVar1 = fn_080e_000b();
  *(int *)(unaff_BP + -2) = in_DX;
  *(undefined2 *)(unaff_BP + -4) = uVar1;
  *(undefined2 *)*(undefined4 *)(unaff_BP + -8) =
       *(undefined2 *)((int)*(undefined4 *)(unaff_BP + -4) + 2);
  *(undefined2 *)((int)*(undefined4 *)(unaff_BP + -4) + 2) = 0;
  return;
}


//// fn_080e_034a @ 180e:034a

void fn_080e_034a(void)

{
  undefined2 uVar1;
  undefined2 in_AX;
  int in_DX;
  int unaff_BP;
  undefined2 unaff_SS;
  
  while( true ) {
    *(int *)(unaff_BP + -2) = in_DX;
    *(undefined2 *)(unaff_BP + -4) = in_AX;
    in_DX = *(int *)(unaff_BP + -4) + 2;
    *(undefined2 *)(unaff_BP + -6) = *(undefined2 *)(unaff_BP + -2);
    *(int *)(unaff_BP + -8) = in_DX;
    if (*(int *)*(undefined4 *)(unaff_BP + -8) == 0) {
      ovr_2d46_002a(1,(char *)s_RemoveIdx__Object_didn_t_exist__3e2d_21b5,0x3e2d);
      return;
    }
    if (*(int *)*(undefined4 *)(unaff_BP + -8) == *(int *)(unaff_BP + 10)) break;
    in_AX = fn_080e_000b(*(undefined2 *)*(undefined4 *)(unaff_BP + -8));
  }
  uVar1 = fn_080e_000b(*(int *)*(undefined4 *)(unaff_BP + -8));
  *(int *)(unaff_BP + -2) = in_DX;
  *(undefined2 *)(unaff_BP + -4) = uVar1;
  *(undefined2 *)*(undefined4 *)(unaff_BP + -8) =
       *(undefined2 *)((int)*(undefined4 *)(unaff_BP + -4) + 2);
  *(undefined2 *)((int)*(undefined4 *)(unaff_BP + -4) + 2) = 0;
  return;
}


//// fn_080e_034f @ 180e:034f

void __cdecl16far fn_080e_034f(void)

{
  undefined2 uVar1;
  int iVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  
  while( true ) {
    iVar2 = *(int *)(unaff_BP + -4) + 2;
    *(undefined2 *)(unaff_BP + -6) = *(undefined2 *)(unaff_BP + -2);
    *(int *)(unaff_BP + -8) = iVar2;
    if (*(int *)*(undefined4 *)(unaff_BP + -8) == 0) {
      ovr_2d46_002a(1,(char *)s_RemoveIdx__Object_didn_t_exist__3e2d_21b5,0x3e2d);
      return;
    }
    if (*(int *)*(undefined4 *)(unaff_BP + -8) == *(int *)(unaff_BP + 10)) break;
    uVar1 = fn_080e_000b(*(undefined2 *)*(undefined4 *)(unaff_BP + -8));
    *(int *)(unaff_BP + -2) = iVar2;
    *(undefined2 *)(unaff_BP + -4) = uVar1;
  }
  uVar1 = fn_080e_000b(*(int *)*(undefined4 *)(unaff_BP + -8));
  *(int *)(unaff_BP + -2) = iVar2;
  *(undefined2 *)(unaff_BP + -4) = uVar1;
  *(undefined2 *)*(undefined4 *)(unaff_BP + -8) =
       *(undefined2 *)((int)*(undefined4 *)(unaff_BP + -4) + 2);
  *(undefined2 *)((int)*(undefined4 *)(unaff_BP + -4) + 2) = 0;
  return;
}

