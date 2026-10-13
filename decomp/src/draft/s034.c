//// fn_1809_0000 @ 2809:0000

int __cdecl16far fn_1809_0000(undefined4 param_1,uint param_2)

{
  char *pcVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  ulong in_EDX;
  int *piVar8;
  int iVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  undefined2 unaff_SS;
  undefined4 uStackY_68;
  char local_58 [14];
  undefined1 local_4a [20];
  undefined1 local_36 [20];
  long local_22;
  undefined4 local_1e;
  int local_1a;
  long local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  undefined2 local_6;
  int local_4;
  
  g_abde = g_abde + '\x01';
  local_14 = &f_2c12_0000;
  iVar9 = 0;
  do {
    if (*local_14 != 0) break;
    iVar9 = iVar9 + 1;
    local_14 = (int *)CONCAT22(local_14._2_2_,(int *)local_14 + 10);
  } while (iVar9 < 0x14);
  uVar13 = (undefined2)param_1;
  uVar12 = (undefined2)((ulong)param_1 >> 0x10);
  if (iVar9 == 0x14) {
    fn_1809_1319(3,uVar13,uVar12);
  }
  iVar4 = fn_1981_01af(uVar13,uVar12);
  puVar5 = (undefined4 *)fn_1981_02c0(iVar4,local_36);
  local_c = (undefined4 *)CONCAT22((int)in_EDX,puVar5);
  fn_2148_002c(g_ae59 + -0x41);
  local_8 = 0;
  if (iVar4 != -1) {
    uVar10 = (undefined2)((ulong)local_c >> 0x10);
    if (((*(uint *)((int)(undefined4 *)local_c + 0x12) & 0x1000) != 0) &&
       (((undefined4 *)local_c)[2] == 0)) {
      uVar6 = fn_2148_0121(uVar13,uVar12,0x8001,0x100);
      in_EDX = (ulong)uVar6;
      if (uVar6 != 0xffff) {
        fn_2148_004d(uVar6);
        local_8 = 1;
      }
    }
  }
  if (((param_2 & 2) != 0) && (iVar4 != -1)) {
    uVar10 = (undefined2)((ulong)local_c >> 0x10);
    puVar5 = (undefined4 *)local_c;
    if (puVar5[2] != 0) {
      if ((*(uint *)((int)puVar5 + 0x12) & 0x1000) == 0) {
        fn_1809_1319(9,uVar13,uVar12);
      }
      else {
        fn_203b_0203((int)puVar5[2],(int)((ulong)puVar5[2] >> 0x10));
        ((undefined4 *)local_c)[2] = 0;
        fn_1981_031f(iVar4,local_36);
      }
    }
  }
  uVar10 = (undefined2)in_EDX;
  uVar11 = (undefined2)((ulong)local_c >> 0x10);
  puVar5 = (undefined4 *)local_c;
  if ((puVar5[2] == 0) || (iVar4 == -1)) {
    if ((iVar4 == -1) ||
       ((((*(uint *)((int)puVar5 + 0x12) & 0x1000) == 0 || (local_8 != 0)) || ((param_2 & 2) != 0)))
       ) {
      local_6 = 0x8001;
      if (param_2 == 1) {
        local_6 = 0x8001;
      }
      else if (param_2 == 2) {
        local_6 = 0x8302;
      }
      else if (param_2 == 3) {
        local_6 = 0x8004;
      }
      else {
        fn_1809_1319(1,uVar13,uVar12);
      }
      if ((param_2 & 1) == 0) goto LAB_2809_0448;
      iVar7 = fn_1809_11b9(uVar13,uVar12);
      while (iVar7 != 0) {
LAB_2809_0448:
        local_4 = fn_1809_1460(uVar13,uVar12,local_6);
        uVar10 = (undefined2)in_EDX;
        if (local_4 != -1) {
          if ((local_8 != 0) && (iVar4 != -1)) {
            uVar13 = (undefined2)((ulong)local_c >> 0x10);
            puVar3 = (uint *)((int)(undefined4 *)local_c + 0x12);
            *puVar3 = *puVar3 & 0xefff;
            ((undefined4 *)local_c)[1] = 0;
            fn_1981_031f(iVar4,local_36);
          }
          if (iVar4 != -1) {
            uVar13 = fn_2148_0094(local_4,0,0,2);
            uStackY_68 = CONCAT22(uVar10,uVar13);
            ((undefined4 *)local_c)[1] = uStackY_68;
            fn_1981_031f(iVar4,local_36);
            fn_2148_0094(local_4,0,0,0);
          }
          uVar13 = (undefined2)((ulong)local_14 >> 0x10);
          piVar8 = (int *)local_14;
          piVar8[6] = iVar4;
          (piVar8 + 2)[0] = 0;
          (piVar8 + 2)[1] = 0;
          (piVar8 + 4)[0] = 0;
          (piVar8 + 4)[1] = 0;
          *local_14 = 0;
          piVar8[1] = local_4;
          piVar8[7] = param_2;
          if (iVar4 == -1) {
            (piVar8 + 8)[0] = 0;
            (piVar8 + 8)[1] = 0;
          }
          else {
            *(undefined4 *)(piVar8 + 8) = *local_c;
          }
          if ((param_2 & 2) == 0) goto LAB_2809_054b;
          goto LAB_2809_0555;
        }
        fn_2148_014d((undefined1 *)&g_aeaa,0x3e2d);
        fn_2148_014d((undefined1 *)&g_ae59,0x3e2d);
        iVar7 = fn_1809_12c0(2,uVar13,uVar12);
      }
      iVar9 = -1;
      goto LAB_2809_0589;
    }
    puVar5 = (undefined4 *)fn_1981_02c0(*(undefined1 *)(puVar5 + 4),local_4a);
    local_10 = (undefined4 *)CONCAT22((int)in_EDX,puVar5);
    uVar13 = fn_1981_0365((int)*local_10,(int)((ulong)*local_10 >> 0x10),param_2);
    iVar9 = fn_1809_0000(uVar13,(int)in_EDX);
    uVar13 = fn_1981_02c0(*(undefined1 *)((undefined4 *)local_c + 4),local_4a);
    uVar10 = (undefined2)in_EDX;
    local_10 = (undefined4 *)CONCAT22(uVar10,uVar13);
    local_14 = (int *)CONCAT22(0x3c12,(int *)(iVar9 * 0x14));
    if (((g_2aa9 == 0x37fc) && (g_2aa7 == 0)) &&
       ((*(uint *)(((int *)(iVar9 * 0x14))[6] * 0x14 + 0x12) & 0x100) == 0)) {
      local_1e = 0;
      local_22 = 0;
      while( true ) {
        uVar10 = (undefined2)in_EDX;
        fn_1809_084d();
        if (local_18 == 0) break;
        local_1a = 0;
        do {
          in_EDX = ZEXT24(local_58 + local_1a);
          fn_1809_084d();
          iVar7 = local_1a;
          local_1a = local_1a + 1;
        } while (local_58[iVar7] != '\0');
        local_1a = fn_1981_01af(local_58);
        if (local_1a != -1) {
          iVar7 = local_1a * 0x14;
          local_1e = CONCAT22(0x37fc,iVar7);
          if ((*(uint *)(iVar7 + 0x12) & 0x1000) != 0) {
            uVar13 = (undefined2)((ulong)local_14 >> 0x10);
            if ((uint)*(byte *)(iVar7 + 0x10) == ((int *)local_14)[6]) {
              in_EDX = local_18 + *(long *)(((int *)local_14)[6] * 0x14 + 0xc);
              *(ulong *)(iVar7 + 0xc) = in_EDX;
              if (local_22 != 0) {
                uVar13 = (undefined2)((ulong)local_22 >> 0x10);
                *(long *)((int)local_22 + 4) =
                     *(long *)(iVar7 + 0xc) - *(long *)((int)local_22 + 0xc);
              }
              local_22 = local_1e;
            }
          }
        }
      }
      if (local_22 != 0) {
        uVar13 = fn_1809_120c(iVar9);
        uVar12 = (undefined2)((ulong)local_22 >> 0x10);
        *(long *)((int)local_22 + 4) = CONCAT22(uVar10,uVar13) - *(long *)((int)local_22 + 0xc);
      }
      puVar3 = (uint *)(((int *)local_14)[6] * 0x14 + 0x12);
      *puVar3 = *puVar3 | 0x100;
    }
    ((undefined4 *)local_c)[2] = *(undefined4 *)((int)local_10 + 8);
    fn_1981_031f(iVar4,local_36);
    uVar13 = (undefined2)((ulong)local_14 >> 0x10);
    piVar8 = (int *)local_14;
    piVar8[6] = iVar4;
    *(undefined4 *)(piVar8 + 8) = *local_c;
    *(undefined4 *)(piVar8 + 4) = ((undefined4 *)local_c)[3];
    fn_1809_0e76(iVar9,0,0,0);
LAB_2809_054b:
    fn_1809_1502(iVar4,iVar9);
  }
  else {
    uVar13 = (undefined2)((ulong)local_14 >> 0x10);
    piVar8 = (int *)local_14;
    piVar8[6] = iVar4;
    *local_14 = 0;
    (piVar8 + 2)[0] = 0;
    (piVar8 + 2)[1] = 0;
    *(undefined4 *)(piVar8 + 8) = *local_c;
    piVar8[1] = 0;
    piVar8[7] = param_2;
    if ((*(uint *)((int)puVar5 + 0x12) & 0x1000) == 0) {
      local_10 = (undefined4 *)0x0;
    }
    else {
      uVar13 = fn_1981_02c0(*(undefined1 *)(puVar5 + 4),local_4a);
      local_10 = (undefined4 *)CONCAT22(uVar10,uVar13);
    }
    uVar13 = (undefined2)((ulong)local_14 >> 0x10);
    if (local_10 != (undefined4 *)0x0) {
      uVar12 = (undefined2)((ulong)local_10 >> 0x10);
      uVar11 = (undefined2)((ulong)local_c >> 0x10);
      puVar5 = (undefined4 *)local_c;
      if (*(long *)((int)local_10 + 8) == puVar5[2]) {
        *(undefined4 *)((int *)local_14 + 4) = puVar5[3];
        pcVar1 = (char *)((int)local_10 + 0x11);
        *pcVar1 = *pcVar1 + '\x01';
        fn_1981_031f(*(undefined1 *)(puVar5 + 4),local_4a);
        goto LAB_2809_0555;
      }
    }
    piVar2 = (int *)local_14 + 4;
    piVar2[0] = 0;
    piVar2[1] = 0;
  }
LAB_2809_0555:
  if (iVar4 != -1) {
    iVar7 = fn_1981_02c0(iVar4,local_36);
    local_c = (undefined4 *)CONCAT22(uVar10,iVar7);
    *(char *)(iVar7 + 0x11) = *(char *)(iVar7 + 0x11) + '\x01';
    fn_1981_031f(iVar4,local_36);
  }
LAB_2809_0589:
  g_abde = g_abde + -1;
  return iVar9;
}


