#include <stdio.h>

int div16(int x) {
    int bias = (x >> 31) & 15;
    return (x + bias) >> 4;
}

int main(void) {
    printf("%d/16 = %d\n", 5, div16(5));
    printf("%d/16 = %d\n", 20, div16(20));
    printf("%d/16 = %d\n", 81, div16(81));
    printf("%d/16 = %d\n", -81, div16(-81));
    printf("%d/16 = %d\n", -33, div16(-33));
}
