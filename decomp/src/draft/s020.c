//// fn_130a_0052 @ 230a:0052

void __cdecl16far
fn_130a_0052(int param_1,int param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5,
             undefined2 param_6)

{
  uint *puVar1;
  
  fn_1aff_030e((char *)s_ADLIBG_ADV_3e2d_1d00 + 4 + param_1 * 0x10,(undefined1 *)&g_3803,
                (char *)s_ADLIBG_ADV_3e2d_1d00 + 6 + param_1 * 0x10,(undefined1 *)&g_3803,
                param_3,param_4,param_5);
  if (*(int *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 2 + param_1 * 0x10) != 0) {
    fn_07bc_0367(param_1,*(undefined2 *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 2 + param_1 * 0x10));
  }
  if (g_7fe5 == param_2) {
    fn_07bc_0272(param_1,*(undefined2 *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 4 + param_1 * 0x10),
                  *(undefined2 *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 6 + param_1 * 0x10),param_6,1);
  }
  else {
    ((char *)s_ADLIBG_ADV_3e2d_1d00 + 8)[param_1 * 0x10] = (char)param_2;
    *(undefined2 *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 2 + param_1 * 0x10) = param_3;
    ((char *)s_ADLIBG_ADV_3e2d_1d00 + 1)[param_1 * 0x10] = (char)param_6;
    puVar1 = (uint *)(param_1 * 0x10 + 0x1d0b);
    *puVar1 = *puVar1 | 0x4000;
  }
  return;
}


//// fn_130a_012a @ 230a:012a

undefined2 __cdecl16far fn_130a_012a(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined4 local_6;
  
  uVar6 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  iVar4 = iVar3 + *(char *)(iVar3 + 0xf) * 0x10;
  local_6 = (int *)CONCAT22(uVar6,(int *)(iVar4 + 0x15));
  *(undefined4 *)(iVar3 + 8) = 0;
  if (*(int *)(iVar4 + 0x17) < *local_6) {
    iVar2 = -1;
    *(char *)(iVar3 + 0x10) = *(char *)(iVar3 + 0x10) + -1;
  }
  else {
    iVar2 = 1;
    *(char *)(iVar3 + 0x10) = *(char *)(iVar3 + 0x10) + '\x01';
  }
  if ((int)*(char *)(iVar3 + 0x10) == *(int *)(iVar4 + 0x17) + iVar2) {
    cVar1 = *(char *)(iVar3 + 0x11) + '\x01';
    *(char *)(iVar3 + 0x11) = cVar1;
    if ((*(int *)(iVar4 + 0x19) < (int)cVar1) || (*(char *)(iVar3 + 0xd) != '\0')) {
      *(undefined1 *)(iVar3 + 0x14) = *(undefined1 *)(iVar3 + 0xf);
      if ((*(int *)(iVar4 + 0x1b) == -1) ||
         ((*(char *)(iVar3 + 0xd) != '\0' && (*(int *)(iVar4 + 0x1f) != 0)))) {
        *(undefined1 *)(iVar3 + 0xc) = 0;
        *(undefined1 *)(iVar3 + 0xd) = 0;
        return 0;
      }
      *(long *)(iVar3 + 8) = *(long *)(iVar3 + 8) + (long)*(int *)(iVar4 + 0x1d);
      *(undefined1 *)(iVar3 + 0xf) = *(undefined1 *)(iVar4 + 0x1b);
      local_6 = (int *)CONCAT22(uVar6,(int *)(iVar3 + *(char *)(iVar3 + 0xf) * 0x10 + 0x15));
      *(undefined1 *)(iVar3 + 0x10) = (char)*local_6;
      *(undefined1 *)(iVar3 + 0x11) = 0;
    }
    else {
      *(undefined1 *)(iVar3 + 0x10) = (char)*local_6;
    }
  }
  uVar7 = (undefined2)((ulong)local_6 >> 0x10);
  piVar5 = (int *)local_6;
  if ((piVar5[6] != -1) && ((int)*(char *)(iVar3 + 0x10) == piVar5[7])) {
    fn_067a_0401(piVar5[6],0);
  }
  *(long *)(iVar3 + 8) = *(long *)(iVar3 + 8) + (long)(int)*(char *)(iVar3 + 0xe);
  return 1;
}


//// fn_130a_028a @ 230a:028a

