#include <stdio.h>

extern char **environ;

int main(void) {
    char **p;
    for (p = environ; *p != NULL; p++) {
        printf("%s\n", *p);
    }
    // or
    int i;
    for (i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }
}
