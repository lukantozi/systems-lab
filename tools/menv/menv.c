#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

void show_env(void) {
    for (char **p = environ; *p != NULL; p++) {
        printf("%s\n", *p);
    }
}

void process(int argc, char *argv[]) {
    /* copy key_val */
    int enverr, i, program_index = 0;
    size_t key_val_len;
    char *key_val, *eq, *key, *val;

    for (i = 1; i < argc; i++) {
        key_val_len = strlen(argv[i]);
        if ((key_val = malloc(key_val_len + 1)) == NULL) {
            perror("malloc");
            continue;
        }
        memcpy(key_val, argv[i], key_val_len + 1); /* check return value */

        /* split key_val */
        eq = strchr(key_val, '=');
        if (eq) {
            *eq = '\0';
            key = key_val;
            val = eq + 1;
            if ((enverr = setenv(key, val, 1)) == -1) {
                perror("setenv");
                free(key_val);
                continue;
            }
            program_index++;
        } else {
            free(key_val);
            break;
        }
        free(key_val);
    }
    if (argc - program_index < 2) {
        show_env();
        exit(EXIT_SUCCESS);
    }

    execve(argv[program_index+1], argv+program_index+1, environ); 
    perror("execve");
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        show_env();
        exit(EXIT_SUCCESS);
    }

    int program_index = 0, unsetval, opt;
    while ((opt = getopt(argc, argv, "+C:u:")) != -1) {
        switch (opt) {
            case 'u':
                if ((unsetval = unsetenv(optarg)) == -1) {
                    fprintf(stderr, "can't unset %s\n", optarg);
                }
                /* shift out unset variable */
                argv[optind-1] = argv[program_index];
                program_index += 2;
                break;
            case 'C':
                if ((chdir(optarg)) == -1) {
                    fprintf(stderr, "%s: cannot change directory to '%s': No such file or directory\n",
                            argv[0], optarg);
                    exit(EXIT_FAILURE);
                }
                /* shift out dir variable */
                argv[optind-1] = argv[program_index];
                program_index += 2;
                break;
        }
    }
    process(argc-program_index, argv+program_index);
}
