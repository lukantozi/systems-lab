#include "msh.h"
#include "builtins.h"

int exit_exec(char **args, char *line) {
    if ((strcmp(line, "exit")) == 0) {
        free(line);
        exit(EXIT_SUCCESS);
    }
    perror("exit_exec");
    free(line);
    free(args);
    exit(EXIT_FAILURE);
}

int cd_exec(char **args, char *line) {
    if (chdir(args[1]) == -1) {
        perror("chdir");
        free(args);
        free(line);
        exit(ENOTDIR);
    }
    return(EXIT_SUCCESS);
}

int env_exec(char **env, char *line) {
    (void)env; (void)line;
    for (char **p = environ; *p != NULL; p++) {
        printf("%s\n", *p);
    }
    return(EXIT_SUCCESS);
}
