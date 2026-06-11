#include <stdio.h>
#include <stdlib.h>

#ifndef __STDC_IEC_559__
    #error I really need IEEE-754 floating point to compile.
#endif

#define ASSERT_ENABLED 1

#if ASSERT_ENABLED
#define ASSERT(c, m) do { \
    if (!(c)) { \
        fprintf(stderr, __FILE__ ":%d: assertion %s failed: %s\n", \
                __LINE__, #c, m); \
        exit(1); \
    } \
} while(0)
#else
#define ASSERT(c, m)
#endif

int main(void) {
    int x = 30;
    ASSERT(x < 20, "must be under 20");
}
