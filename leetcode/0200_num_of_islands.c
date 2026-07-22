#include <stdio.h>

void dfs(int rows, int cols, char grid[][cols], int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0')
        return;

    grid[r][c] = '0';

    dfs(rows, cols, grid, r+1, c);
    dfs(rows, cols, grid, r-1, c);
    dfs(rows, cols, grid, r, c+1);
    dfs(rows, cols, grid, r, c-1);
}

int numIslands(int rows, int cols, char grid[][cols]) {
    int islands = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '1') {
                islands++;
                dfs(rows, cols, grid, i, j);
            }
        }
    }
    return islands;
}

int main(void) {
    int rows = 4, cols = 5;
    char grid1[4][5] = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    int isl1 = numIslands(rows, cols, grid1);
    char grid2[4][5] = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    int isl2 = numIslands(rows, cols, grid2);
    printf("%d, %d\n", isl1, isl2);
}