//// fn_1809_058d @ 2809:058d

void __cdecl16far fn_1809_058d(int param_1)

{
  int iVar1;
  long *plVar2;
  undefined2 in_DX;
  long *plVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined1 local_38 [20];
  undefined1 local_24 [20];
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  int local_6;
  int local_4;
  
  local_4 = 0;
  local_6 = 0;
  local_c = (long *)0x0;
  local_10 = (long *)0x0;
  iVar1 = fn_1809_1279(param_1,4,0);
  if (iVar1 == 0) {
    return;
  }
  g_abde = g_abde + '\x01';
  iVar1 = *(int *)(param_1 * 0x14 + 0xc);
  plVar2 = (long *)fn_1981_02c0(iVar1,local_38);
  local_10 = (long *)CONCAT22(in_DX,plVar2);
  if (iVar1 != -1) {
    if ((*(uint *)((int)plVar2 + 0x12) & 0xff) == 1) {
      local_6 = 1;
    }
    else {
      *(uint *)((int)plVar2 + 0x12) = *(uint *)((int)plVar2 + 0x12) & 0xff00;
    }
    *(char *)((int)plVar2 + 0x11) = *(char *)((int)plVar2 + 0x11) + -1;
    local_8 = (uint)*(byte *)((int)plVar2 + 0x11);
    fn_1981_031f(iVar1,local_38);
    uVar4 = (undefined2)((ulong)local_10 >> 0x10);
    if ((*(uint *)((int)(long *)local_10 + 0x12) & 0x1000) != 0) {
      plVar2 = (long *)fn_1981_02c0((char)((long *)local_10)[4],local_24);
      local_c = (long *)CONCAT22(in_DX,plVar2);
      uVar4 = (undefined2)((ulong)local_10 >> 0x10);
      if (plVar2[2] == ((long *)local_10)[2]) {
        if ((*(uint *)((int)plVar2 + 0x12) & 0xff) == 1) {
          local_6 = 1;
        }
        else {
          *(uint *)((int)plVar2 + 0x12) = *(uint *)((int)plVar2 + 0x12) & 0xff00;
        }
        *(char *)((int)plVar2 + 0x11) = *(char *)((int)plVar2 + 0x11) + -1;
        local_8 = (uint)*(byte *)((int)plVar2 + 0x11);
        fn_1981_031f((char)((long *)local_10)[4],local_24);
      }
    }
  }
  if (iVar1 != -1) {
    uVar4 = (undefined2)((ulong)local_10 >> 0x10);
    plVar2 = (long *)local_10;
    if (plVar2[2] != 0) {
      if (local_c == (long *)0x0) {
LAB_2809_0719:
        if (((*(uint *)((int)plVar2 + 0x12) & 0x800) != 0) &&
           (*(char *)((int)plVar2 + 0x11) == '\0')) {
          fn_203b_0203(plVar2[2]);
          uVar4 = (undefined2)((ulong)local_10 >> 0x10);
          plVar2 = (long *)local_10;
LAB_2809_073e:
          plVar2[2] = 0;
          local_4 = 1;
        }
      }
      else {
        uVar5 = (undefined2)((ulong)local_c >> 0x10);
        plVar3 = (long *)local_c;
        if (plVar3[2] != plVar2[2]) goto LAB_2809_0719;
        if (*(char *)((int)plVar2 + 0x11) == '\0') {
          plVar2[2] = 0;
        }
        if ((*(char *)((int)plVar3 + 0x11) == '\0') &&
           ((*(uint *)((int)plVar3 + 0x12) & 0x800) != 0)) {
          fn_203b_0203(plVar3[2]);
          uVar4 = (undefined2)((ulong)local_c >> 0x10);
          plVar2 = (long *)local_c;
          goto LAB_2809_073e;
        }
      }
      fn_1981_031f(iVar1,local_38);
      if (local_c != (long *)0x0) {
        fn_1981_031f((char)((long *)local_10)[4],local_24);
      }
      if ((((local_6 == 0) && (local_4 == 0)) && (local_8 == 0)) &&
         ((*(uint *)((int)(long *)local_10 + 0x12) & 0x6000) == 0)) {
        iVar1 = 0;
        while( true ) {
          plVar2 = (long *)fn_1981_02c0(iVar1,local_38);
          local_10 = (long *)CONCAT22(in_DX,plVar2);
          if (*local_10 == 0) break;
          if (((plVar2[2] != 0) && (*(char *)((int)plVar2 + 0x11) == '\0')) &&
             ((*(uint *)((int)plVar2 + 0x12) & 0x6000) == 0)) {
            if ((*(uint *)((int)plVar2 + 0x12) & 0xff) == 0xff) {
              fn_203b_0203(plVar2[2]);
              ((long *)local_10)[2] = 0;
            }
            else {
              *(int *)((int)plVar2 + 0x12) = *(int *)((int)plVar2 + 0x12) + 1;
            }
            fn_1981_031f(iVar1,local_38);
          }
          iVar1 = iVar1 + 1;
        }
      }
      goto LAB_2809_0834;
    }
  }
  fn_2148_004d();
LAB_2809_0834:
  *(undefined2 *)(param_1 * 0x14) = 1;
  g_abde = g_abde + -1;
  return;
}


