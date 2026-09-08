#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static int compar(const void *p1, const void *p2) {
    const int *v1 = p1;
    const int *v2 = p2;

    return (*v1 > *v2) - (*v2 > *v1);
}

int union_of_two_sets(int *set1, int len1, int *set2, int len2, int *sunion, int *union_len) {
    if (set1 == NULL || set2 == NULL || sunion == NULL
            || union_len == NULL || len1 < 0 || len2 < 0)
        return -1;

    qsort(set1, len1, sizeof(int), compar);
    qsort(set2, len2, sizeof(int), compar);

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < len1 && j < len2) {
        if (set1[i] < set2[j]) {
            if (k == 0 || set1[i] != sunion[k-1]) {
                sunion[k] = set1[i];
                k++;
            }
            i++;
        } else if (set2[j] < set1[i]){
            if (k == 0 || set2[j] != sunion[k-1]) {
                sunion[k] = set2[j];
                k++;
            }
            j++;
        } else {
            if (k == 0 || set1[i] != sunion[k-1]) {
                sunion[k] = set1[i];
                k++;
            }
            i++;
            j++;
        }
    }

    while (i < len1) {
        if (k == 0 || set1[i] != sunion[k-1]) {
            sunion[k] = set1[i];
            k++;
        }
        i++;
    }

    while (j < len2) {
        if (k == 0 || set2[j] != sunion[k-1]) {
            sunion[k] = set2[j];
            k++;
        }
        j++;
    }

    *union_len = k;

    return 1;
}

int main(void) {
    int set1[] = {3, 5, 1, 6, 12, 40, 2, 10};
    int set2[] = {45, 5, 6, 3, 14, 39, 1};

    int union_len = 0;
    int *sunion = malloc(sizeof(int) * (size_t)(15));
    if (sunion == NULL)
        return -1;

    assert(union_of_two_sets(set1, 8, set2, 7, sunion, &union_len) == 1);

    printf("[");
    for (int i = 0; i < union_len; i++) {
        printf(i ? ", %d" : "%d", sunion[i]);
    }
    printf("]\n");

    free(sunion);
}
