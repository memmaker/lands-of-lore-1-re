//// _Dracle_Status @ 1543:000d

undefined2 __cdecl16far _Dracle_Status(void)

{
  if ((uRam0002d298 <= DAT_2d16_29a0) &&
     ((DAT_2d16_29a0 != uRam0002d298 || (uRam0002d296 < TimerValues)))) {
    _Animate_Frame(uRam0002d290,uRam0002d292,uRam0002d294,0x4b,0x33,0,0);
    uRam0002d294 = uRam0002d294 + 1;
    if (4 < uRam0002d294) {
      uRam0002d294 = 0;
    }
    uRam0002d296 = TimerValues + 4;
    uRam0002d298 = DAT_2d16_29a0 + (0xfffb < TimerValues);
  }
  _Long_Sample_Status();
  return 1;
}


//// _Open_Anim @ 1543:0078

void __cdecl16far _Open_Anim(undefined2 param_1,undefined2 param_2)

{
  undefined2 uVar1;
  undefined1 local_302 [768];
  
  _Long_Sample_Status();
  if (iRam0002d29a != 0 || iRam0002d29c != 0) {
    _Close_Animation(iRam0002d29a,iRam0002d29c);
  }
  _Long_Sample_Status();
  uVar1 = 0;
  iRam0002d29a = _Open_Animation(param_1,param_2,0,0,0,0,3,local_302);
  iRam0002d29c = uVar1;
  _Set_Palette(local_302);
  _sx = _Get_Animation_X(iRam0002d29a,iRam0002d29c);
  _sy = _Get_Animation_Y(iRam0002d29a,iRam0002d29c);
  _sw = _Get_Animation_Width(iRam0002d29a,iRam0002d29c);
  _sh = _Get_Animation_Height(iRam0002d29a,iRam0002d29c);
  uRam0002d29e = 1;
  _Long_Sample_Status();
  return;
}


//// _Restore_BG @ 1543:0130

void __cdecl16far _Restore_BG(void)

{
  _Long_Sample_Status();
  _Bit_Blit(0x26e6,_sx,_sy,_sx,_sy,_sw,_sh,8,0);
  _Long_Sample_Status();
  _Bit_Blit(0x26e6,_sx,_sy,_sx,_sy,_sw,_sh,8,2);
  _Long_Sample_Status();
  return;
}


//// _Animate @ 1543:0193

void __cdecl16far _Animate(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  while (iVar1 < 0xf) {
    _Long_Sample_Status();
    DAT_2d16_29a4 = 0;
    DAT_2d16_29a2 = 3;
    _Animate_Frame(uRam0002d29a,uRam0002d29c,iRam0002d29e,0,0,2,0);
    _Bit_Blit(0x1e35,_sx,_sy,_sx,_sy,_sw,_sh,2,0);
    while (DAT_2d16_29a2 != 0 || DAT_2d16_29a4 != 0) {
      _Long_Sample_Status();
    }
    iVar1 = iVar1 + 1;
    if (param_1 == 0) {
      iRam0002d29e = iRam0002d29e + -1;
    }
    else {
      iRam0002d29e = iRam0002d29e + 1;
    }
  }
  _Long_Sample_Status();
  return;
}


//// _Patrick_Stewart @ 1543:022c

/* WARNING: Instruction at (ram,0x000155cc) overlaps instruction at (ram,0x000155cb)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

size_t * __cdecl16far
_Patrick_Stewart(FILE *param_1,char *param_2,char *param_3,char *param_4,undefined1 param_5,
                char *param_6,uint param_7,undefined2 param_8,undefined2 param_9,undefined2 param_10
                ,undefined2 param_11)

{
  byte *pbVar1;
  char *pcVar2;
  undefined2 *puVar3;
  undefined1 *puVar4;
  code *pcVar5;
  char cVar6;
  size_t *psVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  void *__s;
  int iVar11;
  size_t *psVar12;
  int *piVar13;
  undefined1 *puVar14;
  size_t *psVar15;
  byte bVar16;
  uint uVar17;
  int iVar18;
  size_t *psVar19;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  undefined2 *extraout_DX_01;
  undefined2 *puVar20;
  size_t *extraout_DX_02;
  char *pcVar21;
  size_t *psVar22;
  uint *puVar23;
  size_t *psVar24;
  undefined1 *puVar25;
  undefined2 *puVar26;
  undefined1 *unaff_DI;
  char *unaff_SS;
  bool bVar27;
  bool bVar28;
  size_t *psVar29;
  undefined4 uVar30;
  undefined2 uVar31;
  undefined2 uVar32;
  int iVar33;
  undefined1 local_7e6 [2];
  size_t local_7e4 [308];
  undefined1 local_314 [616];
  char acStack_ac [80];
  size_t asStack_5c [2];
  undefined1 auStack_53 [43];
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined1 *puStack_20;
  int local_10;
  size_t *local_e;
  int local_c;
  size_t *local_8;
  undefined4 local_6;
  
  iVar11 = (int)((ulong)local_6 >> 0x10);
  SCOPY_();
  MonoEnabled = 0;
  puVar26 = extraout_DX_01;
  local_8 = (size_t *)_Load_Font();
  local_6 = (undefined2 *)CONCAT22(iVar11,puVar26);
  puVar20 = puVar26;
  iVar8 = _Load_Alloc_Data();
  _memset(local_314,(int)unaff_SS,0x3000000);
  _Fade_Palette_To();
code_r0x000156ef:
  _Load_Picture();
  _Byte_Blit();
  _Byte_Blit();
  _Fade_Palette_To();
  iVar18 = _sx;
  iVar33 = _sy;
  psVar12 = _sh;
  _Bit_Blit();
  psVar7 = extraout_DX_02;
  _Flush_Unused_File_Cache();
  _memset(local_314,(int)unaff_SS,0x3000000);
  psVar24 = (size_t *)0x0;
  _Set_Font();
  local_e = (size_t *)0x2d16;
LAB_1543_083a:
  if (('9' < cRam0002d497) || (iVar10 = Check_Key(), iVar10 != 0)) {
    _memset(local_314,(int)unaff_SS,0x300003f);
    if (iRam0002d290 == 0 && iRam0002d292 == 0) {
      pcVar21 = (char *)0x0;
    }
    else {
      pcVar21 = (char *)s_Not_enough_disk_space_to_run_Lan_2d16_1523 + 0x20;
    }
    _Fade_Palette_To();
    uVar32 = 64000;
    uVar31 = 0;
    __s = (void *)_Get_Page();
    _memset(__s,(int)pcVar21,CONCAT22(uVar32,uVar31));
    _memset(local_314,(int)unaff_SS,0x3000000);
    _Fade_Palette_To();
code_r0x00015d06:
    _Free();
    while (iVar11 = Check_Key(), iVar11 != 0) {
      Get_Key();
    }
    return (size_t *)0x1;
  }
LAB_1543_081f:
  iVar10 = Check_Key();
  if ((iVar10 != 0) ||
     (psVar19 = local_e, iVar10 = _Load_Quick_Sample(), iVar10 == 0 && psVar7 == (size_t *)0x0))
  goto LAB_1543_082b;
  if (iVar10 == 0 && psVar7 == (size_t *)0x0) goto LAB_1543_0818;
  psVar7 = (size_t *)local_7e6;
  if (*(char *)((int)psVar24 * 0xf + (int)psVar7) != cRam0002d497) {
LAB_1543_07dc:
    _Play_Long_Sample_Vol();
LAB_1543_07f4:
    do {
      iVar10 = _Long_Sample_Status();
      if (iVar10 == 0) break;
      iVar10 = Check_Key();
    } while (iVar10 == 0);
    _Stop_Long_Sample();
    _Free();
    goto LAB_1543_0818;
  }
  psVar7 = (size_t *)(local_7e6 + 1);
  pbVar9 = (byte *)((int)psVar24 * 0xf + (int)psVar7);
  bVar16 = *pbVar9;
  cVar6 = (char)((uint)pbVar9 >> 8);
  psVar15 = (size_t *)CONCAT11(cVar6,bVar16);
  if (bVar16 != bRam0002d498) goto LAB_1543_07dc;
  if ((size_t *)0x1d < psVar24) {
    _Play_Long_Sample_Vol();
    _Animate();
    _Restore_BG();
    psVar7 = (size_t *)(local_7e6 + 2);
    _Open_Anim();
    _Animate();
    psVar24 = (size_t *)((int)psVar24 + 1);
    goto LAB_1543_07f4;
  }
  goto LAB_1543_03fc;
LAB_1543_082b:
  bRam0002d498 = 0x61;
  cRam0002d497 = cRam0002d497 + '\x01';
  goto LAB_1543_083a;
LAB_1543_0818:
  bRam0002d498 = bRam0002d498 + 1;
  goto LAB_1543_081f;
switchD_1000_582e_caseD_1b:
  (&stack0xfffe)[(int)unaff_DI] = (&stack0xfffe)[(int)unaff_DI] | (byte)((uint)psVar7 >> 8);
  ((undefined1 *)((int)psVar22 + (int)psVar24))[0x33] =
       ((undefined1 *)((int)psVar22 + (int)psVar24))[0x33];
  _Animate_Frame();
  Conditional_Show_Mouse();
  DAT_2d16_29a4 = 0;
  DAT_2d16_29a2 = 8;
  do {
    if (DAT_2d16_29a2 == 0 && DAT_2d16_29a4 == 0) break;
    iVar8 = Check_Key();
  } while (iVar8 == 0);
  psVar22 = (size_t *)0x16;
  psVar24 = (size_t *)((int)((int)psVar24 + 1) % 0x16);
  psVar7 = psVar24;
  iVar8 = Check_Key();
  if ((iVar8 != 0) || (iVar8 = _Long_Sample_Status(), iVar8 == 0)) {
    _Stop_Long_Sample();
    _Conditional_Hide_Mouse();
    _Animate_Frame();
    Conditional_Show_Mouse();
    psVar7 = (size_t *)0x0;
    if (puVar26 != (undefined2 *)0x0 || iVar11 != 0) {
      psVar7 = (size_t *)_Free();
    }
    return psVar7;
  }
  if ((int)psVar24 < 4) {
    psVar24 = (size_t *)0x4;
  }
  _Conditional_Hide_Mouse();
  goto switchD_1000_582e_caseD_1b;
code_r0x00013001:
  bVar28 = bVar16 < 9;
  bVar27 = false;
  if (bVar16 == 9) {
LAB_1000_3005:
    bVar28 = false;
    bVar27 = true;
  }
  goto LAB_1000_2fe9;
switchD_1000_582e_caseD_f:
  while( true ) {
    _Bit_Blit();
    while (DAT_2d16_29a2 != 0 || DAT_2d16_29a4 != 0) {
      _Long_Sample_Status();
    }
    psVar24 = (size_t *)((int)psVar24 + 1);
    if (param_1 == (FILE *)0x0) {
      iRam0002d29e = iRam0002d29e + -1;
    }
    else {
      iRam0002d29e = iRam0002d29e + 1;
    }
    if (0xe < (int)psVar24) break;
    _Long_Sample_Status();
code_r0x000155d1:
    DAT_2d16_29a4 = 0;
    DAT_2d16_29a2 = 3;
    _Animate_Frame();
  }
  psVar7 = (size_t *)_Long_Sample_Status();
  return psVar7;
switchD_1000_582e_caseD_0:
  _Alloc_Sample_Buffers();
  _Open_Quick_File();
  uVar32 = 0x300;
  _BlackPalette = _Alloc();
  DAT_2d16_083a = uVar32;
  _IntroFont = _Load_Font();
  DAT_2d16_0832 = DAT_2d16_3dc5;
  _Font6Ptr = _SystemFontPtr;
  uVar31 = _SystemFontPtr;
  DAT_2d16_0f9e = uVar32;
  _Font8Ptr = _Load_Font();
  DAT_2d16_0836 = uVar31;
  _Set_Font();
  MT32_Init();
  Clear_KeyBuffer();
  _BumpRate = 0;
  _Set_Palette();
  Clear_Page();
  Clear_Page();
  _RawText = _Load_Alloc_Data();
  DAT_2d16_082e = uVar31;
  _Size_Of_Region();
  uVar31 = 0;
  _TextBuffer = _Alloc();
  DAT_2d16_0faa = uVar31;
  _Set_Font();
  _Set_Font_Palette();
  _Set_Palette();
  iVar11 = _stricmp();
  if (iVar11 == 0) {
    _Patrick_Stewart();
  }
  else {
    iVar11 = _stricmp();
    if (iVar11 != 0) {
      _AVEnd = 0;
      iVar11 = 0;
      _AV = _Load_AV_File();
      DAT_2d16_0fae = iVar11;
      while ((iVar11 = Check_Key(), iVar11 == 0 && (_AVEnd == 0))) {
        _Long_Sample_Status();
        if (_AV != 0 || DAT_2d16_0fae != 0) {
          _Process_AV();
        }
        if (((_BumpRate != 0) && (DAT_2d16_1142 <= DAT_2d16_29a0)) &&
           ((DAT_2d16_29a0 != DAT_2d16_1142 || (_fadetimer <= TimerValues)))) {
          uVar17 = _BumpAccum + _BumpTick;
          _fadetimer = (size_t *)((int)TimerValues + ((int)uVar17 >> 8));
          DAT_2d16_1142 =
               DAT_2d16_29a0 + ((int)uVar17 >> 0xf) +
               (uint)CARRY2((uint)TimerValues,(int)uVar17 >> 8);
          _BumpAccum = uVar17 & 0xff;
          iVar11 = _Bump_Palette();
          if (iVar11 == 0) {
            _BumpRate = 0;
          }
        }
      }
      if (_AV != 0 || DAT_2d16_0fae != 0) {
        _Free_AV();
        DAT_2d16_0fae = 0;
        _AV = 0;
      }
      _Fade_Palette_To();
      _Fade_Score();
      _Stop_Sample();
    }
  }
  iVar11 = _stricmp();
  if ((iVar11 != 0) && (iVar11 = _stricmp(), iVar11 != 0)) {
    _Load_Score_File();
    _Play_Score();
    _Char_Gen();
    _Play_Score();
    _Load_Score_File();
    _Fade_Palette_To();
    _sprintf(acStack_ac,unaff_SS);
  }
  uVar30 = Operating_System();
  iVar11 = (int)((ulong)uVar30 >> 0x10);
  if ((int)uVar30 == 3) {
    local_8 = (size_t *)s_MAINW_EXE_2d16_11d7;
  }
  else {
    local_8 = (size_t *)s_MAIN_EXE_2d16_11e1;
  }
  _Prog_End();
  _Cursor_Off();
  psVar7 = _strlen(asStack_5c,unaff_SS);
  if (((size_t *)0x3 < psVar7) &&
     (pcVar21 = _strrchr((char *)asStack_5c,(int)unaff_SS), pcVar21 != (char *)0x0 || iVar11 != 0))
  {
    pcVar21 = _strrchr((char *)asStack_5c,(int)unaff_SS);
    *pcVar21 = '\0';
  }
  _toupper((int)(char)asStack_5c[0]);
  _setdisk();
  _errno = 0;
  iVar11 = _chdir((char *)asStack_5c);
  if (iVar11 != 0) {
    _perror((char *)asStack_5c);
  }
  psVar7 = (size_t *)_execl((char *)local_8,(char *)0x2d16);
  _perror((char *)local_8);
  return psVar7;
LAB_1543_03fc:
  psVar22 = (size_t *)((int)psVar24 * 2);
  switch(psVar24) {
  case (size_t *)0x0:
    goto switchD_1000_582e_caseD_0;
  case (size_t *)0x1:
    *(size_t **)psVar22 = psVar15;
    *(int *)((int)psVar22 + 2) = (int)psVar15;
    *(undefined2 *)0x73 = *(undefined2 *)((int)(undefined4 *)&_environ + 2);
    psVar7 = *(size_t **)(undefined4 *)&_environ;
    *(undefined2 *)0x71 = psVar7;
    return psVar7;
  case (size_t *)0x2:
    _Apply_XOR_Delta_On_Page();
    *local_6 = 0;
    psVar7 = (size_t *)*local_6;
    if ((int)psVar7 < (int)unaff_DI) {
      puVar25 = (undefined1 *)-((int)psVar7 - (int)unaff_DI);
    }
    else {
      puVar25 = (undefined1 *)((int)psVar7 - (int)unaff_DI);
    }
    local_c = 1;
    local_e = (size_t *)puVar25;
    if ((int)psVar7 < (int)unaff_DI) {
      puVar14 = (undefined1 *)(((int)local_8 - (int)unaff_DI) + (int)psVar7);
      if (((int)puVar14 < (int)puVar25) && ((*(uint *)((int)puVar26 + 0x23) & 0x20) == 0)) {
        local_c = -1;
        local_e = (size_t *)puVar14;
      }
    }
    else if (((int)puVar25 <= (int)(unaff_DI + ((int)local_8 - (int)psVar7))) ||
            (local_e = (size_t *)(unaff_DI + ((int)local_8 - (int)psVar7)),
            (*(uint *)((int)puVar26 + 0x23) & 0x20) != 0)) {
      local_c = -1;
      local_e = (size_t *)puVar25;
    }
    if (local_c < 1) {
      for (local_10 = 0; local_10 < (int)local_e; local_10 = local_10 + 1) {
        if (psVar7 == (size_t *)0x0) {
          psVar7 = local_8;
        }
        Apply_Delta();
        psVar7 = (size_t *)((int)psVar7 + local_c);
      }
    }
    else {
      for (local_10 = 0; local_10 < (int)local_e; local_10 = local_10 + 1) {
        psVar7 = (size_t *)((int)psVar7 + local_c);
        Apply_Delta();
        if (psVar7 == local_8) {
          psVar7 = (size_t *)0x0;
        }
      }
    }
    *local_6 = unaff_DI;
    uVar31 = _LogicPage;
    if ((*(uint *)((int)puVar26 + 0x23) & 0x10) != 0) {
      _LogicPage = param_6;
      uStack_22 = param_9;
      uStack_24 = param_8;
      puStack_20 = &stack0x001a;
      uStack_26 = param_11;
      uStack_28 = param_10;
      _Buffer_Bitblit_To_LogicPage();
    }
    _LogicPage = (char *)uVar31;
    return (size_t *)0x1;
  case (size_t *)0x3:
    *(size_t **)psVar22 = psVar19;
    *(int *)((int)psVar22 + 2) = (int)psVar7;
    return psVar15;
  case (size_t *)0x4:
    while ((size_t *)((int)psVar19 + -1) != (size_t *)0x0) {
      puVar4 = unaff_DI;
      unaff_DI = unaff_DI + 1;
      psVar29 = psVar24;
      psVar24 = (size_t *)((int)psVar24 + 1);
      *puVar4 = (char)*psVar29;
      psVar19 = (size_t *)((int)psVar19 + -1);
    }
    bVar28 = false;
    *unaff_DI = 0;
    bVar27 = psVar19 == (size_t *)0x0;
LAB_1000_2fe9:
    psVar29 = (size_t *)FUN_1000_3009();
    bVar16 = (byte)psVar29;
    if (!bVar28 && !bVar27) {
LAB_1000_2ff9:
      if ((bVar16 != 0x20) && (bVar16 != 0xd)) goto code_r0x00013001;
      goto LAB_1000_3005;
    }
    while( true ) {
      uVar31 = DAT_1000_2f74;
      psVar7 = (size_t *)psVar29;
      if (bVar28) break;
      bVar28 = (byte)psVar29 < 0xd;
      bVar27 = (byte)psVar29 == 0xd;
      if (bVar27) goto LAB_1000_3005;
      psVar29 = (size_t *)FUN_1000_3009();
      bVar16 = (byte)psVar29;
      if (bVar28 || bVar27) goto LAB_1000_2ff9;
    }
    pcVar21 = &stack0xf80e;
    iVar18 = iVar18 + (int)((ulong)psVar29 >> 0x10);
    *(undefined2 *)&__argc = psVar19;
    iVar11 = (int)((int)psVar19 + 1) * -4;
    piVar13 = (int *)(local_7e6 + iVar11 + -0xc);
    if (&stack0xf80e < (undefined1 *)(((int)psVar19 + 1) * 4)) {
      _abort();
      return psVar7;
    }
    *(int **)(undefined4 *)&__argv = piVar13;
    *(undefined2 *)((int)(undefined4 *)&__argv + 2) = unaff_SS;
    uVar31 = DAT_1000_2f74;
    do {
      if (iVar18 == 0) break;
      *piVar13 = (int)pcVar21;
      piVar13[1] = (int)unaff_SS;
      piVar13 = piVar13 + 2;
      do {
        pcVar2 = pcVar21;
        pcVar21 = pcVar21 + 1;
        iVar18 = iVar18 + -1;
      } while (iVar18 != 0 && *pcVar2 != '\0');
    } while (*pcVar2 == '\0');
    *piVar13 = 0;
    piVar13[1] = 0;
    *(undefined2 *)(local_7e6 + iVar11 + -0xe) = *(undefined2 *)0x310c;
    *(undefined2 *)(local_7e6 + iVar11 + -0x10) = *(undefined2 *)0x310a;
    *(undefined2 *)0x6b = *(undefined2 *)&__argc;
    *(undefined2 *)0x6f = *(undefined2 *)((int)(undefined4 *)&__argv + 2);
    *(undefined2 *)0x6d = *(undefined2 *)(undefined4 *)&__argv;
                    /* WARNING: Could not recover jumptable at 0x0001309b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    psVar7 = (size_t *)(*(code *)*(undefined2 *)0x3108)();
    return psVar7;
  case (size_t *)0x5:
    break;
  case (size_t *)0x6:
    pbVar1 = (byte *)((int)psVar24 * 3 + -1);
    bVar16 = *pbVar1;
    *pbVar1 = bVar16 << 4 | (byte)(CONCAT11((int)psVar24 < 0,bVar16) >> 5);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case (size_t *)0x7:
    *(char **)(&stack0x03dd + (int)unaff_DI) =
         (char *)(*(int *)(&stack0x03dd + (int)unaff_DI) + (int)psVar19);
    ((undefined1 *)((int)psVar22 + (int)unaff_DI))[-0x72e2] =
         ((undefined1 *)((int)psVar22 + (int)unaff_DI))[-0x72e2] + (char)psVar19;
    ((undefined1 *)((int)psVar22 + (int)unaff_DI))[0x7b] =
         ((undefined1 *)((int)psVar22 + (int)unaff_DI))[0x7b] + cVar6;
    goto code_r0x00010090;
  case (size_t *)0x8:
    psVar15 = (size_t *)((int)param_1 - (MouseWidth - MouseXHot));
    if ((int)psVar15 < 0) {
      psVar15 = (size_t *)0x0;
    }
    psVar22 = (size_t *)(param_2 + -(MouseHeight - MouseYHot));
    if ((int)psVar22 < 0) {
      psVar22 = (size_t *)0x0;
    }
    psVar19 = (size_t *)(param_3 + MouseXHot);
    if ((size_t *)0x13e < psVar19) {
      psVar19 = (size_t *)0x13f;
    }
    psVar7 = (size_t *)(param_4 + MouseYHot);
    if ((size_t *)0xc6 < psVar7) {
      psVar7 = (size_t *)0xc7;
    }
    break;
  case (size_t *)0x9:
    uVar31 = Default_Score_Close();
    cRam0002d927 = cRam0002d927 + (char)((uint)uVar31 >> 8);
    *(char *)((int)psVar22 + (int)psVar24) =
         *(char *)((int)psVar22 + (int)psVar24) +
         (char)uVar31 + *(char *)((int)psVar22 + (int)psVar24);
    goto code_r0x00015ee2;
  default:
    return psVar15;
  case (size_t *)0xb:
  case (size_t *)0x14:
    *(uint *)(&stack0x022c + (int)unaff_DI) =
         *(uint *)(&stack0x022c + (int)unaff_DI) & (int)psVar15 + 0x76d2U;
    (&stack0x2c1c)[(int)unaff_DI] =
         (&stack0x2c1c)[(int)unaff_DI] + (char)(char *)((int)psVar15 + 0x76d2U);
    psRam0002d1d7 = psVar22;
    psRam0002d1db = local_e;
    puRam0002d1f1 = &stack0xfffe;
    FUN_1000_017d();
    psVar7 = (size_t *)0x0;
    iVar11 = 0;
    pcVar21 = (char *)0x0;
    uVar17 = 0x7fff;
    goto LAB_1000_0037;
  case (size_t *)0xc:
  case (size_t *)0x15:
                    /* WARNING: Does not return */
    pcVar5 = (code *)invalidInstructionException();
    (*pcVar5)();
  case (size_t *)0xd:
    pcVar2 = (char *)((int)psVar24 * 3 + 0x1e);
    *pcVar2 = *pcVar2 + (char)psVar7;
    goto code_r0x000156ef;
  case (size_t *)0xe:
    _Bit_Blit();
    _Change_Window();
    _New_Window();
    psVar7 = (size_t *)Show_Mouse();
    return psVar7;
  case (size_t *)0xf:
    goto switchD_1000_582e_caseD_f;
  case (size_t *)0x10:
    _Free();
    DAT_2d16_167a = 0;
    _ScreenSaveBuffer = 0;
    _memcpy(auStack_53,unaff_SS,(size_t)CONCAT22(unaff_SS,&uStack_22));
    _Set_Palette();
    Show_Mouse();
    return (size_t *)0x1;
  case (size_t *)0x11:
    _Buffer_To_Page();
    _up = 0;
    if (voc != 0 || DAT_2d16_114a != (size_t *)0x0) {
      _Free();
    }
    DAT_2d16_114a = (size_t *)0x0;
    voc = 0;
    if ((*(char *)CONCAT22(local_8,(char *)0x2d16) == '$') &&
       (pcVar21 = _strchr((char *)0x2d17,(int)local_8),
       pcVar21 != (char *)0x0 || psVar7 != (size_t *)0x0)) {
      _memset(&uStack_24,(int)unaff_SS,0x100000);
      _strchr((char *)0x2d17,(int)local_8);
      _memcpy(&uStack_24,unaff_SS,CONCAT22(local_8,0x2d17));
      _strcat((char *)&uStack_24,unaff_SS);
      uVar17 = DAT_2d16_29a0;
      psVar7 = TimerValues;
      voc = _Load_Quick_Sample();
      DAT_2d16_114a = TimerValues;
      TimerValues = psVar7;
      DAT_2d16_29a0 = uVar17;
    }
    if (((voc == 0 && DAT_2d16_114a == (size_t *)0x0) || (_SampleType == 0)) || ((int)psVar24 < 0))
    {
      psVar12 = (size_t *)((uint)local_8 | 0x2d16);
      if ((psVar12 != (size_t *)0x0) && (*(char *)CONCAT22(local_8,(char *)0x2d16) != '\0')) {
        if (*(char *)CONCAT22(local_8,(char *)0x2d16) == '$') {
          pcVar21 = _strchr((char *)0x2d17,(int)local_8);
          local_e = (size_t *)(pcVar21 + 1);
          local_8 = psVar7;
        }
        _Raw_Palette_Fade();
        if ((int)psVar24 < 0) {
          _Set_Font();
          _Set_Font_Palette();
          uRam0002f824 = 0xfffe;
        }
        uRam0002f826 = 0xfffc;
        pcVar21 = _strchr((char *)local_e,(int)local_8);
        if (pcVar21 == (char *)0x0 && psVar7 == (size_t *)0x0) {
          _oldy = (int)cRam0002f829;
        }
        else {
          _oldy = (int)cRam0002f829 << 1;
        }
        _Page_To_Buffer();
        _up = 1;
        bVar16 = 0;
        psVar12 = local_8;
        psVar7 = local_e;
        while (psVar19 = psVar7, (char)*(size_t *)CONCAT22(local_8,local_e) != '\0') {
          pbVar9 = (byte *)_strchr((char *)local_e,(int)local_8);
          if (pbVar9 != (byte *)0x0 || psVar19 != (size_t *)0x0) {
            bVar16 = *(byte *)CONCAT22(psVar19,pbVar9);
            *(byte *)CONCAT22(psVar19,pbVar9) = 0;
          }
          iVar11 = _String_Pixel_Width();
          psVar7 = (size_t *)(0x140 - iVar11 >> 0xf);
          _Text_Print();
          psVar12 = _strlen(local_e,(char *)local_8);
          local_e = (size_t *)((int)local_e + (int)psVar12);
          if (bVar16 != 0) {
            psVar12 = (size_t *)(uint)bVar16;
            *(byte *)CONCAT22(psVar19,pbVar9) = bVar16;
            local_e = (size_t *)((int)local_e + 1);
          }
        }
        uRam0002f826 = 0;
        if ((int)psVar24 < 0) {
          _Set_Font();
          psVar12 = (size_t *)_Set_Font_Palette();
          uRam0002f824 = 0;
        }
      }
    }
    else {
      psVar12 = (size_t *)0x0;
      if (voc != 0 || DAT_2d16_114a != (size_t *)0x0) {
        psVar12 = (size_t *)_Play_Long_Sample_Vol();
      }
    }
    return psVar12;
  case (size_t *)0x12:
    if ((int)*psVar22 == 0 && *(int *)((int)psVar22 + 2) == 0) {
      return (size_t *)0x0;
    }
    if (*(int *)((int)__AV_Anims + (int)psVar24 * 0xc + 8) == 0) {
      _LOL_Close_Animation();
      _memset((void *)(_AV_Anims + (int)psVar24 * 0xc),DAT_2d16_39ea,0xc0000);
      return (size_t *)0x1;
    }
