//// fn_17d6_0006 @ 27d6:0006

void __cdecl16far fn_17d6_0006(undefined2 param_1)

{
  fn_17d6_0019(param_1,0xff);
  return;
}


//// fn_17d6_0019 @ 27d6:0019

void __cdecl16far fn_17d6_0019(int param_1,uint param_2)

{
  undefined2 uVar1;
  char *pcVar2;
  
  pcVar2 = (char *)s_Cmd_Animate_Wall__Too_many_anim_f_3e2d_27af + 0x27;
  if (((-1 < param_1) && (param_1 < 0xfa)) && ((g_35e2 != 0 || (param_1 < 2)))) {
    if (g_28b8 == -1) {
      fn_178d_01ef((undefined2 *)&g_28b8,0x3e2d,param_1,param_2);
    }
    else {
      if (((undefined2 *)&g_28e2)[g_28e0 * 3] != -1) {
        uVar1 = ((undefined2 *)&g_28e2)[g_28e0 * 3];
        fn_1b79_02e3();
        pcVar2 = (char *)0x2b79;
        fn_1b79_02b1(0x2b79,g_28b8,((undefined2 *)&g_28e2)[g_28e0 * 3],uVar1);
        ((undefined2 *)&g_28e2)[g_28e0 * 3] = 0xffff;
      }
      uVar1 = fn_1b79_02ac(pcVar2,g_28b8,g_28ce,param_1,
                            *(undefined4 *)(g_28e0 * 6 + 0x28e4),0);
      ((undefined2 *)&g_28e2)[g_28e0 * 3] = uVar1;
      fn_1b79_02dd(0x2b79,g_28b8,((undefined2 *)&g_28e2)[g_28e0 * 3]);
      fn_1b79_0301(0x2b79,g_28b8,((undefined2 *)&g_28e2)[g_28e0 * 3],
                    (int)((param_2 & 0xff) * 0x5a) >> 8,0);
      g_28e0 = g_28e0 + 1;
      if (3 < g_28e0) {
        g_28e0 = 0;
      }
    }
  }
  return;
}


//// fn_17d6_0123 @ 27d6:0123

void __cdecl16far fn_17d6_0123(void)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = (char *)s_Cmd_Animate_Wall__Too_many_anim_f_3e2d_27af + 0x27;
  if (g_28b8 == -1) {
    if (g_28c6 != 0) {
      if (g_2928 != -1) {
        fn_1b79_035b((char *)s_Cmd_Animate_Wall__Too_many_anim_f_3e2d_27af + 0x27,g_28fa,
                      g_2928);
        g_2928 = -1;
      }
      fn_178d_01ef((undefined2 *)&g_28b8,0x3e2d,0);
    }
  }
  else {
    iVar1 = 0;
    do {
      if (((undefined2 *)&g_28e2)[iVar1 * 3] != -1) {
        fn_1b79_02e3(pcVar2,g_28b8,((undefined2 *)&g_28e2)[iVar1 * 3]);
        pcVar2 = (char *)0x2b79;
        fn_1b79_02b1(0x2b79);
        ((undefined2 *)&g_28e2)[iVar1 * 3] = 0xffff;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 4);
  }
  return;
}


//// fn_17d6_01b0 @ 27d6:01b0

void __cdecl16far fn_17d6_01b0(void)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  
  if (g_28b8 == -1) {
    if (g_28c6 != 0) {
      if (g_2928 != -1) {
        fn_1b79_035b((char *)s_Cmd_Animate_Wall__Too_many_anim_f_3e2d_27af + 0x27,g_28fa,
                      g_2928);
        g_2928 = -1;
      }
      fn_178d_01ef((undefined2 *)&g_28b8,0x3e2d,1,0);
    }
  }
  else {
    iVar1 = 0;
    pcVar2 = (char *)s_Cmd_Animate_Wall__Too_many_anim_f_3e2d_27af + 0x27;
    do {
      pcVar3 = pcVar2;
      if (((undefined2 *)&g_28e2)[iVar1 * 3] != -1) {
        pcVar3 = (char *)0x2b79;
        fn_1b79_0301(pcVar2,g_28b8,((undefined2 *)&g_28e2)[iVar1 * 3],0,2000);
      }
      iVar1 = iVar1 + 1;
      pcVar2 = pcVar3;
    } while (iVar1 < 4);
  }
  return;
}

