#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void) {
    int32_t n = 14;
    int32_t x = 1;
    int32_t nill = 0;
    do {
        x *= n;
        n -= 1;
    } while (n > nill);
    printf("%" PRId32 "\n", x); /* overflows: 14! % 2^32 */

    int64_t m = 14;
    int64_t y = 1;
    do {
        y *= m;
        m -= 1;
    } while (m > 0);
    printf("%" PRId64 "\n", y); /* represents correctly */
}
