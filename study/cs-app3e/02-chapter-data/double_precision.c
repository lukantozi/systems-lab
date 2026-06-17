#include <stdio.h>

#define MY_IMPL 0

#if MY_IMPL
/* 
 * my implementation; not portable 
 * C does not guarantee +inf, -inf...
 * most IEEE systems do, but not
 * standard confirming
 */
#define POS_INFINITY ((double)  1 / 0)
#define NEG_INFINITY ((double) -1 / 0)
#define NEG_ZERO     -(double)  0

#else
/*
 * book implementation
 * assuming 1e400 overflows to infinity
 * portable enough for most IEEE systems,
 * but not ideal
 */
#define POS_INFINITY 1e400
#define NEG_INFINITY -POS_INFINITY
#define NEG_ZERO     (-1.0/POS_INFINITY) 

#endif

int main(void) {
    printf("%f\n", POS_INFINITY);
    printf("%f\n", NEG_INFINITY);
    printf("%f\n", NEG_ZERO);
}
