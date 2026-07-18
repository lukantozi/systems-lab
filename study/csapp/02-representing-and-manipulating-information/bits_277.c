/*
 * Suppose we are given the task of generating code to multiply integer variable x
 * by various different constant factors K. To be efficient, we want to use only the
 * operations +, -, and <<. For the following values of K, write C expressions to
 * perform the multiplication using at most three operations per expression.
 */

/* A. K = 17 */
int mult_by_17(int x) {
    return (x << 4) + x;
}

/* B. K = −7 */
int mult_by_neg_7(int x) {
    return 0 - ((x << 3) - x);
    // shorter: x - (x << 3);
}

/* C. K = 60 */
int mult_by_60(int x) {
    return (x << 6) - (x << 2);
}

/* D. K = −112 */
int mult_by_neg_112(int x) {
    return 0 - ((x << 7) - (x << 4));
    // shorter: (x << 4) - (x << 7);
}
