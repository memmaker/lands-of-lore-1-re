//// fn_15a7_0004 @ 25a7:0004

undefined2 __cdecl16far fn_15a7_0004(long param_1,ulong param_2)

{
  undefined2 uVar1;
  undefined2 in_DX;
  undefined2 local_32;
  undefined2 uStack_30;
  undefined4 local_2e;
  long local_2a;
  long local_26;
  undefined4 local_22;
  undefined4 local_1e;
  long local_1a;
  undefined2 local_16;
  undefined4 local_14;
  
  if ((param_1 == 0) || ((param_2 & 0xfffffff0) == 0)) {
    uVar1 = 0;
  }
  else {
    local_2a = (long)((param_2 & 0xfffffff0) - 0x10) >> 4;
    local_2e = 0;
    uVar1 = fn_2037_0002(param_1,0x10);
    _local_32 = CONCAT22(in_DX,uVar1);
    local_26 = local_2a;
    fn_2279_025b(&local_32);
    local_22 = 0;
    local_1e = 0;
    local_1a = local_2a;
    local_14 = 0xffffffff;
    local_16 = 0;
    fn_2279_025b(&local_22);
    uVar1 = 1;
  }
  return uVar1;
}


//// fn_15a7_00b0 @ 25a7:00b0

undefined2 __cdecl16far fn_15a7_00b0(long param_1,long param_2)

{
  bool bVar1;
  undefined2 uVar2;
  long local_3e [2];
  ulong local_36;
  long local_1e [2];
  long local_16;
  ulong local_12;
  ulong local_e;
  long local_a;
  long local_6;
  
  local_6 = 0;
  if ((param_1 != 0) && (param_2 != 0)) {
    fn_2279_025b((int)param_1,(int)((ulong)param_1 >> 0x10),local_1e);
    local_e = param_2 + 0x2f >> 4;
    if (local_e <= local_12) {
      local_3e[0] = local_1e[0];
      bVar1 = false;
      do {
        if (local_3e[0] == 0) goto LAB_25a7_0151;
        local_a = local_3e[0];
        fn_2279_025b((int)local_3e[0],(int)((ulong)local_3e[0] >> 0x10),local_3e);
      } while (local_36 < local_e);
      bVar1 = true;
LAB_25a7_0151:
      if (bVar1) {
        local_6 = local_36 - local_e;
        if (local_6 < 3) {
          local_6 = 0;
          local_e = local_36;
        }
        fn_15a7_064a(local_1e);
        if (local_6 != 0) {
          fn_2037_0002(local_a,(int)(local_e << 4),(int)((local_e << 4) >> 0x10),(int)local_6,
                        (int)((ulong)local_6 >> 0x10),0xffff,0xffff,0);
          fn_15a7_06e9(local_1e);
        }
        fn_15a7_06e9(local_1e);
        local_16 = local_16 - local_e;
        fn_2279_025b(local_1e);
        uVar2 = fn_2037_0002((int)local_a,(int)((ulong)local_a >> 0x10),0x20,0);
        return uVar2;
      }
    }
  }
  return 0;
}


//// fn_15a7_0210 @ 25a7:0210

undefined2 __cdecl16far fn_15a7_0210(long param_1,long param_2)

{
  undefined2 uVar1;
  undefined2 in_DX;
  undefined1 local_36 [8];
  long local_2e;
  undefined1 local_16 [8];
  long local_e;
  undefined2 local_6;
  
  if ((param_2 == 0) || (param_1 == 0)) {
    uVar1 = 0;
  }
  else {
    fn_2279_025b((int)param_1,(int)((ulong)param_1 >> 0x10),local_16);
    local_6 = fn_2037_0002((int)param_2,(int)((ulong)param_2 >> 0x10),0xffe0,0xffff);
    fn_2279_025b(local_6,in_DX,local_36);
    fn_15a7_064a(local_16);
    fn_15a7_06e9(local_16);
    local_e = local_e + local_2e;
    fn_2279_025b(local_16);
    uVar1 = 1;
  }
  return uVar1;
}


//// fn_15a7_02b6 @ 25a7:02b6

void __cdecl16far fn_15a7_02b6(long param_1)

{
  undefined2 uVar1;
  undefined2 in_DX;
  undefined2 local_4;
  
  if (param_1 != 0) {
    uVar1 = fn_2037_0002(param_1,0xffffffe0);
    fn_2037_0002(uVar1,in_DX,0xc);
    local_4 = (undefined2)(g_384c >> 4);
    fn_2279_025b(&local_4);
  }
  return;
}


//// fn_15a7_030c @ 25a7:030c

