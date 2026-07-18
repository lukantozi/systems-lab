#include <stdio.h>

void insertion_sort(char s[], int n) {
    int i, j;

    for (i = 1; i < n; i++) {
        j = i;
        while ((j > 0) && (s[j] < s[j-1])) {
            char tmp = s[j]; 
            s[j] = s[j-1];
            s[j-1] = tmp;
            j--;
        }
    }
}


int main(void) {
    char ins[] = "INSERTIONSORT";

    int count = 0;
    while (ins[count] != '\0') {
       count++;
    }
    insertion_sort(ins, count);
    printf("%s\n", ins);
}
