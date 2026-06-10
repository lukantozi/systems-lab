#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int replace(char *pattern, char *rplc, FILE *f) {
    char buf[4096];
    size_t size = strlen(pattern);
    while (fgets(buf, sizeof buf, f) != NULL) {
        int ptr = 0;
        int ptrn_ptr = 0;
        int found = 0;
        int pos;
        while (buf[ptr] != '\0') {
            ptrn_ptr = 0;
            if (buf[ptr] == pattern[ptrn_ptr]) {
                pos = ptr;
                while ( buf[ptr] == pattern[ptrn_ptr] &&
                        buf[ptr] != '\0') {
                    ptr++;
                    ptrn_ptr++;
                }
                if (pattern[ptrn_ptr] == '\0') {
                    found = 1;
                    int i;
                    for (i = 0; i < pos; i++) putchar(buf[i]);
                    if (rplc) printf("%s", rplc);
                    for (i = pos+size; buf[i] != '\0'; i++) putchar(buf[i]);
                    break;
                }
            } else ptr++;
        }
        if (!found) printf("%s", buf);
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("Usage: ./msed-lite {pattern/replace} [input-file]\n");
        return 1;
    } else if (argc == 2) {
        char *ptrn = strtok(argv[1], "/");
        if (ptrn) {
            char *rplc = strtok(NULL, "/");
            replace(ptrn, rplc, stdin);
        }
    } else if (argc > 2) {
        char *ptrn = strtok(argv[1], "/");
        if (ptrn) {
            char *rplc;
            rplc = strtok(NULL, "/");
            for (int i = 2; i < argc; i++) {
                FILE *f = fopen(argv[i], "r");
                if (f == NULL) continue;
                replace(ptrn, rplc, f);
                fclose(f);
            }
        }
    }
    return 0;
}