undefined2 __cdecl16far fn_15a7_030c(long param_1,long param_2)

{
  undefined2 uVar1;
  long local_36 [3];
  long local_28;
  undefined1 local_16 [4];
  long local_12;
  long local_6;
  
  if ((param_1 != 0) && (fn_2279_025b(param_1,local_16), local_12 != 0)) {
    local_36[0] = local_12;
    while (local_36[0] != 0) {
      local_6 = local_36[0];
      fn_2279_025b(local_36[0],local_36);
      if (local_28 == param_2) {
        uVar1 = fn_2037_0002(local_6,0x20);
        return uVar1;
      }
    }
  }
  return 0;
}


//// fn_15a7_0382 @ 25a7:0382

undefined2 __cdecl16far fn_15a7_0382(long param_1)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  undefined2 in_DX;
  ulong local_3a [3];
  uint local_2e;
  undefined1 local_1a [4];
  ulong local_16;
  ulong local_a;
  ulong local_6;
  
  if (param_1 == 0) {
    local_a._0_2_ = 0;
  }
  else {
    fn_2279_025b(param_1,local_1a);
    local_a = 0;
    local_3a[0] = local_16;
    uVar3 = 0;
    while (local_3a[0] != 0) {
      local_6 = local_3a[0];
      fn_2279_025b(local_3a[0],local_3a);
      uVar1 = fn_2037_0002(local_6,0x20);
      iVar2 = fn_16cf_057a(uVar1,in_DX);
      if ((iVar2 == -1) && ((local_2e < uVar3 || (local_a == 0)))) {
        local_a = local_6;
        uVar3 = local_2e;
      }
    }
    if (local_a != 0) {
      uVar3 = fn_2037_0002(local_a,0x20);
      local_a = (ulong)uVar3;
    }
  }
  return (undefined2)local_a;
}


//// fn_15a7_043c @ 25a7:043c

undefined2 __cdecl16far fn_15a7_043c(long param_1)

{
  int iVar1;
  undefined2 in_DX;
  undefined1 local_16 [4];
  long local_12;
  undefined2 local_6;
  
  if (param_1 != 0) {
    fn_2279_025b(param_1,local_16);
    if (local_12 != 0) {
      fn_0845_08a5((char *)s_Mem_free_oldest_from__lX_used_ch_3e2d_2866,0x3e2d,0x28,0x1000f,param_1
                    ,local_12);
    }
    local_6 = fn_15a7_0382(param_1);
    iVar1 = fn_15a7_0210(param_1,local_6,in_DX);
    if (iVar1 != 0) {
      return local_6;
    }
  }
  return 0;
}


//// fn_15a7_04b0 @ 25a7:04b0

undefined2 __cdecl16far fn_15a7_04b0(long param_1)

{
  undefined2 uVar1;
  long lVar2;
  undefined1 local_16 [8];
  long local_e;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    fn_2279_025b(param_1,local_16);
    lVar2 = local_e * 0x10 + -0x2f;
    if (lVar2 < 1) {
      lVar2 = 0;
    }
    uVar1 = (undefined2)lVar2;
  }
  return uVar1;
}


//// fn_15a7_0501 @ 25a7:0501

void __cdecl16far fn_15a7_0501(long param_1)

{
  undefined2 uVar1;
  undefined2 in_DX;
  undefined4 local_42;
  long local_3e;
  long local_3a;
  long local_22;
  long local_1e;
  long local_1a;
  long local_12;
  undefined4 local_e;
  long local_a;
  long local_6;
  
  if (param_1 != 0) {
    uVar1 = (undefined2)((ulong)param_1 >> 0x10);
    fn_2279_025b((int)param_1,uVar1,&local_22);
    if ((local_1a != 0) && (local_22 != 0)) {
      local_a = 0;
      local_6 = local_1e;
      uVar1 = fn_2037_0002((int)param_1,uVar1,0x10,0);
      local_e = CONCAT22(in_DX,uVar1);
      local_1e = local_e;
      while (local_6 != 0) {
        fn_2279_025b((int)local_6,(int)((ulong)local_6 >> 0x10),&local_42);
        local_12 = local_3a << 4;
        if (local_6 != local_e) {
          fn_2279_025b((int)local_6,(int)((ulong)local_6 >> 0x10),(int)local_e,
                        (int)((ulong)local_e >> 0x10),(int)local_12,(int)((ulong)local_12 >> 0x10));
        }
        local_6 = local_42;
        if (local_42 != 0) {
          uVar1 = fn_2037_0002((int)local_e,(int)((ulong)local_e >> 0x10),(int)local_12,
                                (int)((ulong)local_12 >> 0x10));
          local_42 = CONCAT22(in_DX,uVar1);
        }
        local_3e = local_a;
        fn_2279_025b(&local_42);
        local_a = local_e;
        uVar1 = fn_2037_0002((int)local_e,(int)((ulong)local_e >> 0x10),(int)local_12,
                              (int)((ulong)local_12 >> 0x10));
        local_e = CONCAT22(in_DX,uVar1);
      }
      local_22 = 0;
      fn_15a7_06e9(&local_22);
      fn_2279_025b(&local_22);
    }
  }
  return;
}


