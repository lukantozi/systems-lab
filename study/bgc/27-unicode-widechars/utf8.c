#include <stdio.h>

int main(void) {
    char *s = u8"Hello, world!";
    char *c = u8"€123";
    printf("%s\n", s);
    printf("%s\n", c);
}
