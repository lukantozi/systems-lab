#ifndef BUILTINS_H
#define BUILTINS_H

#define BUILTIN_SIZE 3

struct builtin {
    char *name;
    int (*func)(char **);
};


extern char **environ;
int exit_exec(char **);
int cd_exec(char **);
int env_exec(char **);
extern struct builtin cmds[BUILTIN_SIZE];

#endif