//// fn_1809_084d @ 2809:084d

undefined2 __cdecl16far fn_1809_084d(int param_1,ulong param_2,ulong param_3)

{
  long *plVar1;
  int iVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined2 uVar5;
  ulong in_EDX;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined1 local_32 [20];
  ulong local_1e;
  undefined4 local_1a;
  ulong local_16;
  int local_12;
  undefined2 uStack_10;
  ulong local_e;
  int local_a;
  long local_8;
  int local_4;
  
  if (((param_2 == 0) || (param_3 == 0)) || (iVar2 = fn_1809_1279(param_1,5,0,0), iVar2 == 0)) {
    uVar3 = 0;
  }
  else {
    g_abde = g_abde + '\x01';
    local_4 = *(int *)(param_1 * 0x14 + 2);
    local_a = *(int *)(param_1 * 0x14 + 0xc);
    local_12 = fn_1981_02c0(local_a,local_32);
    uStack_10 = (undefined2)in_EDX;
    local_8 = *(long *)(local_12 + 4);
    if (((local_8 != 0) && (local_a != -1)) &&
       ((*(long *)(local_12 + 4) != 0 &&
        (in_EDX = param_3,
        (ulong)(*(long *)(local_12 + 4) - *(long *)(param_1 * 0x14 + 4)) < param_3)))) {
      in_EDX = *(long *)(local_12 + 4) - *(long *)(param_1 * 0x14 + 4);
      param_3 = in_EDX;
    }
    local_e = 0;
    if (param_3 != 0) {
      uVar3 = fn_2279_02b5((int)param_2,(int)(param_2 >> 0x10));
      uVar5 = (undefined2)in_EDX;
      param_2 = CONCAT22(uVar5,uVar3);
      if (local_4 == 0) {
        fn_2279_025b(*(long *)(local_12 + 8) + *(long *)(param_1 * 0x14 + 8) +
                      *(long *)(param_1 * 0x14 + 4),uVar3,uVar5,(int)param_3,(int)(param_3 >> 0x10))
        ;
        local_e = param_3;
        *(long *)(param_1 * 0x14 + 4) = *(long *)(param_1 * 0x14 + 4) + param_3;
      }
      else {
        iVar2 = fn_2365_063f(uVar3,uVar5);
        if (iVar2 == 0) {
          while (uVar3 = (undefined2)in_EDX, param_3 != 0) {
            g_ae4d = 0;
            uVar5 = (undefined2)param_3;
            if (0xffef < param_3) {
              uVar5 = 0xfff0;
            }
            uVar6 = (undefined2)param_2;
            uVar7 = (undefined2)(param_2 >> 0x10);
            uVar4 = fn_2148_00c9(local_4,uVar6,uVar7,uVar5);
            local_16 = (ulong)uVar4;
            if (g_ae4d != 0) {
              uVar5 = (undefined2)param_3;
              if (0xffef < param_3) {
                uVar5 = 0xfff0;
              }
              uVar5 = fn_1809_133b(param_1,uVar6,uVar7,uVar5);
              local_16 = CONCAT22(uVar3,uVar5);
              local_4 = *(int *)(param_1 * 0x14 + 2);
            }
            param_3 = param_3 - local_16;
            local_e = local_e + local_16;
            plVar1 = (long *)(param_1 * 0x14 + 4);
            *plVar1 = *plVar1 + local_16;
            if (local_16 < 0xfff0) break;
            in_EDX = local_16;
            uVar3 = fn_2037_0002(uVar6,uVar7,(int)local_16,(int)(local_16 >> 0x10));
            param_2 = CONCAT22((int)in_EDX,uVar3);
          }
        }
        else {
          uVar3 = fn_203b_03b4(0);
          local_16 = CONCAT22((int)in_EDX,uVar3) >> 1 & 0xfffffff0;
          if (0xffef < local_16) {
            local_16 = 0xfff0;
          }
          uVar3 = fn_203b_0007((int)local_16,(int)(local_16 >> 0x10),0x28);
          local_1a = CONCAT22((int)in_EDX,uVar3);
          while (uVar3 = (undefined2)in_EDX, param_3 != 0) {
            g_ae4d = 0;
            uVar5 = (undefined2)param_3;
            if (local_16 <= param_3) {
              uVar5 = (undefined2)local_16;
            }
            uVar4 = fn_2148_00c9(local_4,(int)local_1a,(int)((ulong)local_1a >> 0x10),uVar5);
            local_1e = (ulong)uVar4;
            if (g_ae4d != 0) {
              uVar5 = (undefined2)param_3;
              if (local_16 <= param_3) {
                uVar5 = (undefined2)local_16;
              }
              uVar5 = fn_1809_133b(param_1,(int)local_1a,(int)((ulong)local_1a >> 0x10),uVar5);
              local_1e = CONCAT22(uVar3,uVar5);
              local_4 = *(int *)(param_1 * 0x14 + 2);
            }
            fn_2279_025b(local_1a,(int)param_2,(int)(param_2 >> 0x10),(int)local_1e,
                          (int)(local_1e >> 0x10));
            param_3 = param_3 - local_1e;
            local_e = local_e + local_1e;
            *(long *)(param_1 * 0x14 + 4) = *(long *)(param_1 * 0x14 + 4) + local_1e;
            if (local_1e < local_16) break;
            param_2 = param_2 + local_1e;
            in_EDX = param_2 >> 0x10;
          }
          fn_203b_0203((int)local_1a,(int)((ulong)local_1a >> 0x10));
        }
      }
    }
    fn_1981_031f(local_a,local_32);
    g_abde = g_abde + -1;
    uVar3 = (undefined2)local_e;
  }
  return uVar3;
}


