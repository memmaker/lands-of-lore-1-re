//// fn_17c5_0004 @ 27c5:0004

undefined2 __cdecl16far fn_17c5_0004(void)

{
  code *pcVar1;
  code *pcVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  undefined2 in_DX;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  ulong uStackY_26;
  long lVar6;
  undefined4 local_e;
  long local_a;
  
  local_a = 0;
  fn_178d_015e();
  fn_2db9_003e();
  if ((g_28fa != -1) || (g_2908 != (code *)0x0)) {
    if (g_2910 == g_28ce) {
      g_2910 = 0;
      g_2918 = 0;
      g_2914 = 0;
      g_291c = 0;
    }
    else {
      fn_2db9_003e();
    }
    if (g_28d2 != 0) {
      lVar6 = g_28d2;
      uVar3 = fn_2db9_0020();
      iVar4 = stricmp(uVar3,in_DX,lVar6);
      if (iVar4 == 0) {
        g_2910 = g_28ce;
        g_2918 = g_28d6;
        g_2914 = g_28d2;
        g_291c = g_28da;
        if (g_28fa == -1) {
          local_e = g_2908;
          pcVar2 = local_e;
          local_e._0_2_ = (code *)g_2908;
          pcVar1 = (code *)local_e;
          local_e = pcVar2;
          (*pcVar1)(0x1000,(uint)(in_NT & 1) * 0x4000 | (uint)(in_IF & 1) * 0x200 |
                           (uint)(in_TF & 1) * 0x100 | 0x40 | (uint)(in_AF & 1) * 0x10 | 4,
                    g_28ce);
        }
        goto LAB_27c5_010b;
      }
    }
    uVar5 = fn_2db9_0039();
    uStackY_26 = (ulong)uVar5;
    local_a = local_a + uStackY_26;
  }
LAB_27c5_010b:
  return (int)local_a;
}

