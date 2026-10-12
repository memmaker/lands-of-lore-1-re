//// fn_067a_0005 @ 167a:0005

void fn_067a_0005(void)

{
  undefined2 in_DX;
  
  in(in_DX);
                    /* WARNING: Subroutine does not return */
  fn_17f8_0003(0,uRam00043032,26000);
}


//// fn_067a_001e @ 167a:001e

void __cdecl16far fn_067a_001e(void)

{
  char in_AL;
  int in_BX;
  int unaff_SI;
  undefined2 in_GS;
  
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + in_AL;
  fn_17c5_0004(0,uRam00043032);
  g_1e90 = 0xff;
  uRam00040161 = 0xff;
  return;
}


//// fn_067a_003e @ 167a:003e

void fn_067a_003e(undefined2 param_1,int param_2)

{
  undefined1 local_16 [20];
  
  if ((g_7fda & 2) == 0) {
    if (g_1e90 == -2) {
      fn_067a_01ce();
      return;
    }
                    /* WARNING: Subroutine does not return */
    fn_17f8_0003(0,0,0);
  }
  if ((*(char *)((param_2 + -0xfa) * 3) == g_1e90) &&
     (*(char *)((param_2 + -0xfa) * 3 + 1) == cRam00040161)) {
    fn_067a_01c9();
    return;
  }
  fn_067a_023d();
  sprintf(local_16);
                    /* WARNING: Subroutine does not return */
  fn_17f8_0003(0,0,0);
}


//// fn_067a_0098 @ 167a:0098

void fn_067a_0098(void)

{
  int unaff_SI;
  
  uRam00040161 = *(undefined1 *)(unaff_SI * 3 + 1);
  fn_067a_01ce();
  return;
}


//// fn_067a_0180 @ 167a:0180

void fn_067a_0180(void)

{
  long in_EAX;
  long in_EDX;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + (char)in_EAX;
  if (1 < in_EDX - in_EAX) {
    fn_2037_0002(uRam00043032);
    fn_17c5_0004(unaff_BP + -0x14);
  }
  g_1e90 = *(undefined1 *)(unaff_SI * 3);
  fn_067a_0098();
  return;
}


//// fn_067a_0185 @ 167a:0185

void fn_067a_0185(void)

{
  long in_EDX;
  int unaff_BP;
  int unaff_SI;
  
  if (1 < in_EDX) {
    fn_2037_0002(uRam00043032);
    fn_17c5_0004(unaff_BP + -0x14);
  }
  g_1e90 = *(undefined1 *)(unaff_SI * 3);
  fn_067a_0098();
  return;
}


//// fn_067a_01c9 @ 167a:01c9

void fn_067a_01c9(void)

{
  fn_067a_023d();
  return;
}


//// fn_067a_01ce @ 167a:01ce

void __cdecl16far fn_067a_01ce(void)

{
  return;
}


//// fn_067a_01d1 @ 167a:01d1

int __cdecl16far fn_067a_01d1(int param_1)

{
  int iVar1;
  
  iVar1 = iRam00040164;
  if ((param_1 != -1) && (iRam00040164 = param_1, (g_7fda & 2) != 0)) {
    fn_067a_003e((char *)s_Lib_error_6___s__3e2d_1676 + 4,param_1);
    fn_178d_015e();
    uRam00040162 = 1;
    fn_178d_0091((int)*(char *)((param_1 + -0xfa) * 3 + 2));
    fn_2db9_0048(0x278d,(g_8201 * 0x91) / 100 + 0x6e);
  }
  return iVar1;
}


//// fn_067a_0200 @ 167a:0200

/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void __cdecl16far fn_067a_0200(void)

{
  int in_BX;
  int unaff_SI;
  undefined2 unaff_SS;
  
  uRam00040162 = 1;
  *(int *)(in_BX + -2) = (int)*(char *)(unaff_SI * 3 + 2);
  *(undefined2 *)(in_BX + -4) = (char *)s_Lib_error_6___s__3e2d_1676 + 4;
  *(undefined2 *)(in_BX + -6) = 0x69be;
  fn_178d_0091();
  *(int *)(in_BX + -2) = (g_8201 * 0x91) / 100 + 0x6e;
  *(undefined2 *)(in_BX + -4) = 0x278d;
  *(undefined2 *)(in_BX + -6) = 0x69d6;
  fn_2db9_0048();
  return;
}


