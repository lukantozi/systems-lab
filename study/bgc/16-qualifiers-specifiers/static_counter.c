#include <stdio.h>

void counter() {
    static int count = 1;
    printf("This function has been called %d time(s)\n", count);
    count++;
}

int main(void) {
    counter();
    counter();
    counter();
    counter();
    counter();
}
