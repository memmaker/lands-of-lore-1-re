//// fn_057f_0053 @ 157f:0053

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far fn_057f_0053(void)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  
  while ((g_4bb4 == -1 && (g_4bb2 == 0))) {
    fn_0845_093a();
    g_4bb2 = fn_13e8_06a1();
  }
  iVar1 = 0;
  do {
    uVar3 = (undefined2)((ulong)g_4bae >> 0x10);
    puVar2 = (undefined2 *)((int)g_4bae + iVar1 * 0x18);
    puVar2[1] = 0;
    *puVar2 = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 10);
  return 0xffff;
}


//// fn_057f_0096 @ 157f:0096

undefined2 __cdecl16far fn_057f_0096(char *param_1)

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
      piVar6 = (int *)0x2a2;
      do {
        if (*piVar6 == (int)*param_1) {
                    /* WARNING: Could not recover jumptable at 0x000158d3. Too many branches */
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
    iVar5 = 7;
    piVar6 = (int *)0x256;
    do {
      if (*piVar6 == (int)*param_1) {
                    /* WARNING: Could not recover jumptable at 0x0001596b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar4 = (*(code *)piVar6[7])();
        return uVar4;
      }
      piVar6 = piVar6 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  } while( true );
}


//// fn_057f_034f @ 157f:034f

undefined2 __cdecl16far fn_057f_034f(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  ovr_2d5f_008e();
  memset(g_4baa + iVar1 * 0xc,g_4bac,0xc0000);
  return 1;
}


//// fn_057f_0384 @ 157f:0384

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far fn_057f_0384(int *param_1)

{
  undefined2 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 local_6;
  
  uVar1 = g_4bb0;
  piVar2 = (int *)(g_4bae + *param_1 * 0x18);
  local_6 = (int *)CONCAT22(g_4bb0,piVar2);
  if (*(long *)(piVar2 + 10) == 0) {
    iVar4 = (int)((ulong)g_4bc0 >> 0x10);
    iVar3 = (int)g_4bc0 + *(int *)((int)g_4bc0 + *param_1 * 2) * 2;
    piVar2[0xb] = iVar4;
    piVar2[10] = iVar3;
    piVar2[1] = iVar4;
    *piVar2 = iVar3;
  }
  else {
    *(undefined4 *)local_6 = *(undefined4 *)(piVar2 + 10);
  }
  return 1;
}


//// fn_057f_03f7 @ 157f:03f7

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far fn_057f_03f7(int *param_1)

{
  *(undefined4 *)(g_4bae + *param_1 * 0x18) = 0;
  return 1;
}


//// fn_057f_0426 @ 157f:0426

undefined2 __cdecl16far fn_057f_0426(int *param_1)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined4 *puVar5;
  int iVar6;
  
  puVar1 = (undefined4 *)((int)(undefined4 *)&g_4ee0 + *param_1 * 0xb5);
  puVar5 = (undefined4 *)CONCAT22(0x3e2d,puVar1);
  iVar6 = ((int *)param_1)[1];
  if ((*(uint *)(*param_1 * 0xb5 + 0x4ef2) & 0x4000) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 2;
  }
  iVar3 = ovr_2cef_0025((int)*puVar5,(int)((ulong)*puVar5 >> 0x10),puVar1,0x3e2d,iVar6,uVar2);
  iVar3 = ovr_2cef_0020((int)*puVar5,(int)((ulong)*puVar5 >> 0x10),
                        *(int *)((int)(undefined4 *)puVar5 + 6) + iVar3);
  uVar4 = (undefined2)((ulong)puVar5 >> 0x10);
  puVar1 = (undefined4 *)puVar5;
  fn_1ebc_0111(*(undefined2 *)(puVar1 + 1),*(undefined2 *)((int)puVar1 + 6),
                *(int *)(puVar1 + 1) + iVar3);
  uVar4 = (undefined2)((ulong)puVar5 >> 0x10);
  puVar1 = (undefined4 *)puVar5;
  ovr_2dfd_002a((char *)s_PageArraySize_is_negative__3e2d_2eba + 2,*puVar5,iVar6,
                *(undefined2 *)(puVar1 + 1),*(undefined2 *)((int)puVar1 + 6),uVar2,
                *(uint *)((int)puVar1 + 0x12) & 0xf0ff);
  fn_1ebc_01ec();
  return 1;
}


//// fn_057f_04c9 @ 157f:04c9

undefined2 __cdecl16far fn_057f_04c9(void)

{
  return 1;
}


//// fn_057f_04d1 @ 157f:04d1

undefined2 __cdecl16far fn_057f_04d1(void)

{
  return 1;
}


//// fn_057f_04d9 @ 157f:04d9

undefined2 __cdecl16far fn_057f_04d9(void)

{
  return 1;
}


//// fn_057f_04e1 @ 157f:04e1

undefined2 __cdecl16far fn_057f_04e1(void)

{
  return 1;
}


//// fn_057f_04e9 @ 157f:04e9

undefined2 __cdecl16far fn_057f_04e9(void)

{
  return 1;
}


//// fn_057f_04f1 @ 157f:04f1

undefined2 __cdecl16far fn_057f_04f1(void)

{
  return 1;
}


//// fn_057f_04f9 @ 157f:04f9

undefined2 __cdecl16far fn_057f_04f9(void)

{
  return 1;
}


//// fn_057f_0501 @ 157f:0501

undefined2 __cdecl16far fn_057f_0501(undefined2 *param_1)

{
  fn_178d_0091(*param_1);
  return 1;
}


//// fn_057f_0515 @ 157f:0515

undefined2 __cdecl16far fn_057f_0515(void)

{
  fn_178d_015e();
  return 1;
}


//// fn_057f_0522 @ 157f:0522

undefined2 __cdecl16far fn_057f_0522(void)

{
  return 1;
}


//// fn_057f_052a @ 157f:052a

undefined2 __cdecl16far fn_057f_052a(void)

{
  return 1;
}


//// fn_057f_0532 @ 157f:0532

undefined2 __cdecl16far fn_057f_0532(undefined2 *param_1)

{
  fn_17d6_0006(*param_1);
  return 1;
}


//// fn_057f_0546 @ 157f:0546

undefined2 __cdecl16far fn_057f_0546(void)

{
  fn_17d6_0123();
  return 1;
}


//// fn_057f_0553 @ 157f:0553

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far fn_057f_0553(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((g_81ff != '\0') && (iVar1 = fn_154c_0136(), iVar1 != 2)) {
    fn_057f_07aa(0x15);
    return 1;
  }
  puVar2 = (undefined4 *)(g_4bae + g_4bb6 * 0x18);
  puVar2[3] = *puVar2;
  return 1;
}


//// fn_057f_059b @ 157f:059b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far fn_057f_059b(int *param_1)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  uVar2 = g_4bb0;
  iVar1 = *param_1;
  puVar4 = (undefined4 *)(g_4bae + g_4bb6 * 0x18);
  if ((puVar4[3] != 0) && (*puVar4 = puVar4[3], iVar1 != 0)) {
    iVar3 = fn_154c_0136();
    if (iVar3 != 2) {
      iVar3 = rand(0x254c);
      puVar4[2] = puVar4[2] + (long)(int)(((long)iVar3 * (long)iVar1) / 0x8000);
    }
  }
  return 0xfffe;
}


//// fn_057f_060e @ 157f:060e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far fn_057f_060e(int *param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)g_4bae >> 0x10);
  iVar1 = (int)g_4bae + *param_1 * 0x18;
  *(undefined2 *)(iVar1 + 0xe) = 0;
  *(undefined2 *)(iVar1 + 0xc) = 0;
  return 1;
}


//// fn_057f_0631 @ 157f:0631

void __cdecl16far fn_057f_0631(int *param_1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)(*param_1 * 4 + 0x1e48);
  (*(code *)*puVar1)((undefined2 *)&g_157f,(int *)param_1 + 1,param_1._2_2_);
  return;
}


//// fn_057f_065c @ 157f:065c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far fn_057f_065c(void)

{
  int iVar1;
  long *plVar2;
  
  iVar1 = 0;
  do {
    plVar2 = (long *)(g_4bae + iVar1 * 0x18);
    if (*plVar2 != 0) {
      plVar2[2] = g_384c + 1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 10);
  return 1;
}


//// fn_057f_0699 @ 157f:0699

undefined2 fn_057f_0699(void)

{
  return 1;
}


//// fn_057f_06a1 @ 157f:06a1

undefined2 __cdecl16far fn_057f_06a1(undefined2 *param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  char *pcVar4;
  undefined2 unaff_SS;
  undefined4 uVar5;
  undefined4 local_e;
  undefined4 local_a;
  undefined4 local_6;
  
  pcVar4 = (char *)&g_157f;
  *g_4bbc = *param_1;
  g_4bb2 = 0;
  iVar2 = 0;
  for (iVar1 = 1; iVar1 < 4; iVar1 = iVar1 + 1) {
    uVar3 = (undefined2)((ulong)param_1 >> 0x10);
    if (((undefined2 *)param_1)[iVar1] == -1) {
      *(undefined2 *)(&stack0xfff0 + iVar1 * 4) = 0;
      *(undefined2 *)(&stack0xffee + iVar1 * 4) = 0;
    }
    else {
      uVar5 = fn_0845_06f8(pcVar4,((undefined2 *)param_1)[iVar1]);
      *(int *)(&stack0xfff0 + iVar1 * 4) = (int)((ulong)uVar5 >> 0x10);
      *(int *)(&stack0xffee + iVar1 * 4) = (int)uVar5;
      iVar2 = iVar2 + 1;
      pcVar4 = (char *)s_Lib_error_29_3e2d_1842 + 3;
    }
  }
  fn_13e8_0903(iVar2,local_e,local_a,local_6);
  fn_2169_062e();
  fn_15a7_0964();
  return 0xfffd;
}


//// fn_057f_0730 @ 157f:0730

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl16far fn_057f_0730(void)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  iVar1 = fn_13e8_06a1();
  if ((iVar1 != 0) && (*g_4bbc != 0)) {
    fn_154c_000f(0);
    uVar3 = (undefined2)((ulong)g_4bae >> 0x10);
    iVar2 = (int)g_4bae + *g_4bb8 * 0x18;
    *(undefined2 *)(iVar2 + 0xe) = 0;
    *(undefined2 *)(iVar2 + 0xc) = 0;
    g_4bb4 = *g_4bb8;
    *g_4bb8 = -1;
    g_5275 = 0;
    g_5276 = 0;
    g_5269 = 0;
    g_4bb2 = iVar1;
    if (*g_4bbc != 0) {
      fn_057f_07aa(0x15);
    }
  }
  return iVar1;
}


//// fn_057f_07aa @ 157f:07aa

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far fn_057f_07aa(char param_1)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 local_6;
  
  uVar2 = g_4bb0;
  piVar4 = (int *)(g_4bae + g_4bb4 * 0x18);
  local_6 = (int *)CONCAT22(g_4bb0,piVar4);
  iVar3 = **(int **)piVar4;
  do {
    if (*(char *)((int)*(undefined4 *)local_6 + 4) == param_1) {
LAB_157f_0806:
      *(undefined4 *)(piVar4 + 4) = g_384c;
      return;
    }
    piVar1 = *(int **)local_6;
    if ((char)((int *)piVar1)[2] == '\x01') {
      *piVar1 = iVar3;
      goto LAB_157f_0806;
    }
    iVar3 = **(int **)local_6;
    *local_6 = *local_6 + **(int **)local_6 * 2;
  } while( true );
}


//// fn_057f_0814 @ 157f:0814

void __cdecl16far fn_057f_0814(void)

{
  return;
}


//// fn_057f_081f @ 157f:081f

undefined2 __cdecl16far fn_057f_081f(undefined2 *param_1)

{
  ovr_2d5f_00fc(*param_1);
  return 1;
}


//// fn_057f_0833 @ 157f:0833

undefined2 __cdecl16far fn_057f_0833(undefined2 *param_1)

{
  ovr_2d5f_0101(*param_1);
  return 1;
}


//// fn_057f_0847 @ 157f:0847

undefined2 __cdecl16far fn_057f_0847(void)

{
  return 1;
}


//// fn_057f_084f @ 157f:084f

bool __cdecl16far fn_057f_084f(undefined2 *param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  uVar2 = fn_07bc_012d((undefined2 *)&g_157f,*param_1,((undefined2 *)param_1)[1],
                        ((undefined2 *)param_1)[2]);
  iVar1 = fn_0c59_03a8(uVar2);
  if (iVar1 == 0) {
    fn_07bc_044c(uVar2);
  }
  return iVar1 != 0;
}


//// fn_057f_0887 @ 157f:0887

undefined2 __cdecl16far fn_057f_0887(int *param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  if (*param_1 == 0) {
    g_7fd0 = ((int *)param_1)[1];
    fn_1aff_030e((undefined2 *)&g_7fd2,0x3e2d,(undefined2 *)&g_7fd4,0x3e2d,
                  g_7fd0,0x800080);
  }
  else if (*param_1 == 1) {
    g_7fdf = ((int *)param_1)[1];
  }
  return 1;
}


//// fn_057f_08cd @ 157f:08cd

char * __cdecl16far
fn_057f_08cd(code *param_1,undefined4 *param_2,int param_3,code *param_4,uint param_5,code *param_6
             ,undefined2 param_7,code *param_8,long param_9,code *param_10,int param_11)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  long lVar4;
  uint uVar5;
  uint uVar6;
  code *pcVar7;
  byte bVar8;
  int in_AX;
  char *pcVar9;
  uint uVar10;
  undefined2 uVar11;
  char *pcVar12;
  ulong uVar13;
  int iVar14;
  byte bVar15;
  byte bVar17;
  int iVar16;
  code *in_EDX;
  undefined2 *puVar18;
  char *unaff_SI;
  uint uVar19;
  int *piVar20;
  uint unaff_DI;
  code *pcVar21;
  code *pcVar22;
  code *pcVar23;
  code *pcVar24;
  undefined2 uVar25;
  undefined1 uVar26;
  bool bVar27;
  code *in_stack_00000002;
  undefined1 auStack_304 [744];
  undefined2 uStack_1c;
  code *pcStack_1a;
  code *pcStack_18;
  code *pcStack_16;
  code *pcStack_14;
  code *pcStack_12;
  uint uStack_10;
  uint uStack_e;
  code *pcStack_c;
  code *pcStack_a;
  char *in_stack_0000fff8;
  undefined4 *puVar28;
  code *in_stack_0000fffa;
  uint uVar29;
  char cStack_4;
  char cStack_3;
  
  uVar13 = CONCAT22(param_6,param_5);
  pcVar21 = (code *)((ulong)param_1 >> 0x10);
  uVar10 = *(uint *)param_1;
  if (5 < uVar10) {
    return (char *)0x1;
  }
  uVar26 = (int)uVar10 < 0;
  puVar18 = (undefined2 *)(uVar10 * 2);
  pcVar23 = (code *)s_Process_Mist_FX__Can_t_load__Mis_3e2d_1000;
  bVar8 = (byte)in_AX;
  pcVar24 = (code *)in_EDX;
  puVar28 = (undefined4 *)param_2;
  uVar29 = (uint)((ulong)param_2 >> 0x10);
  switch(uVar10) {
  case 0:
    do {
      iVar2 = param_3 + -1;
      if (param_3 < 1) goto LAB_1000_1140;
      cStack_3 = (char)((ulong)param_2 >> 8);
      in_stack_0000fff8 = (char *)0x10f4;
      pcVar9 = (char *)(*in_stack_00000002)();
      fn_0000_0fb3();
      if ((bool)uVar26) goto fn_0000_1130;
      lVar4 = ZEXT24(unaff_SI) * ((ulong)param_2 >> 0x10);
      uVar5 = (uint)((ulong)lVar4 >> 0x10);
      uVar10 = (uint)lVar4;
      unaff_SI = pcVar9 + uVar10;
      uVar10 = (uint)CARRY2((uint)pcVar9,uVar10);
      uVar19 = unaff_DI + uVar5;
      uVar26 = CARRY2(unaff_DI,uVar5) || CARRY2(uVar19,uVar10);
      uVar19 = uVar19 + uVar10;
      unaff_DI = 0;
      param_3 = iVar2;
      in_stack_0000fffa = pcVar21;
    } while (uVar19 == 0);
    do {
      if (param_3 < 1) goto LAB_1000_1140;
      in_stack_0000fff8 = (char *)s_ONETIME_INF_3e2d_1119 + 0xb;
      pcVar9 = (char *)(*in_stack_00000002)();
      uVar10 = uVar29;
      fn_0000_0fb3();
      if ((bool)uVar26) goto fn_0000_1130;
      uVar6 = (uint)(ZEXT24(unaff_SI) * (ulong)uVar10 >> 0x10);
      uVar5 = (uint)(ZEXT24(unaff_SI) * (ulong)uVar10);
      lVar4 = (ulong)uVar19 * (ulong)uVar10;
      unaff_SI = pcVar9 + uVar5;
      uVar10 = (uint)CARRY2((uint)pcVar9,uVar5);
      uVar19 = (uint)lVar4 + uVar6;
      bVar27 = CARRY2((uint)lVar4,uVar6) || CARRY2(uVar19,uVar10);
      uVar19 = uVar19 + uVar10;
      bVar15 = (byte)((ulong)lVar4 >> 0x10);
      bVar17 = (byte)((ulong)lVar4 >> 0x18);
      bVar8 = bVar15 + bVar17;
      uVar26 = CARRY1(bVar15,bVar17) || CARRY1(bVar8,bVar27);
      param_3 = param_3 + -1;
    } while ((byte)(bVar8 + bVar27) == '\0');
    unaff_SI = (char *)CONCAT11((cStack_3 != '\0') + -1,cStack_3 + -1);
    in_stack_0000fff8 = (char *)0x2;
    goto LAB_1000_1150;
  case 1:
    iVar2 = CONCAT11(bVar8 / 0x23,bVar8 % 0x23);
    bVar27 = iVar2 == 0;
    do {
      if (bVar27) {
        return (char *)0x2;
      }
      if (unaff_SI == (char *)0x0) {
        return (char *)0xffff;
      }
      iVar16 = *(int *)0x0;
      piVar1 = (int *)((char *)s_Borland_C_____Copyright_1991_Bor_3e2d_0004 + 2);
      piVar20 = (int *)((char *)s_Borland_C_____Copyright_1991_Bor_3e2d_0004 + 6);
      iVar14 = 3;
      bVar27 = false;
      pcVar9 = unaff_SI;
LAB_1000_2b80:
      do {
        if (iVar14 != 0) {
          iVar14 = iVar14 + -1;
          piVar3 = piVar20;
          piVar20 = piVar20 + 1;
          bVar27 = iVar2 == *piVar3;
          if (bVar27) goto LAB_1000_2b80;
        }
        if (!bVar27) {
          return (char *)0xfffd;
        }
        piVar20 = (int *)0x0;
        iVar14 = 8;
        unaff_SI = unaff_SI + 1;
        iVar16 = iVar16 + -1;
        bVar27 = iVar16 == 0;
        pcVar9 = unaff_SI;
      } while (!bVar27);
      bVar27 = (char *)*piVar1 == f_0000_23d4;
      unaff_SI = (char *)*piVar1;
    } while( true );
  case 2:
    puVar18[1] = in_AX;
    *puVar18 = pcVar24;
    pcVar9 = (char *)fn_0f28_091b();
    return pcVar9;
  case 3:
    *(char *)(unaff_DI + 5) = *(char *)(unaff_DI + 5) + (char)((uint)puVar18 >> 8);
    if ((int)param_5 < 0) {
      unaff_DI = 0;
    }
    pcVar12 = (char *)(ulong)((int)pcVar24 <= (int)uVar29);
    pcStack_a = (code *)(uint)((int)pcVar24 <= (int)uVar29);
LAB_1845_0efe:
    do {
      pcVar9 = (char *)pcVar12;
      if (CONCAT11(cStack_3,cStack_4) == 1) {
        if ((param_11 != 0) &&
           ((param_1 != (code *)0x0 || ((code *)CONCAT22(param_7,param_6) != (code *)0x0)))) {
          pcStack_c = (code *)0x9378;
          pcStack_a = pcVar23;
          pcStack_a = (code *)fn_215f_001d();
          uStack_e = (uint)uRam0004302a;
          pcStack_c = (code *)((ulong)uRam0004302a >> 0x10);
          uStack_10 = 0x315f;
          pcStack_12 = (code *)0x9385;
          fn_2279_025b();
          pcStack_a = (code *)0x0;
          pcStack_c = (code *)0x3279;
          uStack_e = 0x939b;
          fn_1ebc_0111();
          pcStack_a = pcStack_14;
          uStack_e = 0;
          pcStack_12 = (code *)0x0;
          pcStack_14 = (code *)((char *)s_PageArraySize_is_negative__3e2d_2eba + 2);
          pcStack_16 = (code *)0x93b6;
          uStack_10 = unaff_DI;
          pcStack_c = (code *)unaff_DI;
          fn_1dbc_0004();
          pcVar9 = (char *)fn_1ebc_01ec();
        }
        return pcVar9;
      }
      pcVar12 = (char *)(long)param_3;
      g_3850 = pcVar12;
      if ((param_1 != (code *)0x0) || ((code *)CONCAT22(param_7,param_6) != (code *)0x0)) {
        pcVar24 = (code *)0xfa00;
        cStack_4 = '\0';
        cStack_3 = '\0';
        pcStack_c = (code *)0x923f;
        pcStack_a = pcVar23;
        pcStack_a = (code *)fn_215f_001d();
        uStack_e = (uint)uRam0004302a;
        pcStack_c = (code *)((ulong)uRam0004302a >> 0x10);
        uStack_10 = 0x315f;
        pcVar23 = (code *)0x3279;
        pcStack_12 = (code *)0x924c;
        uVar10 = fn_2279_025b();
        pcVar12 = (char *)(ulong)uVar10;
      }
      if ((code *)CONCAT22(param_7,param_6) != (code *)0x0) {
        cStack_4 = (char)param_5;
        cStack_3 = (char)(param_5 >> 8);
        uStack_e = 0x9263;
        pcStack_c = pcVar23;
        pcStack_a = (code *)param_1;
        uVar10 = (*param_6)();
        pcVar12 = (char *)(ulong)uVar10;
        pcVar24 = param_4;
      }
      if (param_1 == (code *)0x0) {
        pcVar22 = pcVar23;
        pcStack_c = pcVar23;
        if ((code *)CONCAT22(param_7,param_6) != (code *)0x0) goto LAB_1845_0e5a;
      }
      else {
        pcStack_a = (code *)g_4bec;
        uStack_e = 2;
        pcStack_c = (code *)0x5000;
        uStack_10 = param_5;
        pcStack_12 = param_4;
        pcStack_14 = (code *)(code *)((g_4bf0 & 0xffff) %
                                     (ulong)*(uint *)((code *)param_1 + 2));
        pcStack_18 = (code *)param_1;
        uStack_1c = 0x9299;
        pcStack_1a = pcVar23;
        pcStack_16 = pcVar21;
        ovr_2dfd_002a();
        pcStack_c = (code *)0x3dfd;
LAB_1845_0e5a:
        pcStack_a = (code *)0x0;
        uStack_e = 0x92bd;
        fn_1ebc_0111();
        pcStack_a = pcStack_14;
        uStack_e = 0;
        pcStack_12 = (code *)0x0;
        pcStack_14 = (code *)((char *)s_PageArraySize_is_negative__3e2d_2eba + 2);
        pcStack_16 = (code *)0x92d2;
        uStack_10 = unaff_DI;
        pcStack_c = (code *)unaff_DI;
        fn_1dbc_0004();
        cStack_4 = -0x44;
        cStack_3 = '-';
        pcVar24 = (code *)0x92da;
        uVar10 = fn_1ebc_01ec();
        pcVar12 = (char *)(ulong)uVar10;
        pcVar22 = (code *)((char *)s_PageArraySize_is_negative__3e2d_2eba + 2);
      }
      do {
        pcVar7 = param_10;
        pcVar23 = pcVar22;
        if ((param_8 != (code *)0x0) && (param_9 != 0)) {
          cStack_4 = (char)((int)param_10 >> 0xf);
          pcStack_a = (code *)(code *)(g_384c - (ulong)uStack_e);
          uStack_e = (uint)param_9;
          pcStack_c = (code *)((ulong)param_9 >> 0x10);
          pcStack_12 = (code *)param_8;
          uStack_10 = (uint)((ulong)param_8 >> 0x10);
          pcVar23 = (code *)0x3d1b;
          pcStack_16 = (code *)0x9306;
          pcStack_14 = pcVar22;
          uVar10 = ovr_2d1b_003e();
          pcVar12 = (char *)(ulong)uVar10;
          pcVar24 = pcVar7;
          cStack_3 = cStack_4;
          if ((uVar10 == 0) && (param_1 == (code *)0x0)) {
            return (char *)0x0;
          }
        }
        pcVar22 = pcVar23;
      } while (g_3850 != (char *)0x0);
    } while (param_1 == (code *)0x0);
    if (pcStack_a == (code *)((int)(undefined2 *)&g_0000 + 1)) {
      pcVar24 = pcVar24 + 1;
      pcVar12 = (char *)ZEXT24(pcVar24);
      if ((int)pcVar24 < (int)uVar29) goto LAB_1845_0efe;
    }
    else {
      pcVar24 = pcVar24 + -1;
      pcVar12 = (char *)ZEXT24(pcVar24);
      if ((int)uVar29 <= (int)pcVar24) goto LAB_1845_0efe;
    }
    cStack_4 = '\x01';
    cStack_3 = '\0';
    goto LAB_1845_0efe;
  case 5:
    *(char *)((int)puVar18 + (int)unaff_SI) = *(char *)((int)puVar18 + (int)unaff_SI) + bVar8;
    pcStack_c = (code *)g_adea;
    pcStack_a = (code *)((ulong)g_adea >> 0x10);
    uStack_e = 0x1000;
    uStack_10 = 0x884b;
    fn_2279_025b();
    pcStack_a = (code *)0x3279;
    pcStack_c = (code *)0x885e;
    setmem();
    fn_0845_1430();
    pcStack_a = (code *)auStack_304;
    pcStack_c = (code *)0x1000;
    uStack_e = 0x8880;
    fn_1ef2_0075();
    fn_1ebc_00e7();
    fn_1e74_000f();
    pcStack_a = (code *)0x70;
    pcStack_c = (code *)0x2e74;
    uStack_e = 0x88a3;
    fn_1e59_001d();
    fn_1e74_000f();
    pcVar9 = (char *)fn_1ebc_00fe();
    g_20d5 = 1;
    return pcVar9;
  }
  if (in_AX != 0) {
    if (CONCAT22(param_6,param_5) == 0) {
      pcStack_c = (code *)0x1000;
      pcVar24 = (code *)0x303b;
      uStack_e = 0xf43b;
      uVar25 = fn_203b_0007();
      uVar13 = CONCAT22(param_6,param_5);
      *(undefined2 *)((int)puVar28 + 2) = (code *)in_EDX;
      *(undefined2 *)param_2 = uVar25;
    }
    else {
      *param_2 = CONCAT22(param_6,param_5);
      uVar13 = CONCAT22(param_6,param_5) + (long)in_AX;
      in_EDX = (code *)(uVar13 >> 0x10);
      pcVar24 = pcVar23;
    }
    pcStack_c = (code *)*param_2;
    pcStack_a = (code *)((ulong)*param_2 >> 0x10);
    uStack_10 = 0x4554;
    uStack_e = 0x5458;
    pcVar23 = (code *)0x3de9;
    pcStack_16 = (code *)ovr_2cef_0025;
    pcStack_14 = pcVar24;
    pcStack_12 = pcVar21;
    ovr_2de9_002f();
  }
  pcVar24 = (code *)0x3de9;
  uStack_e = 0xf474;
  pcStack_c = pcVar23;
  pcStack_a = pcVar21;
  uVar10 = ovr_2de9_002a();
  if (uVar10 != 0) {
    if (uVar13 == 0) {
      pcStack_c = (code *)0x3de9;
      pcVar24 = (code *)0x303b;
      uStack_e = 0xf4be;
      pcStack_a = (code *)uVar10;
      uVar25 = fn_203b_0007();
      *(undefined2 *)((int)puVar28 + 10) = (code *)in_EDX;
      *(undefined2 *)(puVar28 + 2) = uVar25;
      uVar13 = 0;
    }
    else {
      puVar28[2] = uVar13;
      uVar13 = uVar13 + (long)(int)uVar10;
      in_EDX = (code *)(uVar13 >> 0x10);
    }
    pcStack_c = (code *)puVar28[2];
    pcStack_a = (code *)((ulong)puVar28[2] >> 0x10);
    uStack_10 = 0x524f;
    uStack_e = 0x5244;
    uVar25 = 0x3de9;
    pcStack_16 = (code *)0xf4e8;
    pcStack_14 = pcVar24;
    pcStack_12 = pcVar21;
    ovr_2de9_002f();
    uVar19 = uVar10 >> 1;
    while( true ) {
      pcVar23 = (code *)in_EDX;
      uVar19 = uVar19 - 1;
      if ((int)uVar19 < 0) break;
      uVar25 = 0x3315;
      pcStack_a = (code *)0xf505;
      uVar11 = fn_2315_0018();
      in_EDX = (code *)(ulong)(uVar19 * 2);
      *(undefined2 *)((int)puVar28[2] + uVar19 * 2) = uVar11;
    }
    pcVar24 = (code *)0x3de9;
    uStack_e = 0xf529;
    pcStack_c = (code *)uVar25;
    pcStack_a = pcVar21;
    uVar19 = ovr_2de9_002a();
    pcVar9 = (char *)(unaff_DI + in_AX + uVar10 + uVar19);
    if (uVar19 != 0) {
      if (uVar13 == 0) {
        pcStack_c = (code *)0x3de9;
        pcVar24 = (code *)0x303b;
        uStack_e = 0xf556;
        pcStack_a = (code *)uVar19;
        uVar25 = fn_203b_0007();
        *(undefined2 *)((int)puVar28 + 6) = pcVar23;
        *(undefined2 *)(puVar28 + 1) = uVar25;
      }
      else {
        puVar28[1] = uVar13;
      }
      pcStack_c = (code *)puVar28[1];
      pcStack_a = (code *)((ulong)puVar28[1] >> 0x10);
      uStack_10 = 0x4144;
      uStack_e = 0x4154;
      pcStack_16 = (code *)0xf580;
      pcStack_14 = pcVar24;
      pcStack_12 = pcVar21;
      ovr_2de9_002f();
      *(uint *)(puVar28 + 3) = uVar19 >> 1;
      goto LAB_1f28_031d;
    }
  }
  pcStack_a = (code *)0x3de9;
  pcStack_c = (code *)0xf598;
  fn_0f28_0009();
  pcVar9 = (char *)0x0;
LAB_1f28_031d:
  pcStack_a = (code *)0xf5a5;
  ovr_2de9_0025();
  return pcVar9;
fn_0000_1130:
  pcStack_a = (code *)0x113a;
  (*(code *)param_1)();
  in_stack_0000fff8 = pcVar9;
  in_stack_0000fffa = pcVar21 + -1;
LAB_1000_1140:
  pcVar21 = in_stack_0000fffa;
  if (cStack_3 != '\0') {
    unaff_SI = (char *)-(int)unaff_SI;
  }
LAB_1000_1150:
  *(code **)CONCAT22(param_5,param_4) = pcVar21 + *(int *)CONCAT22(param_5,param_4);
  *(char **)CONCAT22(param_7,param_6) = in_stack_0000fff8;
  return unaff_SI;
}


//// fn_057f_09d6 @ 157f:09d6

undefined2 __cdecl16far fn_057f_09d6(undefined2 *param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  uVar2 = fn_0845_06f8((undefined2 *)&g_157f,((undefined2 *)param_1)[2],0,param_1,3);
  fn_130a_03cd(*param_1,((undefined2 *)param_1)[1],1,uVar2);
  return 1;
}


//// fn_057f_0a0a @ 157f:0a0a

undefined2 __cdecl16far fn_057f_0a0a(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  fn_0845_15d9(iVar1);
  if ((iRam00043040 != 2) && (iVar1 == 2)) {
    fn_1dbc_0017((char *)s_Lib_error_29_3e2d_1842 + 3,0x70,0x70,0x7800b0,iRam00043040,2);
  }
  return 1;
}


//// fn_057f_0a47 @ 157f:0a47

undefined2 __cdecl16far fn_057f_0a47(void)

{
  fn_0845_093a();
  return 1;
}


//// fn_057f_0a54 @ 157f:0a54

undefined2 __cdecl16far fn_057f_0a54(void)

{
  if ((f_2803_0045 == '\0') || (g_81fd._1_1_ != '\0')) {
    fn_14b3_0122(5);
    fn_1ebc_00e7();
    fn_1e59_001d(g_ad8d,g_ad8b,g_ad8d + g_ad8f + -2,
                  g_ad8b + g_ad91 + -2,g_3711);
    fn_14b3_01fa(4);
    fn_1ebc_00fe();
    g_1f87 = 0;
    g_1f89 = 0;
  }
  return 1;
}


//// fn_057f_0ac1 @ 157f:0ac1

undefined2 __cdecl16far fn_057f_0ac1(undefined2 *param_1)

{
  fn_067a_003e((undefined2 *)&g_157f,*param_1);
  return 1;
}


//// fn_057f_0ad5 @ 157f:0ad5

undefined2 __cdecl16far fn_057f_0ad5(undefined2 *param_1)

{
  fn_067a_01d1(*param_1);
  return 1;
}


//// fn_057f_0ae9 @ 157f:0ae9

undefined2 __cdecl16far fn_057f_0ae9(undefined2 *param_1)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  
  lVar1 = g_384c;
  iVar2 = fn_154c_01d3(*param_1,0,0);
  if ((iVar2 == 0) || (g_81fd._1_1_ != '\0')) {
    uVar3 = fn_0845_06f8(0x254c,*param_1,0,(undefined2 *)param_1,(int)((ulong)param_1 >> 0x10),1);
    fn_130a_0a7c(4,uVar3);
  }
  g_213c = g_384c - lVar1;
  return 1;
}


//// fn_057f_0b4a @ 157f:0b4a

undefined2 __cdecl16far fn_057f_0b4a(undefined2 *param_1)

{
  fn_067a_0401(*param_1,0);
  return 1;
}


//// fn_057f_0b62 @ 157f:0b62

undefined2 __cdecl16far fn_057f_0b62(undefined2 *param_1)

{
  fn_130a_0c28(*param_1,((undefined2 *)param_1)[1]);
  return 1;
}


//// fn_057f_0b7c @ 157f:0b7c

undefined2 __cdecl16far fn_057f_0b7c(undefined2 *param_1)

{
  fn_130a_0cf6(*param_1);
  return 1;
}


//// fn_057f_0b90 @ 157f:0b90

undefined2 __cdecl16far fn_057f_0b90(void)

{
  return 1;
}

