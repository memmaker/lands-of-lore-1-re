//// fn_13e8_0005 @ 23e8:0005

undefined2 __cdecl16far fn_13e8_0005(int param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 in_DX;
  undefined4 uVar5;
  int local_a;
  undefined4 local_6;
  
  do {
    if (param_1 == 0) {
      return 0;
    }
    if (*(int *)(param_1 * 0x48 + 0x5a54) != -1) {
      uVar3 = fn_0845_04ec(*(undefined4 *)(*(int *)(param_1 * 0x48 + 0x5a54) * 4 + 0x5412));
      local_6 = CONCAT22(in_DX,uVar3);
      iVar1 = *(int *)(param_1 * 0x48 + 0x5a72);
      iVar2 = *(int *)(param_1 * 0x48 + 0x5a86);
      local_a = fn_1f36_01e2(uVar3,in_DX);
      iVar4 = fn_1f36_0224(local_6);
      if ((*(byte *)(param_1 * 0x48 + 0x5a99) & 1) != 0) {
        local_a = local_a << 1;
      }
      uVar5 = fn_0845_03b4((undefined4 *)&g_2f36,iVar1 + 0x84,iVar2 + 4,
                            iVar1 + local_a + 0x90,iVar2 + iVar4 + 0x10);
      in_DX = (undefined2)((ulong)uVar5 >> 0x10);
      if ((int)uVar5 != 0) {
        return 1;
      }
    }
    param_1 = (int)*(char *)(param_1 * 0x48 + 0x5a98);
  } while( true );
}


//// fn_13e8_00d4 @ 23e8:00d4

bool __cdecl16far fn_13e8_00d4(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = fn_13e8_0005((int)*(char *)(*(char *)(param_1 * 10 + param_2 + -0x7dfd) + 0x536e));
  if (iVar1 != 0) {
    fn_154c_000f(1);
    fn_0845_13d6(param_1,0x40);
  }
  return iVar1 != 0;
}


//// fn_13e8_011c @ 23e8:011c

bool __cdecl16far fn_13e8_011c(int param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = fn_13e8_0005();
  if (iVar2 != 0) {
    pcVar1 = (char *)(param_1 * 10 + param_2 + -0x7dfd);
    *pcVar1 = *pcVar1 + '\x01';
    g_7fb6 = 1;
    fn_067a_0401(0x1e);
    fn_0845_13d6(param_1,0x40);
  }
  return iVar2 != 0;
}


//// fn_13e8_017c @ 23e8:017c

bool __cdecl16far fn_13e8_017c(int param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = fn_13e8_0005();
  if (iVar2 != 0) {
    pcVar1 = (char *)(param_1 * 10 + param_2 + -0x7dfd);
    *pcVar1 = *pcVar1 + -1;
    g_7fb6 = 1;
    fn_067a_0401(0x1d);
    fn_0845_13d6(param_1,0x40);
  }
  return iVar2 != 0;
}


//// fn_13e8_01dc @ 23e8:01dc

undefined2 __cdecl16far fn_13e8_01dc(undefined2 param_1)

{
  fn_0845_13d6(param_1,0x40);
  return 1;
}


//// fn_13e8_01f1 @ 23e8:01f1

undefined2 __cdecl16far fn_13e8_01f1(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = fn_13e8_0005();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    g_4be0 = 0;
    fn_067a_0401(0x4e);
    fn_0845_13d6(param_1,0x40);
    if (g_4be0 == 0) {
      fn_2120_0007();
      fn_13e8_0358(param_1,param_2,0);
    }
    uVar2 = 1;
  }
  return uVar2;
}


//// fn_13e8_0261 @ 23e8:0261

