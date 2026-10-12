/* s126: WW library -- random number in [lo, hi] (bounds swapped if needed) */
#include <stdlib.h>

unsigned far fn_2164_000d(unsigned lo, unsigned hi)
{
    unsigned r;
    if (lo > hi) {
        lo ^= hi;
        hi ^= lo;
        lo ^= hi;
    }
    while ((r = (int)((long)rand() * (hi - (lo - 1)) / 0x8000L) + lo) > hi)
        ;
    return r;
}
