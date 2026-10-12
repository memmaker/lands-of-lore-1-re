//// fn_16cf_0022 @ 26cf:0022

undefined2 __cdecl16far fn_16cf_0022(long param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  int iVar2;
  
  if ((((g_20cd != 0) || (g_20cf != 0)) && (g_292a != -1)) && (param_3 != 0)) {
    uVar1 = fn_16bf_00d6();
    if (param_1 == 0) {
      param_2 = 0x100;
    }
    else if (0xfe < param_2) {
      param_2 = 0xff;
    }
    iVar2 = fn_16cf_022f();
    if (iVar2 == 0) {
      g_2950 = -1;
    }
    if ((g_2990 == 0) || (g_2950 <= param_2)) {
      if (g_2990 != 0) {
        fn_16cf_00b9(0);
      }
      if (param_1 != 0) {
        g_2950 = param_2;
        uVar1 = fn_16cf_0ae2(param_1,param_2,uVar1);
        return uVar1;
      }
    }
  }
  return 0;
}


//// fn_16cf_00b9 @ 26cf:00b9

undefined2 __cdecl16far fn_16cf_00b9(long param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 local_6;
  
  uVar1 = 0;
  if (param_1 == 0) {
    iVar2 = fn_16cf_022f();
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      g_2a31 = 0;
      g_2a09 = 0;
      g_29e1 = 0;
      g_29b9 = 0;
      fn_1b79_0284(0x26cf,g_292a);
      *(undefined1 *)((int)g_2952 + 0xf) = 0;
      for (iVar2 = 1; iVar2 < 5; iVar2 = iVar2 + 1) {
        memset((int)((undefined4 *)&g_2a37)[iVar2],
                      (int)((ulong)((undefined4 *)&g_2a37)[iVar2] >> 0x10),0x80,
                      *(undefined2 *)((undefined4 *)&g_2a4f + iVar2));
      }
      g_297e = 0xffff;
      uVar1 = 1;
    }
  }
  else {
    iVar2 = 0;
    do {
      local_6 = (long *)CONCAT22(0x3e2d,(long *)(iVar2 * 0x28 + 0x2997));
      if ((*local_6 == param_1) && (((undefined2 *)&g_29b9)[iVar2 * 0x14] != 0)) {
        ((undefined2 *)&g_29b9)[iVar2 * 0x14] = 0;
        memset((int)*(undefined4 *)((undefined2 *)&g_2a3b + iVar2 * 2),
                      (int)((ulong)*(undefined4 *)((undefined2 *)&g_2a3b + iVar2 * 2) >> 0x10
                           ),0x80,((undefined2 *)&g_2a53)[iVar2 * 2]);
        uVar1 = 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 4);
  }
  return uVar1;
}


//// fn_16cf_0181 @ 26cf:0181

undefined2 __cdecl16far fn_16cf_0181(int param_1)

{
  undefined2 uVar1;
  
  if ((g_2a6f == 0) || (((undefined2 *)&g_29b9)[param_1 * 0x14] == 0)) {
    uVar1 = 0;
  }
  else {
    if (g_297e == -1) {
      fn_1b79_027f(0x26cf,g_292a);
      g_297e = param_1;
    }
    *(undefined4 *)(param_1 * 0x28 + 0x299f) = g_384c;
    uVar1 = 1;
  }
  return uVar1;
}


//// fn_16cf_01c8 @ 26cf:01c8

bool __cdecl16far fn_16cf_01c8(int param_1)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = false;
  if (g_2990 == 0) {
    iVar1 = 0;
    while ((iVar1 < 4 && (bVar2 == false))) {
      if (((undefined2 *)&g_29b9)[iVar1 * 0x14] == 0) {
        bVar2 = true;
      }
      iVar1 = iVar1 + 1;
    }
    iVar1 = 0;
    while ((iVar1 < 4 && (bVar2 == false))) {
      if ((int)((undefined2 *)&g_29b1)[iVar1 * 0x14] <= param_1) {
        bVar2 = true;
      }
      iVar1 = iVar1 + 1;
    }
  }
  else {
    bVar2 = g_29b9 == 0;
    if ((!bVar2) && (g_29b1 <= param_1)) {
      bVar2 = true;
    }
  }
  return bVar2;
}


