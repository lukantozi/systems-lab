#include <assert.h>
#include <stdio.h>

/*
  [3] Give an efficient algorithm to rearrange an array of n keys so that all
  the negative keys precede all the non-negative keys. Your algorithm must be
  in-place, meaning you cannot allocate another array to temporarily hold the
  items. How fast is your algorithm?
*/

static void swap(int *v1, int *v2) {
    if (v1 == NULL || v2 == NULL)
        return;

    int temp;
    temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

int neg_first_opt(int arr[], int len) {
    int i = 0;
    int j = len - 1;

    while (i < j) {
        while (i < j && arr[i] < 0)
            i++;

        while (i < j && arr[j] >= 0)
            j--;

        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    return 1;
} /* O(n) */

int neg_first(int arr[], int len) {
    int temp;
    int i;
    int j;
    for (i = 0; i < len; i++) {
        if (arr[i] >= 0) {
            for (j = i; j < len; j++) {
                if (arr[j] >= 0)
                    continue;
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                break;
            }
        }
    }
    return 1;
} /* O(n^2) */

void print_array(int arr[], int len) {
    printf("[");
    for (int i = 0; i < len; i++) {
        printf(i ? ", %d" : "%d", arr[i]);
    }
    printf("]\n");
}

void test(int arr[], int len) {
    printf("before sorting: ");
    print_array(arr, len);
    assert(neg_first_opt(arr, len) == 1);
    printf(" after sorting: ");
    print_array(arr, len);
}

int main(void) {
    int arr1[] = {0, 3, 5, -1, 4, -4, 10, -2, 0};
    int len = sizeof(arr1) / sizeof(arr1[0]);
    test(arr1, len);

    int arr2[] = {-1, -5, -6, 4, 5, 6, 7, 7, -1};
    len = sizeof(arr2) / sizeof(arr2[0]);
    test(arr2, len);
}
