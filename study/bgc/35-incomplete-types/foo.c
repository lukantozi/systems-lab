#include <stdio.h>
#include "bar.h" // includes incomplete type for my_array

int main(void) {
    my_array[0] = 10;

    printf("%d\n", my_array[0]);
}
