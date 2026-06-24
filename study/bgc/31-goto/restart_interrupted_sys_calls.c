#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(void) {
    char buf[100];
    int byte_count;

retry:
    byte_count = read(0, buf, sizeof(buf) - 1);

    if (byte_count == -1) {           // an error occured
        if (errno == EINTR) {         // but just an interruption
            printf("Restarting...\n");
            goto retry;
        }
    }
}
