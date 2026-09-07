#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    RED,
    BLUE,
    YELLOW
} Color;

int sort_by_color(int pairs, int arr[][2]) {
    if (arr == NULL)
        return -1;

    int red[pairs][2];
    int rcount = 0;

    int blue[pairs][2];
    int bcount = 0;

    int yellow[pairs][2];
    int ycount = 0;

    for (int i = 0; i < pairs; i++) {
        switch (arr[i][1]) {
            case RED:
                red[rcount][0] = arr[i][0];
                red[rcount][1] = arr[i][1];
                rcount++;
                break;

            case BLUE:
                blue[bcount][0] = arr[i][0];
                blue[bcount][1] = arr[i][1];
                bcount++;
                break;

            case YELLOW:
                yellow[ycount][0] = arr[i][0];
                yellow[ycount][1] = arr[i][1];
                ycount++;
                break;

            default:
                printf("wrong color at arr[%d][1]\n", i);
                return -1;
        }
    }

    memcpy(arr, red, sizeof(red[0]) * rcount);
    memcpy(arr + rcount, blue, sizeof(blue[0]) * bcount);
    memcpy(arr + rcount + bcount, yellow, sizeof(yellow[0]) * ycount);
    return 1;
}

int main(void) {
    int col_num[][2] = {{1,BLUE}, {3,RED}, {4,BLUE}, {6,YELLOW}};
    sort_by_color(4, col_num);

    for (int i = 0; i < 4; i++) {
        printf("%d - %d\n", col_num[i][0], col_num[i][1]);
    }
    putchar('\n');
}
