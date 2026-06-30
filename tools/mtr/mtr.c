#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <assert.h>

#define TF_SIZE 128

void format_time(char *time_format) {
    time_t now = time(NULL);
    strftime(time_format, TF_SIZE, "[%Y-%e-%d %T]", localtime(&now));
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s COMMAND [OPTIONS]\n",
                argv[0]);
        exit(EXIT_FAILURE);
    }
    // initialize
    pid_t pid;
    int status, err, exit_status;

    // build argline
    size_t line_size = 1;
    for (int i = 1; i < argc; i++) {
        line_size += strlen(argv[i]) + 1;
    }
    char *argline;
    if ((argline = malloc(line_size)) == NULL) {
        perror("malloc");
        exit(2);
    }
    line_size = 0;
    for (int i = 1; i < argc; i++) {
        line_size += sprintf(argline + line_size, "%s ", argv[i]);
        assert(argline[line_size] == '\0');
    }
    argline[--line_size] = '\0';

    // stamp before forking
    char *time_format = malloc(TF_SIZE);
    format_time(time_format);
    printf("%s starting: %s\n\n", time_format, argline);
    free(time_format);

    // fork
    pid = fork();
    if (pid == 0) {
        if ((err = execvp(argv[1], argv+1)) == -1) {
            perror("execvp");
            _exit(127);
        }
   } else if (pid > 0) {
        if (wait(&status) < 0) { // wait for child to die
            perror("wait");
            _exit(EXIT_FAILURE);
        }
        // stamp after child dies 
        time_format = malloc(TF_SIZE);
        format_time(time_format);
        printf("\n%s finished: exit=%d\n", time_format, status >> 8);
        free(time_format);
    } else {
        perror("fork");
        _exit(EXIT_FAILURE);
    }

    return 0;
}
