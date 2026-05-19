#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <linux/limits.h>

int main(int argc, char *argv[]) {
    const char *name;
    if (argc == 1) name = ".";
    else if (argc == 2) name = argv[1];
    else {
        printf("Usage: ./mls [FILENAME]\n");
        return 1;
    }

    DIR *stream; 
    if ((stream = opendir(name)) == NULL) {
        perror("opendir error");
        exit(1);
    }

    struct stat statbuf;
    struct dirent *inode;
    char time_display[100];
    char full_path[PATH_MAX];
    const char *filename;
    struct tm *tm;
    unsigned links, uid, gid, mode;

    while ((inode = readdir(stream)) != NULL) {
        filename = inode->d_name;
        snprintf(full_path, sizeof full_path, "%s/%s", name, filename);
        int stat_out = stat(full_path, &statbuf);
        if (stat_out == -1) {
            perror("stat error");
            exit(errno);
        }
        tm = localtime(&statbuf.st_mtime);
        links = statbuf.st_nlink;
        uid = statbuf.st_uid;
        gid = statbuf.st_gid;
        mode = statbuf.st_mode;
        strftime(time_display, sizeof time_display, "%b %d %H:%M", tm);
        printf("%u %u %u %u %lu %s -- %s\n", mode, links, uid, gid, statbuf.st_size, time_display, filename);
    }
    putchar('\n');
    closedir(stream);
}
