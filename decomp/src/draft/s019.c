//// fn_0fbe_004c @ 1fbe:004c

undefined2 __cdecl16far fn_0fbe_004c(void)

{
  return 0;
}


//// fn_0fbe_0053 @ 1fbe:0053

void __cdecl16far fn_0fbe_0053(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  fn_0845_0636(*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c));
  return;
}


//// fn_0fbe_007f @ 1fbe:007f

undefined2 __cdecl16far fn_0fbe_007f(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  iVar1 = *(int *)(iVar3 + (*(int *)(iVar3 + 0xc) + 2) * 2 + 0x2c);
  uVar2 = *(undefined2 *)(iVar3 + (*(int *)(iVar3 + 0xc) + 1) * 2 + 0x2c);
  uVar4 = *(undefined2 *)(iVar3 + *(int *)(iVar3 + 0xc) * 2 + 0x2c);
  if ((*(byte *)(iVar1 + 0x531e) & 4) != 0) {
    fn_0845_155d(uVar4);
  }
  fn_130a_0360(uVar4,uVar2,iVar1);
  return 1;
}


//// fn_0fbe_00dd @ 1fbe:00dd

int __cdecl16far fn_0fbe_00dd(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  return (int)*(char *)(*(int *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c) * 10 +
                        (*(uint *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c) & 3) + -0x7dfd);
}


//// fn_0fbe_0110 @ 1fbe:0110

undefined1 __cdecl16far fn_0fbe_0110(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  return *(undefined1 *)
          (*(char *)(*(int *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c) * 10 +
                     (*(uint *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c) & 3) + -0x7dfd) +
          0x531e);
}


//// fn_0fbe_014b @ 1fbe:014b

undefined2 __cdecl16far fn_0fbe_014b(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  fn_0845_15d9(*(undefined2 *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c));
  return 1;
}


//// fn_0fbe_0168 @ 1fbe:0168

/* WARNING: Instruction at (ram,0x00018a28) overlaps instruction at (ram,0x00018a26)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char * __cdecl16far fn_0fbe_0168(char *param_1,char *param_2,char *param_3,int param_4,int param_5)

{
  int *piVar1;
  char *pcVar2;
  char *pcVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  long lVar6;
  long lVar7;
  code *pcVar8;
  undefined4 uVar9;
  char **ppcVar10;
  char cVar11;
  int iVar12;
  char *pcVar13;
  undefined4 in_EAX;
  byte in_CL;
  uint uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int unaff_BP;
  undefined2 *puVar18;
  char *unaff_SI;
  undefined2 *puVar19;
  char *unaff_DI;
  undefined2 uVar20;
  char *unaff_SS;
  bool bVar21;
  undefined1 *puVar22;
  int *in_stack_00000002;
  char *pcStack_a;
  char *in_stack_0000fff8;
  char *in_stack_0000fffa;
  byte bStack_4;
  undefined1 uStack_3;
  
  ppcVar10 = (char **)CONCAT11(uStack_3,bStack_4);
  pcVar13 = (char *)(*(int *)(param_1 + 0xc) * 2);
  uVar16 = *(uint *)(param_1 + *(int *)(param_1 + 0xc) * 2 + 0x2c);
  if ((5 < (int)uVar16) && ((int)uVar16 < 10)) {
    uVar16 = (uVar16 - 6) - g_7fdf & 3;
  }
  if (0xd < uVar16) {
    return (char *)0x1;
  }
  switch(uVar16) {
  case 0:
    *(uint *)(unaff_DI + 2) =
         *(int *)(unaff_DI + 2) +
         (CONCAT11((char)((uint)pcVar13 >> 8),*(undefined1 *)0x9a4e) & 0xc4ff);
    pcVar13 = unaff_DI + 4;
    while( true ) {
      pcStack_a = (char *)((ulong)g_4ea0 >> 0x10);
      iVar12 = fn_15a7_00b0();
      if (iVar12 != 0 || uVar16 != 0) break;
      if (pcVar13 != (char *)0x0) {
        fn_15a7_043c();
      }
      if (2 < (int)(pcVar13 + 1)) {
        pcStack_a = (char *)0x25a7;
        fn_15a7_0004();
      }
      fn_15a7_0501();
      pcVar13 = pcVar13 + 1;
    }
    bStack_4 = (byte)(unaff_SI + 4);
    uStack_3 = (undefined1)((uint)(unaff_SI + 4) >> 8);
    pcStack_a = param_2;
    fn_2279_025b();
    return (char *)(CONCAT13(uStack_3,CONCAT12(bStack_4,iVar12)) >> 0x10);
  case 1:
    exit();
    pcStack_a = (char *)0x167;
    pcVar13 = (char *)fn_0000_0231();
    return pcVar13;
  case 2:
    *unaff_DI = *unaff_DI + '\x01';
    uVar9 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + 6) + 0x21);
    uVar20 = (undefined2)((ulong)uVar9 >> 0x10);
    iVar15 = (int)uVar9;
    iVar12 = *(int *)(iVar15 + 0x44);
    if ((*(uint *)(iVar15 + 0x3e) & 0x10) == 0) {
      uVar20 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 6) >> 0x10);
      iVar17 = (int)*(undefined4 *)(unaff_BP + 6);
      iVar15 = (int)*(char *)(iVar17 + 0x26);
      cVar11 = *(char *)(iVar17 + 0x26) + '\x01';
      *(char *)(iVar17 + 0x26) = cVar11;
      if (iVar12 <= cVar11) {
        *(undefined1 *)(iVar17 + 0x26) = 0;
      }
    }
    else {
      iVar15 = fn_0845_0636();
      iVar15 = iVar15 + -1;
    }
    uVar9 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + 6) + 0x21);
    uVar16 = *(uint *)((int)uVar9 + (iVar15 + 2) * 2 + 0x42);
    if ((uVar16 & 0xc000) == 0) {
      if ((uVar16 & 0x2000) == 0) {
        iVar12 = fn_1aff_02d2();
        if (1 < iVar12) {
          return (char *)0x0;
        }
        if (uVar16 == 1) {
          fn_17d6_0006();
          pcStack_a = (char *)s_Cmd_Animate_Wall__Too_many_anim_f_3e2d_27af + 0x27;
          ovr_2d28_0034();
          pcVar13 = (char *)0x0;
          do {
            if ((*(uint *)((int)(undefined4 *)&g_362a + (int)pcVar13 * 0x82 + 3) & 1) != 0) {
              pcStack_a = (char *)0xeeeb;
              pcStack_a = (char *)ovr_2d46_0048();
              if (pcStack_a != (char *)0x0) {
                fn_07bc_0272();
              }
              pcStack_a = pcVar13;
              fn_070c_07f5();
            }
            pcVar13 = pcVar13 + 1;
          } while ((int)pcVar13 < 4);
        }
        else if (uVar16 == 3) {
          *(undefined2 *)(unaff_BP + -6) = (undefined1 *)&g_3803;
          *(undefined2 *)(unaff_BP + -8) = 0x15fa;
          iVar12 = 0;
          do {
            iVar15 = fn_1aff_02d2();
            if (iVar15 < 7) {
              pcStack_a = (char *)0xee8b;
              fn_0d6c_0995();
            }
            iVar12 = iVar12 + 1;
            *(int *)(unaff_BP + -8) = *(int *)(unaff_BP + -8) + 0x2e;
          } while (iVar12 < 0x1e);
          fn_0845_06f8();
          pcStack_a = (char *)0xeeaa;
          fn_0845_01c4();
        }
        else {
          if (uVar16 != 4) {
            return (char *)0x0;
          }
          ovr_2da0_002a();
        }
      }
    }
    else {
      iVar12 = fn_1aff_02d2();
      if (1 < iVar12) {
        *(uint *)(unaff_BP + -4) = (uint)((uVar16 & 0x4000) == 0);
        pcStack_a = (char *)0xedcf;
        iVar12 = fn_07bc_012d();
        if (iVar12 != 0) {
          pcStack_a = (char *)0xc;
          iVar12 = fn_0b6b_032f();
          if (iVar12 == 0) {
            fn_07bc_044c();
          }
        }
      }
    }
    uVar20 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 6) >> 0x10);
    iVar12 = (int)*(undefined4 *)(unaff_BP + 6);
    if (*(char *)(iVar12 + 0x25) != -1) {
      pcVar2 = (char *)(iVar12 + 0x25);
      *pcVar2 = *pcVar2 + -1;
    }
                    /* WARNING: Subroutine does not return */
    fn_1aff_0420();
  case 3:
    pcStack_a = in_stack_0000fff8;
    while( true ) {
      ovr_2dfd_002a();
      pcStack_a = (char *)0x0;
      fn_1dbc_0004();
      do {
      } while (g_3850 != 0);
      pcStack_a = pcStack_a + 1;
      if (0x18 < (int)pcStack_a) break;
      g_3850 = 7;
      pcStack_a = (char *)(*(int *)(param_1 + 0x20) + -3);
      fn_1dbc_0004();
      pcStack_a = (char *)0x0;
    }
    ovr_2dfd_0025();
    fn_2148_0173();
    pcStack_a = (char *)0x315f;
    fn_2279_025b();
    fn_07bc_044c();
    fn_07bc_044c();
    fn_0845_0acf();
    uVar20 = fn_07bc_012d();
    ((undefined2 *)&g_7fe6)[(int)unaff_SI] = uVar20;
    fn_1ebc_00fe();
    fn_0c59_0055();
    return (char *)0x1;
  case 5:
    do {
      bStack_4 = 0xc;
      pcStack_a = (char *)0xc196;
      iVar12 = fn_0845_0636();
      pcVar13 = (char *)(iVar12 + 6);
      iVar12 = 1;
      pcRam0000010f = pcVar13;
      while( true ) {
        do {
          iVar15 = iVar12;
          unaff_SI = unaff_SI + 1;
          iVar12 = iVar15 + 0x82;
          if (3 < (int)unaff_SI) {
            return pcVar13;
          }
        } while ((((*(uint *)(ulong)CONCAT12(bStack_4,iVar12) & 1) == 0) ||
                 ((*(uint *)(ulong)CONCAT12(bStack_4,iVar12) & 8) != 0)) ||
                (uVar16 = (uint)bStack_4, '\x01' < *(char *)(iVar15 + 0x92)));
        if (*(char *)(iVar15 + 0x92) == '\x01') break;
        piVar1 = (int *)(iVar15 + 0xd0);
        iVar17 = *piVar1;
        *piVar1 = *piVar1 + -1;
        if ((*piVar1 == 0 || SBORROW2(iVar17,1) != *piVar1 < 0) && (param_1 == (char *)0x0)) {
          *(undefined1 *)(iVar15 + 0x92) = 1;
          fn_0a21_022b();
          bStack_4 = 1;
          pcStack_a = (char *)s_PLAYFLD_CPS_3e2d_1a19 + 8;
          pcVar13 = (char *)fn_0bbc_06d1();
          iVar12 = 0;
        }
      }
      *(undefined1 *)(iVar15 + 0x92) = 0;
      fn_0a21_022b();
    } while( true );
  case 6:
    return pcVar13;
  case 7:
    uVar20 = (undefined2)(CONCAT13(uStack_3,CONCAT12(bStack_4,pcVar13)) >> 0x10);
    pcVar13[0x12] = '\x01';
    *(long *)(pcVar13 + 4) = (long)(int)param_2;
    lVar6 = **(long **)(pcVar13 + 0xe);
    uVar20 = (undefined2)(CONCAT13(uStack_3,CONCAT12(bStack_4,pcVar13)) >> 0x10);
    lVar7 = *(long *)(pcVar13 + 4);
    *(char **)(pcVar13 + 8) = (char *)(lVar6 + lVar7);
    return (char *)(char *)(lVar6 + lVar7);
  case 8:
    if ((int)uVar16 < 0 || (uVar16 & 0x7fff) == 0) {
      fn_0d6c_0004();
    }
    pcStack_a = param_1;
    iVar12 = fn_0d6c_059d();
    if (iVar12 == 0) {
      pcStack_a = param_1;
      pcVar13 = (char *)fn_0d6c_0742();
    }
    else {
      pcStack_a = (char *)0xeb45;
      iVar12 = fn_0845_0636();
      cVar11 = *(char *)((int)(undefined2 *)&g_247f + iVar12 + 1);
      param_1[0x15] = cVar11;
      pcVar13 = (char *)CONCAT11(cVar11 >> 7,param_1[0x15]);
      param_1[0x17] = param_1[0x17] + param_1[0x15];
      param_1[0x17] = param_1[0x17] & 6;
    }
    return pcVar13;
  case 9:
    (&stack0x0644)[(int)unaff_DI] = (&stack0x0644)[(int)unaff_DI] | in_CL;
    return pcVar13;
  case 10:
    do {
      if ((int)pcStack_a < (int)param_2) {
        iVar12 = -((int)pcStack_a - (int)param_2);
      }
      else {
        iVar12 = (int)pcStack_a - (int)param_2;
      }
      if (unaff_BP + iVar12 < (int)ppcVar10) {
        in_stack_0000fffa = unaff_SI;
      }
      do {
        unaff_SI = unaff_SI + 1;
        if (3 < (int)unaff_SI) {
          return in_stack_0000fffa;
        }
      } while (((*(uint *)((int)(undefined4 *)&g_362a + (int)unaff_SI * 0x82 + 3) & 1) == 0)
              || (*(int *)((int)unaff_SI * 0x82 + 0x3666) < 1));
      ppcVar10 = &pcStack_a;
      pcStack_a = unaff_SI;
      fn_070c_0201();
      in_stack_0000fffa = unaff_SS;
      if ((int)&stack0xfff8 < (int)unaff_DI) {
        unaff_BP = -((int)&stack0xfff8 - (int)unaff_DI);
      }
      else {
        unaff_BP = (int)&stack0xfff8 - (int)unaff_DI;
      }
    } while( true );
  case 0xb:
    g_ab1c = (char *)CONCAT22((int)((ulong)in_EAX >> 0x10),param_3);
    return param_3;
  case 0xc:
    iVar12 = 0x3e2e;
    while( true ) {
      puVar19 = (undefined2 *)0x0;
      puVar18 = (undefined2 *)0x0;
      uVar14 = uVar16;
      if (0x1000 < uVar16) {
        uVar14 = 0x1000;
      }
      for (iVar15 = uVar14 << 3; iVar15 != 0; iVar15 = iVar15 + -1) {
        puVar5 = puVar19;
        puVar19 = puVar19 + 1;
        puVar4 = puVar18;
        puVar18 = puVar18 + 1;
        *puVar5 = *puVar4;
      }
      bVar21 = uVar16 < 0x1000;
      uVar16 = uVar16 - 0x1000;
      if (bVar21 || uVar16 == 0) break;
      param_2 = param_2 + 0x1000;
      iVar12 = iVar12 + 0x1000;
    }
    farfree();
    return (char *)0x4;
  case 0xd:
    bVar21 = false;
    pcVar8 = (code *)swi(0x21);
    pcVar13 = (char *)(*pcVar8)();
    if (bVar21) {
      pcVar13 = (char *)__IOERROR();
    }
    else {
      *(uint *)((int)pcVar13 * 2 + 0x3d84) = (uint)param_3 & 0xb8ff | 0x8000;
    }
    return pcVar13;
  }
  if ((char *)0x1fff < unaff_SI + (int)(pcVar13 + 3)) {
    pcVar13 = (char *)fn_0000_0569();
    return pcVar13;
  }
  pcStack_a = (char *)malloc();
  if (pcStack_a != (char *)0x0 || uVar16 != 0) {
    in_stack_00000002[1] = uVar16;
    *(char **)CONCAT22(param_1,in_stack_00000002) = pcStack_a;
    pcVar3 = pcStack_a + 0xf;
    pcStack_a = (char *)((uint)pcVar3 & 0xfff0);
    bStack_4 = (byte)param_5;
    uStack_3 = (undefined1)((uint)param_5 >> 8);
    if ((param_4 == 0 && param_5 == 0) ||
       (piVar1 = (int *)CONCAT13(uStack_3,CONCAT12(bStack_4,param_4)),
       *piVar1 == 0 && *(int *)(param_4 + 2) == 0)) {
      *(undefined1 *)((ulong)CONCAT22(uVar16,pcVar3) & 0xfffffff0) = 0;
      pcStack_a = pcStack_a + 1;
    }
    else {
      while ((piVar1 = (int *)CONCAT13(uStack_3,CONCAT12(bStack_4,param_4)),
             *piVar1 != 0 || *(int *)(param_4 + 2) != 0 && (**(char **)piVar1 != '\0'))) {
        piVar1 = (int *)CONCAT13(uStack_3,CONCAT12(bStack_4,param_4));
        bStack_4 = (byte)*(undefined2 *)(param_4 + 2);
        uStack_3 = (undefined1)((uint)*(undefined2 *)(param_4 + 2) >> 8);
        param_4 = *piVar1;
        puVar22 = (undefined1 *)stpcpy();
        uVar16 = (uint)((ulong)puVar22 >> 0x10);
        *puVar22 = 0;
        pcStack_a = (undefined1 *)puVar22 + 1;
      }
    }
    *(char *)CONCAT22(uVar16,pcStack_a) = '\0';
    pcVar3 = pcStack_a + 1;
    if (param_2 != (char *)0x0 || param_3 != (char *)0x0) {
      pcVar2 = (char *)CONCAT22(uVar16,pcStack_a + 1);
      pcVar2[0] = '\x01';
      pcVar2[1] = '\0';
      pcStack_a = pcStack_a + 3;
      puVar22 = (undefined1 *)stpcpy();
      *puVar22 = 0;
      pcVar3 = (undefined1 *)puVar22 + 1;
    }
    pcStack_a = pcVar3;
    return pcStack_a + -(int)(unaff_SI + (int)(pcVar13 + 3));
  }
  pcVar13 = (char *)fn_0000_0569();
  return pcVar13;
}


//// fn_0fbe_0273 @ 1fbe:0273

undefined2 __cdecl16far fn_0fbe_0273(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  fn_0845_0bb6(*(undefined2 *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c));
  return 1;
}


//// fn_0fbe_0290 @ 1fbe:0290

undefined2 __cdecl16far fn_0fbe_0290(undefined4 param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  uVar2 = *(uint *)(iVar3 + *(int *)(iVar3 + 0xc) * 2 + 0x2c);
  if (*(int *)(iVar3 + (*(int *)(iVar3 + 0xc) + 1) * 2 + 0x2c) == 0) {
    puVar1 = (uint *)((uVar2 >> 4) * 2 + -0x7fb4);
    *puVar1 = *puVar1 & ~(1 << ((byte)uVar2 & 0xf));
  }
  else {
    puVar1 = (uint *)((uVar2 >> 4) * 2 + -0x7fb4);
    *puVar1 = *puVar1 | 1 << ((byte)uVar2 & 0xf);
  }
  return 1;
}


//// fn_0fbe_02e8 @ 1fbe:02e8

undefined2 __cdecl16far fn_0fbe_02e8(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = *(int *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c);
  if (iVar1 < 0) {
    uVar2 = 0;
  }
  else if ((*(uint *)((iVar1 >> 4) * 2 + -0x7fb4) & 1 << ((byte)iVar1 & 0xf)) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


//// fn_0fbe_0322 @ 1fbe:0322

undefined2 __cdecl16far fn_0fbe_0322(void)

{
  undefined2 uVar1;
  
  uVar1 = fn_0845_0ac7();
  fn_07bc_044c(uVar1);
  fn_0845_0acf(0);
  return uVar1;
}


//// fn_0fbe_0341 @ 1fbe:0341

void __cdecl16far fn_0fbe_0341(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  fn_07bc_012d(0x1fbe,*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 2) * 2 + 0x2c));
  return;
}


//// fn_0fbe_037f @ 1fbe:037f

undefined2 __cdecl16far fn_0fbe_037f(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  fn_130a_0052(*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 2) * 2 + 0x2c),
                *(undefined1 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 3) * 2 + 0x2c),
                *(undefined1 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 4) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 5) * 2 + 0x2c));
  return 1;
}


//// fn_0fbe_03fc @ 1fbe:03fc

int __cdecl16far fn_0fbe_03fc(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  iVar1 = fn_07bc_012d(0x1fbe,*(undefined2 *)(iVar2 + *(int *)(iVar2 + 0xc) * 2 + 0x2c),
                        *(undefined2 *)(iVar2 + (*(int *)(iVar2 + 0xc) + 1) * 2 + 0x2c),
                        *(undefined2 *)(iVar2 + (*(int *)(iVar2 + 0xc) + 2) * 2 + 0x2c));
  if (iVar1 != -1) {
    fn_130a_0052(iVar1,*(undefined2 *)(iVar2 + (*(int *)(iVar2 + 0xc) + 3) * 2 + 0x2c),
                  *(undefined2 *)(iVar2 + (*(int *)(iVar2 + 0xc) + 4) * 2 + 0x2c),
                  *(undefined2 *)(iVar2 + (*(int *)(iVar2 + 0xc) + 5) * 2 + 0x2c),
                  *(undefined2 *)(iVar2 + (*(int *)(iVar2 + 0xc) + 6) * 2 + 0x2c),
                  *(undefined2 *)(iVar2 + (*(int *)(iVar2 + 0xc) + 7) * 2 + 0x2c));
  }
  return iVar1;
}


//// fn_0fbe_04a8 @ 1fbe:04a8

