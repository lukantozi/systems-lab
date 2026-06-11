#include <stdio.h>
#include <math.h>

#define SQR(x) ((x) * (x))
#define TRIANGLE_AREA(w, h) (0.5 * (w) * (h))
#define QUADP(a, b, c) ((-(b) + sqrt((b) * (b) - 4 * (a) * (c))) / (2 * (a)))
#define QUADM(a, b, c) ((-(b) - sqrt((b) * (b) - 4 * (a) * (c))) / (2 * (a)))
#define QUAD(a, b, c) QUADP(a, b, c), QUADM(a, b, c)

int main(void) {
    printf("SQR(%s) = %d\n", "5", SQR(5));
    printf("SQR(%s) = %d\n", "5 + 4", SQR(5 + 4));

    printf("TRIANGLE_AREA(0.5 * %s) = %.2f\n", "(4) * (2)", TRIANGLE_AREA(4, 2));
    printf("TRIANGLE_AREA(0.5 * %s) = %.2f\n", "(5) * (3)", TRIANGLE_AREA(5, 3));

    printf("x^2 + 3x - 4 = 0\n");
    printf("x = %.2f or x = %.2f\n", QUAD(1, 3, -4));
}
