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

int tadd_k(int x, int y) {
    if (x < 0 && y < 0 && x + y >= 0) return 0;
    if (x >= 0 && y >= 0 && x + y < 0) return 0;
    return 1;
    /* book solution
     * int sum = x+y;
     * int neg_over = x < 0 && y < 0 && sum >= 0;
     * int pos_over = x >= 0 && y >= 0 && sum < 0;
     * return !neg_over && !pos_over;
    */
}

int main(void) {
    int uok = uadd_ok(4294967273, 23);
    printf("%d\n", uok);

    int tok = tadd_k(4294967273/3, 123);
    printf("%d\n", tok);
    int tok1 = tadd_k(4294967273/2, 123);
    printf("%d\n", tok1);
    return 0;
}
