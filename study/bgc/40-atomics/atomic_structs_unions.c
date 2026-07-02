#include <stdio.h>
#include <stdatomic.h>

int main(void) {
    struct point {
        float x, y;
    };

    _Atomic(struct point) p;
    printf("Is lock free: %d\n", atomic_is_lock_free(&p));

    struct point t;

    p = (struct point){1, 2};

    //printf("%f\n", p.x); // error

    // in order to access atomic struct values
    // we have to copy it into non-atomic variable
    t = p; 
    printf("%f\n", t.x);
}
