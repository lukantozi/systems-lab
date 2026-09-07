#include <assert.h>
#include <stdio.h>

/* set1 and set2 must be sorted in ascending order */
int pair_sums(int *set1, int *set2, int size, int target) {
    if (set1 == NULL || set2 == NULL || size <= 0)
        return -1;

    int i = 0;
    int j = size - 1;
    int sum;
    while (i < size && j >= 0) {
        sum = set1[i] + set2[j];
        if (sum > target)
            j--;
        else if (sum < target)
            i++;
        else
            return 1;
    }

    return 0;
}

int main(void) {
    /* considering both after sorting */
    int set1[] = {1, 4, 6, 10, 12};
    int set2[] = {1, 2, 4, 13, 14};

    assert(pair_sums(set1, set2, 5, 2) == 1);
    assert(pair_sums(set1, set2, 5, 13) == 1);
    assert(pair_sums(set1, set2, 5, 25) == 1);
    assert(pair_sums(set1, set2, 5, 26) == 1);
    assert(pair_sums(set1, set2, 5, 27) == 0);
}
