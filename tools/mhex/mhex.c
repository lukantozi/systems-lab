#include <stdio.h>

void hdump(FILE *f, int canon) {
    int c;
    int col = 0;
    int word2 = 0;
    int offset = 0;
    char buf[17];
    printf("%.7x ", offset);
    while ((c = fgetc(f)) != EOF) {
        if (!canon && word2 == 2) {
            putchar(0x20);
            word2 = 0;
        }
        // TODO: maybe move this logic after
        if (col == 16) {
            buf[col] = '\0';
            if (canon) printf("|%s|\n", buf);
            else putchar(0x0A);
            printf("%.7x ", offset);
            col = 0;
        }
        printf("%.2x%s", c, canon? " ": "");
        if (canon && col != 0 && (col % 8) == 0) putchar(0x20);
        // TODO: deal with non-printables
        if (c != 0x0A) buf[col] = c;
        col++;
        word2++;
        offset++;
    }
    if (canon) {
        // TODO: make padding work
        /*
        int pad = 28 - col;
        printf("%*c", pad, ' ');
        */
        buf[col] = '\0';
        printf("|%s|\n", buf);
        printf("%.7x\n", offset);
    } else {
        printf("\n%.7x\n", offset);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        hdump(stdin, 1);
    } else {
        for (int i = 1; i < argc; i++) {
            FILE *f = fopen(argv[i], "r");
            if (f == NULL) continue;
            hdump(f, 1);
            fclose(f);
        }
    }
}
