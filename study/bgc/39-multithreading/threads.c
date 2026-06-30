#include <stdio.h>
#include <threads.h>

int run(void *arg) {
    int *a = arg;

    printf("THREAD: Running thread with arg %d\n", *a);

    return 12; // value picked up by thrd_join() (chose randomly)
}

int main(void) {
    thrd_t t;
    int arg = 3490;

    printf("Launching a thread\n");

    // launch a thread to the run() function
    // pass a pointer to arg and store ID in t
    thrd_create(&t, run, &arg);

    printf("Doing other things while the thread runs\n");

    printf("Waiting for thread to complete...\n");

    int res; // holds return value when thread exits

    thrd_join(t, &res);

    printf("Thread exited with return value %d\n", res);
}
