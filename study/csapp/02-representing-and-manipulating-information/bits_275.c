#include <limits.h>
#include <stdio.h>
/*
 * Suppose we want to compute the complete 2w-bit representation of x . y, where
 * both x and y are unsigned, on a machine for which data type unsigned is w bits.
 * The low-order w bits of the product can be computed with the expression x*y, so
 * we only require a procedure with prototype
 */

unsigned unsigned_high_prod(unsigned x, unsigned y);
/*
 * that computes the high-order w bits of x . y for unsigned variables.
 * We have access to a library function with prototype
 */

int signed_high_prod(int x, int y);

/*
 * that computes the high-order w bits of x . y for the case where x and y are in two’s-
 * complement form. Write code calling this procedure to implement the function
 * for unsigned arguments. Justify the correctness of your solution.
 *
 * Hint: Look at the relationship between the signed product x . y and the un-
 * signed product x′ . y′ in the derivation of Equation 2.18.
 */

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