code_r0x00015ee2:
    *(undefined2 *)((int)psVar24 * 0x8c + 0x3472) = 0;
    *(undefined2 *)((undefined *)&_Anim + (int)psVar24 * 0x8c) = 0;
    uVar31 = (undefined2)((ulong)__AV_Anims >> 0x10);
    puVar26 = (undefined2 *)((int)__AV_Anims + (int)psVar24 * 0xc);
    puVar26[1] = 0;
    *puVar26 = 0;
    return (size_t *)0x1;
  case (size_t *)0x16:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case (size_t *)0x17:
    uVar31 = 0x1000;
    if ((((FILE *)param_1->_IO_save_base == param_1) && ((int)unaff_DI < 3)) &&
       (param_6 < (char *)0x8000)) {
      if ((DAT_2d16_33ee == 0) && (param_1 == (FILE *)0x2e2e)) {
        DAT_2d16_33ee = 1;
      }
      else if ((DAT_2d16_33ec == 0) && (param_1 == (FILE *)(FILE *)&__streams)) {
        DAT_2d16_33ec = 1;
      }
      if (((FILE *)CONCAT22(param_2,param_1))->_flags != 0) {
        _fseek(param_1,0,1);
      }
      if (((uint)param_1->_IO_read_ptr & 4) != 0) {
        _free(param_1->_IO_write_base);
      }
      param_1->_IO_read_ptr = (char *)((uint)param_1->_IO_read_ptr & 0xfff3);
      param_1->_IO_read_base = (char *)0x0;
      pcVar21 = (char *)((int)&param_1->_IO_read_end + 1);
      param_1->_IO_write_ptr = param_2;
      param_1->_IO_write_base = pcVar21;
      param_1->_IO_buf_base = param_2;
      param_1->_IO_write_end = pcVar21;
      if ((unaff_DI != (undefined1 *)0x2) && (param_6 != (char *)0x0)) {
        DAT_2d16_2e10 = 0x1000;
        __exitbuf = 0x5398;
        if (param_3 == (char *)0x0 && param_4 == (char *)0x0) {
          param_3 = _malloc((size_t)CONCAT22(uVar31,param_6));
          if (param_3 == (char *)0x0 && pcVar21 == (char *)0x0) goto LAB_1000_441b;
          param_1->_IO_read_ptr = (char *)((uint)param_1->_IO_read_ptr | 4);
          param_4 = pcVar21;
        }
        param_1->_IO_buf_base = param_4;
        param_1->_IO_write_end = param_3;
        param_1->_IO_write_ptr = param_4;
        param_1->_IO_write_base = param_3;
        param_1->_IO_read_base = param_6;
        if (unaff_DI == (undefined1 *)0x1) {
          param_1->_IO_read_ptr = (char *)((uint)param_1->_IO_read_ptr | 8);
        }
      }
      psVar7 = (size_t *)0x0;
    }
    else {
LAB_1000_441b:
      psVar7 = (size_t *)0xffff;
    }
    return psVar7;
  case (size_t *)0x18:
    uVar31 = _LOL_Open_Animation();
    puVar26[1] = psVar7;
    *local_6 = uVar31;
    return (size_t *)0x1;
  case (size_t *)0x19:
    if ((psVar15 == (size_t *)*(int *)(iVar8 + 10)) && ((int)psVar22[2] == *(int *)(iVar8 + 8))) {
      if ((uRam0002d4a6 & 0xff) == 1) {
        local_6 = (undefined2 *)CONCAT22(iVar11,(undefined2 *)0x1);
      }
      else {
        uRam0002d4a6 = uRam0002d4a6 & 0xff00;
      }
      bRam0002d4a5 = bRam0002d4a5 - 1;
      local_8 = (size_t *)(uint)bRam0002d4a5;
      _Set_FileData();
    }
    iVar11 = iRam0002d49c;
    if ((psVar24 == (size_t *)0xffff) || (*(int *)(iVar8 + 8) == 0 && *(int *)(iVar8 + 10) == 0)) {
      _ibm_close();
    }
    else {
      if ((iRam0002d49e == *(int *)(iVar8 + 10)) && (iRam0002d49c == *(int *)(iVar8 + 8))) {
        if (*(char *)(iVar8 + 0x11) == '\0') {
          *(undefined2 *)(iVar8 + 10) = 0;
          *(undefined2 *)(iVar8 + 8) = 0;
        }
        if ((bRam0002d4a5 == 0) && ((uRam0002d4a6 & 0x800) != 0)) {
          _Free();
          iRam0002d49e = 0;
          iRam0002d49c = 0;
          local_6 = (undefined2 *)CONCAT22(1,(undefined2 *)local_6);
        }
      }
      else if (((*(uint *)(iVar8 + 0x12) & 0x800) != 0) && (*(char *)(iVar8 + 0x11) == '\0')) {
        _Free();
        *(undefined2 *)(iVar8 + 10) = 0;
        *(undefined2 *)(iVar8 + 8) = 0;
        local_6 = (undefined2 *)CONCAT22(1,(undefined2 *)local_6);
      }
      _Set_FileData();
      _Set_FileData();
      if (((((undefined2 *)local_6 == (undefined2 *)0x0) && (local_6._2_2_ == 0)) &&
          (local_8 == (size_t *)0x0)) && ((*(uint *)(iVar8 + 0x12) & 0x6000) == 0)) {
        while (piVar13 = (int *)_Get_FileData(),
              *(int *)CONCAT22(iVar11,piVar13) != 0 || piVar13[1] != 0) {
          if (((piVar13[4] != 0 || piVar13[5] != 0) && (*(char *)((int)piVar13 + 0x11) == '\0')) &&
             ((piVar13[9] & 0x6000U) == 0)) {
            if ((piVar13[9] & 0xffU) == 0xff) {
              iVar8 = iVar11;
              _Free();
              piVar13[5] = 0;
              piVar13[4] = 0;
              iVar11 = iVar8;
            }
            else {
              piVar13[9] = piVar13[9] + 1;
            }
            _Set_FileData();
          }
        }
      }
    }
    *(undefined2 *)(size_t *)((int)unaff_DI * 0x14) = 1;
    _CallingDOSInt = _CallingDOSInt + -1;
    return (size_t *)((int)unaff_DI * 0x14);
  case (size_t *)0x1a:
    _Set_Font();
    local_6._2_2_ = param_7 & 0xf0;
    _point = unaff_DI;
    if (((local_6._2_2_ != _shadow) && (local_6._2_2_ != 0)) ||
       (param_1 == (FILE *)0x0 && param_2 == (char *)0x0)) {
      _memset((undefined1 *)&fontpalette,0x2d16,0x100000);
      DAT_2d16_3a10 = 0x56;
      iVar11 = 4;
      puVar23 = (uint *)0x1000;
      do {
        if (*puVar23 == local_6._2_2_) {
                    /* WARNING: Could not recover jumptable at 0x0001929a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          psVar7 = (size_t *)(*(code *)puVar23[4])();
          return psVar7;
        }
        puVar23 = puVar23 + 1;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      fontpalette = param_6._0_1_;
      DAT_2d16_3a0d = param_5;
      _Set_Font_Palette();
      _shadow = local_6._2_2_;
    }
    psVar7 = (size_t *)0x0;
    if (param_1 != (FILE *)0x0 || param_2 != (char *)0x0) {
      _vsprintf((char *)&buffer,(char *)0x2d16,param_1);
      if ((param_7 & 0xf00) == 0x100) {
        _String_Pixel_Width();
      }
      else if ((param_7 & 0xf00) == 0x200) {
        _String_Pixel_Width();
      }
      psVar7 = (size_t *)_Text_Print();
    }
    return psVar7;
  case (size_t *)0x1b:
    goto switchD_1000_582e_caseD_1b;
  case (size_t *)0x1c:
    *(char *)((int)psVar24 * 3) = *(char *)((int)psVar24 * 3) + cVar6;
    (&stack0x0ac2)[(int)unaff_DI] = (&stack0x0ac2)[(int)unaff_DI] & bVar16;
    goto code_r0x00015d06;
  case (size_t *)0x1d:
    (&stack0x093e)[(int)psVar24] = (&stack0x093e)[(int)psVar24] + (char)psVar22;
    out(0x26,bVar16);
    goto code_r0x000155d1;
  }
  MouseUpdate = MouseUpdate + 1;
  if (MCState == 0) {
    MouseCXLeft = psVar15;
    MouseCYUpper = psVar22;
    MouseCXRight = psVar19;
    MouseCYLower = psVar7;
  }
  if (MouseCXLeft <= psVar15) {
    MouseCXLeft = psVar15;
  }
  if (MouseCYUpper <= psVar22) {
    MouseCYUpper = psVar22;
  }
  if (psVar19 <= MouseCXRight) {
    MouseCXRight = psVar19;
  }
  if (psVar7 <= MouseCYLower) {
    MouseCYLower = psVar7;
  }
  if (((((MCState & 0x4000) == 0) && (MouseCXLeft <= MouseX)) && (MouseX <= MouseCXRight)) &&
     ((MouseCYUpper <= MouseY && (MouseY <= MouseCYLower)))) {
    FUN_2d16_2d4c();
    MCState = MCState | 0x4000;
  }
  MCState = CONCAT11((char)(MCState >> 8),(byte)MCState + 1 + (0xfe < (byte)MCState)) | 0x8000;
  MouseUpdate = MouseUpdate + -1;
  return psVar12;
  while( true ) {
    if (uVar17 == 0) goto LAB_1000_007e;
    iVar11 = iVar11 + 1;
    if (*pcVar21 == '\0') break;
LAB_1000_0037:
    if (uVar17 != 0) {
      uVar17 = uVar17 - 1;
      pcVar2 = pcVar21;
      pcVar21 = pcVar21 + 1;
      if (*pcVar2 != '\0') goto LAB_1000_0037;
    }
  }
  iRam0002d1d5 = -(uVar17 | 0x8000);
  uRam0002d1d9 = iVar11 * 4 + 0x10U & 0xfff0;
  if (__stklen < 0x200) {
    __stklen = (undefined1 *)0x200;
  }
  psVar19 = (size_t *)0x4;
  puVar25 = (undefined1 *)(((uint)__stklen >> 4) + 1);
  if (&stack0xfffe + -(int)unaff_SS < puVar25) {
LAB_1000_007e:
    _abort();
    return psVar7;
  }
  pcRam0002d1e9 = unaff_SS + (int)puVar25;
  pcRam0002d1ed = pcRam0002d1e9;
code_r0x00010090:
  bVar16 = (byte)psVar19;
  pcVar5 = (code *)swi(0x21);
  (*pcVar5)();
  uVar31 = _DGROUP_;
  puVar25 = (undefined1 *)(iVar33 << (bVar16 & 0x1f));
  puVar26 = (undefined2 *)&_sh;
  __stklen = puVar25;
  for (iVar11 = 0xcaa; iVar11 != 0; iVar11 = iVar11 + -1) {
    puVar3 = puVar26;
    puVar26 = (undefined2 *)((int)puVar26 + 1);
    *(undefined1 *)puVar3 = 0;
  }
  if (((0x14 < __nfile) && (bVar27 = bRam0002d1dd < 3, !bVar27)) &&
     ((3 < bRam0002d1dd || (bVar27 = __osminor < 0x1e, !bVar27)))) {
    pcVar5 = (code *)swi(0x21);
    psVar7 = (size_t *)(*pcVar5)();
    if (!bVar27) {
      pcVar5 = (code *)swi(0x21);
      psVar7 = (size_t *)(*pcVar5)();
      if (!bVar27) {
        pcVar5 = (code *)swi(0x21);
        psVar7 = (size_t *)(*pcVar5)();
        if (!bVar27) {
          puRam0002d1f1 = (undefined1 *)((int)psVar7 + 1);
          pcVar5 = (code *)swi(0x21);
          psVar7 = (size_t *)(*pcVar5)();
          if (!bVar27) {
            pcVar5 = (code *)swi(0x21);
            psVar7 = (size_t *)(*pcVar5)();
            if (!bVar27) goto LAB_1000_010c;
          }
        }
      }
    }
    _abort();
    return psVar7;
  }
LAB_1000_010c:
  pcVar5 = (code *)swi(0x1a);
  cVar6 = (*pcVar5)();
  if (cVar6 != '\0') {
    DAT_0000_0470 = 1;
  }
  uRam0002d1e1 = extraout_DX_00;
  iRam0002d1e3 = iVar11;
  *(undefined2 *)(puVar25 + -2) = 0x138;
  FUN_1000_01ed();
  *(undefined2 *)(puVar25 + -2) = uRam0002d1d3;
  *(undefined2 *)(puVar25 + -4) = uRam0002d1d1;
  *(undefined2 *)(puVar25 + -6) = uRam0002d1cf;
  *(undefined2 *)(puVar25 + -8) = uRam0002d1cd;
  *(undefined2 *)(puVar25 + -10) = uRam0002d1cb;
  *(undefined2 *)(puVar25 + -0xc) = 0x1000;
  *(undefined2 *)(puVar25 + -0xe) = 0x151;
  uVar31 = _main();
  *(undefined2 *)(puVar25 + -0xc) = uVar31;
  *(undefined2 *)(puVar25 + -0xe) = 0x1b1c;
  *(undefined2 *)(puVar25 + -0x10) = 0x157;
  _exit(*(int *)(puVar25 + -0xc));
  *(undefined2 *)(puVar25 + -0xe) = 0x3438;
  *(undefined2 *)(puVar25 + -0x10) = 0x3456;
  *(undefined2 *)(puVar25 + -0x12) = 0x167;
  psVar7 = (size_t *)FUN_1000_0231();
  return psVar7;
}


//// Restart_AV_Process @ 1543:0939

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far Restart_AV_Process(void)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined2 uVar5;
  
  for (iVar4 = 1; puVar2 = __AV_Anim_Lines, iVar4 < 10; iVar4 = iVar4 + 1) {
    _memset((void *)(_AV_Anims + iVar4 * 0xc),DAT_2d16_39ea,0xc0000);
  }
  uVar5 = (undefined2)((ulong)__AV_Anim_Lines >> 0x10);
  puVar3 = (undefined2 *)__AV_Anim_Lines;
  uVar1 = puVar3[10];
  puVar3[1] = puVar3[0xb];
  *puVar2 = uVar1;
  uVar1 = TimerValues;
  uVar5 = (undefined2)((ulong)__AV_Anim_Lines >> 0x10);
  puVar3 = (undefined2 *)__AV_Anim_Lines;
  puVar3[3] = DAT_2d16_29a0;
  puVar3[2] = uVar1;
  return 1;
}


//// End_AV_Process @ 1543:099b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far End_AV_Process(void)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)__AV_Anim_Lines >> 0x10);
  puVar1 = (undefined2 *)((int)__AV_Anim_Lines + _Current_AV_Line * 0x18);
  puVar1[1] = 0;
  *puVar1 = 0;
  if (_Current_AV_Line == 0) {
    _AVEnd = 1;
  }
  return 0xfffe;
}


//// Default_Anim_Open @ 1543:09cb

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far Default_Anim_Open(int *param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  int *piVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined4 local_6;
  
  uVar2 = DAT_2d16_39ea;
  iVar1 = *param_1;
  puVar4 = (undefined2 *)(_AV_Anims + iVar1 * 0xc);
  local_6 = (undefined2 *)CONCAT22(DAT_2d16_39ea,puVar4);
  uVar6 = (undefined2)((ulong)param_1 >> 0x10);
  piVar5 = (int *)param_1;
  puVar4[2] = piVar5[2];
  puVar4[3] = piVar5[3];
  puVar4[4] = piVar5[4];
  puVar4[5] = piVar5[5];
  uVar7 = (undefined2)((ulong)__AV_Strings >> 0x10);
  uVar3 = uVar2;
  uVar6 = _LOL_Open_Animation(iVar1,(int)__AV_Strings + *(int *)((int)__AV_Strings + piVar5[1] * 2),
                              uVar7,puVar4[2],puVar4[3],10,puVar4[4],puVar4[5]);
  puVar4[1] = uVar3;
  *local_6 = uVar6;
  return 1;
}


//// Default_Anim_Close @ 1543:0a7e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far Default_Anim_Close(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  undefined2 uVar4;
  
  iVar1 = *param_1;
  uVar4 = (undefined2)((ulong)__AV_Anims >> 0x10);
  piVar2 = (int *)((int)__AV_Anims + iVar1 * 0xc);
  if (*piVar2 == 0 && piVar2[1] == 0) {
    uVar4 = 0;
  }
  else {
    if (*(int *)((int)__AV_Anims + iVar1 * 0xc + 8) == 0) {
      _LOL_Close_Animation();
      _memset((void *)(_AV_Anims + iVar1 * 0xc),DAT_2d16_39ea,0xc0000);
    }
    else {
      *(undefined2 *)(iVar1 * 0x8c + 0x3472) = 0;
      *(undefined2 *)((undefined *)&_Anim + iVar1 * 0x8c) = 0;
      uVar4 = (undefined2)((ulong)__AV_Anims >> 0x10);
      puVar3 = (undefined2 *)((int)__AV_Anims + iVar1 * 0xc);
      puVar3[1] = 0;
      *puVar3 = 0;
    }
    uVar4 = 1;
  }
  return uVar4;
}


//// Default_Background_Process_Start @ 1543:0b15

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far Default_Background_Process_Start(int *param_1)

{
  undefined2 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 local_6;
  
  uVar1 = _DAT_2d16_39ee;
  piVar2 = (int *)(_AV_Anim_Lines + *param_1 * 0x18);
  local_6 = (int *)CONCAT22(_DAT_2d16_39ee,piVar2);
  if (piVar2[10] == 0 && piVar2[0xb] == 0) {
    iVar4 = (int)((ulong)__AV_Buffer >> 0x10);
    iVar3 = (int)__AV_Buffer + *(int *)((int)__AV_Buffer + *param_1 * 2) * 2;
    piVar2[0xb] = iVar4;
    piVar2[10] = iVar3;
  }
  else {
    iVar4 = piVar2[0xb];
    iVar3 = piVar2[10];
  }
  piVar2[1] = iVar4;
  *local_6 = iVar3;
  return 1;
}


//// Default_Background_Process_End @ 1543:0b8f

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far Default_Background_Process_End(int *param_1)

{
  undefined2 *puVar1;
  undefined4 local_6;
  
  puVar1 = (undefined2 *)(_AV_Anim_Lines + *param_1 * 0x18);
  local_6 = (undefined2 *)CONCAT22(_DAT_2d16_39ee,puVar1);
  puVar1[1] = 0;
  *local_6 = 0;
  return 1;
}


//// Default_Display_Frame @ 1543:0bc7

undefined2 __cdecl16far Default_Display_Frame(int *param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 local_a;
  
  iVar1 = *param_1 * 0x8c;
  local_a = (undefined2 *)CONCAT22(0x2d16,(undefined *)&_Anim + iVar1);
  if ((*(uint *)(iVar1 + 0x3482) & 0x4000) == 0) {
    uVar2 = 8;
  }
  else {
    uVar2 = 2;
  }
  _Animate_Frame(*local_a,*(undefined2 *)(iVar1 + 0x3472),((int *)param_1)[1],
                 *(undefined2 *)(iVar1 + 0x3474),*(undefined2 *)(iVar1 + 0x3476),uVar2,
                 *(uint *)(iVar1 + 0x3482) & 0xf0ff);
  return 1;
}


//// Default_Display_Text @ 1543:0c3b

undefined2 __cdecl16far Default_Display_Text(undefined2 *param_1)

{
  _Intro_Print(*param_1,((undefined2 *)param_1)[1]);
  return 1;
}


//// Custom_Display_Text @ 1543:0c59

undefined2 __cdecl16far Custom_Display_Text(undefined2 *param_1)

{
  _Intro_Print(*param_1,((undefined2 *)param_1)[1]);
  return 1;
}


//// Default_Sample_Load @ 1543:0c77

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far Default_Sample_Load(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)__AV_Strings >> 0x10);
  iVar2 = (int)__AV_Strings + *(int *)((int)__AV_Strings + *param_1 * 2);
  iVar1 = ((int *)param_1)[1];
  iVar3 = iVar2;
  if (*(int *)(iVar1 * 4 + 0xdbc) != 0 || *(int *)(iVar1 * 4 + 0xdbe) != 0) {
    _Free_Sample(*(undefined2 *)(iVar1 * 4 + 0xdbc),*(undefined2 *)(iVar1 * 4 + 0xdbe));
  }
  uVar4 = _Load_Quick_Sample(iVar2,uVar4);
  *(int *)(iVar1 * 4 + 0xdbe) = iVar3;
  *(undefined2 *)(iVar1 * 4 + 0xdbc) = uVar4;
  return 1;
}


//// Default_Sample_Close @ 1543:0ced

undefined2 __cdecl16far Default_Sample_Close(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 * 4 + 0xdbc) != 0 || *(int *)(iVar1 * 4 + 0xdbe) != 0) {
    _Free(*(undefined2 *)(iVar1 * 4 + 0xdbc),*(undefined2 *)(iVar1 * 4 + 0xdbe));
    *(undefined2 *)(iVar1 * 4 + 0xdbe) = 0;
    *(undefined2 *)(iVar1 * 4 + 0xdbc) = 0;
  }
  return 1;
}


//// Default_Sample_Play @ 1543:0d36

undefined2 __cdecl16far Default_Sample_Play(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (((int *)param_1)[1] * 0xff) / 100;
  iVar1 = *param_1;
  if (*(int *)(iVar1 * 4 + 0xdbc) == 0 && *(int *)(iVar1 * 4 + 0xdbe) == 0) {
    _Play_Sound_Vol(iVar1,iVar2);
  }
  else {
    _Play_Long_Sample_Vol
              (*(undefined2 *)(iVar1 * 4 + 0xdbc),*(undefined2 *)(iVar1 * 4 + 0xdbe),0,iVar2);
  }
  return 1;
}


//// Default_Sample_Stop @ 1543:0d95

undefined2 __cdecl16far Default_Sample_Stop(void)

{
  _Stop_Sample();
  return 1;
}


//// Default_Score_Load @ 1543:0da4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far Default_Score_Load(int *param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)__AV_Strings >> 0x10);
  _Load_Score_File((int)__AV_Strings + *(int *)((int)__AV_Strings + *param_1 * 2),uVar1,0,0,0,0);
  uVar1 = (undefined2)((ulong)__AV_Strings >> 0x10);
  _Load_Sound_File((int)__AV_Strings + *(int *)((int)__AV_Strings + *param_1 * 2),uVar1,0,0,0,0);
  return 1;
}


//// Default_Score_Close @ 1543:0e08

undefined2 __cdecl16far Default_Score_Close(void)

{
  return 1;
}


//// Default_Score_Play @ 1543:0e12

undefined2 __cdecl16far Default_Score_Play(undefined2 *param_1)

{
  _Play_Score(*param_1);
  return 1;
}


//// Default_Score_Stop @ 1543:0e28

undefined2 __cdecl16far Default_Score_Stop(void)

{
  _Stop_Score();
  return 1;
}


//// Default_Sound_Load @ 1543:0e37

undefined2 __cdecl16far Default_Sound_Load(void)

{
  return 1;
}


//// Default_Sound_Close @ 1543:0e41

undefined2 __cdecl16far Default_Sound_Close(void)

{
  return 1;
}


//// Default_Sound_Play @ 1543:0e4b

undefined2 __cdecl16far Default_Sound_Play(undefined2 *param_1)

{
  _Play_Sound(*param_1);
  return 1;
}


//// Default_Sound_Stop @ 1543:0e61

undefined2 __cdecl16far Default_Sound_Stop(void)

{
  _Stop_Sound();
  return 1;
}


//// Default_Loop_Start @ 1543:0e70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far Default_Loop_Start(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  undefined4 local_6;
  
  uVar2 = _DAT_2d16_39ee;
  puVar3 = (undefined2 *)(_AV_Anim_Lines + _Current_AV_Line * 0x18);
  local_6 = (undefined2 *)CONCAT22(_DAT_2d16_39ee,puVar3);
  uVar1 = *local_6;
  puVar3[7] = puVar3[1];
  puVar3[6] = uVar1;
  return 1;
}


//// Default_Loop_End @ 1543:0eac

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far Default_Loop_End(int *param_1)

{
  uint *puVar1;
  uint uVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined2 uVar5;
  int iVar6;
  undefined2 *puVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined4 local_6;
  
  uVar5 = _DAT_2d16_39ee;
  iVar6 = *param_1;
  puVar7 = (undefined2 *)(_AV_Anim_Lines + _Current_AV_Line * 0x18);
  local_6 = (undefined2 *)CONCAT22(_DAT_2d16_39ee,puVar7);
  if (puVar7[6] == 0 && puVar7[7] == 0) {
    uVar5 = 0xfffe;
  }
  else {
    uVar3 = puVar7[6];
    puVar7[1] = puVar7[7];
    *local_6 = uVar3;
    if (iVar6 != 0) {
      uVar9 = 0;
      uVar8 = 0x8000;
      _rand();
      iVar6 = iVar6 >> 0xf;
      uVar3 = LXMUL_(uVar8,uVar9);
      uVar4 = LDIV_(uVar3,iVar6,uVar8,uVar9);
      puVar1 = puVar7 + 4;
      uVar2 = *puVar1;
      *puVar1 = *puVar1 + uVar4;
      puVar7[5] = puVar7[5] + ((int)uVar4 >> 0xf) + (uint)CARRY2(uVar2,uVar4);
    }
    uVar5 = 1;
  }
  return uVar5;
}


//// Default_Stop_Loop @ 1543:0f32

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far Default_Stop_Loop(int *param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)__AV_Anim_Lines >> 0x10);
  iVar1 = (int)__AV_Anim_Lines + *param_1 * 0x18;
  *(undefined2 *)(iVar1 + 0xe) = 0;
  *(undefined2 *)(iVar1 + 0xc) = 0;
  return 1;
}


//// Default_User_Function @ 1543:0f59

undefined2 __cdecl16far Default_User_Function(int *param_1)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  
  puVar1 = (undefined2 *)(*param_1 * 4 + 0x110);
  uVar2 = (*(code *)*puVar1)((char *)s_Not_enough_disk_space_to_run_Lan_2d16_1523 + 0x20,
                             (int *)param_1 + 1,param_1._2_2_);
  return uVar2;
}


//// Default_Time_Start @ 1543:0f8b

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far Default_Time_Start(void)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 local_6;
  
  for (iVar3 = 0; uVar2 = _DAT_2d16_39ee, iVar1 = TimerValues, iVar3 < 10; iVar3 = iVar3 + 1) {
    piVar4 = (int *)(_AV_Anim_Lines + iVar3 * 0x18);
    local_6 = (int *)CONCAT22(_DAT_2d16_39ee,piVar4);
    if (*local_6 != 0 || piVar4[1] != 0) {
      piVar4[5] = DAT_2d16_29a0;
      piVar4[4] = iVar1;
    }
  }
  return 1;
}


//// Default_Time_Stop @ 1543:0fd9

undefined2 __cdecl16far Default_Time_Stop(void)

{
  return 1;
}


//// Default_AV_Error_Trap @ 1543:0fe3

undefined2 __cdecl16far Default_AV_Error_Trap(void)

{
  _AV_Debug_Print(0x353,0x2d16);
  Clear_KeyBuffer();
  Get_Key();
  return 0xffff;
}


//// AV_Button_Setup @ 1543:1003

undefined2 __cdecl16far AV_Button_Setup(void)

{
  return 1;
}


//// AV_Process_Input @ 1543:100d

undefined2 __cdecl16far AV_Process_Input(void)

{
  return 1;
}


//// Default_Start_Timeline @ 1543:1017

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far Default_Start_Timeline(int *param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  
  iVar4 = *param_1;
  uVar5 = (undefined2)((ulong)__AV_Anim_Lines >> 0x10);
  iVar2 = (int)__AV_Anim_Lines + iVar4 * 0x18;
  uVar1 = *(undefined2 *)(iVar2 + 0x14);
  puVar3 = (undefined2 *)((int)__AV_Anim_Lines + iVar4 * 0x18);
  puVar3[1] = *(undefined2 *)(iVar2 + 0x16);
  *puVar3 = uVar1;
  uVar5 = DAT_2d16_29a0;
  uVar1 = TimerValues;
  uVar6 = (undefined2)((ulong)__AV_Anim_Lines >> 0x10);
  iVar2 = (int)__AV_Anim_Lines + iVar4 * 0x18;
  *(undefined2 *)(iVar2 + 10) = DAT_2d16_29a0;
  *(undefined2 *)(iVar2 + 8) = uVar1;
  uVar6 = (undefined2)((ulong)__AV_Anim_Lines >> 0x10);
  iVar4 = (int)__AV_Anim_Lines + iVar4 * 0x18;
  *(undefined2 *)(iVar4 + 6) = uVar5;
  *(undefined2 *)(iVar4 + 4) = uVar1;
  return 1;
}


//// Default_Stop_Timeline @ 1543:1089

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far Default_Stop_Timeline(int *param_1)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  iVar3 = *param_1;
  uVar4 = (undefined2)((ulong)__AV_Anim_Lines >> 0x10);
  puVar1 = (undefined2 *)((int)__AV_Anim_Lines + iVar3 * 0x18);
  puVar1[1] = 0;
  *puVar1 = 0;
  uVar4 = (undefined2)((ulong)__AV_Anim_Lines >> 0x10);
  iVar2 = (int)__AV_Anim_Lines + iVar3 * 0x18;
  *(undefined2 *)(iVar2 + 10) = 0;
  *(undefined2 *)(iVar2 + 8) = 0;
  uVar4 = (undefined2)((ulong)__AV_Anim_Lines >> 0x10);
  iVar3 = (int)__AV_Anim_Lines + iVar3 * 0x18;
  *(undefined2 *)(iVar3 + 6) = 0;
  *(undefined2 *)(iVar3 + 4) = 0;
  return 1;
}


//// _Load_AV_File @ 1651:0003

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * __cdecl16far
_Load_AV_File(undefined2 param_1,undefined2 param_2,undefined2 *param_3,uint param_4,int param_5)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined2 *puVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined2 uVar9;
  undefined2 uStack_a;
  
  iVar1 = _Find_File(param_1,param_2);
  if (iVar1 != 0) {
    uVar2 = _Open_Iff_File(param_1,param_2);
    _Seek_File(uVar2,0,0,0);
    uVar5 = 0x4f46;
    uVar3 = _Get_Iff_Chunk_Size(uVar2,0x4f46,0x4d52);
    if (uVar3 < 0x14) {
      return (undefined2 *)0x0;
    }
    if (((undefined2 *)param_3 == (undefined2 *)0x0 && param_3._2_2_ == 0) ||
       ((uVar5 = 0, param_5 == 0 && (param_4 < uVar3 + 0x168)))) {
      puVar4 = (undefined2 *)_Alloc(uVar3 + 0x168,0,0x30);
      param_3 = (undefined2 *)CONCAT22(uVar5,puVar4);
      *param_3 = 0xbabe;
    }
    else {
      *param_3 = 0;
    }
    iVar1 = _Get_Iff_Chunk_Size(uVar2,0x5641,0x4c54);
    uStack_a = (undefined2)((ulong)param_3 >> 0x10);
    ((undefined2 *)param_3)[1] = 0xffff;
    ((undefined2 *)param_3)[2] = 0;
    ((undefined2 *)param_3)[3] = 0xe;
    ((undefined2 *)param_3)[4] = ((undefined2 *)param_3)[3] + 0xf0;
    ((undefined2 *)param_3)[5] = ((undefined2 *)param_3)[4] + 0x78;
    ((undefined2 *)param_3)[6] = ((undefined2 *)param_3)[5] + iVar1;
    __AV_Buffer = CONCAT22(uStack_a,(int)(undefined2 *)param_3 + ((undefined2 *)param_3)[5]);
    _AV_Strings = (int)(undefined2 *)param_3 + ((undefined2 *)param_3)[6];
    DAT_2d16_3a02 = uStack_a;
    _Read_Iff_Chunk(uVar2,0x5641,0x4c54,(int)(undefined2 *)param_3 + ((undefined2 *)param_3)[5],
                    uStack_a,iVar1,0);
    __AV_Anim_Lines = CONCAT22(uStack_a,(int)(undefined2 *)param_3 + ((undefined2 *)param_3)[3]);
    for (iVar1 = 0; iVar1 < 10; iVar1 = iVar1 + 1) {
      uVar5 = (undefined2)((ulong)__AV_Anim_Lines >> 0x10);
      puVar4 = (undefined2 *)((int)__AV_Anim_Lines + iVar1 * 0x18);
      puVar4[1] = 0;
      *puVar4 = 0;
      uVar5 = (undefined2)((ulong)__AV_Buffer >> 0x10);
      iVar6 = (int)__AV_Buffer;
      iVar7 = *(int *)(iVar6 + iVar1 * 2);
      uVar9 = (undefined2)((ulong)__AV_Anim_Lines >> 0x10);
      iVar8 = (int)__AV_Anim_Lines + iVar1 * 0x18;
      *(undefined2 *)(iVar8 + 0x16) = uVar5;
      *(int *)(iVar8 + 0x14) = iVar6 + iVar7 * 2;
      uVar5 = (undefined2)((ulong)__AV_Anim_Lines >> 0x10);
      iVar7 = (int)__AV_Anim_Lines + iVar1 * 0x18;
      *(undefined2 *)(iVar7 + 10) = 0;
      *(undefined2 *)(iVar7 + 8) = 0;
      uVar5 = (undefined2)((ulong)__AV_Anim_Lines >> 0x10);
      iVar7 = (int)__AV_Anim_Lines + iVar1 * 0x18;
      *(undefined2 *)(iVar7 + 6) = 0;
      *(undefined2 *)(iVar7 + 4) = 0;
    }
    iVar1 = _Get_Iff_Chunk_Size(uVar2,0x4554,0x5458);
    if (iVar1 != 0) {
      _Read_Iff_Chunk(uVar2,0x4554,0x5458,_AV_Strings,DAT_2d16_3a02,iVar1,0);
    }
    _Close_Iff_File(uVar2);
  }
  return (undefined2 *)param_3;
}


//// _Free_AV @ 1651:025e

void __cdecl16far _Free_AV(int *param_1)

{
  if (*param_1 == -0x4542) {
    _Free((int *)param_1,param_1._2_2_);
  }
  return;
}


//// Set_Next_Event @ 1651:027a

void __cdecl16far Set_Next_Event(int *param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (((int *)param_1 != (int *)0x0 || param_1._2_2_ != 0) &&
     (*param_1 != 0 || ((int *)param_1)[1] != 0)) {
    *param_1 = *param_1 + **(int **)param_1 * 2;
    iVar3 = ((int *)param_1)[4];
    ((int *)param_1)[3] = ((int *)param_1)[5];
    ((int *)param_1)[2] = iVar3;
    uVar4 = *(uint *)((int)*(undefined4 *)param_1 + 2);
    puVar1 = (uint *)((int *)param_1 + 4);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + uVar4;
    ((int *)param_1)[5] = ((int *)param_1)[5] + ((int)uVar4 >> 0xf) + (uint)CARRY2(uVar2,uVar4);
  }
  return;
}


//// _Process_AV @ 1651:02d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far _Process_AV(int param_1,int param_2,int param_3)

{
  undefined2 *puVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  undefined2 uVar9;
  char *pcVar10;
  
  pcVar10 = (char *)s_Unable_to_load_Digitized_Driver__2d16_1627 + 0x2a;
  if (param_1 == 0 && param_2 == 0) {
    _AV_Debug_Print(0x378,0x2d16);
    Clear_KeyBuffer();
    Get_Key();
    _Prog_End();
    _exit(1);
  }
  else {
    _AV_Input_Line = (int *)CONCAT22(param_2,(int *)(param_1 + 2));
    _AV_Input_Flags = param_1 + 4;
    DAT_2d16_39fa = param_2;
    piVar7 = (int *)(param_1 + *(int *)(param_1 + 6));
    __AV_Anim_Lines = (int *)CONCAT22(param_2,piVar7);
    piVar4 = __AV_Anim_Lines;
    _AV_Anims = param_1 + *(int *)(param_1 + 8);
    DAT_2d16_39ea = param_2;
    _AV_Buffer = param_1 + *(int *)(param_1 + 10);
    DAT_2d16_39fe = param_2;
    _AV_Strings = param_1 + *(int *)(param_1 + 0xc);
    DAT_2d16_3a02 = param_2;
    if (*__AV_Anim_Lines == 0 && piVar7[1] == 0) {
      iVar5 = piVar7[10];
      piVar7[1] = piVar7[0xb];
      *piVar4 = iVar5;
      uVar3 = DAT_2d16_29a0;
      uVar2 = TimerValues;
      uVar9 = (undefined2)((ulong)__AV_Anim_Lines >> 0x10);
      piVar7 = (int *)__AV_Anim_Lines;
      piVar7[5] = DAT_2d16_29a0;
      piVar7[4] = uVar2;
      uVar9 = (undefined2)((ulong)__AV_Anim_Lines >> 0x10);
      piVar7 = (int *)__AV_Anim_Lines;
      piVar7[3] = uVar3;
      piVar7[2] = uVar2;
    }
    do {
      for (_Current_AV_Line = 0; _Current_AV_Line < 10; _Current_AV_Line = _Current_AV_Line + 1) {
        piVar7 = _AV_Anim_Lines + _Current_AV_Line * 0xc;
        uVar9 = (undefined2)((ulong)__AV_Anim_Lines >> 0x10);
        if (*_AV_Input_Line != -1) {
          (*pcRam0002d264)(pcVar10,_AV_Input_Flags,DAT_2d16_39fa);
        }
        while (*(int *)CONCAT22(uVar9,piVar7) != 0 || piVar7[1] != 0) {
          if ((DAT_2d16_29a0 < (uint)piVar7[5]) ||
             ((piVar7[5] == DAT_2d16_29a0 && (TimerValues < (uint)piVar7[4])))) break;
          iVar5 = *(int *)CONCAT22(uVar9,piVar7);
          puVar1 = (undefined2 *)(*(char *)(iVar5 + 4) * 4 + 0x94);
          iVar5 = (*(code *)*puVar1)(pcVar10,iVar5 + 6,piVar7[1]);
          iVar6 = 4;
          piVar8 = (int *)&DAT_2d16_04fa;
          do {
            if (*piVar8 == iVar5) {
                    /* WARNING: Could not recover jumptable at 0x0001696f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              (*(code *)piVar8[4])();
              return;
            }
            piVar8 = piVar8 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
          Set_Next_Event(piVar7,uVar9);
          pcVar10 = (char *)s_Not_enough_disk_space_to_run_Lan_2d16_1523 + 0x1a;
          _Big_Copy_View(8,4);
        }
      }
    } while (param_3 == 1);
  }
  return;
}


//// _AV_Debug_Print @ 1651:050a

void __cdecl16far _AV_Debug_Print(undefined2 param_1,undefined2 param_2)

{
  _Mono_Text_Print(0x3a0,0x2d16,1,0x18,2);
  _Mono_Text_Print(param_1,param_2,1,0x18,2);
  return;
}


//// _Char_Gen @ 16a5:0002

int __cdecl16far _Char_Gen(void)

{
  bool bVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 in_DX;
  undefined2 uVar4;
  undefined2 uVar5;
  int iVar6;
  
  bVar1 = true;
  uVar2 = _Load_Font(0x728,0x2d16);
  uVar4 = 3000;
  _ShapeBuff._0_2_ = _Alloc(3000,0,0x20);
  _ShapeBuff._2_2_ = uVar4;
  _Set_Shape_Buffer((undefined2)_ShapeBuff,uVar4,3000);
  _Load_Shape_File(0x733,0x2d16,3);
  uVar3 = _Get_Shape(3,0);
  _Load_Uncompress(0x73f,0x2d16,2,2,_Palette,DAT_2d16_3d60);
  _Load_Uncompress(0x748,0x2d16,4,4,_Palette,DAT_2d16_3d60);
  _Set_Score_Vol(200);
  uVar5 = 0;
  _AnimHandle = _Open_Animation(0x755,0x2d16,0,0,0,0,1,0,0);
  DAT_2d16_3a06 = uVar5;
  _Animate_Frame(_AnimHandle,uVar5,0,0x71,0,2,0);
  _Set_Font(uVar2,in_DX);
  _Set_LogicPage(2);
  for (iVar6 = 0; iVar6 < 4; iVar6 = iVar6 + 1) {
    _Lands_Print(*(undefined2 *)(iVar6 * 0xe + 0x3c8),*(undefined2 *)(iVar6 * 0xe + 0x3ca),
                 *(int *)(iVar6 * 0xe + 0x3cc) + 0x10,*(int *)(iVar6 * 0xe + 0x3ce) + 0x24,0xc0,0,
                 0x9c,0x120);
  }
  for (iVar6 = 0; iVar6 < 4; iVar6 = iVar6 + 1) {
    _Lands_Print(0x761,0x2d16,*(int *)(iVar6 * 0xe + 0x3cc) + 0x15,
                 *(int *)(iVar6 * 0xe + 0x3ce) + 0x30,0x98,0,0x9c,0x220,
                 *(undefined2 *)(iVar6 * 0xe + 0x3d0));
    _Lands_Print(0x761,0x2d16,*(int *)(iVar6 * 0xe + 0x3cc) + 0x15,
                 *(int *)(iVar6 * 0xe + 0x3ce) + 0x38,0x98,0,0x9c,0x220,
                 *(undefined2 *)(iVar6 * 0xe + 0x3d2));
    _Lands_Print(0x761,0x2d16,*(int *)(iVar6 * 0xe + 0x3cc) + 0x15,
                 *(int *)(iVar6 * 0xe + 0x3ce) + 0x40,0x98,0,0x9c,0x220,
                 *(undefined2 *)(iVar6 * 0xe + 0x3d4));
  }
  _Extract_String(_RawText,DAT_2d16_082e,0x33);
  _strcpy((char *)&_TextString,(char *)0x2d16);
  _Lands_Print((undefined *)&_TextString,0x2d16,0x24,0xad,0x98,0,0x9c,0x20);
  _Extract_String(_RawText,DAT_2d16_082e,0x35);
  _strcpy((char *)&_TextString,(char *)0x2d16);
  _Lands_Print((undefined *)&_TextString,0x2d16,0x24,0xb5,0x98,0,0x9c,0x20);
  _Extract_String(_RawText,DAT_2d16_082e,0x37);
  _strcpy((char *)&_TextString,(char *)0x2d16);
  _Lands_Print((undefined *)&_TextString,0x2d16,0x24,0xbd,0x98,0,0x9c,0x20);
  _Byte_Blit(0x1000,0,0,0,0,0x28,200,2,0);
  _Set_LogicPage(0);
  _Fade_Palette_To(_Palette,DAT_2d16_3d60,0x1e,0,0);
  _Set_Font(uVar2,in_DX);
  _Set_Mouse_Cursor(0,0,uVar3,uVar4);
  Show_Mouse();
  do {
    if (bVar1) {
      _Animate_King_1();
    }
    if (iRam0002d63a < 0) {
      _Wait_For_Select();
    }
    if (iRam0002d63a == 100) {
      bVar1 = true;
    }
    else {
      _Conditional_Hide_Mouse(0,0,0xe,0x78);
      _Byte_Blit(0x1fea,0,0,0,0,0xe,0x78,4,0);
      Conditional_Show_Mouse();
      iVar6 = _Process_Char(iRam0002d63a);
      if (iVar6 != -1) break;
      bVar1 = false;
    }
    iRam0002d63a = -1;
  } while( true );
  DAT_2d16_29a4 = 0;
  DAT_2d16_29a2 = 0x1a4;
  do {
    iVar6 = Check_Key();
    if (iVar6 != 0) {
      iVar6 = Get_Key();
      if ((iVar6 == 0xc6) || (iVar6 == 199)) {
        DAT_2d16_29a4 = 0;
        DAT_2d16_29a2 = 0;
        goto LAB_16a5_0468;
      }
    }
    if (DAT_2d16_29a2 == 0 && DAT_2d16_29a4 == 0) {
LAB_16a5_0468:
      Clear_KeyBuffer();
      return iRam0002d63a;
    }
  } while( true );
}


//// _Wait_For_Select @ 16a5:0478

void __cdecl16far _Wait_For_Select(void)

{
  iRam0002d63a = -1;
  do {
    if (-1 < iRam0002d63a) {
      return;
    }
    DAT_2d16_29a4 = 0;
    DAT_2d16_29a2 = 900;
    do {
      _Party_Wait_Processing();
      iRam0002d63a = _Get_Char();
      if (DAT_2d16_29a2 == 0 && DAT_2d16_29a4 == 0) break;
    } while (iRam0002d63a < 0);
    if (iRam0002d63a < 0) {
      _Animate_King_2();
    }
  } while( true );
}


//// _Get_Char @ 16a5:04c1

int __cdecl16far _Get_Char(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = Check_Key_Num();
  if ((iVar1 != 0) && ((iVar1 = Get_Key_Num(), iVar1 == 0x41 || (iVar1 == 0x42)))) {
    for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
      iVar2 = _Mouse_In_Region(*(undefined2 *)(iVar1 * 0xe + 0x3cc),
                               *(undefined2 *)(iVar1 * 0xe + 0x3ce),
                               *(int *)(iVar1 * 0xe + 0x3cc) + 0x1f,
                               *(int *)(iVar1 * 0xe + 0x3ce) + 0x1f);
      if (iVar2 != 0) {
        return iVar1;
      }
    }
  }
  return -1;
}


//// _Animate_Character @ 16a5:053f

void __cdecl16far _Animate_Character(undefined2 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int in_DX;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  
  uVar7 = (undefined2)((ulong)param_2 >> 0x10);
  iVar5 = (int)param_2;
  *(undefined1 *)(iVar5 + 4) = 0x30;
  cVar1 = '\0';
  do {
    if ((-1 < _Confirmed) || (iVar2 = _Load_Quick_Sample(iVar5,uVar7), iVar2 == 0 && in_DX == 0)) {
      uVar7 = (undefined2)((ulong)_ShapeBuff >> 0x10);
      _Conditional_Hide_Mouse
                (0xb,0x82,*(int *)((int)_ShapeBuff + 3) + 0xb,*(byte *)((int)_ShapeBuff + 2) + 0x82)
      ;
      uVar7 = _Get_Buff(9,uRam0002d5e4);
      uVar7 = _Extract_Shape(uVar7,in_DX);
      _ShapeBuff = CONCAT22(in_DX,uVar7);
      _Draw_Shape(0,uVar7,in_DX,0xb,0x82,0,0);
      Conditional_Show_Mouse();
      return;
    }
    iVar4 = in_DX;
    if (iVar2 != 0 || in_DX != 0) {
      _Play_Long_Sample_Vol(iVar2,in_DX,0xff,0xd0);
    }
    iVar6 = 0;
    while ((iVar3 = _Long_Sample_Status(), iVar3 != 0 && (_Confirmed < 0))) {
      uVar8 = (undefined2)((ulong)_ShapeBuff >> 0x10);
      _Conditional_Hide_Mouse
                (0xb,0x82,*(int *)((int)_ShapeBuff + 3) + 0xb,*(byte *)((int)_ShapeBuff + 2) + 0x82)
      ;
      uVar8 = _Get_Buff(9,*(undefined2 *)(iVar6 * 2 + 0x444));
      uVar8 = _Extract_Shape(uVar8,iVar4);
      _ShapeBuff = CONCAT22(iVar4,uVar8);
      _Draw_Shape(0,uVar8,iVar4,0xb,0x82,0,0);
      Conditional_Show_Mouse();
      DAT_2d16_29a4 = 0;
      DAT_2d16_29a2 = 8;
      do {
        if (DAT_2d16_29a2 == 0 && DAT_2d16_29a4 == 0) break;
        _Confirmed = _Quick_Confirm();
      } while (_Confirmed < 0);
      iVar4 = (iVar6 + 1) % 0x20;
      iVar6 = iVar4;
    }
    _Stop_Long_Sample();
    if (iVar2 != 0 || in_DX != 0) {
      _Free(iVar2,in_DX);
    }
    *(char *)(iVar5 + 4) = cVar1 + '1';
    in_DX = iVar4;
    cVar1 = cVar1 + '\x01';
  } while( true );
}


//// _Process_Char @ 16a5:06fc

/* WARNING: Instruction at (ram,0x00017c0f) overlaps instruction at (ram,0x00017c0e)
    */

undefined1 * __cdecl16far
_Process_Char(undefined1 *param_1,uint param_2,undefined4 param_3,uint param_4)

{
  char cVar1;
  int in_AX;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  int in_DX;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined2 uVar6;
  undefined2 uVar7;
  char *pcVar8;
  bool bVar9;
  int in_stack_00000002;
  undefined1 auStackY_2e [20];
  uint uStackY_1a;
  uint uStackY_18;
  undefined *puStackY_16;
  char *pcStackY_14;
  uint uStackY_12;
  char *pcStackY_10;
  undefined4 in_stack_0000fff2;
  
  if ((undefined1 *)0x3 < param_1) {
    pcStackY_10 = (char *)0x71e6;
    _Load_Shape_File();
    Hide_Mouse();
    pcStackY_10 = "";
    uStackY_12 = 0;
    pcStackY_14 = "";
    puStackY_16 = (undefined *)0x0;
    uStackY_18 = 0x1fea;
    uStackY_1a = 0x7210;
    _Byte_Blit();
    pcStackY_10 = (char *)0x7f;
    uStackY_12 = 8;
    pcStackY_14 = (char *)(*(int *)((int)param_1 * 0xe + 0x3ce) + -3);
    puStackY_16 = (undefined *)(*(int *)((int)param_1 * 0xe + 0x3cc) + -3);
    uStackY_18 = 0x1ef7;
    uStackY_1a = 0x7251;
    _Bit_Blit();
    pcStackY_10 = (char *)0x726a;
    _Extract_String();
    pcStackY_10 = (char *)s_Too_many_files_open__2d16_232a + 0xf;
    uStackY_12 = 0x7279;
    _strcpy((char *)&_TextString,(char *)0x2d16);
    pcStackY_10 = (char *)0x7f;
    uStackY_12 = 0x32;
    pcStackY_14 = (char *)0x2d16;
    puStackY_16 = (undefined *)&_TextString;
    uStackY_18 = 0x1000;
    uStackY_1a = 0x729d;
    _Lands_Print();
    pcStackY_10 = (char *)0x72b1;
    _Extract_String();
    pcStackY_10 = (char *)s_Too_many_files_open__2d16_232a + 0xf;
    uStackY_12 = 0x72c0;
    _strcpy((char *)&_TextString,(char *)0x2d16);
    pcStackY_10 = "";
    uStackY_12 = 0x32;
    pcStackY_14 = (char *)0x2d16;
    puStackY_16 = (undefined *)&_TextString;
    uStackY_18 = 0x1000;
    uStackY_1a = 0x72e4;
    _Lands_Print();
    pcStackY_10 = (char *)0x72fa;
    _Extract_String();
    pcStackY_10 = (char *)s_Too_many_files_open__2d16_232a + 0xf;
    uStackY_12 = 0x7309;
    _strcpy((char *)&_TextString,(char *)0x2d16);
    pcStackY_10 = "";
    uStackY_12 = 0x32;
    pcStackY_14 = (char *)0x2d16;
    puStackY_16 = (undefined *)&_TextString;
    uStackY_18 = 0x1000;
    uStackY_1a = 0x732d;
    _Lands_Print();
    pcStackY_10 = (char *)0x7343;
    _Extract_String();
    pcStackY_10 = (char *)s_Too_many_files_open__2d16_232a + 0xf;
    uStackY_12 = 0x7352;
    _strcpy((char *)&_TextString,(char *)0x2d16);
    pcStackY_10 = (char *)0x9d;
    uStackY_12 = 0x32;
    pcStackY_14 = (char *)0x2d16;
    puStackY_16 = (undefined *)&_TextString;
    uStackY_18 = 0x1000;
    uStackY_1a = 0x7376;
    _Lands_Print();
    pcStackY_10 = (char *)0x738c;
    _Extract_String();
    pcStackY_10 = (char *)s_Too_many_files_open__2d16_232a + 0xf;
    uStackY_12 = 0x739b;
    _strcpy((char *)&_TextString,(char *)0x2d16);
    pcStackY_10 = (char *)0xa7;
    uStackY_12 = 0x32;
    pcStackY_14 = (char *)0x2d16;
    puStackY_16 = (undefined *)&_TextString;
    uStackY_18 = 0x1000;
    uStackY_1a = 0x73bf;
    _Lands_Print();
    pcStackY_10 = (char *)0x73d3;
    _Extract_String();
    pcStackY_10 = (char *)s_Too_many_files_open__2d16_232a + 0xf;
    uStackY_12 = 0x73e2;
    _strcpy((char *)&_TextString,(char *)0x2d16);
    pcStackY_10 = (char *)0xa8;
    uStackY_12 = 100;
    pcStackY_14 = (char *)0x2d16;
    puStackY_16 = (undefined *)&_TextString;
    uStackY_18 = 0x1000;
    uStackY_1a = 0x7406;
    _Lands_Print();
    Show_Mouse();
    pcStackY_10 = (char *)0x741b;
    _Animate_Character();
    if (_Confirmed == -1) {
      iVar2 = _Get_Confirm();
      if (iVar2 == 0) {
        _Confirmed = 0;
      }
      else {
        _Confirmed = 1;
      }
    }
    if (_Confirmed == 1) {
      pcStackY_10 = (char *)0x1fea;
      uStackY_12 = 0x745b;
      _Conditional_Hide_Mouse();
      pcStackY_10 = (char *)0x7f;
      uStackY_12 = 6;
      pcStackY_14 = (char *)0x7f;
      puStackY_16 = (undefined *)0x6;
      uStackY_18 = 0x1fea;
      uStackY_1a = 0x7482;
      _Byte_Blit();
      Conditional_Show_Mouse();
      Hide_Mouse();
      pcStackY_10 = (char *)0xa0;
      uStackY_12 = 6;
      pcStackY_14 = (char *)0x7f;
      puStackY_16 = (undefined *)0x6;
      uStackY_18 = 0x1fea;
      uStackY_1a = 0x74b3;
      _Byte_Blit();
      pcStackY_10 = (char *)0x0;
      uStackY_12 = 0;
      pcStackY_14 = (char *)0x0;
      puStackY_16 = (undefined *)0x0;
      uStackY_18 = 0x1ef7;
      uStackY_1a = 0x74d6;
      _Byte_Blit();
      pcStackY_10 = (char *)0x74ea;
      _Extract_String();
      pcStackY_10 = (char *)s_Too_many_files_open__2d16_232a + 0xf;
      uStackY_12 = 0x74f9;
      _strcpy((char *)&_TextString,(char *)0x2d16);
      pcStackY_10 = "1991 Borland Intl.";
      uStackY_12 = 3;
      pcStackY_14 = (char *)0x2d16;
      puStackY_16 = (undefined *)&_TextString;
      uStackY_18 = 0x1000;
      uStackY_1a = 0x751d;
      _Lands_Print();
      pcStackY_10 = (char *)0x7531;
      _Extract_String();
      pcStackY_10 = (char *)s_Too_many_files_open__2d16_232a + 0xf;
      uStackY_12 = 0x7540;
      _strcpy((char *)&_TextString,(char *)0x2d16);
      pcStackY_10 = "nd Intl.";
      uStackY_12 = 3;
      pcStackY_14 = (char *)0x2d16;
      puStackY_16 = (undefined *)&_TextString;
      uStackY_18 = 0x1000;
      uStackY_1a = 0x7564;
      _Lands_Print();
      pcStackY_10 = (char *)0x757a;
      _Extract_String();
      pcStackY_10 = (char *)s_Too_many_files_open__2d16_232a + 0xf;
      uStackY_12 = 0x7589;
      _strcpy((char *)&_TextString,(char *)0x2d16);
      pcStackY_10 = "ivide error\r\nAbnormal program termination\r\n";
      uStackY_12 = 3;
      pcStackY_14 = (char *)0x2d16;
      puStackY_16 = (undefined *)&_TextString;
      uStackY_18 = 0x1000;
      uStackY_1a = 0x75ad;
      _Lands_Print();
      pcStackY_10 = (char *)0x75c3;
      _Extract_String();
      pcStackY_10 = (char *)s_Too_many_files_open__2d16_232a + 0xf;
      uStackY_12 = 0x75d2;
      _strcpy((char *)&_TextString,(char *)0x2d16);
      pcStackY_10 = "r\r\nAbnormal program termination\r\n";
      uStackY_12 = 3;
      pcStackY_14 = (char *)0x2d16;
      puStackY_16 = (undefined *)&_TextString;
      uStackY_18 = 0x1000;
      uStackY_1a = 0x75f6;
      _Lands_Print();
      pcStackY_10 = (char *)0x760c;
      _Extract_String();
      pcStackY_10 = (char *)s_Too_many_files_open__2d16_232a + 0xf;
      uStackY_12 = 0x761b;
      _strcpy((char *)&_TextString,(char *)0x2d16);
      pcStackY_10 = "l program termination\r\n";
      uStackY_12 = 3;
      pcStackY_14 = (char *)0x2d16;
      puStackY_16 = (undefined *)&_TextString;
      uStackY_18 = 0x1000;
      uStackY_1a = 0x763f;
      _Lands_Print();
      Show_Mouse();
      _Animate_King_3();
    }
    else {
      _Confirmed = -1;
      _Show_Chars();
      Clear_KeyBuffer();
      param_1 = (undefined1 *)0xffff;
    }
    return param_1;
  }
  pcVar8 = (char *)0x1000;
  switch(param_1) {
  case (undefined1 *)0x0:
    uVar6 = *(undefined2 *)((int)param_1 * 2 + 4);
    break;
  case (undefined1 *)0x1:
    if ((in_AX + 0x46U & 3) == 0) {
      param_2 = param_2 + 1;
    }
    if ((undefined1 *)0x3 < param_1) {
      if (param_1 != (undefined1 *)0x4) {
        if ((undefined1 *)0xa < param_1) {
          return (undefined1 *)0x0;
        }
        if (param_1 != (undefined1 *)0xa) {
          return (undefined1 *)0x1;
        }
      }
      if ((in_stack_00000002 < 0x11) || (param_1 != (undefined1 *)0x4)) {
        iVar2 = *(int *)((undefined *)&__monthDay + (int)param_1 * 2);
      }
      else {
        iVar2 = iRam00030562 + 7;
      }
      if ((in_stack_00000002 + 0x7b2U & 3) != 0) {
        iVar2 = iVar2 + -1;
      }
      uVar5 = iVar2 - (in_stack_00000002 * 0x16d + (in_stack_00000002 + 1 >> 2) + iVar2 + 4U) % 7;
      if (param_1 == (undefined1 *)0x4) {
        if ((uVar5 < param_2) || ((param_2 == uVar5 && (1 < (byte)param_3)))) {
          return (undefined1 *)0x1;
        }
      }
      else {
        if (param_2 < uVar5) {
          return (undefined1 *)0x1;
        }
        if ((param_2 == uVar5) && ((byte)param_3 < 2)) {
          return (undefined1 *)0x1;
        }
      }
    }
    return (undefined1 *)0x0;
  case (undefined1 *)0x2:
    bVar9 = false;
    while( true ) {
      param_2 = (param_2 - in_DX) - (uint)bVar9;
      *(char *)((int)param_3 + 3) = *(char *)((int)param_3 + 3) + '\x01';
      unaff_ES = (undefined2)((ulong)param_3 >> 0x10);
      cVar1 = *(char *)(*(char *)((int)param_3 + 3) + 0x33f0);
      uVar5 = (int)cVar1 >> 0xf;
      if (((int)param_2 <= (int)uVar5) &&
         ((uVar5 != param_2 || (param_1 <= (undefined1 *)(int)cVar1)))) break;
      puVar4 = (undefined1 *)(int)*(char *)(*(char *)((int)param_3 + 3) + 0x33f0);
      in_DX = (int)puVar4 >> 0xf;
      bVar9 = param_1 < puVar4;
      param_1 = param_1 + -(int)puVar4;
    }
    *(char *)((int)param_3 + 3) = *(char *)((int)param_3 + 3) + '\x01';
    *(undefined1 *)((int)param_3 + 2) = param_1._0_1_;
    return (undefined1 *)CONCAT11(cVar1 >> 7,param_1._0_1_);
  case (undefined1 *)0x3:
    *(int *)(unaff_SI + 0xb) = *(int *)(unaff_SI + 0xb) - unaff_SI;
    iVar2 = unaff_SI;
    do {
      iRam0002d63a = _Get_Char();
      if (iRam0002d63a < 0) goto LAB_16a5_11b8;
      do {
        iVar2 = (iVar2 + 1) % 0x16;
        iVar3 = _Long_Sample_Status();
        if ((iVar3 == 0) || (-1 < iRam0002d63a)) {
          Hide_Mouse();
          pcStackY_10 = (char *)uRam0002d59e;
          uStackY_12 = DAT_2d16_3a06;
          pcStackY_14 = (char *)_AnimHandle;
          puStackY_16 = (undefined *)0x1fea;
          uStackY_18 = 0x7c5d;
          _Animate_Frame();
          Show_Mouse();
          _Stop_Long_Sample();
          puVar4 = (undefined1 *)0x0;
          if (unaff_DI != 0 || unaff_SI != 0) {
            puVar4 = (undefined1 *)_Free();
          }
          return puVar4;
        }
        if (iVar2 < 4) {
          iVar2 = 4;
        }
        pcStackY_10 = (char *)0x26e6;
        uStackY_12 = 0x7a45;
        _Conditional_Hide_Mouse();
        pcStackY_10 = (char *)*(undefined2 *)(iVar2 * 2 + 0x408);
        uStackY_12 = DAT_2d16_3a06;
        pcStackY_14 = (char *)_AnimHandle;
        puStackY_16 = (undefined *)0x1fea;
        uStackY_18 = 0x7a6a;
        _Animate_Frame();
        Conditional_Show_Mouse();
        pcStackY_10 = (char *)0x1fea;
        uStackY_12 = 0x7a8d;
        _Conditional_Hide_Mouse();
        pcStackY_10 = (char *)DAT_2d16_03ce;
        uStackY_12 = DAT_2d16_03cc;
        pcStackY_14 = (char *)*(undefined2 *)(*(int *)(iVar2 * 2 + 0x51e) * 4 + 0x4e0);
        puStackY_16 = (undefined *)*(undefined2 *)(*(int *)(iVar2 * 2 + 0x51e) * 4 + 0x4de);
        uStackY_18 = 0x1fea;
        uStackY_1a = 0x7acc;
        _Bit_Blit();
        Conditional_Show_Mouse();
        pcStackY_10 = (char *)0x1fea;
        uStackY_12 = 0x7aef;
        _Conditional_Hide_Mouse();
        pcStackY_10 = (char *)DAT_2d16_03dc;
        uStackY_12 = DAT_2d16_03da;
        pcStackY_14 = (char *)*(undefined2 *)(*(int *)(iVar2 * 2 + 0x554) * 4 + 0x4e0);
        puStackY_16 = (undefined *)*(undefined2 *)(*(int *)(iVar2 * 2 + 0x554) * 4 + 0x4de);
        uStackY_18 = 0x1fea;
        uStackY_1a = 0x7b2e;
        _Bit_Blit();
        Conditional_Show_Mouse();
        pcStackY_10 = (char *)0x1fea;
        uStackY_12 = 0x7b51;
        _Conditional_Hide_Mouse();
        pcStackY_10 = (char *)DAT_2d16_03ea;
        uStackY_12 = DAT_2d16_03e8;
        pcStackY_14 = (char *)*(undefined2 *)(*(int *)(iVar2 * 2 + 0x58a) * 4 + 0x4e0);
        puStackY_16 = (undefined *)*(undefined2 *)(*(int *)(iVar2 * 2 + 0x58a) * 4 + 0x4de);
        uStackY_18 = 0x1fea;
        uStackY_1a = 0x7b90;
        _Bit_Blit();
        Conditional_Show_Mouse();
        pcStackY_10 = (char *)0x1fea;
        uStackY_12 = 0x7bb3;
        _Conditional_Hide_Mouse();
        pcStackY_10 = (char *)uRam0002d558;
        uStackY_12 = uRam0002d556;
        pcStackY_14 = (char *)*(undefined2 *)(*(int *)(iVar2 * 2 + 0x5c0) * 4 + 0x4e0);
        puStackY_16 = (undefined *)*(undefined2 *)(*(int *)(iVar2 * 2 + 0x5c0) * 4 + 0x4de);
        uStackY_18 = 0x1fea;
        uStackY_1a = 0x7bf2;
        _Bit_Blit();
        Conditional_Show_Mouse();
        DAT_2d16_29a4 = 0;
        DAT_2d16_29a2 = 7;
LAB_16a5_11b8:
      } while (DAT_2d16_29a2 == 0 && DAT_2d16_29a4 == 0);
    } while( true );
  }
  do {
    uVar7 = (undefined2)((ulong)in_stack_0000fff2 >> 0x10);
    *(int *)((int)in_stack_0000fff2 + 6) = in_DX;
    *(undefined2 *)((int)in_stack_0000fff2 + 4) = uVar6;
    do {
      bVar9 = CARRY2(param_2,uStackY_1a);
      param_2 = param_2 + uStackY_1a;
      iVar2 = (int)param_3 + uStackY_18 + (uint)bVar9;
      if (param_3._2_2_ == 0 && param_4 == 0) {
LAB_1c56_0ec8:
        _Free();
        pcStackY_10 = (char *)0xd778;
        _Set_FileData();
        _CallingDOSInt = _CallingDOSInt + -1;
        return auStackY_2e;
      }
      uStackY_1a = uStackY_12;
      uStackY_18 = (uint)pcStackY_10;
      if ((param_4 <= pcStackY_10) && ((param_4 < pcStackY_10 || (param_3._2_2_ < uStackY_12)))) {
        uStackY_1a = param_3._2_2_;
        uStackY_18 = param_4;
      }
      puStackY_16 = (undefined *)0xd55a;
      pcStackY_14 = pcVar8;
      uStackY_12 = param_2;
      pcStackY_10 = (char *)iVar2;
      _Mem_Copy();
      in_stack_0000fff2 = CONCAT22(puStackY_16,unaff_SI);
      pcStackY_10 = "t enabled.\r\n";
      pcVar8 = (char *)s_You_are_exiting_with_open_files__2d16_2433 + 0xd;
      uStackY_12 = 0xd56e;
      uStackY_1a = _ibm_write();
      uStackY_18 = 0;
      bVar9 = param_3._2_2_ < uStackY_1a;
      param_3 = CONCAT22(param_3._2_2_ - uStackY_1a,iVar2);
      param_4 = param_4 - bVar9;
      uVar5 = *(uint *)((int)param_1 * 0x14 + 4);
      *(int *)((int)param_1 * 0x14 + 6) =
           *(int *)((int)param_1 * 0x14 + 6) + (uint)CARRY2(uVar5,uStackY_1a);
      *(int *)((int)param_1 * 0x14 + 4) = uVar5 + uStackY_1a;
      if (uStackY_1a == 0) goto LAB_1c56_0ec8;
    } while (unaff_DI == -1);
    iVar2 = *(int *)((int)param_1 * 0x14 + 6);
    uVar6 = (undefined2)((ulong)in_stack_0000fff2 >> 0x10);
    iVar3 = (int)in_stack_0000fff2;
    if ((*(int *)(iVar3 + 6) < iVar2) ||
       ((*(int *)(iVar3 + 6) <= iVar2 &&
        (*(uint *)(iVar3 + 4) <= *(uint *)((int)param_1 * 0x14 + 4))))) {
      in_DX = *(int *)((int)param_1 * 0x14 + 6);
      uVar6 = *(undefined2 *)((int)param_1 * 0x14 + 4);
    }
    else {
      in_DX = *(int *)(iVar3 + 6);
      uVar6 = *(undefined2 *)(iVar3 + 4);
    }
  } while( true );
}


//// _Restore_Char @ 16a5:0c21

void __cdecl16far _Restore_Char(int param_1)

{
  Hide_Mouse();
  _Bit_Blit(0x1fea,0,0xa0,*(int *)(param_1 * 0xe + 0x3cc) + -3,*(int *)(param_1 * 0xe + 0x3ce) + -3,
            0x26,0x27,2,0);
  _Change_Window(2);
  _New_Window();
  Show_Mouse();
  return;
}


//// _Show_Chars @ 16a5:0c84

void __cdecl16far _Show_Chars(void)

{
  Hide_Mouse();
  _Byte_Blit(0x1fea,0,0x7a,0,0x7a,0x28,0x4e,2,0);
  Show_Mouse();
  return;
}


//// _Get_Confirm @ 16a5:0cb8

undefined2 __cdecl16far _Get_Confirm(void)

{
  int iVar1;
  
  Clear_KeyBuffer();
  do {
    iVar1 = Get_Key();
    if ((iVar1 == 0xc6) || (iVar1 == 199)) {
      iVar1 = _Mouse_In_Region(0x58,0xb4,0x80,0xc2);
      if (iVar1 != 0) {
        return 1;
      }
      iVar1 = _Mouse_In_Region(0xc4,0xb4,0xec,0xc2);
      if (iVar1 != 0) {
        return 0;
      }
    }
    Clear_KeyBuffer();
  } while( true );
}


//// _Lands_Print @ 16a5:0d21

void __cdecl16far _Lands_Print(__gnuc_va_list param_1,int param_2)

{
  char *unaff_SS;
  uint in_stack_00000012;
  char local_196 [400];
  undefined1 *local_6;
  
  if (param_1 != (__gnuc_va_list)0x0 || param_2 != 0) {
    local_6 = &stack0x0014;
    _vsprintf(local_196,unaff_SS,param_1);
    if ((in_stack_00000012 & 0xf00) == 0x100) {
      _String_Pixel_Width(local_196);
    }
    if ((in_stack_00000012 & 0xf00) == 0x200) {
      _String_Pixel_Width(local_196);
    }
    if ((in_stack_00000012 & 0xf0) == 0x20) {
      _Text_Print(local_196);
      _Text_Print(local_196);
    }
    _Text_Print(local_196);
  }
  return;
}


//// _Animate_King_1 @ 16a5:0ded

void __cdecl16far _Animate_King_1(void)

{
  int iVar1;
  int iVar2;
  int extraout_DX;
  int iVar3;
  int iVar4;
  
  _Conditional_Hide_Mouse(0,0,0x70,0x78);
  _Byte_Blit(0x1fea,0,0,0,0,0xe,0x78,4,0);
  iVar3 = extraout_DX;
  _Extract_String(_RawText,DAT_2d16_082e,0x39);
  _strcpy((char *)&_TextString,(char *)0x2d16);
  _Lands_Print((undefined *)&_TextString,0x2d16,8,0x26,0x32,0,0x9c,0x20);
  _Extract_String(_RawText,DAT_2d16_082e,0x3a);
  _strcpy((char *)&_TextString,(char *)0x2d16);
  _Lands_Print((undefined *)&_TextString,0x2d16,8,0x30,0x32,0,0x9c,0x20);
  _Extract_String(_RawText,DAT_2d16_082e,0x3b);
  _strcpy((char *)&_TextString,(char *)0x2d16);
  _Lands_Print((undefined *)&_TextString,0x2d16,8,0x3a,0x32,0,0x9c,0x20);
  _Extract_String(_RawText,DAT_2d16_082e,0x3c);
  _strcpy((char *)&_TextString,(char *)0x2d16);
  _Lands_Print((undefined *)&_TextString,0x2d16,8,0x44,0x32,0,0x9c,0x20);
  _Extract_String(_RawText,DAT_2d16_082e,0x3d);
  _strcpy((char *)&_TextString,(char *)0x2d16);
  _Lands_Print((undefined *)&_TextString,0x2d16,8,0x4e,0x32,0,0x9c,0x20);
  Conditional_Show_Mouse();
  iVar1 = _Load_Quick_Sample(0x79a,0x2d16);
  if (iVar1 != 0 || iVar3 != 0) {
    _Play_Long_Sample_Vol(iVar1,iVar3,0xff,0xd0);
  }
  iVar4 = 4;
  do {
    iVar2 = _Long_Sample_Status();
    if ((iVar2 == 0) || (-1 < iRam0002d63a)) {
      Hide_Mouse();
      _Animate_Frame(_AnimHandle,DAT_2d16_3a06,uRam0002d59e,0x71,0,0,0);
      Show_Mouse();
      _Stop_Long_Sample();
      if (iVar1 != 0 || iVar3 != 0) {
        _Free(iVar1,iVar3);
      }
      return;
    }
    if (iVar4 < 4) {
      iVar4 = 4;
    }
    _Conditional_Hide_Mouse(0x71,0,0x122,0x78);
    _Animate_Frame(_AnimHandle,DAT_2d16_3a06,*(undefined2 *)(iVar4 * 2 + 0x408),0x71,0,0,0);
    Conditional_Show_Mouse();
    _Conditional_Hide_Mouse(DAT_2d16_03cc,DAT_2d16_03ce,DAT_2d16_03cc + 0x20,DAT_2d16_03ce + 0x20);
    _Bit_Blit(0x1fea,*(undefined2 *)(*(int *)(iVar4 * 2 + 0x51e) * 4 + 0x4de),
              *(undefined2 *)(*(int *)(iVar4 * 2 + 0x51e) * 4 + 0x4e0),DAT_2d16_03cc,DAT_2d16_03ce,
              0x20,0x20,4,0);
    Conditional_Show_Mouse();
    _Conditional_Hide_Mouse(DAT_2d16_03da,DAT_2d16_03dc,DAT_2d16_03da + 0x20,DAT_2d16_03dc + 0x20);
    _Bit_Blit(0x1fea,*(undefined2 *)(*(int *)(iVar4 * 2 + 0x554) * 4 + 0x4de),
              *(undefined2 *)(*(int *)(iVar4 * 2 + 0x554) * 4 + 0x4e0),DAT_2d16_03da,DAT_2d16_03dc,
              0x20,0x20,4,0);
    Conditional_Show_Mouse();
    _Conditional_Hide_Mouse(DAT_2d16_03e8,DAT_2d16_03ea,DAT_2d16_03e8 + 0x20,DAT_2d16_03ea + 0x20);
    _Bit_Blit(0x1fea,*(undefined2 *)(*(int *)(iVar4 * 2 + 0x58a) * 4 + 0x4de),
              *(undefined2 *)(*(int *)(iVar4 * 2 + 0x58a) * 4 + 0x4e0),DAT_2d16_03e8,DAT_2d16_03ea,
              0x20,0x20,4,0);
    Conditional_Show_Mouse();
    _Conditional_Hide_Mouse(iRam0002d556,iRam0002d558,iRam0002d556 + 0x20,iRam0002d558 + 0x20);
    _Bit_Blit(0x1fea,*(undefined2 *)(*(int *)(iVar4 * 2 + 0x5c0) * 4 + 0x4de),
              *(undefined2 *)(*(int *)(iVar4 * 2 + 0x5c0) * 4 + 0x4e0),iRam0002d556,iRam0002d558,
              0x20,0x20,4,0);
    Conditional_Show_Mouse();
    DAT_2d16_29a4 = 0;
    DAT_2d16_29a2 = 7;
    do {
      if (DAT_2d16_29a2 == 0 && DAT_2d16_29a4 == 0) break;
      iRam0002d63a = _Get_Char();
    } while (iRam0002d63a < 0);
    iVar4 = (iVar4 + 1) % 0x16;
  } while( true );
}


//// _Animate_King_2 @ 16a5:1235

void __cdecl16far _Animate_King_2(void)

{
  int iVar1;
  int iVar2;
  int extraout_DX;
  int iVar3;
  int iVar4;
  
  _Conditional_Hide_Mouse(0,0,0x70,0x78);
  _Byte_Blit(0x1fea,0,0,0,0,0xe,0x78,4,0);
  iVar3 = extraout_DX;
  _Extract_String(_RawText,DAT_2d16_082e,0x3e);
  _strcpy((char *)&_TextString,(char *)0x2d16);
  _Lands_Print((undefined *)&_TextString,0x2d16,8,0x30,0x32,0,0x9c,0x20);
  _Extract_String(_RawText,DAT_2d16_082e,0x3f);
  _strcpy((char *)&_TextString,(char *)0x2d16);
  _Lands_Print((undefined *)&_TextString,0x2d16,8,0x3a,0x32,0,0x9c,0x20);
  Conditional_Show_Mouse();
  iVar1 = _Load_Quick_Sample(0x7a5,0x2d16);
  if (iVar1 != 0 || iVar3 != 0) {
    _Play_Long_Sample_Vol(iVar1,iVar3,0xff,0xd0);
  }
  for (iVar4 = 0; iVar4 < 0xf; iVar4 = iVar4 + 1) {
    iVar2 = _Long_Sample_Status();
    if ((iVar2 == 0) || (-1 < iRam0002d63a)) break;
    _Conditional_Hide_Mouse(0x71,0,0x122,0x78);
    _Animate_Frame(_AnimHandle,DAT_2d16_3a06,*(undefined2 *)(iVar4 * 2 + 0x41a),0x71,0,0,0);
    Conditional_Show_Mouse();
    _Conditional_Hide_Mouse(DAT_2d16_03cc,DAT_2d16_03ce,DAT_2d16_03cc + 0x20,DAT_2d16_03ce + 0x20);
    _Bit_Blit(0x1fea,*(undefined2 *)(*(int *)(iVar4 * 2 + 0x606) * 4 + 0x4de),
              *(undefined2 *)(*(int *)(iVar4 * 2 + 0x606) * 4 + 0x4e0),DAT_2d16_03cc,DAT_2d16_03ce,
              0x20,0x20,4,0);
    Conditional_Show_Mouse();
    _Conditional_Hide_Mouse(DAT_2d16_03da,DAT_2d16_03dc,DAT_2d16_03da + 0x20,DAT_2d16_03dc + 0x20);
    _Bit_Blit(0x1fea,*(undefined2 *)(*(int *)(iVar4 * 2 + 0x628) * 4 + 0x4de),
              *(undefined2 *)(*(int *)(iVar4 * 2 + 0x628) * 4 + 0x4e0),DAT_2d16_03da,DAT_2d16_03dc,
              0x20,0x20,4,0);
    Conditional_Show_Mouse();
    _Conditional_Hide_Mouse(DAT_2d16_03e8,DAT_2d16_03ea,DAT_2d16_03e8 + 0x20,DAT_2d16_03ea + 0x20);
    _Bit_Blit(0x1fea,*(undefined2 *)(*(int *)(iVar4 * 2 + 0x64a) * 4 + 0x4de),
              *(undefined2 *)(*(int *)(iVar4 * 2 + 0x64a) * 4 + 0x4e0),DAT_2d16_03e8,DAT_2d16_03ea,
              0x20,0x20,4,0);
    Conditional_Show_Mouse();
    _Conditional_Hide_Mouse(iRam0002d556,iRam0002d558,iRam0002d556 + 0x20,iRam0002d558 + 0x20);
    _Bit_Blit(0x1fea,*(undefined2 *)(*(int *)(iVar4 * 2 + 0x66c) * 4 + 0x4de),
              *(undefined2 *)(*(int *)(iVar4 * 2 + 0x66c) * 4 + 0x4e0),iRam0002d556,iRam0002d558,
              0x20,0x20,4,0);
    Conditional_Show_Mouse();
    DAT_2d16_29a4 = 0;
    DAT_2d16_29a2 = 8;
    do {
      if (DAT_2d16_29a2 == 0 && DAT_2d16_29a4 == 0) break;
      iRam0002d63a = _Get_Char();
    } while (iRam0002d63a < 0);
  }
  _Stop_Long_Sample();
  if (iVar1 != 0 || iVar3 != 0) {
    _Free(iVar1,iVar3);
  }
  return;
}


//// _Animate_King_3 @ 16a5:156c

void __cdecl16far _Animate_King_3(void)

{
  int iVar1;
  int iVar2;
  int in_DX;
  int iVar3;
  
  Clear_KeyBuffer();
  iVar1 = _Load_Quick_Sample(0x7b0,0x2d16);
  if (iVar1 != 0 || in_DX != 0) {
    _Play_Long_Sample_Vol(iVar1,in_DX,0xff,0xd0);
  }
  iVar3 = 4;
  while( true ) {
    iVar2 = Check_Key();
    if (iVar2 != 0) break;
    iVar2 = _Long_Sample_Status();
    if (iVar2 == 0) break;
    if (iVar3 < 4) {
      iVar3 = 4;
    }
    _Conditional_Hide_Mouse(0x71,0,0x122,0x78);
    _Animate_Frame(_AnimHandle,DAT_2d16_3a06,*(undefined2 *)(iVar3 * 2 + 0x408),0x71,0,0,0);
    Conditional_Show_Mouse();
    DAT_2d16_29a4 = 0;
    DAT_2d16_29a2 = 8;
    do {
      if (DAT_2d16_29a2 == 0 && DAT_2d16_29a4 == 0) break;
      iVar2 = Check_Key();
    } while (iVar2 == 0);
    iVar3 = (iVar3 + 1) % 0x16;
  }
  _Stop_Long_Sample();
  _Conditional_Hide_Mouse(0x71,0,0x122,0x78);
  _Animate_Frame(_AnimHandle,DAT_2d16_3a06,uRam0002d59e,0x71,0,0,0);
  Conditional_Show_Mouse();
  if (iVar1 != 0 || in_DX != 0) {
    _Free(iVar1,in_DX);
  }
  return;
}


//// _Party_Wait_Processing @ 16a5:169c

void __cdecl16far _Party_Wait_Processing(void)

{
  int *piVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  for (iVar5 = 0; iVar5 < 4; iVar5 = iVar5 + 1) {
    uVar3 = *(uint *)(iVar5 * 4 + 0x6f4);
    if ((uVar3 <= DAT_2d16_29a0) &&
       ((uVar3 < DAT_2d16_29a0 || (*(uint *)(iVar5 * 4 + 0x6f2) < TimerValues)))) {
      _Conditional_Hide_Mouse
                (*(undefined2 *)(iVar5 * 0xe + 0x3cc),*(undefined2 *)(iVar5 * 0xe + 0x3ce),
                 *(int *)(iVar5 * 0xe + 0x3cc) + 0x20,*(int *)(iVar5 * 0xe + 0x3ce) + 0x20);
      _Bit_Blit(0x1fea,*(undefined2 *)
                        (*(int *)(iVar5 * 4 + *(int *)(iVar5 * 2 + 0x702) * 2 + 0x5f6) * 4 + 0x4de),
                *(undefined2 *)
                 (*(int *)(iVar5 * 4 + *(int *)(iVar5 * 2 + 0x702) * 2 + 0x5f6) * 4 + 0x4e0),
                *(undefined2 *)(iVar5 * 0xe + 0x3cc),*(undefined2 *)(iVar5 * 0xe + 0x3ce),0x20,0x20,
                4,0);
      Conditional_Show_Mouse();
      if (*(int *)(iVar5 * 2 + 0x702) == 1) {
        bVar2 = Random();
        uVar3 = (bVar2 & 0x1f) + 0x50;
      }
      else {
        bVar2 = Random();
        uVar3 = (bVar2 & 3) + 10;
      }
      iVar4 = TimerValues + uVar3;
      *(int *)(iVar5 * 4 + 0x6f4) = DAT_2d16_29a0 + CARRY2(TimerValues,uVar3);
      *(int *)(iVar5 * 4 + 0x6f2) = iVar4;
      piVar1 = (int *)(iVar5 * 2 + 0x702);
      *piVar1 = *piVar1 + 1;
      if (1 < *(int *)(iVar5 * 2 + 0x702)) {
        *(undefined2 *)(iVar5 * 2 + 0x702) = 0;
      }
    }
  }
  return;
}


//// _Quick_Confirm @ 16a5:17ec

undefined2 __cdecl16far _Quick_Confirm(void)

{
  int iVar1;
  
  iVar1 = _Key_Down(0x41);
  if ((iVar1 != 0) || (iVar1 = _Key_Down(0x42), iVar1 != 0)) {
    iVar1 = _Mouse_In_Region(0x58,0xb4,0x80,0xc2);
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = _Mouse_In_Region(0xc4,0xb4,0xec,0xc2);
    if (iVar1 != 0) {
      return 0;
    }
  }
  return 0xffff;
}


//// _Char_Blink @ 16a5:1855

void __cdecl16far _Char_Blink(undefined2 param_1)

{
  _Char_Eye_Close(param_1);
  _Delay(3);
  _Delay(3);
  _Char_Eye_Open(param_1);
  return;
}


//// _Char_Eye_Open @ 16a5:1881

void __cdecl16far _Char_Eye_Open(int param_1)

{
  Hide_Mouse();
  _Bit_Blit(0x1fea,param_1 * 0x20 + 0x6f,0x20,*(undefined2 *)(param_1 * 0xe + 0x3cc),
            *(undefined2 *)(param_1 * 0xe + 0x3ce),0x20,0x20,4,0);
  Show_Mouse();
  return;
}


//// _Char_Eye_Close @ 16a5:18d4

void __cdecl16far _Char_Eye_Close(int param_1)

{
  Hide_Mouse();
  _Bit_Blit(0x1fea,param_1 * 0x20 + 0x6f,0,*(undefined2 *)(param_1 * 0xe + 0x3cc),
            *(undefined2 *)(param_1 * 0xe + 0x3ce),0x20,0x20,4,0);
  Show_Mouse();
  return;
}


//// _Main_Program @ 1837:0006

/* WARNING: Type propagation algorithm not settling */

void __cdecl16far _Main_Program(undefined2 param_1,undefined4 param_2)

{
  uint uVar1;
  size_t *psVar2;
  undefined2 uVar3;
  int iVar4;
  char *pcVar5;
  undefined2 uVar6;
  int iVar7;
  undefined2 uVar8;
  char *unaff_SS;
  undefined4 uVar9;
  char local_ac [79];
  char acStack_5d [81];
  char *local_c;
  char *pcVar10;
  char *local_8;
  
  uVar8 = (undefined2)((ulong)param_2 >> 0x10);
  iVar7 = (int)param_2;
  _strcpy((char *)((int)acStack_5d + 1),unaff_SS);
  psVar2 = _strlen((size_t *)((int)acStack_5d + 1),unaff_SS);
  if (*(char *)((int)psVar2 + (int)acStack_5d) != '\\') {
    psVar2 = _strlen((size_t *)((int)acStack_5d + 1),unaff_SS);
    *(undefined1 *)((int)psVar2 + (int)(acStack_5d + 2)) = 0;
    psVar2 = _strlen((size_t *)((int)acStack_5d + 1),unaff_SS);
    *(undefined1 *)((int)psVar2 + (int)acStack_5d + 1U) = 0x5c;
  }
  _Alloc_Sample_Buffers(64000,0,0);
  _Open_Quick_File((char *)s_INTROVOC_PAK_2d16_1174,0x2d16);
  uVar6 = 0x300;
  _BlackPalette = _Alloc(0x300,0,0x10);
  DAT_2d16_083a = uVar6;
  _IntroFont = _Load_Font((char *)s_intro_fnt_2d16_1181,0x2d16);
  DAT_2d16_0832 = DAT_2d16_3dc5;
  _Font6Ptr = _SystemFontPtr;
  uVar3 = _SystemFontPtr;
  DAT_2d16_0f9e = uVar6;
  _Font8Ptr = _Load_Font(0x118b,0x2d16);
  DAT_2d16_0836 = uVar3;
  _Set_Font(_Font8Ptr,uVar3);
  MT32_Init(0);
  Clear_KeyBuffer();
  _BumpRate = 0;
  _Set_Palette(_BlackPalette,DAT_2d16_083a);
  Clear_Page(0);
  Clear_Page(4);
  _RawText = _Load_Alloc_Data((char *)s_LOLINTRO_DIP_2d16_1195,0x2d16,0);
  DAT_2d16_082e = uVar3;
  uVar3 = _Size_Of_Region(0x140,0x28,0x20);
  uVar6 = 0;
  _TextBuffer = _Alloc(uVar3,0);
  DAT_2d16_0faa = uVar6;
  _Set_Font(_IntroFont,DAT_2d16_0f9e);
  _Set_Font_Palette(0x80c,0x2d16);
  _Set_Palette(_BlackPalette,DAT_2d16_083a);
  iVar4 = _stricmp(*(undefined2 *)(iVar7 + 8),*(undefined2 *)(iVar7 + 10),
                   (char *)s_HISTORY_2d16_11a2,0x2d16);
  if (iVar4 == 0) {
    _Patrick_Stewart(0,0);
  }
  else {
    iVar4 = _stricmp(*(undefined2 *)(iVar7 + 8),*(undefined2 *)(iVar7 + 10),
                     (char *)s_CHARGEN_2d16_11aa,0x2d16);
    if (iVar4 != 0) {
      _AVEnd = 0;
      iVar4 = 0;
      _AV = _Load_AV_File((char *)s_LOLINTRO_TIM_2d16_11b2,0x2d16,0,0,0,0);
      DAT_2d16_0fae = iVar4;
      while ((iVar4 = Check_Key(), iVar4 == 0 && (_AVEnd == 0))) {
        _Long_Sample_Status();
        if (_AV != 0 || DAT_2d16_0fae != 0) {
          _Process_AV(_AV,DAT_2d16_0fae,0);
        }
        if (((_BumpRate != 0) && (DAT_2d16_1142 <= DAT_2d16_29a0)) &&
           ((DAT_2d16_29a0 != DAT_2d16_1142 || (_fadetimer <= TimerValues)))) {
          uVar1 = _BumpAccum + _BumpTick;
          _fadetimer = TimerValues + ((int)uVar1 >> 8);
          DAT_2d16_1142 =
               DAT_2d16_29a0 + ((int)uVar1 >> 0xf) + (uint)CARRY2(TimerValues,(int)uVar1 >> 8);
          _BumpAccum = uVar1 & 0xff;
          iVar4 = _Bump_Palette(_Palette,DAT_2d16_3d60,_BumpRate);
          if (iVar4 == 0) {
            _BumpRate = 0;
          }
        }
      }
      if (_AV != 0 || DAT_2d16_0fae != 0) {
        _Free_AV(_AV,DAT_2d16_0fae);
        DAT_2d16_0fae = 0;
        _AV = 0;
      }
      _Fade_Palette_To(_BlackPalette,DAT_2d16_083a,0x1e,0,0);
      _Fade_Score();
      _Stop_Sample();
    }
  }
  iVar4 = _stricmp(*(undefined2 *)(iVar7 + 8),*(undefined2 *)(iVar7 + 10),(char *)s_INTRO_2d16_11bf,
                   0x2d16);
  if ((iVar4 == 0) ||
     (iVar7 = _stricmp(*(undefined2 *)(iVar7 + 8),*(undefined2 *)(iVar7 + 10),
                       (char *)s_HISTORY_2d16_11a2,0x2d16), iVar7 == 0)) {
    local_c = (char *)s_PLAIN_2d16_11d1;
    pcVar10 = (char *)0x2d16;
  }
  else {
    _Load_Score_File((char *)s_LOREINTR_2d16_11c5,0x2d16,0,0,0,0);
    _Play_Score(6);
    uVar8 = _Char_Gen();
    _Play_Score(1);
    _Load_Score_File(0,0,0,0,0,0);
    _Fade_Palette_To(_BlackPalette,DAT_2d16_083a,0x3c,0,0);
    _sprintf(local_ac,unaff_SS,0x11ce,0x2d16,uVar8);
    local_c = local_ac;
    pcVar10 = unaff_SS;
  }
  uVar9 = Operating_System(0x1000);
  iVar7 = (int)((ulong)uVar9 >> 0x10);
  if ((int)uVar9 == 3) {
    local_8 = (char *)s_MAINW_EXE_2d16_11d7;
  }
  else {
    local_8 = (char *)s_MAIN_EXE_2d16_11e1;
  }
  _Prog_End();
  _Cursor_Off();
  psVar2 = _strlen((size_t *)((int)acStack_5d + 1),unaff_SS);
  if (((size_t *)0x3 < psVar2) &&
     (pcVar5 = _strrchr((char *)((int)acStack_5d + 1),(int)unaff_SS),
     pcVar5 != (char *)0x0 || iVar7 != 0)) {
    pcVar5 = _strrchr((char *)((int)acStack_5d + 1),(int)unaff_SS);
    *pcVar5 = '\0';
  }
  iVar7 = _toupper((int)acStack_5d[1]);
  _setdisk(iVar7 + -0x41);
  _errno = 0;
  iVar7 = _chdir((char *)((int)acStack_5d + 1));
  if (iVar7 != 0) {
    _perror((char *)((int)acStack_5d + 1));
  }
  _execl(local_8,(char *)0x2d16,local_8,0x2d16,local_c,pcVar10,0,0);
  _perror(local_8);
  return;
}


//// _LOL_Open_Animation @ 1837:0477

int __cdecl16far
_LOL_Open_Animation(int param_1,undefined2 param_2,undefined2 param_3,int param_4,int param_5,
                   undefined1 param_6,int param_7,uint param_8)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined4 local_e;
  undefined2 local_a;
  undefined2 local_8;
  undefined2 local_6;
  undefined2 local_4;
  
  uVar4 = (undefined2)((ulong)((long)param_1 * 0x8c) >> 0x10);
  iVar1 = (int)((long)param_1 * 0x8c);
  local_e = (int *)CONCAT22(0x2d16,(undefined *)&_Anim + iVar1);
  *(int *)(iVar1 + 0x3474) = param_4;
  *(int *)(iVar1 + 0x3476) = param_5;
  *(undefined1 *)(iVar1 + 0x347e) = param_6;
  *(uint *)(iVar1 + 0x3482) = param_8;
  if ((param_8 & 0x10) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 2;
  }
  uVar2 = uVar2 | 1;
  local_4 = 0;
  local_6 = 0;
  if ((param_7 == 2) || ((param_8 & 0x20) != 0)) {
    local_a = _Get_Page(2);
    local_4 = DAT_2d16_2735;
    local_6 = DAT_2d16_2733;
    uVar2 = 1;
    uVar5 = DAT_2d16_2733;
    local_8 = uVar4;
  }
  else {
    local_8 = 0;
    local_a = 0;
    uVar5 = uVar4;
  }
  _sprintf((char *)&_TextString,(char *)0x2d16,0x11ea,0x2d16,param_2,param_3,0x11f0,0x2d16);
  iVar3 = _Find_File((undefined *)&_TextString,0x2d16);
  if (iVar3 != 0) {
    uVar4 = _Palette;
    uVar6 = DAT_2d16_3d60;
    if (param_1 != 1) {
      uVar5 = 0;
      uVar4 = 0;
      uVar6 = 0;
    }
    iVar3 = _Open_Animation((undefined *)&_TextString,0x2d16,local_a,local_8,local_6,local_4,uVar2,
                            uVar4,uVar6);
    *(undefined2 *)(iVar1 + 0x3472) = uVar5;
    *local_e = iVar3;
  }
  if (*local_e == 0 && *(int *)(iVar1 + 0x3472) == 0) {
    if ((param_8 & 2) != 0) {
      _Fade_Palette_To(_BlackPalette,DAT_2d16_083a,0xf,0,0);
      Clear_Page(8);
      _Big_Copy_View(8,4);
    }
    _sprintf((char *)&_TextString,(char *)0x2d16,0x11f4,0x2d16,param_2,param_3);
    iVar1 = _Find_File((undefined *)&_TextString,0x2d16);
    if (iVar1 != 0) {
      uVar4 = _Palette;
      uVar5 = DAT_2d16_3d60;
      if (_GraphicMode != 3) {
        uVar4 = 0;
        uVar5 = 0;
      }
      _Load_Uncompress((undefined *)&_TextString,0x2d16,3,3,uVar4,uVar5);
      _Byte_Blit(0x29e6,0,0,0,0,0x28,200,2,8);
      _Big_Copy_View(8,4);
    }
    if ((param_8 & 2) != 0) {
      _Fade_Palette_To(_Palette,DAT_2d16_3d60,0x1e,0,0);
    }
  }
  else {
    if (param_4 == -1) {
      param_4 = 0;
      *(undefined2 *)(iVar1 + 0x3474) = 0;
    }
    if (param_5 == -1) {
      param_5 = 0;
      *(undefined2 *)(iVar1 + 0x3476) = 0;
    }
    if ((param_8 & 2) != 0) {
      _Fade_Palette_To(_BlackPalette,DAT_2d16_083a,0xf,0,0);
      Clear_Page(8);
      _Big_Copy_View(8,4);
    }
    if ((param_8 & 4) != 0) {
      _sprintf((char *)&_TextString,(char *)0x2d16,0x11f4,0x2d16,param_2,param_3);
      iVar3 = _Find_File((undefined *)&_TextString,0x2d16);
      if (iVar3 != 0) {
        uVar4 = _Palette;
        uVar5 = DAT_2d16_3d60;
        if (_GraphicMode != 3) {
          uVar4 = 0;
          uVar5 = 0;
        }
        _Load_Uncompress((undefined *)&_TextString,0x2d16,3,3,uVar4,uVar5);
        _Byte_Blit(0x29e6,0,0,0,0,0x28,200,2,8);
        _Big_Copy_View(8,4);
      }
      _Animate_Frame(*local_e,*(undefined2 *)(iVar1 + 0x3472),0,param_4,param_5,8,0);
      _Big_Copy_View(8,4);
    }
    if ((param_8 & 2) != 0) {
      _Fade_Palette_To(_Palette,DAT_2d16_3d60,0x1e,0,0);
    }
  }
  return *local_e;
}


//// _LOL_Close_Animation @ 1837:07c0

bool __cdecl16far _LOL_Close_Animation(int param_1)

{
  bool bVar1;
  byte extraout_AH;
  int iVar2;
  undefined4 local_6;
  
  param_1 = param_1 * 0x8c;
  local_6 = (int *)CONCAT22(0x2d16,(undefined *)&_Anim + param_1);
  for (iVar2 = 0; iVar2 < 0x17; iVar2 = iVar2 + 1) {
    if (*(int *)(iVar2 * 4 + 0xfb0) != 0 || *(int *)(iVar2 * 4 + 0xfb2) != 0) {
      _Free(*(undefined2 *)(iVar2 * 4 + 0xfb0),*(undefined2 *)(iVar2 * 4 + 0xfb2));
      *(undefined2 *)(iVar2 * 4 + 0xfb2) = 0;
      *(undefined2 *)(iVar2 * 4 + 0xfb0) = 0;
    }
  }
  iVar2 = *local_6;
  bVar1 = *(int *)(param_1 + 0x3472) != 0;
  if (iVar2 != 0 || bVar1) {
    _Close_Animation(*local_6,*(undefined2 *)(param_1 + 0x3472));
    _setmem((undefined *)&_Anim + param_1,0x2d16,0x8c,(uint)extraout_AH << 8);
  }
  return iVar2 != 0 || bVar1;
}


//// _Intro_Print @ 1837:0859

void __cdecl16far _Intro_Print(undefined2 param_1,int param_2)

{
  size_t *psVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  int in_DX;
  int iVar5;
  char *unaff_SS;
  char local_24 [17];
  char local_13;
  undefined4 local_12;
  undefined4 local_e;
  undefined4 local_a;
  int local_6;
  int local_4;
  
  psVar1 = (size_t *)_Extract_String(_RawText,DAT_2d16_082e,param_1);
  local_a = (size_t *)CONCAT22(in_DX,psVar1);
  if (_up != 0) {
    _Buffer_To_Page(0,0xa0,0x140,0x28,_TextBuffer,DAT_2d16_0faa,0);
    _up = 0;
  }
  if (voc != 0 || DAT_2d16_114a != 0) {
    _Free(voc,DAT_2d16_114a);
  }
  DAT_2d16_114a = 0;
  voc = 0;
  if ((char)*local_a == '$') {
    pcVar2 = _strchr((char *)local_a + 1,local_a._2_2_);
    if (pcVar2 != (char *)0x0 || in_DX != 0) {
      _memset(local_24,(int)unaff_SS,0x100000);
      _strchr((char *)local_a + 1,local_a._2_2_);
      _memcpy(local_24,unaff_SS,(size_t)CONCAT22(local_a._2_2_,(char *)local_a + 1));
      _strcat(local_24,unaff_SS);
      local_e = (size_t *)CONCAT22(DAT_2d16_29a0,TimerValues);
      iVar5 = TimerValues;
      voc = _Load_Quick_Sample(local_24);
      DAT_2d16_29a0 = local_e._2_2_;
      TimerValues = (int)(size_t *)local_e;
      in_DX = (int)(size_t *)local_e;
      DAT_2d16_114a = iVar5;
    }
  }
  if (((voc == 0 && DAT_2d16_114a == 0) || (_SampleType == 0)) || (param_2 < 0)) {
    if (((char *)local_a != (char *)0x0 || local_a._2_2_ != 0) && ((char)*local_a != '\0')) {
      if ((char)*local_a == '$') {
        pcVar2 = _strchr((char *)local_a + 1,local_a._2_2_);
        local_a = (size_t *)CONCAT22(in_DX,pcVar2 + 1);
      }
      iVar5 = param_2;
      if (param_2 < 0) {
        iVar5 = 1;
      }
      _Raw_Palette_Fade(iVar5,0);
      if (param_2 < 0) {
        _Set_Font(_Font8Ptr,DAT_2d16_0836);
        _Set_Font_Palette(0x81c,0x2d16);
        uRam0002f824 = 0xfffe;
      }
      uRam0002f826 = 0xfffc;
      pcVar2 = _strchr((char *)local_a,local_a._2_2_);
      if (pcVar2 == (char *)0x0 && in_DX == 0) {
        _oldy = (int)cRam0002f829;
      }
      else {
        _oldy = (int)cRam0002f829 << 1;
      }
      local_6 = _oldy;
      _Page_To_Buffer(0,0xa0,0x140,0x28,_TextBuffer,DAT_2d16_0faa,0);
      _up = 1;
      local_13 = '\0';
      iVar5 = 0;
      local_e = local_a;
      pcVar2 = (char *)local_a;
      while ((char)*local_e != '\0') {
        pcVar3 = _strchr((char *)(size_t *)local_e,(int)local_e._2_2_);
        local_12 = (char *)CONCAT22(pcVar2,pcVar3);
        if (pcVar3 != (char *)0x0 || pcVar2 != (char *)0x0) {
          local_13 = *local_12;
          *local_12 = '\0';
        }
        local_4 = _String_Pixel_Width((size_t *)local_e,local_e._2_2_);
        if (param_2 < 0) {
          iVar4 = 0xbc;
        }
        else {
          iVar4 = iVar5 + 0xa0;
        }
        pcVar2 = (char *)(0x140 - local_4 >> 0xf);
        _Text_Print((size_t *)local_e,local_e._2_2_,(0x140 - local_4) / 2,iVar4,0xf0,0);
        iVar5 = iVar5 + cRam0002f829;
        psVar1 = _strlen((size_t *)local_e,local_e._2_2_);
        psVar1 = (size_t *)((int)(size_t *)local_e + (int)psVar1);
        local_e = (size_t *)CONCAT22(local_e._2_2_,psVar1);
        if (local_13 != '\0') {
          *local_12 = local_13;
          local_e = (size_t *)CONCAT22(local_e._2_2_,(size_t *)((int)psVar1 + 1));
        }
      }
      uRam0002f826 = 0;
      if (param_2 < 0) {
        _Set_Font(_IntroFont,DAT_2d16_0f9e);
        _Set_Font_Palette(0x80c,0x2d16);
        uRam0002f824 = 0;
      }
    }
  }
  else if (voc != 0 || DAT_2d16_114a != 0) {
    _Play_Long_Sample_Vol(voc,DAT_2d16_114a,0xff,0xd0);
  }
  return;
}


//// _Custom_Load_Palette @ 1837:0b75

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far _Custom_Load_Palette(int *param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)__AV_Strings >> 0x10);
  _Load_Data((int)__AV_Strings + *(int *)((int)__AV_Strings + *param_1 * 2),uVar1,_Palette,
             DAT_2d16_3d60,0x300,0);
  return 1;
}


