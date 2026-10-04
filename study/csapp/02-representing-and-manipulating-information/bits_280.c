#include <stdio.h>
#include <limits.h>

/* CS:APP 3e, Problem 2.80: compute three-fourths of x with truncation
 * toward zero, avoiding intermediate overflow. */
int threefourths(int x) {
    int xs_mask = ~(!!(x & ~(UINT_MAX >> 1))) + 1;
    int bias = 3 & xs_mask;
    int div4 = (x + bias) >> 2;

    int rem = x - (div4 << 2);
    rem = (rem << 1) + rem;
    int rems_mask = ~(!!(rem & ~(UINT_MAX >> 1))) + 1;
    bias = 3 & rems_mask;
    rem = (rem + bias) >> 2;

    int mult3 = (div4 << 1) + div4 + rem;
    return mult3;
}

int main(void) {
    printf("-5 * (3/4): %d\n", threefourths(-5));
    printf(" 5 * (3/4): %d\n", threefourths(5));
    printf("-7 * (3/4): %d\n", threefourths(-7));
    printf(" 7 * (3/4): %d\n", threefourths(7));
}