//// fn_067a_023d @ 167a:023d

void __cdecl16far fn_067a_023d(void)

{
  if ((g_7fda & 2) != 0) {
    if (iRam00040162 != 0) {
      fn_178d_01b0();
      fn_2120_0007(3);
    }
    iRam00040162 = 0;
  }
  fn_067a_01d1(0xffff);
  return;
}


//// fn_067a_026b @ 167a:026b

void __cdecl16far fn_067a_026b(undefined2 param_1)

{
  fn_067a_02f5((char *)s_Lib_error_6___s__3e2d_1676 + 4,param_1,g_7fd0);
  return;
}


//// fn_067a_027f @ 167a:027f

void __cdecl16far fn_067a_027f(undefined2 param_1,undefined2 param_2)

{
  if (g_2144 == 0) {
    fn_067a_02f5((char *)s_Lib_error_6___s__3e2d_1676 + 4,param_1,param_2);
  }
  else if (g_2146 < 10) {
    ((undefined2 *)&g_2148)[g_2146] = param_1;
    ((undefined2 *)&g_215c)[g_2146] = param_2;
    g_2146 = g_2146 + 1;
  }
  else {
    fn_0845_0f81(0x1ec7,0x3e2d);
  }
  return;
}


//// fn_067a_02c7 @ 167a:02c7

void __cdecl16far fn_067a_02c7(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < g_2146) {
    do {
      fn_067a_02f5((char *)s_Lib_error_6___s__3e2d_1676 + 4,((undefined2 *)&g_2148)[iVar1],
                    ((undefined2 *)&g_215c)[iVar1]);
      iVar1 = iVar1 + 1;
    } while (iVar1 < g_2146);
  }
  return;
}


//// fn_067a_02f5 @ 167a:02f5

void fn_067a_02f5(undefined2 param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int unaff_DI;
  char *pcVar3;
  int iStack_6;
  
  pcVar3 = (char *)s_Lib_error_6___s__3e2d_1676 + 4;
  if ((g_7fda & 1) != 0) {
    if (0 < iRam00040166) {
      fn_067a_0417(iRam00040166,iRam00040168);
    }
    if (param_3 != 0) {
      pcVar3 = (char *)0x2aff;
      unaff_DI = fn_1aff_02d2();
      if ((g_3745 == 6) || (g_3745 == 7)) {
        iVar1 = 3;
      }
      else {
        iVar1 = 0xf;
      }
      if (iVar1 < unaff_DI) {
        iRam00040166 = 0;
        return;
      }
    }
    iRam00040166 = param_2;
    if ((param_3 == 0) && (1 < unaff_DI)) {
      unaff_DI = 0;
    }
    iRam00040168 = (0xf - unaff_DI) * 0x10;
    if (g_7fd0 != param_3) {
      uVar2 = g_7fd0;
      for (iStack_6 = 3; (uVar2 != param_3 && (iStack_6 != 0)); iStack_6 = iStack_6 + -1) {
        pcVar3 = (char *)0x2afa;
        iVar1 = fn_1afa_0010(uVar2 & 0x1f,(int)uVar2 >> 5,param_3 & 0x1f,(int)param_3 >> 5);
        uVar2 = uVar2 + *(int *)(iVar1 * 2 + 0x1e9a);
        if (uVar2 != param_3) {
          pcVar3 = (char *)s_Lib_error_29_3e2d_1842 + 3;
          iVar1 = fn_0845_0cf7(uVar2);
          if (iVar1 != 0) {
            iRam00040168 = iRam00040168 >> 1;
          }
        }
      }
    }
    if ((param_2 != 0) && (g_7fb6 == 0)) {
      fn_067a_02f5(pcVar3,0);
    }
  }
  return;
}


//// fn_067a_0300 @ 167a:0300

