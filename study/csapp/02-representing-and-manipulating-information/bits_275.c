#include <limits.h>
#include <stdio.h>

/* CS:APP 3e, Problem 2.75.
 * Compute an unsigned product's high word using signed_high_prod(). */

unsigned unsigned_high_prod(unsigned x, unsigned y);
int signed_high_prod(int x, int y);

unsigned unsigned_high_prod(unsigned x, unsigned y) {
    unsigned tbit = ~(UINT_MAX >> 1);
    /* getting top bits of x and y */
    unsigned sx = !!(x & tbit);
    unsigned sy = !!(y & tbit);

    /* deriving the answer using formula 2.18:
     *
     * x'y' = x*y + (x*y(w-1) + y*x(w-1))*2^w + x(w-1)*y(w-1)*2^(2*w) 
     * x' and y' are the unsigned interpretations; x and y are the
     * signed interpretations of the same bit patterns.
     *
     * To extract a high word, divide the full product by 2^w and
     * retain w bits. The middle term therefore becomes sx * y + sy * x.
     * The final term still contains 2^w after division, so it overflows
     * the returned high word.
     */
    return signed_high_prod(x, y) + sx * y + sy * x;
}