/* WARNING: Instruction at (ram,0x00022667) overlaps instruction at (ram,0x00022666)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char ** __cdecl16far
fn_0fbe_04a8(char **param_1,char **param_2,char **param_3,int param_4,char **param_5,ulong param_6)

{
  undefined1 *puVar1;
  byte *pbVar2;
  uint *puVar3;
  undefined1 *puVar4;
  char *pcVar5;
  char **ppcVar6;
  byte bVar7;
  byte bVar8;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  code *pcVar12;
  byte bVar13;
  char cVar14;
  char cVar15;
  code cVar16;
  int iVar17;
  code *pcVar18;
  char **ppcVar19;
  char **ppcVar20;
  uint *puVar21;
  char **ppcVar22;
  char **ppcVar23;
  char **ppcVar24;
  code *pcVar25;
  undefined3 uVar26;
  char **in_CX;
  uint uVar27;
  code *pcVar28;
  undefined4 in_EDX;
  long lVar29;
  ulong uVar30;
  char **ppcVar31;
  char **ppcVar32;
  int *piVar33;
  uint uVar34;
  int iVar35;
  uint unaff_BP;
  char **unaff_SI;
  char *pcVar36;
  undefined1 *puVar37;
  char **unaff_DI;
  uint uVar38;
  undefined2 uVar39;
  char **ppcVar40;
  undefined2 uVar41;
  int iVar42;
  char **ppcVar43;
  undefined2 uVar44;
  char **unaff_SS;
  undefined2 in_FS;
  undefined1 uVar45;
  bool bVar46;
  char **in_stack_00000002;
  undefined1 auStack_750 [2];
  int aiStack_74e [891];
  char **ppcStack_58;
  int iStack_56;
  undefined2 uStack_54;
  int iStack_52;
  undefined2 uStack_50;
  uint uStack_4e;
  uint uStack_4c;
  int iStack_46;
  code *pcStack_42;
  char **ppcStack_40;
  char **ppcStack_3e;
  char **ppcStack_3c;
  char **ppcStack_3a;
  char **ppcStack_38;
  undefined4 uStack_36;
  char *pcStack_32;
  int in_stack_0000ffd0;
  char *pcStack_2e;
  char **in_stack_0000ffd4;
  undefined2 uStack_26;
  int iStack_22;
  undefined1 uStack_20;
  undefined1 uStack_1f;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  int iStack_1a;
  char **ppcStack_18;
  char *pcVar47;
  char **in_stack_0000ffee;
  char **in_stack_0000fff2;
  int in_stack_0000fff4;
  undefined2 uStack_8;
  char **local_6;
  undefined1 local_4;
  char cStack_3;
  
  lVar29 = CONCAT22(param_5,param_4);
  ppcVar20 = (char **)0x3e2d;
  puVar37 = &stack0xfffe;
  uVar39 = (undefined2)((ulong)in_EDX >> 0x10);
  if ((int)param_1[(int)(param_1[6] + 0x16)] < 1) {
    return (char **)0x0;
  }
  iVar17 = (int)param_1[(int)(param_1[6] + 0x16)] * 0x10;
  pcVar18 = (code *)(iVar17 + 0x1cfd);
  uStack_8._0_1_ = (code)0x3;
  uStack_8._1_1_ = 0x38;
  puVar1 = (undefined1 *)&g_3803;
  ppcVar31 = (char **)CONCAT22(uVar39,g_7fb2._2_2_);
  local_4 = SUB21(g_7fb2._2_2_,0);
  cStack_3 = (char)((uint)g_7fb2._2_2_ >> 8);
  local_6 = (char **)((int)g_7fb2 +
                     *(int *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 9 + iVar17) * 0xd);
  ppcVar19 = (char **)((int)(param_1[6] + 1) * 2);
  uVar30 = ZEXT24(ppcVar19);
  pcVar47 = (param_1 + (int)(param_1[6] + 1))[0x16];
  if ((char *)0x11 < pcVar47) {
    ppcVar20 = (char **)fn_0fbe_05cf();
    return ppcVar20;
  }
  ppcVar32 = (char **)((int)pcVar47 * 2);
  bVar13 = (byte)ppcVar19;
  ppcVar40 = g_7fb2._2_2_;
  switch(pcVar47) {
  default:
    if ((int)pcVar47 < 0 || ppcVar32 == (char **)0x0) {
      if ((int)unaff_SI < 0) {
        unaff_SI = unaff_SI + *(int *)((int)ppcVar32[0xe] * 0x10 + 7999) * 4;
      }
      uStack_8._0_1_ = SUB21(unaff_SI,0);
      uStack_8._1_1_ = (undefined1)((uint)unaff_SI >> 8);
      ppcVar32 = (char **)param_1[0xe];
    }
    iVar17 = *(int *)((int)ppcVar32 * 0x10 + 0x1f3b);
    ppcVar19 = (char **)(iVar17 * 8);
    uVar30 = ZEXT24(ppcVar19);
    unaff_SI = unaff_SI + iVar17 * 4;
    ppcVar31 = (char **)ZEXT24((code *)((int)unaff_SI + (int)(param_1[0x11] + -1)));
    pcVar18 = (code *)param_1[0x10];
    if ((int)pcVar18 < 0) {
      pcVar18 = pcVar18 + *(int *)((int)param_1[0xe] * 0x10 + 0x1f41);
    }
    unaff_DI = (char **)(pcVar18 + *(int *)((int)param_1[0xe] * 0x10 + 0x1f3d));
    ppcVar22 = (char **)((int)unaff_DI + (int)(param_1[0x12] + -1));
    uVar34 = in_stack_0000fff4 - 1;
    if (5 < uVar34) {
      return ppcVar19;
    }
    uVar45 = (int)uVar34 < 0;
    ppcVar32 = (char **)(uVar34 * 2);
    switch(uVar34) {
    case 0:
      return ppcVar19;
    case 1:
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + (char)ppcVar19;
LAB_2809_028d:
      iStack_22 = 0;
      uStack_20 = 0;
      uStack_1f = 0;
      break;
    case 2:
switchD_2000_4eaa_caseD_10:
      ppcVar40 = (char **)ppcVar31;
      in_CX = (char **)((uint)ppcVar22 & 0xff);
      goto switchD_2000_00eb_caseD_3;
    case 3:
switchD_2000_4eaa_caseD_18:
      return (char **)(((uint)CONCAT31((int3)(uVar30 >> 8),
                                       ((char)uVar30 - (char)*(code *)unaff_DI) - uVar45) & 0xff05)
                      + 0xa8c);
    case 4:
      fn_2279_025b();
      return (char **)((int)(undefined2 *)&g_0000 + 1);
    case 5:
switchD_2000_4eaa_caseD_1b:
      return ppcVar19;
    }
switchD_2000_00eb_caseD_5:
    uVar44 = 0x2000;
    while( true ) {
      uVar39 = uVar44;
      in_stack_0000fff2 = (char **)s_Borland_C_____Copyright_1991_Bor_3e2d_0004;
      fn_1809_084d();
      if (CONCAT22(uVar39,0x83e4) == 0) break;
      iStack_1a = 0;
      do {
        ppcVar31 = (char **)(ulong)(uint)((int)&ppcStack_58 + iStack_1a);
        fn_1809_084d();
        pcVar47 = (char *)((int)&ppcStack_58 + iStack_1a);
        iStack_1a = iStack_1a + 1;
      } while (*pcVar47 != '\0');
      uVar44 = 0x2981;
      iVar17 = fn_1981_01af();
      if (iVar17 != -1) {
        iVar17 = iVar17 * 0x14;
        uVar41 = (undefined2)(CONCAT13(0x37,CONCAT12(0xfc,iVar17)) >> 0x10);
        if (((*(uint *)(iVar17 + 0x12) & 0x1000) != 0) &&
           ((char *)(uint)*(byte *)(iVar17 + 0x10) == unaff_DI[6])) {
          ppcVar31 = (char **)(CONCAT22(uVar39,0x8348) + *(long *)((int)unaff_DI[6] * 0x14 + 0xc));
          uVar39 = (undefined2)(CONCAT13(0x37,CONCAT12(0xfc,iVar17)) >> 0x10);
          *(undefined4 *)(iVar17 + 0xc) = ppcVar31;
          if (CONCAT13(uStack_1f,CONCAT12(uStack_20,iStack_22)) != 0) {
            uVar41 = (undefined2)(CONCAT13(uStack_1f,CONCAT12(uStack_20,iStack_22)) >> 0x10);
            *(long *)(iStack_22 + 4) = *(long *)(iVar17 + 0xc) - *(long *)(iStack_22 + 0xc);
          }
          uStack_20 = 0xfc;
          uStack_1f = 0x37;
          iStack_22 = iVar17;
        }
      }
    }
    ppcVar23 = unaff_SS;
    ppcVar43 = (char **)0x0;
    if (CONCAT13(uStack_1f,CONCAT12(uStack_20,iStack_22)) != 0) {
      ppcVar23 = (char **)fn_1809_120c();
      in_stack_0000fff2 = (char **)ppcVar31;
      uVar44 = (undefined2)(CONCAT13(uStack_1f,CONCAT12(uStack_20,iStack_22)) >> 0x10);
      *(long *)(iStack_22 + 4) =
           (long)CONCAT22(in_stack_0000fff2,ppcVar23) - *(long *)(iStack_22 + 0xc);
      ppcVar43 = unaff_DI;
    }
    puVar3 = (uint *)((int)unaff_DI[6] * 0x14 + 0x12);
    *puVar3 = *puVar3 | 0x100;
LAB_2809_0396:
    ppcVar20 = (char **)ppcVar31;
    *(undefined4 *)(ppcVar43 + 4) = *(undefined4 *)(ppcVar23 + 4);
    fn_1981_031f();
    *(undefined2 *)0x844d = unaff_SI;
    *(undefined4 *)0x8451 = *(undefined4 *)unaff_SS;
    *(undefined4 *)0x8449 = *(undefined4 *)(unaff_SS + 6);
    fn_1809_0e76();
    fn_1809_1502();
    if (unaff_SI != (char **)0xffff) {
      iVar17 = fn_1981_02c0();
      *(char *)(iVar17 + 0x11) = *(char *)(iVar17 + 0x11) + '\x01';
      fn_1981_031f();
    }
    g_abde = g_abde + -1;
    return unaff_DI;
  case (char *)0x1:
    out(0,bVar13);
                    /* WARNING: Does not return */
    pcVar12 = (code *)invalidInstructionException();
    (*pcVar12)();
  case (char *)0x2:
    do {
      if ((*(ulong *)(ppcVar32 + 6) < g_384c - *(long *)(local_6 + 4)) &&
         (uVar39 = CONCAT11(cStack_3,local_4), *(ulong *)(ppcVar32 + 10) <= *(ulong *)(ppcVar32 + 8)
         )) {
        ppcVar32[0x11] = (char *)0x0;
        memset();
      }
      do {
        unaff_DI = (char **)((int)unaff_DI + 1);
        if (3 < (int)unaff_DI) {
          if ((((g_29b9 != 0) || (g_29e1 != 0)) || (g_2a09 != 0)) ||
             (g_2a31 != 0)) {
            if (g_3749 == 4) {
              iVar17 = fn_1b79_0367();
              uVar34 = (int)((g_2a4f - (ulong)(iVar17 + 1)) / g_2a53) + 1;
              if (g_2a7d <= uVar34) {
                uVar34 = 0;
              }
            }
            else {
              uVar34 = (int)*(char *)((int)g_2952 + 0xf) + 1;
              if (g_2a7d <= uVar34) {
                uVar34 = 0;
              }
              iVar17 = 0;
            }
            if ((*(char *)((int)g_2a79 + uVar34) == '\0') || (iVar17 == -1)) {
              if (iVar17 == -1) {
                g_2984 = g_2984 + 1;
                if (1 < g_2984 - g_2988) {
                  fn_1b79_0284();
                  *(undefined1 *)((int)g_2952 + 0xf) = 0;
                  uStack_8._0_1_ = SUB41((ulong)g_2a4f >> 0x10,0);
                  uStack_8._1_1_ = (undefined1)((ulong)g_2a4f >> 0x18);
                  fn_1b79_0261();
                  fn_1b79_027f();
                  g_298c = g_298c + 1;
                }
              }
              else {
                g_2988 = g_2984;
              }
              fn_16cf_05d0();
            }
          }
          g_297c = 0;
          return (char **)((int)(undefined2 *)&g_0000 + 1);
        }
        ppcVar32 = (char **)((int)unaff_DI * 0x28 + 0x2997);
        local_4 = 0x2d;
        cStack_3 = '>';
        param_2 = (char **)(CONCAT13(0x3e,CONCAT12(0x2d,ppcVar32)) >> 0x10);
        local_6 = ppcVar32;
      } while (((undefined2 *)&g_29b9)[(int)unaff_DI * 0x14] == 0);
    } while( true );
  case (char *)0x3:
switchD_2000_00eb_caseD_3:
    *(code *)((int)ppcVar32 + (int)unaff_DI) =
         (code)((byte)*(code *)((int)ppcVar32 + (int)unaff_DI) | (byte)((uint)in_CX >> 8));
    *(byte *)(ppcVar32 + 4) = (byte)*(code *)(ppcVar32 + 4) | (byte)ppcVar19;
    ((code *)((int)ppcVar32 + (int)unaff_DI))[8] =
         (code)((byte)((code *)((int)ppcVar32 + (int)unaff_DI))[8] | (byte)ppcVar32);
    *(byte *)(unaff_DI + 0x3984) = (byte)*(code *)(unaff_DI + 0x3984) | (byte)in_CX;
    *(code *)((int)unaff_DI + -0x75) =
         (code)((byte)*(code *)((int)unaff_DI + -0x75) | (byte)ppcVar40);
    in(ppcVar40);
    pcVar47 = param_1[(int)(param_1[6] + 0x16)];
    pcVar36 = param_1[(int)(param_1[6] + 1 + 0x16)];
    pcVar9 = param_1[(int)(param_1[6] + 2 + 0x16)];
    uStack_8._0_1_ = SUB21(pcVar9,0);
    uStack_8._1_1_ = (undefined1)((uint)pcVar9 >> 8);
    pcVar10 = param_1[(int)(param_1[6] + 3 + 0x16)];
    if ((int)pcVar9 < (int)pcVar36) {
      iVar17 = -1;
    }
    else {
      iVar17 = 1;
    }
    for (; (char *)(CONCAT11(uStack_8._1_1_,uStack_8._0_1_) + iVar17) != pcVar36;
        pcVar36 = pcVar36 + iVar17) {
      lVar29 = g_384c + (long)(int)pcVar10;
      local_6 = (char **)lVar29;
      local_4 = (undefined1)((ulong)lVar29 >> 0x10);
      cStack_3 = (char)((ulong)lVar29 >> 0x18);
      ovr_2cef_0025();
      ovr_2cef_0020();
      fn_1ebc_0111();
      if ((*(uint *)((int)pcVar47 * 0xb5 + 0x4ef2) & 0x4000) == 0) {
        pcStack_32 = (char *)0x601;
        ovr_2dfd_002a();
      }
      else {
        pcStack_32 = (char *)s_PageArraySize_is_negative__3e2d_2eba + 2;
        uStack_36 = CONCAT22(0x5a0,(char **)uStack_36);
        fn_1dbc_0004();
        pcStack_32 = pcVar36 + -1;
        uStack_36 = *(undefined4 *)((int)(undefined4 *)&g_4ee0 + (int)pcVar47 * 0xb5);
        ppcStack_38 = (char **)0x2dbc;
        ppcStack_3a = (char **)0x5ca;
        ovr_2dfd_002a();
        pcStack_32 = "\x0e\x0e\x0e\x0e\x0e#\x0e\x1c(\x17#%\x13(";
        uStack_36 = CONCAT22(0x5e1,(char **)uStack_36);
        fn_1dbc_0004();
      }
      fn_1ebc_01ec();
      fn_0845_0be0();
    }
    return (char **)((int)(undefined2 *)&g_0000 + 1);
  case (char *)0x4:
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + bVar13;
    *(byte *)(char **)((int)ppcVar32 + (int)unaff_DI) =
         (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_DI) + bVar13;
    *(char **)(&stack0xfffe + (int)unaff_SI) =
         (char *)((int)ppcVar19 + *(int *)(&stack0xfffe + (int)unaff_SI));
    *(char **)((int)ppcVar32 + (int)unaff_SI) =
         (char *)((int)in_CX + (int)*(char **)((int)ppcVar32 + (int)unaff_SI));
    *(char **)((int)ppcVar32 + (int)unaff_DI) =
         (char *)((uint)*(char **)((int)ppcVar32 + (int)unaff_DI) | (uint)in_CX);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case (char *)0x5:
    goto switchD_2000_00eb_caseD_5;
  case (char *)0x6:
    while( true ) {
      ppcVar20 = local_6 + 0x17;
      if (0x1d < (int)puVar1) {
        return (char **)0xffff;
      }
      uVar39 = (undefined2)(CONCAT13(cStack_3,CONCAT12(local_4,ppcVar20)) >> 0x10);
      if ((*(int *)(code *)((int)local_6 + 0x4b) == 0) && (*(code *)(local_6 + 0x21) != (code)0xd))
      break;
      puVar1 = puVar1 + 1;
      local_6 = ppcVar20;
    }
    local_6 = ppcVar20;
    uStack_8 = (code *)puVar1;
    setmem();
    uVar39 = (undefined2)(CONCAT13(cStack_3,CONCAT12(local_4,local_6)) >> 0x10);
    *(code *)(local_6 + 0xb) = uStack_8._0_1_;
    *(code **)(code *)((int)local_6 + 7) = pcVar18;
    *(undefined2 *)(code *)((int)local_6 + 9) = 0;
    *(code *)(local_6 + 0xc) = *(code *)(param_1 + (int)(param_1[6] + 3 + 0x16));
    uVar39 = (undefined2)(CONCAT13(cStack_3,CONCAT12(local_4,local_6)) >> 0x10);
    *(code *)(local_6 + 0x10) = *(code *)(param_1 + (int)(param_1[6] + 4 + 0x16));
    *(undefined1 **)(code *)((int)local_6 + 0x23) = (undefined1 *)&g_3803;
    *(char **)(code *)((int)local_6 + 0x21) =
         (char *)s_TANDY_ADV_3e2d_1b5c + 2 + (int)((int)unaff_SI + 1) * 0x53;
    *(code *)((int)local_6 + 0x17) = (code)((char)*(code *)(local_6 + 0xc) << 1);
    fn_0845_1036();
                    /* WARNING: Subroutine does not return */
    fn_1aff_0420();
  case (char *)0x7:
    pcVar47 = param_1[(int)(param_1[6] + 3 + 0x16)];
    uVar34 = *(uint *)((int)ppcVar32[(int)(ppcVar32[6] + 0x16)] * 10 + -0x7df9);
LAB_1fbe_247c:
    do {
      uVar38 = uVar34;
      if (uVar38 == 0) {
        return (char **)CONCAT11(uStack_8._1_1_,uStack_8._0_1_);
      }
      puVar21 = (uint *)fn_080e_000b();
      uVar34 = *puVar21;
      if ((uVar38 & 0x8000) == 0) goto LAB_1fbe_2397;
    } while (pcVar47 == (char *)0x0);
    local_6 = (char **)((uVar38 & 0x7fff) * 0x2e + 0x15fa);
    local_4 = 3;
    cStack_3 = '8';
    fn_0d6c_0995();
    fn_0845_046c();
    fn_0d6c_0742();
    goto LAB_1fbe_2477;
  case (char *)0x9:
    ppcVar22 = g_2f28;
    ppcVar20 = g_2f2a;
    if ((g_35ee != '\x02') && (g_2f0a == 0)) {
      ppcVar22 = in_CX;
      if (g_3630 != 0) {
        ppcVar22 = (char **)((((int)in_CX - g_3634) / g_3630) * g_3630 +
                            g_3634);
        ppcVar31 = (char **)ZEXT24(g_7fb2._2_2_);
      }
      if (g_3632 != 0) {
        ppcVar31 = (char **)(ulong)(uint)((((int)(char **)ppcVar31 - g_3636) / g_3632)
                                          * g_3632 + g_3636);
      }
      g_2f0e = (char **)ppcVar31;
      g_2f0c = ppcVar22;
      if (((g_35ee != '\x02') && (g_35ee != '\0')) && ((g_35e6 & 0x1000) == 0))
      {
        fn_1c24_0058();
      }
      ppcVar20 = (char **)ppcVar31;
      if ((g_2f16 == 0) && ((g_2f28 != ppcVar22 || (g_2f2a != ppcVar20)))) {
LAB_2c24_0242:
        ppcVar20 = (char **)ppcVar31;
        if ((((g_2f2c & 0xc000) == 0xc000) ||
            (fn_1ebc_000c(), (g_2f2c & 0x8000) != 0)) &&
           (((g_2f2e <= ppcVar22 && (ppcVar22 <= g_2f32)) &&
            ((g_2f30 <= ppcVar20 && (ppcVar20 <= g_2f34)))))) {
          g_2f2c = g_2f2c | 0x4000;
        }
        else {
          fn_1ebc_0053();
        }
      }
    }
    g_2f2a = ppcVar20;
    g_2f28 = ppcVar22;
    return param_1;
  case (char *)0xa:
    if (ppcVar32 != (char **)0x0) {
      ppcVar20 = unaff_DI + 5;
      iVar17 = 0x10;
      do {
        ppcVar31 = ppcVar20;
        ppcVar6 = ppcVar20;
        ppcVar20 = (char **)((int)ppcVar20 + 1);
        *(code *)ppcVar6 = *(code *)ZEXT24((code *)((int)unaff_SI + (uint)(byte)*(code *)ppcVar31));
        iVar17 = iVar17 + -1;
      } while (iVar17 != 0);
    }
    return param_1;
  case (char *)0xb:
  case (char *)0xd:
switchD_2000_4eaa_caseD_3:
    uVar34 = CONCAT11((char)ppcVar31,(char)(uVar30 >> 8));
    uVar30 = (ulong)uVar34;
    if (uVar34 == 0) {
      ppcVar20 = (char **)fn_0fbe_059c();
      return ppcVar20;
    }
LAB_2fd6_01d1:
    if ((param_6 & 0x200000) != 0) {
      param_5 = (char **)((int)param_5 - (int)(uVar30 >> 1));
    }
    uStack_36 = CONCAT22((int)uVar30,(char **)uStack_36);
    ppcVar31 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    ppcStack_3a = (char **)*ppcVar31;
    ppcVar19 = ppcStack_3a;
    if (((param_6 & 0x40000) != 0) &&
       (ppcVar19 = (char **)(ZEXT24(ppcStack_3a) * (ulong)uStack_4c >> 8), ppcVar19 == (char **)0x0)
       ) {
      ppcVar20 = (char **)fn_0fbe_059c();
      return ppcVar20;
    }
    if ((param_6 & 0x200000) != 0) {
      ppcVar31 = (char **)(ulong)((uint)ppcVar19 >> 1);
switchD_2000_4eaa_caseD_b:
      param_4 = param_4 - (int)(char **)ppcVar31;
    }
    uVar39 = uStack_54;
    ppcVar32 = (char **)((int)unaff_SI + 5);
    uVar34 = 0x10;
    if (((uint)pcStack_32 & 4) != 0) {
      uVar34 = (uint)(byte)*(code *)ppcVar32;
      ppcVar32 = unaff_SI + 3;
    }
    if ((param_6 & 0x4000000) != 0) {
      ppcVar32 = (char **)((int)ppcVar32 + uVar34);
    }
    ppcStack_38 = ppcVar19;
    uStack_36._0_2_ = ppcVar19;
    if (((uint)pcStack_32 & 2) == 0) {
      in_stack_0000ffee = (char **)((ulong)*(undefined4 *)&g_35ac >> 0x10);
      fn_232c_000c();
      ppcVar20 = (char **)((ulong)*(undefined4 *)&g_35ac >> 0x10);
      ppcStack_18 = ppcVar32;
      in_stack_0000fff2 = unaff_DI;
    }
    if ((param_6 & 0x20000) == 0) {
      pcVar47 = (char *)((int)param_5 - (int)in_stack_0000ffd4);
    }
    else {
      pcVar47 = pcStack_2e + (-(int)uStack_36._2_2_ - (int)param_5);
    }
    if ((int)pcVar47 < 0) {
      bVar46 = SCARRY2((int)uStack_36._2_2_,(int)pcVar47);
      uStack_36._2_2_ = uStack_36._2_2_ + (int)pcVar47;
      if (uStack_36._2_2_ == (char *)0x0 || bVar46 != (int)uStack_36._2_2_ < 0) {
        ppcVar20 = (char **)fn_0fbe_059c();
        return ppcVar20;
      }
      iStack_46 = -(int)pcVar47;
      do {
        do {
          iStack_56 = 0;
          ppcStack_3c = ppcStack_3a;
          ppcVar31 = in_stack_0000fff2;
          in_stack_0000fff2 = (char **)((int)(undefined2 *)&g_0000 + 1);
          (*(code *)ppcVar31)();
          uStack_50 = uStack_50 + uStack_4e;
        } while ((uStack_50 & 0xff00) == 0);
        LOCK();
        uVar34 = uStack_50 >> 8;
        uStack_50 = uStack_50 & 0xff;
        UNLOCK();
        iVar17 = iStack_46 - uVar34;
        bVar46 = (int)uVar34 <= iStack_46;
        iStack_46 = iVar17;
      } while (iVar17 != 0 && bVar46);
      if (iVar17 < 0) {
        iStack_46 = -iVar17;
        uStack_50 = uStack_50 + iVar17 * -0x100;
      }
      ppcStack_18 = ppcVar20;
      if ((param_6 & 0x20000) == 0) {
        param_5 = in_stack_0000ffd4;
      }
    }
    if ((param_6 & 0x20000) == 0) {
      pcVar47 = pcStack_2e + -(int)param_5;
    }
    else {
      pcVar47 = (char *)((int)param_5 + ((int)uStack_36._2_2_ - (int)in_stack_0000ffd4));
    }
    if ((-1 < (int)pcVar47) && (pcVar47 != (char *)0x0)) {
      if ((pcVar47 < uStack_36._2_2_) && (uStack_36._2_2_ = pcVar47, (param_6 & 0x20000) != 0)) {
        param_5 = in_stack_0000ffd4;
      }
      ppcStack_3e = (char **)0x0;
      if (param_4 < 0) {
        uStack_36._0_2_ = (char **)((int)(char **)uStack_36 + param_4);
        ppcStack_3e = (char **)-param_4;
        if (ppcStack_38 <= ppcStack_3e) goto LAB_2fd6_041c;
        param_4 = 0;
      }
      ppcStack_40 = (char **)0x0;
      ppcVar19 = (char **)(in_stack_0000ffd0 - param_4);
      if ((-1 < (int)ppcVar19) && (ppcVar19 != (char **)0x0)) {
        if (ppcVar19 < (char **)uStack_36) {
          ppcStack_40 = (char **)((int)ppcStack_38 + (-(int)ppcVar19 - (int)ppcStack_3e));
          uStack_36._0_2_ = ppcVar19;
        }
        ppcVar19 = ppcStack_40;
        iStack_52 = 0x140;
        if ((param_6 & 0x20000) != 0) {
          iStack_52 = -0x140;
          param_5 = (char **)((int)param_5 + (int)(uStack_36._2_2_ + -1));
        }
        pcStack_42 = (code *)((int)unaff_DI +
                             *(int *)((int)param_5 * 2 +
                                     (int)*(undefined4 *)
                                           ((char *)s_etainosrlhcdupmtasio_wb_rnsdalmh_3e2d_38b0 +
                                           0x90)) + param_4);
        if ((param_6 & 0x10000) != 0) {
          LOCK();
          ppcStack_40 = ppcStack_3e;
          UNLOCK();
          ppcStack_3e = ppcVar19;
          pcStack_42 = pcStack_42 + (int)((int)(char **)uStack_36 - 1);
        }
        if ((param_6 & 0x40000) != 0) {
          ppcStack_40 = (char **)0x0;
          ppcStack_58 = ppcStack_3e;
          uVar30 = (ulong)CONCAT12((char)((uint)ppcStack_3e >> 8),(int)ppcStack_3e << 8);
          ppcStack_3e = (char **)(char **)(uVar30 / uStack_4c);
          iStack_56 = -(int)(uVar30 % (ulong)uStack_4c);
        }
        ppcVar19 = ppcVar20;
        ppcVar32 = ppcVar20;
        if ((uStack_50 & 0xff00) == 0) goto LAB_2fd6_03be;
        while( true ) {
          ppcVar20 = ppcVar19;
          ppcStack_3c = ppcStack_3a;
          ppcVar32 = (char **)0x14e;
          ppcVar19 = ppcStack_3e;
          (*pcVar18)();
          if (ppcStack_3c != (char **)0x0) {
            pcVar47 = (char *)((int)ppcVar19 + (int)(char **)uStack_36);
            if (pcVar47 != (char *)0x0 &&
                SCARRY2((int)ppcVar19,(int)(char **)uStack_36) == (int)pcVar47 < 0) {
              ppcVar32 = (char **)0x15c;
              (*(code *)in_stack_0000ffee)();
            }
            if (pcVar47 + (int)ppcStack_40 != (char *)0x0) {
              ppcVar31 = ppcVar32;
              ppcVar32 = (char **)0x164;
              (*(code *)ppcVar31)();
            }
          }
          pcStack_42 = pcStack_42 + iStack_52;
          uStack_36._2_2_ = uStack_36._2_2_ + -1;
          if (uStack_36._2_2_ == (char *)0x0) break;
          cVar15 = uStack_50._1_1_ + -1;
          uStack_50 = CONCAT11(cVar15,(undefined1)uStack_50);
          ppcVar19 = ppcStack_18;
          if (cVar15 == '\0') {
LAB_2fd6_03be:
            while (uStack_50 = uStack_50 + uStack_4e, ppcVar19 = ppcVar20, ppcStack_18 = ppcVar20,
                  (uStack_50 & 0xff00) == 0) {
              ppcStack_3c = ppcStack_3a;
              ppcVar31 = ppcVar32;
              ppcVar32 = (char **)0x136;
              (*(code *)ppcVar31)();
            }
          }
        }
      }
    }
