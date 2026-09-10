#include <stdio.h>

/*
  [5] Consider an n×n array A containing integer elements (positive, negative, and
  zero). Assume that the elements in each row of A are in strictly increasing order,
  and the elements of each column of A are in strictly decreasing order. (Hence
  there cannot be two zeros in the same row or the same column.) Describe an
  efficient algorithm that counts the number of occurrences of the element 0 in A.
  Analyze its running time.
*/

#define ROWS(mat) ((sizeof(mat)) / (sizeof(mat[0])))
#define COLS(mat) ((sizeof(mat[0])) / (sizeof(mat[0][0])))

int count_zeros(int rows, int cols, const int matrix[][cols]) {
    if (matrix == NULL || rows <= 0 || cols <= 0) {
        return -1;
    }

    int i = 0;
    int j = 0;
    int zeros = 0;
    while (i < rows && j < cols) {
        while (i < rows && matrix[i][j] > 0) {
            i++;
        }
        if (i == rows) {
            return zeros;
        }
        if (matrix[i][j] == 0) {
            zeros++;
            i++;
            j++;
        } else {
            j++;
        }
    }
    return zeros;
} /* theta(rows + cols) = theta(n) */

int main(void) {
    int matrix1[][5] = {
        { 9, 10, 12, 14, 17},
        { 7,  8, 10, 13, 15},
        { 4,  6,  8, 11, 12},
        { 1,  3,  5,  7,  9},
        {-2,  0,  2,  4,  6}
    };
    int zeros = count_zeros(ROWS(matrix1), COLS(matrix1), matrix1);
    printf("%d\n", zeros);

    int matrix2[][5] = {
        { 8,  9, 11, 12, 15},
        { 5,  7,  8, 10, 13},
        { 2,  4,  6,  8,  9},
        {-1,  0,  3,  5,  7},
        {-4, -2,  0,  2,  4}
    };
    zeros = count_zeros(ROWS(matrix2), COLS(matrix2), matrix2);
    printf("%d\n", zeros);

    int matrix3[][6] = {
        {12, 14, 16, 18, 20, 22},
        { 8, 10, 12, 14, 16, 18},
        { 4,  6,  8, 10, 12, 14},
        { 0,  2,  4,  6,  8, 10},
        {-3,  0,  2,  4,  6,  8},
        {-6, -3,  0,  2,  4,  6}
    };
    zeros = count_zeros(ROWS(matrix3), COLS(matrix3), matrix3);
    printf("%d\n", zeros);

    int matrix4[][4] = {
        { 7,  8,  9, 10},
        { 5,  6,  7,  8},
        { 3,  4,  5,  6},
        { 1,  2,  3,  4}
    };
    zeros = count_zeros(ROWS(matrix4), COLS(matrix4), matrix4);
    printf("%d\n", zeros);
}
