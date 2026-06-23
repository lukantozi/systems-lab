#include <stdio.h>

int sum(int count, int *v) {
    int total = 0;

    for (int i = 0; i < count; i++) {
        total += v[i];
    }

    return total;
}

// can prototype this way
void sth(int count, int v[count]);
void sth(int count, int v[*]);

int main(void) {
    int x[5];

    int a = 5;
    int y[a];

    for (int i = 0; i < 5; i++) {
        x[i] = y[i] = i + 1;
    }

    printf("%d\n", sum(5, x));
    printf("%d\n", sum(a, y));
}
