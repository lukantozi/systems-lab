#include <stdio.h>
#include "bytes.h"

/*
 * Fill in code for the following C functions. Function srl performs a logical right
 * shift using an arithmetic right shift (given by value xsra), followed by other oper-
 * ations not including right shifts or division. Function sra performs an arithmetic
 * right shift using a logical right shift (given by value xsrl), followed by other
 * operations not including right shifts or division. You may use the computation
 * 8*sizeof(int) to determine w, the number of bits in data type int. The shift
 * amount k can range from 0 to w − 1.
 */

unsigned srl(unsigned x, int k) {
    /* Perform shift arithmetically */
    unsigned xsra = (int) x >> k;

    int w = (sizeof(int) << 3) - k;
    int mask = (-1 << w) ^ (-1);
    return xsra & mask;
}


int sra(int x, int k) {
    /* Perform shift logically */
    int xsrl = (unsigned) x >> k;

    int w = (sizeof(int) << 3) - k;
    int w_1 = (sizeof(int) << 3) - 1;
    int mask = (-(!!(x & (1 << w_1)))) << w;
    return xsrl | mask;
}

int main(void) {
    unsigned x = srl(0xFFFFFFFF, 4);
    show_bytes((byte_pointer) &x, sizeof(unsigned));
    putchar('\n');
    unsigned y = srl(0x0FFFFFFF, 4);
    show_bytes((byte_pointer) &y, sizeof(unsigned));

    putchar('\n');
    int z = sra(0xFF0FFFFF, 8);
    show_bytes((byte_pointer) &z, sizeof(int));
    putchar('\n');
    int k = sra(0x7FFFFFFF, 8);
    show_bytes((byte_pointer) &k, sizeof(int));
}
