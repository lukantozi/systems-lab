#include <stdio.h>
#include <stddef.h>

struct bar {
    int a;
    char b;
    int c;
    char d;
};

int main(void) {
    printf("%zu\n", sizeof(int) + sizeof(char) + sizeof(int) + sizeof(char));
    printf("%zu\n", sizeof(struct bar));

    printf("%zu\n", offsetof(struct bar, a));
    printf("%zu\n", offsetof(struct bar, b));
    printf("%zu\n", offsetof(struct bar, c));
    printf("%zu\n", offsetof(struct bar, d));
}
