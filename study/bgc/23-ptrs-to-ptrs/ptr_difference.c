#include <stdio.h>
#include <stddef.h>

int main(void) {
    int cats[100];

    int *m = cats + 20;
    int *o = cats + 60;

    ptrdiff_t d = o - m;

    printf("dec: %td\n", d);
    printf("hex: %x\n", d);
}
