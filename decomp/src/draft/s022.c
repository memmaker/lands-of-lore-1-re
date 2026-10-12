//// fn_14b3_0001 @ 24b3:0001

void __cdecl16far fn_14b3_0001(undefined4 param_1,int param_2,int param_3,int param_4)

{
  if (param_4 == 0) {
    param_4 = *(int *)(g_3715 * 0x10 + 0x1f43);
  }
  if (param_3 == 0) {
    param_3 = *(int *)(g_3715 * 0x10 + 0x1f45);
  }
  fn_1f6c_0006(param_1,(g_ad8d + g_ad8f) * 8 -
                        (param_2 + -1) * (g_3628 + g_3624),
                g_ad8b + (g_ad93 + -1) * (g_3629 + g_3626),param_3,
                param_4);
  if (g_3649 == 0) {
    fn_234e_0062();
  }
  fn_2169_062e();
  fn_2169_06e9();
  if (g_3649 == 0) {
    fn_234e_0003(g_3715);
  }
  fn_1e59_001d();
  return;
}


//// fn_14b3_00c8 @ 24b3:00c8

void __cdecl16far
fn_14b3_00c8(long param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  if (param_1 == 0) {
    g_1614 = 0x3e2d2855;
    g_284f = 7;
    g_2853 = 0;
    g_2851 = 0;
  }
  else {
    g_1614 = param_1;
    g_284f = param_2;
    g_2851 = param_3;
    g_2853 = param_4;
  }
  return;
}


//// fn_14b3_0108 @ 24b3:0108

void __cdecl16far fn_14b3_0108(void)

{
  g_3644 = 1;
  g_284c = 0;
  return;
}


//// fn_14b3_0118 @ 24b3:0118

void __cdecl16far fn_14b3_0118(void)

{
  g_3644 = 0;
  return;
}


//// fn_14b3_0122 @ 24b3:0122

undefined2 __cdecl16far fn_14b3_0122(int param_1)

{
  undefined2 uVar1;
  undefined4 local_8;
  
  uVar1 = g_3715;
  g_3715 = param_1;
  param_1 = param_1 * 0x10;
  local_8 = (uint *)CONCAT22(0x3e2d,(undefined2 *)(param_1 + 0x1f3b));
  g_ad8d = *local_8;
  local_8 = (uint *)CONCAT22(0x3e2d,(undefined2 *)(param_1 + 0x1f3d));
  g_ad8b = *local_8;
  local_8 = (uint *)CONCAT22(0x3e2d,(int *)(param_1 + 7999));
  g_ad8f = *local_8;
  local_8 = (uint *)CONCAT22(0x3e2d,(int *)(param_1 + 0x1f41));
  g_ad91 = *local_8;
  local_8 = (uint *)CONCAT22(0x3e2d,(undefined2 *)(param_1 + 0x1f43));
  g_3713 = *local_8;
  local_8 = (uint *)CONCAT22(0x3e2d,(undefined2 *)(param_1 + 0x1f45));
  g_3711 = *local_8;
  local_8 = (uint *)CONCAT22(0x3e2d,(uint *)(param_1 + 0x1f47));
  g_ad95 = *local_8;
  local_8 = (uint *)CONCAT22(0x3e2d,(undefined2 *)(param_1 + 0x1f49));
  g_ad93 = *local_8;
  g_284c = 0;
  g_ab49 = g_ad95 / (uint)(g_3628 + g_3624);
  g_3717 = (uint)(g_ad91 - g_3626) / (uint)(g_3629 + g_3626);
  g_371b = g_ad8f << 3;
  g_3719 = g_371b / (g_3628 + g_3624);
  return uVar1;
}


//// fn_14b3_01fa @ 24b3:01fa

undefined2 __cdecl16far fn_14b3_01fa(undefined2 param_1)

{
  undefined2 uVar1;
  
  uVar1 = fn_14b3_0122(param_1);
  fn_14b3_0215();
  return uVar1;
}


//// fn_14b3_0215 @ 24b3:0215

void __cdecl16far fn_14b3_0215(void)

{
  fn_1e59_001d(g_ad8d << 3,g_ad8b,(g_ad8d + g_ad8f) * 8 + -1,
                g_ad8b + g_ad91 + -1,g_3711,g_ad8b + g_ad91);
  g_ab49 = 0;
  g_ad95 = 0;
  g_ad93 = 0;
  g_284c = 0;
  return;
}


//// fn_14b3_0270 @ 24b3:0270

void __cdecl16far fn_14b3_0270(undefined2 param_1)

{
  fn_14b3_0284(0x285c,0x3e2d,param_1);
  return;
}


//// fn_14b3_0284 @ 24b3:0284

