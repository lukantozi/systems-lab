#include <assert.h>
#include <stdio.h>

/*
  [5] Give an efficient algorithm to take the array of citation counts (each count
  is a non-negative integer) of a researcher’s papers, and compute the researcher’s
  h-index. By definition, a scientist has index h if h of his or her n papers have
  been cited at least h times, while the other n − h papers each have no more than
  h citations.
*/

#define LEN(arr) ((sizeof(arr)) / (sizeof(arr[0])))

/* 
 * requires an array to be sorted in descending order O(nlongn);
 * runs in O(n), so total time complexity is O(nlogn)
 */
int hindex(int arr[], int len) {
    if (arr == NULL)
        return -1;

    int index = 0;

    for (int i = 0; i < len; i++) {
        if (arr[i] >= i + 1)
            index = i + 1;
        else
            return index;
    }
    return index;
}

int main(void) {
    int arr1[] = {15, 14, 13, 12, 12, 12, 11, 10, 5, 4, 3};
    assert(hindex(arr1, LEN(arr1)) == 8);

    int arr2[] = {84, 20, 19, 12, 11, 9, 9, 9, 9, 7, 6, 6, 6, 6};
    assert(hindex(arr2, LEN(arr2)) == 9); 

    int arr3[] = {84, 20, 19, 12, 11, 10, 10, 10, 10, 10, 6, 6, 6, 6};
    assert(hindex(arr3, LEN(arr3)) == 10);

    int arr4[] = {84, 20, 19, 12, 11, 9, 9, 8, 8, 7, 6, 6, 6, 6};
    assert(hindex(arr4, LEN(arr4)) == 8);
}
