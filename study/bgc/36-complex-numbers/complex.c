#ifdef __STC_NO_COMPLEX__
#error Complex numbers not supported!
#endif

#include <complex.h>

#if __STDC_IEC_559_COMPLEX__ != 1
#error Need IEC 60559 complex support!
#endif

#include <stdio.h>

int main(void) {
    double complex x = 5 + 2*I;
    double complex y = 10 + 3*I;

    printf("x = %f + %fi\n", creal(x), cimag(x));
    printf("y = %f + %fi\n", creal(y), cimag(y));

    double a = 5;
    double b = 2;
    double complex z = a + b*I;     // may convert negative 0s to positive
    double complex r = CMPLX(5, 2); // will handle negative 0s correctly

}
