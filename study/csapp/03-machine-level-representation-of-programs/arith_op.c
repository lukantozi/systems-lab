#include <stdio.h>

// arith:
//     leaq    15(%rdi), %rbx
//     testq   %rdi, %rdi
//     cmovns  %rdi, %rbx
//     sarq    $4, $rbx
//     ret

/*
 * adding 15 to x is adding bias (2^k-1) when
 * x is negative, so that before division by 16 
 * (>>4), negative-number rounding is corrected;
 * C division would truncate toward zero, and by
 * adding 15, we make sure arithmetic shift matches
 * the result of division
 */
#define OP /

/* x in %rdi */
short arith(short x) {
    return x OP 16;
}

int main() {
    printf("%d\n", arith(17));
    printf("%d\n", arith(-17));
}
