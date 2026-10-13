//// ovr_2d56_0020 @ 5646:0000
// FAILED
//// ovr_2d56_0048 @ 5646:0263

undefined2 __cdecl16far ovr_2d56_0048(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined2 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined2 uVar11;
  undefined2 unaff_DS;
  undefined2 uVar12;
  undefined2 local_a;
  
  uVar12 = 2;
  iVar3 = fn_0000_1e8f();
  uVar11 = (undefined2)((ulong)param_1 >> 0x10);
  iVar9 = (int)param_1;
  iVar10 = *(int *)(iVar9 + 0x1e) + *(int *)(*(int *)(iVar9 + 0x1c) * 0x10 + 0x1f3b) * 8;
  iVar4 = *(int *)(iVar9 + 0x20) + *(int *)(*(int *)(iVar9 + 0x1c) * 0x10 + 0x1f3d);
  iVar1 = *(int *)(iVar9 + 0x22);
  iVar2 = *(int *)(iVar9 + 0x24);
  iVar5 = iVar10 >> 3;
  *(int *)0x1ffb = iVar5;
  *(int *)0x1ffd = iVar4;
  *(int *)0x1fff = iVar1 >> 3;
  *(int *)0x2001 = iVar2;
  uVar6 = *(uint *)(iVar9 + 0x2e) & 5;
  if (uVar6 == 1) {
LAB_5646_02ef:
    uVar7 = 0;
  }
  else {
    if (uVar6 != 4) {
      if (uVar6 != 5) {
        uVar7 = 2;
        local_a = 0xcc;
        goto LAB_5646_02fb;
      }
      goto LAB_5646_02ef;
    }
    uVar7 = 2;
  }
  local_a = 0xfe;
LAB_5646_02fb:
  fn_067a_0185(0x11e8,0xc,uVar7,1,uVar12);
  iVar8 = iVar10 + (iVar1 >> 1);
  uVar11 = ovr_2d56_007f(*(undefined2 *)(iVar9 + 0x38),iVar8,iVar4 + 4,local_a,0x90000);
  uVar12 = 0x1040;
  fn_0000_0bb3(0x1690,uVar11,iVar8);
  if (iVar3 == 0) {
    fn_0000_2191(0x1040,iVar10,iVar4,iVar10 + iVar1,iVar4 + iVar2);
    fn_0000_1917(0x1208,iVar5,iVar4,iVar5,iVar4,iVar1 >> 3,iVar2,2);
    uVar12 = 0x1208;
    fn_0000_226c();
  }
  fn_0000_1e8f(uVar12,iVar3);
  return 1;
}


//// ovr_2d56_004d @ 5646:041a

void __cdecl16far ovr_2d56_004d(void)

{
  undefined2 unaff_DS;
  undefined4 uVar1;
  
  fn_0000_0c22();
  fn_0000_2167();
  uVar1 = fn_0000_3e03(0x1208,7);
  func_0x00013bcb(0x13e0,*(int *)0xad8d << 3,*(undefined2 *)0xad8b,*(int *)0xad8f << 3,
                  *(undefined2 *)0xad91,uVar1);
  func_0x0001217e();
  return;
}


//// ovr_2d56_0052 @ 5646:045e

void __cdecl16far ovr_2d56_0052(void)

{
  undefined2 unaff_DS;
  undefined4 uVar1;
  
  fn_0000_0c22();
  fn_0000_2167();
  uVar1 = fn_0000_3e03(0x1208,7);
  fn_0000_3a80(0x13e0,*(int *)0xad8d << 3,*(undefined2 *)0xad8b,*(int *)0xad8f << 3,
                *(undefined2 *)0xad91,uVar1);
  func_0x0001217e();
  return;
}


//// ovr_2d56_0057 @ 5646:04a2

void __cdecl16far ovr_2d56_0057(undefined2 *param_1)

{
  char cVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  int iVar5;
  int extraout_DX;
  int iVar6;
  int extraout_DX_00;
  undefined2 extraout_DX_01;
  undefined2 extraout_DX_02;
  undefined2 extraout_DX_03;
  undefined2 extraout_DX_04;
  undefined2 extraout_DX_05;
  undefined2 extraout_DX_06;
  undefined2 extraout_DX_07;
  undefined2 extraout_DX_08;
  undefined2 *puVar7;
  undefined2 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined2 uVar11;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_stack_0000ffc6;
  undefined2 in_stack_0000ffc8;
  undefined2 uVar12;
  undefined2 uVar13;
  undefined2 uVar14;
  undefined2 uVar15;
  int local_18 [4];
  int local_10;
  undefined4 local_e;
  undefined4 local_a;
  undefined4 local_6;
  
  *(undefined4 *)0x4b60 = 0;
  uVar15 = 2;
  fn_0000_1e8f();
  fn_0000_0c22(0x11e8,*param_1,uVar15);
  uVar11 = 0x1690;
  fn_067a_0185(0x10b0,*(undefined2 *)0x3715,2,1);
  iVar10 = (int)((ulong)param_1 >> 0x10);
  puVar7 = (undefined2 *)param_1;
  iVar6 = extraout_DX;
  iVar2 = ovr_2d56_007f(puVar7[1]);
  if (iVar2 != 0 || iVar6 != 0) {
    iVar6 = *(int *)0xad8f * 4;
    uVar3 = ovr_2d56_007f(puVar7[1],*(int *)0xad8d * 8 + iVar6,*(int *)0xad8b + 6,0xfe,0,9);
    uVar11 = 0x1040;
    in_stack_0000ffc8 = 0x697e;
    fn_0000_0bb3(0x1690,uVar3,iVar6);
    iVar6 = extraout_DX_00;
  }
  iVar2 = ovr_2d56_007f(*(undefined2 *)((int)puVar7 + 7));
  uVar3 = uVar11;
  if (iVar2 == 0 && iVar6 == 0) {
    iVar6 = *(int *)0xad8f * 4;
    uVar4 = ovr_2d56_007f(0x4009,*(int *)0xad8d * 8 + iVar6,*(int *)0xad8b + 0x2a,0xcc,0,9);
    uVar3 = 0x1040;
    in_stack_0000ffc8 = 0x69c2;
    fn_0000_0bb3(uVar11,uVar4,iVar6);
  }
  for (iVar6 = 0; iVar6 < *(char *)(puVar7 + 3); iVar6 = iVar6 + 1) {
    local_a = (undefined4 *)CONCAT22(0x15f8,(undefined4 *)(iVar6 * 0x3c + 0x592));
    puVar8 = (undefined2 *)((int)puVar7 + iVar6 * 0xe + 7);
    local_6 = (undefined2 *)CONCAT22(iVar10,puVar8);
    iVar2 = iVar10;
    iVar5 = ovr_2d56_007f(*puVar8);
    if (iVar5 != 0 || iVar2 != 0) {
      uVar12 = 0x6a15;
      fn_0000_445b(uVar3,0x10,0x15d0,(undefined4 *)local_a,(int)((ulong)local_a >> 0x10),0x3c,0);
      uVar4 = (undefined2)((ulong)local_a >> 0x10);
      puVar9 = (undefined4 *)local_a;
      *local_a = 0;
      *(int *)(puVar9 + 1) = iVar6 + 1;
      uVar11 = (undefined2)((ulong)local_6 >> 0x10);
      puVar8 = (undefined2 *)local_6;
      *(undefined2 *)((int)puVar9 + 6) = puVar8[6];
      *(undefined2 *)(puVar9 + 2) = 0;
      *(undefined2 *)((int)puVar9 + 0x1e) = puVar8[1];
      *(undefined2 *)(puVar9 + 8) = puVar8[2];
      *(undefined2 *)((int)puVar9 + 0x22) = puVar8[3];
      *(undefined2 *)(puVar9 + 9) = puVar8[4];
      *(undefined1 *)((int)puVar9 + 10) = 4;
      *(undefined1 *)((int)puVar9 + 0xb) = 4;
      *(undefined1 *)(puVar9 + 3) = 4;
      *(undefined1 *)((int)puVar9 + 0xd) = 0;
      *(undefined2 *)((int)puVar9 + 0xe) = 0x4443;
      *(undefined2 *)((int)puVar9 + 0x12) = 0x1730;
      *(undefined2 *)(puVar9 + 4) = 0x48;
      *(undefined2 *)((int)puVar9 + 0x16) = 0x1730;
      *(undefined2 *)(puVar9 + 5) = 0x48;
      *(undefined2 *)((int)puVar9 + 0x1a) = 0x1730;
      *(undefined2 *)(puVar9 + 6) = 0x48;
      *(undefined2 *)(puVar9 + 7) = *param_1;
      *(undefined2 *)((int)puVar9 + 0x2e) = 0;
      *(undefined2 *)(puVar9 + 0xe) = *local_6;
      uVar13 = 0x6ae3;
      uVar11 = extraout_DX_01;
      uVar4 = fn_0000_3b06((int)*(undefined4 *)0x4b60,(int)((ulong)*(undefined4 *)0x4b60 >> 0x10),
                            puVar9,uVar4);
      *(undefined2 *)0x4b62 = uVar11;
      *(undefined2 *)0x4b60 = uVar4;
      func_0x00013ba8(0x13b0,(undefined4 *)local_a,(int)((ulong)local_a >> 0x10));
      puVar9 = (undefined4 *)local_a;
      uVar14 = 0x13b0;
      uVar4 = 0x6b04;
      uVar11 = uVar3;
      func_0x00013c0c(0x13b0,puVar9,(int)((ulong)local_a >> 0x10),0);
      uVar3 = 0x10c8;
      fn_0000_124c(0x13b0,local_a,in_stack_0000ffc6,in_stack_0000ffc8,uVar12,uVar11,uVar13,uVar4,
                    uVar14,puVar9);
      uVar11 = (undefined2)((ulong)local_6 >> 0x10);
      if (((undefined2 *)local_6)[5] != 0) {
        uVar3 = (undefined2)((ulong)local_a >> 0x10);
        puVar9 = (undefined4 *)local_a;
        iVar5 = *(int *)(*(int *)(puVar9 + 7) * 0x10 + 0x1f3b) * 8;
        iVar2 = *(int *)((int)puVar9 + 0x1e) + iVar5 + -1;
        uVar11 = ovr_2d56_007f(((undefined2 *)local_6)[5],iVar2,
                               *(int *)(puVar9 + 8) + *(int *)(*(int *)(puVar9 + 7) * 0x10 + 0x1f3d)
                               + 3,0xcc,0,8);
        iVar5 = func_0x00011d2b(0x10c8,uVar11,iVar5);
        iVar2 = iVar2 - iVar5;
        uVar11 = ovr_2d56_007f(((undefined2 *)local_6)[5],iVar2);
        uVar3 = 0x1040;
        in_stack_0000ffc8 = 0x6b84;
        fn_0000_0bb3(0x11d0,uVar11,iVar2);
      }
    }
  }
  if ((3 < *(int *)0x4b64) && (puVar7[2] == 1)) {
    *(undefined4 *)0x1152 = uRam0001606a;
    *(undefined4 *)0x1156 = uRam00016072;
    *(undefined4 *)0x115a = uRam00016072;
    *(undefined4 *)0x1142 = 0;
    *(undefined2 *)0x115e = *param_1;
    func_0x00013c0c(uVar3,0x1142);
    fn_0000_3b73(0x13b0,0x1142);
    uVar11 = extraout_DX_02;
    fn_4646_038c(0x1142);
    uVar3 = fn_0000_3b06((int)*(undefined4 *)0x4b60,(int)((ulong)*(undefined4 *)0x4b60 >> 0x10),
                          0x1142);
    *(undefined2 *)0x4b62 = uVar11;
    *(undefined2 *)0x4b60 = uVar3;
    *(undefined4 *)0x118e = uRam0001606e;
    *(undefined4 *)0x1192 = uRam00016076;
    *(undefined4 *)0x1196 = uRam00016076;
    *(undefined4 *)0x117e = 0;
    *(undefined2 *)0x119a = *param_1;
    func_0x00013c0c(0x13b0,0x117e);
    fn_0000_3b73(0x13b0,0x117e);
    uVar11 = extraout_DX_03;
    fn_4646_038c(0x117e);
    uVar3 = 0x13b0;
    uVar4 = fn_0000_3b06((int)*(undefined4 *)0x4b60,(int)((ulong)*(undefined4 *)0x4b60 >> 0x10),
                          0x117e);
    *(undefined2 *)0x4b62 = uVar11;
    *(undefined2 *)0x4b60 = uVar4;
  }
  if (puVar7[2] == 2) {
    SCOPY@(0x11be,unaff_DS,local_18,unaff_SS);
    uVar3 = 0x1000;
    SCOPY@(0x11c4,unaff_DS,&stack0xffe2,unaff_SS);
    uVar11 = extraout_DX_04;
    local_10 = iVar6;
    while (*(int *)((int)puVar7 + iVar6 * 0xe + 7) != -1) {
      for (iVar2 = 0; iVar2 < 3; iVar2 = iVar2 + 1) {
        puVar9 = (undefined4 *)(local_10 * 0x3c + 0x592);
        local_a = (undefined4 *)CONCAT22(0x15f8,puVar9);
        local_10 = local_10 + 1;
        local_6 = (undefined2 *)CONCAT22(iVar10,(undefined2 *)((int)puVar7 + iVar6 * 0xe + 7));
        fn_0000_445b(uVar3,0x10,0x15d0,puVar9,0x15f8,0x3c,0);
        uVar11 = (undefined2)((ulong)local_a >> 0x10);
        puVar9 = (undefined4 *)local_a;
        *local_a = 0;
        *(int *)(puVar9 + 1) = local_10;
        *(undefined2 *)((int)puVar9 + 6) = 0;
        *(undefined2 *)(puVar9 + 2) = 0;
        uVar3 = (undefined2)((ulong)local_6 >> 0x10);
        puVar8 = (undefined2 *)local_6;
        *(int *)((int)puVar9 + 0x1e) = puVar8[1] + local_18[iVar2];
        *(undefined2 *)(puVar9 + 8) = puVar8[2];
        *(undefined2 *)((int)puVar9 + 0x22) = *(undefined2 *)(&stack0xffe2 + iVar2 * 2);
        *(undefined2 *)(puVar9 + 9) = puVar8[4];
        *(undefined1 *)((int)puVar9 + 10) = 0;
        *(undefined1 *)((int)puVar9 + 0xb) = 0;
        *(undefined1 *)(puVar9 + 3) = 0;
        *(undefined1 *)((int)puVar9 + 0xd) = 0;
        if (iVar2 == 1) {
          *(undefined2 *)((int)puVar9 + 0xe) = 0x6606;
        }
        else {
          *(undefined2 *)((int)puVar9 + 0xe) = 0x4406;
        }
        puVar9[4] = 0;
        puVar9[5] = 0;
        puVar9[6] = 0;
        *(undefined2 *)(puVar9 + 7) = *param_1;
        *(undefined2 *)((int)puVar9 + 0x2e) = 0;
        *(undefined2 *)((int)puVar9 + 0x32) = 0x1730;
        *(undefined2 *)(puVar9 + 0xc) = 0x61;
        *(undefined2 *)(puVar9 + 0xe) = *(undefined2 *)((int)puVar7 + iVar6 * 0xe + 7);
        *(int *)((int)puVar9 + 0x3a) = iVar2;
        uVar3 = extraout_DX_05;
        uVar11 = fn_0000_3b06((int)*(undefined4 *)0x4b60,
                               (int)((ulong)*(undefined4 *)0x4b60 >> 0x10),puVar9,uVar11);
        *(undefined2 *)0x4b62 = uVar3;
        *(undefined2 *)0x4b60 = uVar11;
        func_0x00013ba8(0x13b0,(undefined4 *)local_a,(int)((ulong)local_a >> 0x10));
        uVar3 = 0x13b0;
        func_0x00013c0c(0x13b0,(undefined4 *)local_a,(int)((ulong)local_a >> 0x10),0);
        uVar11 = extraout_DX_06;
      }
      uVar3 = fn_0000_08ec((int)uRam0001617a,(int)((ulong)uRam0001617a >> 0x10));
      local_e = CONCAT22(uVar11,uVar3);
      uVar4 = (undefined2)((ulong)local_6 >> 0x10);
      fn_0000_338a(0x1040,*(undefined2 *)0x3649,uVar3,uVar11,((undefined2 *)local_6)[1],
                    ((undefined2 *)local_6)[2]);
      uVar3 = 0x6e8f;
      fn_0000_0a31(0x1338,local_e);
      iVar2 = *(int *)((int)puVar7 + iVar6 * 0xe + 7);
      if (iVar2 == 3) {
        cVar1 = *(char *)0x8201;
LAB_5646_0a5e:
        local_18[3] = (int)cVar1;
      }
      else {
        if (iVar2 == 4) {
          cVar1 = *(char *)0x8200;
          goto LAB_5646_0a5e;
        }
        if (iVar2 == 5) {
          cVar1 = *(char *)0x81ff;
          goto LAB_5646_0a5e;
        }
      }
      uVar4 = (undefined2)((ulong)local_6 >> 0x10);
      uVar11 = extraout_DX_07;
      ovr_2d56_005c(*(undefined2 *)0x3649,((undefined2 *)local_6)[1] + local_18[1],
                    ((undefined2 *)local_6)[2],local_18[3],0,*param_1,uVar15,uVar3);
      uVar3 = (undefined2)((ulong)local_6 >> 0x10);
      puVar8 = (undefined2 *)local_6;
      if (puVar8[5] != 0) {
        uVar11 = (undefined2)((ulong)local_a >> 0x10);
        iVar5 = *(int *)(*(int *)((undefined4 *)local_a + 7) * 0x10 + 0x1f3b) * 8;
        iVar2 = puVar8[1] + iVar5 + -5;
        uVar11 = ovr_2d56_007f(puVar8[5],iVar2,
                               puVar8[2] +
                               *(int *)(*(int *)((undefined4 *)local_a + 7) * 0x10 + 0x1f3d) + 3,
                               0xcc,0,8);
        iVar5 = func_0x00011d2b(0x1040,uVar11,iVar5);
        iVar2 = iVar2 - iVar5;
        uVar11 = ovr_2d56_007f(((undefined2 *)local_6)[5],iVar2);
        fn_0000_0bb3(0x11d0,uVar11,iVar2);
        uVar11 = extraout_DX_08;
      }
      uVar3 = 0x1040;
      iVar6 = iVar6 + 1;
    }
  }
  fn_0000_2167(uVar3);
  fn_0000_0c22(0x1208,*param_1);
  fn_0000_1917(0x10b0,*(undefined2 *)0xad8d,*(undefined2 *)0xad8b,*(undefined2 *)0xad8d,
                *(undefined2 *)0xad8b,*(undefined2 *)0xad8f,*(undefined2 *)0xad91,2,0);
  func_0x0001217e(0x1190);
  fn_0000_1e8f(0x1208,0);
  return;
}


//// ovr_2d56_005c @ 5646:0b5b

void __cdecl16far
ovr_2d56_005c(undefined2 param_1,int param_2,undefined2 param_3,int param_4,int param_5,
             undefined2 param_6)

{
  undefined2 uVar1;
  undefined2 extraout_DX;
  undefined2 uVar2;
  undefined2 extraout_DX_00;
  undefined2 unaff_DS;
  undefined4 uVar3;
  
  fn_0000_1e8f();
  fn_0000_2167();
  uVar2 = extraout_DX;
  uVar1 = fn_0000_08ec(f_057f_0992);
  uVar3 = CONCAT22(uVar2,uVar1);
  fn_0000_338a(0x1040,*(undefined2 *)0x3649,uVar1,uVar2,param_2 + 2 + param_5,param_3);
  fn_0000_0a31(0x1338,uVar3);
  uVar2 = extraout_DX_00;
  fn_0000_08ec(f_057f_098e);
  fn_0000_338a(0x1040,*(undefined2 *)0x3649,param_6,uVar2,param_2 + 2 + param_4,param_3);
  fn_0000_0a31();
  func_0x0001217e();
  fn_0000_1e8f();
  return;
}


//// ovr_2d56_0061 @ 5646:0c11

