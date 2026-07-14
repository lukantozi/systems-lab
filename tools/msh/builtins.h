#ifndef BUILTINS_H
#define BUILTINS_H

struct builtin {
    char *name;
    int (*func)(char **, char *);
};

extern char **environ;
int exit_exec(char **, char *);
int cd_exec(char **, char *);
int env_exec(char **, char *);

#define BUILTIN_SIZE 3

#endif
