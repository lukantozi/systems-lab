#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* a) maximizes |x - y| from unsorted array in O(n) */
int maximize(int *nums, int numssize, int *max, int *min) {
    if (nums == NULL ||
            numssize == 0 ||
            max == NULL ||
            min == NULL)
        return -1;

    *max = INT_MIN;
    *min = INT_MAX;
    for (int i = 0; i < numssize; i++) {
        if (nums[i] < *min)
            *min = nums[i];
        if (nums[i] > *max)
            *max = nums[i];
    }

    return 1;
}

/* b) maximizes |x - y| from sorted array in O(1) */
int maximize_1(int *nums, int numssize, int *max, int *min) {
    if (nums == NULL || numssize == 0 || max == NULL || min == NULL)
        return -1;

    *max = nums[numssize-1];
    *min = nums[0];
    
    return 1;
}

static int compar(const void *p1, const void *p2) {
    int *v1 = (int *) p1;
    int *v2 = (int *) p2;

    return *v1 - *v2;
}

/* TODO: c) minimizes |x - y| (x != y) form unsorted array in O(nlogn) */
int minimize(int *nums, int numssize, int *high, int *low) {
    if (nums == NULL || high == NULL || low || NULL) {
        return -1;
    }
    qsort(nums, numssize, sizeof(int), compar);
    // if ()

    return 1;
}

/* minimizes |x - y| from sorted array in O(n) */
int minimize_1(int *nums, int numssize, int *high, int *low) {
    if (nums == NULL || numssize == 0 || high == NULL || low == NULL)
        return -1;

    int min_diff = INT_MAX;
    int cur_diff = 0;
    for (int i = 0; i < numssize - 1; i++) {
        cur_diff = nums[i+1] - nums[i];
        if (cur_diff < min_diff) {
            min_diff = cur_diff;
            *high = nums[i+1];
            *low = nums[i];
        }
    } 

    return 1;
}

int main(void) {
    int max;
    int min;
    int set[] = {6, 13, 19, 3, 8};

    assert(maximize(set, 5, &max, &min));
    assert(max - min == 16);

    int set1[] = {2, 4, 9, 10, 40};
    assert(maximize(set1, 5, &max, &min));
    assert(max - min == 38);

    int high;
    int low;
    assert(minimize_1(set1, 4, &high, &low) == 1);
    assert(high == 10);
    assert(low == 9);
}
