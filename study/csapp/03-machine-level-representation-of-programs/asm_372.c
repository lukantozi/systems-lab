#include <alloca.h>

long aframe(long n, long idx, long *q) {
    long i;
    long **p = alloca(n * sizeof(long *));
    p[0] = &i;
    for (i = 1; i < n; i++)
        p[i] = q;
    return *p[idx];
} /* n in %rdi, idx in %rsi, q in %rdx */


/**
 * A. Explain, in mathematical terms, the logic in the computation of s2:
 *    s2 = s1 - 16 floor((8n + 30) / 16)
 *    even n: s2 = s1 - (8n + 16)
 *    odd n:  s2 = s1 - (8n + 24)
 *
 * B. Explain, in mathematical terms, the logic in the computation of p:
 *    p = 16 ceil(s2 / 16)
 *    p is the smallest multiple of 16 greater than or equal to s2.
 *
 * C. Find values of n and s1 that lead to minimum and maximum values of e1:
 *    minimum  e1 = 1
 *    Example: n = 2, s1 = 33
 *    maximum  e1 = 24
 *    Example: n = 1, s1 = 32
 *
 * D. What alignment properties does this code guarantee for the values of s2
 *    and p?
 *    s2 has the same value modulo 16 as s1.
 *
 *    p is always 16-byte aligned.
 *
 *    With the normal x86-64 stack-alignment convention,
 *    both s2 and p are 16-byte aligned.
 */

aframe:
2    pushq   %rbp
3    movq    %rsp, %rbp
4    subq    $16, %rsp           // Allocate space for i (%rsp = s1)
5    leaq    30(,%rdi,8), %rax
6    andq    $-16, %rax
7    subq    %rax, %rsp          // Allocate space for array p (%rsp = s2)
8    leaq    15(%rsp), %r8
9    andq    $-16, %r8           // Set %r8 to &p[0]
