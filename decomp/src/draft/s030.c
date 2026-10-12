//// fn_178d_0038 @ 278d:0038

uint __cdecl16far fn_178d_0038(void)

{
  code *pcVar1;
  code *pcVar2;
  int iVar3;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0;
  if (g_28fa == -1) {
    if (g_2908 != (code *)0x0) {
      local_8 = g_2908;
      pcVar2 = local_8;
      local_8._0_2_ = (code *)g_2908;
      pcVar1 = (code *)local_8;
      local_8 = pcVar2;
      local_4 = (*pcVar1)(0x278d,(uint)(in_NT & 1) * 0x4000 | (uint)(in_IF & 1) * 0x200 |
                                 (uint)(in_TF & 1) * 0x100 | (uint)((long)g_2908 < 0) * 0x80
                                 | (uint)(in_AF & 1) * 0x10 |
                                 (uint)((POPCOUNT((ulong)g_2908 & 0xff) & 1U) == 0) * 4);
    }
  }
  else if (g_2922 != -1) {
    iVar3 = fn_1b79_02ef(0x278d,g_28fa,g_2922);
    local_4 = (uint)(iVar3 == 1);
  }
  return local_4;
}


//// fn_178d_0091 @ 278d:0091

void __cdecl16far fn_178d_0091(undefined2 param_1)

{
  fn_178d_00a4(param_1,0xff);
  return;
}


//// fn_178d_00a4 @ 278d:00a4

void __cdecl16far fn_178d_00a4(int param_1,uint param_2)

{
  undefined2 uVar1;
  int iVar2;
  
  uVar1 = 0x278d;
  if (((-1 < param_1) && (param_1 < 0xfb)) && (g_35e4 != 0)) {
    if (g_28fa == -1) {
      if (g_2908 != 0) {
        fn_178d_01ef((undefined2 *)&g_28fa,0x3e2d,param_1,param_2);
      }
    }
    else {
      if (g_2922 != -1) {
        iVar2 = g_2922;
        fn_1b79_02e3();
        uVar1 = 0x2b79;
        fn_1b79_02b1(0x2b79,g_28fa,g_2922,iVar2);
        g_2922 = -1;
      }
      g_2922 = fn_1b79_02ac(uVar1,g_28fa,g_2910,param_1,g_2924,0);
      fn_1b79_02dd(0x2b79,g_28fa,g_2922);
      fn_1b79_0301(0x2b79,g_28fa,g_2922,(int)((param_2 & 0xff) * 0x5a) >> 8,0);
    }
  }
  return;
}


//// fn_178d_015e @ 278d:015e

void __cdecl16far fn_178d_015e(void)

{
  if (g_28fa == -1) {
    if (g_2908 != 0) {
      fn_178d_01ef((undefined2 *)&g_28fa,0x3e2d,0);
    }
  }
  else if (g_2922 != -1) {
    fn_1b79_02e3(0x278d,g_28fa,g_2922);
    fn_1b79_02b1(0x2b79,g_28fa,g_2922);
    g_2922 = -1;
  }
  return;
}


//// fn_178d_01b0 @ 278d:01b0

void __cdecl16far fn_178d_01b0(void)

{
  if (g_28fa == -1) {
    if (g_2908 != 0) {
      fn_178d_01ef((undefined2 *)&g_28fa,0x3e2d,1);
    }
  }
  else if (g_2922 != -1) {
    fn_1b79_0301(0x278d,g_28fa,g_2922,0x7d00000);
  }
  return;
}


//// fn_178d_01ef @ 278d:01ef

