#include <stdio.h>

int main(void) {
    /* print bullets on UTF-8 console
     * printf("\xE2\x80\xA2 Bullet 1\n");
     * printf("\xE2\x80\xA2 Bullet 2\n");
     * printf("\xE2\x80\xA2 Bullet 3\n");
    */

    /* print portable bullets */
    // 16-bit
    printf("\u2022 Bullet 1\n");
    printf("\u2022 Bullet 2\n");
    // 32-bit
    printf("\U00002022 Bullet 3\n");
}
