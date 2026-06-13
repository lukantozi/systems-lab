#include <stdio.h>

struct cabin_info {
    int window_count;
    int o2level;
};

struct spaceship {
    char *manufacturer;
    struct cabin_info ci;
};

int main(void) {
    struct spaceship s = {
        .manufacturer="NASA",
        .ci.window_count = 5,
        .ci.o2level = 30,
    };

    struct spaceship h = {
        .manufacturer="X",
        .ci={
            .window_count = 10,
            .o2level = 21,
        }
    };

    printf("%s: %d seats, %d%% oxygen\n",
            s.manufacturer, s.ci.window_count, s.ci.o2level);
    printf("%s: %d seats, %d%% oxygen\n",
            h.manufacturer, h.ci.window_count, h.ci.o2level);
}
