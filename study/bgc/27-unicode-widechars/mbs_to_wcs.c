#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <string.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "");

    char *mb_string = "The cost is \u20ac1.23";
    size_t mb_len = strlen(mb_string);

    // holds 128 wide chars
    wchar_t wc_string[128];

    // returns the number of wide chars
    size_t wc_len = mbstowcs(wc_string, mb_string, 128);

    printf("multibyte: \"%s\" (%zu bytes)\n", mb_string, mb_len);
    printf("wide char: \"%ls\" (%zu characters)\n", wc_string, wc_len);

    size_t len_in_chars = mbstowcs(NULL, "§¶°±π€•", 0); 
    printf("len in chars: %zu\n", len_in_chars);
    printf("len in bytes: %zu\n", strlen("§¶°±π€•"));
}
