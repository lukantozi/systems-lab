#include <math.h>

/* replace V with A, B, or C */
#define V

#ifdef A
    #define EXPR(x) (fabs(x))
#elifdef B
    #define EXPR(x) (0.0)
#elifdef C
    #define EXPR(x) (-x)
#else
    #define EXPR(x) (x)
#endif

double simplefun(double x) {
    return EXPR(x);
}
