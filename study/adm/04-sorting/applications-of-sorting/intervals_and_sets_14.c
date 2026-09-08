#include <stdio.h>
#include <stdlib.h>

/*
  [5] Given a list I of n intervals, specified as (xi, yi) pairs, return a list where
  the overlapping intervals are merged. For I = {(1, 3), (2, 6), (8, 10), (7, 18)} the
  output should be {(1, 6), (7, 18)}. Your algorithm should run in worst-case
  O(n log n) time complexity.
*/

static int compar(const void *p1, const void *p2) {
    const int *v1 = (const int *) p1;
    const int *v2 = (const int *) p2;

    return (v1[0] > v2[0]) - (v2[0] > v1[0]);
}

int main(void) {
    int inter[][2] = {{1,3}, {2,6}, {8,10}, {7,18}};
    int n = 4;
    qsort(inter, n, 2 * sizeof(int), compar);

    int i;
    for (i = 0; i < n; i++) {
        printf("(%d, %d)\n", inter[i][0], inter[i][1]);
    } /* (1, 3) (2, 6) (7, 18) (8, 10) */

    int (*inter_merged)[2] = malloc(sizeof(*inter_merged) * n);
    if (inter_merged == NULL)
        return 1;

    int merged_ind = 0;
    inter_merged[merged_ind][0] = inter[0][0];
    inter_merged[merged_ind][1] = inter[0][1];

    for (i = 1; i < n; i++) {
        if (inter_merged[merged_ind][1] >= inter[i][0]) {
            if (inter_merged[merged_ind][1] < inter[i][1])
                inter_merged[merged_ind][1] = inter[i][1];
        } else {
            merged_ind++;
            inter_merged[merged_ind][0] = inter[i][0];
            inter_merged[merged_ind][1] = inter[i][1];
        }
    }

    putchar('\n');
    for (i = 0; i < merged_ind+1; i++) {
        printf("(%d, %d)\n", inter_merged[i][0], inter_merged[i][1]);
    }

    free(inter_merged);
}