undefined2 __cdecl16far fn_13e8_0261(int param_1,int param_2)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 local_6;
  int local_4;
  
  local_4 = (int)*(char *)(*(char *)(param_1 * 10 + param_2 + -0x7dfd) + 0x536e);
  iVar1 = fn_13e8_0005();
  if ((iVar1 != 0) && (iVar1 = fn_0845_0ac7(), iVar1 != 0)) {
    local_6 = 0x80;
    fn_1aff_03b4(&local_6);
    fn_1aff_030e(&local_6);
    uVar2 = fn_0845_0ac7(local_6,0xff,0x10008);
    fn_07bc_0272(uVar2);
    fn_0845_0acf();
    return 1;
  }
  return 0;
}


//// fn_13e8_02fa @ 23e8:02fa

undefined2 __cdecl16far fn_13e8_02fa(void)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  iVar2 = fn_09aa_0183(g_7fd0,g_7fdf);
  iVar3 = (int)*(char *)(iVar2 * 10 + (g_7fdf ^ 2) + -0x7dfd);
  if (*(char *)(iVar3 + 0x56) == '\0') {
    uVar4 = 0;
  }
  else {
    puVar1 = (undefined2 *)(*(char *)(iVar3 + 0x56) * 4 + 0x282c);
    uVar4 = (*(code *)*puVar1)((char *)s_This_cannot_be_run_under_Windows_3e2d_198b + 0x1f,iVar2,
                               g_7fdf ^ 2);
  }
  fn_2169_062e();
  return uVar4;
}


//// fn_13e8_0358 @ 23e8:0358

void __cdecl16far fn_13e8_0358(int param_1,undefined2 param_2,int param_3)

