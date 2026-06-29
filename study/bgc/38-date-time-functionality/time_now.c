#include <stdio.h>
#include <time.h>

int main(void) {
    time_t now;

    printf("%ld\n", time(&now));

    now = time(NULL);
    printf("%ld\n", now);

    printf("%s\n", ctime(&now));

    printf("Local: %s", asctime(localtime(&now)));
    printf("  UTC: %s", asctime(gmtime(&now)));
}