void __cdecl16far fn_130a_028a(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined2 uVar4;
  undefined4 local_6;
  
  if ((g_7fd6 & 8) == 0) {
    local_6 = &g_4ee0;
    for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
      puVar2 = (undefined4 *)local_6;
      uVar4 = (undefined2)((ulong)local_6 >> 0x10);
      if ((((local_6 != (undefined4 *)0x0) && (*(char *)(puVar2 + 3) != '\0')) &&
          ((ulong)puVar2[2] < g_384c)) && (iVar1 = fn_130a_012a(puVar2,uVar4), iVar1 != 0))
      {
        iVar1 = ovr_2cef_0025((int)*local_6,(int)((ulong)*local_6 >> 0x10));
        iVar1 = ovr_2cef_0020((int)*local_6,(int)((ulong)*local_6 >> 0x10),
                              *(int *)((int)puVar2 + 6) + iVar1);
        fn_1ebc_0111(*(undefined2 *)(puVar2 + 1),*(undefined2 *)((int)puVar2 + 6),
                      *(int *)(puVar2 + 1) + iVar1);
        ovr_2dfd_002a((char *)s_PageArraySize_is_negative__3e2d_2eba + 2,*local_6,
                      *(char *)(puVar2 + 4) + -1,*(undefined2 *)(puVar2 + 1),
                      *(undefined2 *)((int)puVar2 + 6),0,0);
        fn_1ebc_01ec();
        puVar2[2] = puVar2[2] + g_384c;
      }
      local_6 = (undefined4 *)CONCAT22(uVar4,(undefined4 *)((int)puVar2 + 0xb5));
    }
  }
  return;
}


//// fn_130a_0360 @ 230a:0360

void __cdecl16far fn_130a_0360(int param_1,int param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  
  if (param_2 == -1) {
    iVar2 = 0;
    do {
      *(undefined1 *)(param_1 * 10 + iVar2 + -0x7dfd) = (undefined1)param_3;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 4);
    if (*(char *)(param_3 + 0x3835) == '\x11') {
      pbVar1 = (byte *)(param_1 * 10 + -0x7df4);
      *pbVar1 = *pbVar1 & 0xef;
      pbVar1 = (byte *)(param_1 * 10 + -0x7df4);
      *pbVar1 = *pbVar1 | 0x20;
    }
    else {
      pbVar1 = (byte *)(param_1 * 10 + -0x7df4);
      *pbVar1 = *pbVar1 & 0xdf;
    }
  }
  else {
    *(undefined1 *)(param_1 * 10 + param_2 + -0x7dfd) = (undefined1)param_3;
  }
  fn_0845_046c(param_1);
  return;
}


//// fn_130a_03cd @ 230a:03cd

