#include <stdio.h>

int main(void) {
    int random_nums[] = {
#if __has_embed("/dev/urandom")
    #embed "/dev/urandom" limit(5)
#elif __has_embed("myrandoms.dat")
    #embed "/dev/myrandoms.dat" limit(5)
#else
    140,178,12,51
#endif
    };
    for (int i = 0; i < sizeof(random_nums) / sizeof(random_nums[0]); i++) {
        printf("%d\n", random_nums[i]);
    }
}
