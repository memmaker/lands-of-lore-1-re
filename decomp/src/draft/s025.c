//// fn_15a7_0964 @ 25a7:0964

void __cdecl16far fn_15a7_0964(void)

{
  g_372d = 1;
  return;
}


//// fn_163d_0039 @ 263d:0039

undefined2 __cdecl16far fn_163d_0039(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = fn_2169_060c();
  if ((iVar1 != 0) && (iVar3 = fn_2169_0790(), iVar3 == 0x2d)) {
    return 0;
  }
  uVar2 = fn_163d_0068(param_1,iVar3);
  return uVar2;
}


//// fn_163d_0068 @ 263d:0068

uint __cdecl16far fn_163d_0068(undefined4 *param_1,uint param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  uint local_e;
  int local_8;
  int local_6;
  
  uVar12 = 0x263d;
  bVar4 = false;
  if (param_1 == (undefined4 *)0x0) {
    return param_2 & 0x7fff;
  }
  if ((param_1 != g_2894) || (g_372d != 0)) {
    g_2890 = (undefined4 *)0x0;
    g_abd2 = 0;
    iVar6 = fn_2169_07ae();
    if (iVar6 != 0) {
      g_abd2 = g_abd2 | 0x200;
    }
    uVar12 = 0x3169;
    iVar6 = fn_2169_07ae();
    if (iVar6 != 0) {
      g_abd2 = g_abd2 | 0x2000;
    }
    g_2894 = param_1;
    g_372d = 0;
    for (; param_1 != (undefined4 *)0x0; param_1 = (undefined4 *)*param_1) {
      fn_163d_05cc(param_1);
    }
  }
  puVar5 = g_2890;
  local_6 = g_2f0c;
  local_8 = g_2f0e;
  uVar10 = 0;
  if (g_2f43 != '\0') goto LAB_263d_0186;
  uVar8 = 0;
  uVar10 = param_2 & 0xff;
  if ((int)param_2 < 0) {
    if (uVar10 == 199) {
      uVar8 = 0x1000;
    }
    if (uVar10 == 0xc6) {
LAB_263d_0141:
      uVar8 = 0x100;
    }
  }
  else {
    if (uVar10 == 0x42) {
      uVar8 = 0x1000;
    }
    if (uVar10 == 0x41) goto LAB_263d_0141;
  }
  if ((param_2 & 0x800) != 0) {
    uVar8 = uVar8 << 2;
  }
  if (uVar8 != 0) {
    local_6 = g_2f10;
    local_8 = g_2f12;
  }
  g_abd2 = g_abd2 & ~((int)(uVar8 & 0x4400) >> 1) | (uVar8 & 0x1100) << 1;
  uVar10 = uVar8 | g_abd2 | g_abd2 << 2 ^ 0x8800;
LAB_263d_0186:
  param_1 = g_2894;
  if ((g_2890 != (undefined4 *)0x0) &&
     (param_1 = puVar5, (*(uint *)((int)(undefined4 *)g_2890 + 0xe) & 8) != 0)) {
    g_2890 = (undefined4 *)0x0;
  }
  local_e = 0;
  for (; param_1 != (undefined4 *)0x0; param_1 = (undefined4 *)*param_1) {
    uVar11 = (undefined2)((ulong)param_1 >> 0x10);
    puVar9 = (undefined4 *)param_1;
    if ((*(uint *)((int)puVar9 + 0xe) & 8) == 0) {
      *(uint *)((int)puVar9 + 0x2e) = *(uint *)((int)puVar9 + 0x2e) & 0xffe7;
      *(uint *)((int)puVar9 + 0x2e) =
           *(uint *)((int)puVar9 + 0x2e) | (*(uint *)((int)puVar9 + 0x2e) & 3) << 3;
      iVar6 = *(int *)((int)puVar9 + 0x1e);
      if (iVar6 < 0) {
        iVar6 = iVar6 + *(int *)(*(int *)(puVar9 + 7) * 0x10 + 7999) * 8;
      }
      iVar6 = iVar6 + *(int *)(*(int *)(puVar9 + 7) * 0x10 + 0x1f3b) * 8;
      iVar7 = *(int *)(puVar9 + 8);
      if (iVar7 < 0) {
        iVar7 = iVar7 + *(int *)(*(int *)(puVar9 + 7) * 0x10 + 0x1f41);
      }
      iVar7 = iVar7 + *(int *)(*(int *)(puVar9 + 7) * 0x10 + 0x1f3d);
      if ((((local_6 < iVar6) || (local_8 < iVar7)) ||
          (iVar6 + *(int *)((int)puVar9 + 0x22) < local_6)) ||
         (iVar7 + *(int *)(puVar9 + 9) < local_8)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      *(uint *)((int)puVar9 + 0x2e) = *(uint *)((int)puVar9 + 0x2e) & 0xff7f;
      uVar8 = param_2 & 0x7fff;
      if (uVar8 != 0) {
        if (*(uint *)((int)puVar9 + 6) == uVar8) {
LAB_263d_0298:
          uVar10 = *(uint *)((int)puVar9 + 0xe) & 0xf00;
        }
        else {
          if (*(uint *)(puVar9 + 2) != uVar8) goto LAB_263d_02b9;
          uVar10 = *(uint *)((int)puVar9 + 0xe) & 0xf000;
          if (uVar10 == 0) goto LAB_263d_0298;
        }
        bVar1 = true;
        *(uint *)((int)puVar9 + 0x2e) = *(uint *)((int)puVar9 + 0x2e) | 0x80;
        param_2 = 0;
        g_2890 = param_1;
      }
LAB_263d_02b9:
      bVar3 = false;
      if (!bVar1) {
        *(uint *)((int)puVar9 + 0x2e) = *(uint *)((int)puVar9 + 0x2e) & 0xfff9;
      }
      if ((((uVar10 & 0x3300) == 0) || ((*(uint *)((int)puVar9 + 0xe) & 4) == 0)) ||
         ((!bVar1 || ((param_1 != g_2890 && (g_2890 != (undefined4 *)0x0)))))) {
        if (((uVar10 & 0x8800) == 0) || (((*(uint *)((int)puVar9 + 0xe) & 4) != 0 || (!bVar1)))) {
          *(uint *)((int)puVar9 + 0x2e) = *(uint *)((int)puVar9 + 0x2e) & 0xfff9;
        }
        else {
          *(uint *)((int)puVar9 + 0x2e) = *(uint *)((int)puVar9 + 0x2e) | 6;
        }
      }
      else {
        *(uint *)((int)puVar9 + 0x2e) = *(uint *)((int)puVar9 + 0x2e) | 6;
        if (g_2890 == (undefined4 *)0x0) {
          g_2890 = param_1;
        }
      }
      bVar2 = bVar1;
      if ((g_2890 != (undefined4 *)0x0) &&
         ((*(uint *)((int)(undefined4 *)g_2890 + 0xe) & 0x40) != 0)) {
        bVar2 = g_2890 == param_1;
      }
      if (bVar2) {
        if ((((uVar10 & 0x1100) != 0) && (bVar1)) && (g_2890 == (undefined4 *)0x0)) {
          param_2 = 0;
          g_2890 = param_1;
        }
        if (((*(uint *)((int)puVar9 + 0xe) & uVar10) != 0) &&
           ((bVar1 || ((*(uint *)((int)puVar9 + 0xe) & 1) == 0)))) {
          uVar8 = uVar10 & *(uint *)((int)puVar9 + 0xe);
          iVar6 = *(int *)(((uVar8 & 0xf00 | (uVar8 & 0xf000) >> 4) >> 8) * 2 + 0x2898);
          if (iVar6 == 0x200) {
            if ((*(uint *)((int)puVar9 + 0xe) & 4) != 0) {
              *(uint *)((int)puVar9 + 0x2e) = *(uint *)((int)puVar9 + 0x2e) | 4;
              *(uint *)((int)puVar9 + 0x2e) = *(uint *)((int)puVar9 + 0x2e) | 2;
            }
            uVar8 = *(uint *)((int)puVar9 + 0xe);
joined_r0x00026849:
            if ((uVar8 & 1) == 0) {
              bVar3 = true;
            }
          }
          else if (iVar6 == 0x400) {
            if ((((*(uint *)((int)puVar9 + 0xe) & 1) != 0) && (g_2890 == param_1)) ||
               ((*(uint *)((int)puVar9 + 0xe) & 1) == 0)) {
              *(uint *)((int)puVar9 + 0x2e) = *(uint *)((int)puVar9 + 0x2e) ^ 1;
              local_e = *(uint *)(puVar9 + 1) | 0x8000;
              bVar3 = true;
            }
            if ((*(uint *)((int)puVar9 + 0xe) & 4) == 0) {
              *(uint *)((int)puVar9 + 0x2e) = *(uint *)((int)puVar9 + 0x2e) & 0xfffb;
              *(uint *)((int)puVar9 + 0x2e) = *(uint *)((int)puVar9 + 0x2e) & 0xfffd;
            }
          }
          else {
            if (iVar6 == 0x800) {
              if ((*(uint *)((int)puVar9 + 0xe) & 4) == 0) {
                *(uint *)((int)puVar9 + 0x2e) = *(uint *)((int)puVar9 + 0x2e) | 4;
                *(uint *)((int)puVar9 + 0x2e) = *(uint *)((int)puVar9 + 0x2e) | 2;
              }
              uVar8 = *(uint *)((int)puVar9 + 0xe);
              goto joined_r0x00026849;
            }
            *(uint *)((int)puVar9 + 0x2e) = *(uint *)((int)puVar9 + 0x2e) ^ 1;
            local_e = *(uint *)(puVar9 + 1) | 0x8000;
            bVar3 = true;
            if ((*(uint *)((int)puVar9 + 0xe) & 4) != 0) {
              *(uint *)((int)puVar9 + 0x2e) = *(uint *)((int)puVar9 + 0x2e) | 4;
              *(uint *)((int)puVar9 + 0x2e) = *(uint *)((int)puVar9 + 0x2e) | 2;
            }
            g_2890 = param_1;
          }
        }
      }
      if (((((uVar10 & 0x2200) != 0) && (bVar1)) &&
          (*(uint *)((int)puVar9 + 0x2e) = *(uint *)((int)puVar9 + 0x2e) | 6,
          (*(uint *)((int)puVar9 + 0xe) & 4) == 0)) && ((*(uint *)((int)puVar9 + 0x2e) & 1) == 0)) {
        bVar4 = true;
        *(uint *)((int)puVar9 + 0x2e) = *(uint *)((int)puVar9 + 0x2e) | 1;
      }
      if ((((*(uint *)((int)puVar9 + 0x2e) & 0x80) != 0) || ((uVar10 & 0x8800) == 0x8800)) &&
         ((g_2890 = (undefined4 *)0x0, !bVar1 || ((*(uint *)((int)puVar9 + 0xe) & 4) != 0))))
      {
        *(uint *)((int)puVar9 + 0x2e) = *(uint *)((int)puVar9 + 0x2e) & 0xfff9;
      }
      if (((!bVar1) && (param_1 == g_2890)) && ((*(uint *)((int)puVar9 + 0xe) & 0x40) == 0))
      {
        g_2890 = (undefined4 *)0x0;
      }
      if ((*(uint *)((int)puVar9 + 0x2e) & 0x18) != (*(uint *)((int)puVar9 + 0x2e) & 3) * 8) {
        fn_163d_05cc(puVar9,uVar11);
      }
      if (bVar4) {
        *(uint *)((int)puVar9 + 0x2e) = *(uint *)((int)puVar9 + 0x2e) & 0xfffe;
      }
      if (bVar3) {
        *(uint *)((int)puVar9 + 0x2e) = *(uint *)((int)puVar9 + 0x2e) & 0xff;
        *(uint *)((int)puVar9 + 0x2e) = *(uint *)((int)puVar9 + 0x2e) | uVar10;
        if (((puVar9[0xc] != 0) && (iVar6 = (**(code **)(puVar9 + 0xc))(uVar12), iVar6 != 0)) ||
           ((*(uint *)((int)puVar9 + 0xe) & 0x20) != 0)) break;
      }
      if ((g_2890 == param_1) && ((*(uint *)((int)puVar9 + 0xe) & 0x40) != 0)) break;
    }
  }
  if (local_e == 0) {
    local_e = param_2 & 0x7fff;
  }
  return local_e;
}


//// fn_163d_05cc @ 263d:05cc

/* WARNING: Removing unreachable block (ram,0x000283f1) */
/* WARNING: Removing unreachable block (ram,0x000283f8) */
/* WARNING: Removing unreachable block (ram,0x00028410) */
/* WARNING: Removing unreachable block (ram,0x000285ea) */
/* WARNING: Removing unreachable block (ram,0x00028613) */

int __cdecl16far fn_163d_05cc(long param_1)

{
  char *pcVar1;
  int iVar2;
  int in_AX;
  uint uVar3;
  int iVar4;
  undefined2 unaff_SI;
  int iVar5;
  int unaff_DI;
  int iVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  int unaff_SS;
  char acStack_58 [42];
  undefined4 uStack_2e;
  undefined4 uStack_2a;
  char *pcStack_26;
  char *pcStack_24;
  undefined1 *puStack_22;
  uint local_c;
  
  if (param_1 != 0) {
    uVar7 = (undefined2)((ulong)param_1 >> 0x10);
    iVar4 = (int)param_1;
    if ((*(uint *)(iVar4 + 0xe) & 8) == 0) {
      uVar3 = *(uint *)(iVar4 + 0x2e) & 5;
      if (uVar3 == 1) {
        local_c = (uint)*(byte *)(iVar4 + 0xb);
      }
      else if ((uVar3 == 4) || (uVar3 == 5)) {
        local_c = (uint)*(byte *)(iVar4 + 0xc);
      }
      else {
        local_c = (uint)*(byte *)(iVar4 + 10);
      }
      iVar5 = *(int *)(iVar4 + 0x1e);
      if (iVar5 < 0) {
        iVar5 = iVar5 + *(int *)(*(int *)(iVar4 + 0x1c) * 0x10 + 7999) * 8;
      }
      iVar2 = *(int *)(*(int *)(iVar4 + 0x1c) * 0x10 + 0x1f3b);
      in_AX = iVar2 * 8;
      iVar6 = *(int *)(iVar4 + 0x20);
      if (iVar6 < 0) {
        iVar6 = iVar6 + *(int *)(*(int *)(iVar4 + 0x1c) * 0x10 + 0x1f41);
      }
      local_c = local_c - 1;
      if (local_c < 6) {
        switch(local_c) {
        case 0:
          return in_AX;
        case 1:
          pcVar1 = (char *)(local_c * 2 + iVar5 + in_AX);
          *pcVar1 = *pcVar1 + (char)in_AX;
          uVar7 = 0x2000;
          break;
        case 2:
          iVar5 = *(int *)(iVar4 + (*(int *)(iVar4 + 0xc) + 1) * 2 + 0x2c);
          iVar4 = *(int *)(iVar4 + (*(int *)(iVar4 + 0xc) + 2) * 2 + 0x2c);
          if (iVar4 < iVar5) {
            iVar6 = -1;
          }
          else {
            iVar6 = 1;
          }
          for (; iVar4 + iVar6 != iVar5; iVar5 = iVar5 + iVar6) {
            ovr_2cef_0025();
            ovr_2cef_0020();
            fn_1ebc_0111();
            if ((*(uint *)(in_AX + 0x4ef2) & 0x4000) == 0) {
              puStack_22 = (undefined1 *)
                           *(undefined4 *)CONCAT22(0x3e2d,(undefined4 *)&g_4ee0 + iVar2 * 2);
              pcStack_24 = (char *)s_PageArraySize_is_negative__3e2d_2eba + 2;
              pcStack_26 = (char *)0x601;
              ovr_2dfd_002a();
            }
            else {
              pcStack_24 = (char *)0x70;
              puStack_22 = (undefined1 *)0x0;
              pcStack_26 = (char *)s_PageArraySize_is_negative__3e2d_2eba + 2;
              uStack_2a = CONCAT22(0x5a0,(undefined2)uStack_2a);
              fn_1dbc_0004();
              puStack_22 = (undefined1 *)((undefined2 *)&g_4ee6)[iVar2 * 4];
              pcStack_24 = (char *)((undefined2 *)&g_4ee4)[iVar2 * 4];
              pcStack_26 = (char *)(iVar5 + -1);
              uStack_2a = *(undefined4 *)CONCAT22(0x3e2d,(undefined4 *)&g_4ee0 + iVar2 * 2);
              uStack_2e = 0x2dbc05ca;
              ovr_2dfd_002a();
              pcStack_24 = (char *)0x70;
              puStack_22 = (undefined1 *)0x0;
              pcStack_26 = "\x0e\x0e\x0e\x0e\x0e#\x0e\x1c(\x17#%\x13(";
              uStack_2a = CONCAT22(0x5e1,(undefined2)uStack_2a);
              fn_1dbc_0004();
            }
            fn_1ebc_01ec();
            fn_0845_0be0();
          }
          return 1;
        case 3:
          return (CONCAT11((char)((uint)in_AX >> 8),
                           ((char)in_AX -
                           *(char *)(iVar6 + *(int *)(*(int *)(iVar4 + 0x1c) * 0x10 + 0x1f3d))) -
                           ((int)local_c < 0)) & 0xff05) + 0xa8c;
        case 4:
          puStack_22 = &stack0xffea;
          pcStack_24 = (char *)0x2000;
          pcStack_26 = (char *)0x5d1e;
          fn_2279_025b();
          return 1;
        case 5:
          return in_AX;
        }
        do {
          do {
            uVar8 = uVar7;
            puStack_22 = (undefined1 *)0x83e4;
            fn_1809_084d();
            do {
              puStack_22 = (undefined1 *)0x8348;
              fn_1809_084d();
            } while (acStack_58[unaff_SS] != '\0');
            uVar7 = 0x2981;
            iVar4 = fn_1981_01af();
          } while ((((iVar4 == -1) ||
                    (iVar4 = iVar4 * 0x14, (*(uint *)(iVar4 + 0x12) & 0x1000) == 0)) ||
                   ((uint)*(byte *)(iVar4 + 0x10) != *(uint *)(unaff_DI + 0xc))) ||
                  (*(long *)(iVar4 + 0xc) =
                        (long)((char *)CONCAT22(unaff_SS,acStack_58) +
                              *(long *)(*(int *)(unaff_DI + 0xc) * 0x14 + 0xc)),
                  CONCAT22(uVar8,puStack_22) == 0));
          *(long *)((int)puStack_22 + 4) = *(long *)(iVar4 + 0xc) - *(long *)((int)puStack_22 + 0xc)
          ;
        } while( true );
      }
    }
    else if ((*(uint *)(iVar4 + 0xe) & 0x10) != 0) {
      in_AX = fn_1db2_0003();
    }
  }
  return in_AX;
}