//// fn_16cf_022f @ 26cf:022f

undefined2 __cdecl16far fn_16cf_022f(void)

{
  undefined2 uVar1;
  int iVar2;
  
  if ((g_2a6f == 0) ||
     ((((g_29b9 == 0 && (g_29e1 == 0)) && (g_2a09 == 0)) &&
      (g_2a31 == 0)))) {
    if (g_297e != -1) {
      fn_1b79_0284(0x26cf,g_292a);
      *(undefined1 *)((int)g_2952 + 0xf) = 0;
      g_2a31 = 0;
      g_2a09 = 0;
      g_29e1 = 0;
      g_29b9 = 0;
      for (iVar2 = 1; iVar2 < 5; iVar2 = iVar2 + 1) {
        memset(((undefined4 *)&g_2a37)[iVar2],0x80,
                      *(undefined2 *)((undefined4 *)&g_2a4f + iVar2));
      }
      g_297e = -1;
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


//// fn_16cf_02b7 @ 26cf:02b7

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far fn_16cf_02b7(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 local_12;
  uint local_10;
  undefined4 local_e;
  long local_a;
  int local_6;
  undefined2 uStack_4;
  
  uVar4 = 0x26cf;
  if (g_297c == 1) {
    fn_0845_0f81((char *)s_REENTERED_______3e2d_2a88,0x3e2d);
  }
  else {
    g_297c = 1;
    if ((g_2a6f != 0) &&
       ((((g_29b9 != 0 || (g_29e1 != 0)) || (g_2a09 != 0)) ||
        (g_2a31 != 0)))) {
      iVar3 = 0;
      do {
        iVar1 = iVar3 * 0x28;
        _local_6 = CONCAT22(0x3e2d,iVar1 + 0x2997);
        if (((((undefined2 *)&g_29b9)[iVar3 * 0x14] != 0) &&
            (*(ulong *)(iVar1 + 0x29a3) < (ulong)(g_384c - *(long *)(iVar1 + 0x299f)))) &&
           (*(ulong *)(iVar1 + 0x29ab) <= *(ulong *)(iVar1 + 0x29a7))) {
          ((undefined2 *)&g_29b9)[iVar3 * 0x14] = 0;
          uVar4 = 0x1000;
          memset((int)((undefined4 *)&g_2a37)[iVar3 + 1],
                        (int)((ulong)((undefined4 *)&g_2a37)[iVar3 + 1] >> 0x10),0x80,
                        *(undefined2 *)((undefined4 *)&g_2a4f + iVar3 + 1));
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 4);
      if (((g_29b9 != 0) || (g_29e1 != 0)) ||
         ((g_2a09 != 0 || (g_2a31 != 0)))) {
        if (g_3749 == 4) {
          iVar3 = fn_1b79_0367(uVar4,g_292a);
          uVar2 = (int)((g_2a4f - (ulong)(iVar3 + 1)) / g_2a53) + 1;
          uVar4 = 0x2b79;
          if (g_2a7d <= uVar2) {
            uVar2 = 0;
          }
        }
        else {
          uVar2 = (int)*(char *)((int)g_2952 + 0xf) + 1;
          if (g_2a7d <= uVar2) {
            uVar2 = 0;
          }
          iVar3 = 0;
        }
        if ((*(char *)((int)g_2a79 + uVar2) == '\0') || (iVar3 == -1)) {
          if (iVar3 == -1) {
            g_2984 = g_2984 + 1;
            if (1 < g_2984 - g_2988) {
              fn_1b79_0284(uVar4,g_292a);
              *(undefined1 *)((int)g_2952 + 0xf) = 0;
              local_12 = 0;
              local_10 = (uint)g_2994;
              local_e = g_2a4b;
              local_a = g_2a4f;
              fn_1b79_0261(0x2b79,g_292a,0,&local_12);
              fn_1b79_027f(0x2b79,g_292a);
              g_298c = g_298c + 1;
            }
          }
          else {
            g_2988 = g_2984;
          }
          fn_16cf_05d0(1,0,uVar2);
        }
      }
      g_297c = 0;
      return 1;
    }
    if (g_297e != -1) {
      fn_1b79_0284(0x26cf,g_292a);
      *(undefined1 *)((int)g_2952 + 0xf) = 0;
      g_2a31 = 0;
      g_2a09 = 0;
      g_29e1 = 0;
      g_29b9 = 0;
      for (iVar3 = 1; iVar3 < 5; iVar3 = iVar3 + 1) {
        memset((int)((undefined4 *)&g_2a37)[iVar3],
                      (int)((ulong)((undefined4 *)&g_2a37)[iVar3] >> 0x10),0x80,
                      *(undefined2 *)((undefined4 *)&g_2a4f + iVar3));
      }
      g_297e = -1;
    }
    g_297c = 0;
  }
  return 0;
}


//// fn_16cf_04db @ 26cf:04db

int __cdecl16far fn_16cf_04db(long param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_16 [4];
  int local_12;
  undefined4 local_6;
  
  iVar1 = -1;
  if (param_1 == 0) {
    iVar2 = -1;
    iVar3 = 0;
    do {
      if ((((undefined2 *)&g_29b9)[iVar3 * 0x14] != 0) &&
         ((ulong)(long)iVar1 < *(ulong *)(iVar3 * 0x28 + 0x29a3))) {
        iVar1 = *(int *)(iVar3 * 0x28 + 0x29a3);
        iVar2 = iVar3;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
    if (iVar2 == -1) {
      iVar1 = 0;
    }
  }
  else {
    iVar2 = 0;
    do {
      local_6 = (long *)CONCAT22(0x3e2d,(long *)(iVar2 * 0x28 + 0x2997));
      if ((*local_6 == param_1) && (((undefined2 *)&g_29b9)[iVar2 * 0x14] != 0)) {
        iVar1 = *(int *)(iVar2 * 0x28 + 0x29a3);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 4);
    if (iVar1 == -1) {
      fn_2279_025b(param_1,local_16);
      iVar1 = local_12;
    }
  }
  return iVar1;
}


//// fn_16cf_057a @ 26cf:057a

undefined2 __cdecl16far fn_16cf_057a(long param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_6;
  
  if (param_1 != 0) {
    iVar2 = 0;
    do {
      iVar1 = iVar2 * 0x28;
      local_6 = (long *)CONCAT22(0x3e2d,(long *)(iVar1 + 0x2997));
      if (*local_6 == param_1) {
        if (((undefined2 *)&g_29b9)[iVar2 * 0x14] == 0) {
          return 0xffff;
        }
        return (int)(*(ulong *)(iVar1 + 0x29a7) / (ulong)(long)*(int *)(iVar1 + 0x29b5));
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 4);
  }
  return 0xffff;
}


//// fn_16cf_05d0 @ 26cf:05d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl16far fn_16cf_05d0(char param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  ulong uVar4;
  undefined2 uVar5;
  ulong in_EDX;
  undefined4 *puVar6;
  int iVar7;
  undefined2 uVar8;
  uint local_24;
  uint local_22;
  undefined4 local_20;
  ulong local_1c;
  undefined4 local_18;
  byte local_14 [4];
  int local_10;
  undefined4 local_e;
  undefined4 local_a;
  ulong local_6;
  
  if (param_1 == '\0') {
    if (g_297e == -1) {
      local_18._0_2_ = (undefined4 *)(param_2 * 0x28 + 0x2997);
      local_18._2_2_ = 0x3e2d;
      do {
        while( true ) {
          uVar8 = (undefined2)in_EDX;
          if (((undefined4 *)local_18)[1] == 0) goto LAB_26cf_08cd;
          uVar5 = fn_16cf_0a05((int)((undefined4 *)local_18)[1],
                                (int)((ulong)((undefined4 *)local_18)[1] >> 0x10),local_14);
          uVar8 = (undefined2)in_EDX;
          *(undefined2 *)((int)(undefined4 *)local_18 + 6) = uVar8;
          *(undefined2 *)((undefined4 *)local_18 + 1) = uVar5;
          if (local_10 != -0x3000) break;
          local_14[1] = 0xd3;
          local_24 = (uint)local_14[0];
          local_22 = (uint)g_2994;
          *(undefined1 *)((int)(undefined4 *)local_18 + 0x1d) = 0xd3;
          g_2980 = 0x172;
          *(undefined2 *)((int)(undefined4 *)local_18 + 0x1e) = 0x172;
          in_EDX = (ulong)((long)g_2992 * 0x172) >> 0x10;
          g_2982 = (undefined2)((long)g_2992 * 0x172);
        }
        if (local_10 == -0x1000) goto LAB_26cf_08cd;
      } while (local_10 != 0);
      ((undefined4 *)local_18)[1] = 0;
LAB_26cf_08cd:
      uVar5 = fn_2037_0002((int)*(undefined4 *)local_18,
                            (int)((ulong)*(undefined4 *)local_18 >> 0x10),
                            (int)((undefined4 *)local_18)[4],
                            (int)((ulong)((undefined4 *)local_18)[4] >> 0x10));
      local_a = CONCAT22(uVar8,uVar5);
      local_e = g_2a37;
      local_20 = g_2a4b;
      local_6 = ((undefined4 *)local_18)[5] - ((undefined4 *)local_18)[4];
      local_1c = local_6;
      if (g_2a53 <= local_6) {
        local_1c = g_2a53;
      }
      fn_2279_025b(uVar5,uVar8,(int)g_2a37,(int)((ulong)g_2a37 >> 0x10),(int)local_1c
                    ,(int)(local_1c >> 0x10));
      fn_1bbe_050c((int)local_e,(int)((ulong)local_e >> 0x10),(int)local_1c,
                    *(undefined2 *)((undefined4 *)local_18 + 8));
      if (local_1c < g_2a53) {
        uVar5 = fn_2037_0002((int)local_e,(int)((ulong)local_e >> 0x10),(int)local_1c,
                              (int)(local_1c >> 0x10),0x80,g_2a53 - (int)local_1c);
        memset(uVar5,uVar8);
      }
      ((undefined4 *)local_18)[4] = ((undefined4 *)local_18)[4] + local_1c;
      local_1c = g_2a4f;
      fn_1bbe_05bc((int)local_e,(int)((ulong)local_e >> 0x10),g_2a53);
      if ((ulong)((undefined4 *)local_18)[4] < (ulong)((undefined4 *)local_18)[5]) {
        *(undefined2 *)((int)(undefined4 *)local_18 + 0x22) = 3;
      }
      else {
        *(undefined2 *)((int)(undefined4 *)local_18 + 0x22) = 1;
      }
      uVar2 = *(undefined4 *)((int)g_2a75 + 4);
      memset((int)uVar2,(int)((ulong)uVar2 >> 0x10),0x80,g_2a53);
      fn_1b79_0261(0x1000,g_292a,0,&local_24);
      fn_16cf_0181(param_2);
      uVar4 = (ulong)g_2a79 >> 0x10;
      puVar3 = (undefined1 *)g_2a79;
      *g_2a79 = 1;
      puVar3[1] = 0;
    }
  }
  else {
    for (iVar7 = 0; iVar7 < 4; iVar7 = iVar7 + 1) {
      local_18 = (undefined4 *)CONCAT22(0x3e2d,(undefined4 *)(iVar7 * 0x28 + 0x2997));
      if (((undefined2 *)&g_29b9)[iVar7 * 0x14] != 0) {
        do {
          while( true ) {
            uVar8 = (undefined2)((ulong)local_18 >> 0x10);
            if (((undefined4 *)local_18)[1] == 0) goto LAB_26cf_06b3;
            uVar2 = ((undefined4 *)local_18)[1];
            uVar8 = fn_16cf_0a05((int)uVar2,(int)((ulong)uVar2 >> 0x10),local_14);
            uVar5 = (undefined2)((ulong)local_18 >> 0x10);
            puVar6 = (undefined4 *)local_18;
            *(undefined2 *)((int)puVar6 + 6) = (int)in_EDX;
            *(undefined2 *)(puVar6 + 1) = uVar8;
            if (local_10 != -0x3000) break;
            local_14[1] = 0xd3;
            local_24 = (uint)local_14[0];
            local_22 = (uint)g_2994;
            *(undefined1 *)((int)puVar6 + 0x1d) = 0xd3;
            g_2980 = 0x172;
            *(undefined2 *)((int)puVar6 + 0x1e) = 0x172;
            in_EDX = (ulong)((long)g_2992 * 0x172) >> 0x10;
            g_2982 = (undefined2)((long)g_2992 * 0x172);
          }
          if (local_10 == -0x1000) goto LAB_26cf_06b3;
        } while (local_10 != 0);
        puVar6[1] = 0;
LAB_26cf_06b3:
        uVar8 = ((undefined2 *)&g_2a3d)[iVar7 * 2];
        uVar1 = ((undefined2 *)&g_2a3b)[iVar7 * 2];
        in_EDX = (ulong)uVar1;
        local_e = CONCAT22(uVar8,uVar1);
        uVar5 = (undefined2)((ulong)local_18 >> 0x10);
        puVar6 = (undefined4 *)local_18;
        if ((ulong)puVar6[4] < (ulong)puVar6[5]) {
          uVar8 = fn_2037_0002((int)*local_18,(int)((ulong)*local_18 >> 0x10),(int)puVar6[4],
                                (int)((ulong)puVar6[4] >> 0x10));
          local_a = CONCAT22((int)in_EDX,uVar8);
          local_20 = g_2a4b;
          uVar5 = (undefined2)((ulong)local_18 >> 0x10);
          local_6 = ((undefined4 *)local_18)[5] - ((undefined4 *)local_18)[4];
          local_1c = local_6;
          if (g_2a53 <= local_6) {
            local_1c = g_2a53;
          }
          fn_2279_025b(uVar8,(int)in_EDX,(int)local_e,(int)((ulong)local_e >> 0x10),(int)local_1c,
                        (int)(local_1c >> 0x10));
          fn_1bbe_050c((int)local_e,(int)((ulong)local_e >> 0x10),(int)local_1c,
                        *(undefined2 *)((undefined4 *)local_18 + 8));
          if (local_1c < g_2a53) {
            uVar8 = fn_2037_0002((int)local_e,(int)((ulong)local_e >> 0x10),(int)local_1c,
                                  (int)(local_1c >> 0x10),0x80,g_2a53 - (int)local_1c);
            memset(uVar8,(int)in_EDX);
          }
          ((undefined4 *)local_18)[4] = ((undefined4 *)local_18)[4] + local_1c;
          local_1c = g_2a53;
        }
        else {
          *(undefined2 *)((int)puVar6 + 0x22) = 1;
          memset(uVar1,uVar8,0x80,g_2a53);
        }
      }
    }
    uVar2 = *(undefined4 *)((int)g_2a75 + param_3 * 4);
    fn_1bbe_05e1((int)g_2a3b,(int)((ulong)g_2a3b >> 0x10),(int)uVar2,
                  (int)((ulong)uVar2 >> 0x10),g_2a53);
    ((undefined1 *)g_2a79)[param_3] = 1;
    param_3 = param_3 + 1;
    if (g_2a7d <= param_3) {
      param_3 = 0;
    }
    ((undefined1 *)g_2a79)[param_3] = 0;
    uVar2 = *(undefined4 *)((int)g_2a75 + param_3 * 4);
    memset((int)uVar2,(int)((ulong)uVar2 >> 0x10),0x80,g_2a53);
  }
  return g_29b9 | g_29e1 | g_2a09 | g_2a31;
}


//// fn_16cf_0a05 @ 26cf:0a05

int __cdecl16far fn_16cf_0a05(undefined4 param_1,undefined4 *param_2,uint *param_3)

{
  undefined4 local_6;
  
  fn_2279_025b(param_1,&local_6);
  *param_3 = local_6._2_2_ & 0xf000;
  local_6 = CONCAT22(local_6._2_2_ ^ *param_3,(undefined2)local_6);
  *param_2 = local_6;
  return (int)param_1 + -4;
}


//// fn_16cf_0a4b @ 26cf:0a4b

void __cdecl16far fn_16cf_0a4b(undefined4 param_1,int param_2)

{
  undefined4 local_16;
  undefined4 local_12;
  undefined4 local_e;
  int local_6;
  undefined2 uStack_4;
  
  fn_2279_025b(param_1,&local_16);
  param_2 = param_2 * 0x28;
  _local_6 = CONCAT22(0x3e2d,param_2 + 0x2997);
  *(undefined4 *)(param_2 + 0x29a3) = local_12;
  *(undefined4 *)(param_2 + 0x29ab) = local_e;
  fn_2037_0002(param_1,local_16);
  return;
}


//// fn_16cf_0a9b @ 26cf:0a9b

undefined2 __cdecl16far fn_16cf_0a9b(undefined4 param_1,undefined4 *param_2,int param_3)

{
  undefined2 uVar1;
  undefined2 in_DX;
  int local_4;
  
  do {
    uVar1 = fn_16cf_0a05(param_1,param_2,&local_4);
    param_1 = CONCAT22(in_DX,uVar1);
    if (local_4 == 0) {
      *param_2 = 0;
      return 0;
    }
  } while (local_4 != param_3);
  return uVar1;
}


//// fn_16cf_0ae2 @ 26cf:0ae2

undefined2 __cdecl16far fn_16cf_0ae2(long param_1,int param_2,undefined2 param_3)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_a;
  undefined4 local_6;
  
  if ((param_1 != 0) && (g_2a6f != 0)) {
    iVar3 = -1;
    iVar2 = 0;
    while ((iVar2 < 4 && (iVar3 == -1))) {
      if (((undefined2 *)&g_29b9)[iVar2 * 0x14] == 0) {
        iVar3 = iVar2;
      }
      iVar2 = iVar2 + 1;
    }
    iVar2 = 0;
    while ((iVar2 < 4 && (iVar3 == -1))) {
      if ((int)((undefined2 *)&g_29b1)[iVar2 * 0x14] <= param_2) {
        iVar3 = iVar2;
      }
      iVar2 = iVar2 + 1;
    }
    if (iVar3 != -1) {
      iVar2 = iVar3 * 0x28;
      local_a = (undefined2 *)CONCAT22(0x3e2d,(undefined2 *)(iVar2 + 0x2997));
      memset();
      ((undefined2 *)&g_29b1)[iVar3 * 0x14] = param_2;
      *(undefined2 *)(iVar2 + 0x29b7) = param_3;
      *(undefined2 *)(iVar2 + 0x2999) = param_1._2_2_;
      *local_a = (undefined2)param_1;
      uVar1 = fn_16cf_0a4b((undefined2)param_1,param_1._2_2_,iVar3);
      *(undefined2 *)(iVar2 + 0x299d) = (undefined2)param_1;
      *(undefined2 *)(iVar2 + 0x299b) = uVar1;
      uVar1 = fn_16cf_0a9b(*(undefined4 *)(iVar2 + 0x299b),&local_6);
      *(undefined2 *)(iVar2 + 0x299d) = (undefined2)param_1;
      *(undefined2 *)(iVar2 + 0x299b) = uVar1;
      if (*(long *)(iVar2 + 0x299b) != 0) {
        *(undefined4 *)(iVar2 + 0x29a7) = local_6;
        *(undefined2 *)(iVar2 + 0x29b5) = g_2980;
        ((undefined2 *)&g_29b9)[iVar3 * 0x14] = 2;
        fn_16cf_05d0(0,iVar3,0);
        return 1;
      }
    }
  }
  return 0;
}

