#include <stdio.h>

/* 
 * this algorithm halves the time for calculating 
 * a^n by utilizing the idea that n = n/2 + n/2; 
 * if n is even => a^n = (a^(n/2))^2, and if odd =>
 * a^n = a(a^(n/2))^2; in either case we are achieving
 * the mutliplication in O(lgn) time, while if calculated
 * traditionally, multiplying a (n - 1) times, we would get O(n). */
int power(int a, int n) {
    if (n == 0) return 1;

    long x = power(a, n / 2);

    if (n % 2 == 0) return x * x;
    else return a * x * x;
}

int main(void) {
    int res = power(2, 3);
    printf("2^3 = %d\n", res);
    res = power(2, 11);
    printf("2^11 = %d\n", res);
}
