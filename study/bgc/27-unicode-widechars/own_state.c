#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <wchar.h>
#include <string.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "");

    char *mb_string = "The cost is \u20ac1.23";
    size_t mb_len = strlen(mb_string);

    wchar_t wc_string[128];

    mbstate_t mbs;
    memset(&mbs, 0, sizeof mbs);

    const char *invalid = mb_string;

    size_t wc_len = mbsrtowcs(wc_string, &invalid, 128, &mbs);

    if (invalid == NULL) {
        printf("No invalid characters found\n");

        printf("multibyte: \"%s\" (%zu bytes)\n", mb_string, mb_len);
        printf("wide char: \"%ls\" (%zu chars) \n", wc_string, wc_len);
    } else {
        ptrdiff_t offset = invalid - mb_string;
        printf("Invalid character at offet %td\n", offset);
    }

    /* for functions that manage their own states
    mbstowcs(NULL, NULL, 0); // reset the parse state
    mbstowcs(dest, src, 100);
    */
}
