//// fn_154c_000f @ 254c:000f

void __cdecl16far fn_154c_000f(int param_1)

{
  int iVar1;
  
  iVar1 = fn_16cf_057a(g_abbe);
  if (-1 < iVar1) {
    g_aba4 = 0;
    g_abac = 0;
    g_2138 = 0;
    fn_16cf_00b9(g_abbe);
    if (param_1 != 0) {
      g_abb8 = 1;
    }
  }
  return;
}


//// fn_154c_0057 @ 254c:0057

undefined2 __cdecl16far fn_154c_0057(undefined2 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  if (param_2 == 1) {
    if (g_7fe3 == '\0') {
      iVar1 = 0;
    }
    else {
      iVar1 = (int)g_7fe3;
    }
  }
  else if (param_2 < 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2;
    if (param_2 != 0) {
      iVar2 = 0;
      do {
        if ((*(int *)((int)(undefined2 *)&g_363a + iVar2 * 0x82 + 1) == param_2) &&
           (iVar1 = iVar2,
           (*(uint *)((int)(undefined4 *)&g_362a + iVar2 * 0x82 + 3) & 1) != 0)) break;
        iVar2 = iVar2 + 1;
        iVar1 = param_2;
      } while (iVar2 < 4);
      if (iVar2 == 4) {
        return 0;
      }
    }
  }
  iVar2 = fn_154c_01d3(param_1,iVar1,0);
  if ((iVar2 != 0) && (param_3 != 0)) {
    fn_130a_0784();
    g_4bfa = 0;
    g_4c00 = 1;
    g_20f6 = 0;
    g_4bf8 = iVar1;
    fn_130a_0605();
  }
  if ((iVar2 == 0) || (g_81fd._1_1_ != '\0')) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


//// fn_154c_010f @ 254c:010f

undefined2 __cdecl16far fn_154c_010f(int param_1,int param_2)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    g_aba4 = param_1 + 1000;
    g_aba6 = (undefined1)param_2;
    g_aba7 = 0;
  }
  return 1;
}


//// fn_154c_0136 @ 254c:0136

undefined2 __cdecl16far fn_154c_0136(void)

{
  long lVar1;
  int iVar2;
  
  iVar2 = fn_16cf_057a(g_abbe);
  lVar1 = g_384c;
  if (iVar2 == -1) {
    iVar2 = 0;
    g_2864 = 0xffff;
    g_2862 = 0xffff;
    if (g_abac != 0) {
      iVar2 = fn_154c_01d3(g_abb0,(int)g_abb2,(int)g_abb3);
    }
    if ((iVar2 == 0) && (g_aba4 != 0)) {
      iVar2 = fn_154c_01d3(g_aba4,(int)g_aba6,(int)g_aba7);
      g_aba4 = 0;
    }
    if (iVar2 == 0) {
      iVar2 = fn_16cf_022f();
      if (iVar2 != 0) {
        return 1;
      }
      return 0;
    }
    g_213c = g_384c - lVar1;
  }
  return 2;
}


//// fn_154c_01d3 @ 254c:01d3

undefined2 __cdecl16far fn_154c_01d3(uint param_1,undefined2 param_2,undefined2 param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  int iVar5;
  
  cVar1 = fn_154c_057b();
  iVar2 = (int)cVar1;
  if ((g_2862 == param_1) && (g_2864 == iVar2)) {
    uVar4 = 1;
  }
  else {
    iVar5 = g_abc4;
    iVar3 = g_abc2;
    if ((param_1 & 0x4000) != 0) {
      iVar5 = g_abc8;
      iVar3 = g_abc6;
    }
    if ((iVar3 == 0 && iVar5 == 0) || (g_81ff == '\0')) {
      uVar4 = 0;
    }
    else {
      while ((iVar5 = fn_16cf_022f(), iVar5 != 0 &&
             (iVar5 = fn_16cf_057a(g_abbe), iVar5 != -1))) {
        fn_0845_093a();
      }
      iVar5 = fn_154c_029f(g_abbe,(int)g_abca,(int)((ulong)g_abca >> 0x10),
                            param_1,iVar2,param_3);
      uVar4 = 0;
      if (iVar5 != 0) {
        g_2862 = param_1;
        g_2864 = iVar2;
        uVar4 = fn_16cf_0022((int)g_abbe,(int)((ulong)g_abbe >> 0x10),0xff,
                              (g_81ff * 200) / 100 + 0x37);
        g_abb8 = 0;
      }
    }
  }
  return uVar4;
}


//// fn_154c_029f @ 254c:029f

