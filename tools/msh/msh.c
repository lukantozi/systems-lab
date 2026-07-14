#include "msh.h"
#include "builtins.h"

struct builtin commands[BUILTIN_SIZE] = {
    [0] = {.name="exit", .func=exit_exec},
    [1] = {.name="cd",   .func=cd_exec},
    [2] = {.name="env",  .func=env_exec},
};

char *get_line(void) {
    size_t line_size = BUFSIZE;
    size_t index = 0;
    char *line = Malloc(line_size * sizeof(char *));

    int c;
    while (1) {
        c = getchar();
        if (c == '\n' || c == EOF) {
            line[index] = '\0';
            return line;
        } else line[index] = c;
        index++;

        if (index >= line_size) {
            line_size *= 2;
            Realloc(line, line_size);
        }
    }
}

void tokenize(char **tokens, char *line) {
    size_t tokens_size = TOKENSIZE;
    size_t index = 0;

    for (char *token = strtok(line, DELIM); token; token = strtok(NULL, DELIM)) {
        if (index >= tokens_size) {
            tokens_size *= 2;
            Realloc(tokens, tokens_size * sizeof(char *));
        }
        tokens[index++] = token;
    }
    tokens[index] = NULL;
}

void execute(char **tokens, char *line) {
    pid_t pid = fork();
    int status;
    switch (pid) {
        case -1:
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

void prompt(void) {
    char cwd[BUFSIZE];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd");
        exit(ENOENT);
    }
    printf("\n%s\n> ", cwd);
}

int main(void) {
    char *line = NULL;
    while (1) {
        free(line);

        prompt();
        line = get_line();

        char **tokens = Malloc(TOKENSIZE * sizeof(char *));
        tokenize(tokens, line);

        int builtin_flag = 0;
        for (int i = 0; i < BUILTIN_SIZE; i++) {
            if (strcmp(tokens[0], commands[i].name) == 0) {
                commands[i].func(tokens, line);
                builtin_flag = 1;
                break;
            }
        }

        // TODO: pipe detection
        // TODO: redirects

        if (!builtin_flag) execute(tokens, line);
        free(tokens);
    }
}
