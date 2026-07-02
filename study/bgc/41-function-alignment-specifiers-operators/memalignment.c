#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>
#include <stdalign.h>

void foo(void *p) {
    if (memalignment(p) >= alignof(atomic_int)) {
        atomic_int *i = p;
        puts("aligned");
    } else {
        puts("This pointer is no good as an atomic int");
    }
}

int main(void) {
    atomic_int x = 0;
    atomic_char c;
    foo(&x);
    foo(&c);
}