//// fn_1809_0bde @ 2809:0bde

undefined2 __cdecl16far fn_1809_0bde(int param_1,long param_2,ulong param_3)

{
  long *plVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined2 uVar4;
  int iVar5;
  uint uVar6;
  undefined2 uVar7;
  undefined4 uVar8;
  undefined2 in_DX;
  undefined1 local_2c [20];
  ulong local_18;
  undefined2 local_14;
  undefined2 uStack_12;
  ulong local_10;
  undefined4 *local_c;
  long local_8;
  int local_4;
  
  iVar2 = fn_1809_1279(param_1,6,0,0);
  if (iVar2 != 0) {
    local_4 = *(int *)(param_1 * 0x14 + 2);
    iVar2 = *(int *)(param_1 * 0x14 + 0xc);
    puVar3 = (undefined4 *)fn_1981_02c0(iVar2,local_2c);
    local_c = (undefined4 *)CONCAT22(in_DX,puVar3);
    if (local_4 != 0) {
      g_abde = g_abde + '\x01';
      local_8 = 0;
      iVar5 = fn_2365_063f((int)param_2,(int)((ulong)param_2 >> 0x10));
      if (iVar5 == 0) {
        while (param_3 != 0) {
          if (param_3 < 0xfff0) {
            uVar4 = (undefined2)param_3;
          }
          else {
            uVar4 = 0xfff0;
          }
          uVar6 = fn_2148_00f5(local_4,(int)param_2,(int)((ulong)param_2 >> 0x10),uVar4);
          local_10 = (ulong)uVar6;
          param_3 = param_3 - local_10;
          local_8 = local_8 + local_10;
          plVar1 = (long *)(param_1 * 0x14 + 4);
          *plVar1 = *plVar1 + local_10;
          if (local_10 == 0) break;
          if (iVar2 != -1) {
            uVar4 = (undefined2)((ulong)local_c >> 0x10);
            puVar3 = (undefined4 *)local_c;
            if (*(long *)(param_1 * 0x14 + 4) < (long)puVar3[1]) {
              uVar8 = puVar3[1];
            }
            else {
              uVar8 = *(undefined4 *)(param_1 * 0x14 + 4);
            }
            puVar3[1] = uVar8;
          }
          uVar4 = (undefined2)(param_2 + local_10 >> 0x10);
          uVar7 = fn_2279_02b5(param_2 + local_10);
          param_2 = CONCAT22(uVar4,uVar7);
        }
      }
      else {
        uVar4 = fn_203b_03b4(0);
        local_10 = CONCAT22(in_DX,uVar4) >> 1 & 0xfffffff0;
        if (0xffef < local_10) {
          local_10 = 0xfff0;
        }
        uVar4 = fn_203b_0007((int)local_10,(int)(local_10 >> 0x10),0x28);
        _local_14 = CONCAT22(in_DX,uVar4);
        while (param_3 != 0) {
          local_18 = local_10;
          if (param_3 < local_10) {
            local_18 = param_3;
          }
          fn_2279_025b(param_2,(int)_local_14,(int)((ulong)_local_14 >> 0x10),(int)local_18,
                        (int)(local_18 >> 0x10));
          uVar6 = fn_2148_00f5(local_4,(int)_local_14,(int)((ulong)_local_14 >> 0x10),
                                (undefined2)local_18);
          local_18 = (ulong)uVar6;
          param_3 = param_3 - local_18;
          local_8 = local_8 + local_18;
          *(long *)(param_1 * 0x14 + 4) = *(long *)(param_1 * 0x14 + 4) + local_18;
          if (local_18 == 0) break;
          if (iVar2 != -1) {
            uVar4 = (undefined2)((ulong)local_c >> 0x10);
            puVar3 = (undefined4 *)local_c;
            if (*(long *)(param_1 * 0x14 + 4) < (long)puVar3[1]) {
              uVar8 = puVar3[1];
            }
            else {
              uVar8 = *(undefined4 *)(param_1 * 0x14 + 4);
            }
            puVar3[1] = uVar8;
          }
          param_2 = param_2 + local_18;
        }
        fn_203b_0203((int)_local_14,(int)((ulong)_local_14 >> 0x10));
      }
      fn_1981_031f(iVar2,local_2c);
      g_abde = g_abde + -1;
      return (int)local_8;
    }
    uVar4 = fn_1981_0365((int)*local_c,(int)((ulong)*local_c >> 0x10));
    fn_1809_1319(9,uVar4,in_DX);
  }
  return 0;
}


