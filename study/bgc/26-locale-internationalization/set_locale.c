#include <stdio.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "");
    char *current_locale = setlocale(LC_ALL, NULL);
    printf("%s\n", current_locale);

    struct lconv *x = localeconv();
    printf("currency symbol: %s\n", x->currency_symbol);
    printf("international currency symbol: %s\n", x->int_curr_symbol);
    printf("monetary decimal point: %s\n", x->mon_decimal_point);
    printf("monetary thousands sep: %s\n", x->mon_thousands_sep);
}
