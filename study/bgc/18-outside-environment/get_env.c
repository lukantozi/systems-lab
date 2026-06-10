#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *env = getenv("FROTZ");
    if (env == NULL) {
        fprintf(stderr, "Can't find FROTZ env variable\n");
        return EXIT_FAILURE;
    }
    printf("Value: %s\n", env);
}
