#include <stdio.h>

#define PRINT_TO_MULT(a, b) do { \
    int mult = (a) * (b); \
    for (int i = 0; i < mult; i++) { \
        printf("%d\n", i); \
    } \
} while (0)

int main(void) {
    PRINT_TO_MULT(2, 4);
}
