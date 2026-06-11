#include <stdio.h>

int main(void) {
#define GOATS

#ifdef GOATS
    printf("Goats detected!\n");
#endif

#undef GOATS

#ifdef GOATS
    printf("Goats detected again!\n"); // won't print
#endif
}
