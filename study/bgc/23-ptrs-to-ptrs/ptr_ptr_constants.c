#include <stdio.h>

int main(void) {
    int ***const q;
    //q++; not allowed

    int x = 3490;
    int *const p = &x;

    /* 
     * int **j = &p; would discard constant
     * qualifier
     */

    /* matching the type:
     * j here is not constant, but
     * the thing it points to is
     */
    int *const *j = &p;
    // k here is also constant itself
    int *const *k = &p;
    printf("%p\n", j);
    j++;
    printf("%p\n", j);
}
