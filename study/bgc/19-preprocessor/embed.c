#include <stdio.h>

int main(void) {
    int a[] = {
    #embed "/dev/random" __limit__(5) if_empty(999)
    };
    printf("/dev/random: ");
    for (int i = 0; i < 5; i++) {
        printf("%x", a[i]);
    }
    putchar('\n');

    int x = (
    #embed "foo.dat" if_empty(999)
            )
    ;
    printf("foo.dat: ");
    printf("%d\n", x);

    int y = (
    #embed "baz.dat" if_empty(999)
            );
    printf("baz.dat: ");
    printf("%d\n", y);

    int xa[] = {
    #embed "/dev/urandom" __limit__(3) prefix(11, ) suffix(,99)
    };

    printf("/dev/urandom: ");
    for (int i = 0; i < sizeof(xa)/sizeof(xa[0]); i++) {
        printf("%d", xa[i]);
    }
    putchar('\n');

    int xe[] = {
    #embed "foo.dat" suffix(,)
        0
    };
    printf("foo.dat: '%d'\n", xe[0]);
}
