#include <stdio.h>
#include <time.h>

int main(void) {
    struct tm some_time = {
        .tm_year=101, // years since 1900
        .tm_mon=1,    // months since January -- [0, 11]
        .tm_mday=24,  // day of month -- [1, 31]
        .tm_hour=12,  // hours since midnight -- [0, 23]
        .tm_min=5,    // minutes after the hour -- [0, 59]
        .tm_sec=6,    // seconds after the minute -- [0, 60]
        .tm_isdst=-1, // Daylight Saving Time Flag
    };

    time_t some_time_epoch;

    some_time_epoch = mktime(&some_time);

    printf("%s", ctime(&some_time_epoch));
    printf("Is DST: %d\n", some_time.tm_isdst);
}

