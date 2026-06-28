#define _GNU_SOURCE
#include <stdio.h>
#include <sys/stat.h>
#include <linux/limits.h>
#include <limits.h>
#include <stdlib.h>
#include <libgen.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
            fprintf(stderr, "%s: missing file operand\n",
                    argv[0]);
            return EXIT_FAILURE;

    } else if (argc == 2) {
            fprintf(stderr, "%s: missing destination file operand after %s\n",
                    argv[0], argv[1]);
            return EXIT_FAILURE;

    } else if (argc == 3) {
            char *src_name; 
            if ((src_name = malloc(PATH_MAX)) == NULL) {
                perror("malloc(src_name)");
                return EXIT_FAILURE;
            }
            if (realpath(argv[1], src_name) == NULL) {
                free(src_name);
                fprintf(stderr, "%s: cannot stat '%s': No such file or directory\n",
                        argv[0], argv[1]);
                return EXIT_FAILURE;
            }

            char *dest_name;
            if ((dest_name = malloc(PATH_MAX)) == NULL) {
                free(src_name);
                perror("malloc(dest_name)");
                return EXIT_FAILURE;
            }

            if (realpath(argv[2], dest_name) != NULL) {
                struct stat dest_stat;
                if (stat(dest_name, &dest_stat) == -1) {
                    fprintf(stderr, "%s: cannot stat '%s': No such file or directory\n",
                            argv[0], argv[2]);
                    free(src_name);
                    free(dest_name);
                    return EXIT_FAILURE;
                }

                if (S_ISDIR(dest_stat.st_mode)) {
                    char *new_name;
                    if ((new_name = malloc(PATH_MAX)) == NULL) {
                        free(src_name);
                        free(dest_name);
                        perror("malloc(new_name)");
                        return EXIT_FAILURE;
                    }

                    snprintf(new_name, PATH_MAX, "%s/%s", dest_name, basename(src_name));
                    if (rename(src_name, new_name) == -1) {
                        perror("rename");
                    }
                    free(new_name);
                }
            } else {
                rename(src_name, argv[2]);
            }
            free(dest_name);
            free(src_name);

    } else if (argc > 3) {
        struct stat dir_stat;
        if (stat(argv[argc-1], &dir_stat) == -1) {
            fprintf(stderr, "%s: target '%s': No such file or directory\n",
                    argv[0], argv[argc-1]);
            return EXIT_FAILURE;
        } 

        if (S_ISDIR(dir_stat.st_mode)) {
            for (int i = 1; i < argc-1; i++) {
                char *new_name;
                if ((new_name = malloc(PATH_MAX)) == NULL) {
                    perror("malloc(new_name)");
                    continue;
                }

                char *src_name;
                if ((src_name = malloc(PATH_MAX)) == NULL) {
                    free(new_name);
                    fprintf(stderr, "%s: target '%s': No such file or directory\n",
                            argv[0], argv[i]);
                    continue;
                }

                if ((realpath(argv[i], src_name)) == NULL) {
                    free(new_name);
                    free(src_name);
                    fprintf(stderr, "%s: cannot stat '%s': No such file or directory\n",
                            argv[0], argv[i]);
                    continue;
                }

                snprintf(new_name, PATH_MAX, "%s/%s", argv[argc-1], basename(src_name));
                if (rename(src_name, new_name) == -1) {
                    perror("rename");
                }

                free(src_name);
                free(new_name);
            }
        } else if (S_ISREG(dir_stat.st_mode)){
            fprintf(stderr, "%s: target '%s': Not a directory\n",
                    argv[0], argv[argc-1]);
            return EXIT_FAILURE;
        } else {
            fprintf(stderr, "%s: target '%s': No such file or directory\n",
                    argv[0], argv[argc-1]);
            return EXIT_FAILURE;
        }
    }
}
