#define _GNU_SOURCE
#include <limits.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

const char *walk_dir(const char *path, const char *match) {
    DIR *dir;
    if ((dir = opendir(path)) == NULL) {
        return NULL;
    }
    struct dirent *drnt;
    while ((drnt = readdir(dir)) != NULL) {
        const char *name = drnt->d_name;
        char *full_path = malloc(PATH_MAX);
        if (full_path == NULL) continue;
        if (drnt->d_type == DT_LNK) {
            sprintf(full_path, "%s/%s", path, name);
            free(full_path);
            continue;
        }
        struct stat path_stat;
        sprintf(full_path, "%s/%s", path, name);
        if ((stat(full_path, &path_stat)) == -1) {
            free(full_path);
            continue;
        }
        if (S_ISDIR(path_stat.st_mode))  {
            if (strcmp(name, ".") == 0) {
                free(full_path);
                continue;
            }
            if (strcmp(name, "..") == 0) {
                free(full_path);
                continue;
            }
            walk_dir(full_path, match);
            if (strcmp(match, name) == 0 || strcmp(match, "") == 0) {
                printf("%s\n", full_path);
            }
            free(full_path);
        } else {
            if (strcmp(match, name) == 0 || strcmp(match, "") == 0) {
                printf("%s\n", full_path);
                free(full_path);
            }
        }
    }
    closedir(dir);
    return path;
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        const char *idk = walk_dir(".", "");
    } else if (argc == 2) {
        const char *idk = walk_dir(argv[1], "");
    } else if (argc == 3) {
        const char *idk = walk_dir(argv[1], argv[2]);
    }
    return 0;
}
