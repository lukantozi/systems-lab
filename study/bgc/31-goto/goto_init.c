#include <stdio.h>

/* demo for handling system startup failures */
int main(void) {
    if (init_system_1() == -1) {
        goto shutdown;
    }

    if (init_system_2() == -1) {
        goto shutdown_1;
    }

    if (init_system_3() == -1) {
        goto shutdown_2;
    }

    if (init_system_4() == -1) {
        goto shutdown_3;
    }

    run_program();

    shutdown_system4();

shutdown_3:
    shutdown_system3();

shutdown_2:
    shutdown_system2();

shutdown_1:
    shutdown_system1();

shutdown:
    printf("All subsystems shut down.\n");
}
