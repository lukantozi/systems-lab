#include <assert.h>
#include <stdio.h>
#include <string.h>

int orangesRotting(int rows, int cols, int grid[][cols]) {
    int fresh = 0;
    int rottn = 0;
    int mins = 0;
    int rottn_ind = 0;
    int rottn_arr[rows*cols];
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2)
                rottn_arr[rottn_ind++] = i * cols + j;
            if (grid[i][j] == 1)
                fresh++;
        }
    }

    int i = 0, k, j, r, c, curr_row, curr_col, curr_rottn_ind;
    while (i < rottn_ind && fresh > 0) {
        curr_rottn_ind = rottn_ind;
        for (; i < curr_rottn_ind; i++) {
            r = rottn_arr[i] / cols;
            c = rottn_arr[i] % cols;
            for (j = 0; j < 4; j++) {
                curr_row = r + dirs[j][0];
                curr_col = c + dirs[j][1];
                if (curr_row >= 0 && curr_row < rows &&
                        curr_col >= 0 &&
                        curr_col < cols &&
                        grid[curr_row][curr_col] == 1) {
                    grid[curr_row][curr_col] = 2;
                    rottn_arr[rottn_ind++] = curr_row * cols + curr_col;
                    fresh--;
                }
            }
        }
        mins++;
    }
    return fresh == 0 ? mins : -1;
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
    int grid1[3][3] = {{2,1,1},{1,1,0},{0,1,1}};
    print_grid(3, 3, grid1);
    assert(orangesRotting(3, 3, grid1) == 4);
    putchar('\n');

    int grid2[3][3] = {{2,1,1},{0,1,1},{1,0,1}};
    print_grid(3, 3, grid2);
    assert(orangesRotting(3, 3, grid2) == -1);
    putchar('\n');

    int grid3[1][2] = {{0,2}};
    print_grid(1, 2, grid3);
    assert(orangesRotting(1, 2, grid3) == 0);
}
