#include <stdio.h>

int main(void) {
    int x = 3490;
    int *p = &x;
    int **q = &p;
    printf("%d %d\n\n", *p, **q);
    printf("%*d stored at %p\n", 14, x, p);
    printf("%p stored at %p\n", p, &p);
    printf("%p stored at %p\n", q, &q);
}
