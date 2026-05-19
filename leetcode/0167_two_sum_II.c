#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int currentSum;
    int i = 0;
    int j = numbersSize - 1;
    int mid;
    *returnSize = 2;
    int *result = malloc(sizeof result *(*returnSize));
    while (i < j) {
        currentSum = numbers[i] + numbers[j];
        if (currentSum == target) {
            result[0] = i+1;
            result[1] = j+1;
            return result;
        }
        else if (currentSum < target) i++;
        else j--;
        
    }
    return result;
}

int main(void) {
    int size;
    int numbers[4] = {2,7,11,15};
    int *res1 = twoSum(numbers, 4, 9, &size);
    printf("[%d, %d]\n", res1[0], res1[1]);

    int numbers1[3] = {2,3,4};
    int *res2 = twoSum(numbers1, 3, 6, &size);
    printf("[%d, %d]\n", res2[0], res2[1]);

    int numbersn[2] = {-1,0};
    int *res3 = twoSum(numbersn, 2, -1, &size);
    printf("[%d, %d]\n", res3[0], res3[1]);
}
