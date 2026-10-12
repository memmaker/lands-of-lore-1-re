//// fn_17f8_0003 @ 27f8:0003

undefined2 __cdecl16far fn_17f8_0003(void)

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
  fn_17d6_0123();
  fn_2db9_003e();
  if ((g_28b8 != -1) || (g_28c6 != (code *)0x0)) {
    if (g_28ce == g_2910) {
      g_28ce = 0;
      g_28d6 = 0;
      g_28d2 = 0;
      g_28da = 0;
    }
    else {
      fn_2db9_003e();
    }
    if (g_2914 != 0) {
      lVar6 = g_2914;
      uVar3 = fn_2db9_0020();
      iVar4 = stricmp(uVar3,in_DX,lVar6);
      if (iVar4 == 0) {
        g_28ce = g_2910;
        g_28d6 = g_2918;
        g_28d2 = g_2914;
        g_28da = g_291c;
        if (g_28b8 == -1) {
          local_e = g_28c6;
          pcVar2 = local_e;
          local_e._0_2_ = (code *)g_28c6;
          pcVar1 = (code *)local_e;
          local_e = pcVar2;
          (*pcVar1)(0x1000,(uint)(in_NT & 1) * 0x4000 | (uint)(in_IF & 1) * 0x200 |
                           (uint)(in_TF & 1) * 0x100 | 0x40 | (uint)(in_AF & 1) * 0x10 | 4,
                    g_2910);
        }
        goto LAB_27f8_0105;
      }
    }
    uVar5 = fn_2db9_0039();
    uStackY_26 = (ulong)uVar5;
    local_a = local_a + uStackY_26;
  }
LAB_27f8_0105:
  return (int)local_a;
}

