#include <stdio.h>
#include <unistd.h>

void hdump(FILE *f, int canon) {
    int c;
    int bytes = 0;
    int word2 = 0;
    int offset = 0;
    int len = 0;
    int size = canon? 80: 49;
    char line[size];
    char buf[17];

    len += sprintf(line + len, "%.8x%s", offset, canon? "  ": " ");
    while ((c = fgetc(f)) != EOF) {
        if (!canon && word2 == 2) {
            line[len++] = 0x20;
            word2 = 0;
        }

        if (canon && bytes != 0 && (bytes % 8) == 0) {
            line[len++] = 0x20;
        }

        len += sprintf(line + len, "%.2x%s", c, canon? " ": "");
        buf[bytes] = (c > 31 && c < 127)? c: '.';
        bytes++;
        word2++;
        offset++;

        if (bytes == 16) {
            buf[bytes] = '\0';
            if (canon) len += sprintf(line + len, " |%s|%c", buf, '\n');
            else line[len++] = 0x0A;

            line[len] = '\0';
            printf("%s", line);
            len = 0;
            len += sprintf(line + len, "%.8x%s", offset, canon? "  ": " ");
            bytes = 0;
            word2 = 0;
            buf[0] = 0;
        }
    }

    buf[bytes] = '\0';
    if (canon) {
        printf("%-*s|%s|\n%.8x\n", size-20, line, buf, offset);
    }
    else printf("%s\n%.8x\n", line, offset);
}

int main(int argc, char *argv[]) {
    int opt;
    int canon = 0;
    if ((opt = getopt(argc, argv, "C")) != -1) {
        switch (opt) {
            case 'C':
                canon = 1;
                break;
        }
    }
    if (argc == 1 + canon) {
        int opt;
        hdump(stdin, canon);
    } else {
        for (int i = 1 + canon; i < argc; i++) {
            FILE *f = fopen(argv[i], "r");
            if (f == NULL) continue;
            hdump(f, canon);
            fclose(f);
        }
    }
}
