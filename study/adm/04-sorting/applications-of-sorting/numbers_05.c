#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static int compar(const void *p1, const void *p2) {
    int *v1 = (int *)p1;
    int *v2 = (int *)p2;
    return (*v1 > *v2) - (*v2 > *v1);
}

int find_mode(int *set, int size, int *mode) {
    if (set == NULL || mode == NULL || size <= 0)
        return -1;

    qsort(set, size, sizeof(int), compar);

    int cur_value = set[0];
    int max_value = cur_value;
    int cur_count = 1;
    int max_count = 1;

    for (int i = 1; i < size; i++) {
        if (set[i] != cur_value) {
            if (cur_count > max_count) {
                max_count = cur_count;
                max_value = cur_value;
            }
            cur_value = set[i];
            cur_count = 1;
        } else {
            cur_count += 1;
        }
    }

    if (cur_count > max_count) {
        max_count = cur_count;
        max_value = cur_value;
    }
    *mode = max_value;

    return 1;
}

int main(void) {
    int set[] = {4,6,2,4,3,1,1,1};
    int mode;
    assert(find_mode(set, 8, &mode) == 1);
    assert(mode == 1);

    int set1[] = {4, 5, 6, 12, 3, 4, 5, 6, 5};
    assert(find_mode(set1, 9, &mode) == 1);
    assert(mode == 5);
}
