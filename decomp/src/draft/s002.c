//// fn_0638_0008 @ 1638:0008

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * __cdecl16far fn_0638_0008(undefined4 param_1,undefined2 *param_2,ulong param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 *puVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined2 uVar7;
  
  uVar1 = ovr_2de9_0020((int)param_1,(int)((ulong)param_1 >> 0x10));
  fn_1809_0e76(uVar1,0,0,0);
  iVar2 = ovr_2de9_002a(uVar1,0x4f46,0x4d52);
  if (iVar2 + 4U < 0x14) {
    puVar3 = (undefined2 *)0x0;
  }
  else {
    uVar4 = iVar2 + 0x16c;
    if ((param_2 == (undefined2 *)0x0) || (param_3 < uVar4)) {
      puVar3 = (undefined2 *)fn_203b_0007(uVar4,0,0x30);
      param_2 = (undefined2 *)CONCAT22(uVar4,puVar3);
      *param_2 = 0xbabe;
    }
    else {
      *param_2 = 0;
    }
    iVar2 = ovr_2de9_002a(uVar1,0x5641,0x4c54);
    uVar7 = (undefined2)((ulong)param_2 >> 0x10);
    puVar3 = (undefined2 *)param_2;
    puVar3[1] = 0xffff;
    puVar3[2] = 0;
    puVar3[3] = 0xe;
    puVar3[4] = puVar3[3] + 0xf0;
    puVar3[5] = puVar3[4] + 0x78;
    puVar3[6] = puVar3[5] + iVar2;
    g_4bc0 = (int *)CONCAT22(uVar7,(int *)((int)puVar3 + puVar3[5]));
    g_4bc4 = CONCAT22(uVar7,(int)puVar3 + puVar3[6]);
    ovr_2de9_002f(uVar1,0x4c545641,(int *)((int)puVar3 + puVar3[5]),uVar7,iVar2,0);
    iVar2 = ovr_2de9_002a(uVar1,0x4554,0x5458);
    if (iVar2 != 0) {
      ovr_2de9_002f(uVar1,0x54584554,(int)g_4bc4,(int)((ulong)g_4bc4 >> 0x10),iVar2,
                    0);
    }
    g_4bae = (undefined4 *)CONCAT22(uVar7,(undefined4 *)((int)puVar3 + puVar3[3]));
    *g_4bae = 0;
    piVar5 = (int *)g_4bc0;
    iVar2 = *g_4bc0;
    uVar7 = (undefined2)((ulong)g_4bae >> 0x10);
    puVar6 = (undefined4 *)g_4bae;
    *(undefined2 *)((int)puVar6 + 0x16) = g_4bc2;
    *(int **)(puVar6 + 5) = piVar5 + iVar2;
    ovr_2de9_0025(uVar1);
  }
  return puVar3;
}


//// fn_0638_018b @ 1638:018b

void __cdecl16far fn_0638_018b(int *param_1)

{
  if (*param_1 == -0x4542) {
    fn_0845_144e((int *)param_1,param_1._2_2_);
  }
  return;
}


//// fn_0638_01a6 @ 1638:01a6

void __cdecl16far fn_0638_01a6(int *param_1)

{
  int *piVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  piVar1 = (int *)param_1;
  *param_1 = *param_1 + **(int **)param_1 * 2;
  *(undefined4 *)(piVar1 + 2) = *(undefined4 *)(piVar1 + 4);
  *(long *)(piVar1 + 4) =
       *(long *)(piVar1 + 4) + *(int *)((int)*(undefined4 *)param_1 + 2) + g_213c;
  g_213c = 0;
  return;
}


//// fn_0638_01e5 @ 1638:01e5

/* WARNING: Removing unreachable block (ram,0x00016784) */
/* WARNING: Removing unreachable block (ram,0x00016789) */
/* WARNING: Removing unreachable block (ram,0x0001678c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far fn_0638_01e5(long param_1)

{
  long lVar1;
  undefined2 uVar2;
  long *plVar3;
  int local_14;
  undefined2 uStack_12;
  
  if (param_1 == 0) {
    return 0;
  }
  uStack_12 = (undefined2)((ulong)param_1 >> 0x10);
  local_14 = (int)param_1;
  g_4bb8._0_2_ = local_14 + 2;
  g_4bb8._2_2_ = uStack_12;
  g_4bbc._0_2_ = local_14 + 4;
  g_4bbc._2_2_ = uStack_12;
  plVar3 = (long *)(local_14 + *(int *)(local_14 + 6));
  g_4bae = (long *)CONCAT22(uStack_12,plVar3);
  g_4baa = local_14 + *(int *)(local_14 + 8);
  g_4bac = uStack_12;
  g_4bc0 = local_14 + *(int *)(local_14 + 10);
  g_4bc2 = uStack_12;
  g_4bc4 = local_14 + *(int *)(local_14 + 0xc);
  g_4bc6 = uStack_12;
  if (*g_4bae == 0) {
    *g_4bae = plVar3[5];
    lVar1 = g_384c;
    plVar3[2] = g_384c;
    plVar3[1] = lVar1;
  }
  fn_0845_093a();
  g_4bb6 = 0;
  uVar2 = fn_0638_0293();
  return uVar2;
}


//// fn_0638_0285 @ 1638:0285

/* WARNING: Removing unreachable block (ram,0x00016784) */
/* WARNING: Removing unreachable block (ram,0x00016789) */
/* WARNING: Removing unreachable block (ram,0x0001678c) */

