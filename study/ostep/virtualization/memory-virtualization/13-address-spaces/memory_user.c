#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#define MB * 1000000

static volatile sig_atomic_t stop = 0;

static void handle_sigint(int sig)
{
    (void)sig;
    stop = 1;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: ./memory-user N (in mb)\n");
        return 1;
    }

    char *arg_num = argv[1];
    char *arg_end;
    errno = 0;
    long mbytes = strtol(arg_num, &arg_end, 10);
    if (arg_end == arg_num || *arg_end != '\0' || errno == ERANGE) {
        fprintf(stderr, "%s not a number\n", arg_num);
        return 1;
    }
    printf("pid %d\n", getpid());
    long bytes = mbytes MB;
    printf("%ldMB == %ldB\n", mbytes, bytes);

    unsigned char *mem = malloc(bytes);
    if (mem == NULL) {
        perror("malloc");
        return 1;
    }

    struct sigaction sa = {0};
    sa.sa_handler = handle_sigint;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    while (!stop) {
        for (long i = 0; i < bytes && !stop; i++) {
            mem[i] = i;
        }
    }

    free(mem);
    return 0;
}
