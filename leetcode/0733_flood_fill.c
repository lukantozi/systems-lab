#include <stdio.h>
#include <stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int init_color, int rows, int *imageColSize, int **image, int sr, int sc, int color) {
    if (sr < 0 || sr >= rows || sc < 0 || sc >= imageColSize[sr]) return;
    if (image[sr][sc] != init_color) return;

    image[sr][sc] = color;

    dfs(init_color, rows, imageColSize, image, sr, sc+1, color);
    dfs(init_color, rows, imageColSize, image, sr, sc-1, color);
    dfs(init_color, rows, imageColSize, image, sr-1, sc, color);
    dfs(init_color, rows, imageColSize, image, sr+1, sc, color);
}

int **floodFill(int **image, int imageSize, int *imageColSize, int sr, int sc,
        int color, int *returnSize, int **returnColumnSizes) {

    *returnSize = imageSize;
    *returnColumnSizes = malloc(imageSize * sizeof(int));
    for (int i = 0; i < imageSize; i++) {
        (*returnColumnSizes)[i] = imageColSize[i];
    }

    int init_color = image[sr][sc];
    if (init_color == color) return image;

    dfs(init_color, imageSize, imageColSize, image, sr, sc, color);

    return image;
}

/*
 * void flood_fill_local(int rows, int cols, int image[][cols], int sr, int sc,
 *         int color) {
 *     int init_color = image[sr][sc];
 * 
 *     dfs(init_color, rows, cols, image, sr, sc, color);
 * }
 */

void print_image(int row, int col, int image[][col]) {
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            printf(" %d", image[r][c]);
        }
        putchar('\n');
    }
}

int main(void) {
    int image1[3][3] = {
        {0,0,1},
        {1,0,0},
        {1,1,1}
    };

    //int image2[3][3] = {0};

    print_image(3, 3, image1);
    //flood_fill_local(3, 3, image1, 2, 2, 2);
    putchar('\n');
    print_image(3, 3, image1);
}
