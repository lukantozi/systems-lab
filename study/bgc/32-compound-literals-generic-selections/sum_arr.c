#include <stdio.h>

int sum(int p[], int count) {
    int total = 0;

    for (int i = 0; i < count; i++) {
        total += p[i];
    }
    return total;
}

int main(void) {
    int s = sum((int []){1, 2, 3, 4}, 4);
    printf("%d\n", s);
}
