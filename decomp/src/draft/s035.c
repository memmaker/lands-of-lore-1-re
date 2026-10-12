//// fn_1981_000a @ 2981:000a

int __cdecl16far fn_1981_000a(long param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined2 uVar5;
  undefined2 in_DX;
  undefined2 uVar6;
  undefined1 local_1e [22];
  uint local_8;
  undefined4 local_6;
  
  local_6 = (undefined4 *)0x0;
  if (param_1 != 0) {
    uVar5 = (undefined2)param_1;
    uVar6 = (undefined2)((ulong)param_1 >> 0x10);
    iVar2 = fn_1981_01af(uVar5,uVar6);
    local_6._0_2_ = fn_1981_02c0(iVar2,local_1e);
    if ((iVar2 != -1) && (*(long *)((int)local_6 + 8) != 0)) {
      return 1;
    }
    g_abdc = 0xffff;
    local_6._2_2_ = in_DX;
    fn_2148_002c(g_ae59 + -0x41);
    g_abde = g_abde + '\x01';
    iVar3 = open(0x3148,uVar5,uVar6,0x8001,0x100);
    cVar1 = g_abde + -1;
    if (iVar3 != -1) {
      close(iVar3);
      iVar2 = getdisk();
      g_abde = g_abde + -1;
LAB_2981_0136:
      return iVar2 + 1;
    }
    g_abde = cVar1;
    if (((iVar2 != -1) && (local_8 = (uint)*(byte *)((int)local_6 + 0x10), iVar2 != -1)) &&
       ((*(uint *)((int)local_6 + 0x12) & 0x1000) != 0)) {
      puVar4 = (undefined4 *)fn_1981_02c0(local_8,local_1e);
      local_6 = (undefined4 *)CONCAT22(iVar3,puVar4);
      uVar5 = fn_1981_0365((int)*local_6,(int)((ulong)*local_6 >> 0x10));
      iVar2 = fn_1981_000a(uVar5,iVar3);
      return iVar2;
    }
    if (g_2aa6 != '\0') {
      fn_2148_002c(g_aeaa + -0x41);
      g_ae4d = 0;
      iVar2 = fn_1809_1460(uVar5,uVar6,0x8001);
      if (iVar2 != -1) {
        fn_2148_004d(iVar2);
        iVar2 = fn_2148_000f();
        goto LAB_2981_0136;
      }
      fn_2148_002c(g_ae59 + -0x41);
    }
  }
  return 0;
}


//// fn_1981_014c @ 2981:014c

void __cdecl16far fn_1981_014c(undefined4 *param_1,undefined4 *param_2)

{
  strcmp(*param_1,*param_2);
  return;
}


//// fn_1981_0167 @ 2981:0167

void __cdecl16far fn_1981_0167(undefined4 *param_1,undefined4 *param_2)

{
  undefined1 local_1e [14];
  undefined1 local_10 [14];
  
  fn_2279_025b(*param_1,local_10);
  fn_2279_025b(*param_2,local_1e);
  strcmp(local_10);
  return;
}


//// fn_1981_01af @ 2981:01af

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far fn_1981_01af(long param_1)

{
  bool bVar1;
  int iVar2;
  undefined2 uVar3;
  int in_DX;
  undefined2 local_1a [10];
  undefined4 local_6;
  
  if ((g_2aa9 == 0x37fc) && (g_2aa7 == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (param_1 == 0) {
    return 0xffff;
  }
  local_6 = 0;
  local_1a[0] = strupr(param_1);
  iVar2 = strstr(local_1a[0],in_DX,0x2aac,0x3e2d);
  if (iVar2 == 0 && in_DX == 0) {
    if (bVar1) {
      uVar3 = 0x14c;
    }
    else {
      uVar3 = 0x167;
    }
    in_DX = 0x2981;
    if (bVar1) {
      in_DX = 0x37fc;
    }
    else {
      fn_2037_0002(g_2aa7,(ulong)g_abda * 0x14,g_abd8,0x14,uVar3,0x2981);
    }
  }
  else if (bVar1) {
    uVar3 = fn_242d_0108(local_1a);
    goto LAB_2981_0294;
  }
  uVar3 = fn_242d_000f(local_1a);
LAB_2981_0294:
  local_6 = CONCAT22(in_DX,uVar3);
  if (local_6 == 0) {
    return 0xffff;
  }
  return (int)((local_6 - g_2aa7) / 0x14);
}


//// fn_1981_02c0 @ 2981:02c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl16far fn_1981_02c0(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  
  if (param_1 == -1) {
    param_2._0_2_ = 0;
  }
  else if ((g_2aa9 == 0x37fc) && (g_2aa7 == 0)) {
    param_2._0_2_ = param_1 * 0x14;
  }
  else {
    uVar1 = fn_2037_0002(g_2aa7,param_1 * 0x14,param_2,0x14);
    fn_2279_025b(uVar1,param_1);
  }
  return (int)param_2;
}


//// fn_1981_031f @ 2981:031f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far fn_1981_031f(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  
  if (((g_2aa9 != 0x37fc) || (g_2aa7 != 0)) && (param_1 != -1)) {
    uVar1 = fn_2037_0002(g_2aa7,param_1 * 0x14,0x14);
    fn_2279_025b(param_2,uVar1,param_1);
  }
  return;
}


//// fn_1981_0365 @ 2981:0365

undefined2 __cdecl16far fn_1981_0365(undefined4 param_1)

{
  if ((g_2aa9 == 0x37fc) && (g_2aa7 == 0)) {
  }
  else {
    fn_2279_025b(param_1,0xabe2,0x3e2d,0xe);
    param_1._0_2_ = 0xabe2;
  }
  return (undefined2)param_1;
}

