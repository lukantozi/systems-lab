#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
  [3] Use the partitioning idea of quicksort to give an algorithm that finds the
  median element of an array of n integers in expected O(n) time. (Hint: must
  you look at both sides of the partition?)
*/

#define LEN(arr) ((sizeof(arr)) / (sizeof(arr[0])))

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int h) {
    int i;
    for (i = l; i < h; i++) {
        if (arr[i] < arr[h]) {
            swap(&arr[i], &arr[l]);
            l++;
        }
    }
    swap(&arr[h], &arr[l]);
    return l;
}

int find_median(int arr[], int len) {
    if (arr == NULL || len <= 0)
        return -1;

    int i = 0;
    int j = len - 1;
    int t = (len - 1) / 2;
    int pi;
    int rand_ind;

    while (i <= j) {
        /* randomized partition to achieve O(n) */
        rand_ind = rand() % (j - i + 1) + i;
        swap(&arr[rand_ind], &arr[j]);

        pi = partition(arr, i, j);

        if (pi == t) {
            return arr[pi];
        }

        if (t < pi) {
            j = pi - 1;
        } else {
            i = pi + 1;
        }
    }

    return -1;
}

int main(void) {
    srand((unsigned)time(NULL));

    int arr1[] = {3, 13, 5, 6, 12, 1, 4, 2};
    int median = find_median(arr1, LEN(arr1));
    printf("%d\n", median);
    assert(median == 4);

    int arr2[] = {5, 1, 23, 4, 5, 13, 14, 15};
    median = find_median(arr2, LEN(arr2));
    printf("%d\n", median);
    assert(median == 5);
}
