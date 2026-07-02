#include <stdalign.h>
#include <stddef.h>

char alignas(int) c;

char alignas(8) t; // align on 8-byte boundaries

char alignas(max_align_t) k;
