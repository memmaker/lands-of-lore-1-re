/* s130: WW library -- far pointer checks */
int far fn_19ba_0086(void far *p);
void far *far fn_19ba_0053(void far *p);
int far fn_19ba_0073(void far *p);
int far fn_2365_063f(void far *p);

void far *fn_226d_0007(void far *p)
{
    if (fn_19ba_0086(p))
        return fn_19ba_0053(p);
    if (fn_2365_063f(p))
        return 0;
    return p;
}

int fn_226d_004e(void far *p)
{
    if (p == 0)
        return 0;
    if (!fn_19ba_0073(p))
        return 0;
    return 1;
}
