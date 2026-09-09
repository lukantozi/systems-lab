#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int good_echo() {
    size_t bufsize = 1024;
    char *buf = malloc(bufsize);
    if (buf == NULL) {
        perror("malloc");
        return -1;
    }

    size_t buflen;
    int flag = 1;
    while (flag) {
        if (fgets(buf, bufsize, stdin) == NULL) {
            if (feof(stdin)) {
                break;
            }
            free(buf);
            perror("fgets");
            return -1;
        }

        buflen = strlen(buf);
        if (buflen > 0 && buf[buflen-1] == '\n') {
            flag = 0;
        }

        if (fwrite(buf, buflen, sizeof(char), stdout) != 1) {
            free(buf);
            perror("fwrite");
            return -1;
        }
    }

    free(buf);
    return 1;
}

int main(void) {
    assert(good_echo() == 1);
    return 0;
}