undefined2 __cdecl16far ovr_2d56_0061(undefined4 param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int unaff_SI;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 unaff_DS;
  int local_4;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar4 = (int)param_1;
  iVar3 = *(int *)(iVar4 + 0x38);
  if (iVar3 == 3) {
    if (*(int *)0x3747 == 0) {
      return 0;
    }
    if (*(int *)0x3747 == 4) {
      return 0;
    }
    cVar2 = *(char *)0x8201;
  }
  else if (iVar3 == 4) {
    if (*(int *)0x3745 == 0) {
      return 0;
    }
    if (*(int *)0x3745 == 4) {
      return 0;
    }
    cVar2 = *(char *)0x8200;
  }
  else {
    if (iVar3 != 5) goto LAB_5646_0c70;
    if (*(int *)0x3749 == 0) {
      return 0;
    }
    if (*(long *)0xabbe == 0) {
      return 0;
    }
    cVar2 = *(char *)0x81ff;
  }
  unaff_SI = (int)cVar2;
LAB_5646_0c70:
  iVar3 = *(int *)(iVar4 + 0x1e);
  iVar1 = *(int *)(iVar4 + 0x3a);
  if (iVar1 == 0) {
    local_4 = unaff_SI + -10;
    iVar3 = iVar3 + 10;
  }
  else if (iVar1 == 1) {
    local_4 = *(int *)0x2f0c -
              (*(int *)(iVar4 + 0x1e) + *(int *)(*(int *)(iVar4 + 0x1c) * 0x10 + 0x1f3b) * 8 + 7);
  }
  else {
    local_4 = unaff_SI;
    if (iVar1 == 2) {
      iVar3 = iVar3 + -0x72;
      local_4 = unaff_SI + 10;
    }
  }
  if (local_4 < 0) {
    local_4 = 0;
  }
  if (100 < local_4) {
    local_4 = 100;
  }
  if (local_4 == unaff_SI) {
    return 0;
  }
  ovr_2d56_005c(0,iVar3,*(undefined2 *)(iVar4 + 0x20),local_4,unaff_SI,*(undefined2 *)(iVar4 + 0x1c)
               );
  uVar6 = 0x10b8;
  switchD_1000:0b94::default();
  iVar3 = *(int *)(iVar4 + 0x38);
  if (iVar3 == 3) {
    *(char *)0x8201 = (char)local_4;
    if (local_4 == 0) {
      *(uint *)0x7fda = *(uint *)0x7fda & 0xfffd;
      fn_07bc_0288(0);
      fn_0000_105e(0x17e0);
      *(undefined2 *)0x35e4 = 0;
    }
    else {
      fn_07bc_0288(((char)local_4 * 0x91) / 100 + 0x6e);
      *(uint *)0x7fda = *(uint *)0x7fda | 2;
      if (unaff_SI == 0) {
        *(undefined2 *)0x35e4 = 1;
        uVar5 = fn_0000_0351(0x17e0,0xffff);
        fn_0000_0351(0x1018,uVar5);
      }
    }
  }
  else if (iVar3 == 4) {
    *(char *)0x8200 = (char)local_4;
    if (local_4 == 0) {
      *(uint *)0x7fda = *(uint *)0x7fda & 0xfffe;
    }
    else {
      uVar6 = 0x17e0;
      fn_07bc_026a(0x10b8,((char)local_4 * 200) / 100 + 0x37);
      *(uint *)0x7fda = *(uint *)0x7fda | 1;
    }
    if ((*(uint *)0x7fda & 1) == 0) {
      fn_07bc_026a(uVar6,1);
      *(undefined2 *)0x35e2 = 0;
      *(undefined2 *)0x20cd = 0;
    }
    else {
      *(undefined2 *)0x35e2 = 1;
      *(undefined2 *)0x20cd = 1;
    }
    func_0x00010581();
    iVar3 = func_0x00010a42(0x1018,*(undefined2 *)0x11ca);
    *(int *)0x11ca = iVar3;
    if (iVar3 == 0x2f) {
      *(int *)0x11ca = *(int *)0x11ca + 1;
    }
  }
  else if (iVar3 == 5) {
    *(char *)0x81ff = (char)local_4;
    if ((*(char *)0x81ff == '\0') || (*(long *)0xabbe == 0)) {
      *(undefined2 *)0x20cf = 0;
    }
    else {
      func_0x00010ea2(0x10b8,*(undefined4 *)0xabbe,0xff,((char)local_4 * 200) / 100 + 0x37);
      *(undefined2 *)0x20cf = 1;
    }
  }
  return 1;
}


//// ovr_2d56_0025 @ 5646:0e43

undefined2 __cdecl16far ovr_2d56_0025(undefined2 param_1)

{
  bool bVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined2 unaff_CS;
  undefined2 unaff_DS;
  
  uVar3 = 0;
  uRam0001596b = param_1;
  ovr_2d56_004d(0x69,0x1590);
  ovr_2d56_0057(0x69,0x1590);
  bVar1 = true;
  while (bVar1) {
    uVar2 = fn_0000_0cb9(unaff_CS,*(undefined4 *)0x4b60);
    if ((uVar2 & 0x8000) != 0) {
      if ((uVar2 & 0x7fff) == 1) {
        uVar3 = 1;
      }
      else if ((uVar2 & 0x7fff) == 2) {
        uVar3 = 0;
      }
      bVar1 = false;
    }
    unaff_CS = 0x1040;
    fn_0000_0d3a();
  }
  ovr_2d56_0052(0x69,0x1590);
  return uVar3;
}


//// ovr_2d56_002a @ 5646:0ebd

void __cdecl16far ovr_2d56_002a(undefined2 param_1)

{
  bool bVar1;
  uint uVar2;
  undefined2 unaff_CS;
  undefined2 unaff_DS;
  
  f_057f_01e4 = param_1;
  ovr_2d56_004d(0xd2,0x1590);
  ovr_2d56_0057(0xd2,0x1590);
  bVar1 = true;
  while (bVar1) {
    uVar2 = fn_0000_0cb9(unaff_CS,*(undefined4 *)0x4b60);
    if ((uVar2 & 0x8000) != 0) {
      bVar1 = false;
    }
    unaff_CS = 0x1040;
    fn_0000_0d3a();
  }
  ovr_2d56_0052(0xd2,0x1590);
  return;
}


//// ovr_2d56_002f @ 5646:0f1e

int __cdecl16far ovr_2d56_002f(int param_1)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  undefined2 unaff_CS;
  undefined2 uVar4;
  undefined2 unaff_DS;
  undefined1 local_26 [14];
  undefined1 local_18 [14];
  undefined4 local_a;
  int local_6;
  int local_4;
  
  local_6 = 0;
  uVar1 = ovr_2d56_006b();
  *(undefined2 *)0x4b64 = uVar1;
  if (param_1 == 1) {
    iVar3 = *(int *)0x11ba;
  }
  else {
    iVar3 = 0;
  }
  *(int *)0x11bc = *(int *)0x4b64 + iVar3 + -1;
  if (*(int *)0x11bc < 1) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined2 *)0x11bc;
  }
  *(undefined2 *)0x11bc = uVar1;
  ovr_2d56_007a(param_1 == 1);
  if (param_1 == 0) {
    uRam00015a3d = 0x400e;
  }
  else if (param_1 == 1) {
    uRam00015a3d = 0x400d;
  }
  else if (param_1 == 2) {
    uRam00015a3d = 0x400f;
  }
  ovr_2d56_004d(0x13b,0x1590);
  ovr_2d56_0057(0x13b,0x1590);
  ovr_2d56_0075(param_1 == 1,1);
  local_4 = 1;
  do {
    if (local_4 == 0) {
      ovr_2d56_0052(0x13b,0x1590);
      return local_6;
    }
    ovr_2d56_0075(param_1 == 1,0);
    uVar1 = 0x10c8;
    uVar2 = fn_0000_0cb9(unaff_CS,(int)*(undefined4 *)0x4b60,
                          (int)((ulong)*(undefined4 *)0x4b60 >> 0x10));
    if ((uVar2 & 0x8000) != 0) {
      uVar2 = uVar2 & 0x7fff;
      uVar4 = 0x13b0;
      local_a = func_0x00013bdd(0x10c8,(int)*(undefined4 *)0x4b60,
                                (int)((ulong)*(undefined4 *)0x4b60 >> 0x10),uVar2);
      if (uVar2 == 5) {
        local_6 = 0;
        local_4 = 0;
      }
      else {
        if (uVar2 == 0x14) {
          *(int *)0x11bc = *(int *)0x11bc + 1;
          if (param_1 == 1) {
            iVar3 = *(int *)0x11ba;
          }
          else {
            iVar3 = 0;
          }
          if (*(int *)0x11bc < *(int *)0x4b64 + iVar3 + -1) {
            iVar3 = *(int *)0x11bc;
          }
          else {
            if (param_1 == 1) {
              iVar3 = *(int *)0x11ba;
            }
            else {
              iVar3 = 0;
            }
            iVar3 = *(int *)0x4b64 + iVar3 + -1;
          }
          *(int *)0x11bc = iVar3;
          if (param_1 == 1) goto LAB_5646_10b0;
LAB_5646_1080:
          uVar1 = 0;
        }
        else {
          if (uVar2 != 0x15) {
            ovr_2d56_0052(0x13b,0x1590);
            ovr_2d56_0070(local_18);
            if (param_1 == 0) {
              uVar4 = 0x1700;
              iVar3 = func_0x0001702a(0x13b0,local_18);
              if (iVar3 == 0) {
                uVar1 = 0x425d;
LAB_5646_1125:
                ovr_2d56_002a(uVar1);
              }
              else {
                if (iVar3 == 1) {
                  return 1;
                }
                if (iVar3 == 2) {
                  uVar1 = 0x425c;
                  goto LAB_5646_1125;
                }
              }
              if (iVar3 == 1) {
                return 1;
              }
            }
            else if (param_1 == 1) {
              local_6 = ovr_2d56_0066(uVar2 - 1);
              if (local_6 != 0) {
                return local_6;
              }
            }
            else if (param_1 == 2) {
              iVar3 = ovr_2d56_0025(0x400b);
              if (iVar3 != 0) {
                ovr_2d56_0070(local_18);
                remove(local_18);
                while( true ) {
                  ovr_2d56_0070(local_26);
                  iVar3 = func_0x0001118a(0x1000,local_26);
                  if (iVar3 == 0) break;
                  rename(local_26);
                  strcpy(local_18);
                }
              }
              return 1;
            }
            ovr_2d56_004d(0x13b,0x1590);
            ovr_2d56_0057(0x13b,0x1590);
            ovr_2d56_0075(param_1 == 1,1);
            goto LAB_5646_11f3;
          }
          *(int *)0x11bc = *(int *)0x11bc + -1;
          if (*(int *)0x11bc < 1) {
            uVar1 = 0;
          }
          else {
            uVar1 = *(undefined2 *)0x11bc;
          }
          *(undefined2 *)0x11bc = uVar1;
          if (param_1 != 1) goto LAB_5646_1080;
LAB_5646_10b0:
          uVar1 = 1;
        }
        ovr_2d56_007a(uVar1);
        uVar4 = 0x13b0;
        thunk_FUN_1000_3e64((int)*(undefined4 *)0x4b60,(int)((ulong)*(undefined4 *)0x4b60 >> 0x10));
      }
LAB_5646_11f3:
      uVar1 = 0x13b0;
      func_0x00013c0c(uVar4,(int)local_a,(int)((ulong)local_a >> 0x10),0);
    }
    unaff_CS = 0x1040;
    fn_0000_0d3a(uVar1);
  } while( true );
}


//// ovr_2d56_0066 @ 5646:1223

undefined2 __cdecl16far ovr_2d56_0066(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  undefined4 uVar3;
  undefined2 uVar4;
  undefined1 local_1a [14];
  uint local_c;
  undefined2 local_a;
  int local_8;
  undefined4 local_6;
  
  local_6 = (char *)CONCAT22(0x1590,(char *)(param_1 * 0x3d + 0x348));
  if ((*local_6 == '[') && (iVar1 = ovr_2d56_0039(0xa120,7), iVar1 == 0)) {
    ovr_2d56_002a(0x42cf);
    uVar2 = 0;
  }
  else {
    if (*local_6 == '[') {
      *local_6 = '\0';
    }
    ovr_2d56_004d(0x1a4,0x1590);
    ovr_2d56_0057(0x1a4,0x1590);
    uVar2 = 0;
    local_8 = 1;
    local_a = 1;
    uVar4 = 0;
    fn_0000_1e8f();
    fn_0000_0c22(0x11e8,8,uVar4);
    fn_0000_2167(0x10b0);
    fn_067a_0180(0x1208,*(int *)0xad8d * 8 + -1,*(int *)0xad8b + -1,*(int *)0xad8f * 8 + 2,
                  *(int *)0xad91 + 2,4,0);
    func_0x0001217e(0x1690);
    while (local_8 != 0) {
      local_c = fn_070c_07e0(local_6,0x8003c,(int)*(undefined4 *)0x4b60,
                              (int)((ulong)*(undefined4 *)0x4b60 >> 0x10),0,0,local_a);
      local_a = 2;
      if ((local_c & 0x8000) != 0) {
        uVar3 = func_0x00013bdd(0x1788,(int)*(undefined4 *)0x4b60,
                                (int)((ulong)*(undefined4 *)0x4b60 >> 0x10),local_c & 0x7fff,0);
        func_0x00013c0c(0x13b0,uVar3);
        if ((local_c & 0x7fff) == 1) {
          if (*local_6 != '\0') {
            ovr_2d56_0070(local_1a);
            fn_067a_088f(local_1a);
            local_8 = 0;
            uVar2 = 1;
          }
        }
        else if ((local_c & 0x7fff) == 2) {
          local_8 = 0;
          uVar2 = 0;
          ovr_2d56_007a(1);
        }
      }
    }
    ovr_2d56_0052(0x1a4,0x1590);
  }
  return uVar2;
}


//// ovr_2d56_0034 @ 5646:13a9

undefined2 __cdecl16far ovr_2d56_0034(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined2 unaff_SI;
  undefined2 unaff_DI;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 unaff_DS;
  undefined2 in_stack_0000fffa;
  undefined2 uVar6;
  undefined2 in_stack_0000fffc;
  
  fn_0000_0351();
  fn_0000_1184(0x1018,unaff_DI,unaff_SI,in_stack_0000fffa);
  segread(0,1);
  fn_0000_0df1(0x1040,0);
  *(uint *)0x7fd6 = *(uint *)0x7fd6 | 4;
  fn_070c_03f3(1);
  uVar4 = 0x1460;
  fn_0000_4642(0x1738,2,in_stack_0000fffc);
  ovr_2d56_004d(0x20d,0x1590);
  uVar6 = 0x1460;
  ovr_2d56_0057(0x20d,0x1590);
  bVar1 = true;
  while (bVar1) {
    uVar5 = 0x10c8;
    uVar2 = fn_0000_0cb9(uVar4,(int)*(undefined4 *)0x4b60,
                          (int)((ulong)*(undefined4 *)0x4b60 >> 0x10));
    uVar6 = uVar4;
    if ((uVar2 & 0x8000) != 0) {
      uVar5 = 0x13b0;
      func_0x00013bdd(0x10c8,(int)*(undefined4 *)0x4b60,(int)((ulong)*(undefined4 *)0x4b60 >> 0x10),
                      uVar2);
      uVar6 = 0x789c;
      ovr_2d56_0052(0x20d);
      if ((uVar2 & 0x7fff) == 1) {
        uVar5 = 0x1040;
        fn_0000_0ff6();
      }
      else if (((uVar2 & 0x7fff) == 2) && (iVar3 = ovr_2d56_002f(), iVar3 != 0)) {
        bVar1 = false;
      }
      if (bVar1) {
        ovr_2d56_004d(0x20d,0x1590);
        uVar6 = uVar5;
        ovr_2d56_0057(0x20d,0x1590);
      }
    }
    uVar4 = 0x1040;
    fn_0000_0d3a(uVar5);
  }
  func_0x00010e5b(uVar4);
  *(uint *)0x7fd6 = *(uint *)0x7fd6 & 0xfffb;
  uVar4 = 0x78fd;
  fn_070c_03ee(0x1040);
  func_0x00013cb2(0x1738,uVar6,uVar4,0);
  thunk_FUN_1638_03d4(0x13b0);
  func_0x00014608(0x1670,2);
  fn_0000_0caa(0x1460);
  return 1;
}


//// ovr_2d56_006b @ 5646:14c4

int __cdecl16far ovr_2d56_006b(void)

{
  int iVar1;
  int iVar2;
  undefined2 unaff_CS;
  undefined1 local_10 [14];
  
  iVar2 = 0;
  while( true ) {
    ovr_2d56_0070(local_10);
    iVar1 = func_0x0001118a(unaff_CS,local_10);
    if (iVar1 == 0) break;
    iVar2 = iVar2 + 1;
    unaff_CS = 0x1118;
  }
  return iVar2;
}


//// ovr_2d56_0070 @ 5646:14f4

void __cdecl16far ovr_2d56_0070(undefined4 param_1)

{
  sprintf(param_1,0x11e4);
  return;
}


//// ovr_2d56_0075 @ 5646:150c

void __cdecl16far ovr_2d56_0075(int param_1,int param_2)

{
  int iVar1;
  undefined2 unaff_DS;
  
  if ((param_2 != 0) || (*(int *)0x11bc != *(int *)0x11cc)) {
    *(undefined2 *)0x11cc = *(undefined2 *)0x11bc;
    if (*(int *)0x11bc < 4) {
      fn_0000_3b73();
      fn_4646_038c(0x117e);
    }
    else {
      func_0x00013ba8();
    }
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)0x11ba;
    }
    if (*(int *)0x11bc < *(int *)0x4b64 + iVar1 + -1) {
      func_0x00013ba8(0x13b0,0x1142);
    }
    else {
      fn_0000_3b73(0x13b0,0x1142);
      fn_4646_038c(0x1142);
    }
  }
  return;
}


//// ovr_2d56_0039 @ 5646:1597

undefined2 __cdecl16far ovr_2d56_0039(long param_1)

