#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process(FILE *f) {
    char buff_sent[4096];
    int size = 100;
    char *buff;
    if ((buff = malloc(size)) == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    int pos;
    char c;

    while (fgets(buff_sent, sizeof buff_sent, f) != NULL) {
        pos = 0;
        while ((c = buff_sent[pos++]) != '\0' && c != 0x20) {
            buff[i++] = c;
            if (i >= size - 1) {
                char *new_buff;
                if ((new_buff = realloc(buff, size += 50)) == NULL) {
                    free(buff);
                    exit(EXIT_FAILURE);
                } else buff = new_buff;
            }
        }
        buff[i++] = '\n';
    }
    buff[i++] = '\0';
    fputs(buff, stdout);
    free(buff);
}

int main(int argc, char *argv[]) {
    if (argc == 1) process(stdin);
    else if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            FILE *f;
            if ((f = fopen(argv[i], "r")) == NULL) {
                continue;
            }
            process(f);
            fclose(f);
        }
    } else {
        printf("Usage: ./mcut FILE");
        return 1;
    }
    return 0;
}
