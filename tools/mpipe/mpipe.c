#define _GNU_SOURCE
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

int main(int argc, char *argv[]) {
    (void)argc, (void)argv;
    int pipefd[2];
    int pid, status;
    status = pipe(pipefd);
    if (status == -1) {
        err(EXIT_FAILURE, "pipe");
    }
    char *cmd1[2] = {"ls", NULL};
    char *cmd2[3] = {"grep", "txt", NULL};

    pid = fork();
    switch (pid) {
        case -1:
            err(EXIT_FAILURE, "fork");
        case 0: /* child */
            close(pipefd[0]); // close unused read end
            dup2(pipefd[1], STDOUT_FILENO);
            execvp(cmd1[0], cmd1);
        default: /* parent */
            close(pipefd[1]); // close unused write end
            dup2(pipefd[0], STDIN_FILENO);
            execvp(cmd2[0], cmd2);
    }
}
