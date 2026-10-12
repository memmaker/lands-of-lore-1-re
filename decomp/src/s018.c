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

/* NONMATCHING original keeps dead jmps after inner switches */
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