undefined2 __cdecl16far fn_154c_029f(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  long lVar4;
  undefined4 uVar5;
  undefined2 local_16 [2];
  int local_12;
  char local_10;
  long local_e;
  int local_a;
  char local_8;
  long local_6;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    if (g_abac == 0) {
      uVar1 = fn_154c_040d(&local_12);
      if (uVar1 == 0) {
        g_abac = 0;
        return 0;
      }
    }
    else {
      uVar1 = (uint)g_abac;
      fn_2279_025b((undefined2 *)&g_abb0,0x3e2d,&local_12);
    }
    g_abac = (ulong)uVar1 + 8;
    uVar3 = g_abc4;
    uVar2 = g_abc2;
    if ((param_3 & 0x4000) != 0) {
      uVar3 = g_abc8;
      uVar2 = g_abc6;
    }
    uVar2 = fn_2037_0002(uVar2,uVar3,g_abac,&local_a);
    fn_2279_025b(uVar2,uVar3);
    if ((local_a == local_12) && (local_8 == local_10)) {
      fn_2279_025b(&local_a);
    }
    else {
      g_abac = 0;
    }
    lVar4 = local_6 - local_e;
    uVar3 = g_abc4;
    uVar2 = g_abc2;
    if ((param_3 & 0x4000) != 0) {
      uVar3 = g_abc8;
      uVar2 = g_abc6;
    }
    fn_2279_025b(uVar2,uVar3,local_16);
    fn_1809_0e76(local_16[0],(int)local_e,(int)((ulong)local_e >> 0x10),0);
    uVar3 = fn_2dc6_0020((char *)s_FINALE_EXE_3e2d_2803 + 6,local_16[0]);
    uVar5 = fn_2dc6_0025(0x3dc6,lVar4,uVar3);
    lVar4 = fn_2dc6_002f(0x3dc6,local_16[0],uVar5,(int)param_1,(int)((ulong)param_1 >> 0x10),
                          (int)param_2,(int)((ulong)param_2 >> 0x10));
    if (lVar4 != 0) {
      return 1;
    }
  }
  return 0;
}


//// fn_154c_03fc @ 254c:03fc

int __cdecl16far fn_154c_03fc(int *param_1,int *param_2)

{
  return *param_1 - *param_2;
}


//// fn_154c_040d @ 254c:040d

int __cdecl16far fn_154c_040d(uint *param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  uint *puVar5;
  undefined4 local_1e;
  undefined4 local_1a;
  undefined1 local_16 [8];
  undefined4 local_e;
  undefined4 local_a;
  undefined1 local_6 [2];
  int local_4;
  
  uVar4 = g_abc4;
  iVar1 = g_abc2;
  if ((param_2 & 0x4000) != 0) {
    uVar4 = g_abc8;
    iVar1 = g_abc6;
  }
  local_1e = CONCAT22(uVar4,iVar1);
  fn_2279_025b(iVar1,uVar4,local_6);
  uVar2 = fn_2037_0002(local_1e,4);
  local_a = CONCAT22(uVar4,uVar2);
  *param_1 = param_2;
  fn_2037_0002(uVar2,uVar4,8,local_4 + -2,8,0x3fc,0x254c);
  uVar2 = fn_242d_000f(param_1,local_16);
  local_1a = CONCAT22(uVar4,uVar2);
  if (local_1a != 0) {
    fn_2279_025b(local_1a,param_1,8);
    uVar2 = (undefined2)((ulong)param_1 >> 0x10);
    puVar5 = (uint *)param_1;
    if ((char)puVar5[1] == '_') {
LAB_254c_0567:
      while (*(char *)((int)puVar5 + 3) != '\0') {
        uVar3 = fn_2037_0002(local_1a,0xfffffff8);
        local_1a = CONCAT22(uVar4,uVar3);
        fn_2279_025b(uVar3,uVar4,param_1,8);
      }
      return (int)local_1a - iVar1;
    }
    local_e = 8;
    if (param_3 < (char)puVar5[1]) {
      local_e = 0xfffffff8;
    }
    do {
      if (((char)puVar5[1] == param_3) || (*param_1 != param_2)) goto LAB_254c_0567;
      uVar3 = fn_2037_0002(local_1a,local_e);
      local_1a = CONCAT22(uVar4,uVar3);
      fn_2279_025b(uVar3,uVar4,param_1,8);
    } while ((char)puVar5[1] != '0');
  }
  fn_2279_025b(local_a,param_1,8);
  return 0;
}


//// fn_154c_057b @ 254c:057b

uint __cdecl16far fn_154c_057b(uint param_1)

{
  if ((int)param_1 < 0x41) {
    if ((*(uint *)((int)(undefined4 *)&g_362a + param_1 * 0x82 + 3) & 1) == 0) {
      param_1 = 0;
    }
    else {
      param_1 = CONCAT11(0x38,*(undefined1 *)
                               ((int)(undefined2 *)&g_362e + param_1 * 0x82 + 1));
    }
  }
  else {
    param_1 = param_1 & 0xff;
  }
  return param_1;
}

