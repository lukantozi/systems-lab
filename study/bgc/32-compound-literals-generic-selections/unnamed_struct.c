#include <stdio.h>

struct coord {
    int x, y;
};

void print_struct(struct coord c) {
    printf("%d, %d\n", c.x, c.y);
}

void print_struct_ptr(struct coord *c) {
    printf("%d, %d\n", c->x, c->y);
}

int main(void) {
    print_struct((struct coord){.x=10, .y=20});
    print_struct_ptr(&(struct coord){.x=11, .y=22});
}
