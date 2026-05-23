#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int tmult_ok_64(int x, int y) {
    int64_t p_64 = (int64_t) x*y;
    return p_64 == (int) p_64;
}

int main(void) {
    printf("tmult_ok_64: %d\n", tmult_ok_64(INT_MAX, 2));
    printf("tmult_ok_64: %d\n", tmult_ok_64(INT_MAX / 2, 3));
    printf("tmult_ok_64: %d\n", tmult_ok_64(INT_MAX / 3, 2));
    printf("tmult_ok_64: %d\n", tmult_ok_64(5, 2));
    printf("tmult_ok_64: %d\n", tmult_ok_64(INT_MIN, 2));
    printf("tmult_ok_64: %d\n", tmult_ok_64(INT_MIN, -2));
    printf("tmult_ok_64: %d\n", tmult_ok_64(100, 200));
}
