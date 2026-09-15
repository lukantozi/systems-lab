#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#define KILO 1000
#define MEGA 1000000
#define ITER (MEGA * 10)

int main(void) {
    struct timeval tv;

    double old   = 0;
    double new   = 0;
    double delta = 0;
    char   buf;

    printf("calling read() %d times...\n", ITER);

    gettimeofday(&tv, NULL);
    old = tv.tv_sec * MEGA + tv.tv_usec;

    for (int i = 0; i < ITER; i++) {
        read(0, &buf, 0);
    }

    gettimeofday(&tv, NULL);
    new = tv.tv_sec * MEGA + tv.tv_usec;

    delta = new - old;

    printf("\neach call took %.2f nsecs\n", ((double) delta / ITER) * KILO);
}
