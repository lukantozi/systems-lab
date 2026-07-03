#include <stdio.h>

/*
* Return 1 when x can be represented as an n-bit, 2’s-complement
* number; 0 otherwise
* Assume 1 <= n <= w
*/
int fits_bits(int x, int n) {
#if 0
    int ms = -1 << n;
    int n_min = ~ms & (-1 << (n - 1));
    int n_max = n_min ^ ~ms;
    printf("n    : %d\n", n);
    printf("n_min: %x\n", n_min);
    printf("n_max: %x\n", n_max);
#else
    /* 
     * if x is positive, we get all 0s, if negative 1s
     * we push n - 1 bit down to 0th bit, and extend
     * the sign behind it. if x were to fit n bit two's
     * complement representation, after the shift all the
     * bits should be either 0s or 1s, which we confirm
     * by comparing it to x's sign broadcast to all the bits.
     * if x does not fit, then there would be some other values
     * other than all 1s or 0s, giving us evaluation to 0 (false).
     * we get the comparison by XOR ing two values, and then, if
     * they are equal, all the bits will be 0s, !0 == 1, if values
     * were different, we would have 1 somewhere, !nonzero == 0.
     */
    return !((x >> ((sizeof(int) << 3) - 1)) ^ (x >> (n - 1)));
#endif
}

/* n=2 -> 01     -> 1  <-> -2
 * n=3 -> 011    -> 3  <-> -4
 * n=4 -> 0111   -> 7  <-> -8
 * n=5 -> 01111  -> 15 <-> -16
 * n=6 -> 011111 -> 31 <-> -32
 */

int main(void) {
    printf("%d\n", fits_bits(5, 4));
    printf("%d\n", fits_bits(-32, 6));
    printf("%d\n", fits_bits(-33, 6));
}
