#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFF_SIZE 4096

char buff_first[BUFF_SIZE];
char buff_second[BUFF_SIZE];

void process(FILE *input, FILE *output) {
    if (fgets(buff_first, sizeof buff_first, input) == NULL) {
        exit(EXIT_SUCCESS);
    }
    if (fputs(buff_first, output) == EOF) {
        perror("fputs");
        exit(EXIT_FAILURE);
    }
    while (fgets(buff_second, sizeof buff_second, input) != NULL) {
        if (strcmp(buff_first, buff_second) == 0) continue;
        else {
            if (fputs(buff_second, output) == EOF) {
                perror("fputs");
                exit(EXIT_FAILURE);
            }
            strcpy(buff_first, buff_second);
        }
    }
}

FILE *open_file(const char *filename, const char *mode) {
    FILE *f;
    if ((f = fopen(filename, mode)) == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    return f;
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        process(stdin, stdout);
    }
    else if (argc == 2) {
        FILE *f; 
        f = open_file(argv[1], "r");
        process(f, stdout);
        fclose(f);
    }
    else if (argc == 3) {
        FILE *src;
        FILE *dest;
        src = open_file(argv[1], "r");
        dest = open_file(argv[2], "w");
        process(src, dest);
        fclose(src);
        fclose(dest);
    }
    return 0;
}