undefined2 __cdecl16far fn_0638_0285(void)

{
  undefined2 uVar1;
  
  fn_0845_093a();
  g_4bb6 = 0;
  uVar1 = fn_0638_0293();
  return uVar1;
}


//// fn_0638_0293 @ 1638:0293

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 fn_0638_0293(void)

{
  undefined2 uVar1;
  int iVar2;
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_SS;
  
  iVar2 = g_4bae + g_4bb6 * 0x18;
  *(undefined2 *)(unaff_BP + -6) = g_4bb0;
  *(int *)(unaff_BP + -8) = iVar2;
  if (*g_4bb8 != -1) {
    (*pcRam0004010c)((char *)s__>Lib_error_1_3e2d_162a + 0xe,g_4bbc);
  }
  fn_0845_093a();
  if ((((1 < *g_4bbc) && (*(long *)((int)*(undefined4 *)(unaff_BP + -8) + 0xc) != 0)) &&
      (g_81ff != '\0')) && (iVar2 = fn_154c_0136(), iVar2 != 2)) {
    *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -8) + 0xc) = 0;
    g_5275 = 0;
    g_5276 = 0;
    g_5269 = 0;
    g_4bb4 = g_4bb6;
    fn_057f_07aa();
    g_4bb4 = 0xffff;
  }
  if (*(long *)*(undefined4 *)(unaff_BP + -8) == 0) {
    uVar1 = fn_0638_03f6();
    return uVar1;
  }
  *(undefined2 *)(unaff_BP + -4) = 0;
  if (*(ulong *)((int)*(undefined4 *)(unaff_BP + -8) + 8) <= g_384c) {
    uVar1 = fn_0638_0335();
    return uVar1;
  }
  g_4bb6 = g_4bb6 + 1;
  if (9 < g_4bb6) {
    if (unaff_DI != 1) {
      return g_4bb2;
    }
    uVar1 = fn_0638_0285();
    return uVar1;
  }
  uVar1 = fn_0638_0293();
  return uVar1;
}


//// fn_0638_0335 @ 1638:0335

