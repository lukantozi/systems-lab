#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

int has_1(int x) {
    /* any number that is not 0 will evaluate to 0, and then
     * to 1; any number that is 0, will evaluate to 1, and then
     * to 0; */
    return !!x;
}

int has_0(int x) {
    /* we are XOR ing all 1's and x
     * which will give 1's only if there
     * is any 0s in x; then we apply the 
     * similar logic as in has_1 */
    return !!(x ^ ~0);
}

int has_1_ls(int x) {
    /* we leave only least significant
     * byte by turning rest of the x to
     * zeros, then applying same pattern
     * as in has_1 */
    return !!(x & 0xFF);
}

int has_0_bs(int x) {
    /* prepare mask for MS byte*/
    int shift = (sizeof(int) - 1) << 3;
    int mask = ~0 << shift;
    /* apply mask so that x's MS byte
     * takes the form we can shift and
     * get something we can XOR and find
     * if we have 0's or not */
    x = (x & mask);
    x >>= shift;
    return !!(x ^ ~0);
}

int main(void) {
    int xq = 0xFEFFFFFF;
    printf("%d\n", has_0_bs(xq));
}