LAB_2fd6_041c:
    uStack_8._0_1_ = SUB21(param_3,0);
    uStack_8._1_1_ = (undefined1)((uint)param_3 >> 8);
    fn_226d_004e();
    return param_3;
  case (char *)0xc:
    (&stack0x08c3)[(int)unaff_DI] =
         ((&stack0x08c3)[(int)unaff_DI] - (bVar13 + 0x66)) - (bVar13 < 0x9a);
    return (char **)CONCAT11(3,bVar13 + 0x66);
  case (char *)0xe:
    *(char ***)(code *)((int)ppcVar32 + 0x25) = g_7fb2._2_2_;
    return (char **)0x0;
  case (char *)0xf:
    ppcVar20 = g_7fb2._2_2_;
    if ((((((g_2f2c & 0xc000) == 0xc000) || (fn_1ebc_000c(), (g_2f2c & 0x8000) != 0))
         && (g_2f2e <= in_CX)) && ((in_CX <= g_2f32 && (g_2f30 <= ppcVar20))))
       && (ppcVar20 <= g_2f34)) {
      g_2f2c = g_2f2c | 0x4000;
    }
    else {
      fn_1ebc_0053();
    }
    g_2f28 = in_CX;
    g_2f2a = ppcVar20;
    return param_1;
  case (char *)0x10:
    ppcVar31 = (char **)CONCAT22(uVar39,(char **)((ulong)((long)(int)ppcVar19 *
                                                         (long)(int)g_7fb2._2_2_) >> 0x10));
    g_ad95 = (int)((long)(int)ppcVar19 * (long)(int)g_7fb2._2_2_);
    ppcVar23 = (char **)((int)ppcVar32 + g_ad95 + -1);
    ppcVar24 = (char **)((int)ppcVar32 + (int)unaff_SI);
    pcVar47 = (char *)0x2000;
    ppcVar43 = (char **)0x2e59;
    ppcStack_18 = (char **)0x5070;
    ppcVar22 = in_CX;
    fn_1e59_001d();
    ppcVar40 = param_2;
    in_stack_0000ffee = in_CX;