/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined2 fn_0638_0335(void)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  int iVar3;
  int *piVar4;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  char *pcVar5;
  undefined2 unaff_SS;
  
  pcVar5 = (char *)s__>Lib_error_1_3e2d_162a + 0xe;
  iVar3 = *(int *)(unaff_BP + -4);
  *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) + 1;
  if (0 < iVar3) {
    if (*g_4bb8 != -1) {
      (*pcRam0004010c)((char *)s__>Lib_error_1_3e2d_162a + 0xe,g_4bbc);
    }
    pcVar5 = (char *)s_Lib_error_29_3e2d_1842 + 3;
    fn_0845_093a();
  }
  *(undefined4 *)(unaff_BP + -0x10) = *(undefined4 *)*(undefined4 *)(unaff_BP + -8);
  *(int *)(unaff_BP + -0xc) = (int)*(char *)((int)*(undefined4 *)(unaff_BP + -0x10) + 4);
  puVar1 = (undefined2 *)(*(int *)(unaff_BP + -0xc) * 4 + 0x1dcc);
  uVar2 = (*(code *)*puVar1)(pcVar5,*(int *)(unaff_BP + -0x10) + 6,*(undefined2 *)(unaff_BP + -0xe))
  ;
  *(undefined2 *)(unaff_BP + -2) = uVar2;
  *(undefined2 *)(unaff_BP + -10) = uVar2;
  iVar3 = 4;
  piVar4 = (int *)0x413;
  do {
    if (*piVar4 == *(int *)(unaff_BP + -10)) {
                    /* WARNING: Could not recover jumptable at 0x00016722. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*(code *)piVar4[4])();
      return uVar2;
    }
    piVar4 = piVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  fn_0638_01a6(*(undefined4 *)(unaff_BP + -8));
  if ((*(ulong *)((int)*(undefined4 *)(unaff_BP + -8) + 8) <= g_384c) && (unaff_SI == 1)) {
    uVar2 = fn_0638_0335();
    return uVar2;
  }
  g_4bb6 = g_4bb6 + 1;
  if (g_4bb6 < 10) {
    uVar2 = fn_0638_0293();
    return uVar2;
  }
  if (unaff_DI == 1) {
    uVar2 = fn_0638_0285();
    return uVar2;
  }
  return g_4bb2;
}


//// fn_0638_0343 @ 1638:0343

/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined2 fn_0638_0343(void)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  int iVar3;
  int *in_BX;
  int *piVar4;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  
  if (*in_BX != -1) {
    (*pcRam0004010c)((char *)s__>Lib_error_1_3e2d_162a + 0xe,g_4bbc);
  }
  fn_0845_093a();
  *(undefined4 *)(unaff_BP + -0x10) = *(undefined4 *)*(undefined4 *)(unaff_BP + -8);
  *(int *)(unaff_BP + -0xc) = (int)*(char *)((int)*(undefined4 *)(unaff_BP + -0x10) + 4);
  puVar1 = (undefined2 *)(*(int *)(unaff_BP + -0xc) * 4 + 0x1dcc);
  uVar2 = (*(code *)*puVar1)((char *)s_Lib_error_29_3e2d_1842 + 3,*(int *)(unaff_BP + -0x10) + 6,
                             *(undefined2 *)(unaff_BP + -0xe));
  *(undefined2 *)(unaff_BP + -2) = uVar2;
  *(undefined2 *)(unaff_BP + -10) = uVar2;
  iVar3 = 4;
  piVar4 = (int *)0x413;
  do {
    if (*piVar4 == *(int *)(unaff_BP + -10)) {
                    /* WARNING: Could not recover jumptable at 0x00016722. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*(code *)piVar4[4])();
      return uVar2;
    }
    piVar4 = piVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  fn_0638_01a6(*(undefined4 *)(unaff_BP + -8));
  if ((*(ulong *)((int)*(undefined4 *)(unaff_BP + -8) + 8) <= g_384c) && (unaff_SI == 1)) {
    uVar2 = fn_0638_0335();
    return uVar2;
  }
  g_4bb6 = g_4bb6 + 1;
  if (g_4bb6 < 10) {
    uVar2 = fn_0638_0293();
    return uVar2;
  }
  if (unaff_DI == 1) {
    uVar2 = fn_0638_0285();
    return uVar2;
  }
  return g_4bb2;
}


//// fn_0638_037f @ 1638:037f

void fn_0638_037f(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


//// thunk_FUN_1638_03d4 @ 1638:03a0

undefined2 thunk_FUN_1638_03d4(void)

{
  undefined2 uVar1;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  
  fn_0638_01a6(*(undefined4 *)(unaff_BP + -8));
  if ((*(ulong *)((int)*(undefined4 *)(unaff_BP + -8) + 8) <= g_384c) && (unaff_SI == 1)) {
    uVar1 = fn_0638_0335();
    return uVar1;
  }
  g_4bb6 = g_4bb6 + 1;
  if (g_4bb6 < 10) {
    uVar1 = fn_0638_0293();
    return uVar1;
  }
  if (unaff_DI == 1) {
    uVar1 = fn_0638_0285();
    return uVar1;
  }
  return g_4bb2;
}


//// fn_0638_03a5 @ 1638:03a5

void fn_0638_03a5(void)

{
  byte in_DH;
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_SS;
  
  *(byte *)(unaff_BP + unaff_DI) = *(byte *)(unaff_BP + unaff_DI) | in_DH;
  fn_0638_03d4();
  return;
}


//// fn_0638_03b9 @ 1638:03b9

void fn_0638_03b9(void)

{
  undefined2 in_AX;
  undefined2 *in_BX;
  undefined2 unaff_ES;
  
  *in_BX = in_AX;
  g_4bb4 = 0xffff;
  fn_0638_03d4();
  return;
}


//// fn_0638_03d4 @ 1638:03d4

undefined2 fn_0638_03d4(void)

{
  undefined2 uVar1;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  
  fn_0638_01a6(*(undefined4 *)(unaff_BP + -8));
  if ((*(ulong *)((int)*(undefined4 *)(unaff_BP + -8) + 8) <= g_384c) && (unaff_SI == 1)) {
    uVar1 = fn_0638_0335();
    return uVar1;
  }
  g_4bb6 = g_4bb6 + 1;
  if (g_4bb6 < 10) {
    uVar1 = fn_0638_0293();
    return uVar1;
  }
  if (unaff_DI == 1) {
    uVar1 = fn_0638_0285();
    return uVar1;
  }
  return g_4bb2;
}


//// fn_0638_03f6 @ 1638:03f6

undefined2 __cdecl16far fn_0638_03f6(void)

{
  undefined2 uVar1;
  int unaff_DI;
  
  g_4bb6 = g_4bb6 + 1;
  if (g_4bb6 < 10) {
    uVar1 = fn_0638_0293();
    return uVar1;
  }
  if (unaff_DI == 1) {
    uVar1 = fn_0638_0285();
    return uVar1;
  }
  return g_4bb2;
}


//// fn_067a_0000 @ 167a:0000

void fn_067a_0000(void)

{
  int in_DX;
  int unaff_DI;
  
  in(in_DX + *(int *)(unaff_DI + -0x75));
                    /* WARNING: Subroutine does not return */
  fn_17f8_0003(0,uRam00043032,26000);
}