void __cdecl16far fn_178d_01ef(undefined4 param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined2 uVar5;
  byte bVar6;
  byte bVar7;
  bool bVar8;
  byte in_AF;
  byte bVar9;
  byte bVar10;
  bool bVar11;
  byte in_TF;
  byte in_IF;
  byte bVar12;
  byte in_NT;
  uint uVar13;
  undefined4 local_8;
  uint local_4;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar4 = (int)param_1;
  local_8 = (code *)*(long *)(iVar4 + 0xe);
  if ((((param_2 != -1) && (local_8 != (code *)0x0)) && (*(long *)(iVar4 + 0x16) != 0)) &&
     (uVar1 = *(uint *)((int)*(undefined4 *)(iVar4 + 0x1e) + param_2 * 2), uVar1 != 0xffff)) {
    iVar4 = memcmp(0x278d,*(undefined4 *)(iVar4 + 2),0x2a9c,0x3e2d,4);
    if (iVar4 == 0) {
      do {
        uVar2 = (*(code *)local_8)(0x1000,(uint)(in_NT & 1) * 0x4000 | (uint)(in_IF & 1) * 0x200 |
                                          (uint)(in_TF & 1) * 0x100 | 0x40 |
                                          (uint)(in_AF & 1) * 0x10 | 4);
      } while ((uVar2 & 8) != 0);
      bVar6 = g_2a9a != 0xffff;
      bVar12 = SBORROW2(g_2a9a,-1);
      uVar2 = g_2a9a + 1;
      bVar10 = (int)uVar2 < 0;
      bVar9 = uVar2 == 0;
      bVar7 = (POPCOUNT(uVar2 & 0xff) & 1U) == 0;
      if (!(bool)bVar9) {
        (*(code *)local_8)(0x1000,(uint)(in_NT & 1) * 0x4000 | (uint)bVar12 * 0x800 |
                                  (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
                                  (uint)bVar10 * 0x80 | (uint)(in_AF & 1) * 0x10 | (uint)bVar7 * 4 |
                                  (uint)bVar6);
        (*(code *)local_8)(0x1000,(uint)(in_NT & 1) * 0x4000 | (uint)(bVar12 & 1) * 0x800 |
                                  (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
                                  (uint)(bVar10 & 1) * 0x80 | (uint)(bVar9 & 1) * 0x40 |
                                  (uint)(in_AF & 1) * 0x10 | (uint)(bVar7 & 1) * 4 |
                                  (uint)(bVar6 & 1));
        g_2a9a = 0xffff;
      }
      local_4 = (*(code *)local_8)(0x1000,(uint)(in_NT & 1) * 0x4000 | (uint)(bVar12 & 1) * 0x800 |
                                          (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
                                          (uint)(bVar10 & 1) * 0x80 | (uint)(bVar9 & 1) * 0x40 |
                                          (uint)(in_AF & 1) * 0x10 | (uint)(bVar7 & 1) * 4 |
                                          (uint)(bVar6 & 1));
      g_2a9a = 0xffff;
      if (param_3 == 0xffff) {
        bVar9 = 0;
        bVar10 = 1;
        bVar12 = 1;
        bVar6 = 0;
        bVar7 = 0;
      }
      else {
        bVar6 = local_4 < 9;
        bVar7 = SBORROW2(local_4,9);
        uVar2 = local_4 - 9;
        bVar12 = (int)uVar2 < 0;
        bVar10 = uVar2 == 0;
        bVar9 = (POPCOUNT(uVar2 & 0xff) & 1U) == 0;
        if ((bool)bVar10) {
          bVar9 = 0;
          bVar10 = 1;
          bVar12 = 1;
        }
        else {
          g_2a9a = uVar1 & 0xff;
          g_abd6 =
               (*(code *)local_8)(0x1000,(uint)(in_NT & 1) * 0x4000 | (uint)bVar7 * 0x800 |
                                         (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
                                         (uint)bVar12 * 0x80 | (uint)bVar10 * 0x40 |
                                         (uint)(in_AF & 1) * 0x10 | (uint)bVar9 * 4 | (uint)bVar6);
          uVar13 = (uint)(in_NT & 1) * 0x4000 | (uint)(bVar7 & 1) * 0x800 |
                   (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)(bVar12 & 1) * 0x80
                   | (uint)(bVar10 & 1) * 0x40 | (uint)(in_AF & 1) * 0x10 | (uint)(bVar9 & 1) * 4 |
                   (uint)(bVar6 & 1);
          g_abd4 = (*(code *)local_8)();
          uVar2 = -((0x3fU - g_abd4 & 0xff) * (param_3 & 0xff) >> 8);
          uVar3 = uVar2 + 0x3f;
          (*(code *)local_8)(0x1000,(uint)(in_NT & 1) * 0x4000 | (uint)SCARRY2(uVar2,0x3f) * 0x800 |
                                    (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
                                    (uint)((int)uVar3 < 0) * 0x80 | (uint)(uVar3 == 0) * 0x40 |
                                    (uint)(in_AF & 1) * 0x10 |
                                    (uint)((POPCOUNT(uVar3 & 0xff) & 1U) == 0) * 4 |
                                    (uint)(0xffc0 < uVar2),uVar13);
          bVar6 = 0;
          bVar7 = 0;
          bVar9 = 0;
          bVar10 = 1;
          bVar12 = 1;
          (*(code *)local_8)(0x1000,(uint)(in_NT & 1) * 0x4000 | (uint)(in_IF & 1) * 0x200 |
                                    (uint)(in_TF & 1) * 0x100 | 0x40 | (uint)(in_AF & 1) * 0x10 | 4)
          ;
        }
      }
      (*(code *)local_8)(0x1000,(uint)(in_NT & 1) * 0x4000 | (uint)(bVar7 & 1) * 0x800 |
                                (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
                                (uint)(bVar9 & 1) * 0x80 | (uint)(bVar10 & 1) * 0x40 |
                                (uint)(in_AF & 1) * 0x10 | (uint)(bVar12 & 1) * 4 |
                                (uint)(bVar6 & 1));
      if ((uVar1 & 0xff) == 0) {
        fn_2120_0007(5);
      }
    }
    else {
      if (g_28de == 1) {
        bVar11 = (int)uVar1 < 0;
        bVar8 = (POPCOUNT(uVar1 & 0xff) & 1U) == 0;
        if (bVar11) {
          (*(code *)local_8)(0x1000,(uint)(in_NT & 1) * 0x4000 | (uint)(in_IF & 1) * 0x200 |
                                    (uint)(in_TF & 1) * 0x100 | (uint)bVar11 * 0x80 |
                                    (uint)(uVar1 == 0) * 0x40 | (uint)(in_AF & 1) * 0x10 |
                                    (uint)bVar8 * 4);
        }
        else {
          (*(code *)local_8)(0x1000,(uint)(in_NT & 1) * 0x4000 | (uint)(in_IF & 1) * 0x200 |
                                    (uint)(in_TF & 1) * 0x100 | (uint)bVar11 * 0x80 |
                                    (uint)(uVar1 == 0) * 0x40 | (uint)(in_AF & 1) * 0x10 |
                                    (uint)bVar8 * 4);
        }
      }
      bVar8 = false;
      uVar2 = uVar1;
      if ((int)uVar1 < 0) {
        bVar8 = (int)-uVar1 < 0;
        uVar2 = -uVar1;
      }
      (*(code *)local_8)(0x1000,(uint)(in_NT & 1) * 0x4000 |
                                (uint)((int)uVar1 < 0 && SBORROW2(0,uVar1)) * 0x800 |
                                (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
                                (uint)bVar8 * 0x80 | (uint)(uVar2 == 0) * 0x40 |
                                (uint)(in_AF & 1) * 0x10 |
                                (uint)((POPCOUNT(uVar2 & 0xff) & 1U) == 0) * 4 |
                                (uint)(0x7fff < uVar1));
    }
  }
  return;
}