code_r0x00024e0d:
    cStack_3 = fn_14b3_095d();
    if (cStack_3 == '\0') {
      if (g_ab4d != 0) {
        fn_14b3_0731();
      }
      *(int *)(g_3715 * 0x10 + 0x1f47) = g_ad95;
      *(undefined2 *)(g_3715 * 0x10 + 0x1f49) = g_ad93;
      g_3713 = ppcVar23;
      *(undefined2 *)(g_3715 * 0x10 + 0x1f43) = ppcVar23;
      g_3711 = in_stack_0000ffee;
      *(undefined2 *)(g_3715 * 0x10 + 0x1f45) = in_stack_0000ffee;
      if (g_3649 == (char *)0x0) {
        in_stack_0000ffee = (char **)fn_234e_0062();
      }
      return in_stack_0000ffee;
    }
    in_stack_0000fff2 = (char **)0x4e11;
    if ((g_ab41 == (char **)0x0) && (cStack_3 == '%')) {
      ppcVar22 = (char **)(int)g_ab3f;
      ppcVar23 = (char **)0x4e34;
      iVar17 = tolower();
      if (iVar17 == 100) {
        ppcVar19 = (char **)&stack0xfff2;
        g_ab41 = (char **)CONCAT22(unaff_SS,ppcVar19);
        ppcVar23 = (char **)0x285f;
        pcVar47 = (char *)s_Process_Mist_FX__Can_t_load__Mis_3e2d_1000;
        ppcStack_18 = (char **)0x4e94;
        sprintf();
        in_stack_0000ffee = unaff_SS;
LAB_24b3_0329:
        g_ab3e = g_ab40;
        g_ab40 = 0;
        g_ab3f = '\0';
        cStack_3 = fn_14b3_095d();
        ppcVar40 = ppcVar24;
        ppcVar24 = ppcVar19;
        in_stack_0000fff2 = (char **)0x4e6c;
        ppcVar43 = (char **)s_Process_Mist_FX__Can_t_load__Mis_3e2d_1000;
      }
      else {
        in_stack_0000fff2 = ppcVar43;
        ppcVar43 = ppcVar22;
        if (iVar17 == 0x73) {
          pcVar36 = pcVar47 + 4;
          g_ab41 = *(char ***)pcVar47;
          ppcVar40 = ppcVar24;
          pcVar47 = pcVar36;
          ppcVar19 = ppcVar24;
          if (g_ab41 != (char **)0x0) goto LAB_24b3_0329;
        }
      }
    }
    pcVar25 = (code *)CONCAT11(uStack_8._1_1_,uStack_8._0_1_);
    ppcVar19 = (char **)(cStack_3 + -1);
    uVar30 = ZEXT24(ppcVar19);
    cVar15 = (char)((uint)ppcVar19 >> 8);
    if ((char *)s_Borland_C_____Copyright_1991_Bor_3e2d_0004 + 0x18 < ppcVar19) {
      ppcVar22 = (char **)CONCAT11(cVar15,cStack_3);
      ppcVar43 = (char **)0x2e64;
      ppcVar23 = (char **)0x5095;
      iVar17 = fn_1e64_0007();
      g_ab4b = g_ab4b + iVar17;
      ((undefined1 *)&g_ab4f)[g_ab4d] = cStack_3;
      puVar1 = (undefined1 *)&g_ab50 + g_ab4d;
      g_ab4d = g_ab4d + 1;
      *puVar1 = 0;
      if (g_371b < (uint)(g_ad95 + g_ab4b)) {
        fn_14b3_0731();
      }
      goto code_r0x00024e0d;
    }
    uVar45 = (int)ppcVar19 < 0;
    ppcVar32 = (char **)((int)ppcVar19 * 2);
    uVar39 = 0x2000;
    cVar14 = (char)ppcVar19;
    switch(ppcVar19) {
    case (char **)0x0:
      goto switchD_2000_4eaa_caseD_0;
    case (char **)0x1:
      uVar30 = g_384c +
               (ulong)(CONCAT22(local_6,CONCAT11(uStack_8._1_1_,uStack_8._0_1_)) *
                      (long)CONCAT22(pcVar18,ppcVar19)) / (ulong)(long)g_2170;
      if ((f_2803_0044 == '\0') || ((g_7fd6 & 2) == 0)) {
        iVar17 = g_ad8b + g_ad91 + -10;
      }
      else if ((f_2803_0045 == '\0') && ((g_7fd6 & 2) != 0)) {
        iVar17 = g_ad8b + g_ad91 + -2;
      }
      else {
        iVar17 = g_ad8b + g_ad91 + -5;
      }
      local_6 = (char **)0x2000;
      uStack_8._0_1_ = (code)0x5c;
      uStack_8._1_1_ = 0x49;
      g_523d = ppcVar19;
      fn_1ebc_00e7();
      uStack_8._0_1_ = (code)0xfb;
      uStack_8._1_1_ = 0;
      local_6 = (char **)0xffff;
      fn_0845_0008();
      uStack_8._0_1_ = (code)0x90;
      uStack_8._1_1_ = 0;
      local_6 = (char **)0x0;
      fn_0845_06f8();
      fn_1e64_002b();
      fn_0845_06f8();
      fn_1f6c_0006();
      local_6 = (char **)0x2f6c;
      uStack_8._0_1_ = (code)0xb7;
      uStack_8._1_1_ = 0x49;
      fn_1ebc_00fe();
      local_6 = (char **)((char *)s_PageArraySize_is_negative__3e2d_2eba + 2);
      pcVar47 = (char *)0x3169;
      uStack_8._0_1_ = (code)0xbc;
      uStack_8._1_1_ = 0x49;
      fn_2169_062e();
      if (g_2f43 == '\0') {
        while (g_2f16 != 0) {
          uStack_8._0_1_ = (code)0xd2;
          uStack_8._1_1_ = 0x49;
          local_6 = (char **)pcVar47;
          fn_1ebc_00fe();
          pcVar47 = (char *)s_PageArraySize_is_negative__3e2d_2eba + 2;
        }
      }
      local_4 = 1;
      cStack_3 = 0;
LAB_23e8_0b98:
      do {
        uStack_8._0_1_ = (code)0x1d;
        uStack_8._1_1_ = 0x4a;
        local_6 = (char **)pcVar47;
        iVar42 = fn_2169_060c();
        pcVar47 = (char *)0x3169;
        if (iVar42 == 0) {
          local_6 = (char **)0x3169;
          pcVar47 = (char *)s_Lib_error_29_3e2d_1842 + 3;
          uStack_8._0_1_ = (code)0xea;
          uStack_8._1_1_ = 0x49;
          fn_0845_093a();
          if (g_81ff == '\0') goto LAB_23e8_0b98;
          if (g_384c <= uVar30) {
            local_6 = (char **)((char *)s_Lib_error_29_3e2d_1842 + 3);
            pcVar47 = (char *)0x254c;
            uStack_8._0_1_ = (code)0x0;
            uStack_8._1_1_ = 0x4a;
            iVar42 = fn_154c_0136();
            if (iVar42 == 2) goto LAB_23e8_0b98;
          }
          if (uVar30 == 0) goto LAB_23e8_0b98;
          local_4 = 0;
          cStack_3 = 0;
        }
        pcVar36 = pcVar47;
        if (CONCAT11(cStack_3,local_4) != 0) {
          pcVar36 = (char *)0x3169;
          uStack_8._0_1_ = (code)0x2c;
          uStack_8._1_1_ = 0x4a;
          local_6 = (char **)pcVar47;
          fn_2169_0790();
        }
        uStack_8._0_1_ = (code)0x37;
        uStack_8._1_1_ = 0x4a;
        local_6 = (char **)pcVar36;
        fn_15a7_0964();
        iVar42 = 6;
        piVar33 = (int *)((char *)s_Process_Litning_FX__Can_t_load___3e2d_0c94 + 5);
        do {
          pcVar47 = (char *)0x2000;
          if (*piVar33 == CONCAT11(uStack_8._1_1_,uStack_8._0_1_)) {
                    /* WARNING: Could not recover jumptable at 0x00024a52. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            ppcVar20 = (char **)(*(code *)piVar33[6])();
            return ppcVar20;
          }
          piVar33 = piVar33 + 1;
          iVar42 = iVar42 + -1;
        } while (iVar42 != 0);
        if (CONCAT11(cStack_3,local_4) == 0) {
          if (g_2f43 == '\0') {
            while (local_6 != (char **)0x0) {
              uStack_8._0_1_ = (code)0x98;
              uStack_8._1_1_ = 0x4a;
              local_6 = (char **)pcVar47;
              fn_1ebc_00e7();
              pcVar47 = (char *)s_PageArraySize_is_negative__3e2d_2eba + 2;
            }
          }
          uStack_8._0_1_ = (code)0xa7;
          uStack_8._1_1_ = 0x4a;
          local_6 = (char **)pcVar47;
          fn_1ebc_00e7();
          local_6 = g_3711;
          uStack_8 = (code *)(iVar17 + 9);
          fn_1e59_001d();
          local_6 = (char **)0x2e59;
          uStack_8._0_1_ = (code)0xc6;
          uStack_8._1_1_ = 0x4a;
          fn_14b3_0215();
          local_6 = (char **)0x24b3;
          uStack_8._0_1_ = (code)0xcb;
          uStack_8._1_1_ = 0x4a;
          fn_1ebc_00fe();
          uStack_8._0_1_ = (code)0xaf;
          uStack_8._1_1_ = 0x49;
          local_6 = (char **)0x4abe;
          fn_0bbc_09a9();
          if (g_4bf8 != -1) {
            if (ppcStack_18 < (char *)s_Borland_C_____Copyright_1991_Bor_3e2d_0004 + 0x21) {
              ppcStack_18 = (char **)((int)ppcStack_18 >> 1);
            }
            else {
              ppcStack_18 = ppcStack_18 + -0x12;
            }
            g_4bfc = ppcStack_18;
            g_4c00 = 0x4971;
          }
          uStack_8._0_1_ = (code)0xbc;
          uStack_8._1_1_ = 0x2e;
          local_6 = (char **)0x4ad6;
          fn_1f2d_0002();
          local_6 = (char **)0x4b04;
          uStack_8._0_1_ = (code)0x2d;
          uStack_8._1_1_ = 0x2f;
          fn_1e74_000f();
          local_6 = (char **)0x2e74;
          uStack_8._0_1_ = (code)0x15;
          uStack_8._1_1_ = 0x4b;
          ppcVar20 = (char **)fn_2169_062e();
          return ppcVar20;
        }
      } while( true );
    case (char **)0x2:
      goto switchD_2000_4eaa_caseD_2;
    case (char **)0x3:
      goto switchD_2000_4eaa_caseD_3;
    case (char **)0x4:
      puVar37 = (undefined1 *)
                (*(int *)(code *)((int)((int)ppcVar32 + (int)unaff_SI) + -0x7f) * 0x6829);
      ppcVar31[10] = puVar37 + (int)ppcVar31[10];
      break;
    case (char **)0x5:
      fn_130a_0052();
      return unaff_SI;
    case (char **)0x6:
      return (char **)0x0;
    case (char **)0x7:
      goto LAB_2c24_0242;
    case (char **)0x8:
      if (ppcVar19 == (char **)0x0 && (char **)ppcVar31 == (char **)0x0) {
        if (unaff_SI == (char **)0x0) {
          local_6 = (char **)0x167;
        }
        else {
          local_6 = (char **)0x14c;
        }
        ppcVar31 = (char **)0x2981;
        local_4 = 0x81;
        cStack_3 = ')';
        uStack_8._0_1_ = (code)0x14;
        uStack_8._1_1_ = 0;
        if (unaff_SI == (char **)0x0) {
          fn_2037_0002();
          puVar37 = &stack0xfffe;
        }
        else {
          ppcVar31 = (char **)0x37fc;
          puVar37 = &stack0xfffe;
        }
      }
      else {
        if (unaff_SI != (char **)0x0) {
          local_4 = 0x81;
          cStack_3 = 0x29;
          local_6 = (char **)0x14c;
          uStack_8._0_1_ = (code)0x14;
          uStack_8._1_1_ = 0;
          uVar39 = fn_242d_0108();
          ppcVar20 = (char **)ppcVar31;
          puVar37 = &stack0xfffe;
          goto LAB_2981_0294;
        }
        local_4 = 0x81;
        cStack_3 = ')';
        local_6 = (char **)0x167;
        uStack_8._0_1_ = (code)0x14;
        uStack_8._1_1_ = 0;
      }
      break;
    case (char **)0x9:
      if ((int)ppcVar32[0x16] < 1) {
        ppcVar20 = (char **)0x0;
      }
      else {
        iVar17 = (int)ppcVar32[0x16] * 0x10;
        ppcVar20 = (char **)param_1[(int)(param_1[6] + 2 + 0x16)];
        if (param_1[(int)(param_1[6] + 1 + 0x16)] == (char *)0x4) {
          *(char ***)((char *)s_ADLIBG_ADV_3e2d_1d00 + 9 + iVar17) = ppcVar20;
        }
        else if (param_1[(int)(param_1[6] + 1 + 0x16)] == (char *)0xf) {
          ppcVar20 = (char **)((uint)ppcVar20 & 0x1fff);
          *(uint *)(iVar17 + 0x1d0b) = *(uint *)(iVar17 + 0x1d0b) & 0xe000;
          *(uint *)(iVar17 + 0x1d0b) = *(uint *)(iVar17 + 0x1d0b) | (uint)ppcVar20;
        }
        else {
          ppcVar20 = (char **)0xffff;
        }
      }
      return ppcVar20;
    case (char **)0xa:
      sprintf();
      local_6 = (char **)0x1000;
      uStack_8._0_1_ = (code)0xd2;
      uStack_8._1_1_ = 0x2e;
      fn_2309_000c();
      local_6 = (char **)0x3309;
      uStack_8._0_1_ = (code)0xd7;
      uStack_8._1_1_ = 0x2e;
      fn_0845_1536();
      local_6 = (char **)(g_aeaa + -0x41);
      uStack_8._0_1_ = (code)0x45;
      uStack_8._1_1_ = 0x18;
      fn_2148_002c();
      local_6 = (char **)0x3e2d;
      uStack_8._0_1_ = (code)0xaa;
      uStack_8._1_1_ = 0xae;
      fn_2148_014d();
      uStack_8 = (code *)((int)local_6 + 2);
      local_6 = (char **)CONCAT11(cStack_3,local_4);
      fn_2148_014d();
      uStack_8._0_1_ = (code)0x0;
      uStack_8._1_1_ = 0;
      local_6 = (char **)0x0;
      execl();
      return (char **)0x0;
    case (char **)0xb:
      goto switchD_2000_4eaa_caseD_b;
    case (char **)0xc:
      cVar16 = *(code *)(ulong)(CONCAT11((char)((uint)uStack_26 >> 8) + cVar15,(char)uStack_26) +
                               ((uint)ppcVar19 & 0xff));
      if (cVar16 != (code)0x0) {
        *(code *)unaff_DI = cVar16;
      }
      return (char **)CONCAT11(cVar15,cVar16);
    case (char **)0xd:
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar14;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar14;
      cVar14 = cVar14 + (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI);
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar14;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar14;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar14;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar14;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar14;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar14;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar14;
      ppcVar20 = (char **)(*(char **)((int)ppcVar32 + (int)unaff_SI) + CONCAT11(cVar15,cVar14));
      cVar15 = (char)ppcVar20;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      g_0000._0_1_ = (char)g_0000 + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)ppcVar32 = (char)*(code *)ppcVar32 + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      cVar14 = (char)ppcVar22;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar14;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_DI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_DI) + cVar14;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      (&stack0xfffe)[(int)unaff_SI] = (&stack0xfffe)[(int)unaff_SI] + cVar14;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      (&stack0xfffe)[(int)unaff_DI] = (&stack0xfffe)[(int)unaff_DI] + cVar14;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)unaff_SI = (char)*(code *)unaff_SI + cVar14;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)unaff_DI = (char)*(code *)unaff_DI + cVar14;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      g_0000._0_1_ = (char)g_0000 + cVar14;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)(char **)((int)ppcVar32 + (int)unaff_SI) =
           (char)*(code *)(char **)((int)ppcVar32 + (int)unaff_SI) + cVar15;
      *(char *)ppcVar32 = (char)*(code *)ppcVar32 + cVar14;
      pcStack_32 = g_3649;
      uStack_36 = 0x2000e184;
      fn_215f_001d();
      cVar15 = cRam0000000e;
      ppcVar19 = (char **)ppcVar31;
      iVar42 = (int)((ulong)g_ae53 >> 0x10);
      iVar17 = (int)g_ae53;
      if (iVar42 == 0 && iVar17 == 0) {
        return ppcVar20;
      }
      iVar11 = *(int *)(((uint)local_6 & 0xff) * 2 + *(int *)(iVar17 + 6) + iVar17);
      if (iVar11 == 0) {
        return ppcVar20;
      }
      uVar34 = CONCAT11(cStack_3,local_4);
      if (0x13f < uVar34) {
        return ppcVar20;
      }
      uVar38 = (uint)(byte)*(code *)((int)local_6 + iVar17 + *(int *)(iVar17 + 8));
      if (0x140 < uVar38 + uVar34) {
        return ppcVar20;
      }
      if (199 < unaff_BP) {
        return ppcVar20;
      }
      bVar13 = *(byte *)(*(int *)(iVar17 + 4) + iVar17 + 4);
      if (200 < bVar13 + unaff_BP) {
        return ppcVar20;
      }
      iVar35 = (int)local_6 * 2 + *(int *)(iVar17 + 0xc);
      bVar7 = *(byte *)(iVar35 + iVar17);
      bVar8 = *(byte *)(iVar35 + iVar17 + 1);
      puVar37 = (undefined1 *)(iVar17 + iVar11);
      pcVar47 = (char *)(uVar34 + unaff_BP * 0x140);
      iVar17 = 0x140 - uVar38;
      uVar34 = (uint)bVar7;
      if (uVar34 != 0) {
        uVar27 = uVar38;
        if (cRam0000000e == '\0') {
          pcVar47 = pcVar47 + uVar34 * 0x140;
        }
        else {
          do {
            do {
              pcVar5 = pcVar47;
              pcVar47 = pcVar47 + 1;
              *pcVar5 = cVar15;
              uVar27 = uVar27 - 1;
            } while (uVar27 != 0);
            pcVar47 = pcVar47 + iVar17;
            uVar34 = uVar34 - 1;
            uVar27 = uVar38;
          } while (uVar34 != 0);
        }
      }
      uVar27 = (uint)bVar8;
      uVar34 = uVar38;
      if (uVar27 == 0) {
        return ppcVar20;
      }
LAB_2e07_0208:
      do {
        puVar4 = puVar37;
        puVar37 = puVar37 + 1;
        uVar30 = (ulong)CONCAT11(*puVar4,*puVar4) & 0xffffff0f;
        cVar15 = *(char *)(ulong)((byte)uVar30 + 0xe);
        if (cVar15 != '\0') {
          *pcVar47 = cVar15;
        }
        pcVar36 = pcVar47 + 1;
        if (uVar34 != 1) {
          cVar15 = *(char *)(ulong)(((byte)(uVar30 >> 8) & 0xf0) + 0xe);
          if (cVar15 != '\0') {
            pcVar47[1] = cVar15;
          }
          pcVar47 = pcVar47 + 2;
          uVar34 = uVar34 - 2;
          pcVar36 = pcVar47;
          if (uVar34 != 0) goto LAB_2e07_0208;
        }
        cVar15 = cRam0000000e;
        pcVar47 = pcVar36 + iVar17;
        uVar27 = uVar27 - 1;
        uVar34 = uVar38;
        if (uVar27 == 0) {
          uVar34 = (uint)(byte)(bVar13 - (bVar7 + bVar8));
          if ((uVar34 != 0) && (uVar27 = uVar38, cRam0000000e != '\0')) {
            do {
              do {
                pcVar5 = pcVar47;
                pcVar47 = pcVar47 + 1;
                *pcVar5 = cVar15;
                uVar27 = uVar27 - 1;
              } while (uVar27 != 0);
              pcVar47 = pcVar47 + iVar17;
              uVar34 = uVar34 - 1;
              uVar27 = uVar38;
            } while (uVar34 != 0);
          }
          return ppcVar20;
        }
      } while( true );
    case (char **)0xe:
      fn_1e74_000f();
      ppcVar20 = (char **)fn_1f2d_0002();
      return ppcVar20;
    case (char **)0xf:
      if (ppcVar32 != (char **)0x0) goto LAB_2809_0396;
      goto LAB_2809_028d;
    case (char **)0x10:
      goto switchD_2000_4eaa_caseD_10;
    case (char **)0x11:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case (char **)0x12:
      *(code *)(unaff_SI + 6) = (code)0x0;
      *unaff_DI = (char *)ppcVar19;
      local_6 = ppcVar19;
      if (CONCAT11(cStack_3,local_4) != g_ab2a) {
        fn_13e8_05a4();
      }
      if (local_6 != (char **)0x0) {
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
      return local_6;
    case (char **)0x13:
      fn_0a21_06fd();
      return (char **)0x0;
    case (char **)0x14:
      local_6 = ppcVar19;
      fn_1f2d_0002();
      uStack_8._0_1_ = SUB41(ppcVar31,0);
      uStack_8._1_1_ = (undefined1)((ulong)ppcVar31 >> 8);
      setmem();
      iVar17 = fn_130a_07be();
      local_4 = (undefined1)iVar17;
      cStack_3 = (char)((uint)iVar17 >> 8);
      if (iVar17 == 0) {
        g_2170 = strlen();
      }
      else {
        vsprintf();
        g_2170 = strlen();
      }
      fn_14b3_0284();
      iVar17 = 0;
      goto LAB_230a_0bc9;
    case (char **)0x15:
      if ((int)g_2a7d <= (int)ppcVar19) {
        unaff_DI = (char **)0x0;
      }
      *(code *)((int)unaff_DI + (int)g_2a79) = (code)0x0;
      memset();
      return (char **)(g_29b9 | g_29e1 | g_2a09 | g_2a31);
    case (char **)0x16:
      goto switchD_2000_4eaa_caseD_16;
    case (char **)0x17:
      pcVar25 = (code *)((int)ppcVar22 + -1);
      if (pcVar25 != (code *)0x0 && ppcVar32 != (char **)0x0) {
        uStack_50 = 0;
        uVar34 = (uint)(byte)(((byte)(param_6 >> 0x10) & 0xf) << 2);
        pcVar12 = (code *)*(undefined4 *)(uVar34 + 0x2b30);
        pcVar18 = (code *)pcVar12;
        uStack_8._0_1_ = SUB41((ulong)pcVar12 >> 0x10,0);
        uStack_8._1_1_ = (undefined1)((ulong)pcVar12 >> 0x18);
        in_stack_0000ffee = (char **)(char **)*(undefined4 *)(uVar34 + 0x2b70);
        ppcVar31 = (char **)*(undefined4 *)((byte)((char)(param_6 >> 0x18) << 2) + 0x2b90);
        local_6 = (char **)ppcVar31;
        local_4 = (undefined1)((ulong)ppcVar31 >> 0x10);
        cStack_3 = (char)((ulong)ppcVar31 >> 0x18);
        in_stack_0000fff2 = (char **)0x2000;
        fn_215f_001d();
        iVar17 = (int)param_6 * 0x10;
        unaff_SI = (char **)(iVar17 + 0x1f3b);
        pcVar25 = (code *)((int)(undefined2 *)&g_0002 + 1);
        unaff_DI = (char **)((int)*unaff_SI * 8);
        if ((param_6 & 0x100000) == 0) {
          param_4 = param_4 + (int)*unaff_SI * -8;
        }
        in_stack_0000ffd0 = *(int *)(iVar17 + 7999) << 3;
        ppcVar19 = (char **)*(undefined2 *)(iVar17 + 0x1f3d);
      }
      pbVar2 = &stack0x0242 + (int)unaff_DI;
      bVar13 = (byte)pcVar25 & 7;
      *pbVar2 = *pbVar2 >> bVar13 | *pbVar2 << 8 - bVar13;
      if ((param_6 & 0x100000) != 0) {
        param_5 = (char **)((int)param_5 + (int)ppcVar19);
      }
      pcStack_2e = (char *)((int)ppcVar19 + *(int *)(code *)((int)unaff_SI + 7));
      pcStack_32 = *(char **)CONCAT22(param_3,param_2);
      unaff_SI = (char **)((int)param_2 + 3);
      uVar30 = (ulong)(byte)*(code *)(param_2 + 1);
      ppcVar20 = param_3;
      in_stack_0000ffd4 = ppcVar19;
      if ((param_6 & 0x40000) == 0) goto LAB_2fd6_01d1;
      ppcVar31 = (char **)(uVar30 * uStack_4e >> 0x10);
      uVar30 = uVar30 * uStack_4e & 0xffff;
      goto switchD_2000_4eaa_caseD_3;
    case (char **)0x18:
      goto switchD_2000_4eaa_caseD_18;
    case (char **)0x19:
      iVar17 = fn_15a7_0210();
      if (iVar17 == 0) {
        local_6 = (char **)0x0;
      }
      return local_6;
    case (char **)0x1a:
      goto switchD_2000_4eaa_caseD_1a;
    case (char **)0x1b:
      goto switchD_2000_4eaa_caseD_1b;
    case (char **)0x1c:
      fn_1fd6_000a();
      return in_stack_00000002;
    }
    ppcVar20 = (char **)ppcVar31;
    uVar39 = fn_242d_000f();
LAB_2981_0294:
    *(char ***)(puVar37 + -2) = ppcVar20;
    *(undefined2 *)(puVar37 + -4) = uVar39;
    if (*(long *)(puVar37 + -4) == 0) {
      ppcVar20 = (char **)0xffff;
    }
    else {
      ppcVar20 = (char **)(char **)((*(long *)(puVar37 + -4) - g_2aa7) / 0x14);
    }
    return ppcVar20;
  case (char *)0x11:
    while( true ) {
      pcVar47 = *ppcVar32;
      if (pcVar47 == (char *)0x0) {
        return (char **)0xffff;
      }
      ppcVar32 = (char **)fn_080e_000b();
      local_4 = SUB41(ppcVar31,0);
      cStack_3 = (char)((ulong)ppcVar31 >> 8);
      if (((uint)pcVar47 & 0x8000) != 0) break;
      param_2 = (char **)(CONCAT13(cStack_3,CONCAT12(local_4,ppcVar32)) >> 0x10);
      local_6 = ppcVar32;
    }
    return (char **)((uint)pcVar47 & 0x7fff);
  }
switchD_2000_4eaa_caseD_1a:
  uStack_8 = pcVar25;
  (**(code **)(&stack0x004e + (int)unaff_SI))();
  pcVar12 = (code *)swi(0x21);
  (*pcVar12)();
  fn_1c8d_0286();
  uVar39 = uRam00020002;
  if ((bool)uVar45) {
LAB_2c8d_004b:
    pcVar12 = (code *)swi(0x21);
    (*pcVar12)();
    return (char **)0xffff;
  }
  pcVar25 = pcVar18 + 0x10;
  pcVar28 = uStack_8 + ((code *)0xffef < pcVar18);
  if (pcVar47 != (char *)0x4246) goto LAB_2c8d_004b;
  if (ppcVar24 == (char **)0x564f) {
    g_0114 = pcVar25;
    g_0116 = pcVar28;
    *(undefined2 *)0x2e40 = in_stack_0000ffee;
    *(undefined2 *)0x2e42 = ppcVar23;
    pcVar12 = (code *)swi(0x21);
    (*pcVar12)();
    g_0128 = 0;
    uStack_8._0_1_ = (code)0x0;
    uStack_8._1_1_ = 0x20;
    fn_1c8d_013b();
    g_0120 = param_4 + 1;
    g_0126 = param_3;
    uStack_8._0_1_ = (code)0xd5;
    uStack_8._1_1_ = 0xc9;
    g_0124 = g_0120;
    __InitModules();
    uVar34 = (int)g_0126 - g_0124;
    if (g_011a <= uVar34) {
      bVar46 = (uVar34 >> 1 & 1) != 0;
      g_0118 = uVar34 >> 2;
      uStack_8._0_1_ = (code)0xf4;
      uStack_8._1_1_ = 0xc9;
      ppcVar20 = (char **)fn_1c8d_0316();
      if (bVar46) {
        return ppcVar20;
      }
      return (char **)0x0;
    }
    goto LAB_2c8d_004b;
  }
  pcVar18 = pcVar25 + (int)in_stack_0000ffee;
  uVar45 = CARRY2((uint)pcVar28,(uint)ppcVar23) ||
           CARRY2((uint)(pcVar28 + (int)ppcVar23),
                  (uint)CARRY2((uint)pcVar25,(uint)in_stack_0000ffee));
  pcVar25 = pcVar28 + (int)ppcVar23 + CARRY2((uint)pcVar25,(uint)in_stack_0000ffee);
  uStack_8._0_1_ = SUB21(pcVar25,0);
  uStack_8._1_1_ = (undefined1)((uint)pcVar25 >> 8);
  goto switchD_2000_4eaa_caseD_1a;
switchD_2000_4eaa_caseD_16:
  do {
    ppcVar20 = (char **)ppcVar31 + -(int)ppcVar19;
    pcVar18 = pcVar18 + 0x140;
    pcVar25 = pcVar18 + (int)ppcVar20;
    while (ppcVar31 = (char **)ZEXT24(ppcVar20), ppcVar20 < ppcVar32) {
      while( true ) {
        while( true ) {
          while( true ) {
            ppcVar24 = (char **)((int)unaff_SI + 1);
            cVar16 = *(code *)unaff_SI;
            uVar26 = (undefined3)(uVar30 >> 8);
            uVar30 = CONCAT31(uVar26,cVar16);
            uVar45 = (undefined1)((uint)ppcVar22 >> 8);
            if (cVar16 != (code)0x0) break;
            iVar17 = CONCAT11(uVar45,*(code *)ppcVar24);
            ppcVar20 = unaff_SI + 1;
            unaff_SI = (char **)((int)unaff_SI + 3);
            cVar16 = *(code *)ppcVar20;
            uVar30 = CONCAT31(uVar26,cVar16);
            do {
              *pcVar25 = cVar16;
              pcVar25 = pcVar25 + 1;
              ppcVar20 = (char **)((int)(char **)ppcVar31 + 1);
              if (ppcVar20 == ppcVar32) {
                ppcVar20 = (char **)0x0;
                pcVar25 = pcVar18 + 0x140;
                pcVar18 = pcVar25;
              }
              ppcVar31 = (char **)ZEXT24(ppcVar20);
              iVar17 = iVar17 + -1;
            } while (iVar17 != 0);
            ppcVar22 = (char **)0x0;
          }
          if ((char)cVar16 < '\0') break;
          iVar17 = CONCAT11(uVar45,cVar16);
          do {
            ppcVar6 = ppcVar24;
            ppcVar24 = (char **)((int)ppcVar24 + 1);
            uVar30 = CONCAT31((int3)(uVar30 >> 8),*(code *)ppcVar6);
            *pcVar25 = *(code *)ppcVar6;
            pcVar25 = pcVar25 + 1;
            ppcVar20 = (char **)((int)(char **)ppcVar31 + 1);
            if (ppcVar20 == ppcVar32) {
              ppcVar20 = (char **)0x0;
              pcVar25 = pcVar18 + 0x140;
              pcVar18 = pcVar25;
            }
            ppcVar31 = (char **)ZEXT24(ppcVar20);
            iVar17 = iVar17 + -1;
          } while (iVar17 != 0);
          ppcVar22 = (char **)0x0;
          unaff_SI = ppcVar24;
        }
        uVar30 = CONCAT31(uVar26,(char)cVar16 + -0x80);
        if ((char)((char)cVar16 + -0x80) != '\0') break;
        ppcVar20 = (char **)((int)unaff_SI + 3);
        pcVar47 = *ppcVar24;
        if ((int)pcVar47 < 1) {
          if (pcVar47 == (char *)0x0) {
            return (char **)0x0;
          }
          pcVar36 = pcVar47 + -0x8000;
          if (((uint)pcVar36 & 0x4000) == 0) {
            do {
              unaff_SI = (char **)((int)ppcVar20 + 1);
              *pcVar25 = *(code *)ppcVar20;
              pcVar25 = pcVar25 + 1;
              ppcVar20 = (char **)((int)(char **)ppcVar31 + 1);
              if (ppcVar20 == ppcVar32) {
                ppcVar20 = (char **)0x0;
                pcVar25 = pcVar18 + 0x140;
                pcVar18 = pcVar25;
              }
              ppcVar31 = (char **)ZEXT24(ppcVar20);
              pcVar36 = pcVar36 + -1;
              ppcVar20 = unaff_SI;
            } while (pcVar36 != (char *)0x0);
            uVar30 = 0;
            ppcVar22 = (char **)0x0;
          }
          else {
            pcVar47 = pcVar47 + 0x4000;
            unaff_SI = unaff_SI + 2;
            cVar16 = *(code *)ppcVar20;
            do {
              *pcVar25 = cVar16;
              pcVar25 = pcVar25 + 1;
              ppcVar20 = (char **)((int)(char **)ppcVar31 + 1);
              if (ppcVar20 == ppcVar32) {
                ppcVar20 = (char **)0x0;
                pcVar25 = pcVar18 + 0x140;
                pcVar18 = pcVar25;
              }
              ppcVar31 = (char **)ZEXT24(ppcVar20);
              pcVar47 = pcVar47 + -1;
            } while (pcVar47 != (char *)0x0);
            uVar30 = 0;
            ppcVar22 = (char **)0x0;
          }
        }
        else {
          pcVar25 = pcVar25 + (int)pcVar47;
          ppcVar24 = (char **)((int)(char **)ppcVar31 + (int)pcVar47);
          while (ppcVar31 = (char **)ZEXT24(ppcVar24), ppcVar32 <= ppcVar24) {
            ppcVar24 = ppcVar24 + -(int)ppcVar19;
            pcVar18 = pcVar18 + 0x140;
            pcVar25 = pcVar18 + (int)ppcVar24;
          }
          uVar30 = 0;
          unaff_SI = ppcVar20;
        }
      }
      pcVar25 = pcVar25 + (int)uVar30;
      unaff_SI = ppcVar24;
      ppcVar20 = (char **)((int)(char **)ppcVar31 + (int)uVar30);
    }
  } while( true );
switchD_2000_4eaa_caseD_2:
  do {
    if ((char **)param_1[4] != ppcVar43) goto LAB_263d_02b9;
    unaff_SI = (char **)((uint)param_1[7] & 0xf000);
    if (unaff_SI != (char **)0x0) goto LAB_263d_02a3;
    do {
      unaff_SI = (char **)((uint)param_1[7] & 0xf00);
LAB_263d_02a3:
      ppcVar22 = (char **)((int)(undefined2 *)&g_0000 + 1);
      param_1[0x17] = (char *)((uint)param_1[0x17] | 0x80);
      unaff_DI = (char **)0x0;
      g_2890 = (char **)CONCAT22(param_2,param_1);
LAB_263d_02b9:
      do {
        iVar17 = 0;
        if (ppcVar22 == (char **)0x0) {
          param_1[0x17] = (char *)((uint)param_1[0x17] & 0xfff9);
        }
        if ((((((uint)unaff_SI & 0x3300) == 0) || (((uint)param_1[7] & 4) == 0)) ||
            (ppcVar22 == (char **)0x0)) ||
           (((char **)CONCAT22(param_2,param_1) != g_2890 && (g_2890 != (char **)0x0))
           )) {
          if ((((uint)unaff_SI & 0x8800) == 0) ||
             ((((uint)param_1[7] & 4) != 0 || (ppcVar22 == (char **)0x0)))) {
            param_1[0x17] = (char *)((uint)param_1[0x17] & 0xfff9);
          }
          else {
            param_1[0x17] = (char *)((uint)param_1[0x17] | 6);
          }
        }
        else {
          param_1[0x17] = (char *)((uint)param_1[0x17] | 6);
          if (g_2890 == (char **)0x0) {
            g_2890 = (char **)CONCAT22(param_2,param_1);
          }
        }
        ppcVar20 = ppcVar22;
        if ((g_2890 != (char **)0x0) && (((uint)((char **)g_2890)[7] & 0x40) != 0)) {
          ppcVar20 = (char **)(uint)(g_2890 == (char **)CONCAT22(param_2,param_1));
        }
        if (ppcVar20 != (char **)0x0) {
          if (((((uint)unaff_SI & 0x1100) != 0) && (ppcVar22 != (char **)0x0)) &&
             (g_2890 == (char **)0x0)) {
            unaff_DI = (char **)0x0;
            g_2890 = (char **)CONCAT22(param_2,param_1);
          }
          if ((((uint)param_1[7] & (uint)unaff_SI) != 0) &&
             ((ppcVar22 != (char **)0x0 || (((uint)param_1[7] & 1) == 0)))) {
            iVar42 = *(int *)((((uint)unaff_SI & (uint)param_1[7] & 0xf00 |
                               ((uint)unaff_SI & (uint)param_1[7] & 0xf000) >> 4) >> 8) * 2 + 0x2898
                             );
            if (iVar42 == 0x200) {
              if (((uint)param_1[7] & 4) != 0) {
                param_1[0x17] = (char *)((uint)param_1[0x17] | 4);
                param_1[0x17] = (char *)((uint)param_1[0x17] | 2);
              }
              pcVar47 = param_1[7];
joined_r0x00026849:
              if (((uint)pcVar47 & 1) == 0) {
                iVar17 = 1;
              }
            }
            else if (iVar42 == 0x400) {
              if (((((uint)param_1[7] & 1) != 0) &&
                  (g_2890 == (char **)CONCAT22(param_2,param_1))) ||
                 (((uint)param_1[7] & 1) == 0)) {
                param_1[0x17] = (char *)((uint)param_1[0x17] ^ 1);
                in_stack_0000fff2 = (char **)((uint)param_1[2] | 0x8000);
                iVar17 = 1;
              }
              if (((uint)param_1[7] & 4) == 0) {
                param_1[0x17] = (char *)((uint)param_1[0x17] & 0xfffb);
                param_1[0x17] = (char *)((uint)param_1[0x17] & 0xfffd);
              }
            }
            else {
              if (iVar42 == 0x800) {
                if (((uint)param_1[7] & 4) == 0) {
                  param_1[0x17] = (char *)((uint)param_1[0x17] | 4);
                  param_1[0x17] = (char *)((uint)param_1[0x17] | 2);
                }
                pcVar47 = param_1[7];
                goto joined_r0x00026849;
              }
              param_1[0x17] = (char *)((uint)param_1[0x17] ^ 1);
              in_stack_0000fff2 = (char **)((uint)param_1[2] | 0x8000);
              iVar17 = 1;
              if (((uint)param_1[7] & 4) != 0) {
                param_1[0x17] = (char *)((uint)param_1[0x17] | 4);
                param_1[0x17] = (char *)((uint)param_1[0x17] | 2);
              }
              g_2890 = (char **)CONCAT22(param_2,param_1);
            }
          }
        }
        if ((((((uint)unaff_SI & 0x2200) != 0) && (ppcVar22 != (char **)0x0)) &&
            (param_1[0x17] = (char *)((uint)param_1[0x17] | 6), ((uint)param_1[7] & 4) == 0)) &&
           (((uint)param_1[0x17] & 1) == 0)) {
          local_4 = 1;
          cStack_3 = '\0';
          param_1[0x17] = (char *)((uint)param_1[0x17] | 1);
        }
        if (((((uint)param_1[0x17] & 0x80) != 0) || (((uint)unaff_SI & 0x8800) == 0x8800)) &&
           ((g_2890 = (char **)0x0, ppcVar22 == (char **)0x0 || (((uint)param_1[7] & 4) != 0)
            ))) {
          param_1[0x17] = (char *)((uint)param_1[0x17] & 0xfff9);
        }
        if (((ppcVar22 == (char **)0x0) && ((char **)CONCAT22(param_2,param_1) == g_2890)) &&
           (((uint)param_1[7] & 0x40) == 0)) {
          g_2890 = (char **)0x0;
        }
        if (((uint)param_1[0x17] & 0x18) != ((uint)param_1[0x17] & 3) << 3) {
          iVar17 = 0x2000;
          fn_163d_05cc();
          in_stack_0000fff2 = param_1;
        }
        if (CONCAT11(cStack_3,local_4) != 0) {
          param_1[0x17] = (char *)((uint)param_1[0x17] & 0xfffe);
        }
        if (iVar17 != 0) {
          param_1[0x17] = (char *)((uint)param_1[0x17] & 0xff);
          param_1[0x17] = (char *)((uint)param_1[0x17] | (uint)unaff_SI);
          if (((*(long *)(param_1 + 0x18) != 0) &&
              (iVar17 = (*(code *)param_1[0x18])(), in_stack_0000fff2 = param_1, iVar17 != 0)) ||
             (((uint)param_1[7] & 0x20) != 0)) goto LAB_263d_05b7;
        }
        if ((g_2890 == (char **)CONCAT22(param_2,param_1)) &&
           (((uint)param_1[7] & 0x40) != 0)) {
LAB_263d_05b7:
          if (in_stack_0000fff2 == (char **)0x0) {
            in_stack_0000fff2 = (char **)((uint)unaff_DI & 0x7fff);
          }
          return in_stack_0000fff2;
        }
        do {
          ppcVar31 = *(char ***)param_1;
          param_1 = (char **)ppcVar31;
          param_2 = (char **)((ulong)ppcVar31 >> 0x10);
          if (ppcVar31 == (char **)0x0) goto LAB_263d_05b7;
        } while (((uint)param_1[7] & 8) != 0);
        param_1[0x17] = (char *)((uint)param_1[0x17] & 0xffe7);
        param_1[0x17] = (char *)((uint)param_1[0x17] | ((uint)param_1[0x17] & 3) << 3);
        pcVar47 = param_1[0xf];
        if ((int)pcVar47 < 0) {
          pcVar47 = pcVar47 + *(int *)((int)param_1[0xe] * 0x10 + 7999) * 8;
        }
        pcVar36 = param_1[0x10];
        if ((int)pcVar36 < 0) {
          pcVar36 = pcVar36 + *(int *)((int)param_1[0xe] * 0x10 + 0x1f41);
        }
        if ((((int)local_6 < (int)(pcVar47 + *(int *)((int)param_1[0xe] * 0x10 + 0x1f3b) * 8)) ||
            (CONCAT11(uStack_8._1_1_,uStack_8._0_1_) <
             (int)(pcVar36 + *(int *)((int)param_1[0xe] * 0x10 + 0x1f3d)))) ||
           (((int)(pcVar47 + *(int *)((int)param_1[0xe] * 0x10 + 0x1f3b) * 8 + (int)param_1[0x11]) <
             (int)local_6 ||
            ((int)(pcVar36 + *(int *)((int)param_1[0xe] * 0x10 + 0x1f3d) + (int)param_1[0x12]) <
             CONCAT11(uStack_8._1_1_,uStack_8._0_1_))))) {
          ppcVar22 = (char **)0x0;
        }
        else {
          ppcVar22 = (char **)((int)(undefined2 *)&g_0000 + 1);
        }
        param_1[0x17] = (char *)((uint)param_1[0x17] & 0xff7f);
        ppcVar43 = (char **)((uint)unaff_DI & 0x7fff);
      } while (ppcVar43 == (char **)0x0);
    } while ((char **)param_1[3] == ppcVar43);
  } while( true );
switchD_2000_4eaa_caseD_0:
  ppcVar20 = ppcStack_18;
  iVar17 = iStack_1a;
  ppcVar19 = (char **)ppcVar31;
  if (lVar29 == 0) {
LAB_2809_0a81:
    fn_203b_0203();
    fn_1981_031f();
    g_abde = g_abde + -1;
    return &pcStack_32;
  }
  g_ae4d = 0;
  uVar39 = fn_2148_00c9();
  uStack_1e = (undefined1)uVar39;
  uStack_1d = (undefined1)((uint)uVar39 >> 8);
  uStack_1c = 0;
  uStack_1b = 0;
  if (g_ae4d != 0) {
    uVar39 = fn_1809_133b();
    uStack_1e = (undefined1)uVar39;
    uStack_1d = (undefined1)((uint)uVar39 >> 8);
    uStack_1c = SUB21(ppcVar19,0);
    uStack_1b = (undefined1)((uint)ppcVar19 >> 8);
    uVar39 = *(undefined2 *)((int)unaff_DI * 0x14 + 2);
    local_4 = (undefined1)uVar39;
    cStack_3 = (char)((uint)uVar39 >> 8);
  }
  ppcStack_18 = (char **)0x3148;
  iStack_1a = 0x8aaf;
  fn_2279_025b();
  lVar29 = lVar29 - CONCAT13(uStack_1b,CONCAT12(uStack_1c,CONCAT11(uStack_1d,uStack_1e)));
  *(long *)((int)unaff_DI * 0x14 + 4) =
       *(long *)((int)unaff_DI * 0x14 + 4) +
       CONCAT13(uStack_1b,CONCAT12(uStack_1c,CONCAT11(uStack_1d,uStack_1e)));
  if (CONCAT13(uStack_1b,CONCAT12(uStack_1c,CONCAT11(uStack_1d,uStack_1e))) <
      CONCAT22(ppcVar20,iVar17)) goto LAB_2809_0a81;
  uVar30 = CONCAT22(param_3,(int)uVar30) +
           CONCAT13(uStack_1b,CONCAT12(uStack_1c,CONCAT11(uStack_1d,uStack_1e)));
  ppcVar31 = (char **)(uVar30 >> 0x10);
  param_3 = (char **)(uVar30 >> 0x10);
  goto switchD_2000_4eaa_caseD_0;
LAB_1fbe_2397:
  if (((*(uint *)(uVar38 * 0x10 + 0x1d0b) & 0x4000) != 0) && (uVar38 != 0)) {
    fn_130a_0052();
    if ((param_1[(int)(param_1[6] + 4 + 0x16)] != (char *)0x0) && ((int)g_7fe5 == uVar38)) {
      fn_0845_1343();
    }
LAB_1fbe_2477:
    uStack_8._0_1_ = (code)0x1;
    uStack_8._1_1_ = 0;
  }
  goto LAB_1fbe_247c;
  while( true ) {
    *(code *)((int)param_2 + *(int *)(auStack_750 + iVar17 * 2 + 2)) = (code)auStack_750[iVar17 * 2]
    ;
    iVar17 = iVar17 + 2;
    if (9 < iVar17) break;
LAB_230a_0bc9:
    if (*(int *)(auStack_750 + iVar17 * 2) == 0) break;
  }
  fn_14b3_0122();
  fn_1e74_000f();
  ppcVar20 = (char **)fn_1f2d_0002();
  g_20f6 = 0;
  return ppcVar20;
}


//// fn_0fbe_059c @ 1fbe:059c

undefined2 __cdecl16far fn_0fbe_059c(void)

{
  char *pcVar1;
  char in_CL;
  int in_BX;
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  
  pcVar1 = (char *)(unaff_BP + unaff_DI + -0x1430);
  *pcVar1 = *pcVar1 + in_CL;
  return CONCAT11(*(undefined1 *)(in_BX + 9),*(undefined1 *)(in_BX + 8));
}


//// fn_0fbe_05cf @ 1fbe:05cf

undefined2 __cdecl16far fn_0fbe_05cf(void)

{
  return 0xffff;
}


//// fn_0fbe_0677 @ 1fbe:0677

/* WARNING: Instruction at (ram,0x00020609) overlaps instruction at (ram,0x00020606)
    */
/* WARNING: Removing unreachable block (ram,0x0002d0eb) */
/* WARNING: Removing unreachable block (ram,0x0002d0f2) */
/* WARNING: Removing unreachable block (ram,0x0002d0f4) */
/* WARNING: Removing unreachable block (ram,0x0002d0fc) */

char * __cdecl16far
fn_0fbe_0677(int param_1,undefined2 param_2,char *param_3,long param_4,undefined4 param_5)

{
  byte *pbVar1;
  long *plVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  undefined2 uVar10;
  ulong uVar11;
  byte *pbVar12;
  uint unaff_SI;
  uint *puVar13;
  uint *unaff_DI;
  undefined2 unaff_SS;
  bool bVar14;
  undefined2 uStack_16;
  undefined2 uStack_14;
  undefined2 uStack_12;
  undefined2 uStack_10;
  char local_4;
  
  iVar6 = *(int *)(param_1 + *(int *)(param_1 + 0xc) * 2 + 0x2c) * 0x82 + 0x362d;
  local_4 = '\x03';
  uVar8 = *(uint *)(param_1 + (*(int *)(param_1 + 0xc) + 2) * 2 + 0x2c);
  uVar11 = (ulong)uVar8;
  pcVar7 = (char *)((*(int *)(param_1 + 0xc) + 1) * 2);
  uVar9 = *(uint *)(pcVar7 + param_1 + 0x2c);
  if (0xf < uVar9) {
    return (char *)0x0;
  }
  pbVar12 = (byte *)(uVar9 * 2);
  bVar14 = pbVar12 == (byte *)0x0;
  switch(uVar9) {
  default:
    while( true ) {
      uVar10 = (undefined2)uVar11;
      pcVar7 = (char *)0x3148;
      uStack_16 = fn_2148_00c9();
      uStack_14 = 0;
      if (g_ae4d != 0) {
        uStack_16 = fn_1809_133b();
        uStack_14 = uVar10;
      }
      param_4 = param_4 - CONCAT22(uStack_14,uStack_16);
      uVar11 = CONCAT22(uStack_14,uStack_16);
      plVar2 = (long *)((int)unaff_DI * 0x14 + 4);
      *plVar2 = *plVar2 + uVar11;
      if (CONCAT22(uStack_14,uStack_16) < 0xfff0) break;
      pcVar7 = (char *)0x3037;
      fn_2037_0002();
      if (param_4 == 0) break;
      g_ae4d = 0;
    }
    fn_1981_031f();
    g_abde = g_abde + -1;
    return pcVar7;
  case 1:
    pbVar12[unaff_SI] = pbVar12[unaff_SI] + (char)((uint)pbVar12 >> 8);
    fn_1dbc_0017();
    fn_234e_0062();
    return (char *)0x0;
  case 2:
    pcVar7 = (char *)0x3279;
    fn_2279_025b();
    if (CONCAT22(uStack_10,uStack_12) != 0) {
      pcVar7 = (char *)s_Lib_error_29_3e2d_1842 + 3;
      fn_0845_08a5();
    }
    fn_15a7_0382();
    iVar6 = fn_15a7_0210();
    if (iVar6 == 0) {
      pcVar7 = (char *)0x0;
    }
    return pcVar7;
  case 3:
    ovr_2d46_0039();
    fn_1ebc_00fe();
    return (char *)0x1;
  case 4:
    bVar14 = unaff_SI == 1;
    break;
  case 5:
    bVar4 = *pbVar12;
    *pbVar12 = *pbVar12;
    g_7400 = g_7400 ^ (byte)(uVar8 >> 8);
    *(uint *)(&stack0x8bbf + (int)unaff_DI) =
         *(int *)(&stack0x8bbf + (int)unaff_DI) + (uint)bVar4 * -0x100;
    return pcVar7;
  case 6:
    pcVar7 = (char *)fn_0845_03b4();
    return pcVar7;
  case 8:
    fn_130a_0360();
    return (char *)0x0;
  case 9:
    in(uVar8);
    *(int *)(unaff_SI + 0x662e) = *(int *)(unaff_SI + 0x662e) + (int)unaff_DI;
    while( true ) {
      fn_0845_0be0();
      unaff_SI = unaff_SI + (int)unaff_DI;
      if (iVar6 + (int)unaff_DI == unaff_SI) break;
      ovr_2cef_0025();
      ovr_2cef_0020();
      fn_1ebc_0111();
      if ((uRam0003d46a & 0x4000) == 0) {
        iVar6 = 0x3dfd;
        ovr_2dfd_002a();
      }
      else {
        fn_1dbc_0004();
        ovr_2dfd_002a();
        iVar6 = 0x2dbc;
        fn_1dbc_0004();
      }
      fn_1ebc_01ec();
    }
    return (char *)0x1;
  case 10:
    if (bVar14 || ((int)uVar9 < 0 != (int)pbVar12 < 0) != (int)pbVar12 < 0) {
      bVar14 = unaff_DI == (uint *)0x0;
    }
    if ((bVar14) && ((char *)*unaff_DI == pcVar7)) {
      local_4 = '\x01';
      unaff_DI[1] = (uint)unaff_DI;
    }
    puVar13 = (uint *)(unaff_SI * 2);
    if (local_4 == '\x01') {
      while( true ) {
        uVar9 = *puVar13 >> 1;
        if (uVar9 == 0) break;
        if (((((*puVar13 & 1) == 0) && (uVar5 = puVar13[2], uVar5 < uVar8)) && (puVar13[1] != 0)) &&
           (((char *)*(uint *)0x0 == pcVar7 && (*(int *)&g_0002 == 0)))) {
          LOCK();
          uVar3 = *(uint *)&g_0002;
          *(uint *)&g_0002 = puVar13[1];
          UNLOCK();
          puVar13[1] = uVar3;
        }
        puVar13 = (uint *)(uVar9 << 1);
      }
    }
    return pcVar7;
  case 0xb:
                    /* WARNING: Could not recover jumptable at 0x000203e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar7 = (char *)(**(code **)(pbVar12 + 0x8ad))();
    return pcVar7;
  case 0xc:
    return (char *)0xffff;
  case 0xd:
    pbVar1 = pbVar12 + (int)unaff_DI;
    *pbVar1 = *pbVar1 + 1;
    bVar14 = *pbVar1 == 0;
    break;
  case 0xe:
    uVar8 = (uint)pcVar7 ^ 0x36;
    uVar9 = 0;
    if (g_3632 != 0) {
      uVar9 = (-g_3636 / g_3632) * g_3632 + g_3636;
    }
    g_2f0c = uVar8;
    g_2f0e = uVar9;
    if (((g_35ee != '\x02') && (g_35ee != '\0')) && ((g_35e6 & 0x1000) == 0)) {
      fn_1c24_0058();
    }
    if ((g_2f16 == 0) && ((g_2f28 != uVar8 || (g_2f2a != uVar9)))) {
      if ((((g_2f2c & 0xc000) == 0xc000) || (fn_1ebc_000c(), (g_2f2c & 0x8000) != 0))
         && (((g_2f2e <= uVar8 && (uVar8 <= g_2f32)) &&
             ((g_2f30 <= uVar9 && (uVar9 <= g_2f34)))))) {
        g_2f2c = g_2f2c | 0x4000;
      }
      else {
        fn_1ebc_0053();
      }
    }
    g_2f28 = uVar8;
    g_2f2a = uVar9;
    return param_3;
  case 0xf:
    out(0x26,pcVar7);
    *(char *)unaff_DI = (char)pcVar7;
    return pcVar7;
  }
  if ((bVar14) && (g_81ff != '\0')) {
    pcVar7 = (char *)fn_14b3_0122();
    g_4bde = 0;
    g_ab32 = 0;
    g_ab36 = 0;
    g_ab3a = 0;
  }
  else {
    g_ab2a = 1;
    g_ab32 = CONCAT22(param_3,param_2);
    g_ab36 = param_4;
    g_ab3a = param_5;
    g_4bde = unaff_SI;
    fn_14b3_0122();
    g_ab2e = g_ad8b + g_ad91 + -9;
    if (unaff_SI == 1) {
      g_ab2c = 0;
      g_ab30 = g_ad8d + g_ad8f + -0x4d;
    }
    else {
      g_ab2c = g_ad8f / unaff_SI;
      g_ab30 = g_ad8d + ((int)g_ab2c >> 1) + -0x25;
    }
    fn_13e8_05a4();
    pcVar7 = (char *)fn_2169_062e();
  }
  return pcVar7;
}


//// fn_0fbe_0a52 @ 1fbe:0a52

void __cdecl16far fn_0fbe_0a52(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  fn_0845_03b4(0x1fbe,*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 2) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 3) * 2 + 0x2c));
  return;
}


//// fn_0fbe_0aa2 @ 1fbe:0aa2

undefined2 __cdecl16far fn_0fbe_0aa2(void)

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


//// fn_0fbe_0b0f @ 1fbe:0b0f

undefined2 __cdecl16far fn_0fbe_0b0f(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined4 local_6;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  iVar1 = *(int *)(iVar2 + *(int *)(iVar2 + 0xc) * 2 + 0x2c) * 0xb5 +
          *(int *)(iVar2 + (*(int *)(iVar2 + 0xc) + 1) * 2 + 0x2c) * 0x10;
  local_6 = (undefined2 *)CONCAT22(0x3e2d,(undefined2 *)(iVar1 + 0x4ef5));
  *local_6 = *(undefined2 *)(iVar2 + (*(int *)(iVar2 + 0xc) + 2) * 2 + 0x2c);
  *(undefined2 *)(iVar1 + 0x4ef7) = *(undefined2 *)(iVar2 + (*(int *)(iVar2 + 0xc) + 3) * 2 + 0x2c);
  *(undefined2 *)(iVar1 + 0x4ef9) = *(undefined2 *)(iVar2 + (*(int *)(iVar2 + 0xc) + 4) * 2 + 0x2c);
  *(undefined2 *)(iVar1 + 0x4efb) = *(undefined2 *)(iVar2 + (*(int *)(iVar2 + 0xc) + 5) * 2 + 0x2c);
  *(undefined2 *)(iVar1 + 0x4efd) = *(undefined2 *)(iVar2 + (*(int *)(iVar2 + 0xc) + 6) * 2 + 0x2c);
  *(undefined2 *)((int)(undefined4 *)&g_4eff + iVar1) =
       *(undefined2 *)(iVar2 + (*(int *)(iVar2 + 0xc) + 7) * 2 + 0x2c);
  *(undefined2 *)((int)(undefined4 *)&g_4eff + iVar1 + 2) =
       *(undefined2 *)(iVar2 + (*(int *)(iVar2 + 0xc) + 8) * 2 + 0x2c);
  *(undefined2 *)(iVar1 + 0x4f03) = *(undefined2 *)(iVar2 + (*(int *)(iVar2 + 0xc) + 9) * 2 + 0x2c);
  return 0;
}


//// fn_0fbe_0c11 @ 1fbe:0c11

undefined2 fn_0fbe_0c11(undefined2 param_1,undefined4 param_2)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_2 >> 0x10);
  iVar1 = (int)param_2;
  fn_130a_0c28(*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c));
  return 1;
}


//// fn_0fbe_0c4d @ 1fbe:0c4d

undefined2 __cdecl16far fn_0fbe_0c4d(void)

{
  fn_1ebc_00fe();
  return 1;
}


//// fn_0fbe_0c5a @ 1fbe:0c5a

undefined2 __cdecl16far fn_0fbe_0c5a(void)

{
  fn_0845_08d9(0x1fbe,10);
  return 1;
}


//// fn_0fbe_0c6a @ 1fbe:0c6a

undefined2 __cdecl16far fn_0fbe_0c6a(void)

{
  fn_1ef2_0075(g_4edc,10,0);
  g_20d5 = 0;
  return 1;
}


//// fn_0fbe_0c8a @ 1fbe:0c8a

undefined2 __cdecl16far fn_0fbe_0c8a(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  iVar2 = fn_2315_0018(*(undefined2 *)
                         ((int)*(undefined4 *)*(undefined4 *)(iVar3 + 4) +
                         *(int *)(iVar3 + *(int *)(iVar3 + 0xc) * 2 + 0x2c) * 2),0x30003,
                        g_4edc);
  piVar1 = (int *)*(undefined4 *)(iVar3 + 4);
  ovr_2ded_002f(*piVar1 + iVar2,((int *)piVar1)[1]);
  if (*(int *)(iVar3 + (*(int *)(iVar3 + 0xc) + 1) * 2 + 0x2c) != 2) {
    fn_1ebc_00e7();
    fn_1dff_0008(3,*(undefined2 *)(iVar3 + (*(int *)(iVar3 + 0xc) + 1) * 2 + 0x2c));
    fn_1ebc_00fe();
  }
  return 1;
}


//// fn_0fbe_0d17 @ 1fbe:0d17

undefined2 __cdecl16far fn_0fbe_0d17(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  fn_130a_0cf6(*(undefined2 *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c));
  return 1;
}


//// fn_0fbe_0d34 @ 1fbe:0d34

undefined2 __cdecl16far fn_0fbe_0d34(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  *(undefined1 *)(*(int *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c) * 0xb5 + 0x4eed)
       = 1;
  return 1;
}


//// fn_0fbe_0d54 @ 1fbe:0d54

undefined2 __cdecl16far fn_0fbe_0d54(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  ((undefined1 *)&g_4eec)[*(int *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c) * 0xb5] = 1;
  *(undefined1 *)(*(int *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c) * 0xb5 + 0x4eed) = 1;
  return 1;
}


//// fn_0fbe_0d8c @ 1fbe:0d8c

undefined2 __cdecl16far fn_0fbe_0d8c(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined2 *)(*(int *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c) * 2 + -0x7eec) =
       *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c);
  return 1;
}


//// fn_0fbe_0db9 @ 1fbe:0db9

undefined2 __cdecl16far fn_0fbe_0db9(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  return *(undefined2 *)
          (*(int *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c) * 2 + -0x7eec);
}


//// fn_0fbe_0dd3 @ 1fbe:0dd3

/* WARNING: Control flow encountered bad instruction data */

uint __cdecl16far
fn_0fbe_0dd3(uint param_1,undefined2 param_2,undefined2 param_3,long param_4,undefined4 param_5)

{
  long *plVar1;
  char *pcVar2;
  undefined1 *puVar3;
  char *pcVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  int iVar8;
  undefined4 uVar9;
  code *pcVar10;
  uint *puVar11;
  undefined4 *puVar12;
  byte bVar13;
  char cVar14;
  uint uVar15;
  undefined2 uVar16;
  byte extraout_AH;
  uint uVar17;
  ulong uVar18;
  char in_CL;
  uint uVar19;
  undefined2 uVar20;
  long lVar21;
  code *pcVar22;
  uint *puVar23;
  int iVar24;
  char *unaff_SI;
  char *pcVar25;
  undefined1 *puVar26;
  char *unaff_DI;
  char *pcVar27;
  int iVar28;
  int iVar29;
  undefined2 unaff_SS;
  bool bVar30;
  undefined1 uVar31;
  uint in_stack_00000000;
  uint in_stack_00000002;
  char cStack_1f;
  code *pcStack_1e;
  uint uStack_1c;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined2 uStack_16;
  char *pcStack_14;
  undefined2 uStack_12;
  undefined1 uStack_10;
  undefined1 uStack_f;
  undefined2 uStack_e;
  int iStack_8;
  undefined2 local_4;
  
  lVar21 = 0;
  uVar15 = *(int *)(param_1 + 0xc) * 2;
  uVar17 = *(uint *)(param_1 + uVar15 + 0x2c);
  uVar19 = 0;
  if (0xe < uVar17) {
    return uVar19;
  }
  pcVar22 = (code *)(uVar17 * 2);
  uVar16 = 0x2000;
  bVar13 = (byte)uVar15;
  switch(uVar17) {
  case 0:
    fn_2279_025b();
    if (CONCAT13(uStack_f,CONCAT12(uStack_10,uStack_12)) != 0) {
      uStack_e._0_1_ = 0x79;
      uStack_e._1_1_ = 0x32;
      uStack_10 = 0xed;
      uStack_f = 0x5e;
      fn_0845_08a5();
    }
    fn_15a7_0382();
    iVar28 = fn_15a7_0210();
    if (iVar28 == 0) {
      uVar17 = 0;
    }
    else {
      uVar17 = 0x5f0b;
    }
    return uVar17;
  case 1:
    uVar17 = *(uint *)(param_1 + (*(int *)(param_1 + 0xc) + 1) * 2 + 0x2c);
    uVar18 = (ulong)uVar17;
    if (uVar17 != 0xffff) {
      puVar23 = (uint *)fn_080e_000b();
      local_4 = (undefined2)uVar18;
      goto LAB_1fbe_2a87;
    }
    uVar17 = *(uint *)(*(int *)(param_1 + *(int *)(param_1 + 0xc) * 2 + 0x2c) * 10 + -0x7df9);
    while( true ) {
      if (uVar17 == 0) {
        return 0xffff;
      }
      puVar23 = (uint *)fn_080e_000b();
      local_4 = (undefined2)uVar18;
      if ((uVar17 & 0x8000) != 0) break;
LAB_1fbe_2a87:
      uVar17 = *(uint *)CONCAT22(local_4,puVar23);
    }
    return uVar17 & 0x7fff;
  case 2:
    pcVar10 = pcVar22 + (int)unaff_DI;
    *pcVar10 = (code)((char)*pcVar10 + '\x01');
    if ((*pcVar10 == (code)0x0) && (g_81ff != '\0')) {
      uVar17 = fn_14b3_0122();
      g_4bde = (char *)0x0;
      g_ab32 = 0;
      g_ab36 = 0;
      g_ab3a = 0;
    }
    else {
      g_ab2a = 1;
      g_ab32 = CONCAT22(param_3,param_2);
      g_ab36 = param_4;
      g_ab3a = param_5;
      g_4bde = unaff_SI;
      fn_14b3_0122();
      g_ab2e = g_ad8b + g_ad91 + -9;
      if (unaff_SI == (char *)((int)(undefined2 *)&g_0000 + 1)) {
        g_ab2c = 0;
        g_ab30 = g_ad8d + g_ad8f + -0x4d;
      }
      else {
        g_ab2c = g_ad8f / (uint)unaff_SI;
        g_ab30 = g_ad8d + ((int)g_ab2c >> 1) + -0x25;
      }
      fn_13e8_05a4();
      uVar17 = fn_2169_062e();
    }
    return uVar17;
  case 3:
    if (((int)uVar17 < 0 != (int)pcVar22 < 0) == (int)pcVar22 < 0) {
      iVar28 = 1;
    }
    else {
      iVar28 = -1;
    }
    for (iVar29 = 0; iStack_8 + iVar28 != iVar29; iVar29 = iVar29 + iVar28) {
      ovr_2cef_0025();
      uStack_e._0_1_ = 0x4e;
      uStack_e._1_1_ = 5;
      ovr_2cef_0020();
      uStack_e._0_1_ = 0xef;
      uStack_e._1_1_ = 0x3c;
      uStack_10 = 0x68;
      uStack_f = 5;
      fn_1ebc_0111();
      if ((*(uint *)(CONCAT11(uStack_f,uStack_10) + 0x12) & 0x4000) == 0) {
        puVar12 = (undefined4 *)
                  CONCAT13(uStack_e._1_1_,
                           CONCAT12((undefined1)uStack_e,CONCAT11(uStack_f,uStack_10)));
        uStack_e = iVar29 + -1;
        uVar9 = *puVar12;
        uStack_12 = (undefined2)uVar9;
        uStack_10 = (undefined1)((ulong)uVar9 >> 0x10);
        uStack_f = (undefined1)((ulong)uVar9 >> 0x18);
        pcStack_14 = (char *)s_PageArraySize_is_negative__3e2d_2eba + 2;
        iStack_8 = 0x3dfd;
        uStack_16._0_1_ = 1;
        uStack_16._1_1_ = 6;
        ovr_2dfd_002a();
      }
      else {
        uStack_10 = 0x70;
        uStack_f = 0;
        uStack_e._0_1_ = 0;
        uStack_e._1_1_ = 0;
        pcStack_14 = (char *)0x70;
        uStack_12 = 0;
        uStack_16._0_1_ = 0xbc;
        uStack_16._1_1_ = 0x2e;
        uStack_18 = 0xa0;
        uStack_17 = 5;
        fn_1dbc_0004();
        uStack_e._0_1_ = (undefined1)g_4bec;
        uStack_e._1_1_ = (undefined1)((ulong)g_4bec >> 8);
        uStack_10 = 2;
        uStack_f = 0;
        puVar12 = (undefined4 *)CONCAT13(uStack_e._1_1_,CONCAT12((undefined1)uStack_e,2));
        uVar16 = (undefined2)((ulong)puVar12 >> 0x10);
        uStack_12 = *(undefined2 *)((char *)s_Borland_C_____Copyright_1991_Bor_3e2d_0004 + 4);
        pcStack_14 = *(char **)((char *)s_Borland_C_____Copyright_1991_Bor_3e2d_0004 + 2);
        uStack_16 = iVar29 + -1;
        uVar9 = *puVar12;
        uStack_1a = (undefined1)uVar9;
        uStack_19 = (undefined1)((ulong)uVar9 >> 8);
        uStack_18 = (undefined1)((ulong)uVar9 >> 0x10);
        uStack_17 = (undefined1)((ulong)uVar9 >> 0x18);
        uStack_1c = 0x2dbc;
        pcStack_1e = (code *)0x5ca;
        ovr_2dfd_002a();
        uStack_10 = 0x70;
        uStack_f = 0;
        uStack_e._0_1_ = 0;
        uStack_e._1_1_ = 0;
        pcStack_14 = (char *)0x70;
        uStack_12 = 0;
        uStack_16._0_1_ = 0xfd;
        uStack_16._1_1_ = 0x3d;
        iStack_8 = 0x2dbc;
        uStack_18 = 0xe1;
        uStack_17 = 5;
        fn_1dbc_0004();
      }
      fn_1ebc_01ec();
      fn_0845_0be0();
    }
    return 1;
  case 4:
    uVar17 = fn_07bc_012d();
    if (uVar17 != 0xffff) {
      uStack_e._0_1_ = (undefined1)uVar17;
      uStack_e._1_1_ = (undefined1)(uVar17 >> 8);
      uStack_10 = 0xbc;
      uStack_f = 0x17;
      uStack_12 = 0x80;
      fn_130a_0052();
    }
    return uVar17;
  case 5:
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    g_0000._0_1_ = (char)g_0000 + bVar13;
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    *pcVar22 = (code)((char)*pcVar22 + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + in_CL);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_DI] = (code)((char)pcVar22[(int)unaff_DI] + in_CL);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    (&stack0xfffe)[(int)unaff_SI] = (&stack0xfffe)[(int)unaff_SI] + in_CL;
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    (&stack0xfffe)[(int)unaff_DI] = (&stack0xfffe)[(int)unaff_DI] + in_CL;
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    *unaff_SI = *unaff_SI + in_CL;
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    *unaff_DI = *unaff_DI + in_CL;
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    g_0000._0_1_ = (char)g_0000 + in_CL;
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    *pcVar22 = (code)((char)*pcVar22 + in_CL);
    pcStack_1e = pcVar22;
    uStack_1c = uVar15;
    fn_215f_001d();
    cVar14 = cRam0000000e;
    iVar29 = (int)((ulong)g_ae53 >> 0x10);
    iVar28 = (int)g_ae53;
    if (iVar29 != 0 || iVar28 != 0) {
      iVar8 = *(int *)((in_stack_00000000 & 0xff) * 2 + *(int *)(iVar28 + 6) + iVar28);
      if ((((iVar8 != 0) && (in_stack_00000002 < 0x140)) &&
          (bVar13 = *(byte *)(in_stack_00000000 + *(int *)(iVar28 + 8) + iVar28),
          bVar13 + in_stack_00000002 < 0x141)) &&
         ((param_1 < 200 &&
          (bVar5 = *(byte *)(*(int *)(iVar28 + 4) + iVar28 + 4), bVar5 + param_1 < 0xc9)))) {
        iVar24 = in_stack_00000000 * 2 + *(int *)(iVar28 + 0xc);
        bVar6 = *(byte *)(iVar24 + iVar28);
        bVar7 = *(byte *)(iVar24 + iVar28 + 1);
        puVar26 = (undefined1 *)(iVar28 + iVar8);
        pcVar27 = (char *)(in_stack_00000002 + param_1 * 0x140);
        iVar28 = 0x140 - (uint)bVar13;
        uVar17 = (uint)bVar6;
        if (uVar17 != 0) {
          if (cRam0000000e == '\0') {
            pcVar27 = pcVar27 + uVar17 * 0x140;
          }
          else {
            do {
              uVar15 = (uint)bVar13;
              do {
                pcVar2 = pcVar27;
                pcVar27 = pcVar27 + 1;
                *pcVar2 = cVar14;
                uVar15 = uVar15 - 1;
              } while (uVar15 != 0);
              pcVar27 = pcVar27 + iVar28;
              uVar17 = uVar17 - 1;
            } while (uVar17 != 0);
          }
        }
        uVar17 = (uint)bVar7;
        if (uVar17 != 0) {
          do {
            uVar15 = (uint)bVar13;
            do {
              puVar3 = puVar26;
              puVar26 = puVar26 + 1;
              uVar18 = (ulong)CONCAT11(*puVar3,*puVar3) & 0xffffff0f;
              cVar14 = *(char *)(ulong)((byte)uVar18 + 0xe);
              if (cVar14 != '\0') {
                *pcVar27 = cVar14;
              }
              pcVar25 = pcVar27 + 1;
              if (uVar15 == 1) break;
              cVar14 = *(char *)(ulong)(((byte)(uVar18 >> 8) & 0xf0) + 0xe);
              if (cVar14 != '\0') {
                pcVar27[1] = cVar14;
              }
              pcVar27 = pcVar27 + 2;
              uVar15 = uVar15 - 2;
              pcVar25 = pcVar27;
            } while (uVar15 != 0);
            cVar14 = cRam0000000e;
            pcVar27 = pcVar25 + iVar28;
            uVar17 = uVar17 - 1;
          } while (uVar17 != 0);
          uVar17 = (uint)(byte)(bVar5 - (bVar6 + bVar7));
          if ((uVar17 != 0) && (cRam0000000e != '\0')) {
            do {
              uVar15 = (uint)bVar13;
              do {
                pcVar2 = pcVar27;
                pcVar27 = pcVar27 + 1;
                *pcVar2 = cVar14;
                uVar15 = uVar15 - 1;
              } while (uVar15 != 0);
              pcVar27 = pcVar27 + iVar28;
              uVar17 = uVar17 - 1;
            } while (uVar17 != 0);
          }
        }
      }
    }
    return uStack_1c;
  case 7:
    while( true ) {
      uVar20 = (undefined2)lVar21;
      uStack_e._0_1_ = (undefined1)uVar16;
      uStack_e._1_1_ = (undefined1)((uint)uVar16 >> 8);
      uStack_10 = 0x45;
      uStack_f = 0x8b;
      uVar16 = fn_2148_00c9();
      uStack_16._0_1_ = (undefined1)uVar16;
      uStack_16._1_1_ = (undefined1)((uint)uVar16 >> 8);
      pcStack_14 = (char *)0x0;
      if (g_ae4d != 0) {
        uStack_e._0_1_ = 0x48;
        uStack_e._1_1_ = 0x31;
        uStack_10 = 0x74;
        uStack_f = 0x8b;
        uVar16 = fn_1809_133b();
        uStack_e._0_1_ = (undefined1)uVar20;
        uStack_e._1_1_ = (undefined1)((uint)uVar20 >> 8);
        uStack_10 = (undefined1)uVar16;
        uStack_f = (undefined1)((uint)uVar16 >> 8);
        pcStack_14 = (char *)(CONCAT13(uStack_e._1_1_,CONCAT12((undefined1)uStack_e,uVar16)) >> 0x10
                             );
        uStack_16._0_1_ = uStack_10;
        uStack_16._1_1_ = uStack_f;
      }
      param_4 = param_4 - CONCAT22(pcStack_14,CONCAT11(uStack_16._1_1_,(undefined1)uStack_16));
      lVar21 = CONCAT22(pcStack_14,CONCAT11(uStack_16._1_1_,(undefined1)uStack_16));
      plVar1 = (long *)((int)unaff_DI * 0x14 + 4);
      *plVar1 = *plVar1 + lVar21;
      if (CONCAT22(pcStack_14,CONCAT11(uStack_16._1_1_,(undefined1)uStack_16)) < 0xfff0) break;
      uStack_e._0_1_ = 0x48;
      uStack_e._1_1_ = 0x31;
      uVar16 = 0x3037;
      uStack_10 = 0xcb;
      uStack_f = 0x8b;
      fn_2037_0002();
      if (param_4 == 0) break;
      g_ae4d = 0;
    }
    uStack_e._0_1_ = 0x5a;
    uStack_e._1_1_ = 0x8c;
    fn_1981_031f();
    g_abde = g_abde + -1;
    return CONCAT11(uStack_e._1_1_,(undefined1)uStack_e);
  case 8:
    fn_067a_0401();
    return 1;
  case 9:
    return param_4._2_2_;
  case 10:
    uStack_e._0_1_ = (undefined1)g_3649;
    uStack_e._1_1_ = (undefined1)((uint)g_3649 >> 8);
    uStack_10 = 0;
    uStack_f = 0x20;
    uStack_12 = 0xdb8c;
    fn_1fd6_000a();
    uStack_e._0_1_ = 0xb3;
    uStack_e._1_1_ = 0xdb;
    uVar17 = fn_1b63_0004();
    if (g_3649 == 0) {
      uVar17 = fn_1ebc_01ec();
    }
    return uVar17;
  case 0xb:
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    pcVar22[(int)unaff_SI] = (code)((char)pcVar22[(int)unaff_SI] + bVar13);
    bVar30 = CARRY1(bRam0004de53,bVar13);
    bRam0004de53 = bRam0004de53 + bVar13;
    (&stack0x0023)[(int)unaff_DI] = (&stack0x0023)[(int)unaff_DI] + bVar30;
    puVar11 = (uint *)*(undefined4 *)(uVar17 * 8 + 0x2db2);
    iVar28 = (int)((ulong)puVar11 >> 0x10);
    puVar23 = (uint *)puVar11;
    if (iVar28 == 0 && puVar23 == (uint *)0x0) {
      return 0;
    }
    do {
      puVar11 = puVar23;
      if (*puVar11 == uVar15) {
        return puVar23[1];
      }
      puVar23 = puVar23 + 2;
    } while (*puVar11 != 0xffff);
    return 0;
  case 0xc:
    g_4bf8 = 0xffff;
    return uVar15;
  case 0xd:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xe:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((int)uVar17 < 0) {
LAB_2c8d_0fb7:
    pcVar10 = (code *)swi(0x15);
    uVar17 = (*pcVar10)();
    if (uVar17 != 0) {
      s_Divide_error_Abnormal_program_te_3e2d_002f._15_2_ = uVar17 * 0x400;
      s_Divide_error_Abnormal_program_te_3e2d_002f[0x12] = (byte)(uVar17 >> 0xe);
      s_Divide_error_Abnormal_program_te_3e2d_002f[0x11] = (char)(uVar17 >> 6) + '\x10';
      if (s_Divide_error_Abnormal_program_te_3e2d_002f._20_2_ != 0 ||
          s_Divide_error_Abnormal_program_te_3e2d_002f._22_2_ != 0) {
        s_Divide_error_Abnormal_program_te_3e2d_002f[0xd] = '\x11';
        s_Divide_error_Abnormal_program_te_3e2d_002f[0xb] = '\0';
        s_Divide_error_Abnormal_program_te_3e2d_002f[0xc] = '\0';
      }
      bVar30 = false;
      uVar31 = 1;
      __EXTCOPY();
      if (!bVar30) {
        pcVar27 = &cStack_1f;
        pcVar25 = (char *)s_Borland_C_____Copyright_1991_Bor_3e2d_0004 + 0x1c;
        iVar28 = 5;
        do {
          if (iVar28 == 0) break;
          iVar28 = iVar28 + -1;
          pcVar4 = pcVar27;
          pcVar27 = pcVar27 + 1;
          pcVar2 = pcVar25;
          pcVar25 = pcVar25 + 1;
          uVar31 = *pcVar2 == *pcVar4;
        } while ((bool)uVar31);
        if ((bool)uVar31) {
          lVar21 = (ulong)CONCAT11((undefined1)uStack_16,uStack_17) *
                   (ulong)CONCAT11((undefined1)uStack_e,uStack_f);
          s_Divide_error_Abnormal_program_te_3e2d_002f._11_2_ = (undefined2)lVar21;
          s_Divide_error_Abnormal_program_te_3e2d_002f[0xd] = (char)((ulong)lVar21 >> 0x10) + '\x10'
          ;
        }
        bVar30 = true;
        pcVar25 = (char *)s_Borland_C_____Copyright_1991_Bor_3e2d_0004 + 0xe;
        pcVar27 = (char *)s_Borland_C_____Copyright_1991_Bor_3e2d_0004 + 0x1c;
        iVar28 = 5;
        do {
          if (iVar28 == 0) break;
          iVar28 = iVar28 + -1;
          pcVar4 = pcVar25;
          pcVar25 = pcVar25 + 1;
          pcVar2 = pcVar27;
          pcVar27 = pcVar27 + 1;
          bVar30 = *pcVar2 == *pcVar4;
        } while (bVar30);
        if (bVar30) {
          bVar13 = ((char *)s_Borland_C_____Copyright_1991_Bor_3e2d_0004)[0x2a];
          if (((byte)s_Divide_error_Abnormal_program_te_3e2d_002f[0xd] <= bVar13) &&
             ((bVar13 != s_Divide_error_Abnormal_program_te_3e2d_002f[0xd] ||
              ((uint)s_Divide_error_Abnormal_program_te_3e2d_002f._11_2_ <
               *(uint *)((char *)s_Borland_C_____Copyright_1991_Bor_3e2d_0004 + 0x28))))) {
            s_Divide_error_Abnormal_program_te_3e2d_002f[0xd] = bVar13;
            s_Divide_error_Abnormal_program_te_3e2d_002f._11_2_ =
                 *(uint *)((char *)s_Borland_C_____Copyright_1991_Bor_3e2d_0004 + 0x28);
          }
        }
        goto LAB_2c8d_105d;
      }
    }
    uVar17 = 0;
  }
  else {
    pcVar10 = (code *)swi(0x2f);
    cVar14 = (*pcVar10)();
    if (cVar14 != -0x80) goto LAB_2c8d_0fb7;
    pcVar10 = (code *)swi(0x2f);
    (*pcVar10)();
    s_Divide_error_Abnormal_program_te_3e2d_002f._22_2_ = param_2;
    s_Divide_error_Abnormal_program_te_3e2d_002f._20_2_ = pcVar22;
    (*pcVar22)();
    if (extraout_AH < 2) goto LAB_2c8d_0fb7;
    uVar17 = (*(code *)s_Divide_error_Abnormal_program_te_3e2d_002f._20_2_)();
    if ((uVar17 != 0) &&
       (uVar15 = uVar17, iVar28 = (*(code *)s_Divide_error_Abnormal_program_te_3e2d_002f._20_2_)(),
       iVar28 != 0)) {
      s_Divide_error_Abnormal_program_te_3e2d_002f._24_2_ = uVar15;
      iVar28 = (*(code *)s_Divide_error_Abnormal_program_te_3e2d_002f._20_2_)();
      if (iVar28 != 0) {
        uVar19 = (uint)((ulong)uVar17 * 0x400);
        s_Divide_error_Abnormal_program_te_3e2d_002f._15_2_ = pcVar22 + uVar19;
        s_Divide_error_Abnormal_program_te_3e2d_002f._17_2_ =
             (int)((ulong)uVar17 * 0x400 >> 0x10) + uVar15 + (uint)CARRY2(uVar19,(uint)pcVar22);
        s_Divide_error_Abnormal_program_te_3e2d_002f._11_2_ = pcVar22;
        s_Divide_error_Abnormal_program_te_3e2d_002f._13_2_ = uVar15;
      }
      (*(code *)s_Divide_error_Abnormal_program_te_3e2d_002f._20_2_)();
      (*(code *)s_Divide_error_Abnormal_program_te_3e2d_002f._20_2_)();
      s_Divide_error_Abnormal_program_te_3e2d_002f[0x18] = '\0';
      s_Divide_error_Abnormal_program_te_3e2d_002f[0x19] = '\0';
    }
LAB_2c8d_105d:
    uVar17 = s_Divide_error_Abnormal_program_te_3e2d_002f._15_2_ -
             s_Divide_error_Abnormal_program_te_3e2d_002f._11_2_;
  }
  return uVar17;
}


//// fn_0fbe_0fe7 @ 1fbe:0fe7

undefined2 __cdecl16far fn_0fbe_0fe7(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    if ((*(uint *)((int)(undefined4 *)&g_362a + iVar4 * 0x82 + 3) & 1) != 0) {
      for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
        iVar2 = *(int *)(iVar4 * 0x82 + iVar3 * 2 + 0x367d);
        if ((iVar2 != 0) &&
           ((cVar1 = *(char *)((int)g_7fb2 +
                               *(int *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 9 + iVar2 * 0x10) * 0xd + 7
                              ), cVar1 == '\0' || (cVar1 == '\x02')))) {
          return 1;
        }
      }
    }
    iVar4 = iVar4 + 1;
    if (3 < iVar4) {
      return 0;
    }
  } while( true );
}


//// fn_0fbe_1063 @ 1fbe:1063

undefined2 __cdecl16far fn_0fbe_1063(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  int iVar5;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  iVar1 = *(int *)(iVar3 + *(int *)(iVar3 + 0xc) * 2 + 0x2c);
  iVar5 = *(int *)(iVar3 + (*(int *)(iVar3 + 0xc) + 1) * 2 + 0x2c);
  if (iVar5 == -1) {
    if ((int)*(char *)(iVar1 * 10 + -0x7dfd) ==
        *(int *)(iVar3 + (*(int *)(iVar3 + 0xc) + 2) * 2 + 0x2c)) {
      uVar4 = *(undefined2 *)(iVar3 + (*(int *)(iVar3 + 0xc) + 3) * 2 + 0x2c);
    }
    else {
      uVar4 = *(undefined2 *)(iVar3 + (*(int *)(iVar3 + 0xc) + 2) * 2 + 0x2c);
    }
    iVar5 = -1;
  }
  else {
    if ((int)*(char *)(iVar1 * 10 + iVar5 + -0x7dfd) ==
        *(int *)(iVar3 + (*(int *)(iVar3 + 0xc) + 2) * 2 + 0x2c)) {
      iVar2 = *(int *)(iVar3 + 0xc) + 3;
    }
    else {
      iVar2 = *(int *)(iVar3 + 0xc) + 2;
    }
    uVar4 = *(undefined2 *)(iVar3 + iVar2 * 2 + 0x2c);
  }
  fn_130a_0360(iVar1,iVar5,uVar4);
  return 0;
}


//// fn_0fbe_1126 @ 1fbe:1126

undefined2 __cdecl16far fn_0fbe_1126(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  fn_1ebc_00e7();
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  fn_1dbc_0004((char *)s_PageArraySize_is_negative__3e2d_2eba + 2,
                *(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 2) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 3) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 4) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 5) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 6) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 7) * 2 + 0x2c));
  fn_1ebc_00fe();
  return 1;
}


