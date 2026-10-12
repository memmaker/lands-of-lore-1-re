//// fn_07bc_000e @ 17bc:000e

undefined2 __cdecl16far fn_07bc_000e(int param_1)

{
  undefined2 uVar1;
  
  if (((*(uint *)(param_1 * 0x10 + 0x1d0b) & 0x4000) == 0) ||
     ((*(uint *)((int)g_7fb2 +
                 *(int *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 9 + param_1 * 0x10) * 0xd + 3) & 4) != 0)
     ) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


//// fn_07bc_0050 @ 17bc:0050

void fn_07bc_0050(void)

{
  fn_07bc_0077();
  return;
}


//// fn_07bc_0060 @ 17bc:0060

void __cdecl16far fn_07bc_0060(void)

{
  int in_AX;
  int in_BX;
  int unaff_SI;
  
  *(undefined1 *)(unaff_SI + 5) = 0;
  *(int *)(in_BX + unaff_SI) = *(int *)(in_BX + unaff_SI) + in_AX;
  return;
}


//// fn_07bc_0077 @ 17bc:0077

undefined2 __cdecl16far fn_07bc_0077(void)

{
  int iVar1;
  int unaff_SI;
  
  while( true ) {
    if (unaff_SI == 0) {
      return 0;
    }
    iVar1 = fn_07bc_000e(unaff_SI);
    if (iVar1 != 0) break;
    unaff_SI = *(int *)(unaff_SI * 0x10 + 0x1cfd);
  }
  return 1;
}


//// fn_07bc_0080 @ 17bc:0080

int __cdecl16far fn_07bc_0080(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = fn_07bc_000e(param_1);
  if (iVar1 == 0) {
    do {
      iVar1 = param_1;
      param_1 = *(int *)(iVar1 * 0x10 + 0x1cfd);
      if (param_1 == 0) {
        return 0;
      }
      iVar2 = fn_07bc_000e(param_1);
    } while (iVar2 == 0);
    *(undefined2 *)(iVar1 * 0x10 + 0x1cfd) = *(undefined2 *)(param_1 * 0x10 + 0x1cfd);
    fn_07bc_044c(param_1);
  }
  else {
    if (*(int *)(param_1 * 0x10 + 0x1cfd) != 0) {
      ((char *)s_ADLIBG_ADV_3e2d_1d00 + 8)[*(int *)(param_1 * 0x10 + 0x1cfd) * 0x10] =
           ((char *)s_ADLIBG_ADV_3e2d_1d00 + 8)[param_1 * 0x10];
    }
    fn_07bc_044c(param_1);
  }
  return param_1;
}


//// fn_07bc_012d @ 17bc:012d

/* WARNING: Removing unreachable block (ram,0x00017dbd) */
/* WARNING: Removing unreachable block (ram,0x00017dc1) */
/* WARNING: Removing unreachable block (ram,0x00017dcb) */

undefined2 fn_07bc_012d(void)

{
  undefined2 uVar1;
  
  uVar1 = fn_07bc_0142();
  return uVar1;
}


//// fn_07bc_0142 @ 17bc:0142

int fn_07bc_0142(void)

{
  uint *puVar1;
  int iVar2;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  
  if ((*(uint *)(unaff_SI * 0x10 + 0x1d0b) & 0x8000) != 0) {
    iVar2 = fn_07bc_01fd();
    return iVar2;
  }
  if (((((char *)s_ADLIBG_ADV_3e2d_1d00 + 8)[unaff_SI * 0x10] != '\0') &&
      ((byte)((char *)s_ADLIBG_ADV_3e2d_1d00 + 8)[unaff_SI * 0x10] < 0x1e)) &&
     (((char *)s_ADLIBG_ADV_3e2d_1d00 + 8)[unaff_SI * 0x10] != g_7fe5)) {
    if ((int)g_7fe5 < (int)(uint)(byte)((char *)s_ADLIBG_ADV_3e2d_1d00 + 8)[unaff_SI * 0x10])
    {
      iVar2 = -((int)g_7fe5 -
               (uint)(byte)((char *)s_ADLIBG_ADV_3e2d_1d00 + 8)[unaff_SI * 0x10]);
    }
    else {
      iVar2 = (int)g_7fe5 - (uint)(byte)((char *)s_ADLIBG_ADV_3e2d_1d00 + 8)[unaff_SI * 0x10]
      ;
    }
    *(int *)(unaff_BP + -2) = iVar2;
    if ((unaff_DI < *(int *)(unaff_BP + -2)) &&
       (iVar2 = fn_07bc_0050((char *)s_File_error_16_24__3e2d_17b2 + 10), iVar2 != 0)) {
      unaff_DI = *(int *)(unaff_BP + -2);
      *(int *)(unaff_BP + -4) = unaff_SI;
    }
  }
  iVar2 = unaff_SI + 1;
  if (399 < iVar2) {
    if (unaff_DI != 0) {
      iVar2 = fn_07bc_0080(*(undefined2 *)(unaff_BP + -4));
    }
    setmem((char *)s_File_error_16_24__3e2d_17b2 + 10,iVar2 * 0x10 + 0x1cfd,
                  (undefined1 *)&g_3803,0x10,0);
    *(undefined2 *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 9 + iVar2 * 0x10) =
         *(undefined2 *)(unaff_BP + 6);
    *(uint *)(iVar2 * 0x10 + 0x1d0b) = *(uint *)(unaff_BP + 8) & 0x1fff;
    puVar1 = (uint *)(iVar2 * 0x10 + 0x1d0b);
    *puVar1 = *puVar1 | *(uint *)(unaff_BP + 10);
    ((char *)s_ADLIBG_ADV_3e2d_1d00 + 8)[iVar2 * 0x10] = -1;
    return iVar2;
  }
  iVar2 = fn_07bc_0142();
  return iVar2;
}


//// fn_07bc_01e0 @ 17bc:01e0

int fn_07bc_01e0(void)

{
  uint *puVar1;
  int iVar2;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  
  *(char *)(unaff_BP + 0x10) = *(char *)(unaff_BP + 0x10) + '\x01';
  iVar2 = fn_07bc_0050((char *)s_File_error_16_24__3e2d_17b2 + 10);
  if (iVar2 != 0) {
    unaff_DI = *(int *)(unaff_BP + -2);
    *(int *)(unaff_BP + -4) = unaff_SI;
  }
  iVar2 = unaff_SI + 1;
  if (iVar2 < 400) {
    iVar2 = fn_07bc_0142();
    return iVar2;
  }
  if (unaff_DI != 0) {
    iVar2 = fn_07bc_0080(*(undefined2 *)(unaff_BP + -4));
  }
  setmem((char *)s_File_error_16_24__3e2d_17b2 + 10,iVar2 * 0x10 + 0x1cfd,
                (undefined1 *)&g_3803,0x10,0);
  *(undefined2 *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 9 + iVar2 * 0x10) = *(undefined2 *)(unaff_BP + 6)
  ;
  *(uint *)(iVar2 * 0x10 + 0x1d0b) = *(uint *)(unaff_BP + 8) & 0x1fff;
  puVar1 = (uint *)(iVar2 * 0x10 + 0x1d0b);
  *puVar1 = *puVar1 | *(uint *)(unaff_BP + 10);
  ((char *)s_ADLIBG_ADV_3e2d_1d00 + 8)[iVar2 * 0x10] = -1;
  return iVar2;
}


//// fn_07bc_01e5 @ 17bc:01e5

int fn_07bc_01e5(void)

{
  uint *puVar1;
  int iVar2;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  
  iVar2 = fn_07bc_0050();
  if (iVar2 != 0) {
    unaff_DI = *(int *)(unaff_BP + -2);
    *(int *)(unaff_BP + -4) = unaff_SI;
  }
  iVar2 = unaff_SI + 1;
  if (iVar2 < 400) {
    iVar2 = fn_07bc_0142();
    return iVar2;
  }
  if (unaff_DI != 0) {
    iVar2 = fn_07bc_0080();
  }
  setmem((char *)s_File_error_16_24__3e2d_17b2 + 10,iVar2 * 0x10 + 0x1cfd,
                (undefined1 *)&g_3803);
  *(undefined2 *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 9 + iVar2 * 0x10) = *(undefined2 *)(unaff_BP + 6)
  ;
  *(uint *)(iVar2 * 0x10 + 0x1d0b) = *(uint *)(unaff_BP + 8) & 0x1fff;
  puVar1 = (uint *)(iVar2 * 0x10 + 0x1d0b);
  *puVar1 = *puVar1 | *(uint *)(unaff_BP + 10);
  ((char *)s_ADLIBG_ADV_3e2d_1d00 + 8)[iVar2 * 0x10] = -1;
  return iVar2;
}


//// fn_07bc_01fd @ 17bc:01fd

int fn_07bc_01fd(void)

{
  uint *puVar1;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  
  if (unaff_DI != 0) {
    unaff_SI = fn_07bc_0080(*(undefined2 *)(unaff_BP + -4));
  }
  setmem((char *)s_File_error_16_24__3e2d_17b2 + 10,unaff_SI * 0x10 + 0x1cfd,
                (undefined1 *)&g_3803,0x10,0);
  *(undefined2 *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 9 + unaff_SI * 0x10) =
       *(undefined2 *)(unaff_BP + 6);
  *(uint *)(unaff_SI * 0x10 + 0x1d0b) = *(uint *)(unaff_BP + 8) & 0x1fff;
  puVar1 = (uint *)(unaff_SI * 0x10 + 0x1d0b);
  *puVar1 = *puVar1 | *(uint *)(unaff_BP + 10);
  ((char *)s_ADLIBG_ADV_3e2d_1d00 + 8)[unaff_SI * 0x10] = -1;
  return unaff_SI;
}


//// fn_07bc_026a @ 17bc:026a

/* WARNING: Control flow encountered bad instruction data */

void fn_07bc_026a(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


//// fn_07bc_0272 @ 17bc:0272

void __cdecl16far fn_07bc_0272(int param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  uint *puVar1;
  int iVar2;
  
  if (param_4 == 0) {
    param_2 = param_2 & 0xffc0 | 0x40;
    param_3 = param_3 & 0xffc0 | 0x40;
  }
  iVar2 = fn_1aff_039a(param_2,param_3);
  *(uint *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 4 + param_1 * 0x10) = param_2;
  *(uint *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 6 + param_1 * 0x10) = param_3;
  *(int *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 2 + param_1 * 0x10) = iVar2;
  ((char *)s_ADLIBG_ADV_3e2d_1d00 + 1)[param_1 * 0x10] = (char)param_4;
  if (param_5 == 0) {
    puVar1 = (uint *)(param_1 * 0x10 + 0x1d0b);
    *puVar1 = *puVar1 & 0xbfff;
  }
  else {
    puVar1 = (uint *)(param_1 * 0x10 + 0x1d0b);
    *puVar1 = *puVar1 | 0x4000;
  }
  fn_080e_005f(iVar2 * 10 + -0x7df9,0x3e2d,param_1);
  fn_080e_0245(g_7fdf,param_1,iVar2 * 10 + -0x7dfd,0x3e2d,0);
  if (param_5 != 0) {
    fn_0845_1343(iVar2,0xffff0080,param_1,0);
  }
  fn_0845_046c();
  return;
}


//// fn_07bc_0288 @ 17bc:0288

void __cdecl16far fn_07bc_0288(void)

{
  char *pcVar1;
  uint *puVar2;
  int iVar3;
  char in_CL;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  
  pcVar1 = (char *)(in_BX + unaff_DI + 0x846);
  *pcVar1 = *pcVar1 + in_CL;
  *(uint *)(unaff_BP + 10) = *(uint *)(unaff_BP + 10) & 0xffc0 | 0x40;
  iVar3 = fn_1aff_039a(*(undefined2 *)(unaff_BP + 8),*(undefined2 *)(unaff_BP + 10));
  *(undefined2 *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 4 + unaff_SI * 0x10) =
       *(undefined2 *)(unaff_BP + 8);
  *(undefined2 *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 6 + unaff_SI * 0x10) =
       *(undefined2 *)(unaff_BP + 10);
  *(int *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 2 + unaff_SI * 0x10) = iVar3;
  ((char *)s_ADLIBG_ADV_3e2d_1d00 + 1)[unaff_SI * 0x10] = *(char *)(unaff_BP + 0xc);
  if (*(int *)(unaff_BP + 0xe) == 0) {
    puVar2 = (uint *)(unaff_SI * 0x10 + 0x1d0b);
    *puVar2 = *puVar2 & 0xbfff;
  }
  else {
    puVar2 = (uint *)(unaff_SI * 0x10 + 0x1d0b);
    *puVar2 = *puVar2 | 0x4000;
  }
  fn_080e_005f(iVar3 * 10 + -0x7df9,0x3e2d);
  fn_080e_0245(g_7fdf);
  if (*(int *)(unaff_BP + 0xe) != 0) {
    fn_0845_1343(iVar3,0xffff0080);
  }
  fn_0845_046c();
  return;
}


//// fn_07bc_0367 @ 17bc:0367

void __cdecl16far fn_07bc_0367(int param_1,int param_2)

{
  fn_080e_013c(param_2 * 10 + -0x7df9,0x3e2d,param_1);
  fn_080e_02f5(param_2 * 10 + -0x7dfd,0x3e2d,param_1);
  fn_0845_1343(param_2,0xffff0100,param_1,0);
  ((char *)s_ADLIBG_ADV_3e2d_1d00 + 2 + param_1 * 0x10)[0] = '\0';
  ((char *)s_ADLIBG_ADV_3e2d_1d00 + 2 + param_1 * 0x10)[1] = '\0';
  ((char *)s_ADLIBG_ADV_3e2d_1d00 + 8)[param_1 * 0x10] = '\0';
  return;
}


//// fn_07bc_03d0 @ 17bc:03d0

uint __cdecl16far fn_07bc_03d0(uint *param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint *puVar2;
  undefined2 in_DX;
  undefined4 uStack_6;
  
  while( true ) {
    if (*param_1 == 0) {
      return 0xffff;
    }
    puVar2 = (uint *)fn_080e_000b(*param_1);
    uStack_6 = (uint *)CONCAT22(in_DX,puVar2);
    if (((((*param_1 & 0x8000) == 0) && (*(int *)((int)puVar2 + 7) == param_2)) &&
        (*(int *)((int)puVar2 + 9) == param_3)) && ((byte)puVar2[2] == param_4)) break;
    param_1 = uStack_6;
  }
  uVar1 = *param_1;
  *param_1 = *uStack_6;
  *uStack_6 = 0;
  return uVar1;
}


//// fn_07bc_03e0 @ 17bc:03e0

/* WARNING: Instruction at (ram,0x00017fa3) overlaps instruction at (ram,0x00017fa0)
    */

undefined2 __cdecl16far fn_07bc_03e0(void)

{
  undefined2 in_AX;
  undefined2 in_CX;
  undefined2 in_DX;
  int iVar1;
  int unaff_BP;
  undefined2 uVar2;
  undefined2 unaff_SS;
  
  do {
    g_5918 = g_5918 + (char)in_CX;
    *(undefined2 *)(unaff_BP + -2) = in_DX;
    *(undefined2 *)(unaff_BP + -4) = in_AX;
    if ((*(uint *)*(undefined4 *)(unaff_BP + 6) & 0x8000) == 0) {
      uVar2 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
      iVar1 = (int)*(undefined4 *)(unaff_BP + -4);
      if (((*(int *)(iVar1 + 7) == *(int *)(unaff_BP + 10)) &&
          (*(int *)(iVar1 + 9) == *(int *)(unaff_BP + 0xc))) &&
         ((uint)*(byte *)(iVar1 + 4) == *(uint *)(unaff_BP + 0xe))) {
        *(undefined2 *)(unaff_BP + -6) = *(undefined2 *)*(undefined4 *)(unaff_BP + 6);
        *(undefined2 *)*(undefined4 *)(unaff_BP + 6) = *(undefined2 *)*(undefined4 *)(unaff_BP + -4)
        ;
        *(undefined2 *)*(undefined4 *)(unaff_BP + -4) = 0;
        return *(undefined2 *)(unaff_BP + -6);
      }
    }
    *(undefined4 *)(unaff_BP + 6) = *(undefined4 *)(unaff_BP + -4);
    if (*(int *)*(undefined4 *)(unaff_BP + 6) == 0) {
      return 0xffff;
    }
    in_CX = *(undefined2 *)*(undefined4 *)(unaff_BP + 6);
    in_AX = fn_080e_000b();
  } while( true );
}


//// fn_07bc_044c @ 17bc:044c

void __cdecl16far fn_07bc_044c(int param_1)

{
  uint *puVar1;
  
  setmem((char *)s_File_error_16_24__3e2d_17b2 + 10,param_1 * 0x10 + 0x1cfd,
                (undefined1 *)&g_3803,0x10,0);
  puVar1 = (uint *)(param_1 * 0x10 + 0x1d0b);
  *puVar1 = *puVar1 | 0x8000;
  return;
}


//// fn_07bc_047f @ 17bc:047f

void __cdecl16far
fn_07bc_047f(undefined2 param_1,int param_2,uint param_3,undefined2 param_4,undefined2 param_5)

{
  char *pcVar1;
  uint uVar2;
  char cVar3;
  undefined1 local_fa [14];
  uint local_ec;
  undefined2 local_ea;
  int local_e8;
  undefined2 local_e6;
  undefined2 local_e4;
  uint local_4;
  
  if (param_2 == 0) {
    cVar3 = '\x03';
  }
  else {
    cVar3 = *(char *)((int)g_7fb2 +
                      *(int *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 9 + param_2 * 0x10) * 0xd + 7);
  }
  if (cVar3 != -1) {
    fn_0f28_032c(local_fa);
    fn_0f28_035f(local_fa);
    local_ec = param_3;
    local_ea = param_1;
    local_e8 = param_2;
    local_e6 = param_4;
    local_e4 = param_5;
    uVar2 = fn_2315_0018(*(undefined2 *)((int)local_fa._0_4_ + -2));
    pcVar1 = (char *)0x3315;
    uVar2 = param_3 & uVar2;
    while (uVar2 != 0) {
      local_4 = fn_0f28_04a0(pcVar1,local_fa);
      pcVar1 = (char *)s_Damage_inflicted_was__d_3e2d_1f22 + 6;
      uVar2 = local_4;
    }
  }
  return;
}

