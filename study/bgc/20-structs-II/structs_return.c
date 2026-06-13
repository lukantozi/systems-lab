#include <stdio.h>

struct foo {
    int x, y;
};

struct foo f(void) {
    return (struct foo){.x=10, .y=20};
}

int main(void) {
    struct foo a = f();
    printf("%d, %d\n", a.x, a.y);
}