//// _Custom_Fade_To_Black @ 1837:0baf

undefined2 __cdecl16far _Custom_Fade_To_Black(undefined2 *param_1)

{
  _memcpy(_Palette,DAT_2d16_3d60,CONCAT22(DAT_2d16_083a,_BlackPalette));
  _Determine_BumpRate(_Palette,DAT_2d16_3d60,*param_1,0xfa2,0x2d16,4000,0x2d16);
  _BumpAccum = 0;
  return 1;
}


//// _Custom_Start_Fade @ 1837:0bfb

undefined2 __cdecl16far _Custom_Start_Fade(undefined2 *param_1)

{
  _Determine_BumpRate(_Palette,DAT_2d16_3d60,*param_1,0xfa2,0x2d16,4000,0x2d16);
  _BumpAccum = 0;
  return 1;
}


//// _Custom_Palette_Fade @ 1837:0c2b

undefined2 __cdecl16far _Custom_Palette_Fade(undefined2 *param_1)

{
  _Raw_Palette_Fade(*param_1,((undefined2 *)param_1)[1]);
  return 1;
}


//// _Custom_Scale_Blit @ 1837:0c49

undefined2 __cdecl16far _Custom_Scale_Blit(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  undefined2 uVar10;
  undefined4 local_14;
  
  iVar5 = *param_1 * 0x8c;
  local_14 = (undefined2 *)CONCAT22(0x2d16,(undefined *)&_Anim + iVar5);
  uVar10 = (undefined2)((ulong)param_1 >> 0x10);
  piVar9 = (int *)param_1;
  iVar1 = piVar9[1];
  iVar2 = piVar9[2];
  iVar3 = piVar9[3];
  iVar6 = piVar9[4];
  if (iVar6 < 1) {
    iVar6 = 0;
  }
  uVar10 = *(undefined2 *)(iVar5 + 0x3474);
  uVar4 = *(undefined2 *)(iVar5 + 0x3476);
  iVar7 = _Get_Animation_Width(*local_14,*(undefined2 *)(iVar5 + 0x3472));
  iVar8 = _Get_Animation_Height(*local_14,*(undefined2 *)(iVar5 + 0x3472));
  _Animate_Frame(*local_14,*(undefined2 *)(iVar5 + 0x3472),iVar1,*(undefined2 *)(iVar5 + 0x3474),
                 *(undefined2 *)(iVar5 + 0x3476),2,*(uint *)(iVar5 + 0x3482) & 0xf0ff);
  _Scale_Bit_Blit(uVar10,uVar4,iVar2,iVar3,iVar7,iVar8,(iVar7 * iVar6) / 100,(iVar8 * iVar6) / 100,2
                  ,8,0,0,0);
  _Big_Copy_View(8,4);
  return 1;
}