void __cdecl16far fn_067a_0300(void)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  int unaff_BP;
  uint unaff_SI;
  int unaff_DI;
  char *pcVar4;
  undefined2 unaff_SS;
  
  pcVar4 = (char *)s_Lib_error_6___s__3e2d_1676 + 4;
  if ((g_7fda & 1) != 0) {
    if (0 < iRam00040166) {
      fn_067a_0417(iRam00040166,iRam00040168);
    }
    if (unaff_SI != 0) {
      pcVar4 = (char *)0x2aff;
      unaff_DI = fn_1aff_02d2();
      if ((g_3745 == 6) || (g_3745 == 7)) {
        iVar1 = 3;
      }
      else {
        iVar1 = 0xf;
      }
      if (iVar1 < unaff_DI) {
        iRam00040166 = 0;
        return;
      }
    }
    uVar3 = g_7fd0;
    iRam00040166 = *(int *)(unaff_BP + 6);
    if ((unaff_SI == 0) && (1 < unaff_DI)) {
      unaff_DI = 0;
    }
    iRam00040168 = (0xf - unaff_DI) * 0x10;
    if (g_7fd0 != unaff_SI) {
      *(undefined2 *)(unaff_BP + -4) = 3;
      while ((uVar3 != unaff_SI && (*(int *)(unaff_BP + -4) != 0))) {
        pcVar4 = (char *)0x2afa;
        uVar2 = fn_1afa_0010(uVar3 & 0x1f,(int)uVar3 >> 5,unaff_SI & 0x1f,(int)unaff_SI >> 5);
        *(undefined2 *)(unaff_BP + -2) = uVar2;
        uVar3 = uVar3 + *(int *)(*(int *)(unaff_BP + -2) * 2 + 0x1e9a);
        if (uVar3 != unaff_SI) {
          pcVar4 = (char *)s_Lib_error_29_3e2d_1842 + 3;
          iVar1 = fn_0845_0cf7(uVar3);
          if (iVar1 != 0) {
            iRam00040168 = iRam00040168 >> 1;
          }
        }
        *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) + -1;
      }
    }
    if ((*(int *)(unaff_BP + 6) != 0) && (g_7fb6 == 0)) {
      fn_067a_02f5(pcVar4,0);
    }
  }
  return;
}


//// fn_067a_0401 @ 167a:0401

void __cdecl16far fn_067a_0401(undefined2 param_1,undefined2 param_2)

{
  fn_067a_0417(param_1,0xff,param_2);
  return;
}


//// fn_067a_0417 @ 167a:0417

void __cdecl16far fn_067a_0417(char *param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int local_8;
  long local_6;
  
  if ((param_3 == 0) && ((g_7fda & 1) == 0)) {
    return;
  }
  if (param_1 == (char *)((int)(undefined2 *)&g_0000 + 1)) {
    if (UINT_3e2d_1eaa == 0xffff) {
      return;
    }
    if (UINT_3e2d_1eaa == 1) {
      return;
    }
  }
  UINT_3e2d_1eaa = (uint)param_1;
  if (*(int *)((int)param_1 * 4 + 0x9e4) < 1) {
    local_8 = -*(int *)((int)param_1 * 4 + 0x9e4);
  }
  else {
    local_8 = *(int *)((int)param_1 * 4 + 0x9e4) * param_2 >> 8;
  }
  iVar2 = fn_16cf_01c8();
  if (iVar2 == 0) {
    local_6 = 0;
  }
  else {
    local_6 = fn_067a_0649(0x26cf,param_1);
  }
  if (local_6 != 0) {
    fn_15a7_02b6(local_6);
    if (param_2 == 0xff) {
      uVar3 = (g_8200 * 200) / 100 + 0x37;
    }
    else {
      uVar3 = (uint)(((g_8200 * 200) / 100 + 0x37) * param_2) >> 8;
    }
    fn_16cf_0022(local_6,local_8,uVar3);
    return;
  }
  if (*(int *)((int)param_1 * 4 + 0x9e4) < 0) {
    param_2 = 0xff;
  }
  if (g_3745 == 4) {
    cVar1 = *param_1;
  }
  else if (g_3745 == 6) {
    cVar1 = *param_1;
  }
  else {
    if (g_3745 != 7) goto LAB_167a_055b;
    cVar1 = *param_1;
  }
  param_1 = (char *)(int)cVar1;
LAB_167a_055b:
  if (param_1 == (char *)0xa8) {
    param_1 = (char *)0xa7;
  }
  fn_17d6_0019(param_1,param_2);
  return;
}


