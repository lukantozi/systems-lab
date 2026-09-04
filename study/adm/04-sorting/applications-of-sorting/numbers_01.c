#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
 * - grinch wants to:
 *     - partition 2n players into two teams of n
 *     - each player has numerical value how good they are
 *     - divide teams as unfairly as possible
 * 
 * - show O(nlogn) way of doing such evil job
 * 
 * 1. quicksort players
 * 2. split them in half
 */

static int compar(const void *p1, const void *p2) {
    int *pl1 = (int *) p1;
    int *pl2 = (int *) p2;

    return (*pl1 > *pl2) - (*pl1 < *pl2);
}

int split_teams_unevenly(int *pool, int pool_size, int **team1, int **team2) {
    if (pool == NULL
            || pool_size == 0
            || pool_size % 2 != 0
            || *team1 == NULL
            || *team2 == NULL)
        return -1;

    qsort(pool, pool_size, sizeof(int), compar);
    *team1 = pool;
    *team2 = pool + pool_size / 2;

    return 1;
}

int display_teams(int *team1, int size1, int *team2, int size2) {
    if (size1 != size2) {
        puts("something went wrong in splitting teams...\n");
        return -1;
    }

    printf("[%d", team1[0]);
    for (int i = 1; i < size1; i++) {
        printf(", %d", team1[i]);
    }

    puts("]\nVS");

    printf("[%d", team2[0]);
    for (int i = 1; i < size2; i++) {
        printf(", %d", team2[i]);
    }
    puts("]");
    return 1;
}

int main(void) {
    int players[] = {4, 1, 6, 1, 6, 10, 40, 43, 5, 4};
    int *team1;
    int *team2;

    assert(split_teams_unevenly(players, 10, &team1, &team2) == 1);
    assert(display_teams(team1, 5, team2, 5) == 1);
}
