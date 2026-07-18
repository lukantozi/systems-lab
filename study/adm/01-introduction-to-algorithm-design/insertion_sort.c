#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertion_sort(char s[], int n) {
    int i, j;

    for (int i = 1; i < n; i++) {
        j = i;
        while (j > 0 && s[j] < s[j-1]) {
            swap(&s[j], &s[j-1]);
            j--;
        }
    }
}


int main(void) {
    char ins[] = "INSERTIONSORT";
    int size = strlen(ins);

    insertion_sort(ins, size);
    printf("%s\n", ins);
}