//// fn_067a_0572 @ 167a:0572

undefined2 fn_067a_0572(undefined2 param_1,long param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  char *pcVar3;
  long lVar4;
  undefined2 uVar5;
  
  pcVar3 = (char *)s_Lib_error_6___s__3e2d_1676 + 4;
  if (g_3749 == 0) {
    uVar1 = fn_067a_060a();
    return uVar1;
  }
  if (lRam0004015c != 0) {
    fn_203b_0203((int)lRam0004015c,(int)((ulong)lRam0004015c >> 0x10));
    lRam0004015c = 0;
    pcVar3 = 
    "\x11\x02\x1e),(((((),(((\x05\x05)\x17\x17\x0e\x0e\x0e\x0e\x0e\x0e\x0e\x0e\x0e\x0e\x0e\x0e\x0e\x0f,#\x02,\x0f*(((\x13\x1b\x1c\x02\x02\x05\x0f\x02\x17(*\x13*\x0e\x0e\x0e\x0e\x0e\x0e\x0e#\x0e\x1c(\x17#%\x13("
    ;
    fn_2dc3_0020(0x303b);
  }
  if (param_2 != 0) {
    lVar4 = fn_2dca_0025(pcVar3,g_2140,0,g_2142,0);
    uVar1 = (undefined2)((ulong)lVar4 >> 0x10);
    if (lVar4 != 0) {
      uVar5 = (undefined2)((ulong)param_2 >> 0x10);
      uVar2 = fn_203b_0007((int)param_2,uVar5,g_4b92);
      lRam0004015c = CONCAT22(uVar1,uVar2);
      if (lRam0004015c == 0) {
        fn_2dc3_0020(0x303b);
      }
      else {
        fn_15a7_0004(uVar2,uVar1,(int)param_2,uVar5);
      }
    }
  }
  if (lRam0004015c != 0) {
    uVar1 = fn_067a_060a();
    return uVar1;
  }
  return 0;
}


//// fn_067a_058a @ 167a:058a

undefined2 fn_067a_058a(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  long lVar3;
  
  fn_203b_0203((undefined2)lRam0004015c);
  lRam0004015c = 0;
  fn_2dc3_0020();
  if (*(long *)(unaff_BP + 6) != 0) {
    lVar3 = fn_2dca_0025(0x3dc3,g_2140,0,g_2142);
    uVar2 = (undefined2)((ulong)lVar3 >> 0x10);
    if (lVar3 != 0) {
      uVar1 = fn_203b_0007((int)*(undefined4 *)(unaff_BP + 6),
                            (int)((ulong)*(undefined4 *)(unaff_BP + 6) >> 0x10));
      lRam0004015c = CONCAT22(uVar2,uVar1);
      if (lRam0004015c == 0) {
        fn_2dc3_0020();
      }
      else {
        fn_15a7_0004(uVar1,uVar2,(int)*(undefined4 *)(unaff_BP + 6));
      }
    }
  }
  if (lRam0004015c != 0) {
    uVar2 = fn_067a_060a();
    return uVar2;
  }
  return 0;
}


//// fn_067a_060a @ 167a:060a

void __cdecl16far fn_067a_060a(void)

{
  return;
}


//// fn_067a_060c @ 167a:060c

void __cdecl16far fn_067a_060c(void)

{
  undefined2 uVar1;
  undefined2 extraout_DX;
  undefined2 uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uStackY_c;
  
  pcVar4 = (char *)s_Lib_error_6___s__3e2d_1676 + 4;
  if (g_3749 != 0) {
    for (iVar3 = 0; iVar3 < 0x2e; iVar3 = iVar3 + 1) {
      fn_067a_0649(pcVar4,iVar3);
      pcVar4 = (char *)0x25a7;
      uVar2 = extraout_DX;
      uVar1 = fn_15a7_04b0();
      uStackY_c = CONCAT22(uVar2,uVar1);
      if (uStackY_c < 10000) {
        return;
      }
    }
  }
  return;
}


