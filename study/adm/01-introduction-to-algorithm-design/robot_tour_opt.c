#include <stdio.h>
#include <math.h>

double pt_dis(int x_1, int y_1, int x_2, int y_2) {
    int square_x = (x_2 - x_1) * (x_2 - x_1);
    int square_y = (y_2 - y_1) * (y_2 - y_1); 
    double sum_x_y_sq = square_x + square_y;
    double distance = sqrt(sum_x_y_sq); 
    return distance;
}

void shortest_cycle(int pt_x[], int pt_y[], int n) {
    int j;
    double dist_new;
    for (int i = 1; i < n; i++) {
        double dist_min = 1000; 
        j = i;
        while (j > 0 && ((dist_new = pt_dis(pt_x[j], pt_y[j], pt_x[j-1], pt_y[j-1])) < dist_min)) {
            int tmp_x = pt_x[j];
            int tmp_y = pt_y[j];
            pt_x[j] = pt_x[j-1];
            pt_x[j-1] = tmp_x;
            pt_y[j] = pt_y[j-1];
            pt_y[j-1] = tmp_y;
            dist_min = dist_new;
            j--;
        }
    }
}

int main(void) {
    int x[4] = {1, 3, 6, 4};
    int y[4] = {4, 5, 4, 1};
    shortest_cycle(x, y, 4);
    for (int i = 0; i < 4; i++) {
        printf("(%d, %d)\n", x[i], y[i]);
    }
}
