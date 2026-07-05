#include <stdio.h>
#include <limits.h>

/*
 * Instead of overflowing the way normal two’s-complement addition does, sat-
 * urating addition returns TMax when there would be positive overflow, and TMin
 * when there would be negative overflow. Saturating arithmetic is commonly used
 * in programs that perform digital signal processing.
 */

/* Addition that saturates to TMin or TMax */
int saturating_add(int x, int y) {
    int w_1 = (sizeof(int) << 3) - 1;
    int s   = x + y;

    // signs
    int xs = x >> w_1;
    int ys = y >> w_1;
    int ss = s >> w_1;

    // overflows
    int o  = (xs ^ ss) & (ys ^ ss);
    int po = -(!xs && !ys && ss);
    int no = -(xs && ys && !ss);

    return (~o & s) | (po & INT_MAX) | (no & INT_MIN);
}

int main(void) {
    printf("%d -- %d\n", INT_MIN, INT_MAX);
    printf("INT_MAX + 2 = %d\n", saturating_add(INT_MAX, 2));
    printf("INT_MAX - 2 = %d\n", saturating_add(INT_MAX, -2));
    printf("INT_MIN - 2 = %d\n", saturating_add(INT_MIN, -2));
    printf("INT_MIN + 2 = %d\n", saturating_add(INT_MIN, 2));
    printf("100 + 23    = %d\n", saturating_add(100, 23));
    printf("100 - 23    = %d\n", saturating_add(100, -23));
    printf("-23 + 100   = %d\n", saturating_add(-23, 100));
}
