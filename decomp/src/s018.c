/* s018: EMC script loader and interpreter (IFF FORM with TEXT/ORDR/DATA chunks) */

#include "lol.h"

int ovr_2de9_0020(char far *name);
void ovr_2de9_0025(int h);
int ovr_2de9_002a(int h, long tag);
void ovr_2de9_002f(int h, long tag, void far *buf, long len);
void far *fn_203b_0007(long size, int flags);
void fn_203b_0203(void far *p);
int fn_2315_0018(int w);

void fn_0f28_0009(struct EmcData far *d);
int fn_0f28_0478(struct EmcState far *s);

void fn_0f28_0009(struct EmcData far *d)
{
    if (d) {
        if (d->alloc) {
            if (d->text) fn_203b_0203(d->text);
            if (d->ordr) fn_203b_0203(d->ordr);
            if (d->data) fn_203b_0203(d->data);
        }
        d->text = 0;
        d->ordr = 0;
        d->data = 0;
    }
}

long fn_0f28_007f(char far *name)
{
    long total;
    int n;
    register int h;

    if (!name) return 0;
    total = 0;
    h = ovr_2de9_0020(name);
    n = ovr_2de9_002a(h, 0x54584554L);      /* TEXT */
    total += n;
    n = ovr_2de9_002a(h, 0x5244524fL);      /* ORDR */
    total += n;
    if (n) {
        n = ovr_2de9_002a(h, 0x41544144L);  /* DATA */
        total += n;
    } else
        total = 0;
    ovr_2de9_0025(h);
    return total;
}

int fn_0f28_0114(char far *name, struct EmcData far *d, int (far * far *opcodes)(struct EmcState far *), void far *buf)
{
    int h;
    register int n;
    register int total;

    if (!d) return 0;
    if (!name) return 0;
    fn_0f28_0009(d);
    total = 0;
    d->alloc = !buf;
    d->opcodes = opcodes;
    h = ovr_2de9_0020(name);
    n = ovr_2de9_002a(h, 0x54584554L);
    total += n;
    if (n) {
        if (buf) {
            d->text = buf;
            buf = (void far *)((long)buf + n);
        } else
            d->text = fn_203b_0007((long)n, 0x30);
        ovr_2de9_002f(h, 0x54584554L, d->text, (long)n);
    }
    n = ovr_2de9_002a(h, 0x5244524fL);
    total += n;
    if (!n) goto fail;
    if (buf) {
        d->ordr = buf;
        buf = (void far *)((long)buf + n);
    } else
        d->ordr = fn_203b_0007((long)n, 0x30);
    ovr_2de9_002f(h, 0x5244524fL, d->ordr, (long)n);
    for (n = ((unsigned)n >> 1) - 1; n >= 0; n--) d->ordr[n] = fn_2315_0018(d->ordr[n]);
    n = ovr_2de9_002a(h, 0x41544144L);
    total += n;
    if (!n) goto fail;
    if (buf)
        d->data = buf;
    else
        d->data = fn_203b_0007((long)n, 0x30);
    ovr_2de9_002f(h, 0x41544144L, d->data, (long)n);
    d->dataSize = (unsigned)n >> 1;
    goto done;
fail:
    fn_0f28_0009(d);
    total = 0;
done:
    ovr_2de9_0025(h);
    return total;
}

void fn_0f28_032c(struct EmcState far *s, struct EmcData far *d)
{
    if (s) {
        s->ip = 0;
        s->running = 0;
        s->bp = 0x66;
        s->sp = 0x64;
        s->dat = d;
    }
}

void fn_0f28_035f(struct EmcState far *s, int fn)
{
    struct EmcData far *d;

    if (s) {
        d = s->dat;
        if (d && d->ordr[fn] != -1)
            s->ip = d->data + d->ordr[fn] + 1;
        else
            s->ip = 0;
    }
}

