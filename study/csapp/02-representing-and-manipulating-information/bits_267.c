#include <limits.h>

/* CS:APP 3e, Problem 2.67: detect a 32-bit int without sizeof.
 * The supplied example below is examined for invalid shifts.
 */

/* The following code does not run properly on some machines */
int bad_int_size_is_32() {
    /* Set most significant bit (msb) of 32-bit machine */
    int set_msb = 1 << 31;
    /* Shift past msb of 32-bit word */
    int beyond_msb = 1 << 32;

    /* set_msb is nonzero when word size >= 32
       beyond_msb is zero when word size <= 32 */
    return set_msb && !beyond_msb;
} // On a 32-bit SUN SPARC: warning: left shift count >= width of type


/*
 * A: Analysis of the supplied example.
 * On a 32-bit or smaller bit size architectures, shifting bits 32 times
 * to left is UB
 */


/* B: My attempt for implementations with int widths of at
 * least 32 bits. */
int int_size_is_32_on_at_least_32() {
    // derive one
    int msb = -1 & (1 << 31);

    return msb == INT_MIN;
}

/* C: My attempt for implementations with int widths of at
 * least 16 bits. */
int int_size_is_32_on_at_least_16() {
    // derive msb by shifting bits
    // in safe chunks
    int msb = 1 << 15;
    msb <<= 15;
    msb <<= 1;
    int beyond_msb = msb << 1;
    return msb && !beyond_msb;
}
