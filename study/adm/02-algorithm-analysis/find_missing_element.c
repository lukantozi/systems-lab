#include <stdio.h>
#include <assert.h>

int find_missing_element(int *arr, int size) {
    int sum = (size + 1) * (size + 2) / 2;
    for (int i = 0; i < size; i++) {
        sum -= arr[i];
    }
    return sum;
}

int main(void) {
    int dist[4] = {3, 1, 4, 5};
    int res = find_missing_element(dist, 4);
    printf("%d\n", res);
    assert(res == 2);

    int dist1[4] = {3, 2, 4, 5};
    res = find_missing_element(dist1, 4);
    printf("%d\n", res);
    assert(res == 1);
}
