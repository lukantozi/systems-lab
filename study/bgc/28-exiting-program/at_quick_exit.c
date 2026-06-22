#include <stdio.h>
#include <stdlib.h>

void on_quick_exit_1(void) {
    printf("Quick exit handler 1 called!\n");
}

void on_quick_exit_2(void) {
    printf("Quick exit handler 2 called!\n");
}

void on_exit_1(void) {
    printf("Normal exit--I won't be called\n");
}

int main(void) {
    at_quick_exit(on_quick_exit_1);
    at_quick_exit(on_quick_exit_2);

    atexit(on_exit_1);

    quick_exit(0);
}