//// _Raw_Palette_Fade @ 1837:0d67

void __cdecl16far _Raw_Palette_Fade(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 local_6;
  
  for (iVar5 = 0; uVar3 = DAT_2d16_3d60, iVar5 < 0xf; iVar5 = iVar5 + 1) {
    puVar4 = (undefined1 *)(_Palette + (iVar5 + 0xf0) * 3);
    local_6 = (undefined1 *)CONCAT22(DAT_2d16_3d60,puVar4);
    iVar1 = *(int *)(param_1 * 6 + 0x114e);
    iVar2 = *(int *)(param_1 * 6 + 0x1150);
    *local_6 = (char)(((0xf - iVar5) * 4 * *(int *)((undefined *)&_colors + param_1 * 6)) / 100);
    local_6 = (undefined1 *)CONCAT22(uVar3,puVar4 + 1);
    *local_6 = (char)(((0xf - iVar5) * 4 * iVar1) / 100);
    local_6 = (undefined1 *)CONCAT22(uVar3,puVar4 + 2);
    *local_6 = (char)(((0xf - iVar5) * 4 * iVar2) / 100);
  }
  if ((param_2 == 0) && (_BumpRate == 0)) {
    _Set_Palette(_Palette,DAT_2d16_3d60);
  }
  else {
    _Determine_BumpRate(_Palette,DAT_2d16_3d60,param_2,0xfa2,0x2d16,4000,0x2d16);
    _BumpAccum = 0;
  }
  return;
}


