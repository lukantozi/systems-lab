#include "msh.h"
#include "parser.h"
#include "utils.h"

char *get_line(int *status) {
    size_t line_size    = BUFSIZE;
    size_t token_count  = 0;
    char  *line         = Malloc(line_size * sizeof(char *));
    int    c;

    while (1) {
        c = getchar();
        if (c == '\n' || c == EOF) {
            if (token_count == 0) {
                free(line);
                *status = c == EOF ? 1 : 2;
                return NULL;
            }
            line[token_count] = '\0';
            *status = 0;
            return line;
        } else line[token_count] = c;
        token_count++;

        if (token_count >= line_size) {
            line_size += BUFSIZE;
            line = Realloc(line, line_size);
        }
    }
}

char **tokenize(char **tokens, char *line, size_t *token_count) {
    size_t tokens_size = TOKENSIZE;

    for (char *token = strtok(line, DELIM); token; token = strtok(NULL, DELIM)) {
        if (*token_count >= tokens_size) {
            tokens_size *= 2;
            tokens = Realloc(tokens, tokens_size * sizeof(char *));
        }
        tokens[(*token_count)++] = token;
    }
    tokens[*token_count] = NULL;
    return tokens;
}

int pipeline_split(char **tokens, size_t token_count, char ***cmd_start,
        int *pipe_count) {
    int ind = 1;
    if (strcmp(tokens[0], "|") == 0 || strcmp(tokens[token_count-1], "|") == 0) {
        fprintf(stderr, "msh: parse error near '\\'\n");
        return -1;
    }
    for (size_t i = 1; i < token_count-1; i++) {
        if (strcmp(tokens[i], "|") == 0) {
            tokens[i] = NULL;
            (*pipe_count)++;
            cmd_start[ind++] = &tokens[i+1];
            if (strcmp(tokens[i+1], "|") == 0) {
                fprintf(stderr, "msh: parse error near '\\'\n");
                return -1;
            }
        }
    }
    return *pipe_count ? 1 : 0;
}
