#include <stdio.h>

/*
  [5] Suppose an array A consists of n elements, each of which is red, white, or
  blue. We seek to sort the elements so that all the reds come before all the whites,
  which come before all the blues. The only operations permitted on the keys are:

    • Examine(A,i) – report the color of the ith element of A.
    • Swap(A,i,j) – swap the ith element of A with the jth element.

  Find a correct and efficient algorithm for red–white–blue sorting. There is a
  linear-time solution.
*/

typedef enum {
    RED,
    WHITE,
    BLUE
} Rwb;

static void swap(Rwb *p1, Rwb *p2) {
    Rwb temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int sort_rwb(Rwb arr[], int len) {
    int red_end = 0;
    int i = 0;
    int blue_beg = len - 1;

    while (i <= blue_beg) {
        switch (arr[i]) {
            case RED:
                swap(&arr[i], &arr[red_end]);
                red_end++;
                i++;
                break;
            case WHITE:
                i++;
                break;
            case BLUE:
                swap(&arr[i], &arr[blue_beg]);
                blue_beg--;
                break;
        }
    }
    return 1;
}

int sort_rwb_count(Rwb arr[], int len) {
    int r = 0;
    int w = 0;
    int i;

    for (i = 0; i < len; i++) {
        if (arr[i] == RED)
            r++;
        if (arr[i] == WHITE)
            w++;
    }

    for (i = 0; i < r; i++)
        arr[i] = RED;

    for (i = r; i < r + w; i++)
        arr[i] = WHITE;

    for (i = r + w; i < len; i++)
        arr[i] = BLUE;

    return 1;
}

void print_arr(Rwb arr[], int len) {
    printf("[");
    for (int i = 0; i < len; i++) {
        printf(i ? ", %d" : "%d", arr[i]);
    }
    printf("]\n");
}

void test(Rwb arr[], int len) {
    printf("before sorting: ");
    print_arr(arr, len);
    sort_rwb(arr, len);
    printf(" after sorting: ");
    print_arr(arr, len);
}

int main(void) {
    Rwb arr[] = {BLUE, RED, WHITE, RED, WHITE, BLUE, WHITE, WHITE, BLUE, WHITE, RED};
    int len = sizeof(arr) / sizeof(arr[0]);
    test(arr, len);
    putchar('\n');
    Rwb arr1[] = {RED, RED, RED, WHITE, BLUE, WHITE, RED};
    len = sizeof(arr1) / sizeof(arr1[0]);
    test(arr1, len);
}

