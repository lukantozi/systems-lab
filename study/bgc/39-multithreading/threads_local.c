#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

int run(void *arg) {
    int n = *(int *)arg; // thread num

    free(arg);

    thread_local static int foo = 10; // static val shared between threads.
                                      // with thread_local in front it's not shared
                                      // between threads

    int x = foo; // automatic local variable; each thread has its own

    // they should be equal here but sometimes they are not
    printf("Thread: %d: x = %d, foo = %d\n", n, x, foo); 

    // another thread comes in and increments foo right now,
    // but this thread's x remains what it was before
    if (x != foo) {
        printf("Thread: %d x != foo! %d != %d\n", n, x, foo);
    }

    foo++;

    return 0;
}

#define THREAD_COUNT 5

int main(void) {
    thrd_t t[THREAD_COUNT];

    for (int i = 0; i < THREAD_COUNT; i++) {
        int *n = malloc(sizeof *n);
        *n = i;
        thrd_create(t + i, run, n);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        thrd_join(t[i], NULL);
    }
}
