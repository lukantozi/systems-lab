/* x in %rdi, y in %rsi, and z in %rdx */
long decode2(long x, long y, long z) {
    y -= z;
    x *= y;
    return (-(y & 1)) ^ x;
}
