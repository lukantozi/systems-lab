#include <stdio.h>
#include <complex.h>

int factorial(int n, int a) {
tco:

    if (n == 0) {
        return a;
    }

    //return factorial(n - 1, a * n);

    int next_n = n - 1; // matching the recursive
    int next_a = a * n; // args above

    n = next_n; // set the params
    a = next_a; // to the new values

    // this would work just fine too
    // a *= n;
    // n--;

    goto tco; // and repeat
}

int main(void) {
    for (int i = 0; i < 8; i++) {
        printf("%d! = %ld\n", i, factorial(i, 1));
    }
}
