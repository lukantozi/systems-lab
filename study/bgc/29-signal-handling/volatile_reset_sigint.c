#include <stdio.h>
#include <signal.h>

volatile sig_atomic_t count = 0;

void sigint_handler(int signum) {
    (void)signum;                   // silence unused variable warning 

    signal(SIGINT, sigint_handler); // reset handler behavior

    count++;                        // UB
}

int main(void) {
    signal(SIGINT, sigint_handler);

    printf("Hit ^C twice to exit.\n");

    while (count < 2);
}
