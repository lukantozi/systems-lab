#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <linux/limits.h>
#include <libgen.h>

int is_regular_file(char *path) {
    struct stat path_stat;
    if (stat(path, &path_stat) == -1) {
        printf("Cannot stat '%s': No such file or directory\n", path);
        return 0;
    } 
    return S_ISREG(path_stat.st_mode);
}

int is_dir(char *path) {
    struct stat path_stat;
    if (stat(path, &path_stat) == -1) {
        printf("Cannot stat '%s': No such file or directory\n", path);
        return 0;
    } 
    return S_ISDIR(path_stat.st_mode);
}

void copy_data(FILE *src, FILE *dst) {
    int c;
    while ((c = fgetc(src)) != EOF) {
        fputc(c, dst);
    }
}

FILE *open_file(char *program, char *mode, char *file) {
    FILE *fp;
    if ((fp = fopen(file, mode)) == NULL) {
        printf("%s cannot open '%s': No such file or directory\n", program, file);
        exit(EXIT_FAILURE);
    }
    return fp;
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("%s: missing file operand\n", argv[0]);
        exit(EXIT_FAILURE);
    } else if (argc == 2) {
        printf("%s: missing file operand after '%s\n'", argv[0], argv[1]);
        exit(EXIT_FAILURE);
    } else if (argc == 3) {
        FILE *src, *dst;
        if (is_regular_file(argv[1])) src = open_file(argv[0], "r", argv[1]);
        else {
            printf("%s cannot open '%s': No such file or directory\n", argv[0], argv[1]);
            exit(EXIT_FAILURE);
        }
        if (is_regular_file(argv[2])) {
            dst = open_file(argv[0], "w", argv[2]);
            copy_data(src, dst);
            fclose(src);
            fclose(dst);
        } else if (is_dir(argv[2])) {
            char dest_filename[PATH_MAX];
            snprintf(dest_filename, sizeof dest_filename, "%s/%s", argv[2], basename(argv[1]));
            dst = open_file(argv[0], "w", dest_filename);
            copy_data(src, dst);
            fclose(src);
            fclose(dst);
        } else {
            printf("Can't handle anything other than file or dir\n");
            exit(EXIT_FAILURE);
        }
        return 0;
    } else if (argc > 3) {
        char *dst_dir;
        DIR *dir;
        if ((dir = opendir(argv[argc-1])) == NULL) {
            printf("%s: target '%s': No such directory\n", argv[0], argv[argc-1]);
            exit(EXIT_FAILURE);
        }
        closedir(dir);
        dst_dir = argv[argc-1];
        FILE *src_file, *dst_file;
        char dest_filename[PATH_MAX];
        for (int i = 1; i < argc-1; i++) {
            if (is_regular_file(argv[i])) {
                src_file = open_file(argv[0], "r", argv[i]);
                snprintf(dest_filename, sizeof dest_filename, "%s/%s", dst_dir, basename(argv[i]));
                dst_file = open_file(argv[0], "w", dest_filename);
                copy_data(src_file, dst_file);
                fclose(src_file);
                fclose(dst_file);
            }
        }
    }
}