//// fn_0fbe_11cb @ 1fbe:11cb

undefined2 __cdecl16far fn_0fbe_11cb(void)

{
  fn_0845_03d4(10);
  return 1;
}


//// fn_0fbe_11db @ 1fbe:11db

undefined2 __cdecl16far fn_0fbe_11db(void)

{
  fn_2279_025b((int)g_adea + 0x180,g_adea._2_2_,(int)g_4edc + 0x180,
                g_4edc._2_2_,0x180);
  fn_0845_1430(g_4edc);
  fn_1ef2_0075(g_4edc,10,0);
  g_20d5 = 0;
  return 1;
}


//// fn_0fbe_122c @ 1fbe:122c

undefined2 __cdecl16far fn_0fbe_122c(void)

{
  ovr_2d5f_00f2();
  return 1;
}


//// fn_0fbe_1239 @ 1fbe:1239

undefined2 __cdecl16far fn_0fbe_1239(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 local_c;
  undefined2 local_a;
  int local_8;
  int local_6;
  undefined1 *puStack_4;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  fn_1aff_030e(&local_a);
  iVar2 = *(int *)(iVar3 + (*(int *)(iVar3 + 0xc) + 4) * 2 + 0x2c);
  iVar1 = fn_0d6c_0338(local_a,local_c,(int)((char *)s_TANDY_ADV_3e2d_1b5c + 3)[iVar2 * 0x53],
                        0x70007);
  if (iVar1 == 0) {
    puStack_4 = (undefined1 *)&g_3803;
    local_6 = 0x15fa;
    local_8 = 0;
    do {
      if ((*(int *)(local_6 + 0x1d) == 0) && (*(char *)(local_6 + 0x14) != '\r')) {
        setmem(0x1d6c,local_6,(undefined1 *)&g_3803,0x2e,0);
        *(undefined1 *)(local_6 + 0x16) = (undefined1)local_8;
        *(undefined2 *)(local_6 + 7) = local_a;
        *(undefined2 *)(local_6 + 9) = local_c;
        *(undefined1 *)(local_6 + 0x18) =
             *(undefined1 *)(iVar3 + (*(int *)(iVar3 + 0xc) + 3) * 2 + 0x2c);
        *(undefined1 *)(local_6 + 0x20) =
             *(undefined1 *)(iVar3 + (*(int *)(iVar3 + 0xc) + 4) * 2 + 0x2c);
        *(undefined2 *)(local_6 + 0x23) = (undefined1 *)&g_3803;
        *(undefined2 *)(local_6 + 0x21) = (char *)s_TANDY_ADV_3e2d_1b5c + 2 + iVar2 * 0x53;
        *(char *)(local_6 + 0x17) = *(char *)(local_6 + 0x18) << 1;
        iVar2 = fn_0845_1036();
                    /* WARNING: Subroutine does not return */
        fn_1aff_0420(*(undefined2 *)((int)*(undefined4 *)(local_6 + 0x21) + 0x3a),
                      *(undefined2 *)(iVar2 * 2 + 0x2c));
      }
      local_8 = local_8 + 1;
      local_6 = local_6 + 0x2e;
    } while (local_8 < 0x1e);
  }
  return 0xffff;
}


