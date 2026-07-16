#include "msh.h"
#include "builtins.h"

int exit_exec(char **tokens) {
    (void)tokens;
    return 2;
}

int cd_exec(char **tokens) {
    if (tokens[1] == NULL) {
        char *home;
        if ((home = getenv("HOME")) == NULL) {
            fprintf(stderr, "cd: HOME variable not set\n");
            return(EXIT_FAILURE);
        }
        if (chdir(home) == -1) {
            fprintf(stderr, "cd: no such file or direcdtory: %s\n", home);
            return(EXIT_FAILURE);
        }
    } else {
        if (chdir(tokens[1]) == -1) {
            fprintf(stderr, "cd: no such file or direcdtory: %s\n", tokens[1]);
            return(EXIT_FAILURE);
        }
    }
    return(EXIT_SUCCESS);
}

int env_exec(char **tokens) {
    (void)tokens;
    for (char **p = environ; *p != NULL; p++) {
        printf("%s\n", *p);
    }
    return(EXIT_SUCCESS);
}

struct builtin cmds[BUILTIN_SIZE] = {
    [0] = {.name="exit", .func=exit_exec},
    [1] = {.name="cd",   .func=cd_exec},
    [2] = {.name="env",  .func=env_exec},
};
