#include <stdio.h>

#define X(a, b, ...) (10*(a)) + (20*(b)), __VA_ARGS__
#define Y(a, b, ...) (10*(a)) + (20*(b)), #__VA_ARGS__
#define STR(...) #__VA_ARGS__
#define STR_ONE(x) #x
#define PRINT_INT_VAL(x) printf("%s = %d\n", #x, x)
#define CAT(a, b) a ## b

int main(void) {
    printf("%d %.2f %s\n", X(5, 4, 4.4*2, "hello"));
    printf("%d %s\n", Y(5, 4, 4.4*2, "hello"));

    printf("%s\n", STR(4 5/6*6));
    printf("%s\n", STR(4.3));

    int a = 5;
    PRINT_INT_VAL(a);

    printf("%f\n", CAT(3.14, 1592));
    printf("%d\n", CAT(5, 12));
}
