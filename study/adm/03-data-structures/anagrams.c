#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compchar(const void *a, const void *b) {
    const unsigned char ca = *(const unsigned char *)a;
    const unsigned char cb = *(const unsigned char *)b;
    return (ca > cb) - (ca < cb);
}

int anagram_sort(char *x, char *y) {
    qsort(x, strlen(x), sizeof(char), compchar);
    qsort(y, strlen(y), sizeof(char), compchar);

    size_t i;
    for (i = 0; x[i] != '\0' && (x[i] == y[i]); i++);

    return x[i] == y[i];
}

int anagram_freq(const char *x, const char *y) {
    if (strlen(x) != strlen(y))
        return 0;

    int char_freq[256] = {0};
    size_t i;
    for (i = 0; x[i] != '\0'; i++) {
        char_freq[(unsigned char)x[i]]++;
        char_freq[(unsigned char)y[i]]--;
    }

    for (i = 0; i < 256; i++)
        if (char_freq[i] != 0)
            return 0;
    return 1;
}

int main(void) {
    char s1[] = "insect";
    char s2[] = "incest";
    assert(anagram_freq(s1, s2) == 1);
    assert(anagram_sort(s1, s2) == 1);

    char s3[] = "a";
    char s4[] = "abc";
    assert(anagram_freq(s3, s4) == 0);
    assert(anagram_sort(s3, s4) == 0);

    char s5[] = "abc";
    char s6[] = "a";
    assert(anagram_freq(s5, s6) == 0);
    assert(anagram_sort(s5, s6) == 0);

    char s7[] = "silent";
    char s8[] = "listen";
    assert(anagram_freq(s7, s8) == 1);
    assert(anagram_sort(s7, s8) == 1);

    char s9[] = "ad";
    char s10[] = "bc";
    assert(anagram_freq(s9, s10) == 0);
    assert(anagram_sort(s9, s10) == 0);

    char s11[] = "";
    char s12[] = "";
    assert(anagram_freq(s11, s12) == 1);
    assert(anagram_sort(s11, s12) == 1);
}
