#include <stdint.h>
#include <stdio.h>

typedef int_least16_t char16_t;
typedef int_least32_t char32_t;

int main(void) {
    char16_t *s = u"Hello, world!";
    char16_t c = u'B';

    char32_t *s1 = U"Hello, world!";
    char32_t c1= U'B';

    char16_t pi = u'\u03c0';

#if __STDC_UTF_16__
    printf("UTF_16: %s\n", pi == 0x3c0? "True": "False");
#else
    printf("UTF_32: %s\n", pi == 0x3c0? "True": "Fasle");
#endif
}
