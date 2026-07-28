/* xp in %rdi, yp in %rsi, zp in %rdx */
void decode1(long *xp, long *yp, long *zp) {
    long tmp = *yp;
    *yp = *xp;
    *xp = *zp;
    *zp = tmp;
}
