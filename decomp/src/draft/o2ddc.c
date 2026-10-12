//// ovr_2ddc_0020 @ 5f1f:0000

int __cdecl16far ovr_2ddc_0020(int param_1)

{
  int iVar1;
  undefined2 unaff_DS;
  undefined4 local_6;
  
  local_6 = CONCAT22(*(undefined2 *)(param_1 * 4 + 0x1d4a),*(undefined2 *)(param_1 * 4 + 0x1d48));
  if (local_6 != 0) {
    iVar1 = fn_07bc_01e5();
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  return param_1;
}