//// fn_067a_0644 @ 167a:0644

void __cdecl16far fn_067a_0644(void)

{
  return;
}


//// fn_067a_0649 @ 167a:0649

undefined4 fn_067a_0649(undefined2 param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 in_DX;
  undefined4 uVar5;
  long lStackY_38;
  int iVar6;
  char local_22;
  char cStack_21;
  undefined4 uStack_e;
  undefined4 uStack_a;
  undefined4 local_6;
  
  if (((param_2 == -1) || (g_3749 == 0)) || (*(int *)(param_2 * 4 + 0x9e2) == -1)) {
    return 0;
  }
  iVar6 = param_2 >> 0xf;
  uVar1 = fn_15a7_030c((int)uRam0004015c,(int)((ulong)uRam0004015c >> 0x10),param_2,iVar6);
  local_6 = CONCAT22(in_DX,uVar1);
  if ((((local_6 == 0) && (sprintf(&local_22), local_22 != 'X')) &&
      ((local_22 != 'E' || (cStack_21 != 'M')))) && (iVar2 = fn_1981_000a(&local_22), iVar2 != 0))
  {
    uVar1 = fn_1809_0000(&local_22);
    uStack_a._0_2_ = fn_1809_120c(uVar1);
    uStack_a._2_2_ = in_DX;
    uVar3 = fn_2dc6_0020((char *)s_FINALE_EXE_3e2d_2803 + 6,uVar1);
    uStack_a = fn_2dc6_0025(0x3dc6,(undefined2)uStack_a,uStack_a._2_2_,uVar3);
    uVar3 = (undefined2)((ulong)uStack_a >> 0x10);
    do {
      uVar4 = fn_15a7_04b0((int)uRam0004015c,(int)((ulong)uRam0004015c >> 0x10));
      if (uStack_a <= CONCAT22(uVar3,uVar4)) break;
      uVar4 = fn_15a7_043c((int)uRam0004015c,(int)((ulong)uRam0004015c >> 0x10));
      uStack_e = CONCAT22(uVar3,uVar4);
    } while (uStack_e != 0);
    uVar4 = fn_15a7_00b0((int)uRam0004015c,(int)((ulong)uRam0004015c >> 0x10),(int)uStack_a,
                          (int)((ulong)uStack_a >> 0x10),param_2,iVar6);
    local_6 = CONCAT22(uVar3,uVar4);
    if (local_6 == 0) {
      while (local_6 == 0) {
        uVar4 = fn_15a7_043c((int)uRam0004015c,(int)((ulong)uRam0004015c >> 0x10));
        uStack_e = CONCAT22(uVar3,uVar4);
        if (uStack_e == 0) break;
        uVar4 = fn_15a7_00b0((int)uRam0004015c,(int)((ulong)uRam0004015c >> 0x10),(int)uStack_a,
                              (int)((ulong)uStack_a >> 0x10),param_2,iVar6);
        local_6 = CONCAT22(uVar3,uVar4);
      }
      if (local_6 == 0) {
        fn_16cf_00b9(0,0);
        fn_15a7_0501((int)uRam0004015c,(int)((ulong)uRam0004015c >> 0x10));
        uVar4 = fn_15a7_00b0((int)uRam0004015c,(int)((ulong)uRam0004015c >> 0x10),(int)uStack_a,
                              (int)((ulong)uStack_a >> 0x10),param_2,iVar6);
        local_6 = CONCAT22(uVar3,uVar4);
      }
    }
    if (local_6 != 0) {
      lStackY_38 = fn_2dc6_002f();
      uStack_e = lStackY_38;
      if (lStackY_38 == 0) {
        ovr_2d46_002a(1,(char *)s_Unable_to_load_voc_file__s_3e2d_1ef4,0x3e2d,&local_22);
      }
    }
    fn_1809_058d(uVar1);
  }
  uVar5 = fn_067a_0849();
  return uVar5;
}


//// fn_067a_06c1 @ 167a:06c1

