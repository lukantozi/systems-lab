#include <stdio.h>
#include <signal.h>

void sigint_handler(int signum) {
    (void)signum;
    signal(SIGINT, SIG_DFL);
}

int main(void) {
    signal(SIGINT, sigint_handler);

    printf("Hit ^C twice to exit.\n");

    while(1);
}
