#include <stdio.h>

//#define HAPPY
#define REGULAR

int main(void) {

#ifdef HAPPY
    printf("I'm happy!\n");
#elif defined REGULAR // from C23 compiler #elifdef possible 
    printf("I'm just regular.\n");
#else
    printf("Just hangind around.\n");
#endif

    printf("I'm ok.\n");
}
