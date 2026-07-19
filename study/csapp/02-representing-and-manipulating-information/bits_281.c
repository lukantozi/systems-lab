#include <stdio.h>

/*
 * Write C expressions to generate the bit patterns that follow, where a^k represents
 * k repetitions of symbol a. Assume a w-bit data type. Your code may contain
 * references to parameters j and k, representing the values of j and k, but not a
 * parameter representing w.
 */

/* A. 1^(w−k)*0^k */
int repr_a(int k) {
    return ~0 << k;
}

/* B. 0^(w−k−j)*1^k*0^j */
int repr_b(int k, int j) {
    int zeros_right = ~0 << j;
    int mask = ~(~0 << (j + k));
    return zeros_right & mask;
}

int main(void) {
    printf("%08x\n", repr_a(8));
    printf("%08x\n", repr_b(12, 4));
}