void fn_0f28_03d2(struct EmcState far *s, int fn)
{
    struct EmcData far *d;

    if (fn_0f28_0478(s) && !s->running) {
        d = s->dat;
        s->running = 1;
        s->stack[--s->sp] = ((long)s->ip - (long)d->data) / 2;
        s->stack[--s->sp] = s->retValue;
        s->ip = d->data + d->ordr[fn] + 1;
    }
}

int fn_0f28_0478(struct EmcState far *s)
{
    if (!s) return 0;
    if (!s->ip) return 0;
    if (!s->dat) return 0;
    return 1;
}

/* C version: BCC 3.1 does not reproduce the original code from it (tools/inlasm.py) */
#if 0
int fn_0f28_04a0(struct EmcState far *s)
{
    int op;
    int w;
    register int a;

    a = 0;
    if (!s) return 0;
    if (!s->ip) return 0;
    w = *s->ip++;
    w = fn_2315_0018(w);
    op = (w >> 8) & 0x1f;
    if (w & 0x8000) {
        op = 0;
        a = w & 0x7fff;
    } else if (w & 0x4000)
        a = (char)w;
    else if (w & 0x2000) {
        a = *s->ip++;
        a = fn_2315_0018(a);
    }
    switch (op) {
    case 0:
    jump:
        s->ip = s->dat->data + a;
        break;
    case 1:
        s->retValue = a;
        break;
    case 2:
        switch (a) {
        case 0:
            s->stack[--s->sp] = s->retValue;
            break;
        case 1:
            s->stack[--s->sp] = ((long)s->ip - (long)s->dat->data) / 2 + 1;
            s->stack[--s->sp] = s->bp;
            s->bp = s->sp + 2;
            break;
        default:
            goto err;
        }
        break;
    default:
    err:
        s->ip = 0;
        return 0;
    case 3:
    case 4:
        s->stack[--s->sp] = a;
        break;
    case 5:
        s->stack[--s->sp] = s->regs[a];
        break;
    case 6:
        s->stack[--s->sp] = s->stack[s->bp + -(a + 2)];
        break;
    case 7:
        s->stack[--s->sp] = s->stack[a + s->bp - 1];
        break;
    case 8:
        switch (a) {
        case 0:
            s->retValue = s->stack[s->sp++];
            break;
        case 1:
            if (s->sp == 100) goto err;
            s->bp = s->stack[s->sp++];
            a = s->stack[s->sp++];
            goto jump;
        default:
            goto err;
        }
        break;
    case 9:
        s->regs[a] = s->stack[s->sp++];
        break;
    case 10:
        s->stack[s->bp + -(a + 2)] = s->stack[s->sp++];
        break;
    case 11:
        s->stack[a + s->bp - 1] = s->stack[s->sp++];
        break;
    case 12:
        s->sp += a;
        break;
    case 13:
        s->sp -= a;
        break;
    case 14: {
        int (far * far *tbl)(struct EmcState far *);
        int (far *fn)(struct EmcState far *);

        tbl = s->dat->opcodes;
        fn = tbl[a & 0xff];
        s->retValue = fn(s);
        break;
    }
    case 15:
        if (s->stack[s->sp++]) break;
        a &= 0x7fff;
        goto jump;
    case 16: {
        int x;

        x = s->stack[s->sp++];
        switch (a) {
        case 0: x = !x; break;
        case 1: x = -x; break;
        case 2: x = ~x; break;
        default: goto err;
        }
        s->stack[--s->sp] = x;
        break;
    }
    case 17: {
        int y;
        int x;
        int r;

        y = s->stack[s->sp++];
        x = s->stack[s->sp++];
        switch (a) {
        case 0: r = x && y; break;
        case 1: r = x || y; break;
        case 2: r = x == y; break;
        case 3: r = x != y; break;
        case 4: r = x < y; break;
        case 5: r = x <= y; break;
        case 6: r = x > y; break;
        case 7: r = x >= y; break;
        case 8: r = x + y; break;
        case 9: r = x - y; break;
        case 10: r = x * y; break;
        case 11: r = x / y; break;
        case 12: r = x >> y; break;
        case 13: r = x << y; break;
        case 14: r = x & y; break;
        case 15: r = x | y; break;
        case 16: r = x % y; break;
        case 17: r = x ^ y; break;
        default: goto err;
        }
        s->stack[--s->sp] = r;
        break;
    }
    case 18:
        if (s->sp == 100) goto err;
        s->retValue = s->stack[s->sp++];
        a = s->stack[s->sp++];
        s->running = 0;
        goto jump;
    }
    return 1;
}
#endif
int fn_0f28_04a0(struct EmcState far *s)
{
    char _l[10];
    _SI;   /* saved by the original */
    _DI;   /* saved by the original */
    asm db 33h, 0ffh	/* xor di,di */
    asm db 66h	/* cmp dword [bp+0x6],0x0 */
    asm cmp word ptr [bp+6],0
    asm jnz L_0016
L_0011:
    asm db 33h, 0c0h	/* xor ax,ax */
    asm jmp Lret
L_0016:
    asm les bx,dword ptr [bp+6]
    asm db 66h	/* cmp dword [es:bx],0x0 */
    asm cmp word ptr es:[bx],0
    asm jnz L_0022
    asm jmp L_0011
L_0022:
    asm les bx,dword ptr [bp+6]
    asm mov ax,es:[bx+2]
    asm mov si,es:[bx]
    asm add word ptr es:[bx],2
    asm mov es,ax
    asm mov dx,es:[si]
    asm push dx
    asm call far ptr fn_2315_0018
    asm pop cx
    asm db 8bh, 0d0h	/* mov dx,ax */
    asm sar ax,8
    asm and ax,1fh
    asm mov word ptr _l+8,ax
    asm test dx,8000h
    asm jz L_005a
    asm mov word ptr _l+8,0
    asm db 8bh, 0fah	/* mov di,dx */
    asm and di,7fffh
    asm jmp L_0087
L_005a:
    asm test dx,4000h
    asm jz L_0065
    asm db 8ah, 0c2h	/* mov al,dl */
    asm cbw
    asm jmp L_0085
L_0065:
    asm test dx,2000h
    asm jz L_0087
    asm les bx,dword ptr [bp+6]
    asm mov ax,es:[bx+2]
    asm mov si,es:[bx]
    asm add word ptr es:[bx],2
    asm mov es,ax
    asm mov di,es:[si]
    asm push di
    asm call far ptr fn_2315_0018
    asm pop cx
L_0085:
    asm db 8bh, 0f8h	/* mov di,ax */
L_0087:
    switch (*(int *)(_l + 8)) {
    case 0: goto L_0099;
    case 1: goto L_00bb;
    case 2: goto L_00c5;
    case 3: goto L_014c;
    case 4: goto L_014c;
    case 5: goto L_0162;
    case 6: goto L_0172;
    case 7: goto L_0184;
    case 8: goto L_019c;
    case 9: goto L_01fc;
    case 10: goto L_021f;
    case 11: goto L_0244;
    case 12: goto L_026f;
    case 13: goto L_0279;
    case 14: goto L_0283;
    case 15: goto L_02c6;
    case 16: goto L_02e6;
    case 17: goto L_0338;
    case 18: goto L_0434;
    default: goto L_013e;
    }
L_0092:
L_0099:
    asm les bx,dword ptr [bp+6]
    asm les bx,dword ptr es:[bx+4]
    asm mov ax,es:[bx+6]
    asm mov dx,es:[bx+4]
    asm db 8bh, 0dfh	/* mov bx,di */
    asm shl bx,1
    asm db 3, 0d3h	/* add dx,bx */
    asm les bx,dword ptr [bp+6]
    asm mov es:[bx+2],ax
    asm mov es:[bx],dx
    asm jmp L_047b
L_00bb:
    asm les bx,dword ptr [bp+6]
    asm mov es:[bx+8],di
    asm jmp L_047b
L_00c5:
    asm db 8bh, 0c7h	/* mov ax,di */
    asm db 0bh, 0c0h	/* or ax,ax */
    asm jz L_00d2
    asm cmp ax,1
    asm jz L_00e7
    asm jmp L_013e
L_00d2:
    asm les bx,dword ptr [bp+6]
    asm mov ax,es:[bx+8]
L_00d9:
    asm les bx,dword ptr [bp+6]
    asm dec word ptr es:[bx+0ch]
    asm mov dx,es:[bx+0ch]
    asm jmp L_0261
L_00e7:
    asm les bx,dword ptr [bp+6]
    asm db 66h	/* mov eax,[es:bx] */
    asm mov ax,es:[bx]
    asm les bx,dword ptr es:[bx+4]
    asm db 66h	/* sub eax,[es:bx+0x4] */
    asm sub ax,es:[bx+4]
    asm db 66h, 0bbh, 2, 0, 0, 0	/* mov ebx,0x2 */
    asm db 66h	/* cdq */
    asm cwd
    asm db 66h	/* idiv ebx */
    asm idiv bx
    asm inc ax
    asm les bx,dword ptr [bp+6]
    asm dec word ptr es:[bx+0ch]
    asm mov dx,es:[bx+0ch]
    asm shl dx,1
    asm db 3, 0dah	/* add bx,dx */
    asm mov es:[bx+2ch],ax
    asm mov bx,[bp+6]
    asm mov ax,es:[bx+0ah]
    asm dec word ptr es:[bx+0ch]
    asm mov dx,es:[bx+0ch]
    asm shl dx,1
    asm db 3, 0dah	/* add bx,dx */
    asm mov es:[bx+2ch],ax
    asm mov bx,[bp+6]
    asm mov ax,es:[bx+0ch]
    asm add ax,2
    asm mov es:[bx+0ah],ax
    asm jmp L_047b
L_013e:
    asm les bx,dword ptr [bp+6]
    asm db 66h, 26h, 0c7h, 7, 0, 0, 0, 0	/* mov dword [es:bx],0x0 */
    asm jmp L_0011
L_014c:
    asm les bx,dword ptr [bp+6]
    asm dec word ptr es:[bx+0ch]
    asm mov ax,es:[bx+0ch]
    asm shl ax,1
    asm db 3, 0d8h	/* add bx,ax */
    asm mov es:[bx+2ch],di
    asm jmp L_047b
L_0162:
    asm db 8bh, 0c7h	/* mov ax,di */
    asm shl ax,1
    asm les bx,dword ptr [bp+6]
    asm db 3, 0d8h	/* add bx,ax */
    asm mov ax,es:[bx+0eh]
    asm jmp L_00d9
L_0172:
    asm les bx,dword ptr [bp+6]
    asm mov ax,es:[bx+0ah]
    asm db 8bh, 0d7h	/* mov dx,di */
    asm add dx,2
    asm neg dx
    asm db 3, 0c2h	/* add ax,dx */
    asm jmp L_018e
L_0184:
    asm les bx,dword ptr [bp+6]
    asm db 8bh, 0c7h	/* mov ax,di */
    asm add ax,es:[bx+0ah]
    asm dec ax
L_018e:
    asm shl ax,1
    asm les bx,dword ptr [bp+6]
    asm db 3, 0d8h	/* add bx,ax */
    asm mov ax,es:[bx+2ch]
    asm jmp L_00d9
L_019c:
    asm db 8bh, 0c7h	/* mov ax,di */
    asm db 0bh, 0c0h	/* or ax,ax */
    asm jz L_01a9
    asm cmp ax,1
    asm jz L_01bf
    asm jmp L_013e
L_01a9:
    asm les bx,dword ptr [bp+6]
    asm mov ax,es:[bx+0ch]
    asm inc word ptr es:[bx+0ch]
    asm shl ax,1
    asm db 3, 0d8h	/* add bx,ax */
    asm mov ax,es:[bx+2ch]
    asm jmp L_02bc
L_01bf:
    asm les bx,dword ptr [bp+6]
    asm cmp word ptr es:[bx+0ch],64h
    asm jnz L_01cc
    asm jmp L_013e
L_01cc:
    asm les bx,dword ptr [bp+6]
    asm mov ax,es:[bx+0ch]
    asm inc word ptr es:[bx+0ch]
    asm shl ax,1
    asm db 3, 0d8h	/* add bx,ax */
    asm mov ax,es:[bx+2ch]
    asm mov bx,[bp+6]
    asm mov es:[bx+0ah],ax
    asm mov ax,es:[bx+0ch]
    asm inc word ptr es:[bx+0ch]
    asm shl ax,1
    asm db 3, 0d8h	/* add bx,ax */
    asm mov di,es:[bx+2ch]
    asm jmp L_0099
    asm jmp L_013e
L_01fc:
    asm les bx,dword ptr [bp+6]
    asm mov ax,es:[bx+0ch]
    asm inc word ptr es:[bx+0ch]
    asm shl ax,1
    asm db 3, 0d8h	/* add bx,ax */
    asm mov ax,es:[bx+2ch]
    asm db 8bh, 0d7h	/* mov dx,di */
    asm shl dx,1
    asm mov bx,[bp+6]
    asm db 3, 0dah	/* add bx,dx */
    asm mov es:[bx+0eh],ax
    asm jmp L_047b
L_021f:
    asm les bx,dword ptr [bp+6]
    asm mov ax,es:[bx+0ch]
    asm inc word ptr es:[bx+0ch]
    asm shl ax,1
    asm db 3, 0d8h	/* add bx,ax */
    asm mov ax,es:[bx+2ch]
    asm mov bx,[bp+6]
    asm mov dx,es:[bx+0ah]
    asm db 8bh, 0dfh	/* mov bx,di */
    asm add bx,2
    asm neg bx
    asm db 3, 0d3h	/* add dx,bx */
    asm jmp L_0261
L_0244:
    asm les bx,dword ptr [bp+6]
    asm mov ax,es:[bx+0ch]
    asm inc word ptr es:[bx+0ch]
    asm shl ax,1
    asm db 3, 0d8h	/* add bx,ax */
    asm mov ax,es:[bx+2ch]
    asm mov bx,[bp+6]
    asm db 8bh, 0d7h	/* mov dx,di */
    asm add dx,es:[bx+0ah]
    asm dec dx
L_0261:
    asm shl dx,1
    asm les bx,dword ptr [bp+6]
    asm db 3, 0dah	/* add bx,dx */
    asm mov es:[bx+2ch],ax
    asm jmp L_047b
L_026f:
    asm les bx,dword ptr [bp+6]
    asm add es:[bx+0ch],di
    asm jmp L_047b
L_0279:
    asm les bx,dword ptr [bp+6]
    asm sub es:[bx+0ch],di
    asm jmp L_047b
L_0283:
    asm les bx,dword ptr [bp+6]
    asm les bx,dword ptr es:[bx+4]
    asm mov ax,es:[bx+10h]
    asm mov dx,es:[bx+0eh]
    asm mov word ptr _l+6,ax
    asm mov word ptr _l+4,dx
    asm db 8bh, 0c7h	/* mov ax,di */
    asm and ax,0ffh
    asm shl ax,2
    asm les bx,dword ptr _l+4
    asm db 3, 0d8h	/* add bx,ax */
    asm mov ax,es:[bx+2]
    asm mov dx,es:[bx]
    asm mov word ptr _l+2,ax
    asm mov word ptr _l,dx
    asm db 66h	/* push dword [bp+0x6] */
    asm push word ptr [bp+6]
    asm db 0ffh, 5eh, 0f6h	/* call word far [bp-0xa] */
    asm add sp,4
L_02bc:
    asm les bx,dword ptr [bp+6]
    asm mov es:[bx+8],ax
    asm jmp L_047b
L_02c6:
    asm les bx,dword ptr [bp+6]
    asm mov ax,es:[bx+0ch]
    asm inc word ptr es:[bx+0ch]
    asm shl ax,1
    asm db 3, 0d8h	/* add bx,ax */
    asm cmp word ptr es:[bx+2ch],0
    asm jz L_02df
    asm jmp L_047b
L_02df:
    asm and di,7fffh
    asm jmp L_0099
L_02e6:
    asm les bx,dword ptr [bp+6]
    asm mov ax,es:[bx+0ch]
    asm inc word ptr es:[bx+0ch]
    asm shl ax,1
    asm db 3, 0d8h	/* add bx,ax */
    asm mov dx,es:[bx+2ch]
    asm db 8bh, 0c7h	/* mov ax,di */
    asm db 0bh, 0c0h	/* or ax,ax */
    asm jz L_030c
    asm cmp ax,1
    asm jz L_0317
    asm cmp ax,2
    asm jz L_031b
    asm jmp L_013e
L_030c:
    asm db 8bh, 0c2h	/* mov ax,dx */
    asm neg ax
    asm db 1bh, 0c0h	/* sbb ax,ax */
    asm inc ax
    asm db 8bh, 0d0h	/* mov dx,ax */
    asm jmp L_0322
L_0317:
    asm neg dx
    asm jmp L_031d
L_031b:
    asm not dx
L_031d:
    asm jmp L_0322
    asm jmp L_013e
L_0322:
    asm les bx,dword ptr [bp+6]
    asm dec word ptr es:[bx+0ch]
    asm mov ax,es:[bx+0ch]
    asm shl ax,1
    asm db 3, 0d8h	/* add bx,ax */
    asm mov es:[bx+2ch],dx
    asm jmp L_047b
L_0338:
    asm les bx,dword ptr [bp+6]
    asm mov ax,es:[bx+0ch]
    asm inc word ptr es:[bx+0ch]
    asm shl ax,1
    asm db 3, 0d8h	/* add bx,ax */
    asm mov ax,es:[bx+2ch]
    asm mov word ptr _l+6,ax
    asm mov bx,[bp+6]
    asm mov ax,es:[bx+0ch]
    asm inc word ptr es:[bx+0ch]
    asm shl ax,1
    asm db 3, 0d8h	/* add bx,ax */
    asm mov dx,es:[bx+2ch]
    switch ((int)_DI) {
    case 0: goto L_0372;
    case 1: goto L_0385;
    case 2: goto L_0393;
    case 3: goto L_039c;
    case 4: goto L_03a5;
    case 5: goto L_03ae;
    case 6: goto L_03b7;
    case 7: goto L_03c0;
    case 8: goto L_03cc;
    case 9: goto L_03d3;
    case 10: goto L_03da;
    case 11: goto L_03e1;
    case 12: goto L_03e9;
    case 13: goto L_03f2;
    case 14: goto L_03fd;
    case 15: goto L_0404;
    case 16: goto L_040b;
    case 17: goto L_0415;
    default: goto L_013e;
    }
L_036b:
L_0372:
    asm db 0bh, 0d2h	/* or dx,dx */
    asm jz L_037e
    asm cmp word ptr _l+6,0
    asm jz L_037e
    asm jmp L_03c5
L_037e:
    asm db 33h, 0c0h	/* xor ax,ax */
L_0380:
    asm db 8bh, 0c8h	/* mov cx,ax */
    asm jmp L_041f
L_0385:
    asm db 0bh, 0d2h	/* or dx,dx */
    asm jnz L_03c5
    asm cmp word ptr _l+6,0
    asm jz L_037e
    asm jmp L_03c5
    asm jmp L_037e
L_0393:
    asm cmp dx,word ptr _l+6
    asm jnz L_037e
    asm jmp L_03c5
    asm jmp L_037e
L_039c:
    asm cmp dx,word ptr _l+6
    asm jz L_037e
    asm jmp L_03c5
    asm jmp L_037e
L_03a5:
    asm cmp dx,word ptr _l+6
    asm jnl L_037e
    asm jmp L_03c5
    asm jmp L_037e
L_03ae:
    asm cmp dx,word ptr _l+6
    asm jg L_037e
    asm jmp L_03c5
    asm jmp L_037e
L_03b7:
    asm cmp dx,word ptr _l+6
    asm jng L_037e
    asm jmp L_03c5
    asm jmp L_037e
L_03c0:
    asm cmp dx,word ptr _l+6
    asm jl L_037e
L_03c5:
    asm mov ax,1
    asm jmp L_0380
    asm jmp L_037e
L_03cc:
    asm db 8bh, 0cah	/* mov cx,dx */
    asm add cx,word ptr _l+6
    asm jmp L_041a
L_03d3:
    asm db 8bh, 0cah	/* mov cx,dx */
    asm sub cx,word ptr _l+6
    asm jmp L_041a
L_03da:
    asm db 8bh, 0c2h	/* mov ax,dx */
    asm imul word ptr _l+6
    asm jmp L_03f9
L_03e1:
    asm db 8bh, 0c2h	/* mov ax,dx */
    asm cwd
    asm idiv word ptr _l+6
    asm jmp L_03f9
L_03e9:
    asm db 8bh, 0c2h	/* mov ax,dx */
    asm mov cl,byte ptr _l+6
    asm sar ax,cl
    asm jmp L_03f9
L_03f2:
    asm db 8bh, 0c2h	/* mov ax,dx */
    asm mov cl,byte ptr _l+6
    asm shl ax,cl
L_03f9:
    asm db 8bh, 0c8h	/* mov cx,ax */
    asm jmp L_041f
L_03fd:
    asm db 8bh, 0cah	/* mov cx,dx */
    asm and cx,word ptr _l+6
    asm jmp L_041a
L_0404:
    asm db 8bh, 0cah	/* mov cx,dx */
    asm or cx,word ptr _l+6
    asm jmp L_041a
L_040b:
    asm db 8bh, 0c2h	/* mov ax,dx */
    asm cwd
    asm idiv word ptr _l+6
    asm db 8bh, 0cah	/* mov cx,dx */
    asm jmp L_041f
L_0415:
    asm db 8bh, 0cah	/* mov cx,dx */
    asm xor cx,word ptr _l+6
L_041a:
    asm jmp L_041f
    asm jmp L_013e
L_041f:
    asm les bx,dword ptr [bp+6]
    asm dec word ptr es:[bx+0ch]
    asm mov ax,es:[bx+0ch]
    asm shl ax,1
    asm db 3, 0d8h	/* add bx,ax */
    asm mov es:[bx+2ch],cx
    asm jmp L_047b
L_0434:
    asm les bx,dword ptr [bp+6]
    asm cmp word ptr es:[bx+0ch],64h
    asm jnz L_0441
    asm jmp L_013e
L_0441:
    asm les bx,dword ptr [bp+6]
    asm mov ax,es:[bx+0ch]
    asm inc word ptr es:[bx+0ch]
    asm shl ax,1
    asm db 3, 0d8h	/* add bx,ax */
    asm mov ax,es:[bx+2ch]
    asm mov bx,[bp+6]
    asm mov es:[bx+8],ax
    asm mov ax,es:[bx+0ch]
    asm inc word ptr es:[bx+0ch]
    asm shl ax,1
    asm db 3, 0d8h	/* add bx,ax */
    asm mov di,es:[bx+2ch]
    asm mov bx,[bp+6]
    asm mov word ptr es:[bx+0f4h],0
    asm jmp L_0099
    asm jmp L_013e
L_047b:
    asm mov ax,1
Lret:
    ;
}
