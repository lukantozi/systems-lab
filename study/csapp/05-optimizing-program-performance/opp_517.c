#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef unsigned long word;
#define K (sizeof(unsigned long))

/* optimized implementation of memset */
void *memset_opt(void *a, int c, size_t n)
{
    unsigned long byte = (unsigned char) c;
    unsigned char *achar_align = a;
    size_t rem = n;
    word packed = 0;

    while (rem > 0 && (uintptr_t) achar_align % K != 0) {
        *achar_align++ = (unsigned char) c;
        rem--;
    }

    for (size_t i = 0; i < K; i++) {
        packed |= byte << (8 * i);
    }

    word *achar  = (word *) achar_align;
    while (rem > K) {
        *achar++ = packed;
        rem -= K;
    }

    unsigned char *fill = (unsigned char *) achar;
    while (rem > 0) {
        *fill++ = (unsigned char) c;
        rem--;
    }

    return a;
}

int main(void)
{
    int some[10];
    memset_opt(some, 1, sizeof(some));
    for (int i = 0; i < 10; i++)
        printf("%d\n", some[i]);
}
