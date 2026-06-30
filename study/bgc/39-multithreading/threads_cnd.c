#include <stdio.h>
#include <threads.h>

#define VALUE_COUNT_MAX 5

int value[VALUE_COUNT_MAX];
int value_count = 0;

mtx_t value_mtx; // mutex around value
cnd_t value_cnd; // condition variable on value

int run(void *arg) {
    (void)arg;

    for (;;) {
        mtx_lock(&value_mtx); // GRAB THE MUTEX

        while (value_count < VALUE_COUNT_MAX) {
            printf("Thread: is waiting\n");
            cnd_wait(&value_cnd, &value_mtx); // CONDITION WAIT
        }

        printf("Thread: is awake!\n");

        int t = 0;

        // add everything up
        for (int i = 0; i < VALUE_COUNT_MAX; i++) {
            t += value[i];
        }

        printf("Thread: total is %d\n", t);

        // reset the count for main thread
        value_count = 0;

        mtx_unlock(&value_mtx);
    }

    return 0;
}

int main(void) {
    thrd_t t;

    // spawn a new thread
    thrd_create(&t, run, NULL);
    thrd_detach(t);

    // set up mutex and condition variables
    mtx_init(&value_mtx, mtx_plain);
    cnd_init(&value_cnd);

    for (;;) {
        int n;
        scanf("%d", &n);

        mtx_lock(&value_mtx); // LOCK MUTEX

        value[value_count++] = n;
        if (value_count == VALUE_COUNT_MAX) {
            printf("Main: signaling thread\n");
            cnd_signal(&value_cnd); // SIGNAL CONDITION
        }

        mtx_unlock(&value_mtx);
    }

    // to pretend to be proper
    mtx_destroy(&value_mtx);
    cnd_destroy(&value_cnd);
}
