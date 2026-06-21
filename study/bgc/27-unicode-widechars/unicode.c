#include <stdio.h>
#include <string.h>

int main(void) {
    char *s = "\u20AC1.23";
    char *b = "\U0001D4D1";
    printf("%s\n", s);
    printf("%zu\n", strlen(s));
    printf("%s\n", b);

    // gcc on my system complains
    printf("%x\n", '\u20ac'); 
    printf("%x\n", '€');
}
