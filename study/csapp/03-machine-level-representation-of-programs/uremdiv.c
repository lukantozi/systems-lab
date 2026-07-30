typedef unsigned long ulong;

/* x in %rdi, y in %rsi, qp in %rdx, rp in %rcx */
void uremdiv(ulong x, ulong y, ulong *qp, ulong *rp) {
    ulong q = x / y;
    ulong r = x % y;
    *qp = q;
    *rp = r;
}
