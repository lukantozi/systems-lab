#include <stdio.h>

int dfs(int rows, int col, int grid[rows][col], int sr, int sc) {
    if (sr < 0 ||sr >= rows || sc < 0 || sc >= col || grid[sr][sc] == 0) 
        return 0;

    grid[sr][sc] = 0; // visited

   return 1 + dfs(rows, col, grid, sr, sc+1) +
        dfs(rows, col, grid, sr, sc-1) +
        dfs(rows, col, grid, sr-1, sc) +
        dfs(rows, col, grid, sr+1, sc);
}

int maxAreaOfIsland(int rows, int cols, int grid[rows][cols]) {
    int max = 0, local_max;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                local_max = dfs(rows, cols, grid, i, j);
                max = local_max > max ? local_max : max;
            }
        }
    }
    return max;
}

void print_grid(int rows, int cols, int grid[][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        putchar('\n');
    }
}

int main(void) {
    int test[][13] = { 
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    int rows = 8;
    int cols = 13;
    int max = maxAreaOfIsland(rows, cols, test);
    printf("%d\n", max);
    int test1[][8] = {{0,0,0,0,0,0,0,0}};
    rows = 1;
    cols = 8;
    max = maxAreaOfIsland(rows, cols, test1);
    printf("%d\n", max);
}
