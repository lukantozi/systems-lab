#include <stdio.h>

/* Sum even numbers between 0 and 9 */
long sum_even(void) {
    long sum = 0;
    long i;
    for (i = 0; i < 10; i++) {
        if (i & 1)
            continue;
        sum += i;
    }
    return sum;
}

long sum_even_while(void) {
    long sum = 0;
    long i = 0;
    while (i < 10) {
        if (i & 1) {
            i++;
            continue;
        }
        sum += i;
        i++;
    }
    return sum;
}

long sum_even_goto(void) {
    long sum = 0;
    long i = 0;
loop:
    if (i & 1)
        goto loop_continue;
    sum += i;
loop_continue:
    i++;
    if (i < 10)
        goto loop;
    return sum;
}

int main(void) {
    printf("%ld\n", sum_even());
    printf("%ld\n", sum_even_while());
    printf("%ld\n", sum_even_goto());
}
