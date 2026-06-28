#include <stdint.h>

int main(void) {
    int32_t w;       // w is exactly 32 bits, signed
    uint16_t x;      // k is exactly 16 bits, unsigned

    int_least8_t y;  // y is at least 8 bits, signed
    uint_fast64_t z; // z is the fastest representation at least 64 bits, unsigned

    // fixed sized constants
    uint16_t k = UINT16_C(12);
    intmax_t r = INTMAX_C(3490);
}