//// fn_0fbe_14fb @ 1fbe:14fb

void __cdecl16far fn_0fbe_14fb(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  fn_070c_0253(0x1fbe,*(undefined2 *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c));
  return;
}


//// fn_0fbe_1515 @ 1fbe:1515

undefined2 __cdecl16far fn_0fbe_1515(void)

{
  return 0;
}


//// fn_0fbe_151c @ 1fbe:151c

void __cdecl16far fn_0fbe_151c(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  fn_070c_044a(0x1fbe,*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 2) * 2 + 0x2c));
  return;
}


//// fn_0fbe_155a @ 1fbe:155a

undefined2 __cdecl16far fn_0fbe_155a(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c) == -1) {
    iVar2 = 0;
    do {
      fn_070c_07f5(iVar2,*(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c),
                    *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 2) * 2 + 0x2c),
                    *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 3) * 2 + 0x2c),
                    *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 4) * 2 + 0x2c));
      iVar2 = iVar2 + 1;
    } while (iVar2 < 4);
  }
  else {
    fn_070c_07f5(*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                  *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c),
                  *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 2) * 2 + 0x2c),
                  *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 3) * 2 + 0x2c),
                  *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 4) * 2 + 0x2c));
  }
  return 1;
}


//// fn_0fbe_162c @ 1fbe:162c

undefined2 __cdecl16far fn_0fbe_162c(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined4 local_6;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  iVar1 = *(int *)(iVar2 + *(int *)(iVar2 + 0xc) * 2 + 0x2c) * 0x2e;
  local_6 = CONCAT22((undefined1 *)&g_3803,iVar1 + 0x15fa);
  if ((*(char *)(iVar1 + 0x160e) == '\x01') || (*(char *)(iVar1 + 0x160e) == '\x02')) {
    fn_1aff_030e(iVar1 + 0x1606,(undefined1 *)&g_3803,iVar1 + 0x1608,
                  (undefined1 *)&g_3803,
                  *(undefined2 *)(iVar2 + (*(int *)(iVar2 + 0xc) + 1) * 2 + 0x2c),
                  *(undefined2 *)(iVar2 + (*(int *)(iVar2 + 0xc) + 2) * 2 + 0x2c),
                  *(undefined2 *)(iVar2 + (*(int *)(iVar2 + 0xc) + 3) * 2 + 0x2c));
    *(char *)(iVar1 + 0x160a) = *(char *)(iVar2 + (*(int *)(iVar2 + 0xc) + 4) * 2 + 0x2c) << 1;
    if ((*(int *)(iVar1 + 0x1601) != *(int *)(iVar1 + 0x1606)) ||
       (*(int *)(iVar1 + 0x1603) != *(int *)(iVar1 + 0x1608))) {
      uVar3 = fn_1afa_0010(*(undefined2 *)(iVar1 + 0x1601),*(undefined2 *)(iVar1 + 0x1603),
                            *(undefined2 *)(iVar1 + 0x1606),*(undefined2 *)(iVar1 + 0x1608));
      fn_0d6c_0073(local_6,uVar3);
    }
  }
  return 1;
}


//// fn_0fbe_170f @ 1fbe:170f

undefined2 __cdecl16far fn_0fbe_170f(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  uVar3 = fn_0845_06f8(0x1fbe,*(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 3) * 2 + 0x2c));
  uVar3 = fn_0845_06f8((char *)s_Lib_error_29_3e2d_1842 + 3,
                        *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 2) * 2 + 0x2c),uVar3);
  uVar3 = fn_0845_06f8((char *)s_Lib_error_29_3e2d_1842 + 3,
                        *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c),uVar3);
  fn_13e8_0903(*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),uVar3);
  return 1;
}


//// fn_0fbe_177a @ 1fbe:177a

void __cdecl16far fn_0fbe_177a(void)

{
  fn_13e8_06a1();
  return;
}


//// fn_0fbe_1784 @ 1fbe:1784

undefined2 __cdecl16far fn_0fbe_1784(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = *(int *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c);
  if (iVar1 < 0) {
    ovr_2d0e_0034(-iVar1,1);
  }
  else {
    ovr_2d0e_002f(iVar1,1);
  }
  return 1;
}


//// fn_0fbe_17b8 @ 1fbe:17b8

bool __cdecl16far fn_0fbe_17b8(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  return *(int *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c) <= g_81e0;
}


//// fn_0fbe_17d9 @ 1fbe:17d9

undefined2 __cdecl16far fn_0fbe_17d9(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  iVar1 = *(int *)(iVar2 + *(int *)(iVar2 + 0xc) * 2 + 0x2c) + 5;
  iVar2 = *(int *)(iVar2 + (*(int *)(iVar2 + 0xc) + 1) * 2 + 0x2c);
  if (iVar2 == 0) {
    fn_0bbc_070e(iVar1,0);
  }
  else {
    fn_0bbc_07b1(iVar1,iVar2);
  }
  return 1;
}


//// fn_0fbe_181b @ 1fbe:181b

bool __cdecl16far fn_0fbe_181b(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  iVar1 = fn_0845_0ac7();
  if (iVar1 == 0) {
    uVar3 = (undefined2)((ulong)param_1 >> 0x10);
    iVar2 = (int)param_1;
    uVar3 = fn_07bc_012d((char *)s_Lib_error_29_3e2d_1842 + 3,
                          *(undefined2 *)(iVar2 + *(int *)(iVar2 + 0xc) * 2 + 0x2c),
                          *(undefined2 *)(iVar2 + (*(int *)(iVar2 + 0xc) + 1) * 2 + 0x2c),
                          *(undefined2 *)(iVar2 + (*(int *)(iVar2 + 0xc) + 2) * 2 + 0x2c));
    fn_0845_0acf(uVar3);
  }
  return iVar1 == 0;
}


//// fn_0fbe_1870 @ 1fbe:1870

bool __cdecl16far fn_0fbe_1870(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  uVar2 = fn_07bc_012d(0x1fbe,*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                        *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c),
                        *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 2) * 2 + 0x2c));
  iVar1 = fn_0c59_03a8(uVar2);
  if (iVar1 == 0) {
    fn_07bc_044c(uVar2);
  }
  return iVar1 != 0;
}


//// fn_0fbe_18cb @ 1fbe:18cb

undefined2 __cdecl16far fn_0fbe_18cb(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  fn_070c_00cf(0x1fbe,*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c),
                (long)*(int *)(iVar1 + (*(int *)(iVar1 + 0xc) + 2) * 2 + 0x2c));
  return 1;
}


//// fn_0fbe_1910 @ 1fbe:1910

undefined2 __cdecl16far fn_0fbe_1910(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined1 local_10 [14];
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  iVar3 = *(int *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c);
  iVar2 = iVar3 * 4;
  if (*(int *)(iVar2 + 0x20fc) == 0 && *(int *)(iVar2 + 0x20fe) == 0) {
    iVar2 = fn_2315_0018();
    iVar2 = *(int *)*(undefined4 *)(iVar1 + 4) + iVar2;
    sprintf(local_10);
    uVar4 = fn_0638_0008(local_10);
    iVar3 = iVar3 * 4;
    *(int *)(iVar3 + 0x20fe) = iVar2;
    *(undefined2 *)(iVar3 + 0x20fc) = uVar4;
  }
  fn_0d6b_000f();
  return 1;
}


