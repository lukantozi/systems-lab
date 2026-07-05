#include <stdio.h>
#include <limits.h>

/* Determine whether arguments can be subtracted without overflow */
int tsub_ok(int x, int y) { // = 1 if does not overflow
    int w_1 = (sizeof(int) << 3) - 1;
    int d   = x - y;

    int xs =  x >> w_1;
    int ys =  ~(y >> w_1);
    int ds =  d >> w_1;

    int o = ~((xs ^ ds) & (ys ^ ds));
    return -o;
}

int main(void) {
    printf("%d\n", tsub_ok(INT_MIN, 1));
    printf("%d\n", tsub_ok(INT_MIN + 1, 2));
    printf("%d\n", tsub_ok(1, INT_MAX));
    printf("%d\n", tsub_ok(1, 2));
    printf("%d\n", tsub_ok(1, INT_MIN));
}
