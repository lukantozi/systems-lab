#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int s[], int l, int h) {
    int i;         /* counter */
    int p;         /* pivot element index */
    int firsthigh; /* divider position for pivot element */

    p = h;
    firsthigh = l;
    for (i = l; i < h; i++) {
        if (s[i] < s[p]) {
            swap(&s[i], &s[firsthigh]);
            firsthigh++;
        }
    }
    swap(&s[p], &s[firsthigh]);
    return firsthigh;
}

void quicksort(int s[], int l, int h) {
    int p;

    if (l < h) {
        p = partition(s, l, h);
        quicksort(s, l, p - 1);
        quicksort(s, p + 1, h);
    }
}

void print_arr(int *arr, size_t len) {
    printf("[");
    if (len)
        printf("%d", arr[0]);
    for (int i = 1; i < len; i++)
        printf(", %d", arr[i]);
    printf("]\n");
}

int main(void) {
    int test1[] = {5, 5, 1, 2, 3, 2, 13, 1, 4};
    size_t len = sizeof(test1) / sizeof(test1[0]);
    print_arr(test1, len);
    quicksort(test1, 0, len-1);
    print_arr(test1, len);
    return 0;
}
