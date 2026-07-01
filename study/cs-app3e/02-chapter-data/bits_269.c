#include <stdio.h>
#include <assert.h>

/*
* Do rotating left shift. Assume 0 <= n < w
* Examples when x = 0x12345678 and w = 32:
* n=4 -> 0x23456781, n=20 -> 0x67812345
*/
unsigned rotate_left(unsigned x, int n) { // careful with n == 0
    unsigned w = sizeof(unsigned) << 3;
    unsigned extr = (x & ~(-1U >> n)) >> (w - n);
    x = (x << n) | extr;
    printf("%08x\n", x);
    return x;
    // more robust solution
    // (x << n) | (x >> (w - n))
}

int main(void) {
    assert(rotate_left(0x12345678, 4) == 0x23456781);
    assert(rotate_left(0x12345678, 20) == 0x67812345);
    assert(rotate_left(0x12345678, 0) == 0x12345678);
}