//// fn_1809_0e76 @ 2809:0e76

undefined2 __cdecl16far fn_1809_0e76(int param_1,long param_2,int param_3)

{
  long *plVar1;
  int iVar2;
  undefined2 uVar3;
  long lVar4;
  undefined4 uVar5;
  undefined2 in_DX;
  undefined4 uStackY_2e;
  undefined1 local_1e [20];
  int local_a;
  undefined2 uStack_8;
  int local_6;
  int local_4;
  
  iVar2 = fn_1809_1279(param_1,7,0,0);
  if (iVar2 == 0) {
    return 0;
  }
  g_abde = g_abde + '\x01';
  local_6 = *(int *)(param_1 * 0x14 + 0xc);
  local_4 = *(int *)(param_1 * 0x14 + 2);
  local_a = fn_1981_02c0(local_6,local_1e);
  uStack_8 = in_DX;
  if (local_4 == 0) {
    if (param_3 == 0) {
      if (param_2 < 0) {
        param_2 = 0;
      }
      *(undefined4 *)(param_1 * 0x14 + 4) = 0;
    }
    else if (param_3 != 1) {
      if (param_3 == 2) {
        if (0 < param_2) {
          param_2 = 0;
        }
        *(undefined4 *)(param_1 * 0x14 + 4) = *(undefined4 *)(local_a + 4);
      }
      else {
        uVar5 = *(undefined4 *)(param_1 * 0x14 + 0x10);
        uVar3 = fn_1981_0365((int)uVar5,(int)((ulong)uVar5 >> 0x10));
        fn_1809_1319(8,uVar3,in_DX);
      }
    }
    plVar1 = (long *)(param_1 * 0x14 + 4);
    *plVar1 = *plVar1 + param_2;
    if (*(long *)(param_1 * 0x14 + 4) < *(long *)(local_a + 4) + -1) {
      lVar4 = *(long *)(param_1 * 0x14 + 4);
    }
    else {
      lVar4 = *(long *)(local_a + 4) + -1;
    }
    *(long *)(param_1 * 0x14 + 4) = lVar4;
    if (*(long *)(param_1 * 0x14 + 4) < 1) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(undefined4 *)(param_1 * 0x14 + 4);
    }
    *(undefined4 *)(param_1 * 0x14 + 4) = uVar5;
    goto LAB_2809_119c;
  }
  if ((local_6 == -1) || ((*(uint *)(local_a + 0x12) & 0x1000) == 0)) {
    uVar3 = fn_2148_0094(local_4,(int)param_2,(int)((ulong)param_2 >> 0x10),param_3);
    uStackY_2e = CONCAT22(in_DX,uVar3);
    *(undefined4 *)(param_1 * 0x14 + 4) = uStackY_2e;
    if (local_6 != -1) {
      plVar1 = (long *)(param_1 * 0x14 + 4);
      *plVar1 = *plVar1 - *(long *)(param_1 * 0x14 + 8);
    }
    goto LAB_2809_119c;
  }
  if (param_3 == 0) {
LAB_2809_1038:
    *(long *)(param_1 * 0x14 + 4) = param_2;
  }
  else if (param_3 == 1) {
    plVar1 = (long *)(param_1 * 0x14 + 4);
    *plVar1 = *plVar1 + param_2;
    if (*(long *)(param_1 * 0x14 + 4) < 0) {
      *(undefined4 *)(param_1 * 0x14 + 4) = 0;
    }
    if (*(long *)(local_a + 4) <= *(long *)(param_1 * 0x14 + 4)) {
      param_2 = *(long *)(local_a + 4);
      goto LAB_2809_1038;
    }
  }
  else {
    if (param_3 == 2) {
      if (0 < param_2) {
        param_2 = 0;
      }
      if (-*(long *)(local_a + 4) != param_2 && *(long *)(local_a + 4) <= -param_2) {
        uVar5 = *(undefined4 *)(param_1 * 0x14 + 0x10);
        uVar3 = fn_1981_0365((int)uVar5,(int)((ulong)uVar5 >> 0x10));
        fn_1809_1319(8,uVar3,in_DX);
      }
      param_2 = *(long *)(local_a + 4) + param_2;
      goto LAB_2809_1038;
    }
    uVar5 = *(undefined4 *)(param_1 * 0x14 + 0x10);
    uVar3 = fn_1981_0365((int)uVar5,(int)((ulong)uVar5 >> 0x10));
    fn_1809_1319(8,uVar3,in_DX);
  }
  fn_2148_0094(local_4,*(long *)(param_1 * 0x14 + 4) + *(long *)(param_1 * 0x14 + 8),0);
