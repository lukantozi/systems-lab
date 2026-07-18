#include <stdio.h>
#include <limits.h>

/* The function should compute x/2^k with correct rounding, and it should follow
 * the bit-level integer coding rules (page 164). */

/* Divide by power of 2. Assume 0 <= k < w-1 */
int divide_power2(int x, int k) {
    /* if negative: 0xFF..., if non-negative: 0x00.. */
    int xs = ~(!!(x & ~(UINT_MAX >> 1))) + 1;
    /* if non-negative: no bias; if negative: bias applies */
    return (~xs & x >> k) | (xs & ((x + (1 << k) - 1) >> k));
}

int main(void) {
    int x = divide_power2(10, 2);
    printf("x: %d\n", x);
    x = divide_power2(-13, 2);
    printf("x: %d\n", x);
}