//// _Fancy_Text_Print @ 1837:0e68

void __cdecl16far
_Fancy_Text_Print(__gnuc_va_list param_1,int param_2,int param_3,undefined2 param_4,
                 undefined2 param_5,undefined2 param_6,uint param_7)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  undefined2 local_8;
  
  uVar2 = param_7 & 0xf;
  if (((uVar2 != _point) && (uVar2 != 0)) || (param_1 == (__gnuc_va_list)0x0 && param_2 == 0)) {
    local_8 = _SystemFontPtr;
    uVar1 = _Font6Ptr;
    if ((uVar2 != 1) && (uVar1 = _Font8Ptr, uVar2 != 2)) {
      uVar1 = local_8;
    }
    local_8 = uVar1;
    _Set_Font(local_8);
    _point = uVar2;
  }
  uVar2 = param_7 & 0xf0;
  if (((uVar2 != _shadow) && (uVar2 != 0)) || (param_1 == (__gnuc_va_list)0x0 && param_2 == 0)) {
    _memset((undefined1 *)&fontpalette,0x2d16,0x100000);
    DAT_2d16_3a10 = 0x56;
    iVar3 = 4;
    puVar4 = (uint *)0x1000;
    do {
      if (*puVar4 == uVar2) {
                    /* WARNING: Could not recover jumptable at 0x0001929a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)puVar4[4])();
        return;
      }
      puVar4 = puVar4 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    fontpalette = (undefined1)param_6;
    DAT_2d16_3a0d = (undefined1)param_5;
    _Set_Font_Palette((undefined1 *)&fontpalette,0x2d16);
    _shadow = uVar2;
  }
  if (param_1 == (__gnuc_va_list)0x0 && param_2 == 0) {
    return;
  }
  _vsprintf((char *)&buffer,(char *)0x2d16,param_1);
  if ((param_7 & 0xf00) == 0x100) {
    uVar2 = _String_Pixel_Width((undefined *)&buffer,0x2d16);
    uVar2 = uVar2 >> 1;
  }
  else {
    if ((param_7 & 0xf00) != 0x200) goto LAB_1837_0fe3;
    uVar2 = _String_Pixel_Width((undefined *)&buffer,0x2d16);
  }
  param_3 = param_3 - uVar2;
LAB_1837_0fe3:
  _Text_Print((undefined *)&buffer,0x2d16,param_3,param_4,param_5,param_6);
  return;
}


//// MT32_Init @ 1837:1010

void __cdecl16far MT32_Init(void)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  if ((_ScoreType == 6) || (_SoundType == 6)) {
    _Load_Score_File((char *)s_LOREINTR_2d16_11c5,0x2d16,0,0,0);
    Clear_Page();
    Clear_Page();
    _Load_Data((char *)s_COLPAL_PAL_2d16_1200,0x2d16,_Palette,DAT_2d16_3d60,0x300);
    _Set_Palette(_Palette);
    _Play_Score();
    uVar4 = 0;
    iVar3 = 0;
    pcVar1 = (char *)s_Initializing_sound_card__2d16_120b;
    while( true ) {
      _Text_Print(pcVar1,0x2d16,iVar3,uVar4,0xff);
      iVar2 = _Score_Status();
      if (iVar2 == 0) break;
      _Delay();
      uVar4 = 10;
      iVar3 = iVar3 + 6;
      pcVar1 = (char *)s_Initializing_sound_card__2d16_120b + 0x17;
    }
    _memset(_Palette,DAT_2d16_3d60,0x3000000);
    _Set_Palette(_Palette,DAT_2d16_3d60);
  }
  return;
}


//// _Cursor_Off @ 1837:10f4

void __cdecl16far _Cursor_Off(void)

{
  DAT_2d16_3b0d = 2;
  DAT_2d16_3b12 = 0x1900;
  DAT_2d16_3b0f = 0;
  _int86(0x10,(undefined *)&rg,0x2d16,(undefined *)&rg,0x2d16);
  return;
}


//// _Hilite_Box @ 1948:000f

void __cdecl16far
_Hilite_Box(int param_1,int param_2,int param_3,int param_4,undefined2 param_5,undefined2 param_6,
           int param_7)

{
  param_3 = param_3 + -1;
  param_4 = param_4 + -1;
  if (param_7 != -1) {
    _Fill_Rect(0x1948,param_1 + 1,param_2 + 1,param_1 + param_3 + -1,param_2 + param_4 + -1,param_7)
    ;
  }
  _Draw_Line(param_1 + 1,param_2,param_1 + param_3,param_2,param_6);
  _Draw_Line(param_1 + param_3,param_2,param_1 + param_3,param_2 + param_4 + -1,param_6);
  _Draw_Line(param_1,param_2,param_1,param_2 + param_4,param_5);
  _Draw_Line(param_1,param_2 + param_4,param_1 + param_3,param_2 + param_4,param_5);
  return;
}


//// _Load_Shape_File @ 1948:00b3

void __cdecl16far _Load_Shape_File(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  _Load_Uncompress(param_1,param_2,param_3,param_3,0,0);
  return;
}


//// _Get_Shape @ 1948:00d3

undefined2 __cdecl16far _Get_Shape(undefined2 param_1,undefined2 param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int in_DX;
  int iVar4;
  int iVar5;
  undefined2 local_a;
  
  uVar1 = _Get_Buff(param_1,param_2);
  iVar2 = _Extract_Shape(uVar1,in_DX);
  if (iVar2 == 0 && in_DX == 0) {
    local_a = 0;
  }
  else {
    iVar3 = _Get_Shape_Size(iVar2,in_DX);
    iVar4 = iVar3 >> 0xf;
    iVar5 = iVar4;
    local_a = _Alloc(iVar3,iVar4,0);
    _Mem_Copy(iVar2,in_DX,local_a,iVar5,iVar3,iVar4);
  }
  return local_a;
}


//// _Vertical_Bar_Graph @ 1948:0155

void __cdecl16far
_Vertical_Bar_Graph(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                   undefined2 param_7,undefined2 param_8)

{
  undefined2 uVar1;
  
  uVar1 = 0x1948;
  param_6 = param_6 + -1;
  if (0 < param_4) {
    if (param_3 < 1) {
      param_3 = 0;
    }
    if (param_4 < param_3) {
      param_3 = param_4;
    }
    param_4 = (param_6 * param_3) / param_4;
    if ((param_4 < 1) && (0 < param_3)) {
      param_4 = 1;
    }
    if (0 < param_4) {
      uVar1 = 0x1f90;
      _Fill_Rect(0x1948,param_1,param_2 - param_4,param_1 + param_5 + -1,param_2,param_7);
    }
    if (param_4 < param_6) {
      _Fill_Rect(uVar1,param_1,param_2 - param_6,param_1 + param_5 + -1,param_2 - param_4,param_8);
    }
  }
  return;
}


//// _Center_Text_Print @ 1948:01e8

void __cdecl16far
_Center_Text_Print(undefined2 param_1,undefined2 param_2,int param_3,undefined2 param_4,
                  undefined2 param_5,undefined2 param_6)

{
  uint uVar1;
  
  uVar1 = _String_Pixel_Width(param_1,param_2);
  _Text_Print(param_1,param_2,param_3 - (uVar1 >> 1),param_4,param_5,param_6);
  return;
}


//// _Mouse_Clicked_In_Region @ 1948:021f

undefined2 __cdecl16far
_Mouse_Clicked_In_Region
          (undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  int iVar1;
  
  iVar1 = Get_Key();
  if (((iVar1 == 0xc6) || (iVar1 == 199)) &&
     (iVar1 = _Mouse_In_Region(param_1,param_2,param_3,param_4), iVar1 != 0)) {
    return 1;
  }
  return 0;
}