LAB_2809_119c:
  g_abde = g_abde + -1;
  return (int)*(undefined4 *)(param_1 * 0x14 + 4);
}


//// fn_1809_11b9 @ 2809:11b9

undefined2 __cdecl16far fn_1809_11b9(long param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
LAB_2809_11c3:
    uVar1 = 0;
  }
  else {
    while( true ) {
      iVar2 = fn_1981_000a(param_1);
      if (iVar2 != 0) break;
      do {
        iVar2 = fn_1809_12c0(2,param_1);
        if (iVar2 == 0) goto LAB_2809_11c3;
        fn_2148_002c();
        iVar2 = fn_2148_014d((undefined1 *)&g_aeaa,0x3e2d);
      } while (iVar2 != 0);
    }
    uVar1 = 1;
  }
  return uVar1;
}


//// fn_1809_120c @ 2809:120c

undefined2 __cdecl16far fn_1809_120c(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 in_DX;
  undefined1 local_1a [20];
  int local_6;
  undefined2 uStack_4;
  
  if (*(int *)(param_1 * 0x14 + 0xc) != -1) {
    iVar1 = fn_1981_02c0(*(undefined2 *)(param_1 * 0x14 + 0xc),local_1a);
    _local_6 = CONCAT22(in_DX,iVar1);
    if (*(long *)(iVar1 + 4) != 0) {
      return (int)*(undefined4 *)(iVar1 + 4);
    }
  }
  uVar2 = filelength(*(undefined2 *)(param_1 * 0x14 + 2));
  return uVar2;
}


