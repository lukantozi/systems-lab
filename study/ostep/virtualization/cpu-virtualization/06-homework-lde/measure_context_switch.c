#define _GNU_SOURCE
#define _XOPEN_SOURCE 600

#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

#define ITER 1000000
#define GIGA 1000000000LL
#define DIV (ITER * 2)

typedef enum {
    SUCCESS,
    FAIL,
} STATUS;

int main(void) {
    cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(0, &set);
    if (sched_setaffinity(0, sizeof(set), &set) == -1) {
        perror("sched_affinity");
        exit(FAIL);
    }

    char buf;
    int status;
    int pipefds[4];
    pid_t pid;
    struct timespec st;
    struct timespec en;

    if (pipe(pipefds) == -1) {
        perror("pipe(1)");
        exit(FAIL);
    }

    if (pipe(pipefds+2) == -1) {
        perror("pipe(2)");
        exit(FAIL);
    }

    pid = fork();
    switch (pid) {
        case -1:
            perror("fork(1)");
            exit(FAIL);
        case 0:
            if (close(pipefds[0]) == -1) {
                perror("close(pipefds[0])");
                _exit(FAIL);
            }
            if (close(pipefds[3]) == -1) {
                perror("close(pipefds[3])");
                _exit(FAIL);
            }

            for (int i = 0; i < ITER; i++) {
                if (write(pipefds[1], "c", 1) != 1) {
                    perror("write(pipefds[1])");
                    _exit(FAIL);
                }
                if (read(pipefds[2], &buf, 1) != 1) {
                    perror("read(pipefds[2])");
                    _exit(FAIL);
                }
            }

            if (close(pipefds[1]) == -1) {
                perror("close(pipefds[1])");
                _exit(FAIL);
            }
            if (close(pipefds[2]) == -1) {
                perror("close(pipefds[2])");
                _exit(FAIL);
            }

            _exit(SUCCESS);
        default:
            if (close(pipefds[1]) == -1) {
                perror("close(pipefds[1])");
                exit(FAIL);
            }
            if (close(pipefds[2]) == -1) {
                perror("close(pipefds[2])");
                exit(FAIL);
            }

            if (clock_gettime(CLOCK_MONOTONIC, &st) == -1) {
                perror("clock_gettime(st)");
                exit(FAIL);
            }
            for (int i = 0; i < ITER; i++) {
                if (read(pipefds[0], &buf, 1) != 1) {
                    perror("read(pipefds[0])");
                    exit(FAIL);
                }
                if (write(pipefds[3], "c", 1) != 1) {
                    perror("write(pipefds[3])");
                    exit(FAIL);
                }
            }
            if (clock_gettime(CLOCK_MONOTONIC, &en) == -1) {
                perror("clock_gettime(en)");
                exit(FAIL);
            }

            if (close(pipefds[0]) == -1) {
                perror("close(pipefds[0])");
                exit(FAIL);
            }
            if (close(pipefds[3]) == -1) {
                perror("close(pipefds[3])");
                exit(FAIL);
            }

            if (waitpid(pid, &status, 0) == -1) {
                perror("waitpid");
                exit(FAIL);
            }
            if (WIFEXITED(status) || WEXITSTATUS(status)) {
                fprintf(stderr, "child failed\n", exit_status);
                exit(FAIL);
            }
    }


    double delta = ((double) en.tv_sec * GIGA - (double) st.tv_sec * GIGA) + ((double) en.tv_nsec - (double) st.tv_nsec);
    printf("in total  : %.2f ns\n", delta);
    printf("per switch: %.4f ns\n", delta / DIV);
}
