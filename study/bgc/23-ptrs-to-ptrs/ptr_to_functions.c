#include <stdio.h>

void print_int(int x) {
    printf("%d\n", x);
}

int add(int a, int b) {
    return a + b;
}

int mult(int a, int b) {
    return a * b;
}

void print_math(int (*op)(int, int), int x, int y) {
    int res = op(x, y);
    printf("result: %d\n", res);
}

int main(void) {
    void (*p)(int) = print_int;
    p(24);

    print_math(add, 2, 5);
    print_math(mult, 5, 10);
}
