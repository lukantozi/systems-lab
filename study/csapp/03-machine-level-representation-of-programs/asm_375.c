#include <complex.h>

double c_imag(double complex x) {
    return cimag(x);
}

double c_real(double complex x) {
    return creal(x);
}

double complex c_sub(double complex x, double complex y) {
    return x - y;
}

c_imag:
    movapd %xmm1, %xmm0
    ret

c_real:
    rep; ret

c_sub:
    subsd %xmm2, %xmm0
    subsd %xmm3, %xmm1
    ret

/*
    A. A double complex argument uses two consecutive XMM registers:
       real first, imaginary second.
    
    B. A double complex return value uses:
       real part in %xmm0,
       imaginary part in %xmm1.
*/
