#include <stdio.h>
#include "bytes.h"

/*
* Write a function int_shifts_are_arithmetic() that yields 1 when run on a
* machine that uses arithmetic right shifts for data type int and yields 0 otherwise.
* Your code should work on a machine with any word size. Test your code on several
* machines.
*/

int int_shifts_are_arithmetic(void) {
    int w = (sizeof(int) << 3) - 1;
    return 1 != ((1 << w) >> w);
    /* or 
     * return -1 >> 1 == -1;
     */
}

int main(void) {
    printf("%d\n", int_shifts_are_arithmetic());
}
