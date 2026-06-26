#include <stdio.h>
#include "bytes.h"

/* Return 1 when any odd bit of x equals 1; 0 otherwise.
Assume w=32 */
int any_odd_one(unsigned x) {
    return !!(x & 0xaaaaaaaa);
}

int main(void) {
    unsigned x = 0x55555556;
    printf("%d\n", any_odd_one(x));
    unsigned y = 0x55555555;
    printf("%d\n", any_odd_one(y));
}
