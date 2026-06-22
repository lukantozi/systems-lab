#include <stdio.h>
#include <assert.h>

#define PI 3.14159

int main(void) {
    assert(PI > 3);
    // assert(PI > 4); would abort

    int goats = -100;
    // assert(goats >= 0); would abort
    goats += 100;
    assert(goats >= 0);
}
