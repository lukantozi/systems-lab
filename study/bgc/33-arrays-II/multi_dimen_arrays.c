#include <stdio.h>

void print_array(int a[][2]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", a[i][j]);
        }
        putchar('\n');
    }
}

int main(void) {
    int a[3][2] = {
        {1, 2},
        {3, 4},
        {5, 6}
    };
    print_array(a);
    putchar('\n');

    int b[3][2] = {
        {1, 2},
        {3},
        {5, 6}
    };
    print_array(b);
    putchar('\n');

    int c[3][2] = {
        {1, 2},
    //    {3},
        {5, 6}
    };
    print_array(c);
    putchar('\n');

    int d[3][2] = { 1, 2, 3, 4, 5, 6};
    print_array(d);
    putchar('\n');

    int e[3][2] = { 1, 2, 3 };
    print_array(e);
    putchar('\n');

    int f[3][2] = {0};
    print_array(f);
}
