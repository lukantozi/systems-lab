#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *range = malloc(sizeof(int) * *returnSize);
    range[0] = -1;
    range[1] = -1;

    int low = 0;
    int high = numsSize - 1;
    int ind_left = -1;
    int mid;
    while (high >= low) {
        mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            ind_left = mid;
            high = mid - 1;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (ind_left == -1)
        return range;

    high = numsSize - 1;
    low = ind_left;
    int ind_right;
    while (high >= low) {
        mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            ind_right = mid;
            low = mid + 1;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    range[0] = ind_left;
    range[1] = ind_right;
    return range;
}

int main(void) {
    int return_size;

    int nums1[] = {5,7,7,8,8,10};
    int *res1 = searchRange(nums1, 6, 8, &return_size);
    printf("[%d,%d]\n", res1[0], res1[1]);
    free(res1);

    int nums2[] = {5,7,7,8,8,10};
    int *res2 = searchRange(nums2, 6, 6, &return_size);
    printf("[%d,%d]\n", res2[0], res2[1]);
    free(res2);

    int nums3[] = {};
    int *res3 = searchRange(nums3, 0, 0, &return_size);
    printf("[%d,%d]\n", res3[0], res3[1]);
    free(res3);
}