{
  undefined2 uVar1;
  long lVar2;
  undefined2 local_a;
  undefined2 local_6;
  undefined2 local_4;
  
  getdfree();
  if ((local_4 == 0xffff) ||
     (lVar2 = (ulong)local_a * (ulong)local_6 * (ulong)local_4,
     lVar2 - param_1 == 0 || lVar2 < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


//// ovr_2d56_007a @ 5646:15d8

void __cdecl16far ovr_2d56_007a(int param_1)

{
  undefined2 uVar1;
  undefined2 in_DX;
  undefined2 extraout_DX;
  int iVar2;
  undefined2 unaff_CS;
  undefined2 unaff_DS;
  undefined4 uVar3;
  undefined2 uVar4;
  undefined1 local_10 [14];
  
  iVar2 = 0;
  do {
    if (3 < iVar2) {
      return;
    }
    if (*(int *)0x11bc < iVar2) {
LAB_5646_1678:
      *(undefined1 *)(iVar2 * 0x3d + 0x348) = 0;
    }
    else if (*(int *)0x11bc - iVar2 == *(int *)0x4b64) {
      if (param_1 == 0) goto LAB_5646_1678;
      uVar1 = ovr_2d56_007f(0x4010);
      unaff_CS = 0x1000;
      strcpy(iVar2 * 0x3d + 0x348,0x1590,uVar1,in_DX);
    }
    else {
      ovr_2d56_0070(local_10);
      uVar3 = func_0x0001118a(unaff_CS,local_10);
      in_DX = (undefined2)((ulong)uVar3 >> 0x10);
      unaff_CS = 0x1118;
      if ((int)uVar3 == 0) goto LAB_5646_1678;
      uVar4 = 1;
      uVar1 = thunk_FUN_1000_1130(0x1118,local_10);
      fn_0000_194d(0x1110,uVar1,iVar2 * 0x3d + 0x348,0x1590,0x3c,uVar4);
      unaff_CS = 0x1110;
      in_DX = extraout_DX;
      fn_0000_168d(uVar1);
    }
    iVar2 = iVar2 + 1;
  } while( true );
}


//// ovr_2d56_007f @ 5646:1695

/* WARNING: Instruction at (ram,0x000515d2) overlaps instruction at (ram,0x000515d1)
    */
/* WARNING: Type propagation algorithm not settling */

uint * __cdecl16far
ovr_2d56_007f(undefined1 *param_1,undefined2 param_2,undefined2 *param_3,int param_4,long param_5,
             long param_6,long param_7)

{
  byte *pbVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  char cVar13;
  undefined1 uVar14;
  undefined1 uVar15;
  undefined1 uVar16;
  undefined1 uVar17;
  undefined1 uVar18;
  undefined1 uVar19;
  undefined1 uVar20;
  undefined1 uVar21;
  undefined1 uVar22;
  undefined1 uVar23;
  undefined1 uVar24;
  undefined1 uVar25;
  undefined1 uVar26;
  undefined1 uVar27;
  undefined1 uVar28;
  undefined1 uVar29;
  byte bVar30;
  uint *puVar31;
  undefined2 uVar32;
  undefined2 uVar33;
  int iVar34;
  int iVar35;
  ulong in_EAX;
  long lVar36;
  long lVar37;
  int in_CX;
  int iVar38;
  byte bVar39;
  uint uVar40;
  undefined1 *puVar41;
  undefined4 uVar43;
  undefined1 *puVar44;
  int iVar45;
  undefined2 *puVar46;
  undefined2 unaff_BP;
  uint unaff_SI;
  int iVar47;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_AF;
  bool bVar48;
  undefined1 in_stack_00000000;
  undefined1 auStack_326 [45];
  undefined1 auStack_2f9 [357];
  undefined1 auStack_194 [14];
  undefined1 auStack_186 [342];
  int aiStack_30 [4];
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined1 uStack_25;
  undefined2 uStack_24;
  undefined1 uStack_22;
  undefined1 uStack_21;
  undefined1 uStack_20;
  undefined1 uStack_1f;
  char cStack_1e;
  undefined1 uStack_1d;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined1 auStack_14 [2];
  undefined1 auStack_12 [2];
  undefined1 auStack_10 [2];
  undefined1 auStack_e [2];
  undefined1 auStack_c [2];
  undefined1 auStack_a [2];
  undefined1 auStack_8 [2];
  undefined1 auStack_6 [2];
  undefined2 uStack_4;
  undefined2 uStack_2;
  ulong uVar42;
  
  uVar28 = auStack_6[1];
  uVar26 = auStack_6[0];
  uVar24 = auStack_8[1];
  uVar22 = auStack_8[0];
  uVar19 = auStack_a[1];
  uVar15 = auStack_a[0];
  uVar12 = auStack_c[1];
  uVar10 = auStack_e[1];
  uVar8 = auStack_e[0];
  uVar6 = auStack_14[0];
  uVar4 = uStack_15;
  iVar47 = CONCAT11(auStack_6[1],auStack_6[0]);
  iVar34 = CONCAT11(auStack_14[1],auStack_14[0]);
  puVar46 = &uStack_2;
  uStack_2._0_1_ = (undefined1)unaff_BP;
  uStack_2._1_1_ = (undefined1)((uint)unaff_BP >> 8);
  uVar42 = ZEXT24(param_1);
  puVar44 = param_1 + 0xe;
  bVar39 = (byte)param_1;
  auStack_c[1] = (char)((uint)param_1 >> 8);
  cVar13 = auStack_c[1];
  if ((undefined1 *)0xc < puVar44) {
    auStack_a[0] = (char)unaff_CS;
    auStack_a[1] = (char)((uint)unaff_CS >> 8);
    auStack_c[0] = 0x93;
    auStack_c[1] = 0x7b;
    auStack_8[0] = bVar39;
    auStack_8[1] = cVar13;
    puVar31 = (uint *)fn_0000_0af8();
    return puVar31;
  }
  iVar45 = (int)puVar44 * 2;
  uVar32 = 0x5000;
  bVar30 = (byte)in_EAX;
  auStack_a[0] = (char)param_2;
  uVar16 = auStack_a[0];
  auStack_a[1] = (char)((uint)param_2 >> 8);
  uVar20 = auStack_a[1];
  auStack_e[0] = (byte)param_3;
  uVar9 = auStack_e[0];
  auStack_e[1] = (char)((uint)param_3 >> 8);
  uVar11 = auStack_e[1];
  auStack_c[1] = (char)param_4;
  uVar14 = auStack_c[1];
  auStack_a[0] = (char)((uint)param_4 >> 8);
  uVar17 = auStack_a[0];
  uStack_15 = (undefined1)unaff_DS;
  uVar5 = uStack_15;
  auStack_14[0] = (undefined1)((uint)unaff_DS >> 8);
  uVar7 = auStack_14[0];
  auStack_8[0] = (byte)param_5;
  uVar23 = auStack_8[0];
  auStack_8[1] = (char)((ulong)param_5 >> 8);
  uVar25 = auStack_8[1];
  auStack_6[0] = (byte)((ulong)param_5 >> 0x10);
  uVar27 = auStack_6[0];
  auStack_6[1] = (char)((ulong)param_5 >> 0x18);
  uVar29 = auStack_6[1];
  auStack_a[0] = (char)unaff_SS;
  uVar18 = auStack_a[0];
  auStack_a[1] = (char)((uint)unaff_SS >> 8);
  uVar21 = auStack_a[1];
  puVar41 = param_1;
  auStack_6[0] = uVar26;
  auStack_6[1] = uVar28;
  auStack_8[1] = uVar24;
  auStack_a[1] = uVar19;
  auStack_8[0] = uVar22;
  auStack_a[0] = uVar15;
  uStack_15 = uVar4;
  switch(puVar44) {
  case (undefined1 *)0x0:
    auStack_8[0] = 0;
    auStack_8[1] = 0x50;
    auStack_a[0] = 0x1a;
    auStack_a[1] = 0x8b;
    func_0x000188aa();
    break;
  case (undefined1 *)0x1:
    uVar32 = *(undefined2 *)(iVar45 + (*(int *)(iVar45 + 0xc) + 2) * 2 + 0x2c);
    auStack_8[0] = (byte)uVar32;
    auStack_8[1] = (char)((uint)uVar32 >> 8);
    auStack_a[0] = (char)*(undefined2 *)(param_1 + (*(int *)(param_1 + 0xc) + 1) * 2 + 0x2c);
    auStack_a[1] = (char)((uint)*(undefined2 *)(param_1 + (*(int *)(param_1 + 0xc) + 1) * 2 + 0x2c)
                         >> 8);
    auStack_c[0] = (byte)*(undefined2 *)(param_1 + *(int *)(param_1 + 0xc) * 2 + 0x2c);
    auStack_c[1] = (char)((uint)*(undefined2 *)(param_1 + *(int *)(param_1 + 0xc) * 2 + 0x2c) >> 8);
    auStack_e[0] = 0;
    auStack_e[1] = 0x50;
    auStack_10[0] = 9;
    auStack_10[1] = 0x8f;
    ovr_2d5f_0070();
    return (uint *)0x1;
  case (undefined1 *)0x2:
    auStack_a[0] = (char)unaff_SI;
    uVar4 = auStack_a[0];
    auStack_a[1] = (char)(unaff_SI >> 8);
    uVar6 = auStack_a[1];
    auStack_8[0] = (byte)(in_EAX >> 0x10);
    auStack_8[1] = (char)(in_EAX >> 0x18);
    auStack_c[0] = 0;
    auStack_c[1] = 0x50;
    auStack_e[0] = 0xcc;
    auStack_e[1] = 0x26;
    uVar32 = func_0x000171be();
    *(undefined2 *)0x7fc2 = (int)uVar42;
    *(undefined2 *)0x7fc0 = uVar32;
    auStack_6[0] = 0;
    auStack_6[1] = 0;
    uVar43 = *(undefined4 *)0x7fc0;
    auStack_c[0] = (byte)uVar43;
    auStack_c[1] = (char)((ulong)uVar43 >> 8);
    auStack_a[0] = (char)((ulong)uVar43 >> 0x10);
    auStack_a[1] = (char)((ulong)uVar43 >> 0x18);
    auStack_10[0] = 0;
    auStack_10[1] = 0;
    auStack_12[0] = 0x18;
    auStack_12[1] = 0x17;
    auStack_14[0] = 0xea;
    auStack_14[1] = 0x26;
    auStack_8[0] = uVar4;
    auStack_8[1] = uVar6;
    fn_0000_445b();
    auStack_8 = (undefined1  [2])(CONCAT11(auStack_6[1],auStack_6[0]) + unaff_SI);
    auStack_a[0] = 0x20;
    auStack_a[1] = 0x14;
    uVar32 = 0x1140;
    auStack_c[0] = 0xf9;
    auStack_c[1] = 0x26;
    func_0x0001141c();
    if (param_7 != 0) {
      auStack_8[0] = 0x80;
      auStack_8[1] = 1;
      auStack_6[0] = 0;
      auStack_6[1] = 0;
      auStack_c[0] = 0;
      auStack_c[1] = 0;
      auStack_10[0] = (char)param_7;
      auStack_10[1] = (undefined1)((ulong)param_7 >> 8);
      auStack_e[0] = (byte)((ulong)param_7 >> 0x10);
      auStack_e[1] = (char)((ulong)param_7 >> 0x18);
      auStack_12[0] = 0x40;
      auStack_12[1] = 0x11;
      uVar32 = 0x1860;
      auStack_14[0] = 0x1b;
      auStack_14[1] = 0x27;
      fn_0845_01d0();
    }
    auStack_8[0] = 0x80;
    auStack_8[1] = 1;
    auStack_6[0] = 0;
    auStack_6[1] = 0;
    uVar43 = *(undefined4 *)0xadea;
    auStack_c[0] = (byte)uVar43;
    auStack_c[1] = (char)((ulong)uVar43 >> 8);
    auStack_a[0] = (char)((ulong)uVar43 >> 0x10);
    auStack_a[1] = (char)((ulong)uVar43 >> 0x18);
    auStack_10[0] = 0;
    auStack_10[1] = 0;
    auStack_12[0] = (byte)uVar32;
    auStack_12[1] = (byte)((uint)uVar32 >> 8);
    auStack_14[0] = 0x32;
    auStack_14[1] = 0x27;
    fn_0000_445b();
    auStack_8[0] = 0x80;
    auStack_8[1] = 1;
    auStack_6[0] = 0;
    auStack_6[1] = 0;
    auStack_c = (undefined1  [2])auStack_186;
    auStack_10 = (undefined1  [2])(*(int *)0xadea + 0x180);
    auStack_e[0] = (byte)*(undefined2 *)0xadec;
    auStack_e[1] = (char)((uint)*(undefined2 *)0xadec >> 8);
    auStack_12[0] = 0x20;
    auStack_12[1] = 0x14;
    auStack_14[0] = 0x51;
    auStack_14[1] = 0x27;
    auStack_a[0] = uVar18;
    auStack_a[1] = uVar21;
    fn_0000_445b();
    auStack_6[0] = 0xff;
    auStack_6[1] = 0xff;
    auStack_8[0] = 0x80;
    auStack_8[1] = 1;
    auStack_c = (undefined1  [2])(*(int *)0xadea + 0x180);
    auStack_a[0] = (char)*(undefined2 *)0xadec;
    auStack_a[1] = (char)((uint)*(undefined2 *)0xadec >> 8);
    auStack_e[0] = 0x20;
    auStack_e[1] = 0x14;
    auStack_10[0] = 0x69;
    auStack_10[1] = 0x27;
    setmem();
    auStack_8[0] = 0x80;
    auStack_8[1] = 1;
    auStack_6[0] = 0;
    auStack_6[1] = 0;
    auStack_c = (undefined1  [2])(*(int *)0xadea + 0x180);
    auStack_a[0] = (char)*(undefined2 *)0xadec;
    auStack_a[1] = (char)((uint)*(undefined2 *)0xadec >> 8);
    auStack_10 = (undefined1  [2])auStack_186;
    auStack_12[0] = 0;
    auStack_12[1] = 0x10;
    auStack_14[0] = 0x88;
    auStack_14[1] = 0x27;
    auStack_e[0] = uVar18;
    auStack_e[1] = uVar21;
    fn_0000_445b();
    auStack_6[0] = 0x20;
    auStack_6[1] = 0x14;
    auStack_8[0] = 0x90;
    auStack_8[1] = 0x27;
    func_0x00016e2a();
    uVar43 = *(undefined4 *)0x7fc4;
    auStack_c[0] = (byte)uVar43;
    auStack_c[1] = (char)((ulong)uVar43 >> 8);
    auStack_a[0] = (char)((ulong)uVar43 >> 0x10);
    auStack_a[1] = (char)((ulong)uVar43 >> 0x18);
    auStack_12[0] = 0xe0;
    auStack_12[1] = 0x16;
    auStack_14[0] = 0xa7;
    auStack_14[1] = 0x27;
    auStack_10[0] = uVar27;
    auStack_10[1] = uVar29;
    auStack_8[0] = uVar23;
    auStack_8[1] = uVar25;
    auStack_6[0] = uVar27;
    auStack_6[1] = uVar29;
    fn_0000_445b();
    auStack_8[0] = 0x70;
    auStack_8[1] = 0xe;
    auStack_10[0] = 0x6a;
    auStack_10[1] = 0xe;
    auStack_14[0] = 0x99;
    auStack_14[1] = 0xad;
    uStack_16 = 0x20;
    uStack_15 = 0x14;
    uStack_18 = 0xbf;
    uStack_17 = 0x27;
    auStack_12[0] = uVar5;
    auStack_12[1] = uVar7;
    auStack_e[0] = uVar5;
    auStack_e[1] = uVar7;
    auStack_c[0] = bVar39;
    auStack_c[1] = cVar13;
    auStack_a[0] = uVar16;
    auStack_a[1] = uVar20;
    auStack_6[0] = uVar5;
    auStack_6[1] = uVar7;
    sprintf();
    if (param_6 == 0xffff) {
      auStack_8[0] = 0;
      auStack_8[1] = 0;
      auStack_6[0] = 0;
      auStack_6[1] = 0;
      auStack_c[0] = 3;
      auStack_c[1] = 0;
      auStack_a[0] = 3;
      auStack_a[1] = 0;
      auStack_10[0] = 0x99;
      auStack_10[1] = 0xad;
      auStack_12[0] = 0;
      auStack_12[1] = 0x10;
      auStack_14[0] = 0xde;
      auStack_14[1] = 0x27;
      auStack_e[0] = uVar5;
      auStack_e[1] = uVar7;
      uVar32 = fn_0845_01df();
      auStack_12[0] = (byte)uVar42;
      auStack_12[1] = (byte)(uVar42 >> 8);
      auStack_14[0] = (undefined1)uVar32;
      auStack_14[1] = (undefined1)((uint)uVar32 >> 8);
      param_6 = CONCAT13(auStack_12[1],CONCAT12(auStack_12[0],uVar32)) + -2;
    }
    else {
      auStack_8[0] = 0;
      auStack_8[1] = 0;
      auStack_6[0] = 0;
      auStack_6[1] = 0;
      auStack_c[0] = 3;
      auStack_c[1] = 0;
      auStack_a[0] = 3;
      auStack_a[1] = 0;
      auStack_10[0] = 0x99;
      auStack_10[1] = 0xad;
      auStack_12[0] = 0;
      auStack_12[1] = 0x10;
      auStack_14[0] = 1;
      auStack_14[1] = 0x28;
      auStack_e[0] = uVar5;
      auStack_e[1] = uVar7;
      fn_0845_01df();
    }
    uVar32 = 0x1860;
    auStack_a[0] = (char)param_6;
    uVar4 = auStack_a[0];
    auStack_a[1] = (char)((ulong)param_6 >> 8);
    uVar6 = auStack_a[1];
    auStack_8[0] = (byte)((ulong)param_6 >> 0x10);
    uVar8 = auStack_8[0];
    auStack_8[1] = (char)((ulong)param_6 >> 0x18);
    uVar10 = auStack_8[1];
    if (*(long *)0x7fc8 == 0) {
      auStack_6[0] = 0x20;
      auStack_6[1] = 0;
      auStack_c[0] = 0x60;
      auStack_c[1] = 0x18;
      uVar32 = 0x1718;
      auStack_e[0] = 0x17;
      auStack_e[1] = 0x28;
      uVar33 = func_0x000171be();
      *(undefined2 *)0x7fca = (int)uVar42;
      *(undefined2 *)0x7fc8 = uVar33;
    }
    uVar43 = *(undefined4 *)0x7fc8;
    auStack_c[0] = (byte)uVar43;
    auStack_c[1] = (char)((ulong)uVar43 >> 8);
    auStack_a[0] = (char)((ulong)uVar43 >> 0x10);
    auStack_a[1] = (char)((ulong)uVar43 >> 0x18);
    auStack_10 = (undefined1  [2])(*(int *)0x7fcc + 2);
    auStack_e[0] = (byte)*(undefined2 *)0x7fce;
    auStack_e[1] = (char)((uint)*(undefined2 *)0x7fce >> 8);
    auStack_12[0] = (byte)uVar32;
    auStack_12[1] = (byte)((uint)uVar32 >> 8);
    uVar32 = 0x1420;
    auStack_14[0] = 0x3a;
    auStack_14[1] = 0x28;
    auStack_8[0] = uVar4;
    auStack_8[1] = uVar6;
    auStack_6[0] = uVar8;
    auStack_6[1] = uVar10;
    fn_0000_445b();
    iVar47 = 0;
    do {
      if (*(int *)(iVar47 * 4 + 0x7c72) == 0 && *(int *)(iVar47 * 4 + 0x7c74) == 0) {
        auStack_6[0] = 0;
        auStack_6[1] = 0;
        auStack_a[0] = 0;
        auStack_a[1] = 1;
        auStack_8[0] = 0;
        auStack_8[1] = 0;
        auStack_c[0] = (byte)uVar32;
        auStack_c[1] = (char)((uint)uVar32 >> 8);
        uVar32 = 0x1718;
        auStack_e[0] = 0x5b;
        auStack_e[1] = 0x28;
        uVar33 = func_0x000171be();
        *(undefined2 *)(iVar47 * 4 + 0x7c74) = (int)uVar42;
        *(undefined2 *)(iVar47 * 4 + 0x7c72) = uVar33;
      }
      if (iVar47 != 7) {
        iVar34 = 100 - iVar47 * param_4;
        if (iVar34 < 1) {
          iVar34 = 0;
        }
        else {
          iVar34 = (iVar34 * 0xff) / 100;
        }
        auStack_6[0] = (byte)iVar34;
        auStack_6[1] = (char)((uint)iVar34 >> 8);
        auStack_8[0] = (byte)unaff_DI;
        auStack_8[1] = (char)((uint)unaff_DI >> 8);
        uVar43 = *(undefined4 *)(iVar47 * 4 + 0x7c72);
        auStack_c[0] = (byte)uVar43;
        auStack_c[1] = (char)((ulong)uVar43 >> 8);
        auStack_a[0] = (char)((ulong)uVar43 >> 0x10);
        auStack_a[1] = (char)((ulong)uVar43 >> 0x18);
        uVar43 = *(undefined4 *)0xadea;
        auStack_10[0] = (char)uVar43;
        auStack_10[1] = (undefined1)((ulong)uVar43 >> 8);
        auStack_e[0] = (byte)((ulong)uVar43 >> 0x10);
        auStack_e[1] = (char)((ulong)uVar43 >> 0x18);
        auStack_12[0] = (byte)uVar32;
        auStack_12[1] = (byte)((uint)uVar32 >> 8);
        uVar32 = 0x1150;
        auStack_14[0] = 0xa6;
        auStack_14[1] = 0x28;
        fn_0000_1609();
        iVar34 = 0;
        do {
          uVar43 = *(undefined4 *)(iVar47 * 4 + 0x7c72);
          uVar33 = (undefined2)((ulong)uVar43 >> 0x10);
          if (*(char *)((int)uVar43 + iVar34) == -1) {
            *(undefined1 *)(*(int *)(iVar47 * 4 + 0x7c72) + iVar34) = 0;
          }
          iVar34 = iVar34 + 1;
        } while (iVar34 < 0x80);
        uVar42 = 0x80;
        while (iVar34 = (int)uVar42, iVar34 < 0x100) {
          uVar43 = *(undefined4 *)(iVar47 * 4 + 0x7c72);
          *(undefined1 *)((int)uVar43 + iVar34) = (char)uVar42;
          uVar42 = (ulong)(iVar34 + 1);
        }
      }
      iVar47 = iVar47 + 1;
    } while (iVar47 < 8);
    iVar47 = 0;
    do {
      *(undefined1 *)((int)*(undefined4 *)0x7c8e + iVar47) = (char)iVar47;
      iVar47 = iVar47 + 1;
    } while (iVar47 < 0x100);
    *(undefined2 *)0x20d9 = 0;
    auStack_6[0] = *(char *)0x81de;
    auStack_6[1] = (char)auStack_6[0] >> 7;
    auStack_8[0] = *(char *)0x81dc;
    auStack_8[1] = (char)auStack_8[0] >> 7;
    uVar43 = *(undefined4 *)0x540e;
    auStack_c[0] = (byte)uVar43;
    auStack_c[1] = (char)((ulong)uVar43 >> 8);
    auStack_a[0] = (char)((ulong)uVar43 >> 0x10);
    auStack_a[1] = (char)((ulong)uVar43 >> 0x18);
    uVar43 = *(undefined4 *)0xadea;
    auStack_10[0] = (char)uVar43;
    auStack_10[1] = (undefined1)((ulong)uVar43 >> 8);
    auStack_e[0] = (byte)((ulong)uVar43 >> 0x10);
    auStack_e[1] = (char)((ulong)uVar43 >> 0x18);
    auStack_12[0] = (byte)uVar32;
    auStack_12[1] = (byte)((uint)uVar32 >> 8);
    auStack_14[0] = 0x26;
    auStack_14[1] = 0x29;
    fn_0000_06c6();
    auStack_6[0] = *(char *)0x7fe5;
    auStack_6[1] = (char)auStack_6[0] >> 7;
    auStack_a[0] = 0x74;
    auStack_a[1] = 0xe;
    auStack_e = (undefined1  [2])auStack_194;
    auStack_10[0] = 0x40;
    auStack_10[1] = 0x10;
    auStack_12[0] = 0x3d;
    auStack_12[1] = 0x29;
    auStack_c[0] = uVar18;
    auStack_c[1] = uVar21;
    auStack_8[0] = uVar5;
    auStack_8[1] = uVar7;
    sprintf();
    auStack_6[0] = 1;
    auStack_6[1] = 0;
    auStack_a = (undefined1  [2])auStack_194;
    auStack_c[0] = 0;
    auStack_c[1] = 0x10;
    auStack_e[0] = 0x4d;
    auStack_e[1] = 0x29;
    auStack_8[0] = uVar18;
    auStack_8[1] = uVar21;
    uVar32 = thunk_FUN_1000_1130();
    auStack_a[0] = 0;
    auStack_a[1] = 1;
    auStack_8[0] = 0;
    auStack_8[1] = 0;
    uVar43 = *(undefined4 *)0x4bec;
    auStack_e[0] = (byte)uVar43;
    auStack_e[1] = (char)((ulong)uVar43 >> 8);
    auStack_c[0] = (byte)((ulong)uVar43 >> 0x10);
    auStack_c[1] = (char)((ulong)uVar43 >> 0x18);
    auStack_10[0] = (char)uVar32;
    uVar4 = auStack_10[0];
    auStack_10[1] = (undefined1)((uint)uVar32 >> 8);
    uVar6 = auStack_10[1];
    auStack_12[0] = 0x10;
    auStack_12[1] = 0x11;
    auStack_14[0] = 99;
    auStack_14[1] = 0x29;
    fn_0000_194d();
    auStack_a[0] = 0;
    auStack_a[1] = 0x14;
    auStack_8[0] = 0;
    auStack_8[1] = 0;
    uVar43 = *(undefined4 *)0x4bf0;
    auStack_e[0] = (byte)uVar43;
    auStack_e[1] = (char)((ulong)uVar43 >> 8);
    auStack_c[0] = (byte)((ulong)uVar43 >> 0x10);
    auStack_c[1] = (char)((ulong)uVar43 >> 0x18);
    auStack_12[0] = 0x10;
    auStack_12[1] = 0x11;
    auStack_14[0] = 0x77;
    auStack_14[1] = 0x29;
    auStack_10[0] = uVar4;
    auStack_10[1] = uVar6;
    fn_0000_194d();
    auStack_a[0] = 0x10;
    auStack_a[1] = 0x11;
    auStack_c[0] = 0x80;
    auStack_c[1] = 0x29;
    auStack_8[0] = uVar4;
    auStack_8[1] = uVar6;
    puVar31 = (uint *)fn_0000_168d();
    *(undefined2 *)0x20d9 = 1;
    return puVar31;
  case (undefined1 *)0x3:
    *(byte *)((int)&uStack_2 + unaff_SI) = *(byte *)((int)&uStack_2 + unaff_SI) | bVar39;
    auStack_a[0] = 0;
    auStack_a[1] = 0x50;
    auStack_c[0] = 0x99;
    auStack_c[1] = 0x97;
    fn_0000_1e8f();
    auStack_e[0] = 0xe8;
    auStack_e[1] = 0x11;
    auStack_10[0] = 0xa3;
    auStack_10[1] = 0x97;
    func_0x00012302();
    return (uint *)0x1;
  case (undefined1 *)0x4:
    auStack_14 = (undefined1  [2])iVar34;
    do {
      auStack_8[1] = 0;
      auStack_8[0] = 4;
      auStack_c = (undefined1  [2])(unaff_SI * 0x82 + 0x362d);
      auStack_a[0] = 0xf8;
      auStack_a[1] = 0x15;
      auStack_e[0] = (byte)uVar32;
      auStack_e[1] = (char)((uint)uVar32 >> 8);
      uVar32 = 0x1068;
      auStack_10[0] = 0x77;
      auStack_10[1] = 1;
      fn_0000_09e5();
      do {
        auStack_6[0] = (byte)unaff_SI;
        auStack_6[1] = (char)(unaff_SI >> 8);
        auStack_8[0] = (byte)uVar32;
        auStack_8[1] = (char)((uint)uVar32 >> 8);
        auStack_a[0] = 0x80;
        auStack_a[1] = 1;
        fn_0000_072b();
        iVar47 = *(int *)(&uStack_1c + unaff_SI * 2) + 0x2c;
        auStack_6[0] = (byte)iVar47;
        auStack_6[1] = (char)((uint)iVar47 >> 8);
        iVar34 = *(int *)(auStack_14 + unaff_SI * 2) + 0x4d;
        auStack_8[0] = (byte)iVar34;
        auStack_8[1] = (char)((uint)iVar34 >> 8);
        auStack_a[0] = (char)*(undefined2 *)(&uStack_1c + unaff_SI * 2);
        auStack_a[1] = (char)((uint)*(undefined2 *)(&uStack_1c + unaff_SI * 2) >> 8);
        auStack_c[0] = (byte)*(undefined2 *)(auStack_14 + unaff_SI * 2);
        auStack_c[1] = (char)((uint)*(undefined2 *)(auStack_14 + unaff_SI * 2) >> 8);
        auStack_e[0] = 0x50;
        auStack_e[1] = 0x10;
        auStack_10[0] = 0xbe;
        auStack_10[1] = 1;
        auStack_6 = (undefined1  [2])iVar47;
        auStack_8 = (undefined1  [2])iVar34;
        fn_0000_2191();
        auStack_8[0] = 2;
        auStack_8[1] = 0;
        auStack_6[0] = 0;
        auStack_6[1] = 0;
        auStack_c[0] = 0x4d;
        auStack_c[1] = 0;
        auStack_a[0] = 0x2c;
        auStack_a[1] = 0;
        auStack_e[0] = (byte)*(undefined2 *)(&uStack_1c + unaff_SI * 2);
        auStack_e[1] = (char)((uint)*(undefined2 *)(&uStack_1c + unaff_SI * 2) >> 8);
        auStack_10[0] = (char)*(undefined2 *)(auStack_14 + unaff_SI * 2);
        auStack_10[1] = (undefined1)((uint)*(undefined2 *)(auStack_14 + unaff_SI * 2) >> 8);
        auStack_12[0] = (byte)*(undefined2 *)(&uStack_1c + unaff_SI * 2);
        auStack_12[1] = (byte)((uint)*(undefined2 *)(&uStack_1c + unaff_SI * 2) >> 8);
        auStack_14[0] = (undefined1)*(undefined2 *)(auStack_14 + unaff_SI * 2);
        auStack_14[1] = (undefined1)((uint)*(undefined2 *)(auStack_14 + unaff_SI * 2) >> 8);
        uStack_16 = 8;
        uStack_15 = 0x12;
        uStack_18 = 0xff;
        uStack_17 = 1;
        fn_0000_1904();
        auStack_6[0] = 0x90;
        auStack_6[1] = 0x11;
        auStack_8[0] = 7;
        auStack_8[1] = 2;
        fn_0000_226c();
        do {
          unaff_SI = unaff_SI + 1;
          if (unaff_DI <= (int)unaff_SI) {
            auStack_8[0] = 8;
            auStack_8[1] = 0x12;
            auStack_a[0] = 0x17;
            auStack_a[1] = 2;
            fn_0000_1e8f();
            if (aiStack_30[2] == 1) {
              auStack_8[0] = 0xe8;
              auStack_8[1] = 0x11;
              auStack_a[0] = 0x22;
              auStack_a[1] = 2;
              func_0x0005fc2a();
            }
            auStack_8[0] = 0xe8;
            auStack_8[1] = 0x11;
            auStack_a[0] = 0x27;
            auStack_a[1] = 2;
            puVar31 = (uint *)fn_0000_0caa();
            return puVar31;
          }
        } while ((*(uint *)(unaff_SI * 0x82 + 0x362d) & 1) == 0);
        auStack_8[0] = 2;
        auStack_8[1] = 0;
        auStack_6[0] = 2;
        auStack_6[1] = 0;
        auStack_c[0] = 0x4d;
        auStack_c[1] = 0;
        auStack_a[0] = 0x2c;
        auStack_a[1] = 0;
        auStack_e[0] = (byte)*(undefined2 *)(&uStack_1c + unaff_SI * 2);
        auStack_e[1] = (char)((uint)*(undefined2 *)(&uStack_1c + unaff_SI * 2) >> 8);
        auStack_10[0] = (char)*(undefined2 *)(auStack_14 + unaff_SI * 2);
        auStack_10[1] = (undefined1)((uint)*(undefined2 *)(auStack_14 + unaff_SI * 2) >> 8);
        auStack_12[0] = 0x20;
        auStack_12[1] = 0;
        auStack_14 = (undefined1  [2])(unaff_SI * 0x4d);
        uStack_16 = 8;
        uStack_15 = 0x12;
        uVar32 = 0x1190;
        uStack_18 = 0x56;
        uStack_17 = 1;
        fn_0000_1904();
      } while (aiStack_30[1] == 0);
      auStack_6[0] = 4;
      auStack_6[1] = 0;
    } while( true );
  case (undefined1 *)0x5:
    *(char *)(iVar45 + unaff_SI) = *(char *)(iVar45 + unaff_SI) + bVar39;
    iVar47 = CONCAT11(uVar19,uVar15);
    uVar32 = (undefined2)(CONCAT13(uVar24,CONCAT12(uVar22,iVar47)) >> 0x10);
    *(undefined2 *)(iVar47 + 0xc) =
         (int)CONCAT31((int3)(in_EAX >> 8),
                       bVar30 + (9 < (bVar30 & 0xf) | in_AF) * -6 +
                       (0x99 < bVar30 || (int)puVar44 < 0) * -0x60);
    *(undefined2 *)0x2962 = *(undefined2 *)(iVar47 + 0xc);
    uStack_4._0_1_ = 0;
    uStack_4._1_1_ = 0x50;
    auStack_6[0] = 0xab;
    auStack_6[1] = 0xda;
    auStack_12 = (undefined1  [2])strchr();
    auStack_10[0] = (char)puVar41;
    auStack_10[1] = (undefined1)((uint)puVar41 >> 8);
    if (auStack_12 != (undefined1  [2])0x0 || puVar41 != (undefined1 *)0x0) {
      auStack_12 = (undefined1  [2])((int)auStack_12 + 1);
      uStack_2._0_1_ = 0;
      uStack_2._1_1_ = 0;
      auStack_6[0] = SUB21(auStack_12,0);
      auStack_6[1] = (char)((uint)auStack_12 >> 8);
      uStack_4._0_1_ = auStack_10[0];
      uStack_4._1_1_ = auStack_10[1];
      auStack_8[0] = 0;
      auStack_8[1] = 0x10;
      auStack_a[0] = 0xcc;
      auStack_a[1] = 0xda;
      uVar32 = strtol();
      iVar47 = CONCAT11(auStack_a[1],auStack_a[0]);
      uVar33 = (undefined2)(CONCAT13(auStack_8[1],CONCAT12(auStack_8[0],iVar47)) >> 0x10);
      *(undefined2 *)(iVar47 + 0x12) = uVar32;
      *(undefined2 *)(iVar47 + 0xe) = uVar32;
    }
    uStack_4._0_1_ = 0;
    uStack_4._1_1_ = 0x10;
    auStack_6[0] = 0xe5;
    auStack_6[1] = 0xda;
    iVar47 = strchr();
    auStack_10[0] = (char)puVar41;
    auStack_10[1] = (undefined1)((uint)puVar41 >> 8);
    auStack_12 = (undefined1  [2])iVar47;
    if (iVar47 != 0 || puVar41 != (undefined1 *)0x0) {
      auStack_12 = (undefined1  [2])(iVar47 + 1);
      uStack_2._0_1_ = 0;
      uStack_2._1_1_ = 0;
      auStack_6[0] = SUB21(auStack_12,0);
      auStack_6[1] = (char)((uint)auStack_12 >> 8);
      uStack_4._0_1_ = auStack_10[0];
      uStack_4._1_1_ = auStack_10[1];
      auStack_8[0] = 0;
      auStack_8[1] = 0x10;
      auStack_a[0] = 6;
      auStack_a[1] = 0xdb;
      uVar32 = strtol();
      *(undefined2 *)(CONCAT11(auStack_a[1],auStack_a[0]) + 0x10) = uVar32;
    }
    iVar47 = CONCAT11(auStack_a[1],auStack_a[0]);
    uVar32 = (undefined2)(CONCAT13(auStack_8[1],CONCAT12(auStack_8[0],iVar47)) >> 0x10);
    uStack_2._0_1_ = (undefined1)*(undefined2 *)(iVar47 + 0xe);
    uStack_2._1_1_ = (undefined1)((uint)*(undefined2 *)(iVar47 + 0xe) >> 8);
    uStack_4._0_1_ = (undefined1)*(undefined2 *)(iVar47 + 0xc);
    uStack_4._1_1_ = (undefined1)((uint)*(undefined2 *)(iVar47 + 0xc) >> 8);
    auStack_6[0] = (byte)*param_3;
    auStack_6[1] = (char)((uint)*param_3 >> 8);
    auStack_8[0] = 0;
    auStack_8[1] = 0x10;
    auStack_a[0] = 0x2e;
    auStack_a[1] = 0xdb;
    iVar47 = func_0x00018b43();
    if (iVar47 == 0) {
      uStack_2._0_1_ = 0x40;
      uStack_2._1_1_ = 0xdb;
      func_0x00018baf();
      uStack_2._0_1_ = 0xb8;
      uStack_2._1_1_ = 0x18;
      uStack_4._0_1_ = 0x4f;
      uStack_4._1_1_ = 0xd9;
      fn_0000_3b83();
      *(undefined4 *)(param_3 + 7) = 0;
      return (uint *)0x0;
    }
    iVar47 = CONCAT11(auStack_a[1],auStack_a[0]);
    uVar32 = (undefined2)(CONCAT13(auStack_8[1],CONCAT12(auStack_8[0],iVar47)) >> 0x10);
    uStack_2._0_1_ = (undefined1)*(undefined2 *)(iVar47 + 0xe);
    uStack_2._1_1_ = (undefined1)((uint)*(undefined2 *)(iVar47 + 0xe) >> 8);
    uStack_4._0_1_ = (undefined1)*(undefined2 *)(iVar47 + 0xc);
    uStack_4._1_1_ = (undefined1)((uint)*(undefined2 *)(iVar47 + 0xc) >> 8);
    auStack_6[0] = (byte)*param_3;
    auStack_6[1] = (char)((uint)*param_3 >> 8);
    auStack_8[0] = 0xb0;
    auStack_8[1] = 0x18;
    uVar32 = 0x18b0;
    auStack_a[0] = 0x62;
    auStack_a[1] = 0xdb;
    func_0x00018b39();
    auStack_6[0] = (byte)*param_3;
    auStack_6[1] = (char)((uint)*param_3 >> 8);
  case (undefined1 *)0x6:
    auStack_8[0] = (byte)uVar32;
    auStack_8[1] = (char)((uint)uVar32 >> 8);
    auStack_a[0] = 0x70;
    auStack_a[1] = 0xdb;
    iVar47 = fn_0000_18b6();
    if (iVar47 != 0) {
      auStack_6[0] = 0;
      auStack_6[1] = 0;
      auStack_a[0] = (char)iVar47;
      uVar4 = auStack_a[0];
      auStack_a[1] = (char)((uint)iVar47 >> 8);
      uVar6 = auStack_a[1];
      auStack_8[0] = (byte)(iVar47 >> 0xf);
      auStack_c[0] = 0x60;
      auStack_c[1] = 0x11;
      auStack_e[0] = 0x84;
      auStack_e[1] = 0xdb;
      auStack_8[1] = auStack_8[0];
      uVar32 = func_0x00013987();
      param_3[10] = puVar41;
      param_3[9] = uVar32;
      uVar43 = *(undefined4 *)(param_3 + 9);
      auStack_a[0] = (char)uVar43;
      auStack_a[1] = (char)((ulong)uVar43 >> 8);
      auStack_8[0] = (byte)((ulong)uVar43 >> 0x10);
      auStack_8[1] = (char)((ulong)uVar43 >> 0x18);
      auStack_c[0] = (byte)*param_3;
      auStack_c[1] = (char)((uint)*param_3 >> 8);
      auStack_e[0] = 0x98;
      auStack_e[1] = 0x13;
      auStack_10[0] = 0xa0;
      auStack_10[1] = 0xdb;
      auStack_6[0] = uVar4;
      auStack_6[1] = uVar6;
      fn_0000_18bb();
    }
    *(undefined1 **)(param_3 + 1) = (undefined1 *)CONCAT22(param_2,param_1);
    *(undefined1 *)(param_3 + 3) = 0;
    if (param_5 != 0) {
      auStack_6[0] = 4;
      auStack_6[1] = 0;
      auStack_e = (undefined1  [2])(param_3 + 3);
      auStack_10[0] = 0x60;
      auStack_10[1] = 0x11;
      auStack_12[0] = 0xd0;
      auStack_12[1] = 0xdb;
      auStack_c[0] = uVar14;
      auStack_c[1] = uVar17;
      auStack_a[0] = uVar23;
      auStack_a[1] = uVar25;
      auStack_8[0] = uVar27;
      auStack_8[1] = uVar29;
      memcpy();
    }
    return (uint *)0x1;
  case (undefined1 *)0x7:
    *(undefined1 *)(iVar45 + unaff_SI) = (char)iVar45;
    break;
  case (undefined1 *)0x8:
    iVar47 = unaff_SI + 2;
    *(char *)(unaff_DI + 3) = *(char *)(unaff_DI + 3) + cVar13;
    *(undefined4 *)0x18ca = 0;
    if (*(char *)0xad44 == '\0') {
      *(undefined4 *)0x18ca = 0;
    }
    auStack_e[0] = 0;
    auStack_e[1] = 0;
    auStack_c[0] = 0;
    auStack_c[1] = 0;
    auStack_8[1] = 0;
    auStack_6[0] = 0x50;
    uVar33 = 0x18a0;
    auStack_a[1] = 0xaa;
    auStack_8[0] = 0xd2;
    puVar44 = param_1;
    uVar32 = func_0x00018a20();
    auStack_8[1] = (char)puVar44;
    auStack_6[0] = (byte)((uint)puVar44 >> 8);
    auStack_a[0] = (char)uVar32;
    auStack_a[1] = (char)((uint)uVar32 >> 8);
    auStack_8[0] = auStack_8[1];
    auStack_8[1] = auStack_6[0];
    if ((int)puVar44 < 0) {
      auStack_a[0] = 0;
      auStack_a[1] = 0;
      auStack_8[0] = 0;
      auStack_8[1] = 0;
    }
    lVar36 = CONCAT13(auStack_c[1],CONCAT12(auStack_c[0],CONCAT11(auStack_e[1],auStack_e[0]))) +
             CONCAT13(auStack_8[1],CONCAT12(auStack_8[0],CONCAT11(auStack_a[1],auStack_a[0])));
    uStack_16 = (undefined1)lVar36;
    uStack_15 = (undefined1)((ulong)lVar36 >> 8);
    auStack_14[0] = (undefined1)((ulong)lVar36 >> 0x10);
    auStack_14[1] = (undefined1)((ulong)lVar36 >> 0x18);
    *(undefined4 *)0x18d6 = 0x1c800;
    *(long *)0x18d2 = *(long *)0x18ca + 0xbb800;
    *(undefined4 *)0x18ce = 0x7d000;
    lVar37 = *(long *)0x18da + 0x472e8;
    auStack_12[0] = (byte)lVar37;
    auStack_12[1] = (byte)((ulong)lVar37 >> 8);
    auStack_10[0] = (char)((ulong)lVar37 >> 0x10);
    iVar34 = *(int *)0x7b + -1;
    *(long *)0x18b6 = (long)*(int *)0x3 << 4;
    if ((((lVar36 < *(long *)0x18d6 + *(long *)0x18d2 + *(long *)0x18ce) || (lVar36 < 2000000)) ||
        (CONCAT13(uStack_17,CONCAT12(uStack_18,CONCAT11(uStack_19,uStack_1a))) <
         lVar37 + *(long *)0x18b6)) || (iVar47 < 2)) {
      lVar37 = lVar37 + *(long *)0x18b6;
      auStack_a[1] = (char)lVar37;
      auStack_8[0] = (byte)((ulong)lVar37 >> 8);
      auStack_8[1] = (char)((ulong)lVar37 >> 0x10);
      auStack_6[0] = (byte)((ulong)lVar37 >> 0x18);
      auStack_12[1] = 0xae;
      auStack_10[0] = 0x19;
      auStack_14[1] = 0xa0;
      auStack_12[0] = 0x18;
      uStack_15 = 0xc2;
      auStack_14[0] = 0xd3;
      auStack_10[1] = uVar5;
      auStack_e[0] = uVar7;
      printf();
      auStack_8[1] = 0;
      auStack_6[0] = 0;
      auStack_c[1] = 0x80;
      auStack_a[0] = 0x84;
      auStack_a[1] = 0x1e;
      auStack_8[0] = 0;
      auStack_10[1] = 0x84;
      auStack_e[0] = 0x1e;
      auStack_e[1] = 0;
      auStack_c[0] = 0;
      auStack_14[1] = 0xda;
      auStack_12[0] = 0x19;
      uStack_15 = 0;
      auStack_14[0] = 0x10;
      uStack_17 = 0xda;
      uStack_16 = 0xd3;
      auStack_12[1] = uVar5;
      auStack_10[0] = uVar7;
      printf();
      auStack_8[1] = 1;
      auStack_6[0] = 0;
      auStack_a[1] = 0;
      auStack_8[0] = 0x10;
      uVar33 = 0x1000;
      auStack_c[1] = 0xe4;
      auStack_a[0] = 0xd3;
      exit();
    }
    else if (*(long *)0x18ca != 0) {
      lVar37 = *(long *)0x18d6 + *(long *)0x18d2 + *(long *)0x18ce;
      while (lVar37 + 0x19000 <= lVar36) {
        *(long *)0x18d2 = *(long *)0x18d2 + 0xc800;
        *(long *)0x18ce = *(long *)0x18ce + 0xc800;
        if (0x1f3fff < *(long *)0x18d2 + -0xddec8) break;
        lVar37 = *(long *)0x18d6 + *(long *)0x18d2 + *(long *)0x18ce;
      }
    }
    lVar36 = *(long *)0x18d2;
    *(long *)0x18ca = lVar36 + -0xddec8;
    *(long *)0x4b94 = (lVar36 + -0xddec8) - *(long *)0x18c2;
    lVar36 = *(long *)0x18d6 / 0x10;
    iVar45 = (int)(*(long *)0x18d6 % 0x10);
    auStack_8[1] = (char)lVar36;
    auStack_6[0] = (byte)((ulong)lVar36 >> 8);
    auStack_c[1] = 0;
    auStack_a[0] = 0;
    auStack_a[1] = 0;
    auStack_8[0] = 0;
    auStack_e[1] = (char)uVar33;
    auStack_c[0] = (byte)((uint)uVar33 >> 8);
    auStack_10[1] = 0x14;
    auStack_e[0] = 0xd4;
    fn_0000_20e6();
    uVar43 = *(undefined4 *)0x18d6;
    auStack_a[1] = (char)uVar43;
    auStack_8[0] = (byte)((ulong)uVar43 >> 8);
    auStack_8[1] = (char)((ulong)uVar43 >> 0x10);
    auStack_6[0] = (byte)((ulong)uVar43 >> 0x18);
    auStack_e[1] = 0;
    auStack_c[0] = 0;
    auStack_c[1] = 0;
    auStack_a[0] = 0;
    auStack_10[1] = 0x80;
    auStack_e[0] = 0x11;
    auStack_12[1] = 0x24;
    auStack_10[0] = 0xd4;
    func_0x000122b0();
    if (CONCAT13(auStack_c[1],CONCAT12(auStack_c[0],CONCAT11(auStack_e[1],auStack_e[0]))) == 0) {
      auStack_a[1] = 0;
      auStack_8[0] = 0x30;
      auStack_8[1] = 0xf2;
      auStack_6[0] = 0;
      uVar43 = *(undefined4 *)0x18d2;
      auStack_e[1] = (char)uVar43;
      auStack_c[0] = (byte)((ulong)uVar43 >> 8);
      auStack_c[1] = (char)((ulong)uVar43 >> 0x10);
      auStack_a[0] = (char)((ulong)uVar43 >> 0x18);
      auStack_10[1] = 0x80;
      auStack_e[0] = 0x11;
      auStack_12[1] = 0x7b;
      auStack_10[0] = 0xd4;
      func_0x00018a25();
      auStack_8[1] = 0x40;
      auStack_6[0] = 0;
      auStack_a[1] = 0xa0;
      auStack_8[0] = 0x18;
      auStack_c[1] = 0x85;
      auStack_a[0] = 0xd4;
      uVar32 = fn_0000_3d34();
      auStack_a[1] = (char)iVar45;
      auStack_8[0] = (byte)((uint)iVar45 >> 8);
      *(undefined4 *)0x18d2 = CONCAT13(auStack_8[0],CONCAT12(auStack_a[1],uVar32));
      auStack_8[1] = 0x42;
      auStack_6[0] = 0;
      auStack_a[1] = 0x98;
      auStack_8[0] = 0x13;
      auStack_c[1] = 0x95;
      auStack_a[0] = 0xd4;
      uVar32 = fn_0000_3d34();
      auStack_a[1] = (char)iVar45;
      auStack_8[0] = (byte)((uint)iVar45 >> 8);
      *(undefined4 *)0x18ce = CONCAT13(auStack_8[0],CONCAT12(auStack_a[1],uVar32));
      *(undefined2 *)0x4b92 = 0x40;
    }
    else {
      auStack_a[1] = 0;
      auStack_8[0] = 0x30;
      auStack_8[1] = 0xf2;
      auStack_6[0] = 0;
      uVar43 = *(undefined4 *)0x18d2;
      auStack_e[1] = (char)uVar43;
      auStack_c[0] = (byte)((ulong)uVar43 >> 8);
      auStack_c[1] = (char)((ulong)uVar43 >> 0x10);
      auStack_a[0] = (char)((ulong)uVar43 >> 0x18);
      auStack_10[1] = 0x80;
      auStack_e[0] = 0x11;
      auStack_12[1] = 0x3e;
      auStack_10[0] = 0xd4;
      func_0x0001127a();
      auStack_8[1] = 0x80;
      auStack_6[0] = 0;
      auStack_a[1] = 0x20;
      auStack_8[0] = 0x11;
      auStack_c[1] = 0x49;
      auStack_a[0] = 0xd4;
      uVar32 = fn_0000_3d34();
      auStack_a[1] = (char)iVar45;
      auStack_8[0] = (byte)((uint)iVar45 >> 8);
      *(undefined4 *)0x18d2 = CONCAT13(auStack_8[0],CONCAT12(auStack_a[1],uVar32));
      auStack_8[1] = 0x82;
      auStack_6[0] = 0;
      auStack_a[1] = 0x98;
      auStack_8[0] = 0x13;
      auStack_c[1] = 0x5a;
      auStack_a[0] = 0xd4;
      uVar32 = fn_0000_3d34();
      auStack_a[1] = (char)iVar45;
      auStack_8[0] = (byte)((uint)iVar45 >> 8);
      *(undefined4 *)0x18ce = CONCAT13(auStack_8[0],CONCAT12(auStack_a[1],uVar32));
      *(undefined2 *)0x4b92 = 0x80;
    }
    auStack_a[1] = 6;
    auStack_8[0] = 0x1a;
    auStack_c[1] = 0x98;
    auStack_a[0] = 0x13;
    auStack_e[1] = 0xad;
    auStack_c[0] = 0xd4;
    auStack_8[1] = uVar5;
    auStack_6[0] = uVar7;
    fn_080e_0345();
    auStack_8[1] = 1;
    auStack_6[0] = 0;
    auStack_a[1] = 0x40;
    auStack_8[0] = 0x18;
    auStack_c[1] = 0xb7;
    auStack_a[0] = 0xd4;
    fn_080e_034a();
    iVar38 = CONCAT11(auStack_6[0],auStack_8[1]);
    auStack_a[1] = 0xc;
    auStack_8[0] = 0x1a;
    auStack_c[1] = 0x40;
    auStack_a[0] = 0x18;
    auStack_e[1] = 0xc1;
    auStack_c[0] = 0xd4;
    auStack_8[1] = uVar5;
    auStack_6[0] = uVar7;
    func_0x00018420();
    auStack_a[1] = 0x19;
    auStack_8[0] = 0x1a;
    auStack_c[1] = 0x40;
    auStack_a[0] = 0x18;
    auStack_e[1] = 0xcd;
    auStack_c[0] = 0xd4;
    auStack_8[1] = uVar5;
    auStack_6[0] = uVar7;
    func_0x00018caa();
    auStack_a[1] = 0x25;
    auStack_8[0] = 0x1a;
    auStack_c[1] = 200;
    auStack_a[0] = 0x18;
    auStack_e[1] = 0xd9;
    auStack_c[0] = 0xd4;
    auStack_8[1] = uVar5;
    auStack_6[0] = uVar7;
    func_0x00018caa();
    auStack_8[1] = 1;
    auStack_6[0] = 0;
    lVar36 = CONCAT13(auStack_10[1],CONCAT12(auStack_10[0],CONCAT11(auStack_12[1],auStack_12[0]))) +
             -0x400;
    auStack_c[1] = (char)lVar36;
    auStack_a[0] = (char)((ulong)lVar36 >> 8);
    auStack_a[1] = (char)((ulong)lVar36 >> 0x10);
    auStack_8[0] = (byte)((ulong)lVar36 >> 0x18);
    auStack_10[1] = 0x31;
    auStack_e[0] = 0x1a;
    auStack_12[1] = 200;
    auStack_10[0] = 0x18;
    uVar32 = 0x17b8;
    auStack_14[1] = 0xf3;
    auStack_12[0] = 0xd4;
    auStack_e[1] = uVar5;
    auStack_c[0] = uVar7;
    iVar35 = fn_070c_0ae0();
    if (iVar35 != 0) {
      return (uint *)0x1;
    }
    if (*(char *)0xad45 == '\0') {
      auStack_8[1] = 0;
      auStack_6[0] = 0x30;
      auStack_a[1] = 0xb8;
      auStack_8[0] = 0x17;
      uVar32 = 0x13f8;
      auStack_c[1] = 0x11;
      auStack_a[0] = 0xd5;
      func_0x0001443a();
      iVar38 = CONCAT11(auStack_6[0],auStack_8[1]);
    }
    *(undefined2 *)0x362e = 3;
    puVar31 = (uint *)(*(byte *)0xad41 - 7);
    if (puVar31 < (uint *)0x6) {
      iVar35 = (int)puVar31 * 2;
      bVar30 = (byte)iVar35;
      uVar32 = 0x5000;
      switch(puVar31) {
      case (uint *)0x0:
        auStack_8[1] = 0;
        auStack_6[0] = 0x50;
        auStack_a[1] = 0x7d;
        auStack_8[0] = 0xc;
        uVar32 = fn_0000_1e8f();
        uStack_4._0_1_ = (undefined1)uVar32;
        uStack_4._1_1_ = (undefined1)((uint)uVar32 >> 8);
        auStack_8[1] = (char)*(undefined2 *)0x7fdf;
        auStack_6[0] = (byte)((uint)*(undefined2 *)0x7fdf >> 8);
        auStack_a[1] = (char)*(undefined2 *)0x7fd0;
        auStack_8[0] = (byte)((uint)*(undefined2 *)0x7fd0 >> 8);
        auStack_c[1] = 0xe8;
        auStack_a[0] = 0x11;
        auStack_e[1] = 0x8e;
        auStack_c[0] = 0xc;
        iVar47 = func_0x00010603();
        pbVar1 = (byte *)(iVar47 * 10 + -0x7df4);
        *pbVar1 = *pbVar1 & 0xef;
        auStack_a[1] = 0;
        auStack_8[0] = 0;
        auStack_8[1] = 2;
        auStack_6[0] = 0;
        auStack_e[1] = 0x40;
        auStack_c[0] = 1;
        auStack_c[1] = 200;
        auStack_a[0] = 0;
        auStack_12[1] = 0;
        auStack_10[0] = 0;
        auStack_10[1] = 0;
        auStack_e[0] = 0;
        uStack_15 = 0;
        auStack_14[0] = 0;
        auStack_14[1] = 0;
        auStack_12[0] = 0;
        uStack_17 = 0x48;
        uStack_16 = 0x10;
        uStack_19 = 0xb6;
        uStack_18 = 0xc;
        fn_0000_1917();
        auStack_8[1] = 2;
        auStack_6[0] = 0;
        auStack_a[1] = 0x90;
        auStack_8[0] = 0x11;
        auStack_c[1] = 0xc0;
        auStack_a[0] = 0xc;
        fn_0000_19d9();
        auStack_a[1] = 0;
        auStack_8[0] = 0xfa;
        auStack_8[1] = 0;
        auStack_6[0] = 0;
        uVar43 = *(undefined4 *)0x4d5a;
        auStack_e[1] = (char)uVar43;
        auStack_c[0] = (byte)((ulong)uVar43 >> 8);
        auStack_c[1] = (char)((ulong)uVar43 >> 0x10);
        auStack_a[0] = (char)((ulong)uVar43 >> 0x18);
        auStack_10[1] = 2;
        auStack_e[0] = 0;
        auStack_12[1] = 0x40;
        auStack_10[0] = 0x10;
        auStack_14[1] = 0xd3;
        auStack_12[0] = 0xc;
        uVar32 = fn_0000_3e1d();
        auStack_10[1] = (undefined1)iVar45;
        auStack_e[0] = (byte)((uint)iVar45 >> 8);
        auStack_12[1] = (byte)uVar32;
        auStack_10[0] = (char)((uint)uVar32 >> 8);
        auStack_14[1] = 0xe0;
        auStack_12[0] = 0x13;
        uStack_15 = 0xdb;
        auStack_14[0] = 0xc;
        fn_0000_445b();
        auStack_a[1] = 0;
        auStack_8[0] = 0xfa;
        auStack_8[1] = 0;
        auStack_6[0] = 0;
        uVar43 = *(undefined4 *)0x4d56;
        auStack_e[1] = (char)uVar43;
        auStack_c[0] = (byte)((ulong)uVar43 >> 8);
        auStack_c[1] = (char)((ulong)uVar43 >> 0x10);
        auStack_a[0] = (char)((ulong)uVar43 >> 0x18);
        auStack_10[1] = 5;
        auStack_e[0] = 0;
        auStack_12[1] = 0x20;
        auStack_10[0] = 0x14;
        auStack_14[1] = 0xf0;
        auStack_12[0] = 0xc;
        uVar32 = fn_0000_3e03();
        auStack_10[1] = (undefined1)iVar45;
        auStack_e[0] = (byte)((uint)iVar45 >> 8);
        auStack_12[1] = (byte)uVar32;
        auStack_10[0] = (char)((uint)uVar32 >> 8);
        auStack_14[1] = 0xe0;
        auStack_12[0] = 0x13;
        uStack_15 = 0xf8;
        auStack_14[0] = 0xc;
        fn_0000_445b();
        auStack_a[1] = 0;
        auStack_8[0] = 0;
        auStack_8[1] = 0;
        auStack_6[0] = 0;
        auStack_c[1] = 1;
        auStack_a[0] = 0;
        uVar43 = *(undefined4 *)0x369f;
        auStack_10[1] = (undefined1)uVar43;
        auStack_e[0] = (byte)((ulong)uVar43 >> 8);
        auStack_e[1] = (char)((ulong)uVar43 >> 0x10);
        auStack_c[0] = (byte)((ulong)uVar43 >> 0x18);
        auStack_12[1] = 5;
        auStack_10[0] = 0;
        auStack_14[1] = 0x20;
        auStack_12[0] = 0x14;
        uStack_15 = 0xc;
        auStack_14[0] = 0xd;
        uVar32 = fn_0000_3e03();
        auStack_12[1] = (byte)iVar45;
        auStack_10[0] = (char)((uint)iVar45 >> 8);
        auStack_14[1] = (undefined1)uVar32;
        auStack_12[0] = (byte)((uint)uVar32 >> 8);
        uStack_17 = 0xf2;
        uStack_16 = 0xb;
        uStack_19 = 0xe0;
        uStack_18 = 0x13;
        uVar32 = 0x1888;
        uStack_1b = 0x18;
        uStack_1a = 0xd;
        uStack_15 = uVar5;
        auStack_14[0] = uVar7;
        iVar47 = fn_0845_0450();
        auStack_6[1] = (char)((uint)iVar45 >> 8);
        if (iVar47 == 0 && iVar45 == 0) {
          auStack_a[1] = 0xfe;
          auStack_8[0] = 0xb;
          auStack_c[1] = 0x88;
          auStack_a[0] = 0x18;
          uVar32 = 0x1668;
          auStack_e[1] = 0x2e;
          auStack_c[0] = 0xd;
          auStack_8[1] = uVar5;
          auStack_6[0] = uVar7;
          fn_0638_037f();
        }
        auStack_a[1] = 0xa6;
        auStack_8[0] = 0;
        auStack_8[1] = 0;
        auStack_6[0] = 0;
        auStack_c[1] = (char)uVar32;
        auStack_a[0] = (char)((uint)uVar32 >> 8);
        auStack_e[1] = 0x3c;
        auStack_c[0] = 0xd;
        func_0x00010581();
        auStack_a[1] = 0x14;
        auStack_8[0] = 0;
        auStack_8[1] = 1;
        auStack_6[0] = 0;
        uStack_15 = 0;
        auStack_14[0] = 0;
        auStack_14[1] = 0;
        auStack_12[0] = 0;
        uStack_19 = 0x3a;
        uStack_18 = 0;
        uStack_17 = 0;
        uStack_16 = 0;
        uStack_1b = 1;
        uStack_1a = 0;
        uStack_1d = (undefined1)*(undefined2 *)0x102;
        uStack_1c = (undefined1)((uint)*(undefined2 *)0x102 >> 8);
        uStack_1f = 0;
        cStack_1e = '\0';
        uStack_21 = 0;
        uStack_20 = auStack_6[1];
        uStack_24._1_1_ = 0;
        uStack_22 = 1;
        uStack_25 = 0x18;
        uStack_24._0_1_ = 0x10;
        uStack_27 = 0x67;
        uStack_26 = 0xd;
        auStack_12[1] = bVar39;
        auStack_10[0] = cVar13;
        auStack_10[1] = uVar16;
        auStack_e[0] = uVar20;
        auStack_e[1] = uVar9;
        auStack_c[0] = uVar11;
        auStack_c[1] = uVar14;
        auStack_a[0] = uVar17;
        func_0x0001115e();
        auStack_a[1] = auStack_8[0];
        auStack_8[0] = auStack_8[1];
        auStack_8[1] = auStack_6[0];
        auStack_6[0] = auStack_6[1];
        auStack_c[1] = 0x40;
        auStack_a[0] = 0x10;
        auStack_e[1] = 0x73;
        auStack_c[0] = 0xd;
        func_0x000188a5();
        auStack_a[1] = 0;
        auStack_8[0] = 0xfa;
        auStack_8[1] = 0;
        auStack_6[0] = 0;
        auStack_c[1] = 5;
        auStack_a[0] = 0;
        auStack_e[1] = 0x88;
        auStack_c[0] = 0x18;
        auStack_10[1] = 0x83;
        auStack_e[0] = 0xd;
        uVar32 = fn_0000_3e03();
        auStack_c[1] = (char)iVar45;
        auStack_a[0] = (char)((uint)iVar45 >> 8);
        auStack_e[1] = (char)uVar32;
        auStack_c[0] = (byte)((uint)uVar32 >> 8);
        uVar43 = *(undefined4 *)0x4d56;
        auStack_12[1] = (byte)uVar43;
        auStack_10[0] = (char)((ulong)uVar43 >> 8);
        auStack_10[1] = (undefined1)((ulong)uVar43 >> 0x10);
        auStack_e[0] = (byte)((ulong)uVar43 >> 0x18);
        auStack_14[1] = 0xe0;
        auStack_12[0] = 0x13;
        uStack_15 = 0x90;
        auStack_14[0] = 0xd;
        fn_0000_445b();
        auStack_8[1] = (undefined1)uStack_4;
        auStack_6[0] = uStack_4._1_1_;
        auStack_a[1] = 0x20;
        auStack_8[0] = 0x14;
        auStack_c[1] = 0x9b;
        auStack_a[0] = 0xd;
        fn_0000_1e8f();
        auStack_a[1] = 0xe8;
        auStack_8[0] = 0x11;
        auStack_c[1] = 0xa1;
        auStack_a[0] = 0xd;
        fn_0000_0caa();
        auStack_a[1] = 0;
        auStack_8[0] = 0;
        auStack_c[1] = 0x40;
        auStack_a[0] = 0x10;
        auStack_e[1] = 0xa8;
        auStack_c[0] = 0xd;
        fn_0000_19d9();
        auStack_a[1] = 0x40;
        auStack_8[0] = 0x10;
        auStack_c[1] = 0xae;
        auStack_a[0] = 0xd;
        puVar31 = (uint *)func_0x0001217e();
        return puVar31;
      case (uint *)0x1:
        unaff_DS = CONCAT11((undefined1)uStack_4,auStack_6[1]);
        break;
      case (uint *)0x2:
        uVar40 = *(uint *)(CONCAT11(in_stack_00000000,uStack_2._1_1_) * 10 + -0x7df9);
        while ((uVar40 & 0x8000) != 0) {
          uVar40 = uVar40 & 0x7fff;
          iVar34 = uVar40 * 0x2e;
          puVar31 = (uint *)(iVar34 + 0x15fa);
          auStack_a[1] = 0xf8;
          auStack_8[0] = 0x15;
          uVar33 = (undefined2)(CONCAT13(0x15,CONCAT12(0xf8,puVar31)) >> 0x10);
          unique0x10001f7a = puVar31;
          if (*(char *)(iVar34 + 0x160e) == '\v') {
            auStack_14[1] = (undefined1)uVar32;
            auStack_12[0] = (byte)((uint)uVar32 >> 8);
            unique0x10001fcb = (undefined1 *)puVar46;
            unique0x10001fcd = iVar47;
            unique0x10001fcf = puVar31;
            if ((*(uint *)(iVar34 + 0x1613) & 0x20) == 0) {
              auStack_10[1] = 0xf8;
              auStack_e[0] = 0x15;
              uVar32 = 0x1020;
              uStack_15 = 0x56;
              auStack_14[0] = 0xc;
              puVar31 = (uint *)func_0x000107fa();
              puVar46 = (undefined2 *)stack0xfff9;
              iVar47 = stack0xfff3;
            }
            else {
              *(undefined1 *)(iVar34 + 0x160e) = 0;
              auStack_10[1] = 0xf8;
              auStack_e[0] = 0x15;
              uStack_15 = 0xfa;
              auStack_14[0] = 0xb;
              fn_0000_08b4();
              if (*(char *)0x7fe5 != '\x1d') {
                auStack_10[1] = 0xe;
                auStack_e[0] = 0;
                auStack_12[1] = auStack_a[1];
                auStack_10[0] = auStack_8[0];
                uStack_15 = 0x88;
                auStack_14[0] = 0x10;
                uStack_17 = 0xf;
                uStack_16 = 0xc;
                unique0x10001fba = stack0xfff5;
                func_0x00011215();
              }
              auStack_12[1] = 0;
              auStack_10[0] = 0;
              auStack_10[1] = 0;
              auStack_e[0] = 0;
              auStack_14[1] = (undefined1)uVar40;
              auStack_12[0] = (byte)(uVar40 >> 8);
              uStack_19 = 4;
              uStack_18 = 4;
              uStack_17 = 0xff;
              uStack_16 = 0xff;
              uStack_1b = 0x88;
              uStack_1a = 0x10;
              uStack_1d = 0x22;
              uStack_1c = 0xc;
              auStack_14[0] = auStack_12[0];
              uStack_15 = auStack_14[1];
              auStack_12[0] = auStack_14[0];
              func_0x00011743();
              auStack_10[1] = (undefined1)*(undefined2 *)((int)stack0xfff5 + 5);
              auStack_e[0] = (byte)((uint)*(undefined2 *)((int)stack0xfff5 + 5) >> 8);
              auStack_12[1] = 0x40;
              auStack_10[0] = 0x10;
              uVar32 = 0x1040;
              auStack_14[1] = 0x31;
              auStack_12[0] = 0xc;
              puVar31 = (uint *)fn_0000_086c();
              puVar46 = (undefined2 *)stack0xfff9;
              iVar47 = stack0xfff3;
              if ((char)stack0xfff5[10] == '\x0e') {
                auStack_12[1] = 0;
                auStack_10[0] = 0;
                auStack_10[1] = 0;
                auStack_e[0] = 0;
                auStack_14[1] = auStack_a[1];
                auStack_12[0] = auStack_8[0];
                uStack_17 = 0x40;
                uStack_16 = 0x10;
                uVar32 = 0x1088;
                uStack_19 = 0x48;
                uStack_18 = 0xc;
                _uStack_15 = stack0xfff5;
                puVar31 = (uint *)func_0x00010fc2();
                puVar46 = (undefined2 *)stack0xfff9;
                iVar47 = stack0xfff3;
              }
            }
          }
          uVar40 = *unique0x10001780;
        }
        return puVar31;
      case (uint *)0x3:
        puVar3 = (undefined2 *)(iVar35 + unaff_DI + -0x42);
        auStack_6[0] = 0;
        auStack_6[1] = 0x50;
        auStack_8[0] = 0x9e;
        auStack_8[1] = 0x7f;
        (*(code *)*puVar3)();
        iVar47 = (iVar47 - unaff_DI) - (uint)CARRY1(bVar30,(byte)((uint)iVar38 >> 8));
        *(undefined2 *)(&stack0x0000 + iVar47 + -2) = 0x7400;
        bVar48 = SBORROW2(unaff_DI,1);
        uVar40 = unaff_DI - 1U;
        do {
          if (bVar48 == (int)uVar40 < 0) {
            auStack_8[1] = 2;
            iVar34 = iVar47;
            goto LAB_57ee_00d3;
          }
          do {
            auStack_8[1] = 3;
            iVar34 = iVar47;
LAB_57ee_00d3:
            auStack_6[0] = 0;
            auStack_a[1] = (char)iVar34;
            auStack_8[0] = (byte)((uint)iVar34 >> 8);
            auStack_c[1] = (char)uVar32;
            auStack_a[0] = (char)((uint)uVar32 >> 8);
            uVar32 = 0x1048;
            auStack_e[1] = 0xb9;
            auStack_c[0] = 0x7f;
            fn_0000_0487();
            iVar47 = iVar34 + 1;
            if (0x54 < iVar47) {
              return (uint *)0x1;
            }
          } while ((unaff_DI - 1U & 2) == 0);
          bVar48 = SBORROW2(iVar47,0x4f);
          uVar40 = iVar34 - 0x4e;
        } while( true );
      case (uint *)0x4:
        if (-1 < (int)puVar31 && iVar35 != 0) {
          iVar45 = CONCAT11((undefined1)uStack_4,auStack_6[1]);
          if (iVar38 != 1 && iVar35 != 0) {
            iVar47 = CONCAT11((undefined1)uStack_4,auStack_6[1]);
            iVar45 = iVar34;
          }
          goto code_r0x00056822;
        }
        break;
      case (uint *)0x5:
        if (*(char *)0x45 == '\0') {
          auStack_8[1] = 5;
          auStack_6[0] = 0;
          auStack_a[1] = 0;
          auStack_8[0] = 0x50;
          auStack_c[1] = 0x6f;
          auStack_a[0] = 0x83;
          fn_0000_0c22();
          auStack_8[1] = 0xb0;
          auStack_6[0] = 0x10;
          auStack_a[1] = 0x75;
          auStack_8[0] = 0x83;
          fn_0000_2167();
          auStack_8[1] = (char)*(undefined2 *)0x3711;
          auStack_6[0] = (byte)((uint)*(undefined2 *)0x3711 >> 8);
          register0x00000000 = *(int *)0xad8b + *(int *)0xad91 + -2;
          register0x00000000 = (uint *)(*(int *)0xad8d + *(int *)0xad8f + -2);
          auStack_e[1] = (char)*(undefined2 *)0xad8b;
          auStack_c[0] = (byte)((uint)*(undefined2 *)0xad8b >> 8);
          auStack_10[1] = (undefined1)*(undefined2 *)0xad8d;
          auStack_e[0] = (byte)((uint)*(undefined2 *)0xad8d >> 8);
          auStack_12[1] = 8;
          auStack_10[0] = 0x12;
          auStack_14[1] = 0x9c;
          auStack_12[0] = 0x83;
          fn_0000_1c9d();
          uStack_2._1_1_ = 200;
          uStack_4._1_1_ = 0xa6;
          uStack_2._0_1_ = 0x83;
          func_0x00010cfa();
          uStack_2._1_1_ = 0xac;
          func_0x0001217e();
          *(undefined2 *)0x1f87 = 0;
          *(undefined2 *)0x1f89 = 0;
          uStack_2._1_1_ = 8;
          uStack_4._1_1_ = 0xbf;
          uStack_2._0_1_ = 0x83;
          ovr_2d5f_00f7();
        }
        else {
          auStack_a[1] = 0x1c;
          auStack_8[0] = 0;
          auStack_8[1] = 0x2d;
          auStack_6[0] = 0;
          auStack_e[1] = 0xb;
          auStack_c[0] = 0;
          auStack_c[1] = 0x7c;
          auStack_a[0] = 0;
          auStack_10[1] = 4;
          auStack_e[0] = 0;
          auStack_12[1] = 0;
          auStack_10[0] = 0x50;
          auStack_14[1] = 0x30;
          auStack_12[0] = 0x83;
          fn_0000_1f8b();
          auStack_c[1] = 0xe9;
          auStack_a[0] = 0;
          auStack_a[1] = 0x36;
          auStack_8[0] = 0;
          auStack_10[1] = 0x55;
          auStack_e[0] = 0;
          auStack_e[1] = 0x7b;
          auStack_c[0] = 0;
          auStack_12[1] = 5;
          auStack_10[0] = 0;
          auStack_14[1] = 0xf8;
          auStack_12[0] = 0x11;
          uStack_15 = 0x46;
          auStack_14[0] = 0x83;
          fn_0000_1f8b();
          *(undefined2 *)0x1f85 = 0xfc;
          *(undefined2 *)0x1f95 = 0xfc;
          *(undefined2 *)0x1f87 = 0;
          *(undefined2 *)0x1f89 = 0;
          *(uint *)0x7fd6 = *(uint *)0x7fd6 & 0xfffd;
        }
        uRam00015fc6 = 0;
        return (uint *)0x15f8;
      }
      unaff_DI = *(int *)(iVar35 + 0x20);
      uStack_4._0_1_ = (undefined1)*(undefined2 *)(iVar35 + 0x22);
      uStack_4._1_1_ = (undefined1)((uint)*(undefined2 *)(iVar35 + 0x22) >> 8);
      auStack_6[0] = (byte)*(undefined2 *)(iVar35 + 0x24);
      auStack_6[1] = (char)((uint)*(undefined2 *)(iVar35 + 0x24) >> 8);
      puVar31 = (uint *)(*(int *)(*(int *)(iVar35 + 0x1c) * 0x10 + 0x1f3b) << 3);
      iVar45 = CONCAT11((undefined1)uStack_4,auStack_6[1]);
code_r0x00056822:
      uStack_4._0_1_ = (undefined1)((uint)iVar45 >> 8);
      auStack_6[1] = (char)iVar45;
      iVar47 = iVar47 + (int)puVar31;
      iVar34 = unaff_DI + *(int *)(*(int *)(param_1 + 0x1c) * 0x10 + 0x1f3d);
      if (*(int *)0x3649 == 0) {
        register0x00000000 = (undefined1 *)(iVar34 + CONCAT11(auStack_6[1],auStack_6[0]));
        register0x00000000 = iVar47 + CONCAT11(uStack_4._1_1_,(undefined1)uStack_4);
        auStack_10[1] = 0;
        auStack_e[0] = 0x50;
        uVar32 = 0x1208;
        auStack_12[1] = 0x4c;
        auStack_10[0] = 0x68;
        unique0x10001fa6 = iVar45;
        unique0x10001fa8 = (uint *)iVar34;
        unique0x10001faa = iVar47;
        fn_0000_2191();
        iVar45 = stack0xfffb;
      }
      uStack_4._0_1_ = (undefined1)((uint)iVar45 >> 8);
      auStack_6[1] = (char)iVar45;
      register0x00000000 = iVar34 + CONCAT11(auStack_6[1],uVar11) + -1;
      register0x00000000 = (uint *)(iVar47 + CONCAT11(uStack_4._1_1_,(undefined1)uStack_4) + -1);
      auStack_12[1] = (byte)uVar32;
      auStack_10[0] = (char)((uint)uVar32 >> 8);
      auStack_14[1] = 0x67;
      auStack_12[0] = 0x68;
      auStack_8[1] = uVar9;
      auStack_6[0] = uVar11;
      unique0x10001f96 = iVar45;
      unique0x10001fb4 = iVar34;
      unique0x10001fb6 = iVar47;
      puVar31 = (uint *)fn_0000_1c9d();
      if (*(int *)0x3649 == 0) {
        uStack_2._1_1_ = 0x76;
        puVar31 = (uint *)fn_0000_226c();
      }
      return puVar31;
    }
    auStack_8[1] = 0x27;
    auStack_6[0] = 0;
    uVar43 = *(undefined4 *)0x4b8e;
    auStack_c[1] = (char)uVar43;
    auStack_a[0] = (char)((ulong)uVar43 >> 8);
    auStack_a[1] = (char)((ulong)uVar43 >> 0x10);
    auStack_8[0] = (byte)((ulong)uVar43 >> 0x18);
    auStack_e[1] = (char)uVar32;
    auStack_c[0] = (byte)((uint)uVar32 >> 8);
    auStack_10[1] = 0x42;
    auStack_e[0] = 0xd5;
    uVar32 = fn_0000_3e4c();
    auStack_8[1] = (char)iVar45;
    auStack_6[0] = (byte)((uint)iVar45 >> 8);
    auStack_a[1] = (char)uVar32;
    auStack_8[0] = (byte)((uint)uVar32 >> 8);
    auStack_c[1] = 0xd0;
    auStack_a[0] = 0x13;
    auStack_e[1] = 0x4c;
    auStack_c[0] = 0xd5;
    printf();
    auStack_8[1] = 0;
    auStack_6[0] = 0x10;
    auStack_a[1] = 0x54;
    auStack_8[0] = 0xd5;
    func_0x0001440c();
    auStack_8[1] = 0x40;
    auStack_6[0] = 0x14;
    auStack_a[1] = 0x59;
    auStack_8[0] = 0xd5;
    getch();
    auStack_8[1] = 1;
    auStack_6[0] = 0;
    auStack_a[1] = 0;
    auStack_8[0] = 0x10;
    auStack_c[1] = 0x60;
    auStack_a[0] = 0xd5;
    exit();
    *(undefined4 *)0x368f = 64000;
    *(undefined4 *)0x368b = 64000;
    *(undefined4 *)0x3697 = 0xfbf4;
    *(undefined4 *)0x3693 = 0xfbf4;
    *(undefined4 *)0x369f = 0xffff;
    *(undefined4 *)0x369b = 0xffff;
    *(undefined4 *)0x36a7 = 0x9600;
    *(undefined4 *)0x36a3 = 0x9600;
    *(undefined4 *)0x36af = 0;
    *(undefined4 *)0x36ab = 0;
    if (*(char *)0xad46 == '\0') {
      *(undefined1 *)0xad44 = 0;
    }
    auStack_8[1] = *(undefined1 *)0xad44;
    auStack_6[0] = 0;
    auStack_a[1] = *(undefined1 *)0xad42;
    auStack_8[0] = 0;
    auStack_c[1] = *(undefined1 *)0xad43;
    auStack_a[0] = 0;
    auStack_e[1] = 0;
    auStack_c[0] = 0x10;
    uVar32 = 0x17d8;
    auStack_10[1] = 0xc9;
    auStack_e[0] = 0xd5;
    fn_07bc_01e0();
    if (((uint)*(byte *)0xad42 == *(uint *)0x3747) && ((uint)*(byte *)0xad43 == *(uint *)0x3745)) {
      if ((uint)*(byte *)0xad44 == *(uint *)0x3749) goto LAB_5d0d_0544;
      auStack_8[1] = 0xd8;
      auStack_6[0] = 0x17;
      uVar32 = 0x1430;
      auStack_a[1] = 0xf6;
      auStack_8[0] = 0xd5;
      iVar34 = fn_0000_430a();
      if (iVar34 != 3) goto LAB_5d0d_0544;
      auStack_8[1] = 0x29;
    }
    else {
      auStack_8[1] = 0x28;
    }
    auStack_6[0] = 0;
    uVar43 = *(undefined4 *)0x4b8e;
    auStack_c[1] = (char)uVar43;
    auStack_a[0] = (char)((ulong)uVar43 >> 8);
    auStack_a[1] = (char)((ulong)uVar43 >> 0x10);
    auStack_8[0] = (byte)((ulong)uVar43 >> 0x18);
    auStack_e[1] = (char)uVar32;
    auStack_c[0] = (byte)((uint)uVar32 >> 8);
    auStack_10[1] = 7;
    auStack_e[0] = 0xd6;
    uVar32 = fn_0000_3e4c();
    auStack_8[1] = (char)iVar45;
    auStack_6[0] = (byte)((uint)iVar45 >> 8);
    auStack_a[1] = (char)uVar32;
    auStack_8[0] = (byte)((uint)uVar32 >> 8);
    auStack_c[1] = 0xd0;
    auStack_a[0] = 0x13;
    uVar32 = 0x1000;
    auStack_e[1] = 0x11;
    auStack_c[0] = 0xd6;
    printf();
LAB_5d0d_0544:
    auStack_8[1] = 0;
    auStack_6[0] = 0;
    uVar43 = *(undefined4 *)0x18ae;
    auStack_c[1] = (char)uVar43;
    auStack_a[0] = (char)((ulong)uVar43 >> 8);
    auStack_a[1] = (char)((ulong)uVar43 >> 0x10);
    auStack_8[0] = (byte)((ulong)uVar43 >> 0x18);
    auStack_e[1] = (char)*(undefined2 *)0x362e;
    auStack_c[0] = (byte)((uint)*(undefined2 *)0x362e >> 8);
    auStack_10[1] = (undefined1)uVar32;
    auStack_e[0] = (byte)((uint)uVar32 >> 8);
    uVar32 = 0x1878;
    auStack_12[1] = 0x24;
    auStack_10[0] = 0xd6;
    iVar34 = fn_0845_0350();
    if (iVar34 != 0) {
      *(undefined2 *)0x363a = 0x1780;
      *(undefined2 *)0x3638 = 0x25;
      *(undefined2 *)0x3640 = 0x1418;
      *(undefined2 *)0x363e = 7;
      *(undefined1 *)0x2f43 = 0;
      auStack_e[1] = 0x78;
      auStack_c[0] = 0x18;
      uVar32 = 0x1708;
      auStack_10[1] = 0x52;
      auStack_e[0] = 0xd6;
      auStack_a[1] = uVar16;
      auStack_8[0] = uVar20;
      auStack_8[1] = uVar9;
      auStack_6[0] = uVar11;
      unique0x10001fac = (uint *)iVar47;
      fn_067a_0900();
    }
    auStack_8[1] = (char)uVar32;
    auStack_6[0] = (byte)((uint)uVar32 >> 8);
    auStack_a[1] = 0x5a;
    auStack_8[0] = 0xd6;
    func_0x0001440c();
    register0x00000000 = (undefined1 *)(*(char *)0xae59 + -0x41);
    auStack_a[1] = 0x40;
    auStack_8[0] = 0x14;
    auStack_c[1] = 0x67;
    auStack_a[0] = 0xd6;
    fn_0000_3dac();
    return (uint *)0x0;
  case (undefined1 *)0x9:
    bVar30 = bVar30 + (9 < (bVar30 & 0xf) | in_AF) * -6 & 0xf;
    while( true ) {
      param_1[in_CX] = bVar30;
      in_CX = in_CX + 1;
      if (0x2ff < in_CX) break;
      bVar30 = *(byte *)((int)*(undefined4 *)0x540e + in_CX) & 0x3f;
    }
    for (iVar47 = 1; iVar47 < 0x80; iVar47 = iVar47 + 1) {
      param_1[iVar47 * 3] = 0;
      uVar32 = *(undefined2 *)0x5410;
      param_1[iVar47 * 3 + 1] =
           (char)((ulong)((uint)*(byte *)(iVar47 * 3 + *(int *)0x540e + 1) +
                          (uint)*(byte *)(iVar47 * 3 + *(int *)0x540e + 2) +
                         (uint)*(byte *)(*(int *)0x540e + iVar47 * 3)) / 3);
      uVar32 = *(undefined2 *)0x5410;
      param_1[iVar47 * 3 + 2] =
           (char)((ulong)((uint)*(byte *)(iVar47 * 3 + *(int *)0x540e + 1) +
                          (uint)*(byte *)(iVar47 * 3 + *(int *)0x540e + 2) +
                         (uint)*(byte *)(*(int *)0x540e + iVar47 * 3)) / 3) << 1;
      if (0x3f < (byte)param_1[iVar47 * 3 + 2]) {
        param_1[iVar47 * 3 + 2] = 0x3f;
      }
    }
    auStack_8[0] = *(char *)0x81de;
    auStack_8[1] = (char)auStack_8[0] >> 7;
    auStack_a[0] = *(char *)0x81dc;
    auStack_a[1] = auStack_a[0] >> 7;
    auStack_14[0] = 0;
    auStack_14[1] = 0x50;
    uStack_16 = 0xd9;
    uStack_15 = 4;
    auStack_12[0] = bVar39;
    auStack_12[1] = cVar13;
    auStack_10[0] = uVar16;
    auStack_10[1] = uVar20;
    auStack_e[0] = bVar39;
    auStack_e[1] = cVar13;
    auStack_c[0] = uVar16;
    auStack_c[1] = uVar20;
    fn_0000_06c6();
    auStack_8[0] = *(char *)0x81de;
    auStack_8[1] = (char)auStack_8[0] >> 7;
    auStack_a[0] = *(char *)0x81dc;
    auStack_a[1] = auStack_a[0] >> 7;
    auStack_14[0] = 0x40;
    auStack_14[1] = 0x10;
    uStack_16 = 0xf3;
    uStack_15 = 4;
    auStack_12[0] = uVar9;
    auStack_12[1] = uVar11;
    auStack_10[0] = uVar14;
    auStack_10[1] = uVar17;
    auStack_e[0] = uVar9;
    auStack_e[1] = uVar11;
    auStack_c[0] = uVar14;
    auStack_c[1] = uVar17;
    puVar31 = (uint *)fn_0000_06c6();
    *(undefined1 *)CONCAT22(param_4,param_3) = 0;
    *(undefined1 *)((int)param_3 + 1) = 0;
    *(undefined1 *)(param_3 + 1) = 0;
    *(undefined1 *)CONCAT22(param_2,param_1) = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    return puVar31;
  case (undefined1 *)0xa:
    uVar43 = 0x6614;
    if (*(int *)0x14ba == 0) {
      unaff_SI = 0;
    }
    auStack_14[0] = uVar6;
    auStack_e[0] = uVar8;
    auStack_e[1] = uVar10;
    auStack_c[1] = uVar12;
    if (*(long *)0x14ba != 0) {
      uVar2 = *(undefined4 *)0x14ba;
      auStack_a[0] = (char)uVar2;
      auStack_a[1] = (char)((ulong)uVar2 >> 8);
      auStack_8[0] = (byte)((ulong)uVar2 >> 0x10);
      auStack_8[1] = (char)((ulong)uVar2 >> 0x18);
      auStack_c[0] = 0;
      auStack_c[1] = 0x50;
      uVar32 = 0x1498;
      auStack_e[0] = 0xf8;
      auStack_e[1] = 0xb8;
      iVar47 = fn_0000_4fbf();
      if (iVar47 == 0) {
        uVar2 = *(undefined4 *)0x14ba;
        auStack_a[0] = (char)uVar2;
        auStack_a[1] = (char)((ulong)uVar2 >> 8);
        auStack_8[0] = (byte)((ulong)uVar2 >> 0x10);
        auStack_8[1] = (char)((ulong)uVar2 >> 0x18);
        auStack_c[0] = 0x98;
        auStack_c[1] = 0x14;
        uVar32 = 0x1120;
        auStack_e[0] = 9;
        auStack_e[1] = 0xb9;
        iVar47 = func_0x00011286();
        if (iVar47 == 0) {
          auStack_8[0] = 0;
          auStack_8[1] = 0;
          uVar2 = *(undefined4 *)0x14ba;
          auStack_c[0] = (byte)uVar2;
          auStack_c[1] = (char)((ulong)uVar2 >> 8);
          auStack_a[0] = (char)((ulong)uVar2 >> 0x10);
          auStack_a[1] = (char)((ulong)uVar2 >> 0x18);
          auStack_10[0] = (char)(*(int *)0xad8f << 3);
          auStack_10[1] = (undefined1)((uint)(*(int *)0xad8f << 3) >> 8);
          auStack_12[0] = (byte)*(undefined2 *)0xad8b;
          auStack_12[1] = (byte)((uint)*(undefined2 *)0xad8b >> 8);
          auStack_14[0] = (undefined1)(*(int *)0xad8d << 3);
          auStack_14[1] = (undefined1)((uint)(*(int *)0xad8d << 3) >> 8);
          uStack_16 = 0x20;
          uStack_15 = 0x11;
          uVar32 = 0x13a8;
          uStack_18 = 0x5b;
          uStack_17 = 0xb9;
          auStack_e[1] = auStack_c[1];
          auStack_e[0] = auStack_c[0];
          auStack_c[1] = auStack_e[1];
          func_0x00013bcb();
          goto LAB_5b74_021e;
        }
      }
      auStack_8[0] = 0;
      auStack_8[1] = 0;
      uVar2 = *(undefined4 *)0x14ba;
      auStack_e[0] = (byte)uVar2;
      auStack_e[1] = (char)((ulong)uVar2 >> 8);
      auStack_c[0] = (byte)((ulong)uVar2 >> 0x10);
      auStack_c[1] = (char)((ulong)uVar2 >> 0x18);
      auStack_10[0] = 0;
      auStack_10[1] = 0;
      auStack_12[0] = (byte)uVar32;
      auStack_12[1] = (byte)((uint)uVar32 >> 8);
      auStack_14[0] = 0x23;
      auStack_14[1] = 0xb9;
      iVar47 = fn_0000_3e1d();
      auStack_12 = (undefined1  [2])(iVar47 + *(int *)0xad8b * 0x140);
      auStack_10[0] = (char)uVar43;
      auStack_10[1] = (undefined1)((ulong)uVar43 >> 8);
      auStack_14[0] = 0xe0;
      auStack_14[1] = 0x13;
      uVar32 = 0x1420;
      uStack_16 = 0x35;
      uStack_15 = 0xb9;
      fn_0000_445b();
    }
LAB_5b74_021e:
    auStack_8[0] = (byte)uVar32;
    auStack_8[1] = (char)((uint)uVar32 >> 8);
    auStack_a[0] = 99;
    auStack_a[1] = 0xb9;
    thunk_FUN_1000_0d19();
    auStack_8[0] = 0xf;
    auStack_8[1] = 0;
    auStack_a[0] = auStack_10[0];
    auStack_a[1] = auStack_10[1];
    auStack_c[0] = auStack_e[0];
    auStack_c[1] = auStack_e[1];
    auStack_e[0] = 0xf;
    auStack_e[1] = 0;
    auStack_12[0] = 0xb0;
    auStack_12[1] = 0x10;
    auStack_14[0] = 0x76;
    auStack_14[1] = 0xb9;
    fn_0000_1c01();
    uStack_2._0_1_ = 0x7f;
    uStack_2._1_1_ = 0xb9;
    fn_4b74_0000();
    uStack_2._0_1_ = 0xc0;
    uStack_2._1_1_ = 0x11;
    uStack_4._0_1_ = 0x89;
    uStack_4._1_1_ = 0xb9;
    uVar32 = fn_0845_08da();
    *(undefined2 *)0x4b86 = uVar32;
    uStack_4._0_1_ = uStack_16;
    uStack_4._1_1_ = uStack_15;
    uStack_2._0_1_ = auStack_14[0];
    uStack_2._1_1_ = auStack_14[1];
    auStack_6[0] = 0xd0;
    auStack_6[1] = 0x18;
    auStack_8[0] = 0x9c;
    auStack_8[1] = 0xb9;
    fn_0000_0d84();
    if ((unaff_DI == 2) || (unaff_DI == 0)) {
      if (*(int *)0xae57 == 0) {
        cStack_1e = *(char *)0x4b86 + '1';
        uStack_1d = 0;
        uStack_4 = &cStack_1e;
        uVar2 = *(undefined4 *)0x15fc;
        auStack_8[0] = (byte)uVar2;
        auStack_8[1] = (char)((ulong)uVar2 >> 8);
        auStack_6[0] = (byte)((ulong)uVar2 >> 0x10);
        auStack_6[1] = (char)((ulong)uVar2 >> 0x18);
        auStack_a[0] = 0xb0;
        auStack_a[1] = 0x10;
        auStack_c[0] = 0xe1;
        auStack_c[1] = 0xb9;
        uStack_2._0_1_ = uVar18;
        uStack_2._1_1_ = uVar21;
        fn_0000_0d84();
      }
      else {
        uVar2 = *(undefined4 *)0x15f8;
        uStack_4._0_1_ = (undefined1)uVar2;
        uStack_4._1_1_ = (undefined1)((ulong)uVar2 >> 8);
        uStack_2._0_1_ = (undefined1)((ulong)uVar2 >> 0x10);
        uStack_2._1_1_ = (undefined1)((ulong)uVar2 >> 0x18);
        auStack_6[0] = 0xb0;
        auStack_6[1] = 0x10;
        auStack_8[0] = 0xbd;
        auStack_8[1] = 0xb9;
        fn_0000_0d84();
      }
    }
    func_0x000145ae();
    uVar32 = (undefined2)uVar43;
    if (*(char *)0x4b76 == '\0') {
      uVar33 = 0x13f8;
      iVar47 = fn_0000_4669();
    }
    else {
      uStack_26 = 0xff;
      uStack_25 = 0xff;
      iVar47 = 0;
      while ((uVar32 = (undefined2)uVar43, CONCAT11(uStack_25,uStack_26) == -1 && (iVar47 != 0x1b)))
      {
        uStack_2._0_1_ = 0x76;
        uStack_2._1_1_ = 0x4b;
        uStack_4._0_1_ = 0xf8;
        uStack_4._1_1_ = 0x13;
        auStack_6[0] = 4;
        auStack_6[1] = 0xba;
        uVar32 = open();
        uStack_26 = (undefined1)uVar32;
        uStack_25 = (undefined1)((uint)uVar32 >> 8);
        iVar47 = fn_0000_4496();
      }
      uVar33 = 0x1000;
      uStack_2._0_1_ = 0x24;
      uStack_2._1_1_ = 0xba;
      close();
    }
    if (iVar47 == 0x1b) {
      thunk_FUN_1000_0d19();
      uStack_2._0_1_ = 0xb0;
      uStack_2._1_1_ = 0x10;
      uStack_4._0_1_ = 0x42;
      uStack_4._1_1_ = 0xba;
      fn_0000_0d84();
      fn_0000_4669();
      func_0x0001440c();
      uVar33 = 0x1000;
      uStack_2._0_1_ = 0x56;
      uStack_2._1_1_ = 0xba;
      exit();
    }
    uStack_2._0_1_ = 0x5d;
    uStack_2._1_1_ = 0xba;
    fn_4b74_0000();
    if (*(long *)0x14ba != 0) {
      uStack_2._0_1_ = (undefined1)uVar33;
      uStack_2._1_1_ = (undefined1)((uint)uVar33 >> 8);
      uVar33 = 0x1498;
      uStack_4._0_1_ = 0x70;
      uStack_4._1_1_ = 0xba;
      iVar47 = fn_0000_4fbf();
      if (iVar47 == 0) {
        uStack_2._0_1_ = 0x98;
        uStack_2._1_1_ = 0x14;
        uVar33 = 0x1120;
        uStack_4._0_1_ = 0x81;
        uStack_4._1_1_ = 0xba;
        iVar47 = func_0x00011286();
        if (iVar47 == 0) {
          uStack_2._0_1_ = (undefined1)*(undefined4 *)0x14ba;
          uStack_2._1_1_ = (undefined1)((ulong)*(undefined4 *)0x14ba >> 8);
          uStack_4._0_1_ = auStack_c[0];
          uStack_4._1_1_ = auStack_c[1];
          auStack_6[0] = (byte)(*(int *)0xad8f << 3);
          auStack_6[1] = (char)((uint)(*(int *)0xad8f << 3) >> 8);
          auStack_8[0] = (byte)*(undefined2 *)0xad8b;
          auStack_8[1] = (char)((uint)*(undefined2 *)0xad8b >> 8);
          auStack_a[0] = (char)(*(int *)0xad8d << 3);
          auStack_a[1] = (char)((uint)(*(int *)0xad8d << 3) >> 8);
          auStack_c[0] = 0x20;
          auStack_c[1] = 0x11;
          auStack_e[0] = 0xd3;
          auStack_e[1] = 0xba;
          fn_0000_3a80();
          goto LAB_5b74_0396;
        }
      }
      uStack_2._0_1_ = 0;
      uStack_2._1_1_ = 0;
      uStack_4._0_1_ = (undefined1)uVar33;
      uStack_4._1_1_ = (undefined1)((uint)uVar33 >> 8);
      auStack_6[0] = 0x96;
      auStack_6[1] = 0xba;
      iVar47 = fn_0000_3e1d();
      uStack_4 = (char *)(iVar47 + *(int *)0xad8b * 0x140);
      uStack_2._0_1_ = (undefined1)uVar32;
      uStack_2._1_1_ = (undefined1)((uint)uVar32 >> 8);
      uVar43 = *(undefined4 *)0x14ba;
      auStack_8[0] = (byte)uVar43;
      auStack_8[1] = (char)((ulong)uVar43 >> 8);
      auStack_6[0] = (byte)((ulong)uVar43 >> 0x10);
      auStack_6[1] = (char)((ulong)uVar43 >> 0x18);
      auStack_a[0] = 0xe0;
      auStack_a[1] = 0x13;
      auStack_c[0] = 0xad;
      auStack_c[1] = 0xba;
      fn_0000_445b();
    }
LAB_5b74_0396:
    uStack_2._0_1_ = 0xde;
    uStack_2._1_1_ = 0xba;
    fn_0000_0c22();
    uStack_2._0_1_ = 0xb0;
    uStack_2._1_1_ = 0x10;
    uStack_4._0_1_ = 0xe8;
    uStack_4._1_1_ = 0xba;
    func_0x00012302();
    uVar32 = 0x11e8;
    uStack_2._0_1_ = 0xf3;
    uStack_2._1_1_ = 0xba;
    fn_0000_1e8f();
    if (unaff_SI != 0) {
      uStack_2._0_1_ = (undefined1)*(undefined4 *)0x14ba;
      uStack_2._1_1_ = (undefined1)((ulong)*(undefined4 *)0x14ba >> 8);
      uStack_4._0_1_ = 0xe8;
      uStack_4._1_1_ = 0x11;
      uVar32 = 0x1398;
      auStack_6[0] = 2;
      auStack_6[1] = 0xbb;
      fn_0000_3b83();
      *(undefined4 *)0x14ba = 0;
    }
    uStack_4 = &uStack_22;
    auStack_8 = (undefined1  [2])auStack_2f9;
    auStack_a[0] = (char)uVar32;
    auStack_a[1] = (char)((uint)uVar32 >> 8);
    auStack_c[0] = 0x20;
    auStack_c[1] = 0xbb;
    auStack_6[0] = uVar18;
    auStack_6[1] = uVar21;
    uStack_2._0_1_ = uVar18;
    uStack_2._1_1_ = uVar21;
    memcpy();
    uStack_2 = auStack_326;
    uStack_4._0_1_ = 0;
    uStack_4._1_1_ = 0x10;
    auStack_6[0] = 0x2e;
    auStack_6[1] = 0xbb;
    fn_0000_219c();
    uStack_2._0_1_ = 0x36;
    uStack_2._1_1_ = 0xbb;
    func_0x0001217e();
    return (uint *)0x1;
  case (undefined1 *)0xb:
    do {
      *(uint *)(iVar45 + 0x362d) = *(uint *)(iVar45 + 0x362d) & 0xf1ff;
      do {
        uVar32 = (undefined2)uVar42;
        iVar47 = iVar47 + 1;
        auStack_6[0] = (byte)iVar47;
        if (3 < iVar47) {
          auStack_8[0] = 0;
          auStack_8[1] = 0x50;
          auStack_a[0] = 0xe9;
          auStack_a[1] = 0x15;
          auStack_6 = (undefined1  [2])iVar47;
          fn_0000_2167();
          auStack_a[0] = 0;
          auStack_a[1] = 0xfa;
          auStack_8[0] = 0;
          auStack_8[1] = 0;
          auStack_c[0] = 2;
          auStack_c[1] = 0;
          auStack_e[0] = 8;
          auStack_e[1] = 0x12;
          auStack_10[0] = 0xf6;
          auStack_10[1] = 0x15;
          uVar33 = fn_0000_3e03();
          auStack_c[0] = (byte)uVar32;
          auStack_c[1] = (char)((uint)uVar32 >> 8);
          auStack_e[0] = (byte)uVar33;
          auStack_e[1] = (char)((uint)uVar33 >> 8);
          uVar43 = *(undefined4 *)0x4d5a;
          auStack_12[0] = (byte)uVar43;
          auStack_12[1] = (byte)((ulong)uVar43 >> 8);
          auStack_10[0] = (char)((ulong)uVar43 >> 0x10);
          auStack_10[1] = (undefined1)((ulong)uVar43 >> 0x18);
          auStack_14[0] = 0xe0;
          auStack_14[1] = 0x13;
          uStack_16 = 3;
          uStack_15 = 0x16;
          fn_0000_445b();
          auStack_8[0] = 2;
          auStack_8[1] = 0;
          auStack_a[0] = 0x20;
          auStack_a[1] = 0x14;
          auStack_c[0] = 0xd;
          auStack_c[1] = 0x16;
          uVar33 = fn_0000_1e8f();
          uStack_4._0_1_ = (undefined1)uVar33;
          uStack_4._1_1_ = (undefined1)((uint)uVar33 >> 8);
          auStack_a[0] = 0xe8;
          auStack_a[1] = 0x11;
          auStack_c[0] = 0x16;
          auStack_c[1] = 0x16;
          fn_0000_0ace();
          auStack_a[0] = 0x50;
          auStack_a[1] = 0x10;
          auStack_c[0] = 0x1b;
          auStack_c[1] = 0x16;
          func_0x00010a77();
          auStack_a[0] = (undefined1)uStack_4;
          auStack_a[1] = uStack_4._1_1_;
          auStack_c[0] = 0x70;
          auStack_c[1] = 0x10;
          auStack_e[0] = 0x23;
          auStack_e[1] = 0x16;
          fn_0000_1e8f();
          auStack_e[0] = 2;
          auStack_e[1] = 0;
          auStack_c[0] = 0;
          auStack_c[1] = 0;
          auStack_10[0] = 0xe8;
          auStack_10[1] = 0x11;
          auStack_12[0] = 0x2c;
          auStack_12[1] = 0x16;
          fn_0000_1a08();
          auStack_c[0] = 0xa0;
          auStack_c[1] = 0x11;
          auStack_e[0] = 0x34;
          auStack_e[1] = 0x16;
          func_0x000173b4();
          auStack_e[0] = 0;
          auStack_e[1] = 0xfa;
          auStack_c[0] = 0;
          auStack_c[1] = 0;
          auStack_10[0] = 2;
          auStack_10[1] = 0;
          auStack_12[0] = 0x38;
          auStack_12[1] = 0x17;
          auStack_14[0] = 0x41;
          auStack_14[1] = 0x16;
          uVar33 = fn_0000_3e03();
          auStack_10[0] = (char)uVar32;
          auStack_10[1] = (undefined1)((uint)uVar32 >> 8);
          auStack_12[0] = (byte)uVar33;
          auStack_12[1] = (byte)((uint)uVar33 >> 8);
          uVar43 = *(undefined4 *)0x4d56;
          uStack_16 = (undefined1)uVar43;
          uStack_15 = (undefined1)((ulong)uVar43 >> 8);
          auStack_14[0] = (undefined1)((ulong)uVar43 >> 0x10);
          auStack_14[1] = (undefined1)((ulong)uVar43 >> 0x18);
          uStack_18 = 0xe0;
          uStack_17 = 0x13;
          uStack_1a = 0x4e;
          uStack_19 = 0x16;
          fn_0000_445b();
          auStack_c[0] = 0x20;
          auStack_c[1] = 0x14;
          auStack_e[0] = 0x56;
          auStack_e[1] = 0x16;
          func_0x0001217e();
          *(undefined2 *)0x2136 = 0xffff;
          auStack_c[0] = 8;
          auStack_c[1] = 0x12;
          auStack_e[0] = 0x61;
          auStack_e[1] = 0x16;
          fn_0000_0caa();
          auStack_c[0] = 2;
          auStack_c[1] = 0;
          auStack_e[0] = 0x40;
          auStack_e[1] = 0x10;
          auStack_10[0] = 0x68;
          auStack_10[1] = 0x16;
          func_0x00014608();
          return (uint *)0x1;
        }
        uVar40 = 1 << (auStack_6[0] & 0x1f);
        uVar42 = (ulong)uVar40;
      } while ((uVar40 & (int)*(char *)0xc4c) == 0);
      iVar45 = iVar47 * 0x82;
      unaff_ES = 0x15f8;
    } while( true );
  case (undefined1 *)0xc:
    while( true ) {
      *(undefined2 *)((int)&uStack_24 + unaff_SI * 2) = (int)in_EAX;
      uVar42 = ZEXT24(aiStack_30);
      aiStack_30[unaff_SI] = (int)*(char *)(*(int *)(&uStack_18 + unaff_SI * 2) * 0x2e + 0x160f);
      *(undefined1 *)(*(int *)(&uStack_18 + unaff_SI * 2) * 0x2e + 0x160e) = 8;
      *(undefined1 *)(*(int *)(&uStack_18 + unaff_SI * 2) * 0x2e + 0x160f) = 0;
      unaff_SI = unaff_SI + 1;
      if (unaff_DI <= (int)unaff_SI) break;
      in_EAX = (ulong)(uint)(int)*(char *)(*(int *)(&uStack_18 + unaff_SI * 2) * 0x2e + 0x160e);
    }
    auStack_8[0] = (byte)*(undefined2 *)0x3649;
    auStack_8[1] = (char)((uint)*(undefined2 *)0x3649 >> 8);
    auStack_a[0] = 0;
    auStack_a[1] = 0x50;
    auStack_c[0] = 5;
    auStack_c[1] = 0xc1;
    fn_0000_19d9();
    auStack_8[0] = (byte)*(undefined2 *)0x3649;
    auStack_8[1] = (char)((uint)*(undefined2 *)0x3649 >> 8);
    auStack_a[0] = 7;
    auStack_a[1] = 0;
    auStack_c[0] = 0x40;
    auStack_c[1] = 0x10;
    auStack_e[0] = 0x11;
    auStack_e[1] = 0xc1;
    uVar32 = fn_0000_3e03();
    auStack_a[0] = (char)uVar42;
    auStack_a[1] = (char)(uVar42 >> 8);
    auStack_c[0] = (byte)uVar32;
    auStack_c[1] = (char)((uint)uVar32 >> 8);
    auStack_10[0] = 0xb0;
    auStack_10[1] = 0;
    auStack_e[0] = 0x78;
    auStack_e[1] = 0;
    auStack_14[0] = 0x70;
    auStack_14[1] = 0;
    auStack_12[0] = 0;
    auStack_12[1] = 0;
    uStack_16 = 0xe0;
    uStack_15 = 0x13;
    uStack_18 = 0x22;
    uStack_17 = 0xc1;
    func_0x00013bcb();
    iVar47 = 0;
    if (0 < unaff_DI) {
      do {
        *(undefined1 *)(*(int *)(&uStack_18 + iVar47 * 2) * 0x2e + 0x160e) =
             *(undefined1 *)((int)&uStack_24 + iVar47 * 2);
        uVar42 = 0x15f8;
        *(undefined1 *)(*(int *)(&uStack_18 + iVar47 * 2) * 0x2e + 0x160f) =
             (char)aiStack_30[iVar47];
        iVar47 = iVar47 + 1;
      } while (iVar47 < unaff_DI);
    }
    auStack_a[0] = 0;
    auStack_a[1] = 0;
    auStack_8[0] = 0;
    auStack_8[1] = 0;
    auStack_c[0] = 0;
    auStack_c[1] = 0;
    uVar43 = *(undefined4 *)0x369f;
    auStack_10[0] = (char)uVar43;
    auStack_10[1] = (undefined1)((ulong)uVar43 >> 8);
    auStack_e[0] = (byte)((ulong)uVar43 >> 0x10);
    auStack_e[1] = (char)((ulong)uVar43 >> 0x18);
    auStack_12[0] = 5;
    auStack_12[1] = 0;
    auStack_14[0] = 0xa8;
    auStack_14[1] = 0x13;
    uStack_16 = 0x8b;
    uStack_15 = 0xc1;
    uVar32 = fn_0000_3e03();
    auStack_12[0] = (byte)uVar42;
    auStack_12[1] = (byte)(uVar42 >> 8);
    auStack_14[0] = (undefined1)uVar32;
    auStack_14[1] = (undefined1)((uint)uVar32 >> 8);
    uStack_18 = 0xf3;
    uStack_17 = 0x14;
    uStack_1a = 0xe0;
    uStack_19 = 0x13;
    uVar32 = 0x1888;
    uStack_1c = 0x97;
    uStack_1b = 0xc1;
    uStack_16 = uVar5;
    uStack_15 = uVar7;
    iVar47 = fn_0845_0450();
    if (iVar47 == 0 && (int)uVar42 == 0) {
      auStack_a[0] = 0xfd;
      auStack_a[1] = 0x14;
      auStack_c[0] = 0x88;
      auStack_c[1] = 0x18;
      uVar32 = 0x1668;
      auStack_e[0] = 0xad;
      auStack_e[1] = 0xc1;
      auStack_8[0] = uVar5;
      auStack_8[1] = uVar7;
      fn_0638_037f();
    }
    auStack_8[0] = (byte)uVar32;
    auStack_8[1] = (char)((uint)uVar32 >> 8);
    auStack_a[0] = 0xb5;
    auStack_a[1] = 0xc1;
    fn_0000_2167();
    auStack_a[0] = 0;
    auStack_a[1] = 0;
    auStack_8[0] = 0;
    auStack_8[1] = 0;
    auStack_e[0] = 0;
    auStack_e[1] = 0;
    auStack_c[0] = 0;
    auStack_c[1] = 0;
    auStack_12[0] = 0;
    auStack_12[1] = 0;
    auStack_10[0] = 0;
    auStack_10[1] = 0;
    uStack_16 = 0;
    uStack_15 = 0;
    auStack_14[0] = 0;
    auStack_14[1] = 0;
    uStack_1a = 0;
    uStack_19 = 0;
    uStack_18 = 0;
    uStack_17 = 0;
    cStack_1e = '%';
    uStack_1d = 0;
    uStack_1c = 2;
    uStack_1b = 0;
    uStack_20 = 0;
    uStack_1f = 0;
    uStack_24._0_1_ = 0;
    uStack_24._1_1_ = 0;
    uStack_22 = 0;
    uStack_21 = 0;
    uStack_26 = 8;
    uStack_25 = 0x12;
    uStack_28 = 0xd5;
    uStack_27 = 0xc1;
    func_0x0001115e();
    iVar47 = 0;
    do {
      auStack_a[0] = 0;
      auStack_a[1] = 0;
      auStack_8[0] = 0;
      auStack_8[1] = 0;
      auStack_e[0] = 0;
      auStack_e[1] = 0;
      auStack_c[0] = 0;
      auStack_c[1] = 0;
      auStack_12[0] = 0;
      auStack_12[1] = 0;
      auStack_10[0] = 0;
      auStack_10[1] = 0;
      auStack_14[0] = 0x90;
      auStack_14[1] = 0x17;
      uStack_16 = 0x2f;
      uStack_15 = 0;
      uStack_1a = 0;
      uStack_19 = 0;
      uStack_18 = 0;
      uStack_17 = 0;
      cStack_1e = ')';
      uStack_1d = 0;
      uStack_1c = 8;
      uStack_1b = 0;
      uStack_20 = 0x26;
      uStack_1f = 0;
      uStack_24._0_1_ = 0;
      uStack_24._1_1_ = 0;
      uStack_22 = 0;
      uStack_21 = 0;
      uStack_26 = 0x40;
      uStack_25 = 0x10;
      uStack_28 = 0xfd;
      uStack_27 = 0xc1;
      func_0x0001115e();
      uVar32 = (undefined2)uVar42;
      iVar47 = iVar47 + 1;
    } while (iVar47 < 1);
    auStack_c[0] = 0x40;
    auStack_c[1] = 0x10;
    auStack_e[0] = 0xf;
    auStack_e[1] = 0xc2;
    func_0x000188a5();
    auStack_8[0] = 0x88;
    auStack_8[1] = 0x18;
    auStack_a[0] = 0x17;
    auStack_a[1] = 0xc2;
    func_0x0001217e();
    auStack_a[0] = 0;
    auStack_a[1] = 0;
    auStack_8[0] = 1;
    auStack_8[1] = 0;
    auStack_c[0] = 5;
    auStack_c[1] = 0;
    auStack_e[0] = 8;
    auStack_e[1] = 0x12;
    auStack_10[0] = 0x24;
    auStack_10[1] = 0xc2;
    uVar33 = fn_0000_3e03();
    auStack_c[0] = (byte)uVar32;
    auStack_c[1] = (char)((uint)uVar32 >> 8);
    auStack_e[0] = (byte)uVar33;
    auStack_e[1] = (char)((uint)uVar33 >> 8);
    uVar43 = *(undefined4 *)0x4d56;
    auStack_12[0] = (byte)uVar43;
    auStack_12[1] = (byte)((ulong)uVar43 >> 8);
    auStack_10[0] = (char)((ulong)uVar43 >> 0x10);
    auStack_10[1] = (undefined1)((ulong)uVar43 >> 0x18);
    auStack_14[0] = 0xe0;
    auStack_14[1] = 0x13;
    uStack_16 = 0x31;
    uStack_15 = 0xc2;
    fn_0000_445b();
    auStack_a[0] = 0x20;
    auStack_a[1] = 0x14;
    auStack_c[0] = 0x3c;
    auStack_c[1] = 0xc2;
    fn_0000_1e8f();
    auStack_a[0] = 0xe8;
    auStack_a[1] = 0x11;
    auStack_c[0] = 0x42;
    auStack_c[1] = 0xc2;
    fn_0000_2167();
    auStack_c[0] = 0;
    auStack_c[1] = 0xfa;
    auStack_a[0] = 0;
    auStack_a[1] = 0;
    auStack_e[0] = 0;
    auStack_e[1] = 0;
    auStack_10[0] = 8;
    auStack_10[1] = 0x12;
    auStack_12[0] = 0x4f;
    auStack_12[1] = 0xc2;
    uVar33 = fn_0000_3e1d();
    auStack_e[0] = (byte)uVar32;
    auStack_e[1] = (char)((uint)uVar32 >> 8);
    auStack_10[0] = (char)uVar33;
    auStack_10[1] = (undefined1)((uint)uVar33 >> 8);
    uVar43 = *(undefined4 *)0x4d5a;
    auStack_14[0] = (undefined1)uVar43;
    auStack_14[1] = (undefined1)((ulong)uVar43 >> 8);
    auStack_12[0] = (byte)((ulong)uVar43 >> 0x10);
    auStack_12[1] = (byte)((ulong)uVar43 >> 0x18);
    uStack_16 = 0xe0;
    uStack_15 = 0x13;
    uStack_18 = 0x5c;
    uStack_17 = 0xc2;
    fn_0000_445b();
    auStack_a[0] = 0x20;
    auStack_a[1] = 0x14;
    auStack_c[0] = 100;
    auStack_c[1] = 0xc2;
    fn_0000_0caa();
    auStack_a[0] = 0x40;
    auStack_a[1] = 0x10;
    auStack_c[0] = 0x69;
    auStack_c[1] = 0xc2;
    func_0x0001217e();
    auStack_a[0] = 8;
    auStack_a[1] = 0x12;
    auStack_c[0] = 0x6e;
    auStack_c[1] = 0xc2;
    puVar31 = (uint *)func_0x00010447();
    if (CONCAT11(auStack_6[1],auStack_6[0]) == 1) {
      auStack_a[0] = 0x18;
      auStack_a[1] = 0x10;
      auStack_c[0] = 0x78;
      auStack_c[1] = 0xc2;
      puVar31 = (uint *)ovr_2d99_0025();
    }
    return puVar31;
  }
  fn_0000_226c();
  if ((unaff_SI & 3) != 0) {
    func_0x00011830();
    uStack_2._0_1_ = (undefined1)*(undefined4 *)0x4edc;
    uStack_2._1_1_ = (undefined1)((ulong)*(undefined4 *)0x4edc >> 8);
    uStack_4._0_1_ = 0x40;
    uStack_4._1_1_ = 0x10;
    auStack_6[0] = 0x44;
    auStack_6[1] = 0x8b;
    func_0x000121f5();
    *(undefined2 *)0x20d5 = 0;
  }
  fn_0000_080f();
  fn_067a_001e();
  return (uint *)*(undefined2 *)CONCAT11(auStack_12[1],auStack_12[0]);
}


//// ovr_2d56_0084 @ 5646:1750

/* WARNING: Removing unreachable block (ram,0x00057cd0) */

undefined2 __cdecl16far ovr_2d56_0084(void)

{
  byte *pbVar1;
  long lVar2;
  undefined2 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 in_EDX;
  uint uVar6;
  int iVar7;
  undefined2 unaff_SI;
  undefined2 unaff_DI;
  int iVar8;
  undefined2 unaff_DS;
  undefined2 local_e;
  int local_6;
  
  if (*(char *)0x81ff == '\0') {
    *(undefined1 *)0x81fe = 1;
  }
  ovr_2d56_004d();
  ovr_2d56_0057();
  iVar8 = 1;
  do {
    uVar4 = fn_0000_0cb9();
    if ((uVar4 & 0x8000) != 0) {
      iVar5 = func_0x00013bdd();
      uVar6 = (uVar4 & 0x7fff) - 1;
      if (uVar6 < 6) {
        iVar7 = uVar6 * 2;
        switch(uVar4 & 0x7fff) {
        case 1:
          *(char *)(iVar7 + uVar4) = *(char *)(iVar7 + uVar4) + (char)iVar5;
          fn_0000_3e03();
          fn_0000_445b();
          ovr_2d1b_0034();
          func_0x00010581();
          func_0x0001115e();
          lVar2 = *(long *)0x384c;
          local_e = (undefined2)lVar2;
          uVar3 = (undefined2)((ulong)lVar2 >> 0x10);
          ovr_2d1b_003e();
          if (lVar2 != 0) {
            if (2 < (int)uVar4) {
              iVar8 = func_0x00010603();
              pbVar1 = (byte *)(iVar8 * 10 + -0x7df4);
              *pbVar1 = *pbVar1 | 0x10;
              func_0x00010581();
            }
            uVar3 = 0;
            local_e = 0;
            func_0x0001115e();
          }
          if (CONCAT22(uVar3,local_e) != 0) {
            func_0x000188a5();
          }
          fn_0000_3e03();
          fn_0000_445b();
          if ((int)uVar4 < 3) {
            func_0x00010603();
            fn_070c_06e5();
          }
          else {
            func_0x00010603();
            ovr_2d1b_0048();
          }
          fn_0000_0caa();
          fn_0000_19d9();
          func_0x00014608();
          if (*(char *)0x7fe5 != '\v') {
            fn_0000_06c6();
          }
          func_0x0001115e();
          ovr_2d1b_003e();
          ovr_2d1b_0052();
          if (uVar4 == 0xb) {
            fn_0000_0dc4();
          }
          if (local_6 == 1) {
            ovr_2d1b_0025();
          }
          uVar3 = fn_0000_1e8f();
          return uVar3;
        case 2:
          if ((int)in_EDX != 0) {
            fn_0000_0bb3();
          }
          break;
        case 3:
          while( true ) {
            uVar3 = fn_0000_445b();
            if (iVar8 != 0x1b) {
              uVar3 = func_0x00013902();
              iVar7 = iVar5 * 0x70 + iVar8 * 4;
              *(undefined2 *)(iVar7 + 0x4c0c) = (int)in_EDX;
              *(undefined2 *)(iVar7 + 0x4c0a) = uVar3;
            }
            iVar8 = iVar8 + 1;
            if (0x1b < iVar8) break;
            fn_0000_3e03();
            func_0x000123e4();
            fn_0000_23a3();
          }
          return uVar3;
        case 4:
          if (iVar7 == 0) {
            unaff_SI = 0;
          }
          return unaff_SI;
        case 5:
          if ((char)((uint)iVar7 >> 8) != '\0') {
            func_0x0001468c();
          }
          return unaff_DI;
        case 6:
          return unaff_DI;
        }
        fn_0000_1904();
        uVar3 = fn_0000_0bb3();
        return uVar3;
      }
      func_0x00013c0c();
      fn_0000_124c();
    }
    fn_0000_0d3a();
  } while( true );
}


//// ovr_2d56_0089 @ 5646:1890

undefined2 __cdecl16far ovr_2d56_0089(void)

{
  bool bVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  undefined4 uVar4;
  
  ovr_2d56_004d(0x2df,0x1590);
  ovr_2d56_0057(0x2df,0x1590);
  uVar3 = 0x17a8;
  func_0x00017aaa();
  bVar1 = true;
  while (bVar1) {
    uVar2 = fn_0000_0cb9(uVar3,(int)*(undefined4 *)0x4b60,
                          (int)((ulong)*(undefined4 *)0x4b60 >> 0x10));
    if ((uVar2 & 0x8000) != 0) {
      uVar4 = func_0x00013bdd(0x10c8,(int)*(undefined4 *)0x4b60,
                              (int)((ulong)*(undefined4 *)0x4b60 >> 0x10),uVar2 & 0x7fff);
      if ((uVar2 & 0x7fff) == 1) {
        bVar1 = false;
      }
      func_0x00013c0c(0x13b0,uVar4,0);
      fn_0000_124c(0x13b0,uVar4);
    }
    uVar3 = 0x1040;
    fn_0000_0d3a(0x10c8);
  }
  ovr_2d56_0052(0x2df,0x1590);
  return 0xffff;
}


//// ovr_2d56_003e @ 5646:1928

void __cdecl16far ovr_2d56_003e(int param_1,int param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int local_8;
  int local_6;
  
  if (param_1 != param_2) {
    uVar1 = func_0x00011444();
    local_6 = 0x15fa;
    local_8 = 0;
    uVar2 = 0x1040;
    do {
      uVar3 = uVar2;
      if (((*(char *)(local_6 + 0x14) < '\x0e') && (*(int *)(local_6 + 5) != 0)) &&
         (0 < *(int *)(local_6 + 0x1d))) {
        uVar3 = 0x1140;
        uVar2 = func_0x00011820(uVar2,*(undefined2 *)(local_6 + 0x1d),uVar1);
        *(undefined2 *)(local_6 + 0x1d) = uVar2;
        if (param_2 < param_1) {
          *(int *)(local_6 + 0x1d) = *(int *)(local_6 + 0x1d) + 1;
        }
        if (*(int *)(local_6 + 0x1d) == 0) {
          *(undefined2 *)(local_6 + 0x1d) = 1;
        }
      }
      local_8 = local_8 + 1;
      local_6 = local_6 + 0x2e;
      uVar2 = uVar3;
    } while (local_8 < 0x1e);
  }
  return;
}


//// ovr_2d56_0043 @ 5646:19c7

void __cdecl16far ovr_2d56_0043(void)

{
  undefined2 unaff_DS;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 local_10 [14];
  
  if (*(char *)0x20db != *(char *)0x81fd) {
    *(undefined1 *)0x20db = *(undefined1 *)0x81fd;
    fn_07bc_0060();
    sprintf(local_10);
    uVar3 = 0xffff;
    uVar2 = *(undefined4 *)0x4d6c;
    uVar1 = func_0x000171af(0x1000,0x11fc);
    fn_0845_01d0(0x1718,uVar1,uVar2,uVar3);
    uVar3 = 0xffff;
    uVar2 = *(undefined4 *)0x4d68;
    uVar1 = func_0x000171af(0x1860,local_10);
    fn_0845_01d0(0x1718,uVar1,uVar2,uVar3);
    fn_067a_0823();
    fn_0845_07d5(0x1202);
    *(undefined1 *)0xad49 = *(undefined1 *)0x81fd;
    func_0x00018c20(0x18c0,0x120c);
  }
  return;
}

