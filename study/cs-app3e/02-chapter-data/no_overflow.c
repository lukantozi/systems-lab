#include <stdio.h>

/* Determine whether arguments can be added without overflow */
int uadd_ok(unsigned x, unsigned y) {
    if (x + y < x) return 0;
    return 1;
    /* Idiomatic C solution
     * unsigned sum = x+y;
     * return sum >= x;
     */
}

int main(void) {
    int ok = uadd_ok(4294967273, 23);
    printf("%d\n", ok);
    return 0;
}
