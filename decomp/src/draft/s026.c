//// fn_16bf_0058 @ 26bf:0058

undefined2 __cdecl16far fn_16bf_0058(uint param_1)

{
  code *pcVar1;
  undefined2 uVar2;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  undefined4 local_8;
  undefined2 local_4;
  
  uVar2 = 0x26bf;
  local_4 = g_35e4;
  g_35e4 = param_1;
  if (param_1 == 0) {
    uVar2 = 0x278d;
    fn_178d_015e();
  }
  if ((g_28fa == -1) && (g_2908 != (code *)0x0)) {
    local_8 = g_2908;
    pcVar1 = local_8;
    local_8._0_2_ = (code *)g_2908;
    local_8 = pcVar1;
    if (g_35e4 == 0) {
      pcVar1 = (code *)local_8;
      (*pcVar1)(uVar2,(uint)(in_NT & 1) * 0x4000 | (uint)(in_IF & 1) * 0x200 |
                      (uint)(in_TF & 1) * 0x100 | 0x40 | (uint)(in_AF & 1) * 0x10 | 4);
    }
    else {
      pcVar1 = (code *)local_8;
      (*pcVar1)(uVar2,(uint)(in_NT & 1) * 0x4000 | (uint)(in_IF & 1) * 0x200 |
                      (uint)(in_TF & 1) * 0x100 | (uint)((int)g_35e4 < 0) * 0x80 |
                      (uint)(g_35e4 == 0) * 0x40 | (uint)(in_AF & 1) * 0x10 |
                      (uint)((POPCOUNT(g_35e4 & 0xff) & 1U) == 0) * 4);
    }
  }
  return local_4;
}


//// fn_16bf_00af @ 26bf:00af

/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined2 __cdecl16far fn_16bf_00af(void)

{
  undefined4 in_EAX;
  undefined4 in_ECX;
  undefined4 in_EDX;
  undefined4 in_EBX;
  int iVar1;
  undefined1 *puVar2;
  undefined4 in_ESP;
  undefined4 in_EBP;
  undefined4 in_ESI;
  undefined4 in_EDI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 in_FS;
  undefined2 in_GS;
  byte in_CF;
  byte in_PF;
  byte in_AF;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined1 *puVar3;
  
  iVar1 = (int)in_ESP;
  *(undefined2 *)(iVar1 + -2) = (int)in_EBP;
  *(undefined4 *)(iVar1 + -6) = in_EAX;
  *(undefined4 *)(iVar1 + -10) = in_ECX;
  *(undefined4 *)(iVar1 + -0xe) = in_EDX;
  *(undefined4 *)(iVar1 + -0x12) = in_EBX;
  *(undefined4 *)(iVar1 + -0x16) = CONCAT22((int)((ulong)in_ESP >> 0x10),iVar1 + -2);
  *(undefined4 *)(iVar1 + -0x1a) = CONCAT22((int)((ulong)in_EBP >> 0x10),iVar1 + -2);
  *(undefined4 *)(iVar1 + -0x1e) = in_ESI;
  *(undefined4 *)(iVar1 + -0x22) = in_EDI;
  *(undefined2 *)(iVar1 + -0x24) = 0x3e2d;
  *(undefined2 *)(iVar1 + -0x26) = unaff_ES;
  *(undefined2 *)(iVar1 + -0x28) = in_FS;
  *(undefined2 *)(iVar1 + -0x2a) = in_GS;
  puVar2 = (undefined1 *)(iVar1 + -0x2e);
  *(ulong *)(iVar1 + -0x2e) =
       (ulong)(in_NT & 1) * 0x4000 | (ulong)(in_OF & 1) * 0x800 | (ulong)(in_IF & 1) * 0x200 |
       (ulong)(in_TF & 1) * 0x100 | (ulong)(in_SF & 1) * 0x80 | (ulong)(in_ZF & 1) * 0x40 |
       (ulong)(in_AF & 1) * 0x10 | (ulong)(in_PF & 1) * 4 | (ulong)(in_CF & 1) |
       (ulong)(in_ID & 1) * 0x200000 | (ulong)(in_VIP & 1) * 0x100000 |
       (ulong)(in_VIF & 1) * 0x80000 | (ulong)(in_AC & 1) * 0x40000;
  if (g_2952 != 0) {
    *(undefined2 *)(iVar1 + -0x30) = 0x26bf;
    puVar3 = (undefined1 *)(iVar1 + -0x32);
    *(undefined2 *)(iVar1 + -0x32) = 0x6cba;
    fn_16cf_02b7();
    puVar2 = puVar3 + 4;
  }
  return (int)*(undefined4 *)(puVar2 + 0x28);
}


//// fn_16bf_00d6 @ 26bf:00d6

undefined2 __cdecl16far fn_16bf_00d6(int param_1)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  iVar2 = 0;
  while ((!bVar1 && (((undefined2 *)&g_2964)[iVar2] != 0))) {
    if ((int)((undefined2 *)&g_2964)[iVar2] < param_1) {
      bVar1 = true;
    }
    else {
      iVar2 = iVar2 + 1;
    }
  }
  return ((undefined2 *)&g_2970)[iVar2];
}

