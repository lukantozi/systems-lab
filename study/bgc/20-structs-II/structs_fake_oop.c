#include <stdio.h>

struct parent {
    int a, b;
};

struct child {
    struct parent super;
    int c, d;
};

void print_parent(void *p) {
    struct parent *self = p;
    printf("Parent: %d, %d\n", self->a, self->b);
}

void print_child(struct child *self) {
    printf("Child: %d, %d\n", self->c, self->d);
}

int main(void) {
    struct child c = {.super.a=1, .super.b=2, .c=3, .d=4};
    print_parent(&c);
    print_child(&c);
}
