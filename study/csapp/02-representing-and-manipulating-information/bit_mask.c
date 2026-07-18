#include <stdio.h>

void show_least_significant(int *x) {
    printf("%08x\n", *x & 0xff);
}

void show_all_but_least_significant_complement(int *x) {
    printf("%08x\n", *x ^ ~0xff);
}

void show_least_significant_ones(int *x) {
    printf("%08x\n", *x | 0xff);
}

int main(void) {
    int x = 0x87654321;
    show_least_significant(&x);
    show_all_but_least_significant_complement(&x);
    show_least_significant_ones(&x);
}