undefined2 __cdecl16far
fn_130a_03cd(uint param_1,int param_2,undefined2 param_3,undefined4 param_4,long param_5,
             long param_6,undefined2 param_7)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined2 uVar6;
  uint uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  int iVar10;
  undefined2 uVar11;
  
  bVar1 = false;
  if ((param_1 == 0xffff) || ((param_1 & 0x70) == 0)) {
    uVar4 = param_1;
    if (param_1 == 1) {
      if (g_7fe3 == '\0') {
        param_1 = 0;
        uVar4 = param_1;
      }
      else {
        param_1 = *(uint *)((int)(undefined2 *)&g_363a + g_7fe3 * 0x82 + 1);
        uVar4 = param_1;
      }
    }
  }
  else {
    param_1 = param_1 ^ 0x70;
    uVar4 = 0;
  }
  fn_130a_0784();
  if ((int)param_1 < 0) {
    iVar2 = rand(0x230a);
    iVar10 = iVar2 >> 0xf;
    iVar3 = ovr_2d74_0025();
    uVar4 = (uint)((CONCAT22(iVar10,iVar2) * (long)iVar3) / 0x8000);
    uVar5 = uVar4;
  }
  else {
    uVar5 = param_1;
    if (0 < (int)param_1) {
      uVar7 = 0;
      do {
        uVar5 = uVar7;
        if ((*(uint *)((int)(undefined2 *)&g_363a + uVar5 * 0x82 + 1) == param_1) &&
           ((*(uint *)((int)(undefined4 *)&g_362a + uVar5 * 0x82 + 3) & 1) != 0)) {
          uVar7 = uVar5;
          if (uVar4 == param_1) {
            uVar4 = uVar5;
          }
          break;
        }
        uVar7 = uVar5 + 1;
        uVar5 = param_1;
      } while ((int)uVar7 < 4);
      if (uVar7 == 4) {
        if (uVar5 != 8) {
          return 0;
        }
        bVar1 = true;
      }
    }
  }
  if (!bVar1) {
    g_4bfa = param_2;
    g_4bf8 = uVar5;
    uVar5 = strlen((int)param_4,(int)((ulong)param_4 >> 0x10));
    g_4bfc = uVar5 >> 1;
    g_4c00 = param_3;
  }
  iVar2 = (int)param_5;
  uVar8 = (undefined2)((ulong)param_5 >> 0x10);
  iVar3 = (int)param_6;
  uVar9 = (undefined2)((ulong)param_6 >> 0x10);
  if (param_5 == 0) {
    if (param_6 != 0) {
      uVar6 = *(undefined2 *)(iVar3 + 4);
      goto LAB_230a_04f6;
    }
  }
  else {
    uVar6 = *(undefined2 *)(iVar2 + (*(int *)(iVar2 + 0xc) + 2) * 2 + 0x2c);
LAB_230a_04f6:
    fn_154c_01d3(uVar6,uVar4,0);
  }
  if (g_81fd._1_1_ != '\0') {
    if (param_2 == 0) {
      fn_130a_0a7c(3,param_4,iVar2,uVar8,iVar3,uVar9,param_7);
    }
    else {
      if (param_2 == 1) {
        g_1f87 = 0;
        g_1f89 = 0;
        fn_14b3_01fa(4);
        fn_1e9a_000b(4,0x10,0x7b,0x17,0x2f);
        fn_130a_0a7c(4,param_4,iVar2,uVar8,iVar3,uVar9,param_7);
        uVar6 = 0x1c;
        uVar11 = 0x2f;
        uVar8 = 0xb;
        uVar9 = 0x7b;
      }
      else {
        if (param_2 != 2) goto LAB_230a_05ed;
        g_1f87 = 0;
        g_1f89 = 0;
        uVar6 = fn_14b3_01fa(4);
        fn_1e9a_000b(4,9,0x85,0x1e,0x3c);
        fn_130a_0a7c(4,param_4,iVar2,uVar8,iVar3,uVar9,3);
        fn_14b3_0122(uVar6);
        uVar6 = 0x25;
        uVar11 = 0x3c;
        uVar8 = 1;
        uVar9 = 0x85;
      }
      fn_1e9a_000b(4,uVar8,uVar9,uVar6,uVar11);
    }
  }
LAB_230a_05ed:
  g_20f6 = 0;
  if (!bVar1) {
    fn_130a_0605();
  }
  return 1;
}


//// fn_130a_0605 @ 230a:0605

void __cdecl16far fn_130a_0605(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 local_4;
  
  iVar4 = 0;
  local_4 = 0;
  bVar1 = false;
  if (g_4bfa == 0) {
    iVar4 = *(int *)((int)(undefined2 *)&g_3624 + g_4bf8 * 2 + 1);
    local_4 = 0x90;
    bVar1 = true;
  }
  else if (g_4bfa == 1) {
    if (g_81fd._1_1_ == '\0') {
      iVar4 = *(int *)((int)(undefined2 *)&g_3624 + g_4bf8 * 2 + 1);
      local_4 = 0x90;
    }
    else {
      iVar4 = 0x5a;
      local_4 = 0x82;
    }
  }
  else if (g_4bfa == 2) {
    if (g_81fd._1_1_ == '\0') {
      local_4 = 0x91;
      iVar4 = *(int *)((int)(undefined2 *)&g_3624 + g_4bf8 * 2 + 1) + 10;
    }
    else {
      iVar4 = 0x10;
      local_4 = 0x86;
    }
  }
  iVar2 = fn_0845_0636(0x60001);
  iVar3 = iVar2 + -1;
  if ((int)*(char *)(g_4bf8 * 0x82 + 0x363d) == iVar2 + -1) {
    iVar3 = iVar2;
  }
  if (5 < iVar3) {
    iVar3 = iVar3 + -5;
  }
  if (g_81ff != '\0') {
    iVar2 = fn_154c_0136();
    if (iVar2 == 2) {
      g_4bfc = 2;
    }
    else {
      g_4bfc = 1;
    }
  }
  g_4bfc = g_4bfc + -1;
  if (g_4bfc == 0) {
    if (g_4c00 != 0) {
      fn_0a21_0608();
      if (bVar1) {
        fn_0a21_022b();
        fn_0845_114d(0);
      }
      else {
        fn_0a21_00ec(g_4bf8,iVar4,local_4,0);
      }
      g_4bf8 = -1;
    }
  }
  else {
    fn_0a21_05ef(g_4bf8,iVar3 + 7);
    if (bVar1) {
      fn_0a21_022b();
    }
    else {
      fn_0a21_00ec(g_4bf8,iVar4,local_4,0);
    }
    g_4c02 = g_384c + 10;
  }
  return;
}


