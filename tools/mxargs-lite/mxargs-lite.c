#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define TOKEN_SIZE 64
#define ARGS_SIZE 1000

void free_args(int, char **);

void build_args(char **args, int *args_count) {
    *args_count = 0;
    int char_pos = 0;
    int argsize = TOKEN_SIZE;

    char *arg;
    if ((arg = malloc(argsize)) == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    args[*args_count] = arg;

    int c;
    while (1) {
        c = getchar();
        if (c == 0xA || c == 0x20 || c == 0x09 || c == 0x0D || c == EOF) {
            if (char_pos != 0) {
                arg[char_pos] = '\0';
                if (*args_count == ARGS_SIZE) {
                    free_args(*args_count, args);
                    free(arg);
                    fprintf(stderr, "argssize: exceeds size limit - %d (will implement it with malloc)\n", 
                            ARGS_SIZE);
                    exit(EXIT_FAILURE);
                }
                (*args_count)++;
                if ((arg = malloc(argsize)) == NULL) {
                    free_args(*args_count, args);
                    perror("malloc");
                    exit(EXIT_FAILURE);
                }
                args[*args_count] = arg;
                char_pos = 0;
                argsize = TOKEN_SIZE;
            }
        } else {
            if (char_pos >= argsize - 1) {
                char *new_arg = realloc(arg, argsize*2);
                if (new_arg == NULL) {
                    perror("realloc");
                    free_args(*args_count, args);
                    free(arg);
                    exit(EXIT_FAILURE);
                }
                arg = new_arg;
                args[*args_count] = arg;
                argsize *= 2;
            }
            arg[char_pos++] = c;
        }
        if (c == EOF) {
            break;
        }
    }
    args[*args_count] = NULL;
    free(arg);
}

void free_args(int n, char **args) {
    for (int i = 0; i < n; i++) {
        free(args[i]);
    }
}

int main(int argc, char *argv[]) {
    // initialize
    int args_count;
    int argssize = ARGS_SIZE;
    /* TODO: allocate it on heap */
    char *args[argssize + 1];

    build_args(args, &args_count);

    // populate command_args with argv + stdin
    int args_pos = 0;
    char *command_args[argc+1];
    if (argc < 2) {
        for (int i = 0; args[i] != NULL; i++) printf("%s ", args[i]);
        putchar('\n');
        free_args(args_count, args);
        return 0;
    } else {
        for (int i = 0; argv[i] != NULL; i++) {
            command_args[i] = argv[i+1];
        }
        command_args[argc-1] = args[args_pos++];
        command_args[argc] = NULL;
    }

    // execute commands using each stdin argument
    for (int i = 0; i < args_count; i++) {
        int pid, status;
        pid = fork();
        if (pid == 0) {
            execvp(command_args[0], command_args);
            perror("execvp");
            free_args(args_count, args);
            _exit(127);
        } else {
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) {
                command_args[argc-1] = args[args_pos++];
            }
        }
    }
    free_args(args_count, args);
}
