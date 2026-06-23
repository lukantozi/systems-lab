#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int count = 0;

void signal_handler(int signum) {
    /* compiler may reset it to SIG_DFL
     * so we reset it to be safe */
    signal(SIGINT, signal_handler);

    (void)signum; // lose unused var

    count++;                      // UB
    printf("count: %d\n", count); // UB

    if (count == 2) {
        printf("Exiting!\n");     // UB
        exit(0);
    }
}

int main(void) {
    signal(SIGINT, signal_handler);
    printf("Try hitting ^C...\n");
    for (;;);
}