void fn_067a_06c1(void)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 in_DX;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  bool in_ZF;
  undefined4 uVar5;
  undefined4 uStackY_12;
  
  if ((!in_ZF) &&
     (((*(char *)(unaff_BP + -0x20) != 'E' || (*(char *)(unaff_BP + -0x1f) != 'M')) &&
      (iVar1 = fn_1981_000a(unaff_BP + -0x20), iVar1 != 0)))) {
    uVar2 = fn_1809_0000(unaff_BP + -0x20);
    uVar3 = fn_1809_120c(uVar2);
    *(undefined4 *)(unaff_BP + -8) = CONCAT22(in_DX,uVar3);
    uVar3 = fn_2dc6_0020((char *)s_FINALE_EXE_3e2d_2803 + 6,uVar2);
    uVar5 = fn_2dc6_0025(0x3dc6,(int)*(undefined4 *)(unaff_BP + -8),
                          (int)((ulong)*(undefined4 *)(unaff_BP + -8) >> 0x10),uVar3);
    uVar3 = (undefined2)((ulong)uVar5 >> 0x10);
    *(undefined4 *)(unaff_BP + -8) = uVar5;
    do {
      uVar4 = fn_15a7_04b0((int)uRam0004015c,(int)((ulong)uRam0004015c >> 0x10));
      if (*(long *)(unaff_BP + -8) <= CONCAT22(uVar3,uVar4)) break;
      uVar4 = fn_15a7_043c((int)uRam0004015c,(int)((ulong)uRam0004015c >> 0x10));
      *(undefined2 *)(unaff_BP + -10) = uVar3;
      *(undefined2 *)(unaff_BP + -0xc) = uVar4;
    } while (*(long *)(unaff_BP + -0xc) != 0);
    iVar1 = unaff_SI >> 0xf;
    uVar4 = fn_15a7_00b0((int)uRam0004015c,(int)((ulong)uRam0004015c >> 0x10),
                          (int)*(undefined4 *)(unaff_BP + -8),
                          (int)((ulong)*(undefined4 *)(unaff_BP + -8) >> 0x10),unaff_SI,iVar1);
    *(undefined2 *)(unaff_BP + -2) = uVar3;
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    if (*(long *)(unaff_BP + -4) == 0) {
      while (*(long *)(unaff_BP + -4) == 0) {
        uVar4 = fn_15a7_043c((int)uRam0004015c,(int)((ulong)uRam0004015c >> 0x10));
        *(undefined2 *)(unaff_BP + -10) = uVar3;
        *(undefined2 *)(unaff_BP + -0xc) = uVar4;
        if (*(long *)(unaff_BP + -0xc) == 0) break;
        uVar4 = fn_15a7_00b0((int)uRam0004015c,(int)((ulong)uRam0004015c >> 0x10),
                              (int)*(undefined4 *)(unaff_BP + -8),
                              (int)((ulong)*(undefined4 *)(unaff_BP + -8) >> 0x10),unaff_SI,iVar1);
        *(undefined2 *)(unaff_BP + -2) = uVar3;
        *(undefined2 *)(unaff_BP + -4) = uVar4;
      }
      if (*(long *)(unaff_BP + -4) == 0) {
        fn_16cf_00b9(0,0);
        fn_15a7_0501((int)uRam0004015c,(int)((ulong)uRam0004015c >> 0x10));
        uVar4 = fn_15a7_00b0((int)uRam0004015c,(int)((ulong)uRam0004015c >> 0x10),
                              (int)*(undefined4 *)(unaff_BP + -8),
                              (int)((ulong)*(undefined4 *)(unaff_BP + -8) >> 0x10),unaff_SI,iVar1);
        *(undefined2 *)(unaff_BP + -2) = uVar3;
        *(undefined2 *)(unaff_BP + -4) = uVar4;
      }
    }
    if (*(long *)(unaff_BP + -4) != 0) {
      uStackY_12 = fn_2dc6_002f();
      *(undefined4 *)(unaff_BP + -0xc) = uStackY_12;
      if (*(long *)(unaff_BP + -0xc) == 0) {
        ovr_2d46_002a(1,(char *)s_Unable_to_load_voc_file__s_3e2d_1ef4,0x3e2d,unaff_BP + -0x20);
      }
    }
    fn_1809_058d(uVar2);
  }
  fn_067a_0849();
  return;
}


