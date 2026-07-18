/*
 * Write code for a function mul3div4 that, for integer argument x, computes 3 ∗
 * x/4 but follows the bit-level integer coding rules (page 164). Your code should
 * replicate the fact that the computation 3*x can cause overflow.
 */

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
