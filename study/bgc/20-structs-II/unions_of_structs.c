#include <stdio.h>

#define ANTELOPE 1
#define OCTOPUS 2

struct common {
    int type;
};

struct antelope {
    int type;

    int loudness;
};

struct octopus {
    int type;

    int sea_creature;
    int intelligence;
};

union animal {
    struct common common;
    struct antelope antelope;
    struct octopus octopus;
};

void print_animal(union animal *x) {
    switch (x->common.type) {
        case ANTELOPE:
            printf("Antelope: loudness=%d\n", x->antelope.loudness);
            break;

        case OCTOPUS:
            printf("Octopus: sea_creature=%d\n", x->octopus.sea_creature);
            printf("         intelligence=%d\n", x->octopus.intelligence);
            break;

        default:
            printf("Unkown animal type\n");
    }
}

int main(void) {
    union animal a = {.antelope.type=ANTELOPE, .antelope.loudness=10};
    union animal b = {
        .octopus.type=OCTOPUS, .octopus.sea_creature=1,
        .octopus.intelligence=13
    };
    print_animal(&a);
    print_animal(&b);
}
