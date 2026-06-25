#include <stdio.h>

int main(void) {
    int i;
    float f;
    char c;

    char *s = _Generic(i,
            int: "var is an int",
            float: "var is a float",
            default: "var is some type"
            );
    printf("%s\n", s);
}
