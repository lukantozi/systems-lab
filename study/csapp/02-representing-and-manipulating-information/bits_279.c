/* CS:APP 3e, Problem 2.79: multiply by three, then divide by four with
 * truncation toward zero, retaining the exercise's overflow model. */
int mul3div4(int x) {
    int p = (x << 1) + x;
    int ps_mask = ~(!!(p & ~(UINT_MAX >> 1))) + 1;

    return (~ps_mask & p >> 2) | (ps_mask & ((p + (1 << 2) - 1) >> 2));

}

/*
 * Alternative solution using a directly selected bias:
 * int w = sizeof(int) << 3;
 * int product = (x << 1) + x;
 * int sign_mask = product >> (w - 1);
 * int bias = 3 & sign_mask;
 * 
 * return (product + bias) >> 2;
 */
