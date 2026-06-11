#include <stdio.h>

#define HAPPY_FACTOR 1

int main(void) {

#if HAPPY_FACTOR == 0
    printf("Not happy\n");
#elif HAPPY_FACTOR == 1
    printf("Happy\n");
#else
    printf("Extra happy\n");
#endif

    printf("I'm ok\n");
}
