#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int w = 10;

    typedef int goat[w];

    goat x;

    for (int i = 0; i < w; i++) {
        x[i] = i*i;
    }

    for (int i = 0; i < w; i++) {
        printf("%d\n", x[i]);
    }

    w = 20; // goat is still an array of 10 ints 
}
