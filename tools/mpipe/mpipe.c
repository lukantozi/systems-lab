#define _GNU_SOURCE
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <err.h>
#include <wait.h>

void close_pipes(int pipefds[], int pipes_num) {
    for (int i = 0; i < pipes_num*2; i++) {
        close(pipefds[i]);
    }
}

void echoin_pipe(int pipefds[], int pipes_num, int command_indices[],
        char *commands[], int i) {
    /* close pipes */
    close_pipes(pipefds, pipes_num);
    /* execute current command */
    int offset = command_indices[i];
    execvp((commands+offset)[0], commands+offset);
    err(EXIT_FAILURE, "execvp");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s COMMAND [\"|\" [COMMAND ...]]\n",
                argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "|") == 0 || strcmp(argv[argc-1], "|") == 0) {
        fprintf(stderr, "empty command around \"|\"\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc - 1; i++) {
        if (strcmp(argv[i], "|") == 0 && strcmp(argv[i+1], "|") == 0) {
            fprintf(stderr, "empty command around \"|\"\n");
            exit(EXIT_FAILURE);
        }
    }

    if (argc == 2) {
        execvp(argv[1], argv+1);
        exit(EXIT_SUCCESS);
    }
    /* commands built from argv */
    char *commands[argc];
    int command_count = 0;
    for (int i = 0; i < argc-1; i++) {
        if (strcmp(argv[i+1], "|") == 0) {
            commands[i] = NULL;
            command_count++;
        } else commands[i] = argv[i+1];
    }
    commands[argc-1] = NULL;
    command_count++;

    int index = 0;
    int command_indices[command_count+1];
    command_indices[index++] = 0;

    // collect command starting indices
    for (int i = 0; i < argc-1; i++) {
        if (commands[i] == NULL) {
            command_indices[index++] = i+1;
        }
    }
    int pipes_num = command_count - 1;
    int pipefds[2*(pipes_num)];
    int pid;
    for (int i = 0; i < pipes_num; i++) {
        if (pipe(pipefds + i*2) < 0) {
            err(EXIT_FAILURE, "pipe");
        }
    }

    pid_t children[command_count];
    for (int i = 0; i < command_count; i++) {
        pid = fork();
        switch (pid) {
            case -1:
                err(EXIT_FAILURE, "fork");
            case 0: /* child */
                if (i == 0) {                    /* first command; real stdin */
                    if (dup2(pipefds[i*2+1], STDOUT_FILENO) == -1) {
                        err(EXIT_FAILURE, "dup2(first command)");
                    }
                    echoin_pipe(pipefds, pipes_num, command_indices, commands, i);
                } else if (i == command_count - 1) { /* last command; real stdout */
                    if (dup2(pipefds[(i-1)*2], STDIN_FILENO) == -1) {
                        err(EXIT_FAILURE, "dup2(last command)");
                    }
                    echoin_pipe(pipefds, pipes_num, command_indices, commands, i);
                } else {                         /* in between; pipes ends around */
                    if (dup2(pipefds[(i-1)*2], STDIN_FILENO) == -1) {
                        err(EXIT_FAILURE, "dup2(middle stdin)");
                    }
                    if (dup2(pipefds[i*2+1], STDOUT_FILENO) == -1 ){
                        err(EXIT_FAILURE, "dup2(middle stdout)");
                    }
                    echoin_pipe(pipefds, pipes_num, command_indices, commands, i);
                }
            default: /* parent */
                /* save child's pid */
                children[i] = pid;
        }
    }

    int status;
    close_pipes(pipefds, pipes_num);
    for (int i = 0; i < command_count; i++) {
        while (waitpid(children[i], &status, 0) <= 0);
    }
    return WEXITSTATUS(status);
}
