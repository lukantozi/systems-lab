#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint8_t x = 5;

    printf("x      = %u\n", x);
    printf("x << 1 = %u\n", x << 1);
    printf("x << 2 = %u\n", x << 2);
    printf("x >> 1 = %u\n", x >> 1);
    printf("x >> 2 = %u\n", x >> 2);

    uint8_t y = 0xAB;               // 1010 1011
    uint8_t high = (y >> 4) & 0x0F; // 0000 1010
    uint8_t low  = y & 0x0F;        // 0000 1011

    printf("y    = 0x%02x\n", y);
    printf("high = 0x%01x\n", high);
    printf("low  = 0x%01x\n", low);

    return 0;
}
