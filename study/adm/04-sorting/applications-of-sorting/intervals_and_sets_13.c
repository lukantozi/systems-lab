#include <limits.h>

/*
  [5] A camera at the door tracks the entry time a_i and exit time b_i (assume
  b_i > a_i) for each of n persons p_i attending a party. Give an O(n log n) algo-
  rithm that analyzes this data to determine the time when the most people were
  simultaneously present at the party. You may assume that all entry and exit
  times are distinct (no ties).
*/

int main(void) {
    int times[][2] = {{3, 6}, {2, 10}, {1, 7}, {5, 9}};

    /* split times into enter and exit O(n) */
    int enter[] = {3, 2, 1, 5};
    int exit[] = {6, 10, 7, 9};

    /* sort enter and exit times O(2nlogn) */
    int enter_sorted[] = {1, 2, 3, 5};
    int exit_sorted[] = {6, 7, 9, 10};

    int max_people = INT_MIN;
    int curr_people = 0;
    int max_people_time = 0;
    int curr_time = 0;
    int enter_ind = 0;
    int exit_ind = 0;

    while (enter_ind < 4 && exit_ind < 4) {
        if (enter_sorted[enter_ind] < exit_sorted[exit_ind]) {
            curr_time = enter_sorted[enter_ind];
            curr_people++;
            enter_ind++;
        } else if (exit_sorted[exit_ind] < enter_sorted[enter_ind]) {
            curr_time = exit_sorted[exit_ind];
            curr_people--;
            exit_ind++;
        }
        if (curr_people > max_people) {
            max_people = curr_people;
            max_people_time = curr_time;
        }
    }

    /** 
     * 1. increase count if time matches enter_sorted
     * 2. decrease count if time matches exit_sorted
     * 3. every iteration check if current count is greater
     *    than curr_max
     * O(n); total O(n) + O(2nlogn) + O(n) = O(nlogn)
     */
}
