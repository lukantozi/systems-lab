#include <stdio.h>
#include <signal.h>

int main(void) {
    char s[1024];

    signal(SIGINT, SIG_IGN); // ignore SIGINT caused by ^C

    printf("Try hitting ^C... (hit RETURN to exit)\n");

    fgets(s, sizeof s, stdin); // wait for the line
}
