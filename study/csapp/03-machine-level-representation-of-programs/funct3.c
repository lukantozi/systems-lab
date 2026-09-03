/* ap in %rdi, b in %xmm0, c in %rsi, dp in %rdx */
double funct3(int *ap, double b, long c, float *dp) {
    if (b > *ap)
        return *dp * c;
    return c + 2*(*dp);
}
