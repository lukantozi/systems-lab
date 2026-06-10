#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    long sum = 0;
    int i;
    char *err = NULL;
    for (i = 1; i < argc; i++) {
        sum += strtol(argv[i], &err, 10);
        if (*err != '\0') {
            fprintf(stderr, "%s: not an integer\n", argv[i]);
            return 1;
        }
    }
    printf("%ld\n", sum);
    return 0;
}
