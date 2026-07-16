#include "msh.h"
#include "exec.h"
#include "builtins.h"

void create_pipes(int *pipefds, int pipe_count, char *line, char **tokens) {
    for (int i = 0; i < pipe_count; i++) {
        if (pipe(pipefds + i*2) < 0) {
            perror("pipe");
            free(line);
            free(tokens);
            exit(EXIT_FAILURE);
        }
    }
}

void close_pipes(int pipefds[], int pipes_num) {
    for (int i = 0; i < pipes_num*2; i++) {
        close(pipefds[i]);
    }
}

void execute(char **tokens, char *line, int pipe_flag) {
    if (pipe_flag) {
        execvp(*tokens, tokens);
    } else {
        pid_t pid = fork();
        int   status;

        switch (pid) {
            case -1:
                free(line);
                free(tokens);
                err(EXIT_FAILURE, "fork");
            case 0:
                execvp(tokens[0], tokens);
                fprintf(stderr, "msh: command not found: %s\n", tokens[0]);
                free(line);
                free(tokens);
                exit(EKEYEXPIRED);
            default:
                waitpid(pid, &status, 0);
        }
    }
}

void builtin_run(int *builtin_flag, char **tokens) {
    for (int i = 0; i < BUILTIN_SIZE; i++) {
        if (strcmp(tokens[0], cmds[i].name) == 0) {
            *builtin_flag = cmds[i].func(tokens);
            return;
        }
    }
}

void cmd_run(char **tokens, char *line, int pipe_flag) {
    int builtin_flag = -1;
    builtin_run(&builtin_flag, tokens);

    switch (builtin_flag) {
        case -1: /* no builtin command */
            execute(tokens, line, pipe_flag);
            free(tokens);
            break;
        case 0: /* builtin ran successfully */
            free(tokens);
            break;
        case 1: /* for now catching `cd`'s errors */
            free(tokens);
            break;
        case 2: /* exit */
            free(line);
            free(tokens);
            exit(EXIT_SUCCESS);
            break;
        default:
            free(tokens);
    }
}

void execute_pipeline(int pipefds[], int pipe_count, int pipe_flag,
        char *line, char ***cmd_start, pid_t children[]) {
    int command_count = pipe_count + 1;
    int pid;
    for (int i = 0; i < command_count; i++) {
        pid = fork();
        switch (pid) {
            case -1:
                err(EXIT_FAILURE, "fork");
            case 0: /* child */
                if (i == 0) {                    /* first command; real stdin */
                    if (dup2(pipefds[i*2+1], STDOUT_FILENO) == -1) {
                        // free(line);
                        // free(tokens);
                        err(EXIT_FAILURE, "dup2(first command)");
                    }
                    close_pipes(pipefds, pipe_count);
                    execute(cmd_start[i], line, pipe_flag);
                    err(EXIT_FAILURE, "execvp");
                } else if (i == command_count - 1) { /* last command; real stdout */
                    if (dup2(pipefds[(i-1)*2], STDIN_FILENO) == -1) {
                        // free(line);
                        // free(tokens);
                        err(EXIT_FAILURE, "dup2(last command)");
                    }
                    close_pipes(pipefds, pipe_count);
                    execvp(*cmd_start[i], cmd_start[i]);
                    err(EXIT_FAILURE, "execvp");
                } else {                         /* in between; pipes ends around */
                    if (dup2(pipefds[(i-1)*2], STDIN_FILENO) == -1) {
                        // free(line);
                        // free(tokens);
                        err(EXIT_FAILURE, "dup2(middle stdin)");
                    }
                    if (dup2(pipefds[i*2+1], STDOUT_FILENO) == -1) {
                        // free(line);
                        // free(tokens);
                        err(EXIT_FAILURE, "dup2(middle stdout)");
                    }
                    close_pipes(pipefds, pipe_count);
                    execvp(*cmd_start[i], cmd_start[i]);
                    err(EXIT_FAILURE, "execvp");
                }
                break;
            default: /* parent */
                /* save children pids */
                children[i] = pid;
        }
    }
}

void reap_children(int pipefds[], int pipe_count, pid_t children[], int command_count) {
    int status;
    close_pipes(pipefds, pipe_count);
    for (int i = 0; i < command_count; i++) {
        while (waitpid(children[i], &status, 0) <= 0);
    }
}
