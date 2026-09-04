#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * input: 2n real numbers
 * implement O(nlogn) algorithm that partitions
 * numbers into n pairs, and so that partition
 * minimizes the maximum sum of pairs
 * Example:
 *  - given an array [1, 3, 5, 9], its possible
 *  - partitions are ((1,3), (5,9)), ((1,5), (3,9)),
 *  - ((1,9), (3,5)) and pair sums for these partitions
 *  - are (4, 14), (6, 12), and (10, 8). pair that we
 *  - want here is (10, 8), since it's maximum value is
 *  - minimum maximum among other pairs
 */

static int compar(const void *p1, const void *p2) { 
    int *v1 = (int *) p1;
    int *v2 = (int *) p2;

    return *v1 - *v2;
}


int minimum_maximum_sum(int *arr, int arrsize) {
    if (arr == NULL || arrsize == 0)
        return -1;

    qsort(arr, arrsize, sizeof(int), compar);

    int sum_max = INT_MIN;
    int sum_cur = 0;

    for (int i = 0, j = arrsize - 1; i < j; i++, j--) {
        sum_cur = arr[i] + arr[j];
        printf("%d + %d = %d\n", arr[i], arr[j], arr[i] + arr[j]);
        if (sum_cur > sum_max)
            sum_max = sum_cur;
    }

    return sum_max;
}

int main(void) {
    int arr[] = {5, 1, 4, 10, 3, 8, 9, 11};
    printf("%d\n", minimum_maximum_sum(arr, 8));
}
