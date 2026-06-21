#include <stdio.h>
#include <wchar.h>

int main(void) {
    wchar_t *s = L"Hello, World!";
    wchar_t c = L'B';

    printf("%ls %lc\n", s, c);

#ifdef __STDC_ISO_10646__
    printf("It's unicode!\n");
    printf("Standard: %ld\n", __STDC_ISO_10646__);
#endif
}
