#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* 
 * T(n) = (n - 1) + (n - 2) ... + 2 + 1.
 * We are adding up to n - 1 with average value of 
 * n/2. Thus, T(n) => (n - 1) * n/2 = O(n^2)
 */
void selection_sort(int s[], int n) {
    int i, j;
    int min;

    for (i = 0; i < n; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (s[j] < s[min]) min = j;
        }
        swap(&s[i], &s[min]);
    }
}

int main(void) {
    int arr[] = {5, 6, 1, 2, 4};
    selection_sort(arr, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}
