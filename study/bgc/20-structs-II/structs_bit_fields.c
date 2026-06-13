#include <stdio.h>

struct foo { // will only combine adjacent bit-fields
    unsigned int a:5;
    unsigned int b:5;
    unsigned int c;
    unsigned int d;
};

struct bar { // to reserve some bits for hardware reasons
    unsigned char a:2;
    unsigned char :5; // unnamed bit-field
    unsigned char b:1;
};

struct baz { // pack data into two uints
    unsigned int a:1;
    unsigned int b:2;
    unsigned int :0; // zero-width unnamed bit-field
    unsigned int c:3;
    unsigned int d:4;
};

int main(void) {
    printf("%zu\n", sizeof(struct foo));
    printf("%zu\n", sizeof(struct bar));
    printf("%zu\n", sizeof(struct baz));
}
