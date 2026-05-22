#include <stdio.h>

void swap(int *restrict a, int *restrict b) {
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int x = 10, y = 20;
    printf("before: x: %d, y: %d\n", x, y);
    swap(&x, &y);
    printf(" after: x: %d, y: %d\n", x, y);
    //swap(&x, &x); // undefined behavior
}
