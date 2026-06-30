#include <stdio.h>
#include <threads.h>

mtx_t serial_mtx;

int main(void) {
    mtx_init(&serial_mtx, mtx_timed);

    mtx_lock(&serial_mtx);

    struct timespec timeout;
    timespec_get(&timeout, TIME_UTC);
    timeout.tv_sec += 1;

    int result = mtx_timedlock(&serial_mtx, &timeout);

    if (result == thrd_timedout) {
        printf("Mutex lock timed out!\n");
    }
}
