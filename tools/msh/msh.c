#include "msh.h"
#include "parser.h"
#include "utils.h"
#include "exec.h"

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

int main(void) {
    char *line = NULL;
    int pipe_flag;
    int pipe_count;
    int line_status;
    signal(SIGINT, prompt);

    while (1) {
        pipe_count = 0;
        free(line);
        line = NULL;

        prompt(0);
        line = get_line(&line_status);
        switch (line_status) {
            case 1:
                puts("exit");
                fflush(stdout);
                exit(EXIT_SUCCESS);
                break;
            case 2:
                continue;
        }

        char **tokens = Malloc(TOKENSIZE * sizeof(char *));
        size_t token_count = 0;
        tokens = tokenize(tokens, line, &token_count);
        if (token_count == 0) continue;

        char **cmd_start[BUFSIZE]; /* maybe with malloc later */
        cmd_start[0] = &tokens[0];

        pipe_flag = pipeline_split(tokens, token_count, cmd_start, &pipe_count);
        if (pipe_flag == -1) {
            free(tokens);
            continue;
        }

        if (pipe_flag) {
            int pipefds[2*pipe_count];
            pid_t children[pipe_count+1];

            create_pipes(pipefds, pipe_count, line, tokens);
            execute_pipeline(pipefds, pipe_count, pipe_flag, line, cmd_start, children);
            reap_children(pipefds, pipe_count, children, pipe_count+1);

            free(tokens);
        } else cmd_run(*cmd_start, line, pipe_flag);
    }
}
