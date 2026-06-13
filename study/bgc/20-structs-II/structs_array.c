#include <stdio.h>

struct passenger {
    char *name;
    int covid_vaccinated;
};

#define MAX_PASSENGERS 8

struct spaceship {
    char *manufacturer;
    struct passenger passenger[MAX_PASSENGERS];
};

int main(void) {
    struct spaceship s = {
        .manufacturer="X",
        .passenger = {
            [0].name = "John, Doe",
            [0].covid_vaccinated = 0,

            [5] = {.name="Will, Harvard", .covid_vaccinated=1},
        }
    };

    printf("Passengers in %s spaceship:\n", s.manufacturer);

    for (int i = 0; i < MAX_PASSENGERS; i++) {
        if(s.passenger[i].name != NULL) {
        printf("    %s (%svaccinated)\n",
                s.passenger[i].name,
                s.passenger[i].covid_vaccinated? "": "not ");
        }
    }
}
