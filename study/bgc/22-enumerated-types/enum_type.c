#include <stdio.h>

enum resource {
    SHEEP,
    WOOD,
    WHEAT,
    BRICK,
    WATER
};

typedef enum resour {
    SOME,
    OTHER,
    STUFF
} RESOURCE;

enum piece {
    KING,
    PAWN,
    BISHOP,
    KNIGHT,
    ROOK,
    QUEEN=9,
} k = KNIGHT, p = PAWN;

int main(void) {
    enum resource r = WOOD;
    if (r == WOOD) {
        printf("Let's start fire!\n");
    }

    RESOURCE r1 = OTHER;
    printf("%d\n", r1);

    printf("Pawn(value): %d, Knight(value): %d\n", p, k);
    enum piece q = QUEEN;
    printf("Queen(value): %d\n", q);
}