{
  int iVar1;
  
  if ((g_7fd0 != param_1) && ((*(uint *)(param_1 * 10 + -0x7df9) & 0x8000) == 0)) {
    if (param_3 == 0) {
      iVar1 = 0;
      do {
        if (((undefined2 *)&g_4ed0)[iVar1 * 2] == param_1) {
          param_3 = -(int)(char)((undefined1 *)&g_4ed3)[iVar1 * 4];
          break;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < 3);
    }
    if (param_3 == 0) {
      if ((*(byte *)(*(char *)(param_1 * 10 +
                               (uint)((*(byte *)(*(char *)(param_1 * 10 + -0x7dfd) + 0x531e) & 8) ==
                                     0) + -0x7dfd) + 0x531e) & 1) == 0) {
        param_3 = -1;
      }
      else {
        param_3 = 1;
      }
    }
    fn_13e8_03e9(param_1,param_3);
  }
  return;
}


//// fn_13e8_03e9 @ 23e8:03e9

void __cdecl16far fn_13e8_03e9(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined2 uVar4;
  bool bVar5;
  int local_8;
  int local_6;
  char local_3;
  
  local_8 = -1;
  local_6 = -1;
  bVar5 = (*(byte *)(*(char *)(param_1 * 10 + -0x7dfd) + 0x531e) & 8) == 0;
  local_3 = *(char *)(param_1 * 10 + (int)bVar5 + -0x7dfd);
  if ((*(byte *)(param_2 + 0x2849) & *(byte *)(local_3 + 0x531e)) == 0) {
    iVar3 = 0;
    do {
      iVar1 = iVar3;
      if (((undefined2 *)&g_4ed0)[iVar3 * 2] == param_1) break;
      if ((((undefined2 *)&g_4ed0)[iVar3 * 2] == 0) && (local_6 == -1)) {
        local_6 = iVar3;
      }
      iVar3 = iVar3 + 1;
      iVar1 = local_8;
    } while (iVar3 < 3);
    local_8 = iVar1;
    cVar2 = (char)param_2;
    if ((local_8 == -1) && (local_6 == -1)) {
      while ((*(byte *)(param_2 + 0x2849) & *(byte *)(local_3 + 0x531e)) == 0) {
        local_3 = local_3 + cVar2;
      }
      *(char *)(param_1 * 10 + (int)bVar5 + -0x7dfd) = local_3;
      *(char *)(param_1 * 10 + ((int)bVar5 ^ 2U) + -0x7dfd) = local_3;
      fn_0845_046c();
    }
    else {
      if (local_8 == -1) {
        local_8 = local_6;
      }
      ((undefined2 *)&g_4ed0)[local_8 * 2] = param_1;
      ((undefined1 *)&g_4ed3)[local_8 * 4] = cVar2;
      *(bool *)(local_8 * 4 + 0x4ed2) = bVar5;
      if ((*(byte *)(0x2849 - param_2) & *(byte *)(local_3 + 0x531e)) != 0) {
        *(char *)(param_1 * 10 + (int)bVar5 + -0x7dfd) =
             *(char *)(param_1 * 10 + (int)bVar5 + -0x7dfd) + cVar2;
        *(char *)(param_1 * 10 + ((int)bVar5 ^ 2U) + -0x7dfd) =
             *(char *)(param_1 * 10 + ((int)bVar5 ^ 2U) + -0x7dfd) + cVar2;
        if (param_2 == -1) {
          uVar4 = 0x20;
        }
        else {
          uVar4 = 0x1f;
        }
        iVar3 = fn_0845_046c();
        if (iVar3 == 0) {
          fn_067a_02f5((char *)s_Lib_error_29_3e2d_1842 + 3,uVar4,param_1);
          fn_067a_026b();
        }
        else {
          fn_067a_02f5((char *)s_Lib_error_29_3e2d_1842 + 3,uVar4,param_1);
        }
      }
      fn_0bbc_070e(0x10000);
    }
  }
  return;
}


//// fn_13e8_05a4 @ 23e8:05a4

void __cdecl16far fn_13e8_05a4(void)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  undefined2 in_DX;
  int iVar4;
  int iVar5;
  undefined4 *local_e;
  undefined4 local_a;
  int local_4;
  
  fn_1e74_000f();
  uVar1 = fn_1f2d_0002(g_7fbc);
  local_a = CONCAT22(in_DX,uVar1);
  local_4 = g_2f16;
  if (g_2f43 == '\0') {
    while (g_2f16 != 0) {
      fn_1ebc_00fe();
    }
  }
  local_e = &g_ab32;
  iVar4 = g_ab30;
  for (iVar5 = 1; iVar5 <= g_4bde; iVar5 = iVar5 + 1) {
    fn_1ebc_00e7();
    fn_0845_0008(iVar4,g_ab2e,0x4a,0x880009,0xffff00fb);
    if (iVar5 == g_ab2a) {
      uVar1 = 0x90;
    }
    else {
      uVar1 = 0xfe;
    }
    iVar2 = iVar4 + 0x25;
    uVar3 = fn_1e64_002b(*local_e,iVar2,g_ab2e + 2,uVar1,0);
    fn_1f6c_0006(*local_e,iVar2 - (uVar3 >> 1));
    fn_1ebc_00fe();
    iVar4 = iVar4 + g_ab2c;
    local_e = (undefined4 *)CONCAT22(local_e._2_2_,(undefined4 *)local_e + 1);
  }
  if (g_2f43 == '\0') {
    while (local_4 != 0) {
      fn_1ebc_00e7();
      local_4 = local_4 + -1;
    }
  }
  fn_1e74_000f();
  fn_1f2d_0002(local_a);
  return;
}


//// fn_13e8_06a1 @ 23e8:06a1

