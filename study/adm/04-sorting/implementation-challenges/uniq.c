#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
  [3] Implement an algorithm that takes an input array
  and returns only the unique elements in it.
*/

#define LEN(arr) ((sizeof(arr)) / (sizeof(arr[0])))

static int compar(const void *p1, const void *p2) {
    const int *v1 = p1;
    const int *v2 = p2;

    return (*v1 > *v2) - (*v2 > *v1);
}

int uniq(int *arr, int len, int **arr_uniq, int *uniq_len) {
    if (arr == NULL || arr_uniq == NULL || uniq_len == NULL || len < 0)
        return -1;

    *arr_uniq = NULL;
    *uniq_len = 0;

    if (len == 0)
        return 1;

    *arr_uniq = malloc(sizeof(**arr_uniq) * len);
    if (*arr_uniq == NULL)
        return -1;

    qsort(arr, len, sizeof(int), compar);

    int i = 0;
    int val;
    while (i < len) {
        (*arr_uniq)[*uniq_len] = arr[i];
        (*uniq_len)++;
        val = arr[i];
        while (i < len && arr[i] == val)
            i++;
    }
    return 1;
}

void print_arr(int arr[], int len) {
    printf("[");
    for (int i = 0; i < len; i++) {
        printf(i ? ", %d" : "%d", arr[i]);
    }
    printf("]\n");
}

int main(void) {
    int arr1[] = {3, 5, 1, 6, 1, 4, 12, 8, 3, 5, 4, 4, 12, 10};
    int *arr1_uniq;
    int uniq_len = 0;

    print_arr(arr1, LEN(arr1));
    assert(uniq(arr1, LEN(arr1), &arr1_uniq, &uniq_len) == 1);
    print_arr(arr1, LEN(arr1));
    print_arr(arr1_uniq, uniq_len);

    free(arr1_uniq);
}
