#include <stdio.h>

bool evaluate(int *x, int *y) {
    printf("%04x\n", (*x ^ *y));
    return !(*x ^ *y);
}

int main(void) {
    int a = 123;
    int b = 123;
    printf("%d\n", evaluate(&a, &b));
    a = 23;
    b = 123;
    printf("%d\n", evaluate(&a, &b));
}
