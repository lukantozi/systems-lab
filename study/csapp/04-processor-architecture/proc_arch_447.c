#include <stdio.h>

/* Bubble sort: Pointer version */
void bubble_b(long *nums, long lenght)
{
    long i, last;
    for (last = lenght - 1; last > 0; last--) {
        for (i = 0; i < last; i++)
            if (*(nums + i + 1) < *(nums + i)) {
                /* swap */
                long t = *(nums + i + 1);
                *(nums + i + 1) = *(nums + i);
                *(nums + i) = t;
            }
    }
}

// int main(void)
// {
//     long n[] = {12, 3, 4, 10, 5, 23, 2};
//     bubble_b(n, 7);
//     for (int i = 0; i < 7; i++) {
//         printf("%d ", d[i]);
//     }
//     printf("\n");
// }