//// fn_1809_1279 @ 2809:1279

undefined2 __cdecl16far fn_1809_1279(int param_1,undefined2 param_2,undefined4 param_3)

{
  if ((param_1 < 0) || (0x13 < param_1)) {
    fn_1809_1319(param_2,param_3);
  }
  if (*(int *)(param_1 * 0x14) != 0) {
    fn_1809_1319(param_2,param_3);
  }
  return 1;
}


//// fn_1809_12c0 @ 2809:12c0

void __cdecl16far fn_1809_12c0(undefined2 param_1,long param_2)

{
  int iVar1;
  undefined2 in_DX;
  long lVar2;
  
  lVar2 = 0;
  if ((param_2 != 0) &&
     (iVar1 = strrchr((int)param_2,(int)((ulong)param_2 >> 0x10),0x5c,0), lVar2 = param_2,
     CONCAT22(in_DX,iVar1) != 0)) {
    lVar2 = CONCAT22(in_DX,iVar1 + 1);
  }
  strupr((int)lVar2,(int)((ulong)lVar2 >> 0x10));
  (*g_3638)(0x1000,param_1,(int)lVar2,(int)((ulong)lVar2 >> 0x10));
  return;
}


//// fn_1809_1319 @ 2809:1319

void __cdecl16far fn_1809_1319(undefined2 param_1,undefined4 param_2)

{
  (*g_3638)((char *)s_FINALE_EXE_3e2d_2803 + 6,param_1,param_2);
  fn_2309_000c();
  exit();
  return;
}


//// fn_1809_133b @ 2809:133b

undefined2 __cdecl16far fn_1809_133b(int param_1,undefined4 param_2,undefined2 param_3)

{
  undefined4 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 in_EDX;
  
  do {
    g_ae4d = 0;
    fn_2148_014d((undefined1 *)&g_aeaa,0x3e2d);
    uVar1 = *(undefined4 *)(param_1 * 0x14 + 0x10);
    uVar2 = fn_1981_0365((int)uVar1,(int)((ulong)uVar1 >> 0x10),
                          *(undefined2 *)(param_1 * 0x14 + 0xe));
    iVar3 = fn_1809_0000(uVar2,(int)in_EDX);
    uVar1 = *(undefined4 *)(param_1 * 0x14 + 4);
    fn_1809_0e76(iVar3,(int)uVar1,(int)((ulong)uVar1 >> 0x10),0);
    fn_2148_004d(*(undefined2 *)(param_1 * 0x14 + 2));
    fn_2279_025b(iVar3 * 0x14,0x3c12,param_1 * 0x14,0x3c12,0x14,0);
    *(undefined2 *)(iVar3 * 0x14) = 1;
    uVar2 = fn_2148_00c9(*(undefined2 *)(param_1 * 0x14 + 2),(int)param_2,
                          (int)((ulong)param_2 >> 0x10),param_3);
    if (g_ae4d == 0) {
      return uVar2;
    }
    uVar1 = *(undefined4 *)(param_1 * 0x14 + 0x10);
    uVar2 = fn_1981_0365((int)uVar1,(int)((ulong)uVar1 >> 0x10));
    iVar3 = fn_1809_12c0(2,uVar2,(int)in_EDX);
  } while ((iVar3 != 0) && (iVar3 = fn_2148_014d((undefined1 *)&g_aeaa,0x3e2d), iVar3 != 0))
  ;
  return 0;
}


//// fn_1809_1460 @ 2809:1460

