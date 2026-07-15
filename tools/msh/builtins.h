#ifndef BUILTINS_H
#define BUILTINS_H

struct builtin {
    char *name;
    int (*func)(char **);
};

extern char **environ;
int exit_exec(char **);
int cd_exec(char **);
int env_exec(char **);

#define BUILTIN_SIZE 3

#endif
