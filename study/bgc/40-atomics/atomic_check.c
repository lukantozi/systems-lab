#include <stdio.h>

int main(void) {
#if __STDC_VERSION__ < 201112L || __STDC_NO_ATOMICS__ == 1
#define HAS_ATOMICS 0
    printf("we don't have atomics\n");
#else
#define HAS_ATOMICS 1
    printf("we have atomics\n");
#endif // atomics
    return 0;
}