undefined2 __cdecl16far fn_1809_1460(undefined4 param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  
  g_ae4d = 0;
  if (param_2 == -0x7fff) {
    uVar1 = 0x100;
  }
  else {
    uVar1 = 0x180;
  }
  uVar1 = fn_2148_0121(param_1,param_2,uVar1);
  if (((g_ae4d != 0) && (g_ae57 != 0)) &&
     (iVar2 = fn_2148_000f(), iVar2 == g_aeaa + -0x41)) {
    g_ae4d = 0;
    fn_2148_002c(g_aeaa + -0x41);
    fn_2148_014d((undefined1 *)&g_aeaa,0x3e2d);
    if (param_2 == -0x7fff) {
      uVar1 = 0x100;
    }
    else {
      uVar1 = 0x180;
    }
    uVar1 = fn_2148_0121(param_1,param_2,uVar1);
    if (g_ae4d != 0) {
      g_ae4d = 0;
      uVar1 = 0xffff;
    }
  }
  return uVar1;
}


//// fn_1809_1502 @ 2809:1502

undefined2 __cdecl16far fn_1809_1502(int param_1,int param_2)

{
  uint *puVar1;
  long *plVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 in_DX;
  uint uVar5;
  undefined1 local_44 [20];
  undefined1 local_30 [20];
  long local_1c;
  undefined4 local_18;
  int local_14;
  int local_12;
  undefined2 uStack_10;
  undefined4 local_e;
  long local_a;
  long local_6;
  
  local_e = (long *)0x0;
  if (param_1 != -1) {
    plVar2 = (long *)fn_1981_02c0(param_1,local_30);
    local_e = (long *)CONCAT22(in_DX,plVar2);
    if (((*(uint *)((int)plVar2 + 0x12) & 0x600) != 0) && (plVar2[2] == 0)) {
      local_6 = plVar2[1];
      uVar5 = 0;
      uVar3 = fn_203b_03b4(0x42);
      if ((local_6 <= CONCAT22(in_DX,uVar3)) ||
         (uVar3 = fn_203b_0482(0x42), local_6 <= CONCAT22(in_DX,uVar3))) {
        uVar5 = 0x40;
      }
      if (uVar5 == 0) {
        puVar1 = (uint *)((int)(long *)local_e + 0x12);
        *puVar1 = *puVar1 & 0xd1ff;
        fn_1981_031f(param_1,local_30);
      }
      else {
        uVar5 = uVar5 | 2;
        uVar3 = fn_203b_03b4(uVar5);
        local_a = CONCAT22(in_DX,uVar3);
        while (local_a < local_6) {
          local_18 = 0xffff;
          local_1c = local_a;
          local_14 = 0;
          while( true ) {
            plVar2 = (long *)fn_1981_02c0(local_14,local_30);
            local_e = (long *)CONCAT22(in_DX,plVar2);
            if (*local_e == 0) break;
            if (((plVar2[2] != 0) && (*(char *)((int)plVar2 + 0x11) == '\0')) &&
               ((*(uint *)((int)plVar2 + 0x12) & 0x2000) == 0)) {
              local_1c = local_1c + plVar2[1];
              if (local_18._2_2_ < (*(uint *)((int)plVar2 + 0x12) & 0xff)) {
                local_18 = CONCAT22(*(undefined2 *)((int)plVar2 + 0x12),local_14) & 0xffffff;
              }
            }
            local_14 = local_14 + 1;
          }
          if ((local_1c == 0) || ((int)local_18 == -1)) break;
          plVar2 = (long *)fn_1981_02c0((int)local_18,local_30);
          local_e = (long *)CONCAT22(in_DX,plVar2);
          fn_203b_0203((int)plVar2[2],(int)((ulong)plVar2[2] >> 0x10));
          ((long *)local_e)[2] = 0;
          uVar3 = fn_203b_03b4(uVar5);
          local_a = CONCAT22(in_DX,uVar3);
          fn_1981_031f((int)local_18,local_30);
        }
        if (local_6 <= local_a) {
          local_12 = param_2 * 0x14;
          uStack_10 = 0x3c12;
          local_e._0_2_ = fn_1981_02c0(param_1,local_30);
          local_e._2_2_ = in_DX;
          uVar3 = fn_203b_0007((int)local_6,(int)((ulong)local_6 >> 0x10),uVar5);
          *(undefined2 *)((int)local_e + 10) = in_DX;
          *(undefined2 *)((int)local_e + 8) = uVar3;
          if (*(long *)((int)local_e + 8) != 0) {
            fn_1809_084d(param_2,(int)*(undefined4 *)((int)local_e + 8),
                          (int)((ulong)*(undefined4 *)((int)local_e + 8) >> 0x10),(int)local_6,
                          (int)((ulong)local_6 >> 0x10));
            *(undefined4 *)(local_12 + 4) = 0;
            *(undefined4 *)(local_12 + 8) = 0;
            if ((*(uint *)((int)local_e + 0x12) & 0x1000) != 0) {
              iVar4 = fn_1981_02c0(*(undefined1 *)((int)local_e + 0x10),local_44);
              local_18 = CONCAT22(in_DX,iVar4);
              *(char *)(iVar4 + 0x11) = *(char *)(iVar4 + 0x11) + -1;
              fn_1981_031f(*(undefined1 *)((int)local_e + 0x10),local_44);
            }
            fn_2148_004d(*(undefined2 *)(local_12 + 2));
            *(undefined2 *)(local_12 + 2) = 0;
            fn_1981_031f(param_1,local_30);
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