//// fn_067a_0823 @ 167a:0823

void fn_067a_0823(void)

{
  int unaff_BP;
  
  ovr_2d46_002a(1,(char *)s_Unable_to_load_voc_file__s_3e2d_1ef4,0x3e2d,unaff_BP + -0x20);
  fn_1809_058d();
  fn_067a_0849();
  return;
}


//// fn_067a_0841 @ 167a:0841

void fn_067a_0841(void)

{
  fn_067a_0849();
  return;
}


//// fn_067a_0846 @ 167a:0846

void fn_067a_0846(void)

{
  byte in_CL;
  int in_BX;
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_SS;
  
  *(char *)(unaff_BP + unaff_DI) = *(char *)(unaff_BP + unaff_DI) << (in_CL & 0x1f);
  *(undefined1 *)(in_BX + 0x5e) = *(undefined1 *)(in_BX + 0x5e);
  return;
}


//// fn_067a_0849 @ 167a:0849

void fn_067a_0849(void)

{
  return;
}


//// fn_067a_084b @ 167a:084b

void __cdecl16far fn_067a_084b(void)

{
  return;
}


//// fn_067a_084d @ 167a:084d

void fn_067a_084d(undefined2 param_1,long param_2,uint param_3)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uStack_6;
  
  if ((param_2 != 0) && (param_3 < 0xfb)) {
    iVar1 = *(int *)(param_3 * 4 + 0x9e2);
    uVar2 = fn_15a7_030c(uRam0004015c,(long)(int)param_3);
    uStack_6 = CONCAT22(param_3,uVar2);
    if (iVar1 != -1) {
      if (uStack_6 != 0) {
        fn_15a7_0210(uRam0004015c,uVar2,param_3);
      }
      strcpy(iVar1 * 10 + 0xf0,0x36a4,param_2);
    }
  }
  return;
}


//// fn_067a_0850 @ 167a:0850

void fn_067a_0850(void)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  
  uVar3 = *(uint *)(unaff_BP + 10);
  if ((*(long *)(unaff_BP + 6) != 0) && (uVar3 < 0xfb)) {
    iVar1 = *(int *)(uVar3 * 4 + 0x9e2);
    uVar2 = fn_15a7_030c(uRam0004015c,(long)(int)uVar3);
    *(uint *)(unaff_BP + -2) = uVar3;
    *(undefined2 *)(unaff_BP + -4) = uVar2;
    if (iVar1 != -1) {
      if (*(long *)(unaff_BP + -4) != 0) {
        fn_15a7_0210(uRam0004015c,uVar2,uVar3);
      }
      strcpy(iVar1 * 10 + 0xf0,0x36a4,*(undefined4 *)(unaff_BP + 6));
    }
  }
  return;
}


//// fn_067a_0855 @ 167a:0855

/* WARNING: Instruction at (ram,0x00017001) overlaps instruction at (ram,0x00016ffe)
    */

void __cdecl16far fn_067a_0855(void)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 in_EAX;
  uint in_DX;
  char cVar3;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  
  cVar3 = (char)(in_DX >> 8);
  if ((char)((byte)((ulong)in_EAX >> 8) | *(byte *)(unaff_BP + -0x7d)) < '\x01') {
    *(char *)(in_BX + 0x5b) = *(char *)(in_BX + 0x5b) + cVar3;
  }
  else {
    *(char *)(unaff_SI + 0x61) = *(char *)(unaff_SI + 0x61) + cVar3;
    if (0xfa < in_DX) {
      return;
    }
  }
  iVar1 = *(int *)(in_DX * 4 + 0x9e2);
  uVar2 = fn_15a7_030c(uRam0004015c,(long)(int)in_DX);
  *(uint *)(unaff_BP + -2) = in_DX;
  *(undefined2 *)(unaff_BP + -4) = uVar2;
  if (iVar1 != -1) {
    if (*(long *)(unaff_BP + -4) != 0) {
      fn_15a7_0210(uRam0004015c,uVar2,in_DX);
    }
    strcpy(iVar1 * 10 + 0xf0,0x36a4,*(undefined4 *)(unaff_BP + 6));
  }
  return;
}


