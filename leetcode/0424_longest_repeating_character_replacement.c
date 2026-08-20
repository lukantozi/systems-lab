#include <assert.h>
#include <stdio.h>

int characterReplacement(char *s, int k) {
    int table[26] = {0};
    int i;
    int ind;
    int max = 0;
    int f = 0;
    int j = 0;

    for (i = 0; s[i] != '\0'; i++) {
        ind = s[i] % 26;
        table[ind]++; 
        f = table[ind] > f ? table[ind] : f;

        while (i - j + 1 - f > k) {
            table[s[j] % 26]--;
            j++;
        }

        ind = i - j + 1;
        max = max > ind ? max : ind;
    }

    return max;
}

int main(void) {
    char *s1 = "ABAB";
    char *s2 = "AABABBA";
    assert(characterReplacement(s1, 2) == 4);
    assert(characterReplacement(s2, 1) == 4);
}
