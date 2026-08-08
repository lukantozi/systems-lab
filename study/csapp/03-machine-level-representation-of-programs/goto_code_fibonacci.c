#include <stdio.h>

void fibonacci(int n) {
    int fib = 0;
    int fib_next = 1;
    int temp;
    if (n <= 0)
        goto done;
loop:
    printf("%d ", fib);
    temp = fib;
    fib = fib_next;
    fib_next = temp + fib_next;
    n--;
test:
    if (n > 0)
        goto loop;
    putchar('\n');
done:
}

int main(void) {
    fibonacci(9);
    fibonacci(5);
    fibonacci(0);
}