/* WARNING: Instruction at (ram,0x0002c95f) overlaps instruction at (ram,0x0002c95e)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x00024aec) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

code * __cdecl16far
fn_14b3_0284(long *param_1,uint *param_2,code *param_3,ulong param_4,ulong param_5,
             undefined2 param_6)

{
  undefined1 *puVar1;
  byte *pbVar2;
  uint *puVar3;
  undefined1 *puVar4;
  code *pcVar5;
  byte bVar6;
  byte bVar7;
  long *plVar8;
  byte bVar9;
  char cVar10;
  code cVar11;
  int iVar12;
  int iVar13;
  code *pcVar14;
  code *pcVar15;
  undefined2 uVar16;
  code *pcVar17;
  code *pcVar18;
  uint uVar19;
  int iVar20;
  code *pcVar21;
  code *pcVar22;
  ulong uVar23;
  undefined3 uVar24;
  char cVar25;
  uint in_CX;
  uint uVar26;
  code *in_EDX;
  uint *puVar27;
  code *pcVar28;
  uint uVar29;
  int iVar30;
  code *unaff_SI;
  undefined1 *puVar31;
  code *unaff_DI;
  uint unaff_ES;
  uint unaff_SS;
  undefined2 in_FS;
  undefined1 uVar32;
  bool bVar33;
  int aiStack_750 [892];
  code *pcStack_58;
  int iStack_56;
  undefined2 uStack_54;
  int iStack_52;
  undefined2 uStack_50;
  uint uStack_4e;
  uint uStack_4c;
  int iStack_46;
  undefined2 uStack_44;
  code *pcStack_42;
  code *pcStack_40;
  code *in_stack_0000ffc6;
  code *pcStack_36;
  code *pcStack_34;
  uint uStack_32;
  int iStack_30;
  undefined1 uStack_2e;
  undefined1 uStack_2d;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined2 local_26;
  code *local_16;
  code *local_12;
  code *local_10;
  undefined4 local_e;
  code *pcStack_a;
  code *pcStack_8;
  undefined4 uStack_6;
  
  uVar29 = g_3715;
  pcVar15 = g_3711;
  pcVar17 = (code *)0x3e2d;
  puVar31 = &stack0xfffe;
  local_16 = (code *)&param_3;
  g_284e = 0;
  g_ab4b = 0;
  g_ab4d = 0;
  g_ab4f = 0;
  g_ab40 = 0;
  g_ab3f = '\0';
  g_ab45 = (long *)CONCAT22(param_2,param_1);
  g_ab41 = (undefined4 *)0x0;
  local_10 = (code *)g_3713;
  local_12 = g_3711;
  if (g_3649 == 0) {
    fn_234e_0003();
    in_CX = uVar29;
  }
code_r0x00024e0d:
  cVar10 = fn_14b3_095d();
  uStack_6 = (code *)CONCAT13(cVar10,(undefined3)uStack_6);
  if (cVar10 == '\0') {
    if (g_ab4d != 0) {
      fn_14b3_0731();
    }
    *(int *)(g_3715 * 0x10 + 0x1f47) = g_ad95;
    *(undefined2 *)(g_3715 * 0x10 + 0x1f49) = g_ad93;
    g_3713 = (uint)local_10;
    *(uint *)(g_3715 * 0x10 + 0x1f43) = (uint)local_10;
    g_3711 = pcVar15;
    *(undefined2 *)(g_3715 * 0x10 + 0x1f45) = pcVar15;
    if (g_3649 == 0) {
      pcVar15 = (code *)fn_234e_0062();
    }
    return pcVar15;
  }
  if ((g_ab41 == (undefined4 *)0x0) && (cVar10 == '%')) {
    in_CX = (uint)g_ab3f;
    iVar13 = tolower();
    if (iVar13 == 100) {
      g_ab41 = (undefined4 *)CONCAT22(unaff_SS,&local_e);
      local_16 = local_16 + 2;
      local_26 = 0x4e94;
      sprintf();
LAB_24b3_0329:
      g_ab3e = g_ab40;
      g_ab40 = 0;
      g_ab3f = '\0';
      uVar32 = fn_14b3_095d();
      uStack_6 = (code *)CONCAT13(uVar32,(undefined3)uStack_6);
      unaff_ES = unaff_SS;
    }
    else if (iVar13 == 0x73) {
      pcVar14 = local_16 + 4;
      g_ab41 = *(undefined4 **)local_16;
      unaff_ES = unaff_SS;
      local_16 = pcVar14;
      if (g_ab41 != (undefined4 *)0x0) goto LAB_24b3_0329;
    }
  }
  pcVar21 = (code *)CONCAT11(uStack_2d,uStack_2e);
  iVar13 = (int)uStack_6._3_1_;
  pcVar14 = (code *)(iVar13 + -1);
  pcVar22 = (code *)ZEXT24(pcVar14);
  bVar9 = (byte)((uint)pcVar14 >> 8);
  if ((char *)s_Borland_C_____Copyright_1991_Bor_3e2d_0004 + 0x18 < pcVar14) goto LAB_24b3_055c;
  uVar32 = (int)pcVar14 < 0;
  pcVar28 = (code *)((int)pcVar14 * 2);
  cVar10 = (char)pcVar14;
  pcVar18 = unaff_SI;
  switch(pcVar14) {
  case (code *)0x0:
    goto switchD_2000_4eaa_caseD_0;
  case (code *)0x1:
    iVar13 = (g_ad8d + g_ad8f) * 8;
    iVar20 = iVar13 + -0x4d;
    if ((((f_2803_0044 != '\0') && ((g_7fd6 & 2) != 0)) && (f_2803_0045 == '\0')) &&
       ((g_7fd6 & 2) != 0)) {
      iVar20 = iVar13 + -0x47;
    }
    g_523d = pcVar14;
    fn_1ebc_00e7();
    fn_0845_0008();
    fn_0845_06f8();
    uVar29 = fn_1e64_002b();
    iVar20 = (iVar20 + 0x25) - (uVar29 >> 1);
    iVar13 = iVar20;
    fn_0845_06f8();
    fn_1f6c_0006();
    fn_1ebc_00fe();
    fn_2169_062e();
    uStack_6 = (code *)CONCAT22(uStack_6._2_2_,g_2f16);
    if (g_2f43 == '\0') {
      while (g_2f16 != 0) {
        fn_1ebc_00fe();
      }
    }
    uStack_6 = (code *)CONCAT22(1,(code *)uStack_6);
    pcStack_a = (code *)0x0;
LAB_23e8_0b98:
    do {
      iVar12 = fn_2169_060c();
      if (iVar12 == 0) {
        fn_0845_093a();
        if (((g_81ff == '\0') ||
            ((g_384c <= CONCAT22(iVar20,iVar13) && (iVar12 = fn_154c_0136(), iVar12 == 2))))
           || (CONCAT22(iVar20,iVar13) == 0)) goto LAB_23e8_0b98;
        uStack_6 = (code *)((ulong)uStack_6 & 0xffff);
        pcStack_8 = (code *)0x2b;
      }
      if (uStack_6._2_2_ != 0) {
        uVar29 = fn_2169_0790();
        pcStack_8 = (code *)(uVar29 & 0x8ff);
      }
      fn_15a7_0964();
      iVar12 = 6;
      puVar27 = (uint *)((char *)s_Process_Litning_FX__Can_t_load___3e2d_0c94 + 5);
      do {
        if ((code *)*puVar27 == pcStack_8) {
                    /* WARNING: Could not recover jumptable at 0x00024a52. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          pcVar15 = (code *)(*(code *)puVar27[6])();
          return pcVar15;
        }
        puVar27 = puVar27 + 1;
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
      if (uStack_6._2_2_ == 0) {
        if (g_2f43 == '\0') {
          while( true ) {
            iVar13 = (int)(code *)uStack_6;
            uStack_6 = (code *)CONCAT22(uStack_6._2_2_,(int)(code *)uStack_6 + -1);
            if (iVar13 == 0) break;
            fn_1ebc_00e7();
          }
        }
        fn_1ebc_00e7();
        fn_1e59_001d();
        fn_14b3_0215();
        fn_1ebc_00fe();
        fn_0bbc_09a9();
        if (g_4bf8 != -1) {
          g_4c00 = 0x24b3;
          g_4bfc = 5;
        }
        fn_1f2d_0002();
        fn_1e74_000f();
        pcVar15 = (code *)fn_2169_062e();
        return pcVar15;
      }
    } while( true );
  case (code *)0x2:
    goto switchD_2000_4eaa_caseD_2;
  case (code *)0x3:
switchD_2000_4eaa_caseD_3:
    uVar29 = CONCAT11((char)in_EDX,(char)((ulong)pcVar22 >> 8));
    pcVar22 = (code *)(ulong)uVar29;
    if (uVar29 == 0) {
      pcVar15 = (code *)fn_0fbe_059c();
      return pcVar15;
    }
    break;
  case (code *)0x4:
    puVar31 = (undefined1 *)(*(int *)(pcVar28 + (int)unaff_SI + -0x7f) * 0x6829);
    *(undefined1 **)(in_EDX + 0x14) = puVar31 + *(int *)(in_EDX + 0x14);
    goto LAB_2981_0285;
  case (code *)0x5:
    fn_130a_0052();
    return unaff_SI;
  case (code *)0x6:
    return (code *)0x0;
  case (code *)0x7:
    if ((bVar9 & 0xc0) != 0xc0) {
      fn_1ebc_000c();
      pcVar15 = (code *)in_EDX;
      if ((g_2f2c & 0x8000) == 0) goto LAB_2c24_027a;
    }
    pcVar15 = (code *)in_EDX;
    if (((g_2f2e <= in_CX) && (in_CX <= g_2f32)) &&
       ((g_2f30 <= pcVar15 && (pcVar15 <= g_2f34)))) {
      g_2f28 = in_CX;
      g_2f2a = pcVar15;
      g_2f2c = g_2f2c | 0x4000;
      return pcStack_a;
    }
LAB_2c24_027a:
    fn_1ebc_0053();
    g_2f28 = in_CX;
    g_2f2a = pcVar15;
    return pcStack_a;
  case (code *)0x8:
    if (pcVar14 == (code *)0x0 && (code *)in_EDX == (code *)0x0) {
      in_EDX = (code *)0x2981;
      if (unaff_SI == (code *)0x0) {
        fn_2037_0002();
        puVar31 = &stack0xfffe;
      }
      else {
        in_EDX = (code *)0x37fc;
        puVar31 = &stack0xfffe;
      }
    }
    else if (unaff_SI != (code *)0x0) {
      uVar16 = fn_242d_0108();
      pcVar15 = (code *)in_EDX;
      puVar31 = &stack0xfffe;
      goto LAB_2981_0294;
    }
LAB_2981_0285:
    pcVar15 = (code *)in_EDX;
    uVar16 = fn_242d_000f();
LAB_2981_0294:
    *(code **)(puVar31 + -2) = pcVar15;
    *(undefined2 *)(puVar31 + -4) = uVar16;
    if (*(long *)(puVar31 + -4) == 0) {
      pcVar15 = (code *)0xffff;
    }
    else {
      pcVar15 = (code *)(code *)((*(long *)(puVar31 + -4) - g_2aa7) / 0x14);
    }
    return pcVar15;
  case (code *)0x9:
    if (*(int *)(pcVar28 + 0x2c) < 1) {
      pcVar15 = (code *)0x0;
    }
    else {
      iVar20 = *(int *)(pcVar28 + 0x2c) * 0x10;
      pcVar15 = (code *)*(uint *)((int)param_1 + ((int)param_1[3] + 2) * 2 + 0x2c);
      iVar13 = *(int *)((int)param_1 + ((int)param_1[3] + 1) * 2 + 0x2c);
      if (iVar13 == 4) {
        *(code **)((char *)s_ADLIBG_ADV_3e2d_1d00 + 9 + iVar20) = pcVar15;
      }
      else if (iVar13 == 0xf) {
        pcVar15 = (code *)((uint)pcVar15 & 0x1fff);
        *(uint *)(iVar20 + 0x1d0b) = *(uint *)(iVar20 + 0x1d0b) & 0xe000;
        *(uint *)(iVar20 + 0x1d0b) = *(uint *)(iVar20 + 0x1d0b) | (uint)pcVar15;
      }
      else {
        pcVar15 = (code *)0xffff;
      }
    }
    return pcVar15;
  case (code *)0xa:
    sprintf();
    fn_2309_000c();
    fn_0845_1536();
    fn_2148_002c();
    fn_2148_014d();
    fn_2148_014d();
    execl();
    return (code *)0x0;
  case (code *)0xb:
    goto switchD_2000_4eaa_caseD_b;
  case (code *)0xc:
    cVar11 = *(code *)(ulong)(CONCAT11((char)((uint)local_26 >> 8) + bVar9,(char)local_26) +
                             ((uint)pcVar14 & 0xff));
    if (cVar11 != (code)0x0) {
      *unaff_DI = cVar11;
    }
    return (code *)CONCAT11(bVar9,cVar11);
  case (code *)0xd:
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    cVar10 = cVar10 + (char)pcVar28[(int)unaff_SI];
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar17 = (code *)(CONCAT11(bVar9,cVar10) + *(int *)(pcVar28 + (int)unaff_SI));
    cVar10 = (char)pcVar17;
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    g_0000._0_1_ = (char)g_0000 + cVar10;
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    *pcVar28 = (code)((char)*pcVar28 + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    cVar25 = (char)in_CX;
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar25);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_DI] = (code)((char)pcVar28[(int)unaff_DI] + cVar25);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    (&stack0xfffe)[(int)unaff_SI] = (&stack0xfffe)[(int)unaff_SI] + cVar25;
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    (&stack0xfffe)[(int)unaff_DI] = (&stack0xfffe)[(int)unaff_DI] + cVar25;
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    *unaff_SI = (code)((char)*unaff_SI + cVar25);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    *unaff_DI = (code)((char)*unaff_DI + cVar25);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    g_0000._0_1_ = (char)g_0000 + cVar25;
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    pcVar28[(int)unaff_SI] = (code)((char)pcVar28[(int)unaff_SI] + cVar10);
    *pcVar28 = (code)((char)*pcVar28 + cVar25);
    pcStack_40 = (code *)g_3649;
    pcStack_42 = (code *)0x2000;
    uStack_44 = 0xe184;
    fn_215f_001d();
    cVar11 = cRam0000000e;
    pcVar14 = (code *)in_EDX;
    iVar20 = (int)((ulong)g_ae53 >> 0x10);
    iVar13 = (int)g_ae53;
    if (iVar20 == 0 && iVar13 == 0) {
      return pcVar17;
    }
    iVar12 = *(int *)((unaff_SS & 0xff) * 2 + *(int *)(iVar13 + 6) + iVar13);
    if (iVar12 == 0) {
      return pcVar17;
    }
    if ((code *)0x13f < pcVar15) {
      return pcVar17;
    }
    uVar29 = (uint)*(byte *)(unaff_SS + *(int *)(iVar13 + 8) + iVar13);
    if ((code *)0x140 < pcVar15 + uVar29) {
      return pcVar17;
    }
    if (199 < local_10) {
      return pcVar17;
    }
    bVar9 = *(byte *)(*(int *)(iVar13 + 4) + iVar13 + 4);
    if (200 < (uint)bVar9 + (int)local_10) {
      return pcVar17;
    }
    iVar30 = unaff_SS * 2 + *(int *)(iVar13 + 0xc);
    bVar6 = *(byte *)(iVar30 + iVar13);
    bVar7 = *(byte *)(iVar30 + iVar13 + 1);
    puVar31 = (undefined1 *)(iVar13 + iVar12);
    pcVar15 = pcVar15 + (int)local_10 * 0x140;
    iVar13 = 0x140 - uVar29;
    uVar19 = (uint)bVar6;
    if (uVar19 != 0) {
      uVar26 = uVar29;
      if (cRam0000000e == (code)0x0) {
        pcVar15 = pcVar15 + uVar19 * 0x140;
      }
      else {
        do {
          do {
            pcVar22 = pcVar15;
            pcVar15 = pcVar15 + 1;
            *pcVar22 = cVar11;
            uVar26 = uVar26 - 1;
          } while (uVar26 != 0);
          pcVar15 = pcVar15 + iVar13;
          uVar19 = uVar19 - 1;
          uVar26 = uVar29;
        } while (uVar19 != 0);
      }
    }
    uVar26 = (uint)bVar7;
    uVar19 = uVar29;
    if (uVar26 == 0) {
      return pcVar17;
    }
LAB_2e07_0208:
    do {
      puVar4 = puVar31;
      puVar31 = puVar31 + 1;
      uVar23 = (ulong)CONCAT11(*puVar4,*puVar4) & 0xffffff0f;
      cVar11 = *(code *)(ulong)((byte)uVar23 + 0xe);
      if (cVar11 != (code)0x0) {
        *pcVar15 = cVar11;
      }
      pcVar21 = pcVar15 + 1;
      if (uVar19 != 1) {
        cVar11 = *(code *)(ulong)(((byte)(uVar23 >> 8) & 0xf0) + 0xe);
        if (cVar11 != (code)0x0) {
          pcVar15[1] = cVar11;
        }
        pcVar15 = pcVar15 + 2;
        uVar19 = uVar19 - 2;
        pcVar21 = pcVar15;
        if (uVar19 != 0) goto LAB_2e07_0208;
      }
      cVar11 = cRam0000000e;
      pcVar15 = pcVar21 + iVar13;
      uVar26 = uVar26 - 1;
      uVar19 = uVar29;
      if (uVar26 == 0) {
        uVar19 = (uint)(byte)(bVar9 - (bVar6 + bVar7));
        if ((uVar19 != 0) && (uVar26 = uVar29, cRam0000000e != (code)0x0)) {
          do {
            do {
              pcVar22 = pcVar15;
              pcVar15 = pcVar15 + 1;
              *pcVar22 = cVar11;
              uVar26 = uVar26 - 1;
            } while (uVar26 != 0);
            pcVar15 = pcVar15 + iVar13;
            uVar19 = uVar19 - 1;
            uVar26 = uVar29;
          } while (uVar19 != 0);
        }
        return pcVar17;
      }
    } while( true );
  case (code *)0xe:
    fn_1e74_000f();
    pcVar15 = (code *)fn_1f2d_0002();
    return pcVar15;
  case (code *)0xf:
    if (pcVar28 == (code *)0x0) {
      while( true ) {
        fn_1809_084d();
        if ((code *)CONCAT22(local_16,unaff_SI) == (code *)0x0) break;
        do {
          in_EDX = (code *)ZEXT24(&pcStack_58);
          fn_1809_084d();
        } while ((char)pcStack_58 != '\0');
        iVar13 = fn_1981_01af();
        if (((iVar13 != -1) && (iVar13 = iVar13 * 0x14, (*(uint *)(iVar13 + 0x12) & 0x1000) != 0))
           && ((uint)*(byte *)(iVar13 + 0x10) == *(uint *)(unaff_SS + 0xc))) {
          in_EDX = (code *)CONCAT22(local_16,unaff_SI) +
                   *(long *)(*(int *)(unaff_SS + 0xc) * 0x14 + 0xc);
          *(undefined4 *)(iVar13 + 0xc) = in_EDX;
          if ((code *)CONCAT22(0x8363,unaff_DI) != (code *)0x0) {
            *(long *)(unaff_DI + 4) = *(long *)(iVar13 + 0xc) - *(long *)(unaff_DI + 0xc);
          }
        }
      }
      if ((code *)CONCAT22(&stack0xffe8,unaff_DI) != (code *)0x0) {
        uVar16 = fn_1809_120c();
        *(long *)(unaff_DI + 4) = CONCAT22((code *)in_EDX,uVar16) - *(long *)(unaff_DI + 0xc);
      }
      puVar3 = (uint *)(*(int *)(unaff_SS + 0xc) * 0x14 + 0x12);
      *puVar3 = *puVar3 | 0x100;
    }
    pcVar17 = (code *)in_EDX;
    *(undefined4 *)(local_e._2_2_ + 8) = *(undefined4 *)((int)local_10 + 8);
    fn_1981_031f();
    *(undefined2 *)(unaff_SS + 0xc) = unaff_SI;
    *(undefined4 *)(unaff_SS + 0x10) = *(undefined4 *)local_e._2_2_;
    *(undefined4 *)(unaff_SS + 8) = *(undefined4 *)(local_e._2_2_ + 0xc);
    fn_1809_0e76();
    fn_1809_1502();
    if (unaff_SI != (code *)0xffff) {
      local_e._2_2_ = (code *)fn_1981_02c0();
      *(char *)((int)local_e._2_2_ + 0x11) = *(char *)((int)local_e._2_2_ + 0x11) + '\x01';
      pcStack_a = pcVar17;
      fn_1981_031f();
    }
    g_abde = g_abde + -1;
    return unaff_DI;
  case (code *)0x10:
    local_10 = (code *)(iVar13 + 0x4edf);
    local_e._0_2_ = (code *)0x3e2d;
    iVar13 = *(int *)((int)param_1 + ((int)param_1[3] + 1) * 2 + 0x2c);
    pcStack_8 = (code *)*(int *)((int)param_1 + ((int)param_1[3] + 2) * 2 + 0x2c);
    pcStack_a = (code *)*(int *)((int)param_1 + ((int)param_1[3] + 3) * 2 + 0x2c);
    if ((int)pcStack_8 < iVar13) {
      iVar20 = -1;
    }
    else {
      iVar20 = 1;
    }
    for (; (int)pcStack_8 + iVar20 != iVar13; iVar13 = iVar13 + iVar20) {
      uStack_6 = (code *)(g_384c + (long)(int)pcStack_a);
      ovr_2cef_0025();
      ovr_2cef_0020();
      fn_1ebc_0111();
      if ((*(uint *)((int)local_10 + 0x12) & 0x4000) == 0) {
        ovr_2dfd_002a();
      }
      else {
        if ((*(uint *)((int)local_10 + 0x12) & 0x1000) == 0) {
          local_e._2_2_ = (code *)0x4000;
        }
        else {
          local_e._2_2_ = (code *)0x5000;
        }
        fn_1dbc_0004();
        ovr_2dfd_002a();
        fn_1dbc_0004();
      }
      fn_1ebc_01ec();
      fn_0845_0be0();
    }
    return (code *)((int)(undefined2 *)&g_0000 + 1);
  case (code *)0x11:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case (code *)0x12:
    unaff_SI[0xc] = (code)0x0;
    *(code **)unaff_DI = pcVar14;
    uStack_6 = (code *)CONCAT22(uStack_6._2_2_,pcVar14);
    if (uStack_6._2_2_ != g_ab2a) {
      fn_13e8_05a4();
    }
    if ((code *)uStack_6 != (code *)0x0) {
      fn_130a_0784();
      if ((g_81fd._1_1_ == '\0') && (f_2803_0045 != '\0')) {
        fn_14b3_0122();
        fn_1ebc_00e7();
        fn_1e59_001d();
        fn_1ebc_00fe();
      }
      else {
        fn_1ebc_00e7();
        fn_1e59_001d();
        fn_14b3_01fa();
        fn_1ebc_00fe();
        g_1f87 = 0;
        g_1f89 = 0;
      }
    }
    return (code *)uStack_6;
  case (code *)0x13:
    fn_0a21_06fd();
    return (code *)0x0;
  case (code *)0x14:
    uStack_6 = (code *)CONCAT22(uStack_6._2_2_,pcVar14);
    pcStack_a = (code *)fn_1f2d_0002();
    pcStack_8 = (code *)in_EDX;
    setmem();
    iVar13 = fn_130a_07be();
    uStack_6 = (code *)CONCAT22(iVar13,(code *)uStack_6);
    if (iVar13 == 0) {
      g_2170 = strlen();
    }
    else {
      vsprintf();
      g_2170 = strlen();
    }
    fn_14b3_0284();
    iVar13 = 0;
    goto LAB_230a_0bc9;
  case (code *)0x15:
    if (g_2a7d <= (int)pcVar14) {
      unaff_DI = (code *)0x0;
    }
    unaff_DI[(int)g_2a79] = (code)0x0;
    memset();
    return (code *)(g_29b9 | g_29e1 | g_2a09 | g_2a31);
  case (code *)0x16:
    goto switchD_2000_4eaa_caseD_16;
  case (code *)0x17:
    iVar13 = in_CX - 1;
    pcVar15 = unaff_SI;
    if (iVar13 != 0 && pcVar28 != (code *)0x0) {
      uStack_50 = 0;
      uVar29 = (uint)(byte)(((byte)(param_5 >> 0x10) & 0xf) << 2);
      pcStack_a = (code *)(code *)*(undefined4 *)(uVar29 + 0x2b30);
      pcStack_8 = (code *)((ulong)*(undefined4 *)(uVar29 + 0x2b30) >> 0x10);
      local_e._0_2_ = (code *)(code *)*(undefined4 *)(uVar29 + 0x2b50);
      local_e._2_2_ = (code *)((ulong)*(undefined4 *)(uVar29 + 0x2b50) >> 0x10);
      local_12 = (code *)(code *)*(undefined4 *)(uVar29 + 0x2b70);
      local_10 = (code *)((ulong)*(undefined4 *)(uVar29 + 0x2b70) >> 0x10);
      uStack_6 = (code *)*(undefined4 *)((byte)((char)(param_5 >> 0x18) << 2) + 0x2b90);
      fn_215f_001d();
      iVar20 = (int)param_5 * 0x10;
      pcVar15 = (code *)(iVar20 + 0x1f3b);
      iVar13 = 3;
      unaff_DI = (code *)(*(uint *)pcVar15 * 8);
      if ((param_5 & 0x100000) == 0) {
        param_4 = CONCAT22(param_4._2_2_,(int)param_4 + *(uint *)pcVar15 * -8);
      }
      iStack_30 = *(int *)(iVar20 + 7999) << 3;
      pcVar14 = (code *)*(undefined2 *)(iVar20 + 0x1f3d);
    }
    pbVar2 = &stack0x0242 + (int)unaff_DI;
    bVar9 = (byte)iVar13 & 7;
    *pbVar2 = *pbVar2 >> bVar9 | *pbVar2 << 8 - bVar9;
    uStack_2c = SUB21(pcVar14,0);
    uStack_2b = (undefined1)((uint)pcVar14 >> 8);
    if ((param_5 & 0x100000) != 0) {
      param_4 = CONCAT22(pcVar14 + (int)param_4._2_2_,(int)param_4);
    }
    pcVar21 = pcVar14 + *(int *)(pcVar15 + 7);
    uStack_32 = *(uint *)CONCAT22(param_3,param_2);
    pcVar18 = (code *)((int)param_2 + 3);
    pcVar22 = (code *)(ulong)(byte)param_2[1];
    pcVar17 = param_3;
    if ((param_5 & 0x40000) != 0) {
      in_EDX = (code *)((long)pcVar22 * (ulong)uStack_4e >> 0x10);
      pcVar22 = (code *)((long)pcVar22 * (ulong)uStack_4e & 0xffff);
      goto switchD_2000_4eaa_caseD_3;
    }
    break;
  case (code *)0x18:
    return (code *)((CONCAT11(bVar9,(cVar10 - (char)*unaff_DI) - uVar32) & 0xff05) + 0xa8c);
  case (code *)0x19:
    iVar13 = fn_15a7_0210();
    if (iVar13 == 0) {
      uStack_6._0_2_ = (code *)0x0;
    }
    else {
    }
    return (code *)uStack_6;
  case (code *)0x1a:
    goto switchD_2000_4eaa_caseD_1a;
  case (code *)0x1b:
    return pcVar14;
  case (code *)0x1c:
    fn_1fd6_000a();
    return local_e._2_2_;
  }
  pcStack_34 = (code *)pcVar22;
  if ((param_5 & 0x200000) != 0) {
    param_4 = CONCAT22((int)param_4._2_2_ - (int)((ulong)pcVar22 >> 1),(int)param_4);
  }
  in_stack_0000ffc6 = *(code **)pcVar18;
  pcVar14 = in_stack_0000ffc6;
  if (((param_5 & 0x40000) != 0) &&
     (pcVar14 = (code *)(ZEXT24(in_stack_0000ffc6) * (ulong)uStack_4c >> 8), pcVar14 == (code *)0x0)
     ) {
    pcVar15 = (code *)fn_0fbe_059c();
    return pcVar15;
  }
  if ((param_5 & 0x200000) != 0) {
    in_EDX = (code *)(ulong)((uint)pcVar14 >> 1);
switchD_2000_4eaa_caseD_b:
    param_4 = CONCAT22(param_4._2_2_,(int)param_4 - (int)(code *)in_EDX);
  }
  uVar16 = uStack_54;
  if ((uStack_32 & 2) == 0) {
    fn_232c_000c();
    pcVar17 = (code *)((ulong)*(undefined4 *)&g_35ac >> 0x10);
  }
  if ((param_5 & 0x20000) == 0) {
    pcVar15 = (code *)((int)param_4._2_2_ - CONCAT11(uStack_2b,uStack_2c));
  }
  else {
    pcVar15 = pcVar21 + (-(int)pcStack_34 - (int)param_4._2_2_);
  }
  if ((int)pcVar15 < 0) {
    bVar33 = SCARRY2((int)pcStack_34,(int)pcVar15);
    pcStack_34 = pcStack_34 + (int)pcVar15;
    if (pcStack_34 == (code *)0x0 || bVar33 != (int)pcStack_34 < 0) {
      pcVar15 = (code *)fn_0fbe_059c();
      return pcVar15;
    }
    iStack_46 = -(int)pcVar15;
    do {
      do {
        iStack_56 = 0;
        (*(code *)local_e)();
        uStack_50 = uStack_50 + uStack_4e;
      } while ((uStack_50 & 0xff00) == 0);
      LOCK();
      uVar29 = uStack_50 >> 8;
      uStack_50 = uStack_50 & 0xff;
      UNLOCK();
      iVar13 = iStack_46 - uVar29;
      bVar33 = (int)uVar29 <= iStack_46;
      iStack_46 = iVar13;
    } while (iVar13 != 0 && bVar33);
    if (iVar13 < 0) {
      iStack_46 = -iVar13;
      uStack_50 = uStack_50 + iVar13 * -0x100;
    }
    unaff_SI = pcVar17;
    if ((param_5 & 0x20000) == 0) {
      param_4 = CONCAT22(CONCAT11(uStack_2b,uStack_2c),(int)param_4);
    }
  }
  if ((param_5 & 0x20000) == 0) {
    pcVar21 = pcVar21 + -(int)param_4._2_2_;
  }
  else {
    pcVar21 = pcStack_34 + ((int)param_4._2_2_ - CONCAT11(uStack_2b,uStack_2c));
  }
  if ((-1 < (int)pcVar21) && (pcVar21 != (code *)0x0)) {
    if ((pcVar21 < pcStack_34) && (pcStack_34 = pcVar21, (param_5 & 0x20000) != 0)) {
      param_4 = CONCAT22(CONCAT11(uStack_2b,uStack_2c),(int)param_4);
    }
    pcVar15 = (code *)0x0;
    pcStack_36 = pcVar14;
    if ((int)param_4 < 0) {
      pcStack_36 = pcVar14 + (int)param_4;
      pcVar15 = (code *)-(int)param_4;
      if (pcVar14 <= pcVar15) goto LAB_2fd6_041c;
      param_4 = param_4 & 0xffff0000;
    }
    pcStack_40 = (code *)0x0;
    pcVar21 = (code *)(iStack_30 - (int)param_4);
    if ((-1 < (int)pcVar21) && (pcVar21 != (code *)0x0)) {
      if (pcVar21 < pcStack_36) {
        pcStack_40 = pcVar14 + (-(int)pcVar21 - (int)pcVar15);
        pcStack_36 = pcVar21;
      }
      iStack_52 = 0x140;
      pcVar14 = param_4._2_2_;
      if ((param_5 & 0x20000) != 0) {
        iStack_52 = -0x140;
        pcVar14 = pcStack_34 + (int)(param_4._2_2_ + -1);
      }
      pcStack_42 = unaff_DI +
                   (int)param_4 +
                   *(int *)((int)pcVar14 * 2 +
                           (int)*(undefined4 *)
                                 ((char *)s_etainosrlhcdupmtasio_wb_rnsdalmh_3e2d_38b0 + 0x90));
      pcVar14 = pcStack_40;
      if ((param_5 & 0x10000) != 0) {
        LOCK();
        UNLOCK();
        pcStack_42 = pcStack_42 + (int)(pcStack_36 + -1);
        pcVar14 = pcVar15;
        pcVar15 = pcStack_40;
      }
      pcStack_40 = pcVar14;
      pcVar14 = pcVar15;
      if ((param_5 & 0x40000) != 0) {
        pcStack_40 = (code *)0x0;
        uVar23 = (ulong)CONCAT12((char)((uint)pcVar15 >> 8),(int)pcVar15 << 8);
        pcVar14 = (code *)(code *)(uVar23 / uStack_4c);
        iStack_56 = -(int)(uVar23 % (ulong)uStack_4c);
        pcStack_58 = pcVar15;
      }
      pcVar15 = pcVar17;
      if ((uStack_50 & 0xff00) == 0) goto LAB_2fd6_03be;
      while( true ) {
        pcVar17 = pcVar15;
        pcVar15 = pcVar14;
        (*pcStack_a)();
        if (in_stack_0000ffc6 != (code *)0x0) {
          pcVar21 = pcVar15 + (int)pcStack_36;
          if (pcVar21 != (code *)0x0 && SCARRY2((int)pcVar15,(int)pcStack_36) == (int)pcVar21 < 0) {
            (*local_12)();
          }
          if (pcVar21 + (int)pcStack_40 != (code *)0x0) {
            (*(code *)local_e)();
          }
        }
        pcStack_42 = pcStack_42 + iStack_52;
        pcStack_34 = pcStack_34 + -1;
        if (pcStack_34 == (code *)0x0) break;
        cVar10 = uStack_50._1_1_ + -1;
        uStack_50 = CONCAT11(cVar10,(undefined1)uStack_50);
        pcVar15 = unaff_SI;
        if (cVar10 == '\0') {
LAB_2fd6_03be:
          while (uStack_50 = uStack_50 + uStack_4e, pcVar15 = pcVar17, unaff_SI = pcVar17,
                (uStack_50 & 0xff00) == 0) {
            (*(code *)local_e)();
          }
        }
      }
    }
  }
LAB_2fd6_041c:
  fn_226d_004e();
  return (code *)uStack_6;
LAB_24b3_055c:
  in_CX = CONCAT11(bVar9,uStack_6._3_1_);
  iVar13 = fn_1e64_0007();
  g_ab4b = g_ab4b + iVar13;
  ((undefined1 *)&g_ab4f)[g_ab4d] = uStack_6._3_1_;
  puVar1 = (undefined1 *)&g_ab50 + g_ab4d;
  g_ab4d = g_ab4d + 1;
  *puVar1 = 0;
  if (g_371b < (uint)(g_ad95 + g_ab4b)) {
    fn_14b3_0731();
  }
  goto code_r0x00024e0d;
switchD_2000_4eaa_caseD_1a:
  (**(code **)(&stack0x004e + (int)unaff_SI))();
  pcVar22 = (code *)swi(0x21);
  (*pcVar22)();
  fn_1c8d_0286();
  uVar16 = uRam00020002;
  if ((bool)uVar32) {
LAB_2c8d_004b:
    pcVar22 = (code *)swi(0x21);
    (*pcVar22)();
    return (code *)0xffff;
  }
  pcVar17 = pcVar18 + 0x10;
  pcVar14 = local_16 + ((code *)0xffef < pcVar18);
  if (local_16 != (code *)0x4246) goto LAB_2c8d_004b;
  if (unaff_SS == 0x564f) {
    g_0114 = pcVar17;
    g_0116 = pcVar14;
    *(undefined2 *)0x2e40 = pcVar15;
    *(uint *)0x2e42 = (uint)local_10;
    pcVar22 = (code *)swi(0x21);
    (*pcVar22)();
    g_0128 = 0;
    fn_1c8d_013b();
    g_0120 = (int)param_4 + 1;
    g_0126 = param_3;
    g_0124 = g_0120;
    __InitModules();
    uVar29 = (int)g_0126 - g_0124;
    if (g_011a <= uVar29) {
      bVar33 = (uVar29 >> 1 & 1) != 0;
      g_0118 = uVar29 >> 2;
      pcVar15 = (code *)fn_1c8d_0316();
      if (bVar33) {
        return pcVar15;
      }
      return (code *)0x0;
    }
    goto LAB_2c8d_004b;
  }
  pcVar18 = pcVar17 + (int)pcVar15;
  uVar32 = CARRY2((uint)pcVar14,(uint)local_10) ||
           CARRY2((uint)(pcVar14 + (int)local_10),(uint)CARRY2((uint)pcVar17,(uint)pcVar15));
  local_16 = pcVar14 + (int)local_10 + CARRY2((uint)pcVar17,(uint)pcVar15);
  goto switchD_2000_4eaa_caseD_1a;
switchD_2000_4eaa_caseD_16:
  do {
    pcVar15 = (code *)in_EDX + (int)pcVar14 * -2;
    pcVar18 = pcVar18 + 0x140;
    pcVar17 = pcVar18 + (int)pcVar15;
    while (in_EDX = (code *)ZEXT24(pcVar15), pcVar15 < pcVar28) {
      while( true ) {
        while( true ) {
          while( true ) {
            pcVar21 = unaff_SI + 1;
            cVar11 = *unaff_SI;
            uVar24 = (undefined3)((ulong)pcVar22 >> 8);
            pcVar22 = (code *)CONCAT31(uVar24,cVar11);
            uVar32 = (undefined1)(in_CX >> 8);
            if (cVar11 != (code)0x0) break;
            iVar13 = CONCAT11(uVar32,*pcVar21);
            pcVar15 = unaff_SI + 2;
            unaff_SI = unaff_SI + 3;
            cVar11 = *pcVar15;
            pcVar22 = (code *)CONCAT31(uVar24,cVar11);
            do {
              *pcVar17 = cVar11;
              pcVar17 = pcVar17 + 1;
              pcVar15 = (code *)in_EDX + 1;
              if (pcVar15 == pcVar28) {
                pcVar15 = (code *)0x0;
                pcVar17 = pcVar18 + 0x140;
                pcVar18 = pcVar17;
              }
              in_EDX = (code *)ZEXT24(pcVar15);
              iVar13 = iVar13 + -1;
            } while (iVar13 != 0);
            in_CX = 0;
          }
          if ((char)cVar11 < '\0') break;
          iVar13 = CONCAT11(uVar32,cVar11);
          do {
            pcVar5 = pcVar21;
            pcVar21 = pcVar21 + 1;
            pcVar22 = (code *)CONCAT31((int3)((ulong)pcVar22 >> 8),*pcVar5);
            *pcVar17 = *pcVar5;
            pcVar17 = pcVar17 + 1;
            pcVar15 = (code *)in_EDX + 1;
            if (pcVar15 == pcVar28) {
              pcVar15 = (code *)0x0;
              pcVar17 = pcVar18 + 0x140;
              pcVar18 = pcVar17;
            }
            in_EDX = (code *)ZEXT24(pcVar15);
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
          in_CX = 0;
          unaff_SI = pcVar21;
        }
        pcVar22 = (code *)CONCAT31(uVar24,(char)cVar11 + -0x80);
        if ((char)((char)cVar11 + -0x80) != '\0') break;
        pcVar15 = unaff_SI + 3;
        uVar29 = *(uint *)pcVar21;
        if ((int)uVar29 < 1) {
          if (uVar29 == 0) {
            return (code *)0x0;
          }
          uVar19 = uVar29 + 0x8000;
          if ((uVar19 & 0x4000) == 0) {
            do {
              unaff_SI = pcVar15 + 1;
              *pcVar17 = *pcVar15;
              pcVar17 = pcVar17 + 1;
              pcVar15 = (code *)in_EDX + 1;
              if (pcVar15 == pcVar28) {
                pcVar15 = (code *)0x0;
                pcVar17 = pcVar18 + 0x140;
                pcVar18 = pcVar17;
              }
              in_EDX = (code *)ZEXT24(pcVar15);
              uVar19 = uVar19 - 1;
              pcVar15 = unaff_SI;
            } while (uVar19 != 0);
            pcVar22 = (code *)0x0;
            in_CX = 0;
          }
          else {
            iVar13 = uVar29 + 0x4000;
            unaff_SI = unaff_SI + 4;
            cVar11 = *pcVar15;
            do {
              *pcVar17 = cVar11;
              pcVar17 = pcVar17 + 1;
              pcVar15 = (code *)in_EDX + 1;
              if (pcVar15 == pcVar28) {
                pcVar15 = (code *)0x0;
                pcVar17 = pcVar18 + 0x140;
                pcVar18 = pcVar17;
              }
              in_EDX = (code *)ZEXT24(pcVar15);
              iVar13 = iVar13 + -1;
            } while (iVar13 != 0);
            pcVar22 = (code *)0x0;
            in_CX = 0;
          }
        }
        else {
          pcVar17 = pcVar17 + uVar29;
          pcVar21 = (code *)in_EDX + uVar29;
          while (in_EDX = (code *)ZEXT24(pcVar21), pcVar28 <= pcVar21) {
            pcVar21 = pcVar21 + (int)pcVar14 * -2;
            pcVar18 = pcVar18 + 0x140;
            pcVar17 = pcVar18 + (int)pcVar21;
          }
          pcVar22 = (code *)0x0;
          unaff_SI = pcVar15;
        }
      }
      pcVar17 = pcVar17 + (int)(code *)pcVar22;
      unaff_SI = pcVar21;
      pcVar15 = (code *)in_EDX + (int)(code *)pcVar22;
    }
  } while( true );
switchD_2000_4eaa_caseD_2:
  do {
    if (*(code **)(param_1 + 2) != local_e._2_2_) goto LAB_263d_02b9;
    unaff_SI = (code *)(*(uint *)((int)param_1 + 0xe) & 0xf000);
    if (unaff_SI != (code *)0x0) goto LAB_263d_02a3;
    do {
      unaff_SI = (code *)(*(uint *)((int)param_1 + 0xe) & 0xf00);
LAB_263d_02a3:
      in_CX = 1;
      *(uint *)((int)param_1 + 0x2e) = *(uint *)((int)param_1 + 0x2e) | 0x80;
      unaff_DI = (code *)0x0;
      g_2890 = (long *)CONCAT22(param_2,param_1);
LAB_263d_02b9:
      do {
        local_10 = (code *)0x0;
        if (in_CX == 0) {
          *(uint *)((int)param_1 + 0x2e) = *(uint *)((int)param_1 + 0x2e) & 0xfff9;
        }
        if ((((((uint)unaff_SI & 0x3300) == 0) || ((*(uint *)((int)param_1 + 0xe) & 4) == 0)) ||
            (in_CX == 0)) ||
           (((long *)CONCAT22(param_2,param_1) != g_2890 && (g_2890 != (long *)0x0))))
        {
          if ((((uint)unaff_SI & 0x8800) == 0) ||
             (((*(uint *)((int)param_1 + 0xe) & 4) != 0 || (in_CX == 0)))) {
            *(uint *)((int)param_1 + 0x2e) = *(uint *)((int)param_1 + 0x2e) & 0xfff9;
          }
          else {
            *(uint *)((int)param_1 + 0x2e) = *(uint *)((int)param_1 + 0x2e) | 6;
          }
        }
        else {
          *(uint *)((int)param_1 + 0x2e) = *(uint *)((int)param_1 + 0x2e) | 6;
          if (g_2890 == (long *)0x0) {
            g_2890 = (long *)CONCAT22(param_2,param_1);
          }
        }
        uVar29 = in_CX;
        if ((g_2890 != (long *)0x0) &&
           ((*(uint *)((int)(long *)g_2890 + 0xe) & 0x40) != 0)) {
          uVar29 = (uint)(g_2890 == (long *)CONCAT22(param_2,param_1));
        }
        if (uVar29 != 0) {
          if (((((uint)unaff_SI & 0x1100) != 0) && (in_CX != 0)) && (g_2890 == (long *)0x0))
          {
            unaff_DI = (code *)0x0;
            g_2890 = (long *)CONCAT22(param_2,param_1);
          }
          if (((*(uint *)((int)param_1 + 0xe) & (uint)unaff_SI) != 0) &&
             ((in_CX != 0 || ((*(uint *)((int)param_1 + 0xe) & 1) == 0)))) {
            uVar29 = (uint)unaff_SI & *(uint *)((int)param_1 + 0xe);
            pcStack_a = (code *)((uVar29 & 0xf00 | (uVar29 & 0xf000) >> 4) >> 8);
            iVar13 = *(int *)((int)pcStack_a * 2 + 0x2898);
            if (iVar13 == 0x200) {
              if ((*(uint *)((int)param_1 + 0xe) & 4) != 0) {
                *(uint *)((int)param_1 + 0x2e) = *(uint *)((int)param_1 + 0x2e) | 4;
                *(uint *)((int)param_1 + 0x2e) = *(uint *)((int)param_1 + 0x2e) | 2;
              }
              uVar29 = *(uint *)((int)param_1 + 0xe);
joined_r0x00026849:
              if ((uVar29 & 1) == 0) {
                local_10 = (code *)0x1;
              }
            }
            else if (iVar13 == 0x400) {
              if ((((*(uint *)((int)param_1 + 0xe) & 1) != 0) &&
                  (g_2890 == (long *)CONCAT22(param_2,param_1))) ||
                 ((*(uint *)((int)param_1 + 0xe) & 1) == 0)) {
                *(uint *)((int)param_1 + 0x2e) = *(uint *)((int)param_1 + 0x2e) ^ 1;
                local_e._0_2_ = (code *)(*(uint *)(param_1 + 1) | 0x8000);
                local_10 = (code *)0x1;
              }
              if ((*(uint *)((int)param_1 + 0xe) & 4) == 0) {
                *(uint *)((int)param_1 + 0x2e) = *(uint *)((int)param_1 + 0x2e) & 0xfffb;
                *(uint *)((int)param_1 + 0x2e) = *(uint *)((int)param_1 + 0x2e) & 0xfffd;
              }
            }
            else {
              if (iVar13 == 0x800) {
                if ((*(uint *)((int)param_1 + 0xe) & 4) == 0) {
                  *(uint *)((int)param_1 + 0x2e) = *(uint *)((int)param_1 + 0x2e) | 4;
                  *(uint *)((int)param_1 + 0x2e) = *(uint *)((int)param_1 + 0x2e) | 2;
                }
                uVar29 = *(uint *)((int)param_1 + 0xe);
                goto joined_r0x00026849;
              }
              *(uint *)((int)param_1 + 0x2e) = *(uint *)((int)param_1 + 0x2e) ^ 1;
              local_e._0_2_ = (code *)(*(uint *)(param_1 + 1) | 0x8000);
              local_10 = (code *)0x1;
              if ((*(uint *)((int)param_1 + 0xe) & 4) != 0) {
                *(uint *)((int)param_1 + 0x2e) = *(uint *)((int)param_1 + 0x2e) | 4;
                *(uint *)((int)param_1 + 0x2e) = *(uint *)((int)param_1 + 0x2e) | 2;
              }
              g_2890 = (long *)CONCAT22(param_2,param_1);
            }
          }
        }
        if ((((((uint)unaff_SI & 0x2200) != 0) && (in_CX != 0)) &&
            (*(uint *)((int)param_1 + 0x2e) = *(uint *)((int)param_1 + 0x2e) | 6,
            (*(uint *)((int)param_1 + 0xe) & 4) == 0)) &&
           ((*(uint *)((int)param_1 + 0x2e) & 1) == 0)) {
          uStack_6 = (code *)CONCAT22(1,(code *)uStack_6);
          *(uint *)((int)param_1 + 0x2e) = *(uint *)((int)param_1 + 0x2e) | 1;
        }
        if ((((*(uint *)((int)param_1 + 0x2e) & 0x80) != 0) || (((uint)unaff_SI & 0x8800) == 0x8800)
            ) && ((g_2890 = (long *)0x0, in_CX == 0 ||
                  ((*(uint *)((int)param_1 + 0xe) & 4) != 0)))) {
          *(uint *)((int)param_1 + 0x2e) = *(uint *)((int)param_1 + 0x2e) & 0xfff9;
        }
        if (((in_CX == 0) && ((long *)CONCAT22(param_2,param_1) == g_2890)) &&
           ((*(uint *)((int)param_1 + 0xe) & 0x40) == 0)) {
          g_2890 = (long *)0x0;
        }
        if ((*(uint *)((int)param_1 + 0x2e) & 0x18) != (*(uint *)((int)param_1 + 0x2e) & 3) << 3) {
          fn_163d_05cc();
        }
        if (uStack_6._2_2_ != 0) {
          *(uint *)((int)param_1 + 0x2e) = *(uint *)((int)param_1 + 0x2e) & 0xfffe;
        }
        if (local_10 != (code *)0x0) {
          *(uint *)((int)param_1 + 0x2e) = *(uint *)((int)param_1 + 0x2e) & 0xff;
          *(uint *)((int)param_1 + 0x2e) = *(uint *)((int)param_1 + 0x2e) | (uint)unaff_SI;
          if (((param_1[0xc] != 0) && (iVar13 = (**(code **)(param_1 + 0xc))(), iVar13 != 0)) ||
             ((*(uint *)((int)param_1 + 0xe) & 0x20) != 0)) goto LAB_263d_05b7;
        }
        if ((g_2890 == (long *)CONCAT22(param_2,param_1)) &&
           ((*(uint *)((int)param_1 + 0xe) & 0x40) != 0)) {
LAB_263d_05b7:
          if ((code *)local_e == (code *)0x0) {
            local_e._0_2_ = (code *)((uint)unaff_DI & 0x7fff);
          }
          return (code *)local_e;
        }
        do {
          plVar8 = (long *)*param_1;
          param_1 = (long *)plVar8;
          param_2 = (uint *)((ulong)plVar8 >> 0x10);
          if (plVar8 == (long *)0x0) goto LAB_263d_05b7;
        } while ((*(uint *)((int)param_1 + 0xe) & 8) != 0);
        *(uint *)((int)param_1 + 0x2e) = *(uint *)((int)param_1 + 0x2e) & 0xffe7;
        *(uint *)((int)param_1 + 0x2e) =
             *(uint *)((int)param_1 + 0x2e) | (*(uint *)((int)param_1 + 0x2e) & 3) << 3;
        iVar13 = *(int *)((int)param_1 + 0x1e);
        if (iVar13 < 0) {
          iVar13 = iVar13 + *(int *)((int)param_1[7] * 0x10 + 7999) * 8;
        }
        iVar13 = iVar13 + *(int *)((int)param_1[7] * 0x10 + 0x1f3b) * 8;
        iVar20 = (int)param_1[8];
        if (iVar20 < 0) {
          iVar20 = iVar20 + *(int *)((int)param_1[7] * 0x10 + 0x1f41);
        }
        iVar20 = iVar20 + *(int *)((int)param_1[7] * 0x10 + 0x1f3d);
        if ((((int)(code *)uStack_6 < iVar13) || ((int)pcStack_8 < iVar20)) ||
           ((iVar13 + *(int *)((int)param_1 + 0x22) < (int)(code *)uStack_6 ||
            (iVar20 + (int)param_1[9] < (int)pcStack_8)))) {
          in_CX = 0;
        }
        else {
          in_CX = 1;
        }
        *(uint *)((int)param_1 + 0x2e) = *(uint *)((int)param_1 + 0x2e) & 0xff7f;
        local_e._2_2_ = (code *)((uint)unaff_DI & 0x7fff);
      } while (local_e._2_2_ == (code *)0x0);
    } while ((code *)*(int *)((int)param_1 + 6) == local_e._2_2_);
  } while( true );
switchD_2000_4eaa_caseD_0:
  if (param_4 == 0) {
LAB_2809_0a81:
    fn_203b_0203();
    fn_1981_031f();
    g_abde = g_abde + -1;
    return (code *)local_e;
  }
  g_ae4d = 0;
  uVar16 = fn_2148_00c9();
  if (g_ae4d != 0) {
    uVar16 = fn_1809_133b();
    uStack_6 = (code *)CONCAT22(*(undefined2 *)((int)unaff_DI * 0x14 + 2),(code *)uStack_6);
  }
  pcVar15 = param_3;
  fn_2279_025b();
  param_4 = param_4 - (long)CONCAT22(uVar16,pcVar15);
  local_e = local_e + (long)CONCAT22(uVar16,pcVar15);
  *(undefined4 *)((int)unaff_DI * 0x14 + 4) =
       (code *)CONCAT22(uVar16,pcVar15) + *(long *)((int)unaff_DI * 0x14 + 4);
  if ((code *)CONCAT22(uVar16,pcVar15) < (code *)CONCAT22(unaff_SS,local_16)) goto LAB_2809_0a81;
  pcVar22 = (code *)CONCAT22(param_3,(code *)pcVar22) + (long)CONCAT22(uVar16,pcVar15);
  param_3 = (code *)((ulong)pcVar22 >> 0x10);
  goto switchD_2000_4eaa_caseD_0;
  while( true ) {
    *(undefined1 *)((int)param_2 + aiStack_750[iVar13 + 1]) = (char)aiStack_750[iVar13];
    iVar13 = iVar13 + 2;
    if (9 < iVar13) break;
LAB_230a_0bc9:
    if (aiStack_750[iVar13] == 0) break;
  }
  fn_14b3_0122();
  fn_1e74_000f();
  pcVar15 = (code *)fn_1f2d_0002();
  g_20f6 = 0;
  return pcVar15;
}


//// fn_14b3_062d @ 24b3:062d

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far fn_14b3_062d(void)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = 0x24b3;
  if (((g_3717 + -1 <= g_284c) && (g_3644 != '\0')) &&
     (g_284c = 0, g_370d != (code *)0x0)) {
    if (g_3649 == 0) {
      uVar3 = 0x334e;
      fn_234e_0062();
    }
    (*g_370d)(uVar3,g_1614,g_284f,g_2851,g_2853);
    if (g_3649 == 0) {
      uVar3 = 0x334e;
      fn_234e_0003(g_3715);
    }
    g_2172 = 0;
  }
  uVar1 = g_ad91 / (uint)(g_3629 + g_3626);
  iVar2 = g_3629 + g_3626;
  if (g_ad91 != g_3629 + g_3626) {
    fn_1dbc_0017(uVar3,g_ad8d,g_ad8b + g_3629 + g_3626,g_ad8d,
                  g_ad8b,g_ad8f,g_ad91 - (g_3629 + g_3626),
                  g_3649,g_3649);
  }
  fn_1e59_001d(g_ad8d << 3,g_ad8b + (uVar1 - 1) * iVar2,
                (g_ad8d + g_ad8f) * 8 + -1,g_ad8b + g_ad91 + -1,
                g_3711);
  return;
}


//// fn_14b3_0731 @ 24b3:0731

void __cdecl16far fn_14b3_0731(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint local_8;
  int local_6;
  int local_4;
  
  while (iVar6 = g_ab4d, g_3717 <= g_ad93) {
    fn_14b3_062d();
    if (g_3717 <= g_ad93) {
      g_ad93 = g_ad93 - 1;
    }
  }
  iVar2 = g_ad8d * 8 + g_ad95;
  iVar5 = g_ad8b + g_ad93 * (g_3629 + g_3626);
  local_8 = g_371b;
  local_6 = g_ab4b;
  if (g_371b < g_ad95 + g_ab4b) {
    if (((int)(g_3717 - 1) <= g_284c) && (g_3644 != '\0')) {
      local_8 = g_371b - g_284f * (g_3628 + g_3624);
    }
    iVar3 = local_8 - g_ad95;
    local_4 = 0;
    iVar4 = g_ab4d;
    do {
      iVar7 = iVar4 + -1;
      if (iVar7 < 1) goto LAB_24b3_080b;
      cVar1 = *(char *)((int)(undefined2 *)&g_ab4d + iVar4 + 1);
      iVar4 = fn_1e64_0007(cVar1);
      local_6 = local_6 - iVar4;
      if ((local_4 == 0) && (local_6 <= iVar3)) {
        local_4 = iVar7;
      }
      iVar4 = iVar7;
    } while ((local_4 == 0) || (cVar1 != ' '));
    g_284e = '\0';
    iVar6 = iVar7;
LAB_24b3_080b:
    if (((iVar7 == 0) && (iVar6 = local_4, g_ad95 != 0)) && (g_284e == '\0')) {
      local_6 = 0;
      g_284e = '\x01';
      iVar6 = 0;
    }
  }
  cVar1 = ((undefined1 *)&g_ab4f)[iVar6];
  ((undefined1 *)&g_ab4f)[iVar6] = 0;
  fn_1f6c_0006((undefined1 *)&g_ab4f,0x3e2d,iVar2,iVar5,g_3713,g_3711);
  g_ad95 = g_ad95 + local_6;
  iVar2 = strlen((undefined1 *)&g_ab4f,0x3e2d);
  g_2172 = g_2172 + iVar2;
  ((undefined1 *)&g_ab4f)[iVar6] = cVar1;
  if (cVar1 == ' ') {
    iVar6 = iVar6 + 1;
  }
  if (((undefined1 *)&g_ab4f)[iVar6] == ' ') {
    iVar6 = iVar6 + 1;
  }
  strcpy((undefined1 *)&g_ab4f,0x3e2d,(undefined1 *)&g_ab4f + iVar6,0x3e2d);
  g_ab4d = strlen((undefined1 *)&g_ab4f,0x3e2d);
  g_ab4b = fn_1e64_002b((undefined1 *)&g_ab4f,0x3e2d);
  if ((g_ab4d != 0) || (g_371b <= g_ad95)) {
    g_ab49 = 0;
    g_ad95 = 0;
    g_ad93 = g_ad93 + 1;
    g_284c = g_284c + 1;
    fn_14b3_0731();
  }
  return;
}


//// fn_14b3_08e1 @ 24b3:08e1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far fn_14b3_08e1(char *param_1)

{
  char cVar1;
  
  cVar1 = '\0';
  if (g_ab41 != (char *)0x0) {
    if (*g_ab41 == '\0') {
      g_ab41 = (char *)0x0;
      cVar1 = g_ab3e;
    }
    else {
      cVar1 = *g_ab41;
      g_ab41 = (char *)CONCAT22(g_ab43,g_ab41 + 1);
    }
  }
  if ((cVar1 == '\0') && (g_ab45 != (char *)0x0)) {
    if (*g_ab45 == '\0') {
      g_ab45 = (char *)0x0;
    }
    else {
      cVar1 = *g_ab45;
      g_ab45 = (char *)CONCAT22(g_ab45._2_2_,(char *)g_ab45 + 1);
    }
  }
  *param_1 = cVar1;
  param_1 = (char *)CONCAT22(param_1._2_2_,(char *)param_1 + 1);
  *param_1 = '\0';
  return;
}


//// fn_14b3_095d @ 24b3:095d

char __cdecl16far fn_14b3_095d(void)

{
  char cVar1;
  char cVar2;
  
  if (g_ab3f == '\0') {
    fn_14b3_08e1((undefined1 *)&g_ab3f,0x3e2d);
  }
  cVar2 = g_ab40;
  cVar1 = g_ab3f;
  g_ab3f = g_ab40;
  g_ab40 = 0;
  if (cVar2 == '\0') {
    fn_14b3_08e1((undefined1 *)&g_ab3f,0x3e2d);
  }
  return cVar1;
}

