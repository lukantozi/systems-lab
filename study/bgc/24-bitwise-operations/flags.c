#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint8_t flags = 0;

    const uint8_t READ  = 1 << 0;
    const uint8_t WRITE = 1 << 1;
    const uint8_t EXEC  = 1 << 2;

    // set READ and WRITE
    flags |= READ;
    flags |= WRITE;

    printf("flags: 0x%02x\n", flags);

    // check if WRITE is set
    if (flags & WRITE) {
        printf("WRITE is set\n");
    }

    flags &= ~READ; // clear READ
    printf("flags after clear  READ: 0x%02x\n", flags);

    flags ^= EXEC; // toggle EXEC
    printf("flags after toggle EXEC: 0x%02x\n", flags);

    return 0;
}
