#include <stdio.h>
#include <stdlib.h>

long validate(const char *arg) {
    char *err;
    long num = strtol(arg, &err, 10);
    if (*err != '\0') {
        fprintf(stderr, "%s: not an integer\n", arg);
        exit(EXIT_FAILURE);
    }
    return num;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./mult x y\n");
        return EXIT_FAILURE;
    }
    long x = validate(argv[1]);
    long y = validate(argv[2]);
    printf("%ld\n", x * y);
}
