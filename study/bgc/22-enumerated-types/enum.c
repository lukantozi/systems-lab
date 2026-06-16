#include <stdio.h>

enum {
    ONE=1,
    TWO=2
};

enum {
    SOME,
    RANDOM,
    VALUES,
    THAT,
    WILL,
    GET,
    ENUMED
};

enum {
    X=2,
    Y=2,
    Z=2
};

enum {
    A,
    B,
    C=10,
    D,
    E,
    F,
    G=2,
    H,
    J
};

int main(void) {
    printf("%d, %d\n", ONE, TWO);
    printf("%d %d %d\n", THAT, GET, SOME);
    printf("%d %d %d\n", X, Y, Z);
    printf("%d %d %d\n", B, D, H);
}
