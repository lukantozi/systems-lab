#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *data = malloc(100 * sizeof(int));
    // free(data[20]); compiler is able to detect
    data[100] = 0;
}
