#include <stdio.h>
#include <assert.h>

/*
* Mask with least signficant n bits set to 1
* Examples: n = 6 --> 0x3F, n = 17 --> 0x1FFFF
* Assume 1 <= n <= w
*/
int lower_one_mask(int n) {
    int w = sizeof(int) << 3;
    int mask = -1U >> (w - n);
    printf("%08x\n", mask);
    return mask;
}

int UB_lower_one_mask(int n) { // need to be cautious with n == w
    // get 1 on msb and then popagate it w - 1 - n times
    // then ~ it to get least significant n bits set to 1
    int w_1 = (sizeof(int) << 3) - 1;
    int mask = ~((1 << w_1) >> (w_1 - n)); // works for me but it's UB
                                           // !!!!!!!!!!!!!!!!!!!!!!!!
    // in case n == w, OR the mask with 0xFFFFFFFF
    // we will get 0xFFFFFFFF only if (mask == 0);
    mask |= ((mask == 0) << w_1) >> w_1;
    printf("%08x\n", mask);
    return mask;
}

int main(void) {
    assert(lower_one_mask(6) == 0x3F);
    assert(lower_one_mask(17) == 0x1FFFF);
    assert(lower_one_mask(32) == 0xFFFFFFFF);
}
