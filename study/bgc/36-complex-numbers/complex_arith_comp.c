#include <stdio.h>
#include <complex.h>

int main(void) {
    double complex x = 1 + 2*I;
    double complex y = 3 + 4*I;
    double complex z;

    z = x + y;
    printf("x + y = %f + %fi\n", creal(z), cimag(z));

    z = x - y;
    printf("x - y = %f + %fi\n", creal(z), cimag(z));

    z = x * y;
    printf("x * y = %f + %fi\n", creal(z), cimag(z));

    z = x / y;
    printf("x / y = %f + %fi\n", creal(z), cimag(z));

    double complex k = 1 + 2*I;
    double complex r = 3 + 4*I;

    printf("k == r -> %d\n", k == r);
    printf("k != r -> %d\n", k != r);
}