//// fn_130a_0784 @ 230a:0784

void __cdecl16far fn_130a_0784(void)

{
  if (g_4bf8 != -1) {
    g_4bfc = 1;
    g_4c00 = 1;
    fn_130a_0605();
    g_4bf8 = -1;
    g_4bfc = 1;
    if (g_4bfa == 0) {
      fn_0845_114d(0);
    }
  }
  return;
}


//// fn_130a_07be @ 230a:07be

undefined2 __cdecl16far fn_130a_07be(char *param_1)

{
  bool bVar1;
  char *pcVar2;
  char *pcVar3;
  undefined2 uVar4;
  int iVar5;
  int *piVar6;
  
  do {
    do {
      do {
        pcVar3 = param_1;
        if (*param_1 == '\0') {
          return 0;
        }
        pcVar2 = (char *)param_1;
        param_1 = (char *)CONCAT22(param_1._2_2_,(char *)param_1 + 1);
      } while (*pcVar3 != '%');
      iVar5 = 5;
      piVar6 = (int *)0xa68;
      do {
        if (*piVar6 == (int)*param_1) {
                    /* WARNING: Could not recover jumptable at 0x000238ab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar4 = (*(code *)piVar6[5])();
          return uVar4;
        }
        piVar6 = piVar6 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      bVar1 = false;
      if (*param_1 == '\0') {
        bVar1 = true;
      }
      else if (*param_1 == '0') {
        param_1 = (char *)CONCAT22(param_1._2_2_,pcVar2 + 2);
      }
      else {
        while ((*param_1 != '\0' && ((*(byte *)(*param_1 + 0x3ae5) & 2) != 0))) {
          param_1 = (char *)CONCAT22(param_1._2_2_,(char *)param_1 + 1);
        }
      }
    } while (bVar1);
    iVar5 = 8;
    piVar6 = (int *)((char *)s_guardian_wsa_3e2d_0a13 + 5);
    do {
      if (*piVar6 == (int)*param_1) {
                    /* WARNING: Could not recover jumptable at 0x00023943. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar4 = (*(code *)piVar6[8])();
        return uVar4;
      }
      piVar6 = piVar6 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  } while( true );
}


//// fn_130a_0a7c @ 230a:0a7c

void __cdecl16far
fn_130a_0a7c(int param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4,
             undefined2 param_5)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 extraout_DX;
  undefined2 uVar3;
  undefined2 unaff_SS;
  undefined1 *puVar4;
  int local_750 [20];
  undefined1 local_728 [30];
  undefined1 local_70a [768];
  undefined1 local_40a [1024];
  undefined4 local_a;
  undefined2 local_6;
  int local_4;
  
  SCOPY@((char *)s_FINALE_EXE_3e2d_2803 + 0xb,0x3e2d,local_728,unaff_SS);
  uVar3 = extraout_DX;
  fn_1ebc_00e7();
  if (param_1 == 3) {
    if ((g_7fd6 & 2) == 0) {
      fn_14b3_01fa();
      g_3713 = 0xc0;
      memcpy(local_70a);
      fn_1ef2_002f(local_70a);
      fn_0bbc_070e(0x1000b);
      g_20f4 = 0;
      g_20f6 = 0;
      goto LAB_230a_0b1b;
    }
    fn_14b3_01fa();
  }
  else {
    fn_14b3_0122();
  }
  g_3713 = 0xfe;
LAB_230a_0b1b:
  fn_1ebc_00fe();
  local_6 = fn_1e74_000f();
  uVar1 = fn_1f2d_0002(g_7fb8);
  local_a = CONCAT22(uVar3,uVar1);
  setmem(0x2f2d,local_750);
  local_4 = fn_130a_07be(param_2,param_3,param_4,param_5,local_728);
  if (local_4 == 0) {
    g_2170 = strlen(param_2);
    puVar4 = param_2;
  }
  else {
    vsprintf();
    g_2170 = strlen(local_40a);
    puVar4 = (undefined1 *)CONCAT22(unaff_SS,local_40a);
  }
  fn_14b3_0284(puVar4);
  iVar2 = 0;
  do {
    if (local_750[iVar2] == 0) break;
    ((undefined1 *)param_2)[local_750[iVar2 + 1]] = (char)local_750[iVar2];
    iVar2 = iVar2 + 2;
  } while (iVar2 < 10);
  fn_14b3_0122();
  fn_1e74_000f();
  fn_1f2d_0002(local_a);
  g_20f6 = 0;
  return;
}


//// fn_130a_0c28 @ 230a:0c28

void __cdecl16far fn_130a_0c28(int param_1,undefined1 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_a;
  undefined4 local_6;
  
  param_1 = param_1 * 0xb5;
  puVar1 = (undefined4 *)((int)(undefined4 *)&g_4ee0 + param_1);
  local_a = (undefined4 *)CONCAT22(0x3e2d,puVar1);
  *(undefined1 *)(param_1 + 0x4eef) = param_2;
  local_6 = (undefined1 *)
            CONCAT22(0x3e2d,(undefined1 *)((int)puVar1 + *(char *)(param_1 + 0x4eef) * 0x10 + 0x15))
  ;
  ((undefined1 *)&g_4eec)[param_1] = 1;
  *(long *)((int)(undefined4 *)&g_4ee8 + param_1) =
       g_384c + (int)*(char *)(param_1 + 0x4eee);
  ((undefined1 *)&g_4ef0)[param_1] = *local_6;
  *(undefined1 *)(param_1 + 0x4ef1) = 0;
  iVar2 = ovr_2cef_0025((int)*puVar1,(int)((ulong)*puVar1 >> 0x10));
  iVar2 = ovr_2cef_0020((int)*local_a,(int)((ulong)*local_a >> 0x10),
                        *(int *)((int)(undefined2 *)&g_4ee6 + param_1) + iVar2);
  fn_1ebc_0111(*(undefined2 *)((int)(undefined2 *)&g_4ee4 + param_1),
                *(undefined2 *)((int)(undefined2 *)&g_4ee6 + param_1),
                *(int *)((int)(undefined2 *)&g_4ee4 + param_1) + iVar2);
  ovr_2dfd_002a((char *)s_PageArraySize_is_negative__3e2d_2eba + 2,*local_a,
                (char)((undefined1 *)&g_4ef0)[param_1] + -1,
                *(undefined2 *)((int)(undefined2 *)&g_4ee4 + param_1),
                *(undefined2 *)((int)(undefined2 *)&g_4ee6 + param_1),0,0);
  fn_1ebc_01ec();
  return;
}


//// fn_130a_0cf6 @ 230a:0cf6

void __cdecl16far fn_130a_0cf6(int param_1)

{
  ((undefined1 *)&g_4eec)[param_1 * 0xb5] = 0;
  *(undefined1 *)(param_1 * 0xb5 + 0x4eed) = 0;
  if (param_1 == 5) {
    g_5269._2_2_ = 0;
    g_5269._0_2_ = 0;
  }
  return;
}


//// fn_130a_0d2b @ 230a:0d2b

int __cdecl16far fn_130a_0d2b(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar2 = 0;
    do {
      if ((((undefined2 *)&g_7fe6)[iVar2] != 0) &&
         (*(int *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 9 + ((undefined2 *)&g_7fe6)[iVar2] * 0x10
                  ) == param_3)) {
        return 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x30);
  }
  iVar2 = param_2;
  if (param_2 == -1) {
    param_2 = 0;
    iVar2 = 4;
  }
  do {
    if (iVar2 <= param_2) {
      return -1;
    }
    if ((*(uint *)((int)(undefined4 *)&g_362a + param_2 * 0x82 + 3) & 1) != 0) {
      iVar1 = 0;
      do {
        if ((*(int *)(param_2 * 0x82 + iVar1 * 2 + 0x367d) != 0) &&
           (*(int *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 9 +
                    *(int *)(param_2 * 0x82 + iVar1 * 2 + 0x367d) * 0x10) == param_3)) {
          return param_2;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < 0xb);
    }
    param_2 = param_2 + 1;
  } while( true );
}

