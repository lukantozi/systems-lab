#include <stdatomic.h>

atomic_int x = 0;

void thread1() {
    x = x + 3; // NOT atomic
}

void thread2() {
    x += 3;    // ATOMIC
}

atomic_int a = 0;
int b = 3;
/* 
 * in this example, a is atomic
 * and all the operations are atomic
 * read-modify-write operations with
 * sequential consistency
 */
void example() {
    a++;      a--;      --a;      ++a;
    a += b;   a -= b;   a *= b;   a /= b;    a %= b;
    a &= b;   a |= b;   a ^= b;   a >>= b;   a <<= b;
}