int __cdecl16far fn_13e8_06a1(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  int local_6;
  
  iVar5 = g_ab2a;
  local_6 = 0;
  iVar7 = 1;
  iVar3 = g_ab30;
  while ((iVar1 = g_ab2a, iVar7 <= g_4bde &&
         (iVar2 = fn_0845_038e(g_2f0c,g_2f0e,iVar3,g_ab2e,iVar3 + 0x4a,
                                g_ab2e + 9), iVar1 = iVar7, iVar2 == 0))) {
    iVar3 = iVar3 + g_ab2c;
    iVar7 = iVar7 + 1;
  }
  g_ab2a = iVar1;
  if (g_4bde == 0) {
    iVar3 = fn_2169_060c();
    if (iVar3 != 0) {
      uVar4 = fn_2169_0790();
      fn_15a7_0964();
      if (((uVar4 & 0xfff) == 0x2b) || ((uVar4 & 0xfff) == 0x3d)) {
        fn_154c_000f(1);
        g_2138 = 0;
      }
    }
    iVar3 = fn_154c_0136();
    if ((iVar3 != 2) && (g_2138 <= g_384c)) {
      local_6 = 1;
      fn_2169_062e();
      fn_15a7_0964();
    }
  }
  else {
    iVar3 = fn_2169_060c();
    if (iVar3 != 0) {
      uVar4 = fn_2169_0790();
      fn_15a7_0964();
      iVar3 = 8;
      puVar6 = (uint *)((char *)s_Process_Fireball_FX__Can_t_load_f_3e2d_08db + 8);
      do {
        if (*puVar6 == (uVar4 & 0xfff)) {
                    /* WARNING: Could not recover jumptable at 0x0002460f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          iVar5 = (*(code *)puVar6[8])();
          return iVar5;
        }
        puVar6 = puVar6 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  if (iVar5 != g_ab2a) {
    fn_13e8_05a4();
  }
  if (local_6 != 0) {
    fn_130a_0784();
    if ((g_81fd._1_1_ == '\0') && (f_2803_0045 != '\0')) {
      fn_14b3_0122(5);
      fn_1ebc_00e7();
      fn_1e59_001d(g_ad8d,g_ad8b + g_ad91 + -9,
                    g_ad8d + g_ad8f + -1,g_ad8b + g_ad91 + -1,
                    g_3711);
      fn_1ebc_00fe();
    }
    else {
      fn_1ebc_00e7();
      fn_1e59_001d(g_ad8d,g_ad8b,g_ad8d + g_ad8f + -2,
                    g_ad8b + g_ad91 + -1,g_3711);
      fn_14b3_01fa(4);
      fn_1ebc_00fe();
      g_1f87 = 0;
      g_1f89 = 0;
    }
  }
  return local_6;
}


//// fn_13e8_0903 @ 23e8:0903

void __cdecl16far
fn_13e8_0903(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if ((param_1 == 1) && (g_81ff != '\0')) {
    fn_14b3_0122(5);
    g_4bde = 0;
    g_ab32 = 0;
    g_ab36 = 0;
    g_ab3a = 0;
  }
  else {
    g_ab2a = 1;
    g_4bde = param_1;
    g_ab32 = param_2;
    g_ab36 = param_3;
    g_ab3a = param_4;
    fn_14b3_0122(5);
    g_ab2e = g_ad8b + g_ad91 + -9;
    if (param_1 == 1) {
      g_ab2c = 0;
      g_ab30 = g_ad8d + g_ad8f + -0x4d;
    }
    else {
      g_ab2c = g_ad8f / param_1;
      g_ab30 = g_ad8d + ((int)g_ab2c >> 1) + -0x25;
    }
    fn_13e8_05a4();
    fn_2169_062e();
  }
  return;
}


//// fn_13e8_09b7 @ 23e8:09b7

void __cdecl16far fn_13e8_09b7(void)

{
  undefined2 uVar1;
  bool bVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  int iVar7;
  undefined2 uVar8;
  uint uVar9;
  undefined2 uVar10;
  ulong in_EDX;
  uint *puVar11;
  int iVar12;
  int iVar13;
  ulong local_1c;
  int local_18;
  undefined2 local_16;
  uint local_8;
  int local_6;
  
  uVar3 = fn_1e74_000f(0);
  uVar4 = fn_1f2d_0002((int)g_7fbc,(int)((ulong)g_7fbc >> 0x10));
  uVar1 = (undefined2)in_EDX;
  uVar5 = fn_0bbc_0960(0xb);
  uVar10 = (undefined2)in_EDX;
  g_20f6 = 0;
  if (g_4bf8 != -1) {
    local_16 = g_4c00;
    g_4c00 = 0;
    local_18 = g_4bfc;
    if (0x24 < g_4bfc) {
      g_4bfc = 0x24;
    }
  }
  if (g_81ff != '\0') {
    uVar6 = ovr_2da3_002f();
    uVar8 = (undefined2)in_EDX;
    if ((CONCAT22(uVar8,uVar6) != 0) && (g_2170 != 0)) {
      iVar13 = g_2172 >> 0xf;
      iVar12 = g_2172;
      uVar6 = ovr_2da3_002f();
      in_EDX = g_384c +
               (ulong)(CONCAT22(iVar13,iVar12) * CONCAT22(uVar8,uVar6)) / (ulong)(long)g_2170
      ;
      local_1c = in_EDX;
      goto LAB_23e8_0a77;
    }
  }
  local_1c = 0;
LAB_23e8_0a77:
  uVar6 = (undefined2)in_EDX;
  iVar12 = (g_ad8d + g_ad8f) * 8;
  iVar13 = iVar12 + -0x4d;
  if ((f_2803_0044 == '\0') || ((g_7fd6 & 2) == 0)) {
    iVar12 = g_ad8b + g_ad91 + -10;
  }
  else if ((f_2803_0045 == '\0') && ((g_7fd6 & 2) != 0)) {
    iVar13 = iVar12 + -0x47;
    iVar12 = g_ad8b + g_ad91 + -2;
  }
  else {
    iVar12 = g_ad8b + g_ad91 + -5;
  }
  fn_1ebc_00e7();
  fn_0845_0008(iVar13,iVar12,0x4a,9,0x88,0xfb,0xffff);
  iVar7 = iVar13 + 0x25;
  uVar8 = fn_0845_06f8((char *)s_Lib_error_29_3e2d_1842 + 3,0x4073,iVar7,iVar12 + 2,0x90,0);
  uVar9 = fn_1e64_002b(uVar8,uVar6);
  iVar7 = iVar7 - (uVar9 >> 1);
  uVar6 = fn_0845_06f8(0x2e64,0x4073,iVar7);
  fn_1f6c_0006(uVar6,iVar7);
  fn_1ebc_00fe();
  fn_2169_062e();
  local_6 = g_2f16;
  if (g_2f43 == '\0') {
    while (g_2f16 != 0) {
      fn_1ebc_00fe();
    }
  }
  bVar2 = true;
LAB_23e8_0b98:
  do {
    iVar7 = fn_2169_060c();
    if (iVar7 == 0) {
      fn_0845_093a();
      if ((g_81ff == '\0') ||
         (((g_384c <= local_1c && (iVar7 = fn_154c_0136(), iVar7 == 2)) || (local_1c == 0)))
         ) goto LAB_23e8_0b98;
      bVar2 = false;
      local_8 = 0x2b;
    }
    if (bVar2) {
      uVar9 = fn_2169_0790();
      local_8 = uVar9 & 0x8ff;
    }
    fn_15a7_0964();
    iVar7 = 6;
    puVar11 = (uint *)((char *)s_Process_Litning_FX__Can_t_load___3e2d_0c94 + 5);
    do {
      if (*puVar11 == local_8) {
                    /* WARNING: Could not recover jumptable at 0x00024a52. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)puVar11[6])();
        return;
      }
      puVar11 = puVar11 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    if (!bVar2) {
      if (g_2f43 == '\0') {
        while (local_6 != 0) {
          fn_1ebc_00e7();
          local_6 = local_6 + -1;
        }
      }
      fn_1ebc_00e7();
      fn_1e59_001d(iVar13,iVar12,iVar13 + 0x4a,iVar12 + 9,g_3711);
      fn_14b3_0215();
      fn_1ebc_00fe();
      fn_0bbc_09a9(0xb,uVar5,uVar10);
      if (g_4bf8 != -1) {
        g_4c00 = local_16;
        if (local_18 < 0x25) {
          local_18 = local_18 >> 1;
        }
        else {
          local_18 = local_18 + -0x24;
        }
        g_4bfc = local_18;
      }
      fn_1f2d_0002(uVar4,uVar1);
      fn_1e74_000f(uVar3);
      fn_2169_062e();
      return;
    }
  } while( true );
}

