#include <stdio.h>

union foo {
    float a, c, d;
    short b;
};

union bar {
    int a, b, c, d;
    float e, f;
    char g, h;
};

int main(void) {
    union foo x;
    x.a = 3.141590;

    printf("%f\n", x.a);
    printf("%d\n", x.b); // same bit pattern different repr

    union bar y;
    int *bar_int_p = (int *)&y;
    float *bar_float_p = (float *)&y;

    y.a = 12;
    printf("%d\n", y.a);
    printf("%d\n", *bar_int_p);

    y.f = 3.141592;
    printf("%f\n", y.f);
    printf("%f\n", *bar_float_p);
    // same as above
    union bar *p = (union bar *)bar_float_p;
    printf("%f\n", p->f);
}