//// fn_0fbe_19ad @ 1fbe:19ad

void __cdecl16far fn_0fbe_19ad(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  fn_0638_01e5(*(undefined4 *)(*(int *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c) * 4 + 0x20fc),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c));
  return;
}


//// fn_0fbe_19e1 @ 1fbe:19e1

undefined2 __cdecl16far fn_0fbe_19e1(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = *(int *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c);
  fn_0638_018b(*(undefined4 *)(iVar1 * 4 + 0x20fc));
  iVar1 = iVar1 * 4;
  *(undefined2 *)(iVar1 + 0x20fe) = 0;
  *(undefined2 *)(iVar1 + 0x20fc) = 0;
  return 1;
}


//// fn_0fbe_1a1d @ 1fbe:1a1d

void __cdecl16far fn_0fbe_1a1d(void)

{
  fn_0845_0ac7();
  return;
}


//// fn_0fbe_1a27 @ 1fbe:1a27

bool __cdecl16far fn_0fbe_1a27(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  iVar1 = *(int *)(iVar2 + *(int *)(iVar2 + 0xc) * 2 + 0x2c);
  if (iVar1 != -1) {
    ovr_2d2c_00b1(iVar1 * 0x2e + 0x15fa,(undefined1 *)&g_3803,
                  *(undefined2 *)(iVar2 + (*(int *)(iVar2 + 0xc) + 1) * 2 + 0x2c));
  }
  return iVar1 != -1;
}


//// fn_0fbe_1a72 @ 1fbe:1a72

undefined2 __cdecl16far fn_0fbe_1a72(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  fn_067a_0401(*(undefined2 *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c),0);
  return 1;
}


//// fn_0fbe_1a93 @ 1fbe:1a93

undefined2 __cdecl16far fn_0fbe_1a93(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  iVar1 = *(int *)(iVar2 + (*(int *)(iVar2 + 0xc) + 1) * 2 + 0x2c);
  if (iVar1 == -1) {
    iVar1 = g_7fd0;
  }
  fn_067a_02f5(0x1fbe,*(undefined2 *)(iVar2 + *(int *)(iVar2 + 0xc) * 2 + 0x2c),iVar1);
  return 1;
}


//// fn_0fbe_1ad1 @ 1fbe:1ad1

undefined2 __cdecl16far fn_0fbe_1ad1(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 local_a;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = *(int *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c) * 4;
  uVar2 = *(undefined2 *)(iVar1 + 0x20fe);
  iVar1 = *(int *)(iVar1 + 0x20fc);
  local_a = (undefined4 *)CONCAT22(uVar2,(undefined4 *)(iVar1 + *(int *)(iVar1 + 6)));
  iVar1 = 0;
  do {
    *local_a = 0;
    local_a = (undefined4 *)CONCAT22(local_a._2_2_,(undefined4 *)local_a + 6);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 10);
  return 1;
}


//// fn_0fbe_1b20 @ 1fbe:1b20

undefined1 * __cdecl16far
fn_0fbe_1b20(int param_1,undefined1 *param_2,undefined2 param_3,long param_4)

