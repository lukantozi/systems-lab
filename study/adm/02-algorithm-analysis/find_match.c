#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Outer loop goes at most n - m times (no complete alignment);
 * time complexity of nested loops multiplies, giving a worst-
 * case running time of O((n - m)(m + 2));
 *
 * presumably, strlen takes time linear in the length of the
 * string. Thus, the total worst-case running time is
 * O((n + m) + (n - m)(m + 2)) =>  O((n + m) + (n - m)(m)) ==
 * O(n + m + nm - m^2); 
 *
 * in any interesting scenario, n >= m, consequently we get 
 * n + m <= 2n = Theta(n) => (simplifies) => O(n + nm - m^2). 
 *
 * n <= nm, since m >= 1 for a problem to stay interesting.
 * Thus, n + nm = Theta(nm) => (drop additive n) => O(nm - m^2). 
 *
 * The inequality n >= m implies nm >= m^2, so negative term is not
 * enough to cancel the term on the left, so we can express the worst
 * case by simply as O(nm).
 */
int findmatch(char *p, char *t) {
    size_t i, j;
    size_t plen, tlen;

    plen = strlen(p);
    tlen = strlen(t);

    for (size_t i = 0; i <= tlen - plen; i++) {
        j = 0;
        while (j < plen && (t[i+j] == p[j])) j++;
        if (j == plen) return i;
    }

    return -1;
}

int main(void) {
    char *needle = "here";
    char *hay = "where is it?";
    int found = findmatch(needle, hay);

    if (found == -1) {
        printf("no match\n");
        return 1;
    }

    printf("found '%s' in '%s' starting at position: %d\n", needle, hay, found);
}
