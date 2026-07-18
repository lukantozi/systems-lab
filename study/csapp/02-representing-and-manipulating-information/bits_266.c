#include <stdio.h>

/*
* Generate mask indicating leftmost 1 in x. Assume w=32.
* For example, 0xFF00 -> 0x8000, and 0x6600 -> 0x4000.
* If x = 0, then return 0. 
*/
int leftmost_one(unsigned x) {
    x |= x >> 16;
    x |= x >> 8;
    x |= x >> 4;
    x |= x >> 2;
    x |= x >> 1;
    x &= ~(x >> 1);
    return x;
}

//  0110 0110 0001 1000 x |= x >> 8
//  0110 0110 0111 1110 x |= x >> 4
//  0110 0110 0111 1111 x |= x >> 2
//  0111 1111 1111 1111 x &= ~(x >> 1)
//  0100 0000 0000 0000

int main(void) {
    printf("0x%x\n", leftmost_one(0xFF00));
    printf("0x%x\n", leftmost_one(0x6600));
    printf("0x%x\n", leftmost_one(0));
}
