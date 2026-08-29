/* w in %xmm0, x in %edi, y in %xmm1, z in %rsi */
double funct2(double w, int x, float y, long z) {
    return x*y - w/z;
}
