#include <stdio.h>
#include <stdarg.h>

int my_printf(int serial, const char *format, ...) {
    va_list va;
    int rv;

    printf("serial number: %d\n", serial);

    va_start(va, format);
    rv = vprintf(format, va);
    va_end(va);

    return rv;
}

int main(void) {
    int x = 10;
    float y = 3.2;

    my_printf(3450, "x is %d, y is %.2f\n", x, y);
}