{
  int *piVar1;
  long *plVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  undefined1 *puVar10;
  undefined2 uVar11;
  uint *in_CX;
  uint uVar12;
  ulong uVar13;
  int iVar14;
  uint unaff_SI;
  uint *puVar15;
  int *unaff_DI;
  char *pcVar16;
  undefined2 unaff_SS;
  bool bVar17;
  undefined1 auStack_32 [14];
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined4 uStack_20;
  char *pcStack_1c;
  char *pcStack_1a;
  undefined2 uStack_18;
  undefined2 uStack_16;
  char *pcStack_14;
  char *pcStack_10;
  int in_stack_0000fff2;
  undefined4 local_a;
  undefined4 uStack_6;
  
  uVar12 = *(uint *)(param_1 + *(int *)(param_1 + 0xc) * 2 + 0x2c);
  if (uVar12 != 0xffff) {
    puVar7 = (undefined1 *)*(undefined2 *)(param_1 + (*(int *)(param_1 + 0xc) + 2) * 2 + 0x2c);
    uVar13 = ZEXT24(puVar7);
    iVar9 = *(int *)(param_1 + 0xc) + 1;
    puVar10 = (undefined1 *)(iVar9 * 2);
    uVar3 = *(uint *)(puVar10 + param_1 + 0x2c);
    if (uVar3 < 7) {
      iVar14 = uVar3 * 2;
      bVar17 = iVar14 == 0;
      pcVar16 = (char *)0x2000;
      switch(uVar3) {
      case 1:
        pcStack_14 = (char *)0xcfe;
        fn_130a_0360();
        return (undefined1 *)0x0;
      case 2:
        if ((int)puVar7 < 0x3804) {
          iVar9 = 1;
        }
        else {
          iVar9 = -1;
        }
        for (; (undefined1 *)&g_3803 + iVar9 != puVar7; puVar7 = puVar7 + iVar9) {
          iVar6 = (int)g_384c;
          uVar5 = *(undefined4 *)CONCAT22(in_stack_0000fff2,pcStack_10);
          ovr_2cef_0025();
          uVar5 = *(undefined4 *)CONCAT22((int)uVar5,pcVar16);
          pcStack_10 = (char *)uVar5;
          uVar11 = (undefined2)((ulong)uVar5 >> 0x10);
          pcStack_14 = (char *)0x54e;
          iVar8 = ovr_2cef_0020();
          iVar14 = *(int *)((int)pcStack_10 + 4);
          uVar3 = *(uint *)((int)pcStack_10 + 6);
          pcStack_14 = (char *)0x3cef;
          uStack_16 = 0x568;
          fn_1ebc_0111();
          if ((*(uint *)(uVar3 + 0x12) & 0x4000) == 0) {
            pcStack_14 = puVar7 + -1;
            uVar5 = *(undefined4 *)(ulong)uVar3;
            uStack_18 = (undefined2)uVar5;
            uStack_16 = (undefined2)((ulong)uVar5 >> 0x10);
            pcStack_1a = (char *)s_PageArraySize_is_negative__3e2d_2eba + 2;
            pcStack_1c = (char *)0x601;
            ovr_2dfd_002a();
          }
          else {
            uStack_16 = 0x70;
            pcStack_14 = (char *)0x0;
            pcStack_1a = (char *)0x70;
            uStack_18 = 0;
            pcStack_1c = (char *)s_PageArraySize_is_negative__3e2d_2eba + 2;
            uStack_20 = CONCAT22(0x5a0,(undefined2)uStack_20);
            fn_1dbc_0004();
            uVar11 = (undefined2)g_4bf0;
            pcStack_14 = (char *)((ulong)g_4bf0 >> 0x10);
            pcStack_10 = (char *)((ulong)g_4bec >> 0x10);
            uStack_16 = 2;
            uStack_18 = *(undefined2 *)((int)pcStack_10 + 6);
            pcStack_1a = *(char **)(undefined4 *)((int)pcStack_10 + 4);
            pcStack_1c = puVar7 + -1;
            uStack_20 = *(undefined4 *)CONCAT22(uVar11,pcStack_10);
            uStack_22 = 0x2dbc;
            uStack_24 = 0x5ca;
            ovr_2dfd_002a();
            uStack_16 = 0x70;
            pcStack_14 = (undefined1 *)0x0;
            pcStack_1a = (char *)0x70;
            uStack_18 = 0;
            pcStack_1c = "\x0e\x0e\x0e\x0e\x0e#\x0e\x1c(\x17#%\x13(";
            uStack_20 = CONCAT22(0x5e1,(undefined2)uStack_20);
            fn_1dbc_0004();
          }
          fn_1ebc_01ec();
          pcStack_10 = (char *)s_PageArraySize_is_negative__3e2d_2eba + 2;
          pcVar16 = (char *)s_Lib_error_29_3e2d_1842 + 3;
          fn_0845_0be0();
          in_stack_0000fff2 = iVar6 + (uVar12 & 0x7fff) * 0x2e + 0x15fa;
        }
        return (undefined1 *)((int)(undefined2 *)&g_0000 + 1);
      case 3:
        if (!bVar17 && ((int)uVar3 < 0 != iVar14 < 0) == iVar14 < 0) goto code_r0x0002d104;
        do {
          bVar17 = unaff_DI == (int *)0x0;
code_r0x0002d104:
          if ((bVar17) && ((undefined1 *)*unaff_DI == puVar10)) {
            uStack_6 = 0x10000;
            unaff_DI[1] = (int)unaff_DI;
          }
          do {
            puVar15 = (uint *)(unaff_SI * 2);
            if (in_CX <= puVar15) {
LAB_2c8d_0845:
              if (uStack_6._2_1_ == '\x01') {
                while( true ) {
                  uVar12 = *puVar15 >> 1;
                  if (uVar12 == 0) break;
                  if (((((*puVar15 & 1) == 0) &&
                       (puVar4 = (undefined1 *)puVar15[2], puVar4 < puVar7)) && (puVar15[1] != 0))
                     && (((undefined1 *)*(int *)0x0 == puVar10 && (*(int *)&g_0002 == 0)))) {
                    LOCK();
                    uVar3 = *(uint *)&g_0002;
                    *(uint *)&g_0002 = puVar15[1];
                    UNLOCK();
                    puVar15[1] = uVar3;
                  }
                  puVar15 = (uint *)(uVar12 << 1);
                }
              }
              return puVar10;
            }
            unaff_SI = *puVar15 >> 1;
            if (unaff_SI == 0) goto LAB_2c8d_0845;
          } while (((*puVar15 & 1) != 0) || (param_2 = (undefined1 *)puVar15[2], puVar7 <= param_2))
          ;
          unaff_DI = (int *)puVar15[1];
        } while( true );
      case 4:
                    /* WARNING: Could not recover jumptable at 0x000203e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        puVar7 = (undefined1 *)(*(code *)*(undefined2 *)(iVar14 + 0x8ad))();
        return puVar7;
      case 5:
        return (undefined1 *)0xffff;
      case 6:
        piVar1 = (int *)(iVar14 + unaff_SI);
        *piVar1 = *piVar1 + iVar9 * -2;
        iVar9 = *piVar1;
        while( true ) {
          if (iVar9 == 0) {
            unaff_SI = (uint)uVar13;
          }
          uVar12 = (uint)uVar13 + 1;
          uVar13 = (ulong)uVar12;
          if ((3 < (int)uVar12) || (unaff_SI != 0xffff)) break;
          iVar9 = ((undefined2 *)&g_29b9)[uVar12 * 0x14];
        }
        uVar12 = 0;
        while (((int)uVar12 < 4 && (unaff_SI == 0xffff))) {
          if ((int)((undefined2 *)&g_29b1)[uVar12 * 0x14] <= (int)unaff_DI) {
            unaff_SI = uVar12;
          }
          uVar12 = uVar12 + 1;
        }
        if (unaff_SI != 0xffff) {
          iVar9 = unaff_SI * 0x28;
          local_a = (int *)CONCAT22(0x3e2d,(int *)(iVar9 + 0x2997));
          pcStack_14 = (char *)0x2000;
          uStack_16 = 0x784e;
          memset();
          ((undefined2 *)&g_29b1)[unaff_SI * 0x14] = unaff_DI;
          *(undefined2 *)(iVar9 + 0x29b7) = (undefined2)param_4;
          *(undefined2 *)(iVar9 + 0x2999) = param_2;
          *local_a = param_1;
          pcStack_14 = (char *)0x7873;
          uVar11 = fn_16cf_0a4b();
          *(int *)(iVar9 + 0x299d) = param_1;
          *(undefined2 *)(iVar9 + 0x299b) = uVar11;
          pcStack_14 = (char *)*(undefined4 *)(iVar9 + 0x299b);
          uStack_16 = 0x1000;
          uStack_18 = 0x7892;
          uVar11 = fn_16cf_0a9b();
          *(int *)(iVar9 + 0x299d) = param_1;
          *(undefined2 *)(iVar9 + 0x299b) = uVar11;
          if (*(long *)(iVar9 + 0x299b) != 0) {
            *(undefined4 *)(iVar9 + 0x29a7) = uStack_6;
            *(undefined2 *)(iVar9 + 0x29b5) = g_2980;
            ((undefined2 *)&g_29b9)[unaff_SI * 0x14] = 2;
            pcStack_14 = (char *)0x78cd;
            fn_16cf_05d0();
            return (undefined1 *)((int)(undefined2 *)&g_0000 + 1);
          }
        }
        return (undefined1 *)0x0;
      }
      while( true ) {
        uVar11 = (undefined2)uVar13;
        uStack_16 = 0x8b45;
        pcStack_14 = pcVar16;
        uStack_16 = fn_2148_00c9();
        pcStack_14 = (char *)0x0;
        if (g_ae4d != 0) {
          pcStack_14 = (char *)0x3148;
          uStack_16 = 0x8b74;
          uStack_16 = fn_1809_133b();
          pcStack_14 = (char *)uVar11;
        }
        param_4 = param_4 - CONCAT22(pcStack_14,uStack_16);
        uVar13 = CONCAT22(pcStack_14,uStack_16);
        plVar2 = (long *)((int)unaff_DI * 0x14 + 4);
        *plVar2 = *plVar2 + uVar13;
        if (CONCAT22(pcStack_14,uStack_16) < 0xfff0) break;
        pcStack_14 = (char *)0x3148;
        pcVar16 = (char *)0x3037;
        uStack_16 = 0x8bcb;
        fn_2037_0002();
        if (param_4 == 0) break;
        g_ae4d = 0;
      }
      pcStack_14 = (char *)0x8c5a;
      fn_1981_031f();
      g_abde = g_abde + -1;
      return auStack_32;
    }
  }
  return (undefined1 *)((int)(undefined2 *)&g_0000 + 1);
}


//// fn_0fbe_1cf7 @ 1fbe:1cf7

void __cdecl16far fn_0fbe_1cf7(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  
  fn_154c_000f();
  fn_130a_0784();
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  uVar3 = fn_0845_06f8(0x230a,*(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 2) * 2 + 0x2c),
                        param_1,0,0x30000);
  fn_130a_03cd(*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c),1,uVar3);
  return;
}


//// fn_0fbe_1d58 @ 1fbe:1d58

undefined2 __cdecl16far fn_0fbe_1d58(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + (*(int *)(iVar1 + 0xc) + 3) * 2 + 0x2c) == 0) {
    fn_070c_0a8f(*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                  *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c),1);
    if (*(int *)(iVar1 + (*(int *)(iVar1 + 0xc) + 2) * 2 + 0x2c) != 0) {
      fn_0a21_022b(*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c));
    }
  }
  else {
    ovr_2d18_002a(*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                  *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c));
  }
  return 1;
}


//// fn_0fbe_1df1 @ 1fbe:1df1

undefined2 __cdecl16far fn_0fbe_1df1(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  fn_067a_003e(0x1fbe,*(undefined2 *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c));
  return 1;
}


//// fn_0fbe_1e0e @ 1fbe:1e0e

void __cdecl16far fn_0fbe_1e0e(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  fn_067a_01d1(*(undefined2 *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c));
  return;
}


//// fn_0fbe_1e28 @ 1fbe:1e28

int __cdecl16far fn_0fbe_1e28(undefined4 param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined4 local_6;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = 0;
  uVar2 = *(uint *)(*(int *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c) * 10 + -0x7df9)
  ;
  while (uVar2 != 0) {
    if ((uVar2 & 0x8000) == 0) {
      iVar3 = iVar3 + 1;
    }
    puVar1 = (uint *)fn_080e_000b(uVar2);
    local_6 = (uint *)CONCAT22(uVar2,puVar1);
    uVar2 = *local_6;
  }
  return iVar3;
}


//// fn_0fbe_1e6c @ 1fbe:1e6c

int __cdecl16far fn_0fbe_1e6c(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  int local_6;
  
  local_6 = -1;
  iVar5 = 0;
  uVar6 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  iVar2 = *(int *)(iVar3 + *(int *)(iVar3 + 0xc) * 2 + 0x2c);
  for (iVar4 = 0; iVar1 = ovr_2d74_0025(), iVar4 < iVar1; iVar4 = iVar4 + 1) {
    iVar1 = iVar4 * 0x82 + 0x362d;
    iVar1 = ((int)*(char *)(iVar1 + iVar2 + 0x69) + (int)*(char *)(iVar1 + iVar2 + 0x66)) * 10 +
            *(int *)(iVar3 + (*(int *)(iVar3 + 0xc) + 1) * 2 + 0x2c) + 0x19;
    if (iVar5 < iVar1) {
      iVar5 = iVar1;
      local_6 = iVar4;
    }
  }
  iVar2 = fn_0845_0636(0x640001);
  if (iVar5 < iVar2) {
    local_6 = -1;
  }
  return local_6;
}


//// fn_0fbe_1f05 @ 1fbe:1f05

int __cdecl16far fn_0fbe_1f05(void)

{
  int iVar1;
  int iVar2;
  undefined2 local_6;
  
  iVar2 = 0;
  local_6 = 0x15fa;
  iVar1 = 0;
  do {
    if ((0 < *(int *)(local_6 + 0x1d)) && (*(char *)(local_6 + 0x14) != '\r')) {
      iVar2 = iVar2 + 1;
    }
    iVar1 = iVar1 + 1;
    local_6 = local_6 + 0x2e;
  } while (iVar1 < 0x1e);
  return iVar2;
}


//// fn_0fbe_1f39 @ 1fbe:1f39

undefined2 __cdecl16far fn_0fbe_1f39(void)

{
  fn_154c_000f(1);
  fn_130a_0784();
  return 1;
}


//// fn_0fbe_1f4e @ 1fbe:1f4e

undefined2 __cdecl16far fn_0fbe_1f4e(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = 0;
  while (((*(uint *)((int)(undefined4 *)&g_362a + iVar1 * 0x82 + 3) & 9) == 0 ||
         (*(int *)((int)(undefined2 *)&g_363a + iVar1 * 0x82 + 1) !=
          *(int *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c)))) {
    iVar1 = iVar1 + 1;
    if (3 < iVar1) {
      return 0;
    }
  }
  return 1;
}


//// fn_0fbe_1fa0 @ 1fbe:1fa0

undefined2 __cdecl16far fn_0fbe_1fa0(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  uVar1 = *(undefined2 *)(iVar3 + *(int *)(iVar3 + 0xc) * 2 + 0x2c);
  iVar2 = *(int *)(iVar3 + (*(int *)(iVar3 + 0xc) + 2) * 2 + 0x2c);
  uVar5 = fn_0845_06f8(0x1fbe,*(undefined2 *)(iVar3 + (*(int *)(iVar3 + 0xc) + 1) * 2 + 0x2c),
                        *(undefined2 *)(iVar3 + (*(int *)(iVar3 + 0xc) + 3) * 2 + 0x2c),
                        *(undefined2 *)(iVar3 + (*(int *)(iVar3 + 0xc) + 4) * 2 + 0x2c),
                        *(undefined2 *)(iVar3 + (*(int *)(iVar3 + 0xc) + 5) * 2 + 0x2c),
                        *(undefined2 *)(iVar3 + (*(int *)(iVar3 + 0xc) + 6) * 2 + 0x2c),
                        *(undefined2 *)(iVar3 + (*(int *)(iVar3 + 0xc) + 7) * 2 + 0x2c),
                        *(undefined2 *)(iVar3 + (*(int *)(iVar3 + 0xc) + 8) * 2 + 0x2c),
                        *(undefined2 *)(iVar3 + (*(int *)(iVar3 + 0xc) + 9) * 2 + 0x2c));
  fn_0845_01c4((char *)s_Lib_error_29_3e2d_1842 + 3,uVar1,uVar5);
  if (0 < iVar2) {
    fn_067a_0401(iVar2,0);
  }
  return 1;
}


//// fn_0fbe_2087 @ 1fbe:2087

void __cdecl16far fn_0fbe_2087(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  fn_070c_0793(0x1fbe,*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 2) * 2 + 0x2c));
  return;
}


//// fn_0fbe_20c5 @ 1fbe:20c5

void __cdecl16far fn_0fbe_20c5(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  fn_070c_07e3(*(undefined2 *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c));
  return;
}


//// fn_0fbe_20df @ 1fbe:20df

undefined2 __cdecl16far fn_0fbe_20df(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = *(int *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c);
  if (*(int *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 2 + iVar1 * 0x10) != 0) {
    fn_07bc_0367(iVar1,*(undefined2 *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 2 + iVar1 * 0x10));
  }
  fn_07bc_044c(iVar1);
  return 1;
}


//// fn_0fbe_2126 @ 1fbe:2126

void __cdecl16far fn_0fbe_2126(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  fn_070c_06a3(0x1fbe,*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 2) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 3) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 4) * 2 + 0x2c));
  return;
}


//// fn_0fbe_2188 @ 1fbe:2188

int __cdecl16far fn_0fbe_2188(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 local_6;
  undefined2 local_4;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  fn_1aff_030e(&local_4);
  iVar1 = fn_0b6b_032f(*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                        *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c),local_4,
                        local_6,*(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 5) * 2 + 0x2c),
                        *(int *)(iVar1 + (*(int *)(iVar1 + 0xc) + 6) * 2 + 0x2c) << 1,
                        *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 7) * 2 + 0x2c),
                        *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 8) * 2 + 0x2c),0x3f);
  if (iVar1 == 0) {
    fn_07bc_044c();
  }
  return iVar1;
}


//// fn_0fbe_2290 @ 1fbe:2290

undefined2 __cdecl16far fn_0fbe_2290(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  fn_0bbc_0365(*(int *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c) * 0x82 + 0x362d,
                (undefined1 *)&g_3803,
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 2) * 2 + 0x2c));
  return 1;
}


//// fn_0fbe_22dc @ 1fbe:22dc

undefined2 __cdecl16far fn_0fbe_22dc(void)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (((undefined2 *)&g_7fe6)[iVar1] == 0) {
      return 0;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x30);
  return 1;
}


//// fn_0fbe_22fb @ 1fbe:22fb

undefined2 __cdecl16far fn_0fbe_22fb(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  undefined2 in_DX;
  int iVar8;
  uint uVar9;
  undefined2 uVar10;
  undefined4 local_10;
  undefined2 local_8;
  
  local_8 = 0;
  uVar10 = (undefined2)((ulong)param_1 >> 0x10);
  iVar8 = (int)param_1;
  uVar1 = *(undefined2 *)(iVar8 + (*(int *)(iVar8 + 0xc) + 1) * 2 + 0x2c);
  iVar2 = *(int *)(iVar8 + (*(int *)(iVar8 + 0xc) + 2) * 2 + 0x2c);
  iVar3 = *(int *)(iVar8 + (*(int *)(iVar8 + 0xc) + 3) * 2 + 0x2c);
  iVar4 = *(int *)(iVar8 + (*(int *)(iVar8 + 0xc) + 5) * 2 + 0x2c);
  uVar5 = *(uint *)(*(int *)(iVar8 + *(int *)(iVar8 + 0xc) * 2 + 0x2c) * 10 + -0x7df9);
LAB_1fbe_247c:
  do {
    uVar9 = uVar5;
    if (uVar9 == 0) {
      return local_8;
    }
    puVar6 = (uint *)fn_080e_000b();
    local_10 = (uint *)CONCAT22(in_DX,puVar6);
    uVar5 = *local_10;
    if ((uVar9 & 0x8000) == 0) goto LAB_1fbe_2397;
  } while (iVar3 == 0);
  iVar7 = (uVar9 & 0x7fff) * 0x2e + 0x15fa;
  fn_0d6c_0995(iVar7,(undefined1 *)&g_3803,0xe);
  fn_0845_046c();
  fn_0d6c_0742(iVar7,(undefined1 *)&g_3803,0);
  goto LAB_1fbe_2477;
LAB_1fbe_2397:
  if (((*(uint *)(uVar9 * 0x10 + 0x1d0b) & 0x4000) != 0) && (iVar4 != 0)) {
    fn_130a_0052(uVar9,iVar2,uVar1,
                  *(uint *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 4 + uVar9 * 0x10) & 0xff,
                  *(uint *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 6 + uVar9 * 0x10) & 0xff,
                  ((char *)s_ADLIBG_ADV_3e2d_1d00 + 1)[uVar9 * 0x10]);
    if ((*(int *)(iVar8 + (*(int *)(iVar8 + 0xc) + 4) * 2 + 0x2c) != 0) && (g_7fe5 == iVar2))
    {
      fn_0845_1343(uVar1,0x80,0xffff,uVar9,0);
    }
LAB_1fbe_2477:
    local_8 = 1;
  }
  goto LAB_1fbe_247c;
}


//// fn_0fbe_248a @ 1fbe:248a

undefined2 __cdecl16far fn_0fbe_248a(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  if (*(int *)((int)param_1 + (*(int *)((int)param_1 + 0xc) + 1) * 2 + 0x2c) == 0) {
    ovr_2d5f_0133(0);
  }
  else {
    ovr_2d5f_012e();
  }
  return 1;
}


//// fn_0fbe_24b4 @ 1fbe:24b4

undefined2 __cdecl16far fn_0fbe_24b4(undefined4 param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  uVar2 = fn_0845_06f8(0x1fbe,*(undefined2 *)
                                ((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c),param_1,0,
                        0x10000);
  fn_130a_0a7c(3,uVar2);
  return 1;
}


//// fn_0fbe_24e9 @ 1fbe:24e9

undefined2 __cdecl16far fn_0fbe_24e9(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  iVar1 = fn_154c_01d3(*(undefined2 *)(iVar2 + *(int *)(iVar2 + 0xc) * 2 + 0x2c),0);
  if ((iVar1 == 0) || (g_81fd._1_1_ != '\0')) {
    uVar4 = fn_0845_06f8(0x254c,*(undefined2 *)(iVar2 + *(int *)(iVar2 + 0xc) * 2 + 0x2c),param_1,0
                          ,0x10000);
    fn_130a_0a7c(4,uVar4);
  }
  return 1;
}


//// fn_0fbe_254c @ 1fbe:254c

bool __cdecl16far fn_0fbe_254c(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  iVar1 = 0;
  while( true ) {
    uVar3 = (undefined2)((ulong)param_1 >> 0x10);
    iVar2 = (int)param_1;
    if (((int)*(char *)(iVar1 * 0x2e + 0x161a) == *(int *)(iVar2 + *(int *)(iVar2 + 0xc) * 2 + 0x2c)
        ) || (*(int *)(iVar2 + *(int *)(iVar2 + 0xc) * 2 + 0x2c) == -1)) break;
    iVar1 = iVar1 + 1;
    if (0x1d < iVar1) {
      return true;
    }
  }
  return *(char *)(iVar1 * 0x2e + 0x160e) != '\x01';
}


//// fn_0fbe_25aa @ 1fbe:25aa

undefined2 __cdecl16far fn_0fbe_25aa(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  g_20d7 = *(undefined2 *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c);
  return 1;
}


//// fn_0fbe_25c4 @ 1fbe:25c4

undefined2 __cdecl16far fn_0fbe_25c4(void)

{
  fn_0845_0bf6();
  return 1;
}


//// fn_0fbe_25d1 @ 1fbe:25d1

undefined2 __cdecl16far fn_0fbe_25d1(undefined4 param_1)

{
  undefined2 uVar1;
  undefined4 local_6;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  local_6 = CONCAT22((undefined1 *)&g_3803,
                     (*(uint *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c) & 0x7fff) *
                     0x2e + 0x15fa);
  fn_0d6c_0995();
  fn_0845_046c();
  fn_0d6c_0742(local_6,0);
  return 1;
}


//// fn_0fbe_262d @ 1fbe:262d

undefined2 __cdecl16far fn_0fbe_262d(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  g_4bea = *(undefined2 *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c);
  return 1;
}


//// fn_0fbe_2647 @ 1fbe:2647

undefined2 __cdecl16far fn_0fbe_2647(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  
  fn_15a7_0964();
  fn_154c_0136();
  iVar1 = fn_2169_060c();
  if (((iVar1 != 0) && (uVar2 = fn_2169_0790(), uVar2 != 0)) && ((uVar2 & 0x800) == 0)) {
    uVar3 = (undefined2)((ulong)param_1 >> 0x10);
    if (*(int *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c) == 0) {
      fn_2169_062e();
    }
    else {
      fn_2169_0945(uVar2);
      g_20ec = 1;
    }
    return 1;
  }
  return 0;
}


//// fn_0fbe_269d @ 1fbe:269d

undefined2 __cdecl16far fn_0fbe_269d(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  iVar1 = *(int *)(iVar3 + *(int *)(iVar3 + 0xc) * 2 + 0x2c);
  uVar2 = *(uint *)(iVar3 + (*(int *)(iVar3 + 0xc) + 1) * 2 + 0x2c);
  fn_14b3_0122();
  if ((uVar2 & 1) != 0) {
    fn_14b3_0215();
  }
  if ((uVar2 & 3) != 0) {
    *(undefined2 *)(iVar1 * 0x10 + 0x1f47) = 0;
    *(undefined2 *)(iVar1 * 0x10 + 0x1f49) = 0;
  }
  uVar5 = fn_0845_06f8(0x24b3,*(undefined2 *)(iVar3 + (*(int *)(iVar3 + 0xc) + 2) * 2 + 0x2c),
                        param_1,0,0x30000);
  fn_130a_0a7c(iVar1,uVar5);
  return 1;
}


//// fn_0fbe_2725 @ 1fbe:2725

int __cdecl16far fn_0fbe_2725(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined2 uVar4;
  undefined2 local_6;
  
  uVar3 = 0;
  iVar1 = 0;
  while (uVar4 = (undefined2)((ulong)param_1 >> 0x10), iVar2 = (int)param_1,
        *(int *)(iVar2 + (*(int *)(iVar2 + 0xc) + iVar1) * 2 + 0x2c) != -1) {
    uVar3 = uVar3 | 1 << (*(byte *)(iVar2 + (*(int *)(iVar2 + 0xc) + iVar1) * 2 + 0x2c) & 0x1f);
    iVar1 = iVar1 + 1;
  }
  local_6 = 0x15fa;
  iVar2 = 0;
  for (iVar1 = 0; iVar1 < 0x1e; iVar1 = iVar1 + 1) {
    if (((uVar3 & 1 << (*(byte *)(local_6 + 0x20) & 0x1f)) != 0) &&
       (*(char *)(local_6 + 0x14) < '\x0e')) {
      iVar2 = iVar2 + 1;
    }
    local_6 = local_6 + 0x2e;
  }
  return iVar2;
}


//// fn_0fbe_2798 @ 1fbe:2798

undefined2 __cdecl16far fn_0fbe_2798(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1 + *(int *)((int)param_1 + 0xc) * 2;
  if (0x61 < *(int *)(iVar1 + 0x32)) {
    ovr_2ce1_007f((char *)s_Cmd_Animate_Wall__Too_many_anim_f_3e2d_27af,0x3e2d);
  }
  fn_130a_0360(*(undefined2 *)(iVar1 + 0x2c),*(undefined2 *)(iVar1 + 0x2e),
                ((undefined2 *)(iVar1 + 0x2c))
                [*(uint *)(iVar1 + 0x30) % *(uint *)(iVar1 + 0x32) + 4]);
  return 0;
}


//// fn_0fbe_27f6 @ 1fbe:27f6

undefined2 __cdecl16far fn_0fbe_27f6(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  int local_4;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  iVar2 = *(int *)(iVar3 + *(int *)(iVar3 + 0xc) * 2 + 0x2c);
  iVar1 = *(int *)(iVar3 + (*(int *)(iVar3 + 0xc) + 1) * 2 + 0x2c);
  if (*(int *)(iVar3 + (*(int *)(iVar3 + 0xc) + 2) * 2 + 0x2c) == 0) {
    iVar3 = 0;
    do {
      if ((((undefined2 *)&g_7fe6)[iVar3] != 0) &&
         (*(int *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 9 + ((undefined2 *)&g_7fe6)[iVar3] * 0x10
                  ) == iVar1)) {
        return 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x30);
    iVar3 = fn_0845_0ac7();
    if (*(int *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 9 + iVar3 * 0x10) == iVar1) {
      return 1;
    }
  }
  local_4 = iVar2;
  if (iVar2 == -1) {
    iVar2 = 0;
    local_4 = 3;
  }
  while( true ) {
    if (local_4 < iVar2) {
      return 0;
    }
    iVar3 = fn_0a21_0997(iVar2,iVar1);
    if (iVar3 != 0) break;
    iVar2 = iVar2 + 1;
  }
  return 1;
}


//// fn_0fbe_28b5 @ 1fbe:28b5

void __cdecl16far fn_0fbe_28b5(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  g_4be0 = *(undefined2 *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c);
  return;
}


//// fn_0fbe_28cc @ 1fbe:28cc

undefined2 __cdecl16far fn_0fbe_28cc(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = *(int *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c) * 4;
  uVar3 = *(undefined2 *)(iVar2 + 0x20fe);
  iVar2 = *(int *)(iVar2 + 0x20fc);
  *(undefined2 *)(iVar2 + 2) = 0;
  g_4bb2 = 0;
  iVar1 = g_4bde;
  if (g_4bde == 0) {
    iVar1 = 1;
  }
  *(int *)(iVar2 + 4) = iVar1;
  g_4bb4 = 0xffff;
  return 1;
}


//// fn_0fbe_2922 @ 1fbe:2922

uint __cdecl16far fn_0fbe_2922(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  uVar2 = *(uint *)(iVar3 + (*(int *)(iVar3 + 0xc) + 1) * 2 + 0x2c);
  if (uVar2 != 0xffff) {
    uVar2 = uVar2 & 0xff;
  }
  uVar1 = *(uint *)(iVar3 + (*(int *)(iVar3 + 0xc) + 2) * 2 + 0x2c);
  if (uVar1 != 0xffff) {
    uVar1 = uVar1 & 0xff;
  }
  if ((*(int *)(iVar3 + (*(int *)(iVar3 + 0xc) + 3) * 2 + 0x2c) != 0) || (g_2794 == 0xffff))
  {
    g_2794 = *(uint *)(iVar3 + *(int *)(iVar3 + 0xc) * 2 + 0x2c);
  }
  do {
    g_2794 = *(uint *)(g_2794 * 10 + -0x7df9);
    if (g_2794 == 0) {
      return 0;
    }
    if (((g_2794 & 0x8000) == 0) &&
       ((uVar2 == 0xffff ||
        ((*(uint *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 4 + g_2794 * 0x10) & 0xff) == uVar2))))
    {
      if (uVar1 == 0xffff) {
        return g_2794;
      }
      if ((*(uint *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 6 + g_2794 * 0x10) & 0xff) == uVar1) {
        return g_2794;
      }
    }
    g_2794 = g_2794 & 0x7fff;
  } while( true );
}


//// fn_0fbe_29f0 @ 1fbe:29f0

undefined2 __cdecl16far fn_0fbe_29f0(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  fn_07bc_0367(*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c));
  return 1;
}


//// fn_0fbe_2a1f @ 1fbe:2a1f

uint __cdecl16far fn_0fbe_2a1f(undefined4 param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined4 local_6;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  uVar2 = *(uint *)(iVar3 + (*(int *)(iVar3 + 0xc) + 1) * 2 + 0x2c);
  if (uVar2 != 0xffff) {
    puVar1 = (uint *)fn_080e_000b(uVar2 | 0x8000);
    local_6 = (uint *)CONCAT22(uVar2,puVar1);
    goto LAB_1fbe_2a87;
  }
  uVar4 = *(uint *)(*(int *)(iVar3 + *(int *)(iVar3 + 0xc) * 2 + 0x2c) * 10 + -0x7df9);
  while( true ) {
    if (uVar4 == 0) {
      return 0xffff;
    }
    puVar1 = (uint *)fn_080e_000b(uVar4);
    local_6 = (uint *)CONCAT22(uVar2,puVar1);
    if ((uVar4 & 0x8000) != 0) break;
LAB_1fbe_2a87:
    uVar4 = *local_6;
  }
  return uVar4 & 0x7fff;
}


//// fn_0fbe_2a97 @ 1fbe:2a97

uint __cdecl16far fn_0fbe_2a97(undefined4 param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined4 local_6;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  uVar4 = *(uint *)(iVar3 + (*(int *)(iVar3 + 0xc) + 1) * 2 + 0x2c) | 0x8000;
  uVar2 = *(uint *)(*(int *)(iVar3 + *(int *)(iVar3 + 0xc) * 2 + 0x2c) * 10 + -0x7df9);
  while( true ) {
    if ((uVar2 & 0x8000) == 0) {
      return 0xffff;
    }
    if ((uVar4 == 0xffff) || (uVar2 == uVar4)) break;
    puVar1 = (uint *)fn_080e_000b(uVar2);
    local_6 = (uint *)CONCAT22(uVar2,puVar1);
    uVar2 = *local_6;
  }
  return uVar2 & 0x7fff;
}


//// fn_0fbe_2aff @ 1fbe:2aff

undefined2 __cdecl16far fn_0fbe_2aff(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  fn_1ebc_00e7();
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  ovr_2d46_0039(*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 2) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 3) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 4) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 5) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 6) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 7) * 2 + 0x2c));
  fn_1ebc_00fe();
  return 1;
}


//// fn_0fbe_2ba4 @ 1fbe:2ba4

undefined2 __cdecl16far fn_0fbe_2ba4(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 local_4;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  local_4 = *(undefined2 *)(iVar2 + *(int *)(iVar2 + 0xc) * 2 + 0x2c);
  uVar1 = *(undefined2 *)(iVar2 + (*(int *)(iVar2 + 0xc) + 1) * 2 + 0x2c);
  fn_1aff_03b4(&local_4);
  if (*(int *)(iVar2 + (*(int *)(iVar2 + 0xc) + 3) * 2 + 0x2c) != 0) {
    uVar1 = local_4;
  }
  return uVar1;
}


//// fn_0fbe_2c12 @ 1fbe:2c12

int __cdecl16far fn_0fbe_2c12(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  if (*(int *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c) == 0) goto LAB_1fbe_2c4c;
  g_2796 = 0;
  while( true ) {
    if (3 < g_2796) {
      return -1;
    }
    if ((*(uint *)((int)(undefined4 *)&g_362a + g_2796 * 0x82 + 3) & 1) != 0) break;
LAB_1fbe_2c4c:
    g_2796 = g_2796 + 1;
  }
  return g_2796;
}


//// fn_0fbe_2c5c @ 1fbe:2c5c

void __cdecl16far fn_0fbe_2c5c(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  ovr_2d00_0025(*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 2) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 3) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 4) * 2 + 0x2c));
  return;
}


//// fn_0fbe_2cbe @ 1fbe:2cbe

undefined2 __cdecl16far fn_0fbe_2cbe(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c) == -1) {
    fn_0a21_05ce();
  }
  else {
    fn_0a21_022b(*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c));
  }
  return 1;
}


//// fn_0fbe_2cf4 @ 1fbe:2cf4

undefined2 __cdecl16far fn_0fbe_2cf4(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = *(int *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c);
  iVar3 = 0;
  do {
    if ((((undefined2 *)&g_7fe6)[iVar3] != 0) &&
       (*(int *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 9 + ((undefined2 *)&g_7fe6)[iVar3] * 0x10)
        == iVar1)) {
      ((undefined2 *)&g_7fe6)[iVar3] = 0;
      fn_0c59_0377();
      return 1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x30);
  iVar3 = 0;
  do {
    if ((*(uint *)((int)(undefined4 *)&g_362a + iVar3 * 0x82 + 3) & 1) != 0) {
      iVar2 = 0;
      do {
        if ((*(int *)(iVar3 * 0x82 + iVar2 * 2 + 0x367d) != 0) &&
           (*(int *)((char *)s_ADLIBG_ADV_3e2d_1d00 + 9 +
                    *(int *)(iVar3 * 0x82 + iVar2 * 2 + 0x367d) * 0x10) == iVar1)) {
          *(undefined2 *)(iVar3 * 0x82 + iVar2 * 2 + 0x367d) = 0;
          return 1;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0xb);
    }
    iVar3 = iVar3 + 1;
    if (3 < iVar3) {
      return 0;
    }
  } while( true );
}


//// fn_0fbe_2dc7 @ 1fbe:2dc7

undefined2 __cdecl16far fn_0fbe_2dc7(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  fn_231c_0008(*(undefined2 *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c));
  return 1;
}


//// fn_0fbe_2de4 @ 1fbe:2de4

undefined2 __cdecl16far fn_0fbe_2de4(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  fn_231c_0048(*(undefined2 *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c));
  return 1;
}


//// fn_0fbe_2e01 @ 1fbe:2e01

int __cdecl16far fn_0fbe_2e01(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  cVar1 = *(char *)(*(int *)(iVar2 + *(int *)(iVar2 + 0xc) * 2 + 0x2c) * 0xb5 + 0x4ef4);
  *(undefined1 *)(*(int *)(iVar2 + *(int *)(iVar2 + 0xc) * 2 + 0x2c) * 0xb5 + 0x4ef4) = 0xff;
  return (int)cVar1;
}


//// fn_0fbe_2e3f @ 1fbe:2e3f

void __cdecl16far fn_0fbe_2e3f(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  fn_130a_0d2b(*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 2) * 2 + 0x2c));
  return;
}


//// fn_0fbe_2e7d @ 1fbe:2e7d

undefined2 __cdecl16far fn_0fbe_2e7d(void)

{
  fn_2279_025b((int)g_540e + 0x180,g_540e._2_2_,(int)g_adea + 0x180,
                g_adea._2_2_,0x180);
  fn_1ef2_0075(g_adea,10,0);
  g_20d5 = 0;
  return 1;
}


//// fn_0fbe_2ec1 @ 1fbe:2ec1

int __cdecl16far fn_0fbe_2ec1(void)

{
  return (int)g_7fe3;
}


//// fn_0fbe_2eca @ 1fbe:2eca

void __cdecl16far fn_0fbe_2eca(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  fn_09aa_0183(*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c));
  return;
}


//// fn_0fbe_2ef6 @ 1fbe:2ef6

undefined2 __cdecl16far fn_0fbe_2ef6(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  fn_0845_0acf(*(undefined2 *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c));
  return 1;
}


//// fn_0fbe_2f13 @ 1fbe:2f13

void __cdecl16far fn_0fbe_2f13(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  fn_0c59_0410(*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c));
  return;
}


//// fn_0fbe_2f3f @ 1fbe:2f3f

void __cdecl16far fn_0fbe_2f3f(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  ovr_2d8a_0039(*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 2) * 2 + 0x2c));
  return;
}


//// fn_0fbe_2f7d @ 1fbe:2f7d

undefined2 __cdecl16far fn_0fbe_2f7d(void)

{
  int iVar1;
  undefined2 unaff_SS;
  undefined1 local_402 [256];
  undefined1 local_302 [768];
  
  fn_0845_0f86((int)g_540e,(int)((ulong)g_540e >> 0x10),local_302);
  fn_0845_1430(local_302);
  fn_0845_1430(g_540e);
  if (g_1f3a != '\0') {
    iVar1 = 0;
    do {
      local_402[iVar1] = (char)iVar1;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x100);
    local_402[1] = 6;
    fn_234e_0003();
    fn_1dbc_0017(0x334e,0xe,0xe,0,0x16,0x78,0x20000);
    fn_1f24_003f();
    fn_234e_0062();
  }
  fn_1ef2_001c(local_302);
  fn_1ebc_022a(0xc,1,2);
  fn_2120_0007();
  fn_1ef2_001c(g_540e);
  if (g_1f3a != '\0') {
    fn_234e_0003();
    fn_1dbc_0017(0x334e,0xe,0xe,0,0x16,0x78,2);
    fn_234e_0062();
  }
  return 0;
}


//// fn_0fbe_3081 @ 1fbe:3081

void __cdecl16far fn_0fbe_3081(void)

{
  ovr_2cf7_0020();
  return;
}


//// fn_0fbe_308b @ 1fbe:308b

undefined2 __cdecl16far fn_0fbe_308b(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = *(int *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c);
  if (((((iVar1 < 0x46) || (0x4a < iVar1)) && ((iVar1 < 0x51 || (0x59 < iVar1)))) &&
      ((iVar1 < 0x5d || (0x61 < iVar1)))) && ((iVar1 < 0x66 || (0x6a < iVar1)))) {
    uVar3 = CONCAT22(1,*(undefined2 *)
                        ((*(byte *)((int)g_7fb2 + iVar1 * 0xd + 9) & 3) * 2 + 0x2798));
  }
  else {
    uVar3 = 0x1000c;
  }
  fn_067a_0401(uVar3);
  return 1;
}


//// fn_0fbe_30f8 @ 1fbe:30f8

undefined2 __cdecl16far fn_0fbe_30f8(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  ovr_2d28_0034(*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 2) * 2 + 0x2c),1);
  return 1;
}


//// fn_0fbe_313b @ 1fbe:313b

undefined2 __cdecl16far fn_0fbe_313b(undefined4 param_1)

{
  byte *pbVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if (*(int *)(iVar2 + (*(int *)(iVar2 + 0xc) + 1) * 2 + 0x2c) == 0) {
    pbVar1 = (byte *)(*(int *)(iVar2 + *(int *)(iVar2 + 0xc) * 2 + 0x2c) * 10 + -0x7df4);
    *pbVar1 = *pbVar1 & 0xdf;
  }
  else {
    pbVar1 = (byte *)(*(int *)(iVar2 + *(int *)(iVar2 + 0xc) * 2 + 0x2c) * 10 + -0x7df4);
    *pbVar1 = *pbVar1 & 0xef;
    pbVar1 = (byte *)(*(int *)(iVar2 + *(int *)(iVar2 + 0xc) * 2 + 0x2c) * 10 + -0x7df4);
    *pbVar1 = *pbVar1 | 0x20;
  }
  return 1;
}


//// fn_0fbe_319d @ 1fbe:319d
// FAILED
//// fn_0fbe_3244 @ 1fbe:3244

void __cdecl16far fn_0fbe_3244(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  fn_0845_1280(*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 2) * 2 + 0x2c));
  return;
}


//// fn_0fbe_3282 @ 1fbe:3282

undefined2 __cdecl16far fn_0fbe_3282(void)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 in_DX;
  undefined2 uVar3;
  
  if (f_2803_363b == -9) {
    uVar3 = 1;
  }
  else if (f_2803_363b == -5) {
    uVar3 = 3;
  }
  else if (f_2803_363b == -1) {
    uVar3 = 2;
  }
  else {
    uVar3 = 0;
  }
  do {
    iVar1 = fn_154c_0136();
  } while (iVar1 != 0);
  iVar1 = ovr_2d46_002f(0x27e7,0x3e2d,(int)g_20db);
  uVar2 = fn_0845_1036((undefined1 *)&g_ae59,0x3e2d);
  sprintf(0xad99,0x3e2d,(char *)s__d_HOMIE__d__s_3e2d_27e9,0x3e2d,uVar3,uVar2);
  fn_2309_000c();
  fn_0845_1536();
  fn_2148_002c();
  fn_2148_014d((undefined1 *)&g_aeaa,0x3e2d);
  fn_2148_014d(iVar1 + 2,in_DX);
  execl((char *)s_FINALE_EXE_3e2d_27f8,0x3e2d,(char *)s_FINALE_EXE_3e2d_2803,0x3e2d,0xad99,
                0x3e2d,0);
  return 0;
}


//// fn_0fbe_333f @ 1fbe:333f

undefined2 __cdecl16far fn_0fbe_333f(void)

{
  ovr_2d2c_00e8();
  return 0;
}


//// fn_0fbe_334b @ 1fbe:334b

undefined2 __cdecl16far fn_0fbe_334b(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  uVar1 = *(undefined2 *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c);
  fn_0845_155d(uVar1,uVar1);
  return 1;
}


//// fn_0fbe_336f @ 1fbe:336f

undefined2 __cdecl16far fn_0fbe_336f(void)

{
  fn_0845_15d9();
  fn_234e_0003();
  ovr_2d46_0039(0x70,0x70,0x7800b0,2);
  fn_0845_08aa();
  fn_234e_0062();
  return 1;
}


//// fn_0fbe_33a8 @ 1fbe:33a8

undefined2 __cdecl16far fn_0fbe_33a8(void)

{
  fn_0845_08aa(0x1fbe);
  return 1;
}


//// fn_0fbe_33b5 @ 1fbe:33b5

undefined2 __cdecl16far fn_0fbe_33b5(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c) == -1) {
    fn_154c_000f(1);
    uVar2 = 1;
  }
  else if (*(int *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c) == -2) {
    uVar2 = fn_154c_0136();
  }
  else {
    uVar2 = fn_154c_0057(*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                          *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c),
                          *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 2) * 2 + 0x2c));
  }
  return uVar2;
}


//// fn_0fbe_342b @ 1fbe:342b

void __cdecl16far fn_0fbe_342b(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  fn_154c_010f(*(undefined2 *)(iVar1 + *(int *)(iVar1 + 0xc) * 2 + 0x2c),
                *(undefined2 *)(iVar1 + (*(int *)(iVar1 + 0xc) + 1) * 2 + 0x2c));
  return;
}


//// fn_0fbe_3457 @ 1fbe:3457

int __cdecl16far fn_0fbe_3457(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  int *local_6;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = *(int *)((int)param_1 + *(int *)((int)param_1 + 0xc) * 2 + 0x2c);
  if (iVar1 < 0) {
    if (-iVar1 < 0x32) {
      iVar1 = 0x32;
    }
    else {
      iVar1 = ((-iVar1 + 99) / 100) * 100;
    }
  }
  else {
    local_6 = &f_2c0c_0000;
    while (*local_6 != 0) {
      if (iVar1 <= *local_6) {
        return *local_6;
      }
      local_6 = (int *)CONCAT22(local_6._2_2_,(int *)local_6 + 1);
    }
    iVar1 = 0;
  }
  return iVar1;
}


//// fn_0fbe_34b8 @ 1fbe:34b8

int __cdecl16far fn_0fbe_34b8(void)

{
  return (int)g_20db;
}