//// fn_15a7_064a @ 25a7:064a

void __cdecl16far fn_15a7_064a(long *param_1,int param_2,long param_3)

{
  long local_26;
  long local_22 [7];
  long *local_6;
  
  if ((param_1 != (long *)0x0) && (param_3 != 0)) {
    if (param_2 == 0) {
      local_6 = (long *)CONCAT22((int)((ulong)param_1 >> 0x10),(long *)param_1 + 1);
    }
    else {
      local_6 = param_1;
    }
    fn_2279_025b(param_3,&local_26);
    if (local_22[0] == 0) {
      *local_6 = local_26;
    }
    else {
      fn_2279_025b(&local_26);
    }
    if (local_26 != 0) {
      fn_2037_0002(local_26,4,4);
      fn_2279_025b(local_22);
    }
  }
  return;
}


//// fn_15a7_06e9 @ 25a7:06e9

void __cdecl16far
fn_15a7_06e9(ulong *param_1,int param_2,ulong param_3,long param_4,undefined4 param_5,int param_6)

{
  bool bVar1;
  int iVar2;
  ulong *in_DX;
  ulong local_52 [2];
  long local_4a;
  ulong local_32;
  ulong local_2e;
  long local_2a;
  undefined2 local_26;
  undefined4 local_24;
  long local_12;
  undefined4 local_e;
  ulong local_a;
  ulong *local_6;
  
  local_a = 0;
  local_e = 0;
  bVar1 = true;
  if (((param_1 != (ulong *)0x0) && (param_3 != 0)) && (param_4 != 0)) {
    if (param_2 == 0) {
      in_DX = (ulong *)param_1 + 1;
      local_6 = (ulong *)CONCAT22((int)((ulong)param_1 >> 0x10),in_DX);
    }
    else {
      local_6 = param_1;
    }
    if (*local_6 != 0) {
      local_e = *local_6;
      do {
        fn_2279_025b(local_e,&local_32);
        do {
          if ((local_e == 0) || (param_3 <= local_e)) {
            if (param_6 != 0) {
              local_12 = param_4;
              if (local_a != 0) {
                iVar2 = fn_2037_0002(local_a,local_4a << 4);
                local_12 = param_4;
                if ((in_DX == param_3._2_2_) && (iVar2 == (int)param_3)) {
                  local_4a = local_4a + param_4;
                  fn_2279_025b(local_52);
                  param_3 = local_a;
                  local_a = 0;
                  bVar1 = false;
                  local_12 = local_4a;
                }
              }
              if (local_e != 0) {
                iVar2 = fn_2037_0002(param_3,local_12 << 4);
                if ((in_DX == local_e._2_2_) && (iVar2 == (int)local_e)) {
                  if (bVar1) {
                    local_e = local_32;
                    param_4 = param_4 + local_2a;
                  }
                  else {
                    local_4a = local_4a + local_2a;
                    local_52[0] = local_32;
                    fn_2279_025b(local_52);
                    local_e = local_32;
                  }
                }
              }
            }
            if (local_a == 0) {
              if (bVar1) {
                *local_6 = param_3;
              }
            }
            else {
              fn_2279_025b(&param_3);
            }
            if (local_e != 0) {
              fn_2037_0002(local_e,4,4);
              fn_2279_025b(&param_3);
            }
            if (!bVar1) {
              return;
            }
            local_2e = local_a;
            local_32 = local_e;
            local_2a = param_4;
            local_26 = (undefined2)(g_384c >> 4);
            local_24 = param_5;
            fn_2279_025b(&local_32);
            return;
          }
          fn_2279_025b(&local_32);
          local_a = local_e;
          local_e = local_32;
        } while (local_32 == 0);
      } while( true );
    }
    local_32 = 0;
    local_2e = 0;
    local_2a = param_4;
    local_26 = (undefined2)(g_384c >> 4);
    local_24 = param_5;
    fn_2279_025b(&local_32);
    *local_6 = param_3;
  }
  return;
}

