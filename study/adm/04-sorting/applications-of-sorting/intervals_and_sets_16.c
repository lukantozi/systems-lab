#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
  [5] You are given a set S of n seg on the line, where segment Si ranges
  from li to ri. Give an efficient algorithm to select the fewest number of seg
  whose union completely covers the interval from 0 to m.
*/

static int compar(const void *p1, const void *p2) {
    const int *v1 = p1;
    const int *v2 = p2;

    int first = (v1[0] > v2[0]) - (v2[0] > v1[0]);
    if (first == 0) {
        return (v1[1] > v2[1]) - (v2[1] > v1[1]);
    }
    return first;
}

int find_min_seg(int seg[][2], int len, int (*min_seg)[2], int *min_seg_len, int m) {
    if (seg == NULL || min_seg == NULL || min_seg_len == NULL || len <= 0) {
        return -1;
    }

    *min_seg_len = 0;

    if (m <= 0) {
        return 1;
    }

    qsort(seg, len, sizeof(*seg), compar);
    int covered_right = 0;
    int i = 0;
    while (covered_right < m) {
        int best_index = -1;
        int best_right = covered_right;

        /* every segment that starts at or before the point
         * currently covered by the already selected segments. */
        /* (0, 3) (1, 2) (1, 3) (1, 4) (2, 5) (3, 4) (3, 7) (7, 10) */
        while (i < len && seg[i][0] <= covered_right) {
            if (seg[i][1] > best_right) {
                best_right = seg[i][1];
                best_index = i;
            }
            i++;
        }

        /* no reachable segment extends coverage farther. */
        if (best_index == -1) {
            return 0;
        }

        min_seg[*min_seg_len][0] = seg[best_index][0];
        min_seg[*min_seg_len][1] = seg[best_index][1];
        (*min_seg_len)++;

        covered_right = best_right;
    }

    return 1;
}

void print_seg(int seg[][2], int n, int (*min_seg)[2], int min_seg_len, int m) {
    for (int i = 0; i < n; i++) {
        printf("(%d, %d) ", seg[i][0], seg[i][1]);
    }
    printf("\n0 -> %d:\n", m);
    for (int i = 0; i < min_seg_len; i++) {
        printf("(%d, %d) ", min_seg[i][0], min_seg[i][1]);
    }
    putchar('\n');
}

int main(void) {
    int seg[][2] = {{7, 10}, {1, 2}, {3, 4}, {2, 5}, {3, 7}, {1, 4}, {1, 3}, {0, 3}};
    int n = 8;
    int (*min_seg)[2] = malloc(sizeof(*min_seg) * n);
    int min_seg_len;

    int m = 10;
    assert(find_min_seg(seg, n, min_seg, &min_seg_len, m) == 1);
    print_seg(seg, n, min_seg, min_seg_len, m);

    putchar('\n');
    m = 2;
    assert(find_min_seg(seg, n, min_seg, &min_seg_len, m) == 1);
    print_seg(seg, n, min_seg, min_seg_len, m);

    putchar('\n');
    m = 4;
    assert(find_min_seg(seg, n, min_seg, &min_seg_len, m) == 1);
    print_seg(seg, n, min_seg, min_seg_len, m);

    free(min_seg);
}
