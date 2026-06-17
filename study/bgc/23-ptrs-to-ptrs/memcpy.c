#include <stdio.h>

void *my_memcpy(void *dest, const void *src, size_t n) {
    const unsigned char *s = src;
    unsigned char *d = dest;

    while (n-- > 0) *d++ = *s++;

    return dest;
}

int main(void) {
    int x = 5, y;
    if (my_memcpy(&y, &x, sizeof x) != NULL) printf("%d\n", y);
}
