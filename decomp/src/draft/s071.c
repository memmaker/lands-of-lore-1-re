//// fn_1f36_0001 @ 2f36:0001

undefined2 __cdecl16far fn_1f36_0001(undefined2 param_1,undefined2 param_2)

{
  undefined2 local_4;
  
  local_4 = 0;
  fn_2279_025b(param_1,param_2,&local_4);
  return local_4;
}


//// fn_1f36_0029 @ 2f36:0029

undefined2 __cdecl16far fn_1f36_0029(long param_1)

{
  undefined2 uVar1;
  undefined2 in_DX;
  undefined2 local_4;
  
  if (param_1 == 0) {
    local_4 = 0;
  }
  else {
    uVar1 = fn_2037_0002((undefined2)param_1,param_1._2_2_,6,&local_4);
    fn_2279_025b(uVar1,in_DX);
  }
  return local_4;
}


//// fn_1f36_0064 @ 2f36:0064

undefined2 __cdecl16far fn_1f36_0064(int *param_1,int param_2)

{
  int iVar1;
  undefined2 uVar2;
  long *plVar3;
  undefined2 in_DX;
  long local_6;
  
  if ((param_1 == (int *)0x0) || (param_2 < 0)) {
LAB_2f36_007a:
    uVar2 = 0;
  }
  else {
    iVar1 = fn_2365_063f((int *)param_1,param_1._2_2_);
    if ((iVar1 == 0) && (iVar1 = fn_19ba_0086((int *)param_1,param_1._2_2_), iVar1 == 0)) {
      if (*param_1 <= param_2) goto LAB_2f36_007a;
      plVar3 = (long *)fn_2037_0002((int *)param_1,param_1._2_2_,param_2 * 4 + 2);
      local_6 = *plVar3;
    }
    else {
      iVar1 = fn_1f36_0001((int *)param_1,param_1._2_2_);
      if (iVar1 <= param_2) goto LAB_2f36_007a;
      uVar2 = fn_2037_0002((int *)param_1,param_1._2_2_,param_2 * 4 + 2,&local_6);
      fn_2279_025b(uVar2,in_DX);
    }
    uVar2 = fn_2037_0002((int *)param_1,param_1._2_2_,local_6 + 2);
  }
  return uVar2;
}


//// fn_1f36_013d @ 2f36:013d

undefined2 __cdecl16far fn_1f36_013d(long param_1,int param_2)

{
  undefined2 uVar1;
  undefined2 in_DX;
  undefined2 local_4;
  
  local_4 = 0;
  if (param_1 != 0) {
    uVar1 = fn_2037_0002((undefined2)param_1,param_1._2_2_,(long)((param_2 + 1) * -2));
    fn_2279_025b(uVar1,in_DX,&local_4);
  }
  return local_4;
}


//// fn_1f36_018e @ 2f36:018e

undefined1 __cdecl16far fn_1f36_018e(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  undefined2 in_DX;
  undefined1 uVar2;
  undefined4 local_6;
  
  uVar2 = 0;
  iVar1 = fn_226d_0007(param_1,param_2,0);
  local_6 = CONCAT22(in_DX,iVar1);
  if (local_6 != 0) {
    uVar2 = *(undefined1 *)(iVar1 + 2);
    *(undefined1 *)(iVar1 + 2) = *(undefined1 *)(iVar1 + 5);
    fn_226d_004e(param_1,param_2);
  }
  return uVar2;
}


//// fn_1f36_01e2 @ 2f36:01e2

undefined2 __cdecl16far fn_1f36_01e2(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  undefined2 in_DX;
  undefined2 uVar2;
  undefined4 local_6;
  
  uVar2 = 0;
  iVar1 = fn_226d_0007(param_1,param_2,0);
  local_6 = CONCAT22(in_DX,iVar1);
  if (local_6 != 0) {
    uVar2 = *(undefined2 *)(iVar1 + 3);
    fn_226d_004e(param_1,param_2);
  }
  return uVar2;
}


//// fn_1f36_0224 @ 2f36:0224

undefined1 __cdecl16far fn_1f36_0224(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  undefined2 in_DX;
  undefined1 uVar2;
  undefined4 local_6;
  
  uVar2 = 0;
  iVar1 = fn_226d_0007(param_1,param_2,0);
  local_6 = CONCAT22(in_DX,iVar1);
  if (local_6 != 0) {
    uVar2 = *(undefined1 *)(iVar1 + 2);
    fn_226d_004e(param_1,param_2);
  }
  return uVar2;
}


//// fn_1f36_026a @ 2f36:026a

undefined1 __cdecl16far fn_1f36_026a(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  undefined2 in_DX;
  undefined1 uVar2;
  undefined4 local_6;
  
  uVar2 = 0;
  iVar1 = fn_226d_0007(param_1,param_2,0);
  local_6 = CONCAT22(in_DX,iVar1);
  if (local_6 != 0) {
    uVar2 = *(undefined1 *)(iVar1 + 5);
    fn_226d_004e(param_1,param_2);
  }
  return uVar2;
}


//// fn_1f36_02b0 @ 2f36:02b0

undefined1 __cdecl16far fn_1f36_02b0(undefined2 param_1,undefined2 param_2,undefined1 param_3)

{
  int iVar1;
  undefined2 in_DX;
  undefined1 uVar2;
  undefined4 local_6;
  
  uVar2 = 0;
  iVar1 = fn_226d_0007(param_1,param_2,0);
  local_6 = CONCAT22(in_DX,iVar1);
  if (local_6 != 0) {
    uVar2 = *(undefined1 *)(iVar1 + 2);
    *(undefined1 *)(iVar1 + 2) = param_3;
    fn_226d_004e(param_1,param_2);
  }
  return uVar2;
}


//// fn_1f36_0300 @ 2f36:0300

undefined2 __cdecl16far fn_1f36_0300(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  undefined2 in_DX;
  undefined2 uVar2;
  undefined4 local_6;
  
  uVar2 = 0;
  iVar1 = fn_226d_0007(param_1,param_2,0);
  local_6 = CONCAT22(in_DX,iVar1);
  if (local_6 != 0) {
    uVar2 = *(undefined2 *)(iVar1 + 8);
    fn_226d_004e(param_1,param_2);
  }
  return uVar2;
}

