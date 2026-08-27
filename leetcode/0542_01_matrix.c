#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int **updateMatrix(int mat[][3], int matSize, int *matColSize, int *returnSize, int **returnColumnSizes) {
    *returnSize = matSize;
    *returnColumnSizes = malloc(matSize * (sizeof **returnColumnSizes));
    int **updated_mat = malloc(*returnSize * sizeof(*updated_mat));
    int visited_ind = 0, i, j;

    for (i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = matColSize[0];
        updated_mat[i] = malloc((*returnColumnSizes)[0] * sizeof(*updated_mat[i]));
    }

    int visited[100001];
    for (i = 0; i < *returnSize; i++) {
        for (j = 0; j < *returnColumnSizes[0]; j++) {
            if (mat[i][j] == 1) {
                updated_mat[i][j] = INT_MAX;
            } else if (mat[i][j] == 0) {
                updated_mat[i][j] = 0;
                visited[visited_ind++] = i * *returnColumnSizes[0] + j;
            }
        }
    }

    i = 0;
    int curr_row, curr_col, curr_visited_ind, r, c;
    while (i < visited_ind) {
        curr_visited_ind = visited_ind;
        for (;i < curr_visited_ind; i++) {
            r = visited[i] / *returnColumnSizes[0];
            c = visited[i] % *returnColumnSizes[0];
            for (j = 0; j < 4; j++) {
                curr_row = r + dirs[j][0];
                curr_col = c + dirs[j][1];
                if (curr_row < 0 || curr_row >= *returnSize ||
                        curr_col < 0 ||
                        curr_col >= *returnColumnSizes[0])
                    continue;
                if (updated_mat[curr_row][curr_col] == INT_MAX) {
                    updated_mat[curr_row][curr_col] = updated_mat[r][c] + 1;
                    visited[visited_ind++] = curr_row * *returnColumnSizes[0] + curr_col;
                }
            }
        }
    }

    return updated_mat;
}

void print_mat(int rows, int cols, int **mat) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        putchar('\n');
    }
}

int main(void) {
    int mat1[][3] = {{0,0,0},{0,1,0},{0,0,0}};
    int matColSize[] = {3,3,3};
    int returnsize;
    int *returncolumnsize;
    int **updated_mat = updateMatrix(mat1, 3, matColSize, &returnsize, &returncolumnsize);
    print_mat(3, 3, updated_mat);
    for (int i = 0; i < 3; i++) {
        free(updated_mat[i]);
    }
    free(updated_mat);
    free(returncolumnsize);

    putchar('\n');

    int mat2[3][3] = {{0,0,0},{0,1,0},{1,1,1}};
    int *returncolumnsize1;
    int **updated_mat1 = updateMatrix(mat2, 3, matColSize, &returnsize, &returncolumnsize1);
    print_mat(3, 3, updated_mat1);
    for (int i = 0; i < 3; i++) {
        free(updated_mat1[i]);
    }
    free(updated_mat1);
    free(returncolumnsize1);
}