//// fn_067a_0864 @ 167a:0864

void fn_067a_0864(void)

{
  int iVar1;
  undefined2 uVar2;
  int in_DX;
  int unaff_BP;
  undefined2 unaff_SS;
  
  iVar1 = *(int *)(in_DX * 4 + 0x9e2);
  uVar2 = fn_15a7_030c(uRam0004015c,(long)in_DX);
  *(int *)(unaff_BP + -2) = in_DX;
  *(undefined2 *)(unaff_BP + -4) = uVar2;
  if (iVar1 != -1) {
    if (*(long *)(unaff_BP + -4) != 0) {
      fn_15a7_0210(uRam0004015c,uVar2,in_DX);
    }
    strcpy(iVar1 * 10 + 0xf0,0x36a4,*(undefined4 *)(unaff_BP + 6));
  }
  return;
}


//// fn_067a_088f @ 167a:088f

void __cdecl16far fn_067a_088f(void)

{
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  bool in_ZF;
  
  if (!in_ZF) {
    if (*(long *)(unaff_BP + -4) != 0) {
      fn_15a7_0210(uRam0004015c);
    }
    strcpy(unaff_SI * 10 + 0xf0,0x36a4,*(undefined4 *)(unaff_BP + 6));
  }
  return;
}


//// fn_067a_08c2 @ 167a:08c2

int fn_067a_08c2(undefined2 param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_6;
  
  while( true ) {
    iVar3 = param_2 + 1;
    if (iVar3 == 0x2f) {
      iVar3 = param_2 + 2;
    }
    if (*(int *)(iVar3 * 4 + 0x9e2) == 199) break;
    pcVar1 = (char *)(*(int *)(iVar3 * 4 + 0x9e2) * 10 + 0xf0);
    uStack_6 = (char *)CONCAT22(0x36a4,pcVar1);
    param_2 = iVar3;
    if ((*uStack_6 != 'X') &&
       (iVar2 = strcmp(pcVar1,0x36a4,(char *)s_EMPTY_3e2d_1f0f,0x3e2d), iVar2 != 0)) {
      return iVar3;
    }
  }
  return 0xb;
}


//// fn_067a_08c3 @ 167a:08c3

int __cdecl16far fn_067a_08c3(undefined2 param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_4;
  
  while( true ) {
    iVar3 = param_2 + 1;
    if (iVar3 == 0x2f) {
      iVar3 = param_2 + 2;
    }
    if (*(int *)(iVar3 * 4 + 0x9e2) == 199) break;
    pcVar1 = (char *)(*(int *)(iVar3 * 4 + 0x9e2) * 10 + 0xf0);
    uStack_4 = (char *)CONCAT22(0x36a4,pcVar1);
    param_2 = iVar3;
    if ((*uStack_4 != 'X') &&
       (iVar2 = strcmp(pcVar1,0x36a4,(char *)s_EMPTY_3e2d_1f0f,0x3e2d), iVar2 != 0)) {
      return iVar3;
    }
  }
  return 0xb;
}


//// fn_067a_0900 @ 167a:0900

int __cdecl16far fn_067a_0900(void)

{
  int in_AX;
  int iVar1;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  
  while( true ) {
    *(undefined2 *)(unaff_BP + -2) = 0x36a4;
    *(int *)(unaff_BP + -4) = in_AX;
    if ((*(char *)*(undefined4 *)(unaff_BP + -4) != 'X') &&
       (iVar1 = strcmp(in_AX,*(undefined2 *)(unaff_BP + -2),(char *)s_EMPTY_3e2d_1f0f,0x3e2d)
       , iVar1 != 0)) {
      return unaff_SI;
    }
    iVar1 = unaff_SI + 1;
    if (iVar1 == 0x2f) {
      iVar1 = unaff_SI + 2;
    }
    if (*(int *)(iVar1 * 4 + 0x9e2) == 199) break;
    in_AX = *(int *)(iVar1 * 4 + 0x9e2) * 10 + 0xf0;
    unaff_SI = iVar1;
  }
  return 0xb;
}

