#include <stdio.h>

int minSubArrayLen(int target, int* nums, int numsSize) {
    int i = 0, j = 0, sum = 0;
    int min_sub = 100001; // nums.length <= 1e5, so this is a sentinel
    while (j < numsSize) {
        sum += nums[j];
        while (sum >= target) {
            min_sub = min_sub > (j - i + 1) ? (j - i + 1) : min_sub;
            sum -= nums[i++];
        }
        j++;
    }
    return min_sub == 100001 ? 0 : min_sub;
}

int main(void) {
    int nums1[6] = {2,3,1,2,4,3};
    printf("Expect 2, got: %d\n", minSubArrayLen(7, nums1, 6));

    int nums2[3] = {1,4,4};
    printf("Expect 1, got: %d\n", minSubArrayLen(4, nums2, 3));

    int nums3[8] = {1,1,1,1,1,1,1,1};
    printf("Expect 0, got: %d\n", minSubArrayLen(11, nums3, 8));

    int nums4[5] = {1,2,3,4,5};
    printf("Expect 3, got: %d\n", minSubArrayLen(11, nums4, 5));

    int nums5[3] = {10,2,3};
    printf("Expect 1, got: %d\n", minSubArrayLen(6, nums5, 3));
}
