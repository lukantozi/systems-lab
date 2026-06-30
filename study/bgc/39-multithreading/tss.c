#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

tss_t str;

void some_function(void) {
    // retrieve the per-thread value of this string
    char *tss_string = tss_get(str);

    printf("TSS string: %s\n", tss_string);
}

int run(void *arg) {
    int serial = *(int *)arg;
    free(arg);

    // malloc space to hold the data for this thread
    char *s = malloc(64);
    sprintf(s, "thread %d! :)", serial);

    // set this TSS variable to point at the string
    tss_set(str, s);

    // call the function that will get the variable
    some_function();

    return 0; // same as thrd_exit(0)
}

#define THREAD_COUNT 15

int main(void) {
    thrd_t t[THREAD_COUNT];

    // make the tss TSS variable; free() is the destructor function
    tss_create(&str, free);

    for (int i = 0; i < THREAD_COUNT; i++) {
        int *n = malloc(sizeof *n);
        *n = i;
        thrd_create(t + i, run, n);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        thrd_join(t[i], NULL);
    }

    // all threads are done, so we're done with this
    tss_delete(str);
}
