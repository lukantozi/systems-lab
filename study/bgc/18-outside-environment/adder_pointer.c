#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    long sum = 0;
    char *err = NULL;
    for (char **p = argv + 1; *p != NULL; p++) {
        sum += strtol(*p, &err, 10);
        if (*err != '\0') {
            fprintf(stderr, "%s: not an integer\n", *p);
            return 1;
        }
    }
    printf("%ld\n", sum);
}
