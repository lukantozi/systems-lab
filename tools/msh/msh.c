#include "msh.h"
#include "builtins.h"

struct builtin commands[BUILTIN_SIZE] = {
    [0] = {.name="exit", .func=exit_exec},
    [1] = {.name="cd",   .func=cd_exec},
    [2] = {.name="env",  .func=env_exec},
};

void prompt(int sig) {
    (void)sig;
    char cwd[BUFSIZE];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd");
        exit(ENOENT);
    }
    printf("\n%s\n> ", cwd);
    fflush(stdout);
}

char *get_line(void) {
    size_t line_size    = BUFSIZE;
    size_t token_count  = 0;
    char  *line         = Malloc(line_size * sizeof(char *));
    int    c;

    while (1) {
        c = getchar();
        if (c == '\n' || c == EOF) {
            if (token_count == 0) {
                free(line);
                return NULL;
            }
            line[token_count] = '\0';
            return line;
        } else line[token_count] = c;
        token_count++;

        if (token_count >= line_size) {
            line_size += BUFSIZE;
            line = Realloc(line, line_size);
        }
    }
}

void tokenize(char **tokens, char *line, size_t *token_count) {
    size_t tokens_size = TOKENSIZE;

    for (char *token = strtok(line, DELIM); token; token = strtok(NULL, DELIM)) {
        if (*token_count >= tokens_size) {
            tokens_size *= 2;
            tokens = Realloc(tokens, tokens_size * sizeof(char *));
        }
        tokens[(*token_count)++] = token;
    }
    tokens[*token_count] = NULL;
}

void execute(char **tokens, char *line) {
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

void builtin_run(int *builtin_flag, char **tokens) {
    for (int i = 0; i < BUILTIN_SIZE; i++) {
        if (strcmp(tokens[0], commands[i].name) == 0) {
            *builtin_flag = commands[i].func(tokens);
            return;
        }
    }
}

void command_run(char **tokens, char *line) {
    int builtin_flag = -1;
    builtin_run(&builtin_flag, tokens);

    switch (builtin_flag) {
        case -1: /* no builtin command */
            execute(tokens, line);
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

int main(void) {
    char *line = NULL;
    while (1) {
        signal(SIGINT, prompt);
        free(line);
        line = NULL;

        prompt(0);
        line = get_line();
        if (line == NULL) continue;

        char **tokens = Malloc(TOKENSIZE * sizeof(char *));
        size_t token_count = 0;
        tokenize(tokens, line, &token_count);

        /* TODO: pipe detection */
#if 0
        char *commands[token_count+1];
        int pipe_count = 0;
        for (size_t i = 0; i < token_count; i++) {
            if (strcmp(tokens[i], "|") == 0) {
                commands[i] = NULL;
                pipe_count++;
            } else {
                commands[i] = tokens[i];
            }
        }
        (void)pipe_count;
        commands[token_count] = NULL;
        for (size_t i = 0; i < token_count+1; i++) {
            printf("%lu: %s\n", i, commands[i]);
        }
        free(tokens);
#endif // debugging pipe detection

        /* TODO: redirects */
#if 1
        /* can loop this after pipe detection */
        command_run(tokens, line);
#endif // running commands
    }
}
