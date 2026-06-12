#include <stdio.h>
#include <stdlib.h>

void reverse(FILE *fp) {
    char buf[4096];
    int newline;
    int counter;
    while ((fgets(buf, sizeof buf, fp)) != NULL) {
        counter = 0;
        newline = 0;
        while (buf[counter] != '\0') counter++;
        if (buf[counter-1] == '\n') {
            newline = 1;
            counter -= 2;
        } else counter--;
        while (counter >= 0) {
            putchar(buf[counter--]);
        }
        if (newline) putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        reverse(stdin);
    } else {
        for (int i = 1; i < argc; i++) {
            FILE *f; 
            if (!(f = fopen(argv[i], "r"))) continue;
            reverse(f);
            fclose(f);
        }
    }
}
