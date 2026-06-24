#include <stdio.h>

int main(void) {
    printf("One\n");
    printf("Two\n");

    goto skip_3;

    printf("Three\n");

skip_3:
    printf("Five!\n");

infinite_loop:
    printf("Hello, world!\n");
    //goto infinite_loop;

    printf("Zero\n");

// labels are skipped and code is run as 
// if the labels were not there at all
label_1:
label_2:
    printf("One\n");
label_3:
    printf("Two\n");
label_4:
    printf("Three\n");
}
