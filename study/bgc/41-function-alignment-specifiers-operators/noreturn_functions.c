#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

noreturn void foo(void) { // this func should never return
    printf("something\n");
    // it doesn't return, it exits here
    // without it, compiler would complain
    // that the noreturn func returns
    exit(1); 
}

int main(void) {
    foo();
}
