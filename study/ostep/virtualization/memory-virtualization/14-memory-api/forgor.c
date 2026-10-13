#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr = malloc(sizeof(int));
    *ptr = 5;
    printf("%d\n", *ptr);
    /* forgor freeing */
}
