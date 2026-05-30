#include <stdio.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    int file_counter = 0;
    if (argc == 1) {
        while (fgets(buffer, sizeof buffer, stdin) != NULL) {
            fputs(buffer, stdout);
        }
    } else if (argc > 1) {
        FILE *files[argc-1];
        FILE *file;
        for (int i = 1; i < argc; i++) {
            if ((file = fopen(argv[i], "a")) == NULL) continue;
            else files[file_counter++] = file;
        }
        while (fgets(buffer, sizeof buffer, stdin) != NULL) {
            for (int i = 0; i < file_counter; i++) {
                fputs(buffer, files[i]);
                fflush(files[i]);
            }
            fputs(buffer, stdout);
        }
        for (int i = 0; i < file_counter; i++) {
            fclose(files[i]);
        }
    }
}
